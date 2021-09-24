.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_27_main
/* 3454E0 E0036000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3454E4 E0036004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3454E8 E0036008 4485A000 */  mtc1      $a1, $f20
/* 3454EC E003600C AFB1002C */  sw        $s1, 0x2c($sp)
/* 3454F0 E0036010 0080882D */  daddu     $s1, $a0, $zero
/* 3454F4 E0036014 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3454F8 E0036018 4486B000 */  mtc1      $a2, $f22
/* 3454FC E003601C 27A40010 */  addiu     $a0, $sp, 0x10
/* 345500 E0036020 F7B80048 */  sdc1      $f24, 0x48($sp)
/* 345504 E0036024 4487C000 */  mtc1      $a3, $f24
/* 345508 E0036028 3C02E003 */  lui       $v0, %hi(func_E00360DC)
/* 34550C E003602C 244260DC */  addiu     $v0, $v0, %lo(func_E00360DC)
/* 345510 E0036030 AFA20018 */  sw        $v0, 0x18($sp)
/* 345514 E0036034 3C02E003 */  lui       $v0, %hi(func_E00360E4)
/* 345518 E0036038 244260E4 */  addiu     $v0, $v0, %lo(func_E00360E4)
/* 34551C E003603C AFA2001C */  sw        $v0, 0x1c($sp)
/* 345520 E0036040 3C02E003 */  lui       $v0, %hi(func_E00361D8)
/* 345524 E0036044 244261D8 */  addiu     $v0, $v0, %lo(func_E00361D8)
/* 345528 E0036048 AFA20020 */  sw        $v0, 0x20($sp)
/* 34552C E003604C 2402001B */  addiu     $v0, $zero, 0x1b
/* 345530 E0036050 AFBF0030 */  sw        $ra, 0x30($sp)
/* 345534 E0036054 AFB00028 */  sw        $s0, 0x28($sp)
/* 345538 E0036058 AFA00010 */  sw        $zero, 0x10($sp)
/* 34553C E003605C AFA00024 */  sw        $zero, 0x24($sp)
/* 345540 E0036060 0C080124 */  jal       shim_create_effect_instance
/* 345544 E0036064 AFA20014 */   sw       $v0, 0x14($sp)
/* 345548 E0036068 24040020 */  addiu     $a0, $zero, 0x20
/* 34554C E003606C 24030001 */  addiu     $v1, $zero, 1
/* 345550 E0036070 0040802D */  daddu     $s0, $v0, $zero
/* 345554 E0036074 0C08012C */  jal       shim_general_heap_malloc
/* 345558 E0036078 AE030008 */   sw       $v1, 8($s0)
/* 34555C E003607C 0040182D */  daddu     $v1, $v0, $zero
/* 345560 E0036080 14600003 */  bnez      $v1, .LE0036090
/* 345564 E0036084 AE02000C */   sw       $v0, 0xc($s0)
.LE0036088:
/* 345568 E0036088 0800D822 */  j         .LE0036088
/* 34556C E003608C 00000000 */   nop
.LE0036090:
/* 345570 E0036090 24020064 */  addiu     $v0, $zero, 0x64
/* 345574 E0036094 AC620014 */  sw        $v0, 0x14($v1)
/* 345578 E0036098 240200FF */  addiu     $v0, $zero, 0xff
/* 34557C E003609C AC710000 */  sw        $s1, ($v1)
/* 345580 E00360A0 AC600010 */  sw        $zero, 0x10($v1)
/* 345584 E00360A4 E4740004 */  swc1      $f20, 4($v1)
/* 345588 E00360A8 E4760008 */  swc1      $f22, 8($v1)
/* 34558C E00360AC E478000C */  swc1      $f24, 0xc($v1)
/* 345590 E00360B0 AC62001C */  sw        $v0, 0x1c($v1)
/* 345594 E00360B4 8FA20064 */  lw        $v0, 0x64($sp)
/* 345598 E00360B8 AC500000 */  sw        $s0, ($v0)
/* 34559C E00360BC 8FBF0030 */  lw        $ra, 0x30($sp)
/* 3455A0 E00360C0 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3455A4 E00360C4 8FB00028 */  lw        $s0, 0x28($sp)
/* 3455A8 E00360C8 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3455AC E00360CC D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3455B0 E00360D0 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3455B4 E00360D4 03E00008 */  jr        $ra
/* 3455B8 E00360D8 27BD0050 */   addiu    $sp, $sp, 0x50
