.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80029994
/* 004D94 80029994 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 004D98 80029998 AFB00010 */  sw    $s0, 0x10($sp)
/* 004D9C 8002999C 2410FFFF */  addiu $s0, $zero, -1
/* 004DA0 800299A0 AFB10014 */  sw    $s1, 0x14($sp)
/* 004DA4 800299A4 24910001 */  addiu $s1, $a0, 1
/* 004DA8 800299A8 16200002 */  bnez  $s1, .L800299B4
/* 004DAC 800299AC 0211001B */   divu  $zero, $s0, $s1
/* 004DB0 800299B0 0007000D */  break 7
.L800299B4:
/* 004DB4 800299B4 00008012 */  mflo  $s0
/* 004DB8 800299B8 16000002 */  bnez  $s0, .L800299C4
/* 004DBC 800299BC AFBF0018 */   sw    $ra, 0x18($sp)
/* 004DC0 800299C0 24100001 */  addiu $s0, $zero, 1
.L800299C4:
/* 004DC4 800299C4 0C00A640 */  jal   _advance_rng
/* 004DC8 800299C8 00000000 */   nop   
/* 004DCC 800299CC 16000002 */  bnez  $s0, .L800299D8
/* 004DD0 800299D0 0050001B */   divu  $zero, $v0, $s0
/* 004DD4 800299D4 0007000D */  break 7
.L800299D8:
/* 004DD8 800299D8 00001812 */  mflo  $v1
/* 004DDC 800299DC 0071102B */  sltu  $v0, $v1, $s1
/* 004DE0 800299E0 1040FFF8 */  beqz  $v0, .L800299C4
/* 004DE4 800299E4 0060102D */   daddu $v0, $v1, $zero
/* 004DE8 800299E8 8FBF0018 */  lw    $ra, 0x18($sp)
/* 004DEC 800299EC 8FB10014 */  lw    $s1, 0x14($sp)
/* 004DF0 800299F0 8FB00010 */  lw    $s0, 0x10($sp)
/* 004DF4 800299F4 03E00008 */  jr    $ra
/* 004DF8 800299F8 27BD0020 */   addiu $sp, $sp, 0x20

