.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8013CFA8
/* D36A8 8013CFA8 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* D36AC 8013CFAC AFB10034 */  sw        $s1, 0x34($sp)
/* D36B0 8013CFB0 0080882D */  daddu     $s1, $a0, $zero
/* D36B4 8013CFB4 AFBF0054 */  sw        $ra, 0x54($sp)
/* D36B8 8013CFB8 AFBE0050 */  sw        $fp, 0x50($sp)
/* D36BC 8013CFBC AFB7004C */  sw        $s7, 0x4c($sp)
/* D36C0 8013CFC0 AFB60048 */  sw        $s6, 0x48($sp)
/* D36C4 8013CFC4 AFB50044 */  sw        $s5, 0x44($sp)
/* D36C8 8013CFC8 AFB40040 */  sw        $s4, 0x40($sp)
/* D36CC 8013CFCC AFB3003C */  sw        $s3, 0x3c($sp)
/* D36D0 8013CFD0 AFB20038 */  sw        $s2, 0x38($sp)
/* D36D4 8013CFD4 AFB00030 */  sw        $s0, 0x30($sp)
/* D36D8 8013CFD8 AFA5005C */  sw        $a1, 0x5c($sp)
/* D36DC 8013CFDC 8E220014 */  lw        $v0, 0x14($s1)
/* D36E0 8013CFE0 30420020 */  andi      $v0, $v0, 0x20
/* D36E4 8013CFE4 14400030 */  bnez      $v0, .L8013D0A8
/* D36E8 8013CFE8 3C03E300 */   lui      $v1, 0xe300
/* D36EC 8013CFEC 34631001 */  ori       $v1, $v1, 0x1001
/* D36F0 8013CFF0 3C06F500 */  lui       $a2, 0xf500
/* D36F4 8013CFF4 34C60100 */  ori       $a2, $a2, 0x100
/* D36F8 8013CFF8 3C070703 */  lui       $a3, 0x703
/* D36FC 8013CFFC 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* D3700 8013D000 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* D3704 8013D004 8C820000 */  lw        $v0, ($a0)
/* D3708 8013D008 34E7C000 */  ori       $a3, $a3, 0xc000
/* D370C 8013D00C 0040282D */  daddu     $a1, $v0, $zero
/* D3710 8013D010 24420008 */  addiu     $v0, $v0, 8
/* D3714 8013D014 AC820000 */  sw        $v0, ($a0)
/* D3718 8013D018 ACA30000 */  sw        $v1, ($a1)
/* D371C 8013D01C 34038000 */  ori       $v1, $zero, 0x8000
/* D3720 8013D020 ACA30004 */  sw        $v1, 4($a1)
/* D3724 8013D024 24430008 */  addiu     $v1, $v0, 8
/* D3728 8013D028 AC830000 */  sw        $v1, ($a0)
/* D372C 8013D02C 3C058015 */  lui       $a1, %hi(D_8014EE10)
/* D3730 8013D030 8CA5EE10 */  lw        $a1, %lo(D_8014EE10)($a1)
/* D3734 8013D034 3C03FD10 */  lui       $v1, 0xfd10
/* D3738 8013D038 AC430000 */  sw        $v1, ($v0)
/* D373C 8013D03C 24430010 */  addiu     $v1, $v0, 0x10
/* D3740 8013D040 AC830000 */  sw        $v1, ($a0)
/* D3744 8013D044 8CA50004 */  lw        $a1, 4($a1)
/* D3748 8013D048 3C03E800 */  lui       $v1, 0xe800
/* D374C 8013D04C AC430008 */  sw        $v1, 8($v0)
/* D3750 8013D050 24430018 */  addiu     $v1, $v0, 0x18
/* D3754 8013D054 AC40000C */  sw        $zero, 0xc($v0)
/* D3758 8013D058 AC830000 */  sw        $v1, ($a0)
/* D375C 8013D05C 3C030700 */  lui       $v1, 0x700
/* D3760 8013D060 AC430014 */  sw        $v1, 0x14($v0)
/* D3764 8013D064 24430020 */  addiu     $v1, $v0, 0x20
/* D3768 8013D068 AC460010 */  sw        $a2, 0x10($v0)
/* D376C 8013D06C AC830000 */  sw        $v1, ($a0)
/* D3770 8013D070 3C03E600 */  lui       $v1, 0xe600
/* D3774 8013D074 AC430018 */  sw        $v1, 0x18($v0)
/* D3778 8013D078 24430028 */  addiu     $v1, $v0, 0x28
/* D377C 8013D07C AC40001C */  sw        $zero, 0x1c($v0)
/* D3780 8013D080 AC830000 */  sw        $v1, ($a0)
/* D3784 8013D084 3C03F000 */  lui       $v1, 0xf000
/* D3788 8013D088 AC430020 */  sw        $v1, 0x20($v0)
/* D378C 8013D08C 24430030 */  addiu     $v1, $v0, 0x30
/* D3790 8013D090 AC470024 */  sw        $a3, 0x24($v0)
/* D3794 8013D094 AC830000 */  sw        $v1, ($a0)
/* D3798 8013D098 3C03E700 */  lui       $v1, 0xe700
/* D379C 8013D09C AC430028 */  sw        $v1, 0x28($v0)
/* D37A0 8013D0A0 AC40002C */  sw        $zero, 0x2c($v0)
/* D37A4 8013D0A4 AC450004 */  sw        $a1, 4($v0)
.L8013D0A8:
/* D37A8 8013D0A8 96350008 */  lhu       $s5, 8($s1)
/* D37AC 8013D0AC 3C180018 */  lui       $t8, 0x18
/* D37B0 8013D0B0 24160002 */  addiu     $s6, $zero, 2
/* D37B4 8013D0B4 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* D37B8 8013D0B8 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* D37BC 8013D0BC 3C1EE700 */  lui       $fp, 0xe700
/* D37C0 8013D0C0 3C19800B */  lui       $t9, %hi(gCameras)
/* D37C4 8013D0C4 27391D80 */  addiu     $t9, $t9, %lo(gCameras)
/* D37C8 8013D0C8 3C13DC08 */  lui       $s3, 0xdc08
/* D37CC 8013D0CC 36730008 */  ori       $s3, $s3, 8
/* D37D0 8013D0D0 3C178015 */  lui       $s7, %hi(D_8014EE50)
/* D37D4 8013D0D4 26F7EE50 */  addiu     $s7, $s7, %lo(D_8014EE50)
/* D37D8 8013D0D8 3C14E200 */  lui       $s4, 0xe200
/* D37DC 8013D0DC 3694001C */  ori       $s4, $s4, 0x1c
/* D37E0 8013D0E0 00159100 */  sll       $s2, $s5, 4
.L8013D0E4:
/* D37E4 8013D0E4 3C048015 */  lui       $a0, %hi(D_80156950)
/* D37E8 8013D0E8 8C846950 */  lw        $a0, %lo(D_80156950)($a0)
/* D37EC 8013D0EC 02442021 */  addu      $a0, $s2, $a0
/* D37F0 8013D0F0 94820008 */  lhu       $v0, 8($a0)
/* D37F4 8013D0F4 9483000A */  lhu       $v1, 0xa($a0)
/* D37F8 8013D0F8 00021400 */  sll       $v0, $v0, 0x10
/* D37FC 8013D0FC 00021543 */  sra       $v0, $v0, 0x15
/* D3800 8013D100 244CFF00 */  addiu     $t4, $v0, -0x100
/* D3804 8013D104 00031C00 */  sll       $v1, $v1, 0x10
/* D3808 8013D108 00031D43 */  sra       $v1, $v1, 0x15
/* D380C 8013D10C 246FFF00 */  addiu     $t7, $v1, -0x100
/* D3810 8013D110 94820038 */  lhu       $v0, 0x38($a0)
/* D3814 8013D114 9483003A */  lhu       $v1, 0x3a($a0)
/* D3818 8013D118 8E240014 */  lw        $a0, 0x14($s1)
/* D381C 8013D11C 00021400 */  sll       $v0, $v0, 0x10
/* D3820 8013D120 00021543 */  sra       $v0, $v0, 0x15
/* D3824 8013D124 244DFF00 */  addiu     $t5, $v0, -0x100
/* D3828 8013D128 00031C00 */  sll       $v1, $v1, 0x10
/* D382C 8013D12C 00031D43 */  sra       $v1, $v1, 0x15
/* D3830 8013D130 30820020 */  andi      $v0, $a0, 0x20
/* D3834 8013D134 14400200 */  bnez      $v0, .L8013D938
/* D3838 8013D138 246EFF00 */   addiu    $t6, $v1, -0x100
/* D383C 8013D13C 3C028015 */  lui       $v0, %hi(D_80151328)
/* D3840 8013D140 8C421328 */  lw        $v0, %lo(D_80151328)($v0)
/* D3844 8013D144 94420000 */  lhu       $v0, ($v0)
/* D3848 8013D148 30420001 */  andi      $v0, $v0, 1
/* D384C 8013D14C 104000FE */  beqz      $v0, .L8013D548
/* D3850 8013D150 3C06070A */   lui      $a2, 0x70a
/* D3854 8013D154 92220000 */  lbu       $v0, ($s1)
/* D3858 8013D158 104000FB */  beqz      $v0, .L8013D548
/* D385C 8013D15C 00981024 */   and      $v0, $a0, $t8
/* D3860 8013D160 104000FA */  beqz      $v0, .L8013D54C
/* D3864 8013D164 34C60280 */   ori      $a2, $a2, 0x280
/* D3868 8013D168 92230002 */  lbu       $v1, 2($s1)
/* D386C 8013D16C 10600008 */  beqz      $v1, .L8013D190
/* D3870 8013D170 3C07070A */   lui      $a3, 0x70a
/* D3874 8013D174 10760006 */  beq       $v1, $s6, .L8013D190
/* D3878 8013D178 2402000F */   addiu    $v0, $zero, 0xf
/* D387C 8013D17C 10620004 */  beq       $v1, $v0, .L8013D190
/* D3880 8013D180 24020007 */   addiu    $v0, $zero, 7
/* D3884 8013D184 146200F0 */  bne       $v1, $v0, .L8013D548
/* D3888 8013D188 3C06070A */   lui      $a2, 0x70a
/* D388C 8013D18C 3C07070A */  lui       $a3, 0x70a
.L8013D190:
/* D3890 8013D190 34E70280 */  ori       $a3, $a3, 0x280
/* D3894 8013D194 3C08010A */  lui       $t0, 0x10a
/* D3898 8013D198 35080280 */  ori       $t0, $t0, 0x280
/* D389C 8013D19C 3C0A001A */  lui       $t2, 0x1a
/* D38A0 8013D1A0 354A0280 */  ori       $t2, $t2, 0x280
/* D38A4 8013D1A4 3C09F510 */  lui       $t1, 0xf510
/* D38A8 8013D1A8 35290900 */  ori       $t1, $t1, 0x900
/* D38AC 8013D1AC 3C0B020F */  lui       $t3, 0x20f
/* D38B0 8013D1B0 356BC000 */  ori       $t3, $t3, 0xc000
/* D38B4 8013D1B4 AFAA0028 */  sw        $t2, 0x28($sp)
/* D38B8 8013D1B8 8E050000 */  lw        $a1, ($s0)
/* D38BC 8013D1BC 3C0AF200 */  lui       $t2, 0xf200
/* D38C0 8013D1C0 00A0302D */  daddu     $a2, $a1, $zero
/* D38C4 8013D1C4 24A50008 */  addiu     $a1, $a1, 8
/* D38C8 8013D1C8 24A20008 */  addiu     $v0, $a1, 8
/* D38CC 8013D1CC AE050000 */  sw        $a1, ($s0)
/* D38D0 8013D1D0 AE020000 */  sw        $v0, ($s0)
/* D38D4 8013D1D4 24A20010 */  addiu     $v0, $a1, 0x10
/* D38D8 8013D1D8 AE020000 */  sw        $v0, ($s0)
/* D38DC 8013D1DC 24A20018 */  addiu     $v0, $a1, 0x18
/* D38E0 8013D1E0 AE020000 */  sw        $v0, ($s0)
/* D38E4 8013D1E4 24A20020 */  addiu     $v0, $a1, 0x20
/* D38E8 8013D1E8 AE020000 */  sw        $v0, ($s0)
/* D38EC 8013D1EC 24A20028 */  addiu     $v0, $a1, 0x28
/* D38F0 8013D1F0 AE020000 */  sw        $v0, ($s0)
/* D38F4 8013D1F4 24A20030 */  addiu     $v0, $a1, 0x30
/* D38F8 8013D1F8 AE020000 */  sw        $v0, ($s0)
/* D38FC 8013D1FC 3C048015 */  lui       $a0, %hi(D_8014EE10)
/* D3900 8013D200 8C84EE10 */  lw        $a0, %lo(D_8014EE10)($a0)
/* D3904 8013D204 24A20038 */  addiu     $v0, $a1, 0x38
/* D3908 8013D208 AE020000 */  sw        $v0, ($s0)
/* D390C 8013D20C 94820008 */  lhu       $v0, 8($a0)
/* D3910 8013D210 24A30040 */  addiu     $v1, $a1, 0x40
/* D3914 8013D214 AE030000 */  sw        $v1, ($s0)
/* D3918 8013D218 3C03FD48 */  lui       $v1, 0xfd48
/* D391C 8013D21C 00021042 */  srl       $v0, $v0, 1
/* D3920 8013D220 2442FFFF */  addiu     $v0, $v0, -1
/* D3924 8013D224 30420FFF */  andi      $v0, $v0, 0xfff
/* D3928 8013D228 00431025 */  or        $v0, $v0, $v1
/* D392C 8013D22C ACC20000 */  sw        $v0, ($a2)
/* D3930 8013D230 8C830000 */  lw        $v1, ($a0)
/* D3934 8013D234 24A20048 */  addiu     $v0, $a1, 0x48
/* D3938 8013D238 AE020000 */  sw        $v0, ($s0)
/* D393C 8013D23C 3C02F548 */  lui       $v0, 0xf548
/* D3940 8013D240 3C04F400 */  lui       $a0, 0xf400
/* D3944 8013D244 ACC30004 */  sw        $v1, 4($a2)
/* D3948 8013D248 01AC3023 */  subu      $a2, $t5, $t4
/* D394C 8013D24C 00063043 */  sra       $a2, $a2, 1
/* D3950 8013D250 24C60007 */  addiu     $a2, $a2, 7
/* D3954 8013D254 000630C3 */  sra       $a2, $a2, 3
/* D3958 8013D258 30C601FF */  andi      $a2, $a2, 0x1ff
/* D395C 8013D25C 00063240 */  sll       $a2, $a2, 9
/* D3960 8013D260 00C21025 */  or        $v0, $a2, $v0
/* D3964 8013D264 ACA20000 */  sw        $v0, ($a1)
/* D3968 8013D268 3C02E600 */  lui       $v0, 0xe600
/* D396C 8013D26C 000C1840 */  sll       $v1, $t4, 1
/* D3970 8013D270 30630FFF */  andi      $v1, $v1, 0xfff
/* D3974 8013D274 00031B00 */  sll       $v1, $v1, 0xc
/* D3978 8013D278 ACA20008 */  sw        $v0, 8($a1)
/* D397C 8013D27C 000F1080 */  sll       $v0, $t7, 2
/* D3980 8013D280 30420FFF */  andi      $v0, $v0, 0xfff
/* D3984 8013D284 00441025 */  or        $v0, $v0, $a0
/* D3988 8013D288 00621825 */  or        $v1, $v1, $v0
/* D398C 8013D28C ACA30010 */  sw        $v1, 0x10($a1)
/* D3990 8013D290 25A3FFFF */  addiu     $v1, $t5, -1
/* D3994 8013D294 00031840 */  sll       $v1, $v1, 1
/* D3998 8013D298 30630FFF */  andi      $v1, $v1, 0xfff
/* D399C 8013D29C 00031B00 */  sll       $v1, $v1, 0xc
/* D39A0 8013D2A0 25C2FFFF */  addiu     $v0, $t6, -1
/* D39A4 8013D2A4 00021080 */  sll       $v0, $v0, 2
/* D39A8 8013D2A8 30420FFF */  andi      $v0, $v0, 0xfff
/* D39AC 8013D2AC 3C040700 */  lui       $a0, 0x700
/* D39B0 8013D2B0 00441025 */  or        $v0, $v0, $a0
/* D39B4 8013D2B4 00621825 */  or        $v1, $v1, $v0
/* D39B8 8013D2B8 3C02F540 */  lui       $v0, 0xf540
/* D39BC 8013D2BC 00C23025 */  or        $a2, $a2, $v0
/* D39C0 8013D2C0 ACA30014 */  sw        $v1, 0x14($a1)
/* D39C4 8013D2C4 25830100 */  addiu     $v1, $t4, 0x100
/* D39C8 8013D2C8 00031880 */  sll       $v1, $v1, 2
/* D39CC 8013D2CC 30630FFF */  andi      $v1, $v1, 0xfff
/* D39D0 8013D2D0 00031B00 */  sll       $v1, $v1, 0xc
/* D39D4 8013D2D4 25E20100 */  addiu     $v0, $t7, 0x100
/* D39D8 8013D2D8 00021080 */  sll       $v0, $v0, 2
/* D39DC 8013D2DC 30420FFF */  andi      $v0, $v0, 0xfff
/* D39E0 8013D2E0 004A1025 */  or        $v0, $v0, $t2
/* D39E4 8013D2E4 00621825 */  or        $v1, $v1, $v0
/* D39E8 8013D2E8 ACA30028 */  sw        $v1, 0x28($a1)
/* D39EC 8013D2EC 25A300FF */  addiu     $v1, $t5, 0xff
/* D39F0 8013D2F0 00031880 */  sll       $v1, $v1, 2
/* D39F4 8013D2F4 30630FFF */  andi      $v1, $v1, 0xfff
/* D39F8 8013D2F8 00031B00 */  sll       $v1, $v1, 0xc
/* D39FC 8013D2FC 25C200FF */  addiu     $v0, $t6, 0xff
/* D3A00 8013D300 00021080 */  sll       $v0, $v0, 2
/* D3A04 8013D304 30420FFF */  andi      $v0, $v0, 0xfff
/* D3A08 8013D308 3C040100 */  lui       $a0, 0x100
/* D3A0C 8013D30C 00441025 */  or        $v0, $v0, $a0
/* D3A10 8013D310 00621825 */  or        $v1, $v1, $v0
/* D3A14 8013D314 ACA70004 */  sw        $a3, 4($a1)
/* D3A18 8013D318 ACA0000C */  sw        $zero, 0xc($a1)
/* D3A1C 8013D31C ACBE0018 */  sw        $fp, 0x18($a1)
/* D3A20 8013D320 ACA0001C */  sw        $zero, 0x1c($a1)
/* D3A24 8013D324 ACA60020 */  sw        $a2, 0x20($a1)
/* D3A28 8013D328 ACA80024 */  sw        $t0, 0x24($a1)
/* D3A2C 8013D32C ACA3002C */  sw        $v1, 0x2c($a1)
/* D3A30 8013D330 ACA60030 */  sw        $a2, 0x30($a1)
/* D3A34 8013D334 8FAA0028 */  lw        $t2, 0x28($sp)
/* D3A38 8013D338 3C020200 */  lui       $v0, 0x200
/* D3A3C 8013D33C ACAA0034 */  sw        $t2, 0x34($a1)
/* D3A40 8013D340 3C0AF200 */  lui       $t2, 0xf200
/* D3A44 8013D344 ACA90038 */  sw        $t1, 0x38($a1)
/* D3A48 8013D348 ACA2003C */  sw        $v0, 0x3c($a1)
/* D3A4C 8013D34C ACAA0040 */  sw        $t2, 0x40($a1)
/* D3A50 8013D350 ACAB0044 */  sw        $t3, 0x44($a1)
/* D3A54 8013D354 92230002 */  lbu       $v1, 2($s1)
/* D3A58 8013D358 10760008 */  beq       $v1, $s6, .L8013D37C
/* D3A5C 8013D35C 240800FF */   addiu    $t0, $zero, 0xff
/* D3A60 8013D360 28620003 */  slti      $v0, $v1, 3
/* D3A64 8013D364 14400008 */  bnez      $v0, .L8013D388
/* D3A68 8013D368 24020007 */   addiu    $v0, $zero, 7
/* D3A6C 8013D36C 10620005 */  beq       $v1, $v0, .L8013D384
/* D3A70 8013D370 2402000F */   addiu    $v0, $zero, 0xf
/* D3A74 8013D374 14620004 */  bne       $v1, $v0, .L8013D388
/* D3A78 8013D378 00000000 */   nop
.L8013D37C:
/* D3A7C 8013D37C 0804F4E2 */  j         .L8013D388
/* D3A80 8013D380 8E280038 */   lw       $t0, 0x38($s1)
.L8013D384:
/* D3A84 8013D384 2408FFFF */  addiu     $t0, $zero, -1
.L8013D388:
/* D3A88 8013D388 3C028015 */  lui       $v0, %hi(D_80151328)
/* D3A8C 8013D38C 8C421328 */  lw        $v0, %lo(D_80151328)($v0)
/* D3A90 8013D390 94420000 */  lhu       $v0, ($v0)
/* D3A94 8013D394 30420002 */  andi      $v0, $v0, 2
/* D3A98 8013D398 1040005E */  beqz      $v0, .L8013D514
/* D3A9C 8013D39C 0180282D */   daddu    $a1, $t4, $zero
/* D3AA0 8013D3A0 3C028015 */  lui       $v0, %hi(D_80156954)
/* D3AA4 8013D3A4 8C426954 */  lw        $v0, %lo(D_80156954)($v0)
/* D3AA8 8013D3A8 90420000 */  lbu       $v0, ($v0)
/* D3AAC 8013D3AC 1040005A */  beqz      $v0, .L8013D518
/* D3AB0 8013D3B0 01E0302D */   daddu    $a2, $t7, $zero
/* D3AB4 8013D3B4 8E220014 */  lw        $v0, 0x14($s1)
/* D3AB8 8013D3B8 00581024 */  and       $v0, $v0, $t8
/* D3ABC 8013D3BC 50400057 */  beql      $v0, $zero, .L8013D51C
/* D3AC0 8013D3C0 AFAE0010 */   sw       $t6, 0x10($sp)
/* D3AC4 8013D3C4 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D3AC8 8013D3C8 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D3ACC 8013D3CC 00031080 */  sll       $v0, $v1, 2
/* D3AD0 8013D3D0 00431021 */  addu      $v0, $v0, $v1
/* D3AD4 8013D3D4 00021080 */  sll       $v0, $v0, 2
/* D3AD8 8013D3D8 00431023 */  subu      $v0, $v0, $v1
/* D3ADC 8013D3DC 000218C0 */  sll       $v1, $v0, 3
/* D3AE0 8013D3E0 00431021 */  addu      $v0, $v0, $v1
/* D3AE4 8013D3E4 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* D3AE8 8013D3E8 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* D3AEC 8013D3EC 000210C0 */  sll       $v0, $v0, 3
/* D3AF0 8013D3F0 80630070 */  lb        $v1, 0x70($v1)
/* D3AF4 8013D3F4 14760008 */  bne       $v1, $s6, .L8013D418
/* D3AF8 8013D3F8 00592021 */   addu     $a0, $v0, $t9
/* D3AFC 8013D3FC 8E020000 */  lw        $v0, ($s0)
/* D3B00 8013D400 0040182D */  daddu     $v1, $v0, $zero
/* D3B04 8013D404 24420008 */  addiu     $v0, $v0, 8
/* D3B08 8013D408 AE020000 */  sw        $v0, ($s0)
/* D3B0C 8013D40C AC730000 */  sw        $s3, ($v1)
/* D3B10 8013D410 0804F50D */  j         .L8013D434
/* D3B14 8013D414 AC770004 */   sw       $s7, 4($v1)
.L8013D418:
/* D3B18 8013D418 8E020000 */  lw        $v0, ($s0)
/* D3B1C 8013D41C 0040182D */  daddu     $v1, $v0, $zero
/* D3B20 8013D420 24420008 */  addiu     $v0, $v0, 8
/* D3B24 8013D424 AE020000 */  sw        $v0, ($s0)
/* D3B28 8013D428 248200B0 */  addiu     $v0, $a0, 0xb0
/* D3B2C 8013D42C AC730000 */  sw        $s3, ($v1)
/* D3B30 8013D430 AC620004 */  sw        $v0, 4($v1)
.L8013D434:
/* D3B34 8013D434 8E050000 */  lw        $a1, ($s0)
/* D3B38 8013D438 00A0202D */  daddu     $a0, $a1, $zero
/* D3B3C 8013D43C 24A50008 */  addiu     $a1, $a1, 8
/* D3B40 8013D440 AE050000 */  sw        $a1, ($s0)
/* D3B44 8013D444 AC940000 */  sw        $s4, ($a0)
/* D3B48 8013D448 8E220078 */  lw        $v0, 0x78($s1)
/* D3B4C 8013D44C 3C030C08 */  lui       $v1, 0xc08
/* D3B50 8013D450 00431025 */  or        $v0, $v0, $v1
/* D3B54 8013D454 AC820004 */  sw        $v0, 4($a0)
/* D3B58 8013D458 2402FFFF */  addiu     $v0, $zero, -1
/* D3B5C 8013D45C 15020009 */  bne       $t0, $v0, .L8013D484
/* D3B60 8013D460 3C03FCFF */   lui      $v1, 0xfcff
/* D3B64 8013D464 3C02FCFF */  lui       $v0, 0xfcff
/* D3B68 8013D468 3442C5FF */  ori       $v0, $v0, 0xc5ff
/* D3B6C 8013D46C 24A30008 */  addiu     $v1, $a1, 8
/* D3B70 8013D470 AE030000 */  sw        $v1, ($s0)
/* D3B74 8013D474 ACA20000 */  sw        $v0, ($a1)
/* D3B78 8013D478 2402FFF8 */  addiu     $v0, $zero, -8
/* D3B7C 8013D47C 0804F52D */  j         .L8013D4B4
/* D3B80 8013D480 ACA20004 */   sw       $v0, 4($a1)
.L8013D484:
/* D3B84 8013D484 3463D5FF */  ori       $v1, $v1, 0xd5ff
/* D3B88 8013D488 24A20008 */  addiu     $v0, $a1, 8
/* D3B8C 8013D48C AE020000 */  sw        $v0, ($s0)
/* D3B90 8013D490 3C02FB00 */  lui       $v0, 0xfb00
/* D3B94 8013D494 ACA20000 */  sw        $v0, ($a1)
/* D3B98 8013D498 310200FF */  andi      $v0, $t0, 0xff
/* D3B9C 8013D49C ACA20004 */  sw        $v0, 4($a1)
/* D3BA0 8013D4A0 24A20010 */  addiu     $v0, $a1, 0x10
/* D3BA4 8013D4A4 AE020000 */  sw        $v0, ($s0)
/* D3BA8 8013D4A8 2402FFF8 */  addiu     $v0, $zero, -8
/* D3BAC 8013D4AC ACA30008 */  sw        $v1, 8($a1)
/* D3BB0 8013D4B0 ACA2000C */  sw        $v0, 0xc($a1)
.L8013D4B4:
/* D3BB4 8013D4B4 3C050100 */  lui       $a1, 0x100
/* D3BB8 8013D4B8 34A54008 */  ori       $a1, $a1, 0x4008
/* D3BBC 8013D4BC 3C070600 */  lui       $a3, 0x600
/* D3BC0 8013D4C0 34E70402 */  ori       $a3, $a3, 0x402
/* D3BC4 8013D4C4 3C060002 */  lui       $a2, 2
/* D3BC8 8013D4C8 34C60406 */  ori       $a2, $a2, 0x406
/* D3BCC 8013D4CC 8E030000 */  lw        $v1, ($s0)
/* D3BD0 8013D4D0 3C028015 */  lui       $v0, %hi(D_80156950)
/* D3BD4 8013D4D4 8C426950 */  lw        $v0, %lo(D_80156950)($v0)
/* D3BD8 8013D4D8 0060202D */  daddu     $a0, $v1, $zero
/* D3BDC 8013D4DC 24630008 */  addiu     $v1, $v1, 8
/* D3BE0 8013D4E0 00521021 */  addu      $v0, $v0, $s2
/* D3BE4 8013D4E4 AE030000 */  sw        $v1, ($s0)
/* D3BE8 8013D4E8 AC820004 */  sw        $v0, 4($a0)
/* D3BEC 8013D4EC 24620008 */  addiu     $v0, $v1, 8
/* D3BF0 8013D4F0 AC850000 */  sw        $a1, ($a0)
/* D3BF4 8013D4F4 AE020000 */  sw        $v0, ($s0)
/* D3BF8 8013D4F8 24620010 */  addiu     $v0, $v1, 0x10
/* D3BFC 8013D4FC AC670000 */  sw        $a3, ($v1)
/* D3C00 8013D500 AC660004 */  sw        $a2, 4($v1)
/* D3C04 8013D504 AE020000 */  sw        $v0, ($s0)
/* D3C08 8013D508 AC7E0008 */  sw        $fp, 8($v1)
/* D3C0C 8013D50C AC60000C */  sw        $zero, 0xc($v1)
/* D3C10 8013D510 0180282D */  daddu     $a1, $t4, $zero
.L8013D514:
/* D3C14 8013D514 01E0302D */  daddu     $a2, $t7, $zero
.L8013D518:
/* D3C18 8013D518 AFAE0010 */  sw        $t6, 0x10($sp)
.L8013D51C:
/* D3C1C 8013D51C AFA80014 */  sw        $t0, 0x14($sp)
/* D3C20 8013D520 8E220078 */  lw        $v0, 0x78($s1)
/* D3C24 8013D524 8FA4005C */  lw        $a0, 0x5c($sp)
/* D3C28 8013D528 01A0382D */  daddu     $a3, $t5, $zero
/* D3C2C 8013D52C AFB80020 */  sw        $t8, 0x20($sp)
/* D3C30 8013D530 AFB90024 */  sw        $t9, 0x24($sp)
/* D3C34 8013D534 0C052071 */  jal       render_shaded_sprite
/* D3C38 8013D538 AFA20018 */   sw       $v0, 0x18($sp)
/* D3C3C 8013D53C 8FB80020 */  lw        $t8, 0x20($sp)
/* D3C40 8013D540 0804F64E */  j         .L8013D938
/* D3C44 8013D544 8FB90024 */   lw       $t9, 0x24($sp)
.L8013D548:
/* D3C48 8013D548 34C60280 */  ori       $a2, $a2, 0x280
.L8013D54C:
/* D3C4C 8013D54C 3C07000A */  lui       $a3, 0xa
/* D3C50 8013D550 34E70280 */  ori       $a3, $a3, 0x280
/* D3C54 8013D554 8E080000 */  lw        $t0, ($s0)
/* D3C58 8013D558 3C0AF200 */  lui       $t2, 0xf200
/* D3C5C 8013D55C 0100282D */  daddu     $a1, $t0, $zero
/* D3C60 8013D560 25080008 */  addiu     $t0, $t0, 8
/* D3C64 8013D564 25020008 */  addiu     $v0, $t0, 8
/* D3C68 8013D568 AE080000 */  sw        $t0, ($s0)
/* D3C6C 8013D56C AE020000 */  sw        $v0, ($s0)
/* D3C70 8013D570 25020010 */  addiu     $v0, $t0, 0x10
/* D3C74 8013D574 AE020000 */  sw        $v0, ($s0)
/* D3C78 8013D578 3C048015 */  lui       $a0, %hi(D_8014EE10)
/* D3C7C 8013D57C 8C84EE10 */  lw        $a0, %lo(D_8014EE10)($a0)
/* D3C80 8013D580 25020018 */  addiu     $v0, $t0, 0x18
/* D3C84 8013D584 AE020000 */  sw        $v0, ($s0)
/* D3C88 8013D588 94820008 */  lhu       $v0, 8($a0)
/* D3C8C 8013D58C 25030020 */  addiu     $v1, $t0, 0x20
/* D3C90 8013D590 AE030000 */  sw        $v1, ($s0)
/* D3C94 8013D594 3C03FD48 */  lui       $v1, 0xfd48
/* D3C98 8013D598 00021042 */  srl       $v0, $v0, 1
/* D3C9C 8013D59C 2442FFFF */  addiu     $v0, $v0, -1
/* D3CA0 8013D5A0 30420FFF */  andi      $v0, $v0, 0xfff
/* D3CA4 8013D5A4 00431025 */  or        $v0, $v0, $v1
/* D3CA8 8013D5A8 ACA20000 */  sw        $v0, ($a1)
/* D3CAC 8013D5AC 8C830000 */  lw        $v1, ($a0)
/* D3CB0 8013D5B0 25020028 */  addiu     $v0, $t0, 0x28
/* D3CB4 8013D5B4 AE020000 */  sw        $v0, ($s0)
/* D3CB8 8013D5B8 3C02F548 */  lui       $v0, 0xf548
/* D3CBC 8013D5BC 3C04F400 */  lui       $a0, 0xf400
/* D3CC0 8013D5C0 ACA30004 */  sw        $v1, 4($a1)
/* D3CC4 8013D5C4 01AC2823 */  subu      $a1, $t5, $t4
/* D3CC8 8013D5C8 00052843 */  sra       $a1, $a1, 1
/* D3CCC 8013D5CC 24A50007 */  addiu     $a1, $a1, 7
/* D3CD0 8013D5D0 000528C3 */  sra       $a1, $a1, 3
/* D3CD4 8013D5D4 30A501FF */  andi      $a1, $a1, 0x1ff
/* D3CD8 8013D5D8 00052A40 */  sll       $a1, $a1, 9
/* D3CDC 8013D5DC 00A21025 */  or        $v0, $a1, $v0
/* D3CE0 8013D5E0 AD020000 */  sw        $v0, ($t0)
/* D3CE4 8013D5E4 3C02E600 */  lui       $v0, 0xe600
/* D3CE8 8013D5E8 000C1840 */  sll       $v1, $t4, 1
/* D3CEC 8013D5EC 30630FFF */  andi      $v1, $v1, 0xfff
/* D3CF0 8013D5F0 00031B00 */  sll       $v1, $v1, 0xc
/* D3CF4 8013D5F4 AD020008 */  sw        $v0, 8($t0)
/* D3CF8 8013D5F8 000F1080 */  sll       $v0, $t7, 2
/* D3CFC 8013D5FC 30420FFF */  andi      $v0, $v0, 0xfff
/* D3D00 8013D600 00441025 */  or        $v0, $v0, $a0
/* D3D04 8013D604 00621825 */  or        $v1, $v1, $v0
/* D3D08 8013D608 AD030010 */  sw        $v1, 0x10($t0)
/* D3D0C 8013D60C 25A3FFFF */  addiu     $v1, $t5, -1
/* D3D10 8013D610 00031840 */  sll       $v1, $v1, 1
/* D3D14 8013D614 30630FFF */  andi      $v1, $v1, 0xfff
/* D3D18 8013D618 00031B00 */  sll       $v1, $v1, 0xc
/* D3D1C 8013D61C 25C2FFFF */  addiu     $v0, $t6, -1
/* D3D20 8013D620 00021080 */  sll       $v0, $v0, 2
/* D3D24 8013D624 30420FFF */  andi      $v0, $v0, 0xfff
/* D3D28 8013D628 3C040700 */  lui       $a0, 0x700
/* D3D2C 8013D62C 00441025 */  or        $v0, $v0, $a0
/* D3D30 8013D630 00621825 */  or        $v1, $v1, $v0
/* D3D34 8013D634 3C02F540 */  lui       $v0, 0xf540
/* D3D38 8013D638 00A22825 */  or        $a1, $a1, $v0
/* D3D3C 8013D63C AD030014 */  sw        $v1, 0x14($t0)
/* D3D40 8013D640 25830100 */  addiu     $v1, $t4, 0x100
/* D3D44 8013D644 00031880 */  sll       $v1, $v1, 2
/* D3D48 8013D648 30630FFF */  andi      $v1, $v1, 0xfff
/* D3D4C 8013D64C 00031B00 */  sll       $v1, $v1, 0xc
/* D3D50 8013D650 25E20100 */  addiu     $v0, $t7, 0x100
/* D3D54 8013D654 00021080 */  sll       $v0, $v0, 2
/* D3D58 8013D658 30420FFF */  andi      $v0, $v0, 0xfff
/* D3D5C 8013D65C 004A1025 */  or        $v0, $v0, $t2
/* D3D60 8013D660 00621825 */  or        $v1, $v1, $v0
/* D3D64 8013D664 AD030028 */  sw        $v1, 0x28($t0)
/* D3D68 8013D668 25A300FF */  addiu     $v1, $t5, 0xff
/* D3D6C 8013D66C 00031880 */  sll       $v1, $v1, 2
/* D3D70 8013D670 30630FFF */  andi      $v1, $v1, 0xfff
/* D3D74 8013D674 00031B00 */  sll       $v1, $v1, 0xc
/* D3D78 8013D678 25C200FF */  addiu     $v0, $t6, 0xff
/* D3D7C 8013D67C 00021080 */  sll       $v0, $v0, 2
/* D3D80 8013D680 30420FFF */  andi      $v0, $v0, 0xfff
/* D3D84 8013D684 3C048015 */  lui       $a0, %hi(D_80151328)
/* D3D88 8013D688 8C841328 */  lw        $a0, %lo(D_80151328)($a0)
/* D3D8C 8013D68C 00621825 */  or        $v1, $v1, $v0
/* D3D90 8013D690 AD060004 */  sw        $a2, 4($t0)
/* D3D94 8013D694 AD00000C */  sw        $zero, 0xc($t0)
/* D3D98 8013D698 AD1E0018 */  sw        $fp, 0x18($t0)
/* D3D9C 8013D69C AD00001C */  sw        $zero, 0x1c($t0)
/* D3DA0 8013D6A0 AD050020 */  sw        $a1, 0x20($t0)
/* D3DA4 8013D6A4 AD070024 */  sw        $a3, 0x24($t0)
/* D3DA8 8013D6A8 AD03002C */  sw        $v1, 0x2c($t0)
/* D3DAC 8013D6AC 94830000 */  lhu       $v1, ($a0)
/* D3DB0 8013D6B0 25020030 */  addiu     $v0, $t0, 0x30
/* D3DB4 8013D6B4 30630002 */  andi      $v1, $v1, 2
/* D3DB8 8013D6B8 106000D8 */  beqz      $v1, .L8013DA1C
/* D3DBC 8013D6BC AE020000 */   sw       $v0, ($s0)
/* D3DC0 8013D6C0 92220000 */  lbu       $v0, ($s1)
/* D3DC4 8013D6C4 1040009C */  beqz      $v0, .L8013D938
/* D3DC8 8013D6C8 00000000 */   nop
/* D3DCC 8013D6CC 8E220014 */  lw        $v0, 0x14($s1)
/* D3DD0 8013D6D0 00581024 */  and       $v0, $v0, $t8
/* D3DD4 8013D6D4 10400098 */  beqz      $v0, .L8013D938
/* D3DD8 8013D6D8 240900FF */   addiu    $t1, $zero, 0xff
/* D3DDC 8013D6DC 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D3DE0 8013D6E0 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D3DE4 8013D6E4 00031080 */  sll       $v0, $v1, 2
/* D3DE8 8013D6E8 00431021 */  addu      $v0, $v0, $v1
/* D3DEC 8013D6EC 00021080 */  sll       $v0, $v0, 2
/* D3DF0 8013D6F0 00431023 */  subu      $v0, $v0, $v1
/* D3DF4 8013D6F4 000218C0 */  sll       $v1, $v0, 3
/* D3DF8 8013D6F8 00431021 */  addu      $v0, $v0, $v1
/* D3DFC 8013D6FC 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* D3E00 8013D700 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* D3E04 8013D704 000210C0 */  sll       $v0, $v0, 3
/* D3E08 8013D708 80630070 */  lb        $v1, 0x70($v1)
/* D3E0C 8013D70C 14760006 */  bne       $v1, $s6, .L8013D728
/* D3E10 8013D710 00592021 */   addu     $a0, $v0, $t9
/* D3E14 8013D714 25020038 */  addiu     $v0, $t0, 0x38
/* D3E18 8013D718 AE020000 */  sw        $v0, ($s0)
/* D3E1C 8013D71C AD130030 */  sw        $s3, 0x30($t0)
/* D3E20 8013D720 0804F5CF */  j         .L8013D73C
/* D3E24 8013D724 AD170034 */   sw       $s7, 0x34($t0)
.L8013D728:
/* D3E28 8013D728 25020038 */  addiu     $v0, $t0, 0x38
/* D3E2C 8013D72C AE020000 */  sw        $v0, ($s0)
/* D3E30 8013D730 248200B0 */  addiu     $v0, $a0, 0xb0
/* D3E34 8013D734 AD130030 */  sw        $s3, 0x30($t0)
/* D3E38 8013D738 AD020034 */  sw        $v0, 0x34($t0)
.L8013D73C:
/* D3E3C 8013D73C 240200FF */  addiu     $v0, $zero, 0xff
/* D3E40 8013D740 55220005 */  bnel      $t1, $v0, .L8013D758
/* D3E44 8013D744 3C020050 */   lui      $v0, 0x50
/* D3E48 8013D748 3C020055 */  lui       $v0, 0x55
/* D3E4C 8013D74C 8E030000 */  lw        $v1, ($s0)
/* D3E50 8013D750 0804F5D8 */  j         .L8013D760
/* D3E54 8013D754 34423078 */   ori      $v0, $v0, 0x3078
.L8013D758:
/* D3E58 8013D758 8E030000 */  lw        $v1, ($s0)
/* D3E5C 8013D75C 34424A50 */  ori       $v0, $v0, 0x4a50
.L8013D760:
/* D3E60 8013D760 0060202D */  daddu     $a0, $v1, $zero
/* D3E64 8013D764 24630008 */  addiu     $v1, $v1, 8
/* D3E68 8013D768 AE030000 */  sw        $v1, ($s0)
/* D3E6C 8013D76C AC940000 */  sw        $s4, ($a0)
/* D3E70 8013D770 AC820004 */  sw        $v0, 4($a0)
/* D3E74 8013D774 92230002 */  lbu       $v1, 2($s1)
/* D3E78 8013D778 1076000F */  beq       $v1, $s6, .L8013D7B8
/* D3E7C 8013D77C 28620003 */   slti     $v0, $v1, 3
/* D3E80 8013D780 10400005 */  beqz      $v0, .L8013D798
/* D3E84 8013D784 24020007 */   addiu    $v0, $zero, 7
/* D3E88 8013D788 10600009 */  beqz      $v1, .L8013D7B0
/* D3E8C 8013D78C 2402FFFF */   addiu    $v0, $zero, -1
/* D3E90 8013D790 0804F5F3 */  j         .L8013D7CC
/* D3E94 8013D794 00000000 */   nop
.L8013D798:
/* D3E98 8013D798 1062000A */  beq       $v1, $v0, .L8013D7C4
/* D3E9C 8013D79C 2402000F */   addiu    $v0, $zero, 0xf
/* D3EA0 8013D7A0 10620005 */  beq       $v1, $v0, .L8013D7B8
/* D3EA4 8013D7A4 2402FFFF */   addiu    $v0, $zero, -1
/* D3EA8 8013D7A8 0804F5F3 */  j         .L8013D7CC
/* D3EAC 8013D7AC 00000000 */   nop
.L8013D7B0:
/* D3EB0 8013D7B0 0804F5F2 */  j         .L8013D7C8
/* D3EB4 8013D7B4 240900FF */   addiu    $t1, $zero, 0xff
.L8013D7B8:
/* D3EB8 8013D7B8 8E290038 */  lw        $t1, 0x38($s1)
/* D3EBC 8013D7BC 0804F5F3 */  j         .L8013D7CC
/* D3EC0 8013D7C0 2402FFFF */   addiu    $v0, $zero, -1
.L8013D7C4:
/* D3EC4 8013D7C4 2409FFFF */  addiu     $t1, $zero, -1
.L8013D7C8:
/* D3EC8 8013D7C8 2402FFFF */  addiu     $v0, $zero, -1
.L8013D7CC:
/* D3ECC 8013D7CC 1522000C */  bne       $t1, $v0, .L8013D800
/* D3ED0 8013D7D0 3C06FCFF */   lui      $a2, 0xfcff
/* D3ED4 8013D7D4 3C05FCFF */  lui       $a1, 0xfcff
/* D3ED8 8013D7D8 34A5C3FF */  ori       $a1, $a1, 0xc3ff
/* D3EDC 8013D7DC 3C04FF87 */  lui       $a0, 0xff87
/* D3EE0 8013D7E0 8E020000 */  lw        $v0, ($s0)
/* D3EE4 8013D7E4 3484FFFF */  ori       $a0, $a0, 0xffff
/* D3EE8 8013D7E8 0040182D */  daddu     $v1, $v0, $zero
/* D3EEC 8013D7EC 24420008 */  addiu     $v0, $v0, 8
/* D3EF0 8013D7F0 AE020000 */  sw        $v0, ($s0)
/* D3EF4 8013D7F4 AC650000 */  sw        $a1, ($v1)
/* D3EF8 8013D7F8 0804F60F */  j         .L8013D83C
/* D3EFC 8013D7FC AC640004 */   sw       $a0, 4($v1)
.L8013D800:
/* D3F00 8013D800 34C6D3FF */  ori       $a2, $a2, 0xd3ff
/* D3F04 8013D804 3C05FFA7 */  lui       $a1, 0xffa7
/* D3F08 8013D808 34A5FFFF */  ori       $a1, $a1, 0xffff
/* D3F0C 8013D80C 8E030000 */  lw        $v1, ($s0)
/* D3F10 8013D810 3C02FB00 */  lui       $v0, 0xfb00
/* D3F14 8013D814 0060202D */  daddu     $a0, $v1, $zero
/* D3F18 8013D818 24630008 */  addiu     $v1, $v1, 8
/* D3F1C 8013D81C AE030000 */  sw        $v1, ($s0)
/* D3F20 8013D820 AC820000 */  sw        $v0, ($a0)
/* D3F24 8013D824 312200FF */  andi      $v0, $t1, 0xff
/* D3F28 8013D828 AC820004 */  sw        $v0, 4($a0)
/* D3F2C 8013D82C 24620008 */  addiu     $v0, $v1, 8
/* D3F30 8013D830 AE020000 */  sw        $v0, ($s0)
/* D3F34 8013D834 AC660000 */  sw        $a2, ($v1)
/* D3F38 8013D838 AC650004 */  sw        $a1, 4($v1)
.L8013D83C:
/* D3F3C 8013D83C 3C040100 */  lui       $a0, 0x100
/* D3F40 8013D840 34844008 */  ori       $a0, $a0, 0x4008
/* D3F44 8013D844 3C060600 */  lui       $a2, 0x600
/* D3F48 8013D848 34C60402 */  ori       $a2, $a2, 0x402
/* D3F4C 8013D84C 3C050002 */  lui       $a1, 2
/* D3F50 8013D850 34A50406 */  ori       $a1, $a1, 0x406
/* D3F54 8013D854 8E070000 */  lw        $a3, ($s0)
/* D3F58 8013D858 3C028015 */  lui       $v0, %hi(D_80156950)
/* D3F5C 8013D85C 8C426950 */  lw        $v0, %lo(D_80156950)($v0)
/* D3F60 8013D860 00E0182D */  daddu     $v1, $a3, $zero
/* D3F64 8013D864 24E70008 */  addiu     $a3, $a3, 8
/* D3F68 8013D868 00521021 */  addu      $v0, $v0, $s2
/* D3F6C 8013D86C AE070000 */  sw        $a3, ($s0)
/* D3F70 8013D870 AC620004 */  sw        $v0, 4($v1)
/* D3F74 8013D874 24E20008 */  addiu     $v0, $a3, 8
/* D3F78 8013D878 AC640000 */  sw        $a0, ($v1)
/* D3F7C 8013D87C AE020000 */  sw        $v0, ($s0)
/* D3F80 8013D880 24E20010 */  addiu     $v0, $a3, 0x10
/* D3F84 8013D884 ACE60000 */  sw        $a2, ($a3)
/* D3F88 8013D888 ACE50004 */  sw        $a1, 4($a3)
/* D3F8C 8013D88C AE020000 */  sw        $v0, ($s0)
/* D3F90 8013D890 240200FF */  addiu     $v0, $zero, 0xff
/* D3F94 8013D894 ACFE0008 */  sw        $fp, 8($a3)
/* D3F98 8013D898 15220004 */  bne       $t1, $v0, .L8013D8AC
/* D3F9C 8013D89C ACE0000C */   sw       $zero, 0xc($a3)
/* D3FA0 8013D8A0 3C030055 */  lui       $v1, 0x55
/* D3FA4 8013D8A4 0804F62D */  j         .L8013D8B4
/* D3FA8 8013D8A8 34633078 */   ori      $v1, $v1, 0x3078
.L8013D8AC:
/* D3FAC 8013D8AC 3C030050 */  lui       $v1, 0x50
/* D3FB0 8013D8B0 34634A50 */  ori       $v1, $v1, 0x4a50
.L8013D8B4:
/* D3FB4 8013D8B4 24E20018 */  addiu     $v0, $a3, 0x18
/* D3FB8 8013D8B8 AE020000 */  sw        $v0, ($s0)
/* D3FBC 8013D8BC ACF40010 */  sw        $s4, 0x10($a3)
/* D3FC0 8013D8C0 ACE30014 */  sw        $v1, 0x14($a3)
/* D3FC4 8013D8C4 3C056464 */  lui       $a1, 0x6464
/* D3FC8 8013D8C8 34A564FF */  ori       $a1, $a1, 0x64ff
/* D3FCC 8013D8CC 3C07FC40 */  lui       $a3, 0xfc40
/* D3FD0 8013D8D0 34E7FE81 */  ori       $a3, $a3, 0xfe81
/* D3FD4 8013D8D4 3C0655FC */  lui       $a2, 0x55fc
/* D3FD8 8013D8D8 34C6F279 */  ori       $a2, $a2, 0xf279
/* D3FDC 8013D8DC 3C08E300 */  lui       $t0, 0xe300
/* D3FE0 8013D8E0 35081801 */  ori       $t0, $t0, 0x1801
/* D3FE4 8013D8E4 8E030000 */  lw        $v1, ($s0)
/* D3FE8 8013D8E8 3C02FB00 */  lui       $v0, 0xfb00
/* D3FEC 8013D8EC 0060202D */  daddu     $a0, $v1, $zero
/* D3FF0 8013D8F0 24630008 */  addiu     $v1, $v1, 8
/* D3FF4 8013D8F4 AE030000 */  sw        $v1, ($s0)
/* D3FF8 8013D8F8 AC820000 */  sw        $v0, ($a0)
/* D3FFC 8013D8FC 24620008 */  addiu     $v0, $v1, 8
/* D4000 8013D900 AC850004 */  sw        $a1, 4($a0)
/* D4004 8013D904 AE020000 */  sw        $v0, ($s0)
/* D4008 8013D908 3C02FA00 */  lui       $v0, 0xfa00
/* D400C 8013D90C AC620000 */  sw        $v0, ($v1)
/* D4010 8013D910 312200FF */  andi      $v0, $t1, 0xff
/* D4014 8013D914 AC620004 */  sw        $v0, 4($v1)
/* D4018 8013D918 24620010 */  addiu     $v0, $v1, 0x10
/* D401C 8013D91C AE020000 */  sw        $v0, ($s0)
/* D4020 8013D920 24620018 */  addiu     $v0, $v1, 0x18
/* D4024 8013D924 AC670008 */  sw        $a3, 8($v1)
/* D4028 8013D928 AC66000C */  sw        $a2, 0xc($v1)
/* D402C 8013D92C AE020000 */  sw        $v0, ($s0)
/* D4030 8013D930 AC680010 */  sw        $t0, 0x10($v1)
/* D4034 8013D934 AC600014 */  sw        $zero, 0x14($v1)
.L8013D938:
/* D4038 8013D938 3C028015 */  lui       $v0, %hi(D_80151328)
/* D403C 8013D93C 8C421328 */  lw        $v0, %lo(D_80151328)($v0)
/* D4040 8013D940 94420000 */  lhu       $v0, ($v0)
/* D4044 8013D944 30420002 */  andi      $v0, $v0, 2
/* D4048 8013D948 10400035 */  beqz      $v0, .L8013DA20
/* D404C 8013D94C 3C050100 */   lui      $a1, 0x100
/* D4050 8013D950 3C028015 */  lui       $v0, %hi(D_80156954)
/* D4054 8013D954 8C426954 */  lw        $v0, %lo(D_80156954)($v0)
/* D4058 8013D958 90420000 */  lbu       $v0, ($v0)
/* D405C 8013D95C 10400031 */  beqz      $v0, .L8013DA24
/* D4060 8013D960 34A54008 */   ori      $a1, $a1, 0x4008
/* D4064 8013D964 8E220014 */  lw        $v0, 0x14($s1)
/* D4068 8013D968 00581024 */  and       $v0, $v0, $t8
/* D406C 8013D96C 1040002C */  beqz      $v0, .L8013DA20
/* D4070 8013D970 3C050100 */   lui      $a1, 0x100
/* D4074 8013D974 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* D4078 8013D978 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* D407C 8013D97C 3C058007 */  lui       $a1, %hi(gGameStatusPtr)
/* D4080 8013D980 8CA5419C */  lw        $a1, %lo(gGameStatusPtr)($a1)
/* D4084 8013D984 00031080 */  sll       $v0, $v1, 2
/* D4088 8013D988 00431021 */  addu      $v0, $v0, $v1
/* D408C 8013D98C 00021080 */  sll       $v0, $v0, 2
/* D4090 8013D990 00431023 */  subu      $v0, $v0, $v1
/* D4094 8013D994 000218C0 */  sll       $v1, $v0, 3
/* D4098 8013D998 00431021 */  addu      $v0, $v0, $v1
/* D409C 8013D99C 000210C0 */  sll       $v0, $v0, 3
/* D40A0 8013D9A0 80A30070 */  lb        $v1, 0x70($a1)
/* D40A4 8013D9A4 14760016 */  bne       $v1, $s6, .L8013DA00
/* D40A8 8013D9A8 00592021 */   addu     $a0, $v0, $t9
/* D40AC 8013D9AC 8E020000 */  lw        $v0, ($s0)
/* D40B0 8013D9B0 3C048015 */  lui       $a0, %hi(D_8014EE40)
/* D40B4 8013D9B4 2484EE40 */  addiu     $a0, $a0, %lo(D_8014EE40)
/* D40B8 8013D9B8 0040182D */  daddu     $v1, $v0, $zero
/* D40BC 8013D9BC 24420008 */  addiu     $v0, $v0, 8
/* D40C0 8013D9C0 AE020000 */  sw        $v0, ($s0)
/* D40C4 8013D9C4 AC730000 */  sw        $s3, ($v1)
/* D40C8 8013D9C8 AC640004 */  sw        $a0, 4($v1)
/* D40CC 8013D9CC 90A20082 */  lbu       $v0, 0x82($a1)
/* D40D0 8013D9D0 94830008 */  lhu       $v1, 8($a0)
/* D40D4 8013D9D4 00021600 */  sll       $v0, $v0, 0x18
/* D40D8 8013D9D8 00021603 */  sra       $v0, $v0, 0x18
/* D40DC 8013D9DC 00621821 */  addu      $v1, $v1, $v0
/* D40E0 8013D9E0 A6E30008 */  sh        $v1, 8($s7)
/* D40E4 8013D9E4 90A20083 */  lbu       $v0, 0x83($a1)
/* D40E8 8013D9E8 9483000A */  lhu       $v1, 0xa($a0)
/* D40EC 8013D9EC 00021600 */  sll       $v0, $v0, 0x18
/* D40F0 8013D9F0 00021603 */  sra       $v0, $v0, 0x18
/* D40F4 8013D9F4 00621821 */  addu      $v1, $v1, $v0
/* D40F8 8013D9F8 0804F687 */  j         .L8013DA1C
/* D40FC 8013D9FC A6E3000A */   sh       $v1, 0xa($s7)
.L8013DA00:
/* D4100 8013DA00 8E020000 */  lw        $v0, ($s0)
/* D4104 8013DA04 0040182D */  daddu     $v1, $v0, $zero
/* D4108 8013DA08 24420008 */  addiu     $v0, $v0, 8
/* D410C 8013DA0C AE020000 */  sw        $v0, ($s0)
/* D4110 8013DA10 248200A0 */  addiu     $v0, $a0, 0xa0
/* D4114 8013DA14 AC730000 */  sw        $s3, ($v1)
/* D4118 8013DA18 AC620004 */  sw        $v0, 4($v1)
.L8013DA1C:
/* D411C 8013DA1C 3C050100 */  lui       $a1, 0x100
.L8013DA20:
/* D4120 8013DA20 34A54008 */  ori       $a1, $a1, 0x4008
.L8013DA24:
/* D4124 8013DA24 3C070600 */  lui       $a3, 0x600
/* D4128 8013DA28 34E70402 */  ori       $a3, $a3, 0x402
/* D412C 8013DA2C 3C060002 */  lui       $a2, 2
/* D4130 8013DA30 34C60406 */  ori       $a2, $a2, 0x406
/* D4134 8013DA34 8E030000 */  lw        $v1, ($s0)
/* D4138 8013DA38 3C028015 */  lui       $v0, %hi(D_80156950)
/* D413C 8013DA3C 8C426950 */  lw        $v0, %lo(D_80156950)($v0)
/* D4140 8013DA40 0060202D */  daddu     $a0, $v1, $zero
/* D4144 8013DA44 24630008 */  addiu     $v1, $v1, 8
/* D4148 8013DA48 00521021 */  addu      $v0, $v0, $s2
/* D414C 8013DA4C AE030000 */  sw        $v1, ($s0)
/* D4150 8013DA50 AC820004 */  sw        $v0, 4($a0)
/* D4154 8013DA54 24620008 */  addiu     $v0, $v1, 8
/* D4158 8013DA58 AC850000 */  sw        $a1, ($a0)
/* D415C 8013DA5C AE020000 */  sw        $v0, ($s0)
/* D4160 8013DA60 AC670000 */  sw        $a3, ($v1)
/* D4164 8013DA64 AC660004 */  sw        $a2, 4($v1)
/* D4168 8013DA68 9623000A */  lhu       $v1, 0xa($s1)
/* D416C 8013DA6C 26A20003 */  addiu     $v0, $s5, 3
/* D4170 8013DA70 0043102A */  slt       $v0, $v0, $v1
/* D4174 8013DA74 10400003 */  beqz      $v0, .L8013DA84
/* D4178 8013DA78 26520020 */   addiu    $s2, $s2, 0x20
/* D417C 8013DA7C 0804F439 */  j         .L8013D0E4
/* D4180 8013DA80 26B50002 */   addiu    $s5, $s5, 2
.L8013DA84:
/* D4184 8013DA84 8FBF0054 */  lw        $ra, 0x54($sp)
/* D4188 8013DA88 8FBE0050 */  lw        $fp, 0x50($sp)
/* D418C 8013DA8C 8FB7004C */  lw        $s7, 0x4c($sp)
/* D4190 8013DA90 8FB60048 */  lw        $s6, 0x48($sp)
/* D4194 8013DA94 8FB50044 */  lw        $s5, 0x44($sp)
/* D4198 8013DA98 8FB40040 */  lw        $s4, 0x40($sp)
/* D419C 8013DA9C 8FB3003C */  lw        $s3, 0x3c($sp)
/* D41A0 8013DAA0 8FB20038 */  lw        $s2, 0x38($sp)
/* D41A4 8013DAA4 8FB10034 */  lw        $s1, 0x34($sp)
/* D41A8 8013DAA8 8FB00030 */  lw        $s0, 0x30($sp)
/* D41AC 8013DAAC 03E00008 */  jr        $ra
/* D41B0 8013DAB0 27BD0058 */   addiu    $sp, $sp, 0x58
