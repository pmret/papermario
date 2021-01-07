.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD2B4
/* 31CE24 802BD2B4 3C028011 */  lui       $v0, %hi(D_8010EBB1)
/* 31CE28 802BD2B8 8042EBB1 */  lb        $v0, %lo(D_8010EBB1)($v0)
/* 31CE2C 802BD2BC 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 31CE30 802BD2C0 AFB00018 */  sw        $s0, 0x18($sp)
/* 31CE34 802BD2C4 3C108011 */  lui       $s0, %hi(gPlayerData)
/* 31CE38 802BD2C8 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* 31CE3C 802BD2CC AFBF0028 */  sw        $ra, 0x28($sp)
/* 31CE40 802BD2D0 AFB30024 */  sw        $s3, 0x24($sp)
/* 31CE44 802BD2D4 AFB20020 */  sw        $s2, 0x20($sp)
/* 31CE48 802BD2D8 AFB1001C */  sw        $s1, 0x1c($sp)
/* 31CE4C 802BD2DC F7B40030 */  sdc1      $f20, 0x30($sp)
/* 31CE50 802BD2E0 8C91014C */  lw        $s1, 0x14c($a0)
/* 31CE54 802BD2E4 14400102 */  bnez      $v0, .L802BD6F0
/* 31CE58 802BD2E8 0000102D */   daddu    $v0, $zero, $zero
/* 31CE5C 802BD2EC 10A00009 */  beqz      $a1, .L802BD314
/* 31CE60 802BD2F0 0220202D */   daddu    $a0, $s1, $zero
/* 31CE64 802BD2F4 0C03B4C4 */  jal       enable_partner_flying
/* 31CE68 802BD2F8 24050001 */   addiu    $a1, $zero, 1
/* 31CE6C 802BD2FC 3C04802C */  lui       $a0, %hi(D_802BE274)
/* 31CE70 802BD300 8C84E274 */  lw        $a0, %lo(D_802BE274)($a0)
/* 31CE74 802BD304 0C00A580 */  jal       mem_clear
/* 31CE78 802BD308 2405001C */   addiu    $a1, $zero, 0x1c
/* 31CE7C 802BD30C 3C018011 */  lui       $at, %hi(D_8010C954)
/* 31CE80 802BD310 AC20C954 */  sw        $zero, %lo(D_8010C954)($at)
.L802BD314:
/* 31CE84 802BD314 3C138011 */  lui       $s3, %hi(D_8010C954)
/* 31CE88 802BD318 2673C954 */  addiu     $s3, $s3, %lo(D_8010C954)
/* 31CE8C 802BD31C 8E02030C */  lw        $v0, 0x30c($s0)
/* 31CE90 802BD320 8E720000 */  lw        $s2, ($s3)
/* 31CE94 802BD324 24420001 */  addiu     $v0, $v0, 1
/* 31CE98 802BD328 16400026 */  bnez      $s2, .L802BD3C4
/* 31CE9C 802BD32C AE02030C */   sw       $v0, 0x30c($s0)
/* 31CEA0 802BD330 0C0AF440 */  jal       func_802BD100
/* 31CEA4 802BD334 0220202D */   daddu    $a0, $s1, $zero
/* 31CEA8 802BD338 0C03B52E */  jal       update_player_move_history
/* 31CEAC 802BD33C 0220202D */   daddu    $a0, $s1, $zero
/* 31CEB0 802BD340 0C03B574 */  jal       func_800ED5D0
/* 31CEB4 802BD344 0220202D */   daddu    $a0, $s1, $zero
/* 31CEB8 802BD348 C6220018 */  lwc1      $f2, 0x18($s1)
/* 31CEBC 802BD34C 44800000 */  mtc1      $zero, $f0
/* 31CEC0 802BD350 00000000 */  nop       
/* 31CEC4 802BD354 46001032 */  c.eq.s    $f2, $f0
/* 31CEC8 802BD358 00000000 */  nop       
/* 31CECC 802BD35C 4501000D */  bc1t      .L802BD394
/* 31CED0 802BD360 00000000 */   nop      
/* 31CED4 802BD364 3C03802C */  lui       $v1, %hi(D_802BE278)
/* 31CED8 802BD368 2463E278 */  addiu     $v1, $v1, %lo(D_802BE278)
/* 31CEDC 802BD36C 8C620000 */  lw        $v0, ($v1)
/* 31CEE0 802BD370 144000CE */  bnez      $v0, .L802BD6AC
/* 31CEE4 802BD374 00000000 */   nop      
/* 31CEE8 802BD378 24040001 */  addiu     $a0, $zero, 1
/* 31CEEC 802BD37C 0080102D */  daddu     $v0, $a0, $zero
/* 31CEF0 802BD380 0C0AF46B */  jal       func_802BD1AC
/* 31CEF4 802BD384 AC620000 */   sw       $v0, ($v1)
/* 31CEF8 802BD388 3C020006 */  lui       $v0, 6
/* 31CEFC 802BD38C 080AF4EF */  j         .L802BD3BC
/* 31CF00 802BD390 34420003 */   ori      $v0, $v0, 3
.L802BD394:
/* 31CF04 802BD394 3C03802C */  lui       $v1, %hi(D_802BE278)
/* 31CF08 802BD398 2463E278 */  addiu     $v1, $v1, %lo(D_802BE278)
/* 31CF0C 802BD39C 8C620000 */  lw        $v0, ($v1)
/* 31CF10 802BD3A0 104000C2 */  beqz      $v0, .L802BD6AC
/* 31CF14 802BD3A4 00000000 */   nop      
/* 31CF18 802BD3A8 0000202D */  daddu     $a0, $zero, $zero
/* 31CF1C 802BD3AC 0C0AF46B */  jal       func_802BD1AC
/* 31CF20 802BD3B0 AC600000 */   sw       $zero, ($v1)
/* 31CF24 802BD3B4 3C020006 */  lui       $v0, 6
/* 31CF28 802BD3B8 34420001 */  ori       $v0, $v0, 1
.L802BD3BC:
/* 31CF2C 802BD3BC 080AF5AB */  j         .L802BD6AC
/* 31CF30 802BD3C0 AE220028 */   sw       $v0, 0x28($s1)
.L802BD3C4:
/* 31CF34 802BD3C4 3C10802C */  lui       $s0, %hi(D_802BE274)
/* 31CF38 802BD3C8 2610E274 */  addiu     $s0, $s0, %lo(D_802BE274)
/* 31CF3C 802BD3CC 8E040000 */  lw        $a0, ($s0)
/* 31CF40 802BD3D0 8C830004 */  lw        $v1, 4($a0)
/* 31CF44 802BD3D4 24050001 */  addiu     $a1, $zero, 1
/* 31CF48 802BD3D8 1065002F */  beq       $v1, $a1, .L802BD498
/* 31CF4C 802BD3DC 28620002 */   slti     $v0, $v1, 2
/* 31CF50 802BD3E0 50400005 */  beql      $v0, $zero, .L802BD3F8
/* 31CF54 802BD3E4 24020002 */   addiu    $v0, $zero, 2
/* 31CF58 802BD3E8 50600009 */  beql      $v1, $zero, .L802BD410
/* 31CF5C 802BD3EC AC850004 */   sw       $a1, 4($a0)
/* 31CF60 802BD3F0 080AF5AB */  j         .L802BD6AC
/* 31CF64 802BD3F4 00000000 */   nop      
.L802BD3F8:
/* 31CF68 802BD3F8 10620099 */  beq       $v1, $v0, .L802BD660
/* 31CF6C 802BD3FC 24020003 */   addiu    $v0, $zero, 3
/* 31CF70 802BD400 1062009F */  beq       $v1, $v0, .L802BD680
/* 31CF74 802BD404 00000000 */   nop      
/* 31CF78 802BD408 080AF5AB */  j         .L802BD6AC
/* 31CF7C 802BD40C 00000000 */   nop      
.L802BD410:
/* 31CF80 802BD410 8E220000 */  lw        $v0, ($s1)
/* 31CF84 802BD414 AC820008 */  sw        $v0, 8($a0)
/* 31CF88 802BD418 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 31CF8C 802BD41C C62E0040 */  lwc1      $f14, 0x40($s1)
/* 31CF90 802BD420 8E460048 */  lw        $a2, 0x48($s2)
/* 31CF94 802BD424 0C00A7B5 */  jal       dist2D
/* 31CF98 802BD428 8E470050 */   lw       $a3, 0x50($s2)
/* 31CF9C 802BD42C 8E020000 */  lw        $v0, ($s0)
/* 31CFA0 802BD430 46000005 */  abs.s     $f0, $f0
/* 31CFA4 802BD434 E440000C */  swc1      $f0, 0xc($v0)
/* 31CFA8 802BD438 C64C0048 */  lwc1      $f12, 0x48($s2)
/* 31CFAC 802BD43C C64E0050 */  lwc1      $f14, 0x50($s2)
/* 31CFB0 802BD440 8E260038 */  lw        $a2, 0x38($s1)
/* 31CFB4 802BD444 0C00A720 */  jal       atan2
/* 31CFB8 802BD448 8E270040 */   lw       $a3, 0x40($s1)
/* 31CFBC 802BD44C 3C040004 */  lui       $a0, 4
/* 31CFC0 802BD450 24020078 */  addiu     $v0, $zero, 0x78
/* 31CFC4 802BD454 8E030000 */  lw        $v1, ($s0)
/* 31CFC8 802BD458 3C0140C0 */  lui       $at, 0x40c0
/* 31CFCC 802BD45C 44811000 */  mtc1      $at, $f2
/* 31CFD0 802BD460 3C014248 */  lui       $at, 0x4248
/* 31CFD4 802BD464 44812000 */  mtc1      $at, $f4
/* 31CFD8 802BD468 34840148 */  ori       $a0, $a0, 0x148
/* 31CFDC 802BD46C E4600010 */  swc1      $f0, 0x10($v1)
/* 31CFE0 802BD470 E4620014 */  swc1      $f2, 0x14($v1)
/* 31CFE4 802BD474 E4640018 */  swc1      $f4, 0x18($v1)
/* 31CFE8 802BD478 AC620000 */  sw        $v0, ($v1)
/* 31CFEC 802BD47C 8E220000 */  lw        $v0, ($s1)
/* 31CFF0 802BD480 2403FDFF */  addiu     $v1, $zero, -0x201
/* 31CFF4 802BD484 00441025 */  or        $v0, $v0, $a0
/* 31CFF8 802BD488 00431024 */  and       $v0, $v0, $v1
/* 31CFFC 802BD48C AE220000 */  sw        $v0, ($s1)
/* 31D000 802BD490 3C10802C */  lui       $s0, %hi(D_802BE274)
/* 31D004 802BD494 2610E274 */  addiu     $s0, $s0, %lo(D_802BE274)
.L802BD498:
/* 31D008 802BD498 8E020000 */  lw        $v0, ($s0)
/* 31D00C 802BD49C 3C0140C9 */  lui       $at, 0x40c9
/* 31D010 802BD4A0 34210FD0 */  ori       $at, $at, 0xfd0
/* 31D014 802BD4A4 44810000 */  mtc1      $at, $f0
/* 31D018 802BD4A8 C44C0010 */  lwc1      $f12, 0x10($v0)
/* 31D01C 802BD4AC 46006302 */  mul.s     $f12, $f12, $f0
/* 31D020 802BD4B0 00000000 */  nop       
/* 31D024 802BD4B4 27A50010 */  addiu     $a1, $sp, 0x10
/* 31D028 802BD4B8 3C0143B4 */  lui       $at, 0x43b4
/* 31D02C 802BD4BC 44810000 */  mtc1      $at, $f0
/* 31D030 802BD4C0 27A60014 */  addiu     $a2, $sp, 0x14
/* 31D034 802BD4C4 0C00A82D */  jal       sin_cos_rad
/* 31D038 802BD4C8 46006303 */   div.s    $f12, $f12, $f0
/* 31D03C 802BD4CC 8E020000 */  lw        $v0, ($s0)
/* 31D040 802BD4D0 C7A20010 */  lwc1      $f2, 0x10($sp)
/* 31D044 802BD4D4 C440000C */  lwc1      $f0, 0xc($v0)
/* 31D048 802BD4D8 46001082 */  mul.s     $f2, $f2, $f0
/* 31D04C 802BD4DC 00000000 */  nop       
/* 31D050 802BD4E0 C6400048 */  lwc1      $f0, 0x48($s2)
/* 31D054 802BD4E4 46020000 */  add.s     $f0, $f0, $f2
/* 31D058 802BD4E8 E6200038 */  swc1      $f0, 0x38($s1)
/* 31D05C 802BD4EC C7A20014 */  lwc1      $f2, 0x14($sp)
/* 31D060 802BD4F0 C440000C */  lwc1      $f0, 0xc($v0)
/* 31D064 802BD4F4 46001082 */  mul.s     $f2, $f2, $f0
/* 31D068 802BD4F8 00000000 */  nop       
/* 31D06C 802BD4FC C6400050 */  lwc1      $f0, 0x50($s2)
/* 31D070 802BD500 46020001 */  sub.s     $f0, $f0, $f2
/* 31D074 802BD504 E6200040 */  swc1      $f0, 0x40($s1)
/* 31D078 802BD508 C4400010 */  lwc1      $f0, 0x10($v0)
/* 31D07C 802BD50C C44C0014 */  lwc1      $f12, 0x14($v0)
/* 31D080 802BD510 0C00A6C9 */  jal       clamp_angle
/* 31D084 802BD514 460C0301 */   sub.s    $f12, $f0, $f12
/* 31D088 802BD518 8E100000 */  lw        $s0, ($s0)
/* 31D08C 802BD51C 3C0141A0 */  lui       $at, 0x41a0
/* 31D090 802BD520 44811000 */  mtc1      $at, $f2
/* 31D094 802BD524 C604000C */  lwc1      $f4, 0xc($s0)
/* 31D098 802BD528 4604103C */  c.lt.s    $f2, $f4
/* 31D09C 802BD52C 00000000 */  nop       
/* 31D0A0 802BD530 45000005 */  bc1f      .L802BD548
/* 31D0A4 802BD534 E6000010 */   swc1     $f0, 0x10($s0)
/* 31D0A8 802BD538 3C013F80 */  lui       $at, 0x3f80
/* 31D0AC 802BD53C 44810000 */  mtc1      $at, $f0
/* 31D0B0 802BD540 080AF55D */  j         .L802BD574
/* 31D0B4 802BD544 46002001 */   sub.s    $f0, $f4, $f0
.L802BD548:
/* 31D0B8 802BD548 3C014198 */  lui       $at, 0x4198
/* 31D0BC 802BD54C 44810000 */  mtc1      $at, $f0
/* 31D0C0 802BD550 00000000 */  nop       
/* 31D0C4 802BD554 4600203C */  c.lt.s    $f4, $f0
/* 31D0C8 802BD558 00000000 */  nop       
/* 31D0CC 802BD55C 45000006 */  bc1f      .L802BD578
/* 31D0D0 802BD560 00000000 */   nop      
/* 31D0D4 802BD564 3C013F80 */  lui       $at, 0x3f80
/* 31D0D8 802BD568 44810000 */  mtc1      $at, $f0
/* 31D0DC 802BD56C 00000000 */  nop       
/* 31D0E0 802BD570 46002000 */  add.s     $f0, $f4, $f0
.L802BD574:
/* 31D0E4 802BD574 E600000C */  swc1      $f0, 0xc($s0)
.L802BD578:
/* 31D0E8 802BD578 3C10802C */  lui       $s0, %hi(D_802BE274)
/* 31D0EC 802BD57C 2610E274 */  addiu     $s0, $s0, %lo(D_802BE274)
/* 31D0F0 802BD580 8E020000 */  lw        $v0, ($s0)
/* 31D0F4 802BD584 3C0140C9 */  lui       $at, 0x40c9
/* 31D0F8 802BD588 34210FD0 */  ori       $at, $at, 0xfd0
/* 31D0FC 802BD58C 44810000 */  mtc1      $at, $f0
/* 31D100 802BD590 C44C0018 */  lwc1      $f12, 0x18($v0)
/* 31D104 802BD594 46006302 */  mul.s     $f12, $f12, $f0
/* 31D108 802BD598 00000000 */  nop       
/* 31D10C 802BD59C 3C0143B4 */  lui       $at, 0x43b4
/* 31D110 802BD5A0 4481A000 */  mtc1      $at, $f20
/* 31D114 802BD5A4 0C00A85B */  jal       sin_rad
/* 31D118 802BD5A8 46146303 */   div.s    $f12, $f12, $f20
/* 31D11C 802BD5AC 8E020000 */  lw        $v0, ($s0)
/* 31D120 802BD5B0 3C014040 */  lui       $at, 0x4040
/* 31D124 802BD5B4 44812000 */  mtc1      $at, $f4
/* 31D128 802BD5B8 C4420018 */  lwc1      $f2, 0x18($v0)
/* 31D12C 802BD5BC 46041080 */  add.s     $f2, $f2, $f4
/* 31D130 802BD5C0 3C014316 */  lui       $at, 0x4316
/* 31D134 802BD5C4 44813000 */  mtc1      $at, $f6
/* 31D138 802BD5C8 00000000 */  nop       
/* 31D13C 802BD5CC 4602303C */  c.lt.s    $f6, $f2
/* 31D140 802BD5D0 E4420018 */  swc1      $f2, 0x18($v0)
/* 31D144 802BD5D4 46040082 */  mul.s     $f2, $f0, $f4
/* 31D148 802BD5D8 00000000 */  nop       
/* 31D14C 802BD5DC 45030001 */  bc1tl     .L802BD5E4
/* 31D150 802BD5E0 E4460018 */   swc1     $f6, 0x18($v0)
.L802BD5E4:
/* 31D154 802BD5E4 C620003C */  lwc1      $f0, 0x3c($s1)
/* 31D158 802BD5E8 46020000 */  add.s     $f0, $f0, $f2
/* 31D15C 802BD5EC 8E020000 */  lw        $v0, ($s0)
/* 31D160 802BD5F0 E620003C */  swc1      $f0, 0x3c($s1)
/* 31D164 802BD5F4 C44C0010 */  lwc1      $f12, 0x10($v0)
/* 31D168 802BD5F8 0C00A6C9 */  jal       clamp_angle
/* 31D16C 802BD5FC 460CA301 */   sub.s    $f12, $f20, $f12
/* 31D170 802BD600 8E020000 */  lw        $v0, ($s0)
/* 31D174 802BD604 E6200034 */  swc1      $f0, 0x34($s1)
/* 31D178 802BD608 C4400014 */  lwc1      $f0, 0x14($v0)
/* 31D17C 802BD60C 3C01802C */  lui       $at, %hi(D_802BE2F0)
/* 31D180 802BD610 D422E2F0 */  ldc1      $f2, %lo(D_802BE2F0)($at)
/* 31D184 802BD614 46000021 */  cvt.d.s   $f0, $f0
/* 31D188 802BD618 46220000 */  add.d     $f0, $f0, $f2
/* 31D18C 802BD61C 3C014220 */  lui       $at, 0x4220
/* 31D190 802BD620 44811000 */  mtc1      $at, $f2
/* 31D194 802BD624 46200020 */  cvt.s.d   $f0, $f0
/* 31D198 802BD628 4600103C */  c.lt.s    $f2, $f0
/* 31D19C 802BD62C 00000000 */  nop       
/* 31D1A0 802BD630 45000002 */  bc1f      .L802BD63C
/* 31D1A4 802BD634 E4400014 */   swc1     $f0, 0x14($v0)
/* 31D1A8 802BD638 E4420014 */  swc1      $f2, 0x14($v0)
.L802BD63C:
/* 31D1AC 802BD63C 8E030000 */  lw        $v1, ($s0)
/* 31D1B0 802BD640 8C620000 */  lw        $v0, ($v1)
/* 31D1B4 802BD644 2442FFFF */  addiu     $v0, $v0, -1
/* 31D1B8 802BD648 14400018 */  bnez      $v0, .L802BD6AC
/* 31D1BC 802BD64C AC620000 */   sw       $v0, ($v1)
/* 31D1C0 802BD650 8C620004 */  lw        $v0, 4($v1)
/* 31D1C4 802BD654 24420001 */  addiu     $v0, $v0, 1
/* 31D1C8 802BD658 080AF5AB */  j         .L802BD6AC
/* 31D1CC 802BD65C AC620004 */   sw       $v0, 4($v1)
.L802BD660:
/* 31D1D0 802BD660 8C820008 */  lw        $v0, 8($a0)
/* 31D1D4 802BD664 AE220000 */  sw        $v0, ($s1)
/* 31D1D8 802BD668 8C820004 */  lw        $v0, 4($a0)
/* 31D1DC 802BD66C 2403001E */  addiu     $v1, $zero, 0x1e
/* 31D1E0 802BD670 AC830000 */  sw        $v1, ($a0)
/* 31D1E4 802BD674 24420001 */  addiu     $v0, $v0, 1
/* 31D1E8 802BD678 080AF5AB */  j         .L802BD6AC
/* 31D1EC 802BD67C AC820004 */   sw       $v0, 4($a0)
.L802BD680:
/* 31D1F0 802BD680 0C03B52E */  jal       update_player_move_history
/* 31D1F4 802BD684 0220202D */   daddu    $a0, $s1, $zero
/* 31D1F8 802BD688 0C03B574 */  jal       func_800ED5D0
/* 31D1FC 802BD68C 0220202D */   daddu    $a0, $s1, $zero
/* 31D200 802BD690 8E030000 */  lw        $v1, ($s0)
/* 31D204 802BD694 8C620000 */  lw        $v0, ($v1)
/* 31D208 802BD698 2442FFFF */  addiu     $v0, $v0, -1
/* 31D20C 802BD69C 14400003 */  bnez      $v0, .L802BD6AC
/* 31D210 802BD6A0 AC620000 */   sw       $v0, ($v1)
/* 31D214 802BD6A4 AC600004 */  sw        $zero, 4($v1)
/* 31D218 802BD6A8 AE600000 */  sw        $zero, ($s3)
.L802BD6AC:
/* 31D21C 802BD6AC 3C03802C */  lui       $v1, %hi(D_802BE310)
/* 31D220 802BD6B0 8C63E310 */  lw        $v1, %lo(D_802BE310)($v1)
/* 31D224 802BD6B4 1060000E */  beqz      $v1, .L802BD6F0
/* 31D228 802BD6B8 0000102D */   daddu    $v0, $zero, $zero
/* 31D22C 802BD6BC 8C62000C */  lw        $v0, 0xc($v1)
/* 31D230 802BD6C0 C6200038 */  lwc1      $f0, 0x38($s1)
/* 31D234 802BD6C4 3C014150 */  lui       $at, 0x4150
/* 31D238 802BD6C8 44811000 */  mtc1      $at, $f2
/* 31D23C 802BD6CC E4400004 */  swc1      $f0, 4($v0)
/* 31D240 802BD6D0 C620003C */  lwc1      $f0, 0x3c($s1)
/* 31D244 802BD6D4 46020000 */  add.s     $f0, $f0, $f2
/* 31D248 802BD6D8 8C62000C */  lw        $v0, 0xc($v1)
/* 31D24C 802BD6DC E4400008 */  swc1      $f0, 8($v0)
/* 31D250 802BD6E0 8C62000C */  lw        $v0, 0xc($v1)
/* 31D254 802BD6E4 C6200040 */  lwc1      $f0, 0x40($s1)
/* 31D258 802BD6E8 E440000C */  swc1      $f0, 0xc($v0)
/* 31D25C 802BD6EC 0000102D */  daddu     $v0, $zero, $zero
.L802BD6F0:
/* 31D260 802BD6F0 8FBF0028 */  lw        $ra, 0x28($sp)
/* 31D264 802BD6F4 8FB30024 */  lw        $s3, 0x24($sp)
/* 31D268 802BD6F8 8FB20020 */  lw        $s2, 0x20($sp)
/* 31D26C 802BD6FC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 31D270 802BD700 8FB00018 */  lw        $s0, 0x18($sp)
/* 31D274 802BD704 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 31D278 802BD708 03E00008 */  jr        $ra
/* 31D27C 802BD70C 27BD0038 */   addiu    $sp, $sp, 0x38
