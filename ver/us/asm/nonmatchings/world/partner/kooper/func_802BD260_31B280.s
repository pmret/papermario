.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802BEBC0_31CBE0
.double 0.8

.section .text

glabel func_802BD260_31B280
/* 31B280 802BD260 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 31B284 802BD264 AFB00018 */  sw        $s0, 0x18($sp)
/* 31B288 802BD268 3C108011 */  lui       $s0, %hi(gPlayerData)
/* 31B28C 802BD26C 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* 31B290 802BD270 AFBF0028 */  sw        $ra, 0x28($sp)
/* 31B294 802BD274 AFB30024 */  sw        $s3, 0x24($sp)
/* 31B298 802BD278 AFB20020 */  sw        $s2, 0x20($sp)
/* 31B29C 802BD27C AFB1001C */  sw        $s1, 0x1c($sp)
/* 31B2A0 802BD280 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 31B2A4 802BD284 8C91014C */  lw        $s1, 0x14c($a0)
/* 31B2A8 802BD288 10A00009 */  beqz      $a1, .L802BD2B0
/* 31B2AC 802BD28C 0220202D */   daddu    $a0, $s1, $zero
/* 31B2B0 802BD290 0C03AE2A */  jal       partner_walking_enable
/* 31B2B4 802BD294 24050001 */   addiu    $a1, $zero, 1
/* 31B2B8 802BD298 3C04802C */  lui       $a0, %hi(D_802BEB60_31CB80)
/* 31B2BC 802BD29C 8C84EB60 */  lw        $a0, %lo(D_802BEB60_31CB80)($a0)
/* 31B2C0 802BD2A0 0C00A580 */  jal       mem_clear
/* 31B2C4 802BD2A4 2405001C */   addiu    $a1, $zero, 0x1c
/* 31B2C8 802BD2A8 3C018011 */  lui       $at, %hi(D_8010C954)
/* 31B2CC 802BD2AC AC20C954 */  sw        $zero, %lo(D_8010C954)($at)
.L802BD2B0:
/* 31B2D0 802BD2B0 3C138011 */  lui       $s3, %hi(D_8010C954)
/* 31B2D4 802BD2B4 2673C954 */  addiu     $s3, $s3, %lo(D_8010C954)
/* 31B2D8 802BD2B8 8E0202FC */  lw        $v0, 0x2fc($s0)
/* 31B2DC 802BD2BC 8E720000 */  lw        $s2, ($s3)
/* 31B2E0 802BD2C0 24420001 */  addiu     $v0, $v0, 1
/* 31B2E4 802BD2C4 16400007 */  bnez      $s2, .L802BD2E4
/* 31B2E8 802BD2C8 AE0202FC */   sw       $v0, 0x2fc($s0)
/* 31B2EC 802BD2CC 0C03AE8F */  jal       partner_walking_update_player_tracking
/* 31B2F0 802BD2D0 0220202D */   daddu    $a0, $s1, $zero
/* 31B2F4 802BD2D4 0C03AED0 */  jal       partner_walking_update_motion
/* 31B2F8 802BD2D8 0220202D */   daddu    $a0, $s1, $zero
/* 31B2FC 802BD2DC 080AF575 */  j         .L802BD5D4
/* 31B300 802BD2E0 0000102D */   daddu    $v0, $zero, $zero
.L802BD2E4:
/* 31B304 802BD2E4 3C10802C */  lui       $s0, %hi(D_802BEB60_31CB80)
/* 31B308 802BD2E8 2610EB60 */  addiu     $s0, $s0, %lo(D_802BEB60_31CB80)
/* 31B30C 802BD2EC 8E040000 */  lw        $a0, ($s0)
/* 31B310 802BD2F0 8C830004 */  lw        $v1, 4($a0)
/* 31B314 802BD2F4 24050001 */  addiu     $a1, $zero, 1
/* 31B318 802BD2F8 10650030 */  beq       $v1, $a1, .L802BD3BC
/* 31B31C 802BD2FC 28620002 */   slti     $v0, $v1, 2
/* 31B320 802BD300 10400005 */  beqz      $v0, .L802BD318
/* 31B324 802BD304 24020002 */   addiu    $v0, $zero, 2
/* 31B328 802BD308 10600009 */  beqz      $v1, .L802BD330
/* 31B32C 802BD30C 0000102D */   daddu    $v0, $zero, $zero
/* 31B330 802BD310 080AF575 */  j         .L802BD5D4
/* 31B334 802BD314 00000000 */   nop
.L802BD318:
/* 31B338 802BD318 1062009A */  beq       $v1, $v0, .L802BD584
/* 31B33C 802BD31C 24020003 */   addiu    $v0, $zero, 3
/* 31B340 802BD320 106200A0 */  beq       $v1, $v0, .L802BD5A4
/* 31B344 802BD324 0000102D */   daddu    $v0, $zero, $zero
/* 31B348 802BD328 080AF575 */  j         .L802BD5D4
/* 31B34C 802BD32C 00000000 */   nop
.L802BD330:
/* 31B350 802BD330 AC850004 */  sw        $a1, 4($a0)
/* 31B354 802BD334 8E220000 */  lw        $v0, ($s1)
/* 31B358 802BD338 AC820008 */  sw        $v0, 8($a0)
/* 31B35C 802BD33C C62C0038 */  lwc1      $f12, 0x38($s1)
/* 31B360 802BD340 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 31B364 802BD344 8E460048 */  lw        $a2, 0x48($s2)
/* 31B368 802BD348 0C00A7B5 */  jal       dist2D
/* 31B36C 802BD34C 8E470050 */   lw       $a3, 0x50($s2)
/* 31B370 802BD350 8E020000 */  lw        $v0, ($s0)
/* 31B374 802BD354 46000005 */  abs.s     $f0, $f0
/* 31B378 802BD358 E440000C */  swc1      $f0, 0xc($v0)
/* 31B37C 802BD35C C64C0048 */  lwc1      $f12, 0x48($s2)
/* 31B380 802BD360 C64E0050 */  lwc1      $f14, 0x50($s2)
/* 31B384 802BD364 8E260038 */  lw        $a2, 0x38($s1)
/* 31B388 802BD368 0C00A720 */  jal       atan2
/* 31B38C 802BD36C 8E270040 */   lw       $a3, 0x40($s1)
/* 31B390 802BD370 3C040004 */  lui       $a0, 4
/* 31B394 802BD374 24020078 */  addiu     $v0, $zero, 0x78
/* 31B398 802BD378 8E030000 */  lw        $v1, ($s0)
/* 31B39C 802BD37C 3C0140C0 */  lui       $at, 0x40c0
/* 31B3A0 802BD380 44811000 */  mtc1      $at, $f2
/* 31B3A4 802BD384 3C014248 */  lui       $at, 0x4248
/* 31B3A8 802BD388 44812000 */  mtc1      $at, $f4
/* 31B3AC 802BD38C 34840148 */  ori       $a0, $a0, 0x148
/* 31B3B0 802BD390 E4600010 */  swc1      $f0, 0x10($v1)
/* 31B3B4 802BD394 E4620014 */  swc1      $f2, 0x14($v1)
/* 31B3B8 802BD398 E4640018 */  swc1      $f4, 0x18($v1)
/* 31B3BC 802BD39C AC620000 */  sw        $v0, ($v1)
/* 31B3C0 802BD3A0 8E220000 */  lw        $v0, ($s1)
/* 31B3C4 802BD3A4 2403FDFF */  addiu     $v1, $zero, -0x201
/* 31B3C8 802BD3A8 00441025 */  or        $v0, $v0, $a0
/* 31B3CC 802BD3AC 00431024 */  and       $v0, $v0, $v1
/* 31B3D0 802BD3B0 AE220000 */  sw        $v0, ($s1)
/* 31B3D4 802BD3B4 3C10802C */  lui       $s0, %hi(D_802BEB60_31CB80)
/* 31B3D8 802BD3B8 2610EB60 */  addiu     $s0, $s0, %lo(D_802BEB60_31CB80)
.L802BD3BC:
/* 31B3DC 802BD3BC 8E020000 */  lw        $v0, ($s0)
/* 31B3E0 802BD3C0 3C0140C9 */  lui       $at, 0x40c9
/* 31B3E4 802BD3C4 34210FD0 */  ori       $at, $at, 0xfd0
/* 31B3E8 802BD3C8 44810000 */  mtc1      $at, $f0
/* 31B3EC 802BD3CC C44C0010 */  lwc1      $f12, 0x10($v0)
/* 31B3F0 802BD3D0 46006302 */  mul.s     $f12, $f12, $f0
/* 31B3F4 802BD3D4 00000000 */  nop
/* 31B3F8 802BD3D8 27A50010 */  addiu     $a1, $sp, 0x10
/* 31B3FC 802BD3DC 3C0143B4 */  lui       $at, 0x43b4
/* 31B400 802BD3E0 44810000 */  mtc1      $at, $f0
/* 31B404 802BD3E4 27A60014 */  addiu     $a2, $sp, 0x14
/* 31B408 802BD3E8 0C00A82D */  jal       sin_cos_rad
/* 31B40C 802BD3EC 46006303 */   div.s    $f12, $f12, $f0
/* 31B410 802BD3F0 8E020000 */  lw        $v0, ($s0)
/* 31B414 802BD3F4 C7A20010 */  lwc1      $f2, 0x10($sp)
/* 31B418 802BD3F8 C440000C */  lwc1      $f0, 0xc($v0)
/* 31B41C 802BD3FC 46001082 */  mul.s     $f2, $f2, $f0
/* 31B420 802BD400 00000000 */  nop
/* 31B424 802BD404 C6400048 */  lwc1      $f0, 0x48($s2)
/* 31B428 802BD408 46020000 */  add.s     $f0, $f0, $f2
/* 31B42C 802BD40C E6200038 */  swc1      $f0, 0x38($s1)
/* 31B430 802BD410 C7A20014 */  lwc1      $f2, 0x14($sp)
/* 31B434 802BD414 C440000C */  lwc1      $f0, 0xc($v0)
/* 31B438 802BD418 46001082 */  mul.s     $f2, $f2, $f0
/* 31B43C 802BD41C 00000000 */  nop
/* 31B440 802BD420 C6400050 */  lwc1      $f0, 0x50($s2)
/* 31B444 802BD424 46020001 */  sub.s     $f0, $f0, $f2
/* 31B448 802BD428 E6200040 */  swc1      $f0, 0x40($s1)
/* 31B44C 802BD42C C4400010 */  lwc1      $f0, 0x10($v0)
/* 31B450 802BD430 C44C0014 */  lwc1      $f12, 0x14($v0)
/* 31B454 802BD434 0C00A6C9 */  jal       clamp_angle
/* 31B458 802BD438 460C0301 */   sub.s    $f12, $f0, $f12
/* 31B45C 802BD43C 8E100000 */  lw        $s0, ($s0)
/* 31B460 802BD440 3C0141A0 */  lui       $at, 0x41a0
/* 31B464 802BD444 44811000 */  mtc1      $at, $f2
/* 31B468 802BD448 C604000C */  lwc1      $f4, 0xc($s0)
/* 31B46C 802BD44C 4604103C */  c.lt.s    $f2, $f4
/* 31B470 802BD450 00000000 */  nop
/* 31B474 802BD454 45000005 */  bc1f      .L802BD46C
/* 31B478 802BD458 E6000010 */   swc1     $f0, 0x10($s0)
/* 31B47C 802BD45C 3C013F80 */  lui       $at, 0x3f80
/* 31B480 802BD460 44810000 */  mtc1      $at, $f0
/* 31B484 802BD464 080AF526 */  j         .L802BD498
/* 31B488 802BD468 46002001 */   sub.s    $f0, $f4, $f0
.L802BD46C:
/* 31B48C 802BD46C 3C014198 */  lui       $at, 0x4198
/* 31B490 802BD470 44810000 */  mtc1      $at, $f0
/* 31B494 802BD474 00000000 */  nop
/* 31B498 802BD478 4600203C */  c.lt.s    $f4, $f0
/* 31B49C 802BD47C 00000000 */  nop
/* 31B4A0 802BD480 45000006 */  bc1f      .L802BD49C
/* 31B4A4 802BD484 00000000 */   nop
/* 31B4A8 802BD488 3C013F80 */  lui       $at, 0x3f80
/* 31B4AC 802BD48C 44810000 */  mtc1      $at, $f0
/* 31B4B0 802BD490 00000000 */  nop
/* 31B4B4 802BD494 46002000 */  add.s     $f0, $f4, $f0
.L802BD498:
/* 31B4B8 802BD498 E600000C */  swc1      $f0, 0xc($s0)
.L802BD49C:
/* 31B4BC 802BD49C 3C10802C */  lui       $s0, %hi(D_802BEB60_31CB80)
/* 31B4C0 802BD4A0 2610EB60 */  addiu     $s0, $s0, %lo(D_802BEB60_31CB80)
/* 31B4C4 802BD4A4 8E020000 */  lw        $v0, ($s0)
/* 31B4C8 802BD4A8 3C0140C9 */  lui       $at, 0x40c9
/* 31B4CC 802BD4AC 34210FD0 */  ori       $at, $at, 0xfd0
/* 31B4D0 802BD4B0 44810000 */  mtc1      $at, $f0
/* 31B4D4 802BD4B4 C44C0018 */  lwc1      $f12, 0x18($v0)
/* 31B4D8 802BD4B8 46006302 */  mul.s     $f12, $f12, $f0
/* 31B4DC 802BD4BC 00000000 */  nop
/* 31B4E0 802BD4C0 3C0143B4 */  lui       $at, 0x43b4
/* 31B4E4 802BD4C4 4481A000 */  mtc1      $at, $f20
/* 31B4E8 802BD4C8 0C00A85B */  jal       sin_rad
/* 31B4EC 802BD4CC 46146303 */   div.s    $f12, $f12, $f20
/* 31B4F0 802BD4D0 8E020000 */  lw        $v0, ($s0)
/* 31B4F4 802BD4D4 3C014040 */  lui       $at, 0x4040
/* 31B4F8 802BD4D8 44812000 */  mtc1      $at, $f4
/* 31B4FC 802BD4DC C4420018 */  lwc1      $f2, 0x18($v0)
/* 31B500 802BD4E0 46041080 */  add.s     $f2, $f2, $f4
/* 31B504 802BD4E4 3C014316 */  lui       $at, 0x4316
/* 31B508 802BD4E8 44813000 */  mtc1      $at, $f6
/* 31B50C 802BD4EC 00000000 */  nop
/* 31B510 802BD4F0 4602303C */  c.lt.s    $f6, $f2
/* 31B514 802BD4F4 E4420018 */  swc1      $f2, 0x18($v0)
/* 31B518 802BD4F8 46040082 */  mul.s     $f2, $f0, $f4
/* 31B51C 802BD4FC 00000000 */  nop
/* 31B520 802BD500 45030001 */  bc1tl     .L802BD508
/* 31B524 802BD504 E4460018 */   swc1     $f6, 0x18($v0)
.L802BD508:
/* 31B528 802BD508 C620003C */  lwc1      $f0, 0x3c($s1)
/* 31B52C 802BD50C 46020000 */  add.s     $f0, $f0, $f2
/* 31B530 802BD510 8E020000 */  lw        $v0, ($s0)
/* 31B534 802BD514 E620003C */  swc1      $f0, 0x3c($s1)
/* 31B538 802BD518 C44C0010 */  lwc1      $f12, 0x10($v0)
/* 31B53C 802BD51C 0C00A6C9 */  jal       clamp_angle
/* 31B540 802BD520 460CA301 */   sub.s    $f12, $f20, $f12
/* 31B544 802BD524 8E020000 */  lw        $v0, ($s0)
/* 31B548 802BD528 E6200034 */  swc1      $f0, 0x34($s1)
/* 31B54C 802BD52C C4400014 */  lwc1      $f0, 0x14($v0)
/* 31B550 802BD530 3C01802C */  lui       $at, %hi(D_802BEBC0_31CBE0)
/* 31B554 802BD534 D422EBC0 */  ldc1      $f2, %lo(D_802BEBC0_31CBE0)($at)
/* 31B558 802BD538 46000021 */  cvt.d.s   $f0, $f0
/* 31B55C 802BD53C 46220000 */  add.d     $f0, $f0, $f2
/* 31B560 802BD540 3C014220 */  lui       $at, 0x4220
/* 31B564 802BD544 44811000 */  mtc1      $at, $f2
/* 31B568 802BD548 46200020 */  cvt.s.d   $f0, $f0
/* 31B56C 802BD54C 4600103C */  c.lt.s    $f2, $f0
/* 31B570 802BD550 00000000 */  nop
/* 31B574 802BD554 45000002 */  bc1f      .L802BD560
/* 31B578 802BD558 E4400014 */   swc1     $f0, 0x14($v0)
/* 31B57C 802BD55C E4420014 */  swc1      $f2, 0x14($v0)
.L802BD560:
/* 31B580 802BD560 8E030000 */  lw        $v1, ($s0)
/* 31B584 802BD564 8C620000 */  lw        $v0, ($v1)
/* 31B588 802BD568 2442FFFF */  addiu     $v0, $v0, -1
/* 31B58C 802BD56C 14400018 */  bnez      $v0, .L802BD5D0
/* 31B590 802BD570 AC620000 */   sw       $v0, ($v1)
/* 31B594 802BD574 8C620004 */  lw        $v0, 4($v1)
/* 31B598 802BD578 24420001 */  addiu     $v0, $v0, 1
/* 31B59C 802BD57C 080AF574 */  j         .L802BD5D0
/* 31B5A0 802BD580 AC620004 */   sw       $v0, 4($v1)
.L802BD584:
/* 31B5A4 802BD584 8C820008 */  lw        $v0, 8($a0)
/* 31B5A8 802BD588 AE220000 */  sw        $v0, ($s1)
/* 31B5AC 802BD58C 8C820004 */  lw        $v0, 4($a0)
/* 31B5B0 802BD590 2403001E */  addiu     $v1, $zero, 0x1e
/* 31B5B4 802BD594 AC830000 */  sw        $v1, ($a0)
/* 31B5B8 802BD598 24420001 */  addiu     $v0, $v0, 1
/* 31B5BC 802BD59C 080AF574 */  j         .L802BD5D0
/* 31B5C0 802BD5A0 AC820004 */   sw       $v0, 4($a0)
.L802BD5A4:
/* 31B5C4 802BD5A4 0C03AE8F */  jal       partner_walking_update_player_tracking
/* 31B5C8 802BD5A8 0220202D */   daddu    $a0, $s1, $zero
/* 31B5CC 802BD5AC 0C03AED0 */  jal       partner_walking_update_motion
/* 31B5D0 802BD5B0 0220202D */   daddu    $a0, $s1, $zero
/* 31B5D4 802BD5B4 8E030000 */  lw        $v1, ($s0)
/* 31B5D8 802BD5B8 8C620000 */  lw        $v0, ($v1)
/* 31B5DC 802BD5BC 2442FFFF */  addiu     $v0, $v0, -1
/* 31B5E0 802BD5C0 14400003 */  bnez      $v0, .L802BD5D0
/* 31B5E4 802BD5C4 AC620000 */   sw       $v0, ($v1)
/* 31B5E8 802BD5C8 AC600004 */  sw        $zero, 4($v1)
/* 31B5EC 802BD5CC AE600000 */  sw        $zero, ($s3)
.L802BD5D0:
/* 31B5F0 802BD5D0 0000102D */  daddu     $v0, $zero, $zero
.L802BD5D4:
/* 31B5F4 802BD5D4 8FBF0028 */  lw        $ra, 0x28($sp)
/* 31B5F8 802BD5D8 8FB30024 */  lw        $s3, 0x24($sp)
/* 31B5FC 802BD5DC 8FB20020 */  lw        $s2, 0x20($sp)
/* 31B600 802BD5E0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 31B604 802BD5E4 8FB00018 */  lw        $s0, 0x18($sp)
/* 31B608 802BD5E8 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 31B60C 802BD5EC 03E00008 */  jr        $ra
/* 31B610 802BD5F0 27BD0038 */   addiu    $sp, $sp, 0x38
