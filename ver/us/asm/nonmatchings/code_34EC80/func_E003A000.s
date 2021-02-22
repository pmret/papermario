.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E003A000
/* 34EC80 E003A000 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 34EC84 E003A004 F7B40048 */  sdc1      $f20, 0x48($sp)
/* 34EC88 E003A008 4485A000 */  mtc1      $a1, $f20
/* 34EC8C E003A00C F7B60050 */  sdc1      $f22, 0x50($sp)
/* 34EC90 E003A010 4486B000 */  mtc1      $a2, $f22
/* 34EC94 E003A014 F7B80058 */  sdc1      $f24, 0x58($sp)
/* 34EC98 E003A018 4487C000 */  mtc1      $a3, $f24
/* 34EC9C E003A01C AFB30034 */  sw        $s3, 0x34($sp)
/* 34ECA0 E003A020 8FB3007C */  lw        $s3, 0x7c($sp)
/* 34ECA4 E003A024 AFB5003C */  sw        $s5, 0x3c($sp)
/* 34ECA8 E003A028 0080A82D */  daddu     $s5, $a0, $zero
/* 34ECAC E003A02C F7BA0060 */  sdc1      $f26, 0x60($sp)
/* 34ECB0 E003A030 C7BA0080 */  lwc1      $f26, 0x80($sp)
/* 34ECB4 E003A034 27A40010 */  addiu     $a0, $sp, 0x10
/* 34ECB8 E003A038 AFB40038 */  sw        $s4, 0x38($sp)
/* 34ECBC E003A03C 8FB40084 */  lw        $s4, 0x84($sp)
/* 34ECC0 E003A040 3C02E004 */  lui       $v0, %hi(func_E003A1D4)
/* 34ECC4 E003A044 2442A1D4 */  addiu     $v0, $v0, %lo(func_E003A1D4)
/* 34ECC8 E003A048 AFA20018 */  sw        $v0, 0x18($sp)
/* 34ECCC E003A04C 3C02E004 */  lui       $v0, %hi(func_E003A1DC)
/* 34ECD0 E003A050 2442A1DC */  addiu     $v0, $v0, %lo(func_E003A1DC)
/* 34ECD4 E003A054 AFA2001C */  sw        $v0, 0x1c($sp)
/* 34ECD8 E003A058 3C02E004 */  lui       $v0, %hi(func_E003A310)
/* 34ECDC E003A05C 2442A310 */  addiu     $v0, $v0, %lo(func_E003A310)
/* 34ECE0 E003A060 AFA20020 */  sw        $v0, 0x20($sp)
/* 34ECE4 E003A064 2402001D */  addiu     $v0, $zero, 0x1d
/* 34ECE8 E003A068 AFBF0040 */  sw        $ra, 0x40($sp)
/* 34ECEC E003A06C AFB20030 */  sw        $s2, 0x30($sp)
/* 34ECF0 E003A070 AFB1002C */  sw        $s1, 0x2c($sp)
/* 34ECF4 E003A074 AFB00028 */  sw        $s0, 0x28($sp)
/* 34ECF8 E003A078 AFA00010 */  sw        $zero, 0x10($sp)
/* 34ECFC E003A07C AFA00024 */  sw        $zero, 0x24($sp)
/* 34ED00 E003A080 AFA20014 */  sw        $v0, 0x14($sp)
/* 34ED04 E003A084 0C080124 */  jal       func_E0200490
/* 34ED08 E003A088 26730001 */   addiu    $s3, $s3, 1
/* 34ED0C E003A08C 00132040 */  sll       $a0, $s3, 1
/* 34ED10 E003A090 00932021 */  addu      $a0, $a0, $s3
/* 34ED14 E003A094 00042080 */  sll       $a0, $a0, 2
/* 34ED18 E003A098 00932021 */  addu      $a0, $a0, $s3
/* 34ED1C E003A09C 00042080 */  sll       $a0, $a0, 2
/* 34ED20 E003A0A0 0040802D */  daddu     $s0, $v0, $zero
/* 34ED24 E003A0A4 0C08012C */  jal       func_E02004B0
/* 34ED28 E003A0A8 AE130008 */   sw       $s3, 8($s0)
/* 34ED2C E003A0AC 0040882D */  daddu     $s1, $v0, $zero
/* 34ED30 E003A0B0 16200003 */  bnez      $s1, .LE003A0C0
/* 34ED34 E003A0B4 AE11000C */   sw       $s1, 0xc($s0)
.LE003A0B8:
/* 34ED38 E003A0B8 0800E82E */  j         .LE003A0B8
/* 34ED3C E003A0BC 00000000 */   nop
.LE003A0C0:
/* 34ED40 E003A0C0 0220202D */  daddu     $a0, $s1, $zero
/* 34ED44 E003A0C4 00132840 */  sll       $a1, $s3, 1
/* 34ED48 E003A0C8 00B32821 */  addu      $a1, $a1, $s3
/* 34ED4C E003A0CC 00052880 */  sll       $a1, $a1, 2
/* 34ED50 E003A0D0 00B32821 */  addu      $a1, $a1, $s3
/* 34ED54 E003A0D4 0C080130 */  jal       func_E02004C0
/* 34ED58 E003A0D8 00052880 */   sll      $a1, $a1, 2
/* 34ED5C E003A0DC 3C014120 */  lui       $at, 0x4120
/* 34ED60 E003A0E0 44811000 */  mtc1      $at, $f2
/* 34ED64 E003A0E4 24120001 */  addiu     $s2, $zero, 1
/* 34ED68 E003A0E8 AE340024 */  sw        $s4, 0x24($s1)
/* 34ED6C E003A0EC AE200028 */  sw        $zero, 0x28($s1)
/* 34ED70 E003A0F0 AE34002C */  sw        $s4, 0x2c($s1)
/* 34ED74 E003A0F4 AE200030 */  sw        $zero, 0x30($s1)
/* 34ED78 E003A0F8 A6350000 */  sh        $s5, ($s1)
/* 34ED7C E003A0FC E6340004 */  swc1      $f20, 4($s1)
/* 34ED80 E003A100 E6360008 */  swc1      $f22, 8($s1)
/* 34ED84 E003A104 E638000C */  swc1      $f24, 0xc($s1)
/* 34ED88 E003A108 C7A00078 */  lwc1      $f0, 0x78($sp)
/* 34ED8C E003A10C 0253102A */  slt       $v0, $s2, $s3
/* 34ED90 E003A110 E6200020 */  swc1      $f0, 0x20($s1)
/* 34ED94 E003A114 E622001C */  swc1      $f2, 0x1c($s1)
/* 34ED98 E003A118 10400021 */  beqz      $v0, .LE003A1A0
/* 34ED9C E003A11C 26310034 */   addiu    $s1, $s1, 0x34
/* 34EDA0 E003A120 2674FFFF */  addiu     $s4, $s3, -1
/* 34EDA4 E003A124 26300018 */  addiu     $s0, $s1, 0x18
/* 34EDA8 E003A128 0000882D */  daddu     $s1, $zero, $zero
.LE003A12C:
/* 34EDAC E003A12C 16800002 */  bnez      $s4, .LE003A138
/* 34EDB0 E003A130 0234001A */   div      $zero, $s1, $s4
/* 34EDB4 E003A134 0007000D */  break     7
.LE003A138:
/* 34EDB8 E003A138 2401FFFF */   addiu    $at, $zero, -1
/* 34EDBC E003A13C 16810004 */  bne       $s4, $at, .LE003A150
/* 34EDC0 E003A140 3C018000 */   lui      $at, 0x8000
/* 34EDC4 E003A144 16210002 */  bne       $s1, $at, .LE003A150
/* 34EDC8 E003A148 00000000 */   nop
/* 34EDCC E003A14C 0006000D */  break     6
.LE003A150:
/* 34EDD0 E003A150 00001812 */   mflo     $v1
/* 34EDD4 E003A154 26310168 */  addiu     $s1, $s1, 0x168
/* 34EDD8 E003A158 26520001 */  addiu     $s2, $s2, 1
/* 34EDDC E003A15C AE00FFEC */  sw        $zero, -0x14($s0)
/* 34EDE0 E003A160 4483A000 */  mtc1      $v1, $f20
/* 34EDE4 E003A164 00000000 */  nop
/* 34EDE8 E003A168 4680A520 */  cvt.s.w   $f20, $f20
/* 34EDEC E003A16C 4614D500 */  add.s     $f20, $f26, $f20
/* 34EDF0 E003A170 AE00FFF0 */  sw        $zero, -0x10($s0)
/* 34EDF4 E003A174 AE00FFF4 */  sw        $zero, -0xc($s0)
/* 34EDF8 E003A178 0C080140 */  jal       func_E0200500
/* 34EDFC E003A17C 4600A306 */   mov.s    $f12, $f20
/* 34EE00 E003A180 4600A306 */  mov.s     $f12, $f20
/* 34EE04 E003A184 E600FFF8 */  swc1      $f0, -8($s0)
/* 34EE08 E003A188 0C080144 */  jal       func_E0200510
/* 34EE0C E003A18C AE00FFFC */   sw       $zero, -4($s0)
/* 34EE10 E003A190 E6000000 */  swc1      $f0, ($s0)
/* 34EE14 E003A194 0253102A */  slt       $v0, $s2, $s3
/* 34EE18 E003A198 1440FFE4 */  bnez      $v0, .LE003A12C
/* 34EE1C E003A19C 26100034 */   addiu    $s0, $s0, 0x34
.LE003A1A0:
/* 34EE20 E003A1A0 8FBF0040 */  lw        $ra, 0x40($sp)
/* 34EE24 E003A1A4 8FB5003C */  lw        $s5, 0x3c($sp)
/* 34EE28 E003A1A8 8FB40038 */  lw        $s4, 0x38($sp)
/* 34EE2C E003A1AC 8FB30034 */  lw        $s3, 0x34($sp)
/* 34EE30 E003A1B0 8FB20030 */  lw        $s2, 0x30($sp)
/* 34EE34 E003A1B4 8FB1002C */  lw        $s1, 0x2c($sp)
/* 34EE38 E003A1B8 8FB00028 */  lw        $s0, 0x28($sp)
/* 34EE3C E003A1BC D7BA0060 */  ldc1      $f26, 0x60($sp)
/* 34EE40 E003A1C0 D7B80058 */  ldc1      $f24, 0x58($sp)
/* 34EE44 E003A1C4 D7B60050 */  ldc1      $f22, 0x50($sp)
/* 34EE48 E003A1C8 D7B40048 */  ldc1      $f20, 0x48($sp)
/* 34EE4C E003A1CC 03E00008 */  jr        $ra
/* 34EE50 E003A1D0 27BD0068 */   addiu    $sp, $sp, 0x68
