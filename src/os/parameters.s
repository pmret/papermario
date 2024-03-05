.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

.globl leoBootID
leoBootID = 0x800001a0

.globl osTvType
osTvType = 0x80000300

.globl osRomType
osRomType = 0x80000304

.globl osRomBase
osRomBase = 0x80000308

.globl osResetType
osResetType = 0x8000030C

.globl osCicId
osCicId = 0x80000310

.globl osVersion
osVersion = 0x80000314

.globl osMemSize
osMemSize = 0x80000318

.globl osAppNMIBuffer
osAppNMIBuffer = 0x8000031C

#ifdef BBPLAYER
.globl __osBbEepromAddress
__osBbEepromAddress = 0x8000035c

.globl __osBbEepromSize
__osBbEepromSize = 0x80000360

.globl __osBbFlashAddress
__osBbFlashAddress = 0x80000364

.globl __osBbFlashSize
__osBbFlashSize = 0x80000368

.globl __osBbSramAddress
__osBbSramAddress = 0x8000036c

.globl __osBbSramSize
__osBbSramSize = 0x80000370

.globl __osBbPakAddress
__osBbPakAddress = 0x80000374

.globl __osBbPakSize
__osBbPakSize = 0x80000384

.globl __osBbIsBb
__osBbIsBb = 0x80000388

.globl __osBbHackFlags
__osBbHackFlags = 0x8000038c

.globl __osBbStashMagic
__osBbStashMagic = 0x80000390

.globl __osBbPakBindings
__osBbPakBindings = 0x80000394

.globl __osBbStateName
__osBbStateName = 0x800003a4

.globl __osBbStateDirty
__osBbStateDirty = 0x800003b4

.globl __osBbAuxDataLimit
__osBbAuxDataLimit = 0x800003b8

.fill 0x70
#else
.fill 0x60
#endif
