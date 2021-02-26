.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80047AF8
/* 22EF8 80047AF8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 22EFC 80047AFC 00041040 */  sll       $v0, $a0, 1
/* 22F00 80047B00 00441021 */  addu      $v0, $v0, $a0
/* 22F04 80047B04 00021080 */  sll       $v0, $v0, 2
/* 22F08 80047B08 00441023 */  subu      $v0, $v0, $a0
/* 22F0C 80047B0C 3C03800A */  lui       $v1, %hi(D_8009ED54)
/* 22F10 80047B10 8C63ED54 */  lw        $v1, %lo(D_8009ED54)($v1)
/* 22F14 80047B14 00021100 */  sll       $v0, $v0, 4
/* 22F18 80047B18 AFBF0018 */  sw        $ra, 0x18($sp)
/* 22F1C 80047B1C AFB10014 */  sw        $s1, 0x14($sp)
/* 22F20 80047B20 AFB00010 */  sw        $s0, 0x10($sp)
/* 22F24 80047B24 00628821 */  addu      $s1, $v1, $v0
/* 22F28 80047B28 2403FEFF */  addiu     $v1, $zero, -0x101
/* 22F2C 80047B2C 8E220000 */  lw        $v0, ($s1)
/* 22F30 80047B30 82240090 */  lb        $a0, 0x90($s1)
/* 22F34 80047B34 00431024 */  and       $v0, $v0, $v1
/* 22F38 80047B38 1480000E */  bnez      $a0, .L80047B74
/* 22F3C 80047B3C AE220000 */   sw       $v0, ($s1)
/* 22F40 80047B40 3C048010 */  lui       $a0, %hi(D_80107770)
/* 22F44 80047B44 24847770 */  addiu     $a0, $a0, %lo(D_80107770)
/* 22F48 80047B48 24020001 */  addiu     $v0, $zero, 1
/* 22F4C 80047B4C 0C051955 */  jal       func_80146554
/* 22F50 80047B50 A2220090 */   sb       $v0, 0x90($s1)
/* 22F54 80047B54 0040802D */  daddu     $s0, $v0, $zero
/* 22F58 80047B58 0200202D */  daddu     $a0, $s0, $zero
/* 22F5C 80047B5C 0C0526AC */  jal       func_80149AB0
/* 22F60 80047B60 24050002 */   addiu    $a1, $zero, 2
/* 22F64 80047B64 0200202D */  daddu     $a0, $s0, $zero
/* 22F68 80047B68 0C0526AC */  jal       func_80149AB0
/* 22F6C 80047B6C 24050080 */   addiu    $a1, $zero, 0x80
/* 22F70 80047B70 AE300094 */  sw        $s0, 0x94($s1)
.L80047B74:
/* 22F74 80047B74 8FBF0018 */  lw        $ra, 0x18($sp)
/* 22F78 80047B78 8FB10014 */  lw        $s1, 0x14($sp)
/* 22F7C 80047B7C 8FB00010 */  lw        $s0, 0x10($sp)
/* 22F80 80047B80 03E00008 */  jr        $ra
/* 22F84 80047B84 27BD0020 */   addiu    $sp, $sp, 0x20
