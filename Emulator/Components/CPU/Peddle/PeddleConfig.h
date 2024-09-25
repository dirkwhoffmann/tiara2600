// -----------------------------------------------------------------------------
// This file is part of Peddle - A MOS 65xx CPU emulator
//
// Copyright (C) Dirk W. Hoffmann. www.dirkwhoffmann.de
// Published under the terms of the MIT License
// -----------------------------------------------------------------------------

#pragma once

#include "config.h"

/* Idle memory accesses
 *
 * The 65xx CPU is designed to perform a memory access in every clock cycle.
 * The access also takes place when the CPU is busy with an internal operation.
 * In these cases, the access is not necessary for the CPU, and the result of
 * the operation is discarded. However, the result of an idle access can cause
 * side effects, e.g., when a memory-mapped I/O register is read or written.
 * To capture such side effects, emulation of idle accesses must be enabled.
 *
 * Enable to improve accuracy, disable to gain speed.
 */
#define PEDDLE_EMULATE_IDLE_ACCESSES true

/* Watchpoint support
 *
 * By setting a watchpoint, the emulator can be asked to monitor certain memory
 * locations and signal the client when one of these locations is accessed.
 * However, checking for watchpoints requires a fair amount of processing time,
 * since a check must be performed prior to each memory operation. If watchpoint
 * support is not needed, these checks can be omitted by setting this option to
 * false.
 *
 * Enable to perform watchpoint checks, disable to gain speed.
 */
#define PEDDLE_ENABLE_WATCHPOINTS true

/* Memory API
 *
 * Peddle offers two interfaces to interact with the connected memory. The
 * "simple" API requires only a very few functions to be implemented, namely:
 *
 *       read : Reads a byte from memory
 *      write : Writes a byte to memory
 *   readDasm : Reads a byte without causing side-effects
 *
 * In this mode, the higher-level API, which is used inside the instruction
 * handlers, is synthesized automatically. Alternatively, Peddle offers you
 * to implement the high-level API by yourself. This is done, e.g., by
 * Tiara to speed up emulation.
 *
 * Enable to simplify usage, disable to gain speed.
 */

#define PEDDLE_SIMPLE_MEMORY_API true
