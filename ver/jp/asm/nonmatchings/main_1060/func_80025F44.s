.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80097D10
.ascii "File:%s Line:%d  %s \n"

.section .text

glabel func_80025F44
/* 1344 80025F44 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1348 80025F48 AFBF0010 */  sw        $ra, 0x10($sp)
/* 134C 80025F4C 0080382D */  daddu     $a3, $a0, $zero
/* 1350 80025F50 3C048009 */  lui       $a0, %hi(D_80097D10)
/* 1354 80025F54 24847D30 */  addiu     $a0, $a0, %lo(D_80097D10)
/* 1358 80025F58 0C00973F */  jal       func_80025CFC
/* 135C 80025F5C 00000000 */   nop
.L80025F60:
/* 1360 80025F60 080097D8 */  j         .L80025F60
/* 1364 80025F64 00000000 */   nop
/* 1368 80025F68 00000000 */  nop
/* 136C 80025F6C 00000000 */  nop
