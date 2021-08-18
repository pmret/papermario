.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802A2DB0_7330B0
.word L802A1434_731734, L802A14D0_7317D0, L802A1614_731914, L802A1698_731998, L802A1734_731A34, L802A1754_731A54, 0, 0

.section .text

glabel battle_item_strange_cake_func_802A13E4_7316E4
/* 7316E4 802A13E4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 7316E8 802A13E8 0080302D */  daddu     $a2, $a0, $zero
/* 7316EC 802A13EC AFBF0020 */  sw        $ra, 0x20($sp)
/* 7316F0 802A13F0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 7316F4 802A13F4 AFB20018 */  sw        $s2, 0x18($sp)
/* 7316F8 802A13F8 AFB10014 */  sw        $s1, 0x14($sp)
/* 7316FC 802A13FC 10A00003 */  beqz      $a1, .L802A140C
/* 731700 802A1400 AFB00010 */   sw       $s0, 0x10($sp)
/* 731704 802A1404 3C01802A */  lui       $at, %hi(D_802A2DEC)
/* 731708 802A1408 AC202DEC */  sw        $zero, %lo(D_802A2DEC)($at)
.L802A140C:
/* 73170C 802A140C 3C03802A */  lui       $v1, %hi(D_802A2DEC)
/* 731710 802A1410 8C632DEC */  lw        $v1, %lo(D_802A2DEC)($v1)
/* 731714 802A1414 2C620006 */  sltiu     $v0, $v1, 6
/* 731718 802A1418 104000F7 */  beqz      $v0, .L802A17F8
/* 73171C 802A141C 00031080 */   sll      $v0, $v1, 2
/* 731720 802A1420 3C01802A */  lui       $at, %hi(jtbl_802A2DB0_7330B0)
/* 731724 802A1424 00220821 */  addu      $at, $at, $v0
/* 731728 802A1428 8C222DB0 */  lw        $v0, %lo(jtbl_802A2DB0_7330B0)($at)
/* 73172C 802A142C 00400008 */  jr        $v0
/* 731730 802A1430 00000000 */   nop
glabel L802A1434_731734
/* 731734 802A1434 3C05802A */  lui       $a1, %hi(battle_item_strange_cake_func_802A123C_73153C)
/* 731738 802A1438 24A5123C */  addiu     $a1, $a1, %lo(battle_item_strange_cake_func_802A123C_73153C)
/* 73173C 802A143C 0C048C8F */  jal       create_generic_entity_frontUI
/* 731740 802A1440 0000202D */   daddu    $a0, $zero, $zero
/* 731744 802A1444 3C01802A */  lui       $at, %hi(D_802A2E00)
/* 731748 802A1448 AC222E00 */  sw        $v0, %lo(D_802A2E00)($at)
/* 73174C 802A144C 0C00A67F */  jal       rand_int
/* 731750 802A1450 240432C8 */   addiu    $a0, $zero, 0x32c8
/* 731754 802A1454 0000802D */  daddu     $s0, $zero, $zero
/* 731758 802A1458 3C13802A */  lui       $s3, %hi(battle_item_strange_cake_D_802A2848_732B48)
/* 73175C 802A145C 26732848 */  addiu     $s3, $s3, %lo(battle_item_strange_cake_D_802A2848_732B48)
/* 731760 802A1460 3C12802A */  lui       $s2, %hi(D_802A2DD8)
/* 731764 802A1464 26522DD8 */  addiu     $s2, $s2, %lo(D_802A2DD8)
/* 731768 802A1468 3C11802A */  lui       $s1, %hi(battle_item_strange_cake_D_802A2858_732B58)
/* 73176C 802A146C 26312858 */  addiu     $s1, $s1, %lo(battle_item_strange_cake_D_802A2858_732B58)
/* 731770 802A1470 3C01802A */  lui       $at, %hi(D_802A2DF4)
/* 731774 802A1474 AC222DF4 */  sw        $v0, %lo(D_802A2DF4)($at)
/* 731778 802A1478 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 73177C 802A147C 3C01802A */  lui       $at, %hi(D_802A2DF8)
/* 731780 802A1480 AC222DF8 */  sw        $v0, %lo(D_802A2DF8)($at)
.L802A1484:
/* 731784 802A1484 8E220000 */  lw        $v0, ($s1)
/* 731788 802A1488 26310004 */  addiu     $s1, $s1, 4
/* 73178C 802A148C 00021080 */  sll       $v0, $v0, 2
/* 731790 802A1490 00531021 */  addu      $v0, $v0, $s3
/* 731794 802A1494 8C440000 */  lw        $a0, ($v0)
/* 731798 802A1498 0C050529 */  jal       create_hud_element
/* 73179C 802A149C 26100001 */   addiu    $s0, $s0, 1
/* 7317A0 802A14A0 0040202D */  daddu     $a0, $v0, $zero
/* 7317A4 802A14A4 24050080 */  addiu     $a1, $zero, 0x80
/* 7317A8 802A14A8 0C051280 */  jal       set_hud_element_flags
/* 7317AC 802A14AC AE440000 */   sw       $a0, ($s2)
/* 7317B0 802A14B0 2A020005 */  slti      $v0, $s0, 5
/* 7317B4 802A14B4 1440FFF3 */  bnez      $v0, .L802A1484
/* 7317B8 802A14B8 26520004 */   addiu    $s2, $s2, 4
/* 7317BC 802A14BC 24020001 */  addiu     $v0, $zero, 1
/* 7317C0 802A14C0 3C01802A */  lui       $at, %hi(D_802A2DEC)
/* 7317C4 802A14C4 AC222DEC */  sw        $v0, %lo(D_802A2DEC)($at)
/* 7317C8 802A14C8 080A85FF */  j         .L802A17FC
/* 7317CC 802A14CC 0000102D */   daddu    $v0, $zero, $zero
glabel L802A14D0_7317D0
/* 7317D0 802A14D0 3C0351EB */  lui       $v1, 0x51eb
/* 7317D4 802A14D4 3C06802A */  lui       $a2, %hi(D_802A2DF4)
/* 7317D8 802A14D8 24C62DF4 */  addiu     $a2, $a2, %lo(D_802A2DF4)
/* 7317DC 802A14DC 3C07802A */  lui       $a3, %hi(D_802A2DF8)
/* 7317E0 802A14E0 24E72DF8 */  addiu     $a3, $a3, %lo(D_802A2DF8)
/* 7317E4 802A14E4 8CC20000 */  lw        $v0, ($a2)
/* 7317E8 802A14E8 8CE50000 */  lw        $a1, ($a3)
/* 7317EC 802A14EC 3463851F */  ori       $v1, $v1, 0x851f
/* 7317F0 802A14F0 00452021 */  addu      $a0, $v0, $a1
/* 7317F4 802A14F4 00830018 */  mult      $a0, $v1
/* 7317F8 802A14F8 00041FC3 */  sra       $v1, $a0, 0x1f
/* 7317FC 802A14FC 00004010 */  mfhi      $t0
/* 731800 802A1500 00081143 */  sra       $v0, $t0, 5
/* 731804 802A1504 00431023 */  subu      $v0, $v0, $v1
/* 731808 802A1508 28420082 */  slti      $v0, $v0, 0x82
/* 73180C 802A150C 14400003 */  bnez      $v0, .L802A151C
/* 731810 802A1510 ACC40000 */   sw       $a0, ($a2)
/* 731814 802A1514 2482CD38 */  addiu     $v0, $a0, -0x32c8
/* 731818 802A1518 ACC20000 */  sw        $v0, ($a2)
.L802A151C:
/* 73181C 802A151C 00A0182D */  daddu     $v1, $a1, $zero
/* 731820 802A1520 28620191 */  slti      $v0, $v1, 0x191
/* 731824 802A1524 14400003 */  bnez      $v0, .L802A1534
/* 731828 802A1528 28620065 */   slti     $v0, $v1, 0x65
/* 73182C 802A152C 080A8550 */  j         .L802A1540
/* 731830 802A1530 2462FFF6 */   addiu    $v0, $v1, -0xa
.L802A1534:
/* 731834 802A1534 14400002 */  bnez      $v0, .L802A1540
/* 731838 802A1538 24A2FFFF */   addiu    $v0, $a1, -1
/* 73183C 802A153C 2462FFFB */  addiu     $v0, $v1, -5
.L802A1540:
/* 731840 802A1540 ACE20000 */  sw        $v0, ($a3)
/* 731844 802A1544 3C02802A */  lui       $v0, %hi(D_802A2DF8)
/* 731848 802A1548 8C422DF8 */  lw        $v0, %lo(D_802A2DF8)($v0)
/* 73184C 802A154C 2842000A */  slti      $v0, $v0, 0xa
/* 731850 802A1550 104000A9 */  beqz      $v0, .L802A17F8
/* 731854 802A1554 3C0351EB */   lui      $v1, 0x51eb
/* 731858 802A1558 3C02802A */  lui       $v0, %hi(D_802A2DF4)
/* 73185C 802A155C 8C422DF4 */  lw        $v0, %lo(D_802A2DF4)($v0)
/* 731860 802A1560 3463851F */  ori       $v1, $v1, 0x851f
/* 731864 802A1564 00430018 */  mult      $v0, $v1
/* 731868 802A1568 3C044EC4 */  lui       $a0, 0x4ec4
/* 73186C 802A156C 3484EC4F */  ori       $a0, $a0, 0xec4f
/* 731870 802A1570 000217C3 */  sra       $v0, $v0, 0x1f
/* 731874 802A1574 00004010 */  mfhi      $t0
/* 731878 802A1578 00081943 */  sra       $v1, $t0, 5
/* 73187C 802A157C 00621823 */  subu      $v1, $v1, $v0
/* 731880 802A1580 00640018 */  mult      $v1, $a0
/* 731884 802A1584 000317C3 */  sra       $v0, $v1, 0x1f
/* 731888 802A1588 3C01802A */  lui       $at, %hi(D_802A2DF0)
/* 73188C 802A158C AC232DF0 */  sw        $v1, %lo(D_802A2DF0)($at)
/* 731890 802A1590 00004010 */  mfhi      $t0
/* 731894 802A1594 000820C3 */  sra       $a0, $t0, 3
/* 731898 802A1598 00822023 */  subu      $a0, $a0, $v0
/* 73189C 802A159C 00041040 */  sll       $v0, $a0, 1
/* 7318A0 802A15A0 00441021 */  addu      $v0, $v0, $a0
/* 7318A4 802A15A4 00021080 */  sll       $v0, $v0, 2
/* 7318A8 802A15A8 00441021 */  addu      $v0, $v0, $a0
/* 7318AC 802A15AC 00021040 */  sll       $v0, $v0, 1
/* 7318B0 802A15B0 00621823 */  subu      $v1, $v1, $v0
/* 7318B4 802A15B4 2863000D */  slti      $v1, $v1, 0xd
/* 7318B8 802A15B8 10600008 */  beqz      $v1, .L802A15DC
/* 7318BC 802A15BC 00000000 */   nop
/* 7318C0 802A15C0 0C00A67F */  jal       rand_int
/* 7318C4 802A15C4 24040064 */   addiu    $a0, $zero, 0x64
/* 7318C8 802A15C8 28420050 */  slti      $v0, $v0, 0x50
/* 7318CC 802A15CC 1440000D */  bnez      $v0, .L802A1604
/* 7318D0 802A15D0 24020002 */   addiu    $v0, $zero, 2
/* 7318D4 802A15D4 080A857C */  j         .L802A15F0
/* 7318D8 802A15D8 24020003 */   addiu    $v0, $zero, 3
.L802A15DC:
/* 7318DC 802A15DC 0C00A67F */  jal       rand_int
/* 7318E0 802A15E0 24040064 */   addiu    $a0, $zero, 0x64
/* 7318E4 802A15E4 2842003C */  slti      $v0, $v0, 0x3c
/* 7318E8 802A15E8 10400005 */  beqz      $v0, .L802A1600
/* 7318EC 802A15EC 24020003 */   addiu    $v0, $zero, 3
.L802A15F0:
/* 7318F0 802A15F0 3C01802A */  lui       $at, %hi(D_802A2DEC)
/* 7318F4 802A15F4 AC222DEC */  sw        $v0, %lo(D_802A2DEC)($at)
/* 7318F8 802A15F8 080A85FF */  j         .L802A17FC
/* 7318FC 802A15FC 0000102D */   daddu    $v0, $zero, $zero
.L802A1600:
/* 731900 802A1600 24020002 */  addiu     $v0, $zero, 2
.L802A1604:
/* 731904 802A1604 3C01802A */  lui       $at, %hi(D_802A2DEC)
/* 731908 802A1608 AC222DEC */  sw        $v0, %lo(D_802A2DEC)($at)
/* 73190C 802A160C 080A85FF */  j         .L802A17FC
/* 731910 802A1610 0000102D */   daddu    $v0, $zero, $zero
glabel L802A1614_731914
/* 731914 802A1614 3C024EC4 */  lui       $v0, 0x4ec4
/* 731918 802A1618 3C06802A */  lui       $a2, %hi(D_802A2DF0)
/* 73191C 802A161C 24C62DF0 */  addiu     $a2, $a2, %lo(D_802A2DF0)
/* 731920 802A1620 8CC50000 */  lw        $a1, ($a2)
/* 731924 802A1624 3442EC4F */  ori       $v0, $v0, 0xec4f
/* 731928 802A1628 00A20018 */  mult      $a1, $v0
/* 73192C 802A162C 000517C3 */  sra       $v0, $a1, 0x1f
/* 731930 802A1630 00004010 */  mfhi      $t0
/* 731934 802A1634 000818C3 */  sra       $v1, $t0, 3
/* 731938 802A1638 00622023 */  subu      $a0, $v1, $v0
/* 73193C 802A163C 00041040 */  sll       $v0, $a0, 1
/* 731940 802A1640 00441021 */  addu      $v0, $v0, $a0
/* 731944 802A1644 00021080 */  sll       $v0, $v0, 2
/* 731948 802A1648 00441021 */  addu      $v0, $v0, $a0
/* 73194C 802A164C 00021040 */  sll       $v0, $v0, 1
/* 731950 802A1650 00A22023 */  subu      $a0, $a1, $v0
/* 731954 802A1654 24820003 */  addiu     $v0, $a0, 3
/* 731958 802A1658 04420001 */  bltzl     $v0, .L802A1660
/* 73195C 802A165C 24820006 */   addiu    $v0, $a0, 6
.L802A1660:
/* 731960 802A1660 00022083 */  sra       $a0, $v0, 2
/* 731964 802A1664 00A41823 */  subu      $v1, $a1, $a0
/* 731968 802A1668 00031040 */  sll       $v0, $v1, 1
/* 73196C 802A166C 00431021 */  addu      $v0, $v0, $v1
/* 731970 802A1670 000210C0 */  sll       $v0, $v0, 3
/* 731974 802A1674 00431021 */  addu      $v0, $v0, $v1
/* 731978 802A1678 00021080 */  sll       $v0, $v0, 2
/* 73197C 802A167C ACC30000 */  sw        $v1, ($a2)
/* 731980 802A1680 3C01802A */  lui       $at, %hi(D_802A2DF4)
/* 731984 802A1684 AC222DF4 */  sw        $v0, %lo(D_802A2DF4)($at)
/* 731988 802A1688 1480005C */  bnez      $a0, .L802A17FC
/* 73198C 802A168C 0000102D */   daddu    $v0, $zero, $zero
/* 731990 802A1690 080A85B9 */  j         .L802A16E4
/* 731994 802A1694 24020004 */   addiu    $v0, $zero, 4
glabel L802A1698_731998
/* 731998 802A1698 3C024EC4 */  lui       $v0, 0x4ec4
/* 73199C 802A169C 3C06802A */  lui       $a2, %hi(D_802A2DF0)
/* 7319A0 802A16A0 24C62DF0 */  addiu     $a2, $a2, %lo(D_802A2DF0)
/* 7319A4 802A16A4 8CC50000 */  lw        $a1, ($a2)
/* 7319A8 802A16A8 3442EC4F */  ori       $v0, $v0, 0xec4f
/* 7319AC 802A16AC 00A20018 */  mult      $a1, $v0
/* 7319B0 802A16B0 000517C3 */  sra       $v0, $a1, 0x1f
/* 7319B4 802A16B4 00004010 */  mfhi      $t0
/* 7319B8 802A16B8 000818C3 */  sra       $v1, $t0, 3
/* 7319BC 802A16BC 00621823 */  subu      $v1, $v1, $v0
/* 7319C0 802A16C0 00031040 */  sll       $v0, $v1, 1
/* 7319C4 802A16C4 00431021 */  addu      $v0, $v0, $v1
/* 7319C8 802A16C8 00021080 */  sll       $v0, $v0, 2
/* 7319CC 802A16CC 00431021 */  addu      $v0, $v0, $v1
/* 7319D0 802A16D0 00021040 */  sll       $v0, $v0, 1
/* 7319D4 802A16D4 00A21823 */  subu      $v1, $a1, $v0
/* 7319D8 802A16D8 14600006 */  bnez      $v1, .L802A16F4
/* 7319DC 802A16DC 2402001A */   addiu    $v0, $zero, 0x1a
/* 7319E0 802A16E0 24020004 */  addiu     $v0, $zero, 4
.L802A16E4:
/* 7319E4 802A16E4 3C01802A */  lui       $at, %hi(D_802A2DEC)
/* 7319E8 802A16E8 AC222DEC */  sw        $v0, %lo(D_802A2DEC)($at)
/* 7319EC 802A16EC 080A85FF */  j         .L802A17FC
/* 7319F0 802A16F0 0000102D */   daddu    $v0, $zero, $zero
.L802A16F4:
/* 7319F4 802A16F4 00432023 */  subu      $a0, $v0, $v1
/* 7319F8 802A16F8 24820003 */  addiu     $v0, $a0, 3
/* 7319FC 802A16FC 04420001 */  bltzl     $v0, .L802A1704
/* 731A00 802A1700 24820006 */   addiu    $v0, $a0, 6
.L802A1704:
/* 731A04 802A1704 00022083 */  sra       $a0, $v0, 2
/* 731A08 802A1708 00A41821 */  addu      $v1, $a1, $a0
/* 731A0C 802A170C 00031040 */  sll       $v0, $v1, 1
/* 731A10 802A1710 00431021 */  addu      $v0, $v0, $v1
/* 731A14 802A1714 000210C0 */  sll       $v0, $v0, 3
/* 731A18 802A1718 00431021 */  addu      $v0, $v0, $v1
/* 731A1C 802A171C 00021080 */  sll       $v0, $v0, 2
/* 731A20 802A1720 ACC30000 */  sw        $v1, ($a2)
/* 731A24 802A1724 3C01802A */  lui       $at, %hi(D_802A2DF4)
/* 731A28 802A1728 AC222DF4 */  sw        $v0, %lo(D_802A2DF4)($at)
/* 731A2C 802A172C 080A85FF */  j         .L802A17FC
/* 731A30 802A1730 0000102D */   daddu    $v0, $zero, $zero
glabel L802A1734_731A34
/* 731A34 802A1734 24020014 */  addiu     $v0, $zero, 0x14
/* 731A38 802A1738 3C01802A */  lui       $at, %hi(D_802A2DFC)
/* 731A3C 802A173C AC222DFC */  sw        $v0, %lo(D_802A2DFC)($at)
/* 731A40 802A1740 24020005 */  addiu     $v0, $zero, 5
/* 731A44 802A1744 3C01802A */  lui       $at, %hi(D_802A2DEC)
/* 731A48 802A1748 AC222DEC */  sw        $v0, %lo(D_802A2DEC)($at)
/* 731A4C 802A174C 080A85FF */  j         .L802A17FC
/* 731A50 802A1750 0000102D */   daddu    $v0, $zero, $zero
glabel L802A1754_731A54
/* 731A54 802A1754 3C03802A */  lui       $v1, %hi(D_802A2DFC)
/* 731A58 802A1758 24632DFC */  addiu     $v1, $v1, %lo(D_802A2DFC)
/* 731A5C 802A175C 8C620000 */  lw        $v0, ($v1)
/* 731A60 802A1760 10400003 */  beqz      $v0, .L802A1770
/* 731A64 802A1764 2442FFFF */   addiu    $v0, $v0, -1
/* 731A68 802A1768 080A85FE */  j         .L802A17F8
/* 731A6C 802A176C AC620000 */   sw       $v0, ($v1)
.L802A1770:
/* 731A70 802A1770 3C034EC4 */  lui       $v1, 0x4ec4
/* 731A74 802A1774 3C02802A */  lui       $v0, %hi(D_802A2DF0)
/* 731A78 802A1778 8C422DF0 */  lw        $v0, %lo(D_802A2DF0)($v0)
/* 731A7C 802A177C 3463EC4F */  ori       $v1, $v1, 0xec4f
/* 731A80 802A1780 00430018 */  mult      $v0, $v1
/* 731A84 802A1784 3C11802A */  lui       $s1, %hi(D_802A2DD8)
/* 731A88 802A1788 26312DD8 */  addiu     $s1, $s1, %lo(D_802A2DD8)
/* 731A8C 802A178C 3C04802A */  lui       $a0, %hi(D_802A2E00)
/* 731A90 802A1790 8C842E00 */  lw        $a0, %lo(D_802A2E00)($a0)
/* 731A94 802A1794 000217C3 */  sra       $v0, $v0, 0x1f
/* 731A98 802A1798 00004010 */  mfhi      $t0
/* 731A9C 802A179C 000818C3 */  sra       $v1, $t0, 3
/* 731AA0 802A17A0 00628023 */  subu      $s0, $v1, $v0
/* 731AA4 802A17A4 00101080 */  sll       $v0, $s0, 2
/* 731AA8 802A17A8 0000802D */  daddu     $s0, $zero, $zero
/* 731AAC 802A17AC 3C01802A */  lui       $at, %hi(battle_item_strange_cake_D_802A2858_732B58+2)
/* 731AB0 802A17B0 00220821 */  addu      $at, $at, $v0
/* 731AB4 802A17B4 9422285A */  lhu       $v0, %lo(battle_item_strange_cake_D_802A2858_732B58+2)($at)
/* 731AB8 802A17B8 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 731ABC 802A17BC 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 731AC0 802A17C0 A462017A */  sh        $v0, 0x17a($v1)
/* 731AC4 802A17C4 00021400 */  sll       $v0, $v0, 0x10
/* 731AC8 802A17C8 00021403 */  sra       $v0, $v0, 0x10
/* 731ACC 802A17CC 0C048D70 */  jal       free_generic_entity
/* 731AD0 802A17D0 ACC20084 */   sw       $v0, 0x84($a2)
.L802A17D4:
/* 731AD4 802A17D4 8E240000 */  lw        $a0, ($s1)
/* 731AD8 802A17D8 26310004 */  addiu     $s1, $s1, 4
/* 731ADC 802A17DC 0C05123D */  jal       free_hud_element
/* 731AE0 802A17E0 26100001 */   addiu    $s0, $s0, 1
/* 731AE4 802A17E4 2A020005 */  slti      $v0, $s0, 5
/* 731AE8 802A17E8 1440FFFA */  bnez      $v0, .L802A17D4
/* 731AEC 802A17EC 24020002 */   addiu    $v0, $zero, 2
/* 731AF0 802A17F0 080A85FF */  j         .L802A17FC
/* 731AF4 802A17F4 00000000 */   nop
.L802A17F8:
/* 731AF8 802A17F8 0000102D */  daddu     $v0, $zero, $zero
.L802A17FC:
/* 731AFC 802A17FC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 731B00 802A1800 8FB3001C */  lw        $s3, 0x1c($sp)
/* 731B04 802A1804 8FB20018 */  lw        $s2, 0x18($sp)
/* 731B08 802A1808 8FB10014 */  lw        $s1, 0x14($sp)
/* 731B0C 802A180C 8FB00010 */  lw        $s0, 0x10($sp)
/* 731B10 802A1810 03E00008 */  jr        $ra
/* 731B14 802A1814 27BD0028 */   addiu    $sp, $sp, 0x28
