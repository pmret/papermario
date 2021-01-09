.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0072000
/* 374E50 E0072000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 374E54 E0072004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 374E58 E0072008 4485A000 */  mtc1      $a1, $f20
/* 374E5C E007200C AFB1002C */  sw        $s1, 0x2c($sp)
/* 374E60 E0072010 0080882D */  daddu     $s1, $a0, $zero
/* 374E64 E0072014 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 374E68 E0072018 4486B000 */  mtc1      $a2, $f22
/* 374E6C E007201C 27A40010 */  addiu     $a0, $sp, 0x10
/* 374E70 E0072020 F7B80048 */  sdc1      $f24, 0x48($sp)
/* 374E74 E0072024 4487C000 */  mtc1      $a3, $f24
/* 374E78 E0072028 3C02E007 */  lui       $v0, %hi(func_E0072148)
/* 374E7C E007202C 24422148 */  addiu     $v0, $v0, %lo(func_E0072148)
/* 374E80 E0072030 AFA20018 */  sw        $v0, 0x18($sp)
/* 374E84 E0072034 3C02E007 */  lui       $v0, %hi(func_E0072150)
/* 374E88 E0072038 24422150 */  addiu     $v0, $v0, %lo(func_E0072150)
/* 374E8C E007203C AFA2001C */  sw        $v0, 0x1c($sp)
/* 374E90 E0072040 3C02E007 */  lui       $v0, %hi(func_E007238C)
/* 374E94 E0072044 2442238C */  addiu     $v0, $v0, %lo(func_E007238C)
/* 374E98 E0072048 AFA20020 */  sw        $v0, 0x20($sp)
/* 374E9C E007204C 24020039 */  addiu     $v0, $zero, 0x39
/* 374EA0 E0072050 AFBF0030 */  sw        $ra, 0x30($sp)
/* 374EA4 E0072054 AFB00028 */  sw        $s0, 0x28($sp)
/* 374EA8 E0072058 AFA00010 */  sw        $zero, 0x10($sp)
/* 374EAC E007205C AFA00024 */  sw        $zero, 0x24($sp)
/* 374EB0 E0072060 0C080124 */  jal       func_E0200490
/* 374EB4 E0072064 AFA20014 */   sw       $v0, 0x14($sp)
/* 374EB8 E0072068 24040A2C */  addiu     $a0, $zero, 0xa2c
/* 374EBC E007206C 2403001F */  addiu     $v1, $zero, 0x1f
/* 374EC0 E0072070 0040802D */  daddu     $s0, $v0, $zero
/* 374EC4 E0072074 0C08012C */  jal       func_E02004B0
/* 374EC8 E0072078 AE030008 */   sw       $v1, 8($s0)
/* 374ECC E007207C 0040202D */  daddu     $a0, $v0, $zero
/* 374ED0 E0072080 14800003 */  bnez      $a0, .LE0072090
/* 374ED4 E0072084 AE02000C */   sw       $v0, 0xc($s0)
.LE0072088:
/* 374ED8 E0072088 0801C822 */  j         .LE0072088
/* 374EDC E007208C 00000000 */   nop      
.LE0072090:
/* 374EE0 E0072090 240300FF */  addiu     $v1, $zero, 0xff
/* 374EE4 E0072094 AC910000 */  sw        $s1, ($a0)
/* 374EE8 E0072098 E4940004 */  swc1      $f20, 4($a0)
/* 374EEC E007209C E4960008 */  swc1      $f22, 8($a0)
/* 374EF0 E00720A0 E498000C */  swc1      $f24, 0xc($a0)
/* 374EF4 E00720A4 AC830024 */  sw        $v1, 0x24($a0)
/* 374EF8 E00720A8 8FA20064 */  lw        $v0, 0x64($sp)
/* 374EFC E00720AC 3C01E007 */  lui       $at, %hi(D_E00726B0)
/* 374F00 E00720B0 D42226B0 */  ldc1      $f2, %lo(D_E00726B0)($at)
/* 374F04 E00720B4 AC80002C */  sw        $zero, 0x2c($a0)
/* 374F08 E00720B8 AC800030 */  sw        $zero, 0x30($a0)
/* 374F0C E00720BC AC800034 */  sw        $zero, 0x34($a0)
/* 374F10 E00720C0 AC800038 */  sw        $zero, 0x38($a0)
/* 374F14 E00720C4 AC80003C */  sw        $zero, 0x3c($a0)
/* 374F18 E00720C8 AC800044 */  sw        $zero, 0x44($a0)
/* 374F1C E00720CC AC80001C */  sw        $zero, 0x1c($a0)
/* 374F20 E00720D0 A0830050 */  sb        $v1, 0x50($a0)
/* 374F24 E00720D4 A0830051 */  sb        $v1, 0x51($a0)
/* 374F28 E00720D8 AC820028 */  sw        $v0, 0x28($a0)
/* 374F2C E00720DC C7A00060 */  lwc1      $f0, 0x60($sp)
/* 374F30 E00720E0 3C013ECC */  lui       $at, 0x3ecc
/* 374F34 E00720E4 3421CCCD */  ori       $at, $at, 0xcccd
/* 374F38 E00720E8 44812000 */  mtc1      $at, $f4
/* 374F3C E00720EC 46000021 */  cvt.d.s   $f0, $f0
/* 374F40 E00720F0 46220002 */  mul.d     $f0, $f0, $f2
/* 374F44 E00720F4 00000000 */  nop       
/* 374F48 E00720F8 3C013F80 */  lui       $at, 0x3f80
/* 374F4C E00720FC 44813000 */  mtc1      $at, $f6
/* 374F50 E0072100 3C01BF8C */  lui       $at, 0xbf8c
/* 374F54 E0072104 3421CCCD */  ori       $at, $at, 0xcccd
/* 374F58 E0072108 44811000 */  mtc1      $at, $f2
/* 374F5C E007210C 24020040 */  addiu     $v0, $zero, 0x40
/* 374F60 E0072110 A0820052 */  sb        $v0, 0x52($a0)
/* 374F64 E0072114 E4840048 */  swc1      $f4, 0x48($a0)
/* 374F68 E0072118 E486004C */  swc1      $f6, 0x4c($a0)
/* 374F6C E007211C E4820040 */  swc1      $f2, 0x40($a0)
/* 374F70 E0072120 46200020 */  cvt.s.d   $f0, $f0
/* 374F74 E0072124 E4800020 */  swc1      $f0, 0x20($a0)
/* 374F78 E0072128 8FBF0030 */  lw        $ra, 0x30($sp)
/* 374F7C E007212C 8FB1002C */  lw        $s1, 0x2c($sp)
/* 374F80 E0072130 8FB00028 */  lw        $s0, 0x28($sp)
/* 374F84 E0072134 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 374F88 E0072138 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 374F8C E007213C D7B40038 */  ldc1      $f20, 0x38($sp)
/* 374F90 E0072140 03E00008 */  jr        $ra
/* 374F94 E0072144 27BD0050 */   addiu    $sp, $sp, 0x50
