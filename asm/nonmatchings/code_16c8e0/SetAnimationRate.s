.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetAnimationRate
/* 199BB0 8026B2D0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 199BB4 8026B2D4 AFB20018 */  sw    $s2, 0x18($sp)
/* 199BB8 8026B2D8 0080902D */  daddu $s2, $a0, $zero
/* 199BBC 8026B2DC AFBF001C */  sw    $ra, 0x1c($sp)
/* 199BC0 8026B2E0 AFB10014 */  sw    $s1, 0x14($sp)
/* 199BC4 8026B2E4 AFB00010 */  sw    $s0, 0x10($sp)
/* 199BC8 8026B2E8 8E50000C */  lw    $s0, 0xc($s2)
/* 199BCC 8026B2EC 8E050000 */  lw    $a1, ($s0)
/* 199BD0 8026B2F0 0C0B1EAF */  jal   get_variable
/* 199BD4 8026B2F4 26100004 */   addiu $s0, $s0, 4
/* 199BD8 8026B2F8 0040882D */  daddu $s1, $v0, $zero
/* 199BDC 8026B2FC 2402FF81 */  addiu $v0, $zero, -0x7f
/* 199BE0 8026B300 16220002 */  bne   $s1, $v0, .L8026B30C
/* 199BE4 8026B304 00000000 */   nop   
/* 199BE8 8026B308 8E510148 */  lw    $s1, 0x148($s2)
.L8026B30C:
/* 199BEC 8026B30C 8E050000 */  lw    $a1, ($s0)
/* 199BF0 8026B310 26100004 */  addiu $s0, $s0, 4
/* 199BF4 8026B314 0C0B1EAF */  jal   get_variable
/* 199BF8 8026B318 0240202D */   daddu $a0, $s2, $zero
/* 199BFC 8026B31C 0240202D */  daddu $a0, $s2, $zero
/* 199C00 8026B320 8E050000 */  lw    $a1, ($s0)
/* 199C04 8026B324 0C0B210B */  jal   get_float_variable
/* 199C08 8026B328 0040802D */   daddu $s0, $v0, $zero
/* 199C0C 8026B32C 0220202D */  daddu $a0, $s1, $zero
/* 199C10 8026B330 44060000 */  mfc1  $a2, $f0
/* 199C14 8026B334 0C098FAE */  jal   set_animation_rate
/* 199C18 8026B338 0200282D */   daddu $a1, $s0, $zero
/* 199C1C 8026B33C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 199C20 8026B340 8FB20018 */  lw    $s2, 0x18($sp)
/* 199C24 8026B344 8FB10014 */  lw    $s1, 0x14($sp)
/* 199C28 8026B348 8FB00010 */  lw    $s0, 0x10($sp)
/* 199C2C 8026B34C 24020002 */  addiu $v0, $zero, 2
/* 199C30 8026B350 03E00008 */  jr    $ra
/* 199C34 8026B354 27BD0020 */   addiu $sp, $sp, 0x20

