.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetPartTarget
/* 199298 8026A9B8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 19929C 8026A9BC AFB40020 */  sw    $s4, 0x20($sp)
/* 1992A0 8026A9C0 0080A02D */  daddu $s4, $a0, $zero
/* 1992A4 8026A9C4 AFBF0024 */  sw    $ra, 0x24($sp)
/* 1992A8 8026A9C8 AFB3001C */  sw    $s3, 0x1c($sp)
/* 1992AC 8026A9CC AFB20018 */  sw    $s2, 0x18($sp)
/* 1992B0 8026A9D0 AFB10014 */  sw    $s1, 0x14($sp)
/* 1992B4 8026A9D4 AFB00010 */  sw    $s0, 0x10($sp)
/* 1992B8 8026A9D8 8E92000C */  lw    $s2, 0xc($s4)
/* 1992BC 8026A9DC 8E450000 */  lw    $a1, ($s2)
/* 1992C0 8026A9E0 0C0B1EAF */  jal   get_variable
/* 1992C4 8026A9E4 26520004 */   addiu $s2, $s2, 4
/* 1992C8 8026A9E8 0040802D */  daddu $s0, $v0, $zero
/* 1992CC 8026A9EC 8E450000 */  lw    $a1, ($s2)
/* 1992D0 8026A9F0 26520004 */  addiu $s2, $s2, 4
/* 1992D4 8026A9F4 0C0B1EAF */  jal   get_variable
/* 1992D8 8026A9F8 0280202D */   daddu $a0, $s4, $zero
/* 1992DC 8026A9FC 0040882D */  daddu $s1, $v0, $zero
/* 1992E0 8026AA00 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1992E4 8026AA04 16020002 */  bne   $s0, $v0, .L8026AA10
/* 1992E8 8026AA08 00000000 */   nop   
/* 1992EC 8026AA0C 8E900148 */  lw    $s0, 0x148($s4)
.L8026AA10:
/* 1992F0 8026AA10 0C09A75B */  jal   get_actor
/* 1992F4 8026AA14 0200202D */   daddu $a0, $s0, $zero
/* 1992F8 8026AA18 0040202D */  daddu $a0, $v0, $zero
/* 1992FC 8026AA1C 0C099117 */  jal   get_actor_part
/* 199300 8026AA20 0220282D */   daddu $a1, $s1, $zero
/* 199304 8026AA24 8E450000 */  lw    $a1, ($s2)
/* 199308 8026AA28 26520004 */  addiu $s2, $s2, 4
/* 19930C 8026AA2C 8C420010 */  lw    $v0, 0x10($v0)
/* 199310 8026AA30 8E500000 */  lw    $s0, ($s2)
/* 199314 8026AA34 C440000C */  lwc1  $f0, 0xc($v0)
/* 199318 8026AA38 8E520004 */  lw    $s2, 4($s2)
/* 19931C 8026AA3C 4600010D */  trunc.w.s $f4, $f0
/* 199320 8026AA40 44062000 */  mfc1  $a2, $f4
/* 199324 8026AA44 C4400010 */  lwc1  $f0, 0x10($v0)
/* 199328 8026AA48 C4420014 */  lwc1  $f2, 0x14($v0)
/* 19932C 8026AA4C 4600010D */  trunc.w.s $f4, $f0
/* 199330 8026AA50 44112000 */  mfc1  $s1, $f4
/* 199334 8026AA54 4600110D */  trunc.w.s $f4, $f2
/* 199338 8026AA58 44132000 */  mfc1  $s3, $f4
/* 19933C 8026AA5C 0C0B2026 */  jal   set_variable
/* 199340 8026AA60 0280202D */   daddu $a0, $s4, $zero
/* 199344 8026AA64 0280202D */  daddu $a0, $s4, $zero
/* 199348 8026AA68 0200282D */  daddu $a1, $s0, $zero
/* 19934C 8026AA6C 0C0B2026 */  jal   set_variable
/* 199350 8026AA70 0220302D */   daddu $a2, $s1, $zero
/* 199354 8026AA74 0280202D */  daddu $a0, $s4, $zero
/* 199358 8026AA78 0240282D */  daddu $a1, $s2, $zero
/* 19935C 8026AA7C 0C0B2026 */  jal   set_variable
/* 199360 8026AA80 0260302D */   daddu $a2, $s3, $zero
/* 199364 8026AA84 8FBF0024 */  lw    $ra, 0x24($sp)
/* 199368 8026AA88 8FB40020 */  lw    $s4, 0x20($sp)
/* 19936C 8026AA8C 8FB3001C */  lw    $s3, 0x1c($sp)
/* 199370 8026AA90 8FB20018 */  lw    $s2, 0x18($sp)
/* 199374 8026AA94 8FB10014 */  lw    $s1, 0x14($sp)
/* 199378 8026AA98 8FB00010 */  lw    $s0, 0x10($sp)
/* 19937C 8026AA9C 24020002 */  addiu $v0, $zero, 2
/* 199380 8026AAA0 03E00008 */  jr    $ra
/* 199384 8026AAA4 27BD0028 */   addiu $sp, $sp, 0x28

