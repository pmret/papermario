.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetEnemyTargetOffset
/* 199980 8026B0A0 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 199984 8026B0A4 AFB20018 */  sw    $s2, 0x18($sp)
/* 199988 8026B0A8 0080902D */  daddu $s2, $a0, $zero
/* 19998C 8026B0AC AFBF0020 */  sw    $ra, 0x20($sp)
/* 199990 8026B0B0 AFB3001C */  sw    $s3, 0x1c($sp)
/* 199994 8026B0B4 AFB10014 */  sw    $s1, 0x14($sp)
/* 199998 8026B0B8 AFB00010 */  sw    $s0, 0x10($sp)
/* 19999C 8026B0BC F7B60030 */  sdc1  $f22, 0x30($sp)
/* 1999A0 8026B0C0 F7B40028 */  sdc1  $f20, 0x28($sp)
/* 1999A4 8026B0C4 8E50000C */  lw    $s0, 0xc($s2)
/* 1999A8 8026B0C8 8E050000 */  lw    $a1, ($s0)
/* 1999AC 8026B0CC 0C0B1EAF */  jal   get_variable
/* 1999B0 8026B0D0 26100004 */   addiu $s0, $s0, 4
/* 1999B4 8026B0D4 0040882D */  daddu $s1, $v0, $zero
/* 1999B8 8026B0D8 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1999BC 8026B0DC 16220002 */  bne   $s1, $v0, .L8026B0E8
/* 1999C0 8026B0E0 00000000 */   nop   
/* 1999C4 8026B0E4 8E510148 */  lw    $s1, 0x148($s2)
.L8026B0E8:
/* 1999C8 8026B0E8 8E050000 */  lw    $a1, ($s0)
/* 1999CC 8026B0EC 26100004 */  addiu $s0, $s0, 4
/* 1999D0 8026B0F0 0C0B1EAF */  jal   get_variable
/* 1999D4 8026B0F4 0240202D */   daddu $a0, $s2, $zero
/* 1999D8 8026B0F8 8E050000 */  lw    $a1, ($s0)
/* 1999DC 8026B0FC 26100004 */  addiu $s0, $s0, 4
/* 1999E0 8026B100 0240202D */  daddu $a0, $s2, $zero
/* 1999E4 8026B104 0C0B1EAF */  jal   get_variable
/* 1999E8 8026B108 0040982D */   daddu $s3, $v0, $zero
/* 1999EC 8026B10C 8E050000 */  lw    $a1, ($s0)
/* 1999F0 8026B110 4482B000 */  mtc1  $v0, $f22
/* 1999F4 8026B114 00000000 */  nop   
/* 1999F8 8026B118 4680B5A0 */  cvt.s.w $f22, $f22
/* 1999FC 8026B11C 0C0B1EAF */  jal   get_variable
/* 199A00 8026B120 0240202D */   daddu $a0, $s2, $zero
/* 199A04 8026B124 4482A000 */  mtc1  $v0, $f20
/* 199A08 8026B128 00000000 */  nop   
/* 199A0C 8026B12C 4680A520 */  cvt.s.w $f20, $f20
/* 199A10 8026B130 0C09A75B */  jal   get_actor
/* 199A14 8026B134 0220202D */   daddu $a0, $s1, $zero
/* 199A18 8026B138 0040182D */  daddu $v1, $v0, $zero
/* 199A1C 8026B13C 32240700 */  andi  $a0, $s1, 0x700
/* 199A20 8026B140 24020100 */  addiu $v0, $zero, 0x100
/* 199A24 8026B144 10820005 */  beq   $a0, $v0, .L8026B15C
/* 199A28 8026B148 28820101 */   slti  $v0, $a0, 0x101
/* 199A2C 8026B14C 1440000E */  bnez  $v0, .L8026B188
/* 199A30 8026B150 24020200 */   addiu $v0, $zero, 0x200
/* 199A34 8026B154 1482000C */  bne   $a0, $v0, .L8026B188
/* 199A38 8026B158 00000000 */   nop   
.L8026B15C:
/* 199A3C 8026B15C 0060202D */  daddu $a0, $v1, $zero
/* 199A40 8026B160 0C099117 */  jal   get_actor_part
/* 199A44 8026B164 0260282D */   daddu $a1, $s3, $zero
/* 199A48 8026B168 4600B00D */  trunc.w.s $f0, $f22
/* 199A4C 8026B16C 44030000 */  mfc1  $v1, $f0
/* 199A50 8026B170 00000000 */  nop   
/* 199A54 8026B174 A443006C */  sh    $v1, 0x6c($v0)
/* 199A58 8026B178 4600A00D */  trunc.w.s $f0, $f20
/* 199A5C 8026B17C 44030000 */  mfc1  $v1, $f0
/* 199A60 8026B180 00000000 */  nop   
/* 199A64 8026B184 A443006E */  sh    $v1, 0x6e($v0)
.L8026B188:
/* 199A68 8026B188 8FBF0020 */  lw    $ra, 0x20($sp)
/* 199A6C 8026B18C 8FB3001C */  lw    $s3, 0x1c($sp)
/* 199A70 8026B190 8FB20018 */  lw    $s2, 0x18($sp)
/* 199A74 8026B194 8FB10014 */  lw    $s1, 0x14($sp)
/* 199A78 8026B198 8FB00010 */  lw    $s0, 0x10($sp)
/* 199A7C 8026B19C D7B60030 */  ldc1  $f22, 0x30($sp)
/* 199A80 8026B1A0 D7B40028 */  ldc1  $f20, 0x28($sp)
/* 199A84 8026B1A4 24020002 */  addiu $v0, $zero, 2
/* 199A88 8026B1A8 03E00008 */  jr    $ra
/* 199A8C 8026B1AC 27BD0038 */   addiu $sp, $sp, 0x38

