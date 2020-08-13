.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel AwaitPlayerApproach
/* 0F925C 802D48AC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0F9260 802D48B0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F9264 802D48B4 0080882D */  daddu $s1, $a0, $zero
/* 0F9268 802D48B8 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F926C 802D48BC 3C128011 */  lui   $s2, 0x8011
/* 0F9270 802D48C0 2652EFC8 */  addiu $s2, $s2, -0x1038
/* 0F9274 802D48C4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F9278 802D48C8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F927C 802D48CC 10A0000E */  beqz  $a1, .L802D4908
/* 0F9280 802D48D0 8E30000C */   lw    $s0, 0xc($s1)
/* 0F9284 802D48D4 8E050000 */  lw    $a1, ($s0)
/* 0F9288 802D48D8 0C0B1EAF */  jal   get_variable
/* 0F928C 802D48DC 26100004 */   addiu $s0, $s0, 4
/* 0F9290 802D48E0 AE220070 */  sw    $v0, 0x70($s1)
/* 0F9294 802D48E4 8E050000 */  lw    $a1, ($s0)
/* 0F9298 802D48E8 26100004 */  addiu $s0, $s0, 4
/* 0F929C 802D48EC 0C0B1EAF */  jal   get_variable
/* 0F92A0 802D48F0 0220202D */   daddu $a0, $s1, $zero
/* 0F92A4 802D48F4 AE220074 */  sw    $v0, 0x74($s1)
/* 0F92A8 802D48F8 8E050000 */  lw    $a1, ($s0)
/* 0F92AC 802D48FC 0C0B1EAF */  jal   get_variable
/* 0F92B0 802D4900 0220202D */   daddu $a0, $s1, $zero
/* 0F92B4 802D4904 AE220078 */  sw    $v0, 0x78($s1)
.L802D4908:
/* 0F92B8 802D4908 C6240070 */  lwc1  $f4, 0x70($s1)
/* 0F92BC 802D490C 46802120 */  cvt.s.w $f4, $f4
/* 0F92C0 802D4910 44062000 */  mfc1  $a2, $f4
/* 0F92C4 802D4914 C6240074 */  lwc1  $f4, 0x74($s1)
/* 0F92C8 802D4918 46802120 */  cvt.s.w $f4, $f4
/* 0F92CC 802D491C C64C0028 */  lwc1  $f12, 0x28($s2)
/* 0F92D0 802D4920 C64E0030 */  lwc1  $f14, 0x30($s2)
/* 0F92D4 802D4924 44072000 */  mfc1  $a3, $f4
/* 0F92D8 802D4928 0C00A7B5 */  jal   dist2D
/* 0F92DC 802D492C 00000000 */   nop   
/* 0F92E0 802D4930 C6220078 */  lwc1  $f2, 0x78($s1)
/* 0F92E4 802D4934 468010A0 */  cvt.s.w $f2, $f2
/* 0F92E8 802D4938 4602003C */  c.lt.s $f0, $f2
/* 0F92EC 802D493C 00000000 */  nop   
/* 0F92F0 802D4940 45010002 */  bc1t  .L802D494C
/* 0F92F4 802D4944 24020002 */   addiu $v0, $zero, 2
/* 0F92F8 802D4948 0000102D */  daddu $v0, $zero, $zero
.L802D494C:
/* 0F92FC 802D494C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F9300 802D4950 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F9304 802D4954 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F9308 802D4958 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F930C 802D495C 03E00008 */  jr    $ra
/* 0F9310 802D4960 27BD0020 */   addiu $sp, $sp, 0x20

