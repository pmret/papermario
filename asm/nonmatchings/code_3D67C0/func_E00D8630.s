.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00D8630
/* 3D6DF0 E00D8630 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 3D6DF4 E00D8634 3C07DB06 */  lui       $a3, 0xdb06
/* 3D6DF8 E00D8638 3C06800A */  lui       $a2, %hi(gMasterGfxPos)
/* 3D6DFC E00D863C 24C6A66C */  addiu     $a2, $a2, %lo(gMasterGfxPos)
/* 3D6E00 E00D8640 34E70024 */  ori       $a3, $a3, 0x24
/* 3D6E04 E00D8644 3C02E700 */  lui       $v0, 0xe700
/* 3D6E08 E00D8648 AFBF0050 */  sw        $ra, 0x50($sp)
/* 3D6E0C E00D864C 8CC50000 */  lw        $a1, ($a2)
/* 3D6E10 E00D8650 8C88000C */  lw        $t0, 0xc($a0)
/* 3D6E14 E00D8654 3C013F80 */  lui       $at, 0x3f80
/* 3D6E18 E00D8658 44810000 */  mtc1      $at, $f0
/* 3D6E1C E00D865C 00A0182D */  daddu     $v1, $a1, $zero
/* 3D6E20 E00D8660 24A50008 */  addiu     $a1, $a1, 8
/* 3D6E24 E00D8664 AC620000 */  sw        $v0, ($v1)
/* 3D6E28 E00D8668 AC600004 */  sw        $zero, 4($v1)
/* 3D6E2C E00D866C ACA70000 */  sw        $a3, ($a1)
/* 3D6E30 E00D8670 8C820010 */  lw        $v0, 0x10($a0)
/* 3D6E34 E00D8674 24040001 */  addiu     $a0, $zero, 1
/* 3D6E38 E00D8678 ACC50000 */  sw        $a1, ($a2)
/* 3D6E3C E00D867C 8C42001C */  lw        $v0, 0x1c($v0)
/* 3D6E40 E00D8680 3C038000 */  lui       $v1, 0x8000
/* 3D6E44 E00D8684 00431021 */  addu      $v0, $v0, $v1
/* 3D6E48 E00D8688 ACA20004 */  sw        $v0, 4($a1)
/* 3D6E4C E00D868C C502001C */  lwc1      $f2, 0x1c($t0)
/* 3D6E50 E00D8690 24A50008 */  addiu     $a1, $a1, 8
/* 3D6E54 E00D8694 46001032 */  c.eq.s    $f2, $f0
/* 3D6E58 E00D8698 00000000 */  nop       
/* 3D6E5C E00D869C 45000012 */  bc1f      .LE00D86E8
/* 3D6E60 E00D86A0 ACC50000 */   sw       $a1, ($a2)
/* 3D6E64 E00D86A4 C5000020 */  lwc1      $f0, 0x20($t0)
/* 3D6E68 E00D86A8 44801000 */  mtc1      $zero, $f2
/* 3D6E6C E00D86AC 00000000 */  nop       
/* 3D6E70 E00D86B0 46020032 */  c.eq.s    $f0, $f2
/* 3D6E74 E00D86B4 00000000 */  nop       
/* 3D6E78 E00D86B8 4500000B */  bc1f      .LE00D86E8
/* 3D6E7C E00D86BC 00000000 */   nop      
/* 3D6E80 E00D86C0 C5000024 */  lwc1      $f0, 0x24($t0)
/* 3D6E84 E00D86C4 46020032 */  c.eq.s    $f0, $f2
/* 3D6E88 E00D86C8 00000000 */  nop       
/* 3D6E8C E00D86CC 45000006 */  bc1f      .LE00D86E8
/* 3D6E90 E00D86D0 00000000 */   nop      
/* 3D6E94 E00D86D4 C5000028 */  lwc1      $f0, 0x28($t0)
/* 3D6E98 E00D86D8 46020032 */  c.eq.s    $f0, $f2
/* 3D6E9C E00D86DC 00000000 */  nop       
/* 3D6EA0 E00D86E0 45030001 */  bc1tl     .LE00D86E8
/* 3D6EA4 E00D86E4 0000202D */   daddu    $a0, $zero, $zero
.LE00D86E8:
/* 3D6EA8 E00D86E8 C5040004 */  lwc1      $f4, 4($t0)
/* 3D6EAC E00D86EC C508002C */  lwc1      $f8, 0x2c($t0)
/* 3D6EB0 E00D86F0 C5020008 */  lwc1      $f2, 8($t0)
/* 3D6EB4 E00D86F4 C50A0030 */  lwc1      $f10, 0x30($t0)
/* 3D6EB8 E00D86F8 C500000C */  lwc1      $f0, 0xc($t0)
/* 3D6EBC E00D86FC 24020096 */  addiu     $v0, $zero, 0x96
/* 3D6EC0 E00D8700 AFA20014 */  sw        $v0, 0x14($sp)
/* 3D6EC4 E00D8704 2402006B */  addiu     $v0, $zero, 0x6b
/* 3D6EC8 E00D8708 AFA20018 */  sw        $v0, 0x18($sp)
/* 3D6ECC E00D870C 240200FF */  addiu     $v0, $zero, 0xff
/* 3D6ED0 E00D8710 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3D6ED4 E00D8714 AFA00020 */  sw        $zero, 0x20($sp)
/* 3D6ED8 E00D8718 4600030D */  trunc.w.s $f12, $f0
/* 3D6EDC E00D871C E7AC0010 */  swc1      $f12, 0x10($sp)
/* 3D6EE0 E00D8720 C500001C */  lwc1      $f0, 0x1c($t0)
/* 3D6EE4 E00D8724 E7A00024 */  swc1      $f0, 0x24($sp)
/* 3D6EE8 E00D8728 C500001C */  lwc1      $f0, 0x1c($t0)
/* 3D6EEC E00D872C 3C02E00E */  lui       $v0, %hi(func_E00D8334)
/* 3D6EF0 E00D8730 24428334 */  addiu     $v0, $v0, %lo(func_E00D8334)
/* 3D6EF4 E00D8734 E7A00028 */  swc1      $f0, 0x28($sp)
/* 3D6EF8 E00D8738 C5000020 */  lwc1      $f0, 0x20($t0)
/* 3D6EFC E00D873C 3C05E00E */  lui       $a1, %hi(D_E00D87E0)
/* 3D6F00 E00D8740 24A587E0 */  addiu     $a1, $a1, %lo(D_E00D87E0)
/* 3D6F04 E00D8744 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 3D6F08 E00D8748 C5000024 */  lwc1      $f0, 0x24($t0)
/* 3D6F0C E00D874C 46082100 */  add.s     $f4, $f4, $f8
/* 3D6F10 E00D8750 E7A00030 */  swc1      $f0, 0x30($sp)
/* 3D6F14 E00D8754 C5060028 */  lwc1      $f6, 0x28($t0)
/* 3D6F18 E00D8758 3C014296 */  lui       $at, 0x4296
/* 3D6F1C E00D875C 44810000 */  mtc1      $at, $f0
/* 3D6F20 E00D8760 460A1080 */  add.s     $f2, $f2, $f10
/* 3D6F24 E00D8764 AFA20038 */  sw        $v0, 0x38($sp)
/* 3D6F28 E00D8768 24020140 */  addiu     $v0, $zero, 0x140
/* 3D6F2C E00D876C AFA20044 */  sw        $v0, 0x44($sp)
/* 3D6F30 E00D8770 46002101 */  sub.s     $f4, $f4, $f0
/* 3D6F34 E00D8774 3C014254 */  lui       $at, 0x4254
/* 3D6F38 E00D8778 44810000 */  mtc1      $at, $f0
/* 3D6F3C E00D877C 240200F0 */  addiu     $v0, $zero, 0xf0
/* 3D6F40 E00D8780 AFA8003C */  sw        $t0, 0x3c($sp)
/* 3D6F44 E00D8784 AFA00040 */  sw        $zero, 0x40($sp)
/* 3D6F48 E00D8788 AFA20048 */  sw        $v0, 0x48($sp)
/* 3D6F4C E00D878C AFA0004C */  sw        $zero, 0x4c($sp)
/* 3D6F50 E00D8790 46001081 */  sub.s     $f2, $f2, $f0
/* 3D6F54 E00D8794 4600230D */  trunc.w.s $f12, $f4
/* 3D6F58 E00D8798 44066000 */  mfc1      $a2, $f12
/* 3D6F5C E00D879C 4600130D */  trunc.w.s $f12, $f2
/* 3D6F60 E00D87A0 44076000 */  mfc1      $a3, $f12
/* 3D6F64 E00D87A4 0C080190 */  jal       func_E0200640
/* 3D6F68 E00D87A8 E7A60034 */   swc1     $f6, 0x34($sp)
/* 3D6F6C E00D87AC 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 3D6F70 E00D87B0 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 3D6F74 E00D87B4 8C620000 */  lw        $v0, ($v1)
/* 3D6F78 E00D87B8 0040202D */  daddu     $a0, $v0, $zero
/* 3D6F7C E00D87BC 24420008 */  addiu     $v0, $v0, 8
/* 3D6F80 E00D87C0 AC620000 */  sw        $v0, ($v1)
/* 3D6F84 E00D87C4 3C02E700 */  lui       $v0, 0xe700
/* 3D6F88 E00D87C8 AC820000 */  sw        $v0, ($a0)
/* 3D6F8C E00D87CC AC800004 */  sw        $zero, 4($a0)
/* 3D6F90 E00D87D0 8FBF0050 */  lw        $ra, 0x50($sp)
/* 3D6F94 E00D87D4 03E00008 */  jr        $ra
/* 3D6F98 E00D87D8 27BD0058 */   addiu    $sp, $sp, 0x58
/* 3D6F9C E00D87DC 00000000 */  nop       
