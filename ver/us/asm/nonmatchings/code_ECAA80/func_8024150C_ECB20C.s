.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024150C_ECB20C
/* ECB20C 8024150C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* ECB210 80241510 AFB50044 */  sw        $s5, 0x44($sp)
/* ECB214 80241514 0080A82D */  daddu     $s5, $a0, $zero
/* ECB218 80241518 AFBF0048 */  sw        $ra, 0x48($sp)
/* ECB21C 8024151C AFB40040 */  sw        $s4, 0x40($sp)
/* ECB220 80241520 AFB3003C */  sw        $s3, 0x3c($sp)
/* ECB224 80241524 AFB20038 */  sw        $s2, 0x38($sp)
/* ECB228 80241528 AFB10034 */  sw        $s1, 0x34($sp)
/* ECB22C 8024152C AFB00030 */  sw        $s0, 0x30($sp)
/* ECB230 80241530 8EB10148 */  lw        $s1, 0x148($s5)
/* ECB234 80241534 86240008 */  lh        $a0, 8($s1)
/* ECB238 80241538 0C00F92F */  jal       func_8003E4BC
/* ECB23C 8024153C 00A0802D */   daddu    $s0, $a1, $zero
/* ECB240 80241540 8EA3000C */  lw        $v1, 0xc($s5)
/* ECB244 80241544 02A0202D */  daddu     $a0, $s5, $zero
/* ECB248 80241548 8C650000 */  lw        $a1, ($v1)
/* ECB24C 8024154C 0C0B53A3 */  jal       func_802D4E8C
/* ECB250 80241550 0040902D */   daddu    $s2, $v0, $zero
/* ECB254 80241554 AFA00010 */  sw        $zero, 0x10($sp)
/* ECB258 80241558 8E2300D0 */  lw        $v1, 0xd0($s1)
/* ECB25C 8024155C 8C630030 */  lw        $v1, 0x30($v1)
/* ECB260 80241560 AFA30014 */  sw        $v1, 0x14($sp)
/* ECB264 80241564 8E2300D0 */  lw        $v1, 0xd0($s1)
/* ECB268 80241568 8C63001C */  lw        $v1, 0x1c($v1)
/* ECB26C 8024156C AFA30018 */  sw        $v1, 0x18($sp)
/* ECB270 80241570 8E2300D0 */  lw        $v1, 0xd0($s1)
/* ECB274 80241574 8C630024 */  lw        $v1, 0x24($v1)
/* ECB278 80241578 AFA3001C */  sw        $v1, 0x1c($sp)
/* ECB27C 8024157C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* ECB280 80241580 8C630028 */  lw        $v1, 0x28($v1)
/* ECB284 80241584 AFA30020 */  sw        $v1, 0x20($sp)
/* ECB288 80241588 8E2300D0 */  lw        $v1, 0xd0($s1)
/* ECB28C 8024158C 3C0142C8 */  lui       $at, 0x42c8
/* ECB290 80241590 44810000 */  mtc1      $at, $f0
/* ECB294 80241594 8C63002C */  lw        $v1, 0x2c($v1)
/* ECB298 80241598 E7A00028 */  swc1      $f0, 0x28($sp)
/* ECB29C 8024159C A7A0002C */  sh        $zero, 0x2c($sp)
/* ECB2A0 802415A0 AFA30024 */  sw        $v1, 0x24($sp)
/* ECB2A4 802415A4 C6400038 */  lwc1      $f0, 0x38($s2)
/* ECB2A8 802415A8 E6200108 */  swc1      $f0, 0x108($s1)
/* ECB2AC 802415AC C640003C */  lwc1      $f0, 0x3c($s2)
/* ECB2B0 802415B0 27B40010 */  addiu     $s4, $sp, 0x10
/* ECB2B4 802415B4 E620010C */  swc1      $f0, 0x10c($s1)
/* ECB2B8 802415B8 3C013C23 */  lui       $at, 0x3c23
/* ECB2BC 802415BC 3421D70A */  ori       $at, $at, 0xd70a
/* ECB2C0 802415C0 44810000 */  mtc1      $at, $f0
/* ECB2C4 802415C4 C6420040 */  lwc1      $f2, 0x40($s2)
/* ECB2C8 802415C8 0040982D */  daddu     $s3, $v0, $zero
/* ECB2CC 802415CC E6200114 */  swc1      $f0, 0x114($s1)
/* ECB2D0 802415D0 E6200118 */  swc1      $f0, 0x118($s1)
/* ECB2D4 802415D4 16000005 */  bnez      $s0, .L802415EC
/* ECB2D8 802415D8 E6220110 */   swc1     $f2, 0x110($s1)
/* ECB2DC 802415DC 8E2200B0 */  lw        $v0, 0xb0($s1)
/* ECB2E0 802415E0 30420004 */  andi      $v0, $v0, 4
/* ECB2E4 802415E4 1040001F */  beqz      $v0, .L80241664
/* ECB2E8 802415E8 00000000 */   nop
.L802415EC:
/* ECB2EC 802415EC 2404F7FF */  addiu     $a0, $zero, -0x801
/* ECB2F0 802415F0 AEA00070 */  sw        $zero, 0x70($s5)
/* ECB2F4 802415F4 A640008E */  sh        $zero, 0x8e($s2)
/* ECB2F8 802415F8 8E2200CC */  lw        $v0, 0xcc($s1)
/* ECB2FC 802415FC 8E430000 */  lw        $v1, ($s2)
/* ECB300 80241600 8C420000 */  lw        $v0, ($v0)
/* ECB304 80241604 00641824 */  and       $v1, $v1, $a0
/* ECB308 80241608 AE430000 */  sw        $v1, ($s2)
/* ECB30C 8024160C AE420028 */  sw        $v0, 0x28($s2)
/* ECB310 80241610 8E2200D0 */  lw        $v0, 0xd0($s1)
/* ECB314 80241614 8C420034 */  lw        $v0, 0x34($v0)
/* ECB318 80241618 54400005 */  bnel      $v0, $zero, .L80241630
/* ECB31C 8024161C 2402FDFF */   addiu    $v0, $zero, -0x201
/* ECB320 80241620 34620200 */  ori       $v0, $v1, 0x200
/* ECB324 80241624 2403FFF7 */  addiu     $v1, $zero, -9
/* ECB328 80241628 0809058E */  j         .L80241638
/* ECB32C 8024162C 00431024 */   and      $v0, $v0, $v1
.L80241630:
/* ECB330 80241630 00621024 */  and       $v0, $v1, $v0
/* ECB334 80241634 34420008 */  ori       $v0, $v0, 8
.L80241638:
/* ECB338 80241638 AE420000 */  sw        $v0, ($s2)
/* ECB33C 8024163C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* ECB340 80241640 30420004 */  andi      $v0, $v0, 4
/* ECB344 80241644 10400007 */  beqz      $v0, .L80241664
/* ECB348 80241648 24020063 */   addiu    $v0, $zero, 0x63
/* ECB34C 8024164C AEA20070 */  sw        $v0, 0x70($s5)
/* ECB350 80241650 AEA00074 */  sw        $zero, 0x74($s5)
/* ECB354 80241654 8E2200B0 */  lw        $v0, 0xb0($s1)
/* ECB358 80241658 2403FFFB */  addiu     $v1, $zero, -5
/* ECB35C 8024165C 00431024 */  and       $v0, $v0, $v1
/* ECB360 80241660 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80241664:
/* ECB364 80241664 8EA30070 */  lw        $v1, 0x70($s5)
/* ECB368 80241668 2C620064 */  sltiu     $v0, $v1, 0x64
/* ECB36C 8024166C 10400036 */  beqz      $v0, L80241748_ECB448
/* ECB370 80241670 00031080 */   sll      $v0, $v1, 2
/* ECB374 80241674 3C018024 */  lui       $at, %hi(jtbl_80246160_ECFE60)
/* ECB378 80241678 00220821 */  addu      $at, $at, $v0
/* ECB37C 8024167C 8C226160 */  lw        $v0, %lo(jtbl_80246160_ECFE60)($at)
/* ECB380 80241680 00400008 */  jr        $v0
/* ECB384 80241684 00000000 */   nop
glabel L80241688_ECB388
/* ECB388 80241688 02A0202D */  daddu     $a0, $s5, $zero
/* ECB38C 8024168C 0260282D */  daddu     $a1, $s3, $zero
/* ECB390 80241690 0C013670 */  jal       func_8004D9C0
/* ECB394 80241694 0280302D */   daddu    $a2, $s4, $zero
glabel L80241698_ECB398
/* ECB398 80241698 02A0202D */  daddu     $a0, $s5, $zero
/* ECB39C 8024169C 0260282D */  daddu     $a1, $s3, $zero
/* ECB3A0 802416A0 0C0136B6 */  jal       func_8004DAD8
/* ECB3A4 802416A4 0280302D */   daddu    $a2, $s4, $zero
/* ECB3A8 802416A8 080905D2 */  j         L80241748_ECB448
/* ECB3AC 802416AC 00000000 */   nop
glabel L802416B0_ECB3B0
/* ECB3B0 802416B0 02A0202D */  daddu     $a0, $s5, $zero
/* ECB3B4 802416B4 0260282D */  daddu     $a1, $s3, $zero
/* ECB3B8 802416B8 0C0137D9 */  jal       func_8004DF64
/* ECB3BC 802416BC 0280302D */   daddu    $a2, $s4, $zero
glabel L802416C0_ECB3C0
/* ECB3C0 802416C0 02A0202D */  daddu     $a0, $s5, $zero
/* ECB3C4 802416C4 0260282D */  daddu     $a1, $s3, $zero
/* ECB3C8 802416C8 0C013809 */  jal       func_8004E024
/* ECB3CC 802416CC 0280302D */   daddu    $a2, $s4, $zero
/* ECB3D0 802416D0 080905D2 */  j         L80241748_ECB448
/* ECB3D4 802416D4 00000000 */   nop
glabel L802416D8_ECB3D8
/* ECB3D8 802416D8 02A0202D */  daddu     $a0, $s5, $zero
/* ECB3DC 802416DC 0260282D */  daddu     $a1, $s3, $zero
/* ECB3E0 802416E0 0C013897 */  jal       func_8004E25C
/* ECB3E4 802416E4 0280302D */   daddu    $a2, $s4, $zero
glabel L802416E8_ECB3E8
/* ECB3E8 802416E8 02A0202D */  daddu     $a0, $s5, $zero
/* ECB3EC 802416EC 0260282D */  daddu     $a1, $s3, $zero
/* ECB3F0 802416F0 0C0138BB */  jal       func_8004E2EC
/* ECB3F4 802416F4 0280302D */   daddu    $a2, $s4, $zero
/* ECB3F8 802416F8 080905D2 */  j         L80241748_ECB448
/* ECB3FC 802416FC 00000000 */   nop
glabel L80241700_ECB400
/* ECB400 80241700 02A0202D */  daddu     $a0, $s5, $zero
/* ECB404 80241704 0260282D */  daddu     $a1, $s3, $zero
/* ECB408 80241708 0C090360 */  jal       func_80240D80_ECAA80
/* ECB40C 8024170C 0280302D */   daddu    $a2, $s4, $zero
glabel L80241710_ECB410
/* ECB410 80241710 02A0202D */  daddu     $a0, $s5, $zero
/* ECB414 80241714 0260282D */  daddu     $a1, $s3, $zero
/* ECB418 80241718 0C0904D9 */  jal       func_80241364_ECB064
/* ECB41C 8024171C 0280302D */   daddu    $a2, $s4, $zero
/* ECB420 80241720 080905D2 */  j         L80241748_ECB448
/* ECB424 80241724 00000000 */   nop
glabel L80241728_ECB428
/* ECB428 80241728 02A0202D */  daddu     $a0, $s5, $zero
/* ECB42C 8024172C 0260282D */  daddu     $a1, $s3, $zero
/* ECB430 80241730 0C090532 */  jal       func_802414C8_ECB1C8
/* ECB434 80241734 0280302D */   daddu    $a2, $s4, $zero
/* ECB438 80241738 080905D2 */  j         L80241748_ECB448
/* ECB43C 8024173C 00000000 */   nop
glabel L80241740_ECB440
/* ECB440 80241740 0C013AE3 */  jal       func_8004EB8C
/* ECB444 80241744 02A0202D */   daddu    $a0, $s5, $zero
glabel L80241748_ECB448
/* ECB448 80241748 8FBF0048 */  lw        $ra, 0x48($sp)
/* ECB44C 8024174C 8FB50044 */  lw        $s5, 0x44($sp)
/* ECB450 80241750 8FB40040 */  lw        $s4, 0x40($sp)
/* ECB454 80241754 8FB3003C */  lw        $s3, 0x3c($sp)
/* ECB458 80241758 8FB20038 */  lw        $s2, 0x38($sp)
/* ECB45C 8024175C 8FB10034 */  lw        $s1, 0x34($sp)
/* ECB460 80241760 8FB00030 */  lw        $s0, 0x30($sp)
/* ECB464 80241764 0000102D */  daddu     $v0, $zero, $zero
/* ECB468 80241768 03E00008 */  jr        $ra
/* ECB46C 8024176C 27BD0050 */   addiu    $sp, $sp, 0x50
