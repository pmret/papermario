.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC3DC_E2CB0C
/* E2CB0C 802BC3DC 27BDFF78 */  addiu     $sp, $sp, -0x88
/* E2CB10 802BC3E0 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* E2CB14 802BC3E4 4480D000 */  mtc1      $zero, $f26
/* E2CB18 802BC3E8 F7BE0080 */  sdc1      $f30, 0x80($sp)
/* E2CB1C 802BC3EC 3C014F00 */  lui       $at, 0x4f00
/* E2CB20 802BC3F0 4481F000 */  mtc1      $at, $f30
/* E2CB24 802BC3F4 AFBE0050 */  sw        $fp, 0x50($sp)
/* E2CB28 802BC3F8 0080F02D */  daddu     $fp, $a0, $zero
/* E2CB2C 802BC3FC AFB3003C */  sw        $s3, 0x3c($sp)
/* E2CB30 802BC400 0000982D */  daddu     $s3, $zero, $zero
/* E2CB34 802BC404 AFB60048 */  sw        $s6, 0x48($sp)
/* E2CB38 802BC408 27B60020 */  addiu     $s6, $sp, 0x20
/* E2CB3C 802BC40C AFB50044 */  sw        $s5, 0x44($sp)
/* E2CB40 802BC410 27B50024 */  addiu     $s5, $sp, 0x24
/* E2CB44 802BC414 AFB40040 */  sw        $s4, 0x40($sp)
/* E2CB48 802BC418 27B40028 */  addiu     $s4, $sp, 0x28
/* E2CB4C 802BC41C AFB7004C */  sw        $s7, 0x4c($sp)
/* E2CB50 802BC420 3C178000 */  lui       $s7, 0x8000
/* E2CB54 802BC424 AFBF0054 */  sw        $ra, 0x54($sp)
/* E2CB58 802BC428 AFB20038 */  sw        $s2, 0x38($sp)
/* E2CB5C 802BC42C AFB10034 */  sw        $s1, 0x34($sp)
/* E2CB60 802BC430 AFB00030 */  sw        $s0, 0x30($sp)
/* E2CB64 802BC434 F7BC0078 */  sdc1      $f28, 0x78($sp)
/* E2CB68 802BC438 F7B80068 */  sdc1      $f24, 0x68($sp)
/* E2CB6C 802BC43C F7B60060 */  sdc1      $f22, 0x60($sp)
/* E2CB70 802BC440 F7B40058 */  sdc1      $f20, 0x58($sp)
/* E2CB74 802BC444 8FD20040 */  lw        $s2, 0x40($fp)
/* E2CB78 802BC448 4600D706 */  mov.s     $f28, $f26
/* E2CB7C 802BC44C 4600D606 */  mov.s     $f24, $f26
/* E2CB80 802BC450 0240882D */  daddu     $s1, $s2, $zero
/* E2CB84 802BC454 0240802D */  daddu     $s0, $s2, $zero
.L802BC458:
/* E2CB88 802BC458 82230008 */  lb        $v1, 8($s1)
/* E2CB8C 802BC45C 24020001 */  addiu     $v0, $zero, 1
/* E2CB90 802BC460 10620028 */  beq       $v1, $v0, .L802BC504
/* E2CB94 802BC464 28620002 */   slti     $v0, $v1, 2
/* E2CB98 802BC468 10400005 */  beqz      $v0, .L802BC480
/* E2CB9C 802BC46C 24020002 */   addiu    $v0, $zero, 2
/* E2CBA0 802BC470 10600009 */  beqz      $v1, .L802BC498
/* E2CBA4 802BC474 00000000 */   nop
/* E2CBA8 802BC478 080AF169 */  j         .L802BC5A4
/* E2CBAC 802BC47C 00000000 */   nop
.L802BC480:
/* E2CBB0 802BC480 10620029 */  beq       $v1, $v0, .L802BC528
/* E2CBB4 802BC484 24020003 */   addiu    $v0, $zero, 3
/* E2CBB8 802BC488 50620046 */  beql      $v1, $v0, .L802BC5A4
/* E2CBBC 802BC48C 26730001 */   addiu    $s3, $s3, 1
/* E2CBC0 802BC490 080AF169 */  j         .L802BC5A4
/* E2CBC4 802BC494 00000000 */   nop
.L802BC498:
/* E2CBC8 802BC498 3C014000 */  lui       $at, 0x4000
/* E2CBCC 802BC49C 4481E000 */  mtc1      $at, $f28
/* E2CBD0 802BC4A0 92220020 */  lbu       $v0, 0x20($s1)
/* E2CBD4 802BC4A4 C61A0028 */  lwc1      $f26, 0x28($s0)
/* E2CBD8 802BC4A8 3C014120 */  lui       $at, 0x4120
/* E2CBDC 802BC4AC 44810000 */  mtc1      $at, $f0
/* E2CBE0 802BC4B0 44801000 */  mtc1      $zero, $f2
/* E2CBE4 802BC4B4 44822000 */  mtc1      $v0, $f4
/* E2CBE8 802BC4B8 00000000 */  nop
/* E2CBEC 802BC4BC 46802120 */  cvt.s.w   $f4, $f4
/* E2CBF0 802BC4C0 461A103E */  c.le.s    $f2, $f26
/* E2CBF4 802BC4C4 00000000 */  nop
/* E2CBF8 802BC4C8 45000006 */  bc1f      .L802BC4E4
/* E2CBFC 802BC4CC 46002603 */   div.s    $f24, $f4, $f0
/* E2CC00 802BC4D0 3C01802C */  lui       $at, %hi(D_802BCFD8)
/* E2CC04 802BC4D4 D422CFD8 */  ldc1      $f2, %lo(D_802BCFD8)($at)
/* E2CC08 802BC4D8 4600D021 */  cvt.d.s   $f0, $f26
/* E2CC0C 802BC4DC 080AF13E */  j         .L802BC4F8
/* E2CC10 802BC4E0 46220001 */   sub.d    $f0, $f0, $f2
.L802BC4E4:
/* E2CC14 802BC4E4 3C013FE0 */  lui       $at, 0x3fe0
/* E2CC18 802BC4E8 44811800 */  mtc1      $at, $f3
/* E2CC1C 802BC4EC 44801000 */  mtc1      $zero, $f2
/* E2CC20 802BC4F0 4600D021 */  cvt.d.s   $f0, $f26
/* E2CC24 802BC4F4 46220000 */  add.d     $f0, $f0, $f2
.L802BC4F8:
/* E2CC28 802BC4F8 46200020 */  cvt.s.d   $f0, $f0
/* E2CC2C 802BC4FC 080AF169 */  j         .L802BC5A4
/* E2CC30 802BC500 E6000028 */   swc1     $f0, 0x28($s0)
.L802BC504:
/* E2CC34 802BC504 3C013F80 */  lui       $at, 0x3f80
/* E2CC38 802BC508 4481C000 */  mtc1      $at, $f24
/* E2CC3C 802BC50C C6020028 */  lwc1      $f2, 0x28($s0)
/* E2CC40 802BC510 3C013E80 */  lui       $at, 0x3e80
/* E2CC44 802BC514 44810000 */  mtc1      $at, $f0
/* E2CC48 802BC518 4480E000 */  mtc1      $zero, $f28
/* E2CC4C 802BC51C 46001682 */  mul.s     $f26, $f2, $f0
/* E2CC50 802BC520 080AF169 */  j         .L802BC5A4
/* E2CC54 802BC524 00000000 */   nop
.L802BC528:
/* E2CC58 802BC528 C6020028 */  lwc1      $f2, 0x28($s0)
/* E2CC5C 802BC52C 3C013F80 */  lui       $at, 0x3f80
/* E2CC60 802BC530 44810000 */  mtc1      $at, $f0
/* E2CC64 802BC534 00000000 */  nop
/* E2CC68 802BC538 46001080 */  add.s     $f2, $f2, $f0
/* E2CC6C 802BC53C 3C0141A0 */  lui       $at, 0x41a0
/* E2CC70 802BC540 44810000 */  mtc1      $at, $f0
/* E2CC74 802BC544 00000000 */  nop
/* E2CC78 802BC548 4602003C */  c.lt.s    $f0, $f2
/* E2CC7C 802BC54C 00000000 */  nop
/* E2CC80 802BC550 45000002 */  bc1f      .L802BC55C
/* E2CC84 802BC554 E6020028 */   swc1     $f2, 0x28($s0)
/* E2CC88 802BC558 E6000028 */  swc1      $f0, 0x28($s0)
.L802BC55C:
/* E2CC8C 802BC55C C6020028 */  lwc1      $f2, 0x28($s0)
/* E2CC90 802BC560 3C01428C */  lui       $at, 0x428c
/* E2CC94 802BC564 44812000 */  mtc1      $at, $f4
/* E2CC98 802BC568 C6000058 */  lwc1      $f0, 0x58($s0)
/* E2CC9C 802BC56C 46041083 */  div.s     $f2, $f2, $f4
/* E2CCA0 802BC570 46020001 */  sub.s     $f0, $f0, $f2
/* E2CCA4 802BC574 E6000058 */  swc1      $f0, 0x58($s0)
/* E2CCA8 802BC578 9222000E */  lbu       $v0, 0xe($s1)
/* E2CCAC 802BC57C 2442FFFB */  addiu     $v0, $v0, -5
/* E2CCB0 802BC580 A222000E */  sb        $v0, 0xe($s1)
/* E2CCB4 802BC584 304200FF */  andi      $v0, $v0, 0xff
/* E2CCB8 802BC588 2C420006 */  sltiu     $v0, $v0, 6
/* E2CCBC 802BC58C 10400005 */  beqz      $v0, .L802BC5A4
/* E2CCC0 802BC590 00000000 */   nop
/* E2CCC4 802BC594 92220008 */  lbu       $v0, 8($s1)
/* E2CCC8 802BC598 A220000E */  sb        $zero, 0xe($s1)
/* E2CCCC 802BC59C 24420001 */  addiu     $v0, $v0, 1
/* E2CCD0 802BC5A0 A2220008 */  sb        $v0, 8($s1)
.L802BC5A4:
/* E2CCD4 802BC5A4 82220008 */  lb        $v0, 8($s1)
/* E2CCD8 802BC5A8 28420002 */  slti      $v0, $v0, 2
/* E2CCDC 802BC5AC 504000D6 */  beql      $v0, $zero, .L802BC908
/* E2CCE0 802BC5B0 26310001 */   addiu    $s1, $s1, 1
/* E2CCE4 802BC5B4 C6020088 */  lwc1      $f2, 0x88($s0)
/* E2CCE8 802BC5B8 44800000 */  mtc1      $zero, $f0
/* E2CCEC 802BC5BC 00000000 */  nop
/* E2CCF0 802BC5C0 4602003E */  c.le.s    $f0, $f2
/* E2CCF4 802BC5C4 3C01802C */  lui       $at, %hi(D_802BCFE0)
/* E2CCF8 802BC5C8 D420CFE0 */  ldc1      $f0, %lo(D_802BCFE0)($at)
/* E2CCFC 802BC5CC 45000003 */  bc1f      .L802BC5DC
/* E2CD00 802BC5D0 460010A1 */   cvt.d.s  $f2, $f2
/* E2CD04 802BC5D4 3C01802C */  lui       $at, %hi(D_802BCFE8)
/* E2CD08 802BC5D8 D420CFE8 */  ldc1      $f0, %lo(D_802BCFE8)($at)
.L802BC5DC:
/* E2CD0C 802BC5DC 46201081 */  sub.d     $f2, $f2, $f0
/* E2CD10 802BC5E0 3C01802C */  lui       $at, %hi(D_802BCFF0)
/* E2CD14 802BC5E4 D424CFF0 */  ldc1      $f4, %lo(D_802BCFF0)($at)
/* E2CD18 802BC5E8 462010A0 */  cvt.s.d   $f2, $f2
/* E2CD1C 802BC5EC 46001021 */  cvt.d.s   $f0, $f2
/* E2CD20 802BC5F0 4624003C */  c.lt.d    $f0, $f4
/* E2CD24 802BC5F4 00000000 */  nop
/* E2CD28 802BC5F8 45000006 */  bc1f      .L802BC614
/* E2CD2C 802BC5FC E6020088 */   swc1     $f2, 0x88($s0)
/* E2CD30 802BC600 3C01C123 */  lui       $at, 0xc123
/* E2CD34 802BC604 34213333 */  ori       $at, $at, 0x3333
/* E2CD38 802BC608 44810000 */  mtc1      $at, $f0
/* E2CD3C 802BC60C 00000000 */  nop
/* E2CD40 802BC610 E6000088 */  swc1      $f0, 0x88($s0)
.L802BC614:
/* E2CD44 802BC614 C6000058 */  lwc1      $f0, 0x58($s0)
/* E2CD48 802BC618 C6020088 */  lwc1      $f2, 0x88($s0)
/* E2CD4C 802BC61C 46020000 */  add.s     $f0, $f0, $f2
/* E2CD50 802BC620 E6000058 */  swc1      $f0, 0x58($s0)
/* E2CD54 802BC624 9222000E */  lbu       $v0, 0xe($s1)
/* E2CD58 802BC628 3C0143B4 */  lui       $at, 0x43b4
/* E2CD5C 802BC62C 44814000 */  mtc1      $at, $f8
/* E2CD60 802BC630 4482A000 */  mtc1      $v0, $f20
/* E2CD64 802BC634 00000000 */  nop
/* E2CD68 802BC638 4680A520 */  cvt.s.w   $f20, $f20
/* E2CD6C 802BC63C 4608A502 */  mul.s     $f20, $f20, $f8
/* E2CD70 802BC640 00000000 */  nop
/* E2CD74 802BC644 3C013B80 */  lui       $at, 0x3b80
/* E2CD78 802BC648 44814000 */  mtc1      $at, $f8
/* E2CD7C 802BC64C 00000000 */  nop
/* E2CD80 802BC650 4608A502 */  mul.s     $f20, $f20, $f8
/* E2CD84 802BC654 00000000 */  nop
/* E2CD88 802BC658 3C0140C9 */  lui       $at, 0x40c9
/* E2CD8C 802BC65C 34210FD0 */  ori       $at, $at, 0xfd0
/* E2CD90 802BC660 44814000 */  mtc1      $at, $f8
/* E2CD94 802BC664 00000000 */  nop
/* E2CD98 802BC668 4608A002 */  mul.s     $f0, $f20, $f8
/* E2CD9C 802BC66C 00000000 */  nop
/* E2CDA0 802BC670 3C0143B4 */  lui       $at, 0x43b4
/* E2CDA4 802BC674 44814000 */  mtc1      $at, $f8
/* E2CDA8 802BC678 00000000 */  nop
/* E2CDAC 802BC67C 46080583 */  div.s     $f22, $f0, $f8
/* E2CDB0 802BC680 0C00A85B */  jal       sin_rad
/* E2CDB4 802BC684 4600B306 */   mov.s    $f12, $f22
/* E2CDB8 802BC688 4600C002 */  mul.s     $f0, $f24, $f0
/* E2CDBC 802BC68C 00000000 */  nop
/* E2CDC0 802BC690 C6020040 */  lwc1      $f2, 0x40($s0)
/* E2CDC4 802BC694 46001080 */  add.s     $f2, $f2, $f0
/* E2CDC8 802BC698 4600B306 */  mov.s     $f12, $f22
/* E2CDCC 802BC69C 0C00A874 */  jal       cos_rad
/* E2CDD0 802BC6A0 E6020040 */   swc1     $f2, 0x40($s0)
/* E2CDD4 802BC6A4 4600C002 */  mul.s     $f0, $f24, $f0
/* E2CDD8 802BC6A8 00000000 */  nop
/* E2CDDC 802BC6AC C6020070 */  lwc1      $f2, 0x70($s0)
/* E2CDE0 802BC6B0 3C040004 */  lui       $a0, 4
/* E2CDE4 802BC6B4 46001080 */  add.s     $f2, $f2, $f0
/* E2CDE8 802BC6B8 C6000040 */  lwc1      $f0, 0x40($s0)
/* E2CDEC 802BC6BC 02C0282D */  daddu     $a1, $s6, $zero
/* E2CDF0 802BC6C0 E6020070 */  swc1      $f2, 0x70($s0)
/* E2CDF4 802BC6C4 C6020058 */  lwc1      $f2, 0x58($s0)
/* E2CDF8 802BC6C8 C6040070 */  lwc1      $f4, 0x70($s0)
/* E2CDFC 802BC6CC 02A0302D */  daddu     $a2, $s5, $zero
/* E2CE00 802BC6D0 E7A00020 */  swc1      $f0, 0x20($sp)
/* E2CE04 802BC6D4 E7A20024 */  swc1      $f2, 0x24($sp)
/* E2CE08 802BC6D8 E7A40028 */  swc1      $f4, 0x28($sp)
/* E2CE0C 802BC6DC 3C014100 */  lui       $at, 0x4100
/* E2CE10 802BC6E0 44814000 */  mtc1      $at, $f8
/* E2CE14 802BC6E4 0280382D */  daddu     $a3, $s4, $zero
/* E2CE18 802BC6E8 E7B80010 */  swc1      $f24, 0x10($sp)
/* E2CE1C 802BC6EC E7B40014 */  swc1      $f20, 0x14($sp)
/* E2CE20 802BC6F0 E7A80018 */  swc1      $f8, 0x18($sp)
/* E2CE24 802BC6F4 0C0376B9 */  jal       func_800DDAE4
/* E2CE28 802BC6F8 E7A8001C */   swc1     $f8, 0x1c($sp)
/* E2CE2C 802BC6FC 10400031 */  beqz      $v0, .L802BC7C4
/* E2CE30 802BC700 3C040004 */   lui      $a0, 4
/* E2CE34 802BC704 C7A00020 */  lwc1      $f0, 0x20($sp)
/* E2CE38 802BC708 C7A20024 */  lwc1      $f2, 0x24($sp)
/* E2CE3C 802BC70C C7A40028 */  lwc1      $f4, 0x28($sp)
/* E2CE40 802BC710 E6000040 */  swc1      $f0, 0x40($s0)
/* E2CE44 802BC714 E6020058 */  swc1      $f2, 0x58($s0)
/* E2CE48 802BC718 E6040070 */  swc1      $f4, 0x70($s0)
/* E2CE4C 802BC71C 9222000E */  lbu       $v0, 0xe($s1)
/* E2CE50 802BC720 3C0143B4 */  lui       $at, 0x43b4
/* E2CE54 802BC724 44814000 */  mtc1      $at, $f8
/* E2CE58 802BC728 24420080 */  addiu     $v0, $v0, 0x80
/* E2CE5C 802BC72C A222000E */  sb        $v0, 0xe($s1)
/* E2CE60 802BC730 304200FF */  andi      $v0, $v0, 0xff
/* E2CE64 802BC734 44820000 */  mtc1      $v0, $f0
/* E2CE68 802BC738 00000000 */  nop
/* E2CE6C 802BC73C 46800020 */  cvt.s.w   $f0, $f0
/* E2CE70 802BC740 46080002 */  mul.s     $f0, $f0, $f8
/* E2CE74 802BC744 00000000 */  nop
/* E2CE78 802BC748 3C013B80 */  lui       $at, 0x3b80
/* E2CE7C 802BC74C 44814000 */  mtc1      $at, $f8
/* E2CE80 802BC750 00000000 */  nop
/* E2CE84 802BC754 46080002 */  mul.s     $f0, $f0, $f8
/* E2CE88 802BC758 00000000 */  nop
/* E2CE8C 802BC75C 3C0140C9 */  lui       $at, 0x40c9
/* E2CE90 802BC760 34210FD0 */  ori       $at, $at, 0xfd0
/* E2CE94 802BC764 44814000 */  mtc1      $at, $f8
/* E2CE98 802BC768 00000000 */  nop
/* E2CE9C 802BC76C 46080002 */  mul.s     $f0, $f0, $f8
/* E2CEA0 802BC770 00000000 */  nop
/* E2CEA4 802BC774 3C0143B4 */  lui       $at, 0x43b4
/* E2CEA8 802BC778 44814000 */  mtc1      $at, $f8
/* E2CEAC 802BC77C 3C014100 */  lui       $at, 0x4100
/* E2CEB0 802BC780 4481C000 */  mtc1      $at, $f24
/* E2CEB4 802BC784 46080583 */  div.s     $f22, $f0, $f8
/* E2CEB8 802BC788 0C00A85B */  jal       sin_rad
/* E2CEBC 802BC78C 4600B306 */   mov.s    $f12, $f22
/* E2CEC0 802BC790 46180002 */  mul.s     $f0, $f0, $f24
/* E2CEC4 802BC794 00000000 */  nop
/* E2CEC8 802BC798 C6020040 */  lwc1      $f2, 0x40($s0)
/* E2CECC 802BC79C 46001080 */  add.s     $f2, $f2, $f0
/* E2CED0 802BC7A0 4600B306 */  mov.s     $f12, $f22
/* E2CED4 802BC7A4 0C00A874 */  jal       cos_rad
/* E2CED8 802BC7A8 E6020040 */   swc1     $f2, 0x40($s0)
/* E2CEDC 802BC7AC 46180002 */  mul.s     $f0, $f0, $f24
/* E2CEE0 802BC7B0 00000000 */  nop
/* E2CEE4 802BC7B4 C6020070 */  lwc1      $f2, 0x70($s0)
/* E2CEE8 802BC7B8 46001080 */  add.s     $f2, $f2, $f0
/* E2CEEC 802BC7BC E6020070 */  swc1      $f2, 0x70($s0)
/* E2CEF0 802BC7C0 3C040004 */  lui       $a0, 4
.L802BC7C4:
/* E2CEF4 802BC7C4 02C0282D */  daddu     $a1, $s6, $zero
/* E2CEF8 802BC7C8 02A0302D */  daddu     $a2, $s5, $zero
/* E2CEFC 802BC7CC 0280382D */  daddu     $a3, $s4, $zero
/* E2CF00 802BC7D0 27A2002C */  addiu     $v0, $sp, 0x2c
/* E2CF04 802BC7D4 C6020040 */  lwc1      $f2, 0x40($s0)
/* E2CF08 802BC7D8 C6040058 */  lwc1      $f4, 0x58($s0)
/* E2CF0C 802BC7DC C6000088 */  lwc1      $f0, 0x88($s0)
/* E2CF10 802BC7E0 C6060070 */  lwc1      $f6, 0x70($s0)
/* E2CF14 802BC7E4 46000005 */  abs.s     $f0, $f0
/* E2CF18 802BC7E8 E7A20020 */  swc1      $f2, 0x20($sp)
/* E2CF1C 802BC7EC E7A40024 */  swc1      $f4, 0x24($sp)
/* E2CF20 802BC7F0 E7A60028 */  swc1      $f6, 0x28($sp)
/* E2CF24 802BC7F4 E7A0002C */  swc1      $f0, 0x2c($sp)
/* E2CF28 802BC7F8 0C0372DF */  jal       func_800DCB7C
/* E2CF2C 802BC7FC AFA20010 */   sw       $v0, 0x10($sp)
/* E2CF30 802BC800 1440000B */  bnez      $v0, .L802BC830
/* E2CF34 802BC804 00000000 */   nop
/* E2CF38 802BC808 C6400004 */  lwc1      $f0, 4($s2)
/* E2CF3C 802BC80C 3C014348 */  lui       $at, 0x4348
/* E2CF40 802BC810 44811000 */  mtc1      $at, $f2
/* E2CF44 802BC814 00000000 */  nop
/* E2CF48 802BC818 46020001 */  sub.s     $f0, $f0, $f2
/* E2CF4C 802BC81C C7A20024 */  lwc1      $f2, 0x24($sp)
/* E2CF50 802BC820 4600103C */  c.lt.s    $f2, $f0
/* E2CF54 802BC824 00000000 */  nop
/* E2CF58 802BC828 45000010 */  bc1f      .L802BC86C
/* E2CF5C 802BC82C 00000000 */   nop
.L802BC830:
/* E2CF60 802BC830 92220008 */  lbu       $v0, 8($s1)
/* E2CF64 802BC834 24420001 */  addiu     $v0, $v0, 1
/* E2CF68 802BC838 A2220008 */  sb        $v0, 8($s1)
/* E2CF6C 802BC83C C6000088 */  lwc1      $f0, 0x88($s0)
/* E2CF70 802BC840 C7A20024 */  lwc1      $f2, 0x24($sp)
/* E2CF74 802BC844 46000005 */  abs.s     $f0, $f0
/* E2CF78 802BC848 46001080 */  add.s     $f2, $f2, $f0
/* E2CF7C 802BC84C E61C0088 */  swc1      $f28, 0x88($s0)
/* E2CF80 802BC850 E6020058 */  swc1      $f2, 0x58($s0)
/* E2CF84 802BC854 82230008 */  lb        $v1, 8($s1)
/* E2CF88 802BC858 24020002 */  addiu     $v0, $zero, 2
/* E2CF8C 802BC85C 14620003 */  bne       $v1, $v0, .L802BC86C
/* E2CF90 802BC860 240200FE */   addiu    $v0, $zero, 0xfe
/* E2CF94 802BC864 A222000E */  sb        $v0, 0xe($s1)
/* E2CF98 802BC868 AE000028 */  sw        $zero, 0x28($s0)
.L802BC86C:
/* E2CF9C 802BC86C 92220014 */  lbu       $v0, 0x14($s1)
/* E2CFA0 802BC870 44820000 */  mtc1      $v0, $f0
/* E2CFA4 802BC874 00000000 */  nop
/* E2CFA8 802BC878 46800020 */  cvt.s.w   $f0, $f0
/* E2CFAC 802BC87C 461A0000 */  add.s     $f0, $f0, $f26
/* E2CFB0 802BC880 4600F03E */  c.le.s    $f30, $f0
/* E2CFB4 802BC884 00000000 */  nop
/* E2CFB8 802BC888 45010005 */  bc1t      .L802BC8A0
/* E2CFBC 802BC88C 26230014 */   addiu    $v1, $s1, 0x14
/* E2CFC0 802BC890 4600020D */  trunc.w.s $f8, $f0
/* E2CFC4 802BC894 44024000 */  mfc1      $v0, $f8
/* E2CFC8 802BC898 080AF22E */  j         .L802BC8B8
/* E2CFCC 802BC89C A0620000 */   sb       $v0, ($v1)
.L802BC8A0:
/* E2CFD0 802BC8A0 461E0001 */  sub.s     $f0, $f0, $f30
/* E2CFD4 802BC8A4 4600020D */  trunc.w.s $f8, $f0
/* E2CFD8 802BC8A8 44024000 */  mfc1      $v0, $f8
/* E2CFDC 802BC8AC 00000000 */  nop
/* E2CFE0 802BC8B0 00571025 */  or        $v0, $v0, $s7
/* E2CFE4 802BC8B4 A0620000 */  sb        $v0, ($v1)
.L802BC8B8:
/* E2CFE8 802BC8B8 9222001A */  lbu       $v0, 0x1a($s1)
/* E2CFEC 802BC8BC 44820000 */  mtc1      $v0, $f0
/* E2CFF0 802BC8C0 00000000 */  nop
/* E2CFF4 802BC8C4 46800020 */  cvt.s.w   $f0, $f0
/* E2CFF8 802BC8C8 461A0001 */  sub.s     $f0, $f0, $f26
/* E2CFFC 802BC8CC 4600F03E */  c.le.s    $f30, $f0
/* E2D000 802BC8D0 00000000 */  nop
/* E2D004 802BC8D4 45010005 */  bc1t      .L802BC8EC
/* E2D008 802BC8D8 2623001A */   addiu    $v1, $s1, 0x1a
/* E2D00C 802BC8DC 4600020D */  trunc.w.s $f8, $f0
/* E2D010 802BC8E0 44024000 */  mfc1      $v0, $f8
/* E2D014 802BC8E4 080AF241 */  j         .L802BC904
/* E2D018 802BC8E8 A0620000 */   sb       $v0, ($v1)
.L802BC8EC:
/* E2D01C 802BC8EC 461E0001 */  sub.s     $f0, $f0, $f30
/* E2D020 802BC8F0 4600020D */  trunc.w.s $f8, $f0
/* E2D024 802BC8F4 44024000 */  mfc1      $v0, $f8
/* E2D028 802BC8F8 00000000 */  nop
/* E2D02C 802BC8FC 00571025 */  or        $v0, $v0, $s7
/* E2D030 802BC900 A0620000 */  sb        $v0, ($v1)
.L802BC904:
/* E2D034 802BC904 26310001 */  addiu     $s1, $s1, 1
.L802BC908:
/* E2D038 802BC908 26420005 */  addiu     $v0, $s2, 5
/* E2D03C 802BC90C 0222102A */  slt       $v0, $s1, $v0
/* E2D040 802BC910 1440FED1 */  bnez      $v0, .L802BC458
/* E2D044 802BC914 26100004 */   addiu    $s0, $s0, 4
/* E2D048 802BC918 2A620005 */  slti      $v0, $s3, 5
/* E2D04C 802BC91C 14400003 */  bnez      $v0, .L802BC92C
/* E2D050 802BC920 00000000 */   nop
/* E2D054 802BC924 0C043F5A */  jal       exec_entity_updatecmd
/* E2D058 802BC928 03C0202D */   daddu    $a0, $fp, $zero
.L802BC92C:
/* E2D05C 802BC92C 8FBF0054 */  lw        $ra, 0x54($sp)
/* E2D060 802BC930 8FBE0050 */  lw        $fp, 0x50($sp)
/* E2D064 802BC934 8FB7004C */  lw        $s7, 0x4c($sp)
/* E2D068 802BC938 8FB60048 */  lw        $s6, 0x48($sp)
/* E2D06C 802BC93C 8FB50044 */  lw        $s5, 0x44($sp)
/* E2D070 802BC940 8FB40040 */  lw        $s4, 0x40($sp)
/* E2D074 802BC944 8FB3003C */  lw        $s3, 0x3c($sp)
/* E2D078 802BC948 8FB20038 */  lw        $s2, 0x38($sp)
/* E2D07C 802BC94C 8FB10034 */  lw        $s1, 0x34($sp)
/* E2D080 802BC950 8FB00030 */  lw        $s0, 0x30($sp)
/* E2D084 802BC954 D7BE0080 */  ldc1      $f30, 0x80($sp)
/* E2D088 802BC958 D7BC0078 */  ldc1      $f28, 0x78($sp)
/* E2D08C 802BC95C D7BA0070 */  ldc1      $f26, 0x70($sp)
/* E2D090 802BC960 D7B80068 */  ldc1      $f24, 0x68($sp)
/* E2D094 802BC964 D7B60060 */  ldc1      $f22, 0x60($sp)
/* E2D098 802BC968 D7B40058 */  ldc1      $f20, 0x58($sp)
/* E2D09C 802BC96C 03E00008 */  jr        $ra
/* E2D0A0 802BC970 27BD0088 */   addiu    $sp, $sp, 0x88
