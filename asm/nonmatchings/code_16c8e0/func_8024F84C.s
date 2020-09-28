.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024F84C
/* 17E12C 8024F84C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 17E130 8024F850 AFB1001C */  sw        $s1, 0x1c($sp)
/* 17E134 8024F854 0080882D */  daddu     $s1, $a0, $zero
/* 17E138 8024F858 AFBF0030 */  sw        $ra, 0x30($sp)
/* 17E13C 8024F85C AFB5002C */  sw        $s5, 0x2c($sp)
/* 17E140 8024F860 AFB40028 */  sw        $s4, 0x28($sp)
/* 17E144 8024F864 AFB30024 */  sw        $s3, 0x24($sp)
/* 17E148 8024F868 AFB20020 */  sw        $s2, 0x20($sp)
/* 17E14C 8024F86C AFB00018 */  sw        $s0, 0x18($sp)
/* 17E150 8024F870 8E30000C */  lw        $s0, 0xc($s1)
/* 17E154 8024F874 8E050000 */  lw        $a1, ($s0)
/* 17E158 8024F878 0C0B1EAF */  jal       get_variable
/* 17E15C 8024F87C 26100004 */   addiu    $s0, $s0, 4
/* 17E160 8024F880 8E050000 */  lw        $a1, ($s0)
/* 17E164 8024F884 26100004 */  addiu     $s0, $s0, 4
/* 17E168 8024F888 0220202D */  daddu     $a0, $s1, $zero
/* 17E16C 8024F88C 0C0B1EAF */  jal       get_variable
/* 17E170 8024F890 0040A82D */   daddu    $s5, $v0, $zero
/* 17E174 8024F894 8E050000 */  lw        $a1, ($s0)
/* 17E178 8024F898 26100004 */  addiu     $s0, $s0, 4
/* 17E17C 8024F89C 0220202D */  daddu     $a0, $s1, $zero
/* 17E180 8024F8A0 0C0B1EAF */  jal       get_variable
/* 17E184 8024F8A4 0040A02D */   daddu    $s4, $v0, $zero
/* 17E188 8024F8A8 8E050000 */  lw        $a1, ($s0)
/* 17E18C 8024F8AC 26100004 */  addiu     $s0, $s0, 4
/* 17E190 8024F8B0 0220202D */  daddu     $a0, $s1, $zero
/* 17E194 8024F8B4 0C0B1EAF */  jal       get_variable
/* 17E198 8024F8B8 0040982D */   daddu    $s3, $v0, $zero
/* 17E19C 8024F8BC 8E050000 */  lw        $a1, ($s0)
/* 17E1A0 8024F8C0 26100004 */  addiu     $s0, $s0, 4
/* 17E1A4 8024F8C4 0220202D */  daddu     $a0, $s1, $zero
/* 17E1A8 8024F8C8 0C0B1EAF */  jal       get_variable
/* 17E1AC 8024F8CC 0040902D */   daddu    $s2, $v0, $zero
/* 17E1B0 8024F8D0 0220202D */  daddu     $a0, $s1, $zero
/* 17E1B4 8024F8D4 8E050000 */  lw        $a1, ($s0)
/* 17E1B8 8024F8D8 0C0B1EAF */  jal       get_variable
/* 17E1BC 8024F8DC 0040802D */   daddu    $s0, $v0, $zero
/* 17E1C0 8024F8E0 44956000 */  mtc1      $s5, $f12
/* 17E1C4 8024F8E4 00000000 */  nop       
/* 17E1C8 8024F8E8 46806320 */  cvt.s.w   $f12, $f12
/* 17E1CC 8024F8EC 44947000 */  mtc1      $s4, $f14
/* 17E1D0 8024F8F0 00000000 */  nop       
/* 17E1D4 8024F8F4 468073A0 */  cvt.s.w   $f14, $f14
/* 17E1D8 8024F8F8 44930000 */  mtc1      $s3, $f0
/* 17E1DC 8024F8FC 00000000 */  nop       
/* 17E1E0 8024F900 46800020 */  cvt.s.w   $f0, $f0
/* 17E1E4 8024F904 44060000 */  mfc1      $a2, $f0
/* 17E1E8 8024F908 0240382D */  daddu     $a3, $s2, $zero
/* 17E1EC 8024F90C AFB00010 */  sw        $s0, 0x10($sp)
/* 17E1F0 8024F910 0C093BF8 */  jal       func_8024EFE0
/* 17E1F4 8024F914 AFA20014 */   sw       $v0, 0x14($sp)
/* 17E1F8 8024F918 8FBF0030 */  lw        $ra, 0x30($sp)
/* 17E1FC 8024F91C 8FB5002C */  lw        $s5, 0x2c($sp)
/* 17E200 8024F920 8FB40028 */  lw        $s4, 0x28($sp)
/* 17E204 8024F924 8FB30024 */  lw        $s3, 0x24($sp)
/* 17E208 8024F928 8FB20020 */  lw        $s2, 0x20($sp)
/* 17E20C 8024F92C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 17E210 8024F930 8FB00018 */  lw        $s0, 0x18($sp)
/* 17E214 8024F934 24020002 */  addiu     $v0, $zero, 2
/* 17E218 8024F938 03E00008 */  jr        $ra
/* 17E21C 8024F93C 27BD0038 */   addiu    $sp, $sp, 0x38
