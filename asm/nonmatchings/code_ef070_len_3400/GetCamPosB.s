.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetCamPosB
/* 0F0B34 802CC184 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F0B38 802CC188 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F0B3C 802CC18C 0080902D */  daddu $s2, $a0, $zero
/* 0F0B40 802CC190 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F0B44 802CC194 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F0B48 802CC198 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F0B4C 802CC19C 8E51000C */  lw    $s1, 0xc($s2)
/* 0F0B50 802CC1A0 8E250000 */  lw    $a1, ($s1)
/* 0F0B54 802CC1A4 0C0B1EAF */  jal   get_variable
/* 0F0B58 802CC1A8 26310004 */   addiu $s1, $s1, 4
/* 0F0B5C 802CC1AC 3C03800B */  lui   $v1, 0x800b
/* 0F0B60 802CC1B0 24631D80 */  addiu $v1, $v1, 0x1d80
/* 0F0B64 802CC1B4 00028080 */  sll   $s0, $v0, 2
/* 0F0B68 802CC1B8 02028021 */  addu  $s0, $s0, $v0
/* 0F0B6C 802CC1BC 00108080 */  sll   $s0, $s0, 2
/* 0F0B70 802CC1C0 02028023 */  subu  $s0, $s0, $v0
/* 0F0B74 802CC1C4 001010C0 */  sll   $v0, $s0, 3
/* 0F0B78 802CC1C8 02028021 */  addu  $s0, $s0, $v0
/* 0F0B7C 802CC1CC 001080C0 */  sll   $s0, $s0, 3
/* 0F0B80 802CC1D0 02038021 */  addu  $s0, $s0, $v1
/* 0F0B84 802CC1D4 8E250000 */  lw    $a1, ($s1)
/* 0F0B88 802CC1D8 8E0604F0 */  lw    $a2, 0x4f0($s0)
/* 0F0B8C 802CC1DC 8E310004 */  lw    $s1, 4($s1)
/* 0F0B90 802CC1E0 0C0B2190 */  jal   set_float_variable
/* 0F0B94 802CC1E4 0240202D */   daddu $a0, $s2, $zero
/* 0F0B98 802CC1E8 0240202D */  daddu $a0, $s2, $zero
/* 0F0B9C 802CC1EC 8E0604F8 */  lw    $a2, 0x4f8($s0)
/* 0F0BA0 802CC1F0 0C0B2190 */  jal   set_float_variable
/* 0F0BA4 802CC1F4 0220282D */   daddu $a1, $s1, $zero
/* 0F0BA8 802CC1F8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F0BAC 802CC1FC 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F0BB0 802CC200 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F0BB4 802CC204 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F0BB8 802CC208 24020002 */  addiu $v0, $zero, 2
/* 0F0BBC 802CC20C 03E00008 */  jr    $ra
/* 0F0BC0 802CC210 27BD0020 */   addiu $sp, $sp, 0x20

