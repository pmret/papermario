.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_80243F90_E12730
.double 0.65

dlabel D_80243F98_E12738
.double 0.55

.section .text

glabel func_802411E0_E0F980
/* E0F980 802411E0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* E0F984 802411E4 AFB1002C */  sw        $s1, 0x2c($sp)
/* E0F988 802411E8 0080882D */  daddu     $s1, $a0, $zero
/* E0F98C 802411EC AFB20030 */  sw        $s2, 0x30($sp)
/* E0F990 802411F0 00A0902D */  daddu     $s2, $a1, $zero
/* E0F994 802411F4 AFBF0034 */  sw        $ra, 0x34($sp)
/* E0F998 802411F8 1A4000CB */  blez      $s2, .L80241528
/* E0F99C 802411FC AFB00028 */   sw       $s0, 0x28($sp)
/* E0F9A0 80241200 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* E0F9A4 80241204 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* E0F9A8 80241208 3C02DE00 */  lui       $v0, 0xde00
/* E0F9AC 8024120C 44920000 */  mtc1      $s2, $f0
/* E0F9B0 80241210 00000000 */  nop
/* E0F9B4 80241214 46800021 */  cvt.d.w   $f0, $f0
/* E0F9B8 80241218 8C830000 */  lw        $v1, ($a0)
/* E0F9BC 8024121C 3C018024 */  lui       $at, %hi(D_80243F90_E12730)
/* E0F9C0 80241220 D4223F90 */  ldc1      $f2, %lo(D_80243F90_E12730)($at)
/* E0F9C4 80241224 0060282D */  daddu     $a1, $v1, $zero
/* E0F9C8 80241228 24630008 */  addiu     $v1, $v1, 8
/* E0F9CC 8024122C AC830000 */  sw        $v1, ($a0)
/* E0F9D0 80241230 ACA20000 */  sw        $v0, ($a1)
/* E0F9D4 80241234 3C028024 */  lui       $v0, %hi(D_80243C50_E123F0)
/* E0F9D8 80241238 24423C50 */  addiu     $v0, $v0, %lo(D_80243C50_E123F0)
/* E0F9DC 8024123C ACA20004 */  sw        $v0, 4($a1)
/* E0F9E0 80241240 24620008 */  addiu     $v0, $v1, 8
/* E0F9E4 80241244 AC820000 */  sw        $v0, ($a0)
/* E0F9E8 80241248 3C02E700 */  lui       $v0, 0xe700
/* E0F9EC 8024124C 46220002 */  mul.d     $f0, $f0, $f2
/* E0F9F0 80241250 00000000 */  nop
/* E0F9F4 80241254 AC620000 */  sw        $v0, ($v1)
/* E0F9F8 80241258 24620010 */  addiu     $v0, $v1, 0x10
/* E0F9FC 8024125C AC600004 */  sw        $zero, 4($v1)
/* E0FA00 80241260 AC820000 */  sw        $v0, ($a0)
/* E0FA04 80241264 3C02FA00 */  lui       $v0, 0xfa00
/* E0FA08 80241268 3C0141E0 */  lui       $at, 0x41e0
/* E0FA0C 8024126C 44811800 */  mtc1      $at, $f3
/* E0FA10 80241270 44801000 */  mtc1      $zero, $f2
/* E0FA14 80241274 246D000C */  addiu     $t5, $v1, 0xc
/* E0FA18 80241278 4620103E */  c.le.d    $f2, $f0
/* E0FA1C 8024127C 00000000 */  nop
/* E0FA20 80241280 45010005 */  bc1t      .L80241298
/* E0FA24 80241284 AC620008 */   sw       $v0, 8($v1)
/* E0FA28 80241288 4620010D */  trunc.w.d $f4, $f0
/* E0FA2C 8024128C 440C2000 */  mfc1      $t4, $f4
/* E0FA30 80241290 080904AD */  j         .L802412B4
/* E0FA34 80241294 3C091078 */   lui      $t1, 0x1078
.L80241298:
/* E0FA38 80241298 46220001 */  sub.d     $f0, $f0, $f2
/* E0FA3C 8024129C 3C028000 */  lui       $v0, 0x8000
/* E0FA40 802412A0 4620010D */  trunc.w.d $f4, $f0
/* E0FA44 802412A4 440C2000 */  mfc1      $t4, $f4
/* E0FA48 802412A8 00000000 */  nop
/* E0FA4C 802412AC 01826025 */  or        $t4, $t4, $v0
/* E0FA50 802412B0 3C091078 */  lui       $t1, 0x1078
.L802412B4:
/* E0FA54 802412B4 35291800 */  ori       $t1, $t1, 0x1800
/* E0FA58 802412B8 3C0BF644 */  lui       $t3, 0xf644
/* E0FA5C 802412BC 356B0204 */  ori       $t3, $t3, 0x204
/* E0FA60 802412C0 3C0A000C */  lui       $t2, 0xc
/* E0FA64 802412C4 354A00D4 */  ori       $t2, $t2, 0xd4
/* E0FA68 802412C8 2404002D */  addiu     $a0, $zero, 0x2d
/* E0FA6C 802412CC 24050032 */  addiu     $a1, $zero, 0x32
/* E0FA70 802412D0 240600E6 */  addiu     $a2, $zero, 0xe6
/* E0FA74 802412D4 3C08800A */  lui       $t0, %hi(gMasterGfxPos)
/* E0FA78 802412D8 2508A66C */  addiu     $t0, $t0, %lo(gMasterGfxPos)
/* E0FA7C 802412DC 318200FF */  andi      $v0, $t4, 0xff
/* E0FA80 802412E0 00491025 */  or        $v0, $v0, $t1
/* E0FA84 802412E4 44921000 */  mtc1      $s2, $f2
/* E0FA88 802412E8 00000000 */  nop
/* E0FA8C 802412EC 468010A1 */  cvt.d.w   $f2, $f2
/* E0FA90 802412F0 8D030000 */  lw        $v1, ($t0)
/* E0FA94 802412F4 3C018024 */  lui       $at, %hi(D_80243F98_E12738)
/* E0FA98 802412F8 D4203F98 */  ldc1      $f0, %lo(D_80243F98_E12738)($at)
/* E0FA9C 802412FC 24100001 */  addiu     $s0, $zero, 1
/* E0FAA0 80241300 ADA20000 */  sw        $v0, ($t5)
/* E0FAA4 80241304 0060102D */  daddu     $v0, $v1, $zero
/* E0FAA8 80241308 24630008 */  addiu     $v1, $v1, 8
/* E0FAAC 8024130C AD030000 */  sw        $v1, ($t0)
/* E0FAB0 80241310 AC4B0000 */  sw        $t3, ($v0)
/* E0FAB4 80241314 AC4A0004 */  sw        $t2, 4($v0)
/* E0FAB8 80241318 24620008 */  addiu     $v0, $v1, 8
/* E0FABC 8024131C AD020000 */  sw        $v0, ($t0)
/* E0FAC0 80241320 3C02E700 */  lui       $v0, 0xe700
/* E0FAC4 80241324 46201082 */  mul.d     $f2, $f2, $f0
/* E0FAC8 80241328 00000000 */  nop
/* E0FACC 8024132C AC620000 */  sw        $v0, ($v1)
/* E0FAD0 80241330 24020006 */  addiu     $v0, $zero, 6
/* E0FAD4 80241334 AC600004 */  sw        $zero, 4($v1)
/* E0FAD8 80241338 AFA20010 */  sw        $v0, 0x10($sp)
/* E0FADC 8024133C AFA00014 */  sw        $zero, 0x14($sp)
/* E0FAE0 80241340 AFB00018 */  sw        $s0, 0x18($sp)
/* E0FAE4 80241344 AFB20020 */  sw        $s2, 0x20($sp)
/* E0FAE8 80241348 4620110D */  trunc.w.d $f4, $f2
/* E0FAEC 8024134C E7A4001C */  swc1      $f4, 0x1c($sp)
/* E0FAF0 80241350 0C04B6D6 */  jal       msg_draw_frame
/* E0FAF4 80241354 24070052 */   addiu    $a3, $zero, 0x52
/* E0FAF8 80241358 8E220008 */  lw        $v0, 8($s1)
/* E0FAFC 8024135C 1450001F */  bne       $v0, $s0, .L802413DC
/* E0FB00 80241360 3C040008 */   lui      $a0, 8
/* E0FB04 80241364 3484001C */  ori       $a0, $a0, 0x1c
/* E0FB08 80241368 24050042 */  addiu     $a1, $zero, 0x42
/* E0FB0C 8024136C 24060039 */  addiu     $a2, $zero, 0x39
/* E0FB10 80241370 0240382D */  daddu     $a3, $s2, $zero
/* E0FB14 80241374 AFB00010 */  sw        $s0, 0x10($sp)
/* E0FB18 80241378 0C04993B */  jal       draw_msg
/* E0FB1C 8024137C AFA00014 */   sw       $zero, 0x14($sp)
/* E0FB20 80241380 240500DB */  addiu     $a1, $zero, 0xdb
/* E0FB24 80241384 2406004E */  addiu     $a2, $zero, 0x4e
/* E0FB28 80241388 0200382D */  daddu     $a3, $s0, $zero
/* E0FB2C 8024138C 3C108011 */  lui       $s0, %hi(gPlayerData)
/* E0FB30 80241390 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* E0FB34 80241394 AFA00010 */  sw        $zero, 0x10($sp)
/* E0FB38 80241398 AFB20014 */  sw        $s2, 0x14($sp)
/* E0FB3C 8024139C 9604032E */  lhu       $a0, 0x32e($s0)
/* E0FB40 802413A0 24110003 */  addiu     $s1, $zero, 3
/* E0FB44 802413A4 0C049DA7 */  jal       draw_number
/* E0FB48 802413A8 AFB10018 */   sw       $s1, 0x18($sp)
/* E0FB4C 802413AC 240500DB */  addiu     $a1, $zero, 0xdb
/* E0FB50 802413B0 2406005D */  addiu     $a2, $zero, 0x5d
/* E0FB54 802413B4 8E040330 */  lw        $a0, 0x330($s0)
/* E0FB58 802413B8 24070001 */  addiu     $a3, $zero, 1
/* E0FB5C 802413BC AFA00010 */  sw        $zero, 0x10($sp)
/* E0FB60 802413C0 AFB20014 */  sw        $s2, 0x14($sp)
/* E0FB64 802413C4 0C049DA7 */  jal       draw_number
/* E0FB68 802413C8 AFB10018 */   sw       $s1, 0x18($sp)
/* E0FB6C 802413CC 240500DB */  addiu     $a1, $zero, 0xdb
/* E0FB70 802413D0 96040334 */  lhu       $a0, 0x334($s0)
/* E0FB74 802413D4 08090514 */  j         .L80241450
/* E0FB78 802413D8 2406006C */   addiu    $a2, $zero, 0x6c
.L802413DC:
/* E0FB7C 802413DC 3484001D */  ori       $a0, $a0, 0x1d
/* E0FB80 802413E0 24050040 */  addiu     $a1, $zero, 0x40
/* E0FB84 802413E4 24060039 */  addiu     $a2, $zero, 0x39
/* E0FB88 802413E8 0240382D */  daddu     $a3, $s2, $zero
/* E0FB8C 802413EC AFB00010 */  sw        $s0, 0x10($sp)
/* E0FB90 802413F0 0C04993B */  jal       draw_msg
/* E0FB94 802413F4 AFA00014 */   sw       $zero, 0x14($sp)
/* E0FB98 802413F8 240500DB */  addiu     $a1, $zero, 0xdb
/* E0FB9C 802413FC 2406004E */  addiu     $a2, $zero, 0x4e
/* E0FBA0 80241400 24070001 */  addiu     $a3, $zero, 1
/* E0FBA4 80241404 3C108011 */  lui       $s0, %hi(gPlayerData)
/* E0FBA8 80241408 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* E0FBAC 8024140C AFA00010 */  sw        $zero, 0x10($sp)
/* E0FBB0 80241410 AFB20014 */  sw        $s2, 0x14($sp)
/* E0FBB4 80241414 96040336 */  lhu       $a0, 0x336($s0)
/* E0FBB8 80241418 24110003 */  addiu     $s1, $zero, 3
/* E0FBBC 8024141C 0C049DA7 */  jal       draw_number
/* E0FBC0 80241420 AFB10018 */   sw       $s1, 0x18($sp)
/* E0FBC4 80241424 240500DB */  addiu     $a1, $zero, 0xdb
/* E0FBC8 80241428 2406005D */  addiu     $a2, $zero, 0x5d
/* E0FBCC 8024142C 8E040338 */  lw        $a0, 0x338($s0)
/* E0FBD0 80241430 24070001 */  addiu     $a3, $zero, 1
/* E0FBD4 80241434 AFA00010 */  sw        $zero, 0x10($sp)
/* E0FBD8 80241438 AFB20014 */  sw        $s2, 0x14($sp)
/* E0FBDC 8024143C 0C049DA7 */  jal       draw_number
/* E0FBE0 80241440 AFB10018 */   sw       $s1, 0x18($sp)
/* E0FBE4 80241444 240500DB */  addiu     $a1, $zero, 0xdb
/* E0FBE8 80241448 2406006C */  addiu     $a2, $zero, 0x6c
/* E0FBEC 8024144C 9604033C */  lhu       $a0, 0x33c($s0)
.L80241450:
/* E0FBF0 80241450 24070001 */  addiu     $a3, $zero, 1
/* E0FBF4 80241454 AFA00010 */  sw        $zero, 0x10($sp)
/* E0FBF8 80241458 AFB20014 */  sw        $s2, 0x14($sp)
/* E0FBFC 8024145C 0C049DA7 */  jal       draw_number
/* E0FC00 80241460 AFB10018 */   sw       $s1, 0x18($sp)
/* E0FC04 80241464 3C040008 */  lui       $a0, 8
/* E0FC08 80241468 3484001E */  ori       $a0, $a0, 0x1e
/* E0FC0C 8024146C 2405003A */  addiu     $a1, $zero, 0x3a
/* E0FC10 80241470 2406004E */  addiu     $a2, $zero, 0x4e
/* E0FC14 80241474 0240382D */  daddu     $a3, $s2, $zero
/* E0FC18 80241478 24100001 */  addiu     $s0, $zero, 1
/* E0FC1C 8024147C AFA00010 */  sw        $zero, 0x10($sp)
/* E0FC20 80241480 0C04993B */  jal       draw_msg
/* E0FC24 80241484 AFB00014 */   sw       $s0, 0x14($sp)
/* E0FC28 80241488 3C040008 */  lui       $a0, 8
/* E0FC2C 8024148C 34840023 */  ori       $a0, $a0, 0x23
/* E0FC30 80241490 240500DF */  addiu     $a1, $zero, 0xdf
/* E0FC34 80241494 2406004E */  addiu     $a2, $zero, 0x4e
/* E0FC38 80241498 0240382D */  daddu     $a3, $s2, $zero
/* E0FC3C 8024149C AFA00010 */  sw        $zero, 0x10($sp)
/* E0FC40 802414A0 0C04993B */  jal       draw_msg
/* E0FC44 802414A4 AFB00014 */   sw       $s0, 0x14($sp)
/* E0FC48 802414A8 3C040008 */  lui       $a0, 8
/* E0FC4C 802414AC 3484001F */  ori       $a0, $a0, 0x1f
/* E0FC50 802414B0 2405003A */  addiu     $a1, $zero, 0x3a
/* E0FC54 802414B4 2406005D */  addiu     $a2, $zero, 0x5d
/* E0FC58 802414B8 0240382D */  daddu     $a3, $s2, $zero
/* E0FC5C 802414BC AFA00010 */  sw        $zero, 0x10($sp)
/* E0FC60 802414C0 0C04993B */  jal       draw_msg
/* E0FC64 802414C4 AFB00014 */   sw       $s0, 0x14($sp)
/* E0FC68 802414C8 3C040008 */  lui       $a0, 8
/* E0FC6C 802414CC 34840021 */  ori       $a0, $a0, 0x21
/* E0FC70 802414D0 240500DF */  addiu     $a1, $zero, 0xdf
/* E0FC74 802414D4 2406005D */  addiu     $a2, $zero, 0x5d
/* E0FC78 802414D8 0240382D */  daddu     $a3, $s2, $zero
/* E0FC7C 802414DC AFA00010 */  sw        $zero, 0x10($sp)
/* E0FC80 802414E0 0C04993B */  jal       draw_msg
/* E0FC84 802414E4 AFB00014 */   sw       $s0, 0x14($sp)
/* E0FC88 802414E8 3C040008 */  lui       $a0, 8
/* E0FC8C 802414EC 34840020 */  ori       $a0, $a0, 0x20
/* E0FC90 802414F0 2405003A */  addiu     $a1, $zero, 0x3a
/* E0FC94 802414F4 2406006C */  addiu     $a2, $zero, 0x6c
/* E0FC98 802414F8 0240382D */  daddu     $a3, $s2, $zero
/* E0FC9C 802414FC AFA00010 */  sw        $zero, 0x10($sp)
/* E0FCA0 80241500 0C04993B */  jal       draw_msg
/* E0FCA4 80241504 AFB00014 */   sw       $s0, 0x14($sp)
/* E0FCA8 80241508 3C040008 */  lui       $a0, 8
/* E0FCAC 8024150C 34840021 */  ori       $a0, $a0, 0x21
/* E0FCB0 80241510 240500DF */  addiu     $a1, $zero, 0xdf
/* E0FCB4 80241514 2406006C */  addiu     $a2, $zero, 0x6c
/* E0FCB8 80241518 0240382D */  daddu     $a3, $s2, $zero
/* E0FCBC 8024151C AFA00010 */  sw        $zero, 0x10($sp)
/* E0FCC0 80241520 0C04993B */  jal       draw_msg
/* E0FCC4 80241524 AFB00014 */   sw       $s0, 0x14($sp)
.L80241528:
/* E0FCC8 80241528 8FBF0034 */  lw        $ra, 0x34($sp)
/* E0FCCC 8024152C 8FB20030 */  lw        $s2, 0x30($sp)
/* E0FCD0 80241530 8FB1002C */  lw        $s1, 0x2c($sp)
/* E0FCD4 80241534 8FB00028 */  lw        $s0, 0x28($sp)
/* E0FCD8 80241538 03E00008 */  jr        $ra
/* E0FCDC 8024153C 27BD0038 */   addiu    $sp, $sp, 0x38
