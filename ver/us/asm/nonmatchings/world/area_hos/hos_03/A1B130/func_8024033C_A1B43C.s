.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024033C_A1B43C
/* A1B43C 8024033C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* A1B440 80240340 AFB30034 */  sw        $s3, 0x34($sp)
/* A1B444 80240344 3C130001 */  lui       $s3, 1
/* A1B448 80240348 AFB00028 */  sw        $s0, 0x28($sp)
/* A1B44C 8024034C 3C108024 */  lui       $s0, %hi(D_80243BCC_A1ECCC)
/* A1B450 80240350 26103BCC */  addiu     $s0, $s0, %lo(D_80243BCC_A1ECCC)
/* A1B454 80240354 AFBF0040 */  sw        $ra, 0x40($sp)
/* A1B458 80240358 AFB5003C */  sw        $s5, 0x3c($sp)
/* A1B45C 8024035C AFB40038 */  sw        $s4, 0x38($sp)
/* A1B460 80240360 AFB20030 */  sw        $s2, 0x30($sp)
/* A1B464 80240364 AFB1002C */  sw        $s1, 0x2c($sp)
/* A1B468 80240368 96040000 */  lhu       $a0, ($s0)
/* A1B46C 8024036C 0C01917C */  jal       sins
/* A1B470 80240370 36731630 */   ori      $s3, $s3, 0x1630
/* A1B474 80240374 00021400 */  sll       $v0, $v0, 0x10
/* A1B478 80240378 00021403 */  sra       $v0, $v0, 0x10
/* A1B47C 8024037C 44821000 */  mtc1      $v0, $f2
/* A1B480 80240380 00000000 */  nop
/* A1B484 80240384 468010A0 */  cvt.s.w   $f2, $f2
/* A1B488 80240388 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* A1B48C 8024038C 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* A1B490 80240390 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* A1B494 80240394 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* A1B498 80240398 3C073F80 */  lui       $a3, 0x3f80
/* A1B49C 8024039C 3C013800 */  lui       $at, 0x3800
/* A1B4A0 802403A0 44810000 */  mtc1      $at, $f0
/* A1B4A4 802403A4 96240000 */  lhu       $a0, ($s1)
/* A1B4A8 802403A8 46001082 */  mul.s     $f2, $f2, $f0
/* A1B4AC 802403AC 00000000 */  nop
/* A1B4B0 802403B0 8E420000 */  lw        $v0, ($s2)
/* A1B4B4 802403B4 00042180 */  sll       $a0, $a0, 6
/* A1B4B8 802403B8 3C014234 */  lui       $at, 0x4234
/* A1B4BC 802403BC 44810000 */  mtc1      $at, $f0
/* A1B4C0 802403C0 00932021 */  addu      $a0, $a0, $s3
/* A1B4C4 802403C4 46001082 */  mul.s     $f2, $f2, $f0
/* A1B4C8 802403C8 00000000 */  nop
/* A1B4CC 802403CC 00442021 */  addu      $a0, $v0, $a0
/* A1B4D0 802403D0 44800000 */  mtc1      $zero, $f0
/* A1B4D4 802403D4 96020000 */  lhu       $v0, ($s0)
/* A1B4D8 802403D8 44060000 */  mfc1      $a2, $f0
/* A1B4DC 802403DC 44051000 */  mfc1      $a1, $f2
/* A1B4E0 802403E0 24420400 */  addiu     $v0, $v0, 0x400
/* A1B4E4 802403E4 A6020000 */  sh        $v0, ($s0)
/* A1B4E8 802403E8 0C019F20 */  jal       guRotate
/* A1B4EC 802403EC AFA60010 */   sw       $a2, 0x10($sp)
/* A1B4F0 802403F0 3C0ADA38 */  lui       $t2, 0xda38
/* A1B4F4 802403F4 354A0001 */  ori       $t2, $t2, 1
/* A1B4F8 802403F8 24040001 */  addiu     $a0, $zero, 1
/* A1B4FC 802403FC 27A50018 */  addiu     $a1, $sp, 0x18
/* A1B500 80240400 27A6001C */  addiu     $a2, $sp, 0x1c
/* A1B504 80240404 3C08800A */  lui       $t0, %hi(gMasterGfxPos)
/* A1B508 80240408 2508A66C */  addiu     $t0, $t0, %lo(gMasterGfxPos)
/* A1B50C 8024040C 27A70020 */  addiu     $a3, $sp, 0x20
/* A1B510 80240410 8D030000 */  lw        $v1, ($t0)
/* A1B514 80240414 96220000 */  lhu       $v0, ($s1)
/* A1B518 80240418 0060482D */  daddu     $t1, $v1, $zero
/* A1B51C 8024041C 24630008 */  addiu     $v1, $v1, 8
/* A1B520 80240420 AD030000 */  sw        $v1, ($t0)
/* A1B524 80240424 00441821 */  addu      $v1, $v0, $a0
/* A1B528 80240428 3042FFFF */  andi      $v0, $v0, 0xffff
/* A1B52C 8024042C 00021180 */  sll       $v0, $v0, 6
/* A1B530 80240430 AD2A0000 */  sw        $t2, ($t1)
/* A1B534 80240434 A6230000 */  sh        $v1, ($s1)
/* A1B538 80240438 8E430000 */  lw        $v1, ($s2)
/* A1B53C 8024043C 00531021 */  addu      $v0, $v0, $s3
/* A1B540 80240440 00621821 */  addu      $v1, $v1, $v0
/* A1B544 80240444 0C0470AC */  jal       mdl_get_copied_vertices
/* A1B548 80240448 AD230004 */   sw       $v1, 4($t1)
/* A1B54C 8024044C 8FA20020 */  lw        $v0, 0x20($sp)
/* A1B550 80240450 1840004F */  blez      $v0, .L80240590
/* A1B554 80240454 0000802D */   daddu    $s0, $zero, $zero
/* A1B558 80240458 3C158024 */  lui       $s5, %hi(D_80243BCE_A1ECCE)
/* A1B55C 8024045C 26B53BCE */  addiu     $s5, $s5, %lo(D_80243BCE_A1ECCE)
/* A1B560 80240460 3C135555 */  lui       $s3, 0x5555
/* A1B564 80240464 36735556 */  ori       $s3, $s3, 0x5556
/* A1B568 80240468 34148000 */  ori       $s4, $zero, 0x8000
/* A1B56C 8024046C 02130018 */  mult      $s0, $s3
.L80240470:
/* A1B570 80240470 001097C3 */  sra       $s2, $s0, 0x1f
/* A1B574 80240474 00001810 */  mfhi      $v1
/* A1B578 80240478 00721823 */  subu      $v1, $v1, $s2
/* A1B57C 8024047C 00031040 */  sll       $v0, $v1, 1
/* A1B580 80240480 00431021 */  addu      $v0, $v0, $v1
/* A1B584 80240484 02021023 */  subu      $v0, $s0, $v0
/* A1B588 80240488 96A30000 */  lhu       $v1, ($s5)
/* A1B58C 8024048C 24420001 */  addiu     $v0, $v0, 1
/* A1B590 80240490 00620018 */  mult      $v1, $v0
/* A1B594 80240494 00101100 */  sll       $v0, $s0, 4
/* A1B598 80240498 00001812 */  mflo      $v1
/* A1B59C 8024049C 00702021 */  addu      $a0, $v1, $s0
/* A1B5A0 802404A0 8FA3001C */  lw        $v1, 0x1c($sp)
/* A1B5A4 802404A4 3084FFFF */  andi      $a0, $a0, 0xffff
/* A1B5A8 802404A8 0C01917C */  jal       sins
/* A1B5AC 802404AC 00628821 */   addu     $s1, $v1, $v0
/* A1B5B0 802404B0 00021400 */  sll       $v0, $v0, 0x10
/* A1B5B4 802404B4 00021403 */  sra       $v0, $v0, 0x10
/* A1B5B8 802404B8 00541021 */  addu      $v0, $v0, $s4
/* A1B5BC 802404BC 00021FC2 */  srl       $v1, $v0, 0x1f
/* A1B5C0 802404C0 00431021 */  addu      $v0, $v0, $v1
/* A1B5C4 802404C4 000213C0 */  sll       $v0, $v0, 0xf
/* A1B5C8 802404C8 00021403 */  sra       $v0, $v0, 0x10
/* A1B5CC 802404CC 00021880 */  sll       $v1, $v0, 2
/* A1B5D0 802404D0 00621821 */  addu      $v1, $v1, $v0
/* A1B5D4 802404D4 00031140 */  sll       $v0, $v1, 5
/* A1B5D8 802404D8 00431823 */  subu      $v1, $v0, $v1
/* A1B5DC 802404DC 04610002 */  bgez      $v1, .L802404E8
/* A1B5E0 802404E0 0060102D */   daddu    $v0, $v1, $zero
/* A1B5E4 802404E4 24627FFF */  addiu     $v0, $v1, 0x7fff
.L802404E8:
/* A1B5E8 802404E8 000213C3 */  sra       $v0, $v0, 0xf
/* A1B5EC 802404EC 24420064 */  addiu     $v0, $v0, 0x64
/* A1B5F0 802404F0 A222000C */  sb        $v0, 0xc($s1)
/* A1B5F4 802404F4 02121823 */  subu      $v1, $s0, $s2
/* A1B5F8 802404F8 00032843 */  sra       $a1, $v1, 1
/* A1B5FC 802404FC 00B30018 */  mult      $a1, $s3
/* A1B600 80240500 A222000D */  sb        $v0, 0xd($s1)
/* A1B604 80240504 96A40000 */  lhu       $a0, ($s5)
/* A1B608 80240508 00031FC3 */  sra       $v1, $v1, 0x1f
/* A1B60C 8024050C 000433C2 */  srl       $a2, $a0, 0xf
/* A1B610 80240510 00004010 */  mfhi      $t0
/* A1B614 80240514 01031823 */  subu      $v1, $t0, $v1
/* A1B618 80240518 00031040 */  sll       $v0, $v1, 1
/* A1B61C 8024051C 00431021 */  addu      $v0, $v0, $v1
/* A1B620 80240520 00A22823 */  subu      $a1, $a1, $v0
/* A1B624 80240524 24A50001 */  addiu     $a1, $a1, 1
/* A1B628 80240528 00052BC0 */  sll       $a1, $a1, 0xf
/* A1B62C 8024052C 00C50018 */  mult      $a2, $a1
/* A1B630 80240530 00042382 */  srl       $a0, $a0, 0xe
/* A1B634 80240534 000423C0 */  sll       $a0, $a0, 0xf
/* A1B638 80240538 00001812 */  mflo      $v1
/* A1B63C 8024053C 00642021 */  addu      $a0, $v1, $a0
/* A1B640 80240540 00902021 */  addu      $a0, $a0, $s0
/* A1B644 80240544 0C01917C */  jal       sins
/* A1B648 80240548 3084FFFF */   andi     $a0, $a0, 0xffff
/* A1B64C 8024054C 00021400 */  sll       $v0, $v0, 0x10
/* A1B650 80240550 00021403 */  sra       $v0, $v0, 0x10
/* A1B654 80240554 9223000C */  lbu       $v1, 0xc($s1)
/* A1B658 80240558 00541021 */  addu      $v0, $v0, $s4
/* A1B65C 8024055C 00620018 */  mult      $v1, $v0
/* A1B660 80240560 00001812 */  mflo      $v1
/* A1B664 80240564 04610004 */  bgez      $v1, .L80240578
/* A1B668 80240568 00031403 */   sra      $v0, $v1, 0x10
/* A1B66C 8024056C 3402FFFF */  ori       $v0, $zero, 0xffff
/* A1B670 80240570 00621821 */  addu      $v1, $v1, $v0
/* A1B674 80240574 00031403 */  sra       $v0, $v1, 0x10
.L80240578:
/* A1B678 80240578 A222000E */  sb        $v0, 0xe($s1)
/* A1B67C 8024057C 8FA20020 */  lw        $v0, 0x20($sp)
/* A1B680 80240580 26100001 */  addiu     $s0, $s0, 1
/* A1B684 80240584 0202102A */  slt       $v0, $s0, $v0
/* A1B688 80240588 1440FFB9 */  bnez      $v0, .L80240470
/* A1B68C 8024058C 02130018 */   mult     $s0, $s3
.L80240590:
/* A1B690 80240590 3C05D9FF */  lui       $a1, 0xd9ff
/* A1B694 80240594 34A5F9FF */  ori       $a1, $a1, 0xf9ff
/* A1B698 80240598 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* A1B69C 8024059C 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* A1B6A0 802405A0 8C700000 */  lw        $s0, ($v1)
/* A1B6A4 802405A4 24040001 */  addiu     $a0, $zero, 1
/* A1B6A8 802405A8 0200102D */  daddu     $v0, $s0, $zero
/* A1B6AC 802405AC 26100008 */  addiu     $s0, $s0, 8
/* A1B6B0 802405B0 AC700000 */  sw        $s0, ($v1)
/* A1B6B4 802405B4 AC450000 */  sw        $a1, ($v0)
/* A1B6B8 802405B8 AC400004 */  sw        $zero, 4($v0)
/* A1B6BC 802405BC 26020008 */  addiu     $v0, $s0, 8
/* A1B6C0 802405C0 AC620000 */  sw        $v0, ($v1)
/* A1B6C4 802405C4 3C02DE00 */  lui       $v0, 0xde00
/* A1B6C8 802405C8 0C0470BB */  jal       mdl_get_copied_gfx
/* A1B6CC 802405CC AE020000 */   sw       $v0, ($s0)
/* A1B6D0 802405D0 3C048024 */  lui       $a0, %hi(D_80243BCE_A1ECCE)
/* A1B6D4 802405D4 24843BCE */  addiu     $a0, $a0, %lo(D_80243BCE_A1ECCE)
/* A1B6D8 802405D8 94830000 */  lhu       $v1, ($a0)
/* A1B6DC 802405DC AE020004 */  sw        $v0, 4($s0)
/* A1B6E0 802405E0 24630666 */  addiu     $v1, $v1, 0x666
/* A1B6E4 802405E4 A4830000 */  sh        $v1, ($a0)
/* A1B6E8 802405E8 8FBF0040 */  lw        $ra, 0x40($sp)
/* A1B6EC 802405EC 8FB5003C */  lw        $s5, 0x3c($sp)
/* A1B6F0 802405F0 8FB40038 */  lw        $s4, 0x38($sp)
/* A1B6F4 802405F4 8FB30034 */  lw        $s3, 0x34($sp)
/* A1B6F8 802405F8 8FB20030 */  lw        $s2, 0x30($sp)
/* A1B6FC 802405FC 8FB1002C */  lw        $s1, 0x2c($sp)
/* A1B700 80240600 8FB00028 */  lw        $s0, 0x28($sp)
/* A1B704 80240604 03E00008 */  jr        $ra
/* A1B708 80240608 27BD0048 */   addiu    $sp, $sp, 0x48
