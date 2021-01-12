.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E007A50C
/* 37CA4C E007A50C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 37CA50 E007A510 AFBF0010 */  sw        $ra, 0x10($sp)
/* 37CA54 E007A514 8C85000C */  lw        $a1, 0xc($a0)
/* 37CA58 E007A518 8CA2005C */  lw        $v0, 0x5c($a1)
/* 37CA5C E007A51C 8CA30060 */  lw        $v1, 0x60($a1)
/* 37CA60 E007A520 8CA70004 */  lw        $a3, 4($a1)
/* 37CA64 E007A524 2442FFFF */  addiu     $v0, $v0, -1
/* 37CA68 E007A528 24630001 */  addiu     $v1, $v1, 1
/* 37CA6C E007A52C ACA2005C */  sw        $v0, 0x5c($a1)
/* 37CA70 E007A530 04410008 */  bgez      $v0, .LE007A554
/* 37CA74 E007A534 ACA30060 */   sw       $v1, 0x60($a1)
/* 37CA78 E007A538 24020002 */  addiu     $v0, $zero, 2
/* 37CA7C E007A53C 14E20005 */  bne       $a3, $v0, .LE007A554
/* 37CA80 E007A540 00000000 */   nop
/* 37CA84 E007A544 0C080128 */  jal       func_E02004A0
/* 37CA88 E007A548 00000000 */   nop
/* 37CA8C E007A54C 0801EA0D */  j         .LE007A834
/* 37CA90 E007A550 00000000 */   nop
.LE007A554:
/* 37CA94 E007A554 8CA8005C */  lw        $t0, 0x5c($a1)
/* 37CA98 E007A558 8C820008 */  lw        $v0, 8($a0)
/* 37CA9C E007A55C 24060001 */  addiu     $a2, $zero, 1
/* 37CAA0 E007A560 00C2102A */  slt       $v0, $a2, $v0
/* 37CAA4 E007A564 104000AE */  beqz      $v0, .LE007A820
/* 37CAA8 E007A568 24A50068 */   addiu    $a1, $a1, 0x68
/* 37CAAC E007A56C 24A3004C */  addiu     $v1, $a1, 0x4c
/* 37CAB0 E007A570 3C01E008 */  lui       $at, %hi(D_E007AC10)
/* 37CAB4 E007A574 D430AC10 */  ldc1      $f16, %lo(D_E007AC10)($at)
/* 37CAB8 E007A578 3C01E008 */  lui       $at, %hi(D_E007AC18)
/* 37CABC E007A57C D42EAC18 */  ldc1      $f14, %lo(D_E007AC18)($at)
.LE007A580:
/* 37CAC0 E007A580 8C620018 */  lw        $v0, 0x18($v1)
/* 37CAC4 E007A584 18400003 */  blez      $v0, .LE007A594
/* 37CAC8 E007A588 2442FFFF */   addiu    $v0, $v0, -1
/* 37CACC E007A58C 1C40009F */  bgtz      $v0, .LE007A80C
/* 37CAD0 E007A590 AC620018 */   sw       $v0, 0x18($v1)
.LE007A594:
/* 37CAD4 E007A594 8C620010 */  lw        $v0, 0x10($v1)
/* 37CAD8 E007A598 2442FFFF */  addiu     $v0, $v0, -1
/* 37CADC E007A59C 0040282D */  daddu     $a1, $v0, $zero
/* 37CAE0 E007A5A0 04A10024 */  bgez      $a1, .LE007A634
/* 37CAE4 E007A5A4 AC650010 */   sw       $a1, 0x10($v1)
/* 37CAE8 E007A5A8 54E0001B */  bnel      $a3, $zero, .LE007A618
/* 37CAEC E007A5AC AC60FFBC */   sw       $zero, -0x44($v1)
/* 37CAF0 E007A5B0 24050009 */  addiu     $a1, $zero, 9
/* 37CAF4 E007A5B4 C460FFD4 */  lwc1      $f0, -0x2c($v1)
/* 37CAF8 E007A5B8 C462FFD8 */  lwc1      $f2, -0x28($v1)
/* 37CAFC E007A5BC C464FFDC */  lwc1      $f4, -0x24($v1)
/* 37CB00 E007A5C0 3C013F00 */  lui       $at, 0x3f00
/* 37CB04 E007A5C4 44813000 */  mtc1      $at, $f6
/* 37CB08 E007A5C8 3C014080 */  lui       $at, 0x4080
/* 37CB0C E007A5CC 44814000 */  mtc1      $at, $f8
/* 37CB10 E007A5D0 3C0141A0 */  lui       $at, 0x41a0
/* 37CB14 E007A5D4 44815000 */  mtc1      $at, $f10
/* 37CB18 E007A5D8 C46C0008 */  lwc1      $f12, 8($v1)
/* 37CB1C E007A5DC 240200FF */  addiu     $v0, $zero, 0xff
/* 37CB20 E007A5E0 AC62000C */  sw        $v0, 0xc($v1)
/* 37CB24 E007A5E4 00A0102D */  daddu     $v0, $a1, $zero
/* 37CB28 E007A5E8 AC60FFBC */  sw        $zero, -0x44($v1)
/* 37CB2C E007A5EC AC60FFC0 */  sw        $zero, -0x40($v1)
/* 37CB30 E007A5F0 AC60FFC4 */  sw        $zero, -0x3c($v1)
/* 37CB34 E007A5F4 AC620010 */  sw        $v0, 0x10($v1)
/* 37CB38 E007A5F8 E460FFC8 */  swc1      $f0, -0x38($v1)
/* 37CB3C E007A5FC E462FFCC */  swc1      $f2, -0x34($v1)
/* 37CB40 E007A600 E464FFD0 */  swc1      $f4, -0x30($v1)
/* 37CB44 E007A604 E466FFF8 */  swc1      $f6, -8($v1)
/* 37CB48 E007A608 E468FFFC */  swc1      $f8, -4($v1)
/* 37CB4C E007A60C E46A0004 */  swc1      $f10, 4($v1)
/* 37CB50 E007A610 0801E98D */  j         .LE007A634
/* 37CB54 E007A614 E46C0000 */   swc1     $f12, ($v1)
.LE007A618:
/* 37CB58 E007A618 AC60FFC0 */  sw        $zero, -0x40($v1)
/* 37CB5C E007A61C AC60FFC4 */  sw        $zero, -0x3c($v1)
/* 37CB60 E007A620 AC60FFC8 */  sw        $zero, -0x38($v1)
/* 37CB64 E007A624 AC60FFCC */  sw        $zero, -0x34($v1)
/* 37CB68 E007A628 AC60FFD0 */  sw        $zero, -0x30($v1)
/* 37CB6C E007A62C AC60000C */  sw        $zero, 0xc($v1)
/* 37CB70 E007A630 AC600010 */  sw        $zero, 0x10($v1)
.LE007A634:
/* 37CB74 E007A634 24A2FFFC */  addiu     $v0, $a1, -4
/* 37CB78 E007A638 2C420003 */  sltiu     $v0, $v0, 3
/* 37CB7C E007A63C 1040000D */  beqz      $v0, .LE007A674
/* 37CB80 E007A640 28A20008 */   slti     $v0, $a1, 8
/* 37CB84 E007A644 C466FFC8 */  lwc1      $f6, -0x38($v1)
/* 37CB88 E007A648 C460FFE0 */  lwc1      $f0, -0x20($v1)
/* 37CB8C E007A64C C464FFCC */  lwc1      $f4, -0x34($v1)
/* 37CB90 E007A650 46003180 */  add.s     $f6, $f6, $f0
/* 37CB94 E007A654 C460FFE4 */  lwc1      $f0, -0x1c($v1)
/* 37CB98 E007A658 C462FFD0 */  lwc1      $f2, -0x30($v1)
/* 37CB9C E007A65C 46002100 */  add.s     $f4, $f4, $f0
/* 37CBA0 E007A660 C460FFE8 */  lwc1      $f0, -0x18($v1)
/* 37CBA4 E007A664 46001080 */  add.s     $f2, $f2, $f0
/* 37CBA8 E007A668 E466FFC8 */  swc1      $f6, -0x38($v1)
/* 37CBAC E007A66C E464FFCC */  swc1      $f4, -0x34($v1)
/* 37CBB0 E007A670 E462FFD0 */  swc1      $f2, -0x30($v1)
.LE007A674:
/* 37CBB4 E007A674 10400023 */  beqz      $v0, .LE007A704
/* 37CBB8 E007A678 00000000 */   nop
/* 37CBBC E007A67C C468FFF8 */  lwc1      $f8, -8($v1)
/* 37CBC0 E007A680 3C014008 */  lui       $at, 0x4008
/* 37CBC4 E007A684 44813800 */  mtc1      $at, $f7
/* 37CBC8 E007A688 44803000 */  mtc1      $zero, $f6
/* 37CBCC E007A68C 46004221 */  cvt.d.s   $f8, $f8
/* 37CBD0 E007A690 46283181 */  sub.d     $f6, $f6, $f8
/* 37CBD4 E007A694 46303182 */  mul.d     $f6, $f6, $f16
/* 37CBD8 E007A698 00000000 */  nop
/* 37CBDC E007A69C 3C014020 */  lui       $at, 0x4020
/* 37CBE0 E007A6A0 44810800 */  mtc1      $at, $f1
/* 37CBE4 E007A6A4 44800000 */  mtc1      $zero, $f0
/* 37CBE8 E007A6A8 00000000 */  nop
/* 37CBEC E007A6AC 46203182 */  mul.d     $f6, $f6, $f0
/* 37CBF0 E007A6B0 00000000 */  nop
/* 37CBF4 E007A6B4 C464FFFC */  lwc1      $f4, -4($v1)
/* 37CBF8 E007A6B8 3C013FE0 */  lui       $at, 0x3fe0
/* 37CBFC E007A6BC 44810800 */  mtc1      $at, $f1
/* 37CC00 E007A6C0 44800000 */  mtc1      $zero, $f0
/* 37CC04 E007A6C4 46002121 */  cvt.d.s   $f4, $f4
/* 37CC08 E007A6C8 46240001 */  sub.d     $f0, $f0, $f4
/* 37CC0C E007A6CC 46300002 */  mul.d     $f0, $f0, $f16
/* 37CC10 E007A6D0 00000000 */  nop
/* 37CC14 E007A6D4 3C014018 */  lui       $at, 0x4018
/* 37CC18 E007A6D8 44811800 */  mtc1      $at, $f3
/* 37CC1C E007A6DC 44801000 */  mtc1      $zero, $f2
/* 37CC20 E007A6E0 00000000 */  nop
/* 37CC24 E007A6E4 46220002 */  mul.d     $f0, $f0, $f2
/* 37CC28 E007A6E8 00000000 */  nop
/* 37CC2C E007A6EC 46264200 */  add.d     $f8, $f8, $f6
/* 37CC30 E007A6F0 46202100 */  add.d     $f4, $f4, $f0
/* 37CC34 E007A6F4 46204220 */  cvt.s.d   $f8, $f8
/* 37CC38 E007A6F8 E468FFF8 */  swc1      $f8, -8($v1)
/* 37CC3C E007A6FC 46202120 */  cvt.s.d   $f4, $f4
/* 37CC40 E007A700 E464FFFC */  swc1      $f4, -4($v1)
.LE007A704:
/* 37CC44 E007A704 C466FFC8 */  lwc1      $f6, -0x38($v1)
/* 37CC48 E007A708 C460FFEC */  lwc1      $f0, -0x14($v1)
/* 37CC4C E007A70C C462FFCC */  lwc1      $f2, -0x34($v1)
/* 37CC50 E007A710 46003180 */  add.s     $f6, $f6, $f0
/* 37CC54 E007A714 C460FFF0 */  lwc1      $f0, -0x10($v1)
/* 37CC58 E007A718 C464FFD0 */  lwc1      $f4, -0x30($v1)
/* 37CC5C E007A71C 46001080 */  add.s     $f2, $f2, $f0
/* 37CC60 E007A720 C460FFF4 */  lwc1      $f0, -0xc($v1)
/* 37CC64 E007A724 46002100 */  add.s     $f4, $f4, $f0
/* 37CC68 E007A728 44800000 */  mtc1      $zero, $f0
/* 37CC6C E007A72C E466FFC8 */  swc1      $f6, -0x38($v1)
/* 37CC70 E007A730 4600103C */  c.lt.s    $f2, $f0
/* 37CC74 E007A734 E462FFCC */  swc1      $f2, -0x34($v1)
/* 37CC78 E007A738 45000024 */  bc1f      .LE007A7CC
/* 37CC7C E007A73C E464FFD0 */   swc1     $f4, -0x30($v1)
/* 37CC80 E007A740 460031A1 */  cvt.d.s   $f6, $f6
/* 37CC84 E007A744 462E3182 */  mul.d     $f6, $f6, $f14
/* 37CC88 E007A748 00000000 */  nop
/* 37CC8C E007A74C C4680004 */  lwc1      $f8, 4($v1)
/* 37CC90 E007A750 3C01E008 */  lui       $at, %hi(D_E007AC20)
/* 37CC94 E007A754 D420AC20 */  ldc1      $f0, %lo(D_E007AC20)($at)
/* 37CC98 E007A758 46004221 */  cvt.d.s   $f8, $f8
/* 37CC9C E007A75C 46204202 */  mul.d     $f8, $f8, $f0
/* 37CCA0 E007A760 00000000 */  nop
/* 37CCA4 E007A764 46001106 */  mov.s     $f4, $f2
/* 37CCA8 E007A768 3C01E008 */  lui       $at, %hi(D_E007AC28)
/* 37CCAC E007A76C D420AC28 */  ldc1      $f0, %lo(D_E007AC28)($at)
/* 37CCB0 E007A770 46002121 */  cvt.d.s   $f4, $f4
/* 37CCB4 E007A774 46202102 */  mul.d     $f4, $f4, $f0
/* 37CCB8 E007A778 00000000 */  nop
/* 37CCBC E007A77C 3C01E008 */  lui       $at, %hi(D_E007AC30)
/* 37CCC0 E007A780 D420AC30 */  ldc1      $f0, %lo(D_E007AC30)($at)
/* 37CCC4 E007A784 C462000C */  lwc1      $f2, 0xc($v1)
/* 37CCC8 E007A788 468010A1 */  cvt.d.w   $f2, $f2
/* 37CCCC E007A78C 46201082 */  mul.d     $f2, $f2, $f0
/* 37CCD0 E007A790 00000000 */  nop
/* 37CCD4 E007A794 C460FFD0 */  lwc1      $f0, -0x30($v1)
/* 37CCD8 E007A798 46000021 */  cvt.d.s   $f0, $f0
/* 37CCDC E007A79C 462E0002 */  mul.d     $f0, $f0, $f14
/* 37CCE0 E007A7A0 00000000 */  nop
/* 37CCE4 E007A7A4 462031A0 */  cvt.s.d   $f6, $f6
/* 37CCE8 E007A7A8 E466FFC8 */  swc1      $f6, -0x38($v1)
/* 37CCEC E007A7AC 46204220 */  cvt.s.d   $f8, $f8
/* 37CCF0 E007A7B0 E4680004 */  swc1      $f8, 4($v1)
/* 37CCF4 E007A7B4 46202120 */  cvt.s.d   $f4, $f4
/* 37CCF8 E007A7B8 E464FFCC */  swc1      $f4, -0x34($v1)
/* 37CCFC E007A7BC 4620148D */  trunc.w.d $f18, $f2
/* 37CD00 E007A7C0 E472000C */  swc1      $f18, 0xc($v1)
/* 37CD04 E007A7C4 46200020 */  cvt.s.d   $f0, $f0
/* 37CD08 E007A7C8 E460FFD0 */  swc1      $f0, -0x30($v1)
.LE007A7CC:
/* 37CD0C E007A7CC C468FFBC */  lwc1      $f8, -0x44($v1)
/* 37CD10 E007A7D0 C460FFC8 */  lwc1      $f0, -0x38($v1)
/* 37CD14 E007A7D4 C466FFC0 */  lwc1      $f6, -0x40($v1)
/* 37CD18 E007A7D8 46004200 */  add.s     $f8, $f8, $f0
/* 37CD1C E007A7DC C460FFCC */  lwc1      $f0, -0x34($v1)
/* 37CD20 E007A7E0 C464FFC4 */  lwc1      $f4, -0x3c($v1)
/* 37CD24 E007A7E4 46003180 */  add.s     $f6, $f6, $f0
/* 37CD28 E007A7E8 C460FFD0 */  lwc1      $f0, -0x30($v1)
/* 37CD2C E007A7EC C4620004 */  lwc1      $f2, 4($v1)
/* 37CD30 E007A7F0 46002100 */  add.s     $f4, $f4, $f0
/* 37CD34 E007A7F4 C4600000 */  lwc1      $f0, ($v1)
/* 37CD38 E007A7F8 E468FFBC */  swc1      $f8, -0x44($v1)
/* 37CD3C E007A7FC 46020000 */  add.s     $f0, $f0, $f2
/* 37CD40 E007A800 E466FFC0 */  swc1      $f6, -0x40($v1)
/* 37CD44 E007A804 E464FFC4 */  swc1      $f4, -0x3c($v1)
/* 37CD48 E007A808 E4600000 */  swc1      $f0, ($v1)
.LE007A80C:
/* 37CD4C E007A80C 24C60001 */  addiu     $a2, $a2, 1
/* 37CD50 E007A810 8C820008 */  lw        $v0, 8($a0)
/* 37CD54 E007A814 00C2102A */  slt       $v0, $a2, $v0
/* 37CD58 E007A818 1440FF59 */  bnez      $v0, .LE007A580
/* 37CD5C E007A81C 24630068 */   addiu    $v1, $v1, 0x68
.LE007A820:
/* 37CD60 E007A820 05010004 */  bgez      $t0, .LE007A834
/* 37CD64 E007A824 2402000A */   addiu    $v0, $zero, 0xa
/* 37CD68 E007A828 8C85000C */  lw        $a1, 0xc($a0)
/* 37CD6C E007A82C ACA2005C */  sw        $v0, 0x5c($a1)
/* 37CD70 E007A830 ACA00060 */  sw        $zero, 0x60($a1)
.LE007A834:
/* 37CD74 E007A834 8FBF0010 */  lw        $ra, 0x10($sp)
/* 37CD78 E007A838 03E00008 */  jr        $ra
/* 37CD7C E007A83C 27BD0018 */   addiu    $sp, $sp, 0x18
