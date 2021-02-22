.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800479DC
/* 22DDC 800479DC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 22DE0 800479E0 00041040 */  sll       $v0, $a0, 1
/* 22DE4 800479E4 00441021 */  addu      $v0, $v0, $a0
/* 22DE8 800479E8 00021080 */  sll       $v0, $v0, 2
/* 22DEC 800479EC 00441023 */  subu      $v0, $v0, $a0
/* 22DF0 800479F0 3C03800A */  lui       $v1, %hi(D_8009ED54)
/* 22DF4 800479F4 8C63ED54 */  lw        $v1, %lo(D_8009ED54)($v1)
/* 22DF8 800479F8 00021100 */  sll       $v0, $v0, 4
/* 22DFC 800479FC AFBF0018 */  sw        $ra, 0x18($sp)
/* 22E00 80047A00 AFB10014 */  sw        $s1, 0x14($sp)
/* 22E04 80047A04 AFB00010 */  sw        $s0, 0x10($sp)
/* 22E08 80047A08 00628821 */  addu      $s1, $v1, $v0
/* 22E0C 80047A0C 2403FF7F */  addiu     $v1, $zero, -0x81
/* 22E10 80047A10 8E220000 */  lw        $v0, ($s1)
/* 22E14 80047A14 82240084 */  lb        $a0, 0x84($s1)
/* 22E18 80047A18 00431024 */  and       $v0, $v0, $v1
/* 22E1C 80047A1C 1480000E */  bnez      $a0, .L80047A58
/* 22E20 80047A20 AE220000 */   sw       $v0, ($s1)
/* 22E24 80047A24 3C048010 */  lui       $a0, %hi(D_801074A4)
/* 22E28 80047A28 248474A4 */  addiu     $a0, $a0, %lo(D_801074A4)
/* 22E2C 80047A2C 24020001 */  addiu     $v0, $zero, 1
/* 22E30 80047A30 0C051955 */  jal       func_80146554
/* 22E34 80047A34 A2220084 */   sb       $v0, 0x84($s1)
/* 22E38 80047A38 0040802D */  daddu     $s0, $v0, $zero
/* 22E3C 80047A3C 0200202D */  daddu     $a0, $s0, $zero
/* 22E40 80047A40 0C0526AC */  jal       func_80149AB0
/* 22E44 80047A44 24050002 */   addiu    $a1, $zero, 2
/* 22E48 80047A48 0200202D */  daddu     $a0, $s0, $zero
/* 22E4C 80047A4C 0C0526AC */  jal       func_80149AB0
/* 22E50 80047A50 24050080 */   addiu    $a1, $zero, 0x80
/* 22E54 80047A54 AE300088 */  sw        $s0, 0x88($s1)
.L80047A58:
/* 22E58 80047A58 8FBF0018 */  lw        $ra, 0x18($sp)
/* 22E5C 80047A5C 8FB10014 */  lw        $s1, 0x14($sp)
/* 22E60 80047A60 8FB00010 */  lw        $s0, 0x10($sp)
/* 22E64 80047A64 03E00008 */  jr        $ra
/* 22E68 80047A68 27BD0020 */   addiu    $sp, $sp, 0x20
