.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetCamPosB
/* 0F06A4 802CBCF4 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F06A8 802CBCF8 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F06AC 802CBCFC 0080902D */  daddu $s2, $a0, $zero
/* 0F06B0 802CBD00 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F06B4 802CBD04 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F06B8 802CBD08 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F06BC 802CBD0C F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0F06C0 802CBD10 8E51000C */  lw    $s1, 0xc($s2)
/* 0F06C4 802CBD14 8E250000 */  lw    $a1, ($s1)
/* 0F06C8 802CBD18 0C0B1EAF */  jal   get_variable
/* 0F06CC 802CBD1C 26310004 */   addiu $s1, $s1, 4
/* 0F06D0 802CBD20 8E250000 */  lw    $a1, ($s1)
/* 0F06D4 802CBD24 26310004 */  addiu $s1, $s1, 4
/* 0F06D8 802CBD28 0240202D */  daddu $a0, $s2, $zero
/* 0F06DC 802CBD2C 3C03800B */  lui   $v1, 0x800b
/* 0F06E0 802CBD30 24631D80 */  addiu $v1, $v1, 0x1d80
/* 0F06E4 802CBD34 00028080 */  sll   $s0, $v0, 2
/* 0F06E8 802CBD38 02028021 */  addu  $s0, $s0, $v0
/* 0F06EC 802CBD3C 00108080 */  sll   $s0, $s0, 2
/* 0F06F0 802CBD40 02028023 */  subu  $s0, $s0, $v0
/* 0F06F4 802CBD44 001010C0 */  sll   $v0, $s0, 3
/* 0F06F8 802CBD48 02028021 */  addu  $s0, $s0, $v0
/* 0F06FC 802CBD4C 001080C0 */  sll   $s0, $s0, 3
/* 0F0700 802CBD50 0C0B210B */  jal   get_float_variable
/* 0F0704 802CBD54 02038021 */   addu  $s0, $s0, $v1
/* 0F0708 802CBD58 0240202D */  daddu $a0, $s2, $zero
/* 0F070C 802CBD5C 8E250000 */  lw    $a1, ($s1)
/* 0F0710 802CBD60 0C0B210B */  jal   get_float_variable
/* 0F0714 802CBD64 46000506 */   mov.s $f20, $f0
/* 0F0718 802CBD68 E61404F0 */  swc1  $f20, 0x4f0($s0)
/* 0F071C 802CBD6C E60004F8 */  swc1  $f0, 0x4f8($s0)
/* 0F0720 802CBD70 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F0724 802CBD74 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F0728 802CBD78 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F072C 802CBD7C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F0730 802CBD80 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0F0734 802CBD84 24020002 */  addiu $v0, $zero, 2
/* 0F0738 802CBD88 03E00008 */  jr    $ra
/* 0F073C 802CBD8C 27BD0028 */   addiu $sp, $sp, 0x28

