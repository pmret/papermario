.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024F7C8
/* 17E0A8 8024F7C8 0000382D */  daddu $a3, $zero, $zero
/* 17E0AC 8024F7CC 24090001 */  addiu $t1, $zero, 1
/* 17E0B0 8024F7D0 24080014 */  addiu $t0, $zero, 0x14
/* 17E0B4 8024F7D4 3C06802A */  lui   $a2, 0x802a
/* 17E0B8 8024F7D8 24C6F2C0 */  addiu $a2, $a2, -0xd40
.L8024F7DC:
/* 17E0BC 8024F7DC 84C20010 */  lh    $v0, 0x10($a2)
/* 17E0C0 8024F7E0 94C30010 */  lhu   $v1, 0x10($a2)
/* 17E0C4 8024F7E4 10400013 */  beqz  $v0, .L8024F834
/* 17E0C8 8024F7E8 30620010 */   andi  $v0, $v1, 0x10
/* 17E0CC 8024F7EC 50400012 */  beql  $v0, $zero, .L8024F838
/* 17E0D0 8024F7F0 24E70001 */   addiu $a3, $a3, 1
/* 17E0D4 8024F7F4 84C20012 */  lh    $v0, 0x12($a2)
/* 17E0D8 8024F7F8 8CC40018 */  lw    $a0, 0x18($a2)
/* 17E0DC 8024F7FC 1840000D */  blez  $v0, .L8024F834
/* 17E0E0 8024F800 0000282D */   daddu $a1, $zero, $zero
/* 17E0E4 8024F804 24830044 */  addiu $v1, $a0, 0x44
.L8024F808:
/* 17E0E8 8024F808 8C820000 */  lw    $v0, ($a0)
/* 17E0EC 8024F80C 10400004 */  beqz  $v0, .L8024F820
/* 17E0F0 8024F810 24A50001 */   addiu $a1, $a1, 1
/* 17E0F4 8024F814 AC60FFE0 */  sw    $zero, -0x20($v1)
/* 17E0F8 8024F818 AC69FFDC */  sw    $t1, -0x24($v1)
/* 17E0FC 8024F81C AC680000 */  sw    $t0, ($v1)
.L8024F820:
/* 17E100 8024F820 2463004C */  addiu $v1, $v1, 0x4c
/* 17E104 8024F824 84C20012 */  lh    $v0, 0x12($a2)
/* 17E108 8024F828 00A2102A */  slt   $v0, $a1, $v0
/* 17E10C 8024F82C 1440FFF6 */  bnez  $v0, .L8024F808
/* 17E110 8024F830 2484004C */   addiu $a0, $a0, 0x4c
.L8024F834:
/* 17E114 8024F834 24E70001 */  addiu $a3, $a3, 1
.L8024F838:
/* 17E118 8024F838 28E20020 */  slti  $v0, $a3, 0x20
/* 17E11C 8024F83C 1440FFE7 */  bnez  $v0, .L8024F7DC
/* 17E120 8024F840 24C6001C */   addiu $a2, $a2, 0x1c
/* 17E124 8024F844 03E00008 */  jr    $ra
/* 17E128 8024F848 00000000 */   nop   

/* 17E12C 8024F84C 27BDFFC8 */  addiu $sp, $sp, -0x38
/* 17E130 8024F850 AFB1001C */  sw    $s1, 0x1c($sp)
/* 17E134 8024F854 0080882D */  daddu $s1, $a0, $zero
/* 17E138 8024F858 AFBF0030 */  sw    $ra, 0x30($sp)
/* 17E13C 8024F85C AFB5002C */  sw    $s5, 0x2c($sp)
/* 17E140 8024F860 AFB40028 */  sw    $s4, 0x28($sp)
/* 17E144 8024F864 AFB30024 */  sw    $s3, 0x24($sp)
/* 17E148 8024F868 AFB20020 */  sw    $s2, 0x20($sp)
/* 17E14C 8024F86C AFB00018 */  sw    $s0, 0x18($sp)
/* 17E150 8024F870 8E30000C */  lw    $s0, 0xc($s1)
/* 17E154 8024F874 8E050000 */  lw    $a1, ($s0)
/* 17E158 8024F878 0C0B1EAF */  jal   get_variable
/* 17E15C 8024F87C 26100004 */   addiu $s0, $s0, 4
/* 17E160 8024F880 8E050000 */  lw    $a1, ($s0)
/* 17E164 8024F884 26100004 */  addiu $s0, $s0, 4
/* 17E168 8024F888 0220202D */  daddu $a0, $s1, $zero
/* 17E16C 8024F88C 0C0B1EAF */  jal   get_variable
/* 17E170 8024F890 0040A82D */   daddu $s5, $v0, $zero
/* 17E174 8024F894 8E050000 */  lw    $a1, ($s0)
/* 17E178 8024F898 26100004 */  addiu $s0, $s0, 4
/* 17E17C 8024F89C 0220202D */  daddu $a0, $s1, $zero
/* 17E180 8024F8A0 0C0B1EAF */  jal   get_variable
/* 17E184 8024F8A4 0040A02D */   daddu $s4, $v0, $zero
/* 17E188 8024F8A8 8E050000 */  lw    $a1, ($s0)
/* 17E18C 8024F8AC 26100004 */  addiu $s0, $s0, 4
/* 17E190 8024F8B0 0220202D */  daddu $a0, $s1, $zero
/* 17E194 8024F8B4 0C0B1EAF */  jal   get_variable
/* 17E198 8024F8B8 0040982D */   daddu $s3, $v0, $zero
/* 17E19C 8024F8BC 8E050000 */  lw    $a1, ($s0)
/* 17E1A0 8024F8C0 26100004 */  addiu $s0, $s0, 4
/* 17E1A4 8024F8C4 0220202D */  daddu $a0, $s1, $zero
/* 17E1A8 8024F8C8 0C0B1EAF */  jal   get_variable
/* 17E1AC 8024F8CC 0040902D */   daddu $s2, $v0, $zero
/* 17E1B0 8024F8D0 0220202D */  daddu $a0, $s1, $zero
/* 17E1B4 8024F8D4 8E050000 */  lw    $a1, ($s0)
/* 17E1B8 8024F8D8 0C0B1EAF */  jal   get_variable
/* 17E1BC 8024F8DC 0040802D */   daddu $s0, $v0, $zero
/* 17E1C0 8024F8E0 44956000 */  mtc1  $s5, $f12
/* 17E1C4 8024F8E4 00000000 */  nop   
/* 17E1C8 8024F8E8 46806320 */  cvt.s.w $f12, $f12
/* 17E1CC 8024F8EC 44947000 */  mtc1  $s4, $f14
/* 17E1D0 8024F8F0 00000000 */  nop   
/* 17E1D4 8024F8F4 468073A0 */  cvt.s.w $f14, $f14
/* 17E1D8 8024F8F8 44930000 */  mtc1  $s3, $f0
/* 17E1DC 8024F8FC 00000000 */  nop   
/* 17E1E0 8024F900 46800020 */  cvt.s.w $f0, $f0
/* 17E1E4 8024F904 44060000 */  mfc1  $a2, $f0
/* 17E1E8 8024F908 0240382D */  daddu $a3, $s2, $zero
/* 17E1EC 8024F90C AFB00010 */  sw    $s0, 0x10($sp)
/* 17E1F0 8024F910 0C093BF8 */  jal   func_8024EFE0
/* 17E1F4 8024F914 AFA20014 */   sw    $v0, 0x14($sp)
/* 17E1F8 8024F918 8FBF0030 */  lw    $ra, 0x30($sp)
/* 17E1FC 8024F91C 8FB5002C */  lw    $s5, 0x2c($sp)
/* 17E200 8024F920 8FB40028 */  lw    $s4, 0x28($sp)
/* 17E204 8024F924 8FB30024 */  lw    $s3, 0x24($sp)
/* 17E208 8024F928 8FB20020 */  lw    $s2, 0x20($sp)
/* 17E20C 8024F92C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 17E210 8024F930 8FB00018 */  lw    $s0, 0x18($sp)
/* 17E214 8024F934 24020002 */  addiu $v0, $zero, 2
/* 17E218 8024F938 03E00008 */  jr    $ra
/* 17E21C 8024F93C 27BD0038 */   addiu $sp, $sp, 0x38

/* 17E220 8024F940 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 17E224 8024F944 AFBF0010 */  sw    $ra, 0x10($sp)
/* 17E228 8024F948 0C093DF2 */  jal   func_8024F7C8
/* 17E22C 8024F94C 00000000 */   nop   
/* 17E230 8024F950 8FBF0010 */  lw    $ra, 0x10($sp)
/* 17E234 8024F954 24020002 */  addiu $v0, $zero, 2
/* 17E238 8024F958 03E00008 */  jr    $ra
/* 17E23C 8024F95C 27BD0018 */   addiu $sp, $sp, 0x18

