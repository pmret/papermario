.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80055B28
/* 030F28 80055B28 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 030F2C 80055B2C AFB00030 */  sw    $s0, 0x30($sp)
/* 030F30 80055B30 3C108008 */  lui   $s0, 0x8008
/* 030F34 80055B34 26108DB0 */  addiu $s0, $s0, -0x7250
/* 030F38 80055B38 24030001 */  addiu $v1, $zero, 1
/* 030F3C 80055B3C 240207D0 */  addiu $v0, $zero, 0x7d0
/* 030F40 80055B40 AFBF0034 */  sw    $ra, 0x34($sp)
/* 030F44 80055B44 AE030000 */  sw    $v1, ($s0)
/* 030F48 80055B48 AFA20014 */  sw    $v0, 0x14($sp)
/* 030F4C 80055B4C 2402007F */  addiu $v0, $zero, 0x7f
/* 030F50 80055B50 AFA40010 */  sw    $a0, 0x10($sp)
/* 030F54 80055B54 27A40010 */  addiu $a0, $sp, 0x10
/* 030F58 80055B58 AFA30018 */  sw    $v1, 0x18($sp)
/* 030F5C 80055B5C AFA2001C */  sw    $v0, 0x1c($sp)
/* 030F60 80055B60 AFA00020 */  sw    $zero, 0x20($sp)
/* 030F64 80055B64 0C01378B */  jal   func_8004DE2C
/* 030F68 80055B68 AFA00024 */   sw    $zero, 0x24($sp)
/* 030F6C 80055B6C AE000000 */  sw    $zero, ($s0)
/* 030F70 80055B70 8FBF0034 */  lw    $ra, 0x34($sp)
/* 030F74 80055B74 8FB00030 */  lw    $s0, 0x30($sp)
/* 030F78 80055B78 03E00008 */  jr    $ra
/* 030F7C 80055B7C 27BD0038 */   addiu $sp, $sp, 0x38

