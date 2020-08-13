.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetActorIdleJumpGravity
/* 199EB8 8026B5D8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 199EBC 8026B5DC AFB20018 */  sw    $s2, 0x18($sp)
/* 199EC0 8026B5E0 0080902D */  daddu $s2, $a0, $zero
/* 199EC4 8026B5E4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 199EC8 8026B5E8 AFB10014 */  sw    $s1, 0x14($sp)
/* 199ECC 8026B5EC AFB00010 */  sw    $s0, 0x10($sp)
/* 199ED0 8026B5F0 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 199ED4 8026B5F4 8E51000C */  lw    $s1, 0xc($s2)
/* 199ED8 8026B5F8 8E250000 */  lw    $a1, ($s1)
/* 199EDC 8026B5FC 0C0B1EAF */  jal   get_variable
/* 199EE0 8026B600 26310004 */   addiu $s1, $s1, 4
/* 199EE4 8026B604 0040802D */  daddu $s0, $v0, $zero
/* 199EE8 8026B608 2402FF81 */  addiu $v0, $zero, -0x7f
/* 199EEC 8026B60C 16020002 */  bne   $s0, $v0, .L8026B618
/* 199EF0 8026B610 00000000 */   nop   
/* 199EF4 8026B614 8E500148 */  lw    $s0, 0x148($s2)
.L8026B618:
/* 199EF8 8026B618 8E250000 */  lw    $a1, ($s1)
/* 199EFC 8026B61C 0C0B210B */  jal   get_float_variable
/* 199F00 8026B620 0240202D */   daddu $a0, $s2, $zero
/* 199F04 8026B624 0200202D */  daddu $a0, $s0, $zero
/* 199F08 8026B628 0C09A75B */  jal   get_actor
/* 199F0C 8026B62C 46000506 */   mov.s $f20, $f0
/* 199F10 8026B630 E4540104 */  swc1  $f20, 0x104($v0)
/* 199F14 8026B634 8FBF001C */  lw    $ra, 0x1c($sp)
/* 199F18 8026B638 8FB20018 */  lw    $s2, 0x18($sp)
/* 199F1C 8026B63C 8FB10014 */  lw    $s1, 0x14($sp)
/* 199F20 8026B640 8FB00010 */  lw    $s0, 0x10($sp)
/* 199F24 8026B644 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 199F28 8026B648 24020002 */  addiu $v0, $zero, 2
/* 199F2C 8026B64C 03E00008 */  jr    $ra
/* 199F30 8026B650 27BD0028 */   addiu $sp, $sp, 0x28

