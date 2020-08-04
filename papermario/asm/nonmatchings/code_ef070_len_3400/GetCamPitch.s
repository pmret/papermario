.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetCamPitch
/* 0F09A4 802CBFF4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F09A8 802CBFF8 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F09AC 802CBFFC 0080902D */  daddu $s2, $a0, $zero
/* 0F09B0 802CC000 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F09B4 802CC004 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F09B8 802CC008 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F09BC 802CC00C 8E51000C */  lw    $s1, 0xc($s2)
/* 0F09C0 802CC010 8E250000 */  lw    $a1, ($s1)
/* 0F09C4 802CC014 0C0B1EAF */  jal   get_variable
/* 0F09C8 802CC018 26310004 */   addiu $s1, $s1, 4
/* 0F09CC 802CC01C 3C03800B */  lui   $v1, 0x800b
/* 0F09D0 802CC020 24631D80 */  addiu $v1, $v1, 0x1d80
/* 0F09D4 802CC024 00028080 */  sll   $s0, $v0, 2
/* 0F09D8 802CC028 02028021 */  addu  $s0, $s0, $v0
/* 0F09DC 802CC02C 00108080 */  sll   $s0, $s0, 2
/* 0F09E0 802CC030 02028023 */  subu  $s0, $s0, $v0
/* 0F09E4 802CC034 001010C0 */  sll   $v0, $s0, 3
/* 0F09E8 802CC038 02028021 */  addu  $s0, $s0, $v0
/* 0F09EC 802CC03C 001080C0 */  sll   $s0, $s0, 3
/* 0F09F0 802CC040 02038021 */  addu  $s0, $s0, $v1
/* 0F09F4 802CC044 8E250000 */  lw    $a1, ($s1)
/* 0F09F8 802CC048 8E0604E0 */  lw    $a2, 0x4e0($s0)
/* 0F09FC 802CC04C 8E310004 */  lw    $s1, 4($s1)
/* 0F0A00 802CC050 0C0B2190 */  jal   set_float_variable
/* 0F0A04 802CC054 0240202D */   daddu $a0, $s2, $zero
/* 0F0A08 802CC058 0240202D */  daddu $a0, $s2, $zero
/* 0F0A0C 802CC05C 8E0604FC */  lw    $a2, 0x4fc($s0)
/* 0F0A10 802CC060 0C0B2190 */  jal   set_float_variable
/* 0F0A14 802CC064 0220282D */   daddu $a1, $s1, $zero
/* 0F0A18 802CC068 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F0A1C 802CC06C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F0A20 802CC070 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F0A24 802CC074 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F0A28 802CC078 24020002 */  addiu $v0, $zero, 2
/* 0F0A2C 802CC07C 03E00008 */  jr    $ra
/* 0F0A30 802CC080 27BD0020 */   addiu $sp, $sp, 0x20

