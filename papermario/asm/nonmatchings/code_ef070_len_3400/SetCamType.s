.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetCamType
/* 0F0464 802CBAB4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F0468 802CBAB8 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F046C 802CBABC 0080902D */  daddu $s2, $a0, $zero
/* 0F0470 802CBAC0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F0474 802CBAC4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F0478 802CBAC8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F047C 802CBACC 8E51000C */  lw    $s1, 0xc($s2)
/* 0F0480 802CBAD0 8E250000 */  lw    $a1, ($s1)
/* 0F0484 802CBAD4 0C0B1EAF */  jal   get_variable
/* 0F0488 802CBAD8 26310004 */   addiu $s1, $s1, 4
/* 0F048C 802CBADC 8E250000 */  lw    $a1, ($s1)
/* 0F0490 802CBAE0 26310004 */  addiu $s1, $s1, 4
/* 0F0494 802CBAE4 0240202D */  daddu $a0, $s2, $zero
/* 0F0498 802CBAE8 3C03800B */  lui   $v1, 0x800b
/* 0F049C 802CBAEC 24631D80 */  addiu $v1, $v1, 0x1d80
/* 0F04A0 802CBAF0 00028080 */  sll   $s0, $v0, 2
/* 0F04A4 802CBAF4 02028021 */  addu  $s0, $s0, $v0
/* 0F04A8 802CBAF8 00108080 */  sll   $s0, $s0, 2
/* 0F04AC 802CBAFC 02028023 */  subu  $s0, $s0, $v0
/* 0F04B0 802CBB00 001010C0 */  sll   $v0, $s0, 3
/* 0F04B4 802CBB04 02028021 */  addu  $s0, $s0, $v0
/* 0F04B8 802CBB08 001080C0 */  sll   $s0, $s0, 3
/* 0F04BC 802CBB0C 0C0B1EAF */  jal   get_variable
/* 0F04C0 802CBB10 02038021 */   addu  $s0, $s0, $v1
/* 0F04C4 802CBB14 0240202D */  daddu $a0, $s2, $zero
/* 0F04C8 802CBB18 8E250000 */  lw    $a1, ($s1)
/* 0F04CC 802CBB1C 0C0B1EAF */  jal   get_variable
/* 0F04D0 802CBB20 0040882D */   daddu $s1, $v0, $zero
/* 0F04D4 802CBB24 AE020500 */  sw    $v0, 0x500($s0)
/* 0F04D8 802CBB28 AE1104D8 */  sw    $s1, 0x4d8($s0)
/* 0F04DC 802CBB2C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F04E0 802CBB30 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F04E4 802CBB34 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F04E8 802CBB38 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F04EC 802CBB3C 24020002 */  addiu $v0, $zero, 2
/* 0F04F0 802CBB40 03E00008 */  jr    $ra
/* 0F04F4 802CBB44 27BD0020 */   addiu $sp, $sp, 0x20

