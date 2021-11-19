.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_80248370_C95F20
.double 90.0, 0.0

.section .text

glabel func_80240E2C_C8E9DC
/* C8E9DC 80240E2C 27BDFF70 */  addiu     $sp, $sp, -0x90
/* C8E9E0 80240E30 3C038025 */  lui       $v1, %hi(D_80248380)
/* C8E9E4 80240E34 8C638380 */  lw        $v1, %lo(D_80248380)($v1)
/* C8E9E8 80240E38 2402FFFF */  addiu     $v0, $zero, -1
/* C8E9EC 80240E3C AFBF005C */  sw        $ra, 0x5c($sp)
/* C8E9F0 80240E40 AFBE0058 */  sw        $fp, 0x58($sp)
/* C8E9F4 80240E44 AFB70054 */  sw        $s7, 0x54($sp)
/* C8E9F8 80240E48 AFB60050 */  sw        $s6, 0x50($sp)
/* C8E9FC 80240E4C AFB5004C */  sw        $s5, 0x4c($sp)
/* C8EA00 80240E50 AFB40048 */  sw        $s4, 0x48($sp)
/* C8EA04 80240E54 AFB30044 */  sw        $s3, 0x44($sp)
/* C8EA08 80240E58 AFB20040 */  sw        $s2, 0x40($sp)
/* C8EA0C 80240E5C AFB1003C */  sw        $s1, 0x3c($sp)
/* C8EA10 80240E60 AFB00038 */  sw        $s0, 0x38($sp)
/* C8EA14 80240E64 F7BE0088 */  sdc1      $f30, 0x88($sp)
/* C8EA18 80240E68 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* C8EA1C 80240E6C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* C8EA20 80240E70 F7B80070 */  sdc1      $f24, 0x70($sp)
/* C8EA24 80240E74 F7B60068 */  sdc1      $f22, 0x68($sp)
/* C8EA28 80240E78 1062013F */  beq       $v1, $v0, .L80241378
/* C8EA2C 80240E7C F7B40060 */   sdc1     $f20, 0x60($sp)
/* C8EA30 80240E80 1460005E */  bnez      $v1, .L80240FFC
/* C8EA34 80240E84 0000382D */   daddu    $a3, $zero, $zero
/* C8EA38 80240E88 00E0802D */  daddu     $s0, $a3, $zero
/* C8EA3C 80240E8C 3C0142B4 */  lui       $at, 0x42b4
/* C8EA40 80240E90 4481E000 */  mtc1      $at, $f28
/* C8EA44 80240E94 3C014334 */  lui       $at, 0x4334
/* C8EA48 80240E98 4481D000 */  mtc1      $at, $f26
/* C8EA4C 80240E9C 3C0143B4 */  lui       $at, 0x43b4
/* C8EA50 80240EA0 4481A000 */  mtc1      $at, $f20
/* C8EA54 80240EA4 3C01C334 */  lui       $at, 0xc334
/* C8EA58 80240EA8 4481B000 */  mtc1      $at, $f22
.L80240EAC:
/* C8EA5C 80240EAC 0000202D */  daddu     $a0, $zero, $zero
/* C8EA60 80240EB0 3C05FD05 */  lui       $a1, 0xfd05
/* C8EA64 80240EB4 34A50F80 */  ori       $a1, $a1, 0xf80
/* C8EA68 80240EB8 0C0B1EAF */  jal       evt_get_variable
/* C8EA6C 80240EBC AFA70030 */   sw       $a3, 0x30($sp)
/* C8EA70 80240EC0 00502021 */  addu      $a0, $v0, $s0
/* C8EA74 80240EC4 8FA70030 */  lw        $a3, 0x30($sp)
/* C8EA78 80240EC8 24020001 */  addiu     $v0, $zero, 1
/* C8EA7C 80240ECC 10E20011 */  beq       $a3, $v0, .L80240F14
/* C8EA80 80240ED0 28E20002 */   slti     $v0, $a3, 2
/* C8EA84 80240ED4 50400005 */  beql      $v0, $zero, .L80240EEC
/* C8EA88 80240ED8 24020002 */   addiu    $v0, $zero, 2
/* C8EA8C 80240EDC 10E00009 */  beqz      $a3, .L80240F04
/* C8EA90 80240EE0 00000000 */   nop
/* C8EA94 80240EE4 080904DE */  j         .L80241378
/* C8EA98 80240EE8 00000000 */   nop
.L80240EEC:
/* C8EA9C 80240EEC 10E2000B */  beq       $a3, $v0, .L80240F1C
/* C8EAA0 80240EF0 24020003 */   addiu    $v0, $zero, 3
/* C8EAA4 80240EF4 10E2000A */  beq       $a3, $v0, .L80240F20
/* C8EAA8 80240EF8 24140005 */   addiu    $s4, $zero, 5
/* C8EAAC 80240EFC 080904DE */  j         .L80241378
/* C8EAB0 80240F00 00000000 */   nop
.L80240F04:
/* C8EAB4 80240F04 3C014120 */  lui       $at, 0x4120
/* C8EAB8 80240F08 4481C000 */  mtc1      $at, $f24
/* C8EABC 80240F0C 080903CA */  j         .L80240F28
/* C8EAC0 80240F10 24140009 */   addiu    $s4, $zero, 9
.L80240F14:
/* C8EAC4 80240F14 080903C8 */  j         .L80240F20
/* C8EAC8 80240F18 24140007 */   addiu    $s4, $zero, 7
.L80240F1C:
/* C8EACC 80240F1C 24140007 */  addiu     $s4, $zero, 7
.L80240F20:
/* C8EAD0 80240F20 3C014100 */  lui       $at, 0x4100
/* C8EAD4 80240F24 4481C000 */  mtc1      $at, $f24
.L80240F28:
/* C8EAD8 80240F28 0000882D */  daddu     $s1, $zero, $zero
/* C8EADC 80240F2C AC940090 */  sw        $s4, 0x90($a0)
/* C8EAE0 80240F30 1A800027 */  blez      $s4, .L80240FD0
/* C8EAE4 80240F34 E4980094 */   swc1     $f24, 0x94($a0)
/* C8EAE8 80240F38 2686FFFF */  addiu     $a2, $s4, -1
/* C8EAEC 80240F3C 0080182D */  daddu     $v1, $a0, $zero
/* C8EAF0 80240F40 24050004 */  addiu     $a1, $zero, 4
/* C8EAF4 80240F44 3C013FE0 */  lui       $at, 0x3fe0
/* C8EAF8 80240F48 44814800 */  mtc1      $at, $f9
/* C8EAFC 80240F4C 44804000 */  mtc1      $zero, $f8
/* C8EB00 80240F50 3C018025 */  lui       $at, %hi(D_80248370_C95F20)
/* C8EB04 80240F54 D4268370 */  ldc1      $f6, %lo(D_80248370_C95F20)($at)
.L80240F58:
/* C8EB08 80240F58 16260004 */  bne       $s1, $a2, .L80240F6C
/* C8EB0C 80240F5C 00851021 */   addu     $v0, $a0, $a1
/* C8EB10 80240F60 C460006C */  lwc1      $f0, 0x6c($v1)
/* C8EB14 80240F64 080903EE */  j         .L80240FB8
/* C8EB18 80240F68 461C0000 */   add.s    $f0, $f0, $f28
.L80240F6C:
/* C8EB1C 80240F6C C460006C */  lwc1      $f0, 0x6c($v1)
/* C8EB20 80240F70 C444006C */  lwc1      $f4, 0x6c($v0)
/* C8EB24 80240F74 46002081 */  sub.s     $f2, $f4, $f0
/* C8EB28 80240F78 4602D03C */  c.lt.s    $f26, $f2
/* C8EB2C 80240F7C 00000000 */  nop
/* C8EB30 80240F80 45000003 */  bc1f      .L80240F90
/* C8EB34 80240F84 00000000 */   nop
/* C8EB38 80240F88 080903E8 */  j         .L80240FA0
/* C8EB3C 80240F8C 46140000 */   add.s    $f0, $f0, $f20
.L80240F90:
/* C8EB40 80240F90 4616103C */  c.lt.s    $f2, $f22
/* C8EB44 80240F94 00000000 */  nop
/* C8EB48 80240F98 45030001 */  bc1tl     .L80240FA0
/* C8EB4C 80240F9C 46142100 */   add.s    $f4, $f4, $f20
.L80240FA0:
/* C8EB50 80240FA0 46040000 */  add.s     $f0, $f0, $f4
/* C8EB54 80240FA4 46000021 */  cvt.d.s   $f0, $f0
/* C8EB58 80240FA8 46280002 */  mul.d     $f0, $f0, $f8
/* C8EB5C 80240FAC 00000000 */  nop
/* C8EB60 80240FB0 46260000 */  add.d     $f0, $f0, $f6
/* C8EB64 80240FB4 46200020 */  cvt.s.d   $f0, $f0
.L80240FB8:
/* C8EB68 80240FB8 E460006C */  swc1      $f0, 0x6c($v1)
/* C8EB6C 80240FBC 24630004 */  addiu     $v1, $v1, 4
/* C8EB70 80240FC0 26310001 */  addiu     $s1, $s1, 1
/* C8EB74 80240FC4 0234102A */  slt       $v0, $s1, $s4
/* C8EB78 80240FC8 1440FFE3 */  bnez      $v0, .L80240F58
/* C8EB7C 80240FCC 24A50004 */   addiu    $a1, $a1, 4
.L80240FD0:
/* C8EB80 80240FD0 0C0902C0 */  jal       func_80240B00_C8E6B0
/* C8EB84 80240FD4 AFA70030 */   sw       $a3, 0x30($sp)
/* C8EB88 80240FD8 8FA70030 */  lw        $a3, 0x30($sp)
/* C8EB8C 80240FDC 24E70001 */  addiu     $a3, $a3, 1
/* C8EB90 80240FE0 28E20004 */  slti      $v0, $a3, 4
/* C8EB94 80240FE4 1440FFB1 */  bnez      $v0, .L80240EAC
/* C8EB98 80240FE8 261001E0 */   addiu    $s0, $s0, 0x1e0
/* C8EB9C 80240FEC 24020001 */  addiu     $v0, $zero, 1
/* C8EBA0 80240FF0 3C018025 */  lui       $at, %hi(D_80248380)
/* C8EBA4 80240FF4 AC228380 */  sw        $v0, %lo(D_80248380)($at)
/* C8EBA8 80240FF8 0000382D */  daddu     $a3, $zero, $zero
.L80240FFC:
/* C8EBAC 80240FFC 3C02800A */  lui       $v0, %hi(gMasterGfxPos)
/* C8EBB0 80241000 2442A66C */  addiu     $v0, $v0, %lo(gMasterGfxPos)
/* C8EBB4 80241004 0040402D */  daddu     $t0, $v0, $zero
/* C8EBB8 80241008 3C090100 */  lui       $t1, 0x100
/* C8EBBC 8024100C 35294008 */  ori       $t1, $t1, 0x4008
/* C8EBC0 80241010 AFA90018 */  sw        $t1, 0x18($sp)
/* C8EBC4 80241014 3C090602 */  lui       $t1, 0x602
/* C8EBC8 80241018 35290004 */  ori       $t1, $t1, 4
/* C8EBCC 8024101C AFA9001C */  sw        $t1, 0x1c($sp)
/* C8EBD0 80241020 AFA00020 */  sw        $zero, 0x20($sp)
/* C8EBD4 80241024 8D030000 */  lw        $v1, ($t0)
/* C8EBD8 80241028 3C02E700 */  lui       $v0, 0xe700
/* C8EBDC 8024102C 0060202D */  daddu     $a0, $v1, $zero
/* C8EBE0 80241030 24630008 */  addiu     $v1, $v1, 8
/* C8EBE4 80241034 AD030000 */  sw        $v1, ($t0)
/* C8EBE8 80241038 AC820000 */  sw        $v0, ($a0)
/* C8EBEC 8024103C 24620008 */  addiu     $v0, $v1, 8
/* C8EBF0 80241040 AC800004 */  sw        $zero, 4($a0)
/* C8EBF4 80241044 AD020000 */  sw        $v0, ($t0)
/* C8EBF8 80241048 3C02DE00 */  lui       $v0, 0xde00
/* C8EBFC 8024104C AC620000 */  sw        $v0, ($v1)
/* C8EC00 80241050 3C028024 */  lui       $v0, %hi(D_80243AD8_C91688)
/* C8EC04 80241054 24423AD8 */  addiu     $v0, $v0, %lo(D_80243AD8_C91688)
/* C8EC08 80241058 AC620004 */  sw        $v0, 4($v1)
.L8024105C:
/* C8EC0C 8024105C 0000202D */  daddu     $a0, $zero, $zero
/* C8EC10 80241060 3C05FD05 */  lui       $a1, 0xfd05
/* C8EC14 80241064 34A50F80 */  ori       $a1, $a1, 0xf80
/* C8EC18 80241068 AFA70030 */  sw        $a3, 0x30($sp)
/* C8EC1C 8024106C 0C0B1EAF */  jal       evt_get_variable
/* C8EC20 80241070 AFA80034 */   sw       $t0, 0x34($sp)
/* C8EC24 80241074 0000882D */  daddu     $s1, $zero, $zero
/* C8EC28 80241078 8FA90020 */  lw        $t1, 0x20($sp)
/* C8EC2C 8024107C 8FA80034 */  lw        $t0, 0x34($sp)
/* C8EC30 80241080 0049A821 */  addu      $s5, $v0, $t1
/* C8EC34 80241084 3C02DE01 */  lui       $v0, 0xde01
/* C8EC38 80241088 C6B80094 */  lwc1      $f24, 0x94($s5)
/* C8EC3C 8024108C 8D040000 */  lw        $a0, ($t0)
/* C8EC40 80241090 8EB40090 */  lw        $s4, 0x90($s5)
/* C8EC44 80241094 24890008 */  addiu     $t1, $a0, 8
/* C8EC48 80241098 AFA90010 */  sw        $t1, 0x10($sp)
/* C8EC4C 8024109C 8EA601DC */  lw        $a2, 0x1dc($s5)
/* C8EC50 802410A0 AC820000 */  sw        $v0, ($a0)
/* C8EC54 802410A4 00061940 */  sll       $v1, $a2, 5
/* C8EC58 802410A8 24620008 */  addiu     $v0, $v1, 8
/* C8EC5C 802410AC 00821021 */  addu      $v0, $a0, $v0
/* C8EC60 802410B0 01231821 */  addu      $v1, $t1, $v1
/* C8EC64 802410B4 AC820004 */  sw        $v0, 4($a0)
/* C8EC68 802410B8 AD030000 */  sw        $v1, ($t0)
/* C8EC6C 802410BC 8FA70030 */  lw        $a3, 0x30($sp)
/* C8EC70 802410C0 18C00088 */  blez      $a2, .L802412E4
/* C8EC74 802410C4 0120982D */   daddu    $s3, $t1, $zero
/* C8EC78 802410C8 2682FFFF */  addiu     $v0, $s4, -1
/* C8EC7C 802410CC 00021080 */  sll       $v0, $v0, 2
/* C8EC80 802410D0 02A21021 */  addu      $v0, $s5, $v0
/* C8EC84 802410D4 AFA20014 */  sw        $v0, 0x14($sp)
/* C8EC88 802410D8 0220282D */  daddu     $a1, $s1, $zero
/* C8EC8C 802410DC 0220F02D */  daddu     $fp, $s1, $zero
/* C8EC90 802410E0 0220B82D */  daddu     $s7, $s1, $zero
/* C8EC94 802410E4 0220B02D */  daddu     $s6, $s1, $zero
/* C8EC98 802410E8 02A0902D */  daddu     $s2, $s5, $zero
/* C8EC9C 802410EC 24900016 */  addiu     $s0, $a0, 0x16
.L802410F0:
/* C8ECA0 802410F0 44911000 */  mtc1      $s1, $f2
/* C8ECA4 802410F4 00000000 */  nop
/* C8ECA8 802410F8 468010A0 */  cvt.s.w   $f2, $f2
/* C8ECAC 802410FC 44940000 */  mtc1      $s4, $f0
/* C8ECB0 80241100 00000000 */  nop
/* C8ECB4 80241104 46800020 */  cvt.s.w   $f0, $f0
/* C8ECB8 80241108 46001082 */  mul.s     $f2, $f2, $f0
/* C8ECBC 8024110C 00000000 */  nop
/* C8ECC0 80241110 44860000 */  mtc1      $a2, $f0
/* C8ECC4 80241114 00000000 */  nop
/* C8ECC8 80241118 46800020 */  cvt.s.w   $f0, $f0
/* C8ECCC 8024111C C65A0098 */  lwc1      $f26, 0x98($s2)
/* C8ECD0 80241120 C65C009C */  lwc1      $f28, 0x9c($s2)
/* C8ECD4 80241124 C65E00A0 */  lwc1      $f30, 0xa0($s2)
/* C8ECD8 80241128 46001083 */  div.s     $f2, $f2, $f0
/* C8ECDC 8024112C 4600128D */  trunc.w.s $f10, $f2
/* C8ECE0 80241130 44045000 */  mfc1      $a0, $f10
/* C8ECE4 80241134 00000000 */  nop
/* C8ECE8 80241138 44840000 */  mtc1      $a0, $f0
/* C8ECEC 8024113C 00000000 */  nop
/* C8ECF0 80241140 46800020 */  cvt.s.w   $f0, $f0
/* C8ECF4 80241144 24830001 */  addiu     $v1, $a0, 1
/* C8ECF8 80241148 0074102A */  slt       $v0, $v1, $s4
/* C8ECFC 8024114C 14400005 */  bnez      $v0, .L80241164
/* C8ED00 80241150 46001181 */   sub.s    $f6, $f2, $f0
/* C8ED04 80241154 8FA90014 */  lw        $t1, 0x14($sp)
/* C8ED08 80241158 C536006C */  lwc1      $f22, 0x6c($t1)
/* C8ED0C 8024115C 0809047C */  j         .L802411F0
/* C8ED10 80241160 4600B306 */   mov.s    $f12, $f22
.L80241164:
/* C8ED14 80241164 00031080 */  sll       $v0, $v1, 2
/* C8ED18 80241168 02A21021 */  addu      $v0, $s5, $v0
/* C8ED1C 8024116C C444006C */  lwc1      $f4, 0x6c($v0)
/* C8ED20 80241170 00041080 */  sll       $v0, $a0, 2
/* C8ED24 80241174 02A21021 */  addu      $v0, $s5, $v0
/* C8ED28 80241178 C44C006C */  lwc1      $f12, 0x6c($v0)
/* C8ED2C 8024117C 460C2081 */  sub.s     $f2, $f4, $f12
/* C8ED30 80241180 3C014334 */  lui       $at, 0x4334
/* C8ED34 80241184 44810000 */  mtc1      $at, $f0
/* C8ED38 80241188 00000000 */  nop
/* C8ED3C 8024118C 4602003C */  c.lt.s    $f0, $f2
/* C8ED40 80241190 00000000 */  nop
/* C8ED44 80241194 45000006 */  bc1f      .L802411B0
/* C8ED48 80241198 00000000 */   nop
/* C8ED4C 8024119C 3C0143B4 */  lui       $at, 0x43b4
/* C8ED50 802411A0 44815000 */  mtc1      $at, $f10
/* C8ED54 802411A4 00000000 */  nop
/* C8ED58 802411A8 460A2101 */  sub.s     $f4, $f4, $f10
/* C8ED5C 802411AC 460C2081 */  sub.s     $f2, $f4, $f12
.L802411B0:
/* C8ED60 802411B0 3C01C334 */  lui       $at, 0xc334
/* C8ED64 802411B4 44810000 */  mtc1      $at, $f0
/* C8ED68 802411B8 00000000 */  nop
/* C8ED6C 802411BC 4600103C */  c.lt.s    $f2, $f0
/* C8ED70 802411C0 00000000 */  nop
/* C8ED74 802411C4 45020006 */  bc1fl     .L802411E0
/* C8ED78 802411C8 460C2001 */   sub.s    $f0, $f4, $f12
/* C8ED7C 802411CC 3C0143B4 */  lui       $at, 0x43b4
/* C8ED80 802411D0 44815000 */  mtc1      $at, $f10
/* C8ED84 802411D4 00000000 */  nop
/* C8ED88 802411D8 460A2100 */  add.s     $f4, $f4, $f10
/* C8ED8C 802411DC 460C2001 */  sub.s     $f0, $f4, $f12
.L802411E0:
/* C8ED90 802411E0 46060002 */  mul.s     $f0, $f0, $f6
/* C8ED94 802411E4 00000000 */  nop
/* C8ED98 802411E8 460C0580 */  add.s     $f22, $f0, $f12
/* C8ED9C 802411EC 4600B306 */  mov.s     $f12, $f22
.L802411F0:
/* C8EDA0 802411F0 AFA50028 */  sw        $a1, 0x28($sp)
/* C8EDA4 802411F4 AFA6002C */  sw        $a2, 0x2c($sp)
/* C8EDA8 802411F8 AFA70030 */  sw        $a3, 0x30($sp)
/* C8EDAC 802411FC 0C00A8BB */  jal       sin_deg
/* C8EDB0 80241200 AFA80034 */   sw       $t0, 0x34($sp)
/* C8EDB4 80241204 46180502 */  mul.s     $f20, $f0, $f24
/* C8EDB8 80241208 00000000 */  nop
/* C8EDBC 8024120C 0C00A8D4 */  jal       cos_deg
/* C8EDC0 80241210 4600B306 */   mov.s    $f12, $f22
/* C8EDC4 80241214 46000007 */  neg.s     $f0, $f0
/* C8EDC8 80241218 46180002 */  mul.s     $f0, $f0, $f24
/* C8EDCC 8024121C 00000000 */  nop
/* C8EDD0 80241220 4614D100 */  add.s     $f4, $f26, $f20
/* C8EDD4 80241224 4600E080 */  add.s     $f2, $f28, $f0
/* C8EDD8 80241228 4614D501 */  sub.s     $f20, $f26, $f20
/* C8EDDC 8024122C 2652000C */  addiu     $s2, $s2, 0xc
/* C8EDE0 80241230 26310001 */  addiu     $s1, $s1, 1
/* C8EDE4 80241234 4600E001 */  sub.s     $f0, $f28, $f0
/* C8EDE8 80241238 4600228D */  trunc.w.s $f10, $f4
/* C8EDEC 8024123C 44025000 */  mfc1      $v0, $f10
/* C8EDF0 80241240 00000000 */  nop
/* C8EDF4 80241244 A6620000 */  sh        $v0, ($s3)
/* C8EDF8 80241248 4600128D */  trunc.w.s $f10, $f2
/* C8EDFC 8024124C 44025000 */  mfc1      $v0, $f10
/* C8EE00 80241250 4600F28D */  trunc.w.s $f10, $f30
/* C8EE04 80241254 44035000 */  mfc1      $v1, $f10
/* C8EE08 80241258 26730010 */  addiu     $s3, $s3, 0x10
/* C8EE0C 8024125C A602FFF4 */  sh        $v0, -0xc($s0)
/* C8EE10 80241260 A603FFF6 */  sh        $v1, -0xa($s0)
/* C8EE14 80241264 A616FFFA */  sh        $s6, -6($s0)
/* C8EE18 80241268 A600FFFC */  sh        $zero, -4($s0)
/* C8EE1C 8024126C A217FFFE */  sb        $s7, -2($s0)
/* C8EE20 80241270 A21EFFFF */  sb        $fp, -1($s0)
/* C8EE24 80241274 8FA50028 */  lw        $a1, 0x28($sp)
/* C8EE28 80241278 4600A28D */  trunc.w.s $f10, $f20
/* C8EE2C 8024127C 44025000 */  mfc1      $v0, $f10
/* C8EE30 80241280 A2050000 */  sb        $a1, ($s0)
/* C8EE34 80241284 26100010 */  addiu     $s0, $s0, 0x10
/* C8EE38 80241288 A6620000 */  sh        $v0, ($s3)
/* C8EE3C 8024128C 4600028D */  trunc.w.s $f10, $f0
/* C8EE40 80241290 44025000 */  mfc1      $v0, $f10
/* C8EE44 80241294 00000000 */  nop
/* C8EE48 80241298 A602FFF4 */  sh        $v0, -0xc($s0)
/* C8EE4C 8024129C 24020400 */  addiu     $v0, $zero, 0x400
/* C8EE50 802412A0 A603FFF6 */  sh        $v1, -0xa($s0)
/* C8EE54 802412A4 A616FFFA */  sh        $s6, -6($s0)
/* C8EE58 802412A8 A602FFFC */  sh        $v0, -4($s0)
/* C8EE5C 802412AC A217FFFE */  sb        $s7, -2($s0)
/* C8EE60 802412B0 A21EFFFF */  sb        $fp, -1($s0)
/* C8EE64 802412B4 A2050000 */  sb        $a1, ($s0)
/* C8EE68 802412B8 26100010 */  addiu     $s0, $s0, 0x10
/* C8EE6C 802412BC 26730010 */  addiu     $s3, $s3, 0x10
/* C8EE70 802412C0 24A5001E */  addiu     $a1, $a1, 0x1e
/* C8EE74 802412C4 27DE0078 */  addiu     $fp, $fp, 0x78
/* C8EE78 802412C8 26F70032 */  addiu     $s7, $s7, 0x32
/* C8EE7C 802412CC 8FA6002C */  lw        $a2, 0x2c($sp)
/* C8EE80 802412D0 8FA70030 */  lw        $a3, 0x30($sp)
/* C8EE84 802412D4 8FA80034 */  lw        $t0, 0x34($sp)
/* C8EE88 802412D8 0226102A */  slt       $v0, $s1, $a2
/* C8EE8C 802412DC 1440FF84 */  bnez      $v0, .L802410F0
/* C8EE90 802412E0 26D60140 */   addiu    $s6, $s6, 0x140
.L802412E4:
/* C8EE94 802412E4 24C5FFFF */  addiu     $a1, $a2, -1
/* C8EE98 802412E8 18A00014 */  blez      $a1, .L8024133C
/* C8EE9C 802412EC 0000882D */   daddu    $s1, $zero, $zero
/* C8EEA0 802412F0 3C060002 */  lui       $a2, 2
/* C8EEA4 802412F4 34C60406 */  ori       $a2, $a2, 0x406
/* C8EEA8 802412F8 8FA40010 */  lw        $a0, 0x10($sp)
.L802412FC:
/* C8EEAC 802412FC 8D030000 */  lw        $v1, ($t0)
/* C8EEB0 80241300 26310001 */  addiu     $s1, $s1, 1
/* C8EEB4 80241304 0060102D */  daddu     $v0, $v1, $zero
/* C8EEB8 80241308 24630008 */  addiu     $v1, $v1, 8
/* C8EEBC 8024130C AC440004 */  sw        $a0, 4($v0)
/* C8EEC0 80241310 AD030000 */  sw        $v1, ($t0)
/* C8EEC4 80241314 8FA90018 */  lw        $t1, 0x18($sp)
/* C8EEC8 80241318 24840020 */  addiu     $a0, $a0, 0x20
/* C8EECC 8024131C AC490000 */  sw        $t1, ($v0)
/* C8EED0 80241320 24620008 */  addiu     $v0, $v1, 8
/* C8EED4 80241324 AD020000 */  sw        $v0, ($t0)
/* C8EED8 80241328 8FA9001C */  lw        $t1, 0x1c($sp)
/* C8EEDC 8024132C 0225102A */  slt       $v0, $s1, $a1
/* C8EEE0 80241330 AC660004 */  sw        $a2, 4($v1)
/* C8EEE4 80241334 1440FFF1 */  bnez      $v0, .L802412FC
/* C8EEE8 80241338 AC690000 */   sw       $t1, ($v1)
.L8024133C:
/* C8EEEC 8024133C 24E70001 */  addiu     $a3, $a3, 1
/* C8EEF0 80241340 8FA90020 */  lw        $t1, 0x20($sp)
/* C8EEF4 80241344 28E20004 */  slti      $v0, $a3, 4
/* C8EEF8 80241348 252901E0 */  addiu     $t1, $t1, 0x1e0
/* C8EEFC 8024134C 1440FF43 */  bnez      $v0, .L8024105C
/* C8EF00 80241350 AFA90020 */   sw       $t1, 0x20($sp)
/* C8EF04 80241354 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* C8EF08 80241358 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* C8EF0C 8024135C 8C620000 */  lw        $v0, ($v1)
/* C8EF10 80241360 0040202D */  daddu     $a0, $v0, $zero
/* C8EF14 80241364 24420008 */  addiu     $v0, $v0, 8
/* C8EF18 80241368 AC620000 */  sw        $v0, ($v1)
/* C8EF1C 8024136C 3C02E700 */  lui       $v0, 0xe700
/* C8EF20 80241370 AC820000 */  sw        $v0, ($a0)
/* C8EF24 80241374 AC800004 */  sw        $zero, 4($a0)
.L80241378:
/* C8EF28 80241378 8FBF005C */  lw        $ra, 0x5c($sp)
/* C8EF2C 8024137C 8FBE0058 */  lw        $fp, 0x58($sp)
/* C8EF30 80241380 8FB70054 */  lw        $s7, 0x54($sp)
/* C8EF34 80241384 8FB60050 */  lw        $s6, 0x50($sp)
/* C8EF38 80241388 8FB5004C */  lw        $s5, 0x4c($sp)
/* C8EF3C 8024138C 8FB40048 */  lw        $s4, 0x48($sp)
/* C8EF40 80241390 8FB30044 */  lw        $s3, 0x44($sp)
/* C8EF44 80241394 8FB20040 */  lw        $s2, 0x40($sp)
/* C8EF48 80241398 8FB1003C */  lw        $s1, 0x3c($sp)
/* C8EF4C 8024139C 8FB00038 */  lw        $s0, 0x38($sp)
/* C8EF50 802413A0 D7BE0088 */  ldc1      $f30, 0x88($sp)
/* C8EF54 802413A4 D7BC0080 */  ldc1      $f28, 0x80($sp)
/* C8EF58 802413A8 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* C8EF5C 802413AC D7B80070 */  ldc1      $f24, 0x70($sp)
/* C8EF60 802413B0 D7B60068 */  ldc1      $f22, 0x68($sp)
/* C8EF64 802413B4 D7B40060 */  ldc1      $f20, 0x60($sp)
/* C8EF68 802413B8 03E00008 */  jr        $ra
/* C8EF6C 802413BC 27BD0090 */   addiu    $sp, $sp, 0x90
