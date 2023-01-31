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

.fill 0x60
