.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetGroupEnabled
/* 0EDCB8 802C9308 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EDCBC 802C930C AFB10014 */  sw    $s1, 0x14($sp)
/* 0EDCC0 802C9310 0080882D */  daddu $s1, $a0, $zero
/* 0EDCC4 802C9314 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EDCC8 802C9318 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EDCCC 802C931C 8E30000C */  lw    $s0, 0xc($s1)
/* 0EDCD0 802C9320 8E050000 */  lw    $a1, ($s0)
/* 0EDCD4 802C9324 0C0B1EAF */  jal   get_variable
/* 0EDCD8 802C9328 26100004 */   addiu $s0, $s0, 4
/* 0EDCDC 802C932C 0220202D */  daddu $a0, $s1, $zero
/* 0EDCE0 802C9330 8E050000 */  lw    $a1, ($s0)
/* 0EDCE4 802C9334 0C0B1EAF */  jal   get_variable
/* 0EDCE8 802C9338 0040802D */   daddu $s0, $v0, $zero
/* 0EDCEC 802C933C 3204FFFF */  andi  $a0, $s0, 0xffff
/* 0EDCF0 802C9340 24050002 */  addiu $a1, $zero, 2
/* 0EDCF4 802C9344 0C046DF0 */  jal   func_8011B7C0
/* 0EDCF8 802C9348 0040302D */   daddu $a2, $v0, $zero
/* 0EDCFC 802C934C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EDD00 802C9350 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EDD04 802C9354 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EDD08 802C9358 24020002 */  addiu $v0, $zero, 2
/* 0EDD0C 802C935C 03E00008 */  jr    $ra
/* 0EDD10 802C9360 27BD0020 */   addiu $sp, $sp, 0x20

