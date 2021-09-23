.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80248370_EB0E50
.double 90.0, 0.0

.section .text

glabel func_80240E2C_EA990C
/* EA990C 80240E2C 27BDFF70 */  addiu     $sp, $sp, -0x90
/* EA9910 80240E30 3C038025 */  lui       $v1, %hi(D_80248380)
/* EA9914 80240E34 8C638380 */  lw        $v1, %lo(D_80248380)($v1)
/* EA9918 80240E38 2402FFFF */  addiu     $v0, $zero, -1
/* EA991C 80240E3C AFBF005C */  sw        $ra, 0x5c($sp)
/* EA9920 80240E40 AFBE0058 */  sw        $fp, 0x58($sp)
/* EA9924 80240E44 AFB70054 */  sw        $s7, 0x54($sp)
/* EA9928 80240E48 AFB60050 */  sw        $s6, 0x50($sp)
/* EA992C 80240E4C AFB5004C */  sw        $s5, 0x4c($sp)
/* EA9930 80240E50 AFB40048 */  sw        $s4, 0x48($sp)
/* EA9934 80240E54 AFB30044 */  sw        $s3, 0x44($sp)
/* EA9938 80240E58 AFB20040 */  sw        $s2, 0x40($sp)
/* EA993C 80240E5C AFB1003C */  sw        $s1, 0x3c($sp)
/* EA9940 80240E60 AFB00038 */  sw        $s0, 0x38($sp)
/* EA9944 80240E64 F7BE0088 */  sdc1      $f30, 0x88($sp)
/* EA9948 80240E68 F7BC0080 */  sdc1      $f28, 0x80($sp)
/* EA994C 80240E6C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* EA9950 80240E70 F7B80070 */  sdc1      $f24, 0x70($sp)
/* EA9954 80240E74 F7B60068 */  sdc1      $f22, 0x68($sp)
/* EA9958 80240E78 1062013F */  beq       $v1, $v0, .L80241378
/* EA995C 80240E7C F7B40060 */   sdc1     $f20, 0x60($sp)
/* EA9960 80240E80 1460005E */  bnez      $v1, .L80240FFC
/* EA9964 80240E84 0000382D */   daddu    $a3, $zero, $zero
/* EA9968 80240E88 00E0802D */  daddu     $s0, $a3, $zero
/* EA996C 80240E8C 3C0142B4 */  lui       $at, 0x42b4
/* EA9970 80240E90 4481E000 */  mtc1      $at, $f28
/* EA9974 80240E94 3C014334 */  lui       $at, 0x4334
/* EA9978 80240E98 4481D000 */  mtc1      $at, $f26
/* EA997C 80240E9C 3C0143B4 */  lui       $at, 0x43b4
/* EA9980 80240EA0 4481A000 */  mtc1      $at, $f20
/* EA9984 80240EA4 3C01C334 */  lui       $at, 0xc334
/* EA9988 80240EA8 4481B000 */  mtc1      $at, $f22
.L80240EAC:
/* EA998C 80240EAC 0000202D */  daddu     $a0, $zero, $zero
/* EA9990 80240EB0 3C05FD05 */  lui       $a1, 0xfd05
/* EA9994 80240EB4 34A50F80 */  ori       $a1, $a1, 0xf80
/* EA9998 80240EB8 0C0B53A3 */  jal       dead_evt_get_variable
/* EA999C 80240EBC AFA70030 */   sw       $a3, 0x30($sp)
/* EA99A0 80240EC0 00502021 */  addu      $a0, $v0, $s0
/* EA99A4 80240EC4 8FA70030 */  lw        $a3, 0x30($sp)
/* EA99A8 80240EC8 24020001 */  addiu     $v0, $zero, 1
/* EA99AC 80240ECC 10E20011 */  beq       $a3, $v0, .L80240F14
/* EA99B0 80240ED0 28E20002 */   slti     $v0, $a3, 2
/* EA99B4 80240ED4 50400005 */  beql      $v0, $zero, .L80240EEC
/* EA99B8 80240ED8 24020002 */   addiu    $v0, $zero, 2
/* EA99BC 80240EDC 10E00009 */  beqz      $a3, .L80240F04
/* EA99C0 80240EE0 00000000 */   nop
/* EA99C4 80240EE4 080904DE */  j         .L80241378
/* EA99C8 80240EE8 00000000 */   nop
.L80240EEC:
/* EA99CC 80240EEC 10E2000B */  beq       $a3, $v0, .L80240F1C
/* EA99D0 80240EF0 24020003 */   addiu    $v0, $zero, 3
/* EA99D4 80240EF4 10E2000A */  beq       $a3, $v0, .L80240F20
/* EA99D8 80240EF8 24140005 */   addiu    $s4, $zero, 5
/* EA99DC 80240EFC 080904DE */  j         .L80241378
/* EA99E0 80240F00 00000000 */   nop
.L80240F04:
/* EA99E4 80240F04 3C014120 */  lui       $at, 0x4120
/* EA99E8 80240F08 4481C000 */  mtc1      $at, $f24
/* EA99EC 80240F0C 080903CA */  j         .L80240F28
/* EA99F0 80240F10 24140009 */   addiu    $s4, $zero, 9
.L80240F14:
/* EA99F4 80240F14 080903C8 */  j         .L80240F20
/* EA99F8 80240F18 24140007 */   addiu    $s4, $zero, 7
.L80240F1C:
/* EA99FC 80240F1C 24140007 */  addiu     $s4, $zero, 7
.L80240F20:
/* EA9A00 80240F20 3C014100 */  lui       $at, 0x4100
/* EA9A04 80240F24 4481C000 */  mtc1      $at, $f24
.L80240F28:
/* EA9A08 80240F28 0000882D */  daddu     $s1, $zero, $zero
/* EA9A0C 80240F2C AC940090 */  sw        $s4, 0x90($a0)
/* EA9A10 80240F30 1A800027 */  blez      $s4, .L80240FD0
/* EA9A14 80240F34 E4980094 */   swc1     $f24, 0x94($a0)
/* EA9A18 80240F38 2686FFFF */  addiu     $a2, $s4, -1
/* EA9A1C 80240F3C 0080182D */  daddu     $v1, $a0, $zero
/* EA9A20 80240F40 24050004 */  addiu     $a1, $zero, 4
/* EA9A24 80240F44 3C013FE0 */  lui       $at, 0x3fe0
/* EA9A28 80240F48 44814800 */  mtc1      $at, $f9
/* EA9A2C 80240F4C 44804000 */  mtc1      $zero, $f8
/* EA9A30 80240F50 3C018025 */  lui       $at, %hi(D_80248370_EB0E50)
/* EA9A34 80240F54 D4268370 */  ldc1      $f6, %lo(D_80248370_EB0E50)($at)
.L80240F58:
/* EA9A38 80240F58 16260004 */  bne       $s1, $a2, .L80240F6C
/* EA9A3C 80240F5C 00851021 */   addu     $v0, $a0, $a1
/* EA9A40 80240F60 C460006C */  lwc1      $f0, 0x6c($v1)
/* EA9A44 80240F64 080903EE */  j         .L80240FB8
/* EA9A48 80240F68 461C0000 */   add.s    $f0, $f0, $f28
.L80240F6C:
/* EA9A4C 80240F6C C460006C */  lwc1      $f0, 0x6c($v1)
/* EA9A50 80240F70 C444006C */  lwc1      $f4, 0x6c($v0)
/* EA9A54 80240F74 46002081 */  sub.s     $f2, $f4, $f0
/* EA9A58 80240F78 4602D03C */  c.lt.s    $f26, $f2
/* EA9A5C 80240F7C 00000000 */  nop
/* EA9A60 80240F80 45000003 */  bc1f      .L80240F90
/* EA9A64 80240F84 00000000 */   nop
/* EA9A68 80240F88 080903E8 */  j         .L80240FA0
/* EA9A6C 80240F8C 46140000 */   add.s    $f0, $f0, $f20
.L80240F90:
/* EA9A70 80240F90 4616103C */  c.lt.s    $f2, $f22
/* EA9A74 80240F94 00000000 */  nop
/* EA9A78 80240F98 45030001 */  bc1tl     .L80240FA0
/* EA9A7C 80240F9C 46142100 */   add.s    $f4, $f4, $f20
.L80240FA0:
/* EA9A80 80240FA0 46040000 */  add.s     $f0, $f0, $f4
/* EA9A84 80240FA4 46000021 */  cvt.d.s   $f0, $f0
/* EA9A88 80240FA8 46280002 */  mul.d     $f0, $f0, $f8
/* EA9A8C 80240FAC 00000000 */  nop
/* EA9A90 80240FB0 46260000 */  add.d     $f0, $f0, $f6
/* EA9A94 80240FB4 46200020 */  cvt.s.d   $f0, $f0
.L80240FB8:
/* EA9A98 80240FB8 E460006C */  swc1      $f0, 0x6c($v1)
/* EA9A9C 80240FBC 24630004 */  addiu     $v1, $v1, 4
/* EA9AA0 80240FC0 26310001 */  addiu     $s1, $s1, 1
/* EA9AA4 80240FC4 0234102A */  slt       $v0, $s1, $s4
/* EA9AA8 80240FC8 1440FFE3 */  bnez      $v0, .L80240F58
/* EA9AAC 80240FCC 24A50004 */   addiu    $a1, $a1, 4
.L80240FD0:
/* EA9AB0 80240FD0 0C0902C0 */  jal       func_80240B00_EA95E0
/* EA9AB4 80240FD4 AFA70030 */   sw       $a3, 0x30($sp)
/* EA9AB8 80240FD8 8FA70030 */  lw        $a3, 0x30($sp)
/* EA9ABC 80240FDC 24E70001 */  addiu     $a3, $a3, 1
/* EA9AC0 80240FE0 28E20004 */  slti      $v0, $a3, 4
/* EA9AC4 80240FE4 1440FFB1 */  bnez      $v0, .L80240EAC
/* EA9AC8 80240FE8 261001E0 */   addiu    $s0, $s0, 0x1e0
/* EA9ACC 80240FEC 24020001 */  addiu     $v0, $zero, 1
/* EA9AD0 80240FF0 3C018025 */  lui       $at, %hi(D_80248380)
/* EA9AD4 80240FF4 AC228380 */  sw        $v0, %lo(D_80248380)($at)
/* EA9AD8 80240FF8 0000382D */  daddu     $a3, $zero, $zero
.L80240FFC:
/* EA9ADC 80240FFC 3C02800A */  lui       $v0, %hi(D_800A15C4)
/* EA9AE0 80241000 244215C4 */  addiu     $v0, $v0, %lo(D_800A15C4)
/* EA9AE4 80241004 0040402D */  daddu     $t0, $v0, $zero
/* EA9AE8 80241008 3C090100 */  lui       $t1, 0x100
/* EA9AEC 8024100C 35294008 */  ori       $t1, $t1, 0x4008
/* EA9AF0 80241010 AFA90018 */  sw        $t1, 0x18($sp)
/* EA9AF4 80241014 3C090602 */  lui       $t1, 0x602
/* EA9AF8 80241018 35290004 */  ori       $t1, $t1, 4
/* EA9AFC 8024101C AFA9001C */  sw        $t1, 0x1c($sp)
/* EA9B00 80241020 AFA00020 */  sw        $zero, 0x20($sp)
/* EA9B04 80241024 8D030000 */  lw        $v1, ($t0)
/* EA9B08 80241028 3C02E700 */  lui       $v0, 0xe700
/* EA9B0C 8024102C 0060202D */  daddu     $a0, $v1, $zero
/* EA9B10 80241030 24630008 */  addiu     $v1, $v1, 8
/* EA9B14 80241034 AD030000 */  sw        $v1, ($t0)
/* EA9B18 80241038 AC820000 */  sw        $v0, ($a0)
/* EA9B1C 8024103C 24620008 */  addiu     $v0, $v1, 8
/* EA9B20 80241040 AC800004 */  sw        $zero, 4($a0)
/* EA9B24 80241044 AD020000 */  sw        $v0, ($t0)
/* EA9B28 80241048 3C02DE00 */  lui       $v0, 0xde00
/* EA9B2C 8024104C AC620000 */  sw        $v0, ($v1)
/* EA9B30 80241050 3C028024 */  lui       $v0, %hi(D_80243AD8_EAC5B8)
/* EA9B34 80241054 24423AD8 */  addiu     $v0, $v0, %lo(D_80243AD8_EAC5B8)
/* EA9B38 80241058 AC620004 */  sw        $v0, 4($v1)
.L8024105C:
/* EA9B3C 8024105C 0000202D */  daddu     $a0, $zero, $zero
/* EA9B40 80241060 3C05FD05 */  lui       $a1, 0xfd05
/* EA9B44 80241064 34A50F80 */  ori       $a1, $a1, 0xf80
/* EA9B48 80241068 AFA70030 */  sw        $a3, 0x30($sp)
/* EA9B4C 8024106C 0C0B53A3 */  jal       dead_evt_get_variable
/* EA9B50 80241070 AFA80034 */   sw       $t0, 0x34($sp)
/* EA9B54 80241074 0000882D */  daddu     $s1, $zero, $zero
/* EA9B58 80241078 8FA90020 */  lw        $t1, 0x20($sp)
/* EA9B5C 8024107C 8FA80034 */  lw        $t0, 0x34($sp)
/* EA9B60 80241080 0049A821 */  addu      $s5, $v0, $t1
/* EA9B64 80241084 3C02DE01 */  lui       $v0, 0xde01
/* EA9B68 80241088 C6B80094 */  lwc1      $f24, 0x94($s5)
/* EA9B6C 8024108C 8D040000 */  lw        $a0, ($t0)
/* EA9B70 80241090 8EB40090 */  lw        $s4, 0x90($s5)
/* EA9B74 80241094 24890008 */  addiu     $t1, $a0, 8
/* EA9B78 80241098 AFA90010 */  sw        $t1, 0x10($sp)
/* EA9B7C 8024109C 8EA601DC */  lw        $a2, 0x1dc($s5)
/* EA9B80 802410A0 AC820000 */  sw        $v0, ($a0)
/* EA9B84 802410A4 00061940 */  sll       $v1, $a2, 5
/* EA9B88 802410A8 24620008 */  addiu     $v0, $v1, 8
/* EA9B8C 802410AC 00821021 */  addu      $v0, $a0, $v0
/* EA9B90 802410B0 01231821 */  addu      $v1, $t1, $v1
/* EA9B94 802410B4 AC820004 */  sw        $v0, 4($a0)
/* EA9B98 802410B8 AD030000 */  sw        $v1, ($t0)
/* EA9B9C 802410BC 8FA70030 */  lw        $a3, 0x30($sp)
/* EA9BA0 802410C0 18C00088 */  blez      $a2, .L802412E4
/* EA9BA4 802410C4 0120982D */   daddu    $s3, $t1, $zero
/* EA9BA8 802410C8 2682FFFF */  addiu     $v0, $s4, -1
/* EA9BAC 802410CC 00021080 */  sll       $v0, $v0, 2
/* EA9BB0 802410D0 02A21021 */  addu      $v0, $s5, $v0
/* EA9BB4 802410D4 AFA20014 */  sw        $v0, 0x14($sp)
/* EA9BB8 802410D8 0220282D */  daddu     $a1, $s1, $zero
/* EA9BBC 802410DC 0220F02D */  daddu     $fp, $s1, $zero
/* EA9BC0 802410E0 0220B82D */  daddu     $s7, $s1, $zero
/* EA9BC4 802410E4 0220B02D */  daddu     $s6, $s1, $zero
/* EA9BC8 802410E8 02A0902D */  daddu     $s2, $s5, $zero
/* EA9BCC 802410EC 24900016 */  addiu     $s0, $a0, 0x16
.L802410F0:
/* EA9BD0 802410F0 44911000 */  mtc1      $s1, $f2
/* EA9BD4 802410F4 00000000 */  nop
/* EA9BD8 802410F8 468010A0 */  cvt.s.w   $f2, $f2
/* EA9BDC 802410FC 44940000 */  mtc1      $s4, $f0
/* EA9BE0 80241100 00000000 */  nop
/* EA9BE4 80241104 46800020 */  cvt.s.w   $f0, $f0
/* EA9BE8 80241108 46001082 */  mul.s     $f2, $f2, $f0
/* EA9BEC 8024110C 00000000 */  nop
/* EA9BF0 80241110 44860000 */  mtc1      $a2, $f0
/* EA9BF4 80241114 00000000 */  nop
/* EA9BF8 80241118 46800020 */  cvt.s.w   $f0, $f0
/* EA9BFC 8024111C C65A0098 */  lwc1      $f26, 0x98($s2)
/* EA9C00 80241120 C65C009C */  lwc1      $f28, 0x9c($s2)
/* EA9C04 80241124 C65E00A0 */  lwc1      $f30, 0xa0($s2)
/* EA9C08 80241128 46001083 */  div.s     $f2, $f2, $f0
/* EA9C0C 8024112C 4600128D */  trunc.w.s $f10, $f2
/* EA9C10 80241130 44045000 */  mfc1      $a0, $f10
/* EA9C14 80241134 00000000 */  nop
/* EA9C18 80241138 44840000 */  mtc1      $a0, $f0
/* EA9C1C 8024113C 00000000 */  nop
/* EA9C20 80241140 46800020 */  cvt.s.w   $f0, $f0
/* EA9C24 80241144 24830001 */  addiu     $v1, $a0, 1
/* EA9C28 80241148 0074102A */  slt       $v0, $v1, $s4
/* EA9C2C 8024114C 14400005 */  bnez      $v0, .L80241164
/* EA9C30 80241150 46001181 */   sub.s    $f6, $f2, $f0
/* EA9C34 80241154 8FA90014 */  lw        $t1, 0x14($sp)
/* EA9C38 80241158 C536006C */  lwc1      $f22, 0x6c($t1)
/* EA9C3C 8024115C 0809047C */  j         .L802411F0
/* EA9C40 80241160 4600B306 */   mov.s    $f12, $f22
.L80241164:
/* EA9C44 80241164 00031080 */  sll       $v0, $v1, 2
/* EA9C48 80241168 02A21021 */  addu      $v0, $s5, $v0
/* EA9C4C 8024116C C444006C */  lwc1      $f4, 0x6c($v0)
/* EA9C50 80241170 00041080 */  sll       $v0, $a0, 2
/* EA9C54 80241174 02A21021 */  addu      $v0, $s5, $v0
/* EA9C58 80241178 C44C006C */  lwc1      $f12, 0x6c($v0)
/* EA9C5C 8024117C 460C2081 */  sub.s     $f2, $f4, $f12
/* EA9C60 80241180 3C014334 */  lui       $at, 0x4334
/* EA9C64 80241184 44810000 */  mtc1      $at, $f0
/* EA9C68 80241188 00000000 */  nop
/* EA9C6C 8024118C 4602003C */  c.lt.s    $f0, $f2
/* EA9C70 80241190 00000000 */  nop
/* EA9C74 80241194 45000006 */  bc1f      .L802411B0
/* EA9C78 80241198 00000000 */   nop
/* EA9C7C 8024119C 3C0143B4 */  lui       $at, 0x43b4
/* EA9C80 802411A0 44815000 */  mtc1      $at, $f10
/* EA9C84 802411A4 00000000 */  nop
/* EA9C88 802411A8 460A2101 */  sub.s     $f4, $f4, $f10
/* EA9C8C 802411AC 460C2081 */  sub.s     $f2, $f4, $f12
.L802411B0:
/* EA9C90 802411B0 3C01C334 */  lui       $at, 0xc334
/* EA9C94 802411B4 44810000 */  mtc1      $at, $f0
/* EA9C98 802411B8 00000000 */  nop
/* EA9C9C 802411BC 4600103C */  c.lt.s    $f2, $f0
/* EA9CA0 802411C0 00000000 */  nop
/* EA9CA4 802411C4 45020006 */  bc1fl     .L802411E0
/* EA9CA8 802411C8 460C2001 */   sub.s    $f0, $f4, $f12
/* EA9CAC 802411CC 3C0143B4 */  lui       $at, 0x43b4
/* EA9CB0 802411D0 44815000 */  mtc1      $at, $f10
/* EA9CB4 802411D4 00000000 */  nop
/* EA9CB8 802411D8 460A2100 */  add.s     $f4, $f4, $f10
/* EA9CBC 802411DC 460C2001 */  sub.s     $f0, $f4, $f12
.L802411E0:
/* EA9CC0 802411E0 46060002 */  mul.s     $f0, $f0, $f6
/* EA9CC4 802411E4 00000000 */  nop
/* EA9CC8 802411E8 460C0580 */  add.s     $f22, $f0, $f12
/* EA9CCC 802411EC 4600B306 */  mov.s     $f12, $f22
.L802411F0:
/* EA9CD0 802411F0 AFA50028 */  sw        $a1, 0x28($sp)
/* EA9CD4 802411F4 AFA6002C */  sw        $a2, 0x2c($sp)
/* EA9CD8 802411F8 AFA70030 */  sw        $a3, 0x30($sp)
/* EA9CDC 802411FC 0C00AD77 */  jal       dead_sin_deg
/* EA9CE0 80241200 AFA80034 */   sw       $t0, 0x34($sp)
/* EA9CE4 80241204 46180502 */  mul.s     $f20, $f0, $f24
/* EA9CE8 80241208 00000000 */  nop
/* EA9CEC 8024120C 0C00AD90 */  jal       dead_cos_deg
/* EA9CF0 80241210 4600B306 */   mov.s    $f12, $f22
/* EA9CF4 80241214 46000007 */  neg.s     $f0, $f0
/* EA9CF8 80241218 46180002 */  mul.s     $f0, $f0, $f24
/* EA9CFC 8024121C 00000000 */  nop
/* EA9D00 80241220 4614D100 */  add.s     $f4, $f26, $f20
/* EA9D04 80241224 4600E080 */  add.s     $f2, $f28, $f0
/* EA9D08 80241228 4614D501 */  sub.s     $f20, $f26, $f20
/* EA9D0C 8024122C 2652000C */  addiu     $s2, $s2, 0xc
/* EA9D10 80241230 26310001 */  addiu     $s1, $s1, 1
/* EA9D14 80241234 4600E001 */  sub.s     $f0, $f28, $f0
/* EA9D18 80241238 4600228D */  trunc.w.s $f10, $f4
/* EA9D1C 8024123C 44025000 */  mfc1      $v0, $f10
/* EA9D20 80241240 00000000 */  nop
/* EA9D24 80241244 A6620000 */  sh        $v0, ($s3)
/* EA9D28 80241248 4600128D */  trunc.w.s $f10, $f2
/* EA9D2C 8024124C 44025000 */  mfc1      $v0, $f10
/* EA9D30 80241250 4600F28D */  trunc.w.s $f10, $f30
/* EA9D34 80241254 44035000 */  mfc1      $v1, $f10
/* EA9D38 80241258 26730010 */  addiu     $s3, $s3, 0x10
/* EA9D3C 8024125C A602FFF4 */  sh        $v0, -0xc($s0)
/* EA9D40 80241260 A603FFF6 */  sh        $v1, -0xa($s0)
/* EA9D44 80241264 A616FFFA */  sh        $s6, -6($s0)
/* EA9D48 80241268 A600FFFC */  sh        $zero, -4($s0)
/* EA9D4C 8024126C A217FFFE */  sb        $s7, -2($s0)
/* EA9D50 80241270 A21EFFFF */  sb        $fp, -1($s0)
/* EA9D54 80241274 8FA50028 */  lw        $a1, 0x28($sp)
/* EA9D58 80241278 4600A28D */  trunc.w.s $f10, $f20
/* EA9D5C 8024127C 44025000 */  mfc1      $v0, $f10
/* EA9D60 80241280 A2050000 */  sb        $a1, ($s0)
/* EA9D64 80241284 26100010 */  addiu     $s0, $s0, 0x10
/* EA9D68 80241288 A6620000 */  sh        $v0, ($s3)
/* EA9D6C 8024128C 4600028D */  trunc.w.s $f10, $f0
/* EA9D70 80241290 44025000 */  mfc1      $v0, $f10
/* EA9D74 80241294 00000000 */  nop
/* EA9D78 80241298 A602FFF4 */  sh        $v0, -0xc($s0)
/* EA9D7C 8024129C 24020400 */  addiu     $v0, $zero, 0x400
/* EA9D80 802412A0 A603FFF6 */  sh        $v1, -0xa($s0)
/* EA9D84 802412A4 A616FFFA */  sh        $s6, -6($s0)
/* EA9D88 802412A8 A602FFFC */  sh        $v0, -4($s0)
/* EA9D8C 802412AC A217FFFE */  sb        $s7, -2($s0)
/* EA9D90 802412B0 A21EFFFF */  sb        $fp, -1($s0)
/* EA9D94 802412B4 A2050000 */  sb        $a1, ($s0)
/* EA9D98 802412B8 26100010 */  addiu     $s0, $s0, 0x10
/* EA9D9C 802412BC 26730010 */  addiu     $s3, $s3, 0x10
/* EA9DA0 802412C0 24A5001E */  addiu     $a1, $a1, 0x1e
/* EA9DA4 802412C4 27DE0078 */  addiu     $fp, $fp, 0x78
/* EA9DA8 802412C8 26F70032 */  addiu     $s7, $s7, 0x32
/* EA9DAC 802412CC 8FA6002C */  lw        $a2, 0x2c($sp)
/* EA9DB0 802412D0 8FA70030 */  lw        $a3, 0x30($sp)
/* EA9DB4 802412D4 8FA80034 */  lw        $t0, 0x34($sp)
/* EA9DB8 802412D8 0226102A */  slt       $v0, $s1, $a2
/* EA9DBC 802412DC 1440FF84 */  bnez      $v0, .L802410F0
/* EA9DC0 802412E0 26D60140 */   addiu    $s6, $s6, 0x140
.L802412E4:
/* EA9DC4 802412E4 24C5FFFF */  addiu     $a1, $a2, -1
/* EA9DC8 802412E8 18A00014 */  blez      $a1, .L8024133C
/* EA9DCC 802412EC 0000882D */   daddu    $s1, $zero, $zero
/* EA9DD0 802412F0 3C060002 */  lui       $a2, 2
/* EA9DD4 802412F4 34C60406 */  ori       $a2, $a2, 0x406
/* EA9DD8 802412F8 8FA40010 */  lw        $a0, 0x10($sp)
.L802412FC:
/* EA9DDC 802412FC 8D030000 */  lw        $v1, ($t0)
/* EA9DE0 80241300 26310001 */  addiu     $s1, $s1, 1
/* EA9DE4 80241304 0060102D */  daddu     $v0, $v1, $zero
/* EA9DE8 80241308 24630008 */  addiu     $v1, $v1, 8
/* EA9DEC 8024130C AC440004 */  sw        $a0, 4($v0)
/* EA9DF0 80241310 AD030000 */  sw        $v1, ($t0)
/* EA9DF4 80241314 8FA90018 */  lw        $t1, 0x18($sp)
/* EA9DF8 80241318 24840020 */  addiu     $a0, $a0, 0x20
/* EA9DFC 8024131C AC490000 */  sw        $t1, ($v0)
/* EA9E00 80241320 24620008 */  addiu     $v0, $v1, 8
/* EA9E04 80241324 AD020000 */  sw        $v0, ($t0)
/* EA9E08 80241328 8FA9001C */  lw        $t1, 0x1c($sp)
/* EA9E0C 8024132C 0225102A */  slt       $v0, $s1, $a1
/* EA9E10 80241330 AC660004 */  sw        $a2, 4($v1)
/* EA9E14 80241334 1440FFF1 */  bnez      $v0, .L802412FC
/* EA9E18 80241338 AC690000 */   sw       $t1, ($v1)
.L8024133C:
/* EA9E1C 8024133C 24E70001 */  addiu     $a3, $a3, 1
/* EA9E20 80241340 8FA90020 */  lw        $t1, 0x20($sp)
/* EA9E24 80241344 28E20004 */  slti      $v0, $a3, 4
/* EA9E28 80241348 252901E0 */  addiu     $t1, $t1, 0x1e0
/* EA9E2C 8024134C 1440FF43 */  bnez      $v0, .L8024105C
/* EA9E30 80241350 AFA90020 */   sw       $t1, 0x20($sp)
/* EA9E34 80241354 3C03800A */  lui       $v1, %hi(D_800A15C4)
/* EA9E38 80241358 246315C4 */  addiu     $v1, $v1, %lo(D_800A15C4)
/* EA9E3C 8024135C 8C620000 */  lw        $v0, ($v1)
/* EA9E40 80241360 0040202D */  daddu     $a0, $v0, $zero
/* EA9E44 80241364 24420008 */  addiu     $v0, $v0, 8
/* EA9E48 80241368 AC620000 */  sw        $v0, ($v1)
/* EA9E4C 8024136C 3C02E700 */  lui       $v0, 0xe700
/* EA9E50 80241370 AC820000 */  sw        $v0, ($a0)
/* EA9E54 80241374 AC800004 */  sw        $zero, 4($a0)
.L80241378:
/* EA9E58 80241378 8FBF005C */  lw        $ra, 0x5c($sp)
/* EA9E5C 8024137C 8FBE0058 */  lw        $fp, 0x58($sp)
/* EA9E60 80241380 8FB70054 */  lw        $s7, 0x54($sp)
/* EA9E64 80241384 8FB60050 */  lw        $s6, 0x50($sp)
/* EA9E68 80241388 8FB5004C */  lw        $s5, 0x4c($sp)
/* EA9E6C 8024138C 8FB40048 */  lw        $s4, 0x48($sp)
/* EA9E70 80241390 8FB30044 */  lw        $s3, 0x44($sp)
/* EA9E74 80241394 8FB20040 */  lw        $s2, 0x40($sp)
/* EA9E78 80241398 8FB1003C */  lw        $s1, 0x3c($sp)
/* EA9E7C 8024139C 8FB00038 */  lw        $s0, 0x38($sp)
/* EA9E80 802413A0 D7BE0088 */  ldc1      $f30, 0x88($sp)
/* EA9E84 802413A4 D7BC0080 */  ldc1      $f28, 0x80($sp)
/* EA9E88 802413A8 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* EA9E8C 802413AC D7B80070 */  ldc1      $f24, 0x70($sp)
/* EA9E90 802413B0 D7B60068 */  ldc1      $f22, 0x68($sp)
/* EA9E94 802413B4 D7B40060 */  ldc1      $f20, 0x60($sp)
/* EA9E98 802413B8 03E00008 */  jr        $ra
/* EA9E9C 802413BC 27BD0090 */   addiu    $sp, $sp, 0x90
