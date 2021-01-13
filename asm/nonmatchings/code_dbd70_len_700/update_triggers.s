.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel update_triggers
/* DBF60 80145860 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DBF64 80145864 AFB20020 */  sw        $s2, 0x20($sp)
/* DBF68 80145868 3C128016 */  lui       $s2, %hi(gCollisionStatus)
/* DBF6C 8014586C 2652A550 */  addiu     $s2, $s2, %lo(gCollisionStatus)
/* DBF70 80145870 AFB30024 */  sw        $s3, 0x24($sp)
/* DBF74 80145874 0000982D */  daddu     $s3, $zero, $zero
/* DBF78 80145878 AFBF0028 */  sw        $ra, 0x28($sp)
/* DBF7C 8014587C AFB1001C */  sw        $s1, 0x1c($sp)
/* DBF80 80145880 AFB00018 */  sw        $s0, 0x18($sp)
/* DBF84 80145884 A6400016 */  sh        $zero, 0x16($s2)
.L80145888:
/* DBF88 80145888 3C038016 */  lui       $v1, %hi(gCurrentTriggerListPtr)
/* DBF8C 8014588C 8C639390 */  lw        $v1, %lo(gCurrentTriggerListPtr)($v1)
/* DBF90 80145890 00131080 */  sll       $v0, $s3, 2
/* DBF94 80145894 00431021 */  addu      $v0, $v0, $v1
/* DBF98 80145898 8C510000 */  lw        $s1, ($v0)
/* DBF9C 8014589C 522000B1 */  beql      $s1, $zero, .L80145B64
/* DBFA0 801458A0 26730001 */   addiu    $s3, $s3, 1
/* DBFA4 801458A4 8E230000 */  lw        $v1, ($s1)
/* DBFA8 801458A8 30620001 */  andi      $v0, $v1, 1
/* DBFAC 801458AC 504000AD */  beql      $v0, $zero, .L80145B64
/* DBFB0 801458B0 26730001 */   addiu    $s3, $s3, 1
/* DBFB4 801458B4 30620010 */  andi      $v0, $v1, 0x10
/* DBFB8 801458B8 144000A8 */  bnez      $v0, .L80145B5C
/* DBFBC 801458BC 34620002 */   ori      $v0, $v1, 2
/* DBFC0 801458C0 30620040 */  andi      $v0, $v1, 0x40
/* DBFC4 801458C4 1040000D */  beqz      $v0, .L801458FC
/* DBFC8 801458C8 00000000 */   nop
/* DBFCC 801458CC 86430012 */  lh        $v1, 0x12($s2)
/* DBFD0 801458D0 8E220008 */  lw        $v0, 8($s1)
/* DBFD4 801458D4 14430003 */  bne       $v0, $v1, .L801458E4
/* DBFD8 801458D8 00000000 */   nop
/* DBFDC 801458DC 0C0381B0 */  jal       func_800E06C0
/* DBFE0 801458E0 24040001 */   addiu    $a0, $zero, 1
.L801458E4:
/* DBFE4 801458E4 86430000 */  lh        $v1, ($s2)
/* DBFE8 801458E8 8E220008 */  lw        $v0, 8($s1)
/* DBFEC 801458EC 5443009D */  bnel      $v0, $v1, .L80145B64
/* DBFF0 801458F0 26730001 */   addiu    $s3, $s3, 1
/* DBFF4 801458F4 0C0381B0 */  jal       func_800E06C0
/* DBFF8 801458F8 0000202D */   daddu    $a0, $zero, $zero
.L801458FC:
/* DBFFC 801458FC 8E240000 */  lw        $a0, ($s1)
/* DC000 80145900 30820080 */  andi      $v0, $a0, 0x80
/* DC004 80145904 10400006 */  beqz      $v0, .L80145920
/* DC008 80145908 3C020008 */   lui      $v0, 8
/* DC00C 8014590C 86430002 */  lh        $v1, 2($s2)
/* DC010 80145910 8E220008 */  lw        $v0, 8($s1)
/* DC014 80145914 54430093 */  bnel      $v0, $v1, .L80145B64
/* DC018 80145918 26730001 */   addiu    $s3, $s3, 1
/* DC01C 8014591C 3C020008 */  lui       $v0, 8
.L80145920:
/* DC020 80145920 00821024 */  and       $v0, $a0, $v0
/* DC024 80145924 10400006 */  beqz      $v0, .L80145940
/* DC028 80145928 30820100 */   andi     $v0, $a0, 0x100
/* DC02C 8014592C 86430006 */  lh        $v1, 6($s2)
/* DC030 80145930 8E220008 */  lw        $v0, 8($s1)
/* DC034 80145934 5443008B */  bnel      $v0, $v1, .L80145B64
/* DC038 80145938 26730001 */   addiu    $s3, $s3, 1
/* DC03C 8014593C 30820100 */  andi      $v0, $a0, 0x100
.L80145940:
/* DC040 80145940 1040000E */  beqz      $v0, .L8014597C
/* DC044 80145944 00000000 */   nop
/* DC048 80145948 86430012 */  lh        $v1, 0x12($s2)
/* DC04C 8014594C 8E220008 */  lw        $v0, 8($s1)
/* DC050 80145950 14430002 */  bne       $v0, $v1, .L8014595C
/* DC054 80145954 24020001 */   addiu    $v0, $zero, 1
/* DC058 80145958 A6420016 */  sh        $v0, 0x16($s2)
.L8014595C:
/* DC05C 8014595C 8643000A */  lh        $v1, 0xa($s2)
/* DC060 80145960 8E220008 */  lw        $v0, 8($s1)
/* DC064 80145964 5443007F */  bnel      $v0, $v1, .L80145B64
/* DC068 80145968 26730001 */   addiu    $s3, $s3, 1
/* DC06C 8014596C 0C0394BE */  jal       func_800E52F8
/* DC070 80145970 00000000 */   nop
/* DC074 80145974 5040007B */  beql      $v0, $zero, .L80145B64
/* DC078 80145978 26730001 */   addiu    $s3, $s3, 1
.L8014597C:
/* DC07C 8014597C 8E240000 */  lw        $a0, ($s1)
/* DC080 80145980 30820400 */  andi      $v0, $a0, 0x400
/* DC084 80145984 10400006 */  beqz      $v0, .L801459A0
/* DC088 80145988 30820200 */   andi     $v0, $a0, 0x200
/* DC08C 8014598C 86430012 */  lh        $v1, 0x12($s2)
/* DC090 80145990 8E220008 */  lw        $v0, 8($s1)
/* DC094 80145994 54430073 */  bnel      $v0, $v1, .L80145B64
/* DC098 80145998 26730001 */   addiu    $s3, $s3, 1
/* DC09C 8014599C 30820200 */  andi      $v0, $a0, 0x200
.L801459A0:
/* DC0A0 801459A0 10400006 */  beqz      $v0, .L801459BC
/* DC0A4 801459A4 30820800 */   andi     $v0, $a0, 0x800
/* DC0A8 801459A8 86430004 */  lh        $v1, 4($s2)
/* DC0AC 801459AC 8E220008 */  lw        $v0, 8($s1)
/* DC0B0 801459B0 5443006C */  bnel      $v0, $v1, .L80145B64
/* DC0B4 801459B4 26730001 */   addiu    $s3, $s3, 1
/* DC0B8 801459B8 30820800 */  andi      $v0, $a0, 0x800
.L801459BC:
/* DC0BC 801459BC 10400011 */  beqz      $v0, .L80145A04
/* DC0C0 801459C0 30821000 */   andi     $v0, $a0, 0x1000
/* DC0C4 801459C4 86430002 */  lh        $v1, 2($s2)
/* DC0C8 801459C8 8E220008 */  lw        $v0, 8($s1)
/* DC0CC 801459CC 54430065 */  bnel      $v0, $v1, .L80145B64
/* DC0D0 801459D0 26730001 */   addiu    $s3, $s3, 1
/* DC0D4 801459D4 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* DC0D8 801459D8 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* DC0DC 801459DC 8C420010 */  lw        $v0, 0x10($v0)
/* DC0E0 801459E0 30428000 */  andi      $v0, $v0, 0x8000
/* DC0E4 801459E4 5040005F */  beql      $v0, $zero, .L80145B64
/* DC0E8 801459E8 26730001 */   addiu    $s3, $s3, 1
/* DC0EC 801459EC 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* DC0F0 801459F0 8C42EFC8 */  lw        $v0, %lo(gPlayerStatus)($v0)
/* DC0F4 801459F4 30422000 */  andi      $v0, $v0, 0x2000
/* DC0F8 801459F8 5440005A */  bnel      $v0, $zero, .L80145B64
/* DC0FC 801459FC 26730001 */   addiu    $s3, $s3, 1
/* DC100 80145A00 30821000 */  andi      $v0, $a0, 0x1000
.L80145A04:
/* DC104 80145A04 10400006 */  beqz      $v0, .L80145A20
/* DC108 80145A08 3C020004 */   lui      $v0, 4
/* DC10C 80145A0C 86430014 */  lh        $v1, 0x14($s2)
/* DC110 80145A10 8E220008 */  lw        $v0, 8($s1)
/* DC114 80145A14 54430053 */  bnel      $v0, $v1, .L80145B64
/* DC118 80145A18 26730001 */   addiu    $s3, $s3, 1
/* DC11C 80145A1C 3C020004 */  lui       $v0, 4
.L80145A20:
/* DC120 80145A20 00821024 */  and       $v0, $a0, $v0
/* DC124 80145A24 10400006 */  beqz      $v0, .L80145A40
/* DC128 80145A28 30822000 */   andi     $v0, $a0, 0x2000
/* DC12C 80145A2C 86430008 */  lh        $v1, 8($s2)
/* DC130 80145A30 8E220008 */  lw        $v0, 8($s1)
/* DC134 80145A34 5443004B */  bnel      $v0, $v1, .L80145B64
/* DC138 80145A38 26730001 */   addiu    $s3, $s3, 1
/* DC13C 80145A3C 30822000 */  andi      $v0, $a0, 0x2000
.L80145A40:
/* DC140 80145A40 10400006 */  beqz      $v0, .L80145A5C
/* DC144 80145A44 30824000 */   andi     $v0, $a0, 0x4000
/* DC148 80145A48 8643000C */  lh        $v1, 0xc($s2)
/* DC14C 80145A4C 8E220008 */  lw        $v0, 8($s1)
/* DC150 80145A50 54430044 */  bnel      $v0, $v1, .L80145B64
/* DC154 80145A54 26730001 */   addiu    $s3, $s3, 1
/* DC158 80145A58 30824000 */  andi      $v0, $a0, 0x4000
.L80145A5C:
/* DC15C 80145A5C 10400006 */  beqz      $v0, .L80145A78
/* DC160 80145A60 30828000 */   andi     $v0, $a0, 0x8000
/* DC164 80145A64 8643000E */  lh        $v1, 0xe($s2)
/* DC168 80145A68 8E220008 */  lw        $v0, 8($s1)
/* DC16C 80145A6C 5443003D */  bnel      $v0, $v1, .L80145B64
/* DC170 80145A70 26730001 */   addiu    $s3, $s3, 1
/* DC174 80145A74 30828000 */  andi      $v0, $a0, 0x8000
.L80145A78:
/* DC178 80145A78 10400006 */  beqz      $v0, .L80145A94
/* DC17C 80145A7C 3C020010 */   lui      $v0, 0x10
/* DC180 80145A80 86430010 */  lh        $v1, 0x10($s2)
/* DC184 80145A84 8E220008 */  lw        $v0, 8($s1)
/* DC188 80145A88 54430036 */  bnel      $v0, $v1, .L80145B64
/* DC18C 80145A8C 26730001 */   addiu    $s3, $s3, 1
/* DC190 80145A90 3C020010 */  lui       $v0, 0x10
.L80145A94:
/* DC194 80145A94 00821024 */  and       $v0, $a0, $v0
/* DC198 80145A98 1040001C */  beqz      $v0, .L80145B0C
/* DC19C 80145A9C 00000000 */   nop
/* DC1A0 80145AA0 86420018 */  lh        $v0, 0x18($s2)
/* DC1A4 80145AA4 0442002F */  bltzl     $v0, .L80145B64
/* DC1A8 80145AA8 26730001 */   addiu    $s3, $s3, 1
/* DC1AC 80145AAC C6420020 */  lwc1      $f2, 0x20($s2)
/* DC1B0 80145AB0 8E300008 */  lw        $s0, 8($s1)
/* DC1B4 80145AB4 C6400024 */  lwc1      $f0, 0x24($s2)
/* DC1B8 80145AB8 E7A20010 */  swc1      $f2, 0x10($sp)
/* DC1BC 80145ABC E7A00014 */  swc1      $f0, 0x14($sp)
/* DC1C0 80145AC0 C60C0000 */  lwc1      $f12, ($s0)
/* DC1C4 80145AC4 C60E0004 */  lwc1      $f14, 4($s0)
/* DC1C8 80145AC8 8E060008 */  lw        $a2, 8($s0)
/* DC1CC 80145ACC 0C00A7CB */  jal       dist3D
/* DC1D0 80145AD0 8E47001C */   lw       $a3, 0x1c($s2)
/* DC1D4 80145AD4 C604000C */  lwc1      $f4, 0xc($s0)
/* DC1D8 80145AD8 3C013F00 */  lui       $at, 0x3f00
/* DC1DC 80145ADC 44811000 */  mtc1      $at, $f2
/* DC1E0 80145AE0 00000000 */  nop
/* DC1E4 80145AE4 46022102 */  mul.s     $f4, $f4, $f2
/* DC1E8 80145AE8 00000000 */  nop
/* DC1EC 80145AEC 3C014248 */  lui       $at, 0x4248
/* DC1F0 80145AF0 44811000 */  mtc1      $at, $f2
/* DC1F4 80145AF4 00000000 */  nop
/* DC1F8 80145AF8 46022100 */  add.s     $f4, $f4, $f2
/* DC1FC 80145AFC 4600203C */  c.lt.s    $f4, $f0
/* DC200 80145B00 00000000 */  nop
/* DC204 80145B04 45030017 */  bc1tl     .L80145B64
/* DC208 80145B08 26730001 */   addiu    $s3, $s3, 1
.L80145B0C:
/* DC20C 80145B0C 8E220000 */  lw        $v0, ($s1)
/* DC210 80145B10 3C030001 */  lui       $v1, 1
/* DC214 80145B14 00431024 */  and       $v0, $v0, $v1
/* DC218 80145B18 10400005 */  beqz      $v0, .L80145B30
/* DC21C 80145B1C 00000000 */   nop
/* DC220 80145B20 0C05152F */  jal       get_global_flag
/* DC224 80145B24 8E240004 */   lw       $a0, 4($s1)
/* DC228 80145B28 5040000E */  beql      $v0, $zero, .L80145B64
/* DC22C 80145B2C 26730001 */   addiu    $s3, $s3, 1
.L80145B30:
/* DC230 80145B30 8E220000 */  lw        $v0, ($s1)
/* DC234 80145B34 3C030002 */  lui       $v1, 2
/* DC238 80145B38 00431024 */  and       $v0, $v0, $v1
/* DC23C 80145B3C 10400005 */  beqz      $v0, .L80145B54
/* DC240 80145B40 00000000 */   nop
/* DC244 80145B44 0C05157C */  jal       get_area_flag
/* DC248 80145B48 8E240004 */   lw       $a0, 4($s1)
/* DC24C 80145B4C 50400005 */  beql      $v0, $zero, .L80145B64
/* DC250 80145B50 26730001 */   addiu    $s3, $s3, 1
.L80145B54:
/* DC254 80145B54 8E220000 */  lw        $v0, ($s1)
/* DC258 80145B58 34420002 */  ori       $v0, $v0, 2
.L80145B5C:
/* DC25C 80145B5C AE220000 */  sw        $v0, ($s1)
/* DC260 80145B60 26730001 */  addiu     $s3, $s3, 1
.L80145B64:
/* DC264 80145B64 2A620040 */  slti      $v0, $s3, 0x40
/* DC268 80145B68 1440FF47 */  bnez      $v0, .L80145888
/* DC26C 80145B6C 2410FFFD */   addiu    $s0, $zero, -3
/* DC270 80145B70 0000982D */  daddu     $s3, $zero, $zero
.L80145B74:
/* DC274 80145B74 3C038016 */  lui       $v1, %hi(gCurrentTriggerListPtr)
/* DC278 80145B78 8C639390 */  lw        $v1, %lo(gCurrentTriggerListPtr)($v1)
/* DC27C 80145B7C 00131080 */  sll       $v0, $s3, 2
/* DC280 80145B80 00431021 */  addu      $v0, $v0, $v1
/* DC284 80145B84 8C510000 */  lw        $s1, ($v0)
/* DC288 80145B88 52200010 */  beql      $s1, $zero, .L80145BCC
/* DC28C 80145B8C 26730001 */   addiu    $s3, $s3, 1
/* DC290 80145B90 8E230000 */  lw        $v1, ($s1)
/* DC294 80145B94 30620001 */  andi      $v0, $v1, 1
/* DC298 80145B98 5040000C */  beql      $v0, $zero, .L80145BCC
/* DC29C 80145B9C 26730001 */   addiu    $s3, $s3, 1
/* DC2A0 80145BA0 30620002 */  andi      $v0, $v1, 2
/* DC2A4 80145BA4 50400009 */  beql      $v0, $zero, .L80145BCC
/* DC2A8 80145BA8 26730001 */   addiu    $s3, $s3, 1
/* DC2AC 80145BAC 8E22000C */  lw        $v0, 0xc($s1)
/* DC2B0 80145BB0 0040F809 */  jalr      $v0
/* DC2B4 80145BB4 0220202D */   daddu    $a0, $s1, $zero
/* DC2B8 80145BB8 14400004 */  bnez      $v0, .L80145BCC
/* DC2BC 80145BBC 26730001 */   addiu    $s3, $s3, 1
/* DC2C0 80145BC0 8E220000 */  lw        $v0, ($s1)
/* DC2C4 80145BC4 00501024 */  and       $v0, $v0, $s0
/* DC2C8 80145BC8 AE220000 */  sw        $v0, ($s1)
.L80145BCC:
/* DC2CC 80145BCC 2A620040 */  slti      $v0, $s3, 0x40
/* DC2D0 80145BD0 1440FFE8 */  bnez      $v0, .L80145B74
/* DC2D4 80145BD4 00000000 */   nop
/* DC2D8 80145BD8 8FBF0028 */  lw        $ra, 0x28($sp)
/* DC2DC 80145BDC 8FB30024 */  lw        $s3, 0x24($sp)
/* DC2E0 80145BE0 8FB20020 */  lw        $s2, 0x20($sp)
/* DC2E4 80145BE4 8FB1001C */  lw        $s1, 0x1c($sp)
/* DC2E8 80145BE8 8FB00018 */  lw        $s0, 0x18($sp)
/* DC2EC 80145BEC 03E00008 */  jr        $ra
/* DC2F0 80145BF0 27BD0030 */   addiu    $sp, $sp, 0x30
