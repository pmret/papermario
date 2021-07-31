.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8011CFBC
/* B36BC 8011CFBC 44860000 */  mtc1      $a2, $f0
/* B36C0 8011CFC0 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* B36C4 8011CFC4 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* B36C8 8011CFC8 27BDFF88 */  addiu     $sp, $sp, -0x78
/* B36CC 8011CFCC AFB00040 */  sw        $s0, 0x40($sp)
/* B36D0 8011CFD0 8FB00088 */  lw        $s0, 0x88($sp)
/* B36D4 8011CFD4 AFB10044 */  sw        $s1, 0x44($sp)
/* B36D8 8011CFD8 8FB1008C */  lw        $s1, 0x8c($sp)
/* B36DC 8011CFDC 3C04800B */  lui       $a0, %hi(gCameras)
/* B36E0 8011CFE0 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* B36E4 8011CFE4 AFBF0064 */  sw        $ra, 0x64($sp)
/* B36E8 8011CFE8 AFBE0060 */  sw        $fp, 0x60($sp)
/* B36EC 8011CFEC AFB7005C */  sw        $s7, 0x5c($sp)
/* B36F0 8011CFF0 AFB60058 */  sw        $s6, 0x58($sp)
/* B36F4 8011CFF4 AFB50054 */  sw        $s5, 0x54($sp)
/* B36F8 8011CFF8 AFB40050 */  sw        $s4, 0x50($sp)
/* B36FC 8011CFFC AFB3004C */  sw        $s3, 0x4c($sp)
/* B3700 8011D000 AFB20048 */  sw        $s2, 0x48($sp)
/* B3704 8011D004 F7B60070 */  sdc1      $f22, 0x70($sp)
/* B3708 8011D008 F7B40068 */  sdc1      $f20, 0x68($sp)
/* B370C 8011D00C 00031080 */  sll       $v0, $v1, 2
/* B3710 8011D010 00431021 */  addu      $v0, $v0, $v1
/* B3714 8011D014 00021080 */  sll       $v0, $v0, 2
/* B3718 8011D018 00431023 */  subu      $v0, $v0, $v1
/* B371C 8011D01C 000218C0 */  sll       $v1, $v0, 3
/* B3720 8011D020 00431021 */  addu      $v0, $v0, $v1
/* B3724 8011D024 000210C0 */  sll       $v0, $v0, 3
/* B3728 8011D028 0044F021 */  addu      $fp, $v0, $a0
/* B372C 8011D02C 28E20010 */  slti      $v0, $a3, 0x10
/* B3730 8011D030 104001AF */  beqz      $v0, .L8011D6F0
/* B3734 8011D034 AFA70084 */   sw       $a3, 0x84($sp)
/* B3738 8011D038 27C400D4 */  addiu     $a0, $fp, 0xd4
/* B373C 8011D03C 3C013F80 */  lui       $at, 0x3f80
/* B3740 8011D040 4481A000 */  mtc1      $at, $f20
/* B3744 8011D044 44056000 */  mfc1      $a1, $f12
/* B3748 8011D048 44067000 */  mfc1      $a2, $f14
/* B374C 8011D04C 44070000 */  mfc1      $a3, $f0
/* B3750 8011D050 27A20028 */  addiu     $v0, $sp, 0x28
/* B3754 8011D054 AFA20014 */  sw        $v0, 0x14($sp)
/* B3758 8011D058 27A2002C */  addiu     $v0, $sp, 0x2c
/* B375C 8011D05C AFA20018 */  sw        $v0, 0x18($sp)
/* B3760 8011D060 27A20030 */  addiu     $v0, $sp, 0x30
/* B3764 8011D064 AFA2001C */  sw        $v0, 0x1c($sp)
/* B3768 8011D068 27A20034 */  addiu     $v0, $sp, 0x34
/* B376C 8011D06C AFA20020 */  sw        $v0, 0x20($sp)
/* B3770 8011D070 0C00A588 */  jal       transform_point
/* B3774 8011D074 E7B40010 */   swc1     $f20, 0x10($sp)
/* B3778 8011D078 C7A00034 */  lwc1      $f0, 0x34($sp)
/* B377C 8011D07C 44809000 */  mtc1      $zero, $f18
/* B3780 8011D080 00000000 */  nop
/* B3784 8011D084 46120032 */  c.eq.s    $f0, $f18
/* B3788 8011D088 00000000 */  nop
/* B378C 8011D08C 45000004 */  bc1f      .L8011D0A0
/* B3790 8011D090 24020001 */   addiu    $v0, $zero, 1
/* B3794 8011D094 E6120000 */  swc1      $f18, ($s0)
/* B3798 8011D098 080475BD */  j         .L8011D6F4
/* B379C 8011D09C E6320000 */   swc1     $f18, ($s1)
.L8011D0A0:
/* B37A0 8011D0A0 C7AC0030 */  lwc1      $f12, 0x30($sp)
/* B37A4 8011D0A4 4600A383 */  div.s     $f14, $f20, $f0
/* B37A8 8011D0A8 460E6302 */  mul.s     $f12, $f12, $f14
/* B37AC 8011D0AC 00000000 */  nop
/* B37B0 8011D0B0 46146080 */  add.s     $f2, $f12, $f20
/* B37B4 8011D0B4 3C013FE0 */  lui       $at, 0x3fe0
/* B37B8 8011D0B8 44814800 */  mtc1      $at, $f9
/* B37BC 8011D0BC 44804000 */  mtc1      $zero, $f8
/* B37C0 8011D0C0 460010A1 */  cvt.d.s   $f2, $f2
/* B37C4 8011D0C4 46281082 */  mul.d     $f2, $f2, $f8
/* B37C8 8011D0C8 00000000 */  nop
/* B37CC 8011D0CC C7B00028 */  lwc1      $f16, 0x28($sp)
/* B37D0 8011D0D0 460E8402 */  mul.s     $f16, $f16, $f14
/* B37D4 8011D0D4 00000000 */  nop
/* B37D8 8011D0D8 87C2000A */  lh        $v0, 0xa($fp)
/* B37DC 8011D0DC 44820000 */  mtc1      $v0, $f0
/* B37E0 8011D0E0 00000000 */  nop
/* B37E4 8011D0E4 46800020 */  cvt.s.w   $f0, $f0
/* B37E8 8011D0E8 46008102 */  mul.s     $f4, $f16, $f0
/* B37EC 8011D0EC 00000000 */  nop
/* B37F0 8011D0F0 46002100 */  add.s     $f4, $f4, $f0
/* B37F4 8011D0F4 46002121 */  cvt.d.s   $f4, $f4
/* B37F8 8011D0F8 46282102 */  mul.d     $f4, $f4, $f8
/* B37FC 8011D0FC 00000000 */  nop
/* B3800 8011D100 C7A6002C */  lwc1      $f6, 0x2c($sp)
/* B3804 8011D104 46007007 */  neg.s     $f0, $f14
/* B3808 8011D108 46003182 */  mul.s     $f6, $f6, $f0
/* B380C 8011D10C 00000000 */  nop
/* B3810 8011D110 87C2000C */  lh        $v0, 0xc($fp)
/* B3814 8011D114 44825000 */  mtc1      $v0, $f10
/* B3818 8011D118 00000000 */  nop
/* B381C 8011D11C 468052A0 */  cvt.s.w   $f10, $f10
/* B3820 8011D120 460A3002 */  mul.s     $f0, $f6, $f10
/* B3824 8011D124 00000000 */  nop
/* B3828 8011D128 E7AE0034 */  swc1      $f14, 0x34($sp)
/* B382C 8011D12C E7B00028 */  swc1      $f16, 0x28($sp)
/* B3830 8011D130 E7AC0030 */  swc1      $f12, 0x30($sp)
/* B3834 8011D134 460A0000 */  add.s     $f0, $f0, $f10
/* B3838 8011D138 E7A6002C */  swc1      $f6, 0x2c($sp)
/* B383C 8011D13C 462010A0 */  cvt.s.d   $f2, $f2
/* B3840 8011D140 46000021 */  cvt.d.s   $f0, $f0
/* B3844 8011D144 46280002 */  mul.d     $f0, $f0, $f8
/* B3848 8011D148 00000000 */  nop
/* B384C 8011D14C E7A20030 */  swc1      $f2, 0x30($sp)
/* B3850 8011D150 87C2000E */  lh        $v0, 0xe($fp)
/* B3854 8011D154 44821000 */  mtc1      $v0, $f2
/* B3858 8011D158 00000000 */  nop
/* B385C 8011D15C 468010A0 */  cvt.s.w   $f2, $f2
/* B3860 8011D160 46202120 */  cvt.s.d   $f4, $f4
/* B3864 8011D164 E7A40028 */  swc1      $f4, 0x28($sp)
/* B3868 8011D168 87C20010 */  lh        $v0, 0x10($fp)
/* B386C 8011D16C 46022100 */  add.s     $f4, $f4, $f2
/* B3870 8011D170 44821000 */  mtc1      $v0, $f2
/* B3874 8011D174 00000000 */  nop
/* B3878 8011D178 468010A0 */  cvt.s.w   $f2, $f2
/* B387C 8011D17C 46200020 */  cvt.s.d   $f0, $f0
/* B3880 8011D180 46020080 */  add.s     $f2, $f0, $f2
/* B3884 8011D184 E7A40028 */  swc1      $f4, 0x28($sp)
/* B3888 8011D188 E7A0002C */  swc1      $f0, 0x2c($sp)
/* B388C 8011D18C E7A2002C */  swc1      $f2, 0x2c($sp)
/* B3890 8011D190 E6040000 */  swc1      $f4, ($s0)
/* B3894 8011D194 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* B3898 8011D198 E6200000 */  swc1      $f0, ($s1)
/* B389C 8011D19C 8FA80084 */  lw        $t0, 0x84($sp)
/* B38A0 8011D1A0 05010005 */  bgez      $t0, .L8011D1B8
/* B38A4 8011D1A4 24020001 */   addiu    $v0, $zero, 1
/* B38A8 8011D1A8 C7A00030 */  lwc1      $f0, 0x30($sp)
/* B38AC 8011D1AC 4600903C */  c.lt.s    $f18, $f0
/* B38B0 8011D1B0 080475BA */  j         .L8011D6E8
/* B38B4 8011D1B4 00000000 */   nop
.L8011D1B8:
/* B38B8 8011D1B8 C7A40028 */  lwc1      $f4, 0x28($sp)
/* B38BC 8011D1BC 4604903E */  c.le.s    $f18, $f4
/* B38C0 8011D1C0 00000000 */  nop
/* B38C4 8011D1C4 45000143 */  bc1f      .L8011D6D4
/* B38C8 8011D1C8 00000000 */   nop
/* B38CC 8011D1CC C7A2002C */  lwc1      $f2, 0x2c($sp)
/* B38D0 8011D1D0 4602903E */  c.le.s    $f18, $f2
/* B38D4 8011D1D4 00000000 */  nop
/* B38D8 8011D1D8 4500013E */  bc1f      .L8011D6D4
/* B38DC 8011D1DC 00000000 */   nop
/* B38E0 8011D1E0 3C0143A0 */  lui       $at, 0x43a0
/* B38E4 8011D1E4 44810000 */  mtc1      $at, $f0
/* B38E8 8011D1E8 00000000 */  nop
/* B38EC 8011D1EC 4600203C */  c.lt.s    $f4, $f0
/* B38F0 8011D1F0 00000000 */  nop
/* B38F4 8011D1F4 45000137 */  bc1f      .L8011D6D4
/* B38F8 8011D1F8 00000000 */   nop
/* B38FC 8011D1FC 3C014370 */  lui       $at, 0x4370
/* B3900 8011D200 44810000 */  mtc1      $at, $f0
/* B3904 8011D204 00000000 */  nop
/* B3908 8011D208 4600103C */  c.lt.s    $f2, $f0
/* B390C 8011D20C 00000000 */  nop
/* B3910 8011D210 45000130 */  bc1f      .L8011D6D4
/* B3914 8011D214 3C05FD10 */   lui      $a1, 0xfd10
/* B3918 8011D218 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* B391C 8011D21C 2631A66C */  addiu     $s1, $s1, %lo(gMasterGfxPos)
/* B3920 8011D220 34A5013F */  ori       $a1, $a1, 0x13f
/* B3924 8011D224 4600158D */  trunc.w.s $f22, $f2
/* B3928 8011D228 4402B000 */  mfc1      $v0, $f22
/* B392C 8011D22C 00000000 */  nop
/* B3930 8011D230 00022080 */  sll       $a0, $v0, 2
/* B3934 8011D234 00822021 */  addu      $a0, $a0, $v0
/* B3938 8011D238 000421C0 */  sll       $a0, $a0, 7
/* B393C 8011D23C 3C13E700 */  lui       $s3, 0xe700
/* B3940 8011D240 8E320000 */  lw        $s2, ($s1)
/* B3944 8011D244 3C02800A */  lui       $v0, %hi(nuGfxZBuffer)
/* B3948 8011D248 8C42A5DC */  lw        $v0, %lo(nuGfxZBuffer)($v0)
/* B394C 8011D24C 0240182D */  daddu     $v1, $s2, $zero
/* B3950 8011D250 26520008 */  addiu     $s2, $s2, 8
/* B3954 8011D254 00442021 */  addu      $a0, $v0, $a0
/* B3958 8011D258 26420008 */  addiu     $v0, $s2, 8
/* B395C 8011D25C AE320000 */  sw        $s2, ($s1)
/* B3960 8011D260 AC730000 */  sw        $s3, ($v1)
/* B3964 8011D264 AC600004 */  sw        $zero, 4($v1)
/* B3968 8011D268 AE220000 */  sw        $v0, ($s1)
/* B396C 8011D26C 0C0187A4 */  jal       osVirtualToPhysical
/* B3970 8011D270 AE450000 */   sw       $a1, ($s2)
/* B3974 8011D274 3C06F510 */  lui       $a2, 0xf510
/* B3978 8011D278 34C60200 */  ori       $a2, $a2, 0x200
/* B397C 8011D27C 3C030700 */  lui       $v1, 0x700
/* B3980 8011D280 34630090 */  ori       $v1, $v1, 0x90
/* B3984 8011D284 3C18FF10 */  lui       $t8, 0xff10
/* B3988 8011D288 3718013F */  ori       $t8, $t8, 0x13f
/* B398C 8011D28C 3C07E300 */  lui       $a3, 0xe300
/* B3990 8011D290 34E70A01 */  ori       $a3, $a3, 0xa01
/* B3994 8011D294 3C0AE200 */  lui       $t2, 0xe200
/* B3998 8011D298 354A001C */  ori       $t2, $t2, 0x1c
/* B399C 8011D29C 3C080F0A */  lui       $t0, 0xf0a
/* B39A0 8011D2A0 35084000 */  ori       $t0, $t0, 0x4000
/* B39A4 8011D2A4 3C0BFCFF */  lui       $t3, 0xfcff
/* B39A8 8011D2A8 356BFFFF */  ori       $t3, $t3, 0xffff
/* B39AC 8011D2AC 3C09FFFC */  lui       $t1, 0xfffc
/* B39B0 8011D2B0 3529F279 */  ori       $t1, $t1, 0xf279
/* B39B4 8011D2B4 3C0CE300 */  lui       $t4, 0xe300
/* B39B8 8011D2B8 358C1201 */  ori       $t4, $t4, 0x1201
/* B39BC 8011D2BC 3C0DE300 */  lui       $t5, 0xe300
/* B39C0 8011D2C0 35AD0C00 */  ori       $t5, $t5, 0xc00
/* B39C4 8011D2C4 3C0ED700 */  lui       $t6, 0xd700
/* B39C8 8011D2C8 35CE0002 */  ori       $t6, $t6, 2
/* B39CC 8011D2CC 3C0FE300 */  lui       $t7, 0xe300
/* B39D0 8011D2D0 35EF1001 */  ori       $t7, $t7, 0x1001
/* B39D4 8011D2D4 3C15E300 */  lui       $s5, 0xe300
/* B39D8 8011D2D8 36B50D01 */  ori       $s5, $s5, 0xd01
/* B39DC 8011D2DC 3C16E300 */  lui       $s6, 0xe300
/* B39E0 8011D2E0 36D60F00 */  ori       $s6, $s6, 0xf00
/* B39E4 8011D2E4 3C17E400 */  lui       $s7, 0xe400
/* B39E8 8011D2E8 36F70004 */  ori       $s7, $s7, 4
/* B39EC 8011D2EC 3C190400 */  lui       $t9, 0x400
/* B39F0 8011D2F0 AFA80038 */  sw        $t0, 0x38($sp)
/* B39F4 8011D2F4 8E300000 */  lw        $s0, ($s1)
/* B39F8 8011D2F8 3C148015 */  lui       $s4, %hi(D_80153380)
/* B39FC 8011D2FC 26943380 */  addiu     $s4, $s4, %lo(D_80153380)
/* B3A00 8011D300 AE420004 */  sw        $v0, 4($s2)
/* B3A04 8011D304 3C12ED00 */  lui       $s2, 0xed00
/* B3A08 8011D308 37390400 */  ori       $t9, $t9, 0x400
/* B3A0C 8011D30C 0200102D */  daddu     $v0, $s0, $zero
/* B3A10 8011D310 26100008 */  addiu     $s0, $s0, 8
/* B3A14 8011D314 AE300000 */  sw        $s0, ($s1)
/* B3A18 8011D318 AC460000 */  sw        $a2, ($v0)
/* B3A1C 8011D31C AC430004 */  sw        $v1, 4($v0)
/* B3A20 8011D320 26020008 */  addiu     $v0, $s0, 8
/* B3A24 8011D324 AE220000 */  sw        $v0, ($s1)
/* B3A28 8011D328 3C02E600 */  lui       $v0, 0xe600
/* B3A2C 8011D32C AE020000 */  sw        $v0, ($s0)
/* B3A30 8011D330 AE000004 */  sw        $zero, 4($s0)
/* B3A34 8011D334 C7A00028 */  lwc1      $f0, 0x28($sp)
/* B3A38 8011D338 26020010 */  addiu     $v0, $s0, 0x10
/* B3A3C 8011D33C AE220000 */  sw        $v0, ($s1)
/* B3A40 8011D340 3C02F400 */  lui       $v0, 0xf400
/* B3A44 8011D344 4600058D */  trunc.w.s $f22, $f0
/* B3A48 8011D348 4405B000 */  mfc1      $a1, $f22
/* B3A4C 8011D34C 00000000 */  nop
/* B3A50 8011D350 00052080 */  sll       $a0, $a1, 2
/* B3A54 8011D354 30840FFF */  andi      $a0, $a0, 0xfff
/* B3A58 8011D358 00042300 */  sll       $a0, $a0, 0xc
/* B3A5C 8011D35C 00821025 */  or        $v0, $a0, $v0
/* B3A60 8011D360 24A30003 */  addiu     $v1, $a1, 3
/* B3A64 8011D364 00031880 */  sll       $v1, $v1, 2
/* B3A68 8011D368 30630FFF */  andi      $v1, $v1, 0xfff
/* B3A6C 8011D36C 00031B00 */  sll       $v1, $v1, 0xc
/* B3A70 8011D370 AE020008 */  sw        $v0, 8($s0)
/* B3A74 8011D374 3C020700 */  lui       $v0, 0x700
/* B3A78 8011D378 00621025 */  or        $v0, $v1, $v0
/* B3A7C 8011D37C AE02000C */  sw        $v0, 0xc($s0)
/* B3A80 8011D380 26020018 */  addiu     $v0, $s0, 0x18
/* B3A84 8011D384 AE220000 */  sw        $v0, ($s1)
/* B3A88 8011D388 26020020 */  addiu     $v0, $s0, 0x20
/* B3A8C 8011D38C AE130010 */  sw        $s3, 0x10($s0)
/* B3A90 8011D390 AE000014 */  sw        $zero, 0x14($s0)
/* B3A94 8011D394 AE220000 */  sw        $v0, ($s1)
/* B3A98 8011D398 24020090 */  addiu     $v0, $zero, 0x90
/* B3A9C 8011D39C AE02001C */  sw        $v0, 0x1c($s0)
/* B3AA0 8011D3A0 26020028 */  addiu     $v0, $s0, 0x28
/* B3AA4 8011D3A4 AE060018 */  sw        $a2, 0x18($s0)
/* B3AA8 8011D3A8 AE220000 */  sw        $v0, ($s1)
/* B3AAC 8011D3AC 3C02F200 */  lui       $v0, 0xf200
/* B3AB0 8011D3B0 00822025 */  or        $a0, $a0, $v0
/* B3AB4 8011D3B4 26020030 */  addiu     $v0, $s0, 0x30
/* B3AB8 8011D3B8 AE040020 */  sw        $a0, 0x20($s0)
/* B3ABC 8011D3BC AE030024 */  sw        $v1, 0x24($s0)
/* B3AC0 8011D3C0 AE220000 */  sw        $v0, ($s1)
/* B3AC4 8011D3C4 26020038 */  addiu     $v0, $s0, 0x38
/* B3AC8 8011D3C8 AE130028 */  sw        $s3, 0x28($s0)
/* B3ACC 8011D3CC AE00002C */  sw        $zero, 0x2c($s0)
/* B3AD0 8011D3D0 AE220000 */  sw        $v0, ($s1)
/* B3AD4 8011D3D4 26020040 */  addiu     $v0, $s0, 0x40
/* B3AD8 8011D3D8 AE180030 */  sw        $t8, 0x30($s0)
/* B3ADC 8011D3DC AE140034 */  sw        $s4, 0x34($s0)
/* B3AE0 8011D3E0 AE220000 */  sw        $v0, ($s1)
/* B3AE4 8011D3E4 26020048 */  addiu     $v0, $s0, 0x48
/* B3AE8 8011D3E8 AE130038 */  sw        $s3, 0x38($s0)
/* B3AEC 8011D3EC AE00003C */  sw        $zero, 0x3c($s0)
/* B3AF0 8011D3F0 AE220000 */  sw        $v0, ($s1)
/* B3AF4 8011D3F4 26020050 */  addiu     $v0, $s0, 0x50
/* B3AF8 8011D3F8 AE070040 */  sw        $a3, 0x40($s0)
/* B3AFC 8011D3FC AE000044 */  sw        $zero, 0x44($s0)
/* B3B00 8011D400 AE220000 */  sw        $v0, ($s1)
/* B3B04 8011D404 AE0A0048 */  sw        $t2, 0x48($s0)
/* B3B08 8011D408 8FA80038 */  lw        $t0, 0x38($sp)
/* B3B0C 8011D40C 26020058 */  addiu     $v0, $s0, 0x58
/* B3B10 8011D410 AE08004C */  sw        $t0, 0x4c($s0)
/* B3B14 8011D414 AE220000 */  sw        $v0, ($s1)
/* B3B18 8011D418 26020060 */  addiu     $v0, $s0, 0x60
/* B3B1C 8011D41C AE0B0050 */  sw        $t3, 0x50($s0)
/* B3B20 8011D420 AE090054 */  sw        $t1, 0x54($s0)
/* B3B24 8011D424 AE220000 */  sw        $v0, ($s1)
/* B3B28 8011D428 26020068 */  addiu     $v0, $s0, 0x68
/* B3B2C 8011D42C AE0C0058 */  sw        $t4, 0x58($s0)
/* B3B30 8011D430 AE00005C */  sw        $zero, 0x5c($s0)
/* B3B34 8011D434 AE220000 */  sw        $v0, ($s1)
/* B3B38 8011D438 26020070 */  addiu     $v0, $s0, 0x70
/* B3B3C 8011D43C AE0D0060 */  sw        $t5, 0x60($s0)
/* B3B40 8011D440 AE000064 */  sw        $zero, 0x64($s0)
/* B3B44 8011D444 AE220000 */  sw        $v0, ($s1)
/* B3B48 8011D448 2402FFFF */  addiu     $v0, $zero, -1
/* B3B4C 8011D44C AE02006C */  sw        $v0, 0x6c($s0)
/* B3B50 8011D450 26020078 */  addiu     $v0, $s0, 0x78
/* B3B54 8011D454 AE0E0068 */  sw        $t6, 0x68($s0)
/* B3B58 8011D458 AE220000 */  sw        $v0, ($s1)
/* B3B5C 8011D45C 26020080 */  addiu     $v0, $s0, 0x80
/* B3B60 8011D460 AE0F0070 */  sw        $t7, 0x70($s0)
/* B3B64 8011D464 AE000074 */  sw        $zero, 0x74($s0)
/* B3B68 8011D468 AE220000 */  sw        $v0, ($s1)
/* B3B6C 8011D46C 26020088 */  addiu     $v0, $s0, 0x88
/* B3B70 8011D470 AE150078 */  sw        $s5, 0x78($s0)
/* B3B74 8011D474 AE00007C */  sw        $zero, 0x7c($s0)
/* B3B78 8011D478 AE220000 */  sw        $v0, ($s1)
/* B3B7C 8011D47C 26020090 */  addiu     $v0, $s0, 0x90
/* B3B80 8011D480 AE160080 */  sw        $s6, 0x80($s0)
/* B3B84 8011D484 AE000084 */  sw        $zero, 0x84($s0)
/* B3B88 8011D488 AE220000 */  sw        $v0, ($s1)
/* B3B8C 8011D48C 26020098 */  addiu     $v0, $s0, 0x98
/* B3B90 8011D490 AE220000 */  sw        $v0, ($s1)
/* B3B94 8011D494 8FA80084 */  lw        $t0, 0x84($sp)
/* B3B98 8011D498 3C014080 */  lui       $at, 0x4080
/* B3B9C 8011D49C 4481A000 */  mtc1      $at, $f20
/* B3BA0 8011D4A0 25030001 */  addiu     $v1, $t0, 1
/* B3BA4 8011D4A4 00031080 */  sll       $v0, $v1, 2
/* B3BA8 8011D4A8 30420FFF */  andi      $v0, $v0, 0xfff
/* B3BAC 8011D4AC 00021300 */  sll       $v0, $v0, 0xc
/* B3BB0 8011D4B0 00571025 */  or        $v0, $v0, $s7
/* B3BB4 8011D4B4 AE020090 */  sw        $v0, 0x90($s0)
/* B3BB8 8011D4B8 00081080 */  sll       $v0, $t0, 2
/* B3BBC 8011D4BC 30420FFF */  andi      $v0, $v0, 0xfff
/* B3BC0 8011D4C0 00021300 */  sll       $v0, $v0, 0xc
/* B3BC4 8011D4C4 AE020094 */  sw        $v0, 0x94($s0)
/* B3BC8 8011D4C8 260200A0 */  addiu     $v0, $s0, 0xa0
/* B3BCC 8011D4CC AE220000 */  sw        $v0, ($s1)
/* B3BD0 8011D4D0 3C02E100 */  lui       $v0, 0xe100
/* B3BD4 8011D4D4 AE020098 */  sw        $v0, 0x98($s0)
/* B3BD8 8011D4D8 C7A00084 */  lwc1      $f0, 0x84($sp)
/* B3BDC 8011D4DC 46800020 */  cvt.s.w   $f0, $f0
/* B3BE0 8011D4E0 46140002 */  mul.s     $f0, $f0, $f20
/* B3BE4 8011D4E4 00000000 */  nop
/* B3BE8 8011D4E8 00052D40 */  sll       $a1, $a1, 0x15
/* B3BEC 8011D4EC 260200A8 */  addiu     $v0, $s0, 0xa8
/* B3BF0 8011D4F0 AE05009C */  sw        $a1, 0x9c($s0)
/* B3BF4 8011D4F4 AE220000 */  sw        $v0, ($s1)
/* B3BF8 8011D4F8 4600058D */  trunc.w.s $f22, $f0
/* B3BFC 8011D4FC 4402B000 */  mfc1      $v0, $f22
/* B3C00 8011D500 44830000 */  mtc1      $v1, $f0
/* B3C04 8011D504 00000000 */  nop
/* B3C08 8011D508 46800020 */  cvt.s.w   $f0, $f0
/* B3C0C 8011D50C 46140002 */  mul.s     $f0, $f0, $f20
/* B3C10 8011D510 00000000 */  nop
/* B3C14 8011D514 30420FFF */  andi      $v0, $v0, 0xfff
/* B3C18 8011D518 00021300 */  sll       $v0, $v0, 0xc
/* B3C1C 8011D51C 00521025 */  or        $v0, $v0, $s2
/* B3C20 8011D520 AE020088 */  sw        $v0, 0x88($s0)
/* B3C24 8011D524 4600058D */  trunc.w.s $f22, $f0
/* B3C28 8011D528 4402B000 */  mfc1      $v0, $f22
/* B3C2C 8011D52C 00000000 */  nop
/* B3C30 8011D530 30420FFF */  andi      $v0, $v0, 0xfff
/* B3C34 8011D534 00021300 */  sll       $v0, $v0, 0xc
/* B3C38 8011D538 34420004 */  ori       $v0, $v0, 4
/* B3C3C 8011D53C AE02008C */  sw        $v0, 0x8c($s0)
/* B3C40 8011D540 3C02F100 */  lui       $v0, 0xf100
/* B3C44 8011D544 AE0200A0 */  sw        $v0, 0xa0($s0)
/* B3C48 8011D548 3C04800A */  lui       $a0, %hi(nuGfxCfb_ptr)
/* B3C4C 8011D54C 8C84A64C */  lw        $a0, %lo(nuGfxCfb_ptr)($a0)
/* B3C50 8011D550 260200B0 */  addiu     $v0, $s0, 0xb0
/* B3C54 8011D554 AE1900A4 */  sw        $t9, 0xa4($s0)
/* B3C58 8011D558 AE220000 */  sw        $v0, ($s1)
/* B3C5C 8011D55C 260200B8 */  addiu     $v0, $s0, 0xb8
/* B3C60 8011D560 AE1300A8 */  sw        $s3, 0xa8($s0)
/* B3C64 8011D564 AE0000AC */  sw        $zero, 0xac($s0)
/* B3C68 8011D568 AE220000 */  sw        $v0, ($s1)
/* B3C6C 8011D56C 0C0187A4 */  jal       osVirtualToPhysical
/* B3C70 8011D570 AE1800B0 */   sw       $t8, 0xb0($s0)
/* B3C74 8011D574 8E240000 */  lw        $a0, ($s1)
/* B3C78 8011D578 AE0200B4 */  sw        $v0, 0xb4($s0)
/* B3C7C 8011D57C 0080102D */  daddu     $v0, $a0, $zero
/* B3C80 8011D580 AC530000 */  sw        $s3, ($v0)
/* B3C84 8011D584 AC400004 */  sw        $zero, 4($v0)
/* B3C88 8011D588 87C2000E */  lh        $v0, 0xe($fp)
/* B3C8C 8011D58C 44820000 */  mtc1      $v0, $f0
/* B3C90 8011D590 00000000 */  nop
/* B3C94 8011D594 46800020 */  cvt.s.w   $f0, $f0
/* B3C98 8011D598 46140002 */  mul.s     $f0, $f0, $f20
/* B3C9C 8011D59C 00000000 */  nop
/* B3CA0 8011D5A0 87C20010 */  lh        $v0, 0x10($fp)
/* B3CA4 8011D5A4 44821000 */  mtc1      $v0, $f2
/* B3CA8 8011D5A8 00000000 */  nop
/* B3CAC 8011D5AC 468010A0 */  cvt.s.w   $f2, $f2
/* B3CB0 8011D5B0 46141082 */  mul.s     $f2, $f2, $f20
/* B3CB4 8011D5B4 00000000 */  nop
/* B3CB8 8011D5B8 24840008 */  addiu     $a0, $a0, 8
/* B3CBC 8011D5BC 4600058D */  trunc.w.s $f22, $f0
/* B3CC0 8011D5C0 4403B000 */  mfc1      $v1, $f22
/* B3CC4 8011D5C4 00000000 */  nop
/* B3CC8 8011D5C8 30630FFF */  andi      $v1, $v1, 0xfff
/* B3CCC 8011D5CC 00031B00 */  sll       $v1, $v1, 0xc
/* B3CD0 8011D5D0 4600158D */  trunc.w.s $f22, $f2
/* B3CD4 8011D5D4 4402B000 */  mfc1      $v0, $f22
/* B3CD8 8011D5D8 00000000 */  nop
/* B3CDC 8011D5DC 30420FFF */  andi      $v0, $v0, 0xfff
/* B3CE0 8011D5E0 00521025 */  or        $v0, $v0, $s2
/* B3CE4 8011D5E4 00621825 */  or        $v1, $v1, $v0
/* B3CE8 8011D5E8 AC830000 */  sw        $v1, ($a0)
/* B3CEC 8011D5EC 87C2000E */  lh        $v0, 0xe($fp)
/* B3CF0 8011D5F0 87C3000A */  lh        $v1, 0xa($fp)
/* B3CF4 8011D5F4 00431021 */  addu      $v0, $v0, $v1
/* B3CF8 8011D5F8 44821000 */  mtc1      $v0, $f2
/* B3CFC 8011D5FC 00000000 */  nop
/* B3D00 8011D600 468010A0 */  cvt.s.w   $f2, $f2
/* B3D04 8011D604 46141082 */  mul.s     $f2, $f2, $f20
/* B3D08 8011D608 00000000 */  nop
/* B3D0C 8011D60C 87C20010 */  lh        $v0, 0x10($fp)
/* B3D10 8011D610 87C3000C */  lh        $v1, 0xc($fp)
/* B3D14 8011D614 00431021 */  addu      $v0, $v0, $v1
/* B3D18 8011D618 44820000 */  mtc1      $v0, $f0
/* B3D1C 8011D61C 00000000 */  nop
/* B3D20 8011D620 46800020 */  cvt.s.w   $f0, $f0
/* B3D24 8011D624 46140002 */  mul.s     $f0, $f0, $f20
/* B3D28 8011D628 00000000 */  nop
/* B3D2C 8011D62C AE240000 */  sw        $a0, ($s1)
/* B3D30 8011D630 4600158D */  trunc.w.s $f22, $f2
/* B3D34 8011D634 4402B000 */  mfc1      $v0, $f22
/* B3D38 8011D638 00000000 */  nop
/* B3D3C 8011D63C 30420FFF */  andi      $v0, $v0, 0xfff
/* B3D40 8011D640 00021300 */  sll       $v0, $v0, 0xc
/* B3D44 8011D644 4600058D */  trunc.w.s $f22, $f0
/* B3D48 8011D648 4403B000 */  mfc1      $v1, $f22
/* B3D4C 8011D64C 00000000 */  nop
/* B3D50 8011D650 30630FFF */  andi      $v1, $v1, 0xfff
/* B3D54 8011D654 00431025 */  or        $v0, $v0, $v1
/* B3D58 8011D658 AC820004 */  sw        $v0, 4($a0)
/* B3D5C 8011D65C 8FA80084 */  lw        $t0, 0x84($sp)
/* B3D60 8011D660 3C0146FF */  lui       $at, 0x46ff
/* B3D64 8011D664 34218000 */  ori       $at, $at, 0x8000
/* B3D68 8011D668 44810000 */  mtc1      $at, $f0
/* B3D6C 8011D66C 00081040 */  sll       $v0, $t0, 1
/* B3D70 8011D670 00541021 */  addu      $v0, $v0, $s4
/* B3D74 8011D674 94420000 */  lhu       $v0, ($v0)
/* B3D78 8011D678 24840008 */  addiu     $a0, $a0, 8
/* B3D7C 8011D67C AE240000 */  sw        $a0, ($s1)
/* B3D80 8011D680 3C048015 */  lui       $a0, %hi(D_8014B7A8)
/* B3D84 8011D684 2484B7A8 */  addiu     $a0, $a0, %lo(D_8014B7A8)
/* B3D88 8011D688 C7A20030 */  lwc1      $f2, 0x30($sp)
/* B3D8C 8011D68C 00021B42 */  srl       $v1, $v0, 0xd
/* B3D90 8011D690 30421FFF */  andi      $v0, $v0, 0x1fff
/* B3D94 8011D694 00021082 */  srl       $v0, $v0, 2
/* B3D98 8011D698 000318C0 */  sll       $v1, $v1, 3
/* B3D9C 8011D69C 00641821 */  addu      $v1, $v1, $a0
/* B3DA0 8011D6A0 46001082 */  mul.s     $f2, $f2, $f0
/* B3DA4 8011D6A4 00000000 */  nop
/* B3DA8 8011D6A8 8C640000 */  lw        $a0, ($v1)
/* B3DAC 8011D6AC 8C630004 */  lw        $v1, 4($v1)
/* B3DB0 8011D6B0 00821004 */  sllv      $v0, $v0, $a0
/* B3DB4 8011D6B4 00431021 */  addu      $v0, $v0, $v1
/* B3DB8 8011D6B8 000210C2 */  srl       $v0, $v0, 3
/* B3DBC 8011D6BC 4600158D */  trunc.w.s $f22, $f2
/* B3DC0 8011D6C0 4403B000 */  mfc1      $v1, $f22
/* B3DC4 8011D6C4 00000000 */  nop
/* B3DC8 8011D6C8 0043102B */  sltu      $v0, $v0, $v1
/* B3DCC 8011D6CC 14400009 */  bnez      $v0, .L8011D6F4
/* B3DD0 8011D6D0 0000102D */   daddu    $v0, $zero, $zero
.L8011D6D4:
/* B3DD4 8011D6D4 C7A20030 */  lwc1      $f2, 0x30($sp)
/* B3DD8 8011D6D8 44800000 */  mtc1      $zero, $f0
/* B3DDC 8011D6DC 24020001 */  addiu     $v0, $zero, 1
/* B3DE0 8011D6E0 4602003C */  c.lt.s    $f0, $f2
/* B3DE4 8011D6E4 00000000 */  nop
.L8011D6E8:
/* B3DE8 8011D6E8 45010002 */  bc1t      .L8011D6F4
/* B3DEC 8011D6EC 00000000 */   nop
.L8011D6F0:
/* B3DF0 8011D6F0 0000102D */  daddu     $v0, $zero, $zero
.L8011D6F4:
/* B3DF4 8011D6F4 8FBF0064 */  lw        $ra, 0x64($sp)
/* B3DF8 8011D6F8 8FBE0060 */  lw        $fp, 0x60($sp)
/* B3DFC 8011D6FC 8FB7005C */  lw        $s7, 0x5c($sp)
/* B3E00 8011D700 8FB60058 */  lw        $s6, 0x58($sp)
/* B3E04 8011D704 8FB50054 */  lw        $s5, 0x54($sp)
/* B3E08 8011D708 8FB40050 */  lw        $s4, 0x50($sp)
/* B3E0C 8011D70C 8FB3004C */  lw        $s3, 0x4c($sp)
/* B3E10 8011D710 8FB20048 */  lw        $s2, 0x48($sp)
/* B3E14 8011D714 8FB10044 */  lw        $s1, 0x44($sp)
/* B3E18 8011D718 8FB00040 */  lw        $s0, 0x40($sp)
/* B3E1C 8011D71C D7B60070 */  ldc1      $f22, 0x70($sp)
/* B3E20 8011D720 D7B40068 */  ldc1      $f20, 0x68($sp)
/* B3E24 8011D724 03E00008 */  jr        $ra
/* B3E28 8011D728 27BD0078 */   addiu    $sp, $sp, 0x78
