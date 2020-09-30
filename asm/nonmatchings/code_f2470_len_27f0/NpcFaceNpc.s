.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel NpcFaceNpc
/* F3830 802CEE80 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* F3834 802CEE84 AFB10014 */  sw        $s1, 0x14($sp)
/* F3838 802CEE88 0080882D */  daddu     $s1, $a0, $zero
/* F383C 802CEE8C AFB60028 */  sw        $s6, 0x28($sp)
/* F3840 802CEE90 26360074 */  addiu     $s6, $s1, 0x74
/* F3844 802CEE94 AFB50024 */  sw        $s5, 0x24($sp)
/* F3848 802CEE98 26350078 */  addiu     $s5, $s1, 0x78
/* F384C 802CEE9C AFB40020 */  sw        $s4, 0x20($sp)
/* F3850 802CEEA0 AFBF002C */  sw        $ra, 0x2c($sp)
/* F3854 802CEEA4 AFB3001C */  sw        $s3, 0x1c($sp)
/* F3858 802CEEA8 AFB20018 */  sw        $s2, 0x18($sp)
/* F385C 802CEEAC AFB00010 */  sw        $s0, 0x10($sp)
/* F3860 802CEEB0 8E32000C */  lw        $s2, 0xc($s1)
/* F3864 802CEEB4 10A00040 */  beqz      $a1, .L802CEFB8
/* F3868 802CEEB8 2634007C */   addiu    $s4, $s1, 0x7c
/* F386C 802CEEBC 8E450000 */  lw        $a1, ($s2)
/* F3870 802CEEC0 0C0B1EAF */  jal       get_variable
/* F3874 802CEEC4 26520004 */   addiu    $s2, $s2, 4
/* F3878 802CEEC8 8E450000 */  lw        $a1, ($s2)
/* F387C 802CEECC 26520004 */  addiu     $s2, $s2, 4
/* F3880 802CEED0 0220202D */  daddu     $a0, $s1, $zero
/* F3884 802CEED4 0C0B1EAF */  jal       get_variable
/* F3888 802CEED8 0040802D */   daddu    $s0, $v0, $zero
/* F388C 802CEEDC 0220202D */  daddu     $a0, $s1, $zero
/* F3890 802CEEE0 0C0B36B0 */  jal       resolve_npc
/* F3894 802CEEE4 0040282D */   daddu    $a1, $v0, $zero
/* F3898 802CEEE8 0040982D */  daddu     $s3, $v0, $zero
/* F389C 802CEEEC 12600006 */  beqz      $s3, .L802CEF08
/* F38A0 802CEEF0 0220202D */   daddu    $a0, $s1, $zero
/* F38A4 802CEEF4 0C0B36B0 */  jal       resolve_npc
/* F38A8 802CEEF8 0200282D */   daddu    $a1, $s0, $zero
/* F38AC 802CEEFC 0040802D */  daddu     $s0, $v0, $zero
/* F38B0 802CEF00 16000003 */  bnez      $s0, .L802CEF10
/* F38B4 802CEF04 00000000 */   nop      
.L802CEF08:
/* F38B8 802CEF08 080B3C0E */  j         .L802CF038
/* F38BC 802CEF0C 24020002 */   addiu    $v0, $zero, 2
.L802CEF10:
/* F38C0 802CEF10 C600000C */  lwc1      $f0, 0xc($s0)
/* F38C4 802CEF14 E6200074 */  swc1      $f0, 0x74($s1)
/* F38C8 802CEF18 C60C0038 */  lwc1      $f12, 0x38($s0)
/* F38CC 802CEF1C C60E0040 */  lwc1      $f14, 0x40($s0)
/* F38D0 802CEF20 8E660038 */  lw        $a2, 0x38($s3)
/* F38D4 802CEF24 0C00A720 */  jal       atan2
/* F38D8 802CEF28 8E670040 */   lw       $a3, 0x40($s3)
/* F38DC 802CEF2C C6220074 */  lwc1      $f2, 0x74($s1)
/* F38E0 802CEF30 46020001 */  sub.s     $f0, $f0, $f2
/* F38E4 802CEF34 AE300070 */  sw        $s0, 0x70($s1)
/* F38E8 802CEF38 E6200078 */  swc1      $f0, 0x78($s1)
/* F38EC 802CEF3C 8E450000 */  lw        $a1, ($s2)
/* F38F0 802CEF40 0C0B1EAF */  jal       get_variable
/* F38F4 802CEF44 0220202D */   daddu    $a0, $s1, $zero
/* F38F8 802CEF48 AE22007C */  sw        $v0, 0x7c($s1)
/* F38FC 802CEF4C A600008E */  sh        $zero, 0x8e($s0)
/* F3900 802CEF50 C6220078 */  lwc1      $f2, 0x78($s1)
/* F3904 802CEF54 3C01C334 */  lui       $at, 0xc334
/* F3908 802CEF58 44810000 */  mtc1      $at, $f0
/* F390C 802CEF5C 00000000 */  nop       
/* F3910 802CEF60 4600103C */  c.lt.s    $f2, $f0
/* F3914 802CEF64 00000000 */  nop       
/* F3918 802CEF68 45000007 */  bc1f      .L802CEF88
/* F391C 802CEF6C 00000000 */   nop      
/* F3920 802CEF70 3C0143B4 */  lui       $at, 0x43b4
/* F3924 802CEF74 44810000 */  mtc1      $at, $f0
/* F3928 802CEF78 00000000 */  nop       
/* F392C 802CEF7C 46001000 */  add.s     $f0, $f2, $f0
/* F3930 802CEF80 E6200078 */  swc1      $f0, 0x78($s1)
/* F3934 802CEF84 C6220078 */  lwc1      $f2, 0x78($s1)
.L802CEF88:
/* F3938 802CEF88 3C014334 */  lui       $at, 0x4334
/* F393C 802CEF8C 44810000 */  mtc1      $at, $f0
/* F3940 802CEF90 00000000 */  nop       
/* F3944 802CEF94 4602003C */  c.lt.s    $f0, $f2
/* F3948 802CEF98 00000000 */  nop       
/* F394C 802CEF9C 45000006 */  bc1f      .L802CEFB8
/* F3950 802CEFA0 00000000 */   nop      
/* F3954 802CEFA4 3C0143B4 */  lui       $at, 0x43b4
/* F3958 802CEFA8 44810000 */  mtc1      $at, $f0
/* F395C 802CEFAC 00000000 */  nop       
/* F3960 802CEFB0 46001001 */  sub.s     $f0, $f2, $f0
/* F3964 802CEFB4 E6200078 */  swc1      $f0, 0x78($s1)
.L802CEFB8:
/* F3968 802CEFB8 8E820000 */  lw        $v0, ($s4)
/* F396C 802CEFBC 8E300070 */  lw        $s0, 0x70($s1)
/* F3970 802CEFC0 1C400006 */  bgtz      $v0, .L802CEFDC
/* F3974 802CEFC4 24020002 */   addiu    $v0, $zero, 2
/* F3978 802CEFC8 C600000C */  lwc1      $f0, 0xc($s0)
/* F397C 802CEFCC C6A20000 */  lwc1      $f2, ($s5)
/* F3980 802CEFD0 46020000 */  add.s     $f0, $f0, $f2
/* F3984 802CEFD4 080B3C0E */  j         .L802CF038
/* F3988 802CEFD8 E600000C */   swc1     $f0, 0xc($s0)
.L802CEFDC:
/* F398C 802CEFDC 9602008E */  lhu       $v0, 0x8e($s0)
/* F3990 802CEFE0 24420001 */  addiu     $v0, $v0, 1
/* F3994 802CEFE4 A602008E */  sh        $v0, 0x8e($s0)
/* F3998 802CEFE8 00021400 */  sll       $v0, $v0, 0x10
/* F399C 802CEFEC 00021403 */  sra       $v0, $v0, 0x10
/* F39A0 802CEFF0 C6A00000 */  lwc1      $f0, ($s5)
/* F39A4 802CEFF4 44821000 */  mtc1      $v0, $f2
/* F39A8 802CEFF8 00000000 */  nop       
/* F39AC 802CEFFC 468010A0 */  cvt.s.w   $f2, $f2
/* F39B0 802CF000 46020002 */  mul.s     $f0, $f0, $f2
/* F39B4 802CF004 00000000 */  nop       
/* F39B8 802CF008 C6CC0000 */  lwc1      $f12, ($s6)
/* F39BC 802CF00C C6820000 */  lwc1      $f2, ($s4)
/* F39C0 802CF010 468010A0 */  cvt.s.w   $f2, $f2
/* F39C4 802CF014 46020003 */  div.s     $f0, $f0, $f2
/* F39C8 802CF018 46006300 */  add.s     $f12, $f12, $f0
/* F39CC 802CF01C 0C00A6C9 */  jal       clamp_angle
/* F39D0 802CF020 E60C000C */   swc1     $f12, 0xc($s0)
/* F39D4 802CF024 8602008E */  lh        $v0, 0x8e($s0)
/* F39D8 802CF028 E600000C */  swc1      $f0, 0xc($s0)
/* F39DC 802CF02C 8E830000 */  lw        $v1, ($s4)
/* F39E0 802CF030 0043102A */  slt       $v0, $v0, $v1
/* F39E4 802CF034 38420001 */  xori      $v0, $v0, 1
.L802CF038:
/* F39E8 802CF038 8FBF002C */  lw        $ra, 0x2c($sp)
/* F39EC 802CF03C 8FB60028 */  lw        $s6, 0x28($sp)
/* F39F0 802CF040 8FB50024 */  lw        $s5, 0x24($sp)
/* F39F4 802CF044 8FB40020 */  lw        $s4, 0x20($sp)
/* F39F8 802CF048 8FB3001C */  lw        $s3, 0x1c($sp)
/* F39FC 802CF04C 8FB20018 */  lw        $s2, 0x18($sp)
/* F3A00 802CF050 8FB10014 */  lw        $s1, 0x14($sp)
/* F3A04 802CF054 8FB00010 */  lw        $s0, 0x10($sp)
/* F3A08 802CF058 03E00008 */  jr        $ra
/* F3A0C 802CF05C 27BD0030 */   addiu    $sp, $sp, 0x30
