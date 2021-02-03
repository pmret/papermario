.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802421A0_8EDFC0
/* 8EDFC0 802421A0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 8EDFC4 802421A4 AFB60040 */  sw        $s6, 0x40($sp)
/* 8EDFC8 802421A8 0080B02D */  daddu     $s6, $a0, $zero
/* 8EDFCC 802421AC AFB00028 */  sw        $s0, 0x28($sp)
/* 8EDFD0 802421B0 00A0802D */  daddu     $s0, $a1, $zero
/* 8EDFD4 802421B4 AFBF0044 */  sw        $ra, 0x44($sp)
/* 8EDFD8 802421B8 AFB5003C */  sw        $s5, 0x3c($sp)
/* 8EDFDC 802421BC AFB40038 */  sw        $s4, 0x38($sp)
/* 8EDFE0 802421C0 AFB30034 */  sw        $s3, 0x34($sp)
/* 8EDFE4 802421C4 AFB20030 */  sw        $s2, 0x30($sp)
/* 8EDFE8 802421C8 1A00019F */  blez      $s0, .L80242848
/* 8EDFEC 802421CC AFB1002C */   sw       $s1, 0x2c($sp)
/* 8EDFF0 802421D0 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 8EDFF4 802421D4 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 8EDFF8 802421D8 3C02DE00 */  lui       $v0, 0xde00
/* 8EDFFC 802421DC 44900000 */  mtc1      $s0, $f0
/* 8EE000 802421E0 00000000 */  nop
/* 8EE004 802421E4 46800021 */  cvt.d.w   $f0, $f0
/* 8EE008 802421E8 8C830000 */  lw        $v1, ($a0)
/* 8EE00C 802421EC 3C018025 */  lui       $at, %hi(D_80253030_8FEE50)
/* 8EE010 802421F0 D4223030 */  ldc1      $f2, %lo(D_80253030_8FEE50)($at)
/* 8EE014 802421F4 0060282D */  daddu     $a1, $v1, $zero
/* 8EE018 802421F8 24630008 */  addiu     $v1, $v1, 8
/* 8EE01C 802421FC AC830000 */  sw        $v1, ($a0)
/* 8EE020 80242200 ACA20000 */  sw        $v0, ($a1)
/* 8EE024 80242204 3C028025 */  lui       $v0, %hi(D_80252D50_8FEB70)
/* 8EE028 80242208 24422D50 */  addiu     $v0, $v0, %lo(D_80252D50_8FEB70)
/* 8EE02C 8024220C ACA20004 */  sw        $v0, 4($a1)
/* 8EE030 80242210 24620008 */  addiu     $v0, $v1, 8
/* 8EE034 80242214 AC820000 */  sw        $v0, ($a0)
/* 8EE038 80242218 3C02E700 */  lui       $v0, 0xe700
/* 8EE03C 8024221C 46220002 */  mul.d     $f0, $f0, $f2
/* 8EE040 80242220 00000000 */  nop
/* 8EE044 80242224 AC620000 */  sw        $v0, ($v1)
/* 8EE048 80242228 24620010 */  addiu     $v0, $v1, 0x10
/* 8EE04C 8024222C AC600004 */  sw        $zero, 4($v1)
/* 8EE050 80242230 AC820000 */  sw        $v0, ($a0)
/* 8EE054 80242234 3C02FA00 */  lui       $v0, 0xfa00
/* 8EE058 80242238 3C0141E0 */  lui       $at, 0x41e0
/* 8EE05C 8024223C 44811800 */  mtc1      $at, $f3
/* 8EE060 80242240 44801000 */  mtc1      $zero, $f2
/* 8EE064 80242244 246D000C */  addiu     $t5, $v1, 0xc
/* 8EE068 80242248 4620103E */  c.le.d    $f2, $f0
/* 8EE06C 8024224C 00000000 */  nop
/* 8EE070 80242250 45010005 */  bc1t      .L80242268
/* 8EE074 80242254 AC620008 */   sw       $v0, 8($v1)
/* 8EE078 80242258 4620010D */  trunc.w.d $f4, $f0
/* 8EE07C 8024225C 440C2000 */  mfc1      $t4, $f4
/* 8EE080 80242260 080908A1 */  j         .L80242284
/* 8EE084 80242264 3C091078 */   lui      $t1, 0x1078
.L80242268:
/* 8EE088 80242268 46220001 */  sub.d     $f0, $f0, $f2
/* 8EE08C 8024226C 3C028000 */  lui       $v0, 0x8000
/* 8EE090 80242270 4620010D */  trunc.w.d $f4, $f0
/* 8EE094 80242274 440C2000 */  mfc1      $t4, $f4
/* 8EE098 80242278 00000000 */  nop
/* 8EE09C 8024227C 01826025 */  or        $t4, $t4, $v0
/* 8EE0A0 80242280 3C091078 */  lui       $t1, 0x1078
.L80242284:
/* 8EE0A4 80242284 35291800 */  ori       $t1, $t1, 0x1800
/* 8EE0A8 80242288 3C0BF647 */  lui       $t3, 0xf647
/* 8EE0AC 8024228C 356BC300 */  ori       $t3, $t3, 0xc300
/* 8EE0B0 80242290 3C0A0008 */  lui       $t2, 8
/* 8EE0B4 80242294 354A40AC */  ori       $t2, $t2, 0x40ac
/* 8EE0B8 80242298 2404001E */  addiu     $a0, $zero, 0x1e
/* 8EE0BC 8024229C 24050028 */  addiu     $a1, $zero, 0x28
/* 8EE0C0 802422A0 24060104 */  addiu     $a2, $zero, 0x104
/* 8EE0C4 802422A4 3C08800A */  lui       $t0, %hi(gMasterGfxPos)
/* 8EE0C8 802422A8 2508A66C */  addiu     $t0, $t0, %lo(gMasterGfxPos)
/* 8EE0CC 802422AC 318200FF */  andi      $v0, $t4, 0xff
/* 8EE0D0 802422B0 00491025 */  or        $v0, $v0, $t1
/* 8EE0D4 802422B4 44901000 */  mtc1      $s0, $f2
/* 8EE0D8 802422B8 00000000 */  nop
/* 8EE0DC 802422BC 468010A1 */  cvt.d.w   $f2, $f2
/* 8EE0E0 802422C0 8D030000 */  lw        $v1, ($t0)
/* 8EE0E4 802422C4 3C018025 */  lui       $at, %hi(D_80253038_8FEE58)
/* 8EE0E8 802422C8 D4203038 */  ldc1      $f0, %lo(D_80253038_8FEE58)($at)
/* 8EE0EC 802422CC 24110001 */  addiu     $s1, $zero, 1
/* 8EE0F0 802422D0 ADA20000 */  sw        $v0, ($t5)
/* 8EE0F4 802422D4 0060102D */  daddu     $v0, $v1, $zero
/* 8EE0F8 802422D8 24630008 */  addiu     $v1, $v1, 8
/* 8EE0FC 802422DC AD030000 */  sw        $v1, ($t0)
/* 8EE100 802422E0 AC4B0000 */  sw        $t3, ($v0)
/* 8EE104 802422E4 AC4A0004 */  sw        $t2, 4($v0)
/* 8EE108 802422E8 24620008 */  addiu     $v0, $v1, 8
/* 8EE10C 802422EC AD020000 */  sw        $v0, ($t0)
/* 8EE110 802422F0 3C02E700 */  lui       $v0, 0xe700
/* 8EE114 802422F4 46201082 */  mul.d     $f2, $f2, $f0
/* 8EE118 802422F8 00000000 */  nop
/* 8EE11C 802422FC AC620000 */  sw        $v0, ($v1)
/* 8EE120 80242300 24020006 */  addiu     $v0, $zero, 6
/* 8EE124 80242304 AC600004 */  sw        $zero, 4($v1)
/* 8EE128 80242308 AFA20010 */  sw        $v0, 0x10($sp)
/* 8EE12C 8024230C AFA00014 */  sw        $zero, 0x14($sp)
/* 8EE130 80242310 AFB10018 */  sw        $s1, 0x18($sp)
/* 8EE134 80242314 AFB00020 */  sw        $s0, 0x20($sp)
/* 8EE138 80242318 4620110D */  trunc.w.d $f4, $f2
/* 8EE13C 8024231C E7A4001C */  swc1      $f4, 0x1c($sp)
/* 8EE140 80242320 0C04B6D6 */  jal       func_8012DB58
/* 8EE144 80242324 2407009B */   addiu    $a3, $zero, 0x9b
/* 8EE148 80242328 3C04000B */  lui       $a0, 0xb
/* 8EE14C 8024232C 348400FC */  ori       $a0, $a0, 0xfc
/* 8EE150 80242330 0C04991D */  jal       get_string_width
/* 8EE154 80242334 0000282D */   daddu    $a1, $zero, $zero
/* 8EE158 80242338 3C04000B */  lui       $a0, 0xb
/* 8EE15C 8024233C 348400FC */  ori       $a0, $a0, 0xfc
/* 8EE160 80242340 241300CE */  addiu     $s3, $zero, 0xce
/* 8EE164 80242344 02622823 */  subu      $a1, $s3, $v0
/* 8EE168 80242348 24060032 */  addiu     $a2, $zero, 0x32
/* 8EE16C 8024234C 0200382D */  daddu     $a3, $s0, $zero
/* 8EE170 80242350 AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE174 80242354 0C04993B */  jal       draw_string
/* 8EE178 80242358 AFB10014 */   sw       $s1, 0x14($sp)
/* 8EE17C 8024235C 240500D8 */  addiu     $a1, $zero, 0xd8
/* 8EE180 80242360 24060033 */  addiu     $a2, $zero, 0x33
/* 8EE184 80242364 3C128011 */  lui       $s2, %hi(gPlayerData)
/* 8EE188 80242368 2652F290 */  addiu     $s2, $s2, %lo(gPlayerData)
/* 8EE18C 8024236C 0220382D */  daddu     $a3, $s1, $zero
/* 8EE190 80242370 8E4402B4 */  lw        $a0, 0x2b4($s2)
/* 8EE194 80242374 24140002 */  addiu     $s4, $zero, 2
/* 8EE198 80242378 AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE19C 8024237C AFB00014 */  sw        $s0, 0x14($sp)
/* 8EE1A0 80242380 0C049DA7 */  jal       draw_number
/* 8EE1A4 80242384 AFB40018 */   sw       $s4, 0x18($sp)
/* 8EE1A8 80242388 3C04000B */  lui       $a0, 0xb
/* 8EE1AC 8024238C 348400FD */  ori       $a0, $a0, 0xfd
/* 8EE1B0 80242390 0C04991D */  jal       get_string_width
/* 8EE1B4 80242394 0000282D */   daddu    $a1, $zero, $zero
/* 8EE1B8 80242398 3C04000B */  lui       $a0, 0xb
/* 8EE1BC 8024239C 348400FD */  ori       $a0, $a0, 0xfd
/* 8EE1C0 802423A0 02622823 */  subu      $a1, $s3, $v0
/* 8EE1C4 802423A4 24060041 */  addiu     $a2, $zero, 0x41
/* 8EE1C8 802423A8 0200382D */  daddu     $a3, $s0, $zero
/* 8EE1CC 802423AC AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE1D0 802423B0 0C04993B */  jal       draw_string
/* 8EE1D4 802423B4 AFB10014 */   sw       $s1, 0x14($sp)
/* 8EE1D8 802423B8 240500E7 */  addiu     $a1, $zero, 0xe7
/* 8EE1DC 802423BC 24060042 */  addiu     $a2, $zero, 0x42
/* 8EE1E0 802423C0 0220382D */  daddu     $a3, $s1, $zero
/* 8EE1E4 802423C4 96C40024 */  lhu       $a0, 0x24($s6)
/* 8EE1E8 802423C8 24150003 */  addiu     $s5, $zero, 3
/* 8EE1EC 802423CC AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE1F0 802423D0 AFB00014 */  sw        $s0, 0x14($sp)
/* 8EE1F4 802423D4 0C049DA7 */  jal       draw_number
/* 8EE1F8 802423D8 AFB50018 */   sw       $s5, 0x18($sp)
/* 8EE1FC 802423DC 3C04001F */  lui       $a0, 0x1f
/* 8EE200 802423E0 34840034 */  ori       $a0, $a0, 0x34
/* 8EE204 802423E4 240500E8 */  addiu     $a1, $zero, 0xe8
/* 8EE208 802423E8 2406003F */  addiu     $a2, $zero, 0x3f
/* 8EE20C 802423EC 0200382D */  daddu     $a3, $s0, $zero
/* 8EE210 802423F0 AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE214 802423F4 0C04993B */  jal       draw_string
/* 8EE218 802423F8 AFA00014 */   sw       $zero, 0x14($sp)
/* 8EE21C 802423FC 24040050 */  addiu     $a0, $zero, 0x50
/* 8EE220 80242400 240500F4 */  addiu     $a1, $zero, 0xf4
/* 8EE224 80242404 24060042 */  addiu     $a2, $zero, 0x42
/* 8EE228 80242408 0220382D */  daddu     $a3, $s1, $zero
/* 8EE22C 8024240C AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE230 80242410 AFB00014 */  sw        $s0, 0x14($sp)
/* 8EE234 80242414 0C049DA7 */  jal       draw_number
/* 8EE238 80242418 AFB40018 */   sw       $s4, 0x18($sp)
/* 8EE23C 8024241C 9642032C */  lhu       $v0, 0x32c($s2)
/* 8EE240 80242420 1440000A */  bnez      $v0, .L8024244C
/* 8EE244 80242424 3C04000B */   lui      $a0, 0xb
/* 8EE248 80242428 348400FA */  ori       $a0, $a0, 0xfa
/* 8EE24C 8024242C 2405006D */  addiu     $a1, $zero, 0x6d
/* 8EE250 80242430 24060050 */  addiu     $a2, $zero, 0x50
/* 8EE254 80242434 0200382D */  daddu     $a3, $s0, $zero
/* 8EE258 80242438 AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE25C 8024243C 0C04993B */  jal       draw_string
/* 8EE260 80242440 AFB10014 */   sw       $s1, 0x14($sp)
/* 8EE264 80242444 08090937 */  j         .L802424DC
/* 8EE268 80242448 3C04000B */   lui      $a0, 0xb
.L8024244C:
/* 8EE26C 8024244C 348400FB */  ori       $a0, $a0, 0xfb
/* 8EE270 80242450 0C04991D */  jal       get_string_width
/* 8EE274 80242454 0000282D */   daddu    $a1, $zero, $zero
/* 8EE278 80242458 3C04000B */  lui       $a0, 0xb
/* 8EE27C 8024245C 348400FB */  ori       $a0, $a0, 0xfb
/* 8EE280 80242460 02622823 */  subu      $a1, $s3, $v0
/* 8EE284 80242464 24060050 */  addiu     $a2, $zero, 0x50
/* 8EE288 80242468 0200382D */  daddu     $a3, $s0, $zero
/* 8EE28C 8024246C AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE290 80242470 0C04993B */  jal       draw_string
/* 8EE294 80242474 AFB10014 */   sw       $s1, 0x14($sp)
/* 8EE298 80242478 240500E7 */  addiu     $a1, $zero, 0xe7
/* 8EE29C 8024247C 24060051 */  addiu     $a2, $zero, 0x51
/* 8EE2A0 80242480 9644032C */  lhu       $a0, 0x32c($s2)
/* 8EE2A4 80242484 24070001 */  addiu     $a3, $zero, 1
/* 8EE2A8 80242488 AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE2AC 8024248C AFB00014 */  sw        $s0, 0x14($sp)
/* 8EE2B0 80242490 0C049DA7 */  jal       draw_number
/* 8EE2B4 80242494 AFB50018 */   sw       $s5, 0x18($sp)
/* 8EE2B8 80242498 3C04001F */  lui       $a0, 0x1f
/* 8EE2BC 8024249C 34840034 */  ori       $a0, $a0, 0x34
/* 8EE2C0 802424A0 240500E8 */  addiu     $a1, $zero, 0xe8
/* 8EE2C4 802424A4 2406004E */  addiu     $a2, $zero, 0x4e
/* 8EE2C8 802424A8 0200382D */  daddu     $a3, $s0, $zero
/* 8EE2CC 802424AC AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE2D0 802424B0 0C04993B */  jal       draw_string
/* 8EE2D4 802424B4 AFA00014 */   sw       $zero, 0x14($sp)
/* 8EE2D8 802424B8 240400A0 */  addiu     $a0, $zero, 0xa0
/* 8EE2DC 802424BC 240500F4 */  addiu     $a1, $zero, 0xf4
/* 8EE2E0 802424C0 24060050 */  addiu     $a2, $zero, 0x50
/* 8EE2E4 802424C4 24070001 */  addiu     $a3, $zero, 1
/* 8EE2E8 802424C8 AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE2EC 802424CC AFB00014 */  sw        $s0, 0x14($sp)
/* 8EE2F0 802424D0 0C049DA7 */  jal       draw_number
/* 8EE2F4 802424D4 AFB40018 */   sw       $s4, 0x18($sp)
/* 8EE2F8 802424D8 3C04000B */  lui       $a0, 0xb
.L802424DC:
/* 8EE2FC 802424DC 348400FE */  ori       $a0, $a0, 0xfe
/* 8EE300 802424E0 0C04991D */  jal       get_string_width
/* 8EE304 802424E4 0000282D */   daddu    $a1, $zero, $zero
/* 8EE308 802424E8 86C40026 */  lh        $a0, 0x26($s6)
/* 8EE30C 802424EC 1480000C */  bnez      $a0, .L80242520
/* 8EE310 802424F0 0040182D */   daddu    $v1, $v0, $zero
/* 8EE314 802424F4 3C04000B */  lui       $a0, 0xb
/* 8EE318 802424F8 348400FA */  ori       $a0, $a0, 0xfa
/* 8EE31C 802424FC 2405006E */  addiu     $a1, $zero, 0x6e
/* 8EE320 80242500 2406005F */  addiu     $a2, $zero, 0x5f
/* 8EE324 80242504 0200382D */  daddu     $a3, $s0, $zero
/* 8EE328 80242508 24020001 */  addiu     $v0, $zero, 1
/* 8EE32C 8024250C AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE330 80242510 0C04993B */  jal       draw_string
/* 8EE334 80242514 AFA20014 */   sw       $v0, 0x14($sp)
/* 8EE338 80242518 0809097C */  j         .L802425F0
/* 8EE33C 8024251C 00000000 */   nop
.L80242520:
/* 8EE340 80242520 2402FFFF */  addiu     $v0, $zero, -1
/* 8EE344 80242524 1482000F */  bne       $a0, $v0, .L80242564
/* 8EE348 80242528 3C04000B */   lui      $a0, 0xb
/* 8EE34C 8024252C 348400FE */  ori       $a0, $a0, 0xfe
/* 8EE350 80242530 240500CE */  addiu     $a1, $zero, 0xce
/* 8EE354 80242534 00A32823 */  subu      $a1, $a1, $v1
/* 8EE358 80242538 2406005F */  addiu     $a2, $zero, 0x5f
/* 8EE35C 8024253C 0200382D */  daddu     $a3, $s0, $zero
/* 8EE360 80242540 24020001 */  addiu     $v0, $zero, 1
/* 8EE364 80242544 AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE368 80242548 0C04993B */  jal       draw_string
/* 8EE36C 8024254C AFA20014 */   sw       $v0, 0x14($sp)
/* 8EE370 80242550 0000202D */  daddu     $a0, $zero, $zero
/* 8EE374 80242554 240500E7 */  addiu     $a1, $zero, 0xe7
/* 8EE378 80242558 24060060 */  addiu     $a2, $zero, 0x60
/* 8EE37C 8024255C 08090966 */  j         .L80242598
/* 8EE380 80242560 24070001 */   addiu    $a3, $zero, 1
.L80242564:
/* 8EE384 80242564 348400FE */  ori       $a0, $a0, 0xfe
/* 8EE388 80242568 240500CE */  addiu     $a1, $zero, 0xce
/* 8EE38C 8024256C 00A32823 */  subu      $a1, $a1, $v1
/* 8EE390 80242570 2406005F */  addiu     $a2, $zero, 0x5f
/* 8EE394 80242574 0200382D */  daddu     $a3, $s0, $zero
/* 8EE398 80242578 24020001 */  addiu     $v0, $zero, 1
/* 8EE39C 8024257C AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE3A0 80242580 0C04993B */  jal       draw_string
/* 8EE3A4 80242584 AFA20014 */   sw       $v0, 0x14($sp)
/* 8EE3A8 80242588 240500E7 */  addiu     $a1, $zero, 0xe7
/* 8EE3AC 8024258C 24060060 */  addiu     $a2, $zero, 0x60
/* 8EE3B0 80242590 24070001 */  addiu     $a3, $zero, 1
/* 8EE3B4 80242594 86C40026 */  lh        $a0, 0x26($s6)
.L80242598:
/* 8EE3B8 80242598 24020003 */  addiu     $v0, $zero, 3
/* 8EE3BC 8024259C AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE3C0 802425A0 AFB00014 */  sw        $s0, 0x14($sp)
/* 8EE3C4 802425A4 0C049DA7 */  jal       draw_number
/* 8EE3C8 802425A8 AFA20018 */   sw       $v0, 0x18($sp)
/* 8EE3CC 802425AC 3C04001F */  lui       $a0, 0x1f
/* 8EE3D0 802425B0 34840034 */  ori       $a0, $a0, 0x34
/* 8EE3D4 802425B4 240500E8 */  addiu     $a1, $zero, 0xe8
/* 8EE3D8 802425B8 2406005D */  addiu     $a2, $zero, 0x5d
/* 8EE3DC 802425BC 0200382D */  daddu     $a3, $s0, $zero
/* 8EE3E0 802425C0 AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE3E4 802425C4 0C04993B */  jal       draw_string
/* 8EE3E8 802425C8 AFA00014 */   sw       $zero, 0x14($sp)
/* 8EE3EC 802425CC 240500F4 */  addiu     $a1, $zero, 0xf4
/* 8EE3F0 802425D0 2406005F */  addiu     $a2, $zero, 0x5f
/* 8EE3F4 802425D4 24070001 */  addiu     $a3, $zero, 1
/* 8EE3F8 802425D8 86C40028 */  lh        $a0, 0x28($s6)
/* 8EE3FC 802425DC 24020002 */  addiu     $v0, $zero, 2
/* 8EE400 802425E0 AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE404 802425E4 AFB00014 */  sw        $s0, 0x14($sp)
/* 8EE408 802425E8 0C049DA7 */  jal       draw_number
/* 8EE40C 802425EC AFA20018 */   sw       $v0, 0x18($sp)
.L802425F0:
/* 8EE410 802425F0 3C118011 */  lui       $s1, %hi(gPlayerData)
/* 8EE414 802425F4 2631F290 */  addiu     $s1, $s1, %lo(gPlayerData)
/* 8EE418 802425F8 962202C0 */  lhu       $v0, 0x2c0($s1)
/* 8EE41C 802425FC 1440000B */  bnez      $v0, .L8024262C
/* 8EE420 80242600 3C04000B */   lui      $a0, 0xb
/* 8EE424 80242604 348400FA */  ori       $a0, $a0, 0xfa
/* 8EE428 80242608 2405006D */  addiu     $a1, $zero, 0x6d
/* 8EE42C 8024260C 2406006E */  addiu     $a2, $zero, 0x6e
/* 8EE430 80242610 0200382D */  daddu     $a3, $s0, $zero
/* 8EE434 80242614 24020001 */  addiu     $v0, $zero, 1
/* 8EE438 80242618 AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE43C 8024261C 0C04993B */  jal       draw_string
/* 8EE440 80242620 AFA20014 */   sw       $v0, 0x14($sp)
/* 8EE444 80242624 080909B3 */  j         .L802426CC
/* 8EE448 80242628 3C04000B */   lui      $a0, 0xb
.L8024262C:
/* 8EE44C 8024262C 348400FF */  ori       $a0, $a0, 0xff
/* 8EE450 80242630 0C04991D */  jal       get_string_width
/* 8EE454 80242634 0000282D */   daddu    $a1, $zero, $zero
/* 8EE458 80242638 3C04000B */  lui       $a0, 0xb
/* 8EE45C 8024263C 348400FF */  ori       $a0, $a0, 0xff
/* 8EE460 80242640 240500CE */  addiu     $a1, $zero, 0xce
/* 8EE464 80242644 00A22823 */  subu      $a1, $a1, $v0
/* 8EE468 80242648 2406006E */  addiu     $a2, $zero, 0x6e
/* 8EE46C 8024264C 0200382D */  daddu     $a3, $s0, $zero
/* 8EE470 80242650 24020001 */  addiu     $v0, $zero, 1
/* 8EE474 80242654 AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE478 80242658 0C04993B */  jal       draw_string
/* 8EE47C 8024265C AFA20014 */   sw       $v0, 0x14($sp)
/* 8EE480 80242660 240500E7 */  addiu     $a1, $zero, 0xe7
/* 8EE484 80242664 2406006F */  addiu     $a2, $zero, 0x6f
/* 8EE488 80242668 24070001 */  addiu     $a3, $zero, 1
/* 8EE48C 8024266C AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE490 80242670 AFB00014 */  sw        $s0, 0x14($sp)
/* 8EE494 80242674 962402C2 */  lhu       $a0, 0x2c2($s1)
/* 8EE498 80242678 24020003 */  addiu     $v0, $zero, 3
/* 8EE49C 8024267C 0C049DA7 */  jal       draw_number
/* 8EE4A0 80242680 AFA20018 */   sw       $v0, 0x18($sp)
/* 8EE4A4 80242684 3C04001F */  lui       $a0, 0x1f
/* 8EE4A8 80242688 34840034 */  ori       $a0, $a0, 0x34
/* 8EE4AC 8024268C 240500E8 */  addiu     $a1, $zero, 0xe8
/* 8EE4B0 80242690 2406006C */  addiu     $a2, $zero, 0x6c
/* 8EE4B4 80242694 0200382D */  daddu     $a3, $s0, $zero
/* 8EE4B8 80242698 AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE4BC 8024269C 0C04993B */  jal       draw_string
/* 8EE4C0 802426A0 AFA00014 */   sw       $zero, 0x14($sp)
/* 8EE4C4 802426A4 240500F4 */  addiu     $a1, $zero, 0xf4
/* 8EE4C8 802426A8 2406006F */  addiu     $a2, $zero, 0x6f
/* 8EE4CC 802426AC 24070001 */  addiu     $a3, $zero, 1
/* 8EE4D0 802426B0 AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE4D4 802426B4 AFB00014 */  sw        $s0, 0x14($sp)
/* 8EE4D8 802426B8 962402C0 */  lhu       $a0, 0x2c0($s1)
/* 8EE4DC 802426BC 24020002 */  addiu     $v0, $zero, 2
/* 8EE4E0 802426C0 0C049DA7 */  jal       draw_number
/* 8EE4E4 802426C4 AFA20018 */   sw       $v0, 0x18($sp)
/* 8EE4E8 802426C8 3C04000B */  lui       $a0, 0xb
.L802426CC:
/* 8EE4EC 802426CC 348400F4 */  ori       $a0, $a0, 0xf4
/* 8EE4F0 802426D0 0C04991D */  jal       get_string_width
/* 8EE4F4 802426D4 0000282D */   daddu    $a1, $zero, $zero
/* 8EE4F8 802426D8 3C04000B */  lui       $a0, 0xb
/* 8EE4FC 802426DC 348400F4 */  ori       $a0, $a0, 0xf4
/* 8EE500 802426E0 241400CE */  addiu     $s4, $zero, 0xce
/* 8EE504 802426E4 02822823 */  subu      $a1, $s4, $v0
/* 8EE508 802426E8 2406007D */  addiu     $a2, $zero, 0x7d
/* 8EE50C 802426EC 0200382D */  daddu     $a3, $s0, $zero
/* 8EE510 802426F0 24120001 */  addiu     $s2, $zero, 1
/* 8EE514 802426F4 AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE518 802426F8 0C04993B */  jal       draw_string
/* 8EE51C 802426FC AFB20014 */   sw       $s2, 0x14($sp)
/* 8EE520 80242700 240500D8 */  addiu     $a1, $zero, 0xd8
/* 8EE524 80242704 2406007E */  addiu     $a2, $zero, 0x7e
/* 8EE528 80242708 0240382D */  daddu     $a3, $s2, $zero
/* 8EE52C 8024270C 3C118011 */  lui       $s1, %hi(gPlayerData)
/* 8EE530 80242710 2631F290 */  addiu     $s1, $s1, %lo(gPlayerData)
/* 8EE534 80242714 AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE538 80242718 AFB00014 */  sw        $s0, 0x14($sp)
/* 8EE53C 8024271C 962402A2 */  lhu       $a0, 0x2a2($s1)
/* 8EE540 80242720 24130002 */  addiu     $s3, $zero, 2
/* 8EE544 80242724 0C049DA7 */  jal       draw_number
/* 8EE548 80242728 AFB30018 */   sw       $s3, 0x18($sp)
/* 8EE54C 8024272C 3C04000B */  lui       $a0, 0xb
/* 8EE550 80242730 348400F7 */  ori       $a0, $a0, 0xf7
/* 8EE554 80242734 0C04991D */  jal       get_string_width
/* 8EE558 80242738 0000282D */   daddu    $a1, $zero, $zero
/* 8EE55C 8024273C 3C04000B */  lui       $a0, 0xb
/* 8EE560 80242740 348400F7 */  ori       $a0, $a0, 0xf7
/* 8EE564 80242744 02822823 */  subu      $a1, $s4, $v0
/* 8EE568 80242748 2406008C */  addiu     $a2, $zero, 0x8c
/* 8EE56C 8024274C 0200382D */  daddu     $a3, $s0, $zero
/* 8EE570 80242750 AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE574 80242754 0C04993B */  jal       draw_string
/* 8EE578 80242758 AFB20014 */   sw       $s2, 0x14($sp)
/* 8EE57C 8024275C 240500D8 */  addiu     $a1, $zero, 0xd8
/* 8EE580 80242760 2406008D */  addiu     $a2, $zero, 0x8d
/* 8EE584 80242764 9624029C */  lhu       $a0, 0x29c($s1)
/* 8EE588 80242768 0240382D */  daddu     $a3, $s2, $zero
/* 8EE58C 8024276C AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE590 80242770 AFB00014 */  sw        $s0, 0x14($sp)
/* 8EE594 80242774 0C049DA7 */  jal       draw_number
/* 8EE598 80242778 AFB30018 */   sw       $s3, 0x18($sp)
/* 8EE59C 8024277C 3C04000B */  lui       $a0, 0xb
/* 8EE5A0 80242780 348400F8 */  ori       $a0, $a0, 0xf8
/* 8EE5A4 80242784 0C04991D */  jal       get_string_width
/* 8EE5A8 80242788 0000282D */   daddu    $a1, $zero, $zero
/* 8EE5AC 8024278C 3C04000B */  lui       $a0, 0xb
/* 8EE5B0 80242790 348400F8 */  ori       $a0, $a0, 0xf8
/* 8EE5B4 80242794 02822823 */  subu      $a1, $s4, $v0
/* 8EE5B8 80242798 2406009B */  addiu     $a2, $zero, 0x9b
/* 8EE5BC 8024279C 0200382D */  daddu     $a3, $s0, $zero
/* 8EE5C0 802427A0 AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE5C4 802427A4 0C04993B */  jal       draw_string
/* 8EE5C8 802427A8 AFB20014 */   sw       $s2, 0x14($sp)
/* 8EE5CC 802427AC 240500D8 */  addiu     $a1, $zero, 0xd8
/* 8EE5D0 802427B0 2406009C */  addiu     $a2, $zero, 0x9c
/* 8EE5D4 802427B4 9624029E */  lhu       $a0, 0x29e($s1)
/* 8EE5D8 802427B8 0240382D */  daddu     $a3, $s2, $zero
/* 8EE5DC 802427BC AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE5E0 802427C0 AFB00014 */  sw        $s0, 0x14($sp)
/* 8EE5E4 802427C4 0C049DA7 */  jal       draw_number
/* 8EE5E8 802427C8 AFB30018 */   sw       $s3, 0x18($sp)
/* 8EE5EC 802427CC 962202A0 */  lhu       $v0, 0x2a0($s1)
/* 8EE5F0 802427D0 1440000A */  bnez      $v0, .L802427FC
/* 8EE5F4 802427D4 3C04000B */   lui      $a0, 0xb
/* 8EE5F8 802427D8 348400FA */  ori       $a0, $a0, 0xfa
/* 8EE5FC 802427DC 2405006D */  addiu     $a1, $zero, 0x6d
/* 8EE600 802427E0 240600AA */  addiu     $a2, $zero, 0xaa
/* 8EE604 802427E4 0200382D */  daddu     $a3, $s0, $zero
/* 8EE608 802427E8 AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE60C 802427EC 0C04993B */  jal       draw_string
/* 8EE610 802427F0 AFB20014 */   sw       $s2, 0x14($sp)
/* 8EE614 802427F4 08090A12 */  j         .L80242848
/* 8EE618 802427F8 00000000 */   nop
.L802427FC:
/* 8EE61C 802427FC 348400F9 */  ori       $a0, $a0, 0xf9
/* 8EE620 80242800 0C04991D */  jal       get_string_width
/* 8EE624 80242804 0000282D */   daddu    $a1, $zero, $zero
/* 8EE628 80242808 3C04000B */  lui       $a0, 0xb
/* 8EE62C 8024280C 348400F9 */  ori       $a0, $a0, 0xf9
/* 8EE630 80242810 02822823 */  subu      $a1, $s4, $v0
/* 8EE634 80242814 240600AA */  addiu     $a2, $zero, 0xaa
/* 8EE638 80242818 0200382D */  daddu     $a3, $s0, $zero
/* 8EE63C 8024281C AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE640 80242820 0C04993B */  jal       draw_string
/* 8EE644 80242824 AFB20014 */   sw       $s2, 0x14($sp)
/* 8EE648 80242828 240500D8 */  addiu     $a1, $zero, 0xd8
/* 8EE64C 8024282C 240600AB */  addiu     $a2, $zero, 0xab
/* 8EE650 80242830 962402A0 */  lhu       $a0, 0x2a0($s1)
/* 8EE654 80242834 24070001 */  addiu     $a3, $zero, 1
/* 8EE658 80242838 AFA00010 */  sw        $zero, 0x10($sp)
/* 8EE65C 8024283C AFB00014 */  sw        $s0, 0x14($sp)
/* 8EE660 80242840 0C049DA7 */  jal       draw_number
/* 8EE664 80242844 AFB30018 */   sw       $s3, 0x18($sp)
.L80242848:
/* 8EE668 80242848 8FBF0044 */  lw        $ra, 0x44($sp)
/* 8EE66C 8024284C 8FB60040 */  lw        $s6, 0x40($sp)
/* 8EE670 80242850 8FB5003C */  lw        $s5, 0x3c($sp)
/* 8EE674 80242854 8FB40038 */  lw        $s4, 0x38($sp)
/* 8EE678 80242858 8FB30034 */  lw        $s3, 0x34($sp)
/* 8EE67C 8024285C 8FB20030 */  lw        $s2, 0x30($sp)
/* 8EE680 80242860 8FB1002C */  lw        $s1, 0x2c($sp)
/* 8EE684 80242864 8FB00028 */  lw        $s0, 0x28($sp)
/* 8EE688 80242868 03E00008 */  jr        $ra
/* 8EE68C 8024286C 27BD0048 */   addiu    $sp, $sp, 0x48
