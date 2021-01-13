.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel update_partner_menu
/* 41CF58 802A81C8 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 41CF5C 802A81CC AFB40020 */  sw        $s4, 0x20($sp)
/* 41CF60 802A81D0 3C14800E */  lui       $s4, %hi(gBattleStatus)
/* 41CF64 802A81D4 2694C070 */  addiu     $s4, $s4, %lo(gBattleStatus)
/* 41CF68 802A81D8 AFB7002C */  sw        $s7, 0x2c($sp)
/* 41CF6C 802A81DC 3C178011 */  lui       $s7, %hi(gPlayerData)
/* 41CF70 802A81E0 26F7F290 */  addiu     $s7, $s7, %lo(gPlayerData)
/* 41CF74 802A81E4 AFB20018 */  sw        $s2, 0x18($sp)
/* 41CF78 802A81E8 3C12802B */  lui       $s2, %hi(D_802ACCD0)
/* 41CF7C 802A81EC 2652CCD0 */  addiu     $s2, $s2, %lo(D_802ACCD0)
/* 41CF80 802A81F0 AFB10014 */  sw        $s1, 0x14($sp)
/* 41CF84 802A81F4 3C11800E */  lui       $s1, %hi(gBattleStatus+0x46C)
/* 41CF88 802A81F8 2631C4DC */  addiu     $s1, $s1, %lo(gBattleStatus+0x46C)
/* 41CF8C 802A81FC AFBF0034 */  sw        $ra, 0x34($sp)
/* 41CF90 802A8200 AFBE0030 */  sw        $fp, 0x30($sp)
/* 41CF94 802A8204 AFB60028 */  sw        $s6, 0x28($sp)
/* 41CF98 802A8208 AFB50024 */  sw        $s5, 0x24($sp)
/* 41CF9C 802A820C AFB3001C */  sw        $s3, 0x1c($sp)
/* 41CFA0 802A8210 AFB00010 */  sw        $s0, 0x10($sp)
/* 41CFA4 802A8214 F7B80048 */  sdc1      $f24, 0x48($sp)
/* 41CFA8 802A8218 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 41CFAC 802A821C F7B40038 */  sdc1      $f20, 0x38($sp)
/* 41CFB0 802A8220 8E9300D8 */  lw        $s3, 0xd8($s4)
/* 41CFB4 802A8224 8E220000 */  lw        $v0, ($s1)
/* 41CFB8 802A8228 8E9000DC */  lw        $s0, 0xdc($s4)
/* 41CFBC 802A822C 1440002E */  bnez      $v0, .L802A82E8
/* 41CFC0 802A8230 2402FFFF */   addiu    $v0, $zero, -1
/* 41CFC4 802A8234 A2820178 */  sb        $v0, 0x178($s4)
/* 41CFC8 802A8238 A680017C */  sh        $zero, 0x17c($s4)
/* 41CFCC 802A823C 0C0A9634 */  jal       func_802A58D0
/* 41CFD0 802A8240 AE800188 */   sw       $zero, 0x188($s4)
/* 41CFD4 802A8244 14400005 */  bnez      $v0, .L802A825C
/* 41CFD8 802A8248 00000000 */   nop
/* 41CFDC 802A824C 0C090464 */  jal       func_80241190
/* 41CFE0 802A8250 24040009 */   addiu    $a0, $zero, 9
/* 41CFE4 802A8254 080AA0B8 */  j         .L802A82E0
/* 41CFE8 802A8258 00000000 */   nop
.L802A825C:
/* 41CFEC 802A825C 0C093903 */  jal       func_8024E40C
/* 41CFF0 802A8260 24040002 */   addiu    $a0, $zero, 2
/* 41CFF4 802A8264 8E820000 */  lw        $v0, ($s4)
/* 41CFF8 802A8268 3C03F3FF */  lui       $v1, 0xf3ff
/* 41CFFC 802A826C 34420002 */  ori       $v0, $v0, 2
/* 41D000 802A8270 AE820000 */  sw        $v0, ($s4)
/* 41D004 802A8274 8E620000 */  lw        $v0, ($s3)
/* 41D008 802A8278 3463FFFF */  ori       $v1, $v1, 0xffff
/* 41D00C 802A827C 00431024 */  and       $v0, $v0, $v1
/* 41D010 802A8280 AE620000 */  sw        $v0, ($s3)
/* 41D014 802A8284 8E020000 */  lw        $v0, ($s0)
/* 41D018 802A8288 00431024 */  and       $v0, $v0, $v1
/* 41D01C 802A828C AE020000 */  sw        $v0, ($s0)
/* 41D020 802A8290 8E820000 */  lw        $v0, ($s4)
/* 41D024 802A8294 3C030010 */  lui       $v1, 0x10
/* 41D028 802A8298 00431024 */  and       $v0, $v0, $v1
/* 41D02C 802A829C 10400003 */  beqz      $v0, .L802A82AC
/* 41D030 802A82A0 2402012E */   addiu    $v0, $zero, 0x12e
/* 41D034 802A82A4 080AA0B8 */  j         .L802A82E0
/* 41D038 802A82A8 AE220000 */   sw       $v0, ($s1)
.L802A82AC:
/* 41D03C 802A82AC C6000138 */  lwc1      $f0, 0x138($s0)
/* 41D040 802A82B0 C6020140 */  lwc1      $f2, 0x140($s0)
/* 41D044 802A82B4 E600000C */  swc1      $f0, 0xc($s0)
/* 41D048 802A82B8 E6020014 */  swc1      $f2, 0x14($s0)
/* 41D04C 802A82BC C6600138 */  lwc1      $f0, 0x138($s3)
/* 41D050 802A82C0 2402012D */  addiu     $v0, $zero, 0x12d
/* 41D054 802A82C4 AE220000 */  sw        $v0, ($s1)
/* 41D058 802A82C8 E6000018 */  swc1      $f0, 0x18($s0)
/* 41D05C 802A82CC C6600140 */  lwc1      $f0, 0x140($s3)
/* 41D060 802A82D0 24020004 */  addiu     $v0, $zero, 4
/* 41D064 802A82D4 A6020070 */  sh        $v0, 0x70($s0)
/* 41D068 802A82D8 AE000054 */  sw        $zero, 0x54($s0)
/* 41D06C 802A82DC E6000020 */  swc1      $f0, 0x20($s0)
.L802A82E0:
/* 41D070 802A82E0 3C11800E */  lui       $s1, %hi(gBattleStatus+0x46C)
/* 41D074 802A82E4 2631C4DC */  addiu     $s1, $s1, %lo(gBattleStatus+0x46C)
.L802A82E8:
/* 41D078 802A82E8 8E230000 */  lw        $v1, ($s1)
/* 41D07C 802A82EC 2402012D */  addiu     $v0, $zero, 0x12d
/* 41D080 802A82F0 1462006C */  bne       $v1, $v0, .L802A84A4
/* 41D084 802A82F4 00000000 */   nop
/* 41D088 802A82F8 86020070 */  lh        $v0, 0x70($s0)
/* 41D08C 802A82FC 10400022 */  beqz      $v0, .L802A8388
/* 41D090 802A8300 00000000 */   nop
/* 41D094 802A8304 C6000018 */  lwc1      $f0, 0x18($s0)
/* 41D098 802A8308 C6080144 */  lwc1      $f8, 0x144($s0)
/* 41D09C 802A830C C6020020 */  lwc1      $f2, 0x20($s0)
/* 41D0A0 802A8310 46080001 */  sub.s     $f0, $f0, $f8
/* 41D0A4 802A8314 C604014C */  lwc1      $f4, 0x14c($s0)
/* 41D0A8 802A8318 46041081 */  sub.s     $f2, $f2, $f4
/* 41D0AC 802A831C 44823000 */  mtc1      $v0, $f6
/* 41D0B0 802A8320 00000000 */  nop
/* 41D0B4 802A8324 468031A0 */  cvt.s.w   $f6, $f6
/* 41D0B8 802A8328 46060003 */  div.s     $f0, $f0, $f6
/* 41D0BC 802A832C 46004200 */  add.s     $f8, $f8, $f0
/* 41D0C0 802A8330 46003006 */  mov.s     $f0, $f6
/* 41D0C4 802A8334 46061083 */  div.s     $f2, $f2, $f6
/* 41D0C8 802A8338 C600000C */  lwc1      $f0, 0xc($s0)
/* 41D0CC 802A833C 46022100 */  add.s     $f4, $f4, $f2
/* 41D0D0 802A8340 E6080144 */  swc1      $f8, 0x144($s0)
/* 41D0D4 802A8344 E604014C */  swc1      $f4, 0x14c($s0)
/* 41D0D8 802A8348 C6640144 */  lwc1      $f4, 0x144($s3)
/* 41D0DC 802A834C 46040001 */  sub.s     $f0, $f0, $f4
/* 41D0E0 802A8350 46003086 */  mov.s     $f2, $f6
/* 41D0E4 802A8354 46060003 */  div.s     $f0, $f0, $f6
/* 41D0E8 802A8358 46002100 */  add.s     $f4, $f4, $f0
/* 41D0EC 802A835C E6640144 */  swc1      $f4, 0x144($s3)
/* 41D0F0 802A8360 C6000014 */  lwc1      $f0, 0x14($s0)
/* 41D0F4 802A8364 C664014C */  lwc1      $f4, 0x14c($s3)
/* 41D0F8 802A8368 86020070 */  lh        $v0, 0x70($s0)
/* 41D0FC 802A836C 46040001 */  sub.s     $f0, $f0, $f4
/* 41D100 802A8370 44821000 */  mtc1      $v0, $f2
/* 41D104 802A8374 00000000 */  nop
/* 41D108 802A8378 468010A0 */  cvt.s.w   $f2, $f2
/* 41D10C 802A837C 46020003 */  div.s     $f0, $f0, $f2
/* 41D110 802A8380 46002100 */  add.s     $f4, $f4, $f0
/* 41D114 802A8384 E664014C */  swc1      $f4, 0x14c($s3)
.L802A8388:
/* 41D118 802A8388 C60C0054 */  lwc1      $f12, 0x54($s0)
/* 41D11C 802A838C 3C0140C9 */  lui       $at, 0x40c9
/* 41D120 802A8390 34210FD0 */  ori       $at, $at, 0xfd0
/* 41D124 802A8394 4481B000 */  mtc1      $at, $f22
/* 41D128 802A8398 00000000 */  nop
/* 41D12C 802A839C 46166302 */  mul.s     $f12, $f12, $f22
/* 41D130 802A83A0 00000000 */  nop
/* 41D134 802A83A4 3C0143B4 */  lui       $at, 0x43b4
/* 41D138 802A83A8 4481C000 */  mtc1      $at, $f24
/* 41D13C 802A83AC 3C014180 */  lui       $at, 0x4180
/* 41D140 802A83B0 4481A000 */  mtc1      $at, $f20
/* 41D144 802A83B4 0C00A85B */  jal       sin_rad
/* 41D148 802A83B8 46186303 */   div.s    $f12, $f12, $f24
/* 41D14C 802A83BC 46140002 */  mul.s     $f0, $f0, $f20
/* 41D150 802A83C0 00000000 */  nop
/* 41D154 802A83C4 C602014C */  lwc1      $f2, 0x14c($s0)
/* 41D158 802A83C8 46001080 */  add.s     $f2, $f2, $f0
/* 41D15C 802A83CC C60C0054 */  lwc1      $f12, 0x54($s0)
/* 41D160 802A83D0 46006307 */  neg.s     $f12, $f12
/* 41D164 802A83D4 0C00A6C9 */  jal       clamp_angle
/* 41D168 802A83D8 E602014C */   swc1     $f2, 0x14c($s0)
/* 41D16C 802A83DC C60C0054 */  lwc1      $f12, 0x54($s0)
/* 41D170 802A83E0 46166302 */  mul.s     $f12, $f12, $f22
/* 41D174 802A83E4 00000000 */  nop
/* 41D178 802A83E8 E600018C */  swc1      $f0, 0x18c($s0)
/* 41D17C 802A83EC 0C00A85B */  jal       sin_rad
/* 41D180 802A83F0 46186303 */   div.s    $f12, $f12, $f24
/* 41D184 802A83F4 46140002 */  mul.s     $f0, $f0, $f20
/* 41D188 802A83F8 00000000 */  nop
/* 41D18C 802A83FC C662014C */  lwc1      $f2, 0x14c($s3)
/* 41D190 802A8400 46001081 */  sub.s     $f2, $f2, $f0
/* 41D194 802A8404 E662014C */  swc1      $f2, 0x14c($s3)
/* 41D198 802A8408 C60C0054 */  lwc1      $f12, 0x54($s0)
/* 41D19C 802A840C 0C00A6C9 */  jal       clamp_angle
/* 41D1A0 802A8410 46006307 */   neg.s    $f12, $f12
/* 41D1A4 802A8414 E660018C */  swc1      $f0, 0x18c($s3)
/* 41D1A8 802A8418 C6000054 */  lwc1      $f0, 0x54($s0)
/* 41D1AC 802A841C 3C0142B4 */  lui       $at, 0x42b4
/* 41D1B0 802A8420 44811000 */  mtc1      $at, $f2
/* 41D1B4 802A8424 86020070 */  lh        $v0, 0x70($s0)
/* 41D1B8 802A8428 46020000 */  add.s     $f0, $f0, $f2
/* 41D1BC 802A842C 96030070 */  lhu       $v1, 0x70($s0)
/* 41D1C0 802A8430 10400004 */  beqz      $v0, .L802A8444
/* 41D1C4 802A8434 E6000054 */   swc1     $f0, 0x54($s0)
/* 41D1C8 802A8438 2462FFFF */  addiu     $v0, $v1, -1
/* 41D1CC 802A843C 080AA129 */  j         .L802A84A4
/* 41D1D0 802A8440 A6020070 */   sh       $v0, 0x70($s0)
.L802A8444:
/* 41D1D4 802A8444 C6000018 */  lwc1      $f0, 0x18($s0)
/* 41D1D8 802A8448 C6020020 */  lwc1      $f2, 0x20($s0)
/* 41D1DC 802A844C C604000C */  lwc1      $f4, 0xc($s0)
/* 41D1E0 802A8450 E6000144 */  swc1      $f0, 0x144($s0)
/* 41D1E4 802A8454 E602014C */  swc1      $f2, 0x14c($s0)
/* 41D1E8 802A8458 E6640144 */  swc1      $f4, 0x144($s3)
/* 41D1EC 802A845C C6000014 */  lwc1      $f0, 0x14($s0)
/* 41D1F0 802A8460 E660014C */  swc1      $f0, 0x14c($s3)
/* 41D1F4 802A8464 C6000144 */  lwc1      $f0, 0x144($s0)
/* 41D1F8 802A8468 C602014C */  lwc1      $f2, 0x14c($s0)
/* 41D1FC 802A846C 2402012E */  addiu     $v0, $zero, 0x12e
/* 41D200 802A8470 E6000138 */  swc1      $f0, 0x138($s0)
/* 41D204 802A8474 E6020140 */  swc1      $f2, 0x140($s0)
/* 41D208 802A8478 C6600144 */  lwc1      $f0, 0x144($s3)
/* 41D20C 802A847C C662014C */  lwc1      $f2, 0x14c($s3)
/* 41D210 802A8480 3C04800E */  lui       $a0, %hi(gBattleStatus)
/* 41D214 802A8484 2484C070 */  addiu     $a0, $a0, %lo(gBattleStatus)
/* 41D218 802A8488 AE220000 */  sw        $v0, ($s1)
/* 41D21C 802A848C E6600138 */  swc1      $f0, 0x138($s3)
/* 41D220 802A8490 E6620140 */  swc1      $f2, 0x140($s3)
/* 41D224 802A8494 8C820000 */  lw        $v0, ($a0)
/* 41D228 802A8498 3C030010 */  lui       $v1, 0x10
/* 41D22C 802A849C 00431025 */  or        $v0, $v0, $v1
/* 41D230 802A84A0 AC820000 */  sw        $v0, ($a0)
.L802A84A4:
/* 41D234 802A84A4 3C02800E */  lui       $v0, %hi(gBattleStatus+0x46C)
/* 41D238 802A84A8 8C42C4DC */  lw        $v0, %lo(gBattleStatus+0x46C)($v0)
/* 41D23C 802A84AC 2443FFFE */  addiu     $v1, $v0, -2
/* 41D240 802A84B0 2C62012D */  sltiu     $v0, $v1, 0x12d
/* 41D244 802A84B4 1040057D */  beqz      $v0, .L802A9AAC
/* 41D248 802A84B8 00031080 */   sll      $v0, $v1, 2
/* 41D24C 802A84BC 3C01802B */  lui       $at, %hi(jtbl_802AC3C8_421158)
/* 41D250 802A84C0 00220821 */  addu      $at, $at, $v0
/* 41D254 802A84C4 8C22C3C8 */  lw        $v0, %lo(jtbl_802AC3C8_421158)($at)
/* 41D258 802A84C8 00400008 */  jr        $v0
/* 41D25C 802A84CC 00000000 */   nop
glabel L802A84D0_41D260
/* 41D260 802A84D0 3C03FBFF */  lui       $v1, 0xfbff
/* 41D264 802A84D4 3463FFFF */  ori       $v1, $v1, 0xffff
/* 41D268 802A84D8 8E020000 */  lw        $v0, ($s0)
/* 41D26C 802A84DC 3C040800 */  lui       $a0, 0x800
/* 41D270 802A84E0 00441025 */  or        $v0, $v0, $a0
/* 41D274 802A84E4 00431024 */  and       $v0, $v0, $v1
/* 41D278 802A84E8 AE020000 */  sw        $v0, ($s0)
/* 41D27C 802A84EC 8E620000 */  lw        $v0, ($s3)
/* 41D280 802A84F0 3C030400 */  lui       $v1, 0x400
/* 41D284 802A84F4 00431025 */  or        $v0, $v0, $v1
/* 41D288 802A84F8 00441025 */  or        $v0, $v0, $a0
/* 41D28C 802A84FC 0C098CC0 */  jal       func_80263300
/* 41D290 802A8500 AE620000 */   sw       $v0, ($s3)
/* 41D294 802A8504 0C098C9A */  jal       func_80263268
/* 41D298 802A8508 24110001 */   addiu    $s1, $zero, 1
/* 41D29C 802A850C 8282005C */  lb        $v0, 0x5c($s4)
/* 41D2A0 802A8510 04410002 */  bgez      $v0, .L802A851C
/* 41D2A4 802A8514 24020006 */   addiu    $v0, $zero, 6
/* 41D2A8 802A8518 A282005C */  sb        $v0, 0x5c($s4)
.L802A851C:
/* 41D2AC 802A851C 0C098E45 */  jal       func_80263914
/* 41D2B0 802A8520 00000000 */   nop
/* 41D2B4 802A8524 0C098C9A */  jal       func_80263268
/* 41D2B8 802A8528 00000000 */   nop
/* 41D2BC 802A852C 24040007 */  addiu     $a0, $zero, 7
/* 41D2C0 802A8530 3C13802B */  lui       $s3, %hi(D_802AD0D0)
/* 41D2C4 802A8534 2673D0D0 */  addiu     $s3, $s3, %lo(D_802AD0D0)
/* 41D2C8 802A8538 3C15802B */  lui       $s5, %hi(D_802AD0E8)
/* 41D2CC 802A853C 26B5D0E8 */  addiu     $s5, $s5, %lo(D_802AD0E8)
/* 41D2D0 802A8540 3C03802B */  lui       $v1, %hi(D_802AB478)
/* 41D2D4 802A8544 2463B478 */  addiu     $v1, $v1, %lo(D_802AB478)
/* 41D2D8 802A8548 3C12802B */  lui       $s2, %hi(D_802AD078)
/* 41D2DC 802A854C 2652D078 */  addiu     $s2, $s2, %lo(D_802AD078)
/* 41D2E0 802A8550 3C01802B */  lui       $at, %hi(D_802AD0B8)
/* 41D2E4 802A8554 AC24D0B8 */  sw        $a0, %lo(D_802AD0B8)($at)
/* 41D2E8 802A8558 AE710000 */  sw        $s1, ($s3)
/* 41D2EC 802A855C AEA00000 */  sw        $zero, ($s5)
/* 41D2F0 802A8560 8C620000 */  lw        $v0, ($v1)
/* 41D2F4 802A8564 3C16802B */  lui       $s6, %hi(D_802AB4C0)
/* 41D2F8 802A8568 26D6B4C0 */  addiu     $s6, $s6, %lo(D_802AB4C0)
/* 41D2FC 802A856C AE420000 */  sw        $v0, ($s2)
/* 41D300 802A8570 8EC2001C */  lw        $v0, 0x1c($s6)
/* 41D304 802A8574 3C1E802B */  lui       $fp, %hi(D_802AD090)
/* 41D308 802A8578 27DED090 */  addiu     $fp, $fp, %lo(D_802AD090)
/* 41D30C 802A857C AFC20000 */  sw        $v0, ($fp)
/* 41D310 802A8580 96820070 */  lhu       $v0, 0x70($s4)
/* 41D314 802A8584 30420080 */  andi      $v0, $v0, 0x80
/* 41D318 802A8588 14400005 */  bnez      $v0, .L802A85A0
/* 41D31C 802A858C 24020048 */   addiu    $v0, $zero, 0x48
/* 41D320 802A8590 AE600000 */  sw        $zero, ($s3)
/* 41D324 802A8594 8C630004 */  lw        $v1, 4($v1)
/* 41D328 802A8598 AEA20000 */  sw        $v0, ($s5)
/* 41D32C 802A859C AE430000 */  sw        $v1, ($s2)
.L802A85A0:
/* 41D330 802A85A0 8282005C */  lb        $v0, 0x5c($s4)
/* 41D334 802A85A4 50440001 */  beql      $v0, $a0, .L802A85AC
/* 41D338 802A85A8 0000882D */   daddu    $s1, $zero, $zero
.L802A85AC:
/* 41D33C 802A85AC 82E30012 */  lb        $v1, 0x12($s7)
/* 41D340 802A85B0 24100001 */  addiu     $s0, $zero, 1
/* 41D344 802A85B4 00031080 */  sll       $v0, $v1, 2
/* 41D348 802A85B8 00431021 */  addu      $v0, $v0, $v1
/* 41D34C 802A85BC 000210C0 */  sll       $v0, $v0, 3
/* 41D350 802A85C0 3C03802B */  lui       $v1, %hi(D_802AB590)
/* 41D354 802A85C4 00621821 */  addu      $v1, $v1, $v0
/* 41D358 802A85C8 8C63B590 */  lw        $v1, %lo(D_802AB590)($v1)
/* 41D35C 802A85CC 8EC20018 */  lw        $v0, 0x18($s6)
/* 41D360 802A85D0 24050006 */  addiu     $a1, $zero, 6
/* 41D364 802A85D4 3C01802B */  lui       $at, %hi(D_802AD0BC)
/* 41D368 802A85D8 AC25D0BC */  sw        $a1, %lo(D_802AD0BC)($at)
/* 41D36C 802A85DC AE700004 */  sw        $s0, 4($s3)
/* 41D370 802A85E0 AFC20004 */  sw        $v0, 4($fp)
/* 41D374 802A85E4 AE430004 */  sw        $v1, 4($s2)
/* 41D378 802A85E8 82820080 */  lb        $v0, 0x80($s4)
/* 41D37C 802A85EC 3C04802B */  lui       $a0, %hi(D_802AB590)
/* 41D380 802A85F0 1C40000B */  bgtz      $v0, .L802A8620
/* 41D384 802A85F4 2484B590 */   addiu    $a0, $a0, %lo(D_802AB590)
/* 41D388 802A85F8 82E30012 */  lb        $v1, 0x12($s7)
/* 41D38C 802A85FC 00031080 */  sll       $v0, $v1, 2
/* 41D390 802A8600 00431021 */  addu      $v0, $v0, $v1
/* 41D394 802A8604 000210C0 */  sll       $v0, $v0, 3
/* 41D398 802A8608 00441021 */  addu      $v0, $v0, $a0
/* 41D39C 802A860C 8C430004 */  lw        $v1, 4($v0)
/* 41D3A0 802A8610 24020048 */  addiu     $v0, $zero, 0x48
/* 41D3A4 802A8614 AE600004 */  sw        $zero, 4($s3)
/* 41D3A8 802A8618 AEA20004 */  sw        $v0, 4($s5)
/* 41D3AC 802A861C AE430004 */  sw        $v1, 4($s2)
.L802A8620:
/* 41D3B0 802A8620 96820070 */  lhu       $v0, 0x70($s4)
/* 41D3B4 802A8624 30420040 */  andi      $v0, $v0, 0x40
/* 41D3B8 802A8628 1440000B */  bnez      $v0, .L802A8658
/* 41D3BC 802A862C 00000000 */   nop
/* 41D3C0 802A8630 82E30012 */  lb        $v1, 0x12($s7)
/* 41D3C4 802A8634 00031080 */  sll       $v0, $v1, 2
/* 41D3C8 802A8638 00431021 */  addu      $v0, $v0, $v1
/* 41D3CC 802A863C 000210C0 */  sll       $v0, $v0, 3
/* 41D3D0 802A8640 00441021 */  addu      $v0, $v0, $a0
/* 41D3D4 802A8644 8C430004 */  lw        $v1, 4($v0)
/* 41D3D8 802A8648 24020048 */  addiu     $v0, $zero, 0x48
/* 41D3DC 802A864C AE600004 */  sw        $zero, 4($s3)
/* 41D3E0 802A8650 AEA20004 */  sw        $v0, 4($s5)
/* 41D3E4 802A8654 AE430004 */  sw        $v1, 4($s2)
.L802A8658:
/* 41D3E8 802A8658 8282005C */  lb        $v0, 0x5c($s4)
/* 41D3EC 802A865C 50450001 */  beql      $v0, $a1, .L802A8664
/* 41D3F0 802A8660 24110001 */   addiu    $s1, $zero, 1
.L802A8664:
/* 41D3F4 802A8664 82E2028E */  lb        $v0, 0x28e($s7)
/* 41D3F8 802A8668 1040001C */  beqz      $v0, .L802A86DC
/* 41D3FC 802A866C 24100002 */   addiu    $s0, $zero, 2
/* 41D400 802A8670 0C03A752 */  jal       is_ability_active
/* 41D404 802A8674 24040035 */   addiu    $a0, $zero, 0x35
/* 41D408 802A8678 10400018 */  beqz      $v0, .L802A86DC
/* 41D40C 802A867C 2407000B */   addiu    $a3, $zero, 0xb
/* 41D410 802A8680 3C06802B */  lui       $a2, %hi(D_802AB390)
/* 41D414 802A8684 24C6B390 */  addiu     $a2, $a2, %lo(D_802AB390)
/* 41D418 802A8688 8CC40000 */  lw        $a0, ($a2)
/* 41D41C 802A868C 8EC5002C */  lw        $a1, 0x2c($s6)
/* 41D420 802A8690 96830070 */  lhu       $v1, 0x70($s4)
/* 41D424 802A8694 24020001 */  addiu     $v0, $zero, 1
/* 41D428 802A8698 3C01802B */  lui       $at, %hi(D_802AD0C0)
/* 41D42C 802A869C AC27D0C0 */  sw        $a3, %lo(D_802AD0C0)($at)
/* 41D430 802A86A0 AE620008 */  sw        $v0, 8($s3)
/* 41D434 802A86A4 AEA00008 */  sw        $zero, 8($s5)
/* 41D438 802A86A8 30630800 */  andi      $v1, $v1, 0x800
/* 41D43C 802A86AC AE440008 */  sw        $a0, 8($s2)
/* 41D440 802A86B0 14600006 */  bnez      $v1, .L802A86CC
/* 41D444 802A86B4 AFC50008 */   sw       $a1, 8($fp)
/* 41D448 802A86B8 AE600008 */  sw        $zero, 8($s3)
/* 41D44C 802A86BC 8CC30004 */  lw        $v1, 4($a2)
/* 41D450 802A86C0 24020048 */  addiu     $v0, $zero, 0x48
/* 41D454 802A86C4 AEA20008 */  sw        $v0, 8($s5)
/* 41D458 802A86C8 AE430008 */  sw        $v1, 8($s2)
.L802A86CC:
/* 41D45C 802A86CC 8282005C */  lb        $v0, 0x5c($s4)
/* 41D460 802A86D0 50470001 */  beql      $v0, $a3, .L802A86D8
/* 41D464 802A86D4 24110002 */   addiu    $s1, $zero, 2
.L802A86D8:
/* 41D468 802A86D8 24100003 */  addiu     $s0, $zero, 3
.L802A86DC:
/* 41D46C 802A86DC 3C01802B */  lui       $at, %hi(D_802AD0AC)
/* 41D470 802A86E0 AC30D0AC */  sw        $s0, %lo(D_802AD0AC)($at)
/* 41D474 802A86E4 24100001 */  addiu     $s0, $zero, 1
/* 41D478 802A86E8 24020002 */  addiu     $v0, $zero, 2
/* 41D47C 802A86EC 00511023 */  subu      $v0, $v0, $s1
/* 41D480 802A86F0 3C01802B */  lui       $at, %hi(D_802AD0A8)
/* 41D484 802A86F4 AC30D0A8 */  sw        $s0, %lo(D_802AD0A8)($at)
/* 41D488 802A86F8 3C01802B */  lui       $at, %hi(D_802AD0B0)
/* 41D48C 802A86FC AC31D0B0 */  sw        $s1, %lo(D_802AD0B0)($at)
/* 41D490 802A8700 3C01802B */  lui       $at, %hi(D_802AD100)
/* 41D494 802A8704 AC22D100 */  sw        $v0, %lo(D_802AD100)($at)
/* 41D498 802A8708 0C0A9606 */  jal       can_switch_to_player
/* 41D49C 802A870C 00000000 */   nop
/* 41D4A0 802A8710 10400005 */  beqz      $v0, .L802A8728
/* 41D4A4 802A8714 00000000 */   nop
/* 41D4A8 802A8718 3C01802B */  lui       $at, %hi(D_802AD104)
/* 41D4AC 802A871C AC30D104 */  sw        $s0, %lo(D_802AD104)($at)
/* 41D4B0 802A8720 080AA1CC */  j         .L802A8730
/* 41D4B4 802A8724 00000000 */   nop
.L802A8728:
/* 41D4B8 802A8728 3C01802B */  lui       $at, %hi(D_802AD104)
/* 41D4BC 802A872C AC20D104 */  sw        $zero, %lo(D_802AD104)($at)
.L802A8730:
/* 41D4C0 802A8730 0C0A8400 */  jal       func_802A1000
/* 41D4C4 802A8734 00000000 */   nop
/* 41D4C8 802A8738 24020008 */  addiu     $v0, $zero, 8
/* 41D4CC 802A873C 3C01802B */  lui       $at, %hi(D_802ACC60)
/* 41D4D0 802A8740 AC22CC60 */  sw        $v0, %lo(D_802ACC60)($at)
/* 41D4D4 802A8744 3C01802B */  lui       $at, %hi(D_802ACC6C)
/* 41D4D8 802A8748 AC20CC6C */  sw        $zero, %lo(D_802ACC6C)($at)
/* 41D4DC 802A874C 080AA6A9 */  j         .L802A9AA4
/* 41D4E0 802A8750 24020002 */   addiu    $v0, $zero, 2
glabel L802A8754_41D4E4
/* 41D4E4 802A8754 82E20012 */  lb        $v0, 0x12($s7)
/* 41D4E8 802A8758 24040100 */  addiu     $a0, $zero, 0x100
/* 41D4EC 802A875C 00021080 */  sll       $v0, $v0, 2
/* 41D4F0 802A8760 3C06802B */  lui       $a2, %hi(D_802AB520)
/* 41D4F4 802A8764 00C23021 */  addu      $a2, $a2, $v0
/* 41D4F8 802A8768 8CC6B520 */  lw        $a2, %lo(D_802AB520)($a2)
/* 41D4FC 802A876C 0C098F3F */  jal       set_animation
/* 41D500 802A8770 0000282D */   daddu    $a1, $zero, $zero
/* 41D504 802A8774 24020003 */  addiu     $v0, $zero, 3
/* 41D508 802A8778 3C01800E */  lui       $at, %hi(gBattleStatus+0x46C)
/* 41D50C 802A877C AC22C4DC */  sw        $v0, %lo(gBattleStatus+0x46C)($at)
glabel L802A8780_41D510
/* 41D510 802A8780 0C0A846C */  jal       func_802A11B0
/* 41D514 802A8784 00000000 */   nop
/* 41D518 802A8788 3C04802B */  lui       $a0, %hi(D_802ACC6C)
/* 41D51C 802A878C 2484CC6C */  addiu     $a0, $a0, %lo(D_802ACC6C)
/* 41D520 802A8790 8C830000 */  lw        $v1, ($a0)
/* 41D524 802A8794 10600004 */  beqz      $v1, .L802A87A8
/* 41D528 802A8798 0040802D */   daddu    $s0, $v0, $zero
/* 41D52C 802A879C 2462FFFF */  addiu     $v0, $v1, -1
/* 41D530 802A87A0 080AA20D */  j         .L802A8834
/* 41D534 802A87A4 AC820000 */   sw       $v0, ($a0)
.L802A87A8:
/* 41D538 802A87A8 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 41D53C 802A87AC 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 41D540 802A87B0 3C030200 */  lui       $v1, 0x200
/* 41D544 802A87B4 00431024 */  and       $v0, $v0, $v1
/* 41D548 802A87B8 1440001E */  bnez      $v0, .L802A8834
/* 41D54C 802A87BC 00000000 */   nop
/* 41D550 802A87C0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 41D554 802A87C4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 41D558 802A87C8 8C420010 */  lw        $v0, 0x10($v0)
/* 41D55C 802A87CC 30422000 */  andi      $v0, $v0, 0x2000
/* 41D560 802A87D0 10400018 */  beqz      $v0, .L802A8834
/* 41D564 802A87D4 00000000 */   nop
/* 41D568 802A87D8 0C0A9606 */  jal       can_switch_to_player
/* 41D56C 802A87DC 00000000 */   nop
/* 41D570 802A87E0 10400010 */  beqz      $v0, .L802A8824
/* 41D574 802A87E4 00000000 */   nop
/* 41D578 802A87E8 0C05272D */  jal       play_sound
/* 41D57C 802A87EC 2404000F */   addiu    $a0, $zero, 0xf
/* 41D580 802A87F0 3C02802B */  lui       $v0, %hi(D_802AD002)
/* 41D584 802A87F4 8042D002 */  lb        $v0, %lo(D_802AD002)($v0)
/* 41D588 802A87F8 3C03802B */  lui       $v1, %hi(D_802AD06B)
/* 41D58C 802A87FC 8063D06B */  lb        $v1, %lo(D_802AD06B)($v1)
/* 41D590 802A8800 00431021 */  addu      $v0, $v0, $v1
/* 41D594 802A8804 00021080 */  sll       $v0, $v0, 2
/* 41D598 802A8808 3C01802B */  lui       $at, %hi(D_802AD0BB)
/* 41D59C 802A880C 00220821 */  addu      $at, $at, $v0
/* 41D5A0 802A8810 9022D0BB */  lbu       $v0, %lo(D_802AD0BB)($at)
/* 41D5A4 802A8814 0C0A842E */  jal       func_802A10B8
/* 41D5A8 802A8818 A282005C */   sb       $v0, 0x5c($s4)
/* 41D5AC 802A881C 080AA5DD */  j         .L802A9774
/* 41D5B0 802A8820 00000000 */   nop
.L802A8824:
/* 41D5B4 802A8824 0C05272D */  jal       play_sound
/* 41D5B8 802A8828 2404021D */   addiu    $a0, $zero, 0x21d
/* 41D5BC 802A882C 080AA6A9 */  j         .L802A9AA4
/* 41D5C0 802A8830 24020008 */   addiu    $v0, $zero, 8
.L802A8834:
/* 41D5C4 802A8834 3C03802B */  lui       $v1, %hi(D_802ACC60)
/* 41D5C8 802A8838 2463CC60 */  addiu     $v1, $v1, %lo(D_802ACC60)
/* 41D5CC 802A883C 8C620000 */  lw        $v0, ($v1)
/* 41D5D0 802A8840 10400003 */  beqz      $v0, .L802A8850
/* 41D5D4 802A8844 2442FFFF */   addiu    $v0, $v0, -1
/* 41D5D8 802A8848 080AA6AB */  j         .L802A9AAC
/* 41D5DC 802A884C AC620000 */   sw       $v0, ($v1)
.L802A8850:
/* 41D5E0 802A8850 12000496 */  beqz      $s0, .L802A9AAC
/* 41D5E4 802A8854 24040100 */   addiu    $a0, $zero, 0x100
/* 41D5E8 802A8858 82E20012 */  lb        $v0, 0x12($s7)
/* 41D5EC 802A885C 00021080 */  sll       $v0, $v0, 2
/* 41D5F0 802A8860 3C06802B */  lui       $a2, %hi(D_802AB558)
/* 41D5F4 802A8864 00C23021 */  addu      $a2, $a2, $v0
/* 41D5F8 802A8868 8CC6B558 */  lw        $a2, %lo(D_802AB558)($a2)
/* 41D5FC 802A886C 0C098F3F */  jal       set_animation
/* 41D600 802A8870 0000282D */   daddu    $a1, $zero, $zero
/* 41D604 802A8874 2602FFFF */  addiu     $v0, $s0, -1
/* 41D608 802A8878 00021080 */  sll       $v0, $v0, 2
/* 41D60C 802A887C 3C01802B */  lui       $at, %hi(D_802AD0BB)
/* 41D610 802A8880 00220821 */  addu      $at, $at, $v0
/* 41D614 802A8884 9022D0BB */  lbu       $v0, %lo(D_802AD0BB)($at)
/* 41D618 802A8888 A282004A */  sb        $v0, 0x4a($s4)
/* 41D61C 802A888C 8283004A */  lb        $v1, 0x4a($s4)
/* 41D620 802A8890 24050007 */  addiu     $a1, $zero, 7
/* 41D624 802A8894 14650003 */  bne       $v1, $a1, .L802A88A4
/* 41D628 802A8898 A282005C */   sb       $v0, 0x5c($s4)
/* 41D62C 802A889C 080AA641 */  j         .L802A9904
/* 41D630 802A88A0 240200C8 */   addiu    $v0, $zero, 0xc8
.L802A88A4:
/* 41D634 802A88A4 24040006 */  addiu     $a0, $zero, 6
/* 41D638 802A88A8 14640003 */  bne       $v1, $a0, .L802A88B8
/* 41D63C 802A88AC 24020008 */   addiu    $v0, $zero, 8
/* 41D640 802A88B0 080AA641 */  j         .L802A9904
/* 41D644 802A88B4 2402000A */   addiu    $v0, $zero, 0xa
.L802A88B8:
/* 41D648 802A88B8 14620003 */  bne       $v1, $v0, .L802A88C8
/* 41D64C 802A88BC 24020002 */   addiu    $v0, $zero, 2
/* 41D650 802A88C0 080AA641 */  j         .L802A9904
/* 41D654 802A88C4 2402003C */   addiu    $v0, $zero, 0x3c
.L802A88C8:
/* 41D658 802A88C8 14620003 */  bne       $v1, $v0, .L802A88D8
/* 41D65C 802A88CC 24020005 */   addiu    $v0, $zero, 5
/* 41D660 802A88D0 080AA641 */  j         .L802A9904
/* 41D664 802A88D4 24020028 */   addiu    $v0, $zero, 0x28
.L802A88D8:
/* 41D668 802A88D8 54620003 */  bnel      $v1, $v0, .L802A88E8
/* 41D66C 802A88DC A684006C */   sh       $a0, 0x6c($s4)
/* 41D670 802A88E0 080AA641 */  j         .L802A9904
/* 41D674 802A88E4 24020032 */   addiu    $v0, $zero, 0x32
.L802A88E8:
/* 41D678 802A88E8 0C0A840C */  jal       func_802A1030
/* 41D67C 802A88EC A685006E */   sh       $a1, 0x6e($s4)
/* 41D680 802A88F0 080AA6A9 */  j         .L802A9AA4
/* 41D684 802A88F4 24020004 */   addiu    $v0, $zero, 4
glabel L802A88F8_41D688
/* 41D688 802A88F8 0C0A846C */  jal       func_802A11B0
/* 41D68C 802A88FC 00000000 */   nop
/* 41D690 802A8900 8E830214 */  lw        $v1, 0x214($s4)
/* 41D694 802A8904 30634000 */  andi      $v1, $v1, 0x4000
/* 41D698 802A8908 10600007 */  beqz      $v1, .L802A8928
/* 41D69C 802A890C 0040802D */   daddu    $s0, $v0, $zero
/* 41D6A0 802A8910 16000007 */  bnez      $s0, .L802A8930
/* 41D6A4 802A8914 24040011 */   addiu    $a0, $zero, 0x11
/* 41D6A8 802A8918 0C0A841E */  jal       func_802A1078
/* 41D6AC 802A891C 00000000 */   nop
/* 41D6B0 802A8920 080AA6A9 */  j         .L802A9AA4
/* 41D6B4 802A8924 24020005 */   addiu    $v0, $zero, 5
.L802A8928:
/* 41D6B8 802A8928 12000460 */  beqz      $s0, .L802A9AAC
/* 41D6BC 802A892C 24040011 */   addiu    $a0, $zero, 0x11
.L802A8930:
/* 41D6C0 802A8930 24020008 */  addiu     $v0, $zero, 8
/* 41D6C4 802A8934 A2820178 */  sb        $v0, 0x178($s4)
/* 41D6C8 802A8938 3C038009 */  lui       $v1, %hi(D_8008F9B0)
/* 41D6CC 802A893C 8C63F9B0 */  lw        $v1, %lo(D_8008F9B0)($v1)
/* 41D6D0 802A8940 24020077 */  addiu     $v0, $zero, 0x77
/* 41D6D4 802A8944 A682017C */  sh        $v0, 0x17c($s4)
/* 41D6D8 802A8948 080AA34A */  j         .L802A8D28
/* 41D6DC 802A894C A680017A */   sh       $zero, 0x17a($s4)
glabel L802A8950_41D6E0
/* 41D6E0 802A8950 0C0A846C */  jal       func_802A11B0
/* 41D6E4 802A8954 00000000 */   nop
/* 41D6E8 802A8958 10400454 */  beqz      $v0, .L802A9AAC
/* 41D6EC 802A895C 24020008 */   addiu    $v0, $zero, 8
/* 41D6F0 802A8960 3C01802B */  lui       $at, %hi(D_802ACC60)
/* 41D6F4 802A8964 AC22CC60 */  sw        $v0, %lo(D_802ACC60)($at)
/* 41D6F8 802A8968 24020004 */  addiu     $v0, $zero, 4
/* 41D6FC 802A896C 3C01802B */  lui       $at, %hi(D_802ACC6C)
/* 41D700 802A8970 AC22CC6C */  sw        $v0, %lo(D_802ACC6C)($at)
/* 41D704 802A8974 080AA6A9 */  j         .L802A9AA4
/* 41D708 802A8978 24020002 */   addiu    $v0, $zero, 2
glabel L802A897C_41D70C
/* 41D70C 802A897C 0C0A841E */  jal       func_802A1078
/* 41D710 802A8980 00000000 */   nop
/* 41D714 802A8984 080AA6A9 */  j         .L802A9AA4
/* 41D718 802A8988 24020005 */   addiu    $v0, $zero, 5
glabel L802A898C_41D71C
/* 41D71C 802A898C 0C0A9606 */  jal       can_switch_to_player
/* 41D720 802A8990 00000000 */   nop
/* 41D724 802A8994 14400002 */  bnez      $v0, .L802A89A0
/* 41D728 802A8998 24040050 */   addiu    $a0, $zero, 0x50
/* 41D72C 802A899C 24040051 */  addiu     $a0, $zero, 0x51
.L802A89A0:
/* 41D730 802A89A0 2405003C */  addiu     $a1, $zero, 0x3c
/* 41D734 802A89A4 0C093E81 */  jal       show_variable_battle_message
/* 41D738 802A89A8 0000302D */   daddu    $a2, $zero, $zero
/* 41D73C 802A89AC 24020001 */  addiu     $v0, $zero, 1
/* 41D740 802A89B0 3C01802B */  lui       $at, %hi(D_802AD607)
/* 41D744 802A89B4 A022D607 */  sb        $v0, %lo(D_802AD607)($at)
/* 41D748 802A89B8 080AA6A9 */  j         .L802A9AA4
/* 41D74C 802A89BC 24020009 */   addiu    $v0, $zero, 9
glabel L802A89C0_41D750
/* 41D750 802A89C0 0C093EAD */  jal       is_popup_displayed
/* 41D754 802A89C4 00000000 */   nop
/* 41D758 802A89C8 14400438 */  bnez      $v0, .L802A9AAC
/* 41D75C 802A89CC 24020004 */   addiu    $v0, $zero, 4
/* 41D760 802A89D0 3C01802B */  lui       $at, %hi(D_802ACC6C)
/* 41D764 802A89D4 AC22CC6C */  sw        $v0, %lo(D_802ACC6C)($at)
/* 41D768 802A89D8 3C01802B */  lui       $at, %hi(D_802ACC60)
/* 41D76C 802A89DC AC20CC60 */  sw        $zero, %lo(D_802ACC60)($at)
/* 41D770 802A89E0 3C01802B */  lui       $at, %hi(D_802AD607)
/* 41D774 802A89E4 A020D607 */  sb        $zero, %lo(D_802AD607)($at)
/* 41D778 802A89E8 080AA6A9 */  j         .L802A9AA4
/* 41D77C 802A89EC 24020002 */   addiu    $v0, $zero, 2
glabel L802A89F0_41D780
/* 41D780 802A89F0 9282020E */  lbu       $v0, 0x20e($s4)
/* 41D784 802A89F4 1040007A */  beqz      $v0, .L802A8BE0
/* 41D788 802A89F8 0000882D */   daddu    $s1, $zero, $zero
/* 41D78C 802A89FC 3C1E802B */  lui       $fp, %hi(D_802AB590)
/* 41D790 802A8A00 27DEB590 */  addiu     $fp, $fp, %lo(D_802AB590)
/* 41D794 802A8A04 2416000C */  addiu     $s6, $zero, 0xc
/* 41D798 802A8A08 24150008 */  addiu     $s5, $zero, 8
.L802A8A0C:
/* 41D79C 802A8A0C 02912821 */  addu      $a1, $s4, $s1
/* 41D7A0 802A8A10 3C02802B */  lui       $v0, %hi(D_802AD5E8)
/* 41D7A4 802A8A14 2442D5E8 */  addiu     $v0, $v0, %lo(D_802AD5E8)
/* 41D7A8 802A8A18 02222021 */  addu      $a0, $s1, $v0
/* 41D7AC 802A8A1C 90A301DE */  lbu       $v1, 0x1de($a1)
/* 41D7B0 802A8A20 3C188009 */  lui       $t8, %hi(D_8008F060)
/* 41D7B4 802A8A24 2718F060 */  addiu     $t8, $t8, %lo(D_8008F060)
/* 41D7B8 802A8A28 A0800000 */  sb        $zero, ($a0)
/* 41D7BC 802A8A2C 00031080 */  sll       $v0, $v1, 2
/* 41D7C0 802A8A30 00431021 */  addu      $v0, $v0, $v1
/* 41D7C4 802A8A34 00021080 */  sll       $v0, $v0, 2
/* 41D7C8 802A8A38 80A301F6 */  lb        $v1, 0x1f6($a1)
/* 41D7CC 802A8A3C 14600003 */  bnez      $v1, .L802A8A4C
/* 41D7D0 802A8A40 00583821 */   addu     $a3, $v0, $t8
/* 41D7D4 802A8A44 A0800000 */  sb        $zero, ($a0)
/* 41D7D8 802A8A48 80A301F6 */  lb        $v1, 0x1f6($a1)
.L802A8A4C:
/* 41D7DC 802A8A4C 2402FFFF */  addiu     $v0, $zero, -1
/* 41D7E0 802A8A50 14620005 */  bne       $v1, $v0, .L802A8A68
/* 41D7E4 802A8A54 2402FFFE */   addiu    $v0, $zero, -2
/* 41D7E8 802A8A58 A0A001F6 */  sb        $zero, 0x1f6($a1)
/* 41D7EC 802A8A5C 24180048 */  addiu     $t8, $zero, 0x48
/* 41D7F0 802A8A60 A0980000 */  sb        $t8, ($a0)
/* 41D7F4 802A8A64 80A301F6 */  lb        $v1, 0x1f6($a1)
.L802A8A68:
/* 41D7F8 802A8A68 14620003 */  bne       $v1, $v0, .L802A8A78
/* 41D7FC 802A8A6C 24180048 */   addiu    $t8, $zero, 0x48
/* 41D800 802A8A70 A0A001F6 */  sb        $zero, 0x1f6($a1)
/* 41D804 802A8A74 A0980000 */  sb        $t8, ($a0)
.L802A8A78:
/* 41D808 802A8A78 3C04802B */  lui       $a0, %hi(D_802AD260)
/* 41D80C 802A8A7C 2484D260 */  addiu     $a0, $a0, %lo(D_802AD260)
/* 41D810 802A8A80 82E30012 */  lb        $v1, 0x12($s7)
/* 41D814 802A8A84 00113080 */  sll       $a2, $s1, 2
/* 41D818 802A8A88 00031080 */  sll       $v0, $v1, 2
/* 41D81C 802A8A8C 00431021 */  addu      $v0, $v0, $v1
/* 41D820 802A8A90 000210C0 */  sll       $v0, $v0, 3
/* 41D824 802A8A94 02A21021 */  addu      $v0, $s5, $v0
/* 41D828 802A8A98 005E1021 */  addu      $v0, $v0, $fp
/* 41D82C 802A8A9C 8C420000 */  lw        $v0, ($v0)
/* 41D830 802A8AA0 00C42021 */  addu      $a0, $a2, $a0
/* 41D834 802A8AA4 AC820000 */  sw        $v0, ($a0)
/* 41D838 802A8AA8 80A201F6 */  lb        $v0, 0x1f6($a1)
/* 41D83C 802A8AAC 14400009 */  bnez      $v0, .L802A8AD4
/* 41D840 802A8AB0 00000000 */   nop
/* 41D844 802A8AB4 82E20012 */  lb        $v0, 0x12($s7)
/* 41D848 802A8AB8 00021880 */  sll       $v1, $v0, 2
/* 41D84C 802A8ABC 00621821 */  addu      $v1, $v1, $v0
/* 41D850 802A8AC0 000318C0 */  sll       $v1, $v1, 3
/* 41D854 802A8AC4 02C31821 */  addu      $v1, $s6, $v1
/* 41D858 802A8AC8 007E1821 */  addu      $v1, $v1, $fp
/* 41D85C 802A8ACC 8C620000 */  lw        $v0, ($v1)
/* 41D860 802A8AD0 AC820000 */  sw        $v0, ($a0)
.L802A8AD4:
/* 41D864 802A8AD4 90A201DE */  lbu       $v0, 0x1de($a1)
/* 41D868 802A8AD8 3C01802B */  lui       $at, %hi(D_802AD4B0)
/* 41D86C 802A8ADC 00260821 */  addu      $at, $at, $a2
/* 41D870 802A8AE0 AC22D4B0 */  sw        $v0, %lo(D_802AD4B0)($at)
/* 41D874 802A8AE4 80A201F6 */  lb        $v0, 0x1f6($a1)
/* 41D878 802A8AE8 3C01802B */  lui       $at, %hi(D_802AD510)
/* 41D87C 802A8AEC 00260821 */  addu      $at, $at, $a2
/* 41D880 802A8AF0 AC22D510 */  sw        $v0, %lo(D_802AD510)($at)
/* 41D884 802A8AF4 8CE20000 */  lw        $v0, ($a3)
/* 41D888 802A8AF8 3C01802B */  lui       $at, %hi(D_802AD2C0)
/* 41D88C 802A8AFC 00260821 */  addu      $at, $at, $a2
/* 41D890 802A8B00 AC22D2C0 */  sw        $v0, %lo(D_802AD2C0)($at)
/* 41D894 802A8B04 8CE20008 */  lw        $v0, 8($a3)
/* 41D898 802A8B08 3C01802B */  lui       $at, %hi(D_802AD570)
/* 41D89C 802A8B0C 00260821 */  addu      $at, $at, $a2
/* 41D8A0 802A8B10 AC22D570 */  sw        $v0, %lo(D_802AD570)($at)
/* 41D8A4 802A8B14 80E20011 */  lb        $v0, 0x11($a3)
/* 41D8A8 802A8B18 0260202D */  daddu     $a0, $s3, $zero
/* 41D8AC 802A8B1C 3C01802B */  lui       $at, %hi(D_802AD320)
/* 41D8B0 802A8B20 00260821 */  addu      $at, $at, $a2
/* 41D8B4 802A8B24 AC22D320 */  sw        $v0, %lo(D_802AD320)($at)
/* 41D8B8 802A8B28 80E20012 */  lb        $v0, 0x12($a3)
/* 41D8BC 802A8B2C 24050018 */  addiu     $a1, $zero, 0x18
/* 41D8C0 802A8B30 3C01802B */  lui       $at, %hi(D_802AD5D0)
/* 41D8C4 802A8B34 00310821 */  addu      $at, $at, $s1
/* 41D8C8 802A8B38 A031D5D0 */  sb        $s1, %lo(D_802AD5D0)($at)
/* 41D8CC 802A8B3C 3C01802B */  lui       $at, %hi(D_802AD440)
/* 41D8D0 802A8B40 00260821 */  addu      $at, $at, $a2
/* 41D8D4 802A8B44 AC22D440 */  sw        $v0, %lo(D_802AD440)($at)
/* 41D8D8 802A8B48 3C02802B */  lui       $v0, %hi(D_802AD380)
/* 41D8DC 802A8B4C 2442D380 */  addiu     $v0, $v0, %lo(D_802AD380)
/* 41D8E0 802A8B50 00C28021 */  addu      $s0, $a2, $v0
/* 41D8E4 802A8B54 3C02802B */  lui       $v0, %hi(D_802AD3E0)
/* 41D8E8 802A8B58 2442D3E0 */  addiu     $v0, $v0, %lo(D_802AD3E0)
/* 41D8EC 802A8B5C 00C29021 */  addu      $s2, $a2, $v0
/* 41D8F0 802A8B60 AE000000 */  sw        $zero, ($s0)
/* 41D8F4 802A8B64 0C099CAB */  jal       heroes_is_ability_active
/* 41D8F8 802A8B68 AE400000 */   sw       $zero, ($s2)
/* 41D8FC 802A8B6C 10400008 */  beqz      $v0, .L802A8B90
/* 41D900 802A8B70 0260202D */   daddu    $a0, $s3, $zero
/* 41D904 802A8B74 0C099CAB */  jal       heroes_is_ability_active
/* 41D908 802A8B78 24050018 */   addiu    $a1, $zero, 0x18
/* 41D90C 802A8B7C 8E030000 */  lw        $v1, ($s0)
/* 41D910 802A8B80 00621821 */  addu      $v1, $v1, $v0
/* 41D914 802A8B84 24020001 */  addiu     $v0, $zero, 1
/* 41D918 802A8B88 AE030000 */  sw        $v1, ($s0)
/* 41D91C 802A8B8C AE420000 */  sw        $v0, ($s2)
.L802A8B90:
/* 41D920 802A8B90 0260202D */  daddu     $a0, $s3, $zero
/* 41D924 802A8B94 0C099CAB */  jal       heroes_is_ability_active
/* 41D928 802A8B98 24050026 */   addiu    $a1, $zero, 0x26
/* 41D92C 802A8B9C 5040000B */  beql      $v0, $zero, .L802A8BCC
/* 41D930 802A8BA0 26D60008 */   addiu    $s6, $s6, 8
/* 41D934 802A8BA4 0260202D */  daddu     $a0, $s3, $zero
/* 41D938 802A8BA8 0C099CAB */  jal       heroes_is_ability_active
/* 41D93C 802A8BAC 24050026 */   addiu    $a1, $zero, 0x26
/* 41D940 802A8BB0 8E030000 */  lw        $v1, ($s0)
/* 41D944 802A8BB4 00021040 */  sll       $v0, $v0, 1
/* 41D948 802A8BB8 00621821 */  addu      $v1, $v1, $v0
/* 41D94C 802A8BBC 24020002 */  addiu     $v0, $zero, 2
/* 41D950 802A8BC0 AE030000 */  sw        $v1, ($s0)
/* 41D954 802A8BC4 AE420000 */  sw        $v0, ($s2)
/* 41D958 802A8BC8 26D60008 */  addiu     $s6, $s6, 8
.L802A8BCC:
/* 41D95C 802A8BCC 9282020E */  lbu       $v0, 0x20e($s4)
/* 41D960 802A8BD0 26310001 */  addiu     $s1, $s1, 1
/* 41D964 802A8BD4 0222102A */  slt       $v0, $s1, $v0
/* 41D968 802A8BD8 1440FF8C */  bnez      $v0, .L802A8A0C
/* 41D96C 802A8BDC 26B50008 */   addiu    $s5, $s5, 8
.L802A8BE0:
/* 41D970 802A8BE0 8282005D */  lb        $v0, 0x5d($s4)
/* 41D974 802A8BE4 04420001 */  bltzl     $v0, .L802A8BEC
/* 41D978 802A8BE8 A280005D */   sb       $zero, 0x5d($s4)
.L802A8BEC:
/* 41D97C 802A8BEC 8291005D */  lb        $s1, 0x5d($s4)
/* 41D980 802A8BF0 9282020E */  lbu       $v0, 0x20e($s4)
/* 41D984 802A8BF4 3C01802B */  lui       $at, %hi(D_802AD4A0)
/* 41D988 802A8BF8 AC20D4A0 */  sw        $zero, %lo(D_802AD4A0)($at)
/* 41D98C 802A8BFC 3C01802B */  lui       $at, %hi(D_802AD4A4)
/* 41D990 802A8C00 AC22D4A4 */  sw        $v0, %lo(D_802AD4A4)($at)
/* 41D994 802A8C04 3C01802B */  lui       $at, %hi(D_802AD4A8)
/* 41D998 802A8C08 AC31D4A8 */  sw        $s1, %lo(D_802AD4A8)($at)
/* 41D99C 802A8C0C 0C0A89A1 */  jal       func_802A2684
/* 41D9A0 802A8C10 00000000 */   nop
/* 41D9A4 802A8C14 080AA6A9 */  j         .L802A9AA4
/* 41D9A8 802A8C18 2402000B */   addiu    $v0, $zero, 0xb
glabel L802A8C1C_41D9AC
/* 41D9AC 802A8C1C 0C0A8B21 */  jal       func_802A2C84
/* 41D9B0 802A8C20 00000000 */   nop
/* 41D9B4 802A8C24 0040802D */  daddu     $s0, $v0, $zero
/* 41D9B8 802A8C28 2402FFFF */  addiu     $v0, $zero, -1
/* 41D9BC 802A8C2C 1202039D */  beq       $s0, $v0, .L802A9AA4
/* 41D9C0 802A8C30 24020010 */   addiu    $v0, $zero, 0x10
/* 41D9C4 802A8C34 1200039D */  beqz      $s0, .L802A9AAC
/* 41D9C8 802A8C38 240200FF */   addiu    $v0, $zero, 0xff
/* 41D9CC 802A8C3C 5602000B */  bnel      $s0, $v0, .L802A8C6C
/* 41D9D0 802A8C40 2602FFFF */   addiu    $v0, $s0, -1
/* 41D9D4 802A8C44 0C0A8414 */  jal       func_802A1050
/* 41D9D8 802A8C48 00000000 */   nop
/* 41D9DC 802A8C4C 24020008 */  addiu     $v0, $zero, 8
/* 41D9E0 802A8C50 3C01802B */  lui       $at, %hi(D_802ACC60)
/* 41D9E4 802A8C54 AC22CC60 */  sw        $v0, %lo(D_802ACC60)($at)
/* 41D9E8 802A8C58 24020004 */  addiu     $v0, $zero, 4
/* 41D9EC 802A8C5C 3C01802B */  lui       $at, %hi(D_802ACC6C)
/* 41D9F0 802A8C60 AC22CC6C */  sw        $v0, %lo(D_802ACC6C)($at)
/* 41D9F4 802A8C64 080AA641 */  j         .L802A9904
/* 41D9F8 802A8C68 24020002 */   addiu    $v0, $zero, 2
.L802A8C6C:
/* 41D9FC 802A8C6C 0C0A89F4 */  jal       func_802A27D0
/* 41DA00 802A8C70 A282004B */   sb       $v0, 0x4b($s4)
/* 41DA04 802A8C74 0C0A840C */  jal       func_802A1030
/* 41DA08 802A8C78 00000000 */   nop
/* 41DA0C 802A8C7C 080AA6A9 */  j         .L802A9AA4
/* 41DA10 802A8C80 2402000C */   addiu    $v0, $zero, 0xc
glabel L802A8C84_41DA14
/* 41DA14 802A8C84 0C0A8B21 */  jal       func_802A2C84
/* 41DA18 802A8C88 00000000 */   nop
/* 41DA1C 802A8C8C 8E830214 */  lw        $v1, 0x214($s4)
/* 41DA20 802A8C90 30634000 */  andi      $v1, $v1, 0x4000
/* 41DA24 802A8C94 10600009 */  beqz      $v1, .L802A8CBC
/* 41DA28 802A8C98 0040802D */   daddu    $s0, $v0, $zero
/* 41DA2C 802A8C9C 16000007 */  bnez      $s0, .L802A8CBC
/* 41DA30 802A8CA0 00000000 */   nop
/* 41DA34 802A8CA4 0C0A8AAE */  jal       func_802A2AB8
/* 41DA38 802A8CA8 00000000 */   nop
/* 41DA3C 802A8CAC 0C0A8426 */  jal       func_802A1098
/* 41DA40 802A8CB0 00000000 */   nop
/* 41DA44 802A8CB4 080AA6A9 */  j         .L802A9AA4
/* 41DA48 802A8CB8 2402000D */   addiu    $v0, $zero, 0xd
.L802A8CBC:
/* 41DA4C 802A8CBC 0C0A846C */  jal       func_802A11B0
/* 41DA50 802A8CC0 00000000 */   nop
/* 41DA54 802A8CC4 10400379 */  beqz      $v0, .L802A9AAC
/* 41DA58 802A8CC8 24030006 */   addiu    $v1, $zero, 6
/* 41DA5C 802A8CCC 8282004B */  lb        $v0, 0x4b($s4)
/* 41DA60 802A8CD0 A2830178 */  sb        $v1, 0x178($s4)
/* 41DA64 802A8CD4 00021080 */  sll       $v0, $v0, 2
/* 41DA68 802A8CD8 3C01802B */  lui       $at, %hi(D_802AD4B2)
/* 41DA6C 802A8CDC 00220821 */  addu      $at, $at, $v0
/* 41DA70 802A8CE0 9422D4B2 */  lhu       $v0, %lo(D_802AD4B2)($at)
/* 41DA74 802A8CE4 A682017C */  sh        $v0, 0x17c($s4)
/* 41DA78 802A8CE8 00021400 */  sll       $v0, $v0, 0x10
/* 41DA7C 802A8CEC 00021403 */  sra       $v0, $v0, 0x10
/* 41DA80 802A8CF0 00021880 */  sll       $v1, $v0, 2
/* 41DA84 802A8CF4 00621821 */  addu      $v1, $v1, $v0
/* 41DA88 802A8CF8 00031880 */  sll       $v1, $v1, 2
/* 41DA8C 802A8CFC 3C018009 */  lui       $at, %hi(D_8008F064)
/* 41DA90 802A8D00 00230821 */  addu      $at, $at, $v1
/* 41DA94 802A8D04 8C23F064 */  lw        $v1, %lo(D_8008F064)($at)
/* 41DA98 802A8D08 3C02802B */  lui       $v0, %hi(D_802AD603)
/* 41DA9C 802A8D0C 9042D603 */  lbu       $v0, %lo(D_802AD603)($v0)
/* 41DAA0 802A8D10 24040011 */  addiu     $a0, $zero, 0x11
/* 41DAA4 802A8D14 A282005D */  sb        $v0, 0x5d($s4)
/* 41DAA8 802A8D18 2402000E */  addiu     $v0, $zero, 0xe
/* 41DAAC 802A8D1C A682006C */  sh        $v0, 0x6c($s4)
/* 41DAB0 802A8D20 2402000F */  addiu     $v0, $zero, 0xf
/* 41DAB4 802A8D24 A682006E */  sh        $v0, 0x6e($s4)
.L802A8D28:
/* 41DAB8 802A8D28 0C090464 */  jal       func_80241190
/* 41DABC 802A8D2C AE830184 */   sw       $v1, 0x184($s4)
/* 41DAC0 802A8D30 080AA6AB */  j         .L802A9AAC
/* 41DAC4 802A8D34 00000000 */   nop
glabel L802A8D38_41DAC8
/* 41DAC8 802A8D38 0C0A8B21 */  jal       func_802A2C84
/* 41DACC 802A8D3C 00000000 */   nop
/* 41DAD0 802A8D40 0C0A846C */  jal       func_802A11B0
/* 41DAD4 802A8D44 00000000 */   nop
/* 41DAD8 802A8D48 10400358 */  beqz      $v0, .L802A9AAC
/* 41DADC 802A8D4C 2402000B */   addiu    $v0, $zero, 0xb
/* 41DAE0 802A8D50 080AA6A9 */  j         .L802A9AA4
/* 41DAE4 802A8D54 00000000 */   nop
glabel L802A8D58_41DAE8
/* 41DAE8 802A8D58 0C0A8AAE */  jal       func_802A2AB8
/* 41DAEC 802A8D5C 00000000 */   nop
/* 41DAF0 802A8D60 0C0A8426 */  jal       func_802A1098
/* 41DAF4 802A8D64 00000000 */   nop
/* 41DAF8 802A8D68 080AA6A9 */  j         .L802A9AA4
/* 41DAFC 802A8D6C 2402000D */   addiu    $v0, $zero, 0xd
glabel L802A8D70_41DB00
/* 41DB00 802A8D70 0C0A8B21 */  jal       func_802A2C84
/* 41DB04 802A8D74 00000000 */   nop
/* 41DB08 802A8D78 2403FFFF */  addiu     $v1, $zero, -1
/* 41DB0C 802A8D7C 1043034B */  beq       $v0, $v1, .L802A9AAC
/* 41DB10 802A8D80 2402000B */   addiu    $v0, $zero, 0xb
/* 41DB14 802A8D84 080AA6A9 */  j         .L802A9AA4
/* 41DB18 802A8D88 00000000 */   nop
glabel L802A8D8C_41DB1C
/* 41DB1C 802A8D8C 0000802D */  daddu     $s0, $zero, $zero
/* 41DB20 802A8D90 0200882D */  daddu     $s1, $s0, $zero
/* 41DB24 802A8D94 3C098008 */  lui       $t1, %hi(gItemTable)
/* 41DB28 802A8D98 252978E0 */  addiu     $t1, $t1, %lo(gItemTable)
/* 41DB2C 802A8D9C 3C088009 */  lui       $t0, %hi(D_8008A680)
/* 41DB30 802A8DA0 2508A680 */  addiu     $t0, $t0, %lo(D_8008A680)
/* 41DB34 802A8DA4 24070001 */  addiu     $a3, $zero, 1
/* 41DB38 802A8DA8 02E0302D */  daddu     $a2, $s7, $zero
/* 41DB3C 802A8DAC 0240282D */  daddu     $a1, $s2, $zero
.L802A8DB0:
/* 41DB40 802A8DB0 84C201B4 */  lh        $v0, 0x1b4($a2)
/* 41DB44 802A8DB4 50400015 */  beql      $v0, $zero, .L802A8E0C
/* 41DB48 802A8DB8 26310001 */   addiu    $s1, $s1, 1
/* 41DB4C 802A8DBC 00021140 */  sll       $v0, $v0, 5
/* 41DB50 802A8DC0 00492021 */  addu      $a0, $v0, $t1
/* 41DB54 802A8DC4 84820004 */  lh        $v0, 4($a0)
/* 41DB58 802A8DC8 94830018 */  lhu       $v1, 0x18($a0)
/* 41DB5C 802A8DCC 000210C0 */  sll       $v0, $v0, 3
/* 41DB60 802A8DD0 30630002 */  andi      $v1, $v1, 2
/* 41DB64 802A8DD4 1060000C */  beqz      $v1, .L802A8E08
/* 41DB68 802A8DD8 00481021 */   addu     $v0, $v0, $t0
/* 41DB6C 802A8DDC 8C420000 */  lw        $v0, ($v0)
/* 41DB70 802A8DE0 ACA20000 */  sw        $v0, ($a1)
/* 41DB74 802A8DE4 84C201B4 */  lh        $v0, 0x1b4($a2)
/* 41DB78 802A8DE8 ACA7018C */  sw        $a3, 0x18c($a1)
/* 41DB7C 802A8DEC ACA20108 */  sw        $v0, 0x108($a1)
/* 41DB80 802A8DF0 8C820000 */  lw        $v0, ($a0)
/* 41DB84 802A8DF4 ACA20084 */  sw        $v0, 0x84($a1)
/* 41DB88 802A8DF8 8C820014 */  lw        $v0, 0x14($a0)
/* 41DB8C 802A8DFC 26100001 */  addiu     $s0, $s0, 1
/* 41DB90 802A8E00 ACA20294 */  sw        $v0, 0x294($a1)
/* 41DB94 802A8E04 24A50004 */  addiu     $a1, $a1, 4
.L802A8E08:
/* 41DB98 802A8E08 26310001 */  addiu     $s1, $s1, 1
.L802A8E0C:
/* 41DB9C 802A8E0C 2A22000A */  slti      $v0, $s1, 0xa
/* 41DBA0 802A8E10 1440FFE7 */  bnez      $v0, .L802A8DB0
/* 41DBA4 802A8E14 24C60002 */   addiu    $a2, $a2, 2
/* 41DBA8 802A8E18 82820060 */  lb        $v0, 0x60($s4)
/* 41DBAC 802A8E1C 04420001 */  bltzl     $v0, .L802A8E24
/* 41DBB0 802A8E20 A2800060 */   sb       $zero, 0x60($s4)
.L802A8E24:
/* 41DBB4 802A8E24 82910060 */  lb        $s1, 0x60($s4)
/* 41DBB8 802A8E28 0240202D */  daddu     $a0, $s2, $zero
/* 41DBBC 802A8E2C AC800318 */  sw        $zero, 0x318($a0)
/* 41DBC0 802A8E30 AC900324 */  sw        $s0, 0x324($a0)
/* 41DBC4 802A8E34 AC80031C */  sw        $zero, 0x31c($a0)
/* 41DBC8 802A8E38 AC800320 */  sw        $zero, 0x320($a0)
/* 41DBCC 802A8E3C 0C03D44F */  jal       func_800F513C
/* 41DBD0 802A8E40 AC910328 */   sw       $s1, 0x328($a0)
/* 41DBD4 802A8E44 0C03D4AF */  jal       func_800F52BC
/* 41DBD8 802A8E48 00000000 */   nop
/* 41DBDC 802A8E4C 080AA6A9 */  j         .L802A9AA4
/* 41DBE0 802A8E50 24020029 */   addiu    $v0, $zero, 0x29
glabel L802A8E54_41DBE4
/* 41DBE4 802A8E54 8643032C */  lh        $v1, 0x32c($s2)
/* 41DBE8 802A8E58 10600314 */  beqz      $v1, .L802A9AAC
/* 41DBEC 802A8E5C 240200FF */   addiu    $v0, $zero, 0xff
/* 41DBF0 802A8E60 5462000B */  bnel      $v1, $v0, .L802A8E90
/* 41DBF4 802A8E64 2402002C */   addiu    $v0, $zero, 0x2c
/* 41DBF8 802A8E68 0C0A8414 */  jal       func_802A1050
/* 41DBFC 802A8E6C 00000000 */   nop
/* 41DC00 802A8E70 24020008 */  addiu     $v0, $zero, 8
/* 41DC04 802A8E74 3C01802B */  lui       $at, %hi(D_802ACC60)
/* 41DC08 802A8E78 AC22CC60 */  sw        $v0, %lo(D_802ACC60)($at)
/* 41DC0C 802A8E7C 24020004 */  addiu     $v0, $zero, 4
/* 41DC10 802A8E80 3C01802B */  lui       $at, %hi(D_802ACC6C)
/* 41DC14 802A8E84 AC22CC6C */  sw        $v0, %lo(D_802ACC6C)($at)
/* 41DC18 802A8E88 080AA641 */  j         .L802A9904
/* 41DC1C 802A8E8C 24020002 */   addiu    $v0, $zero, 2
.L802A8E90:
/* 41DC20 802A8E90 A682006C */  sh        $v0, 0x6c($s4)
/* 41DC24 802A8E94 8642032C */  lh        $v0, 0x32c($s2)
/* 41DC28 802A8E98 2403002D */  addiu     $v1, $zero, 0x2d
/* 41DC2C 802A8E9C A683006E */  sh        $v1, 0x6e($s4)
/* 41DC30 802A8EA0 2442FFFF */  addiu     $v0, $v0, -1
/* 41DC34 802A8EA4 00021080 */  sll       $v0, $v0, 2
/* 41DC38 802A8EA8 02421021 */  addu      $v0, $s2, $v0
/* 41DC3C 802A8EAC 9442010A */  lhu       $v0, 0x10a($v0)
/* 41DC40 802A8EB0 24030002 */  addiu     $v1, $zero, 2
/* 41DC44 802A8EB4 A2830178 */  sb        $v1, 0x178($s4)
/* 41DC48 802A8EB8 A68201AA */  sh        $v0, 0x1aa($s4)
/* 41DC4C 802A8EBC A682017A */  sh        $v0, 0x17a($s4)
/* 41DC50 802A8EC0 00021400 */  sll       $v0, $v0, 0x10
/* 41DC54 802A8EC4 000212C3 */  sra       $v0, $v0, 0xb
/* 41DC58 802A8EC8 3C038008 */  lui       $v1, %hi(gItemTable+0x8)
/* 41DC5C 802A8ECC 00621821 */  addu      $v1, $v1, $v0
/* 41DC60 802A8ED0 8C6378E8 */  lw        $v1, %lo(gItemTable+0x8)($v1)
/* 41DC64 802A8ED4 9242032D */  lbu       $v0, 0x32d($s2)
/* 41DC68 802A8ED8 AE800188 */  sw        $zero, 0x188($s4)
/* 41DC6C 802A8EDC 2442FFFF */  addiu     $v0, $v0, -1
/* 41DC70 802A8EE0 34638000 */  ori       $v1, $v1, 0x8000
/* 41DC74 802A8EE4 A2820060 */  sb        $v0, 0x60($s4)
/* 41DC78 802A8EE8 0C03C4EC */  jal       func_800F13B0
/* 41DC7C 802A8EEC AE830184 */   sw       $v1, 0x184($s4)
/* 41DC80 802A8EF0 0C0A840C */  jal       func_802A1030
/* 41DC84 802A8EF4 00000000 */   nop
/* 41DC88 802A8EF8 080AA6A9 */  j         .L802A9AA4
/* 41DC8C 802A8EFC 2402002A */   addiu    $v0, $zero, 0x2a
glabel L802A8F00_41DC90
/* 41DC90 802A8F00 8E820214 */  lw        $v0, 0x214($s4)
/* 41DC94 802A8F04 30424000 */  andi      $v0, $v0, 0x4000
/* 41DC98 802A8F08 1040000A */  beqz      $v0, .L802A8F34
/* 41DC9C 802A8F0C 00000000 */   nop
/* 41DCA0 802A8F10 8642032C */  lh        $v0, 0x32c($s2)
/* 41DCA4 802A8F14 14400007 */  bnez      $v0, .L802A8F34
/* 41DCA8 802A8F18 00000000 */   nop
/* 41DCAC 802A8F1C 0C03C5B3 */  jal       func_800F16CC
/* 41DCB0 802A8F20 00000000 */   nop
/* 41DCB4 802A8F24 0C0A8426 */  jal       func_802A1098
/* 41DCB8 802A8F28 00000000 */   nop
/* 41DCBC 802A8F2C 080AA6A9 */  j         .L802A9AA4
/* 41DCC0 802A8F30 2402002B */   addiu    $v0, $zero, 0x2b
.L802A8F34:
/* 41DCC4 802A8F34 0C0A846C */  jal       func_802A11B0
/* 41DCC8 802A8F38 00000000 */   nop
/* 41DCCC 802A8F3C 104002DB */  beqz      $v0, .L802A9AAC
/* 41DCD0 802A8F40 00000000 */   nop
/* 41DCD4 802A8F44 0C090464 */  jal       func_80241190
/* 41DCD8 802A8F48 24040011 */   addiu    $a0, $zero, 0x11
/* 41DCDC 802A8F4C 080AA6AB */  j         .L802A9AAC
/* 41DCE0 802A8F50 00000000 */   nop
glabel L802A8F54_41DCE4
/* 41DCE4 802A8F54 0C0A846C */  jal       func_802A11B0
/* 41DCE8 802A8F58 00000000 */   nop
/* 41DCEC 802A8F5C 104002D3 */  beqz      $v0, .L802A9AAC
/* 41DCF0 802A8F60 24020029 */   addiu    $v0, $zero, 0x29
/* 41DCF4 802A8F64 080AA6A9 */  j         .L802A9AA4
/* 41DCF8 802A8F68 00000000 */   nop
glabel L802A8F6C_41DCFC
/* 41DCFC 802A8F6C 0C03C5B3 */  jal       func_800F16CC
/* 41DD00 802A8F70 00000000 */   nop
/* 41DD04 802A8F74 0C0A8426 */  jal       func_802A1098
/* 41DD08 802A8F78 00000000 */   nop
/* 41DD0C 802A8F7C 080AA6A9 */  j         .L802A9AA4
/* 41DD10 802A8F80 2402002B */   addiu    $v0, $zero, 0x2b
glabel L802A8F84_41DD14
/* 41DD14 802A8F84 0000802D */  daddu     $s0, $zero, $zero
/* 41DD18 802A8F88 24110001 */  addiu     $s1, $zero, 1
/* 41DD1C 802A8F8C 3C0C8009 */  lui       $t4, %hi(D_8008EF20)
/* 41DD20 802A8F90 258CEF20 */  addiu     $t4, $t4, %lo(D_8008EF20)
/* 41DD24 802A8F94 3C0B802B */  lui       $t3, %hi(D_802AB3F8)
/* 41DD28 802A8F98 256BB3F8 */  addiu     $t3, $t3, %lo(D_802AB3F8)
/* 41DD2C 802A8F9C 0220502D */  daddu     $t2, $s1, $zero
/* 41DD30 802A8FA0 3C09802B */  lui       $t1, %hi(D_802AB438)
/* 41DD34 802A8FA4 2529B438 */  addiu     $t1, $t1, %lo(D_802AB438)
/* 41DD38 802A8FA8 3C088009 */  lui       $t0, %hi(D_8008EEC4)
/* 41DD3C 802A8FAC 2508EEC4 */  addiu     $t0, $t0, %lo(D_8008EEC4)
/* 41DD40 802A8FB0 0240202D */  daddu     $a0, $s2, $zero
.L802A8FB4:
/* 41DD44 802A8FB4 8D050000 */  lw        $a1, ($t0)
/* 41DD48 802A8FB8 000510C0 */  sll       $v0, $a1, 3
/* 41DD4C 802A8FBC 02E23021 */  addu      $a2, $s7, $v0
/* 41DD50 802A8FC0 90C20014 */  lbu       $v0, 0x14($a2)
/* 41DD54 802A8FC4 50400019 */  beql      $v0, $zero, .L802A902C
/* 41DD58 802A8FC8 26310001 */   addiu    $s1, $s1, 1
/* 41DD5C 802A8FCC 00051900 */  sll       $v1, $a1, 4
/* 41DD60 802A8FD0 00053880 */  sll       $a3, $a1, 2
/* 41DD64 802A8FD4 00EB1021 */  addu      $v0, $a3, $t3
/* 41DD68 802A8FD8 8C420000 */  lw        $v0, ($v0)
/* 41DD6C 802A8FDC 006C1821 */  addu      $v1, $v1, $t4
/* 41DD70 802A8FE0 AC850108 */  sw        $a1, 0x108($a0)
/* 41DD74 802A8FE4 AC8A018C */  sw        $t2, 0x18c($a0)
/* 41DD78 802A8FE8 AC820000 */  sw        $v0, ($a0)
/* 41DD7C 802A8FEC 8C620000 */  lw        $v0, ($v1)
/* 41DD80 802A8FF0 AC820084 */  sw        $v0, 0x84($a0)
/* 41DD84 802A8FF4 8C62000C */  lw        $v0, 0xc($v1)
/* 41DD88 802A8FF8 AC820294 */  sw        $v0, 0x294($a0)
/* 41DD8C 802A8FFC 80C20015 */  lb        $v0, 0x15($a2)
/* 41DD90 802A9000 AC820210 */  sw        $v0, 0x210($a0)
/* 41DD94 802A9004 82E20012 */  lb        $v0, 0x12($s7)
/* 41DD98 802A9008 54450006 */  bnel      $v0, $a1, .L802A9024
/* 41DD9C 802A900C 24840004 */   addiu    $a0, $a0, 4
/* 41DDA0 802A9010 00E91021 */  addu      $v0, $a3, $t1
/* 41DDA4 802A9014 AC80018C */  sw        $zero, 0x18c($a0)
/* 41DDA8 802A9018 8C420000 */  lw        $v0, ($v0)
/* 41DDAC 802A901C AC820000 */  sw        $v0, ($a0)
/* 41DDB0 802A9020 24840004 */  addiu     $a0, $a0, 4
.L802A9024:
/* 41DDB4 802A9024 26100001 */  addiu     $s0, $s0, 1
/* 41DDB8 802A9028 26310001 */  addiu     $s1, $s1, 1
.L802A902C:
/* 41DDBC 802A902C 2A22000C */  slti      $v0, $s1, 0xc
/* 41DDC0 802A9030 1440FFE0 */  bnez      $v0, .L802A8FB4
/* 41DDC4 802A9034 25080004 */   addiu    $t0, $t0, 4
/* 41DDC8 802A9038 82820061 */  lb        $v0, 0x61($s4)
/* 41DDCC 802A903C 04420001 */  bltzl     $v0, .L802A9044
/* 41DDD0 802A9040 A2800061 */   sb       $zero, 0x61($s4)
.L802A9044:
/* 41DDD4 802A9044 82E30012 */  lb        $v1, 0x12($s7)
/* 41DDD8 802A9048 24020001 */  addiu     $v0, $zero, 1
/* 41DDDC 802A904C AE420318 */  sw        $v0, 0x318($s2)
/* 41DDE0 802A9050 AE500324 */  sw        $s0, 0x324($s2)
/* 41DDE4 802A9054 00031880 */  sll       $v1, $v1, 2
/* 41DDE8 802A9058 3C028009 */  lui       $v0, %hi(D_8008EEF0)
/* 41DDEC 802A905C 00431021 */  addu      $v0, $v0, $v1
/* 41DDF0 802A9060 8C42EEF0 */  lw        $v0, %lo(D_8008EEF0)($v0)
/* 41DDF4 802A9064 0240202D */  daddu     $a0, $s2, $zero
/* 41DDF8 802A9068 AC80031C */  sw        $zero, 0x31c($a0)
/* 41DDFC 802A906C AC800320 */  sw        $zero, 0x320($a0)
/* 41DE00 802A9070 2442FFFF */  addiu     $v0, $v0, -1
/* 41DE04 802A9074 0C03D44F */  jal       func_800F513C
/* 41DE08 802A9078 AC820328 */   sw       $v0, 0x328($a0)
/* 41DE0C 802A907C 0C03D4AF */  jal       func_800F52BC
/* 41DE10 802A9080 00000000 */   nop
/* 41DE14 802A9084 080AA6A9 */  j         .L802A9AA4
/* 41DE18 802A9088 24020033 */   addiu    $v0, $zero, 0x33
glabel L802A908C_41DE1C
/* 41DE1C 802A908C 8643032C */  lh        $v1, 0x32c($s2)
/* 41DE20 802A9090 2402FFFF */  addiu     $v0, $zero, -1
/* 41DE24 802A9094 10620283 */  beq       $v1, $v0, .L802A9AA4
/* 41DE28 802A9098 24020038 */   addiu    $v0, $zero, 0x38
/* 41DE2C 802A909C 10600283 */  beqz      $v1, .L802A9AAC
/* 41DE30 802A90A0 240200FF */   addiu    $v0, $zero, 0xff
/* 41DE34 802A90A4 5462000B */  bnel      $v1, $v0, .L802A90D4
/* 41DE38 802A90A8 24020036 */   addiu    $v0, $zero, 0x36
/* 41DE3C 802A90AC 0C0A8414 */  jal       func_802A1050
/* 41DE40 802A90B0 00000000 */   nop
/* 41DE44 802A90B4 24020008 */  addiu     $v0, $zero, 8
/* 41DE48 802A90B8 3C01802B */  lui       $at, %hi(D_802ACC60)
/* 41DE4C 802A90BC AC22CC60 */  sw        $v0, %lo(D_802ACC60)($at)
/* 41DE50 802A90C0 24020004 */  addiu     $v0, $zero, 4
/* 41DE54 802A90C4 3C01802B */  lui       $at, %hi(D_802ACC6C)
/* 41DE58 802A90C8 AC22CC6C */  sw        $v0, %lo(D_802ACC6C)($at)
/* 41DE5C 802A90CC 080AA641 */  j         .L802A9904
/* 41DE60 802A90D0 24020002 */   addiu    $v0, $zero, 2
.L802A90D4:
/* 41DE64 802A90D4 A682006C */  sh        $v0, 0x6c($s4)
/* 41DE68 802A90D8 8642032C */  lh        $v0, 0x32c($s2)
/* 41DE6C 802A90DC 24030037 */  addiu     $v1, $zero, 0x37
/* 41DE70 802A90E0 A683006E */  sh        $v1, 0x6e($s4)
/* 41DE74 802A90E4 2442FFFF */  addiu     $v0, $v0, -1
/* 41DE78 802A90E8 00021080 */  sll       $v0, $v0, 2
/* 41DE7C 802A90EC 02421021 */  addu      $v0, $s2, $v0
/* 41DE80 802A90F0 9044010B */  lbu       $a0, 0x10b($v0)
/* 41DE84 802A90F4 24020005 */  addiu     $v0, $zero, 5
/* 41DE88 802A90F8 A2820178 */  sb        $v0, 0x178($s4)
/* 41DE8C 802A90FC 24020002 */  addiu     $v0, $zero, 2
/* 41DE90 802A9100 A683017C */  sh        $v1, 0x17c($s4)
/* 41DE94 802A9104 AE820184 */  sw        $v0, 0x184($s4)
/* 41DE98 802A9108 A28401AC */  sb        $a0, 0x1ac($s4)
/* 41DE9C 802A910C 0080182D */  daddu     $v1, $a0, $zero
/* 41DEA0 802A9110 00031E00 */  sll       $v1, $v1, 0x18
/* 41DEA4 802A9114 9242032D */  lbu       $v0, 0x32d($s2)
/* 41DEA8 802A9118 00031E03 */  sra       $v1, $v1, 0x18
/* 41DEAC 802A911C A683017A */  sh        $v1, 0x17a($s4)
/* 41DEB0 802A9120 2442FFFF */  addiu     $v0, $v0, -1
/* 41DEB4 802A9124 0C03C4EC */  jal       func_800F13B0
/* 41DEB8 802A9128 A2820061 */   sb       $v0, 0x61($s4)
/* 41DEBC 802A912C 0C0A840C */  jal       func_802A1030
/* 41DEC0 802A9130 00000000 */   nop
/* 41DEC4 802A9134 080AA6A9 */  j         .L802A9AA4
/* 41DEC8 802A9138 24020034 */   addiu    $v0, $zero, 0x34
glabel L802A913C_41DECC
/* 41DECC 802A913C 8E820214 */  lw        $v0, 0x214($s4)
/* 41DED0 802A9140 30424000 */  andi      $v0, $v0, 0x4000
/* 41DED4 802A9144 10400224 */  beqz      $v0, .L802A99D8
/* 41DED8 802A9148 00000000 */   nop
/* 41DEDC 802A914C 8642032C */  lh        $v0, 0x32c($s2)
/* 41DEE0 802A9150 14400221 */  bnez      $v0, .L802A99D8
/* 41DEE4 802A9154 00000000 */   nop
/* 41DEE8 802A9158 0C03C5B3 */  jal       func_800F16CC
/* 41DEEC 802A915C 00000000 */   nop
/* 41DEF0 802A9160 0C0A8426 */  jal       func_802A1098
/* 41DEF4 802A9164 00000000 */   nop
/* 41DEF8 802A9168 080AA6A9 */  j         .L802A9AA4
/* 41DEFC 802A916C 24020035 */   addiu    $v0, $zero, 0x35
glabel L802A9170_41DF00
/* 41DF00 802A9170 0C0A846C */  jal       func_802A11B0
/* 41DF04 802A9174 00000000 */   nop
/* 41DF08 802A9178 1040024C */  beqz      $v0, .L802A9AAC
/* 41DF0C 802A917C 24020033 */   addiu    $v0, $zero, 0x33
/* 41DF10 802A9180 080AA6A9 */  j         .L802A9AA4
/* 41DF14 802A9184 00000000 */   nop
glabel L802A9188_41DF18
/* 41DF18 802A9188 0C03C5B3 */  jal       func_800F16CC
/* 41DF1C 802A918C 00000000 */   nop
/* 41DF20 802A9190 0C0A8426 */  jal       func_802A1098
/* 41DF24 802A9194 00000000 */   nop
/* 41DF28 802A9198 080AA6A9 */  j         .L802A9AA4
/* 41DF2C 802A919C 24020035 */   addiu    $v0, $zero, 0x35
glabel L802A91A0_41DF30
/* 41DF30 802A91A0 0C03C54E */  jal       func_800F1538
/* 41DF34 802A91A4 00000000 */   nop
.L802A91A8:
glabel L802A91A8_41DF38
/* 41DF38 802A91A8 0C0A842E */  jal       func_802A10B8
/* 41DF3C 802A91AC 00000000 */   nop
/* 41DF40 802A91B0 080AA6AB */  j         .L802A9AAC
/* 41DF44 802A91B4 00000000 */   nop
glabel L802A91B8_41DF48
/* 41DF48 802A91B8 8643032C */  lh        $v1, 0x32c($s2)
/* 41DF4C 802A91BC 2402FFFF */  addiu     $v0, $zero, -1
/* 41DF50 802A91C0 1062023A */  beq       $v1, $v0, .L802A9AAC
/* 41DF54 802A91C4 24020033 */   addiu    $v0, $zero, 0x33
/* 41DF58 802A91C8 080AA6A9 */  j         .L802A9AA4
/* 41DF5C 802A91CC 00000000 */   nop
glabel L802A91D0_41DF60
/* 41DF60 802A91D0 24100001 */  addiu     $s0, $zero, 1
/* 41DF64 802A91D4 0000882D */  daddu     $s1, $zero, $zero
/* 41DF68 802A91D8 24020077 */  addiu     $v0, $zero, 0x77
/* 41DF6C 802A91DC A28201DE */  sb        $v0, 0x1de($s4)
/* 41DF70 802A91E0 24020155 */  addiu     $v0, $zero, 0x155
/* 41DF74 802A91E4 A290020E */  sb        $s0, 0x20e($s4)
/* 41DF78 802A91E8 320300FF */  andi      $v1, $s0, 0xff
/* 41DF7C 802A91EC A68201AE */  sh        $v0, 0x1ae($s4)
/* 41DF80 802A91F0 0200102D */  daddu     $v0, $s0, $zero
/* 41DF84 802A91F4 10600049 */  beqz      $v1, .L802A931C
/* 41DF88 802A91F8 A28201F6 */   sb       $v0, 0x1f6($s4)
/* 41DF8C 802A91FC 3C128009 */  lui       $s2, %hi(D_8008F060)
/* 41DF90 802A9200 2652F060 */  addiu     $s2, $s2, %lo(D_8008F060)
/* 41DF94 802A9204 3C0F802B */  lui       $t7, %hi(D_802AB398)
/* 41DF98 802A9208 25EFB398 */  addiu     $t7, $t7, %lo(D_802AB398)
/* 41DF9C 802A920C 3C10802B */  lui       $s0, %hi(D_802AD5D0)
/* 41DFA0 802A9210 2610D5D0 */  addiu     $s0, $s0, %lo(D_802AD5D0)
/* 41DFA4 802A9214 3C0E802B */  lui       $t6, %hi(D_802AD3E0)
/* 41DFA8 802A9218 25CED3E0 */  addiu     $t6, $t6, %lo(D_802AD3E0)
/* 41DFAC 802A921C 3C0D802B */  lui       $t5, %hi(D_802AD380)
/* 41DFB0 802A9220 25ADD380 */  addiu     $t5, $t5, %lo(D_802AD380)
/* 41DFB4 802A9224 3C0C802B */  lui       $t4, %hi(D_802AD570)
/* 41DFB8 802A9228 258CD570 */  addiu     $t4, $t4, %lo(D_802AD570)
/* 41DFBC 802A922C 3C0B802B */  lui       $t3, %hi(D_802AD2C0)
/* 41DFC0 802A9230 256BD2C0 */  addiu     $t3, $t3, %lo(D_802AD2C0)
/* 41DFC4 802A9234 3C0A802B */  lui       $t2, %hi(D_802AD510)
/* 41DFC8 802A9238 254AD510 */  addiu     $t2, $t2, %lo(D_802AD510)
/* 41DFCC 802A923C 3C09802B */  lui       $t1, %hi(D_802AD4B0)
/* 41DFD0 802A9240 2529D4B0 */  addiu     $t1, $t1, %lo(D_802AD4B0)
/* 41DFD4 802A9244 3C08802B */  lui       $t0, %hi(D_802AD440)
/* 41DFD8 802A9248 2508D440 */  addiu     $t0, $t0, %lo(D_802AD440)
/* 41DFDC 802A924C 3C06802B */  lui       $a2, %hi(D_802AD320)
/* 41DFE0 802A9250 24C6D320 */  addiu     $a2, $a2, %lo(D_802AD320)
/* 41DFE4 802A9254 3C05802B */  lui       $a1, %hi(D_802AD260)
/* 41DFE8 802A9258 24A5D260 */  addiu     $a1, $a1, %lo(D_802AD260)
.L802A925C:
/* 41DFEC 802A925C 02912021 */  addu      $a0, $s4, $s1
/* 41DFF0 802A9260 908301DE */  lbu       $v1, 0x1de($a0)
/* 41DFF4 802A9264 2462FF89 */  addiu     $v0, $v1, -0x77
/* 41DFF8 802A9268 000210C0 */  sll       $v0, $v0, 3
/* 41DFFC 802A926C 004F1021 */  addu      $v0, $v0, $t7
/* 41E000 802A9270 8C420000 */  lw        $v0, ($v0)
/* 41E004 802A9274 ACA20000 */  sw        $v0, ($a1)
/* 41E008 802A9278 00031080 */  sll       $v0, $v1, 2
/* 41E00C 802A927C 00431021 */  addu      $v0, $v0, $v1
/* 41E010 802A9280 00021080 */  sll       $v0, $v0, 2
/* 41E014 802A9284 808301F6 */  lb        $v1, 0x1f6($a0)
/* 41E018 802A9288 14600008 */  bnez      $v1, .L802A92AC
/* 41E01C 802A928C 00523821 */   addu     $a3, $v0, $s2
/* 41E020 802A9290 908201DE */  lbu       $v0, 0x1de($a0)
/* 41E024 802A9294 2442FF89 */  addiu     $v0, $v0, -0x77
/* 41E028 802A9298 000210C0 */  sll       $v0, $v0, 3
/* 41E02C 802A929C 34420004 */  ori       $v0, $v0, 4
/* 41E030 802A92A0 004F1021 */  addu      $v0, $v0, $t7
/* 41E034 802A92A4 8C420000 */  lw        $v0, ($v0)
/* 41E038 802A92A8 ACA20000 */  sw        $v0, ($a1)
.L802A92AC:
/* 41E03C 802A92AC 80E20011 */  lb        $v0, 0x11($a3)
/* 41E040 802A92B0 24A50004 */  addiu     $a1, $a1, 4
/* 41E044 802A92B4 ACC20000 */  sw        $v0, ($a2)
/* 41E048 802A92B8 80E20012 */  lb        $v0, 0x12($a3)
/* 41E04C 802A92BC 24C60004 */  addiu     $a2, $a2, 4
/* 41E050 802A92C0 AD020000 */  sw        $v0, ($t0)
/* 41E054 802A92C4 AD310000 */  sw        $s1, ($t1)
/* 41E058 802A92C8 25290004 */  addiu     $t1, $t1, 4
/* 41E05C 802A92CC 25080004 */  addiu     $t0, $t0, 4
/* 41E060 802A92D0 02301021 */  addu      $v0, $s1, $s0
/* 41E064 802A92D4 A0510000 */  sb        $s1, ($v0)
/* 41E068 802A92D8 808201F6 */  lb        $v0, 0x1f6($a0)
/* 41E06C 802A92DC 26310001 */  addiu     $s1, $s1, 1
/* 41E070 802A92E0 AD420000 */  sw        $v0, ($t2)
/* 41E074 802A92E4 8CE20000 */  lw        $v0, ($a3)
/* 41E078 802A92E8 254A0004 */  addiu     $t2, $t2, 4
/* 41E07C 802A92EC AD620000 */  sw        $v0, ($t3)
/* 41E080 802A92F0 8CE20008 */  lw        $v0, 8($a3)
/* 41E084 802A92F4 256B0004 */  addiu     $t3, $t3, 4
/* 41E088 802A92F8 AD820000 */  sw        $v0, ($t4)
/* 41E08C 802A92FC ADA00000 */  sw        $zero, ($t5)
/* 41E090 802A9300 ADC00000 */  sw        $zero, ($t6)
/* 41E094 802A9304 25CE0004 */  addiu     $t6, $t6, 4
/* 41E098 802A9308 25AD0004 */  addiu     $t5, $t5, 4
/* 41E09C 802A930C 9282020E */  lbu       $v0, 0x20e($s4)
/* 41E0A0 802A9310 0222102A */  slt       $v0, $s1, $v0
/* 41E0A4 802A9314 1440FFD1 */  bnez      $v0, .L802A925C
/* 41E0A8 802A9318 258C0004 */   addiu    $t4, $t4, 4
.L802A931C:
/* 41E0AC 802A931C 82820062 */  lb        $v0, 0x62($s4)
/* 41E0B0 802A9320 04420001 */  bltzl     $v0, .L802A9328
/* 41E0B4 802A9324 A2800062 */   sb       $zero, 0x62($s4)
.L802A9328:
/* 41E0B8 802A9328 82910062 */  lb        $s1, 0x62($s4)
/* 41E0BC 802A932C 9282020E */  lbu       $v0, 0x20e($s4)
/* 41E0C0 802A9330 24030001 */  addiu     $v1, $zero, 1
/* 41E0C4 802A9334 3C01802B */  lui       $at, %hi(D_802AD4A0)
/* 41E0C8 802A9338 AC23D4A0 */  sw        $v1, %lo(D_802AD4A0)($at)
/* 41E0CC 802A933C 3C01802B */  lui       $at, %hi(D_802AD4A4)
/* 41E0D0 802A9340 AC22D4A4 */  sw        $v0, %lo(D_802AD4A4)($at)
/* 41E0D4 802A9344 3C01802B */  lui       $at, %hi(D_802AD4A8)
/* 41E0D8 802A9348 AC31D4A8 */  sw        $s1, %lo(D_802AD4A8)($at)
/* 41E0DC 802A934C 0C0A89A1 */  jal       func_802A2684
/* 41E0E0 802A9350 00000000 */   nop
/* 41E0E4 802A9354 080AA6A9 */  j         .L802A9AA4
/* 41E0E8 802A9358 2402003D */   addiu    $v0, $zero, 0x3d
glabel L802A935C_41E0EC
/* 41E0EC 802A935C 0C0A8B21 */  jal       func_802A2C84
/* 41E0F0 802A9360 00000000 */   nop
/* 41E0F4 802A9364 0040802D */  daddu     $s0, $v0, $zero
/* 41E0F8 802A9368 120001D0 */  beqz      $s0, .L802A9AAC
/* 41E0FC 802A936C 240200FF */   addiu    $v0, $zero, 0xff
/* 41E100 802A9370 5602000B */  bnel      $s0, $v0, .L802A93A0
/* 41E104 802A9374 2602FFFF */   addiu    $v0, $s0, -1
/* 41E108 802A9378 0C0A8414 */  jal       func_802A1050
/* 41E10C 802A937C 00000000 */   nop
/* 41E110 802A9380 24020008 */  addiu     $v0, $zero, 8
/* 41E114 802A9384 3C01802B */  lui       $at, %hi(D_802ACC60)
/* 41E118 802A9388 AC22CC60 */  sw        $v0, %lo(D_802ACC60)($at)
/* 41E11C 802A938C 24020004 */  addiu     $v0, $zero, 4
/* 41E120 802A9390 3C01802B */  lui       $at, %hi(D_802ACC6C)
/* 41E124 802A9394 AC22CC6C */  sw        $v0, %lo(D_802ACC6C)($at)
/* 41E128 802A9398 080AA641 */  j         .L802A9904
/* 41E12C 802A939C 24020002 */   addiu    $v0, $zero, 2
.L802A93A0:
/* 41E130 802A93A0 00021080 */  sll       $v0, $v0, 2
/* 41E134 802A93A4 3C01802B */  lui       $at, %hi(D_802AD4B3)
/* 41E138 802A93A8 00220821 */  addu      $at, $at, $v0
/* 41E13C 802A93AC 9022D4B3 */  lbu       $v0, %lo(D_802AD4B3)($at)
/* 41E140 802A93B0 0C0A89F4 */  jal       func_802A27D0
/* 41E144 802A93B4 A282004B */   sb       $v0, 0x4b($s4)
/* 41E148 802A93B8 0C0A840C */  jal       func_802A1030
/* 41E14C 802A93BC 00000000 */   nop
/* 41E150 802A93C0 080AA6A9 */  j         .L802A9AA4
/* 41E154 802A93C4 2402003E */   addiu    $v0, $zero, 0x3e
glabel L802A93C8_41E158
/* 41E158 802A93C8 0C0A8B21 */  jal       func_802A2C84
/* 41E15C 802A93CC 00000000 */   nop
/* 41E160 802A93D0 8E830214 */  lw        $v1, 0x214($s4)
/* 41E164 802A93D4 30634000 */  andi      $v1, $v1, 0x4000
/* 41E168 802A93D8 10600009 */  beqz      $v1, .L802A9400
/* 41E16C 802A93DC 0040802D */   daddu    $s0, $v0, $zero
/* 41E170 802A93E0 16000007 */  bnez      $s0, .L802A9400
/* 41E174 802A93E4 00000000 */   nop
/* 41E178 802A93E8 0C0A8AAE */  jal       func_802A2AB8
/* 41E17C 802A93EC 00000000 */   nop
/* 41E180 802A93F0 0C0A8426 */  jal       func_802A1098
/* 41E184 802A93F4 00000000 */   nop
/* 41E188 802A93F8 080AA6A9 */  j         .L802A9AA4
/* 41E18C 802A93FC 2402003F */   addiu    $v0, $zero, 0x3f
.L802A9400:
/* 41E190 802A9400 0C0A846C */  jal       func_802A11B0
/* 41E194 802A9404 00000000 */   nop
/* 41E198 802A9408 104001A8 */  beqz      $v0, .L802A9AAC
/* 41E19C 802A940C 24020040 */   addiu    $v0, $zero, 0x40
/* 41E1A0 802A9410 A682006C */  sh        $v0, 0x6c($s4)
/* 41E1A4 802A9414 24020041 */  addiu     $v0, $zero, 0x41
/* 41E1A8 802A9418 A682006E */  sh        $v0, 0x6e($s4)
/* 41E1AC 802A941C 8282004B */  lb        $v0, 0x4b($s4)
/* 41E1B0 802A9420 24030008 */  addiu     $v1, $zero, 8
/* 41E1B4 802A9424 A2830178 */  sb        $v1, 0x178($s4)
/* 41E1B8 802A9428 02821021 */  addu      $v0, $s4, $v0
/* 41E1BC 802A942C 904301DE */  lbu       $v1, 0x1de($v0)
/* 41E1C0 802A9430 8282004B */  lb        $v0, 0x4b($s4)
/* 41E1C4 802A9434 02821021 */  addu      $v0, $s4, $v0
/* 41E1C8 802A9438 A683017C */  sh        $v1, 0x17c($s4)
/* 41E1CC 802A943C 904301DE */  lbu       $v1, 0x1de($v0)
/* 41E1D0 802A9440 24040011 */  addiu     $a0, $zero, 0x11
/* 41E1D4 802A9444 00031080 */  sll       $v0, $v1, 2
/* 41E1D8 802A9448 00431021 */  addu      $v0, $v0, $v1
/* 41E1DC 802A944C 00021080 */  sll       $v0, $v0, 2
/* 41E1E0 802A9450 9283004B */  lbu       $v1, 0x4b($s4)
/* 41E1E4 802A9454 3C058009 */  lui       $a1, %hi(D_8008F064)
/* 41E1E8 802A9458 00A22821 */  addu      $a1, $a1, $v0
/* 41E1EC 802A945C 8CA5F064 */  lw        $a1, %lo(D_8008F064)($a1)
/* 41E1F0 802A9460 3C02802B */  lui       $v0, %hi(D_802AD603)
/* 41E1F4 802A9464 9042D603 */  lbu       $v0, %lo(D_802AD603)($v0)
/* 41E1F8 802A9468 00031E00 */  sll       $v1, $v1, 0x18
/* 41E1FC 802A946C 00031E03 */  sra       $v1, $v1, 0x18
/* 41E200 802A9470 A683017A */  sh        $v1, 0x17a($s4)
/* 41E204 802A9474 A2820062 */  sb        $v0, 0x62($s4)
/* 41E208 802A9478 0C090464 */  jal       func_80241190
/* 41E20C 802A947C AE850184 */   sw       $a1, 0x184($s4)
/* 41E210 802A9480 080AA6AB */  j         .L802A9AAC
/* 41E214 802A9484 00000000 */   nop
glabel L802A9488_41E218
/* 41E218 802A9488 0C0A8B21 */  jal       func_802A2C84
/* 41E21C 802A948C 00000000 */   nop
/* 41E220 802A9490 0C0A846C */  jal       func_802A11B0
/* 41E224 802A9494 00000000 */   nop
/* 41E228 802A9498 10400184 */  beqz      $v0, .L802A9AAC
/* 41E22C 802A949C 2402003D */   addiu    $v0, $zero, 0x3d
/* 41E230 802A94A0 080AA6A9 */  j         .L802A9AA4
/* 41E234 802A94A4 00000000 */   nop
glabel L802A94A8_41E238
/* 41E238 802A94A8 0C0A8AAE */  jal       func_802A2AB8
/* 41E23C 802A94AC 00000000 */   nop
/* 41E240 802A94B0 0C0A8426 */  jal       func_802A1098
/* 41E244 802A94B4 00000000 */   nop
/* 41E248 802A94B8 080AA6A9 */  j         .L802A9AA4
/* 41E24C 802A94BC 2402003F */   addiu    $v0, $zero, 0x3f
glabel L802A94C0_41E250
/* 41E250 802A94C0 0C0A89F9 */  jal       func_802A27E4
/* 41E254 802A94C4 00000000 */   nop
/* 41E258 802A94C8 080AA46A */  j         .L802A91A8
/* 41E25C 802A94CC 00000000 */   nop
glabel L802A94D0_41E260
/* 41E260 802A94D0 0C098C9A */  jal       func_80263268
/* 41E264 802A94D4 0000802D */   daddu    $s0, $zero, $zero
/* 41E268 802A94D8 8282007C */  lb        $v0, 0x7c($s4)
/* 41E26C 802A94DC 04400023 */  bltz      $v0, .L802A956C
/* 41E270 802A94E0 3C05001D */   lui      $a1, 0x1d
/* 41E274 802A94E4 34A500A1 */  ori       $a1, $a1, 0xa1
/* 41E278 802A94E8 24020005 */  addiu     $v0, $zero, 5
/* 41E27C 802A94EC 3C04802B */  lui       $a0, %hi(D_802AB4A4)
/* 41E280 802A94F0 8C84B4A4 */  lw        $a0, %lo(D_802AB4A4)($a0)
/* 41E284 802A94F4 82E30012 */  lb        $v1, 0x12($s7)
/* 41E288 802A94F8 3C06802B */  lui       $a2, %hi(D_802AD690)
/* 41E28C 802A94FC 24C6D690 */  addiu     $a2, $a2, %lo(D_802AD690)
/* 41E290 802A9500 3C01802B */  lui       $at, %hi(D_802AD678)
/* 41E294 802A9504 AC22D678 */  sw        $v0, %lo(D_802AD678)($at)
/* 41E298 802A9508 00031880 */  sll       $v1, $v1, 2
/* 41E29C 802A950C 3C01802B */  lui       $at, %hi(D_802AD658)
/* 41E2A0 802A9510 AC24D658 */  sw        $a0, %lo(D_802AD658)($at)
/* 41E2A4 802A9514 3C01802B */  lui       $at, %hi(D_802AB3F8)
/* 41E2A8 802A9518 00230821 */  addu      $at, $at, $v1
/* 41E2AC 802A951C 8C23B3F8 */  lw        $v1, %lo(D_802AB3F8)($at)
/* 41E2B0 802A9520 24020001 */  addiu     $v0, $zero, 1
/* 41E2B4 802A9524 ACC20000 */  sw        $v0, ($a2)
/* 41E2B8 802A9528 3C01802B */  lui       $at, %hi(D_802AD6C0)
/* 41E2BC 802A952C AC25D6C0 */  sw        $a1, %lo(D_802AD6C0)($at)
/* 41E2C0 802A9530 8282007C */  lb        $v0, 0x7c($s4)
/* 41E2C4 802A9534 3C04802B */  lui       $a0, %hi(D_802AD640)
/* 41E2C8 802A9538 2484D640 */  addiu     $a0, $a0, %lo(D_802AD640)
/* 41E2CC 802A953C 1C40000A */  bgtz      $v0, .L802A9568
/* 41E2D0 802A9540 AC830000 */   sw       $v1, ($a0)
/* 41E2D4 802A9544 82E20012 */  lb        $v0, 0x12($s7)
/* 41E2D8 802A9548 00021080 */  sll       $v0, $v0, 2
/* 41E2DC 802A954C 3C01802B */  lui       $at, %hi(D_802AB438)
/* 41E2E0 802A9550 00220821 */  addu      $at, $at, $v0
/* 41E2E4 802A9554 8C22B438 */  lw        $v0, %lo(D_802AB438)($at)
/* 41E2E8 802A9558 ACC00000 */  sw        $zero, ($a2)
/* 41E2EC 802A955C 3C01802B */  lui       $at, %hi(D_802AD6A8)
/* 41E2F0 802A9560 AC20D6A8 */  sw        $zero, %lo(D_802AD6A8)($at)
/* 41E2F4 802A9564 AC820000 */  sw        $v0, ($a0)
.L802A9568:
/* 41E2F8 802A9568 24100001 */  addiu     $s0, $zero, 1
.L802A956C:
/* 41E2FC 802A956C 3C05001D */  lui       $a1, 0x1d
/* 41E300 802A9570 00101880 */  sll       $v1, $s0, 2
/* 41E304 802A9574 3C04802B */  lui       $a0, %hi(D_802AB480)
/* 41E308 802A9578 8C84B480 */  lw        $a0, %lo(D_802AB480)($a0)
/* 41E30C 802A957C 24020009 */  addiu     $v0, $zero, 9
/* 41E310 802A9580 3C01802B */  lui       $at, %hi(D_802AD678)
/* 41E314 802A9584 00230821 */  addu      $at, $at, $v1
/* 41E318 802A9588 AC22D678 */  sw        $v0, %lo(D_802AD678)($at)
/* 41E31C 802A958C 24020001 */  addiu     $v0, $zero, 1
/* 41E320 802A9590 3C01802B */  lui       $at, %hi(D_802AD690)
/* 41E324 802A9594 00230821 */  addu      $at, $at, $v1
/* 41E328 802A9598 AC22D690 */  sw        $v0, %lo(D_802AD690)($at)
/* 41E32C 802A959C 3C01802B */  lui       $at, %hi(D_802AD640)
/* 41E330 802A95A0 00230821 */  addu      $at, $at, $v1
/* 41E334 802A95A4 AC24D640 */  sw        $a0, %lo(D_802AD640)($at)
/* 41E338 802A95A8 3C02802B */  lui       $v0, %hi(D_802AB4B4)
/* 41E33C 802A95AC 8C42B4B4 */  lw        $v0, %lo(D_802AB4B4)($v0)
/* 41E340 802A95B0 34A500A2 */  ori       $a1, $a1, 0xa2
/* 41E344 802A95B4 3C01802B */  lui       $at, %hi(D_802AD6C0)
/* 41E348 802A95B8 00230821 */  addu      $at, $at, $v1
/* 41E34C 802A95BC AC25D6C0 */  sw        $a1, %lo(D_802AD6C0)($at)
/* 41E350 802A95C0 3C01802B */  lui       $at, %hi(D_802AD658)
/* 41E354 802A95C4 00230821 */  addu      $at, $at, $v1
/* 41E358 802A95C8 AC22D658 */  sw        $v0, %lo(D_802AD658)($at)
/* 41E35C 802A95CC 82820063 */  lb        $v0, 0x63($s4)
/* 41E360 802A95D0 04410002 */  bgez      $v0, .L802A95DC
/* 41E364 802A95D4 26100001 */   addiu    $s0, $s0, 1
/* 41E368 802A95D8 A2800063 */  sb        $zero, 0x63($s4)
.L802A95DC:
/* 41E36C 802A95DC 82910063 */  lb        $s1, 0x63($s4)
/* 41E370 802A95E0 3C01802B */  lui       $at, %hi(D_802AD66C)
/* 41E374 802A95E4 AC30D66C */  sw        $s0, %lo(D_802AD66C)($at)
/* 41E378 802A95E8 3C01802B */  lui       $at, %hi(D_802AD670)
/* 41E37C 802A95EC AC31D670 */  sw        $s1, %lo(D_802AD670)($at)
/* 41E380 802A95F0 0C0A9176 */  jal       func_802A45D8
/* 41E384 802A95F4 00000000 */   nop
/* 41E388 802A95F8 080AA6A9 */  j         .L802A9AA4
/* 41E38C 802A95FC 240200C9 */   addiu    $v0, $zero, 0xc9
glabel L802A9600_41E390
/* 41E390 802A9600 0C0A9295 */  jal       func_802A4A54
/* 41E394 802A9604 00000000 */   nop
/* 41E398 802A9608 0040802D */  daddu     $s0, $v0, $zero
/* 41E39C 802A960C 12000127 */  beqz      $s0, .L802A9AAC
/* 41E3A0 802A9610 240200FF */   addiu    $v0, $zero, 0xff
/* 41E3A4 802A9614 1602000B */  bne       $s0, $v0, .L802A9644
/* 41E3A8 802A9618 2603FFFF */   addiu    $v1, $s0, -1
/* 41E3AC 802A961C 0C0A8414 */  jal       func_802A1050
/* 41E3B0 802A9620 00000000 */   nop
/* 41E3B4 802A9624 24020008 */  addiu     $v0, $zero, 8
/* 41E3B8 802A9628 3C01802B */  lui       $at, %hi(D_802ACC60)
/* 41E3BC 802A962C AC22CC60 */  sw        $v0, %lo(D_802ACC60)($at)
/* 41E3C0 802A9630 24020004 */  addiu     $v0, $zero, 4
/* 41E3C4 802A9634 3C01802B */  lui       $at, %hi(D_802ACC6C)
/* 41E3C8 802A9638 AC22CC6C */  sw        $v0, %lo(D_802ACC6C)($at)
/* 41E3CC 802A963C 080AA641 */  j         .L802A9904
/* 41E3D0 802A9640 24020002 */   addiu    $v0, $zero, 2
.L802A9644:
/* 41E3D4 802A9644 00031080 */  sll       $v0, $v1, 2
/* 41E3D8 802A9648 3C01802B */  lui       $at, %hi(D_802AD67B)
/* 41E3DC 802A964C 00220821 */  addu      $at, $at, $v0
/* 41E3E0 802A9650 9022D67B */  lbu       $v0, %lo(D_802AD67B)($at)
/* 41E3E4 802A9654 A2830063 */  sb        $v1, 0x63($s4)
/* 41E3E8 802A9658 A282004A */  sb        $v0, 0x4a($s4)
/* 41E3EC 802A965C 8283004A */  lb        $v1, 0x4a($s4)
/* 41E3F0 802A9660 24020005 */  addiu     $v0, $zero, 5
/* 41E3F4 802A9664 106200A7 */  beq       $v1, $v0, .L802A9904
/* 41E3F8 802A9668 2402001E */   addiu    $v0, $zero, 0x1e
/* 41E3FC 802A966C 0C0A91C6 */  jal       func_802A4718
/* 41E400 802A9670 00000000 */   nop
/* 41E404 802A9674 0C0A840C */  jal       func_802A1030
/* 41E408 802A9678 00000000 */   nop
/* 41E40C 802A967C 080AA6A9 */  j         .L802A9AA4
/* 41E410 802A9680 240200CA */   addiu    $v0, $zero, 0xca
glabel L802A9684_41E414
/* 41E414 802A9684 0C0A9295 */  jal       func_802A4A54
/* 41E418 802A9688 00000000 */   nop
/* 41E41C 802A968C 8E830214 */  lw        $v1, 0x214($s4)
/* 41E420 802A9690 30634000 */  andi      $v1, $v1, 0x4000
/* 41E424 802A9694 10600009 */  beqz      $v1, .L802A96BC
/* 41E428 802A9698 0040802D */   daddu    $s0, $v0, $zero
/* 41E42C 802A969C 16000007 */  bnez      $s0, .L802A96BC
/* 41E430 802A96A0 00000000 */   nop
/* 41E434 802A96A4 0C0A923F */  jal       func_802A48FC
/* 41E438 802A96A8 00000000 */   nop
/* 41E43C 802A96AC 0C0A8426 */  jal       func_802A1098
/* 41E440 802A96B0 00000000 */   nop
/* 41E444 802A96B4 080AA6A9 */  j         .L802A9AA4
/* 41E448 802A96B8 240200CB */   addiu    $v0, $zero, 0xcb
.L802A96BC:
/* 41E44C 802A96BC 0C0A846C */  jal       func_802A11B0
/* 41E450 802A96C0 00000000 */   nop
/* 41E454 802A96C4 104000F9 */  beqz      $v0, .L802A9AAC
/* 41E458 802A96C8 240200CC */   addiu    $v0, $zero, 0xcc
/* 41E45C 802A96CC 8290004A */  lb        $s0, 0x4a($s4)
/* 41E460 802A96D0 A682006C */  sh        $v0, 0x6c($s4)
/* 41E464 802A96D4 240200CD */  addiu     $v0, $zero, 0xcd
/* 41E468 802A96D8 A682006E */  sh        $v0, 0x6e($s4)
/* 41E46C 802A96DC 24020009 */  addiu     $v0, $zero, 9
/* 41E470 802A96E0 1202000C */  beq       $s0, $v0, .L802A9714
/* 41E474 802A96E4 2A02000A */   slti     $v0, $s0, 0xa
/* 41E478 802A96E8 10400005 */  beqz      $v0, .L802A9700
/* 41E47C 802A96EC 24020003 */   addiu    $v0, $zero, 3
/* 41E480 802A96F0 12020011 */  beq       $s0, $v0, .L802A9738
/* 41E484 802A96F4 240200CD */   addiu    $v0, $zero, 0xcd
/* 41E488 802A96F8 080AA6AB */  j         .L802A9AAC
/* 41E48C 802A96FC 00000000 */   nop
.L802A9700:
/* 41E490 802A9700 2402000A */  addiu     $v0, $zero, 0xa
/* 41E494 802A9704 12020017 */  beq       $s0, $v0, .L802A9764
/* 41E498 802A9708 240200CD */   addiu    $v0, $zero, 0xcd
/* 41E49C 802A970C 080AA6AB */  j         .L802A9AAC
/* 41E4A0 802A9710 00000000 */   nop
.L802A9714:
/* 41E4A4 802A9714 240200CD */  addiu     $v0, $zero, 0xcd
/* 41E4A8 802A9718 3C01800E */  lui       $at, %hi(gBattleStatus+0x46C)
/* 41E4AC 802A971C AC22C4DC */  sw        $v0, %lo(gBattleStatus+0x46C)($at)
/* 41E4B0 802A9720 0C0AA072 */  jal       update_partner_menu
/* 41E4B4 802A9724 00000000 */   nop
/* 41E4B8 802A9728 0C090464 */  jal       func_80241190
/* 41E4BC 802A972C 24040017 */   addiu    $a0, $zero, 0x17
/* 41E4C0 802A9730 080AA6AB */  j         .L802A9AAC
/* 41E4C4 802A9734 00000000 */   nop
.L802A9738:
/* 41E4C8 802A9738 3C01800E */  lui       $at, %hi(gBattleStatus+0x46C)
/* 41E4CC 802A973C AC22C4DC */  sw        $v0, %lo(gBattleStatus+0x46C)($at)
/* 41E4D0 802A9740 0C0AA072 */  jal       update_partner_menu
/* 41E4D4 802A9744 00000000 */   nop
/* 41E4D8 802A9748 24040018 */  addiu     $a0, $zero, 0x18
/* 41E4DC 802A974C 24020039 */  addiu     $v0, $zero, 0x39
/* 41E4E0 802A9750 A2900178 */  sb        $s0, 0x178($s4)
/* 41E4E4 802A9754 0C090464 */  jal       func_80241190
/* 41E4E8 802A9758 A682017C */   sh       $v0, 0x17c($s4)
/* 41E4EC 802A975C 080AA6AB */  j         .L802A9AAC
/* 41E4F0 802A9760 00000000 */   nop
.L802A9764:
/* 41E4F4 802A9764 3C01800E */  lui       $at, %hi(gBattleStatus+0x46C)
/* 41E4F8 802A9768 AC22C4DC */  sw        $v0, %lo(gBattleStatus+0x46C)($at)
/* 41E4FC 802A976C 0C0AA072 */  jal       update_partner_menu
/* 41E500 802A9770 00000000 */   nop
.L802A9774:
/* 41E504 802A9774 0C090464 */  jal       func_80241190
/* 41E508 802A9778 2404000A */   addiu    $a0, $zero, 0xa
/* 41E50C 802A977C 080AA6AB */  j         .L802A9AAC
/* 41E510 802A9780 00000000 */   nop
glabel L802A9784_41E514
/* 41E514 802A9784 0C0A9295 */  jal       func_802A4A54
/* 41E518 802A9788 00000000 */   nop
/* 41E51C 802A978C 0C0A846C */  jal       func_802A11B0
/* 41E520 802A9790 00000000 */   nop
/* 41E524 802A9794 104000C5 */  beqz      $v0, .L802A9AAC
/* 41E528 802A9798 24020008 */   addiu    $v0, $zero, 8
/* 41E52C 802A979C 3C01802B */  lui       $at, %hi(D_802ACC60)
/* 41E530 802A97A0 AC22CC60 */  sw        $v0, %lo(D_802ACC60)($at)
/* 41E534 802A97A4 24020004 */  addiu     $v0, $zero, 4
/* 41E538 802A97A8 3C01802B */  lui       $at, %hi(D_802ACC6C)
/* 41E53C 802A97AC AC22CC6C */  sw        $v0, %lo(D_802ACC6C)($at)
/* 41E540 802A97B0 080AA6A9 */  j         .L802A9AA4
/* 41E544 802A97B4 24020002 */   addiu    $v0, $zero, 2
glabel L802A97B8_41E548
/* 41E548 802A97B8 0C0A923F */  jal       func_802A48FC
/* 41E54C 802A97BC 00000000 */   nop
/* 41E550 802A97C0 0C0A8426 */  jal       func_802A1098
/* 41E554 802A97C4 00000000 */   nop
/* 41E558 802A97C8 080AA6A9 */  j         .L802A9AA4
/* 41E55C 802A97CC 240200CB */   addiu    $v0, $zero, 0xcb
glabel L802A97D0_41E560
/* 41E560 802A97D0 0000802D */  daddu     $s0, $zero, $zero
/* 41E564 802A97D4 24110001 */  addiu     $s1, $zero, 1
/* 41E568 802A97D8 3C0C8009 */  lui       $t4, %hi(D_8008EF20)
/* 41E56C 802A97DC 258CEF20 */  addiu     $t4, $t4, %lo(D_8008EF20)
/* 41E570 802A97E0 3C0B802B */  lui       $t3, %hi(D_802AB3F8)
/* 41E574 802A97E4 256BB3F8 */  addiu     $t3, $t3, %lo(D_802AB3F8)
/* 41E578 802A97E8 0220502D */  daddu     $t2, $s1, $zero
/* 41E57C 802A97EC 3C09802B */  lui       $t1, %hi(D_802AB438)
/* 41E580 802A97F0 2529B438 */  addiu     $t1, $t1, %lo(D_802AB438)
/* 41E584 802A97F4 3C088009 */  lui       $t0, %hi(D_8008EEC4)
/* 41E588 802A97F8 2508EEC4 */  addiu     $t0, $t0, %lo(D_8008EEC4)
/* 41E58C 802A97FC 0240202D */  daddu     $a0, $s2, $zero
.L802A9800:
/* 41E590 802A9800 8D050000 */  lw        $a1, ($t0)
/* 41E594 802A9804 000510C0 */  sll       $v0, $a1, 3
/* 41E598 802A9808 02E23021 */  addu      $a2, $s7, $v0
/* 41E59C 802A980C 90C20014 */  lbu       $v0, 0x14($a2)
/* 41E5A0 802A9810 50400019 */  beql      $v0, $zero, .L802A9878
/* 41E5A4 802A9814 26310001 */   addiu    $s1, $s1, 1
/* 41E5A8 802A9818 00051900 */  sll       $v1, $a1, 4
/* 41E5AC 802A981C 00053880 */  sll       $a3, $a1, 2
/* 41E5B0 802A9820 00EB1021 */  addu      $v0, $a3, $t3
/* 41E5B4 802A9824 8C420000 */  lw        $v0, ($v0)
/* 41E5B8 802A9828 006C1821 */  addu      $v1, $v1, $t4
/* 41E5BC 802A982C AC850108 */  sw        $a1, 0x108($a0)
/* 41E5C0 802A9830 AC8A018C */  sw        $t2, 0x18c($a0)
/* 41E5C4 802A9834 AC820000 */  sw        $v0, ($a0)
/* 41E5C8 802A9838 8C620000 */  lw        $v0, ($v1)
/* 41E5CC 802A983C AC820084 */  sw        $v0, 0x84($a0)
/* 41E5D0 802A9840 8C62000C */  lw        $v0, 0xc($v1)
/* 41E5D4 802A9844 AC820294 */  sw        $v0, 0x294($a0)
/* 41E5D8 802A9848 80C20015 */  lb        $v0, 0x15($a2)
/* 41E5DC 802A984C AC820210 */  sw        $v0, 0x210($a0)
/* 41E5E0 802A9850 82E20012 */  lb        $v0, 0x12($s7)
/* 41E5E4 802A9854 54450006 */  bnel      $v0, $a1, .L802A9870
/* 41E5E8 802A9858 24840004 */   addiu    $a0, $a0, 4
/* 41E5EC 802A985C 00E91021 */  addu      $v0, $a3, $t1
/* 41E5F0 802A9860 AC80018C */  sw        $zero, 0x18c($a0)
/* 41E5F4 802A9864 8C420000 */  lw        $v0, ($v0)
/* 41E5F8 802A9868 AC820000 */  sw        $v0, ($a0)
/* 41E5FC 802A986C 24840004 */  addiu     $a0, $a0, 4
.L802A9870:
/* 41E600 802A9870 26100001 */  addiu     $s0, $s0, 1
/* 41E604 802A9874 26310001 */  addiu     $s1, $s1, 1
.L802A9878:
/* 41E608 802A9878 2A22000C */  slti      $v0, $s1, 0xc
/* 41E60C 802A987C 1440FFE0 */  bnez      $v0, .L802A9800
/* 41E610 802A9880 25080004 */   addiu    $t0, $t0, 4
/* 41E614 802A9884 82820061 */  lb        $v0, 0x61($s4)
/* 41E618 802A9888 04420001 */  bltzl     $v0, .L802A9890
/* 41E61C 802A988C A2800061 */   sb       $zero, 0x61($s4)
.L802A9890:
/* 41E620 802A9890 82E30012 */  lb        $v1, 0x12($s7)
/* 41E624 802A9894 24020001 */  addiu     $v0, $zero, 1
/* 41E628 802A9898 AE420318 */  sw        $v0, 0x318($s2)
/* 41E62C 802A989C AE500324 */  sw        $s0, 0x324($s2)
/* 41E630 802A98A0 00031880 */  sll       $v1, $v1, 2
/* 41E634 802A98A4 3C028009 */  lui       $v0, %hi(D_8008EEF0)
/* 41E638 802A98A8 00431021 */  addu      $v0, $v0, $v1
/* 41E63C 802A98AC 8C42EEF0 */  lw        $v0, %lo(D_8008EEF0)($v0)
/* 41E640 802A98B0 0240202D */  daddu     $a0, $s2, $zero
/* 41E644 802A98B4 AC80031C */  sw        $zero, 0x31c($a0)
/* 41E648 802A98B8 AC800320 */  sw        $zero, 0x320($a0)
/* 41E64C 802A98BC 2442FFFF */  addiu     $v0, $v0, -1
/* 41E650 802A98C0 0C03D44F */  jal       func_800F513C
/* 41E654 802A98C4 AC820328 */   sw       $v0, 0x328($a0)
/* 41E658 802A98C8 0C03D4AF */  jal       func_800F52BC
/* 41E65C 802A98CC 00000000 */   nop
/* 41E660 802A98D0 080AA6A9 */  j         .L802A9AA4
/* 41E664 802A98D4 2402001F */   addiu    $v0, $zero, 0x1f
glabel L802A98D8_41E668
/* 41E668 802A98D8 8643032C */  lh        $v1, 0x32c($s2)
/* 41E66C 802A98DC 2402FFFF */  addiu     $v0, $zero, -1
/* 41E670 802A98E0 10620070 */  beq       $v1, $v0, .L802A9AA4
/* 41E674 802A98E4 24020024 */   addiu    $v0, $zero, 0x24
/* 41E678 802A98E8 10600070 */  beqz      $v1, .L802A9AAC
/* 41E67C 802A98EC 240200FF */   addiu    $v0, $zero, 0xff
/* 41E680 802A98F0 1462000C */  bne       $v1, $v0, .L802A9924
/* 41E684 802A98F4 24020022 */   addiu    $v0, $zero, 0x22
/* 41E688 802A98F8 0C0A91F8 */  jal       func_802A47E0
/* 41E68C 802A98FC 00000000 */   nop
/* 41E690 802A9900 240200C9 */  addiu     $v0, $zero, 0xc9
.L802A9904:
/* 41E694 802A9904 3C01800E */  lui       $at, %hi(gBattleStatus+0x46C)
/* 41E698 802A9908 AC22C4DC */  sw        $v0, %lo(gBattleStatus+0x46C)($at)
/* 41E69C 802A990C 0C0AA072 */  jal       update_partner_menu
/* 41E6A0 802A9910 00000000 */   nop
/* 41E6A4 802A9914 0C0AA072 */  jal       update_partner_menu
/* 41E6A8 802A9918 00000000 */   nop
/* 41E6AC 802A991C 080AA6AB */  j         .L802A9AAC
/* 41E6B0 802A9920 00000000 */   nop
.L802A9924:
/* 41E6B4 802A9924 A682006C */  sh        $v0, 0x6c($s4)
/* 41E6B8 802A9928 8642032C */  lh        $v0, 0x32c($s2)
/* 41E6BC 802A992C 24030023 */  addiu     $v1, $zero, 0x23
/* 41E6C0 802A9930 A683006E */  sh        $v1, 0x6e($s4)
/* 41E6C4 802A9934 2442FFFF */  addiu     $v0, $v0, -1
/* 41E6C8 802A9938 00021080 */  sll       $v0, $v0, 2
/* 41E6CC 802A993C 02421021 */  addu      $v0, $s2, $v0
/* 41E6D0 802A9940 9043010B */  lbu       $v1, 0x10b($v0)
/* 41E6D4 802A9944 24020005 */  addiu     $v0, $zero, 5
/* 41E6D8 802A9948 A2820178 */  sb        $v0, 0x178($s4)
/* 41E6DC 802A994C 24020037 */  addiu     $v0, $zero, 0x37
/* 41E6E0 802A9950 A682017C */  sh        $v0, 0x17c($s4)
/* 41E6E4 802A9954 24020002 */  addiu     $v0, $zero, 2
/* 41E6E8 802A9958 AE820184 */  sw        $v0, 0x184($s4)
/* 41E6EC 802A995C A28301AC */  sb        $v1, 0x1ac($s4)
/* 41E6F0 802A9960 00031E00 */  sll       $v1, $v1, 0x18
/* 41E6F4 802A9964 9242032D */  lbu       $v0, 0x32d($s2)
/* 41E6F8 802A9968 00031E03 */  sra       $v1, $v1, 0x18
/* 41E6FC 802A996C A683017A */  sh        $v1, 0x17a($s4)
/* 41E700 802A9970 2442FFFF */  addiu     $v0, $v0, -1
/* 41E704 802A9974 0C03C4EC */  jal       func_800F13B0
/* 41E708 802A9978 A2820061 */   sb       $v0, 0x61($s4)
/* 41E70C 802A997C 0C0A91C6 */  jal       func_802A4718
/* 41E710 802A9980 00000000 */   nop
/* 41E714 802A9984 0C0A840C */  jal       func_802A1030
/* 41E718 802A9988 00000000 */   nop
/* 41E71C 802A998C 080AA6A9 */  j         .L802A9AA4
/* 41E720 802A9990 24020020 */   addiu    $v0, $zero, 0x20
glabel L802A9994_41E724
/* 41E724 802A9994 8E820214 */  lw        $v0, 0x214($s4)
/* 41E728 802A9998 30424000 */  andi      $v0, $v0, 0x4000
/* 41E72C 802A999C 1040000C */  beqz      $v0, .L802A99D0
/* 41E730 802A99A0 00000000 */   nop
/* 41E734 802A99A4 8642032C */  lh        $v0, 0x32c($s2)
/* 41E738 802A99A8 14400009 */  bnez      $v0, .L802A99D0
/* 41E73C 802A99AC 00000000 */   nop
/* 41E740 802A99B0 0C03C5B3 */  jal       func_800F16CC
/* 41E744 802A99B4 00000000 */   nop
/* 41E748 802A99B8 0C0A9284 */  jal       func_802A4A10
/* 41E74C 802A99BC 00000000 */   nop
/* 41E750 802A99C0 0C0A8426 */  jal       func_802A1098
/* 41E754 802A99C4 00000000 */   nop
/* 41E758 802A99C8 080AA6A9 */  j         .L802A9AA4
/* 41E75C 802A99CC 24020021 */   addiu    $v0, $zero, 0x21
.L802A99D0:
/* 41E760 802A99D0 0C0A9295 */  jal       func_802A4A54
/* 41E764 802A99D4 00000000 */   nop
.L802A99D8:
/* 41E768 802A99D8 0C0A846C */  jal       func_802A11B0
/* 41E76C 802A99DC 00000000 */   nop
/* 41E770 802A99E0 10400032 */  beqz      $v0, .L802A9AAC
/* 41E774 802A99E4 00000000 */   nop
/* 41E778 802A99E8 8682006E */  lh        $v0, 0x6e($s4)
/* 41E77C 802A99EC 3C01800E */  lui       $at, %hi(gBattleStatus+0x46C)
/* 41E780 802A99F0 AC22C4DC */  sw        $v0, %lo(gBattleStatus+0x46C)($at)
/* 41E784 802A99F4 0C0AA072 */  jal       update_partner_menu
/* 41E788 802A99F8 00000000 */   nop
/* 41E78C 802A99FC 0C090464 */  jal       func_80241190
/* 41E790 802A9A00 2404001D */   addiu    $a0, $zero, 0x1d
/* 41E794 802A9A04 080AA6AB */  j         .L802A9AAC
/* 41E798 802A9A08 00000000 */   nop
glabel L802A9A0C_41E79C
/* 41E79C 802A9A0C 0C0A9295 */  jal       func_802A4A54
/* 41E7A0 802A9A10 00000000 */   nop
/* 41E7A4 802A9A14 0C0A846C */  jal       func_802A11B0
/* 41E7A8 802A9A18 00000000 */   nop
/* 41E7AC 802A9A1C 10400023 */  beqz      $v0, .L802A9AAC
/* 41E7B0 802A9A20 2402001F */   addiu    $v0, $zero, 0x1f
/* 41E7B4 802A9A24 080AA6A9 */  j         .L802A9AA4
/* 41E7B8 802A9A28 00000000 */   nop
glabel L802A9A2C_41E7BC
/* 41E7BC 802A9A2C 0C03C5B3 */  jal       func_800F16CC
/* 41E7C0 802A9A30 00000000 */   nop
/* 41E7C4 802A9A34 0C0A9284 */  jal       func_802A4A10
/* 41E7C8 802A9A38 00000000 */   nop
/* 41E7CC 802A9A3C 0C0A8426 */  jal       func_802A1098
/* 41E7D0 802A9A40 00000000 */   nop
/* 41E7D4 802A9A44 080AA6A9 */  j         .L802A9AA4
/* 41E7D8 802A9A48 24020021 */   addiu    $v0, $zero, 0x21
glabel L802A9A4C_41E7DC
/* 41E7DC 802A9A4C 0C03C54E */  jal       func_800F1538
/* 41E7E0 802A9A50 00000000 */   nop
glabel L802A9A54_41E7E4
/* 41E7E4 802A9A54 0C0A91CB */  jal       func_802A472C
/* 41E7E8 802A9A58 00000000 */   nop
/* 41E7EC 802A9A5C 080AA46A */  j         .L802A91A8
/* 41E7F0 802A9A60 00000000 */   nop
glabel L802A9A64_41E7F4
/* 41E7F4 802A9A64 24040006 */  addiu     $a0, $zero, 6
/* 41E7F8 802A9A68 0C051F9F */  jal       func_80147E7C
/* 41E7FC 802A9A6C 24050002 */   addiu    $a1, $zero, 2
/* 41E800 802A9A70 24040007 */  addiu     $a0, $zero, 7
/* 41E804 802A9A74 0C051F9F */  jal       func_80147E7C
/* 41E808 802A9A78 24050002 */   addiu    $a1, $zero, 2
/* 41E80C 802A9A7C 8643032C */  lh        $v1, 0x32c($s2)
/* 41E810 802A9A80 2402FFFF */  addiu     $v0, $zero, -1
/* 41E814 802A9A84 10620009 */  beq       $v1, $v0, .L802A9AAC
/* 41E818 802A9A88 24040006 */   addiu    $a0, $zero, 6
/* 41E81C 802A9A8C 0C051F9F */  jal       func_80147E7C
/* 41E820 802A9A90 24050009 */   addiu    $a1, $zero, 9
/* 41E824 802A9A94 24040007 */  addiu     $a0, $zero, 7
/* 41E828 802A9A98 0C051F9F */  jal       func_80147E7C
/* 41E82C 802A9A9C 24050009 */   addiu    $a1, $zero, 9
/* 41E830 802A9AA0 2402001F */  addiu     $v0, $zero, 0x1f
.L802A9AA4:
/* 41E834 802A9AA4 3C01800E */  lui       $at, %hi(gBattleStatus+0x46C)
/* 41E838 802A9AA8 AC22C4DC */  sw        $v0, %lo(gBattleStatus+0x46C)($at)
.L802A9AAC:
glabel L802A9AAC_41E83C
/* 41E83C 802A9AAC 8FBF0034 */  lw        $ra, 0x34($sp)
/* 41E840 802A9AB0 8FBE0030 */  lw        $fp, 0x30($sp)
/* 41E844 802A9AB4 8FB7002C */  lw        $s7, 0x2c($sp)
/* 41E848 802A9AB8 8FB60028 */  lw        $s6, 0x28($sp)
/* 41E84C 802A9ABC 8FB50024 */  lw        $s5, 0x24($sp)
/* 41E850 802A9AC0 8FB40020 */  lw        $s4, 0x20($sp)
/* 41E854 802A9AC4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 41E858 802A9AC8 8FB20018 */  lw        $s2, 0x18($sp)
/* 41E85C 802A9ACC 8FB10014 */  lw        $s1, 0x14($sp)
/* 41E860 802A9AD0 8FB00010 */  lw        $s0, 0x10($sp)
/* 41E864 802A9AD4 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 41E868 802A9AD8 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 41E86C 802A9ADC D7B40038 */  ldc1      $f20, 0x38($sp)
/* 41E870 802A9AE0 03E00008 */  jr        $ra
/* 41E874 802A9AE4 27BD0050 */   addiu    $sp, $sp, 0x50
