.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel rand_int
/* 004DFC 800299FC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 004E00 80029A00 AFBF0010 */  sw    $ra, 0x10($sp)
/* 004E04 80029A04 04820001 */  bltzl $a0, .L80029A0C
/* 004E08 80029A08 00042023 */   negu  $a0, $a0
.L80029A0C:
/* 004E0C 80029A0C 10800018 */  beqz  $a0, .L80029A70
/* 004E10 80029A10 0000102D */   daddu $v0, $zero, $zero
/* 004E14 80029A14 24020001 */  addiu $v0, $zero, 1
/* 004E18 80029A18 54820006 */  bnel  $a0, $v0, .L80029A34
/* 004E1C 80029A1C 24020064 */   addiu $v0, $zero, 0x64
/* 004E20 80029A20 0C00A665 */  jal   func_80029994
/* 004E24 80029A24 240403E8 */   addiu $a0, $zero, 0x3e8
/* 004E28 80029A28 284201F5 */  slti  $v0, $v0, 0x1f5
/* 004E2C 80029A2C 0800A69C */  j     .L80029A70
/* 004E30 80029A30 38420001 */   xori  $v0, $v0, 1

.L80029A34:
/* 004E34 80029A34 10820005 */  beq   $a0, $v0, .L80029A4C
/* 004E38 80029A38 00000000 */   nop   
/* 004E3C 80029A3C 0C00A665 */  jal   func_80029994
/* 004E40 80029A40 00000000 */   nop   
/* 004E44 80029A44 0800A69C */  j     .L80029A70
/* 004E48 80029A48 00000000 */   nop   

.L80029A4C:
/* 004E4C 80029A4C 0C00A665 */  jal   func_80029994
/* 004E50 80029A50 240403F1 */   addiu $a0, $zero, 0x3f1
/* 004E54 80029A54 3C036666 */  lui   $v1, 0x6666
/* 004E58 80029A58 34636667 */  ori   $v1, $v1, 0x6667
/* 004E5C 80029A5C 00430018 */  mult  $v0, $v1
/* 004E60 80029A60 000217C3 */  sra   $v0, $v0, 0x1f
/* 004E64 80029A64 00002810 */  mfhi  $a1
/* 004E68 80029A68 00051883 */  sra   $v1, $a1, 2
/* 004E6C 80029A6C 00621023 */  subu  $v0, $v1, $v0
.L80029A70:
/* 004E70 80029A70 8FBF0010 */  lw    $ra, 0x10($sp)
/* 004E74 80029A74 03E00008 */  jr    $ra
/* 004E78 80029A78 27BD0018 */   addiu $sp, $sp, 0x18

