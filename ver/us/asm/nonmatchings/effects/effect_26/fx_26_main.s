.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_26_main
/* 344A10 E0034000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 344A14 E0034004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 344A18 E0034008 4485A000 */  mtc1      $a1, $f20
/* 344A1C E003400C AFB1002C */  sw        $s1, 0x2c($sp)
/* 344A20 E0034010 0080882D */  daddu     $s1, $a0, $zero
/* 344A24 E0034014 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 344A28 E0034018 4486B000 */  mtc1      $a2, $f22
/* 344A2C E003401C 27A40010 */  addiu     $a0, $sp, 0x10
/* 344A30 E0034020 F7B80048 */  sdc1      $f24, 0x48($sp)
/* 344A34 E0034024 4487C000 */  mtc1      $a3, $f24
/* 344A38 E0034028 3C02E003 */  lui       $v0, %hi(func_E0034108)
/* 344A3C E003402C 24424108 */  addiu     $v0, $v0, %lo(func_E0034108)
/* 344A40 E0034030 AFA20018 */  sw        $v0, 0x18($sp)
/* 344A44 E0034034 3C02E003 */  lui       $v0, %hi(func_E0034110)
/* 344A48 E0034038 24424110 */  addiu     $v0, $v0, %lo(func_E0034110)
/* 344A4C E003403C AFA2001C */  sw        $v0, 0x1c($sp)
/* 344A50 E0034040 3C02E003 */  lui       $v0, %hi(func_E00342C8)
/* 344A54 E0034044 244242C8 */  addiu     $v0, $v0, %lo(func_E00342C8)
/* 344A58 E0034048 AFA20020 */  sw        $v0, 0x20($sp)
/* 344A5C E003404C 2402001A */  addiu     $v0, $zero, 0x1a
/* 344A60 E0034050 AFBF0030 */  sw        $ra, 0x30($sp)
/* 344A64 E0034054 AFB00028 */  sw        $s0, 0x28($sp)
/* 344A68 E0034058 AFA00010 */  sw        $zero, 0x10($sp)
/* 344A6C E003405C AFA00024 */  sw        $zero, 0x24($sp)
/* 344A70 E0034060 0C080124 */  jal       func_E0200490
/* 344A74 E0034064 AFA20014 */   sw       $v0, 0x14($sp)
/* 344A78 E0034068 24040034 */  addiu     $a0, $zero, 0x34
/* 344A7C E003406C 24030001 */  addiu     $v1, $zero, 1
/* 344A80 E0034070 0040802D */  daddu     $s0, $v0, $zero
/* 344A84 E0034074 0C08012C */  jal       func_E02004B0
/* 344A88 E0034078 AE030008 */   sw       $v1, 8($s0)
/* 344A8C E003407C 0040182D */  daddu     $v1, $v0, $zero
/* 344A90 E0034080 14600003 */  bnez      $v1, .LE0034090
/* 344A94 E0034084 AE02000C */   sw       $v0, 0xc($s0)
.LE0034088:
/* 344A98 E0034088 0800D022 */  j         .LE0034088
/* 344A9C E003408C 00000000 */   nop
.LE0034090:
/* 344AA0 E0034090 AC710000 */  sw        $s1, ($v1)
/* 344AA4 E0034094 E4740004 */  swc1      $f20, 4($v1)
/* 344AA8 E0034098 E4760008 */  swc1      $f22, 8($v1)
/* 344AAC E003409C E478000C */  swc1      $f24, 0xc($v1)
/* 344AB0 E00340A0 8FA20060 */  lw        $v0, 0x60($sp)
/* 344AB4 E00340A4 AC600030 */  sw        $zero, 0x30($v1)
/* 344AB8 E00340A8 AC600024 */  sw        $zero, 0x24($v1)
/* 344ABC E00340AC AC600010 */  sw        $zero, 0x10($v1)
/* 344AC0 E00340B0 16200005 */  bnez      $s1, .LE00340C8
/* 344AC4 E00340B4 AC62002C */   sw       $v0, 0x2c($v1)
/* 344AC8 E00340B8 3C0141F0 */  lui       $at, 0x41f0
/* 344ACC E00340BC 44810000 */  mtc1      $at, $f0
/* 344AD0 E00340C0 0800D033 */  j         .LE00340CC
/* 344AD4 E00340C4 E4600014 */   swc1     $f0, 0x14($v1)
.LE00340C8:
/* 344AD8 E00340C8 AC600014 */  sw        $zero, 0x14($v1)
.LE00340CC:
/* 344ADC E00340CC 3C013F4C */  lui       $at, 0x3f4c
/* 344AE0 E00340D0 3421CCCD */  ori       $at, $at, 0xcccd
/* 344AE4 E00340D4 44810000 */  mtc1      $at, $f0
/* 344AE8 E00340D8 AC600018 */  sw        $zero, 0x18($v1)
/* 344AEC E00340DC AC600028 */  sw        $zero, 0x28($v1)
/* 344AF0 E00340E0 AC600020 */  sw        $zero, 0x20($v1)
/* 344AF4 E00340E4 E460001C */  swc1      $f0, 0x1c($v1)
/* 344AF8 E00340E8 8FBF0030 */  lw        $ra, 0x30($sp)
/* 344AFC E00340EC 8FB1002C */  lw        $s1, 0x2c($sp)
/* 344B00 E00340F0 8FB00028 */  lw        $s0, 0x28($sp)
/* 344B04 E00340F4 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 344B08 E00340F8 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 344B0C E00340FC D7B40038 */  ldc1      $f20, 0x38($sp)
/* 344B10 E0034100 03E00008 */  jr        $ra
/* 344B14 E0034104 27BD0050 */   addiu    $sp, $sp, 0x50
