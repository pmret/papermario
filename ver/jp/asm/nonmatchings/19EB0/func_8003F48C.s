.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003F48C
/* 1A88C 8003F48C 27BDFF40 */  addiu     $sp, $sp, -0xc0
/* 1A890 8003F490 AFB30074 */  sw        $s3, 0x74($sp)
/* 1A894 8003F494 3C13800B */  lui       $s3, %hi(D_800B0EF0)
/* 1A898 8003F498 26730EF0 */  addiu     $s3, $s3, %lo(D_800B0EF0)
/* 1A89C 8003F49C AFB40078 */  sw        $s4, 0x78($sp)
/* 1A8A0 8003F4A0 3C148011 */  lui       $s4, %hi(D_8010F188)
/* 1A8A4 8003F4A4 2694F188 */  addiu     $s4, $s4, %lo(D_8010F188)
/* 1A8A8 8003F4A8 3C038007 */  lui       $v1, %hi(D_800773E0)
/* 1A8AC 8003F4AC 8C6373E0 */  lw        $v1, %lo(D_800773E0)($v1)
/* 1A8B0 8003F4B0 3C04800B */  lui       $a0, %hi(D_800B1D60)
/* 1A8B4 8003F4B4 24841D60 */  addiu     $a0, $a0, %lo(D_800B1D60)
/* 1A8B8 8003F4B8 AFBF008C */  sw        $ra, 0x8c($sp)
/* 1A8BC 8003F4BC AFBE0088 */  sw        $fp, 0x88($sp)
/* 1A8C0 8003F4C0 AFB70084 */  sw        $s7, 0x84($sp)
/* 1A8C4 8003F4C4 AFB60080 */  sw        $s6, 0x80($sp)
/* 1A8C8 8003F4C8 AFB5007C */  sw        $s5, 0x7c($sp)
/* 1A8CC 8003F4CC AFB20070 */  sw        $s2, 0x70($sp)
/* 1A8D0 8003F4D0 AFB1006C */  sw        $s1, 0x6c($sp)
/* 1A8D4 8003F4D4 AFB00068 */  sw        $s0, 0x68($sp)
/* 1A8D8 8003F4D8 F7BE00B8 */  sdc1      $f30, 0xb8($sp)
/* 1A8DC 8003F4DC F7BC00B0 */  sdc1      $f28, 0xb0($sp)
/* 1A8E0 8003F4E0 F7BA00A8 */  sdc1      $f26, 0xa8($sp)
/* 1A8E4 8003F4E4 F7B800A0 */  sdc1      $f24, 0xa0($sp)
/* 1A8E8 8003F4E8 F7B60098 */  sdc1      $f22, 0x98($sp)
/* 1A8EC 8003F4EC F7B40090 */  sdc1      $f20, 0x90($sp)
/* 1A8F0 8003F4F0 00031080 */  sll       $v0, $v1, 2
/* 1A8F4 8003F4F4 00431021 */  addu      $v0, $v0, $v1
/* 1A8F8 8003F4F8 00021080 */  sll       $v0, $v0, 2
/* 1A8FC 8003F4FC 00431023 */  subu      $v0, $v0, $v1
/* 1A900 8003F500 000218C0 */  sll       $v1, $v0, 3
/* 1A904 8003F504 00431021 */  addu      $v0, $v0, $v1
/* 1A908 8003F508 000210C0 */  sll       $v0, $v0, 3
/* 1A90C 8003F50C 00441021 */  addu      $v0, $v0, $a0
/* 1A910 8003F510 AFA20048 */  sw        $v0, 0x48($sp)
/* 1A914 8003F514 82630005 */  lb        $v1, 5($s3)
/* 1A918 8003F518 24020005 */  addiu     $v0, $zero, 5
/* 1A91C 8003F51C 10620426 */  beq       $v1, $v0, .L800405B8
/* 1A920 8003F520 2402FFFF */   addiu    $v0, $zero, -1
/* 1A924 8003F524 C69000A8 */  lwc1      $f16, 0xa8($s4)
/* 1A928 8003F528 3C014334 */  lui       $at, 0x4334
/* 1A92C 8003F52C 44810000 */  mtc1      $at, $f0
/* 1A930 8003F530 E7B0005C */  swc1      $f16, 0x5c($sp)
/* 1A934 8003F534 AE620014 */  sw        $v0, 0x14($s3)
/* 1A938 8003F538 AE620018 */  sw        $v0, 0x18($s3)
/* 1A93C 8003F53C 8E620000 */  lw        $v0, ($s3)
/* 1A940 8003F540 2403FFFE */  addiu     $v1, $zero, -2
/* 1A944 8003F544 A2600005 */  sb        $zero, 5($s3)
/* 1A948 8003F548 A2600011 */  sb        $zero, 0x11($s3)
/* 1A94C 8003F54C A2600013 */  sb        $zero, 0x13($s3)
/* 1A950 8003F550 4600803C */  c.lt.s    $f16, $f0
/* 1A954 8003F554 00431024 */  and       $v0, $v0, $v1
/* 1A958 8003F558 2403FFFD */  addiu     $v1, $zero, -3
/* 1A95C 8003F55C 00431024 */  and       $v0, $v0, $v1
/* 1A960 8003F560 2403FFFB */  addiu     $v1, $zero, -5
/* 1A964 8003F564 00431024 */  and       $v0, $v0, $v1
/* 1A968 8003F568 AE620000 */  sw        $v0, ($s3)
/* 1A96C 8003F56C C6920028 */  lwc1      $f18, 0x28($s4)
/* 1A970 8003F570 E7B20050 */  swc1      $f18, 0x50($sp)
/* 1A974 8003F574 C690002C */  lwc1      $f16, 0x2c($s4)
/* 1A978 8003F578 E7B00054 */  swc1      $f16, 0x54($sp)
/* 1A97C 8003F57C C6920030 */  lwc1      $f18, 0x30($s4)
/* 1A980 8003F580 45000007 */  bc1f      .L8003F5A0
/* 1A984 8003F584 E7B20058 */   swc1     $f18, 0x58($sp)
/* 1A988 8003F588 8FA80048 */  lw        $t0, 0x48($sp)
/* 1A98C 8003F58C 3C0142B4 */  lui       $at, 0x42b4
/* 1A990 8003F590 44816000 */  mtc1      $at, $f12
/* 1A994 8003F594 C500006C */  lwc1      $f0, 0x6c($t0)
/* 1A998 8003F598 0800FD6D */  j         .L8003F5B4
/* 1A99C 8003F59C 460C0301 */   sub.s    $f12, $f0, $f12
.L8003F5A0:
/* 1A9A0 8003F5A0 8FA80048 */  lw        $t0, 0x48($sp)
/* 1A9A4 8003F5A4 3C0142B4 */  lui       $at, 0x42b4
/* 1A9A8 8003F5A8 44816000 */  mtc1      $at, $f12
/* 1A9AC 8003F5AC C500006C */  lwc1      $f0, 0x6c($t0)
/* 1A9B0 8003F5B0 460C0300 */  add.s     $f12, $f0, $f12
.L8003F5B4:
/* 1A9B4 8003F5B4 0C00A6B9 */  jal       func_80029AE4
/* 1A9B8 8003F5B8 00000000 */   nop
/* 1A9BC 8003F5BC E7A0005C */  swc1      $f0, 0x5c($sp)
/* 1A9C0 8003F5C0 8262000A */  lb        $v0, 0xa($s3)
/* 1A9C4 8003F5C4 10400059 */  beqz      $v0, .L8003F72C
/* 1A9C8 8003F5C8 9263000A */   lbu      $v1, 0xa($s3)
/* 1A9CC 8003F5CC 3C02800A */  lui       $v0, %hi(D_8009A630)
/* 1A9D0 8003F5D0 8C42A630 */  lw        $v0, %lo(D_8009A630)($v0)
/* 1A9D4 8003F5D4 30420040 */  andi      $v0, $v0, 0x40
/* 1A9D8 8003F5D8 14400002 */  bnez      $v0, .L8003F5E4
/* 1A9DC 8003F5DC 2462FFFF */   addiu    $v0, $v1, -1
/* 1A9E0 8003F5E0 A262000A */  sb        $v0, 0xa($s3)
.L8003F5E4:
/* 1A9E4 8003F5E4 86820010 */  lh        $v0, 0x10($s4)
/* 1A9E8 8003F5E8 10400050 */  beqz      $v0, .L8003F72C
/* 1A9EC 8003F5EC 00000000 */   nop
/* 1A9F0 8003F5F0 8E820000 */  lw        $v0, ($s4)
/* 1A9F4 8003F5F4 30422000 */  andi      $v0, $v0, 0x2000
/* 1A9F8 8003F5F8 5440004B */  bnel      $v0, $zero, .L8003F728
/* 1A9FC 8003F5FC 24020001 */   addiu    $v0, $zero, 1
/* 1AA00 8003F600 9262000A */  lbu       $v0, 0xa($s3)
/* 1AA04 8003F604 00021600 */  sll       $v0, $v0, 0x18
/* 1AA08 8003F608 0800FDCA */  j         .L8003F728
/* 1AA0C 8003F60C 00021603 */   sra      $v0, $v0, 0x18
.L8003F610:
/* 1AA10 8003F610 24020001 */  addiu     $v0, $zero, 1
/* 1AA14 8003F614 A2620005 */  sb        $v0, 5($s3)
/* 1AA18 8003F618 A2220005 */  sb        $v0, 5($s1)
/* 1AA1C 8003F61C AE760088 */  sw        $s6, 0x88($s3)
/* 1AA20 8003F620 AE71008C */  sw        $s1, 0x8c($s3)
/* 1AA24 8003F624 A2600004 */  sb        $zero, 4($s3)
/* 1AA28 8003F628 0801016D */  j         .L800405B4
/* 1AA2C 8003F62C A2600006 */   sb       $zero, 6($s3)
.L8003F630:
/* 1AA30 8003F630 8E860028 */  lw        $a2, 0x28($s4)
/* 1AA34 8003F634 8E87002C */  lw        $a3, 0x2c($s4)
/* 1AA38 8003F638 C6800030 */  lwc1      $f0, 0x30($s4)
/* 1AA3C 8003F63C 0000282D */  daddu     $a1, $zero, $zero
/* 1AA40 8003F640 0C053B83 */  jal       func_8014EE0C
/* 1AA44 8003F644 E7A00010 */   swc1     $f0, 0x10($sp)
/* 1AA48 8003F648 C6480038 */  lwc1      $f8, 0x38($s2)
/* 1AA4C 8003F64C C68C0028 */  lwc1      $f12, 0x28($s4)
/* 1AA50 8003F650 460C4201 */  sub.s     $f8, $f8, $f12
/* 1AA54 8003F654 3C013F00 */  lui       $at, 0x3f00
/* 1AA58 8003F658 44815000 */  mtc1      $at, $f10
/* 1AA5C 8003F65C 00000000 */  nop
/* 1AA60 8003F660 460A4202 */  mul.s     $f8, $f8, $f10
/* 1AA64 8003F664 00000000 */  nop
/* 1AA68 8003F668 864200A8 */  lh        $v0, 0xa8($s2)
/* 1AA6C 8003F66C C642003C */  lwc1      $f2, 0x3c($s2)
/* 1AA70 8003F670 44820000 */  mtc1      $v0, $f0
/* 1AA74 8003F674 00000000 */  nop
/* 1AA78 8003F678 46800020 */  cvt.s.w   $f0, $f0
/* 1AA7C 8003F67C 46001080 */  add.s     $f2, $f2, $f0
/* 1AA80 8003F680 868200B0 */  lh        $v0, 0xb0($s4)
/* 1AA84 8003F684 C686002C */  lwc1      $f6, 0x2c($s4)
/* 1AA88 8003F688 44820000 */  mtc1      $v0, $f0
/* 1AA8C 8003F68C 00000000 */  nop
/* 1AA90 8003F690 46800020 */  cvt.s.w   $f0, $f0
/* 1AA94 8003F694 46003000 */  add.s     $f0, $f6, $f0
/* 1AA98 8003F698 46001081 */  sub.s     $f2, $f2, $f0
/* 1AA9C 8003F69C 460A1082 */  mul.s     $f2, $f2, $f10
/* 1AAA0 8003F6A0 00000000 */  nop
/* 1AAA4 8003F6A4 C6840030 */  lwc1      $f4, 0x30($s4)
/* 1AAA8 8003F6A8 C6400040 */  lwc1      $f0, 0x40($s2)
/* 1AAAC 8003F6AC 46040001 */  sub.s     $f0, $f0, $f4
/* 1AAB0 8003F6B0 460A0002 */  mul.s     $f0, $f0, $f10
/* 1AAB4 8003F6B4 00000000 */  nop
/* 1AAB8 8003F6B8 46086300 */  add.s     $f12, $f12, $f8
/* 1AABC 8003F6BC 46023180 */  add.s     $f6, $f6, $f2
/* 1AAC0 8003F6C0 24040003 */  addiu     $a0, $zero, 3
/* 1AAC4 8003F6C4 44056000 */  mfc1      $a1, $f12
/* 1AAC8 8003F6C8 46002100 */  add.s     $f4, $f4, $f0
/* 1AACC 8003F6CC 3C01BF80 */  lui       $at, 0xbf80
/* 1AAD0 8003F6D0 44810000 */  mtc1      $at, $f0
/* 1AAD4 8003F6D4 44063000 */  mfc1      $a2, $f6
/* 1AAD8 8003F6D8 44072000 */  mfc1      $a3, $f4
/* 1AADC 8003F6DC 0080802D */  daddu     $s0, $a0, $zero
/* 1AAE0 8003F6E0 AFA5003C */  sw        $a1, 0x3c($sp)
/* 1AAE4 8003F6E4 AFA60040 */  sw        $a2, 0x40($sp)
/* 1AAE8 8003F6E8 AFA70044 */  sw        $a3, 0x44($sp)
/* 1AAEC 8003F6EC AFA00010 */  sw        $zero, 0x10($sp)
/* 1AAF0 8003F6F0 E7A00014 */  swc1      $f0, 0x14($sp)
/* 1AAF4 8003F6F4 AFA00018 */  sw        $zero, 0x18($sp)
/* 1AAF8 8003F6F8 0C01C05C */  jal       func_80070170
/* 1AAFC 8003F6FC AFB0001C */   sw       $s0, 0x1c($sp)
/* 1AB00 8003F700 A2700005 */  sb        $s0, 5($s3)
/* 1AB04 8003F704 8E820004 */  lw        $v0, 4($s4)
/* 1AB08 8003F708 3C030002 */  lui       $v1, 2
/* 1AB0C 8003F70C 00431025 */  or        $v0, $v0, $v1
/* 1AB10 8003F710 AE820004 */  sw        $v0, 4($s4)
/* 1AB14 8003F714 A2300005 */  sb        $s0, 5($s1)
/* 1AB18 8003F718 AE760088 */  sw        $s6, 0x88($s3)
/* 1AB1C 8003F71C AE71008C */  sw        $s1, 0x8c($s3)
/* 1AB20 8003F720 0801016D */  j         .L800405B4
/* 1AB24 8003F724 A2600004 */   sb       $zero, 4($s3)
.L8003F728:
/* 1AB28 8003F728 A6820010 */  sh        $v0, 0x10($s4)
.L8003F72C:
/* 1AB2C 8003F72C 8262001C */  lb        $v0, 0x1c($s3)
/* 1AB30 8003F730 184003A0 */  blez      $v0, .L800405B4
/* 1AB34 8003F734 AFA0004C */   sw       $zero, 0x4c($sp)
/* 1AB38 8003F738 3C087FFF */  lui       $t0, 0x7fff
/* 1AB3C 8003F73C 3508FFFF */  ori       $t0, $t0, 0xffff
/* 1AB40 8003F740 AFA80060 */  sw        $t0, 0x60($sp)
/* 1AB44 8003F744 27A8003C */  addiu     $t0, $sp, 0x3c
/* 1AB48 8003F748 AFA80064 */  sw        $t0, 0x64($sp)
.L8003F74C:
/* 1AB4C 8003F74C 8FA8004C */  lw        $t0, 0x4c($sp)
/* 1AB50 8003F750 00081080 */  sll       $v0, $t0, 2
/* 1AB54 8003F754 02621021 */  addu      $v0, $s3, $v0
/* 1AB58 8003F758 8C560028 */  lw        $s6, 0x28($v0)
/* 1AB5C 8003F75C 12C00390 */  beqz      $s6, .L800405A0
/* 1AB60 8003F760 00000000 */   nop
/* 1AB64 8003F764 8EC20000 */  lw        $v0, ($s6)
/* 1AB68 8003F768 1840038D */  blez      $v0, .L800405A0
/* 1AB6C 8003F76C 0000A82D */   daddu    $s5, $zero, $zero
/* 1AB70 8003F770 27BE0040 */  addiu     $fp, $sp, 0x40
/* 1AB74 8003F774 27B70044 */  addiu     $s7, $sp, 0x44
/* 1AB78 8003F778 00151080 */  sll       $v0, $s5, 2
.L8003F77C:
/* 1AB7C 8003F77C 02C21021 */  addu      $v0, $s6, $v0
/* 1AB80 8003F780 8C510004 */  lw        $s1, 4($v0)
/* 1AB84 8003F784 12200380 */  beqz      $s1, .L80040588
/* 1AB88 8003F788 00000000 */   nop
/* 1AB8C 8003F78C 8E220000 */  lw        $v0, ($s1)
/* 1AB90 8003F790 30420020 */  andi      $v0, $v0, 0x20
/* 1AB94 8003F794 1440037C */  bnez      $v0, .L80040588
/* 1AB98 8003F798 00000000 */   nop
/* 1AB9C 8003F79C 0C00E9EB */  jal       func_8003A7AC
/* 1ABA0 8003F7A0 86240008 */   lh       $a0, 8($s1)
/* 1ABA4 8003F7A4 0040902D */  daddu     $s2, $v0, $zero
/* 1ABA8 8003F7A8 822200B4 */  lb        $v0, 0xb4($s1)
/* 1ABAC 8003F7AC 922300B4 */  lbu       $v1, 0xb4($s1)
/* 1ABB0 8003F7B0 50400030 */  beql      $v0, $zero, .L8003F874
/* 1ABB4 8003F7B4 3C030020 */   lui      $v1, 0x20
/* 1ABB8 8003F7B8 3C02800A */  lui       $v0, %hi(D_8009A630)
/* 1ABBC 8003F7BC 8C42A630 */  lw        $v0, %lo(D_8009A630)($v0)
/* 1ABC0 8003F7C0 30420040 */  andi      $v0, $v0, 0x40
/* 1ABC4 8003F7C4 54400005 */  bnel      $v0, $zero, .L8003F7DC
/* 1ABC8 8003F7C8 0000102D */   daddu    $v0, $zero, $zero
/* 1ABCC 8003F7CC 2462FFFF */  addiu     $v0, $v1, -1
/* 1ABD0 8003F7D0 A22200B4 */  sb        $v0, 0xb4($s1)
/* 1ABD4 8003F7D4 00021600 */  sll       $v0, $v0, 0x18
/* 1ABD8 8003F7D8 00021603 */  sra       $v0, $v0, 0x18
.L8003F7DC:
/* 1ABDC 8003F7DC 30420001 */  andi      $v0, $v0, 1
/* 1ABE0 8003F7E0 10400007 */  beqz      $v0, .L8003F800
/* 1ABE4 8003F7E4 3C088000 */   lui      $t0, 0x8000
/* 1ABE8 8003F7E8 8E420000 */  lw        $v0, ($s2)
/* 1ABEC 8003F7EC 00481025 */  or        $v0, $v0, $t0
/* 1ABF0 8003F7F0 AE420000 */  sw        $v0, ($s2)
/* 1ABF4 8003F7F4 8E220000 */  lw        $v0, ($s1)
/* 1ABF8 8003F7F8 0800FE06 */  j         .L8003F818
/* 1ABFC 8003F7FC 00481025 */   or       $v0, $v0, $t0
.L8003F800:
/* 1AC00 8003F800 8E420000 */  lw        $v0, ($s2)
/* 1AC04 8003F804 8FA80060 */  lw        $t0, 0x60($sp)
/* 1AC08 8003F808 00481024 */  and       $v0, $v0, $t0
/* 1AC0C 8003F80C AE420000 */  sw        $v0, ($s2)
/* 1AC10 8003F810 8E220000 */  lw        $v0, ($s1)
/* 1AC14 8003F814 00481024 */  and       $v0, $v0, $t0
.L8003F818:
/* 1AC18 8003F818 AE220000 */  sw        $v0, ($s1)
/* 1AC1C 8003F81C 0C0B11EA */  jal       func_802C47A8
/* 1AC20 8003F820 8E24005C */   lw       $a0, 0x5c($s1)
/* 1AC24 8003F824 0040202D */  daddu     $a0, $v0, $zero
/* 1AC28 8003F828 10800003 */  beqz      $a0, .L8003F838
/* 1AC2C 8003F82C 00000000 */   nop
/* 1AC30 8003F830 0C0B11FA */  jal       func_802C47E8
/* 1AC34 8003F834 24050080 */   addiu    $a1, $zero, 0x80
.L8003F838:
/* 1AC38 8003F838 8E240054 */  lw        $a0, 0x54($s1)
/* 1AC3C 8003F83C 0C0B11EA */  jal       func_802C47A8
/* 1AC40 8003F840 00000000 */   nop
/* 1AC44 8003F844 0040202D */  daddu     $a0, $v0, $zero
/* 1AC48 8003F848 10800003 */  beqz      $a0, .L8003F858
/* 1AC4C 8003F84C 00000000 */   nop
/* 1AC50 8003F850 0C0B11FA */  jal       func_802C47E8
/* 1AC54 8003F854 24050080 */   addiu    $a1, $zero, 0x80
.L8003F858:
/* 1AC58 8003F858 8E220000 */  lw        $v0, ($s1)
/* 1AC5C 8003F85C 3C030008 */  lui       $v1, 8
/* 1AC60 8003F860 00431024 */  and       $v0, $v0, $v1
/* 1AC64 8003F864 10400052 */  beqz      $v0, .L8003F9B0
/* 1AC68 8003F868 00000000 */   nop
/* 1AC6C 8003F86C 0800FE5D */  j         .L8003F974
/* 1AC70 8003F870 8E24005C */   lw       $a0, 0x5c($s1)
.L8003F874:
/* 1AC74 8003F874 8E220000 */  lw        $v0, ($s1)
/* 1AC78 8003F878 00431024 */  and       $v0, $v0, $v1
/* 1AC7C 8003F87C 14400035 */  bnez      $v0, .L8003F954
/* 1AC80 8003F880 27A20020 */   addiu    $v0, $sp, 0x20
/* 1AC84 8003F884 3C048007 */  lui       $a0, %hi(D_800773E0)
/* 1AC88 8003F888 8C8473E0 */  lw        $a0, %lo(D_800773E0)($a0)
/* 1AC8C 8003F88C AFA20010 */  sw        $v0, 0x10($sp)
/* 1AC90 8003F890 27A20024 */  addiu     $v0, $sp, 0x24
/* 1AC94 8003F894 AFA20014 */  sw        $v0, 0x14($sp)
/* 1AC98 8003F898 27A20028 */  addiu     $v0, $sp, 0x28
/* 1AC9C 8003F89C AFA20018 */  sw        $v0, 0x18($sp)
/* 1ACA0 8003F8A0 8E450038 */  lw        $a1, 0x38($s2)
/* 1ACA4 8003F8A4 8E46003C */  lw        $a2, 0x3c($s2)
/* 1ACA8 8003F8A8 0C00B872 */  jal       func_8002E1C8
/* 1ACAC 8003F8AC 8E470040 */   lw       $a3, 0x40($s2)
/* 1ACB0 8003F8B0 8FA20020 */  lw        $v0, 0x20($sp)
/* 1ACB4 8003F8B4 244200A0 */  addiu     $v0, $v0, 0xa0
/* 1ACB8 8003F8B8 2C420281 */  sltiu     $v0, $v0, 0x281
/* 1ACBC 8003F8BC 1040000A */  beqz      $v0, .L8003F8E8
/* 1ACC0 8003F8C0 00000000 */   nop
/* 1ACC4 8003F8C4 8FA30024 */  lw        $v1, 0x24($sp)
/* 1ACC8 8003F8C8 2862FF88 */  slti      $v0, $v1, -0x78
/* 1ACCC 8003F8CC 14400006 */  bnez      $v0, .L8003F8E8
/* 1ACD0 8003F8D0 28620169 */   slti     $v0, $v1, 0x169
/* 1ACD4 8003F8D4 10400004 */  beqz      $v0, .L8003F8E8
/* 1ACD8 8003F8D8 00000000 */   nop
/* 1ACDC 8003F8DC 8FA20028 */  lw        $v0, 0x28($sp)
/* 1ACE0 8003F8E0 0441001C */  bgez      $v0, .L8003F954
/* 1ACE4 8003F8E4 00000000 */   nop
.L8003F8E8:
/* 1ACE8 8003F8E8 8E220000 */  lw        $v0, ($s1)
/* 1ACEC 8003F8EC 30420001 */  andi      $v0, $v0, 1
/* 1ACF0 8003F8F0 14400018 */  bnez      $v0, .L8003F954
/* 1ACF4 8003F8F4 3C088000 */   lui      $t0, 0x8000
/* 1ACF8 8003F8F8 8E420000 */  lw        $v0, ($s2)
/* 1ACFC 8003F8FC 00481025 */  or        $v0, $v0, $t0
/* 1AD00 8003F900 AE420000 */  sw        $v0, ($s2)
/* 1AD04 8003F904 8E220000 */  lw        $v0, ($s1)
/* 1AD08 8003F908 8E24005C */  lw        $a0, 0x5c($s1)
/* 1AD0C 8003F90C 00481025 */  or        $v0, $v0, $t0
/* 1AD10 8003F910 0C0B11EA */  jal       func_802C47A8
/* 1AD14 8003F914 AE220000 */   sw       $v0, ($s1)
/* 1AD18 8003F918 0040202D */  daddu     $a0, $v0, $zero
/* 1AD1C 8003F91C 10800003 */  beqz      $a0, .L8003F92C
/* 1AD20 8003F920 00000000 */   nop
/* 1AD24 8003F924 0C0B11FA */  jal       func_802C47E8
/* 1AD28 8003F928 24050080 */   addiu    $a1, $zero, 0x80
.L8003F92C:
/* 1AD2C 8003F92C 8E240054 */  lw        $a0, 0x54($s1)
/* 1AD30 8003F930 0C0B11EA */  jal       func_802C47A8
/* 1AD34 8003F934 00000000 */   nop
/* 1AD38 8003F938 0040202D */  daddu     $a0, $v0, $zero
/* 1AD3C 8003F93C 1080001C */  beqz      $a0, .L8003F9B0
/* 1AD40 8003F940 00000000 */   nop
/* 1AD44 8003F944 0C0B11FA */  jal       func_802C47E8
/* 1AD48 8003F948 24050080 */   addiu    $a1, $zero, 0x80
/* 1AD4C 8003F94C 0800FE6C */  j         .L8003F9B0
/* 1AD50 8003F950 00000000 */   nop
.L8003F954:
/* 1AD54 8003F954 8E420000 */  lw        $v0, ($s2)
/* 1AD58 8003F958 8FA80060 */  lw        $t0, 0x60($sp)
/* 1AD5C 8003F95C 00481024 */  and       $v0, $v0, $t0
/* 1AD60 8003F960 AE420000 */  sw        $v0, ($s2)
/* 1AD64 8003F964 8E220000 */  lw        $v0, ($s1)
/* 1AD68 8003F968 8E24005C */  lw        $a0, 0x5c($s1)
/* 1AD6C 8003F96C 00481024 */  and       $v0, $v0, $t0
/* 1AD70 8003F970 AE220000 */  sw        $v0, ($s1)
.L8003F974:
/* 1AD74 8003F974 0C0B11EA */  jal       func_802C47A8
/* 1AD78 8003F978 00000000 */   nop
/* 1AD7C 8003F97C 0040202D */  daddu     $a0, $v0, $zero
/* 1AD80 8003F980 10800003 */  beqz      $a0, .L8003F990
/* 1AD84 8003F984 00000000 */   nop
/* 1AD88 8003F988 0C0B1220 */  jal       func_802C4880
/* 1AD8C 8003F98C 24050080 */   addiu    $a1, $zero, 0x80
.L8003F990:
/* 1AD90 8003F990 8E240054 */  lw        $a0, 0x54($s1)
/* 1AD94 8003F994 0C0B11EA */  jal       func_802C47A8
/* 1AD98 8003F998 00000000 */   nop
/* 1AD9C 8003F99C 0040202D */  daddu     $a0, $v0, $zero
/* 1ADA0 8003F9A0 10800003 */  beqz      $a0, .L8003F9B0
/* 1ADA4 8003F9A4 00000000 */   nop
/* 1ADA8 8003F9A8 0C0B1220 */  jal       func_802C4880
/* 1ADAC 8003F9AC 24050080 */   addiu    $a1, $zero, 0x80
.L8003F9B0:
/* 1ADB0 8003F9B0 8E230000 */  lw        $v1, ($s1)
/* 1ADB4 8003F9B4 3C088000 */  lui       $t0, 0x8000
/* 1ADB8 8003F9B8 00681024 */  and       $v0, $v1, $t0
/* 1ADBC 8003F9BC 144002F2 */  bnez      $v0, .L80040588
/* 1ADC0 8003F9C0 30620001 */   andi     $v0, $v1, 1
/* 1ADC4 8003F9C4 1040002A */  beqz      $v0, .L8003FA70
/* 1ADC8 8003F9C8 3C020040 */   lui      $v0, 0x40
/* 1ADCC 8003F9CC 00621024 */  and       $v0, $v1, $v0
/* 1ADD0 8003F9D0 14400020 */  bnez      $v0, .L8003FA54
/* 1ADD4 8003F9D4 00000000 */   nop
/* 1ADD8 8003F9D8 8E8200C8 */  lw        $v0, 0xc8($s4)
/* 1ADDC 8003F9DC 16420015 */  bne       $s2, $v0, .L8003FA34
/* 1ADE0 8003F9E0 24033039 */   addiu    $v1, $zero, 0x3039
/* 1ADE4 8003F9E4 C640000C */  lwc1      $f0, 0xc($s2)
/* 1ADE8 8003F9E8 4600040D */  trunc.w.s $f16, $f0
/* 1ADEC 8003F9EC 44028000 */  mfc1      $v0, $f16
/* 1ADF0 8003F9F0 00000000 */  nop
/* 1ADF4 8003F9F4 A62200E0 */  sh        $v0, 0xe0($s1)
/* 1ADF8 8003F9F8 C64C0038 */  lwc1      $f12, 0x38($s2)
/* 1ADFC 8003F9FC C64E0040 */  lwc1      $f14, 0x40($s2)
/* 1AE00 8003FA00 8E860028 */  lw        $a2, 0x28($s4)
/* 1AE04 8003FA04 0C00A710 */  jal       func_80029C40
/* 1AE08 8003FA08 8E870030 */   lw       $a3, 0x30($s4)
/* 1AE0C 8003FA0C E640000C */  swc1      $f0, 0xc($s2)
/* 1AE10 8003FA10 0C0B11EA */  jal       func_802C47A8
/* 1AE14 8003FA14 8E240054 */   lw       $a0, 0x54($s1)
/* 1AE18 8003FA18 0040202D */  daddu     $a0, $v0, $zero
/* 1AE1C 8003FA1C 10800014 */  beqz      $a0, .L8003FA70
/* 1AE20 8003FA20 00000000 */   nop
/* 1AE24 8003FA24 0C0B11FA */  jal       func_802C47E8
/* 1AE28 8003FA28 24050080 */   addiu    $a1, $zero, 0x80
/* 1AE2C 8003FA2C 0800FE9C */  j         .L8003FA70
/* 1AE30 8003FA30 00000000 */   nop
.L8003FA34:
/* 1AE34 8003FA34 862200E0 */  lh        $v0, 0xe0($s1)
/* 1AE38 8003FA38 10430006 */  beq       $v0, $v1, .L8003FA54
/* 1AE3C 8003FA3C 00000000 */   nop
/* 1AE40 8003FA40 44820000 */  mtc1      $v0, $f0
/* 1AE44 8003FA44 00000000 */  nop
/* 1AE48 8003FA48 46800020 */  cvt.s.w   $f0, $f0
/* 1AE4C 8003FA4C E640000C */  swc1      $f0, 0xc($s2)
/* 1AE50 8003FA50 A62300E0 */  sh        $v1, 0xe0($s1)
.L8003FA54:
/* 1AE54 8003FA54 0C0B11EA */  jal       func_802C47A8
/* 1AE58 8003FA58 8E240054 */   lw       $a0, 0x54($s1)
/* 1AE5C 8003FA5C 0040202D */  daddu     $a0, $v0, $zero
/* 1AE60 8003FA60 10800003 */  beqz      $a0, .L8003FA70
/* 1AE64 8003FA64 00000000 */   nop
/* 1AE68 8003FA68 0C0B1220 */  jal       func_802C4880
/* 1AE6C 8003FA6C 24050080 */   addiu    $a1, $zero, 0x80
.L8003FA70:
/* 1AE70 8003FA70 8262000A */  lb        $v0, 0xa($s3)
/* 1AE74 8003FA74 144002C4 */  bnez      $v0, .L80040588
/* 1AE78 8003FA78 24080001 */   addiu    $t0, $zero, 1
/* 1AE7C 8003FA7C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 1AE80 8003FA80 8C42417C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 1AE84 8003FA84 80420074 */  lb        $v0, 0x74($v0)
/* 1AE88 8003FA88 104802BF */  beq       $v0, $t0, .L80040588
/* 1AE8C 8003FA8C 3C030008 */   lui      $v1, 8
/* 1AE90 8003FA90 8E820000 */  lw        $v0, ($s4)
/* 1AE94 8003FA94 00431024 */  and       $v0, $v0, $v1
/* 1AE98 8003FA98 144002BB */  bnez      $v0, .L80040588
/* 1AE9C 8003FA9C 00000000 */   nop
/* 1AEA0 8003FAA0 3C04800A */  lui       $a0, %hi(D_8009A630)
/* 1AEA4 8003FAA4 8C84A630 */  lw        $a0, %lo(D_8009A630)($a0)
/* 1AEA8 8003FAA8 30820040 */  andi      $v0, $a0, 0x40
/* 1AEAC 8003FAAC 144002B6 */  bnez      $v0, .L80040588
/* 1AEB0 8003FAB0 24020009 */   addiu    $v0, $zero, 9
/* 1AEB4 8003FAB4 3C038011 */  lui       $v1, %hi(D_8010ED73)
/* 1AEB8 8003FAB8 8063ED73 */  lb        $v1, %lo(D_8010ED73)($v1)
/* 1AEBC 8003FABC 106202B2 */  beq       $v1, $v0, .L80040588
/* 1AEC0 8003FAC0 00000000 */   nop
/* 1AEC4 8003FAC4 8E220000 */  lw        $v0, ($s1)
/* 1AEC8 8003FAC8 00481024 */  and       $v0, $v0, $t0
/* 1AECC 8003FACC 144002AE */  bnez      $v0, .L80040588
/* 1AED0 8003FAD0 30820F00 */   andi     $v0, $a0, 0xf00
/* 1AED4 8003FAD4 144002AC */  bnez      $v0, .L80040588
/* 1AED8 8003FAD8 00000000 */   nop
/* 1AEDC 8003FADC 0C04E4CF */  jal       func_8013933C
/* 1AEE0 8003FAE0 00000000 */   nop
/* 1AEE4 8003FAE4 144002A8 */  bnez      $v0, .L80040588
/* 1AEE8 8003FAE8 3C021000 */   lui      $v0, 0x1000
/* 1AEEC 8003FAEC 8E230000 */  lw        $v1, ($s1)
/* 1AEF0 8003FAF0 00621824 */  and       $v1, $v1, $v0
/* 1AEF4 8003FAF4 14600007 */  bnez      $v1, .L8003FB14
/* 1AEF8 8003FAF8 00000000 */   nop
/* 1AEFC 8003FAFC 0C03AD5E */  jal       func_800EB578
/* 1AF00 8003FB00 0240202D */   daddu    $a0, $s2, $zero
/* 1AF04 8003FB04 10400003 */  beqz      $v0, .L8003FB14
/* 1AF08 8003FB08 24020006 */   addiu    $v0, $zero, 6
/* 1AF0C 8003FB0C 0801008F */  j         .L8004023C
/* 1AF10 8003FB10 A2620005 */   sb       $v0, 5($s3)
.L8003FB14:
/* 1AF14 8003FB14 C6400038 */  lwc1      $f0, 0x38($s2)
/* 1AF18 8003FB18 C65A003C */  lwc1      $f26, 0x3c($s2)
/* 1AF1C 8003FB1C C658000C */  lwc1      $f24, 0xc($s2)
/* 1AF20 8003FB20 C6420040 */  lwc1      $f2, 0x40($s2)
/* 1AF24 8003FB24 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 1AF28 8003FB28 E7A20030 */  swc1      $f2, 0x30($sp)
/* 1AF2C 8003FB2C 864300A8 */  lh        $v1, 0xa8($s2)
/* 1AF30 8003FB30 964200A6 */  lhu       $v0, 0xa6($s2)
/* 1AF34 8003FB34 4483E000 */  mtc1      $v1, $f28
/* 1AF38 8003FB38 00000000 */  nop
/* 1AF3C 8003FB3C 4680E720 */  cvt.s.w   $f28, $f28
/* 1AF40 8003FB40 00021400 */  sll       $v0, $v0, 0x10
/* 1AF44 8003FB44 00021C03 */  sra       $v1, $v0, 0x10
/* 1AF48 8003FB48 000217C2 */  srl       $v0, $v0, 0x1f
/* 1AF4C 8003FB4C 00621821 */  addu      $v1, $v1, $v0
/* 1AF50 8003FB50 00031843 */  sra       $v1, $v1, 1
/* 1AF54 8003FB54 8E2200DC */  lw        $v0, 0xdc($s1)
/* 1AF58 8003FB58 4483F000 */  mtc1      $v1, $f30
/* 1AF5C 8003FB5C 00000000 */  nop
/* 1AF60 8003FB60 10400020 */  beqz      $v0, .L8003FBE4
/* 1AF64 8003FB64 4680F7A0 */   cvt.s.w  $f30, $f30
/* 1AF68 8003FB68 8642008A */  lh        $v0, 0x8a($s2)
/* 1AF6C 8003FB6C 3C014334 */  lui       $at, 0x4334
/* 1AF70 8003FB70 44810000 */  mtc1      $at, $f0
/* 1AF74 8003FB74 4482C000 */  mtc1      $v0, $f24
/* 1AF78 8003FB78 00000000 */  nop
/* 1AF7C 8003FB7C 4680C620 */  cvt.s.w   $f24, $f24
/* 1AF80 8003FB80 4600C03C */  c.lt.s    $f24, $f0
/* 1AF84 8003FB84 00000000 */  nop
/* 1AF88 8003FB88 45000007 */  bc1f      .L8003FBA8
/* 1AF8C 8003FB8C 00000000 */   nop
/* 1AF90 8003FB90 8FA80048 */  lw        $t0, 0x48($sp)
/* 1AF94 8003FB94 3C0142B4 */  lui       $at, 0x42b4
/* 1AF98 8003FB98 44818000 */  mtc1      $at, $f16
/* 1AF9C 8003FB9C C50C006C */  lwc1      $f12, 0x6c($t0)
/* 1AFA0 8003FBA0 0800FEEF */  j         .L8003FBBC
/* 1AFA4 8003FBA4 46106301 */   sub.s    $f12, $f12, $f16
.L8003FBA8:
/* 1AFA8 8003FBA8 8FA80048 */  lw        $t0, 0x48($sp)
/* 1AFAC 8003FBAC 3C0142B4 */  lui       $at, 0x42b4
/* 1AFB0 8003FBB0 44818000 */  mtc1      $at, $f16
/* 1AFB4 8003FBB4 C50C006C */  lwc1      $f12, 0x6c($t0)
/* 1AFB8 8003FBB8 46106300 */  add.s     $f12, $f12, $f16
.L8003FBBC:
/* 1AFBC 8003FBBC 0C00A6B9 */  jal       func_80029AE4
/* 1AFC0 8003FBC0 00000000 */   nop
/* 1AFC4 8003FBC4 46000606 */  mov.s     $f24, $f0
/* 1AFC8 8003FBC8 27A4002C */  addiu     $a0, $sp, 0x2c
/* 1AFCC 8003FBCC C63200DC */  lwc1      $f18, 0xdc($s1)
/* 1AFD0 8003FBD0 468094A0 */  cvt.s.w   $f18, $f18
/* 1AFD4 8003FBD4 4407C000 */  mfc1      $a3, $f24
/* 1AFD8 8003FBD8 44069000 */  mfc1      $a2, $f18
/* 1AFDC 8003FBDC 0C00A7D7 */  jal       func_80029F5C
/* 1AFE0 8003FBE0 27A50030 */   addiu    $a1, $sp, 0x30
.L8003FBE4:
/* 1AFE4 8003FBE4 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 1AFE8 8003FBE8 C7B00050 */  lwc1      $f16, 0x50($sp)
/* 1AFEC 8003FBEC 46100001 */  sub.s     $f0, $f0, $f16
/* 1AFF0 8003FBF0 46000082 */  mul.s     $f2, $f0, $f0
/* 1AFF4 8003FBF4 00000000 */  nop
/* 1AFF8 8003FBF8 C7B20058 */  lwc1      $f18, 0x58($sp)
/* 1AFFC 8003FBFC C7A00030 */  lwc1      $f0, 0x30($sp)
/* 1B000 8003FC00 46120001 */  sub.s     $f0, $f0, $f18
/* 1B004 8003FC04 46000002 */  mul.s     $f0, $f0, $f0
/* 1B008 8003FC08 00000000 */  nop
/* 1B00C 8003FC0C 46001300 */  add.s     $f12, $f2, $f0
/* 1B010 8003FC10 46006004 */  sqrt.s    $f0, $f12
/* 1B014 8003FC14 46000032 */  c.eq.s    $f0, $f0
/* 1B018 8003FC18 00000000 */  nop
/* 1B01C 8003FC1C 45010003 */  bc1t      .L8003FC2C
/* 1B020 8003FC20 00000000 */   nop
/* 1B024 8003FC24 0C0187B0 */  jal       func_80061EC0
/* 1B028 8003FC28 00000000 */   nop
.L8003FC2C:
/* 1B02C 8003FC2C 928200B4 */  lbu       $v0, 0xb4($s4)
/* 1B030 8003FC30 2442FFFD */  addiu     $v0, $v0, -3
/* 1B034 8003FC34 00021600 */  sll       $v0, $v0, 0x18
/* 1B038 8003FC38 00021E03 */  sra       $v1, $v0, 0x18
/* 1B03C 8003FC3C 2C620010 */  sltiu     $v0, $v1, 0x10
/* 1B040 8003FC40 10400184 */  beqz      $v0, .L80040254
/* 1B044 8003FC44 46000586 */   mov.s    $f22, $f0
/* 1B048 8003FC48 00031080 */  sll       $v0, $v1, 2
/* 1B04C 8003FC4C 3C01800A */  lui       $at, %hi(D_800985D8)
/* 1B050 8003FC50 00220821 */  addu      $at, $at, $v0
/* 1B054 8003FC54 8C2285D8 */  lw        $v0, %lo(D_800985D8)($at)
/* 1B058 8003FC58 00400008 */  jr        $v0
/* 1B05C 8003FC5C 00000000 */   nop
/* 1B060 8003FC60 C7B00050 */  lwc1      $f16, 0x50($sp)
/* 1B064 8003FC64 C68C00A8 */  lwc1      $f12, 0xa8($s4)
/* 1B068 8003FC68 C7B20058 */  lwc1      $f18, 0x58($sp)
/* 1B06C 8003FC6C E7B00034 */  swc1      $f16, 0x34($sp)
/* 1B070 8003FC70 0C00A6B9 */  jal       func_80029AE4
/* 1B074 8003FC74 E7B20038 */   swc1     $f18, 0x38($sp)
/* 1B078 8003FC78 3C014334 */  lui       $at, 0x4334
/* 1B07C 8003FC7C 44811000 */  mtc1      $at, $f2
/* 1B080 8003FC80 C7B40054 */  lwc1      $f20, 0x54($sp)
/* 1B084 8003FC84 4602003C */  c.lt.s    $f0, $f2
/* 1B088 8003FC88 00000000 */  nop
/* 1B08C 8003FC8C 45000010 */  bc1f      .L8003FCD0
/* 1B090 8003FC90 00000000 */   nop
/* 1B094 8003FC94 8FA80048 */  lw        $t0, 0x48($sp)
/* 1B098 8003FC98 3C0142B4 */  lui       $at, 0x42b4
/* 1B09C 8003FC9C 44818000 */  mtc1      $at, $f16
/* 1B0A0 8003FCA0 C50C006C */  lwc1      $f12, 0x6c($t0)
/* 1B0A4 8003FCA4 0C00A6B9 */  jal       func_80029AE4
/* 1B0A8 8003FCA8 46106301 */   sub.s    $f12, $f12, $f16
/* 1B0AC 8003FCAC 8E8200A4 */  lw        $v0, 0xa4($s4)
/* 1B0B0 8003FCB0 3C030100 */  lui       $v1, 0x100
/* 1B0B4 8003FCB4 00431024 */  and       $v0, $v0, $v1
/* 1B0B8 8003FCB8 10400017 */  beqz      $v0, .L8003FD18
/* 1B0BC 8003FCBC 27A40034 */   addiu    $a0, $sp, 0x34
/* 1B0C0 8003FCC0 3C0141F0 */  lui       $at, 0x41f0
/* 1B0C4 8003FCC4 44816000 */  mtc1      $at, $f12
/* 1B0C8 8003FCC8 0800FF43 */  j         .L8003FD0C
/* 1B0CC 8003FCCC 460C0300 */   add.s    $f12, $f0, $f12
.L8003FCD0:
/* 1B0D0 8003FCD0 8FA80048 */  lw        $t0, 0x48($sp)
/* 1B0D4 8003FCD4 3C0142B4 */  lui       $at, 0x42b4
/* 1B0D8 8003FCD8 44818000 */  mtc1      $at, $f16
/* 1B0DC 8003FCDC C50C006C */  lwc1      $f12, 0x6c($t0)
/* 1B0E0 8003FCE0 0C00A6B9 */  jal       func_80029AE4
/* 1B0E4 8003FCE4 46106300 */   add.s    $f12, $f12, $f16
/* 1B0E8 8003FCE8 8E8200A4 */  lw        $v0, 0xa4($s4)
/* 1B0EC 8003FCEC 3C030100 */  lui       $v1, 0x100
/* 1B0F0 8003FCF0 00431024 */  and       $v0, $v0, $v1
/* 1B0F4 8003FCF4 10400008 */  beqz      $v0, .L8003FD18
/* 1B0F8 8003FCF8 27A40034 */   addiu    $a0, $sp, 0x34
/* 1B0FC 8003FCFC 3C0141F0 */  lui       $at, 0x41f0
/* 1B100 8003FD00 44816000 */  mtc1      $at, $f12
/* 1B104 8003FD04 00000000 */  nop
/* 1B108 8003FD08 460C0301 */  sub.s     $f12, $f0, $f12
.L8003FD0C:
/* 1B10C 8003FD0C 0C00A6B9 */  jal       func_80029AE4
/* 1B110 8003FD10 00000000 */   nop
/* 1B114 8003FD14 27A40034 */  addiu     $a0, $sp, 0x34
.L8003FD18:
/* 1B118 8003FD18 3C0641C0 */  lui       $a2, 0x41c0
/* 1B11C 8003FD1C 44070000 */  mfc1      $a3, $f0
/* 1B120 8003FD20 0C00A7D7 */  jal       func_80029F5C
/* 1B124 8003FD24 27A50038 */   addiu    $a1, $sp, 0x38
/* 1B128 8003FD28 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* 1B12C 8003FD2C C7A00034 */  lwc1      $f0, 0x34($sp)
/* 1B130 8003FD30 46001001 */  sub.s     $f0, $f2, $f0
/* 1B134 8003FD34 46000102 */  mul.s     $f4, $f0, $f0
/* 1B138 8003FD38 00000000 */  nop
/* 1B13C 8003FD3C C7A20030 */  lwc1      $f2, 0x30($sp)
/* 1B140 8003FD40 C7A00038 */  lwc1      $f0, 0x38($sp)
/* 1B144 8003FD44 46001001 */  sub.s     $f0, $f2, $f0
/* 1B148 8003FD48 46000002 */  mul.s     $f0, $f0, $f0
/* 1B14C 8003FD4C 00000000 */  nop
/* 1B150 8003FD50 46002300 */  add.s     $f12, $f4, $f0
/* 1B154 8003FD54 46006004 */  sqrt.s    $f0, $f12
/* 1B158 8003FD58 46000032 */  c.eq.s    $f0, $f0
/* 1B15C 8003FD5C 00000000 */  nop
/* 1B160 8003FD60 45010003 */  bc1t      .L8003FD70
/* 1B164 8003FD64 00000000 */   nop
/* 1B168 8003FD68 0C0187B0 */  jal       func_80061EC0
/* 1B16C 8003FD6C 00000000 */   nop
.L8003FD70:
/* 1B170 8003FD70 8E220000 */  lw        $v0, ($s1)
/* 1B174 8003FD74 3C030400 */  lui       $v1, 0x400
/* 1B178 8003FD78 00431024 */  and       $v0, $v0, $v1
/* 1B17C 8003FD7C 14400135 */  bnez      $v0, .L80040254
/* 1B180 8003FD80 46000586 */   mov.s    $f22, $f0
/* 1B184 8003FD84 8E820000 */  lw        $v0, ($s4)
/* 1B188 8003FD88 3C030100 */  lui       $v1, 0x100
/* 1B18C 8003FD8C 00431024 */  and       $v0, $v0, $v1
/* 1B190 8003FD90 10400130 */  beqz      $v0, .L80040254
/* 1B194 8003FD94 00000000 */   nop
/* 1B198 8003FD98 3C014160 */  lui       $at, 0x4160
/* 1B19C 8003FD9C 44819000 */  mtc1      $at, $f18
/* 1B1A0 8003FDA0 00000000 */  nop
/* 1B1A4 8003FDA4 461E9000 */  add.s     $f0, $f18, $f30
/* 1B1A8 8003FDA8 4616003E */  c.le.s    $f0, $f22
/* 1B1AC 8003FDAC 00000000 */  nop
/* 1B1B0 8003FDB0 45010128 */  bc1t      .L80040254
/* 1B1B4 8003FDB4 00000000 */   nop
/* 1B1B8 8003FDB8 461CD000 */  add.s     $f0, $f26, $f28
/* 1B1BC 8003FDBC 4614003C */  c.lt.s    $f0, $f20
/* 1B1C0 8003FDC0 00000000 */  nop
/* 1B1C4 8003FDC4 45010123 */  bc1t      .L80040254
/* 1B1C8 8003FDC8 00000000 */   nop
/* 1B1CC 8003FDCC 3C014190 */  lui       $at, 0x4190
/* 1B1D0 8003FDD0 44818000 */  mtc1      $at, $f16
/* 1B1D4 8003FDD4 00000000 */  nop
/* 1B1D8 8003FDD8 4610A000 */  add.s     $f0, $f20, $f16
/* 1B1DC 8003FDDC 461A003C */  c.lt.s    $f0, $f26
/* 1B1E0 8003FDE0 00000000 */  nop
/* 1B1E4 8003FDE4 4501011B */  bc1t      .L80040254
/* 1B1E8 8003FDE8 00000000 */   nop
/* 1B1EC 8003FDEC 8FA60050 */  lw        $a2, 0x50($sp)
/* 1B1F0 8003FDF0 8FA70058 */  lw        $a3, 0x58($sp)
/* 1B1F4 8003FDF4 C7AC002C */  lwc1      $f12, 0x2c($sp)
/* 1B1F8 8003FDF8 C7AE0030 */  lwc1      $f14, 0x30($sp)
/* 1B1FC 8003FDFC E7BA0040 */  swc1      $f26, 0x40($sp)
/* 1B200 8003FE00 E7AC003C */  swc1      $f12, 0x3c($sp)
/* 1B204 8003FE04 0C00A710 */  jal       func_80029C40
/* 1B208 8003FE08 E7AE0044 */   swc1     $f14, 0x44($sp)
/* 1B20C 8003FE0C 3C040001 */  lui       $a0, 1
/* 1B210 8003FE10 03C0302D */  daddu     $a2, $fp, $zero
/* 1B214 8003FE14 02E0382D */  daddu     $a3, $s7, $zero
/* 1B218 8003FE18 8FA50064 */  lw        $a1, 0x64($sp)
/* 1B21C 8003FE1C 461EF500 */  add.s     $f20, $f30, $f30
/* 1B220 8003FE20 E7B60010 */  swc1      $f22, 0x10($sp)
/* 1B224 8003FE24 E7A00014 */  swc1      $f0, 0x14($sp)
/* 1B228 8003FE28 E7BC0018 */  swc1      $f28, 0x18($sp)
/* 1B22C 8003FE2C 0C0376B1 */  jal       func_800DDAC4
/* 1B230 8003FE30 E7B4001C */   swc1     $f20, 0x1c($sp)
/* 1B234 8003FE34 10400016 */  beqz      $v0, .L8003FE90
/* 1B238 8003FE38 00000000 */   nop
/* 1B23C 8003FE3C C7AC0050 */  lwc1      $f12, 0x50($sp)
/* 1B240 8003FE40 8FA6002C */  lw        $a2, 0x2c($sp)
/* 1B244 8003FE44 8FA70030 */  lw        $a3, 0x30($sp)
/* 1B248 8003FE48 C7AE0058 */  lwc1      $f14, 0x58($sp)
/* 1B24C 8003FE4C C7B20054 */  lwc1      $f18, 0x54($sp)
/* 1B250 8003FE50 46007406 */  mov.s     $f16, $f14
/* 1B254 8003FE54 E7AC003C */  swc1      $f12, 0x3c($sp)
/* 1B258 8003FE58 E7B20040 */  swc1      $f18, 0x40($sp)
/* 1B25C 8003FE5C 0C00A710 */  jal       func_80029C40
/* 1B260 8003FE60 E7B00044 */   swc1     $f16, 0x44($sp)
/* 1B264 8003FE64 3C040001 */  lui       $a0, 1
/* 1B268 8003FE68 03C0302D */  daddu     $a2, $fp, $zero
/* 1B26C 8003FE6C 8FA50064 */  lw        $a1, 0x64($sp)
/* 1B270 8003FE70 02E0382D */  daddu     $a3, $s7, $zero
/* 1B274 8003FE74 E7B60010 */  swc1      $f22, 0x10($sp)
/* 1B278 8003FE78 E7A00014 */  swc1      $f0, 0x14($sp)
/* 1B27C 8003FE7C E7BC0018 */  swc1      $f28, 0x18($sp)
/* 1B280 8003FE80 0C0376B1 */  jal       func_800DDAC4
/* 1B284 8003FE84 E7B4001C */   swc1     $f20, 0x1c($sp)
/* 1B288 8003FE88 144000F2 */  bnez      $v0, .L80040254
/* 1B28C 8003FE8C 00000000 */   nop
.L8003FE90:
/* 1B290 8003FE90 82220007 */  lb        $v0, 7($s1)
/* 1B294 8003FE94 1040000F */  beqz      $v0, .L8003FED4
/* 1B298 8003FE98 00000000 */   nop
/* 1B29C 8003FE9C 86220012 */  lh        $v0, 0x12($s1)
/* 1B2A0 8003FEA0 4482D000 */  mtc1      $v0, $f26
/* 1B2A4 8003FEA4 00000000 */  nop
/* 1B2A8 8003FEA8 4680D6A0 */  cvt.s.w   $f26, $f26
/* 1B2AC 8003FEAC 86220010 */  lh        $v0, 0x10($s1)
/* 1B2B0 8003FEB0 86230014 */  lh        $v1, 0x14($s1)
/* 1B2B4 8003FEB4 44820000 */  mtc1      $v0, $f0
/* 1B2B8 8003FEB8 00000000 */  nop
/* 1B2BC 8003FEBC 46800020 */  cvt.s.w   $f0, $f0
/* 1B2C0 8003FEC0 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 1B2C4 8003FEC4 44830000 */  mtc1      $v1, $f0
/* 1B2C8 8003FEC8 00000000 */  nop
/* 1B2CC 8003FECC 46800020 */  cvt.s.w   $f0, $f0
/* 1B2D0 8003FED0 E7A00030 */  swc1      $f0, 0x30($sp)
.L8003FED4:
/* 1B2D4 8003FED4 C7AC0050 */  lwc1      $f12, 0x50($sp)
/* 1B2D8 8003FED8 C7AE0058 */  lwc1      $f14, 0x58($sp)
/* 1B2DC 8003FEDC 8FA6002C */  lw        $a2, 0x2c($sp)
/* 1B2E0 8003FEE0 8FA70030 */  lw        $a3, 0x30($sp)
/* 1B2E4 8003FEE4 0C00A710 */  jal       func_80029C40
/* 1B2E8 8003FEE8 0000802D */   daddu    $s0, $zero, $zero
/* 1B2EC 8003FEEC C7AE005C */  lwc1      $f14, 0x5c($sp)
/* 1B2F0 8003FEF0 0C00A6FA */  jal       func_80029BE8
/* 1B2F4 8003FEF4 46000306 */   mov.s    $f12, $f0
/* 1B2F8 8003FEF8 C7AC002C */  lwc1      $f12, 0x2c($sp)
/* 1B2FC 8003FEFC C7AE0030 */  lwc1      $f14, 0x30($sp)
/* 1B300 8003FF00 8FA60050 */  lw        $a2, 0x50($sp)
/* 1B304 8003FF04 8FA70058 */  lw        $a3, 0x58($sp)
/* 1B308 8003FF08 0C00A710 */  jal       func_80029C40
/* 1B30C 8003FF0C 46000505 */   abs.s    $f20, $f0
/* 1B310 8003FF10 46000306 */  mov.s     $f12, $f0
/* 1B314 8003FF14 0C00A6FA */  jal       func_80029BE8
/* 1B318 8003FF18 4600C386 */   mov.s    $f14, $f24
/* 1B31C 8003FF1C 3C0142B4 */  lui       $at, 0x42b4
/* 1B320 8003FF20 44819000 */  mtc1      $at, $f18
/* 1B324 8003FF24 3C0142B4 */  lui       $at, 0x42b4
/* 1B328 8003FF28 44818000 */  mtc1      $at, $f16
/* 1B32C 8003FF2C 00000000 */  nop
/* 1B330 8003FF30 4610A03C */  c.lt.s    $f20, $f16
/* 1B334 8003FF34 00000000 */  nop
/* 1B338 8003FF38 45000008 */  bc1f      .L8003FF5C
/* 1B33C 8003FF3C 46000005 */   abs.s    $f0, $f0
/* 1B340 8003FF40 4600803E */  c.le.s    $f16, $f0
/* 1B344 8003FF44 00000000 */  nop
/* 1B348 8003FF48 45030004 */  bc1tl     .L8003FF5C
/* 1B34C 8003FF4C 24100001 */   addiu    $s0, $zero, 1
/* 1B350 8003FF50 3C0142B4 */  lui       $at, 0x42b4
/* 1B354 8003FF54 44819000 */  mtc1      $at, $f18
/* 1B358 8003FF58 00000000 */  nop
.L8003FF5C:
/* 1B35C 8003FF5C 4614903E */  c.le.s    $f18, $f20
/* 1B360 8003FF60 00000000 */  nop
/* 1B364 8003FF64 45000005 */  bc1f      .L8003FF7C
/* 1B368 8003FF68 00000000 */   nop
/* 1B36C 8003FF6C 4612003C */  c.lt.s    $f0, $f18
/* 1B370 8003FF70 00000000 */  nop
/* 1B374 8003FF74 45030001 */  bc1tl     .L8003FF7C
/* 1B378 8003FF78 0000802D */   daddu    $s0, $zero, $zero
.L8003FF7C:
/* 1B37C 8003FF7C 3C0142B4 */  lui       $at, 0x42b4
/* 1B380 8003FF80 44818000 */  mtc1      $at, $f16
/* 1B384 8003FF84 00000000 */  nop
/* 1B388 8003FF88 4610A03C */  c.lt.s    $f20, $f16
/* 1B38C 8003FF8C 00000000 */  nop
/* 1B390 8003FF90 45000005 */  bc1f      .L8003FFA8
/* 1B394 8003FF94 00000000 */   nop
/* 1B398 8003FF98 4610003C */  c.lt.s    $f0, $f16
/* 1B39C 8003FF9C 00000000 */  nop
/* 1B3A0 8003FFA0 45030001 */  bc1tl     .L8003FFA8
/* 1B3A4 8003FFA4 24100001 */   addiu    $s0, $zero, 1
.L8003FFA8:
/* 1B3A8 8003FFA8 120000AA */  beqz      $s0, .L80040254
/* 1B3AC 8003FFAC 240400E1 */   addiu    $a0, $zero, 0xe1
/* 1B3B0 8003FFB0 8E860028 */  lw        $a2, 0x28($s4)
/* 1B3B4 8003FFB4 8E87002C */  lw        $a3, 0x2c($s4)
/* 1B3B8 8003FFB8 C6800030 */  lwc1      $f0, 0x30($s4)
/* 1B3BC 8003FFBC 0000282D */  daddu     $a1, $zero, $zero
/* 1B3C0 8003FFC0 0C053B83 */  jal       func_8014EE0C
/* 1B3C4 8003FFC4 E7A00010 */   swc1     $f0, 0x10($sp)
/* 1B3C8 8003FFC8 3C038011 */  lui       $v1, %hi(D_8010F451)
/* 1B3CC 8003FFCC 9063F451 */  lbu       $v1, %lo(D_8010F451)($v1)
/* 1B3D0 8003FFD0 24020004 */  addiu     $v0, $zero, 4
/* 1B3D4 8003FFD4 A2620005 */  sb        $v0, 5($s3)
/* 1B3D8 8003FFD8 0801008F */  j         .L8004023C
/* 1B3DC 8003FFDC A2630006 */   sb       $v1, 6($s3)
/* 1B3E0 8003FFE0 C7B00050 */  lwc1      $f16, 0x50($sp)
/* 1B3E4 8003FFE4 C7B20058 */  lwc1      $f18, 0x58($sp)
/* 1B3E8 8003FFE8 E7B00034 */  swc1      $f16, 0x34($sp)
/* 1B3EC 8003FFEC E7B20038 */  swc1      $f18, 0x38($sp)
/* 1B3F0 8003FFF0 8E220000 */  lw        $v0, ($s1)
/* 1B3F4 8003FFF4 3C030200 */  lui       $v1, 0x200
/* 1B3F8 8003FFF8 00431024 */  and       $v0, $v0, $v1
/* 1B3FC 8003FFFC 14400095 */  bnez      $v0, .L80040254
/* 1B400 80040000 00000000 */   nop
/* 1B404 80040004 3C014160 */  lui       $at, 0x4160
/* 1B408 80040008 44818000 */  mtc1      $at, $f16
/* 1B40C 8004000C 00000000 */  nop
/* 1B410 80040010 461E8000 */  add.s     $f0, $f16, $f30
/* 1B414 80040014 4616003E */  c.le.s    $f0, $f22
/* 1B418 80040018 00000000 */  nop
/* 1B41C 8004001C 4501015A */  bc1t      .L80040588
/* 1B420 80040020 00000000 */   nop
/* 1B424 80040024 461CD600 */  add.s     $f24, $f26, $f28
/* 1B428 80040028 C7B20054 */  lwc1      $f18, 0x54($sp)
/* 1B42C 8004002C 4612C03C */  c.lt.s    $f24, $f18
/* 1B430 80040030 00000000 */  nop
/* 1B434 80040034 45010154 */  bc1t      .L80040588
/* 1B438 80040038 00000000 */   nop
/* 1B43C 8004003C 3C014214 */  lui       $at, 0x4214
/* 1B440 80040040 44818000 */  mtc1      $at, $f16
/* 1B444 80040044 00000000 */  nop
/* 1B448 80040048 46109000 */  add.s     $f0, $f18, $f16
/* 1B44C 8004004C 461A003C */  c.lt.s    $f0, $f26
/* 1B450 80040050 00000000 */  nop
/* 1B454 80040054 4501014C */  bc1t      .L80040588
/* 1B458 80040058 00000000 */   nop
/* 1B45C 8004005C 8FA60050 */  lw        $a2, 0x50($sp)
/* 1B460 80040060 8FA70058 */  lw        $a3, 0x58($sp)
/* 1B464 80040064 C7AC002C */  lwc1      $f12, 0x2c($sp)
/* 1B468 80040068 C7AE0030 */  lwc1      $f14, 0x30($sp)
/* 1B46C 8004006C E7BA0040 */  swc1      $f26, 0x40($sp)
/* 1B470 80040070 E7AC003C */  swc1      $f12, 0x3c($sp)
/* 1B474 80040074 0C00A710 */  jal       func_80029C40
/* 1B478 80040078 E7AE0044 */   swc1     $f14, 0x44($sp)
/* 1B47C 8004007C 3C040001 */  lui       $a0, 1
/* 1B480 80040080 03C0302D */  daddu     $a2, $fp, $zero
/* 1B484 80040084 02E0382D */  daddu     $a3, $s7, $zero
/* 1B488 80040088 8FA50064 */  lw        $a1, 0x64($sp)
/* 1B48C 8004008C 461EF500 */  add.s     $f20, $f30, $f30
/* 1B490 80040090 E7B60010 */  swc1      $f22, 0x10($sp)
/* 1B494 80040094 E7A00014 */  swc1      $f0, 0x14($sp)
/* 1B498 80040098 E7BC0018 */  swc1      $f28, 0x18($sp)
/* 1B49C 8004009C 0C0376B1 */  jal       func_800DDAC4
/* 1B4A0 800400A0 E7B4001C */   swc1     $f20, 0x1c($sp)
/* 1B4A4 800400A4 10400016 */  beqz      $v0, .L80040100
/* 1B4A8 800400A8 00000000 */   nop
/* 1B4AC 800400AC C7AC0050 */  lwc1      $f12, 0x50($sp)
/* 1B4B0 800400B0 8FA6002C */  lw        $a2, 0x2c($sp)
/* 1B4B4 800400B4 8FA70030 */  lw        $a3, 0x30($sp)
/* 1B4B8 800400B8 C7AE0058 */  lwc1      $f14, 0x58($sp)
/* 1B4BC 800400BC C7B20054 */  lwc1      $f18, 0x54($sp)
/* 1B4C0 800400C0 46007406 */  mov.s     $f16, $f14
/* 1B4C4 800400C4 E7AC003C */  swc1      $f12, 0x3c($sp)
/* 1B4C8 800400C8 E7B20040 */  swc1      $f18, 0x40($sp)
/* 1B4CC 800400CC 0C00A710 */  jal       func_80029C40
/* 1B4D0 800400D0 E7B00044 */   swc1     $f16, 0x44($sp)
/* 1B4D4 800400D4 3C040001 */  lui       $a0, 1
/* 1B4D8 800400D8 03C0302D */  daddu     $a2, $fp, $zero
/* 1B4DC 800400DC 8FA50064 */  lw        $a1, 0x64($sp)
/* 1B4E0 800400E0 02E0382D */  daddu     $a3, $s7, $zero
/* 1B4E4 800400E4 E7B60010 */  swc1      $f22, 0x10($sp)
/* 1B4E8 800400E8 E7A00014 */  swc1      $f0, 0x14($sp)
/* 1B4EC 800400EC E7BC0018 */  swc1      $f28, 0x18($sp)
/* 1B4F0 800400F0 0C0376B1 */  jal       func_800DDAC4
/* 1B4F4 800400F4 E7B4001C */   swc1     $f20, 0x1c($sp)
/* 1B4F8 800400F8 14400056 */  bnez      $v0, .L80040254
/* 1B4FC 800400FC 00000000 */   nop
.L80040100:
/* 1B500 80040100 3C014214 */  lui       $at, 0x4214
/* 1B504 80040104 44819000 */  mtc1      $at, $f18
/* 1B508 80040108 3C013F00 */  lui       $at, 0x3f00
/* 1B50C 8004010C 44818000 */  mtc1      $at, $f16
/* 1B510 80040110 00000000 */  nop
/* 1B514 80040114 46109002 */  mul.s     $f0, $f18, $f16
/* 1B518 80040118 00000000 */  nop
/* 1B51C 8004011C C7B20054 */  lwc1      $f18, 0x54($sp)
/* 1B520 80040120 46009000 */  add.s     $f0, $f18, $f0
/* 1B524 80040124 4600C03C */  c.lt.s    $f24, $f0
/* 1B528 80040128 00000000 */  nop
/* 1B52C 8004012C 45000015 */  bc1f      .L80040184
/* 1B530 80040130 0000802D */   daddu    $s0, $zero, $zero
/* 1B534 80040134 928300B4 */  lbu       $v1, 0xb4($s4)
/* 1B538 80040138 2462FFF8 */  addiu     $v0, $v1, -8
/* 1B53C 8004013C 2C420004 */  sltiu     $v0, $v0, 4
/* 1B540 80040140 54400010 */  bnel      $v0, $zero, .L80040184
/* 1B544 80040144 24100001 */   addiu    $s0, $zero, 1
/* 1B548 80040148 00031600 */  sll       $v0, $v1, 0x18
/* 1B54C 8004014C 00021E03 */  sra       $v1, $v0, 0x18
/* 1B550 80040150 2402000D */  addiu     $v0, $zero, 0xd
/* 1B554 80040154 10620007 */  beq       $v1, $v0, .L80040174
/* 1B558 80040158 2402000E */   addiu    $v0, $zero, 0xe
/* 1B55C 8004015C 10620005 */  beq       $v1, $v0, .L80040174
/* 1B560 80040160 2402000F */   addiu    $v0, $zero, 0xf
/* 1B564 80040164 10620003 */  beq       $v1, $v0, .L80040174
/* 1B568 80040168 24020010 */   addiu    $v0, $zero, 0x10
/* 1B56C 8004016C 14620005 */  bne       $v1, $v0, .L80040184
/* 1B570 80040170 00000000 */   nop
.L80040174:
/* 1B574 80040174 24100001 */  addiu     $s0, $zero, 1
/* 1B578 80040178 3C013F00 */  lui       $at, 0x3f00
/* 1B57C 8004017C 44818000 */  mtc1      $at, $f16
/* 1B580 80040180 00000000 */  nop
.L80040184:
/* 1B584 80040184 4610E002 */  mul.s     $f0, $f28, $f16
/* 1B588 80040188 00000000 */  nop
/* 1B58C 8004018C C7B20054 */  lwc1      $f18, 0x54($sp)
/* 1B590 80040190 3C014214 */  lui       $at, 0x4214
/* 1B594 80040194 44818000 */  mtc1      $at, $f16
/* 1B598 80040198 00000000 */  nop
/* 1B59C 8004019C 46109080 */  add.s     $f2, $f18, $f16
/* 1B5A0 800401A0 4600D000 */  add.s     $f0, $f26, $f0
/* 1B5A4 800401A4 4600103C */  c.lt.s    $f2, $f0
/* 1B5A8 800401A8 00000000 */  nop
/* 1B5AC 800401AC 45030001 */  bc1tl     .L800401B4
/* 1B5B0 800401B0 0000802D */   daddu    $s0, $zero, $zero
.L800401B4:
/* 1B5B4 800401B4 12000027 */  beqz      $s0, .L80040254
/* 1B5B8 800401B8 00000000 */   nop
/* 1B5BC 800401BC 3C028011 */  lui       $v0, %hi(D_8010F450)
/* 1B5C0 800401C0 8042F450 */  lb        $v0, %lo(D_8010F450)($v0)
/* 1B5C4 800401C4 0440FD12 */  bltz      $v0, .L8003F610
/* 1B5C8 800401C8 24030002 */   addiu    $v1, $zero, 2
/* 1B5CC 800401CC 928200B4 */  lbu       $v0, 0xb4($s4)
/* 1B5D0 800401D0 A2630005 */  sb        $v1, 5($s3)
/* 1B5D4 800401D4 2442FFFD */  addiu     $v0, $v0, -3
/* 1B5D8 800401D8 00021600 */  sll       $v0, $v0, 0x18
/* 1B5DC 800401DC 00021E03 */  sra       $v1, $v0, 0x18
/* 1B5E0 800401E0 2C62000E */  sltiu     $v0, $v1, 0xe
/* 1B5E4 800401E4 1040000D */  beqz      $v0, .L8004021C
/* 1B5E8 800401E8 00031080 */   sll      $v0, $v1, 2
/* 1B5EC 800401EC 3C01800A */  lui       $at, %hi(D_80098618)
/* 1B5F0 800401F0 00220821 */  addu      $at, $at, $v0
/* 1B5F4 800401F4 8C228618 */  lw        $v0, %lo(D_80098618)($at)
/* 1B5F8 800401F8 00400008 */  jr        $v0
/* 1B5FC 800401FC 00000000 */   nop
/* 1B600 80040200 08010087 */  j         .L8004021C
/* 1B604 80040204 A2600006 */   sb       $zero, 6($s3)
/* 1B608 80040208 24080001 */  addiu     $t0, $zero, 1
/* 1B60C 8004020C 08010087 */  j         .L8004021C
/* 1B610 80040210 A2680006 */   sb       $t0, 6($s3)
/* 1B614 80040214 24020002 */  addiu     $v0, $zero, 2
/* 1B618 80040218 A2620006 */  sb        $v0, 6($s3)
.L8004021C:
/* 1B61C 8004021C 240400E1 */  addiu     $a0, $zero, 0xe1
/* 1B620 80040220 8E860028 */  lw        $a2, 0x28($s4)
/* 1B624 80040224 8E87002C */  lw        $a3, 0x2c($s4)
/* 1B628 80040228 C6800030 */  lwc1      $f0, 0x30($s4)
/* 1B62C 8004022C 0000282D */  daddu     $a1, $zero, $zero
/* 1B630 80040230 0C053B83 */  jal       func_8014EE0C
/* 1B634 80040234 E7A00010 */   swc1     $f0, 0x10($sp)
/* 1B638 80040238 24020002 */  addiu     $v0, $zero, 2
.L8004023C:
/* 1B63C 8004023C A2220005 */  sb        $v0, 5($s1)
/* 1B640 80040240 24080001 */  addiu     $t0, $zero, 1
/* 1B644 80040244 AE760088 */  sw        $s6, 0x88($s3)
/* 1B648 80040248 AE71008C */  sw        $s1, 0x8c($s3)
/* 1B64C 8004024C 0801016D */  j         .L800405B4
/* 1B650 80040250 A2680004 */   sb       $t0, 4($s3)
.L80040254:
/* 1B654 80040254 8E220000 */  lw        $v0, ($s1)
/* 1B658 80040258 3C030100 */  lui       $v1, 0x100
/* 1B65C 8004025C 00431024 */  and       $v0, $v0, $v1
/* 1B660 80040260 144000C9 */  bnez      $v0, .L80040588
/* 1B664 80040264 00000000 */   nop
/* 1B668 80040268 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 1B66C 8004026C C7B00050 */  lwc1      $f16, 0x50($sp)
/* 1B670 80040270 46100001 */  sub.s     $f0, $f0, $f16
/* 1B674 80040274 46000082 */  mul.s     $f2, $f0, $f0
/* 1B678 80040278 00000000 */  nop
/* 1B67C 8004027C C7B20058 */  lwc1      $f18, 0x58($sp)
/* 1B680 80040280 C7A00030 */  lwc1      $f0, 0x30($sp)
/* 1B684 80040284 46120001 */  sub.s     $f0, $f0, $f18
/* 1B688 80040288 46000002 */  mul.s     $f0, $f0, $f0
/* 1B68C 8004028C 00000000 */  nop
/* 1B690 80040290 46001300 */  add.s     $f12, $f2, $f0
/* 1B694 80040294 46006104 */  sqrt.s    $f4, $f12
/* 1B698 80040298 46042032 */  c.eq.s    $f4, $f4
/* 1B69C 8004029C 00000000 */  nop
/* 1B6A0 800402A0 45010004 */  bc1t      .L800402B4
/* 1B6A4 800402A4 00000000 */   nop
/* 1B6A8 800402A8 0C0187B0 */  jal       func_80061EC0
/* 1B6AC 800402AC 00000000 */   nop
/* 1B6B0 800402B0 46000106 */  mov.s     $f4, $f0
.L800402B4:
/* 1B6B4 800402B4 3C014160 */  lui       $at, 0x4160
/* 1B6B8 800402B8 44818000 */  mtc1      $at, $f16
/* 1B6BC 800402BC 00000000 */  nop
/* 1B6C0 800402C0 461E8000 */  add.s     $f0, $f16, $f30
/* 1B6C4 800402C4 3C01800A */  lui       $at, %hi(D_80098650)
/* 1B6C8 800402C8 D4228650 */  ldc1      $f2, %lo(D_80098650)($at)
/* 1B6CC 800402CC 46000021 */  cvt.d.s   $f0, $f0
/* 1B6D0 800402D0 46220002 */  mul.d     $f0, $f0, $f2
/* 1B6D4 800402D4 00000000 */  nop
/* 1B6D8 800402D8 46002586 */  mov.s     $f22, $f4
/* 1B6DC 800402DC 4600B0A1 */  cvt.d.s   $f2, $f22
/* 1B6E0 800402E0 4622003E */  c.le.d    $f0, $f2
/* 1B6E4 800402E4 00000000 */  nop
/* 1B6E8 800402E8 450100A7 */  bc1t      .L80040588
/* 1B6EC 800402EC 00000000 */   nop
/* 1B6F0 800402F0 461CD000 */  add.s     $f0, $f26, $f28
/* 1B6F4 800402F4 C7B20054 */  lwc1      $f18, 0x54($sp)
/* 1B6F8 800402F8 4612003C */  c.lt.s    $f0, $f18
/* 1B6FC 800402FC 00000000 */  nop
/* 1B700 80040300 450100A1 */  bc1t      .L80040588
/* 1B704 80040304 00000000 */   nop
/* 1B708 80040308 3C014214 */  lui       $at, 0x4214
/* 1B70C 8004030C 44818000 */  mtc1      $at, $f16
/* 1B710 80040310 00000000 */  nop
/* 1B714 80040314 46109000 */  add.s     $f0, $f18, $f16
/* 1B718 80040318 461A003C */  c.lt.s    $f0, $f26
/* 1B71C 8004031C 00000000 */  nop
/* 1B720 80040320 45010099 */  bc1t      .L80040588
/* 1B724 80040324 00000000 */   nop
/* 1B728 80040328 8FA60050 */  lw        $a2, 0x50($sp)
/* 1B72C 8004032C 8FA70058 */  lw        $a3, 0x58($sp)
/* 1B730 80040330 C7AC002C */  lwc1      $f12, 0x2c($sp)
/* 1B734 80040334 C7AE0030 */  lwc1      $f14, 0x30($sp)
/* 1B738 80040338 E7BA0040 */  swc1      $f26, 0x40($sp)
/* 1B73C 8004033C E7AC003C */  swc1      $f12, 0x3c($sp)
/* 1B740 80040340 0C00A710 */  jal       func_80029C40
/* 1B744 80040344 E7AE0044 */   swc1     $f14, 0x44($sp)
/* 1B748 80040348 3C040001 */  lui       $a0, 1
/* 1B74C 8004034C 03C0302D */  daddu     $a2, $fp, $zero
/* 1B750 80040350 02E0382D */  daddu     $a3, $s7, $zero
/* 1B754 80040354 8FA50064 */  lw        $a1, 0x64($sp)
/* 1B758 80040358 461EF500 */  add.s     $f20, $f30, $f30
/* 1B75C 8004035C E7B60010 */  swc1      $f22, 0x10($sp)
/* 1B760 80040360 E7A00014 */  swc1      $f0, 0x14($sp)
/* 1B764 80040364 E7BC0018 */  swc1      $f28, 0x18($sp)
/* 1B768 80040368 0C0376B1 */  jal       func_800DDAC4
/* 1B76C 8004036C E7B4001C */   swc1     $f20, 0x1c($sp)
/* 1B770 80040370 10400016 */  beqz      $v0, .L800403CC
/* 1B774 80040374 0000802D */   daddu    $s0, $zero, $zero
/* 1B778 80040378 C7AC0050 */  lwc1      $f12, 0x50($sp)
/* 1B77C 8004037C 8FA6002C */  lw        $a2, 0x2c($sp)
/* 1B780 80040380 8FA70030 */  lw        $a3, 0x30($sp)
/* 1B784 80040384 C7AE0058 */  lwc1      $f14, 0x58($sp)
/* 1B788 80040388 C7B20054 */  lwc1      $f18, 0x54($sp)
/* 1B78C 8004038C 46007406 */  mov.s     $f16, $f14
/* 1B790 80040390 E7AC003C */  swc1      $f12, 0x3c($sp)
/* 1B794 80040394 E7B20040 */  swc1      $f18, 0x40($sp)
/* 1B798 80040398 0C00A710 */  jal       func_80029C40
/* 1B79C 8004039C E7B00044 */   swc1     $f16, 0x44($sp)
/* 1B7A0 800403A0 3C040001 */  lui       $a0, 1
/* 1B7A4 800403A4 03C0302D */  daddu     $a2, $fp, $zero
/* 1B7A8 800403A8 8FA50064 */  lw        $a1, 0x64($sp)
/* 1B7AC 800403AC 02E0382D */  daddu     $a3, $s7, $zero
/* 1B7B0 800403B0 E7B60010 */  swc1      $f22, 0x10($sp)
/* 1B7B4 800403B4 E7A00014 */  swc1      $f0, 0x14($sp)
/* 1B7B8 800403B8 E7BC0018 */  swc1      $f28, 0x18($sp)
/* 1B7BC 800403BC 0C0376B1 */  jal       func_800DDAC4
/* 1B7C0 800403C0 E7B4001C */   swc1     $f20, 0x1c($sp)
/* 1B7C4 800403C4 14400070 */  bnez      $v0, .L80040588
/* 1B7C8 800403C8 0000802D */   daddu    $s0, $zero, $zero
.L800403CC:
/* 1B7CC 800403CC 0C03A73A */  jal       func_800E9CE8
/* 1B7D0 800403D0 24040028 */   addiu    $a0, $zero, 0x28
/* 1B7D4 800403D4 1040000A */  beqz      $v0, .L80040400
/* 1B7D8 800403D8 00000000 */   nop
/* 1B7DC 800403DC 8E220018 */  lw        $v0, 0x18($s1)
/* 1B7E0 800403E0 3C038011 */  lui       $v1, %hi(D_8010F459)
/* 1B7E4 800403E4 8063F459 */  lb        $v1, %lo(D_8010F459)($v1)
/* 1B7E8 800403E8 84420028 */  lh        $v0, 0x28($v0)
/* 1B7EC 800403EC 0062182A */  slt       $v1, $v1, $v0
/* 1B7F0 800403F0 14600003 */  bnez      $v1, .L80040400
/* 1B7F4 800403F4 00000000 */   nop
/* 1B7F8 800403F8 82620012 */  lb        $v0, 0x12($s3)
/* 1B7FC 800403FC 2C500001 */  sltiu     $s0, $v0, 1
.L80040400:
/* 1B800 80040400 0C03A73A */  jal       func_800E9CE8
/* 1B804 80040404 2404002D */   addiu    $a0, $zero, 0x2d
/* 1B808 80040408 54400001 */  bnel      $v0, $zero, .L80040410
/* 1B80C 8004040C 24100001 */   addiu    $s0, $zero, 1
.L80040410:
/* 1B810 80040410 8E820004 */  lw        $v0, 4($s4)
/* 1B814 80040414 3C030001 */  lui       $v1, 1
/* 1B818 80040418 00431024 */  and       $v0, $v0, $v1
/* 1B81C 8004041C 10400007 */  beqz      $v0, .L8004043C
/* 1B820 80040420 3C032000 */   lui      $v1, 0x2000
/* 1B824 80040424 8E220000 */  lw        $v0, ($s1)
/* 1B828 80040428 00431024 */  and       $v0, $v0, $v1
/* 1B82C 8004042C 14400004 */  bnez      $v0, .L80040440
/* 1B830 80040430 3C03FFFD */   lui      $v1, 0xfffd
/* 1B834 80040434 1600FC7E */  bnez      $s0, .L8003F630
/* 1B838 80040438 240400E1 */   addiu    $a0, $zero, 0xe1
.L8004043C:
/* 1B83C 8004043C 3C03FFFD */  lui       $v1, 0xfffd
.L80040440:
/* 1B840 80040440 3463FFFF */  ori       $v1, $v1, 0xffff
/* 1B844 80040444 8E820004 */  lw        $v0, 4($s4)
/* 1B848 80040448 24080001 */  addiu     $t0, $zero, 1
/* 1B84C 8004044C A2680005 */  sb        $t0, 5($s3)
/* 1B850 80040450 00431024 */  and       $v0, $v0, $v1
/* 1B854 80040454 AE820004 */  sw        $v0, 4($s4)
/* 1B858 80040458 A2280005 */  sb        $t0, 5($s1)
/* 1B85C 8004045C AE760088 */  sw        $s6, 0x88($s3)
/* 1B860 80040460 AE71008C */  sw        $s1, 0x8c($s3)
/* 1B864 80040464 C6460038 */  lwc1      $f6, 0x38($s2)
/* 1B868 80040468 C68A0028 */  lwc1      $f10, 0x28($s4)
/* 1B86C 8004046C 460A3181 */  sub.s     $f6, $f6, $f10
/* 1B870 80040470 3C013F00 */  lui       $at, 0x3f00
/* 1B874 80040474 44818000 */  mtc1      $at, $f16
/* 1B878 80040478 00000000 */  nop
/* 1B87C 8004047C 46103182 */  mul.s     $f6, $f6, $f16
/* 1B880 80040480 00000000 */  nop
/* 1B884 80040484 864200A8 */  lh        $v0, 0xa8($s2)
/* 1B888 80040488 C644003C */  lwc1      $f4, 0x3c($s2)
/* 1B88C 8004048C 44820000 */  mtc1      $v0, $f0
/* 1B890 80040490 00000000 */  nop
/* 1B894 80040494 46800020 */  cvt.s.w   $f0, $f0
/* 1B898 80040498 46002100 */  add.s     $f4, $f4, $f0
/* 1B89C 8004049C 868200B0 */  lh        $v0, 0xb0($s4)
/* 1B8A0 800404A0 C688002C */  lwc1      $f8, 0x2c($s4)
/* 1B8A4 800404A4 44820000 */  mtc1      $v0, $f0
/* 1B8A8 800404A8 00000000 */  nop
/* 1B8AC 800404AC 46800020 */  cvt.s.w   $f0, $f0
/* 1B8B0 800404B0 46004000 */  add.s     $f0, $f8, $f0
/* 1B8B4 800404B4 46002101 */  sub.s     $f4, $f4, $f0
/* 1B8B8 800404B8 46102102 */  mul.s     $f4, $f4, $f16
/* 1B8BC 800404BC 00000000 */  nop
/* 1B8C0 800404C0 C6820030 */  lwc1      $f2, 0x30($s4)
/* 1B8C4 800404C4 C6400040 */  lwc1      $f0, 0x40($s2)
/* 1B8C8 800404C8 46020001 */  sub.s     $f0, $f0, $f2
/* 1B8CC 800404CC 46100002 */  mul.s     $f0, $f0, $f16
/* 1B8D0 800404D0 00000000 */  nop
/* 1B8D4 800404D4 46065280 */  add.s     $f10, $f10, $f6
/* 1B8D8 800404D8 46044200 */  add.s     $f8, $f8, $f4
/* 1B8DC 800404DC 24040003 */  addiu     $a0, $zero, 3
/* 1B8E0 800404E0 44055000 */  mfc1      $a1, $f10
/* 1B8E4 800404E4 46001080 */  add.s     $f2, $f2, $f0
/* 1B8E8 800404E8 3C01BF80 */  lui       $at, 0xbf80
/* 1B8EC 800404EC 44810000 */  mtc1      $at, $f0
/* 1B8F0 800404F0 44064000 */  mfc1      $a2, $f8
/* 1B8F4 800404F4 44071000 */  mfc1      $a3, $f2
/* 1B8F8 800404F8 0080102D */  daddu     $v0, $a0, $zero
/* 1B8FC 800404FC AFA5003C */  sw        $a1, 0x3c($sp)
/* 1B900 80040500 AFA60040 */  sw        $a2, 0x40($sp)
/* 1B904 80040504 AFA70044 */  sw        $a3, 0x44($sp)
/* 1B908 80040508 AFA00010 */  sw        $zero, 0x10($sp)
/* 1B90C 8004050C E7A00014 */  swc1      $f0, 0x14($sp)
/* 1B910 80040510 AFA00018 */  sw        $zero, 0x18($sp)
/* 1B914 80040514 0C01C05C */  jal       func_80070170
/* 1B918 80040518 AFA2001C */   sw       $v0, 0x1c($sp)
/* 1B91C 8004051C 82220007 */  lb        $v0, 7($s1)
/* 1B920 80040520 10400005 */  beqz      $v0, .L80040538
/* 1B924 80040524 0000802D */   daddu    $s0, $zero, $zero
/* 1B928 80040528 0C03A73A */  jal       func_800E9CE8
/* 1B92C 8004052C 24040011 */   addiu    $a0, $zero, 0x11
/* 1B930 80040530 2C420001 */  sltiu     $v0, $v0, 1
/* 1B934 80040534 00028040 */  sll       $s0, $v0, 1
.L80040538:
/* 1B938 80040538 0C03A73A */  jal       func_800E9CE8
/* 1B93C 8004053C 2404002A */   addiu    $a0, $zero, 0x2a
/* 1B940 80040540 5040001C */  beql      $v0, $zero, .L800405B4
/* 1B944 80040544 A2700004 */   sb       $s0, 4($s3)
/* 1B948 80040548 8E220018 */  lw        $v0, 0x18($s1)
/* 1B94C 8004054C 3C038011 */  lui       $v1, %hi(D_8010F459)
/* 1B950 80040550 8063F459 */  lb        $v1, %lo(D_8010F459)($v1)
/* 1B954 80040554 84420028 */  lh        $v0, 0x28($v0)
/* 1B958 80040558 0062182A */  slt       $v1, $v1, $v0
/* 1B95C 8004055C 54600015 */  bnel      $v1, $zero, .L800405B4
/* 1B960 80040560 A2700004 */   sb       $s0, 4($s3)
/* 1B964 80040564 8E220000 */  lw        $v0, ($s1)
/* 1B968 80040568 30420040 */  andi      $v0, $v0, 0x40
/* 1B96C 8004056C 54400011 */  bnel      $v0, $zero, .L800405B4
/* 1B970 80040570 A2700004 */   sb       $s0, 4($s3)
/* 1B974 80040574 82620012 */  lb        $v0, 0x12($s3)
/* 1B978 80040578 50400001 */  beql      $v0, $zero, .L80040580
/* 1B97C 8004057C 0000802D */   daddu    $s0, $zero, $zero
.L80040580:
/* 1B980 80040580 0801016D */  j         .L800405B4
/* 1B984 80040584 A2700004 */   sb       $s0, 4($s3)
.L80040588:
/* 1B988 80040588 8EC20000 */  lw        $v0, ($s6)
/* 1B98C 8004058C 26B50001 */  addiu     $s5, $s5, 1
/* 1B990 80040590 02A2102A */  slt       $v0, $s5, $v0
/* 1B994 80040594 1440FC79 */  bnez      $v0, .L8003F77C
/* 1B998 80040598 00151080 */   sll      $v0, $s5, 2
/* 1B99C 8004059C 8FA8004C */  lw        $t0, 0x4c($sp)
.L800405A0:
/* 1B9A0 800405A0 8262001C */  lb        $v0, 0x1c($s3)
/* 1B9A4 800405A4 25080001 */  addiu     $t0, $t0, 1
/* 1B9A8 800405A8 0102102A */  slt       $v0, $t0, $v0
/* 1B9AC 800405AC 1440FC67 */  bnez      $v0, .L8003F74C
/* 1B9B0 800405B0 AFA8004C */   sw       $t0, 0x4c($sp)
.L800405B4:
/* 1B9B4 800405B4 82630005 */  lb        $v1, 5($s3)
.L800405B8:
/* 1B9B8 800405B8 2C620007 */  sltiu     $v0, $v1, 7
/* 1B9BC 800405BC 10400285 */  beqz      $v0, .L80040FD4
/* 1B9C0 800405C0 00031080 */   sll      $v0, $v1, 2
/* 1B9C4 800405C4 3C01800A */  lui       $at, %hi(D_80098658)
/* 1B9C8 800405C8 00220821 */  addu      $at, $at, $v0
/* 1B9CC 800405CC 8C228658 */  lw        $v0, %lo(D_80098658)($at)
/* 1B9D0 800405D0 00400008 */  jr        $v0
/* 1B9D4 800405D4 00000000 */   nop
/* 1B9D8 800405D8 8E71008C */  lw        $s1, 0x8c($s3)
/* 1B9DC 800405DC 8E22003C */  lw        $v0, 0x3c($s1)
/* 1B9E0 800405E0 10400004 */  beqz      $v0, .L800405F4
/* 1B9E4 800405E4 0220B82D */   daddu    $s7, $s1, $zero
/* 1B9E8 800405E8 8E240054 */  lw        $a0, 0x54($s1)
/* 1B9EC 800405EC 0C0B1108 */  jal       func_802C4420
/* 1B9F0 800405F0 00000000 */   nop
.L800405F4:
/* 1B9F4 800405F4 8E220044 */  lw        $v0, 0x44($s1)
/* 1B9F8 800405F8 10400003 */  beqz      $v0, .L80040608
/* 1B9FC 800405FC 00000000 */   nop
/* 1BA00 80040600 0C0B1108 */  jal       func_802C4420
/* 1BA04 80040604 8E24005C */   lw       $a0, 0x5c($s1)
.L80040608:
/* 1BA08 80040608 8E760088 */  lw        $s6, 0x88($s3)
/* 1BA0C 8004060C 8EC20000 */  lw        $v0, ($s6)
/* 1BA10 80040610 1840002B */  blez      $v0, .L800406C0
/* 1BA14 80040614 0000A82D */   daddu    $s5, $zero, $zero
/* 1BA18 80040618 24120001 */  addiu     $s2, $zero, 1
/* 1BA1C 8004061C 02C0802D */  daddu     $s0, $s6, $zero
.L80040620:
/* 1BA20 80040620 8E110004 */  lw        $s1, 4($s0)
/* 1BA24 80040624 12200021 */  beqz      $s1, .L800406AC
/* 1BA28 80040628 00000000 */   nop
/* 1BA2C 8004062C 8E230000 */  lw        $v1, ($s1)
/* 1BA30 80040630 30620008 */  andi      $v0, $v1, 8
/* 1BA34 80040634 10400004 */  beqz      $v0, .L80040648
/* 1BA38 80040638 30620020 */   andi     $v0, $v1, 0x20
/* 1BA3C 8004063C 8E62008C */  lw        $v0, 0x8c($s3)
/* 1BA40 80040640 1622001A */  bne       $s1, $v0, .L800406AC
/* 1BA44 80040644 30620020 */   andi     $v0, $v1, 0x20
.L80040648:
/* 1BA48 80040648 14400018 */  bnez      $v0, .L800406AC
/* 1BA4C 8004064C 00000000 */   nop
/* 1BA50 80040650 8EE20000 */  lw        $v0, ($s7)
/* 1BA54 80040654 30420040 */  andi      $v0, $v0, 0x40
/* 1BA58 80040658 10400004 */  beqz      $v0, .L8004066C
/* 1BA5C 8004065C 00000000 */   nop
/* 1BA60 80040660 8E62008C */  lw        $v0, 0x8c($s3)
/* 1BA64 80040664 16220011 */  bne       $s1, $v0, .L800406AC
/* 1BA68 80040668 00000000 */   nop
.L8004066C:
/* 1BA6C 8004066C 8E220028 */  lw        $v0, 0x28($s1)
/* 1BA70 80040670 1040000E */  beqz      $v0, .L800406AC
/* 1BA74 80040674 2405000A */   addiu    $a1, $zero, 0xa
/* 1BA78 80040678 0040202D */  daddu     $a0, $v0, $zero
/* 1BA7C 8004067C 0000302D */  daddu     $a2, $zero, $zero
/* 1BA80 80040680 0C0B0CF8 */  jal       func_802C33E0
/* 1BA84 80040684 A2320005 */   sb       $s2, 5($s1)
/* 1BA88 80040688 0040202D */  daddu     $a0, $v0, $zero
/* 1BA8C 8004068C AE240040 */  sw        $a0, 0x40($s1)
/* 1BA90 80040690 8C820144 */  lw        $v0, 0x144($a0)
/* 1BA94 80040694 AE220058 */  sw        $v0, 0x58($s1)
/* 1BA98 80040698 AC910148 */  sw        $s1, 0x148($a0)
/* 1BA9C 8004069C 86220008 */  lh        $v0, 8($s1)
/* 1BAA0 800406A0 AC82014C */  sw        $v0, 0x14c($a0)
/* 1BAA4 800406A4 92220006 */  lbu       $v0, 6($s1)
/* 1BAA8 800406A8 A0820004 */  sb        $v0, 4($a0)
.L800406AC:
/* 1BAAC 800406AC 8EC20000 */  lw        $v0, ($s6)
/* 1BAB0 800406B0 26B50001 */  addiu     $s5, $s5, 1
/* 1BAB4 800406B4 02A2102A */  slt       $v0, $s5, $v0
/* 1BAB8 800406B8 1440FFD9 */  bnez      $v0, .L80040620
/* 1BABC 800406BC 26100004 */   addiu    $s0, $s0, 4
.L800406C0:
/* 1BAC0 800406C0 0C038056 */  jal       func_800E0158
/* 1BAC4 800406C4 00000000 */   nop
/* 1BAC8 800406C8 0C03BD6F */  jal       func_800EF5BC
/* 1BACC 800406CC 00000000 */   nop
/* 1BAD0 800406D0 928300B4 */  lbu       $v1, 0xb4($s4)
/* 1BAD4 800406D4 2462FFF1 */  addiu     $v0, $v1, -0xf
/* 1BAD8 800406D8 2C420002 */  sltiu     $v0, $v0, 2
/* 1BADC 800406DC 1440000A */  bnez      $v0, .L80040708
/* 1BAE0 800406E0 00031600 */   sll      $v0, $v1, 0x18
/* 1BAE4 800406E4 00021E03 */  sra       $v1, $v0, 0x18
/* 1BAE8 800406E8 2402000D */  addiu     $v0, $zero, 0xd
/* 1BAEC 800406EC 10620006 */  beq       $v1, $v0, .L80040708
/* 1BAF0 800406F0 2402000E */   addiu    $v0, $zero, 0xe
/* 1BAF4 800406F4 10620004 */  beq       $v1, $v0, .L80040708
/* 1BAF8 800406F8 3C030004 */   lui      $v1, 4
/* 1BAFC 800406FC 8E820000 */  lw        $v0, ($s4)
/* 1BB00 80040700 00431025 */  or        $v0, $v0, $v1
/* 1BB04 80040704 AE820000 */  sw        $v0, ($s4)
.L80040708:
/* 1BB08 80040708 0C03A73A */  jal       func_800E9CE8
/* 1BB0C 8004070C 24040011 */   addiu    $a0, $zero, 0x11
/* 1BB10 80040710 14400013 */  bnez      $v0, .L80040760
/* 1BB14 80040714 24020003 */   addiu    $v0, $zero, 3
/* 1BB18 80040718 82630004 */  lb        $v1, 4($s3)
/* 1BB1C 8004071C 24020002 */  addiu     $v0, $zero, 2
/* 1BB20 80040720 1462000F */  bne       $v1, $v0, .L80040760
/* 1BB24 80040724 24020003 */   addiu    $v0, $zero, 3
/* 1BB28 80040728 0C039761 */  jal       func_800E5D84
/* 1BB2C 8004072C 2404001B */   addiu    $a0, $zero, 0x1b
/* 1BB30 80040730 86240008 */  lh        $a0, 8($s1)
/* 1BB34 80040734 0C00E9EB */  jal       func_8003A7AC
/* 1BB38 80040738 00000000 */   nop
/* 1BB3C 8004073C 0040902D */  daddu     $s2, $v0, $zero
/* 1BB40 80040740 C6400040 */  lwc1      $f0, 0x40($s2)
/* 1BB44 80040744 240400E1 */  addiu     $a0, $zero, 0xe1
/* 1BB48 80040748 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1BB4C 8004074C 8E460038 */  lw        $a2, 0x38($s2)
/* 1BB50 80040750 8E47003C */  lw        $a3, 0x3c($s2)
/* 1BB54 80040754 0C053B83 */  jal       func_8014EE0C
/* 1BB58 80040758 0000282D */   daddu    $a1, $zero, $zero
/* 1BB5C 8004075C 24020003 */  addiu     $v0, $zero, 3
.L80040760:
/* 1BB60 80040760 A2600012 */  sb        $zero, 0x12($s3)
/* 1BB64 80040764 3C01800A */  lui       $at, %hi(D_8009A5E0)
/* 1BB68 80040768 AC22A5E0 */  sw        $v0, %lo(D_8009A5E0)($at)
/* 1BB6C 8004076C 24020001 */  addiu     $v0, $zero, 1
/* 1BB70 80040770 AE600090 */  sw        $zero, 0x90($s3)
/* 1BB74 80040774 080103F1 */  j         .L80040FC4
/* 1BB78 80040778 AE600094 */   sw       $zero, 0x94($s3)
/* 1BB7C 8004077C 8E71008C */  lw        $s1, 0x8c($s3)
/* 1BB80 80040780 8E22003C */  lw        $v0, 0x3c($s1)
/* 1BB84 80040784 10400004 */  beqz      $v0, .L80040798
/* 1BB88 80040788 0220B82D */   daddu    $s7, $s1, $zero
/* 1BB8C 8004078C 8E240054 */  lw        $a0, 0x54($s1)
/* 1BB90 80040790 0C0B1108 */  jal       func_802C4420
/* 1BB94 80040794 00000000 */   nop
.L80040798:
/* 1BB98 80040798 8E220044 */  lw        $v0, 0x44($s1)
/* 1BB9C 8004079C 10400003 */  beqz      $v0, .L800407AC
/* 1BBA0 800407A0 00000000 */   nop
/* 1BBA4 800407A4 0C0B1108 */  jal       func_802C4420
/* 1BBA8 800407A8 8E24005C */   lw       $a0, 0x5c($s1)
.L800407AC:
/* 1BBAC 800407AC 8E760088 */  lw        $s6, 0x88($s3)
/* 1BBB0 800407B0 8EC20000 */  lw        $v0, ($s6)
/* 1BBB4 800407B4 1840002B */  blez      $v0, .L80040864
/* 1BBB8 800407B8 0000A82D */   daddu    $s5, $zero, $zero
/* 1BBBC 800407BC 24120003 */  addiu     $s2, $zero, 3
/* 1BBC0 800407C0 02C0802D */  daddu     $s0, $s6, $zero
.L800407C4:
/* 1BBC4 800407C4 8E110004 */  lw        $s1, 4($s0)
/* 1BBC8 800407C8 12200021 */  beqz      $s1, .L80040850
/* 1BBCC 800407CC 00000000 */   nop
/* 1BBD0 800407D0 8E230000 */  lw        $v1, ($s1)
/* 1BBD4 800407D4 30620008 */  andi      $v0, $v1, 8
/* 1BBD8 800407D8 10400004 */  beqz      $v0, .L800407EC
/* 1BBDC 800407DC 30620020 */   andi     $v0, $v1, 0x20
/* 1BBE0 800407E0 8E62008C */  lw        $v0, 0x8c($s3)
/* 1BBE4 800407E4 1622001A */  bne       $s1, $v0, .L80040850
/* 1BBE8 800407E8 30620020 */   andi     $v0, $v1, 0x20
.L800407EC:
/* 1BBEC 800407EC 14400018 */  bnez      $v0, .L80040850
/* 1BBF0 800407F0 00000000 */   nop
/* 1BBF4 800407F4 8EE20000 */  lw        $v0, ($s7)
/* 1BBF8 800407F8 30420040 */  andi      $v0, $v0, 0x40
/* 1BBFC 800407FC 10400004 */  beqz      $v0, .L80040810
/* 1BC00 80040800 00000000 */   nop
/* 1BC04 80040804 8E62008C */  lw        $v0, 0x8c($s3)
/* 1BC08 80040808 16220011 */  bne       $s1, $v0, .L80040850
/* 1BC0C 8004080C 00000000 */   nop
.L80040810:
/* 1BC10 80040810 8E220028 */  lw        $v0, 0x28($s1)
/* 1BC14 80040814 1040000E */  beqz      $v0, .L80040850
/* 1BC18 80040818 2405000A */   addiu    $a1, $zero, 0xa
/* 1BC1C 8004081C 0040202D */  daddu     $a0, $v0, $zero
/* 1BC20 80040820 0000302D */  daddu     $a2, $zero, $zero
/* 1BC24 80040824 0C0B0CF8 */  jal       func_802C33E0
/* 1BC28 80040828 A2320005 */   sb       $s2, 5($s1)
/* 1BC2C 8004082C 0040202D */  daddu     $a0, $v0, $zero
/* 1BC30 80040830 AE240040 */  sw        $a0, 0x40($s1)
/* 1BC34 80040834 8C820144 */  lw        $v0, 0x144($a0)
/* 1BC38 80040838 AE220058 */  sw        $v0, 0x58($s1)
/* 1BC3C 8004083C AC910148 */  sw        $s1, 0x148($a0)
/* 1BC40 80040840 86220008 */  lh        $v0, 8($s1)
/* 1BC44 80040844 AC82014C */  sw        $v0, 0x14c($a0)
/* 1BC48 80040848 92220006 */  lbu       $v0, 6($s1)
/* 1BC4C 8004084C A0820004 */  sb        $v0, 4($a0)
.L80040850:
/* 1BC50 80040850 8EC20000 */  lw        $v0, ($s6)
/* 1BC54 80040854 26B50001 */  addiu     $s5, $s5, 1
/* 1BC58 80040858 02A2102A */  slt       $v0, $s5, $v0
/* 1BC5C 8004085C 1440FFD9 */  bnez      $v0, .L800407C4
/* 1BC60 80040860 26100004 */   addiu    $s0, $s0, 4
.L80040864:
/* 1BC64 80040864 0C038056 */  jal       func_800E0158
/* 1BC68 80040868 00000000 */   nop
/* 1BC6C 8004086C 0C03BD6F */  jal       func_800EF5BC
/* 1BC70 80040870 00000000 */   nop
/* 1BC74 80040874 24020003 */  addiu     $v0, $zero, 3
/* 1BC78 80040878 A2600012 */  sb        $zero, 0x12($s3)
/* 1BC7C 8004087C 3C01800A */  lui       $at, %hi(D_8009A5E0)
/* 1BC80 80040880 AC22A5E0 */  sw        $v0, %lo(D_8009A5E0)($at)
/* 1BC84 80040884 24020001 */  addiu     $v0, $zero, 1
/* 1BC88 80040888 AE600090 */  sw        $zero, 0x90($s3)
/* 1BC8C 8004088C AE600094 */  sw        $zero, 0x94($s3)
/* 1BC90 80040890 3C01800A */  lui       $at, %hi(D_8009A658)
/* 1BC94 80040894 AC22A658 */  sw        $v0, %lo(D_8009A658)($at)
/* 1BC98 80040898 8E820000 */  lw        $v0, ($s4)
/* 1BC9C 8004089C 3C030004 */  lui       $v1, 4
/* 1BCA0 800408A0 3C01800A */  lui       $at, %hi(D_8009A5B0)
/* 1BCA4 800408A4 AC20A5B0 */  sw        $zero, %lo(D_8009A5B0)($at)
/* 1BCA8 800408A8 00431025 */  or        $v0, $v0, $v1
/* 1BCAC 800408AC 080103F5 */  j         .L80040FD4
/* 1BCB0 800408B0 AE820000 */   sw       $v0, ($s4)
/* 1BCB4 800408B4 8E71008C */  lw        $s1, 0x8c($s3)
/* 1BCB8 800408B8 8E22003C */  lw        $v0, 0x3c($s1)
/* 1BCBC 800408BC 10400004 */  beqz      $v0, .L800408D0
/* 1BCC0 800408C0 0220B82D */   daddu    $s7, $s1, $zero
/* 1BCC4 800408C4 8E240054 */  lw        $a0, 0x54($s1)
/* 1BCC8 800408C8 0C0B1108 */  jal       func_802C4420
/* 1BCCC 800408CC 00000000 */   nop
.L800408D0:
/* 1BCD0 800408D0 8E220044 */  lw        $v0, 0x44($s1)
/* 1BCD4 800408D4 10400003 */  beqz      $v0, .L800408E4
/* 1BCD8 800408D8 00000000 */   nop
/* 1BCDC 800408DC 0C0B1108 */  jal       func_802C4420
/* 1BCE0 800408E0 8E24005C */   lw       $a0, 0x5c($s1)
.L800408E4:
/* 1BCE4 800408E4 8E760088 */  lw        $s6, 0x88($s3)
/* 1BCE8 800408E8 0000802D */  daddu     $s0, $zero, $zero
/* 1BCEC 800408EC 8EC20000 */  lw        $v0, ($s6)
/* 1BCF0 800408F0 18400070 */  blez      $v0, .L80040AB4
/* 1BCF4 800408F4 0200A82D */   daddu    $s5, $s0, $zero
/* 1BCF8 800408F8 241E0003 */  addiu     $fp, $zero, 3
/* 1BCFC 800408FC 3C013F00 */  lui       $at, 0x3f00
/* 1BD00 80040900 4481A000 */  mtc1      $at, $f20
/* 1BD04 80040904 3C01BF80 */  lui       $at, 0xbf80
/* 1BD08 80040908 4481B000 */  mtc1      $at, $f22
/* 1BD0C 8004090C 00151080 */  sll       $v0, $s5, 2
.L80040910:
/* 1BD10 80040910 02C21021 */  addu      $v0, $s6, $v0
/* 1BD14 80040914 8C510004 */  lw        $s1, 4($v0)
/* 1BD18 80040918 12200061 */  beqz      $s1, .L80040AA0
/* 1BD1C 8004091C 00000000 */   nop
/* 1BD20 80040920 8E230000 */  lw        $v1, ($s1)
/* 1BD24 80040924 30620008 */  andi      $v0, $v1, 8
/* 1BD28 80040928 10400004 */  beqz      $v0, .L8004093C
/* 1BD2C 8004092C 30620020 */   andi     $v0, $v1, 0x20
/* 1BD30 80040930 8E62008C */  lw        $v0, 0x8c($s3)
/* 1BD34 80040934 1622005A */  bne       $s1, $v0, .L80040AA0
/* 1BD38 80040938 30620020 */   andi     $v0, $v1, 0x20
.L8004093C:
/* 1BD3C 8004093C 14400058 */  bnez      $v0, .L80040AA0
/* 1BD40 80040940 00000000 */   nop
/* 1BD44 80040944 8EE20000 */  lw        $v0, ($s7)
/* 1BD48 80040948 30420040 */  andi      $v0, $v0, 0x40
/* 1BD4C 8004094C 10400004 */  beqz      $v0, .L80040960
/* 1BD50 80040950 00000000 */   nop
/* 1BD54 80040954 8E62008C */  lw        $v0, 0x8c($s3)
/* 1BD58 80040958 16220051 */  bne       $s1, $v0, .L80040AA0
/* 1BD5C 8004095C 00000000 */   nop
.L80040960:
/* 1BD60 80040960 8E220028 */  lw        $v0, 0x28($s1)
/* 1BD64 80040964 1040001F */  beqz      $v0, .L800409E4
/* 1BD68 80040968 2405000A */   addiu    $a1, $zero, 0xa
/* 1BD6C 8004096C 0000302D */  daddu     $a2, $zero, $zero
/* 1BD70 80040970 0040202D */  daddu     $a0, $v0, $zero
/* 1BD74 80040974 24020002 */  addiu     $v0, $zero, 2
/* 1BD78 80040978 0C0B0CF8 */  jal       func_802C33E0
/* 1BD7C 8004097C A2220005 */   sb       $v0, 5($s1)
/* 1BD80 80040980 0040202D */  daddu     $a0, $v0, $zero
/* 1BD84 80040984 AE240040 */  sw        $a0, 0x40($s1)
/* 1BD88 80040988 8C820144 */  lw        $v0, 0x144($a0)
/* 1BD8C 8004098C AE220058 */  sw        $v0, 0x58($s1)
/* 1BD90 80040990 AC910148 */  sw        $s1, 0x148($a0)
/* 1BD94 80040994 86220008 */  lh        $v0, 8($s1)
/* 1BD98 80040998 AC82014C */  sw        $v0, 0x14c($a0)
/* 1BD9C 8004099C 92220006 */  lbu       $v0, 6($s1)
/* 1BDA0 800409A0 A0820004 */  sb        $v0, 4($a0)
/* 1BDA4 800409A4 0C00E9EB */  jal       func_8003A7AC
/* 1BDA8 800409A8 86240008 */   lh       $a0, 8($s1)
/* 1BDAC 800409AC 0040902D */  daddu     $s2, $v0, $zero
/* 1BDB0 800409B0 C6460038 */  lwc1      $f6, 0x38($s2)
/* 1BDB4 800409B4 C68A0028 */  lwc1      $f10, 0x28($s4)
/* 1BDB8 800409B8 460A3181 */  sub.s     $f6, $f6, $f10
/* 1BDBC 800409BC 46143182 */  mul.s     $f6, $f6, $f20
/* 1BDC0 800409C0 00000000 */  nop
/* 1BDC4 800409C4 864200A8 */  lh        $v0, 0xa8($s2)
/* 1BDC8 800409C8 C642003C */  lwc1      $f2, 0x3c($s2)
/* 1BDCC 800409CC 44820000 */  mtc1      $v0, $f0
/* 1BDD0 800409D0 00000000 */  nop
/* 1BDD4 800409D4 46800020 */  cvt.s.w   $f0, $f0
/* 1BDD8 800409D8 868200B0 */  lh        $v0, 0xb0($s4)
/* 1BDDC 800409DC 0801028B */  j         .L80040A2C
/* 1BDE0 800409E0 46001080 */   add.s    $f2, $f2, $f0
.L800409E4:
/* 1BDE4 800409E4 30620001 */  andi      $v0, $v1, 1
/* 1BDE8 800409E8 1440002D */  bnez      $v0, .L80040AA0
/* 1BDEC 800409EC 00000000 */   nop
/* 1BDF0 800409F0 0C00E9EB */  jal       func_8003A7AC
/* 1BDF4 800409F4 86240008 */   lh       $a0, 8($s1)
/* 1BDF8 800409F8 0040902D */  daddu     $s2, $v0, $zero
/* 1BDFC 800409FC C4460038 */  lwc1      $f6, 0x38($v0)
/* 1BE00 80040A00 C68A0028 */  lwc1      $f10, 0x28($s4)
/* 1BE04 80040A04 460A3181 */  sub.s     $f6, $f6, $f10
/* 1BE08 80040A08 46143182 */  mul.s     $f6, $f6, $f20
/* 1BE0C 80040A0C 00000000 */  nop
/* 1BE10 80040A10 864200A8 */  lh        $v0, 0xa8($s2)
/* 1BE14 80040A14 C642003C */  lwc1      $f2, 0x3c($s2)
/* 1BE18 80040A18 44820000 */  mtc1      $v0, $f0
/* 1BE1C 80040A1C 00000000 */  nop
/* 1BE20 80040A20 46800020 */  cvt.s.w   $f0, $f0
/* 1BE24 80040A24 868200B0 */  lh        $v0, 0xb0($s4)
/* 1BE28 80040A28 46001080 */  add.s     $f2, $f2, $f0
.L80040A2C:
/* 1BE2C 80040A2C C688002C */  lwc1      $f8, 0x2c($s4)
/* 1BE30 80040A30 44820000 */  mtc1      $v0, $f0
/* 1BE34 80040A34 00000000 */  nop
/* 1BE38 80040A38 46800020 */  cvt.s.w   $f0, $f0
/* 1BE3C 80040A3C 46004000 */  add.s     $f0, $f8, $f0
/* 1BE40 80040A40 46001081 */  sub.s     $f2, $f2, $f0
/* 1BE44 80040A44 46141082 */  mul.s     $f2, $f2, $f20
/* 1BE48 80040A48 00000000 */  nop
/* 1BE4C 80040A4C C6840030 */  lwc1      $f4, 0x30($s4)
/* 1BE50 80040A50 C6400040 */  lwc1      $f0, 0x40($s2)
/* 1BE54 80040A54 46040001 */  sub.s     $f0, $f0, $f4
/* 1BE58 80040A58 46140002 */  mul.s     $f0, $f0, $f20
/* 1BE5C 80040A5C 00000000 */  nop
/* 1BE60 80040A60 46065280 */  add.s     $f10, $f10, $f6
/* 1BE64 80040A64 46024200 */  add.s     $f8, $f8, $f2
/* 1BE68 80040A68 24100001 */  addiu     $s0, $zero, 1
/* 1BE6C 80040A6C 46002100 */  add.s     $f4, $f4, $f0
/* 1BE70 80040A70 44055000 */  mfc1      $a1, $f10
/* 1BE74 80040A74 44064000 */  mfc1      $a2, $f8
/* 1BE78 80040A78 44072000 */  mfc1      $a3, $f4
/* 1BE7C 80040A7C 24040003 */  addiu     $a0, $zero, 3
/* 1BE80 80040A80 AFA5003C */  sw        $a1, 0x3c($sp)
/* 1BE84 80040A84 AFA60040 */  sw        $a2, 0x40($sp)
/* 1BE88 80040A88 AFA70044 */  sw        $a3, 0x44($sp)
/* 1BE8C 80040A8C AFA00010 */  sw        $zero, 0x10($sp)
/* 1BE90 80040A90 E7B60014 */  swc1      $f22, 0x14($sp)
/* 1BE94 80040A94 AFA00018 */  sw        $zero, 0x18($sp)
/* 1BE98 80040A98 0C01C05C */  jal       func_80070170
/* 1BE9C 80040A9C AFBE001C */   sw       $fp, 0x1c($sp)
.L80040AA0:
/* 1BEA0 80040AA0 8EC20000 */  lw        $v0, ($s6)
/* 1BEA4 80040AA4 26B50001 */  addiu     $s5, $s5, 1
/* 1BEA8 80040AA8 02A2102A */  slt       $v0, $s5, $v0
/* 1BEAC 80040AAC 1440FF98 */  bnez      $v0, .L80040910
/* 1BEB0 80040AB0 00151080 */   sll      $v0, $s5, 2
.L80040AB4:
/* 1BEB4 80040AB4 0C038056 */  jal       func_800E0158
/* 1BEB8 80040AB8 00000000 */   nop
/* 1BEBC 80040ABC 0C03BD6F */  jal       func_800EF5BC
/* 1BEC0 80040AC0 00000000 */   nop
/* 1BEC4 80040AC4 8E820000 */  lw        $v0, ($s4)
/* 1BEC8 80040AC8 3C030004 */  lui       $v1, 4
/* 1BECC 80040ACC 00431025 */  or        $v0, $v0, $v1
/* 1BED0 80040AD0 12000003 */  beqz      $s0, .L80040AE0
/* 1BED4 80040AD4 AE820000 */   sw       $v0, ($s4)
/* 1BED8 80040AD8 0C039805 */  jal       func_800E6014
/* 1BEDC 80040ADC 00000000 */   nop
.L80040AE0:
/* 1BEE0 80040AE0 0000202D */  daddu     $a0, $zero, $zero
/* 1BEE4 80040AE4 AE600090 */  sw        $zero, 0x90($s3)
/* 1BEE8 80040AE8 AE600094 */  sw        $zero, 0x94($s3)
/* 1BEEC 80040AEC 080103EB */  j         .L80040FAC
/* 1BEF0 80040AF0 A2600012 */   sb       $zero, 0x12($s3)
/* 1BEF4 80040AF4 8E71008C */  lw        $s1, 0x8c($s3)
/* 1BEF8 80040AF8 8E22003C */  lw        $v0, 0x3c($s1)
/* 1BEFC 80040AFC 10400004 */  beqz      $v0, .L80040B10
/* 1BF00 80040B00 0220B82D */   daddu    $s7, $s1, $zero
/* 1BF04 80040B04 8E240054 */  lw        $a0, 0x54($s1)
/* 1BF08 80040B08 0C0B1108 */  jal       func_802C4420
/* 1BF0C 80040B0C 00000000 */   nop
.L80040B10:
/* 1BF10 80040B10 8E220044 */  lw        $v0, 0x44($s1)
/* 1BF14 80040B14 10400003 */  beqz      $v0, .L80040B24
/* 1BF18 80040B18 00000000 */   nop
/* 1BF1C 80040B1C 0C0B1108 */  jal       func_802C4420
/* 1BF20 80040B20 8E24005C */   lw       $a0, 0x5c($s1)
.L80040B24:
/* 1BF24 80040B24 8E760088 */  lw        $s6, 0x88($s3)
/* 1BF28 80040B28 8EC20000 */  lw        $v0, ($s6)
/* 1BF2C 80040B2C 18400113 */  blez      $v0, .L80040F7C
/* 1BF30 80040B30 0000A82D */   daddu    $s5, $zero, $zero
/* 1BF34 80040B34 24100003 */  addiu     $s0, $zero, 3
/* 1BF38 80040B38 3C013F00 */  lui       $at, 0x3f00
/* 1BF3C 80040B3C 4481A000 */  mtc1      $at, $f20
/* 1BF40 80040B40 3C01BF80 */  lui       $at, 0xbf80
/* 1BF44 80040B44 4481B000 */  mtc1      $at, $f22
/* 1BF48 80040B48 00151080 */  sll       $v0, $s5, 2
.L80040B4C:
/* 1BF4C 80040B4C 02C21021 */  addu      $v0, $s6, $v0
/* 1BF50 80040B50 8C510004 */  lw        $s1, 4($v0)
/* 1BF54 80040B54 12200082 */  beqz      $s1, .L80040D60
/* 1BF58 80040B58 00000000 */   nop
/* 1BF5C 80040B5C 8E230000 */  lw        $v1, ($s1)
/* 1BF60 80040B60 30620008 */  andi      $v0, $v1, 8
/* 1BF64 80040B64 10400004 */  beqz      $v0, .L80040B78
/* 1BF68 80040B68 30620020 */   andi     $v0, $v1, 0x20
/* 1BF6C 80040B6C 8E62008C */  lw        $v0, 0x8c($s3)
/* 1BF70 80040B70 1622007B */  bne       $s1, $v0, .L80040D60
/* 1BF74 80040B74 30620020 */   andi     $v0, $v1, 0x20
.L80040B78:
/* 1BF78 80040B78 14400079 */  bnez      $v0, .L80040D60
/* 1BF7C 80040B7C 00000000 */   nop
/* 1BF80 80040B80 8EE20000 */  lw        $v0, ($s7)
/* 1BF84 80040B84 30420040 */  andi      $v0, $v0, 0x40
/* 1BF88 80040B88 10400004 */  beqz      $v0, .L80040B9C
/* 1BF8C 80040B8C 00000000 */   nop
/* 1BF90 80040B90 8E62008C */  lw        $v0, 0x8c($s3)
/* 1BF94 80040B94 16220072 */  bne       $s1, $v0, .L80040D60
/* 1BF98 80040B98 00000000 */   nop
.L80040B9C:
/* 1BF9C 80040B9C 8E220028 */  lw        $v0, 0x28($s1)
/* 1BFA0 80040BA0 1040003A */  beqz      $v0, .L80040C8C
/* 1BFA4 80040BA4 2405000A */   addiu    $a1, $zero, 0xa
/* 1BFA8 80040BA8 0000302D */  daddu     $a2, $zero, $zero
/* 1BFAC 80040BAC 0040202D */  daddu     $a0, $v0, $zero
/* 1BFB0 80040BB0 24020004 */  addiu     $v0, $zero, 4
/* 1BFB4 80040BB4 0C0B0CF8 */  jal       func_802C33E0
/* 1BFB8 80040BB8 A2220005 */   sb       $v0, 5($s1)
/* 1BFBC 80040BBC 0040202D */  daddu     $a0, $v0, $zero
/* 1BFC0 80040BC0 AE240040 */  sw        $a0, 0x40($s1)
/* 1BFC4 80040BC4 8C820144 */  lw        $v0, 0x144($a0)
/* 1BFC8 80040BC8 AE220058 */  sw        $v0, 0x58($s1)
/* 1BFCC 80040BCC AC910148 */  sw        $s1, 0x148($a0)
/* 1BFD0 80040BD0 86220008 */  lh        $v0, 8($s1)
/* 1BFD4 80040BD4 AC82014C */  sw        $v0, 0x14c($a0)
/* 1BFD8 80040BD8 92220006 */  lbu       $v0, 6($s1)
/* 1BFDC 80040BDC A0820004 */  sb        $v0, 4($a0)
/* 1BFE0 80040BE0 0C00E9EB */  jal       func_8003A7AC
/* 1BFE4 80040BE4 86240008 */   lh       $a0, 8($s1)
/* 1BFE8 80040BE8 0040902D */  daddu     $s2, $v0, $zero
/* 1BFEC 80040BEC C6480038 */  lwc1      $f8, 0x38($s2)
/* 1BFF0 80040BF0 C68A0028 */  lwc1      $f10, 0x28($s4)
/* 1BFF4 80040BF4 460A4201 */  sub.s     $f8, $f8, $f10
/* 1BFF8 80040BF8 46144202 */  mul.s     $f8, $f8, $f20
/* 1BFFC 80040BFC 00000000 */  nop
/* 1C000 80040C00 864200A8 */  lh        $v0, 0xa8($s2)
/* 1C004 80040C04 C644003C */  lwc1      $f4, 0x3c($s2)
/* 1C008 80040C08 44820000 */  mtc1      $v0, $f0
/* 1C00C 80040C0C 00000000 */  nop
/* 1C010 80040C10 46800020 */  cvt.s.w   $f0, $f0
/* 1C014 80040C14 46002100 */  add.s     $f4, $f4, $f0
/* 1C018 80040C18 868200B0 */  lh        $v0, 0xb0($s4)
/* 1C01C 80040C1C C686002C */  lwc1      $f6, 0x2c($s4)
/* 1C020 80040C20 44820000 */  mtc1      $v0, $f0
/* 1C024 80040C24 00000000 */  nop
/* 1C028 80040C28 46800020 */  cvt.s.w   $f0, $f0
/* 1C02C 80040C2C 46003000 */  add.s     $f0, $f6, $f0
/* 1C030 80040C30 46002101 */  sub.s     $f4, $f4, $f0
/* 1C034 80040C34 46142102 */  mul.s     $f4, $f4, $f20
/* 1C038 80040C38 00000000 */  nop
/* 1C03C 80040C3C C6820030 */  lwc1      $f2, 0x30($s4)
/* 1C040 80040C40 C6400040 */  lwc1      $f0, 0x40($s2)
/* 1C044 80040C44 46020001 */  sub.s     $f0, $f0, $f2
/* 1C048 80040C48 46140002 */  mul.s     $f0, $f0, $f20
/* 1C04C 80040C4C 00000000 */  nop
/* 1C050 80040C50 46085280 */  add.s     $f10, $f10, $f8
/* 1C054 80040C54 46043180 */  add.s     $f6, $f6, $f4
/* 1C058 80040C58 46001080 */  add.s     $f2, $f2, $f0
/* 1C05C 80040C5C 44055000 */  mfc1      $a1, $f10
/* 1C060 80040C60 44063000 */  mfc1      $a2, $f6
/* 1C064 80040C64 44071000 */  mfc1      $a3, $f2
/* 1C068 80040C68 24040003 */  addiu     $a0, $zero, 3
/* 1C06C 80040C6C AFA5003C */  sw        $a1, 0x3c($sp)
/* 1C070 80040C70 AFA60040 */  sw        $a2, 0x40($sp)
/* 1C074 80040C74 AFA70044 */  sw        $a3, 0x44($sp)
/* 1C078 80040C78 AFA00010 */  sw        $zero, 0x10($sp)
/* 1C07C 80040C7C E7B60014 */  swc1      $f22, 0x14($sp)
/* 1C080 80040C80 AFA00018 */  sw        $zero, 0x18($sp)
/* 1C084 80040C84 08010356 */  j         .L80040D58
/* 1C088 80040C88 AFB0001C */   sw       $s0, 0x1c($sp)
.L80040C8C:
/* 1C08C 80040C8C 30620001 */  andi      $v0, $v1, 1
/* 1C090 80040C90 14400033 */  bnez      $v0, .L80040D60
/* 1C094 80040C94 00000000 */   nop
/* 1C098 80040C98 0C00E9EB */  jal       func_8003A7AC
/* 1C09C 80040C9C 86240008 */   lh       $a0, 8($s1)
/* 1C0A0 80040CA0 0040902D */  daddu     $s2, $v0, $zero
/* 1C0A4 80040CA4 C44C0038 */  lwc1      $f12, 0x38($v0)
/* 1C0A8 80040CA8 C68E0028 */  lwc1      $f14, 0x28($s4)
/* 1C0AC 80040CAC 460E6301 */  sub.s     $f12, $f12, $f14
/* 1C0B0 80040CB0 46146302 */  mul.s     $f12, $f12, $f20
/* 1C0B4 80040CB4 00000000 */  nop
/* 1C0B8 80040CB8 C6420040 */  lwc1      $f2, 0x40($s2)
/* 1C0BC 80040CBC C6880030 */  lwc1      $f8, 0x30($s4)
/* 1C0C0 80040CC0 46081081 */  sub.s     $f2, $f2, $f8
/* 1C0C4 80040CC4 46141082 */  mul.s     $f2, $f2, $f20
/* 1C0C8 80040CC8 00000000 */  nop
/* 1C0CC 80040CCC 864200A8 */  lh        $v0, 0xa8($s2)
/* 1C0D0 80040CD0 C646003C */  lwc1      $f6, 0x3c($s2)
/* 1C0D4 80040CD4 44820000 */  mtc1      $v0, $f0
/* 1C0D8 80040CD8 00000000 */  nop
/* 1C0DC 80040CDC 46800020 */  cvt.s.w   $f0, $f0
/* 1C0E0 80040CE0 868200B0 */  lh        $v0, 0xb0($s4)
/* 1C0E4 80040CE4 46003180 */  add.s     $f6, $f6, $f0
/* 1C0E8 80040CE8 C68A002C */  lwc1      $f10, 0x2c($s4)
/* 1C0EC 80040CEC 44820000 */  mtc1      $v0, $f0
/* 1C0F0 80040CF0 00000000 */  nop
/* 1C0F4 80040CF4 46800020 */  cvt.s.w   $f0, $f0
/* 1C0F8 80040CF8 46005000 */  add.s     $f0, $f10, $f0
/* 1C0FC 80040CFC 46003181 */  sub.s     $f6, $f6, $f0
/* 1C100 80040D00 46143182 */  mul.s     $f6, $f6, $f20
/* 1C104 80040D04 00000000 */  nop
/* 1C108 80040D08 864200A8 */  lh        $v0, 0xa8($s2)
/* 1C10C 80040D0C C644003C */  lwc1      $f4, 0x3c($s2)
/* 1C110 80040D10 44820000 */  mtc1      $v0, $f0
/* 1C114 80040D14 00000000 */  nop
/* 1C118 80040D18 46800020 */  cvt.s.w   $f0, $f0
/* 1C11C 80040D1C 46002100 */  add.s     $f4, $f4, $f0
/* 1C120 80040D20 460C7380 */  add.s     $f14, $f14, $f12
/* 1C124 80040D24 46024200 */  add.s     $f8, $f8, $f2
/* 1C128 80040D28 44062000 */  mfc1      $a2, $f4
/* 1C12C 80040D2C 46065280 */  add.s     $f10, $f10, $f6
/* 1C130 80040D30 E7AE003C */  swc1      $f14, 0x3c($sp)
/* 1C134 80040D34 E7A80044 */  swc1      $f8, 0x44($sp)
/* 1C138 80040D38 E7AA0040 */  swc1      $f10, 0x40($sp)
/* 1C13C 80040D3C AFA00010 */  sw        $zero, 0x10($sp)
/* 1C140 80040D40 E7B60014 */  swc1      $f22, 0x14($sp)
/* 1C144 80040D44 AFA00018 */  sw        $zero, 0x18($sp)
/* 1C148 80040D48 AFB0001C */  sw        $s0, 0x1c($sp)
/* 1C14C 80040D4C 8E450038 */  lw        $a1, 0x38($s2)
/* 1C150 80040D50 8E470040 */  lw        $a3, 0x40($s2)
/* 1C154 80040D54 24040003 */  addiu     $a0, $zero, 3
.L80040D58:
/* 1C158 80040D58 0C01C05C */  jal       func_80070170
/* 1C15C 80040D5C 00000000 */   nop
.L80040D60:
/* 1C160 80040D60 8EC20000 */  lw        $v0, ($s6)
/* 1C164 80040D64 26B50001 */  addiu     $s5, $s5, 1
/* 1C168 80040D68 02A2102A */  slt       $v0, $s5, $v0
/* 1C16C 80040D6C 1440FF77 */  bnez      $v0, .L80040B4C
/* 1C170 80040D70 00151080 */   sll      $v0, $s5, 2
/* 1C174 80040D74 080103DF */  j         .L80040F7C
/* 1C178 80040D78 00000000 */   nop
/* 1C17C 80040D7C 0C0B117A */  jal       func_802C45E8
/* 1C180 80040D80 24040001 */   addiu    $a0, $zero, 1
/* 1C184 80040D84 8E71008C */  lw        $s1, 0x8c($s3)
/* 1C188 80040D88 12200007 */  beqz      $s1, .L80040DA8
/* 1C18C 80040D8C 00000000 */   nop
/* 1C190 80040D90 8E22003C */  lw        $v0, 0x3c($s1)
/* 1C194 80040D94 10400004 */  beqz      $v0, .L80040DA8
/* 1C198 80040D98 00000000 */   nop
/* 1C19C 80040D9C 0C0B1108 */  jal       func_802C4420
/* 1C1A0 80040DA0 8E240054 */   lw       $a0, 0x54($s1)
/* 1C1A4 80040DA4 8E71008C */  lw        $s1, 0x8c($s3)
.L80040DA8:
/* 1C1A8 80040DA8 8E220020 */  lw        $v0, 0x20($s1)
/* 1C1AC 80040DAC 1040000F */  beqz      $v0, .L80040DEC
/* 1C1B0 80040DB0 2405000A */   addiu    $a1, $zero, 0xa
/* 1C1B4 80040DB4 0000302D */  daddu     $a2, $zero, $zero
/* 1C1B8 80040DB8 0040202D */  daddu     $a0, $v0, $zero
/* 1C1BC 80040DBC 24020005 */  addiu     $v0, $zero, 5
/* 1C1C0 80040DC0 0C0B0CF8 */  jal       func_802C33E0
/* 1C1C4 80040DC4 A2220005 */   sb       $v0, 5($s1)
/* 1C1C8 80040DC8 0040202D */  daddu     $a0, $v0, $zero
/* 1C1CC 80040DCC AE240038 */  sw        $a0, 0x38($s1)
/* 1C1D0 80040DD0 8C820144 */  lw        $v0, 0x144($a0)
/* 1C1D4 80040DD4 AE220050 */  sw        $v0, 0x50($s1)
/* 1C1D8 80040DD8 AC910148 */  sw        $s1, 0x148($a0)
/* 1C1DC 80040DDC 86220008 */  lh        $v0, 8($s1)
/* 1C1E0 80040DE0 AC82014C */  sw        $v0, 0x14c($a0)
/* 1C1E4 80040DE4 92220006 */  lbu       $v0, 6($s1)
/* 1C1E8 80040DE8 A0820004 */  sb        $v0, 4($a0)
.L80040DEC:
/* 1C1EC 80040DEC 0C038056 */  jal       func_800E0158
/* 1C1F0 80040DF0 00000000 */   nop
/* 1C1F4 80040DF4 0C03BD6F */  jal       func_800EF5BC
/* 1C1F8 80040DF8 00000000 */   nop
/* 1C1FC 80040DFC 0C039761 */  jal       func_800E5D84
/* 1C200 80040E00 2404000C */   addiu    $a0, $zero, 0xc
/* 1C204 80040E04 24040001 */  addiu     $a0, $zero, 1
/* 1C208 80040E08 AE600090 */  sw        $zero, 0x90($s3)
/* 1C20C 80040E0C 0C03BCDA */  jal       func_800EF368
/* 1C210 80040E10 AE600094 */   sw       $zero, 0x94($s3)
/* 1C214 80040E14 080103EE */  j         .L80040FB8
/* 1C218 80040E18 24020004 */   addiu    $v0, $zero, 4
/* 1C21C 80040E1C 8E71008C */  lw        $s1, 0x8c($s3)
/* 1C220 80040E20 8E22003C */  lw        $v0, 0x3c($s1)
/* 1C224 80040E24 10400004 */  beqz      $v0, .L80040E38
/* 1C228 80040E28 0220B82D */   daddu    $s7, $s1, $zero
/* 1C22C 80040E2C 8E240054 */  lw        $a0, 0x54($s1)
/* 1C230 80040E30 0C0B1108 */  jal       func_802C4420
/* 1C234 80040E34 00000000 */   nop
.L80040E38:
/* 1C238 80040E38 8E220044 */  lw        $v0, 0x44($s1)
/* 1C23C 80040E3C 10400003 */  beqz      $v0, .L80040E4C
/* 1C240 80040E40 00000000 */   nop
/* 1C244 80040E44 0C0B1108 */  jal       func_802C4420
/* 1C248 80040E48 8E24005C */   lw       $a0, 0x5c($s1)
.L80040E4C:
/* 1C24C 80040E4C 8E760088 */  lw        $s6, 0x88($s3)
/* 1C250 80040E50 8EC20000 */  lw        $v0, ($s6)
/* 1C254 80040E54 18400049 */  blez      $v0, .L80040F7C
/* 1C258 80040E58 0000A82D */   daddu    $s5, $zero, $zero
/* 1C25C 80040E5C 3C01BF80 */  lui       $at, 0xbf80
/* 1C260 80040E60 4481A000 */  mtc1      $at, $f20
/* 1C264 80040E64 241E0003 */  addiu     $fp, $zero, 3
/* 1C268 80040E68 02C0802D */  daddu     $s0, $s6, $zero
.L80040E6C:
/* 1C26C 80040E6C 8E110004 */  lw        $s1, 4($s0)
/* 1C270 80040E70 1220003D */  beqz      $s1, .L80040F68
/* 1C274 80040E74 00000000 */   nop
/* 1C278 80040E78 8E230000 */  lw        $v1, ($s1)
/* 1C27C 80040E7C 30620008 */  andi      $v0, $v1, 8
/* 1C280 80040E80 10400004 */  beqz      $v0, .L80040E94
/* 1C284 80040E84 30620020 */   andi     $v0, $v1, 0x20
/* 1C288 80040E88 8E62008C */  lw        $v0, 0x8c($s3)
/* 1C28C 80040E8C 16220036 */  bne       $s1, $v0, .L80040F68
/* 1C290 80040E90 30620020 */   andi     $v0, $v1, 0x20
.L80040E94:
/* 1C294 80040E94 14400034 */  bnez      $v0, .L80040F68
/* 1C298 80040E98 00000000 */   nop
/* 1C29C 80040E9C 8EE20000 */  lw        $v0, ($s7)
/* 1C2A0 80040EA0 30420040 */  andi      $v0, $v0, 0x40
/* 1C2A4 80040EA4 10400004 */  beqz      $v0, .L80040EB8
/* 1C2A8 80040EA8 00000000 */   nop
/* 1C2AC 80040EAC 8E62008C */  lw        $v0, 0x8c($s3)
/* 1C2B0 80040EB0 1622002D */  bne       $s1, $v0, .L80040F68
/* 1C2B4 80040EB4 00000000 */   nop
.L80040EB8:
/* 1C2B8 80040EB8 8E220028 */  lw        $v0, 0x28($s1)
/* 1C2BC 80040EBC 10400010 */  beqz      $v0, .L80040F00
/* 1C2C0 80040EC0 2405000A */   addiu    $a1, $zero, 0xa
/* 1C2C4 80040EC4 0000302D */  daddu     $a2, $zero, $zero
/* 1C2C8 80040EC8 0040202D */  daddu     $a0, $v0, $zero
/* 1C2CC 80040ECC 24020006 */  addiu     $v0, $zero, 6
/* 1C2D0 80040ED0 0C0B0CF8 */  jal       func_802C33E0
/* 1C2D4 80040ED4 A2220005 */   sb       $v0, 5($s1)
/* 1C2D8 80040ED8 0040202D */  daddu     $a0, $v0, $zero
/* 1C2DC 80040EDC AE240040 */  sw        $a0, 0x40($s1)
/* 1C2E0 80040EE0 8C820144 */  lw        $v0, 0x144($a0)
/* 1C2E4 80040EE4 AE220058 */  sw        $v0, 0x58($s1)
/* 1C2E8 80040EE8 AC910148 */  sw        $s1, 0x148($a0)
/* 1C2EC 80040EEC 86220008 */  lh        $v0, 8($s1)
/* 1C2F0 80040EF0 AC82014C */  sw        $v0, 0x14c($a0)
/* 1C2F4 80040EF4 92220006 */  lbu       $v0, 6($s1)
/* 1C2F8 80040EF8 080103C3 */  j         .L80040F0C
/* 1C2FC 80040EFC A0820004 */   sb       $v0, 4($a0)
.L80040F00:
/* 1C300 80040F00 30620001 */  andi      $v0, $v1, 1
/* 1C304 80040F04 14400018 */  bnez      $v0, .L80040F68
/* 1C308 80040F08 00000000 */   nop
.L80040F0C:
/* 1C30C 80040F0C 0C00E9EB */  jal       func_8003A7AC
/* 1C310 80040F10 86240008 */   lh       $a0, 8($s1)
/* 1C314 80040F14 0040902D */  daddu     $s2, $v0, $zero
/* 1C318 80040F18 864200A8 */  lh        $v0, 0xa8($s2)
/* 1C31C 80040F1C C644003C */  lwc1      $f4, 0x3c($s2)
/* 1C320 80040F20 C6420040 */  lwc1      $f2, 0x40($s2)
/* 1C324 80040F24 44820000 */  mtc1      $v0, $f0
/* 1C328 80040F28 00000000 */  nop
/* 1C32C 80040F2C 46800020 */  cvt.s.w   $f0, $f0
/* 1C330 80040F30 46002100 */  add.s     $f4, $f4, $f0
/* 1C334 80040F34 C6400038 */  lwc1      $f0, 0x38($s2)
/* 1C338 80040F38 44071000 */  mfc1      $a3, $f2
/* 1C33C 80040F3C 44050000 */  mfc1      $a1, $f0
/* 1C340 80040F40 44062000 */  mfc1      $a2, $f4
/* 1C344 80040F44 24040003 */  addiu     $a0, $zero, 3
/* 1C348 80040F48 AFA70044 */  sw        $a3, 0x44($sp)
/* 1C34C 80040F4C AFA5003C */  sw        $a1, 0x3c($sp)
/* 1C350 80040F50 AFA60040 */  sw        $a2, 0x40($sp)
/* 1C354 80040F54 AFA00010 */  sw        $zero, 0x10($sp)
/* 1C358 80040F58 E7B40014 */  swc1      $f20, 0x14($sp)
/* 1C35C 80040F5C AFA00018 */  sw        $zero, 0x18($sp)
/* 1C360 80040F60 0C01C05C */  jal       func_80070170
/* 1C364 80040F64 AFBE001C */   sw       $fp, 0x1c($sp)
.L80040F68:
/* 1C368 80040F68 8EC20000 */  lw        $v0, ($s6)
/* 1C36C 80040F6C 26B50001 */  addiu     $s5, $s5, 1
/* 1C370 80040F70 02A2102A */  slt       $v0, $s5, $v0
/* 1C374 80040F74 1440FFBD */  bnez      $v0, .L80040E6C
/* 1C378 80040F78 26100004 */   addiu    $s0, $s0, 4
.L80040F7C:
/* 1C37C 80040F7C 0C038056 */  jal       func_800E0158
/* 1C380 80040F80 00000000 */   nop
/* 1C384 80040F84 0C03BD6F */  jal       func_800EF5BC
/* 1C388 80040F88 00000000 */   nop
/* 1C38C 80040F8C 0000202D */  daddu     $a0, $zero, $zero
/* 1C390 80040F90 AE600090 */  sw        $zero, 0x90($s3)
/* 1C394 80040F94 AE600094 */  sw        $zero, 0x94($s3)
/* 1C398 80040F98 A2600012 */  sb        $zero, 0x12($s3)
/* 1C39C 80040F9C 8E820000 */  lw        $v0, ($s4)
/* 1C3A0 80040FA0 3C030004 */  lui       $v1, 4
/* 1C3A4 80040FA4 00431025 */  or        $v0, $v0, $v1
/* 1C3A8 80040FA8 AE820000 */  sw        $v0, ($s4)
.L80040FAC:
/* 1C3AC 80040FAC 0C053B59 */  jal       func_8014ED64
/* 1C3B0 80040FB0 00000000 */   nop
/* 1C3B4 80040FB4 24020003 */  addiu     $v0, $zero, 3
.L80040FB8:
/* 1C3B8 80040FB8 3C01800A */  lui       $at, %hi(D_8009A5E0)
/* 1C3BC 80040FBC AC22A5E0 */  sw        $v0, %lo(D_8009A5E0)($at)
/* 1C3C0 80040FC0 24020001 */  addiu     $v0, $zero, 1
.L80040FC4:
/* 1C3C4 80040FC4 3C01800A */  lui       $at, %hi(D_8009A658)
/* 1C3C8 80040FC8 AC22A658 */  sw        $v0, %lo(D_8009A658)($at)
/* 1C3CC 80040FCC 3C01800A */  lui       $at, %hi(D_8009A5B0)
/* 1C3D0 80040FD0 AC20A5B0 */  sw        $zero, %lo(D_8009A5B0)($at)
.L80040FD4:
/* 1C3D4 80040FD4 8FBF008C */  lw        $ra, 0x8c($sp)
/* 1C3D8 80040FD8 8FBE0088 */  lw        $fp, 0x88($sp)
/* 1C3DC 80040FDC 8FB70084 */  lw        $s7, 0x84($sp)
/* 1C3E0 80040FE0 8FB60080 */  lw        $s6, 0x80($sp)
/* 1C3E4 80040FE4 8FB5007C */  lw        $s5, 0x7c($sp)
/* 1C3E8 80040FE8 8FB40078 */  lw        $s4, 0x78($sp)
/* 1C3EC 80040FEC 8FB30074 */  lw        $s3, 0x74($sp)
/* 1C3F0 80040FF0 8FB20070 */  lw        $s2, 0x70($sp)
/* 1C3F4 80040FF4 8FB1006C */  lw        $s1, 0x6c($sp)
/* 1C3F8 80040FF8 8FB00068 */  lw        $s0, 0x68($sp)
/* 1C3FC 80040FFC D7BE00B8 */  ldc1      $f30, 0xb8($sp)
/* 1C400 80041000 D7BC00B0 */  ldc1      $f28, 0xb0($sp)
/* 1C404 80041004 D7BA00A8 */  ldc1      $f26, 0xa8($sp)
/* 1C408 80041008 D7B800A0 */  ldc1      $f24, 0xa0($sp)
/* 1C40C 8004100C D7B60098 */  ldc1      $f22, 0x98($sp)
/* 1C410 80041010 D7B40090 */  ldc1      $f20, 0x90($sp)
/* 1C414 80041014 03E00008 */  jr        $ra
/* 1C418 80041018 27BD00C0 */   addiu    $sp, $sp, 0xc0
