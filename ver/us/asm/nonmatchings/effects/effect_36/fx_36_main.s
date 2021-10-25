.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_36_main
/* 356980 E0048000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 356984 E0048004 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 356988 E0048008 4485A000 */  mtc1      $a1, $f20
/* 35698C E004800C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 356990 E0048010 4486B000 */  mtc1      $a2, $f22
/* 356994 E0048014 AFB30034 */  sw        $s3, 0x34($sp)
/* 356998 E0048018 0080982D */  daddu     $s3, $a0, $zero
/* 35699C E004801C F7B80050 */  sdc1      $f24, 0x50($sp)
/* 3569A0 E0048020 4487C000 */  mtc1      $a3, $f24
/* 3569A4 E0048024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3569A8 E0048028 AFB20030 */  sw        $s2, 0x30($sp)
/* 3569AC E004802C 8FB2006C */  lw        $s2, 0x6c($sp)
/* 3569B0 E0048030 3C02E005 */  lui       $v0, %hi(fx_36_init)
/* 3569B4 E0048034 24428128 */  addiu     $v0, $v0, %lo(fx_36_init)
/* 3569B8 E0048038 AFA20018 */  sw        $v0, 0x18($sp)
/* 3569BC E004803C 3C02E005 */  lui       $v0, %hi(fx_36_update)
/* 3569C0 E0048040 24428130 */  addiu     $v0, $v0, %lo(fx_36_update)
/* 3569C4 E0048044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3569C8 E0048048 3C02E005 */  lui       $v0, %hi(fx_36_render)
/* 3569CC E004804C 244281D4 */  addiu     $v0, $v0, %lo(fx_36_render)
/* 3569D0 E0048050 AFA20020 */  sw        $v0, 0x20($sp)
/* 3569D4 E0048054 24020024 */  addiu     $v0, $zero, 0x24
/* 3569D8 E0048058 AFBF0038 */  sw        $ra, 0x38($sp)
/* 3569DC E004805C AFB1002C */  sw        $s1, 0x2c($sp)
/* 3569E0 E0048060 AFB00028 */  sw        $s0, 0x28($sp)
/* 3569E4 E0048064 AFA00010 */  sw        $zero, 0x10($sp)
/* 3569E8 E0048068 AFA00024 */  sw        $zero, 0x24($sp)
/* 3569EC E004806C 0C080124 */  jal       shim_create_effect_instance
/* 3569F0 E0048070 AFA20014 */   sw       $v0, 0x14($sp)
/* 3569F4 E0048074 2404002C */  addiu     $a0, $zero, 0x2c
/* 3569F8 E0048078 24110001 */  addiu     $s1, $zero, 1
/* 3569FC E004807C 0040802D */  daddu     $s0, $v0, $zero
/* 356A00 E0048080 0C08012C */  jal       shim_general_heap_malloc
/* 356A04 E0048084 AE110008 */   sw       $s1, 8($s0)
/* 356A08 E0048088 AE02000C */  sw        $v0, 0xc($s0)
/* 356A0C E004808C 0040802D */  daddu     $s0, $v0, $zero
/* 356A10 E0048090 16000003 */  bnez      $s0, .LE00480A0
/* 356A14 E0048094 0200202D */   daddu    $a0, $s0, $zero
.LE0048098:
/* 356A18 E0048098 08012026 */  j         .LE0048098
/* 356A1C E004809C 00000000 */   nop
.LE00480A0:
/* 356A20 E00480A0 00112840 */  sll       $a1, $s1, 1
/* 356A24 E00480A4 00B12821 */  addu      $a1, $a1, $s1
/* 356A28 E00480A8 00052880 */  sll       $a1, $a1, 2
/* 356A2C E00480AC 00B12823 */  subu      $a1, $a1, $s1
/* 356A30 E00480B0 0C080130 */  jal       shim_mem_clear
/* 356A34 E00480B4 00052880 */   sll      $a1, $a1, 2
/* 356A38 E00480B8 AE120014 */  sw        $s2, 0x14($s0)
/* 356A3C E00480BC AE000018 */  sw        $zero, 0x18($s0)
/* 356A40 E00480C0 AE12001C */  sw        $s2, 0x1c($s0)
/* 356A44 E00480C4 AE000020 */  sw        $zero, 0x20($s0)
/* 356A48 E00480C8 A6130000 */  sh        $s3, ($s0)
/* 356A4C E00480CC E6140004 */  swc1      $f20, 4($s0)
/* 356A50 E00480D0 E6160008 */  swc1      $f22, 8($s0)
/* 356A54 E00480D4 E618000C */  swc1      $f24, 0xc($s0)
/* 356A58 E00480D8 C7A00068 */  lwc1      $f0, 0x68($sp)
/* 356A5C E00480DC AE000024 */  sw        $zero, 0x24($s0)
/* 356A60 E00480E0 16600003 */  bnez      $s3, .LE00480F0
/* 356A64 E00480E4 E6000010 */   swc1     $f0, 0x10($s0)
/* 356A68 E00480E8 08012040 */  j         .LE0048100
/* 356A6C E00480EC AE000028 */   sw       $zero, 0x28($s0)
.LE00480F0:
/* 356A70 E00480F0 3C014220 */  lui       $at, 0x4220
/* 356A74 E00480F4 44810000 */  mtc1      $at, $f0
/* 356A78 E00480F8 00000000 */  nop
/* 356A7C E00480FC E6000028 */  swc1      $f0, 0x28($s0)
.LE0048100:
/* 356A80 E0048100 8FBF0038 */  lw        $ra, 0x38($sp)
/* 356A84 E0048104 8FB30034 */  lw        $s3, 0x34($sp)
/* 356A88 E0048108 8FB20030 */  lw        $s2, 0x30($sp)
/* 356A8C E004810C 8FB1002C */  lw        $s1, 0x2c($sp)
/* 356A90 E0048110 8FB00028 */  lw        $s0, 0x28($sp)
/* 356A94 E0048114 D7B80050 */  ldc1      $f24, 0x50($sp)
/* 356A98 E0048118 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 356A9C E004811C D7B40040 */  ldc1      $f20, 0x40($sp)
/* 356AA0 E0048120 03E00008 */  jr        $ra
/* 356AA4 E0048124 27BD0058 */   addiu    $sp, $sp, 0x58
