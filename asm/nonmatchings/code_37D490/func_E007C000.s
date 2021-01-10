.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E007C000
/* 37D490 E007C000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 37D494 E007C004 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 37D498 E007C008 4485A000 */  mtc1      $a1, $f20
/* 37D49C E007C00C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 37D4A0 E007C010 4486B000 */  mtc1      $a2, $f22
/* 37D4A4 E007C014 AFB30034 */  sw        $s3, 0x34($sp)
/* 37D4A8 E007C018 0080982D */  daddu     $s3, $a0, $zero
/* 37D4AC E007C01C F7B80050 */  sdc1      $f24, 0x50($sp)
/* 37D4B0 E007C020 4487C000 */  mtc1      $a3, $f24
/* 37D4B4 E007C024 27A40010 */  addiu     $a0, $sp, 0x10
/* 37D4B8 E007C028 AFB20030 */  sw        $s2, 0x30($sp)
/* 37D4BC E007C02C 8FB2006C */  lw        $s2, 0x6c($sp)
/* 37D4C0 E007C030 3C02E008 */  lui       $v0, %hi(func_E007C128)
/* 37D4C4 E007C034 2442C128 */  addiu     $v0, $v0, %lo(func_E007C128)
/* 37D4C8 E007C038 AFA20018 */  sw        $v0, 0x18($sp)
/* 37D4CC E007C03C 3C02E008 */  lui       $v0, %hi(func_E007C130)
/* 37D4D0 E007C040 2442C130 */  addiu     $v0, $v0, %lo(func_E007C130)
/* 37D4D4 E007C044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 37D4D8 E007C048 3C02E008 */  lui       $v0, %hi(func_E007C1B0)
/* 37D4DC E007C04C 2442C1B0 */  addiu     $v0, $v0, %lo(func_E007C1B0)
/* 37D4E0 E007C050 AFA20020 */  sw        $v0, 0x20($sp)
/* 37D4E4 E007C054 2402003E */  addiu     $v0, $zero, 0x3e
/* 37D4E8 E007C058 AFBF0038 */  sw        $ra, 0x38($sp)
/* 37D4EC E007C05C AFB1002C */  sw        $s1, 0x2c($sp)
/* 37D4F0 E007C060 AFB00028 */  sw        $s0, 0x28($sp)
/* 37D4F4 E007C064 AFA00010 */  sw        $zero, 0x10($sp)
/* 37D4F8 E007C068 AFA00024 */  sw        $zero, 0x24($sp)
/* 37D4FC E007C06C 0C080124 */  jal       func_E0200490
/* 37D500 E007C070 AFA20014 */   sw       $v0, 0x14($sp)
/* 37D504 E007C074 2404002C */  addiu     $a0, $zero, 0x2c
/* 37D508 E007C078 24110001 */  addiu     $s1, $zero, 1
/* 37D50C E007C07C 0040802D */  daddu     $s0, $v0, $zero
/* 37D510 E007C080 0C08012C */  jal       func_E02004B0
/* 37D514 E007C084 AE110008 */   sw       $s1, 8($s0)
/* 37D518 E007C088 AE02000C */  sw        $v0, 0xc($s0)
/* 37D51C E007C08C 0040802D */  daddu     $s0, $v0, $zero
/* 37D520 E007C090 16000003 */  bnez      $s0, .LE007C0A0
/* 37D524 E007C094 0200202D */   daddu    $a0, $s0, $zero
.LE007C098:
/* 37D528 E007C098 0801F026 */  j         .LE007C098
/* 37D52C E007C09C 00000000 */   nop      
.LE007C0A0:
/* 37D530 E007C0A0 00112840 */  sll       $a1, $s1, 1
/* 37D534 E007C0A4 00B12821 */  addu      $a1, $a1, $s1
/* 37D538 E007C0A8 00052880 */  sll       $a1, $a1, 2
/* 37D53C E007C0AC 00B12823 */  subu      $a1, $a1, $s1
/* 37D540 E007C0B0 0C080130 */  jal       func_E02004C0
/* 37D544 E007C0B4 00052880 */   sll      $a1, $a1, 2
/* 37D548 E007C0B8 AE120014 */  sw        $s2, 0x14($s0)
/* 37D54C E007C0BC AE000018 */  sw        $zero, 0x18($s0)
/* 37D550 E007C0C0 AE12001C */  sw        $s2, 0x1c($s0)
/* 37D554 E007C0C4 AE000020 */  sw        $zero, 0x20($s0)
/* 37D558 E007C0C8 A6130000 */  sh        $s3, ($s0)
/* 37D55C E007C0CC E6140004 */  swc1      $f20, 4($s0)
/* 37D560 E007C0D0 E6160008 */  swc1      $f22, 8($s0)
/* 37D564 E007C0D4 E618000C */  swc1      $f24, 0xc($s0)
/* 37D568 E007C0D8 C7A00068 */  lwc1      $f0, 0x68($sp)
/* 37D56C E007C0DC AE000024 */  sw        $zero, 0x24($s0)
/* 37D570 E007C0E0 16600003 */  bnez      $s3, .LE007C0F0
/* 37D574 E007C0E4 E6000010 */   swc1     $f0, 0x10($s0)
/* 37D578 E007C0E8 0801F040 */  j         .LE007C100
/* 37D57C E007C0EC AE000028 */   sw       $zero, 0x28($s0)
.LE007C0F0:
/* 37D580 E007C0F0 3C014220 */  lui       $at, 0x4220
/* 37D584 E007C0F4 44810000 */  mtc1      $at, $f0
/* 37D588 E007C0F8 00000000 */  nop       
/* 37D58C E007C0FC E6000028 */  swc1      $f0, 0x28($s0)
.LE007C100:
/* 37D590 E007C100 8FBF0038 */  lw        $ra, 0x38($sp)
/* 37D594 E007C104 8FB30034 */  lw        $s3, 0x34($sp)
/* 37D598 E007C108 8FB20030 */  lw        $s2, 0x30($sp)
/* 37D59C E007C10C 8FB1002C */  lw        $s1, 0x2c($sp)
/* 37D5A0 E007C110 8FB00028 */  lw        $s0, 0x28($sp)
/* 37D5A4 E007C114 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 37D5A8 E007C118 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 37D5AC E007C11C D7B40040 */  ldc1      $f20, 0x40($sp)
/* 37D5B0 E007C120 03E00008 */  jr        $ra
/* 37D5B4 E007C124 27BD0058 */   addiu    $sp, $sp, 0x58
