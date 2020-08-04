.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetNpcPos
/* 0F2660 802CDCB0 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0F2664 802CDCB4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F2668 802CDCB8 0080882D */  daddu $s1, $a0, $zero
/* 0F266C 802CDCBC AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F2670 802CDCC0 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F2674 802CDCC4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F2678 802CDCC8 F7B80030 */  sdc1  $f24, 0x30($sp)
/* 0F267C 802CDCCC F7B60028 */  sdc1  $f22, 0x28($sp)
/* 0F2680 802CDCD0 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0F2684 802CDCD4 8E30000C */  lw    $s0, 0xc($s1)
/* 0F2688 802CDCD8 8E050000 */  lw    $a1, ($s0)
/* 0F268C 802CDCDC 0C0B1EAF */  jal   get_variable
/* 0F2690 802CDCE0 26100004 */   addiu $s0, $s0, 4
/* 0F2694 802CDCE4 8E050000 */  lw    $a1, ($s0)
/* 0F2698 802CDCE8 26100004 */  addiu $s0, $s0, 4
/* 0F269C 802CDCEC 0220202D */  daddu $a0, $s1, $zero
/* 0F26A0 802CDCF0 0C0B1EAF */  jal   get_variable
/* 0F26A4 802CDCF4 0040902D */   daddu $s2, $v0, $zero
/* 0F26A8 802CDCF8 8E050000 */  lw    $a1, ($s0)
/* 0F26AC 802CDCFC 26100004 */  addiu $s0, $s0, 4
/* 0F26B0 802CDD00 4482C000 */  mtc1  $v0, $f24
/* 0F26B4 802CDD04 00000000 */  nop   
/* 0F26B8 802CDD08 4680C620 */  cvt.s.w $f24, $f24
/* 0F26BC 802CDD0C 0C0B1EAF */  jal   get_variable
/* 0F26C0 802CDD10 0220202D */   daddu $a0, $s1, $zero
/* 0F26C4 802CDD14 8E050000 */  lw    $a1, ($s0)
/* 0F26C8 802CDD18 4482B000 */  mtc1  $v0, $f22
/* 0F26CC 802CDD1C 00000000 */  nop   
/* 0F26D0 802CDD20 4680B5A0 */  cvt.s.w $f22, $f22
/* 0F26D4 802CDD24 0C0B1EAF */  jal   get_variable
/* 0F26D8 802CDD28 0220202D */   daddu $a0, $s1, $zero
/* 0F26DC 802CDD2C 0220202D */  daddu $a0, $s1, $zero
/* 0F26E0 802CDD30 4482A000 */  mtc1  $v0, $f20
/* 0F26E4 802CDD34 00000000 */  nop   
/* 0F26E8 802CDD38 4680A520 */  cvt.s.w $f20, $f20
/* 0F26EC 802CDD3C 0C0B36B0 */  jal   func_802CDAC0
/* 0F26F0 802CDD40 0240282D */   daddu $a1, $s2, $zero
/* 0F26F4 802CDD44 0040282D */  daddu $a1, $v0, $zero
/* 0F26F8 802CDD48 10A0000F */  beqz  $a1, .L802CDD88
/* 0F26FC 802CDD4C 4600C006 */   mov.s $f0, $f24
/* 0F2700 802CDD50 E4B80038 */  swc1  $f24, 0x38($a1)
/* 0F2704 802CDD54 E4B6003C */  swc1  $f22, 0x3c($a1)
/* 0F2708 802CDD58 4600B086 */  mov.s $f2, $f22
/* 0F270C 802CDD5C E4B40040 */  swc1  $f20, 0x40($a1)
/* 0F2710 802CDD60 4600A106 */  mov.s $f4, $f20
/* 0F2714 802CDD64 24020002 */  addiu $v0, $zero, 2
/* 0F2718 802CDD68 8CA30000 */  lw    $v1, ($a1)
/* 0F271C 802CDD6C 3C040001 */  lui   $a0, 1
/* 0F2720 802CDD70 E4A0006C */  swc1  $f0, 0x6c($a1)
/* 0F2724 802CDD74 E4A20070 */  swc1  $f2, 0x70($a1)
/* 0F2728 802CDD78 E4A40074 */  swc1  $f4, 0x74($a1)
/* 0F272C 802CDD7C 00641825 */  or    $v1, $v1, $a0
/* 0F2730 802CDD80 080B3763 */  j     .L802CDD8C
/* 0F2734 802CDD84 ACA30000 */   sw    $v1, ($a1)

.L802CDD88:
/* 0F2738 802CDD88 24020002 */  addiu $v0, $zero, 2
.L802CDD8C:
/* 0F273C 802CDD8C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F2740 802CDD90 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F2744 802CDD94 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F2748 802CDD98 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F274C 802CDD9C D7B80030 */  ldc1  $f24, 0x30($sp)
/* 0F2750 802CDDA0 D7B60028 */  ldc1  $f22, 0x28($sp)
/* 0F2754 802CDDA4 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0F2758 802CDDA8 03E00008 */  jr    $ra
/* 0F275C 802CDDAC 27BD0038 */   addiu $sp, $sp, 0x38

