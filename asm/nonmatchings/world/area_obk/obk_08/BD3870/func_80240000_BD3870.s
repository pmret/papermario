.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_BD3870
/* BD3870 80240000 27BDFF10 */  addiu     $sp, $sp, -0xf0
/* BD3874 80240004 0000202D */  daddu     $a0, $zero, $zero
/* BD3878 80240008 3C05FD05 */  lui       $a1, 0xfd05
/* BD387C 8024000C AFBF00DC */  sw        $ra, 0xdc($sp)
/* BD3880 80240010 AFB600D8 */  sw        $s6, 0xd8($sp)
/* BD3884 80240014 AFB500D4 */  sw        $s5, 0xd4($sp)
/* BD3888 80240018 AFB400D0 */  sw        $s4, 0xd0($sp)
/* BD388C 8024001C AFB300CC */  sw        $s3, 0xcc($sp)
/* BD3890 80240020 AFB200C8 */  sw        $s2, 0xc8($sp)
/* BD3894 80240024 AFB100C4 */  sw        $s1, 0xc4($sp)
/* BD3898 80240028 AFB000C0 */  sw        $s0, 0xc0($sp)
/* BD389C 8024002C F7B600E8 */  sdc1      $f22, 0xe8($sp)
/* BD38A0 80240030 F7B400E0 */  sdc1      $f20, 0xe0($sp)
/* BD38A4 80240034 0C0B1EAF */  jal       get_variable
/* BD38A8 80240038 34A50F8A */   ori      $a1, $a1, 0xf8a
/* BD38AC 8024003C 3C07E300 */  lui       $a3, 0xe300
/* BD38B0 80240040 34E70A01 */  ori       $a3, $a3, 0xa01
/* BD38B4 80240044 3C08D9C0 */  lui       $t0, 0xd9c0
/* BD38B8 80240048 3508F9FB */  ori       $t0, $t0, 0xf9fb
/* BD38BC 8024004C 3C0AD9FF */  lui       $t2, 0xd9ff
/* BD38C0 80240050 354AFFFF */  ori       $t2, $t2, 0xffff
/* BD38C4 80240054 3C090020 */  lui       $t1, 0x20
/* BD38C8 80240058 35290005 */  ori       $t1, $t1, 5
/* BD38CC 8024005C 3C0BD700 */  lui       $t3, 0xd700
/* BD38D0 80240060 356B0002 */  ori       $t3, $t3, 2
/* BD38D4 80240064 3C0CE300 */  lui       $t4, 0xe300
/* BD38D8 80240068 358C0F00 */  ori       $t4, $t4, 0xf00
/* BD38DC 8024006C 3C0DE300 */  lui       $t5, 0xe300
/* BD38E0 80240070 35AD0C00 */  ori       $t5, $t5, 0xc00
/* BD38E4 80240074 3C0EE300 */  lui       $t6, 0xe300
/* BD38E8 80240078 35CE1201 */  ori       $t6, $t6, 0x1201
/* BD38EC 8024007C 3C0FE300 */  lui       $t7, 0xe300
/* BD38F0 80240080 35EF1801 */  ori       $t7, $t7, 0x1801
/* BD38F4 80240084 3C10E300 */  lui       $s0, 0xe300
/* BD38F8 80240088 36100D01 */  ori       $s0, $s0, 0xd01
/* BD38FC 8024008C 3C12E300 */  lui       $s2, 0xe300
/* BD3900 80240090 36521402 */  ori       $s2, $s2, 0x1402
/* BD3904 80240094 3C14E300 */  lui       $s4, 0xe300
/* BD3908 80240098 36941700 */  ori       $s4, $s4, 0x1700
/* BD390C 8024009C 3C15E200 */  lui       $s5, 0xe200
/* BD3910 802400A0 36B51E01 */  ori       $s5, $s5, 0x1e01
/* BD3914 802400A4 27B30040 */  addiu     $s3, $sp, 0x40
/* BD3918 802400A8 0260202D */  daddu     $a0, $s3, $zero
/* BD391C 802400AC 3C160001 */  lui       $s6, 1
/* BD3920 802400B0 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* BD3924 802400B4 2631A66C */  addiu     $s1, $s1, %lo(gMasterGfxPos)
/* BD3928 802400B8 36D61630 */  ori       $s6, $s6, 0x1630
/* BD392C 802400BC 3C05E700 */  lui       $a1, 0xe700
/* BD3930 802400C0 8E230000 */  lw        $v1, ($s1)
/* BD3934 802400C4 4480A000 */  mtc1      $zero, $f20
/* BD3938 802400C8 0060302D */  daddu     $a2, $v1, $zero
/* BD393C 802400CC 24630008 */  addiu     $v1, $v1, 8
/* BD3940 802400D0 AE230000 */  sw        $v1, ($s1)
/* BD3944 802400D4 ACC50000 */  sw        $a1, ($a2)
/* BD3948 802400D8 24650008 */  addiu     $a1, $v1, 8
/* BD394C 802400DC ACC00004 */  sw        $zero, 4($a2)
/* BD3950 802400E0 AE250000 */  sw        $a1, ($s1)
/* BD3954 802400E4 24650010 */  addiu     $a1, $v1, 0x10
/* BD3958 802400E8 AC670000 */  sw        $a3, ($v1)
/* BD395C 802400EC AC600004 */  sw        $zero, 4($v1)
/* BD3960 802400F0 AE250000 */  sw        $a1, ($s1)
/* BD3964 802400F4 24650018 */  addiu     $a1, $v1, 0x18
/* BD3968 802400F8 AC680008 */  sw        $t0, 8($v1)
/* BD396C 802400FC AC60000C */  sw        $zero, 0xc($v1)
/* BD3970 80240100 AE250000 */  sw        $a1, ($s1)
/* BD3974 80240104 24650020 */  addiu     $a1, $v1, 0x20
/* BD3978 80240108 AC6A0010 */  sw        $t2, 0x10($v1)
/* BD397C 8024010C AC690014 */  sw        $t1, 0x14($v1)
/* BD3980 80240110 AE250000 */  sw        $a1, ($s1)
/* BD3984 80240114 2405FFFF */  addiu     $a1, $zero, -1
/* BD3988 80240118 AC65001C */  sw        $a1, 0x1c($v1)
/* BD398C 8024011C 24650028 */  addiu     $a1, $v1, 0x28
/* BD3990 80240120 AC6B0018 */  sw        $t3, 0x18($v1)
/* BD3994 80240124 AE250000 */  sw        $a1, ($s1)
/* BD3998 80240128 24650030 */  addiu     $a1, $v1, 0x30
/* BD399C 8024012C AC6C0020 */  sw        $t4, 0x20($v1)
/* BD39A0 80240130 AC600024 */  sw        $zero, 0x24($v1)
/* BD39A4 80240134 AE250000 */  sw        $a1, ($s1)
/* BD39A8 80240138 3C050008 */  lui       $a1, 8
/* BD39AC 8024013C AC65002C */  sw        $a1, 0x2c($v1)
/* BD39B0 80240140 24650038 */  addiu     $a1, $v1, 0x38
/* BD39B4 80240144 AC6D0028 */  sw        $t5, 0x28($v1)
/* BD39B8 80240148 AE250000 */  sw        $a1, ($s1)
/* BD39BC 8024014C 24052000 */  addiu     $a1, $zero, 0x2000
/* BD39C0 80240150 AC650034 */  sw        $a1, 0x34($v1)
/* BD39C4 80240154 24650040 */  addiu     $a1, $v1, 0x40
/* BD39C8 80240158 AC6E0030 */  sw        $t6, 0x30($v1)
/* BD39CC 8024015C AE250000 */  sw        $a1, ($s1)
/* BD39D0 80240160 240500C0 */  addiu     $a1, $zero, 0xc0
/* BD39D4 80240164 AC65003C */  sw        $a1, 0x3c($v1)
/* BD39D8 80240168 24650048 */  addiu     $a1, $v1, 0x48
/* BD39DC 8024016C AC6F0038 */  sw        $t7, 0x38($v1)
/* BD39E0 80240170 AE250000 */  sw        $a1, ($s1)
/* BD39E4 80240174 24650050 */  addiu     $a1, $v1, 0x50
/* BD39E8 80240178 AC700040 */  sw        $s0, 0x40($v1)
/* BD39EC 8024017C AC600044 */  sw        $zero, 0x44($v1)
/* BD39F0 80240180 AE250000 */  sw        $a1, ($s1)
/* BD39F4 80240184 24050C00 */  addiu     $a1, $zero, 0xc00
/* BD39F8 80240188 AC720048 */  sw        $s2, 0x48($v1)
/* BD39FC 8024018C 0040902D */  daddu     $s2, $v0, $zero
/* BD3A00 80240190 24620058 */  addiu     $v0, $v1, 0x58
/* BD3A04 80240194 AC65004C */  sw        $a1, 0x4c($v1)
/* BD3A08 80240198 AC740050 */  sw        $s4, 0x50($v1)
/* BD3A0C 8024019C AC600054 */  sw        $zero, 0x54($v1)
/* BD3A10 802401A0 AC750058 */  sw        $s5, 0x58($v1)
/* BD3A14 802401A4 AC60005C */  sw        $zero, 0x5c($v1)
/* BD3A18 802401A8 8E450010 */  lw        $a1, 0x10($s2)
/* BD3A1C 802401AC 8E460014 */  lw        $a2, 0x14($s2)
/* BD3A20 802401B0 8E470018 */  lw        $a3, 0x18($s2)
/* BD3A24 802401B4 24630060 */  addiu     $v1, $v1, 0x60
/* BD3A28 802401B8 AE220000 */  sw        $v0, ($s1)
/* BD3A2C 802401BC 0C019E40 */  jal       guTranslateF
/* BD3A30 802401C0 AE230000 */   sw       $v1, ($s1)
/* BD3A34 802401C4 27B00080 */  addiu     $s0, $sp, 0x80
/* BD3A38 802401C8 E7B40010 */  swc1      $f20, 0x10($sp)
/* BD3A3C 802401CC 8E450020 */  lw        $a1, 0x20($s2)
/* BD3A40 802401D0 3C013F80 */  lui       $at, 0x3f80
/* BD3A44 802401D4 4481B000 */  mtc1      $at, $f22
/* BD3A48 802401D8 4406A000 */  mfc1      $a2, $f20
/* BD3A4C 802401DC 4407B000 */  mfc1      $a3, $f22
/* BD3A50 802401E0 0C019EC8 */  jal       guRotateF
/* BD3A54 802401E4 0200202D */   daddu    $a0, $s0, $zero
/* BD3A58 802401E8 0200202D */  daddu     $a0, $s0, $zero
/* BD3A5C 802401EC 0260282D */  daddu     $a1, $s3, $zero
/* BD3A60 802401F0 0C019D80 */  jal       guMtxCatF
/* BD3A64 802401F4 0260302D */   daddu    $a2, $s3, $zero
/* BD3A68 802401F8 E7B60010 */  swc1      $f22, 0x10($sp)
/* BD3A6C 802401FC 8E450024 */  lw        $a1, 0x24($s2)
/* BD3A70 80240200 4406A000 */  mfc1      $a2, $f20
/* BD3A74 80240204 4407A000 */  mfc1      $a3, $f20
/* BD3A78 80240208 0C019EC8 */  jal       guRotateF
/* BD3A7C 8024020C 0200202D */   daddu    $a0, $s0, $zero
/* BD3A80 80240210 0200202D */  daddu     $a0, $s0, $zero
/* BD3A84 80240214 0260282D */  daddu     $a1, $s3, $zero
/* BD3A88 80240218 0C019D80 */  jal       guMtxCatF
/* BD3A8C 8024021C 0260302D */   daddu    $a2, $s3, $zero
/* BD3A90 80240220 E7B40010 */  swc1      $f20, 0x10($sp)
/* BD3A94 80240224 8E45001C */  lw        $a1, 0x1c($s2)
/* BD3A98 80240228 4406B000 */  mfc1      $a2, $f22
/* BD3A9C 8024022C 4407A000 */  mfc1      $a3, $f20
/* BD3AA0 80240230 0C019EC8 */  jal       guRotateF
/* BD3AA4 80240234 0200202D */   daddu    $a0, $s0, $zero
/* BD3AA8 80240238 0200202D */  daddu     $a0, $s0, $zero
/* BD3AAC 8024023C 0260282D */  daddu     $a1, $s3, $zero
/* BD3AB0 80240240 0C019D80 */  jal       guMtxCatF
/* BD3AB4 80240244 0260302D */   daddu    $a2, $s3, $zero
/* BD3AB8 80240248 8E450028 */  lw        $a1, 0x28($s2)
/* BD3ABC 8024024C 8E46002C */  lw        $a2, 0x2c($s2)
/* BD3AC0 80240250 8E470030 */  lw        $a3, 0x30($s2)
/* BD3AC4 80240254 0C019DF0 */  jal       guScaleF
/* BD3AC8 80240258 0200202D */   daddu    $a0, $s0, $zero
/* BD3ACC 8024025C 0200202D */  daddu     $a0, $s0, $zero
/* BD3AD0 80240260 0260282D */  daddu     $a1, $s3, $zero
/* BD3AD4 80240264 0C019D80 */  jal       guMtxCatF
/* BD3AD8 80240268 0260302D */   daddu    $a2, $s3, $zero
/* BD3ADC 8024026C 0260202D */  daddu     $a0, $s3, $zero
/* BD3AE0 80240270 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* BD3AE4 80240274 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* BD3AE8 80240278 3C14800A */  lui       $s4, %hi(gDisplayContext)
/* BD3AEC 8024027C 2694A674 */  addiu     $s4, $s4, %lo(gDisplayContext)
/* BD3AF0 80240280 96050000 */  lhu       $a1, ($s0)
/* BD3AF4 80240284 8E820000 */  lw        $v0, ($s4)
/* BD3AF8 80240288 00052980 */  sll       $a1, $a1, 6
/* BD3AFC 8024028C 00B62821 */  addu      $a1, $a1, $s6
/* BD3B00 80240290 0C019D40 */  jal       guMtxF2L
/* BD3B04 80240294 00452821 */   addu     $a1, $v0, $a1
/* BD3B08 80240298 3C02DA38 */  lui       $v0, 0xda38
/* BD3B0C 8024029C 34420002 */  ori       $v0, $v0, 2
/* BD3B10 802402A0 27A40030 */  addiu     $a0, $sp, 0x30
/* BD3B14 802402A4 8E270000 */  lw        $a3, ($s1)
/* BD3B18 802402A8 96080000 */  lhu       $t0, ($s0)
/* BD3B1C 802402AC 00E0282D */  daddu     $a1, $a3, $zero
/* BD3B20 802402B0 ACA20000 */  sw        $v0, ($a1)
/* BD3B24 802402B4 3102FFFF */  andi      $v0, $t0, 0xffff
/* BD3B28 802402B8 00021180 */  sll       $v0, $v0, 6
/* BD3B2C 802402BC 00561021 */  addu      $v0, $v0, $s6
/* BD3B30 802402C0 8E830000 */  lw        $v1, ($s4)
/* BD3B34 802402C4 24E70008 */  addiu     $a3, $a3, 8
/* BD3B38 802402C8 00621821 */  addu      $v1, $v1, $v0
/* BD3B3C 802402CC 3C028000 */  lui       $v0, 0x8000
/* BD3B40 802402D0 00621821 */  addu      $v1, $v1, $v0
/* BD3B44 802402D4 ACA30004 */  sw        $v1, 4($a1)
/* BD3B48 802402D8 8E450008 */  lw        $a1, 8($s2)
/* BD3B4C 802402DC 8E46000C */  lw        $a2, 0xc($s2)
/* BD3B50 802402E0 25080001 */  addiu     $t0, $t0, 1
/* BD3B54 802402E4 AE270000 */  sw        $a3, ($s1)
/* BD3B58 802402E8 0C0B7811 */  jal       func_802DE044
/* BD3B5C 802402EC A6080000 */   sh       $t0, ($s0)
/* BD3B60 802402F0 8FA30030 */  lw        $v1, 0x30($sp)
/* BD3B64 802402F4 8FA40034 */  lw        $a0, 0x34($sp)
/* BD3B68 802402F8 97A2003A */  lhu       $v0, 0x3a($sp)
/* BD3B6C 802402FC 3C013F00 */  lui       $at, 0x3f00
/* BD3B70 80240300 44811000 */  mtc1      $at, $f2
/* BD3B74 80240304 27A50018 */  addiu     $a1, $sp, 0x18
/* BD3B78 80240308 A7A20020 */  sh        $v0, 0x20($sp)
/* BD3B7C 8024030C 3042FFFF */  andi      $v0, $v0, 0xffff
/* BD3B80 80240310 44820000 */  mtc1      $v0, $f0
/* BD3B84 80240314 00000000 */  nop
/* BD3B88 80240318 46800020 */  cvt.s.w   $f0, $f0
/* BD3B8C 8024031C AFA30018 */  sw        $v1, 0x18($sp)
/* BD3B90 80240320 AFA4001C */  sw        $a0, 0x1c($sp)
/* BD3B94 80240324 E6400034 */  swc1      $f0, 0x34($s2)
/* BD3B98 80240328 97A2003E */  lhu       $v0, 0x3e($sp)
/* BD3B9C 8024032C 0000302D */  daddu     $a2, $zero, $zero
/* BD3BA0 80240330 A7A20022 */  sh        $v0, 0x22($sp)
/* BD3BA4 80240334 3042FFFF */  andi      $v0, $v0, 0xffff
/* BD3BA8 80240338 44820000 */  mtc1      $v0, $f0
/* BD3BAC 8024033C 00000000 */  nop
/* BD3BB0 80240340 46800020 */  cvt.s.w   $f0, $f0
/* BD3BB4 80240344 E6400038 */  swc1      $f0, 0x38($s2)
/* BD3BB8 80240348 C7A00038 */  lwc1      $f0, 0x38($sp)
/* BD3BBC 8024034C 46800020 */  cvt.s.w   $f0, $f0
/* BD3BC0 80240350 46020002 */  mul.s     $f0, $f0, $f2
/* BD3BC4 80240354 00000000 */  nop
/* BD3BC8 80240358 97A3003E */  lhu       $v1, 0x3e($sp)
/* BD3BCC 8024035C 240200FF */  addiu     $v0, $zero, 0xff
/* BD3BD0 80240360 A3A20028 */  sb        $v0, 0x28($sp)
/* BD3BD4 80240364 A7A30026 */  sh        $v1, 0x26($sp)
/* BD3BD8 80240368 4600010D */  trunc.w.s $f4, $f0
/* BD3BDC 8024036C 44022000 */  mfc1      $v0, $f4
/* BD3BE0 80240370 00000000 */  nop
/* BD3BE4 80240374 00021023 */  negu      $v0, $v0
/* BD3BE8 80240378 A7A20024 */  sh        $v0, 0x24($sp)
/* BD3BEC 8024037C 8E440000 */  lw        $a0, ($s2)
/* BD3BF0 80240380 0C04EBDC */  jal       func_8013AF70
/* BD3BF4 80240384 0260382D */   daddu    $a3, $s3, $zero
/* BD3BF8 80240388 3C04D838 */  lui       $a0, 0xd838
/* BD3BFC 8024038C 8E220000 */  lw        $v0, ($s1)
/* BD3C00 80240390 34840002 */  ori       $a0, $a0, 2
/* BD3C04 80240394 0040182D */  daddu     $v1, $v0, $zero
/* BD3C08 80240398 24420008 */  addiu     $v0, $v0, 8
/* BD3C0C 8024039C AE220000 */  sw        $v0, ($s1)
/* BD3C10 802403A0 24020040 */  addiu     $v0, $zero, 0x40
/* BD3C14 802403A4 AC640000 */  sw        $a0, ($v1)
/* BD3C18 802403A8 AC620004 */  sw        $v0, 4($v1)
/* BD3C1C 802403AC 8FBF00DC */  lw        $ra, 0xdc($sp)
/* BD3C20 802403B0 8FB600D8 */  lw        $s6, 0xd8($sp)
/* BD3C24 802403B4 8FB500D4 */  lw        $s5, 0xd4($sp)
/* BD3C28 802403B8 8FB400D0 */  lw        $s4, 0xd0($sp)
/* BD3C2C 802403BC 8FB300CC */  lw        $s3, 0xcc($sp)
/* BD3C30 802403C0 8FB200C8 */  lw        $s2, 0xc8($sp)
/* BD3C34 802403C4 8FB100C4 */  lw        $s1, 0xc4($sp)
/* BD3C38 802403C8 8FB000C0 */  lw        $s0, 0xc0($sp)
/* BD3C3C 802403CC D7B600E8 */  ldc1      $f22, 0xe8($sp)
/* BD3C40 802403D0 D7B400E0 */  ldc1      $f20, 0xe0($sp)
/* BD3C44 802403D4 03E00008 */  jr        $ra
/* BD3C48 802403D8 27BD00F0 */   addiu    $sp, $sp, 0xf0
