.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024AD34
.L8024AD34:
/* 13E074 8024AD34 90C20002 */  lbu   $v0, 2($a2)
/* 13E078 8024AD38 3C058027 */  lui   $a1, 0x8027
/* 13E07C 8024AD3C 8CA505DC */  lw    $a1, 0x5dc($a1)
/* 13E080 8024AD40 00A20018 */  mult  $a1, $v0
/* 13E084 8024AD44 3C048027 */  lui   $a0, 0x8027
/* 13E088 8024AD48 8C8404C8 */  lw    $a0, 0x4c8($a0)
/* 13E08C 8024AD4C 00002812 */  mflo  $a1
/* 13E090 8024AD50 0C09260A */  jal   func_80249828
/* 13E094 8024AD54 00000000 */   nop   
/* 13E098 8024AD58 3C108027 */  lui   $s0, 0x8027
/* 13E09C 8024AD5C 261005D4 */  addiu $s0, $s0, 0x5d4
/* 13E0A0 8024AD60 8E040000 */  lw    $a0, ($s0)
/* 13E0A4 8024AD64 3C018027 */  lui   $at, 0x8027
/* 13E0A8 8024AD68 AC2205D8 */  sw    $v0, 0x5d8($at)
/* 13E0AC 8024AD6C 0C090D1B */  jal   func_8024346C
/* 13E0B0 8024AD70 00442023 */   subu  $a0, $v0, $a0
/* 13E0B4 8024AD74 8E030000 */  lw    $v1, ($s0)
/* 13E0B8 8024AD78 00621821 */  addu  $v1, $v1, $v0
/* 13E0BC 8024AD7C AE030000 */  sw    $v1, ($s0)
/* 13E0C0 8024AD80 8FBF0014 */  lw    $ra, 0x14($sp)
/* 13E0C4 8024AD84 8FB00010 */  lw    $s0, 0x10($sp)
/* 13E0C8 8024AD88 03E00008 */  jr    $ra
/* 13E0CC 8024AD8C 27BD0018 */   addiu $sp, $sp, 0x18

/* 13E0D0 8024AD90 27BDFFE0 */  addiu $sp, $sp, -0x20
