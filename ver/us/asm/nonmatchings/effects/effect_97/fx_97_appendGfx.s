.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_97_appendGfx
/* 3C13EC E00C221C 27BDFF40 */  addiu     $sp, $sp, -0xc0
/* 3C13F0 E00C2220 0080302D */  daddu     $a2, $a0, $zero
/* 3C13F4 E00C2224 3C07DB06 */  lui       $a3, 0xdb06
/* 3C13F8 E00C2228 34E70024 */  ori       $a3, $a3, 0x24
/* 3C13FC E00C222C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3C1400 E00C2230 AFB300A4 */  sw        $s3, 0xa4($sp)
/* 3C1404 E00C2234 3C130001 */  lui       $s3, 1
/* 3C1408 E00C2238 AFB400A8 */  sw        $s4, 0xa8($sp)
/* 3C140C E00C223C 3C14800A */  lui       $s4, %hi(gMasterGfxPos)
/* 3C1410 E00C2240 2694A66C */  addiu     $s4, $s4, %lo(gMasterGfxPos)
/* 3C1414 E00C2244 AFBF00B8 */  sw        $ra, 0xb8($sp)
/* 3C1418 E00C2248 AFB700B4 */  sw        $s7, 0xb4($sp)
/* 3C141C E00C224C AFB600B0 */  sw        $s6, 0xb0($sp)
/* 3C1420 E00C2250 AFB500AC */  sw        $s5, 0xac($sp)
/* 3C1424 E00C2254 AFB200A0 */  sw        $s2, 0xa0($sp)
/* 3C1428 E00C2258 AFB1009C */  sw        $s1, 0x9c($sp)
/* 3C142C E00C225C AFB00098 */  sw        $s0, 0x98($sp)
/* 3C1430 E00C2260 8E850000 */  lw        $a1, ($s4)
/* 3C1434 E00C2264 8CD6000C */  lw        $s6, 0xc($a2)
/* 3C1438 E00C2268 00A0182D */  daddu     $v1, $a1, $zero
/* 3C143C E00C226C 24A50008 */  addiu     $a1, $a1, 8
/* 3C1440 E00C2270 AE850000 */  sw        $a1, ($s4)
/* 3C1444 E00C2274 8ED50014 */  lw        $s5, 0x14($s6)
/* 3C1448 E00C2278 8ED70024 */  lw        $s7, 0x24($s6)
/* 3C144C E00C227C 3C02E700 */  lui       $v0, 0xe700
/* 3C1450 E00C2280 AFB70090 */  sw        $s7, 0x90($sp)
/* 3C1454 E00C2284 AC620000 */  sw        $v0, ($v1)
/* 3C1458 E00C2288 AC600004 */  sw        $zero, 4($v1)
/* 3C145C E00C228C ACA70000 */  sw        $a3, ($a1)
/* 3C1460 E00C2290 8CC30010 */  lw        $v1, 0x10($a2)
/* 3C1464 E00C2294 24A20008 */  addiu     $v0, $a1, 8
/* 3C1468 E00C2298 AE820000 */  sw        $v0, ($s4)
/* 3C146C E00C229C 8C62001C */  lw        $v0, 0x1c($v1)
/* 3C1470 E00C22A0 3C038000 */  lui       $v1, 0x8000
/* 3C1474 E00C22A4 00431021 */  addu      $v0, $v0, $v1
/* 3C1478 E00C22A8 3C03800B */  lui       $v1, %hi(gCameras)
/* 3C147C E00C22AC 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 3C1480 E00C22B0 ACA20004 */  sw        $v0, 4($a1)
/* 3C1484 E00C22B4 8EC50004 */  lw        $a1, 4($s6)
/* 3C1488 E00C22B8 8EC60008 */  lw        $a2, 8($s6)
/* 3C148C E00C22BC 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 3C1490 E00C22C0 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 3C1494 E00C22C4 8EC7000C */  lw        $a3, 0xc($s6)
/* 3C1498 E00C22C8 00028080 */  sll       $s0, $v0, 2
/* 3C149C E00C22CC 02028021 */  addu      $s0, $s0, $v0
/* 3C14A0 E00C22D0 00108080 */  sll       $s0, $s0, 2
/* 3C14A4 E00C22D4 02028023 */  subu      $s0, $s0, $v0
/* 3C14A8 E00C22D8 001010C0 */  sll       $v0, $s0, 3
/* 3C14AC E00C22DC 02028021 */  addu      $s0, $s0, $v0
/* 3C14B0 E00C22E0 001080C0 */  sll       $s0, $s0, 3
/* 3C14B4 E00C22E4 0C080108 */  jal       shim_guTranslateF
/* 3C14B8 E00C22E8 02038021 */   addu     $s0, $s0, $v1
/* 3C14BC E00C22EC C6C00028 */  lwc1      $f0, 0x28($s6)
/* 3C14C0 E00C22F0 36731630 */  ori       $s3, $s3, 0x1630
/* 3C14C4 E00C22F4 44060000 */  mfc1      $a2, $f0
/* 3C14C8 E00C22F8 27B10050 */  addiu     $s1, $sp, 0x50
/* 3C14CC E00C22FC 44867000 */  mtc1      $a2, $f14
/* 3C14D0 E00C2300 0220202D */  daddu     $a0, $s1, $zero
/* 3C14D4 E00C2304 46007387 */  neg.s     $f14, $f14
/* 3C14D8 E00C2308 44057000 */  mfc1      $a1, $f14
/* 3C14DC E00C230C 0C080110 */  jal       shim_guScaleF
/* 3C14E0 E00C2310 00C0382D */   daddu    $a3, $a2, $zero
/* 3C14E4 E00C2314 0220202D */  daddu     $a0, $s1, $zero
/* 3C14E8 E00C2318 27A50010 */  addiu     $a1, $sp, 0x10
/* 3C14EC E00C231C 0C080114 */  jal       shim_guMtxCatF
/* 3C14F0 E00C2320 00A0302D */   daddu    $a2, $a1, $zero
/* 3C14F4 E00C2324 27A40010 */  addiu     $a0, $sp, 0x10
/* 3C14F8 E00C2328 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* 3C14FC E00C232C 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* 3C1500 E00C2330 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* 3C1504 E00C2334 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* 3C1508 E00C2338 96250000 */  lhu       $a1, ($s1)
/* 3C150C E00C233C 8E420000 */  lw        $v0, ($s2)
/* 3C1510 E00C2340 00052980 */  sll       $a1, $a1, 6
/* 3C1514 E00C2344 00B32821 */  addu      $a1, $a1, $s3
/* 3C1518 E00C2348 0C080118 */  jal       shim_guMtxF2L
/* 3C151C E00C234C 00452821 */   addu     $a1, $v0, $a1
/* 3C1520 E00C2350 3C03DA38 */  lui       $v1, 0xda38
/* 3C1524 E00C2354 34630002 */  ori       $v1, $v1, 2
/* 3C1528 E00C2358 3C05DA38 */  lui       $a1, 0xda38
/* 3C152C E00C235C 34A50001 */  ori       $a1, $a1, 1
/* 3C1530 E00C2360 24020036 */  addiu     $v0, $zero, 0x36
/* 3C1534 E00C2364 00553823 */  subu      $a3, $v0, $s5
/* 3C1538 E00C2368 8E860000 */  lw        $a2, ($s4)
/* 3C153C E00C236C 96220000 */  lhu       $v0, ($s1)
/* 3C1540 E00C2370 00C0202D */  daddu     $a0, $a2, $zero
/* 3C1544 E00C2374 24C60008 */  addiu     $a2, $a2, 8
/* 3C1548 E00C2378 AE860000 */  sw        $a2, ($s4)
/* 3C154C E00C237C AC830000 */  sw        $v1, ($a0)
/* 3C1550 E00C2380 24430001 */  addiu     $v1, $v0, 1
/* 3C1554 E00C2384 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3C1558 E00C2388 00021180 */  sll       $v0, $v0, 6
/* 3C155C E00C238C A6230000 */  sh        $v1, ($s1)
/* 3C1560 E00C2390 8E430000 */  lw        $v1, ($s2)
/* 3C1564 E00C2394 00531021 */  addu      $v0, $v0, $s3
/* 3C1568 E00C2398 00621821 */  addu      $v1, $v1, $v0
/* 3C156C E00C239C 24C20008 */  addiu     $v0, $a2, 8
/* 3C1570 E00C23A0 AC830004 */  sw        $v1, 4($a0)
/* 3C1574 E00C23A4 AE820000 */  sw        $v0, ($s4)
/* 3C1578 E00C23A8 24C20010 */  addiu     $v0, $a2, 0x10
/* 3C157C E00C23AC ACC50000 */  sw        $a1, ($a2)
/* 3C1580 E00C23B0 AE820000 */  sw        $v0, ($s4)
/* 3C1584 E00C23B4 8E030204 */  lw        $v1, 0x204($s0)
/* 3C1588 E00C23B8 3C02DE00 */  lui       $v0, 0xde00
/* 3C158C E00C23BC ACC20008 */  sw        $v0, 8($a2)
/* 3C1590 E00C23C0 3C020901 */  lui       $v0, 0x901
/* 3C1594 E00C23C4 24428BE0 */  addiu     $v0, $v0, -0x7420
/* 3C1598 E00C23C8 ACC2000C */  sw        $v0, 0xc($a2)
/* 3C159C E00C23CC 04E10002 */  bgez      $a3, .LE00C23D8
/* 3C15A0 E00C23D0 ACC30004 */   sw       $v1, 4($a2)
/* 3C15A4 E00C23D4 0000382D */  daddu     $a3, $zero, $zero
.LE00C23D8:
/* 3C15A8 E00C23D8 3C030101 */  lui       $v1, 0x101
/* 3C15AC E00C23DC 3463602C */  ori       $v1, $v1, 0x602c
/* 3C15B0 E00C23E0 02A0202D */  daddu     $a0, $s5, $zero
/* 3C15B4 E00C23E4 24C20018 */  addiu     $v0, $a2, 0x18
/* 3C15B8 E00C23E8 AE820000 */  sw        $v0, ($s4)
/* 3C15BC E00C23EC ACC30010 */  sw        $v1, 0x10($a2)
/* 3C15C0 E00C23F0 3C030900 */  lui       $v1, 0x900
/* 3C15C4 E00C23F4 24634040 */  addiu     $v1, $v1, 0x4040
/* 3C15C8 E00C23F8 00071040 */  sll       $v0, $a3, 1
/* 3C15CC E00C23FC 00471021 */  addu      $v0, $v0, $a3
/* 3C15D0 E00C2400 00021080 */  sll       $v0, $v0, 2
/* 3C15D4 E00C2404 00471023 */  subu      $v0, $v0, $a3
/* 3C15D8 E00C2408 00021140 */  sll       $v0, $v0, 5
/* 3C15DC E00C240C 00431021 */  addu      $v0, $v0, $v1
/* 3C15E0 E00C2410 06A10002 */  bgez      $s5, .LE00C241C
/* 3C15E4 E00C2414 ACC20014 */   sw       $v0, 0x14($a2)
/* 3C15E8 E00C2418 26A4000F */  addiu     $a0, $s5, 0xf
.LE00C241C:
/* 3C15EC E00C241C 0000602D */  daddu     $t4, $zero, $zero
/* 3C15F0 E00C2420 0280482D */  daddu     $t1, $s4, $zero
/* 3C15F4 E00C2424 3C148000 */  lui       $s4, 0x8000
/* 3C15F8 E00C2428 3C12FD48 */  lui       $s2, 0xfd48
/* 3C15FC E00C242C 3652003F */  ori       $s2, $s2, 0x3f
/* 3C1600 E00C2430 3C110709 */  lui       $s1, 0x709
/* 3C1604 E00C2434 3631FA7E */  ori       $s1, $s1, 0xfa7e
/* 3C1608 E00C2438 3C19E600 */  lui       $t9, 0xe600
/* 3C160C E00C243C 3C18F400 */  lui       $t8, 0xf400
/* 3C1610 E00C2440 3C10070F */  lui       $s0, 0x70f
/* 3C1614 E00C2444 3610E000 */  ori       $s0, $s0, 0xe000
/* 3C1618 E00C2448 3C13E700 */  lui       $s3, 0xe700
/* 3C161C E00C244C 3C0FF200 */  lui       $t7, 0xf200
/* 3C1620 E00C2450 0180702D */  daddu     $t6, $t4, $zero
/* 3C1624 E00C2454 0180682D */  daddu     $t5, $t4, $zero
/* 3C1628 E00C2458 00041103 */  sra       $v0, $a0, 4
/* 3C162C E00C245C 00021100 */  sll       $v0, $v0, 4
/* 3C1630 E00C2460 02A21023 */  subu      $v0, $s5, $v0
/* 3C1634 E00C2464 3C03E00C */  lui       $v1, %hi(D_E00C2990)
/* 3C1638 E00C2468 24632990 */  addiu     $v1, $v1, %lo(D_E00C2990)
/* 3C163C E00C246C 00431021 */  addu      $v0, $v0, $v1
/* 3C1640 E00C2470 3C01437F */  lui       $at, 0x437f
/* 3C1644 E00C2474 44816000 */  mtc1      $at, $f12
/* 3C1648 E00C2478 3C014F00 */  lui       $at, 0x4f00
/* 3C164C E00C247C 44813000 */  mtc1      $at, $f6
/* 3C1650 E00C2480 3C014300 */  lui       $at, 0x4300
/* 3C1654 E00C2484 44815000 */  mtc1      $at, $f10
/* 3C1658 E00C2488 3C014080 */  lui       $at, 0x4080
/* 3C165C E00C248C 44814000 */  mtc1      $at, $f8
/* 3C1660 E00C2490 90430000 */  lbu       $v1, ($v0)
/* 3C1664 E00C2494 24C20020 */  addiu     $v0, $a2, 0x20
/* 3C1668 E00C2498 AD220000 */  sw        $v0, ($t1)
/* 3C166C E00C249C 3C02FB00 */  lui       $v0, 0xfb00
/* 3C1670 E00C24A0 ACC20018 */  sw        $v0, 0x18($a2)
/* 3C1674 E00C24A4 ACC3001C */  sw        $v1, 0x1c($a2)
.LE00C24A8:
/* 3C1678 E00C24A8 29820005 */  slti      $v0, $t4, 5
/* 3C167C E00C24AC 14400002 */  bnez      $v0, .LE00C24B8
/* 3C1680 E00C24B0 000D5880 */   sll      $t3, $t5, 2
/* 3C1684 E00C24B4 25CB0004 */  addiu     $t3, $t6, 4
.LE00C24B8:
/* 3C1688 E00C24B8 3C013DCC */  lui       $at, 0x3dcc
/* 3C168C E00C24BC 3421CCCD */  ori       $at, $at, 0xcccd
/* 3C1690 E00C24C0 44811000 */  mtc1      $at, $f2
/* 3C1694 E00C24C4 448C0000 */  mtc1      $t4, $f0
/* 3C1698 E00C24C8 00000000 */  nop
/* 3C169C E00C24CC 46800020 */  cvt.s.w   $f0, $f0
/* 3C16A0 E00C24D0 46020102 */  mul.s     $f4, $f0, $f2
/* 3C16A4 E00C24D4 00000000 */  nop
/* 3C16A8 E00C24D8 3C013F80 */  lui       $at, 0x3f80
/* 3C16AC E00C24DC 44811000 */  mtc1      $at, $f2
/* 3C16B0 E00C24E0 00000000 */  nop
/* 3C16B4 E00C24E4 46041081 */  sub.s     $f2, $f2, $f4
/* 3C16B8 E00C24E8 C7A00090 */  lwc1      $f0, 0x90($sp)
/* 3C16BC E00C24EC 46800020 */  cvt.s.w   $f0, $f0
/* 3C16C0 E00C24F0 46020002 */  mul.s     $f0, $f0, $f2
/* 3C16C4 E00C24F4 00000000 */  nop
/* 3C16C8 E00C24F8 46000000 */  add.s     $f0, $f0, $f0
/* 3C16CC E00C24FC 4600603C */  c.lt.s    $f12, $f0
/* 3C16D0 E00C2500 00000000 */  nop
/* 3C16D4 E00C2504 45030001 */  bc1tl     .LE00C250C
/* 3C16D8 E00C2508 46006006 */   mov.s    $f0, $f12
.LE00C250C:
/* 3C16DC E00C250C 8D220000 */  lw        $v0, ($t1)
/* 3C16E0 E00C2510 4600303E */  c.le.s    $f6, $f0
/* 3C16E4 E00C2514 0040182D */  daddu     $v1, $v0, $zero
/* 3C16E8 E00C2518 24420008 */  addiu     $v0, $v0, 8
/* 3C16EC E00C251C AD220000 */  sw        $v0, ($t1)
/* 3C16F0 E00C2520 3C02FA00 */  lui       $v0, 0xfa00
/* 3C16F4 E00C2524 246A0004 */  addiu     $t2, $v1, 4
/* 3C16F8 E00C2528 AC620000 */  sw        $v0, ($v1)
/* 3C16FC E00C252C 92C4001B */  lbu       $a0, 0x1b($s6)
/* 3C1700 E00C2530 92C3001F */  lbu       $v1, 0x1f($s6)
/* 3C1704 E00C2534 92C20023 */  lbu       $v0, 0x23($s6)
/* 3C1708 E00C2538 00042600 */  sll       $a0, $a0, 0x18
/* 3C170C E00C253C 00031C00 */  sll       $v1, $v1, 0x10
/* 3C1710 E00C2540 00832025 */  or        $a0, $a0, $v1
/* 3C1714 E00C2544 00021200 */  sll       $v0, $v0, 8
/* 3C1718 E00C2548 45010005 */  bc1t      .LE00C2560
/* 3C171C E00C254C 00822025 */   or       $a0, $a0, $v0
/* 3C1720 E00C2550 4600038D */  trunc.w.s $f14, $f0
/* 3C1724 E00C2554 44027000 */  mfc1      $v0, $f14
/* 3C1728 E00C2558 0803095E */  j         .LE00C2578
/* 3C172C E00C255C 3C05F548 */   lui      $a1, 0xf548
.LE00C2560:
/* 3C1730 E00C2560 46060001 */  sub.s     $f0, $f0, $f6
/* 3C1734 E00C2564 4600038D */  trunc.w.s $f14, $f0
/* 3C1738 E00C2568 44027000 */  mfc1      $v0, $f14
/* 3C173C E00C256C 00000000 */  nop
/* 3C1740 E00C2570 00541025 */  or        $v0, $v0, $s4
/* 3C1744 E00C2574 3C05F548 */  lui       $a1, 0xf548
.LE00C2578:
/* 3C1748 E00C2578 34A51000 */  ori       $a1, $a1, 0x1000
/* 3C174C E00C257C 3C07F540 */  lui       $a3, 0xf540
/* 3C1750 E00C2580 34E71000 */  ori       $a3, $a3, 0x1000
/* 3C1754 E00C2584 3C060009 */  lui       $a2, 9
/* 3C1758 E00C2588 34C6FA7E */  ori       $a2, $a2, 0xfa7e
/* 3C175C E00C258C 3C08001F */  lui       $t0, 0x1f
/* 3C1760 E00C2590 3508C000 */  ori       $t0, $t0, 0xc000
/* 3C1764 E00C2594 304200FF */  andi      $v0, $v0, 0xff
/* 3C1768 E00C2598 8D230000 */  lw        $v1, ($t1)
/* 3C176C E00C259C 00821025 */  or        $v0, $a0, $v0
/* 3C1770 E00C25A0 AD420000 */  sw        $v0, ($t2)
/* 3C1774 E00C25A4 3C020900 */  lui       $v0, 0x900
/* 3C1778 E00C25A8 24422020 */  addiu     $v0, $v0, 0x2020
/* 3C177C E00C25AC 460A2002 */  mul.s     $f0, $f4, $f10
/* 3C1780 E00C25B0 00000000 */  nop
/* 3C1784 E00C25B4 0060202D */  daddu     $a0, $v1, $zero
/* 3C1788 E00C25B8 24630008 */  addiu     $v1, $v1, 8
/* 3C178C E00C25BC AD230000 */  sw        $v1, ($t1)
/* 3C1790 E00C25C0 AC820004 */  sw        $v0, 4($a0)
/* 3C1794 E00C25C4 24620008 */  addiu     $v0, $v1, 8
/* 3C1798 E00C25C8 AC920000 */  sw        $s2, ($a0)
/* 3C179C E00C25CC AD220000 */  sw        $v0, ($t1)
/* 3C17A0 E00C25D0 24620010 */  addiu     $v0, $v1, 0x10
/* 3C17A4 E00C25D4 AC650000 */  sw        $a1, ($v1)
/* 3C17A8 E00C25D8 AC710004 */  sw        $s1, 4($v1)
/* 3C17AC E00C25DC AD220000 */  sw        $v0, ($t1)
/* 3C17B0 E00C25E0 24620018 */  addiu     $v0, $v1, 0x18
/* 3C17B4 E00C25E4 000B2880 */  sll       $a1, $t3, 2
/* 3C17B8 E00C25E8 30A50FFF */  andi      $a1, $a1, 0xfff
/* 3C17BC E00C25EC AC790008 */  sw        $t9, 8($v1)
/* 3C17C0 E00C25F0 AC60000C */  sw        $zero, 0xc($v1)
/* 3C17C4 E00C25F4 AD220000 */  sw        $v0, ($t1)
/* 3C17C8 E00C25F8 00B81025 */  or        $v0, $a1, $t8
/* 3C17CC E00C25FC 2564000F */  addiu     $a0, $t3, 0xf
/* 3C17D0 E00C2600 00042080 */  sll       $a0, $a0, 2
/* 3C17D4 E00C2604 30840FFF */  andi      $a0, $a0, 0xfff
/* 3C17D8 E00C2608 AC620010 */  sw        $v0, 0x10($v1)
/* 3C17DC E00C260C 00901025 */  or        $v0, $a0, $s0
/* 3C17E0 E00C2610 AC620014 */  sw        $v0, 0x14($v1)
/* 3C17E4 E00C2614 24620020 */  addiu     $v0, $v1, 0x20
/* 3C17E8 E00C2618 AD220000 */  sw        $v0, ($t1)
/* 3C17EC E00C261C 24620028 */  addiu     $v0, $v1, 0x28
/* 3C17F0 E00C2620 AC730018 */  sw        $s3, 0x18($v1)
/* 3C17F4 E00C2624 AC60001C */  sw        $zero, 0x1c($v1)
/* 3C17F8 E00C2628 AD220000 */  sw        $v0, ($t1)
/* 3C17FC E00C262C 24620030 */  addiu     $v0, $v1, 0x30
/* 3C1800 E00C2630 00AF2825 */  or        $a1, $a1, $t7
/* 3C1804 E00C2634 00882025 */  or        $a0, $a0, $t0
/* 3C1808 E00C2638 AC670020 */  sw        $a3, 0x20($v1)
/* 3C180C E00C263C AC660024 */  sw        $a2, 0x24($v1)
/* 3C1810 E00C2640 AD220000 */  sw        $v0, ($t1)
/* 3C1814 E00C2644 AC650028 */  sw        $a1, 0x28($v1)
/* 3C1818 E00C2648 46080002 */  mul.s     $f0, $f0, $f8
/* 3C181C E00C264C 00000000 */  nop
/* 3C1820 E00C2650 AC64002C */  sw        $a0, 0x2c($v1)
/* 3C1824 E00C2654 24630038 */  addiu     $v1, $v1, 0x38
/* 3C1828 E00C2658 0040502D */  daddu     $t2, $v0, $zero
/* 3C182C E00C265C 4600303E */  c.le.s    $f6, $f0
/* 3C1830 E00C2660 00000000 */  nop
/* 3C1834 E00C2664 45010005 */  bc1t      .LE00C267C
/* 3C1838 E00C2668 AD230000 */   sw       $v1, ($t1)
/* 3C183C E00C266C 4600038D */  trunc.w.s $f14, $f0
/* 3C1840 E00C2670 44027000 */  mfc1      $v0, $f14
/* 3C1844 E00C2674 080309A5 */  j         .LE00C2694
/* 3C1848 E00C2678 3C04007D */   lui      $a0, 0x7d
.LE00C267C:
/* 3C184C E00C267C 46060001 */  sub.s     $f0, $f0, $f6
/* 3C1850 E00C2680 4600038D */  trunc.w.s $f14, $f0
/* 3C1854 E00C2684 44027000 */  mfc1      $v0, $f14
/* 3C1858 E00C2688 00000000 */  nop
/* 3C185C E00C268C 00541025 */  or        $v0, $v0, $s4
/* 3C1860 E00C2690 3C04007D */  lui       $a0, 0x7d
.LE00C2694:
/* 3C1864 E00C2694 348407D0 */  ori       $a0, $a0, 0x7d0
/* 3C1868 E00C2698 3C05F548 */  lui       $a1, 0xf548
/* 3C186C E00C269C 34A51080 */  ori       $a1, $a1, 0x1080
/* 3C1870 E00C26A0 3C07F540 */  lui       $a3, 0xf540
/* 3C1874 E00C26A4 34E71080 */  ori       $a3, $a3, 0x1080
/* 3C1878 E00C26A8 3C060119 */  lui       $a2, 0x119
/* 3C187C E00C26AC 34C6FA7E */  ori       $a2, $a2, 0xfa7e
/* 3C1880 E00C26B0 3C08011F */  lui       $t0, 0x11f
/* 3C1884 E00C26B4 3508C000 */  ori       $t0, $t0, 0xc000
/* 3C1888 E00C26B8 30420FFF */  andi      $v0, $v0, 0xfff
/* 3C188C E00C26BC 8D230000 */  lw        $v1, ($t1)
/* 3C1890 E00C26C0 004F1025 */  or        $v0, $v0, $t7
/* 3C1894 E00C26C4 AD420000 */  sw        $v0, ($t2)
/* 3C1898 E00C26C8 3C020900 */  lui       $v0, 0x900
/* 3C189C E00C26CC 24420000 */  addiu     $v0, $v0, 0
/* 3C18A0 E00C26D0 460A2002 */  mul.s     $f0, $f4, $f10
/* 3C18A4 E00C26D4 00000000 */  nop
/* 3C18A8 E00C26D8 AD440004 */  sw        $a0, 4($t2)
/* 3C18AC E00C26DC 0060202D */  daddu     $a0, $v1, $zero
/* 3C18B0 E00C26E0 24630008 */  addiu     $v1, $v1, 8
/* 3C18B4 E00C26E4 AD230000 */  sw        $v1, ($t1)
/* 3C18B8 E00C26E8 AC820004 */  sw        $v0, 4($a0)
/* 3C18BC E00C26EC 24620008 */  addiu     $v0, $v1, 8
/* 3C18C0 E00C26F0 AC920000 */  sw        $s2, ($a0)
/* 3C18C4 E00C26F4 AD220000 */  sw        $v0, ($t1)
/* 3C18C8 E00C26F8 24620010 */  addiu     $v0, $v1, 0x10
/* 3C18CC E00C26FC AC650000 */  sw        $a1, ($v1)
/* 3C18D0 E00C2700 AC710004 */  sw        $s1, 4($v1)
/* 3C18D4 E00C2704 AD220000 */  sw        $v0, ($t1)
/* 3C18D8 E00C2708 24620018 */  addiu     $v0, $v1, 0x18
/* 3C18DC E00C270C 000B2880 */  sll       $a1, $t3, 2
/* 3C18E0 E00C2710 30A50FFF */  andi      $a1, $a1, 0xfff
/* 3C18E4 E00C2714 AC790008 */  sw        $t9, 8($v1)
/* 3C18E8 E00C2718 AC60000C */  sw        $zero, 0xc($v1)
/* 3C18EC E00C271C AD220000 */  sw        $v0, ($t1)
/* 3C18F0 E00C2720 00B81025 */  or        $v0, $a1, $t8
/* 3C18F4 E00C2724 2564000F */  addiu     $a0, $t3, 0xf
/* 3C18F8 E00C2728 00042080 */  sll       $a0, $a0, 2
/* 3C18FC E00C272C 30840FFF */  andi      $a0, $a0, 0xfff
/* 3C1900 E00C2730 AC620010 */  sw        $v0, 0x10($v1)
/* 3C1904 E00C2734 00901025 */  or        $v0, $a0, $s0
/* 3C1908 E00C2738 AC620014 */  sw        $v0, 0x14($v1)
/* 3C190C E00C273C 24620020 */  addiu     $v0, $v1, 0x20
/* 3C1910 E00C2740 AD220000 */  sw        $v0, ($t1)
/* 3C1914 E00C2744 24620028 */  addiu     $v0, $v1, 0x28
/* 3C1918 E00C2748 AC730018 */  sw        $s3, 0x18($v1)
/* 3C191C E00C274C AC60001C */  sw        $zero, 0x1c($v1)
/* 3C1920 E00C2750 AD220000 */  sw        $v0, ($t1)
/* 3C1924 E00C2754 24620030 */  addiu     $v0, $v1, 0x30
/* 3C1928 E00C2758 00AF2825 */  or        $a1, $a1, $t7
/* 3C192C E00C275C 00882025 */  or        $a0, $a0, $t0
/* 3C1930 E00C2760 AC670020 */  sw        $a3, 0x20($v1)
/* 3C1934 E00C2764 AC660024 */  sw        $a2, 0x24($v1)
/* 3C1938 E00C2768 AD220000 */  sw        $v0, ($t1)
/* 3C193C E00C276C AC650028 */  sw        $a1, 0x28($v1)
/* 3C1940 E00C2770 46080002 */  mul.s     $f0, $f0, $f8
/* 3C1944 E00C2774 00000000 */  nop
/* 3C1948 E00C2778 AC64002C */  sw        $a0, 0x2c($v1)
/* 3C194C E00C277C 24630038 */  addiu     $v1, $v1, 0x38
/* 3C1950 E00C2780 0040202D */  daddu     $a0, $v0, $zero
/* 3C1954 E00C2784 4600303E */  c.le.s    $f6, $f0
/* 3C1958 E00C2788 00000000 */  nop
/* 3C195C E00C278C 45010005 */  bc1t      .LE00C27A4
/* 3C1960 E00C2790 AD230000 */   sw       $v1, ($t1)
/* 3C1964 E00C2794 4600038D */  trunc.w.s $f14, $f0
/* 3C1968 E00C2798 44037000 */  mfc1      $v1, $f14
/* 3C196C E00C279C 080309EF */  j         .LE00C27BC
/* 3C1970 E00C27A0 3C02017D */   lui      $v0, 0x17d
.LE00C27A4:
/* 3C1974 E00C27A4 46060001 */  sub.s     $f0, $f0, $f6
/* 3C1978 E00C27A8 4600038D */  trunc.w.s $f14, $f0
/* 3C197C E00C27AC 44037000 */  mfc1      $v1, $f14
/* 3C1980 E00C27B0 00000000 */  nop
/* 3C1984 E00C27B4 00741825 */  or        $v1, $v1, $s4
/* 3C1988 E00C27B8 3C02017D */  lui       $v0, 0x17d
.LE00C27BC:
/* 3C198C E00C27BC 344207D0 */  ori       $v0, $v0, 0x7d0
/* 3C1990 E00C27C0 30630FFF */  andi      $v1, $v1, 0xfff
/* 3C1994 E00C27C4 006F1825 */  or        $v1, $v1, $t7
/* 3C1998 E00C27C8 AC820004 */  sw        $v0, 4($a0)
/* 3C199C E00C27CC 2D82000A */  sltiu     $v0, $t4, 0xa
/* 3C19A0 E00C27D0 1040004B */  beqz      $v0, .LE00C2900
/* 3C19A4 E00C27D4 AC830000 */   sw       $v1, ($a0)
/* 3C19A8 E00C27D8 000C1080 */  sll       $v0, $t4, 2
/* 3C19AC E00C27DC 3C01E00C */  lui       $at, %hi(jtbl_E00C29A8)
/* 3C19B0 E00C27E0 00220821 */  addu      $at, $at, $v0
/* 3C19B4 E00C27E4 8C2229A8 */  lw        $v0, %lo(jtbl_E00C29A8)($at)
/* 3C19B8 E00C27E8 00400008 */  jr        $v0
/* 3C19BC E00C27EC 00000000 */   nop
dlabel LE00C27F0_3C19C0
/* 3C19C0 E00C27F0 3C040600 */  lui       $a0, 0x600
/* 3C19C4 E00C27F4 8D220000 */  lw        $v0, ($t1)
/* 3C19C8 E00C27F8 34840204 */  ori       $a0, $a0, 0x204
/* 3C19CC E00C27FC 0040182D */  daddu     $v1, $v0, $zero
/* 3C19D0 E00C2800 24420008 */  addiu     $v0, $v0, 8
/* 3C19D4 E00C2804 AD220000 */  sw        $v0, ($t1)
/* 3C19D8 E00C2808 24020406 */  addiu     $v0, $zero, 0x406
/* 3C19DC E00C280C AC640000 */  sw        $a0, ($v1)
/* 3C19E0 E00C2810 08030A40 */  j         .LE00C2900
/* 3C19E4 E00C2814 AC620004 */   sw       $v0, 4($v1)
dlabel LE00C2818_3C19E8
/* 3C19E8 E00C2818 3C050602 */  lui       $a1, 0x602
/* 3C19EC E00C281C 34A5080A */  ori       $a1, $a1, 0x80a
/* 3C19F0 E00C2820 3C040002 */  lui       $a0, 2
/* 3C19F4 E00C2824 8D220000 */  lw        $v0, ($t1)
/* 3C19F8 E00C2828 08030A3B */  j         .LE00C28EC
/* 3C19FC E00C282C 34840A04 */   ori      $a0, $a0, 0xa04
dlabel LE00C2830_3C1A00
/* 3C1A00 E00C2830 3C050608 */  lui       $a1, 0x608
/* 3C1A04 E00C2834 34A50C0E */  ori       $a1, $a1, 0xc0e
/* 3C1A08 E00C2838 3C040008 */  lui       $a0, 8
/* 3C1A0C E00C283C 8D220000 */  lw        $v0, ($t1)
/* 3C1A10 E00C2840 08030A3B */  j         .LE00C28EC
/* 3C1A14 E00C2844 34840E0A */   ori      $a0, $a0, 0xe0a
dlabel LE00C2848_3C1A18
/* 3C1A18 E00C2848 3C05060C */  lui       $a1, 0x60c
/* 3C1A1C E00C284C 34A51012 */  ori       $a1, $a1, 0x1012
/* 3C1A20 E00C2850 3C04000C */  lui       $a0, 0xc
/* 3C1A24 E00C2854 8D220000 */  lw        $v0, ($t1)
/* 3C1A28 E00C2858 08030A3B */  j         .LE00C28EC
/* 3C1A2C E00C285C 3484120E */   ori      $a0, $a0, 0x120e
dlabel LE00C2860_3C1A30
/* 3C1A30 E00C2860 3C050610 */  lui       $a1, 0x610
/* 3C1A34 E00C2864 34A51416 */  ori       $a1, $a1, 0x1416
/* 3C1A38 E00C2868 3C040010 */  lui       $a0, 0x10
/* 3C1A3C E00C286C 8D220000 */  lw        $v0, ($t1)
/* 3C1A40 E00C2870 08030A3B */  j         .LE00C28EC
/* 3C1A44 E00C2874 34841612 */   ori      $a0, $a0, 0x1612
dlabel LE00C2878_3C1A48
/* 3C1A48 E00C2878 3C050614 */  lui       $a1, 0x614
/* 3C1A4C E00C287C 34A5181A */  ori       $a1, $a1, 0x181a
/* 3C1A50 E00C2880 3C040014 */  lui       $a0, 0x14
/* 3C1A54 E00C2884 8D220000 */  lw        $v0, ($t1)
/* 3C1A58 E00C2888 08030A3B */  j         .LE00C28EC
/* 3C1A5C E00C288C 34841A16 */   ori      $a0, $a0, 0x1a16
dlabel LE00C2890_3C1A60
/* 3C1A60 E00C2890 3C050618 */  lui       $a1, 0x618
/* 3C1A64 E00C2894 34A51C1E */  ori       $a1, $a1, 0x1c1e
/* 3C1A68 E00C2898 3C040018 */  lui       $a0, 0x18
/* 3C1A6C E00C289C 8D220000 */  lw        $v0, ($t1)
/* 3C1A70 E00C28A0 08030A3B */  j         .LE00C28EC
/* 3C1A74 E00C28A4 34841E1A */   ori      $a0, $a0, 0x1e1a
dlabel LE00C28A8_3C1A78
/* 3C1A78 E00C28A8 3C05061C */  lui       $a1, 0x61c
/* 3C1A7C E00C28AC 34A52022 */  ori       $a1, $a1, 0x2022
/* 3C1A80 E00C28B0 3C04001C */  lui       $a0, 0x1c
/* 3C1A84 E00C28B4 8D220000 */  lw        $v0, ($t1)
/* 3C1A88 E00C28B8 08030A3B */  j         .LE00C28EC
/* 3C1A8C E00C28BC 3484221E */   ori      $a0, $a0, 0x221e
dlabel LE00C28C0_3C1A90
/* 3C1A90 E00C28C0 3C050620 */  lui       $a1, 0x620
/* 3C1A94 E00C28C4 34A52426 */  ori       $a1, $a1, 0x2426
/* 3C1A98 E00C28C8 3C040020 */  lui       $a0, 0x20
/* 3C1A9C E00C28CC 8D220000 */  lw        $v0, ($t1)
/* 3C1AA0 E00C28D0 08030A3B */  j         .LE00C28EC
/* 3C1AA4 E00C28D4 34842622 */   ori      $a0, $a0, 0x2622
dlabel LE00C28D8_3C1AA8
/* 3C1AA8 E00C28D8 3C050624 */  lui       $a1, 0x624
/* 3C1AAC E00C28DC 34A5282A */  ori       $a1, $a1, 0x282a
/* 3C1AB0 E00C28E0 3C040024 */  lui       $a0, 0x24
/* 3C1AB4 E00C28E4 8D220000 */  lw        $v0, ($t1)
/* 3C1AB8 E00C28E8 34842A26 */  ori       $a0, $a0, 0x2a26
.LE00C28EC:
/* 3C1ABC E00C28EC 0040182D */  daddu     $v1, $v0, $zero
/* 3C1AC0 E00C28F0 24420008 */  addiu     $v0, $v0, 8
/* 3C1AC4 E00C28F4 AD220000 */  sw        $v0, ($t1)
/* 3C1AC8 E00C28F8 AC650000 */  sw        $a1, ($v1)
/* 3C1ACC E00C28FC AC640004 */  sw        $a0, 4($v1)
.LE00C2900:
/* 3C1AD0 E00C2900 25CE000C */  addiu     $t6, $t6, 0xc
/* 3C1AD4 E00C2904 25AD0003 */  addiu     $t5, $t5, 3
/* 3C1AD8 E00C2908 8D220000 */  lw        $v0, ($t1)
/* 3C1ADC E00C290C 258C0001 */  addiu     $t4, $t4, 1
/* 3C1AE0 E00C2910 0040182D */  daddu     $v1, $v0, $zero
/* 3C1AE4 E00C2914 24420008 */  addiu     $v0, $v0, 8
/* 3C1AE8 E00C2918 AD220000 */  sw        $v0, ($t1)
/* 3C1AEC E00C291C 2982000A */  slti      $v0, $t4, 0xa
/* 3C1AF0 E00C2920 AC730000 */  sw        $s3, ($v1)
/* 3C1AF4 E00C2924 1440FEE0 */  bnez      $v0, .LE00C24A8
/* 3C1AF8 E00C2928 AC600004 */   sw       $zero, 4($v1)
/* 3C1AFC E00C292C 3C05D838 */  lui       $a1, 0xd838
/* 3C1B00 E00C2930 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 3C1B04 E00C2934 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 3C1B08 E00C2938 8C620000 */  lw        $v0, ($v1)
/* 3C1B0C E00C293C 34A50002 */  ori       $a1, $a1, 2
/* 3C1B10 E00C2940 0040202D */  daddu     $a0, $v0, $zero
/* 3C1B14 E00C2944 24420008 */  addiu     $v0, $v0, 8
/* 3C1B18 E00C2948 AC620000 */  sw        $v0, ($v1)
/* 3C1B1C E00C294C 24020040 */  addiu     $v0, $zero, 0x40
/* 3C1B20 E00C2950 AC850000 */  sw        $a1, ($a0)
/* 3C1B24 E00C2954 AC820004 */  sw        $v0, 4($a0)
/* 3C1B28 E00C2958 8FBF00B8 */  lw        $ra, 0xb8($sp)
/* 3C1B2C E00C295C 8FB700B4 */  lw        $s7, 0xb4($sp)
/* 3C1B30 E00C2960 8FB600B0 */  lw        $s6, 0xb0($sp)
/* 3C1B34 E00C2964 8FB500AC */  lw        $s5, 0xac($sp)
/* 3C1B38 E00C2968 8FB400A8 */  lw        $s4, 0xa8($sp)
/* 3C1B3C E00C296C 8FB300A4 */  lw        $s3, 0xa4($sp)
/* 3C1B40 E00C2970 8FB200A0 */  lw        $s2, 0xa0($sp)
/* 3C1B44 E00C2974 8FB1009C */  lw        $s1, 0x9c($sp)
/* 3C1B48 E00C2978 8FB00098 */  lw        $s0, 0x98($sp)
/* 3C1B4C E00C297C 03E00008 */  jr        $ra
/* 3C1B50 E00C2980 27BD00C0 */   addiu    $sp, $sp, 0xc0
/* 3C1B54 E00C2984 00000000 */  nop
/* 3C1B58 E00C2988 00000000 */  nop
/* 3C1B5C E00C298C 00000000 */  nop
