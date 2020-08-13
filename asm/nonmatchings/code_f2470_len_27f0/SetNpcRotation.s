.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetNpcRotation
/* 0F2760 802CDDB0 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 0F2764 802CDDB4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F2768 802CDDB8 0080882D */  daddu $s1, $a0, $zero
/* 0F276C 802CDDBC AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F2770 802CDDC0 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F2774 802CDDC4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F2778 802CDDC8 F7B80030 */  sdc1  $f24, 0x30($sp)
/* 0F277C 802CDDCC F7B60028 */  sdc1  $f22, 0x28($sp)
/* 0F2780 802CDDD0 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0F2784 802CDDD4 8E30000C */  lw    $s0, 0xc($s1)
/* 0F2788 802CDDD8 8E050000 */  lw    $a1, ($s0)
/* 0F278C 802CDDDC 0C0B1EAF */  jal   get_variable
/* 0F2790 802CDDE0 26100004 */   addiu $s0, $s0, 4
/* 0F2794 802CDDE4 8E050000 */  lw    $a1, ($s0)
/* 0F2798 802CDDE8 26100004 */  addiu $s0, $s0, 4
/* 0F279C 802CDDEC 0220202D */  daddu $a0, $s1, $zero
/* 0F27A0 802CDDF0 0C0B210B */  jal   get_float_variable
/* 0F27A4 802CDDF4 0040902D */   daddu $s2, $v0, $zero
/* 0F27A8 802CDDF8 8E050000 */  lw    $a1, ($s0)
/* 0F27AC 802CDDFC 26100004 */  addiu $s0, $s0, 4
/* 0F27B0 802CDE00 0220202D */  daddu $a0, $s1, $zero
/* 0F27B4 802CDE04 0C0B210B */  jal   get_float_variable
/* 0F27B8 802CDE08 46000606 */   mov.s $f24, $f0
/* 0F27BC 802CDE0C 0220202D */  daddu $a0, $s1, $zero
/* 0F27C0 802CDE10 8E050000 */  lw    $a1, ($s0)
/* 0F27C4 802CDE14 0C0B210B */  jal   get_float_variable
/* 0F27C8 802CDE18 46000586 */   mov.s $f22, $f0
/* 0F27CC 802CDE1C 0220202D */  daddu $a0, $s1, $zero
/* 0F27D0 802CDE20 0240282D */  daddu $a1, $s2, $zero
/* 0F27D4 802CDE24 0C0B36B0 */  jal   func_802CDAC0
/* 0F27D8 802CDE28 46000506 */   mov.s $f20, $f0
/* 0F27DC 802CDE2C 0040182D */  daddu $v1, $v0, $zero
/* 0F27E0 802CDE30 10600004 */  beqz  $v1, .L802CDE44
/* 0F27E4 802CDE34 24020002 */   addiu $v0, $zero, 2
/* 0F27E8 802CDE38 E4780044 */  swc1  $f24, 0x44($v1)
/* 0F27EC 802CDE3C E4760048 */  swc1  $f22, 0x48($v1)
/* 0F27F0 802CDE40 E474004C */  swc1  $f20, 0x4c($v1)
.L802CDE44:
/* 0F27F4 802CDE44 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F27F8 802CDE48 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F27FC 802CDE4C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F2800 802CDE50 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F2804 802CDE54 D7B80030 */  ldc1  $f24, 0x30($sp)
/* 0F2808 802CDE58 D7B60028 */  ldc1  $f22, 0x28($sp)
/* 0F280C 802CDE5C D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0F2810 802CDE60 03E00008 */  jr    $ra
/* 0F2814 802CDE64 27BD0038 */   addiu $sp, $sp, 0x38

/* 0F2818 802CDE68 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F281C 802CDE6C AFB10014 */  sw    $s1, 0x14($sp)
/* 0F2820 802CDE70 0080882D */  daddu $s1, $a0, $zero
/* 0F2824 802CDE74 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0F2828 802CDE78 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F282C 802CDE7C F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0F2830 802CDE80 8E30000C */  lw    $s0, 0xc($s1)
/* 0F2834 802CDE84 8E050000 */  lw    $a1, ($s0)
/* 0F2838 802CDE88 0C0B1EAF */  jal   get_variable
/* 0F283C 802CDE8C 26100004 */   addiu $s0, $s0, 4
/* 0F2840 802CDE90 0220202D */  daddu $a0, $s1, $zero
/* 0F2844 802CDE94 8E050000 */  lw    $a1, ($s0)
/* 0F2848 802CDE98 0C0B210B */  jal   get_float_variable
/* 0F284C 802CDE9C 0040802D */   daddu $s0, $v0, $zero
/* 0F2850 802CDEA0 0220202D */  daddu $a0, $s1, $zero
/* 0F2854 802CDEA4 0200282D */  daddu $a1, $s0, $zero
/* 0F2858 802CDEA8 0C0B36B0 */  jal   func_802CDAC0
/* 0F285C 802CDEAC 46000506 */   mov.s $f20, $f0
/* 0F2860 802CDEB0 54400001 */  bnel  $v0, $zero, .L802CDEB8
/* 0F2864 802CDEB4 E4540050 */   swc1  $f20, 0x50($v0)
.L802CDEB8:
/* 0F2868 802CDEB8 24020002 */  addiu $v0, $zero, 2
/* 0F286C 802CDEBC 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0F2870 802CDEC0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F2874 802CDEC4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F2878 802CDEC8 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0F287C 802CDECC 03E00008 */  jr    $ra
/* 0F2880 802CDED0 27BD0028 */   addiu $sp, $sp, 0x28

