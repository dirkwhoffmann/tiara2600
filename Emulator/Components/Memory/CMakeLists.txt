target_include_directories(tiaraCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(tiaraCore PRIVATE

Memory.cpp
MemoryBase.cpp
MemoryDebugger.cpp
Heatmap.cpp

)
