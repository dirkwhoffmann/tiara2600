//
// This file is part of VirtualC64 - A Commodore 64 emulator
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Licensed under the GNU General Public License v3
//
// See https://www.gnu.org for license information
//

#include <metal_stdlib>

using namespace metal;

#define SCALE_FACTOR 4


//
// Vertex shader data types
// 

struct InVertex {
    float4 position [[attribute(0)]];
    float2 texCoords [[attribute(1)]];
};

struct ProjectedVertex {
    float4 position [[position]];
    float2 texCoords [[user(tex_coords)]];
};

struct Uniforms {
    float4x4 modelViewProjection;
};


//
// Compute shader data types
//

struct ShaderOptions {
    
    uint blur;
    float blurRadius;

    uint bloom;
    float bloomRadius;
    float bloomBrightness;
    float bloomWeight;

    uint dotMask;
    float dotMaskBrightness;

    uint scanlines;
    float scanlineBrightness;
    float scanlineWeight;
    
    uint disalignment;
    float disalignmentH;
    float disalignmentV;
};


//
// Fragment shader data types
//

struct FragmentUniforms {
    
    float alpha;
    float white;
    uint dotMaskWidth;
    uint dotMaskHeight;
    uint scanlineDistance;
};


//
// Vertex shader
//

vertex ProjectedVertex vertex_main(const device InVertex *vertices [[buffer(0)]],
                                   constant Uniforms &uniforms [[buffer(1)]],
                                   ushort vid [[vertex_id]])
{
    ProjectedVertex out;

    out.position = uniforms.modelViewProjection * float4(vertices[vid].position);
    out.texCoords = vertices[vid].texCoords;
    return out;
}


//
// Fragment shader
//

float4 scanlineWeight(uint2 pixel, uint height, float weight, float brightness, float bloom) {
    
    // Calculate distance to nearest scanline
    float dy = ((float(pixel.y % height) / float(height - 1)) - 0.5);
 
    // Calculate scanline weight
    float scanlineWeight = max(1.0 - dy * dy * 24 * weight, brightness);
    
    // Apply bloom effect an return
    return scanlineWeight * bloom;
}

float3 rgb2hsv(float3 c)
{
    float4 K = float4(0.0, -1.0 / 3.0, 2.0 / 3.0, -1.0);
    float4 p = mix(float4(c.bg, K.wz), float4(c.gb, K.xy), step(c.b, c.g));
    float4 q = mix(float4(p.xyw, c.r), float4(c.r, p.yzx), step(p.x, c.r));
    
    float d = q.x - min(q.w, q.y);
    float e = 1.0e-10;
    return float3(abs(q.z + (q.w - q.y) / (6.0 * d + e)), d / (q.x + e), q.x);
}

float3 hsv2rgb(float3 c)
{
    float4 K = float4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
    float3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
    return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}

fragment half4 fragment_main(ProjectedVertex vert [[ stage_in ]],
                             texture2d<float, access::sample> texture [[ texture(0) ]],
                             texture2d<float, access::sample> bloomTextureR [[ texture(1) ]],
                             texture2d<float, access::sample> bloomTextureG [[ texture(2) ]],
                             texture2d<float, access::sample> bloomTextureB [[ texture(3) ]],
                             texture2d<float, access::sample> dotMask [[ texture(4) ]],
                             constant ShaderOptions &options [[ buffer(0) ]],
                             constant FragmentUniforms &uniforms [[ buffer(1) ]],
                             sampler texSampler [[ sampler(0) ]])
{
    uint x = uint(vert.position.x);
    uint y = uint(vert.position.y);
    uint2 pixel = uint2(x, y);
    float4 color;
    
    // Read fragment from texture
    float2 tc = float2(vert.texCoords.x, vert.texCoords.y);
    if (options.disalignment) {
        float dx = options.disalignmentH;
        float dy = options.disalignmentV;
        float4 r = texture.sample(texSampler, tc + float2(dx,dy));
        float4 g = texture.sample(texSampler, tc);
        float4 b = texture.sample(texSampler, tc - float2(dx,dy));
        color = float4(r.r, g.g, b.b,0);
    } else {
        color = texture.sample(texSampler, float2(vert.texCoords.x, vert.texCoords.y));
    }
    
    // Apply bloom effect (if enabled)
    if (options.bloom) {
        float4 bloom_r = bloomTextureR.sample(texSampler, tc);
        float4 bloom_g = bloomTextureG.sample(texSampler, tc);
        float4 bloom_b = bloomTextureB.sample(texSampler, tc);
        float4 bColor = bloom_r + bloom_g + bloom_b;
        bColor = pow(bColor, options.bloomWeight) * options.bloomBrightness;
        color = saturate(color + bColor);
    }
    
    // Apply scanline effect (if emulation type matches)
    if (options.scanlines == 2) {
        color *= scanlineWeight(pixel,
                                uniforms.scanlineDistance,
                                options.scanlineWeight,
                                options.scanlineBrightness,
                                1.0);
    }

    // Apply dot mask effect
    if (options.dotMask) {
        uint xoffset = x % uniforms.dotMaskWidth;
        uint yoffset = y % uniforms.dotMaskHeight;
        float4 dotColor = dotMask.read(uint2(xoffset, yoffset));
        float4 gain = min(color, 1 - color) * dotColor;
        float4 loose = min(color, 1 - color) * 0.5 * (1 - dotColor);
        color += gain - loose;
    }
    
    color = mix(color, float4(1.0, 1.0, 1.0, 1.0), uniforms.white);
    return half4(color.r, color.g, color.b, uniforms.alpha);
}


//
// Texture upscalers
//

kernel void bypassupscaler(texture2d<half, access::read>  inTexture   [[ texture(0) ]],
                           texture2d<half, access::write> outTexture  [[ texture(1) ]],
                           uint2                          gid         [[ thread_position_in_grid ]])
{
    half4 result = inTexture.read(uint2(gid.x / SCALE_FACTOR, gid.y / SCALE_FACTOR));
    outTexture.write(result, gid);
}

// EPX upscaler (Eric's Pixel Expansion)
void writePixelBlock(texture2d<half, access::write> outTexture, uint2 gid, half4 value)
{
    outTexture.write(value, gid + uint2(0,0));
    outTexture.write(value, gid + uint2(0,1));
    outTexture.write(value, gid + uint2(1,0));
    outTexture.write(value, gid + uint2(1,1));
}

kernel void epxupscaler(texture2d<half, access::read>  inTexture   [[ texture(0) ]],
                        texture2d<half, access::write> outTexture  [[ texture(1) ]],
                        uint2                          gid         [[ thread_position_in_grid ]])
{
    if((gid.x % 4 != 0) || (gid.y % 4 != 0))
        return;
    
    //   A    --\ 1 2
    // C P B  --/ 3 4
    //   D
    // 1=P; 2=P; 3=P; 4=P;
    // IF C==A AND C!=D AND A!=B => 1=A
    // IF A==B AND A!=C AND B!=D => 2=B
    // IF D==C AND D!=B AND C!=A => 3=C
    // IF B==D AND B!=A AND D!=C => 4=D

    half xx = gid.x / SCALE_FACTOR;
    half yy = gid.y / SCALE_FACTOR;
    half4 A = inTexture.read(uint2(xx, yy - 1));
    half4 C = inTexture.read(uint2(xx - 1, yy));
    half4 P = inTexture.read(uint2(xx, yy));
    half4 B = inTexture.read(uint2(xx + 1, yy));
    half4 D = inTexture.read(uint2(xx, yy + 1));
        
    half4 r1 = (all(C == A) && any(C != D) && any(A != B)) ? A : P;
    half4 r2 = (all(A == B) && any(A != C) && any(B != D)) ? B : P;
    half4 r3 = (all(A == B) && any(A != C) && any(B != D)) ? C : P;
    half4 r4 = (all(B == D) && any(B != A) && any(D != C)) ? D : P;

    writePixelBlock(outTexture, gid + uint2(0,0), r1);
    writePixelBlock(outTexture, gid + uint2(2,0), r2);
    writePixelBlock(outTexture, gid + uint2(0,2), r3);
    writePixelBlock(outTexture, gid + uint2(2,2), r4);
}

// xBR upscaler (4x)
// Code is based on what I've found at:
// https://gamedev.stackexchange.com/questions/87275/how-do-i-perform-an-xbr-or-hqx-filter-in-xna

constant half coef = 2.0;
constant half3 yuv_weighted = half3(14.352, 28.176, 5.472);

half4 df(half4 A, half4 B)
{
    return abs(A - B);
}

half4 weighted_distance(half4 a, half4 b, half4 c, half4 d,
                        half4 e, half4 f, half4 g, half4 h)
{
    return (df(a, b) + df(a, c) + df(d, e) + df(d, f) + 4.0 * df(g, h));
}

kernel void xbrupscaler(texture2d<half, access::read>  inTexture   [[ texture(0) ]],
                        texture2d<half, access::write> outTexture  [[ texture(1) ]],
                        uint2                          gid         [[ thread_position_in_grid ]])
{
    bool4 edr, edr_left, edr_up, px;        // px = pixel, edr = edge detection rule
    bool4 ir_lv1, ir_lv2_left, ir_lv2_up;
    bool4 nc;                               // new color
    bool4 fx, fx_left, fx_up;               // inequations of straight lines
        
    half2 fp = fract(half2(gid) / SCALE_FACTOR);
    uint2 ggid = gid / SCALE_FACTOR;
    
    half3 A  = inTexture.read(ggid + uint2(-1,-1)).xyz;
    half3 B  = inTexture.read(ggid + uint2( 0,-1)).xyz;
    half3 C  = inTexture.read(ggid + uint2( 1,-1)).xyz;
    half3 D  = inTexture.read(ggid + uint2(-1, 0)).xyz;
    half3 E  = inTexture.read(ggid + uint2( 0, 0)).xyz;
    half3 F  = inTexture.read(ggid + uint2( 1, 0)).xyz;
    half3 G  = inTexture.read(ggid + uint2(-1, 1)).xyz;
    half3 H  = inTexture.read(ggid + uint2( 0, 1)).xyz;
    half3 I  = inTexture.read(ggid + uint2( 1, 1)).xyz;
    half3 A1 = inTexture.read(ggid + uint2(-1,-2)).xyz;
    half3 C1 = inTexture.read(ggid + uint2( 1,-2)).xyz;
    half3 A0 = inTexture.read(ggid + uint2(-2,-1)).xyz;
    half3 G0 = inTexture.read(ggid + uint2(-2, 1)).xyz;
    half3 C4 = inTexture.read(ggid + uint2( 2,-1)).xyz;
    half3 I4 = inTexture.read(ggid + uint2( 2, 1)).xyz;
    half3 G5 = inTexture.read(ggid + uint2(-1, 2)).xyz;
    half3 I5 = inTexture.read(ggid + uint2( 1, 2)).xyz;
    half3 B1 = inTexture.read(ggid + uint2( 0,-2)).xyz;
    half3 D0 = inTexture.read(ggid + uint2(-2, 0)).xyz;
    half3 H5 = inTexture.read(ggid + uint2( 0, 2)).xyz;
    half3 F4 = inTexture.read(ggid + uint2( 2, 0)).xyz;
        
    half4 b = yuv_weighted * half4x3(B, D, H, F);
    half4 c = yuv_weighted * half4x3(C, A, G, I);
    half4 e = yuv_weighted * half4x3(E, E, E, E);
    half4 d = b.yzwx;
    half4 f = b.wxyz;
    half4 g = c.zwxy;
    half4 h = b.zwxy;
    half4 i = c.wxyz;
        
    half4 i4 = yuv_weighted * half4x3(I4, C1, A0, G5);
    half4 i5 = yuv_weighted * half4x3(I5, C4, A1, G0);
    half4 h5 = yuv_weighted * half4x3(H5, F4, B1, D0);
    half4 f4 = h5.yzwx;
        
    half4 Ao = half4(1.0, -1.0, -1.0, 1.0);
    half4 Bo = half4(1.0, 1.0, -1.0, -1.0);
    half4 Co = half4(1.5, 0.5, -0.5, 0.5);
    half4 Ax = half4(1.0, -1.0, -1.0, 1.0);
    half4 Bx = half4(0.5, 2.0, -0.5, -2.0);
    half4 Cx = half4(1.0, 1.0, -0.5, 0.0);
    half4 Ay = half4(1.0, -1.0, -1.0, 1.0);
    half4 By = half4(2.0, 0.5, -2.0, -0.5);
    half4 Cy = half4(2.0, 0.0, -1.0, 0.5);
        
    // These inequations define the line below which interpolation occurs.
    fx.x = (Ao.x * fp.y + Bo.x * fp.x > Co.x);
    fx.y = (Ao.y * fp.y + Bo.y * fp.x > Co.y);
    fx.z = (Ao.z * fp.y + Bo.z * fp.x > Co.z);
    fx.w = (Ao.w * fp.y + Bo.w * fp.x > Co.w);
        
    fx_left.x = (Ax.x * fp.y + Bx.x * fp.x > Cx.x);
    fx_left.y = (Ax.y * fp.y + Bx.y * fp.x > Cx.y);
    fx_left.z = (Ax.z * fp.y + Bx.z * fp.x > Cx.z);
    fx_left.w = (Ax.w * fp.y + Bx.w * fp.x > Cx.w);
        
    fx_up.x = (Ay.x * fp.y + By.x * fp.x > Cy.x);
    fx_up.y = (Ay.y * fp.y + By.y * fp.x > Cy.y);
    fx_up.z = (Ay.z * fp.y + By.z * fp.x > Cy.z);
    fx_up.w = (Ay.w * fp.y + By.w * fp.x > Cy.w);
        
    ir_lv1      = ((e != f) && (e != h));
    ir_lv2_left = ((e != g) && (d != g));
    ir_lv2_up   = ((e != c) && (b != c));
        
    half4 w1 = weighted_distance(e, c, g, i, h5, f4, h, f);
    half4 w2 = weighted_distance(h, d, i5, f, i4, b, e, i);
    half4 df_fg = df(f, g);
    half4 df_hc = df(h, c);
    half4 t1 = (coef * df_fg);
    half4 t2 = df_hc;
    half4 t3 = df_fg;
    half4 t4 = (coef * df_hc);
        
    edr      = (w1 < w2)  && ir_lv1;
    edr_left = (t1 <= t2) && ir_lv2_left;
    edr_up   = (t4 <= t3) && ir_lv2_up;
        
    nc = (edr && (fx || (edr_left && fx_left) || (edr_up && fx_up)));
        
    t1 = df(e, f);
    t2 = df(e, h);
    px = t1 <= t2;
        
    half3 res =
        nc.x ? px.x ? F : H :
        nc.y ? px.y ? B : F :
        nc.z ? px.z ? D : B :
        nc.w ? px.w ? H : D : E;
        
    outTexture.write(half4(res,1.0), gid);
}


//
// Scanline filters
//

/*
struct CrtParameters {
    float scanlineWeight;
    float scanlineBrightness;
};
*/

kernel void scanlines(texture2d<half, access::read>  inTexture   [[ texture(0) ]],
                      texture2d<half, access::write> outTexture  [[ texture(1) ]],
                      constant ShaderOptions         &options    [[ buffer(0) ]],
                      uint2                          gid         [[ thread_position_in_grid ]])
{
    half4 color = inTexture.read(uint2(gid.x, gid.y));
    if (((gid.y + 1) % 4) < 2) {
        color *= options.scanlineBrightness;
    }
    outTexture.write(color, gid);
}

//
// RGB splitter
//

/*
struct BloomUniforms {
    float bloomBrightness;
    float bloomWeight;
};
*/

kernel void split(texture2d<half, access::read>  t_in        [[ texture(0) ]],
                  texture2d<half, access::write> t_out_r     [[ texture(1) ]],
                  texture2d<half, access::write> t_out_g     [[ texture(2) ]],
                  texture2d<half, access::write> t_out_b     [[ texture(3) ]],
                  constant ShaderOptions         &options    [[ buffer(0) ]],
                  uint2                          gid         [[ thread_position_in_grid ]])
{

    half4 color = t_in.read(uint2(gid.x, gid.y));
    
    t_out_r.write(half4(color.r, 0, 0, 0), gid);
    t_out_g.write(half4(0, color.g, 0, 0), gid);
    t_out_b.write(half4(0, 0, color.b, 0), gid);
}


//
// Bypass filter
//

kernel void bypass(texture2d<half, access::read>  inTexture   [[ texture(0) ]],
                   texture2d<half, access::write> outTexture  [[ texture(1) ]],
                   uint2                          gid         [[ thread_position_in_grid ]])
{
    half4 result = inTexture.read(uint2(gid.x, gid.y));
    outTexture.write(result, gid);
}
