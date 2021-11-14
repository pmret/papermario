.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_80150FB0
.word L8013AB0C_D120C, L8013AB5C_D125C, L8013AB70_D1270, L8013AB0C_D120C, L8013AC14_D1314, L8013ABDC_D12DC, L8013AC14_D1314, L8013AC14_D1314, L8013AC14_D1314, L8013AC14_D1314, L8013AC14_D1314, L8013AC14_D1314, L8013AC14_D1314, L8013AC14_D1314, L8013AC14_D1314, L8013ABB0_D12B0, L8013ABB0_D12B0, L8013AB84_D1284

dlabel jtbl_80150FF8
.word L8013ACD8_D13D8, L8013ACE4_D13E4, L8013AD08_D1408, L8013AD30_D1430, L8013AD30_D1430, L8013AD30_D1430, L8013ADAC_D14AC, L8013ADAC_D14AC, L8013ADE4_D14E4, L8013AE58_D1558, L8013AECC_D15CC, L8013AED8_D15D8, L8013AEE4_D15E4, L8013AEE4_D15E4

dlabel D_80151030
.double 255.0

.section .text

glabel func_8013AA9C
/* D119C 8013AA9C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D11A0 8013AAA0 AFB00010 */  sw        $s0, 0x10($sp)
/* D11A4 8013AAA4 00C0802D */  daddu     $s0, $a2, $zero
/* D11A8 8013AAA8 00041140 */  sll       $v0, $a0, 5
/* D11AC 8013AAAC 00441023 */  subu      $v0, $v0, $a0
/* D11B0 8013AAB0 3C038015 */  lui       $v1, %hi(D_80156954)
/* D11B4 8013AAB4 8C636954 */  lw        $v1, %lo(D_80156954)($v1)
/* D11B8 8013AAB8 8FA80030 */  lw        $t0, 0x30($sp)
/* D11BC 8013AABC 8FA60034 */  lw        $a2, 0x34($sp)
/* D11C0 8013AAC0 00021080 */  sll       $v0, $v0, 2
/* D11C4 8013AAC4 AFBF001C */  sw        $ra, 0x1c($sp)
/* D11C8 8013AAC8 AFB20018 */  sw        $s2, 0x18($sp)
/* D11CC 8013AACC AFB10014 */  sw        $s1, 0x14($sp)
/* D11D0 8013AAD0 00628821 */  addu      $s1, $v1, $v0
/* D11D4 8013AAD4 8E220014 */  lw        $v0, 0x14($s1)
/* D11D8 8013AAD8 8FB20038 */  lw        $s2, 0x38($sp)
/* D11DC 8013AADC 30420001 */  andi      $v0, $v0, 1
/* D11E0 8013AAE0 10400109 */  beqz      $v0, .L8013AF08
/* D11E4 8013AAE4 2C82005A */   sltiu    $v0, $a0, 0x5a
/* D11E8 8013AAE8 10400107 */  beqz      $v0, .L8013AF08
/* D11EC 8013AAEC 2CA20012 */   sltiu    $v0, $a1, 0x12
/* D11F0 8013AAF0 10400048 */  beqz      $v0, L8013AC14_D1314
/* D11F4 8013AAF4 00051080 */   sll      $v0, $a1, 2
/* D11F8 8013AAF8 3C018015 */  lui       $at, %hi(jtbl_80150FB0)
/* D11FC 8013AAFC 00220821 */  addu      $at, $at, $v0
/* D1200 8013AB00 8C220FB0 */  lw        $v0, %lo(jtbl_80150FB0)($at)
/* D1204 8013AB04 00400008 */  jr        $v0
/* D1208 8013AB08 00000000 */   nop
dlabel L8013AB0C_D120C
/* D120C 8013AB0C 8E300014 */  lw        $s0, 0x14($s1)
/* D1210 8013AB10 0C04EA4F */  jal       func_8013A93C
/* D1214 8013AB14 0220202D */   daddu    $a0, $s1, $zero
/* D1218 8013AB18 0C04EA7A */  jal       func_8013A9E8
/* D121C 8013AB1C 0220202D */   daddu    $a0, $s1, $zero
/* D1220 8013AB20 2402FFFF */  addiu     $v0, $zero, -1
/* D1224 8013AB24 A2200005 */  sb        $zero, 5($s1)
/* D1228 8013AB28 A2200006 */  sb        $zero, 6($s1)
/* D122C 8013AB2C A2200001 */  sb        $zero, 1($s1)
/* D1230 8013AB30 A2200002 */  sb        $zero, 2($s1)
/* D1234 8013AB34 AE22001C */  sw        $v0, 0x1c($s1)
/* D1238 8013AB38 AE22002C */  sw        $v0, 0x2c($s1)
/* D123C 8013AB3C AE300014 */  sw        $s0, 0x14($s1)
/* D1240 8013AB40 0200182D */  daddu     $v1, $s0, $zero
/* D1244 8013AB44 30620001 */  andi      $v0, $v1, 1
/* D1248 8013AB48 12400002 */  beqz      $s2, .L8013AB54
/* D124C 8013AB4C AE220014 */   sw       $v0, 0x14($s1)
/* D1250 8013AB50 00521025 */  or        $v0, $v0, $s2
.L8013AB54:
/* D1254 8013AB54 0804EBC2 */  j         .L8013AF08
/* D1258 8013AB58 AE220014 */   sw       $v0, 0x14($s1)
dlabel L8013AB5C_D125C
/* D125C 8013AB5C 2402FFFF */  addiu     $v0, $zero, -1
/* D1260 8013AB60 A2200005 */  sb        $zero, 5($s1)
/* D1264 8013AB64 A2200002 */  sb        $zero, 2($s1)
/* D1268 8013AB68 0804EBC2 */  j         .L8013AF08
/* D126C 8013AB6C AE22001C */   sw       $v0, 0x1c($s1)
dlabel L8013AB70_D1270
/* D1270 8013AB70 2402FFFF */  addiu     $v0, $zero, -1
/* D1274 8013AB74 A2200006 */  sb        $zero, 6($s1)
/* D1278 8013AB78 A2200001 */  sb        $zero, 1($s1)
/* D127C 8013AB7C 0804EBC2 */  j         .L8013AF08
/* D1280 8013AB80 AE22002C */   sw       $v0, 0x2c($s1)
dlabel L8013AB84_D1284
/* D1284 8013AB84 8E24005C */  lw        $a0, 0x5c($s1)
/* D1288 8013AB88 10800004 */  beqz      $a0, .L8013AB9C
/* D128C 8013AB8C 00101080 */   sll      $v0, $s0, 2
/* D1290 8013AB90 0C00AB4B */  jal       heap_free
/* D1294 8013AB94 00000000 */   nop
/* D1298 8013AB98 00101080 */  sll       $v0, $s0, 2
.L8013AB9C:
/* D129C 8013AB9C A6220060 */  sh        $v0, 0x60($s1)
/* D12A0 8013ABA0 0C00AB39 */  jal       heap_malloc
/* D12A4 8013ABA4 3044FFFF */   andi     $a0, $v0, 0xffff
/* D12A8 8013ABA8 0804EBC2 */  j         .L8013AF08
/* D12AC 8013ABAC AE22005C */   sw       $v0, 0x5c($s1)
dlabel L8013ABB0_D12B0
/* D12B0 8013ABB0 82220006 */  lb        $v0, 6($s1)
/* D12B4 8013ABB4 14A20021 */  bne       $a1, $v0, .L8013AC3C
/* D12B8 8013ABB8 24030005 */   addiu    $v1, $zero, 5
/* D12BC 8013ABBC 8E22002C */  lw        $v0, 0x2c($s1)
/* D12C0 8013ABC0 1602001E */  bne       $s0, $v0, .L8013AC3C
/* D12C4 8013ABC4 00000000 */   nop
/* D12C8 8013ABC8 8E220030 */  lw        $v0, 0x30($s1)
/* D12CC 8013ABCC 10E200CE */  beq       $a3, $v0, .L8013AF08
/* D12D0 8013ABD0 00000000 */   nop
/* D12D4 8013ABD4 0804EB0F */  j         .L8013AC3C
/* D12D8 8013ABD8 00000000 */   nop
dlabel L8013ABDC_D12DC
/* D12DC 8013ABDC 82220005 */  lb        $v0, 5($s1)
/* D12E0 8013ABE0 14450016 */  bne       $v0, $a1, .L8013AC3C
/* D12E4 8013ABE4 24030005 */   addiu    $v1, $zero, 5
/* D12E8 8013ABE8 8E22001C */  lw        $v0, 0x1c($s1)
/* D12EC 8013ABEC 14500013 */  bne       $v0, $s0, .L8013AC3C
/* D12F0 8013ABF0 00000000 */   nop
/* D12F4 8013ABF4 8E220020 */  lw        $v0, 0x20($s1)
/* D12F8 8013ABF8 14470010 */  bne       $v0, $a3, .L8013AC3C
/* D12FC 8013ABFC 00000000 */   nop
/* D1300 8013AC00 8E220024 */  lw        $v0, 0x24($s1)
/* D1304 8013AC04 104800C0 */  beq       $v0, $t0, .L8013AF08
/* D1308 8013AC08 00000000 */   nop
/* D130C 8013AC0C 0804EB0F */  j         .L8013AC3C
/* D1310 8013AC10 00000000 */   nop
dlabel L8013AC14_D1314
/* D1314 8013AC14 2403000D */  addiu     $v1, $zero, 0xd
/* D1318 8013AC18 50A30008 */  beql      $a1, $v1, .L8013AC3C
/* D131C 8013AC1C 24030005 */   addiu    $v1, $zero, 5
/* D1320 8013AC20 82220006 */  lb        $v0, 6($s1)
/* D1324 8013AC24 14430005 */  bne       $v0, $v1, .L8013AC3C
/* D1328 8013AC28 24030005 */   addiu    $v1, $zero, 5
/* D132C 8013AC2C 24020001 */  addiu     $v0, $zero, 1
/* D1330 8013AC30 A2200001 */  sb        $zero, 1($s1)
/* D1334 8013AC34 A2220003 */  sb        $v0, 3($s1)
/* D1338 8013AC38 A2220004 */  sb        $v0, 4($s1)
.L8013AC3C:
/* D133C 8013AC3C 10A30005 */  beq       $a1, $v1, .L8013AC54
/* D1340 8013AC40 24A2FFFC */   addiu    $v0, $a1, -4
/* D1344 8013AC44 82220005 */  lb        $v0, 5($s1)
/* D1348 8013AC48 50430001 */  beql      $v0, $v1, .L8013AC50
/* D134C 8013AC4C A2200005 */   sb       $zero, 5($s1)
.L8013AC50:
/* D1350 8013AC50 24A2FFFC */  addiu     $v0, $a1, -4
.L8013AC54:
/* D1354 8013AC54 2C420002 */  sltiu     $v0, $v0, 2
/* D1358 8013AC58 10400007 */  beqz      $v0, .L8013AC78
/* D135C 8013AC5C 24A2FFFA */   addiu    $v0, $a1, -6
/* D1360 8013AC60 A2250005 */  sb        $a1, 5($s1)
/* D1364 8013AC64 AE30001C */  sw        $s0, 0x1c($s1)
/* D1368 8013AC68 AE270020 */  sw        $a3, 0x20($s1)
/* D136C 8013AC6C AE280024 */  sw        $t0, 0x24($s1)
/* D1370 8013AC70 0804EB26 */  j         .L8013AC98
/* D1374 8013AC74 AE260028 */   sw       $a2, 0x28($s1)
.L8013AC78:
/* D1378 8013AC78 2C42000B */  sltiu     $v0, $v0, 0xb
/* D137C 8013AC7C 10400006 */  beqz      $v0, .L8013AC98
/* D1380 8013AC80 00000000 */   nop
/* D1384 8013AC84 A2250006 */  sb        $a1, 6($s1)
/* D1388 8013AC88 AE30002C */  sw        $s0, 0x2c($s1)
/* D138C 8013AC8C AE270030 */  sw        $a3, 0x30($s1)
/* D1390 8013AC90 AE280034 */  sw        $t0, 0x34($s1)
/* D1394 8013AC94 AE260038 */  sw        $a2, 0x38($s1)
.L8013AC98:
/* D1398 8013AC98 8E220014 */  lw        $v0, 0x14($s1)
/* D139C 8013AC9C 30420001 */  andi      $v0, $v0, 1
/* D13A0 8013ACA0 12400003 */  beqz      $s2, .L8013ACB0
/* D13A4 8013ACA4 AE220014 */   sw       $v0, 0x14($s1)
/* D13A8 8013ACA8 00521025 */  or        $v0, $v0, $s2
/* D13AC 8013ACAC AE220014 */  sw        $v0, 0x14($s1)
.L8013ACB0:
/* D13B0 8013ACB0 24A5FFFD */  addiu     $a1, $a1, -3
/* D13B4 8013ACB4 2CA2000E */  sltiu     $v0, $a1, 0xe
/* D13B8 8013ACB8 10400093 */  beqz      $v0, .L8013AF08
/* D13BC 8013ACBC A2200001 */   sb       $zero, 1($s1)
/* D13C0 8013ACC0 00051080 */  sll       $v0, $a1, 2
/* D13C4 8013ACC4 3C018015 */  lui       $at, %hi(jtbl_80150FF8)
/* D13C8 8013ACC8 00220821 */  addu      $at, $at, $v0
/* D13CC 8013ACCC 8C220FF8 */  lw        $v0, %lo(jtbl_80150FF8)($at)
/* D13D0 8013ACD0 00400008 */  jr        $v0
/* D13D4 8013ACD4 00000000 */   nop
dlabel L8013ACD8_D13D8
/* D13D8 8013ACD8 A2200001 */  sb        $zero, 1($s1)
/* D13DC 8013ACDC 0804EBC2 */  j         .L8013AF08
/* D13E0 8013ACE0 A2200002 */   sb       $zero, 2($s1)
dlabel L8013ACE4_D13E4
/* D13E4 8013ACE4 0220202D */  daddu     $a0, $s1, $zero
/* D13E8 8013ACE8 24020004 */  addiu     $v0, $zero, 4
/* D13EC 8013ACEC A0820003 */  sb        $v0, 3($a0)
/* D13F0 8013ACF0 A0820004 */  sb        $v0, 4($a0)
/* D13F4 8013ACF4 24020001 */  addiu     $v0, $zero, 1
/* D13F8 8013ACF8 0C04FB92 */  jal       func_8013EE48
/* D13FC 8013ACFC A0820001 */   sb       $v0, 1($a0)
/* D1400 8013AD00 0804EBC2 */  j         .L8013AF08
/* D1404 8013AD04 00000000 */   nop
dlabel L8013AD08_D1408
/* D1408 8013AD08 8E230014 */  lw        $v1, 0x14($s1)
/* D140C 8013AD0C 24020002 */  addiu     $v0, $zero, 2
/* D1410 8013AD10 A2220001 */  sb        $v0, 1($s1)
/* D1414 8013AD14 2402000B */  addiu     $v0, $zero, 0xb
/* D1418 8013AD18 A2220002 */  sb        $v0, 2($s1)
/* D141C 8013AD1C AE20003C */  sw        $zero, 0x3c($s1)
/* D1420 8013AD20 AE200040 */  sw        $zero, 0x40($s1)
/* D1424 8013AD24 34630200 */  ori       $v1, $v1, 0x200
/* D1428 8013AD28 0804EBC2 */  j         .L8013AF08
/* D142C 8013AD2C AE230014 */   sw       $v1, 0x14($s1)
dlabel L8013AD30_D1430
/* D1430 8013AD30 2A0200FF */  slti      $v0, $s0, 0xff
/* D1434 8013AD34 1440000B */  bnez      $v0, .L8013AD64
/* D1438 8013AD38 28C200FF */   slti     $v0, $a2, 0xff
/* D143C 8013AD3C 28E200FF */  slti      $v0, $a3, 0xff
/* D1440 8013AD40 14400008 */  bnez      $v0, .L8013AD64
/* D1444 8013AD44 28C200FF */   slti     $v0, $a2, 0xff
/* D1448 8013AD48 290200FF */  slti      $v0, $t0, 0xff
/* D144C 8013AD4C 14400005 */  bnez      $v0, .L8013AD64
/* D1450 8013AD50 28C200FF */   slti     $v0, $a2, 0xff
/* D1454 8013AD54 14400008 */  bnez      $v0, .L8013AD78
/* D1458 8013AD58 2A0200FF */   slti     $v0, $s0, 0xff
/* D145C 8013AD5C 0804EBC2 */  j         .L8013AF08
/* D1460 8013AD60 A2200002 */   sb       $zero, 2($s1)
.L8013AD64:
/* D1464 8013AD64 14400004 */  bnez      $v0, .L8013AD78
/* D1468 8013AD68 2A0200FF */   slti     $v0, $s0, 0xff
/* D146C 8013AD6C 24020001 */  addiu     $v0, $zero, 1
/* D1470 8013AD70 0804EBC2 */  j         .L8013AF08
/* D1474 8013AD74 A2220002 */   sb       $v0, 2($s1)
.L8013AD78:
/* D1478 8013AD78 1440000A */  bnez      $v0, .L8013ADA4
/* D147C 8013AD7C 24020003 */   addiu    $v0, $zero, 3
/* D1480 8013AD80 28E200FF */  slti      $v0, $a3, 0xff
/* D1484 8013AD84 14400007 */  bnez      $v0, .L8013ADA4
/* D1488 8013AD88 24020003 */   addiu    $v0, $zero, 3
/* D148C 8013AD8C 290200FF */  slti      $v0, $t0, 0xff
/* D1490 8013AD90 14400004 */  bnez      $v0, .L8013ADA4
/* D1494 8013AD94 24020003 */   addiu    $v0, $zero, 3
/* D1498 8013AD98 24020002 */  addiu     $v0, $zero, 2
/* D149C 8013AD9C 0804EBC2 */  j         .L8013AF08
/* D14A0 8013ADA0 A2220002 */   sb       $v0, 2($s1)
.L8013ADA4:
/* D14A4 8013ADA4 0804EBC2 */  j         .L8013AF08
/* D14A8 8013ADA8 A2220002 */   sb       $v0, 2($s1)
dlabel L8013ADAC_D14AC
/* D14AC 8013ADAC 3C018015 */  lui       $at, %hi(D_80151030)
/* D14B0 8013ADB0 D4221030 */  ldc1      $f2, %lo(D_80151030)($at)
/* D14B4 8013ADB4 44860000 */  mtc1      $a2, $f0
/* D14B8 8013ADB8 00000000 */  nop
/* D14BC 8013ADBC 46800021 */  cvt.d.w   $f0, $f0
/* D14C0 8013ADC0 46220032 */  c.eq.d    $f0, $f2
/* D14C4 8013ADC4 00000000 */  nop
/* D14C8 8013ADC8 45000003 */  bc1f      .L8013ADD8
/* D14CC 8013ADCC 24020004 */   addiu    $v0, $zero, 4
/* D14D0 8013ADD0 0804EBC2 */  j         .L8013AF08
/* D14D4 8013ADD4 A2220002 */   sb       $v0, 2($s1)
.L8013ADD8:
/* D14D8 8013ADD8 24020005 */  addiu     $v0, $zero, 5
/* D14DC 8013ADDC 0804EBC2 */  j         .L8013AF08
/* D14E0 8013ADE0 A2220002 */   sb       $v0, 2($s1)
dlabel L8013ADE4_D14E4
/* D14E4 8013ADE4 96220060 */  lhu       $v0, 0x60($s1)
/* D14E8 8013ADE8 0202102A */  slt       $v0, $s0, $v0
/* D14EC 8013ADEC 10400046 */  beqz      $v0, .L8013AF08
/* D14F0 8013ADF0 00072602 */   srl      $a0, $a3, 0x18
/* D14F4 8013ADF4 8E22005C */  lw        $v0, 0x5c($s1)
/* D14F8 8013ADF8 00101880 */  sll       $v1, $s0, 2
/* D14FC 8013ADFC 00621021 */  addu      $v0, $v1, $v0
/* D1500 8013AE00 A0440000 */  sb        $a0, ($v0)
/* D1504 8013AE04 8E22005C */  lw        $v0, 0x5c($s1)
/* D1508 8013AE08 00072402 */  srl       $a0, $a3, 0x10
/* D150C 8013AE0C 00621021 */  addu      $v0, $v1, $v0
/* D1510 8013AE10 A0440001 */  sb        $a0, 1($v0)
/* D1514 8013AE14 8E22005C */  lw        $v0, 0x5c($s1)
/* D1518 8013AE18 00072202 */  srl       $a0, $a3, 8
/* D151C 8013AE1C 00621021 */  addu      $v0, $v1, $v0
/* D1520 8013AE20 A0440002 */  sb        $a0, 2($v0)
/* D1524 8013AE24 8E22005C */  lw        $v0, 0x5c($s1)
/* D1528 8013AE28 00621821 */  addu      $v1, $v1, $v0
/* D152C 8013AE2C A0670003 */  sb        $a3, 3($v1)
/* D1530 8013AE30 30E300FF */  andi      $v1, $a3, 0xff
/* D1534 8013AE34 240200FF */  addiu     $v0, $zero, 0xff
/* D1538 8013AE38 14620004 */  bne       $v1, $v0, .L8013AE4C
/* D153C 8013AE3C A2200001 */   sb       $zero, 1($s1)
/* D1540 8013AE40 24020006 */  addiu     $v0, $zero, 6
/* D1544 8013AE44 0804EBC2 */  j         .L8013AF08
/* D1548 8013AE48 A2220002 */   sb       $v0, 2($s1)
.L8013AE4C:
/* D154C 8013AE4C 24020008 */  addiu     $v0, $zero, 8
/* D1550 8013AE50 0804EBC2 */  j         .L8013AF08
/* D1554 8013AE54 A2220002 */   sb       $v0, 2($s1)
dlabel L8013AE58_D1558
/* D1558 8013AE58 96220060 */  lhu       $v0, 0x60($s1)
/* D155C 8013AE5C 0202102A */  slt       $v0, $s0, $v0
/* D1560 8013AE60 10400029 */  beqz      $v0, .L8013AF08
/* D1564 8013AE64 00072602 */   srl      $a0, $a3, 0x18
/* D1568 8013AE68 8E22005C */  lw        $v0, 0x5c($s1)
/* D156C 8013AE6C 00101880 */  sll       $v1, $s0, 2
/* D1570 8013AE70 00621021 */  addu      $v0, $v1, $v0
/* D1574 8013AE74 A0440000 */  sb        $a0, ($v0)
/* D1578 8013AE78 8E22005C */  lw        $v0, 0x5c($s1)
/* D157C 8013AE7C 00072402 */  srl       $a0, $a3, 0x10
/* D1580 8013AE80 00621021 */  addu      $v0, $v1, $v0
/* D1584 8013AE84 A0440001 */  sb        $a0, 1($v0)
/* D1588 8013AE88 8E22005C */  lw        $v0, 0x5c($s1)
/* D158C 8013AE8C 00072202 */  srl       $a0, $a3, 8
/* D1590 8013AE90 00621021 */  addu      $v0, $v1, $v0
/* D1594 8013AE94 A0440002 */  sb        $a0, 2($v0)
/* D1598 8013AE98 8E22005C */  lw        $v0, 0x5c($s1)
/* D159C 8013AE9C 00621821 */  addu      $v1, $v1, $v0
/* D15A0 8013AEA0 A0670003 */  sb        $a3, 3($v1)
/* D15A4 8013AEA4 30E300FF */  andi      $v1, $a3, 0xff
/* D15A8 8013AEA8 240200FF */  addiu     $v0, $zero, 0xff
/* D15AC 8013AEAC 14620004 */  bne       $v1, $v0, .L8013AEC0
/* D15B0 8013AEB0 A2200001 */   sb       $zero, 1($s1)
/* D15B4 8013AEB4 24020009 */  addiu     $v0, $zero, 9
/* D15B8 8013AEB8 0804EBC2 */  j         .L8013AF08
/* D15BC 8013AEBC A2220002 */   sb       $v0, 2($s1)
.L8013AEC0:
/* D15C0 8013AEC0 2402000A */  addiu     $v0, $zero, 0xa
/* D15C4 8013AEC4 0804EBC2 */  j         .L8013AF08
/* D15C8 8013AEC8 A2220002 */   sb       $v0, 2($s1)
dlabel L8013AECC_D15CC
/* D15CC 8013AECC 2402000C */  addiu     $v0, $zero, 0xc
/* D15D0 8013AED0 0804EBC2 */  j         .L8013AF08
/* D15D4 8013AED4 A2220002 */   sb       $v0, 2($s1)
dlabel L8013AED8_D15D8
/* D15D8 8013AED8 2402000D */  addiu     $v0, $zero, 0xd
/* D15DC 8013AEDC 0804EBC2 */  j         .L8013AF08
/* D15E0 8013AEE0 A2220002 */   sb       $v0, 2($s1)
dlabel L8013AEE4_D15E4
/* D15E4 8013AEE4 24020004 */  addiu     $v0, $zero, 4
/* D15E8 8013AEE8 A2220001 */  sb        $v0, 1($s1)
/* D15EC 8013AEEC 28E200FF */  slti      $v0, $a3, 0xff
/* D15F0 8013AEF0 14400002 */  bnez      $v0, .L8013AEFC
/* D15F4 8013AEF4 2402000F */   addiu    $v0, $zero, 0xf
/* D15F8 8013AEF8 2402000E */  addiu     $v0, $zero, 0xe
.L8013AEFC:
/* D15FC 8013AEFC A2220002 */  sb        $v0, 2($s1)
/* D1600 8013AF00 AE20004C */  sw        $zero, 0x4c($s1)
/* D1604 8013AF04 AE200050 */  sw        $zero, 0x50($s1)
.L8013AF08:
/* D1608 8013AF08 8FBF001C */  lw        $ra, 0x1c($sp)
/* D160C 8013AF0C 8FB20018 */  lw        $s2, 0x18($sp)
/* D1610 8013AF10 8FB10014 */  lw        $s1, 0x14($sp)
/* D1614 8013AF14 8FB00010 */  lw        $s0, 0x10($sp)
/* D1618 8013AF18 03E00008 */  jr        $ra
/* D161C 8013AF1C 27BD0020 */   addiu    $sp, $sp, 0x20
