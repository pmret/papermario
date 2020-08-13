.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetPartJumpGravity
/* 19A02C 8026B74C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 19A030 8026B750 AFB20018 */  sw    $s2, 0x18($sp)
/* 19A034 8026B754 0080902D */  daddu $s2, $a0, $zero
/* 19A038 8026B758 AFBF001C */  sw    $ra, 0x1c($sp)
/* 19A03C 8026B75C AFB10014 */  sw    $s1, 0x14($sp)
/* 19A040 8026B760 AFB00010 */  sw    $s0, 0x10($sp)
/* 19A044 8026B764 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 19A048 8026B768 8E50000C */  lw    $s0, 0xc($s2)
/* 19A04C 8026B76C 8E050000 */  lw    $a1, ($s0)
/* 19A050 8026B770 0C0B1EAF */  jal   get_variable
/* 19A054 8026B774 26100004 */   addiu $s0, $s0, 4
/* 19A058 8026B778 0040882D */  daddu $s1, $v0, $zero
/* 19A05C 8026B77C 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19A060 8026B780 16220002 */  bne   $s1, $v0, .L8026B78C
/* 19A064 8026B784 00000000 */   nop   
/* 19A068 8026B788 8E510148 */  lw    $s1, 0x148($s2)
.L8026B78C:
/* 19A06C 8026B78C 8E050000 */  lw    $a1, ($s0)
/* 19A070 8026B790 26100004 */  addiu $s0, $s0, 4
/* 19A074 8026B794 0C0B1EAF */  jal   get_variable
/* 19A078 8026B798 0240202D */   daddu $a0, $s2, $zero
/* 19A07C 8026B79C 0240202D */  daddu $a0, $s2, $zero
/* 19A080 8026B7A0 8E050000 */  lw    $a1, ($s0)
/* 19A084 8026B7A4 0C0B210B */  jal   get_float_variable
/* 19A088 8026B7A8 0040802D */   daddu $s0, $v0, $zero
/* 19A08C 8026B7AC 0220202D */  daddu $a0, $s1, $zero
/* 19A090 8026B7B0 0C09A75B */  jal   get_actor
/* 19A094 8026B7B4 46000506 */   mov.s $f20, $f0
/* 19A098 8026B7B8 0040202D */  daddu $a0, $v0, $zero
/* 19A09C 8026B7BC 0C099117 */  jal   get_actor_part
/* 19A0A0 8026B7C0 0200282D */   daddu $a1, $s0, $zero
/* 19A0A4 8026B7C4 8C430010 */  lw    $v1, 0x10($v0)
/* 19A0A8 8026B7C8 E4740024 */  swc1  $f20, 0x24($v1)
/* 19A0AC 8026B7CC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 19A0B0 8026B7D0 8FB20018 */  lw    $s2, 0x18($sp)
/* 19A0B4 8026B7D4 8FB10014 */  lw    $s1, 0x14($sp)
/* 19A0B8 8026B7D8 8FB00010 */  lw    $s0, 0x10($sp)
/* 19A0BC 8026B7DC D7B40020 */  ldc1  $f20, 0x20($sp)
/* 19A0C0 8026B7E0 24020002 */  addiu $v0, $zero, 2
/* 19A0C4 8026B7E4 03E00008 */  jr    $ra
/* 19A0C8 8026B7E8 27BD0028 */   addiu $sp, $sp, 0x28

