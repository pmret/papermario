.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802A25A0_72DB50
.word L802A143C_72C9EC, L802A1548_72CAF8, L802A168C_72CC3C, L802A1710_72CCC0, L802A17AC_72CD5C, L802A17CC_72CD7C, 0, 0

.section .text

glabel battle_item_mystery_func_802A13E4_72C994
/* 72C994 802A13E4 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 72C998 802A13E8 0080302D */  daddu     $a2, $a0, $zero
/* 72C99C 802A13EC AFB20020 */  sw        $s2, 0x20($sp)
/* 72C9A0 802A13F0 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 72C9A4 802A13F4 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 72C9A8 802A13F8 AFBF0028 */  sw        $ra, 0x28($sp)
/* 72C9AC 802A13FC AFB30024 */  sw        $s3, 0x24($sp)
/* 72C9B0 802A1400 AFB1001C */  sw        $s1, 0x1c($sp)
/* 72C9B4 802A1404 10A00003 */  beqz      $a1, .L802A1414
/* 72C9B8 802A1408 AFB00018 */   sw       $s0, 0x18($sp)
/* 72C9BC 802A140C 3C01802A */  lui       $at, %hi(D_802A25E4)
/* 72C9C0 802A1410 AC2025E4 */  sw        $zero, %lo(D_802A25E4)($at)
.L802A1414:
/* 72C9C4 802A1414 3C03802A */  lui       $v1, %hi(D_802A25E4)
/* 72C9C8 802A1418 8C6325E4 */  lw        $v1, %lo(D_802A25E4)($v1)
/* 72C9CC 802A141C 2C620006 */  sltiu     $v0, $v1, 6
/* 72C9D0 802A1420 10400112 */  beqz      $v0, .L802A186C
/* 72C9D4 802A1424 00031080 */   sll      $v0, $v1, 2
/* 72C9D8 802A1428 3C01802A */  lui       $at, %hi(jtbl_802A25A0_72DB50)
/* 72C9DC 802A142C 00220821 */  addu      $at, $at, $v0
/* 72C9E0 802A1430 8C2225A0 */  lw        $v0, %lo(jtbl_802A25A0_72DB50)($at)
/* 72C9E4 802A1434 00400008 */  jr        $v0
/* 72C9E8 802A1438 00000000 */   nop
glabel L802A143C_72C9EC
/* 72C9EC 802A143C 3C05802A */  lui       $a1, %hi(battle_item_mystery_func_802A123C_72C7EC)
/* 72C9F0 802A1440 24A5123C */  addiu     $a1, $a1, %lo(battle_item_mystery_func_802A123C_72C7EC)
/* 72C9F4 802A1444 0C048C8F */  jal       create_generic_entity_frontUI
/* 72C9F8 802A1448 0000202D */   daddu    $a0, $zero, $zero
/* 72C9FC 802A144C 3C01802A */  lui       $at, %hi(D_802A25F8)
/* 72CA00 802A1450 AC2225F8 */  sw        $v0, %lo(D_802A25F8)($at)
/* 72CA04 802A1454 0C00A67F */  jal       rand_int
/* 72CA08 802A1458 24044718 */   addiu    $a0, $zero, 0x4718
/* 72CA0C 802A145C 3C01802A */  lui       $at, %hi(D_802A25EC)
/* 72CA10 802A1460 AC2225EC */  sw        $v0, %lo(D_802A25EC)($at)
/* 72CA14 802A1464 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 72CA18 802A1468 3C10802A */  lui       $s0, %hi(D_802A25FC)
/* 72CA1C 802A146C 261025FC */  addiu     $s0, $s0, %lo(D_802A25FC)
/* 72CA20 802A1470 3C01802A */  lui       $at, %hi(D_802A25F0)
/* 72CA24 802A1474 AC2225F0 */  sw        $v0, %lo(D_802A25F0)($at)
/* 72CA28 802A1478 82430432 */  lb        $v1, 0x432($s2)
/* 72CA2C 802A147C 3C02802A */  lui       $v0, %hi(battle_item_mystery_D_802A227C_72D82C)
/* 72CA30 802A1480 2442227C */  addiu     $v0, $v0, %lo(battle_item_mystery_D_802A227C_72D82C)
/* 72CA34 802A1484 18600010 */  blez      $v1, .L802A14C8
/* 72CA38 802A1488 AE020000 */   sw       $v0, ($s0)
/* 72CA3C 802A148C 24040001 */  addiu     $a0, $zero, 1
/* 72CA40 802A1490 27A50010 */  addiu     $a1, $sp, 0x10
/* 72CA44 802A1494 0C04DF70 */  jal       get_screen_overlay_params
/* 72CA48 802A1498 27A60014 */   addiu    $a2, $sp, 0x14
/* 72CA4C 802A149C C7A20014 */  lwc1      $f2, 0x14($sp)
/* 72CA50 802A14A0 3C014357 */  lui       $at, 0x4357
/* 72CA54 802A14A4 44810000 */  mtc1      $at, $f0
/* 72CA58 802A14A8 00000000 */  nop
/* 72CA5C 802A14AC 4602003E */  c.le.s    $f0, $f2
/* 72CA60 802A14B0 00000000 */  nop
/* 72CA64 802A14B4 45020005 */  bc1fl     .L802A14CC
/* 72CA68 802A14B8 0000802D */   daddu    $s0, $zero, $zero
/* 72CA6C 802A14BC 3C02802A */  lui       $v0, %hi(battle_item_mystery_D_802A229C_72D84C)
/* 72CA70 802A14C0 2442229C */  addiu     $v0, $v0, %lo(battle_item_mystery_D_802A229C_72D84C)
/* 72CA74 802A14C4 AE020000 */  sw        $v0, ($s0)
.L802A14C8:
/* 72CA78 802A14C8 0000802D */  daddu     $s0, $zero, $zero
.L802A14CC:
/* 72CA7C 802A14CC 3C138009 */  lui       $s3, %hi(D_8008A680)
/* 72CA80 802A14D0 2673A680 */  addiu     $s3, $s3, %lo(D_8008A680)
/* 72CA84 802A14D4 3C128008 */  lui       $s2, %hi(gItemTable)
/* 72CA88 802A14D8 265278E0 */  addiu     $s2, $s2, %lo(gItemTable)
/* 72CA8C 802A14DC 3C11802A */  lui       $s1, %hi(D_802A25C8)
/* 72CA90 802A14E0 263125C8 */  addiu     $s1, $s1, %lo(D_802A25C8)
.L802A14E4:
/* 72CA94 802A14E4 3C03802A */  lui       $v1, %hi(D_802A25FC)
/* 72CA98 802A14E8 8C6325FC */  lw        $v1, %lo(D_802A25FC)($v1)
/* 72CA9C 802A14EC 00101080 */  sll       $v0, $s0, 2
/* 72CAA0 802A14F0 00431021 */  addu      $v0, $v0, $v1
/* 72CAA4 802A14F4 8C420000 */  lw        $v0, ($v0)
/* 72CAA8 802A14F8 00021140 */  sll       $v0, $v0, 5
/* 72CAAC 802A14FC 00521021 */  addu      $v0, $v0, $s2
/* 72CAB0 802A1500 84420004 */  lh        $v0, 4($v0)
/* 72CAB4 802A1504 000210C0 */  sll       $v0, $v0, 3
/* 72CAB8 802A1508 00531021 */  addu      $v0, $v0, $s3
/* 72CABC 802A150C 8C440000 */  lw        $a0, ($v0)
/* 72CAC0 802A1510 0C050529 */  jal       create_hud_element
/* 72CAC4 802A1514 26100001 */   addiu    $s0, $s0, 1
/* 72CAC8 802A1518 0040202D */  daddu     $a0, $v0, $zero
/* 72CACC 802A151C 24050080 */  addiu     $a1, $zero, 0x80
/* 72CAD0 802A1520 0C051280 */  jal       set_hud_element_flags
/* 72CAD4 802A1524 AE240000 */   sw       $a0, ($s1)
/* 72CAD8 802A1528 2A020007 */  slti      $v0, $s0, 7
/* 72CADC 802A152C 1440FFED */  bnez      $v0, .L802A14E4
/* 72CAE0 802A1530 26310004 */   addiu    $s1, $s1, 4
/* 72CAE4 802A1534 24020001 */  addiu     $v0, $zero, 1
/* 72CAE8 802A1538 3C01802A */  lui       $at, %hi(D_802A25E4)
/* 72CAEC 802A153C AC2225E4 */  sw        $v0, %lo(D_802A25E4)($at)
/* 72CAF0 802A1540 080A861C */  j         .L802A1870
/* 72CAF4 802A1544 0000102D */   daddu    $v0, $zero, $zero
glabel L802A1548_72CAF8
/* 72CAF8 802A1548 3C0351EB */  lui       $v1, 0x51eb
/* 72CAFC 802A154C 3C06802A */  lui       $a2, %hi(D_802A25EC)
/* 72CB00 802A1550 24C625EC */  addiu     $a2, $a2, %lo(D_802A25EC)
/* 72CB04 802A1554 3C07802A */  lui       $a3, %hi(D_802A25F0)
/* 72CB08 802A1558 24E725F0 */  addiu     $a3, $a3, %lo(D_802A25F0)
/* 72CB0C 802A155C 8CC20000 */  lw        $v0, ($a2)
/* 72CB10 802A1560 8CE50000 */  lw        $a1, ($a3)
/* 72CB14 802A1564 3463851F */  ori       $v1, $v1, 0x851f
/* 72CB18 802A1568 00452021 */  addu      $a0, $v0, $a1
/* 72CB1C 802A156C 00830018 */  mult      $a0, $v1
/* 72CB20 802A1570 00041FC3 */  sra       $v1, $a0, 0x1f
/* 72CB24 802A1574 00004010 */  mfhi      $t0
/* 72CB28 802A1578 00081143 */  sra       $v0, $t0, 5
/* 72CB2C 802A157C 00431023 */  subu      $v0, $v0, $v1
/* 72CB30 802A1580 284200B6 */  slti      $v0, $v0, 0xb6
/* 72CB34 802A1584 14400003 */  bnez      $v0, .L802A1594
/* 72CB38 802A1588 ACC40000 */   sw       $a0, ($a2)
/* 72CB3C 802A158C 2482B8E8 */  addiu     $v0, $a0, -0x4718
/* 72CB40 802A1590 ACC20000 */  sw        $v0, ($a2)
.L802A1594:
/* 72CB44 802A1594 00A0182D */  daddu     $v1, $a1, $zero
/* 72CB48 802A1598 28620191 */  slti      $v0, $v1, 0x191
/* 72CB4C 802A159C 14400003 */  bnez      $v0, .L802A15AC
/* 72CB50 802A15A0 28620065 */   slti     $v0, $v1, 0x65
/* 72CB54 802A15A4 080A856E */  j         .L802A15B8
/* 72CB58 802A15A8 2462FFF6 */   addiu    $v0, $v1, -0xa
.L802A15AC:
/* 72CB5C 802A15AC 14400002 */  bnez      $v0, .L802A15B8
/* 72CB60 802A15B0 24A2FFFF */   addiu    $v0, $a1, -1
/* 72CB64 802A15B4 2462FFFB */  addiu     $v0, $v1, -5
.L802A15B8:
/* 72CB68 802A15B8 ACE20000 */  sw        $v0, ($a3)
/* 72CB6C 802A15BC 3C02802A */  lui       $v0, %hi(D_802A25F0)
/* 72CB70 802A15C0 8C4225F0 */  lw        $v0, %lo(D_802A25F0)($v0)
/* 72CB74 802A15C4 2842000A */  slti      $v0, $v0, 0xa
/* 72CB78 802A15C8 104000A8 */  beqz      $v0, .L802A186C
/* 72CB7C 802A15CC 3C0351EB */   lui      $v1, 0x51eb
/* 72CB80 802A15D0 3C02802A */  lui       $v0, %hi(D_802A25EC)
/* 72CB84 802A15D4 8C4225EC */  lw        $v0, %lo(D_802A25EC)($v0)
/* 72CB88 802A15D8 3463851F */  ori       $v1, $v1, 0x851f
/* 72CB8C 802A15DC 00430018 */  mult      $v0, $v1
/* 72CB90 802A15E0 3C044EC4 */  lui       $a0, 0x4ec4
/* 72CB94 802A15E4 3484EC4F */  ori       $a0, $a0, 0xec4f
/* 72CB98 802A15E8 000217C3 */  sra       $v0, $v0, 0x1f
/* 72CB9C 802A15EC 00004010 */  mfhi      $t0
/* 72CBA0 802A15F0 00081943 */  sra       $v1, $t0, 5
/* 72CBA4 802A15F4 00621823 */  subu      $v1, $v1, $v0
/* 72CBA8 802A15F8 00640018 */  mult      $v1, $a0
/* 72CBAC 802A15FC 000317C3 */  sra       $v0, $v1, 0x1f
/* 72CBB0 802A1600 3C01802A */  lui       $at, %hi(D_802A25E8)
/* 72CBB4 802A1604 AC2325E8 */  sw        $v1, %lo(D_802A25E8)($at)
/* 72CBB8 802A1608 00004010 */  mfhi      $t0
/* 72CBBC 802A160C 000820C3 */  sra       $a0, $t0, 3
/* 72CBC0 802A1610 00822023 */  subu      $a0, $a0, $v0
/* 72CBC4 802A1614 00041040 */  sll       $v0, $a0, 1
/* 72CBC8 802A1618 00441021 */  addu      $v0, $v0, $a0
/* 72CBCC 802A161C 00021080 */  sll       $v0, $v0, 2
/* 72CBD0 802A1620 00441021 */  addu      $v0, $v0, $a0
/* 72CBD4 802A1624 00021040 */  sll       $v0, $v0, 1
/* 72CBD8 802A1628 00621823 */  subu      $v1, $v1, $v0
/* 72CBDC 802A162C 2863000D */  slti      $v1, $v1, 0xd
/* 72CBE0 802A1630 10600008 */  beqz      $v1, .L802A1654
/* 72CBE4 802A1634 00000000 */   nop
/* 72CBE8 802A1638 0C00A67F */  jal       rand_int
/* 72CBEC 802A163C 24040064 */   addiu    $a0, $zero, 0x64
/* 72CBF0 802A1640 28420050 */  slti      $v0, $v0, 0x50
/* 72CBF4 802A1644 1440000D */  bnez      $v0, .L802A167C
/* 72CBF8 802A1648 24020002 */   addiu    $v0, $zero, 2
/* 72CBFC 802A164C 080A859A */  j         .L802A1668
/* 72CC00 802A1650 24020003 */   addiu    $v0, $zero, 3
.L802A1654:
/* 72CC04 802A1654 0C00A67F */  jal       rand_int
/* 72CC08 802A1658 24040064 */   addiu    $a0, $zero, 0x64
/* 72CC0C 802A165C 2842003C */  slti      $v0, $v0, 0x3c
/* 72CC10 802A1660 10400005 */  beqz      $v0, .L802A1678
/* 72CC14 802A1664 24020003 */   addiu    $v0, $zero, 3
.L802A1668:
/* 72CC18 802A1668 3C01802A */  lui       $at, %hi(D_802A25E4)
/* 72CC1C 802A166C AC2225E4 */  sw        $v0, %lo(D_802A25E4)($at)
/* 72CC20 802A1670 080A861C */  j         .L802A1870
/* 72CC24 802A1674 0000102D */   daddu    $v0, $zero, $zero
.L802A1678:
/* 72CC28 802A1678 24020002 */  addiu     $v0, $zero, 2
.L802A167C:
/* 72CC2C 802A167C 3C01802A */  lui       $at, %hi(D_802A25E4)
/* 72CC30 802A1680 AC2225E4 */  sw        $v0, %lo(D_802A25E4)($at)
/* 72CC34 802A1684 080A861C */  j         .L802A1870
/* 72CC38 802A1688 0000102D */   daddu    $v0, $zero, $zero
glabel L802A168C_72CC3C
/* 72CC3C 802A168C 3C024EC4 */  lui       $v0, 0x4ec4
/* 72CC40 802A1690 3C06802A */  lui       $a2, %hi(D_802A25E8)
/* 72CC44 802A1694 24C625E8 */  addiu     $a2, $a2, %lo(D_802A25E8)
/* 72CC48 802A1698 8CC50000 */  lw        $a1, ($a2)
/* 72CC4C 802A169C 3442EC4F */  ori       $v0, $v0, 0xec4f
/* 72CC50 802A16A0 00A20018 */  mult      $a1, $v0
/* 72CC54 802A16A4 000517C3 */  sra       $v0, $a1, 0x1f
/* 72CC58 802A16A8 00004010 */  mfhi      $t0
/* 72CC5C 802A16AC 000818C3 */  sra       $v1, $t0, 3
/* 72CC60 802A16B0 00622023 */  subu      $a0, $v1, $v0
/* 72CC64 802A16B4 00041040 */  sll       $v0, $a0, 1
/* 72CC68 802A16B8 00441021 */  addu      $v0, $v0, $a0
/* 72CC6C 802A16BC 00021080 */  sll       $v0, $v0, 2
/* 72CC70 802A16C0 00441021 */  addu      $v0, $v0, $a0
/* 72CC74 802A16C4 00021040 */  sll       $v0, $v0, 1
/* 72CC78 802A16C8 00A22023 */  subu      $a0, $a1, $v0
/* 72CC7C 802A16CC 24820003 */  addiu     $v0, $a0, 3
/* 72CC80 802A16D0 04420001 */  bltzl     $v0, .L802A16D8
/* 72CC84 802A16D4 24820006 */   addiu    $v0, $a0, 6
.L802A16D8:
/* 72CC88 802A16D8 00022083 */  sra       $a0, $v0, 2
/* 72CC8C 802A16DC 00A41823 */  subu      $v1, $a1, $a0
/* 72CC90 802A16E0 00031040 */  sll       $v0, $v1, 1
/* 72CC94 802A16E4 00431021 */  addu      $v0, $v0, $v1
/* 72CC98 802A16E8 000210C0 */  sll       $v0, $v0, 3
/* 72CC9C 802A16EC 00431021 */  addu      $v0, $v0, $v1
/* 72CCA0 802A16F0 00021080 */  sll       $v0, $v0, 2
/* 72CCA4 802A16F4 ACC30000 */  sw        $v1, ($a2)
/* 72CCA8 802A16F8 3C01802A */  lui       $at, %hi(D_802A25EC)
/* 72CCAC 802A16FC AC2225EC */  sw        $v0, %lo(D_802A25EC)($at)
/* 72CCB0 802A1700 1480005B */  bnez      $a0, .L802A1870
/* 72CCB4 802A1704 0000102D */   daddu    $v0, $zero, $zero
/* 72CCB8 802A1708 080A85D7 */  j         .L802A175C
/* 72CCBC 802A170C 24020004 */   addiu    $v0, $zero, 4
glabel L802A1710_72CCC0
/* 72CCC0 802A1710 3C024EC4 */  lui       $v0, 0x4ec4
/* 72CCC4 802A1714 3C06802A */  lui       $a2, %hi(D_802A25E8)
/* 72CCC8 802A1718 24C625E8 */  addiu     $a2, $a2, %lo(D_802A25E8)
/* 72CCCC 802A171C 8CC50000 */  lw        $a1, ($a2)
/* 72CCD0 802A1720 3442EC4F */  ori       $v0, $v0, 0xec4f
/* 72CCD4 802A1724 00A20018 */  mult      $a1, $v0
/* 72CCD8 802A1728 000517C3 */  sra       $v0, $a1, 0x1f
/* 72CCDC 802A172C 00004010 */  mfhi      $t0
/* 72CCE0 802A1730 000818C3 */  sra       $v1, $t0, 3
/* 72CCE4 802A1734 00621823 */  subu      $v1, $v1, $v0
/* 72CCE8 802A1738 00031040 */  sll       $v0, $v1, 1
/* 72CCEC 802A173C 00431021 */  addu      $v0, $v0, $v1
/* 72CCF0 802A1740 00021080 */  sll       $v0, $v0, 2
/* 72CCF4 802A1744 00431021 */  addu      $v0, $v0, $v1
/* 72CCF8 802A1748 00021040 */  sll       $v0, $v0, 1
/* 72CCFC 802A174C 00A21823 */  subu      $v1, $a1, $v0
/* 72CD00 802A1750 14600006 */  bnez      $v1, .L802A176C
/* 72CD04 802A1754 2402001A */   addiu    $v0, $zero, 0x1a
/* 72CD08 802A1758 24020004 */  addiu     $v0, $zero, 4
.L802A175C:
/* 72CD0C 802A175C 3C01802A */  lui       $at, %hi(D_802A25E4)
/* 72CD10 802A1760 AC2225E4 */  sw        $v0, %lo(D_802A25E4)($at)
/* 72CD14 802A1764 080A861C */  j         .L802A1870
/* 72CD18 802A1768 0000102D */   daddu    $v0, $zero, $zero
.L802A176C:
/* 72CD1C 802A176C 00432023 */  subu      $a0, $v0, $v1
/* 72CD20 802A1770 24820003 */  addiu     $v0, $a0, 3
/* 72CD24 802A1774 04420001 */  bltzl     $v0, .L802A177C
/* 72CD28 802A1778 24820006 */   addiu    $v0, $a0, 6
.L802A177C:
/* 72CD2C 802A177C 00022083 */  sra       $a0, $v0, 2
/* 72CD30 802A1780 00A41821 */  addu      $v1, $a1, $a0
/* 72CD34 802A1784 00031040 */  sll       $v0, $v1, 1
/* 72CD38 802A1788 00431021 */  addu      $v0, $v0, $v1
/* 72CD3C 802A178C 000210C0 */  sll       $v0, $v0, 3
/* 72CD40 802A1790 00431021 */  addu      $v0, $v0, $v1
/* 72CD44 802A1794 00021080 */  sll       $v0, $v0, 2
/* 72CD48 802A1798 ACC30000 */  sw        $v1, ($a2)
/* 72CD4C 802A179C 3C01802A */  lui       $at, %hi(D_802A25EC)
/* 72CD50 802A17A0 AC2225EC */  sw        $v0, %lo(D_802A25EC)($at)
/* 72CD54 802A17A4 080A861C */  j         .L802A1870
/* 72CD58 802A17A8 0000102D */   daddu    $v0, $zero, $zero
glabel L802A17AC_72CD5C
/* 72CD5C 802A17AC 24020014 */  addiu     $v0, $zero, 0x14
/* 72CD60 802A17B0 3C01802A */  lui       $at, %hi(D_802A25F4)
/* 72CD64 802A17B4 AC2225F4 */  sw        $v0, %lo(D_802A25F4)($at)
/* 72CD68 802A17B8 24020005 */  addiu     $v0, $zero, 5
/* 72CD6C 802A17BC 3C01802A */  lui       $at, %hi(D_802A25E4)
/* 72CD70 802A17C0 AC2225E4 */  sw        $v0, %lo(D_802A25E4)($at)
/* 72CD74 802A17C4 080A861C */  j         .L802A1870
/* 72CD78 802A17C8 0000102D */   daddu    $v0, $zero, $zero
glabel L802A17CC_72CD7C
/* 72CD7C 802A17CC 3C03802A */  lui       $v1, %hi(D_802A25F4)
/* 72CD80 802A17D0 246325F4 */  addiu     $v1, $v1, %lo(D_802A25F4)
/* 72CD84 802A17D4 8C620000 */  lw        $v0, ($v1)
/* 72CD88 802A17D8 10400003 */  beqz      $v0, .L802A17E8
/* 72CD8C 802A17DC 2442FFFF */   addiu    $v0, $v0, -1
/* 72CD90 802A17E0 080A861B */  j         .L802A186C
/* 72CD94 802A17E4 AC620000 */   sw       $v0, ($v1)
.L802A17E8:
/* 72CD98 802A17E8 3C034EC4 */  lui       $v1, 0x4ec4
/* 72CD9C 802A17EC 3C02802A */  lui       $v0, %hi(D_802A25E8)
/* 72CDA0 802A17F0 8C4225E8 */  lw        $v0, %lo(D_802A25E8)($v0)
/* 72CDA4 802A17F4 3463EC4F */  ori       $v1, $v1, 0xec4f
/* 72CDA8 802A17F8 00430018 */  mult      $v0, $v1
/* 72CDAC 802A17FC 3C11802A */  lui       $s1, %hi(D_802A25C8)
/* 72CDB0 802A1800 263125C8 */  addiu     $s1, $s1, %lo(D_802A25C8)
/* 72CDB4 802A1804 3C04802A */  lui       $a0, %hi(D_802A25F8)
/* 72CDB8 802A1808 8C8425F8 */  lw        $a0, %lo(D_802A25F8)($a0)
/* 72CDBC 802A180C 000217C3 */  sra       $v0, $v0, 0x1f
/* 72CDC0 802A1810 00004010 */  mfhi      $t0
/* 72CDC4 802A1814 000818C3 */  sra       $v1, $t0, 3
/* 72CDC8 802A1818 00628023 */  subu      $s0, $v1, $v0
/* 72CDCC 802A181C 3C03802A */  lui       $v1, %hi(D_802A25FC)
/* 72CDD0 802A1820 8C6325FC */  lw        $v1, %lo(D_802A25FC)($v1)
/* 72CDD4 802A1824 00101080 */  sll       $v0, $s0, 2
/* 72CDD8 802A1828 00431021 */  addu      $v0, $v0, $v1
/* 72CDDC 802A182C 94420002 */  lhu       $v0, 2($v0)
/* 72CDE0 802A1830 0000802D */  daddu     $s0, $zero, $zero
/* 72CDE4 802A1834 A642017A */  sh        $v0, 0x17a($s2)
/* 72CDE8 802A1838 00021400 */  sll       $v0, $v0, 0x10
/* 72CDEC 802A183C 00021403 */  sra       $v0, $v0, 0x10
/* 72CDF0 802A1840 0C048D70 */  jal       free_generic_entity
/* 72CDF4 802A1844 ACC20084 */   sw       $v0, 0x84($a2)
.L802A1848:
/* 72CDF8 802A1848 8E240000 */  lw        $a0, ($s1)
/* 72CDFC 802A184C 26310004 */  addiu     $s1, $s1, 4
/* 72CE00 802A1850 0C05123D */  jal       free_hud_element
/* 72CE04 802A1854 26100001 */   addiu    $s0, $s0, 1
/* 72CE08 802A1858 2A020007 */  slti      $v0, $s0, 7
/* 72CE0C 802A185C 1440FFFA */  bnez      $v0, .L802A1848
/* 72CE10 802A1860 24020002 */   addiu    $v0, $zero, 2
/* 72CE14 802A1864 080A861C */  j         .L802A1870
/* 72CE18 802A1868 00000000 */   nop
.L802A186C:
/* 72CE1C 802A186C 0000102D */  daddu     $v0, $zero, $zero
.L802A1870:
/* 72CE20 802A1870 8FBF0028 */  lw        $ra, 0x28($sp)
/* 72CE24 802A1874 8FB30024 */  lw        $s3, 0x24($sp)
/* 72CE28 802A1878 8FB20020 */  lw        $s2, 0x20($sp)
/* 72CE2C 802A187C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 72CE30 802A1880 8FB00018 */  lw        $s0, 0x18($sp)
/* 72CE34 802A1884 03E00008 */  jr        $ra
/* 72CE38 802A1888 27BD0030 */   addiu    $sp, $sp, 0x30
