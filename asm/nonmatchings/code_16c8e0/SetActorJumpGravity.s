.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetActorJumpGravity
/* 199E3C 8026B55C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 199E40 8026B560 AFB20018 */  sw    $s2, 0x18($sp)
/* 199E44 8026B564 0080902D */  daddu $s2, $a0, $zero
/* 199E48 8026B568 AFBF001C */  sw    $ra, 0x1c($sp)
/* 199E4C 8026B56C AFB10014 */  sw    $s1, 0x14($sp)
/* 199E50 8026B570 AFB00010 */  sw    $s0, 0x10($sp)
/* 199E54 8026B574 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 199E58 8026B578 8E51000C */  lw    $s1, 0xc($s2)
/* 199E5C 8026B57C 8E250000 */  lw    $a1, ($s1)
/* 199E60 8026B580 0C0B1EAF */  jal   get_variable
/* 199E64 8026B584 26310004 */   addiu $s1, $s1, 4
/* 199E68 8026B588 0040802D */  daddu $s0, $v0, $zero
/* 199E6C 8026B58C 2402FF81 */  addiu $v0, $zero, -0x7f
/* 199E70 8026B590 16020002 */  bne   $s0, $v0, .L8026B59C
/* 199E74 8026B594 00000000 */   nop   
/* 199E78 8026B598 8E500148 */  lw    $s0, 0x148($s2)
.L8026B59C:
/* 199E7C 8026B59C 8E250000 */  lw    $a1, ($s1)
/* 199E80 8026B5A0 0C0B210B */  jal   get_float_variable
/* 199E84 8026B5A4 0240202D */   daddu $a0, $s2, $zero
/* 199E88 8026B5A8 0200202D */  daddu $a0, $s0, $zero
/* 199E8C 8026B5AC 0C09A75B */  jal   get_actor
/* 199E90 8026B5B0 46000506 */   mov.s $f20, $f0
/* 199E94 8026B5B4 E4540048 */  swc1  $f20, 0x48($v0)
/* 199E98 8026B5B8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 199E9C 8026B5BC 8FB20018 */  lw    $s2, 0x18($sp)
/* 199EA0 8026B5C0 8FB10014 */  lw    $s1, 0x14($sp)
/* 199EA4 8026B5C4 8FB00010 */  lw    $s0, 0x10($sp)
/* 199EA8 8026B5C8 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 199EAC 8026B5CC 24020002 */  addiu $v0, $zero, 2
/* 199EB0 8026B5D0 03E00008 */  jr    $ra
/* 199EB4 8026B5D4 27BD0028 */   addiu $sp, $sp, 0x28

