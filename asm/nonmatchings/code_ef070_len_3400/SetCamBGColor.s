.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetCamBGColor
/* 0EF748 802CAD98 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0EF74C 802CAD9C AFB10014 */  sw    $s1, 0x14($sp)
/* 0EF750 802CADA0 0080882D */  daddu $s1, $a0, $zero
/* 0EF754 802CADA4 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0EF758 802CADA8 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0EF75C 802CADAC AFB20018 */  sw    $s2, 0x18($sp)
/* 0EF760 802CADB0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EF764 802CADB4 8E30000C */  lw    $s0, 0xc($s1)
/* 0EF768 802CADB8 8E050000 */  lw    $a1, ($s0)
/* 0EF76C 802CADBC 0C0B1EAF */  jal   get_variable
/* 0EF770 802CADC0 26100004 */   addiu $s0, $s0, 4
/* 0EF774 802CADC4 8E050000 */  lw    $a1, ($s0)
/* 0EF778 802CADC8 26100004 */  addiu $s0, $s0, 4
/* 0EF77C 802CADCC 0220202D */  daddu $a0, $s1, $zero
/* 0EF780 802CADD0 0C0B1EAF */  jal   get_variable
/* 0EF784 802CADD4 0040902D */   daddu $s2, $v0, $zero
/* 0EF788 802CADD8 8E050000 */  lw    $a1, ($s0)
/* 0EF78C 802CADDC 26100004 */  addiu $s0, $s0, 4
/* 0EF790 802CADE0 0220202D */  daddu $a0, $s1, $zero
/* 0EF794 802CADE4 0C0B1EAF */  jal   get_variable
/* 0EF798 802CADE8 0040982D */   daddu $s3, $v0, $zero
/* 0EF79C 802CADEC 0220202D */  daddu $a0, $s1, $zero
/* 0EF7A0 802CADF0 8E050000 */  lw    $a1, ($s0)
/* 0EF7A4 802CADF4 0C0B1EAF */  jal   get_variable
/* 0EF7A8 802CADF8 0040802D */   daddu $s0, $v0, $zero
/* 0EF7AC 802CADFC 3C05800B */  lui   $a1, 0x800b
/* 0EF7B0 802CAE00 24A51D80 */  addiu $a1, $a1, 0x1d80
/* 0EF7B4 802CAE04 00121880 */  sll   $v1, $s2, 2
/* 0EF7B8 802CAE08 00721821 */  addu  $v1, $v1, $s2
/* 0EF7BC 802CAE0C 00031880 */  sll   $v1, $v1, 2
/* 0EF7C0 802CAE10 00721823 */  subu  $v1, $v1, $s2
/* 0EF7C4 802CAE14 000320C0 */  sll   $a0, $v1, 3
/* 0EF7C8 802CAE18 00641821 */  addu  $v1, $v1, $a0
/* 0EF7CC 802CAE1C 000318C0 */  sll   $v1, $v1, 3
/* 0EF7D0 802CAE20 00651821 */  addu  $v1, $v1, $a1
/* 0EF7D4 802CAE24 A4620030 */  sh    $v0, 0x30($v1)
/* 0EF7D8 802CAE28 A473002C */  sh    $s3, 0x2c($v1)
/* 0EF7DC 802CAE2C A470002E */  sh    $s0, 0x2e($v1)
/* 0EF7E0 802CAE30 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0EF7E4 802CAE34 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0EF7E8 802CAE38 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EF7EC 802CAE3C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EF7F0 802CAE40 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EF7F4 802CAE44 24020002 */  addiu $v0, $zero, 2
/* 0EF7F8 802CAE48 03E00008 */  jr    $ra
/* 0EF7FC 802CAE4C 27BD0028 */   addiu $sp, $sp, 0x28

/* 0EF800 802CAE50 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0EF804 802CAE54 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EF808 802CAE58 0080882D */  daddu $s1, $a0, $zero
/* 0EF80C 802CAE5C AFBF0020 */  sw    $ra, 0x20($sp)
/* 0EF810 802CAE60 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0EF814 802CAE64 AFB20018 */  sw    $s2, 0x18($sp)
/* 0EF818 802CAE68 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EF81C 802CAE6C 8E30000C */  lw    $s0, 0xc($s1)
/* 0EF820 802CAE70 8E050000 */  lw    $a1, ($s0)
/* 0EF824 802CAE74 0C0B1EAF */  jal   get_variable
/* 0EF828 802CAE78 26100004 */   addiu $s0, $s0, 4
/* 0EF82C 802CAE7C 8E050000 */  lw    $a1, ($s0)
/* 0EF830 802CAE80 26100004 */  addiu $s0, $s0, 4
/* 0EF834 802CAE84 0220202D */  daddu $a0, $s1, $zero
/* 0EF838 802CAE88 0C0B1EAF */  jal   get_variable
/* 0EF83C 802CAE8C 0040902D */   daddu $s2, $v0, $zero
/* 0EF840 802CAE90 8E050000 */  lw    $a1, ($s0)
/* 0EF844 802CAE94 26100004 */  addiu $s0, $s0, 4
/* 0EF848 802CAE98 0220202D */  daddu $a0, $s1, $zero
/* 0EF84C 802CAE9C 0C0B1EAF */  jal   get_variable
/* 0EF850 802CAEA0 0040982D */   daddu $s3, $v0, $zero
/* 0EF854 802CAEA4 0220202D */  daddu $a0, $s1, $zero
/* 0EF858 802CAEA8 8E050000 */  lw    $a1, ($s0)
/* 0EF85C 802CAEAC 0C0B1EAF */  jal   get_variable
/* 0EF860 802CAEB0 0040802D */   daddu $s0, $v0, $zero
/* 0EF864 802CAEB4 44821000 */  mtc1  $v0, $f2
/* 0EF868 802CAEB8 00000000 */  nop   
/* 0EF86C 802CAEBC 468010A0 */  cvt.s.w $f2, $f2
/* 0EF870 802CAEC0 24020002 */  addiu $v0, $zero, 2
/* 0EF874 802CAEC4 3C05800B */  lui   $a1, 0x800b
/* 0EF878 802CAEC8 24A51D80 */  addiu $a1, $a1, 0x1d80
/* 0EF87C 802CAECC 00521804 */  sllv  $v1, $s2, $v0
/* 0EF880 802CAED0 00721821 */  addu  $v1, $v1, $s2
/* 0EF884 802CAED4 00431804 */  sllv  $v1, $v1, $v0
/* 0EF888 802CAED8 00721823 */  subu  $v1, $v1, $s2
/* 0EF88C 802CAEDC 000320C0 */  sll   $a0, $v1, 3
/* 0EF890 802CAEE0 00641821 */  addu  $v1, $v1, $a0
/* 0EF894 802CAEE4 000318C0 */  sll   $v1, $v1, 3
/* 0EF898 802CAEE8 00651821 */  addu  $v1, $v1, $a1
/* 0EF89C 802CAEEC 44930000 */  mtc1  $s3, $f0
/* 0EF8A0 802CAEF0 00000000 */  nop   
/* 0EF8A4 802CAEF4 46800020 */  cvt.s.w $f0, $f0
/* 0EF8A8 802CAEF8 E4600054 */  swc1  $f0, 0x54($v1)
/* 0EF8AC 802CAEFC 44900000 */  mtc1  $s0, $f0
/* 0EF8B0 802CAF00 00000000 */  nop   
/* 0EF8B4 802CAF04 46800020 */  cvt.s.w $f0, $f0
/* 0EF8B8 802CAF08 E4600058 */  swc1  $f0, 0x58($v1)
/* 0EF8BC 802CAF0C E462005C */  swc1  $f2, 0x5c($v1)
/* 0EF8C0 802CAF10 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0EF8C4 802CAF14 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0EF8C8 802CAF18 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EF8CC 802CAF1C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EF8D0 802CAF20 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EF8D4 802CAF24 03E00008 */  jr    $ra
/* 0EF8D8 802CAF28 27BD0028 */   addiu $sp, $sp, 0x28

