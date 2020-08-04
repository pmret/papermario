.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetCamDistance
/* 0F0594 802CBBE4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F0598 802CBBE8 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F059C 802CBBEC 0080882D */  daddu $s1, $a0, $zero
/* 0F05A0 802CBBF0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F05A4 802CBBF4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F05A8 802CBBF8 8E30000C */  lw    $s0, 0xc($s1)
/* 0F05AC 802CBBFC 8E050000 */  lw    $a1, ($s0)
/* 0F05B0 802CBC00 0C0B1EAF */  jal   get_variable
/* 0F05B4 802CBC04 26100004 */   addiu $s0, $s0, 4
/* 0F05B8 802CBC08 0220202D */  daddu $a0, $s1, $zero
/* 0F05BC 802CBC0C 3C03800B */  lui   $v1, 0x800b
/* 0F05C0 802CBC10 24631D80 */  addiu $v1, $v1, 0x1d80
/* 0F05C4 802CBC14 8E050000 */  lw    $a1, ($s0)
/* 0F05C8 802CBC18 00028080 */  sll   $s0, $v0, 2
/* 0F05CC 802CBC1C 02028021 */  addu  $s0, $s0, $v0
/* 0F05D0 802CBC20 00108080 */  sll   $s0, $s0, 2
/* 0F05D4 802CBC24 02028023 */  subu  $s0, $s0, $v0
/* 0F05D8 802CBC28 001010C0 */  sll   $v0, $s0, 3
/* 0F05DC 802CBC2C 02028021 */  addu  $s0, $s0, $v0
/* 0F05E0 802CBC30 001080C0 */  sll   $s0, $s0, 3
/* 0F05E4 802CBC34 0C0B210B */  jal   get_float_variable
/* 0F05E8 802CBC38 02038021 */   addu  $s0, $s0, $v1
/* 0F05EC 802CBC3C E60004DC */  swc1  $f0, 0x4dc($s0)
/* 0F05F0 802CBC40 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F05F4 802CBC44 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F05F8 802CBC48 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F05FC 802CBC4C 24020002 */  addiu $v0, $zero, 2
/* 0F0600 802CBC50 03E00008 */  jr    $ra
/* 0F0604 802CBC54 27BD0020 */   addiu $sp, $sp, 0x20

