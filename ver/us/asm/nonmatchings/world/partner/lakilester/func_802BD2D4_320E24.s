.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD2D4_320E24
/* 320E24 802BD2D4 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 320E28 802BD2D8 AFB00018 */  sw        $s0, 0x18($sp)
/* 320E2C 802BD2DC 3C108011 */  lui       $s0, %hi(gPlayerData)
/* 320E30 802BD2E0 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* 320E34 802BD2E4 AFBF0028 */  sw        $ra, 0x28($sp)
/* 320E38 802BD2E8 AFB30024 */  sw        $s3, 0x24($sp)
/* 320E3C 802BD2EC AFB20020 */  sw        $s2, 0x20($sp)
/* 320E40 802BD2F0 AFB1001C */  sw        $s1, 0x1c($sp)
/* 320E44 802BD2F4 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 320E48 802BD2F8 8C91014C */  lw        $s1, 0x14c($a0)
/* 320E4C 802BD2FC 10A00009 */  beqz      $a1, .L802BD324
/* 320E50 802BD300 0220202D */   daddu    $a0, $s1, $zero
/* 320E54 802BD304 0C03B4C4 */  jal       partner_flying_enable
/* 320E58 802BD308 24050001 */   addiu    $a1, $zero, 1
/* 320E5C 802BD30C 3C04802C */  lui       $a0, %hi(D_802BFE7C_3239CC)
/* 320E60 802BD310 8C84FE7C */  lw        $a0, %lo(D_802BFE7C_3239CC)($a0)
/* 320E64 802BD314 0C00A580 */  jal       mem_clear
/* 320E68 802BD318 2405001C */   addiu    $a1, $zero, 0x1c
/* 320E6C 802BD31C 3C018011 */  lui       $at, %hi(D_8010C954)
/* 320E70 802BD320 AC20C954 */  sw        $zero, %lo(D_8010C954)($at)
.L802BD324:
/* 320E74 802BD324 3C030001 */  lui       $v1, 1
/* 320E78 802BD328 8E020314 */  lw        $v0, 0x314($s0)
/* 320E7C 802BD32C 3C138011 */  lui       $s3, %hi(D_8010C954)
/* 320E80 802BD330 2673C954 */  addiu     $s3, $s3, %lo(D_8010C954)
/* 320E84 802BD334 24420001 */  addiu     $v0, $v0, 1
/* 320E88 802BD338 AE020314 */  sw        $v0, 0x314($s0)
/* 320E8C 802BD33C 8E220000 */  lw        $v0, ($s1)
/* 320E90 802BD340 8E720000 */  lw        $s2, ($s3)
/* 320E94 802BD344 00431025 */  or        $v0, $v0, $v1
/* 320E98 802BD348 16400007 */  bnez      $s2, .L802BD368
/* 320E9C 802BD34C AE220000 */   sw       $v0, ($s1)
/* 320EA0 802BD350 0C03B52E */  jal       partner_flying_update_player_tracking
/* 320EA4 802BD354 0220202D */   daddu    $a0, $s1, $zero
/* 320EA8 802BD358 0C03B574 */  jal       partner_flying_update_motion
/* 320EAC 802BD35C 0220202D */   daddu    $a0, $s1, $zero
/* 320EB0 802BD360 080AF596 */  j         .L802BD658
/* 320EB4 802BD364 0000102D */   daddu    $v0, $zero, $zero
.L802BD368:
/* 320EB8 802BD368 3C10802C */  lui       $s0, %hi(D_802BFE7C_3239CC)
/* 320EBC 802BD36C 2610FE7C */  addiu     $s0, $s0, %lo(D_802BFE7C_3239CC)
/* 320EC0 802BD370 8E040000 */  lw        $a0, ($s0)
/* 320EC4 802BD374 8C830004 */  lw        $v1, 4($a0)
/* 320EC8 802BD378 24050001 */  addiu     $a1, $zero, 1
/* 320ECC 802BD37C 10650030 */  beq       $v1, $a1, .L802BD440
/* 320ED0 802BD380 28620002 */   slti     $v0, $v1, 2
/* 320ED4 802BD384 10400005 */  beqz      $v0, .L802BD39C
/* 320ED8 802BD388 24020002 */   addiu    $v0, $zero, 2
/* 320EDC 802BD38C 10600009 */  beqz      $v1, .L802BD3B4
/* 320EE0 802BD390 0000102D */   daddu    $v0, $zero, $zero
/* 320EE4 802BD394 080AF596 */  j         .L802BD658
/* 320EE8 802BD398 00000000 */   nop
.L802BD39C:
/* 320EEC 802BD39C 1062009A */  beq       $v1, $v0, .L802BD608
/* 320EF0 802BD3A0 24020003 */   addiu    $v0, $zero, 3
/* 320EF4 802BD3A4 106200A0 */  beq       $v1, $v0, .L802BD628
/* 320EF8 802BD3A8 0000102D */   daddu    $v0, $zero, $zero
/* 320EFC 802BD3AC 080AF596 */  j         .L802BD658
/* 320F00 802BD3B0 00000000 */   nop
.L802BD3B4:
/* 320F04 802BD3B4 AC850004 */  sw        $a1, 4($a0)
/* 320F08 802BD3B8 8E220000 */  lw        $v0, ($s1)
/* 320F0C 802BD3BC AC820008 */  sw        $v0, 8($a0)
/* 320F10 802BD3C0 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 320F14 802BD3C4 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 320F18 802BD3C8 8E460048 */  lw        $a2, 0x48($s2)
/* 320F1C 802BD3CC 0C00A7B5 */  jal       dist2D
/* 320F20 802BD3D0 8E470050 */   lw       $a3, 0x50($s2)
/* 320F24 802BD3D4 8E020000 */  lw        $v0, ($s0)
/* 320F28 802BD3D8 46000005 */  abs.s     $f0, $f0
/* 320F2C 802BD3DC E440000C */  swc1      $f0, 0xc($v0)
/* 320F30 802BD3E0 C64C0048 */  lwc1      $f12, 0x48($s2)
/* 320F34 802BD3E4 C64E0050 */  lwc1      $f14, 0x50($s2)
/* 320F38 802BD3E8 8E260038 */  lw        $a2, 0x38($s1)
/* 320F3C 802BD3EC 0C00A720 */  jal       atan2
/* 320F40 802BD3F0 8E270040 */   lw       $a3, 0x40($s1)
/* 320F44 802BD3F4 3C040004 */  lui       $a0, 4
/* 320F48 802BD3F8 24020078 */  addiu     $v0, $zero, 0x78
/* 320F4C 802BD3FC 8E030000 */  lw        $v1, ($s0)
/* 320F50 802BD400 3C0140C0 */  lui       $at, 0x40c0
/* 320F54 802BD404 44811000 */  mtc1      $at, $f2
/* 320F58 802BD408 3C014248 */  lui       $at, 0x4248
/* 320F5C 802BD40C 44812000 */  mtc1      $at, $f4
/* 320F60 802BD410 34840148 */  ori       $a0, $a0, 0x148
/* 320F64 802BD414 E4600010 */  swc1      $f0, 0x10($v1)
/* 320F68 802BD418 E4620014 */  swc1      $f2, 0x14($v1)
/* 320F6C 802BD41C E4640018 */  swc1      $f4, 0x18($v1)
/* 320F70 802BD420 AC620000 */  sw        $v0, ($v1)
/* 320F74 802BD424 8E220000 */  lw        $v0, ($s1)
/* 320F78 802BD428 2403FDFF */  addiu     $v1, $zero, -0x201
/* 320F7C 802BD42C 00441025 */  or        $v0, $v0, $a0
/* 320F80 802BD430 00431024 */  and       $v0, $v0, $v1
/* 320F84 802BD434 AE220000 */  sw        $v0, ($s1)
/* 320F88 802BD438 3C10802C */  lui       $s0, %hi(D_802BFE7C_3239CC)
/* 320F8C 802BD43C 2610FE7C */  addiu     $s0, $s0, %lo(D_802BFE7C_3239CC)
.L802BD440:
/* 320F90 802BD440 8E020000 */  lw        $v0, ($s0)
/* 320F94 802BD444 3C0140C9 */  lui       $at, 0x40c9
/* 320F98 802BD448 34210FD0 */  ori       $at, $at, 0xfd0
/* 320F9C 802BD44C 44810000 */  mtc1      $at, $f0
/* 320FA0 802BD450 C44C0010 */  lwc1      $f12, 0x10($v0)
/* 320FA4 802BD454 46006302 */  mul.s     $f12, $f12, $f0
/* 320FA8 802BD458 00000000 */  nop
/* 320FAC 802BD45C 27A50010 */  addiu     $a1, $sp, 0x10
/* 320FB0 802BD460 3C0143B4 */  lui       $at, 0x43b4
/* 320FB4 802BD464 44810000 */  mtc1      $at, $f0
/* 320FB8 802BD468 27A60014 */  addiu     $a2, $sp, 0x14
/* 320FBC 802BD46C 0C00A82D */  jal       sin_cos_rad
/* 320FC0 802BD470 46006303 */   div.s    $f12, $f12, $f0
/* 320FC4 802BD474 8E020000 */  lw        $v0, ($s0)
/* 320FC8 802BD478 C7A20010 */  lwc1      $f2, 0x10($sp)
/* 320FCC 802BD47C C440000C */  lwc1      $f0, 0xc($v0)
/* 320FD0 802BD480 46001082 */  mul.s     $f2, $f2, $f0
/* 320FD4 802BD484 00000000 */  nop
/* 320FD8 802BD488 C6400048 */  lwc1      $f0, 0x48($s2)
/* 320FDC 802BD48C 46020000 */  add.s     $f0, $f0, $f2
/* 320FE0 802BD490 E6200038 */  swc1      $f0, 0x38($s1)
/* 320FE4 802BD494 C7A20014 */  lwc1      $f2, 0x14($sp)
/* 320FE8 802BD498 C440000C */  lwc1      $f0, 0xc($v0)
/* 320FEC 802BD49C 46001082 */  mul.s     $f2, $f2, $f0
/* 320FF0 802BD4A0 00000000 */  nop
/* 320FF4 802BD4A4 C6400050 */  lwc1      $f0, 0x50($s2)
/* 320FF8 802BD4A8 46020001 */  sub.s     $f0, $f0, $f2
/* 320FFC 802BD4AC E6200040 */  swc1      $f0, 0x40($s1)
/* 321000 802BD4B0 C4400010 */  lwc1      $f0, 0x10($v0)
/* 321004 802BD4B4 C44C0014 */  lwc1      $f12, 0x14($v0)
/* 321008 802BD4B8 0C00A6C9 */  jal       clamp_angle
/* 32100C 802BD4BC 460C0301 */   sub.s    $f12, $f0, $f12
/* 321010 802BD4C0 8E100000 */  lw        $s0, ($s0)
/* 321014 802BD4C4 3C0141A0 */  lui       $at, 0x41a0
/* 321018 802BD4C8 44811000 */  mtc1      $at, $f2
/* 32101C 802BD4CC C604000C */  lwc1      $f4, 0xc($s0)
/* 321020 802BD4D0 4604103C */  c.lt.s    $f2, $f4
/* 321024 802BD4D4 00000000 */  nop
/* 321028 802BD4D8 45000005 */  bc1f      .L802BD4F0
/* 32102C 802BD4DC E6000010 */   swc1     $f0, 0x10($s0)
/* 321030 802BD4E0 3C013F80 */  lui       $at, 0x3f80
/* 321034 802BD4E4 44810000 */  mtc1      $at, $f0
/* 321038 802BD4E8 080AF547 */  j         .L802BD51C
/* 32103C 802BD4EC 46002001 */   sub.s    $f0, $f4, $f0
.L802BD4F0:
/* 321040 802BD4F0 3C014198 */  lui       $at, 0x4198
/* 321044 802BD4F4 44810000 */  mtc1      $at, $f0
/* 321048 802BD4F8 00000000 */  nop
/* 32104C 802BD4FC 4600203C */  c.lt.s    $f4, $f0
/* 321050 802BD500 00000000 */  nop
/* 321054 802BD504 45000006 */  bc1f      .L802BD520
/* 321058 802BD508 00000000 */   nop
/* 32105C 802BD50C 3C013F80 */  lui       $at, 0x3f80
/* 321060 802BD510 44810000 */  mtc1      $at, $f0
/* 321064 802BD514 00000000 */  nop
/* 321068 802BD518 46002000 */  add.s     $f0, $f4, $f0
.L802BD51C:
/* 32106C 802BD51C E600000C */  swc1      $f0, 0xc($s0)
.L802BD520:
/* 321070 802BD520 3C10802C */  lui       $s0, %hi(D_802BFE7C_3239CC)
/* 321074 802BD524 2610FE7C */  addiu     $s0, $s0, %lo(D_802BFE7C_3239CC)
/* 321078 802BD528 8E020000 */  lw        $v0, ($s0)
/* 32107C 802BD52C 3C0140C9 */  lui       $at, 0x40c9
/* 321080 802BD530 34210FD0 */  ori       $at, $at, 0xfd0
/* 321084 802BD534 44810000 */  mtc1      $at, $f0
/* 321088 802BD538 C44C0018 */  lwc1      $f12, 0x18($v0)
/* 32108C 802BD53C 46006302 */  mul.s     $f12, $f12, $f0
/* 321090 802BD540 00000000 */  nop
/* 321094 802BD544 3C0143B4 */  lui       $at, 0x43b4
/* 321098 802BD548 4481A000 */  mtc1      $at, $f20
/* 32109C 802BD54C 0C00A85B */  jal       sin_rad
/* 3210A0 802BD550 46146303 */   div.s    $f12, $f12, $f20
/* 3210A4 802BD554 8E020000 */  lw        $v0, ($s0)
/* 3210A8 802BD558 3C014040 */  lui       $at, 0x4040
/* 3210AC 802BD55C 44812000 */  mtc1      $at, $f4
/* 3210B0 802BD560 C4420018 */  lwc1      $f2, 0x18($v0)
/* 3210B4 802BD564 46041080 */  add.s     $f2, $f2, $f4
/* 3210B8 802BD568 3C014316 */  lui       $at, 0x4316
/* 3210BC 802BD56C 44813000 */  mtc1      $at, $f6
/* 3210C0 802BD570 00000000 */  nop
/* 3210C4 802BD574 4602303C */  c.lt.s    $f6, $f2
/* 3210C8 802BD578 E4420018 */  swc1      $f2, 0x18($v0)
/* 3210CC 802BD57C 46040082 */  mul.s     $f2, $f0, $f4
/* 3210D0 802BD580 00000000 */  nop
/* 3210D4 802BD584 45030001 */  bc1tl     .L802BD58C
/* 3210D8 802BD588 E4460018 */   swc1     $f6, 0x18($v0)
.L802BD58C:
/* 3210DC 802BD58C C620003C */  lwc1      $f0, 0x3c($s1)
/* 3210E0 802BD590 46020000 */  add.s     $f0, $f0, $f2
/* 3210E4 802BD594 8E020000 */  lw        $v0, ($s0)
/* 3210E8 802BD598 E620003C */  swc1      $f0, 0x3c($s1)
/* 3210EC 802BD59C C44C0010 */  lwc1      $f12, 0x10($v0)
/* 3210F0 802BD5A0 0C00A6C9 */  jal       clamp_angle
/* 3210F4 802BD5A4 460CA301 */   sub.s    $f12, $f20, $f12
/* 3210F8 802BD5A8 8E020000 */  lw        $v0, ($s0)
/* 3210FC 802BD5AC E6200034 */  swc1      $f0, 0x34($s1)
/* 321100 802BD5B0 C4400014 */  lwc1      $f0, 0x14($v0)
/* 321104 802BD5B4 3C01802C */  lui       $at, %hi(D_802BFEF0)
/* 321108 802BD5B8 D422FEF0 */  ldc1      $f2, %lo(D_802BFEF0)($at)
/* 32110C 802BD5BC 46000021 */  cvt.d.s   $f0, $f0
/* 321110 802BD5C0 46220000 */  add.d     $f0, $f0, $f2
/* 321114 802BD5C4 3C014220 */  lui       $at, 0x4220
/* 321118 802BD5C8 44811000 */  mtc1      $at, $f2
/* 32111C 802BD5CC 46200020 */  cvt.s.d   $f0, $f0
/* 321120 802BD5D0 4600103C */  c.lt.s    $f2, $f0
/* 321124 802BD5D4 00000000 */  nop
/* 321128 802BD5D8 45000002 */  bc1f      .L802BD5E4
/* 32112C 802BD5DC E4400014 */   swc1     $f0, 0x14($v0)
/* 321130 802BD5E0 E4420014 */  swc1      $f2, 0x14($v0)
.L802BD5E4:
/* 321134 802BD5E4 8E030000 */  lw        $v1, ($s0)
/* 321138 802BD5E8 8C620000 */  lw        $v0, ($v1)
/* 32113C 802BD5EC 2442FFFF */  addiu     $v0, $v0, -1
/* 321140 802BD5F0 14400018 */  bnez      $v0, .L802BD654
/* 321144 802BD5F4 AC620000 */   sw       $v0, ($v1)
/* 321148 802BD5F8 8C620004 */  lw        $v0, 4($v1)
/* 32114C 802BD5FC 24420001 */  addiu     $v0, $v0, 1
/* 321150 802BD600 080AF595 */  j         .L802BD654
/* 321154 802BD604 AC620004 */   sw       $v0, 4($v1)
.L802BD608:
/* 321158 802BD608 8C820008 */  lw        $v0, 8($a0)
/* 32115C 802BD60C AE220000 */  sw        $v0, ($s1)
/* 321160 802BD610 8C820004 */  lw        $v0, 4($a0)
/* 321164 802BD614 2403001E */  addiu     $v1, $zero, 0x1e
/* 321168 802BD618 AC830000 */  sw        $v1, ($a0)
/* 32116C 802BD61C 24420001 */  addiu     $v0, $v0, 1
/* 321170 802BD620 080AF595 */  j         .L802BD654
/* 321174 802BD624 AC820004 */   sw       $v0, 4($a0)
.L802BD628:
/* 321178 802BD628 0C03B52E */  jal       partner_flying_update_player_tracking
/* 32117C 802BD62C 0220202D */   daddu    $a0, $s1, $zero
/* 321180 802BD630 0C03B574 */  jal       partner_flying_update_motion
/* 321184 802BD634 0220202D */   daddu    $a0, $s1, $zero
/* 321188 802BD638 8E030000 */  lw        $v1, ($s0)
/* 32118C 802BD63C 8C620000 */  lw        $v0, ($v1)
/* 321190 802BD640 2442FFFF */  addiu     $v0, $v0, -1
/* 321194 802BD644 14400003 */  bnez      $v0, .L802BD654
/* 321198 802BD648 AC620000 */   sw       $v0, ($v1)
/* 32119C 802BD64C AC600004 */  sw        $zero, 4($v1)
/* 3211A0 802BD650 AE600000 */  sw        $zero, ($s3)
.L802BD654:
/* 3211A4 802BD654 0000102D */  daddu     $v0, $zero, $zero
.L802BD658:
/* 3211A8 802BD658 8FBF0028 */  lw        $ra, 0x28($sp)
/* 3211AC 802BD65C 8FB30024 */  lw        $s3, 0x24($sp)
/* 3211B0 802BD660 8FB20020 */  lw        $s2, 0x20($sp)
/* 3211B4 802BD664 8FB1001C */  lw        $s1, 0x1c($sp)
/* 3211B8 802BD668 8FB00018 */  lw        $s0, 0x18($sp)
/* 3211BC 802BD66C D7B40030 */  ldc1      $f20, 0x30($sp)
/* 3211C0 802BD670 03E00008 */  jr        $ra
/* 3211C4 802BD674 27BD0038 */   addiu    $sp, $sp, 0x38
