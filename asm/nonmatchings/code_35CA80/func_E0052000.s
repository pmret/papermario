.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0052000
/* 35CA80 E0052000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 35CA84 E0052004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 35CA88 E0052008 4485A000 */  mtc1      $a1, $f20
/* 35CA8C E005200C AFB1002C */  sw        $s1, 0x2c($sp)
/* 35CA90 E0052010 0080882D */  daddu     $s1, $a0, $zero
/* 35CA94 E0052014 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 35CA98 E0052018 4486B000 */  mtc1      $a2, $f22
/* 35CA9C E005201C 27A40010 */  addiu     $a0, $sp, 0x10
/* 35CAA0 E0052020 F7B80048 */  sdc1      $f24, 0x48($sp)
/* 35CAA4 E0052024 4487C000 */  mtc1      $a3, $f24
/* 35CAA8 E0052028 3C02E005 */  lui       $v0, %hi(func_E00520E8)
/* 35CAAC E005202C 244220E8 */  addiu     $v0, $v0, %lo(func_E00520E8)
/* 35CAB0 E0052030 AFA20018 */  sw        $v0, 0x18($sp)
/* 35CAB4 E0052034 3C02E005 */  lui       $v0, %hi(func_E00520F0)
/* 35CAB8 E0052038 244220F0 */  addiu     $v0, $v0, %lo(func_E00520F0)
/* 35CABC E005203C AFA2001C */  sw        $v0, 0x1c($sp)
/* 35CAC0 E0052040 3C02E005 */  lui       $v0, %hi(func_E005241C)
/* 35CAC4 E0052044 2442241C */  addiu     $v0, $v0, %lo(func_E005241C)
/* 35CAC8 E0052048 AFA20020 */  sw        $v0, 0x20($sp)
/* 35CACC E005204C 24020029 */  addiu     $v0, $zero, 0x29
/* 35CAD0 E0052050 AFBF0030 */  sw        $ra, 0x30($sp)
/* 35CAD4 E0052054 AFB00028 */  sw        $s0, 0x28($sp)
/* 35CAD8 E0052058 AFA00010 */  sw        $zero, 0x10($sp)
/* 35CADC E005205C AFA00024 */  sw        $zero, 0x24($sp)
/* 35CAE0 E0052060 0C080124 */  jal       func_E0200490
/* 35CAE4 E0052064 AFA20014 */   sw       $v0, 0x14($sp)
/* 35CAE8 E0052068 240400CC */  addiu     $a0, $zero, 0xcc
/* 35CAEC E005206C 24030001 */  addiu     $v1, $zero, 1
/* 35CAF0 E0052070 0040802D */  daddu     $s0, $v0, $zero
/* 35CAF4 E0052074 0C08012C */  jal       func_E02004B0
/* 35CAF8 E0052078 AE030008 */   sw       $v1, 8($s0)
/* 35CAFC E005207C 0040182D */  daddu     $v1, $v0, $zero
/* 35CB00 E0052080 14600003 */  bnez      $v1, .LE0052090
/* 35CB04 E0052084 AE02000C */   sw       $v0, 0xc($s0)
.LE0052088:
/* 35CB08 E0052088 08014822 */  j         .LE0052088
/* 35CB0C E005208C 00000000 */   nop      
.LE0052090:
/* 35CB10 E0052090 AC710000 */  sw        $s1, ($v1)
/* 35CB14 E0052094 E4740004 */  swc1      $f20, 4($v1)
/* 35CB18 E0052098 E4760008 */  swc1      $f22, 8($v1)
/* 35CB1C E005209C E478000C */  swc1      $f24, 0xc($v1)
/* 35CB20 E00520A0 C7A00064 */  lwc1      $f0, 0x64($sp)
/* 35CB24 E00520A4 24020064 */  addiu     $v0, $zero, 0x64
/* 35CB28 E00520A8 AC62001C */  sw        $v0, 0x1c($v1)
/* 35CB2C E00520AC E4600010 */  swc1      $f0, 0x10($v1)
/* 35CB30 E00520B0 C7A00060 */  lwc1      $f0, 0x60($sp)
/* 35CB34 E00520B4 AC600018 */  sw        $zero, 0x18($v1)
/* 35CB38 E00520B8 AC600020 */  sw        $zero, 0x20($v1)
/* 35CB3C E00520BC E4600014 */  swc1      $f0, 0x14($v1)
/* 35CB40 E00520C0 8FA20068 */  lw        $v0, 0x68($sp)
/* 35CB44 E00520C4 AC500000 */  sw        $s0, ($v0)
/* 35CB48 E00520C8 8FBF0030 */  lw        $ra, 0x30($sp)
/* 35CB4C E00520CC 8FB1002C */  lw        $s1, 0x2c($sp)
/* 35CB50 E00520D0 8FB00028 */  lw        $s0, 0x28($sp)
/* 35CB54 E00520D4 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 35CB58 E00520D8 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 35CB5C E00520DC D7B40038 */  ldc1      $f20, 0x38($sp)
/* 35CB60 E00520E0 03E00008 */  jr        $ra
/* 35CB64 E00520E4 27BD0050 */   addiu    $sp, $sp, 0x50
