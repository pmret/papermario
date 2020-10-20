.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802424AC
/* DF134C 802424AC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DF1350 802424B0 AFB10014 */  sw        $s1, 0x14($sp)
/* DF1354 802424B4 0080882D */  daddu     $s1, $a0, $zero
/* DF1358 802424B8 3C05800B */  lui       $a1, %hi(gCameras)
/* DF135C 802424BC 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* DF1360 802424C0 AFBF0020 */  sw        $ra, 0x20($sp)
/* DF1364 802424C4 AFB3001C */  sw        $s3, 0x1c($sp)
/* DF1368 802424C8 AFB20018 */  sw        $s2, 0x18($sp)
/* DF136C 802424CC AFB00010 */  sw        $s0, 0x10($sp)
/* DF1370 802424D0 F7B40028 */  sdc1      $f20, 0x28($sp)
/* DF1374 802424D4 8E330148 */  lw        $s3, 0x148($s1)
/* DF1378 802424D8 3C03800A */  lui       $v1, 0x800a
/* DF137C 802424DC 8463A634 */  lh        $v1, -0x59cc($v1)
/* DF1380 802424E0 8E30000C */  lw        $s0, 0xc($s1)
/* DF1384 802424E4 00031080 */  sll       $v0, $v1, 2
/* DF1388 802424E8 00431021 */  addu      $v0, $v0, $v1
/* DF138C 802424EC 00021080 */  sll       $v0, $v0, 2
/* DF1390 802424F0 00431023 */  subu      $v0, $v0, $v1
/* DF1394 802424F4 000218C0 */  sll       $v1, $v0, 3
/* DF1398 802424F8 00431021 */  addu      $v0, $v0, $v1
/* DF139C 802424FC 000210C0 */  sll       $v0, $v0, 3
/* DF13A0 80242500 86640008 */  lh        $a0, 8($s3)
/* DF13A4 80242504 0C00EABB */  jal       get_npc_unsafe
/* DF13A8 80242508 00459021 */   addu     $s2, $v0, $a1
/* DF13AC 8024250C 0220202D */  daddu     $a0, $s1, $zero
/* DF13B0 80242510 8E050000 */  lw        $a1, ($s0)
/* DF13B4 80242514 0C0B1EAF */  jal       get_variable
/* DF13B8 80242518 0040802D */   daddu    $s0, $v0, $zero
/* DF13BC 8024251C 0260202D */  daddu     $a0, $s3, $zero
/* DF13C0 80242520 8C460024 */  lw        $a2, 0x24($v0)
/* DF13C4 80242524 8C470028 */  lw        $a3, 0x28($v0)
/* DF13C8 80242528 0C0124FB */  jal       func_800493EC
/* DF13CC 8024252C 0000282D */   daddu    $a1, $zero, $zero
/* DF13D0 80242530 10400052 */  beqz      $v0, .L8024267C
/* DF13D4 80242534 2402FFFF */   addiu    $v0, $zero, -1
/* DF13D8 80242538 C64C006C */  lwc1      $f12, 0x6c($s2)
/* DF13DC 8024253C C60E000C */  lwc1      $f14, 0xc($s0)
/* DF13E0 80242540 3C014387 */  lui       $at, 0x4387
/* DF13E4 80242544 4481A000 */  mtc1      $at, $f20
/* DF13E8 80242548 0C00A70A */  jal       get_clamped_angle_diff
/* DF13EC 8024254C 00000000 */   nop      
/* DF13F0 80242550 0C00A6C9 */  jal       clamp_angle
/* DF13F4 80242554 46000306 */   mov.s    $f12, $f0
/* DF13F8 80242558 3C018024 */  lui       $at, 0x8024
/* DF13FC 8024255C D42279A8 */  ldc1      $f2, 0x79a8($at)
/* DF1400 80242560 46000021 */  cvt.d.s   $f0, $f0
/* DF1404 80242564 4622003C */  c.lt.d    $f0, $f2
/* DF1408 80242568 00000000 */  nop       
/* DF140C 8024256C 45000003 */  bc1f      .L8024257C
/* DF1410 80242570 00000000 */   nop      
/* DF1414 80242574 3C0142B4 */  lui       $at, 0x42b4
/* DF1418 80242578 4481A000 */  mtc1      $at, $f20
.L8024257C:
/* DF141C 8024257C 3C11800F */  lui       $s1, %hi(gPlayerStatusPtr)
/* DF1420 80242580 26317B30 */  addiu     $s1, $s1, %lo(gPlayerStatusPtr)
/* DF1424 80242584 C60C0038 */  lwc1      $f12, 0x38($s0)
/* DF1428 80242588 8E220000 */  lw        $v0, ($s1)
/* DF142C 8024258C C60E0040 */  lwc1      $f14, 0x40($s0)
/* DF1430 80242590 8C460028 */  lw        $a2, 0x28($v0)
/* DF1434 80242594 0C00A720 */  jal       atan2
/* DF1438 80242598 8C470030 */   lw       $a3, 0x30($v0)
/* DF143C 8024259C 4600A306 */  mov.s     $f12, $f20
/* DF1440 802425A0 0C00A70A */  jal       get_clamped_angle_diff
/* DF1444 802425A4 46000386 */   mov.s    $f14, $f0
/* DF1448 802425A8 46000005 */  abs.s     $f0, $f0
/* DF144C 802425AC 3C018024 */  lui       $at, 0x8024
/* DF1450 802425B0 D42279B0 */  ldc1      $f2, 0x79b0($at)
/* DF1454 802425B4 46000021 */  cvt.d.s   $f0, $f0
/* DF1458 802425B8 4620103C */  c.lt.d    $f2, $f0
/* DF145C 802425BC 00000000 */  nop       
/* DF1460 802425C0 4501002E */  bc1t      .L8024267C
/* DF1464 802425C4 2402FFFF */   addiu    $v0, $zero, -1
/* DF1468 802425C8 8E220000 */  lw        $v0, ($s1)
/* DF146C 802425CC C600003C */  lwc1      $f0, 0x3c($s0)
/* DF1470 802425D0 C442002C */  lwc1      $f2, 0x2c($v0)
/* DF1474 802425D4 860200A8 */  lh        $v0, 0xa8($s0)
/* DF1478 802425D8 46020001 */  sub.s     $f0, $f0, $f2
/* DF147C 802425DC 44821000 */  mtc1      $v0, $f2
/* DF1480 802425E0 00000000 */  nop       
/* DF1484 802425E4 468010A1 */  cvt.d.w   $f2, $f2
/* DF1488 802425E8 46221080 */  add.d     $f2, $f2, $f2
/* DF148C 802425EC 46000005 */  abs.s     $f0, $f0
/* DF1490 802425F0 46000021 */  cvt.d.s   $f0, $f0
/* DF1494 802425F4 4620103E */  c.le.d    $f2, $f0
/* DF1498 802425F8 00000000 */  nop       
/* DF149C 802425FC 4501001F */  bc1t      .L8024267C
/* DF14A0 80242600 2402FFFF */   addiu    $v0, $zero, -1
/* DF14A4 80242604 3C038011 */  lui       $v1, 0x8011
/* DF14A8 80242608 8063EBB3 */  lb        $v1, -0x144d($v1)
/* DF14AC 8024260C 24020009 */  addiu     $v0, $zero, 9
/* DF14B0 80242610 10620019 */  beq       $v1, $v0, .L80242678
/* DF14B4 80242614 24020007 */   addiu    $v0, $zero, 7
/* DF14B8 80242618 14620005 */  bne       $v1, $v0, .L80242630
/* DF14BC 8024261C 2402FFFF */   addiu    $v0, $zero, -1
/* DF14C0 80242620 0809099F */  j         .L8024267C
/* DF14C4 80242624 00000000 */   nop      
.L80242628:
/* DF14C8 80242628 0809099F */  j         .L8024267C
/* DF14CC 8024262C 0240102D */   daddu    $v0, $s2, $zero
.L80242630:
/* DF14D0 80242630 8E620078 */  lw        $v0, 0x78($s3)
/* DF14D4 80242634 18400010 */  blez      $v0, .L80242678
/* DF14D8 80242638 0000882D */   daddu    $s1, $zero, $zero
.L8024263C:
/* DF14DC 8024263C 86620008 */  lh        $v0, 8($s3)
/* DF14E0 80242640 00511021 */  addu      $v0, $v0, $s1
/* DF14E4 80242644 24520001 */  addiu     $s2, $v0, 1
/* DF14E8 80242648 0C00FB3A */  jal       get_enemy
/* DF14EC 8024264C 0240202D */   daddu    $a0, $s2, $zero
/* DF14F0 80242650 0240202D */  daddu     $a0, $s2, $zero
/* DF14F4 80242654 0C00EABB */  jal       get_npc_unsafe
/* DF14F8 80242658 0040802D */   daddu    $s0, $v0, $zero
/* DF14FC 8024265C 8E02006C */  lw        $v0, 0x6c($s0)
/* DF1500 80242660 1040FFF1 */  beqz      $v0, .L80242628
/* DF1504 80242664 26310001 */   addiu    $s1, $s1, 1
/* DF1508 80242668 8E620078 */  lw        $v0, 0x78($s3)
/* DF150C 8024266C 0222102A */  slt       $v0, $s1, $v0
/* DF1510 80242670 1440FFF2 */  bnez      $v0, .L8024263C
/* DF1514 80242674 00000000 */   nop      
.L80242678:
/* DF1518 80242678 2402FFFF */  addiu     $v0, $zero, -1
.L8024267C:
/* DF151C 8024267C 8FBF0020 */  lw        $ra, 0x20($sp)
/* DF1520 80242680 8FB3001C */  lw        $s3, 0x1c($sp)
/* DF1524 80242684 8FB20018 */  lw        $s2, 0x18($sp)
/* DF1528 80242688 8FB10014 */  lw        $s1, 0x14($sp)
/* DF152C 8024268C 8FB00010 */  lw        $s0, 0x10($sp)
/* DF1530 80242690 D7B40028 */  ldc1      $f20, 0x28($sp)
/* DF1534 80242694 03E00008 */  jr        $ra
/* DF1538 80242698 27BD0030 */   addiu    $sp, $sp, 0x30
