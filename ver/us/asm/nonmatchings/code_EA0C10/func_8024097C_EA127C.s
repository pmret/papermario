.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024097C_EA127C
/* EA127C 8024097C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* EA1280 80240980 AFB3003C */  sw        $s3, 0x3c($sp)
/* EA1284 80240984 0080982D */  daddu     $s3, $a0, $zero
/* EA1288 80240988 AFBF0048 */  sw        $ra, 0x48($sp)
/* EA128C 8024098C AFB50044 */  sw        $s5, 0x44($sp)
/* EA1290 80240990 AFB40040 */  sw        $s4, 0x40($sp)
/* EA1294 80240994 AFB20038 */  sw        $s2, 0x38($sp)
/* EA1298 80240998 AFB10034 */  sw        $s1, 0x34($sp)
/* EA129C 8024099C AFB00030 */  sw        $s0, 0x30($sp)
/* EA12A0 802409A0 8E710148 */  lw        $s1, 0x148($s3)
/* EA12A4 802409A4 86240008 */  lh        $a0, 8($s1)
/* EA12A8 802409A8 0C00F92F */  jal       func_8003E4BC
/* EA12AC 802409AC 00A0802D */   daddu    $s0, $a1, $zero
/* EA12B0 802409B0 8E63000C */  lw        $v1, 0xc($s3)
/* EA12B4 802409B4 0260202D */  daddu     $a0, $s3, $zero
/* EA12B8 802409B8 8C650000 */  lw        $a1, ($v1)
/* EA12BC 802409BC 0C0B53A3 */  jal       func_802D4E8C
/* EA12C0 802409C0 0040902D */   daddu    $s2, $v0, $zero
/* EA12C4 802409C4 AFA00010 */  sw        $zero, 0x10($sp)
/* EA12C8 802409C8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EA12CC 802409CC 8C630030 */  lw        $v1, 0x30($v1)
/* EA12D0 802409D0 AFA30014 */  sw        $v1, 0x14($sp)
/* EA12D4 802409D4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EA12D8 802409D8 8C63001C */  lw        $v1, 0x1c($v1)
/* EA12DC 802409DC AFA30018 */  sw        $v1, 0x18($sp)
/* EA12E0 802409E0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EA12E4 802409E4 8C630024 */  lw        $v1, 0x24($v1)
/* EA12E8 802409E8 AFA3001C */  sw        $v1, 0x1c($sp)
/* EA12EC 802409EC 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EA12F0 802409F0 8C630028 */  lw        $v1, 0x28($v1)
/* EA12F4 802409F4 AFA30020 */  sw        $v1, 0x20($sp)
/* EA12F8 802409F8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EA12FC 802409FC 3C014282 */  lui       $at, 0x4282
/* EA1300 80240A00 44810000 */  mtc1      $at, $f0
/* EA1304 80240A04 8C63002C */  lw        $v1, 0x2c($v1)
/* EA1308 80240A08 E7A00028 */  swc1      $f0, 0x28($sp)
/* EA130C 80240A0C A7A0002C */  sh        $zero, 0x2c($sp)
/* EA1310 80240A10 AFA30024 */  sw        $v1, 0x24($sp)
/* EA1314 80240A14 C6400038 */  lwc1      $f0, 0x38($s2)
/* EA1318 80240A18 E6200108 */  swc1      $f0, 0x108($s1)
/* EA131C 80240A1C C640003C */  lwc1      $f0, 0x3c($s2)
/* EA1320 80240A20 27B50010 */  addiu     $s5, $sp, 0x10
/* EA1324 80240A24 E620010C */  swc1      $f0, 0x10c($s1)
/* EA1328 80240A28 3C0138D1 */  lui       $at, 0x38d1
/* EA132C 80240A2C 3421B717 */  ori       $at, $at, 0xb717
/* EA1330 80240A30 44810000 */  mtc1      $at, $f0
/* EA1334 80240A34 C6420040 */  lwc1      $f2, 0x40($s2)
/* EA1338 80240A38 0040A02D */  daddu     $s4, $v0, $zero
/* EA133C 80240A3C E6200114 */  swc1      $f0, 0x114($s1)
/* EA1340 80240A40 E6200118 */  swc1      $f0, 0x118($s1)
/* EA1344 80240A44 16000005 */  bnez      $s0, .L80240A5C
/* EA1348 80240A48 E6220110 */   swc1     $f2, 0x110($s1)
/* EA134C 80240A4C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* EA1350 80240A50 30420004 */  andi      $v0, $v0, 4
/* EA1354 80240A54 10400020 */  beqz      $v0, .L80240AD8
/* EA1358 80240A58 00000000 */   nop
.L80240A5C:
/* EA135C 80240A5C 2404F7FF */  addiu     $a0, $zero, -0x801
/* EA1360 80240A60 AE600070 */  sw        $zero, 0x70($s3)
/* EA1364 80240A64 A640008E */  sh        $zero, 0x8e($s2)
/* EA1368 80240A68 8E2200CC */  lw        $v0, 0xcc($s1)
/* EA136C 80240A6C 8E430000 */  lw        $v1, ($s2)
/* EA1370 80240A70 8C420000 */  lw        $v0, ($v0)
/* EA1374 80240A74 00641824 */  and       $v1, $v1, $a0
/* EA1378 80240A78 AE430000 */  sw        $v1, ($s2)
/* EA137C 80240A7C AE420028 */  sw        $v0, 0x28($s2)
/* EA1380 80240A80 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EA1384 80240A84 8C420034 */  lw        $v0, 0x34($v0)
/* EA1388 80240A88 54400005 */  bnel      $v0, $zero, .L80240AA0
/* EA138C 80240A8C 2402FDFF */   addiu    $v0, $zero, -0x201
/* EA1390 80240A90 34620200 */  ori       $v0, $v1, 0x200
/* EA1394 80240A94 2403FFF7 */  addiu     $v1, $zero, -9
/* EA1398 80240A98 080902AA */  j         .L80240AA8
/* EA139C 80240A9C 00431024 */   and      $v0, $v0, $v1
.L80240AA0:
/* EA13A0 80240AA0 00621024 */  and       $v0, $v1, $v0
/* EA13A4 80240AA4 34420008 */  ori       $v0, $v0, 8
.L80240AA8:
/* EA13A8 80240AA8 AE420000 */  sw        $v0, ($s2)
/* EA13AC 80240AAC 8E2200B0 */  lw        $v0, 0xb0($s1)
/* EA13B0 80240AB0 30420004 */  andi      $v0, $v0, 4
/* EA13B4 80240AB4 10400007 */  beqz      $v0, .L80240AD4
/* EA13B8 80240AB8 24020063 */   addiu    $v0, $zero, 0x63
/* EA13BC 80240ABC AE620070 */  sw        $v0, 0x70($s3)
/* EA13C0 80240AC0 AE600074 */  sw        $zero, 0x74($s3)
/* EA13C4 80240AC4 8E2200B0 */  lw        $v0, 0xb0($s1)
/* EA13C8 80240AC8 2403FFFB */  addiu     $v1, $zero, -5
/* EA13CC 80240ACC 00431024 */  and       $v0, $v0, $v1
/* EA13D0 80240AD0 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80240AD4:
/* EA13D4 80240AD4 AE20006C */  sw        $zero, 0x6c($s1)
.L80240AD8:
/* EA13D8 80240AD8 8E620070 */  lw        $v0, 0x70($s3)
/* EA13DC 80240ADC 2842001E */  slti      $v0, $v0, 0x1e
/* EA13E0 80240AE0 10400009 */  beqz      $v0, .L80240B08
/* EA13E4 80240AE4 00000000 */   nop
/* EA13E8 80240AE8 8E22006C */  lw        $v0, 0x6c($s1)
/* EA13EC 80240AEC 14400006 */  bnez      $v0, .L80240B08
/* EA13F0 80240AF0 00000000 */   nop
/* EA13F4 80240AF4 0C090146 */  jal       func_80240518_EA0E18
/* EA13F8 80240AF8 0260202D */   daddu    $a0, $s3, $zero
/* EA13FC 80240AFC 10400002 */  beqz      $v0, .L80240B08
/* EA1400 80240B00 2402001E */   addiu    $v0, $zero, 0x1e
/* EA1404 80240B04 AE620070 */  sw        $v0, 0x70($s3)
.L80240B08:
/* EA1408 80240B08 8E630070 */  lw        $v1, 0x70($s3)
/* EA140C 80240B0C 2C620064 */  sltiu     $v0, $v1, 0x64
/* EA1410 80240B10 10400048 */  beqz      $v0, L80240C34_EA1534
/* EA1414 80240B14 00031080 */   sll      $v0, $v1, 2
/* EA1418 80240B18 3C018024 */  lui       $at, %hi(jtbl_80246488_EA6D88)
/* EA141C 80240B1C 00220821 */  addu      $at, $at, $v0
/* EA1420 80240B20 8C226488 */  lw        $v0, %lo(jtbl_80246488_EA6D88)($at)
/* EA1424 80240B24 00400008 */  jr        $v0
/* EA1428 80240B28 00000000 */   nop
glabel L80240B2C_EA142C
/* EA142C 80240B2C 0260202D */  daddu     $a0, $s3, $zero
/* EA1430 80240B30 0280282D */  daddu     $a1, $s4, $zero
/* EA1434 80240B34 0C013670 */  jal       func_8004D9C0
/* EA1438 80240B38 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240B3C_EA143C
/* EA143C 80240B3C 0260202D */  daddu     $a0, $s3, $zero
/* EA1440 80240B40 0280282D */  daddu     $a1, $s4, $zero
/* EA1444 80240B44 0C0136B6 */  jal       func_8004DAD8
/* EA1448 80240B48 02A0302D */   daddu    $a2, $s5, $zero
/* EA144C 80240B4C 0809030D */  j         L80240C34_EA1534
/* EA1450 80240B50 00000000 */   nop
glabel L80240B54_EA1454
/* EA1454 80240B54 0260202D */  daddu     $a0, $s3, $zero
/* EA1458 80240B58 0280282D */  daddu     $a1, $s4, $zero
/* EA145C 80240B5C 0C0137D9 */  jal       func_8004DF64
/* EA1460 80240B60 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240B64_EA1464
/* EA1464 80240B64 0260202D */  daddu     $a0, $s3, $zero
/* EA1468 80240B68 0280282D */  daddu     $a1, $s4, $zero
/* EA146C 80240B6C 0C013809 */  jal       func_8004E024
/* EA1470 80240B70 02A0302D */   daddu    $a2, $s5, $zero
/* EA1474 80240B74 0809030D */  j         L80240C34_EA1534
/* EA1478 80240B78 00000000 */   nop
glabel L80240B7C_EA147C
/* EA147C 80240B7C 0260202D */  daddu     $a0, $s3, $zero
/* EA1480 80240B80 0280282D */  daddu     $a1, $s4, $zero
/* EA1484 80240B84 0C013897 */  jal       func_8004E25C
/* EA1488 80240B88 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240B8C_EA148C
/* EA148C 80240B8C 0260202D */  daddu     $a0, $s3, $zero
/* EA1490 80240B90 0280282D */  daddu     $a1, $s4, $zero
/* EA1494 80240B94 0C0138BB */  jal       func_8004E2EC
/* EA1498 80240B98 02A0302D */   daddu    $a2, $s5, $zero
/* EA149C 80240B9C 0809030D */  j         L80240C34_EA1534
/* EA14A0 80240BA0 00000000 */   nop
glabel L80240BA4_EA14A4
/* EA14A4 80240BA4 0260202D */  daddu     $a0, $s3, $zero
/* EA14A8 80240BA8 0280282D */  daddu     $a1, $s4, $zero
/* EA14AC 80240BAC 0C0138E7 */  jal       func_8004E39C
/* EA14B0 80240BB0 02A0302D */   daddu    $a2, $s5, $zero
glabel L80240BB4_EA14B4
/* EA14B4 80240BB4 0260202D */  daddu     $a0, $s3, $zero
/* EA14B8 80240BB8 0280282D */  daddu     $a1, $s4, $zero
/* EA14BC 80240BBC 0C013951 */  jal       func_8004E544
/* EA14C0 80240BC0 02A0302D */   daddu    $a2, $s5, $zero
/* EA14C4 80240BC4 0809030D */  j         L80240C34_EA1534
/* EA14C8 80240BC8 00000000 */   nop
glabel L80240BCC_EA14CC
/* EA14CC 80240BCC 0260202D */  daddu     $a0, $s3, $zero
/* EA14D0 80240BD0 0280282D */  daddu     $a1, $s4, $zero
/* EA14D4 80240BD4 0C013A02 */  jal       func_8004E808
/* EA14D8 80240BD8 02A0302D */   daddu    $a2, $s5, $zero
/* EA14DC 80240BDC 0809030D */  j         L80240C34_EA1534
/* EA14E0 80240BE0 00000000 */   nop
glabel L80240BE4_EA14E4
/* EA14E4 80240BE4 0C0900C4 */  jal       func_80240310_EA0C10
/* EA14E8 80240BE8 0260202D */   daddu    $a0, $s3, $zero
glabel L80240BEC_EA14EC
/* EA14EC 80240BEC 0C0900DF */  jal       func_8024037C_EA0C7C
/* EA14F0 80240BF0 0260202D */   daddu    $a0, $s3, $zero
/* EA14F4 80240BF4 8E630070 */  lw        $v1, 0x70($s3)
/* EA14F8 80240BF8 24020020 */  addiu     $v0, $zero, 0x20
/* EA14FC 80240BFC 1462000D */  bne       $v1, $v0, L80240C34_EA1534
/* EA1500 80240C00 00000000 */   nop
glabel L80240C04_EA1504
/* EA1504 80240C04 0C0900FB */  jal       func_802403EC_EA0CEC
/* EA1508 80240C08 0260202D */   daddu    $a0, $s3, $zero
/* EA150C 80240C0C 8E630070 */  lw        $v1, 0x70($s3)
/* EA1510 80240C10 24020021 */  addiu     $v0, $zero, 0x21
/* EA1514 80240C14 14620007 */  bne       $v1, $v0, L80240C34_EA1534
/* EA1518 80240C18 00000000 */   nop
glabel L80240C1C_EA151C
/* EA151C 80240C1C 0C090131 */  jal       func_802404C4_EA0DC4
/* EA1520 80240C20 0260202D */   daddu    $a0, $s3, $zero
/* EA1524 80240C24 0809030D */  j         L80240C34_EA1534
/* EA1528 80240C28 00000000 */   nop
glabel L80240C2C_EA152C
/* EA152C 80240C2C 0C013AE3 */  jal       func_8004EB8C
/* EA1530 80240C30 0260202D */   daddu    $a0, $s3, $zero
glabel L80240C34_EA1534
/* EA1534 80240C34 8FBF0048 */  lw        $ra, 0x48($sp)
/* EA1538 80240C38 8FB50044 */  lw        $s5, 0x44($sp)
/* EA153C 80240C3C 8FB40040 */  lw        $s4, 0x40($sp)
/* EA1540 80240C40 8FB3003C */  lw        $s3, 0x3c($sp)
/* EA1544 80240C44 8FB20038 */  lw        $s2, 0x38($sp)
/* EA1548 80240C48 8FB10034 */  lw        $s1, 0x34($sp)
/* EA154C 80240C4C 8FB00030 */  lw        $s0, 0x30($sp)
/* EA1550 80240C50 0000102D */  daddu     $v0, $zero, $zero
/* EA1554 80240C54 03E00008 */  jr        $ra
/* EA1558 80240C58 27BD0050 */   addiu    $sp, $sp, 0x50
