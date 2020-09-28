.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802DC008
/* FF0F8 802DC008 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* FF0FC 802DC00C AFB3002C */  sw        $s3, 0x2c($sp)
/* FF100 802DC010 0080982D */  daddu     $s3, $a0, $zero
/* FF104 802DC014 AFB20028 */  sw        $s2, 0x28($sp)
/* FF108 802DC018 00A0902D */  daddu     $s2, $a1, $zero
/* FF10C 802DC01C 3C04F500 */  lui       $a0, 0xf500
/* FF110 802DC020 34840100 */  ori       $a0, $a0, 0x100
/* FF114 802DC024 3C050703 */  lui       $a1, 0x703
/* FF118 802DC028 3C0C800A */  lui       $t4, 0x800a
/* FF11C 802DC02C 258CA66C */  addiu     $t4, $t4, -0x5994
/* FF120 802DC030 34A5C000 */  ori       $a1, $a1, 0xc000
/* FF124 802DC034 3C02FD10 */  lui       $v0, 0xfd10
/* FF128 802DC038 3C0F0700 */  lui       $t7, 0x700
/* FF12C 802DC03C 3C0EE600 */  lui       $t6, 0xe600
/* FF130 802DC040 AFBF0034 */  sw        $ra, 0x34($sp)
/* FF134 802DC044 AFB40030 */  sw        $s4, 0x30($sp)
/* FF138 802DC048 AFB10024 */  sw        $s1, 0x24($sp)
/* FF13C 802DC04C AFB00020 */  sw        $s0, 0x20($sp)
/* FF140 802DC050 8D8B0000 */  lw        $t3, ($t4)
/* FF144 802DC054 8FB10048 */  lw        $s1, 0x48($sp)
/* FF148 802DC058 8FB90054 */  lw        $t9, 0x54($sp)
/* FF14C 802DC05C 0160182D */  daddu     $v1, $t3, $zero
/* FF150 802DC060 256B0008 */  addiu     $t3, $t3, 8
/* FF154 802DC064 AD8B0000 */  sw        $t3, ($t4)
/* FF158 802DC068 AC620000 */  sw        $v0, ($v1)
/* FF15C 802DC06C 25620008 */  addiu     $v0, $t3, 8
/* FF160 802DC070 AC660004 */  sw        $a2, 4($v1)
/* FF164 802DC074 AD820000 */  sw        $v0, ($t4)
/* FF168 802DC078 3C02E800 */  lui       $v0, 0xe800
/* FF16C 802DC07C AD620000 */  sw        $v0, ($t3)
/* FF170 802DC080 25620010 */  addiu     $v0, $t3, 0x10
/* FF174 802DC084 AD600004 */  sw        $zero, 4($t3)
/* FF178 802DC088 AD820000 */  sw        $v0, ($t4)
/* FF17C 802DC08C 25620018 */  addiu     $v0, $t3, 0x18
/* FF180 802DC090 AD640008 */  sw        $a0, 8($t3)
/* FF184 802DC094 AD6F000C */  sw        $t7, 0xc($t3)
/* FF188 802DC098 AD820000 */  sw        $v0, ($t4)
/* FF18C 802DC09C 25620020 */  addiu     $v0, $t3, 0x20
/* FF190 802DC0A0 AD6E0010 */  sw        $t6, 0x10($t3)
/* FF194 802DC0A4 AD600014 */  sw        $zero, 0x14($t3)
/* FF198 802DC0A8 AD820000 */  sw        $v0, ($t4)
/* FF19C 802DC0AC 3C02F000 */  lui       $v0, 0xf000
/* FF1A0 802DC0B0 AD620018 */  sw        $v0, 0x18($t3)
/* FF1A4 802DC0B4 25620028 */  addiu     $v0, $t3, 0x28
/* FF1A8 802DC0B8 AD65001C */  sw        $a1, 0x1c($t3)
/* FF1AC 802DC0BC AD820000 */  sw        $v0, ($t4)
/* FF1B0 802DC0C0 3C188015 */  lui       $t8, %hi(D_80151328)
/* FF1B4 802DC0C4 8F181328 */  lw        $t8, %lo(D_80151328)($t8)
/* FF1B8 802DC0C8 3C10E700 */  lui       $s0, 0xe700
/* FF1BC 802DC0CC AD700020 */  sw        $s0, 0x20($t3)
/* FF1C0 802DC0D0 AD600024 */  sw        $zero, 0x24($t3)
/* FF1C4 802DC0D4 97020000 */  lhu       $v0, ($t8)
/* FF1C8 802DC0D8 30420001 */  andi      $v0, $v0, 1
/* FF1CC 802DC0DC 104000C4 */  beqz      $v0, .L802DC3F0
/* FF1D0 802DC0E0 00E0682D */   daddu    $t5, $a3, $zero
/* FF1D4 802DC0E4 3C04070A */  lui       $a0, 0x70a
/* FF1D8 802DC0E8 34840280 */  ori       $a0, $a0, 0x280
/* FF1DC 802DC0EC 3C06010A */  lui       $a2, 0x10a
/* FF1E0 802DC0F0 34C60280 */  ori       $a2, $a2, 0x280
/* FF1E4 802DC0F4 3C07F240 */  lui       $a3, 0xf240
/* FF1E8 802DC0F8 34E70400 */  ori       $a3, $a3, 0x400
/* FF1EC 802DC0FC 3C08001A */  lui       $t0, 0x1a
/* FF1F0 802DC100 35080280 */  ori       $t0, $t0, 0x280
/* FF1F4 802DC104 3C09F510 */  lui       $t1, 0xf510
/* FF1F8 802DC108 35290900 */  ori       $t1, $t1, 0x900
/* FF1FC 802DC10C 3C0A020F */  lui       $t2, 0x20f
/* FF200 802DC110 354AC000 */  ori       $t2, $t2, 0xc000
/* FF204 802DC114 25620030 */  addiu     $v0, $t3, 0x30
/* FF208 802DC118 000D2843 */  sra       $a1, $t5, 1
/* FF20C 802DC11C AD820000 */  sw        $v0, ($t4)
/* FF210 802DC120 24A2FFFF */  addiu     $v0, $a1, -1
/* FF214 802DC124 30420FFF */  andi      $v0, $v0, 0xfff
/* FF218 802DC128 3C03FD48 */  lui       $v1, 0xfd48
/* FF21C 802DC12C 00431025 */  or        $v0, $v0, $v1
/* FF220 802DC130 AD620028 */  sw        $v0, 0x28($t3)
/* FF224 802DC134 25620038 */  addiu     $v0, $t3, 0x38
/* FF228 802DC138 24A50007 */  addiu     $a1, $a1, 7
/* FF22C 802DC13C 000528C3 */  sra       $a1, $a1, 3
/* FF230 802DC140 30A501FF */  andi      $a1, $a1, 0x1ff
/* FF234 802DC144 00052A40 */  sll       $a1, $a1, 9
/* FF238 802DC148 AD72002C */  sw        $s2, 0x2c($t3)
/* FF23C 802DC14C AD820000 */  sw        $v0, ($t4)
/* FF240 802DC150 3C02F548 */  lui       $v0, 0xf548
/* FF244 802DC154 00A21025 */  or        $v0, $a1, $v0
/* FF248 802DC158 AD620030 */  sw        $v0, 0x30($t3)
/* FF24C 802DC15C 25620040 */  addiu     $v0, $t3, 0x40
/* FF250 802DC160 AD640034 */  sw        $a0, 0x34($t3)
/* FF254 802DC164 AD820000 */  sw        $v0, ($t4)
/* FF258 802DC168 25620048 */  addiu     $v0, $t3, 0x48
/* FF25C 802DC16C AD6E0038 */  sw        $t6, 0x38($t3)
/* FF260 802DC170 AD60003C */  sw        $zero, 0x3c($t3)
/* FF264 802DC174 AD820000 */  sw        $v0, ($t4)
/* FF268 802DC178 3C02F400 */  lui       $v0, 0xf400
/* FF26C 802DC17C 25A3FFFF */  addiu     $v1, $t5, -1
/* FF270 802DC180 00031840 */  sll       $v1, $v1, 1
/* FF274 802DC184 30630FFF */  andi      $v1, $v1, 0xfff
/* FF278 802DC188 00031B00 */  sll       $v1, $v1, 0xc
/* FF27C 802DC18C AD620040 */  sw        $v0, 0x40($t3)
/* FF280 802DC190 2622FFFF */  addiu     $v0, $s1, -1
/* FF284 802DC194 00021080 */  sll       $v0, $v0, 2
/* FF288 802DC198 30420FFF */  andi      $v0, $v0, 0xfff
/* FF28C 802DC19C 004F1025 */  or        $v0, $v0, $t7
/* FF290 802DC1A0 00621825 */  or        $v1, $v1, $v0
/* FF294 802DC1A4 25620050 */  addiu     $v0, $t3, 0x50
/* FF298 802DC1A8 AD630044 */  sw        $v1, 0x44($t3)
/* FF29C 802DC1AC AD820000 */  sw        $v0, ($t4)
/* FF2A0 802DC1B0 25620058 */  addiu     $v0, $t3, 0x58
/* FF2A4 802DC1B4 AD700048 */  sw        $s0, 0x48($t3)
/* FF2A8 802DC1B8 AD60004C */  sw        $zero, 0x4c($t3)
/* FF2AC 802DC1BC AD820000 */  sw        $v0, ($t4)
/* FF2B0 802DC1C0 3C02F540 */  lui       $v0, 0xf540
/* FF2B4 802DC1C4 00A22825 */  or        $a1, $a1, $v0
/* FF2B8 802DC1C8 25620060 */  addiu     $v0, $t3, 0x60
/* FF2BC 802DC1CC 25A300FF */  addiu     $v1, $t5, 0xff
/* FF2C0 802DC1D0 00031880 */  sll       $v1, $v1, 2
/* FF2C4 802DC1D4 30630FFF */  andi      $v1, $v1, 0xfff
/* FF2C8 802DC1D8 00031B00 */  sll       $v1, $v1, 0xc
/* FF2CC 802DC1DC AD650050 */  sw        $a1, 0x50($t3)
/* FF2D0 802DC1E0 AD660054 */  sw        $a2, 0x54($t3)
/* FF2D4 802DC1E4 AD820000 */  sw        $v0, ($t4)
/* FF2D8 802DC1E8 262200FF */  addiu     $v0, $s1, 0xff
/* FF2DC 802DC1EC 00021080 */  sll       $v0, $v0, 2
/* FF2E0 802DC1F0 30420FFF */  andi      $v0, $v0, 0xfff
/* FF2E4 802DC1F4 3C040100 */  lui       $a0, 0x100
/* FF2E8 802DC1F8 00441025 */  or        $v0, $v0, $a0
/* FF2EC 802DC1FC 00621825 */  or        $v1, $v1, $v0
/* FF2F0 802DC200 25620068 */  addiu     $v0, $t3, 0x68
/* FF2F4 802DC204 AD670058 */  sw        $a3, 0x58($t3)
/* FF2F8 802DC208 AD63005C */  sw        $v1, 0x5c($t3)
/* FF2FC 802DC20C AD820000 */  sw        $v0, ($t4)
/* FF300 802DC210 25620070 */  addiu     $v0, $t3, 0x70
/* FF304 802DC214 AD650060 */  sw        $a1, 0x60($t3)
/* FF308 802DC218 AD680064 */  sw        $t0, 0x64($t3)
/* FF30C 802DC21C AD820000 */  sw        $v0, ($t4)
/* FF310 802DC220 3C020200 */  lui       $v0, 0x200
/* FF314 802DC224 AD62006C */  sw        $v0, 0x6c($t3)
/* FF318 802DC228 3C02F200 */  lui       $v0, 0xf200
/* FF31C 802DC22C AD690068 */  sw        $t1, 0x68($t3)
/* FF320 802DC230 AD620070 */  sw        $v0, 0x70($t3)
/* FF324 802DC234 AD6A0074 */  sw        $t2, 0x74($t3)
/* FF328 802DC238 97020000 */  lhu       $v0, ($t8)
/* FF32C 802DC23C 25630078 */  addiu     $v1, $t3, 0x78
/* FF330 802DC240 30420002 */  andi      $v0, $v0, 2
/* FF334 802DC244 10400059 */  beqz      $v0, .L802DC3AC
/* FF338 802DC248 AD830000 */   sw       $v1, ($t4)
/* FF33C 802DC24C 3C03800A */  lui       $v1, 0x800a
/* FF340 802DC250 8463A634 */  lh        $v1, -0x59cc($v1)
/* FF344 802DC254 3C04800B */  lui       $a0, %hi(gCameras)
/* FF348 802DC258 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* FF34C 802DC25C 00031080 */  sll       $v0, $v1, 2
/* FF350 802DC260 00431021 */  addu      $v0, $v0, $v1
/* FF354 802DC264 00021080 */  sll       $v0, $v0, 2
/* FF358 802DC268 00431023 */  subu      $v0, $v0, $v1
/* FF35C 802DC26C 000218C0 */  sll       $v1, $v0, 3
/* FF360 802DC270 00431021 */  addu      $v0, $v0, $v1
/* FF364 802DC274 000210C0 */  sll       $v0, $v0, 3
/* FF368 802DC278 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* FF36C 802DC27C 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* FF370 802DC280 00442021 */  addu      $a0, $v0, $a0
/* FF374 802DC284 80630070 */  lb        $v1, 0x70($v1)
/* FF378 802DC288 24020002 */  addiu     $v0, $zero, 2
/* FF37C 802DC28C 14620009 */  bne       $v1, $v0, .L802DC2B4
/* FF380 802DC290 3C02DC08 */   lui      $v0, 0xdc08
/* FF384 802DC294 34420008 */  ori       $v0, $v0, 8
/* FF388 802DC298 25630080 */  addiu     $v1, $t3, 0x80
/* FF38C 802DC29C AD830000 */  sw        $v1, ($t4)
/* FF390 802DC2A0 AD620078 */  sw        $v0, 0x78($t3)
/* FF394 802DC2A4 3C02802E */  lui       $v0, 0x802e
/* FF398 802DC2A8 2442F3E0 */  addiu     $v0, $v0, -0xc20
/* FF39C 802DC2AC 080B70B3 */  j         .L802DC2CC
/* FF3A0 802DC2B0 AD62007C */   sw       $v0, 0x7c($t3)
.L802DC2B4:
/* FF3A4 802DC2B4 34420008 */  ori       $v0, $v0, 8
/* FF3A8 802DC2B8 25630080 */  addiu     $v1, $t3, 0x80
/* FF3AC 802DC2BC AD830000 */  sw        $v1, ($t4)
/* FF3B0 802DC2C0 AD620078 */  sw        $v0, 0x78($t3)
/* FF3B4 802DC2C4 248200B0 */  addiu     $v0, $a0, 0xb0
/* FF3B8 802DC2C8 AD62007C */  sw        $v0, 0x7c($t3)
.L802DC2CC:
/* FF3BC 802DC2CC 240200FF */  addiu     $v0, $zero, 0xff
/* FF3C0 802DC2D0 17220008 */  bne       $t9, $v0, .L802DC2F4
/* FF3C4 802DC2D4 3C06E200 */   lui      $a2, 0xe200
/* FF3C8 802DC2D8 34C6001C */  ori       $a2, $a2, 0x1c
/* FF3CC 802DC2DC 3C050C19 */  lui       $a1, 0xc19
/* FF3D0 802DC2E0 3C04800A */  lui       $a0, 0x800a
/* FF3D4 802DC2E4 2484A66C */  addiu     $a0, $a0, -0x5994
/* FF3D8 802DC2E8 8C820000 */  lw        $v0, ($a0)
/* FF3DC 802DC2EC 080B70C3 */  j         .L802DC30C
/* FF3E0 802DC2F0 34A51238 */   ori      $a1, $a1, 0x1238
.L802DC2F4:
/* FF3E4 802DC2F4 34C6001C */  ori       $a2, $a2, 0x1c
/* FF3E8 802DC2F8 3C050C18 */  lui       $a1, 0xc18
/* FF3EC 802DC2FC 3C04800A */  lui       $a0, 0x800a
/* FF3F0 802DC300 2484A66C */  addiu     $a0, $a0, -0x5994
/* FF3F4 802DC304 8C820000 */  lw        $v0, ($a0)
/* FF3F8 802DC308 34A54B50 */  ori       $a1, $a1, 0x4b50
.L802DC30C:
/* FF3FC 802DC30C 0040182D */  daddu     $v1, $v0, $zero
/* FF400 802DC310 24420008 */  addiu     $v0, $v0, 8
/* FF404 802DC314 AC820000 */  sw        $v0, ($a0)
/* FF408 802DC318 AC660000 */  sw        $a2, ($v1)
/* FF40C 802DC31C AC650004 */  sw        $a1, 4($v1)
/* FF410 802DC320 3C06FCFF */  lui       $a2, 0xfcff
/* FF414 802DC324 34C6D5FF */  ori       $a2, $a2, 0xd5ff
/* FF418 802DC328 3C070100 */  lui       $a3, 0x100
/* FF41C 802DC32C 34E74008 */  ori       $a3, $a3, 0x4008
/* FF420 802DC330 3C080600 */  lui       $t0, 0x600
/* FF424 802DC334 3C04800A */  lui       $a0, 0x800a
/* FF428 802DC338 2484A66C */  addiu     $a0, $a0, -0x5994
/* FF42C 802DC33C 35080402 */  ori       $t0, $t0, 0x402
/* FF430 802DC340 8C820000 */  lw        $v0, ($a0)
/* FF434 802DC344 3C03FB00 */  lui       $v1, 0xfb00
/* FF438 802DC348 0040282D */  daddu     $a1, $v0, $zero
/* FF43C 802DC34C 24420008 */  addiu     $v0, $v0, 8
/* FF440 802DC350 AC820000 */  sw        $v0, ($a0)
/* FF444 802DC354 ACA30000 */  sw        $v1, ($a1)
/* FF448 802DC358 332300FF */  andi      $v1, $t9, 0xff
/* FF44C 802DC35C ACA30004 */  sw        $v1, 4($a1)
/* FF450 802DC360 24430008 */  addiu     $v1, $v0, 8
/* FF454 802DC364 AC830000 */  sw        $v1, ($a0)
/* FF458 802DC368 2403FFF8 */  addiu     $v1, $zero, -8
/* FF45C 802DC36C AC430004 */  sw        $v1, 4($v0)
/* FF460 802DC370 24430010 */  addiu     $v1, $v0, 0x10
/* FF464 802DC374 AC460000 */  sw        $a2, ($v0)
/* FF468 802DC378 AC830000 */  sw        $v1, ($a0)
/* FF46C 802DC37C 24430018 */  addiu     $v1, $v0, 0x18
/* FF470 802DC380 AC470008 */  sw        $a3, 8($v0)
/* FF474 802DC384 AC53000C */  sw        $s3, 0xc($v0)
/* FF478 802DC388 AC830000 */  sw        $v1, ($a0)
/* FF47C 802DC38C 24030604 */  addiu     $v1, $zero, 0x604
/* FF480 802DC390 AC430014 */  sw        $v1, 0x14($v0)
/* FF484 802DC394 24430020 */  addiu     $v1, $v0, 0x20
/* FF488 802DC398 AC480010 */  sw        $t0, 0x10($v0)
/* FF48C 802DC39C AC830000 */  sw        $v1, ($a0)
/* FF490 802DC3A0 3C03E700 */  lui       $v1, 0xe700
/* FF494 802DC3A4 AC430018 */  sw        $v1, 0x18($v0)
/* FF498 802DC3A8 AC40001C */  sw        $zero, 0x1c($v0)
.L802DC3AC:
/* FF49C 802DC3AC 240200FF */  addiu     $v0, $zero, 0xff
/* FF4A0 802DC3B0 AFB10010 */  sw        $s1, 0x10($sp)
/* FF4A4 802DC3B4 17220004 */  bne       $t9, $v0, .L802DC3C8
/* FF4A8 802DC3B8 AFB90014 */   sw       $t9, 0x14($sp)
/* FF4AC 802DC3BC 3C020011 */  lui       $v0, 0x11
/* FF4B0 802DC3C0 080B70F4 */  j         .L802DC3D0
/* FF4B4 802DC3C4 34421238 */   ori      $v0, $v0, 0x1238
.L802DC3C8:
/* FF4B8 802DC3C8 3C020010 */  lui       $v0, 0x10
/* FF4BC 802DC3CC 34424B50 */  ori       $v0, $v0, 0x4b50
.L802DC3D0:
/* FF4C0 802DC3D0 AFA20018 */  sw        $v0, 0x18($sp)
/* FF4C4 802DC3D4 8FA40050 */  lw        $a0, 0x50($sp)
/* FF4C8 802DC3D8 0000282D */  daddu     $a1, $zero, $zero
/* FF4CC 802DC3DC 00A0302D */  daddu     $a2, $a1, $zero
/* FF4D0 802DC3E0 0C052071 */  jal       func_801481C4
/* FF4D4 802DC3E4 01A0382D */   daddu    $a3, $t5, $zero
/* FF4D8 802DC3E8 080B71E2 */  j         .L802DC788
/* FF4DC 802DC3EC 00000000 */   nop      
.L802DC3F0:
/* FF4E0 802DC3F0 3C03070A */  lui       $v1, 0x70a
/* FF4E4 802DC3F4 34630280 */  ori       $v1, $v1, 0x280
/* FF4E8 802DC3F8 01A0202D */  daddu     $a0, $t5, $zero
/* FF4EC 802DC3FC 25620030 */  addiu     $v0, $t3, 0x30
/* FF4F0 802DC400 AD820000 */  sw        $v0, ($t4)
/* FF4F4 802DC404 3C02FD50 */  lui       $v0, 0xfd50
/* FF4F8 802DC408 AD620028 */  sw        $v0, 0x28($t3)
/* FF4FC 802DC40C 25620038 */  addiu     $v0, $t3, 0x38
/* FF500 802DC410 AD72002C */  sw        $s2, 0x2c($t3)
/* FF504 802DC414 AD820000 */  sw        $v0, ($t4)
/* FF508 802DC418 3C02F550 */  lui       $v0, 0xf550
/* FF50C 802DC41C AD620030 */  sw        $v0, 0x30($t3)
/* FF510 802DC420 25620040 */  addiu     $v0, $t3, 0x40
/* FF514 802DC424 AD630034 */  sw        $v1, 0x34($t3)
/* FF518 802DC428 AD820000 */  sw        $v0, ($t4)
/* FF51C 802DC42C 25620048 */  addiu     $v0, $t3, 0x48
/* FF520 802DC430 AD6E0038 */  sw        $t6, 0x38($t3)
/* FF524 802DC434 AD60003C */  sw        $zero, 0x3c($t3)
/* FF528 802DC438 AD820000 */  sw        $v0, ($t4)
/* FF52C 802DC43C 3C02F300 */  lui       $v0, 0xf300
/* FF530 802DC440 05A10002 */  bgez      $t5, .L802DC44C
/* FF534 802DC444 AD620040 */   sw       $v0, 0x40($t3)
/* FF538 802DC448 25A4000F */  addiu     $a0, $t5, 0xf
.L802DC44C:
/* FF53C 802DC44C 00042903 */  sra       $a1, $a0, 4
/* FF540 802DC450 18A00002 */  blez      $a1, .L802DC45C
/* FF544 802DC454 24030800 */   addiu    $v1, $zero, 0x800
/* FF548 802DC458 24A307FF */  addiu     $v1, $a1, 0x7ff
.L802DC45C:
/* FF54C 802DC45C 01B10018 */  mult      $t5, $s1
/* FF550 802DC460 0000A012 */  mflo      $s4
/* FF554 802DC464 26820003 */  addiu     $v0, $s4, 3
/* FF558 802DC468 00021083 */  sra       $v0, $v0, 2
/* FF55C 802DC46C 2444FFFF */  addiu     $a0, $v0, -1
/* FF560 802DC470 28820800 */  slti      $v0, $a0, 0x800
/* FF564 802DC474 50400001 */  beql      $v0, $zero, .L802DC47C
/* FF568 802DC478 240407FF */   addiu    $a0, $zero, 0x7ff
.L802DC47C:
/* FF56C 802DC47C 30820FFF */  andi      $v0, $a0, 0xfff
/* FF570 802DC480 00021300 */  sll       $v0, $v0, 0xc
/* FF574 802DC484 18A0000D */  blez      $a1, .L802DC4BC
/* FF578 802DC488 004F2025 */   or       $a0, $v0, $t7
/* FF57C 802DC48C 14A00002 */  bnez      $a1, .L802DC498
/* FF580 802DC490 0065001A */   div      $zero, $v1, $a1
/* FF584 802DC494 0007000D */  break     7
.L802DC498:
/* FF588 802DC498 2401FFFF */   addiu    $at, $zero, -1
/* FF58C 802DC49C 14A10004 */  bne       $a1, $at, .L802DC4B0
/* FF590 802DC4A0 3C018000 */   lui      $at, 0x8000
/* FF594 802DC4A4 14610002 */  bne       $v1, $at, .L802DC4B0
/* FF598 802DC4A8 00000000 */   nop      
/* FF59C 802DC4AC 0006000D */  break     6
.L802DC4B0:
/* FF5A0 802DC4B0 00001012 */   mflo     $v0
/* FF5A4 802DC4B4 080B7130 */  j         .L802DC4C0
/* FF5A8 802DC4B8 30420FFF */   andi     $v0, $v0, 0xfff
.L802DC4BC:
/* FF5AC 802DC4BC 30620FFF */  andi      $v0, $v1, 0xfff
.L802DC4C0:
/* FF5B0 802DC4C0 00821025 */  or        $v0, $a0, $v0
/* FF5B4 802DC4C4 AD620044 */  sw        $v0, 0x44($t3)
/* FF5B8 802DC4C8 3C05000A */  lui       $a1, 0xa
/* FF5BC 802DC4CC 34A50280 */  ori       $a1, $a1, 0x280
/* FF5C0 802DC4D0 3C04F240 */  lui       $a0, 0xf240
/* FF5C4 802DC4D4 3C07800A */  lui       $a3, 0x800a
/* FF5C8 802DC4D8 24E7A66C */  addiu     $a3, $a3, -0x5994
/* FF5CC 802DC4DC 34840400 */  ori       $a0, $a0, 0x400
/* FF5D0 802DC4E0 8CE60000 */  lw        $a2, ($a3)
/* FF5D4 802DC4E4 3C02E700 */  lui       $v0, 0xe700
/* FF5D8 802DC4E8 00C0182D */  daddu     $v1, $a2, $zero
/* FF5DC 802DC4EC 24C60008 */  addiu     $a2, $a2, 8
/* FF5E0 802DC4F0 ACE60000 */  sw        $a2, ($a3)
/* FF5E4 802DC4F4 AC620000 */  sw        $v0, ($v1)
/* FF5E8 802DC4F8 24C20008 */  addiu     $v0, $a2, 8
/* FF5EC 802DC4FC AC600004 */  sw        $zero, 4($v1)
/* FF5F0 802DC500 ACE20000 */  sw        $v0, ($a3)
/* FF5F4 802DC504 000D1043 */  sra       $v0, $t5, 1
/* FF5F8 802DC508 24420007 */  addiu     $v0, $v0, 7
/* FF5FC 802DC50C 000210C3 */  sra       $v0, $v0, 3
/* FF600 802DC510 304201FF */  andi      $v0, $v0, 0x1ff
/* FF604 802DC514 00021240 */  sll       $v0, $v0, 9
/* FF608 802DC518 3C03F540 */  lui       $v1, 0xf540
/* FF60C 802DC51C 00431025 */  or        $v0, $v0, $v1
/* FF610 802DC520 ACC20000 */  sw        $v0, ($a2)
/* FF614 802DC524 25A200FF */  addiu     $v0, $t5, 0xff
/* FF618 802DC528 00021080 */  sll       $v0, $v0, 2
/* FF61C 802DC52C 30420FFF */  andi      $v0, $v0, 0xfff
/* FF620 802DC530 00021300 */  sll       $v0, $v0, 0xc
/* FF624 802DC534 262300FF */  addiu     $v1, $s1, 0xff
/* FF628 802DC538 00031880 */  sll       $v1, $v1, 2
/* FF62C 802DC53C 30630FFF */  andi      $v1, $v1, 0xfff
/* FF630 802DC540 ACC40008 */  sw        $a0, 8($a2)
/* FF634 802DC544 3C048015 */  lui       $a0, %hi(D_80151328)
/* FF638 802DC548 8C841328 */  lw        $a0, %lo(D_80151328)($a0)
/* FF63C 802DC54C 00431025 */  or        $v0, $v0, $v1
/* FF640 802DC550 ACC50004 */  sw        $a1, 4($a2)
/* FF644 802DC554 ACC2000C */  sw        $v0, 0xc($a2)
/* FF648 802DC558 94820000 */  lhu       $v0, ($a0)
/* FF64C 802DC55C 24C30010 */  addiu     $v1, $a2, 0x10
/* FF650 802DC560 30420002 */  andi      $v0, $v0, 2
/* FF654 802DC564 104000C5 */  beqz      $v0, .L802DC87C
/* FF658 802DC568 ACE30000 */   sw       $v1, ($a3)
/* FF65C 802DC56C 3C03800A */  lui       $v1, 0x800a
/* FF660 802DC570 8463A634 */  lh        $v1, -0x59cc($v1)
/* FF664 802DC574 3C04800B */  lui       $a0, %hi(gCameras)
/* FF668 802DC578 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* FF66C 802DC57C 00031080 */  sll       $v0, $v1, 2
/* FF670 802DC580 00431021 */  addu      $v0, $v0, $v1
/* FF674 802DC584 00021080 */  sll       $v0, $v0, 2
/* FF678 802DC588 00431023 */  subu      $v0, $v0, $v1
/* FF67C 802DC58C 000218C0 */  sll       $v1, $v0, 3
/* FF680 802DC590 00431021 */  addu      $v0, $v0, $v1
/* FF684 802DC594 000210C0 */  sll       $v0, $v0, 3
/* FF688 802DC598 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* FF68C 802DC59C 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* FF690 802DC5A0 00442021 */  addu      $a0, $v0, $a0
/* FF694 802DC5A4 80630070 */  lb        $v1, 0x70($v1)
/* FF698 802DC5A8 24020002 */  addiu     $v0, $zero, 2
/* FF69C 802DC5AC 14620009 */  bne       $v1, $v0, .L802DC5D4
/* FF6A0 802DC5B0 3C02DC08 */   lui      $v0, 0xdc08
/* FF6A4 802DC5B4 34420008 */  ori       $v0, $v0, 8
/* FF6A8 802DC5B8 24C30018 */  addiu     $v1, $a2, 0x18
/* FF6AC 802DC5BC ACE30000 */  sw        $v1, ($a3)
/* FF6B0 802DC5C0 ACC20010 */  sw        $v0, 0x10($a2)
/* FF6B4 802DC5C4 3C02802E */  lui       $v0, 0x802e
/* FF6B8 802DC5C8 2442F3E0 */  addiu     $v0, $v0, -0xc20
/* FF6BC 802DC5CC 080B717B */  j         .L802DC5EC
/* FF6C0 802DC5D0 ACC20014 */   sw       $v0, 0x14($a2)
.L802DC5D4:
/* FF6C4 802DC5D4 34420008 */  ori       $v0, $v0, 8
/* FF6C8 802DC5D8 24C30018 */  addiu     $v1, $a2, 0x18
/* FF6CC 802DC5DC ACE30000 */  sw        $v1, ($a3)
/* FF6D0 802DC5E0 ACC20010 */  sw        $v0, 0x10($a2)
/* FF6D4 802DC5E4 248200B0 */  addiu     $v0, $a0, 0xb0
/* FF6D8 802DC5E8 ACC20014 */  sw        $v0, 0x14($a2)
.L802DC5EC:
/* FF6DC 802DC5EC 240200FF */  addiu     $v0, $zero, 0xff
/* FF6E0 802DC5F0 17220008 */  bne       $t9, $v0, .L802DC614
/* FF6E4 802DC5F4 3C06E200 */   lui      $a2, 0xe200
/* FF6E8 802DC5F8 34C6001C */  ori       $a2, $a2, 0x1c
/* FF6EC 802DC5FC 3C050055 */  lui       $a1, 0x55
/* FF6F0 802DC600 3C04800A */  lui       $a0, 0x800a
/* FF6F4 802DC604 2484A66C */  addiu     $a0, $a0, -0x5994
/* FF6F8 802DC608 8C820000 */  lw        $v0, ($a0)
/* FF6FC 802DC60C 080B718B */  j         .L802DC62C
/* FF700 802DC610 34A53238 */   ori      $a1, $a1, 0x3238
.L802DC614:
/* FF704 802DC614 34C6001C */  ori       $a2, $a2, 0x1c
/* FF708 802DC618 3C050050 */  lui       $a1, 0x50
/* FF70C 802DC61C 3C04800A */  lui       $a0, 0x800a
/* FF710 802DC620 2484A66C */  addiu     $a0, $a0, -0x5994
/* FF714 802DC624 8C820000 */  lw        $v0, ($a0)
/* FF718 802DC628 34A54B50 */  ori       $a1, $a1, 0x4b50
.L802DC62C:
/* FF71C 802DC62C 0040182D */  daddu     $v1, $v0, $zero
/* FF720 802DC630 24420008 */  addiu     $v0, $v0, 8
/* FF724 802DC634 AC820000 */  sw        $v0, ($a0)
/* FF728 802DC638 AC660000 */  sw        $a2, ($v1)
/* FF72C 802DC63C AC650004 */  sw        $a1, 4($v1)
/* FF730 802DC640 3C05FCFF */  lui       $a1, 0xfcff
/* FF734 802DC644 34A5D3FF */  ori       $a1, $a1, 0xd3ff
/* FF738 802DC648 3C04FFA7 */  lui       $a0, 0xffa7
/* FF73C 802DC64C 3484FFFF */  ori       $a0, $a0, 0xffff
/* FF740 802DC650 3C060100 */  lui       $a2, 0x100
/* FF744 802DC654 34C64008 */  ori       $a2, $a2, 0x4008
/* FF748 802DC658 3C070600 */  lui       $a3, 0x600
/* FF74C 802DC65C 3C09800A */  lui       $t1, 0x800a
/* FF750 802DC660 2529A66C */  addiu     $t1, $t1, -0x5994
/* FF754 802DC664 34E70402 */  ori       $a3, $a3, 0x402
/* FF758 802DC668 8D280000 */  lw        $t0, ($t1)
/* FF75C 802DC66C 3C02FB00 */  lui       $v0, 0xfb00
/* FF760 802DC670 0100182D */  daddu     $v1, $t0, $zero
/* FF764 802DC674 25080008 */  addiu     $t0, $t0, 8
/* FF768 802DC678 AD280000 */  sw        $t0, ($t1)
/* FF76C 802DC67C AC620000 */  sw        $v0, ($v1)
/* FF770 802DC680 332200FF */  andi      $v0, $t9, 0xff
/* FF774 802DC684 AC620004 */  sw        $v0, 4($v1)
/* FF778 802DC688 25020008 */  addiu     $v0, $t0, 8
/* FF77C 802DC68C AD220000 */  sw        $v0, ($t1)
/* FF780 802DC690 25020010 */  addiu     $v0, $t0, 0x10
/* FF784 802DC694 AD050000 */  sw        $a1, ($t0)
/* FF788 802DC698 AD040004 */  sw        $a0, 4($t0)
/* FF78C 802DC69C AD220000 */  sw        $v0, ($t1)
/* FF790 802DC6A0 25020018 */  addiu     $v0, $t0, 0x18
/* FF794 802DC6A4 AD060008 */  sw        $a2, 8($t0)
/* FF798 802DC6A8 AD13000C */  sw        $s3, 0xc($t0)
/* FF79C 802DC6AC AD220000 */  sw        $v0, ($t1)
/* FF7A0 802DC6B0 24020604 */  addiu     $v0, $zero, 0x604
/* FF7A4 802DC6B4 AD020014 */  sw        $v0, 0x14($t0)
/* FF7A8 802DC6B8 25020020 */  addiu     $v0, $t0, 0x20
/* FF7AC 802DC6BC AD070010 */  sw        $a3, 0x10($t0)
/* FF7B0 802DC6C0 AD220000 */  sw        $v0, ($t1)
/* FF7B4 802DC6C4 3C02E700 */  lui       $v0, 0xe700
/* FF7B8 802DC6C8 AD020018 */  sw        $v0, 0x18($t0)
/* FF7BC 802DC6CC 240200FF */  addiu     $v0, $zero, 0xff
/* FF7C0 802DC6D0 17220006 */  bne       $t9, $v0, .L802DC6EC
/* FF7C4 802DC6D4 AD00001C */   sw       $zero, 0x1c($t0)
/* FF7C8 802DC6D8 3C04E200 */  lui       $a0, 0xe200
/* FF7CC 802DC6DC 3484001C */  ori       $a0, $a0, 0x1c
/* FF7D0 802DC6E0 3C030055 */  lui       $v1, 0x55
/* FF7D4 802DC6E4 080B71BF */  j         .L802DC6FC
/* FF7D8 802DC6E8 34631238 */   ori      $v1, $v1, 0x1238
.L802DC6EC:
/* FF7DC 802DC6EC 3C04E200 */  lui       $a0, 0xe200
/* FF7E0 802DC6F0 3484001C */  ori       $a0, $a0, 0x1c
/* FF7E4 802DC6F4 3C030050 */  lui       $v1, 0x50
/* FF7E8 802DC6F8 34634B50 */  ori       $v1, $v1, 0x4b50
.L802DC6FC:
/* FF7EC 802DC6FC 25020028 */  addiu     $v0, $t0, 0x28
/* FF7F0 802DC700 AD220000 */  sw        $v0, ($t1)
/* FF7F4 802DC704 AD040020 */  sw        $a0, 0x20($t0)
/* FF7F8 802DC708 AD030024 */  sw        $v1, 0x24($t0)
/* FF7FC 802DC70C 3C066464 */  lui       $a2, 0x6464
/* FF800 802DC710 34C664FF */  ori       $a2, $a2, 0x64ff
/* FF804 802DC714 3C08FC40 */  lui       $t0, 0xfc40
/* FF808 802DC718 3508B281 */  ori       $t0, $t0, 0xb281
/* FF80C 802DC71C 3C075564 */  lui       $a3, 0x5564
/* FF810 802DC720 34E7FE7F */  ori       $a3, $a3, 0xfe7f
/* FF814 802DC724 3C09E300 */  lui       $t1, 0xe300
/* FF818 802DC728 3C04800A */  lui       $a0, 0x800a
/* FF81C 802DC72C 2484A66C */  addiu     $a0, $a0, -0x5994
/* FF820 802DC730 35291801 */  ori       $t1, $t1, 0x1801
/* FF824 802DC734 8C820000 */  lw        $v0, ($a0)
/* FF828 802DC738 3C03FB00 */  lui       $v1, 0xfb00
/* FF82C 802DC73C 0040282D */  daddu     $a1, $v0, $zero
/* FF830 802DC740 24420008 */  addiu     $v0, $v0, 8
/* FF834 802DC744 AC820000 */  sw        $v0, ($a0)
/* FF838 802DC748 ACA30000 */  sw        $v1, ($a1)
/* FF83C 802DC74C 24430008 */  addiu     $v1, $v0, 8
/* FF840 802DC750 ACA60004 */  sw        $a2, 4($a1)
/* FF844 802DC754 AC830000 */  sw        $v1, ($a0)
/* FF848 802DC758 3C03FA00 */  lui       $v1, 0xfa00
/* FF84C 802DC75C AC430000 */  sw        $v1, ($v0)
/* FF850 802DC760 332300FF */  andi      $v1, $t9, 0xff
/* FF854 802DC764 AC430004 */  sw        $v1, 4($v0)
/* FF858 802DC768 24430010 */  addiu     $v1, $v0, 0x10
/* FF85C 802DC76C AC830000 */  sw        $v1, ($a0)
/* FF860 802DC770 24430018 */  addiu     $v1, $v0, 0x18
/* FF864 802DC774 AC480008 */  sw        $t0, 8($v0)
/* FF868 802DC778 AC47000C */  sw        $a3, 0xc($v0)
/* FF86C 802DC77C AC830000 */  sw        $v1, ($a0)
/* FF870 802DC780 AC490010 */  sw        $t1, 0x10($v0)
/* FF874 802DC784 AC400014 */  sw        $zero, 0x14($v0)
.L802DC788:
/* FF878 802DC788 3C028015 */  lui       $v0, %hi(D_80151328)
/* FF87C 802DC78C 8C421328 */  lw        $v0, %lo(D_80151328)($v0)
/* FF880 802DC790 94420000 */  lhu       $v0, ($v0)
/* FF884 802DC794 30420002 */  andi      $v0, $v0, 2
/* FF888 802DC798 10400039 */  beqz      $v0, .L802DC880
/* FF88C 802DC79C 3C050100 */   lui      $a1, 0x100
/* FF890 802DC7A0 3C04800B */  lui       $a0, %hi(gCameras)
/* FF894 802DC7A4 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* FF898 802DC7A8 3C03800A */  lui       $v1, 0x800a
/* FF89C 802DC7AC 8463A634 */  lh        $v1, -0x59cc($v1)
/* FF8A0 802DC7B0 3C068007 */  lui       $a2, %hi(gGameStatusPtr)
/* FF8A4 802DC7B4 8CC6419C */  lw        $a2, %lo(gGameStatusPtr)($a2)
/* FF8A8 802DC7B8 00031080 */  sll       $v0, $v1, 2
/* FF8AC 802DC7BC 00431021 */  addu      $v0, $v0, $v1
/* FF8B0 802DC7C0 00021080 */  sll       $v0, $v0, 2
/* FF8B4 802DC7C4 00431023 */  subu      $v0, $v0, $v1
/* FF8B8 802DC7C8 000218C0 */  sll       $v1, $v0, 3
/* FF8BC 802DC7CC 00431021 */  addu      $v0, $v0, $v1
/* FF8C0 802DC7D0 000210C0 */  sll       $v0, $v0, 3
/* FF8C4 802DC7D4 00443821 */  addu      $a3, $v0, $a0
/* FF8C8 802DC7D8 80C30070 */  lb        $v1, 0x70($a2)
/* FF8CC 802DC7DC 24020002 */  addiu     $v0, $zero, 2
/* FF8D0 802DC7E0 1462001C */  bne       $v1, $v0, .L802DC854
/* FF8D4 802DC7E4 3C05DC08 */   lui      $a1, 0xdc08
/* FF8D8 802DC7E8 3C04DC08 */  lui       $a0, 0xdc08
/* FF8DC 802DC7EC 3C03800A */  lui       $v1, 0x800a
/* FF8E0 802DC7F0 2463A66C */  addiu     $v1, $v1, -0x5994
/* FF8E4 802DC7F4 8C620000 */  lw        $v0, ($v1)
/* FF8E8 802DC7F8 34840008 */  ori       $a0, $a0, 8
/* FF8EC 802DC7FC 0040282D */  daddu     $a1, $v0, $zero
/* FF8F0 802DC800 24420008 */  addiu     $v0, $v0, 8
/* FF8F4 802DC804 AC620000 */  sw        $v0, ($v1)
/* FF8F8 802DC808 ACA40000 */  sw        $a0, ($a1)
/* FF8FC 802DC80C 3C04802E */  lui       $a0, 0x802e
/* FF900 802DC810 2484F3D0 */  addiu     $a0, $a0, -0xc30
/* FF904 802DC814 ACA40004 */  sw        $a0, 4($a1)
/* FF908 802DC818 3C05802E */  lui       $a1, 0x802e
/* FF90C 802DC81C 24A5F3E0 */  addiu     $a1, $a1, -0xc20
/* FF910 802DC820 90C30082 */  lbu       $v1, 0x82($a2)
/* FF914 802DC824 94820008 */  lhu       $v0, 8($a0)
/* FF918 802DC828 00031E00 */  sll       $v1, $v1, 0x18
/* FF91C 802DC82C 00031E03 */  sra       $v1, $v1, 0x18
/* FF920 802DC830 00431021 */  addu      $v0, $v0, $v1
/* FF924 802DC834 A4A20008 */  sh        $v0, 8($a1)
/* FF928 802DC838 90C20083 */  lbu       $v0, 0x83($a2)
/* FF92C 802DC83C 9483000A */  lhu       $v1, 0xa($a0)
/* FF930 802DC840 00021600 */  sll       $v0, $v0, 0x18
/* FF934 802DC844 00021603 */  sra       $v0, $v0, 0x18
/* FF938 802DC848 00621821 */  addu      $v1, $v1, $v0
/* FF93C 802DC84C 080B721F */  j         .L802DC87C
/* FF940 802DC850 A4A3000A */   sh       $v1, 0xa($a1)
.L802DC854:
/* FF944 802DC854 3C03800A */  lui       $v1, 0x800a
/* FF948 802DC858 2463A66C */  addiu     $v1, $v1, -0x5994
/* FF94C 802DC85C 8C620000 */  lw        $v0, ($v1)
/* FF950 802DC860 34A50008 */  ori       $a1, $a1, 8
/* FF954 802DC864 0040202D */  daddu     $a0, $v0, $zero
/* FF958 802DC868 24420008 */  addiu     $v0, $v0, 8
/* FF95C 802DC86C AC620000 */  sw        $v0, ($v1)
/* FF960 802DC870 24E200A0 */  addiu     $v0, $a3, 0xa0
/* FF964 802DC874 AC850000 */  sw        $a1, ($a0)
/* FF968 802DC878 AC820004 */  sw        $v0, 4($a0)
.L802DC87C:
/* FF96C 802DC87C 3C050100 */  lui       $a1, 0x100
.L802DC880:
/* FF970 802DC880 34A54008 */  ori       $a1, $a1, 0x4008
/* FF974 802DC884 3C060600 */  lui       $a2, 0x600
/* FF978 802DC888 3C04800A */  lui       $a0, 0x800a
/* FF97C 802DC88C 2484A66C */  addiu     $a0, $a0, -0x5994
/* FF980 802DC890 8C820000 */  lw        $v0, ($a0)
/* FF984 802DC894 34C60402 */  ori       $a2, $a2, 0x402
/* FF988 802DC898 0040182D */  daddu     $v1, $v0, $zero
/* FF98C 802DC89C 24420008 */  addiu     $v0, $v0, 8
/* FF990 802DC8A0 AC820000 */  sw        $v0, ($a0)
/* FF994 802DC8A4 AC650000 */  sw        $a1, ($v1)
/* FF998 802DC8A8 AC730004 */  sw        $s3, 4($v1)
/* FF99C 802DC8AC 24430008 */  addiu     $v1, $v0, 8
/* FF9A0 802DC8B0 AC830000 */  sw        $v1, ($a0)
/* FF9A4 802DC8B4 24030604 */  addiu     $v1, $zero, 0x604
/* FF9A8 802DC8B8 AC430004 */  sw        $v1, 4($v0)
/* FF9AC 802DC8BC 24430010 */  addiu     $v1, $v0, 0x10
/* FF9B0 802DC8C0 AC460000 */  sw        $a2, ($v0)
/* FF9B4 802DC8C4 AC830000 */  sw        $v1, ($a0)
/* FF9B8 802DC8C8 3C03E700 */  lui       $v1, 0xe700
/* FF9BC 802DC8CC AC430008 */  sw        $v1, 8($v0)
/* FF9C0 802DC8D0 AC40000C */  sw        $zero, 0xc($v0)
/* FF9C4 802DC8D4 8FBF0034 */  lw        $ra, 0x34($sp)
/* FF9C8 802DC8D8 8FB40030 */  lw        $s4, 0x30($sp)
/* FF9CC 802DC8DC 8FB3002C */  lw        $s3, 0x2c($sp)
/* FF9D0 802DC8E0 8FB20028 */  lw        $s2, 0x28($sp)
/* FF9D4 802DC8E4 8FB10024 */  lw        $s1, 0x24($sp)
/* FF9D8 802DC8E8 8FB00020 */  lw        $s0, 0x20($sp)
/* FF9DC 802DC8EC 03E00008 */  jr        $ra
/* FF9E0 802DC8F0 27BD0038 */   addiu    $sp, $sp, 0x38
