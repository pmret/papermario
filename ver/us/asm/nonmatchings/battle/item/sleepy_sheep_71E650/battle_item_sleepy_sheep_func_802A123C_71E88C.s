.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802A3E88_7214D8
.word 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFE2, 0x00000000, 0xFFFFFFCE, 0xFFFFFFE5, 0x00000000, 0x0000001E, 0xFFFFFFBA, 0x00000000, 0xFFFFFFFB, 0xFFFFFF97, 0x00000000, 0x0000001E, 0xFFFFFF92, 0x00000000, 0xFFFFFFCE, 0xFFFFFF6F, 0x00000000, 0xFFFFFFFB, 0xFFFFFF56, 0x00000000, 0xFFFFFFCE, 0xFFFFFF42, 0x00000000, 0xFFFFFFE2, 0xFFFFFF2E, 0x00000000, 0xFFFFFFF6

glabel D_802A3F00_721550
.word 0x3F800000, 0x3F800000, 0x3F400000, 0x3F800000, 0x3F800000, 0x3F800000, 0x3F800000, 0x3F800000, 0x3F400000, 0x3F400000

glabel D_802A3F28_721578
.word 0x802A3260, 0x802A32A0, 0x802A32E0, 0x802A3260, 0x802A32A0, 0x802A32E0, 0x802A3260, 0x802A32A0, 0x802A32E0, 0x802A3260

.section .text

glabel battle_item_sleepy_sheep_func_802A123C_71E88C
/* 71E88C 802A123C 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 71E890 802A1240 AFBE0038 */  sw        $fp, 0x38($sp)
/* 71E894 802A1244 3C1E802A */  lui       $fp, %hi(D_802A3F88)
/* 71E898 802A1248 27DE3F88 */  addiu     $fp, $fp, %lo(D_802A3F88)
/* 71E89C 802A124C AFBF003C */  sw        $ra, 0x3c($sp)
/* 71E8A0 802A1250 AFB70034 */  sw        $s7, 0x34($sp)
/* 71E8A4 802A1254 AFB60030 */  sw        $s6, 0x30($sp)
/* 71E8A8 802A1258 AFB5002C */  sw        $s5, 0x2c($sp)
/* 71E8AC 802A125C AFB40028 */  sw        $s4, 0x28($sp)
/* 71E8B0 802A1260 AFB30024 */  sw        $s3, 0x24($sp)
/* 71E8B4 802A1264 AFB20020 */  sw        $s2, 0x20($sp)
/* 71E8B8 802A1268 AFB1001C */  sw        $s1, 0x1c($sp)
/* 71E8BC 802A126C AFB00018 */  sw        $s0, 0x18($sp)
/* 71E8C0 802A1270 F7BA0058 */  sdc1      $f26, 0x58($sp)
/* 71E8C4 802A1274 F7B80050 */  sdc1      $f24, 0x50($sp)
/* 71E8C8 802A1278 F7B60048 */  sdc1      $f22, 0x48($sp)
/* 71E8CC 802A127C F7B40040 */  sdc1      $f20, 0x40($sp)
/* 71E8D0 802A1280 10A00002 */  beqz      $a1, .L802A128C
/* 71E8D4 802A1284 AFA40060 */   sw       $a0, 0x60($sp)
/* 71E8D8 802A1288 AC800070 */  sw        $zero, 0x70($a0)
.L802A128C:
/* 71E8DC 802A128C 8FA80060 */  lw        $t0, 0x60($sp)
/* 71E8E0 802A1290 8D030070 */  lw        $v1, 0x70($t0)
/* 71E8E4 802A1294 24020001 */  addiu     $v0, $zero, 1
/* 71E8E8 802A1298 1062005A */  beq       $v1, $v0, .L802A1404
/* 71E8EC 802A129C 28620002 */   slti     $v0, $v1, 2
/* 71E8F0 802A12A0 10400005 */  beqz      $v0, .L802A12B8
/* 71E8F4 802A12A4 24020002 */   addiu    $v0, $zero, 2
/* 71E8F8 802A12A8 10600007 */  beqz      $v1, .L802A12C8
/* 71E8FC 802A12AC 0000102D */   daddu    $v0, $zero, $zero
/* 71E900 802A12B0 080A85C0 */  j         .L802A1700
/* 71E904 802A12B4 00000000 */   nop
.L802A12B8:
/* 71E908 802A12B8 10620104 */  beq       $v1, $v0, .L802A16CC
/* 71E90C 802A12BC 0000102D */   daddu    $v0, $zero, $zero
/* 71E910 802A12C0 080A85C0 */  j         .L802A1700
/* 71E914 802A12C4 00000000 */   nop
.L802A12C8:
/* 71E918 802A12C8 0000882D */  daddu     $s1, $zero, $zero
/* 71E91C 802A12CC 3C17802A */  lui       $s7, %hi(D_802A3F00_721550)
/* 71E920 802A12D0 26F73F00 */  addiu     $s7, $s7, %lo(D_802A3F00_721550)
/* 71E924 802A12D4 24160008 */  addiu     $s6, $zero, 8
/* 71E928 802A12D8 24150004 */  addiu     $s5, $zero, 4
/* 71E92C 802A12DC 3C14802A */  lui       $s4, %hi(D_802A3E88_7214D8)
/* 71E930 802A12E0 26943E88 */  addiu     $s4, $s4, %lo(D_802A3E88_7214D8)
/* 71E934 802A12E4 3C13802A */  lui       $s3, %hi(D_802A3F58)
/* 71E938 802A12E8 26733F58 */  addiu     $s3, $s3, %lo(D_802A3F58)
/* 71E93C 802A12EC 3C01C348 */  lui       $at, 0xc348
/* 71E940 802A12F0 44810000 */  mtc1      $at, $f0
/* 71E944 802A12F4 3C014120 */  lui       $at, 0x4120
/* 71E948 802A12F8 44811000 */  mtc1      $at, $f2
/* 71E94C 802A12FC 3C12802A */  lui       $s2, %hi(D_802A3F28_721578)
/* 71E950 802A1300 26523F28 */  addiu     $s2, $s2, %lo(D_802A3F28_721578)
/* 71E954 802A1304 E7C00000 */  swc1      $f0, ($fp)
/* 71E958 802A1308 E7C20008 */  swc1      $f2, 8($fp)
.L802A130C:
/* 71E95C 802A130C 8E440000 */  lw        $a0, ($s2)
/* 71E960 802A1310 26520004 */  addiu     $s2, $s2, 4
/* 71E964 802A1314 0C0B5083 */  jal       func_802D420C
/* 71E968 802A1318 26310001 */   addiu    $s1, $s1, 1
/* 71E96C 802A131C 3C08802A */  lui       $t0, %hi(D_802A3E88_7214D8)
/* 71E970 802A1320 25083E88 */  addiu     $t0, $t0, %lo(D_802A3E88_7214D8)
/* 71E974 802A1324 02A81821 */  addu      $v1, $s5, $t0
/* 71E978 802A1328 AE620000 */  sw        $v0, ($s3)
/* 71E97C 802A132C C4740000 */  lwc1      $f20, ($v1)
/* 71E980 802A1330 4680A520 */  cvt.s.w   $f20, $f20
/* 71E984 802A1334 0040802D */  daddu     $s0, $v0, $zero
/* 71E988 802A1338 0200202D */  daddu     $a0, $s0, $zero
/* 71E98C 802A133C 4600A10D */  trunc.w.s $f4, $f20
/* 71E990 802A1340 44062000 */  mfc1      $a2, $f4
/* 71E994 802A1344 3C08802A */  lui       $t0, %hi(D_802A3E88_7214D8)
/* 71E998 802A1348 25083E88 */  addiu     $t0, $t0, %lo(D_802A3E88_7214D8)
/* 71E99C 802A134C 02C81021 */  addu      $v0, $s6, $t0
/* 71E9A0 802A1350 26D6000C */  addiu     $s6, $s6, 0xc
/* 71E9A4 802A1354 26B5000C */  addiu     $s5, $s5, 0xc
/* 71E9A8 802A1358 C6820000 */  lwc1      $f2, ($s4)
/* 71E9AC 802A135C 468010A0 */  cvt.s.w   $f2, $f2
/* 71E9B0 802A1360 C7C00000 */  lwc1      $f0, ($fp)
/* 71E9B4 802A1364 2694000C */  addiu     $s4, $s4, 0xc
/* 71E9B8 802A1368 46001580 */  add.s     $f22, $f2, $f0
/* 71E9BC 802A136C C7C20008 */  lwc1      $f2, 8($fp)
/* 71E9C0 802A1370 C4400000 */  lwc1      $f0, ($v0)
/* 71E9C4 802A1374 46800020 */  cvt.s.w   $f0, $f0
/* 71E9C8 802A1378 46020600 */  add.s     $f24, $f0, $f2
/* 71E9CC 802A137C 4600B10D */  trunc.w.s $f4, $f22
/* 71E9D0 802A1380 44052000 */  mfc1      $a1, $f4
/* 71E9D4 802A1384 4600C10D */  trunc.w.s $f4, $f24
/* 71E9D8 802A1388 44072000 */  mfc1      $a3, $f4
/* 71E9DC 802A138C 0C0B50D9 */  jal       func_802D4364
/* 71E9E0 802A1390 26730004 */   addiu    $s3, $s3, 4
/* 71E9E4 802A1394 0200202D */  daddu     $a0, $s0, $zero
/* 71E9E8 802A1398 8EE50000 */  lw        $a1, ($s7)
/* 71E9EC 802A139C 26F70004 */  addiu     $s7, $s7, 4
/* 71E9F0 802A13A0 3C073F80 */  lui       $a3, 0x3f80
/* 71E9F4 802A13A4 0C0B50EB */  jal       func_802D43AC
/* 71E9F8 802A13A8 00A0302D */   daddu    $a2, $a1, $zero
/* 71E9FC 802A13AC 2A22000A */  slti      $v0, $s1, 0xa
/* 71EA00 802A13B0 1440FFD6 */  bnez      $v0, .L802A130C
/* 71EA04 802A13B4 00000000 */   nop
/* 71EA08 802A13B8 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 71EA0C 802A13BC 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 71EA10 802A13C0 94440134 */  lhu       $a0, 0x134($v0)
/* 71EA14 802A13C4 3C02CCCC */  lui       $v0, 0xcccc
/* 71EA18 802A13C8 3442CCCD */  ori       $v0, $v0, 0xcccd
/* 71EA1C 802A13CC 00820019 */  multu     $a0, $v0
/* 71EA20 802A13D0 8FA80060 */  lw        $t0, 0x60($sp)
/* 71EA24 802A13D4 24020001 */  addiu     $v0, $zero, 1
/* 71EA28 802A13D8 AD020070 */  sw        $v0, 0x70($t0)
/* 71EA2C 802A13DC 00004010 */  mfhi      $t0
/* 71EA30 802A13E0 000818C2 */  srl       $v1, $t0, 3
/* 71EA34 802A13E4 00031080 */  sll       $v0, $v1, 2
/* 71EA38 802A13E8 00431021 */  addu      $v0, $v0, $v1
/* 71EA3C 802A13EC 00021040 */  sll       $v0, $v0, 1
/* 71EA40 802A13F0 00822023 */  subu      $a0, $a0, $v0
/* 71EA44 802A13F4 8FA80060 */  lw        $t0, 0x60($sp)
/* 71EA48 802A13F8 3084FFFF */  andi      $a0, $a0, 0xffff
/* 71EA4C 802A13FC 080A85BF */  j         .L802A16FC
/* 71EA50 802A1400 AD040074 */   sw       $a0, 0x74($t0)
.L802A1404:
/* 71EA54 802A1404 C7C00000 */  lwc1      $f0, ($fp)
/* 71EA58 802A1408 3C0140C0 */  lui       $at, 0x40c0
/* 71EA5C 802A140C 44811000 */  mtc1      $at, $f2
/* 71EA60 802A1410 00000000 */  nop
/* 71EA64 802A1414 46020000 */  add.s     $f0, $f0, $f2
/* 71EA68 802A1418 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 71EA6C 802A141C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 71EA70 802A1420 E7C00000 */  swc1      $f0, ($fp)
/* 71EA74 802A1424 94430134 */  lhu       $v1, 0x134($v0)
/* 71EA78 802A1428 3C02AAAA */  lui       $v0, 0xaaaa
/* 71EA7C 802A142C 3442AAAB */  ori       $v0, $v0, 0xaaab
/* 71EA80 802A1430 00620019 */  multu     $v1, $v0
/* 71EA84 802A1434 00004010 */  mfhi      $t0
/* 71EA88 802A1438 00082042 */  srl       $a0, $t0, 1
/* 71EA8C 802A143C 00041040 */  sll       $v0, $a0, 1
/* 71EA90 802A1440 00441021 */  addu      $v0, $v0, $a0
/* 71EA94 802A1444 00621823 */  subu      $v1, $v1, $v0
/* 71EA98 802A1448 3063FFFF */  andi      $v1, $v1, 0xffff
/* 71EA9C 802A144C 14600011 */  bnez      $v1, .L802A1494
/* 71EAA0 802A1450 0000A82D */   daddu    $s5, $zero, $zero
/* 71EAA4 802A1454 8FA80060 */  lw        $t0, 0x60($sp)
/* 71EAA8 802A1458 3C026666 */  lui       $v0, 0x6666
/* 71EAAC 802A145C 8D040074 */  lw        $a0, 0x74($t0)
/* 71EAB0 802A1460 34426667 */  ori       $v0, $v0, 0x6667
/* 71EAB4 802A1464 24840001 */  addiu     $a0, $a0, 1
/* 71EAB8 802A1468 00820018 */  mult      $a0, $v0
/* 71EABC 802A146C 000417C3 */  sra       $v0, $a0, 0x1f
/* 71EAC0 802A1470 00004010 */  mfhi      $t0
/* 71EAC4 802A1474 00081883 */  sra       $v1, $t0, 2
/* 71EAC8 802A1478 00621823 */  subu      $v1, $v1, $v0
/* 71EACC 802A147C 00031080 */  sll       $v0, $v1, 2
/* 71EAD0 802A1480 00431021 */  addu      $v0, $v0, $v1
/* 71EAD4 802A1484 00021040 */  sll       $v0, $v0, 1
/* 71EAD8 802A1488 8FA80060 */  lw        $t0, 0x60($sp)
/* 71EADC 802A148C 00822023 */  subu      $a0, $a0, $v0
/* 71EAE0 802A1490 AD040074 */  sw        $a0, 0x74($t0)
.L802A1494:
/* 71EAE4 802A1494 0000882D */  daddu     $s1, $zero, $zero
/* 71EAE8 802A1498 3C014220 */  lui       $at, 0x4220
/* 71EAEC 802A149C 4481D000 */  mtc1      $at, $f26
/* 71EAF0 802A14A0 24140008 */  addiu     $s4, $zero, 8
/* 71EAF4 802A14A4 24130004 */  addiu     $s3, $zero, 4
/* 71EAF8 802A14A8 3C16802A */  lui       $s6, %hi(D_802A3E88_7214D8)
/* 71EAFC 802A14AC 26D63E88 */  addiu     $s6, $s6, %lo(D_802A3E88_7214D8)
/* 71EB00 802A14B0 02C0902D */  daddu     $s2, $s6, $zero
/* 71EB04 802A14B4 3C10802A */  lui       $s0, %hi(D_802A3F58)
/* 71EB08 802A14B8 26103F58 */  addiu     $s0, $s0, %lo(D_802A3F58)
.L802A14BC:
/* 71EB0C 802A14BC 02761021 */  addu      $v0, $s3, $s6
/* 71EB10 802A14C0 C4540000 */  lwc1      $f20, ($v0)
/* 71EB14 802A14C4 4680A520 */  cvt.s.w   $f20, $f20
/* 71EB18 802A14C8 4600A10D */  trunc.w.s $f4, $f20
/* 71EB1C 802A14CC 44062000 */  mfc1      $a2, $f4
/* 71EB20 802A14D0 C6400000 */  lwc1      $f0, ($s2)
/* 71EB24 802A14D4 46800020 */  cvt.s.w   $f0, $f0
/* 71EB28 802A14D8 C7C20000 */  lwc1      $f2, ($fp)
/* 71EB2C 802A14DC 02961021 */  addu      $v0, $s4, $s6
/* 71EB30 802A14E0 46020580 */  add.s     $f22, $f0, $f2
/* 71EB34 802A14E4 C7C20008 */  lwc1      $f2, 8($fp)
/* 71EB38 802A14E8 C4400000 */  lwc1      $f0, ($v0)
/* 71EB3C 802A14EC 46800020 */  cvt.s.w   $f0, $f0
/* 71EB40 802A14F0 46020600 */  add.s     $f24, $f0, $f2
/* 71EB44 802A14F4 8E040000 */  lw        $a0, ($s0)
/* 71EB48 802A14F8 4600B10D */  trunc.w.s $f4, $f22
/* 71EB4C 802A14FC 44052000 */  mfc1      $a1, $f4
/* 71EB50 802A1500 4600C10D */  trunc.w.s $f4, $f24
/* 71EB54 802A1504 44072000 */  mfc1      $a3, $f4
/* 71EB58 802A1508 0C0B50D9 */  jal       func_802D4364
/* 71EB5C 802A150C 00000000 */   nop
/* 71EB60 802A1510 56A00038 */  bnel      $s5, $zero, .L802A15F4
/* 71EB64 802A1514 2694000C */   addiu    $s4, $s4, 0xc
/* 71EB68 802A1518 8FA80060 */  lw        $t0, 0x60($sp)
/* 71EB6C 802A151C 8D020074 */  lw        $v0, 0x74($t0)
/* 71EB70 802A1520 54510034 */  bnel      $v0, $s1, .L802A15F4
/* 71EB74 802A1524 2694000C */   addiu    $s4, $s4, 0xc
/* 71EB78 802A1528 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 71EB7C 802A152C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 71EB80 802A1530 94440134 */  lhu       $a0, 0x134($v0)
/* 71EB84 802A1534 3C02CCCC */  lui       $v0, 0xcccc
/* 71EB88 802A1538 3442CCCD */  ori       $v0, $v0, 0xcccd
/* 71EB8C 802A153C 00820019 */  multu     $a0, $v0
/* 71EB90 802A1540 00004010 */  mfhi      $t0
/* 71EB94 802A1544 00081882 */  srl       $v1, $t0, 2
/* 71EB98 802A1548 00031080 */  sll       $v0, $v1, 2
/* 71EB9C 802A154C 00431021 */  addu      $v0, $v0, $v1
/* 71EBA0 802A1550 00822023 */  subu      $a0, $a0, $v0
/* 71EBA4 802A1554 3084FFFF */  andi      $a0, $a0, 0xffff
/* 71EBA8 802A1558 54800026 */  bnel      $a0, $zero, .L802A15F4
/* 71EBAC 802A155C 2694000C */   addiu    $s4, $s4, 0xc
/* 71EBB0 802A1560 44800000 */  mtc1      $zero, $f0
/* 71EBB4 802A1564 00000000 */  nop
/* 71EBB8 802A1568 4616003C */  c.lt.s    $f0, $f22
/* 71EBBC 802A156C 00000000 */  nop
/* 71EBC0 802A1570 45000013 */  bc1f      .L802A15C0
/* 71EBC4 802A1574 00000000 */   nop
/* 71EBC8 802A1578 3C0142C8 */  lui       $at, 0x42c8
/* 71EBCC 802A157C 44810000 */  mtc1      $at, $f0
/* 71EBD0 802A1580 00000000 */  nop
/* 71EBD4 802A1584 4616003C */  c.lt.s    $f0, $f22
/* 71EBD8 802A1588 00000000 */  nop
/* 71EBDC 802A158C 45000005 */  bc1f      .L802A15A4
/* 71EBE0 802A1590 4600B506 */   mov.s    $f20, $f22
/* 71EBE4 802A1594 3C014248 */  lui       $at, 0x4248
/* 71EBE8 802A1598 44810000 */  mtc1      $at, $f0
/* 71EBEC 802A159C 00000000 */  nop
/* 71EBF0 802A15A0 4600A501 */  sub.s     $f20, $f20, $f0
.L802A15A4:
/* 71EBF4 802A15A4 4600A10D */  trunc.w.s $f4, $f20
/* 71EBF8 802A15A8 44042000 */  mfc1      $a0, $f4
/* 71EBFC 802A15AC 0C00A67F */  jal       rand_int
/* 71EC00 802A15B0 00000000 */   nop
/* 71EC04 802A15B4 4482A000 */  mtc1      $v0, $f20
/* 71EC08 802A15B8 00000000 */  nop
/* 71EC0C 802A15BC 4680A520 */  cvt.s.w   $f20, $f20
.L802A15C0:
/* 71EC10 802A15C0 4616D03C */  c.lt.s    $f26, $f22
/* 71EC14 802A15C4 00000000 */  nop
/* 71EC18 802A15C8 45000003 */  bc1f      .L802A15D8
/* 71EC1C 802A15CC 24040003 */   addiu    $a0, $zero, 3
/* 71EC20 802A15D0 461AB001 */  sub.s     $f0, $f22, $f26
/* 71EC24 802A15D4 46000587 */  neg.s     $f22, $f0
.L802A15D8:
/* 71EC28 802A15D8 4405B000 */  mfc1      $a1, $f22
/* 71EC2C 802A15DC 4406A000 */  mfc1      $a2, $f20
/* 71EC30 802A15E0 4407C000 */  mfc1      $a3, $f24
/* 71EC34 802A15E4 24150001 */  addiu     $s5, $zero, 1
/* 71EC38 802A15E8 0C01BEB4 */  jal       fx_walk_large
/* 71EC3C 802A15EC AFA00010 */   sw       $zero, 0x10($sp)
/* 71EC40 802A15F0 2694000C */  addiu     $s4, $s4, 0xc
.L802A15F4:
/* 71EC44 802A15F4 2673000C */  addiu     $s3, $s3, 0xc
/* 71EC48 802A15F8 2652000C */  addiu     $s2, $s2, 0xc
/* 71EC4C 802A15FC 26310001 */  addiu     $s1, $s1, 1
/* 71EC50 802A1600 2A22000A */  slti      $v0, $s1, 0xa
/* 71EC54 802A1604 1440FFAD */  bnez      $v0, .L802A14BC
/* 71EC58 802A1608 26100004 */   addiu    $s0, $s0, 4
/* 71EC5C 802A160C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 71EC60 802A1610 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 71EC64 802A1614 94420134 */  lhu       $v0, 0x134($v0)
/* 71EC68 802A1618 30420001 */  andi      $v0, $v0, 1
/* 71EC6C 802A161C 10400020 */  beqz      $v0, .L802A16A0
/* 71EC70 802A1620 00000000 */   nop
/* 71EC74 802A1624 0C00A67F */  jal       rand_int
/* 71EC78 802A1628 24040009 */   addiu    $a0, $zero, 9
/* 71EC7C 802A162C 00021840 */  sll       $v1, $v0, 1
/* 71EC80 802A1630 00621821 */  addu      $v1, $v1, $v0
/* 71EC84 802A1634 24620001 */  addiu     $v0, $v1, 1
/* 71EC88 802A1638 00021080 */  sll       $v0, $v0, 2
/* 71EC8C 802A163C 3C01802A */  lui       $at, %hi(D_802A3E88_7214D8)
/* 71EC90 802A1640 00220821 */  addu      $at, $at, $v0
/* 71EC94 802A1644 C4343E88 */  lwc1      $f20, %lo(D_802A3E88_7214D8)($at)
/* 71EC98 802A1648 4680A520 */  cvt.s.w   $f20, $f20
/* 71EC9C 802A164C 00031080 */  sll       $v0, $v1, 2
/* 71ECA0 802A1650 3C01802A */  lui       $at, %hi(D_802A3E88_7214D8)
/* 71ECA4 802A1654 00220821 */  addu      $at, $at, $v0
/* 71ECA8 802A1658 C4203E88 */  lwc1      $f0, %lo(D_802A3E88_7214D8)($at)
/* 71ECAC 802A165C 46800020 */  cvt.s.w   $f0, $f0
/* 71ECB0 802A1660 C7C20000 */  lwc1      $f2, ($fp)
/* 71ECB4 802A1664 24630002 */  addiu     $v1, $v1, 2
/* 71ECB8 802A1668 46020000 */  add.s     $f0, $f0, $f2
/* 71ECBC 802A166C 00031880 */  sll       $v1, $v1, 2
/* 71ECC0 802A1670 C7C20008 */  lwc1      $f2, 8($fp)
/* 71ECC4 802A1674 44050000 */  mfc1      $a1, $f0
/* 71ECC8 802A1678 3C01802A */  lui       $at, %hi(D_802A3E88_7214D8)
/* 71ECCC 802A167C 00230821 */  addu      $at, $at, $v1
/* 71ECD0 802A1680 C4203E88 */  lwc1      $f0, %lo(D_802A3E88_7214D8)($at)
/* 71ECD4 802A1684 46800020 */  cvt.s.w   $f0, $f0
/* 71ECD8 802A1688 46020000 */  add.s     $f0, $f0, $f2
/* 71ECDC 802A168C 4406A000 */  mfc1      $a2, $f20
/* 71ECE0 802A1690 44070000 */  mfc1      $a3, $f0
/* 71ECE4 802A1694 24040002 */  addiu     $a0, $zero, 2
/* 71ECE8 802A1698 0C01BEB4 */  jal       fx_walk_large
/* 71ECEC 802A169C AFA00010 */   sw       $zero, 0x10($sp)
.L802A16A0:
/* 71ECF0 802A16A0 C7C20000 */  lwc1      $f2, ($fp)
/* 71ECF4 802A16A4 3C0143A0 */  lui       $at, 0x43a0
/* 71ECF8 802A16A8 44810000 */  mtc1      $at, $f0
/* 71ECFC 802A16AC 00000000 */  nop
/* 71ED00 802A16B0 4602003E */  c.le.s    $f0, $f2
/* 71ED04 802A16B4 00000000 */  nop
/* 71ED08 802A16B8 45000010 */  bc1f      .L802A16FC
/* 71ED0C 802A16BC 24020002 */   addiu    $v0, $zero, 2
/* 71ED10 802A16C0 8FA80060 */  lw        $t0, 0x60($sp)
/* 71ED14 802A16C4 080A85BF */  j         .L802A16FC
/* 71ED18 802A16C8 AD020070 */   sw       $v0, 0x70($t0)
.L802A16CC:
/* 71ED1C 802A16CC 0000882D */  daddu     $s1, $zero, $zero
/* 71ED20 802A16D0 3C10802A */  lui       $s0, %hi(D_802A3F58)
/* 71ED24 802A16D4 26103F58 */  addiu     $s0, $s0, %lo(D_802A3F58)
.L802A16D8:
/* 71ED28 802A16D8 8E040000 */  lw        $a0, ($s0)
/* 71ED2C 802A16DC 26100004 */  addiu     $s0, $s0, 4
/* 71ED30 802A16E0 0C0B50FD */  jal       func_802D43F4
/* 71ED34 802A16E4 26310001 */   addiu    $s1, $s1, 1
/* 71ED38 802A16E8 2A22000A */  slti      $v0, $s1, 0xa
/* 71ED3C 802A16EC 1440FFFA */  bnez      $v0, .L802A16D8
/* 71ED40 802A16F0 24020002 */   addiu    $v0, $zero, 2
/* 71ED44 802A16F4 080A85C0 */  j         .L802A1700
/* 71ED48 802A16F8 00000000 */   nop
.L802A16FC:
/* 71ED4C 802A16FC 0000102D */  daddu     $v0, $zero, $zero
.L802A1700:
/* 71ED50 802A1700 8FBF003C */  lw        $ra, 0x3c($sp)
/* 71ED54 802A1704 8FBE0038 */  lw        $fp, 0x38($sp)
/* 71ED58 802A1708 8FB70034 */  lw        $s7, 0x34($sp)
/* 71ED5C 802A170C 8FB60030 */  lw        $s6, 0x30($sp)
/* 71ED60 802A1710 8FB5002C */  lw        $s5, 0x2c($sp)
/* 71ED64 802A1714 8FB40028 */  lw        $s4, 0x28($sp)
/* 71ED68 802A1718 8FB30024 */  lw        $s3, 0x24($sp)
/* 71ED6C 802A171C 8FB20020 */  lw        $s2, 0x20($sp)
/* 71ED70 802A1720 8FB1001C */  lw        $s1, 0x1c($sp)
/* 71ED74 802A1724 8FB00018 */  lw        $s0, 0x18($sp)
/* 71ED78 802A1728 D7BA0058 */  ldc1      $f26, 0x58($sp)
/* 71ED7C 802A172C D7B80050 */  ldc1      $f24, 0x50($sp)
/* 71ED80 802A1730 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 71ED84 802A1734 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 71ED88 802A1738 03E00008 */  jr        $ra
/* 71ED8C 802A173C 27BD0060 */   addiu    $sp, $sp, 0x60
