.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802496FC
.L802496FC:
/* 13CA3C 802496FC 90C20002 */  lbu   $v0, 2($a2)
/* 13CA40 80249700 3C058027 */  lui   $a1, 0x8027
/* 13CA44 80249704 8CA50394 */  lw    $a1, 0x394($a1)
/* 13CA48 80249708 00A20018 */  mult  $a1, $v0
/* 13CA4C 8024970C 3C048027 */  lui   $a0, 0x8027
/* 13CA50 80249710 8C840280 */  lw    $a0, 0x280($a0)
/* 13CA54 80249714 00002812 */  mflo  $a1
/* 13CA58 80249718 0C091C5A */  jal   func_80247168
/* 13CA5C 8024971C 00000000 */   nop   
/* 13CA60 80249720 3C108027 */  lui   $s0, 0x8027
/* 13CA64 80249724 2610038C */  addiu $s0, $s0, 0x38c
/* 13CA68 80249728 8E040000 */  lw    $a0, ($s0)
/* 13CA6C 8024972C 3C018027 */  lui   $at, 0x8027
/* 13CA70 80249730 AC220390 */  sw    $v0, 0x390($at)
/* 13CA74 80249734 0C090D1B */  jal   func_8024346C
/* 13CA78 80249738 00442023 */   subu  $a0, $v0, $a0
/* 13CA7C 8024973C 8E030000 */  lw    $v1, ($s0)
/* 13CA80 80249740 00621821 */  addu  $v1, $v1, $v0
/* 13CA84 80249744 AE030000 */  sw    $v1, ($s0)
/* 13CA88 80249748 8FBF0014 */  lw    $ra, 0x14($sp)
/* 13CA8C 8024974C 8FB00010 */  lw    $s0, 0x10($sp)
/* 13CA90 80249750 03E00008 */  jr    $ra
/* 13CA94 80249754 27BD0018 */   addiu $sp, $sp, 0x18

/* 13CA98 80249758 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 13CA9C 8024975C AFB10014 */  sw    $s1, 0x14($sp)
/* 13CAA0 80249760 0000882D */  daddu $s1, $zero, $zero
/* 13CAA4 80249764 AFB00010 */  sw    $s0, 0x10($sp)
/* 13CAA8 80249768 3C108027 */  lui   $s0, 0x8027
/* 13CAAC 8024976C 261003A8 */  addiu $s0, $s0, 0x3a8
/* 13CAB0 80249770 AFBF0018 */  sw    $ra, 0x18($sp)
.L80249774:
/* 13CAB4 80249774 8E040000 */  lw    $a0, ($s0)
/* 13CAB8 80249778 26100004 */  addiu $s0, $s0, 4
/* 13CABC 8024977C 0C05123D */  jal   free_icon
/* 13CAC0 80249780 26310001 */   addiu $s1, $s1, 1
/* 13CAC4 80249784 2A220016 */  slti  $v0, $s1, 0x16
/* 13CAC8 80249788 1440FFFA */  bnez  $v0, .L80249774
/* 13CACC 8024978C 00000000 */   nop   
/* 13CAD0 80249790 8FBF0018 */  lw    $ra, 0x18($sp)
/* 13CAD4 80249794 8FB10014 */  lw    $s1, 0x14($sp)
/* 13CAD8 80249798 8FB00010 */  lw    $s0, 0x10($sp)
/* 13CADC 8024979C 03E00008 */  jr    $ra
/* 13CAE0 802497A0 27BD0020 */   addiu $sp, $sp, 0x20

/* 13CAE4 802497A4 00000000 */  nop   
/* 13CAE8 802497A8 00000000 */  nop   
