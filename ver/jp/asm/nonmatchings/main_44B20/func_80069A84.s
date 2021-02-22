.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80069A84
/* 44E84 80069A84 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 44E88 80069A88 AFB40038 */  sw        $s4, 0x38($sp)
/* 44E8C 80069A8C 0080A021 */  addu      $s4, $a0, $zero
/* 44E90 80069A90 AFBF0040 */  sw        $ra, 0x40($sp)
/* 44E94 80069A94 AFB5003C */  sw        $s5, 0x3c($sp)
/* 44E98 80069A98 AFB30034 */  sw        $s3, 0x34($sp)
/* 44E9C 80069A9C AFB20030 */  sw        $s2, 0x30($sp)
/* 44EA0 80069AA0 AFB1002C */  sw        $s1, 0x2c($sp)
/* 44EA4 80069AA4 AFB00028 */  sw        $s0, 0x28($sp)
/* 44EA8 80069AA8 92820065 */  lbu       $v0, 0x65($s4)
/* 44EAC 80069AAC 10400005 */  beqz      $v0, .L80069AC4
/* 44EB0 80069AB0 00A09021 */   addu     $s2, $a1, $zero
/* 44EB4 80069AB4 0C01A5AC */  jal       func_800696B0
/* 44EB8 80069AB8 00002821 */   addu     $a1, $zero, $zero
/* 44EBC 80069ABC 14400041 */  bnez      $v0, .L80069BC4
/* 44EC0 80069AC0 00000000 */   nop
.L80069AC4:
/* 44EC4 80069AC4 24130001 */  addiu     $s3, $zero, 1
/* 44EC8 80069AC8 27B0001A */  addiu     $s0, $sp, 0x1a
/* 44ECC 80069ACC 24020001 */  addiu     $v0, $zero, 1
/* 44ED0 80069AD0 A7A20018 */  sh        $v0, 0x18($sp)
/* 44ED4 80069AD4 24020003 */  addiu     $v0, $zero, 3
/* 44ED8 80069AD8 A7A2001A */  sh        $v0, 0x1a($sp)
/* 44EDC 80069ADC 24020004 */  addiu     $v0, $zero, 4
/* 44EE0 80069AE0 A7A2001C */  sh        $v0, 0x1c($sp)
/* 44EE4 80069AE4 24020006 */  addiu     $v0, $zero, 6
/* 44EE8 80069AE8 A7A2001E */  sh        $v0, 0x1e($sp)
.L80069AEC:
/* 44EEC 80069AEC 8E840004 */  lw        $a0, 4($s4)
/* 44EF0 80069AF0 8E850008 */  lw        $a1, 8($s4)
/* 44EF4 80069AF4 96060000 */  lhu       $a2, ($s0)
/* 44EF8 80069AF8 0C01A86C */  jal       func_8006A1B0
/* 44EFC 80069AFC 02403821 */   addu     $a3, $s2, $zero
/* 44F00 80069B00 14400030 */  bnez      $v0, .L80069BC4
/* 44F04 80069B04 02402821 */   addu     $a1, $s2, $zero
/* 44F08 80069B08 2647001C */  addiu     $a3, $s2, 0x1c
/* 44F0C 80069B0C A7A00022 */  sh        $zero, 0x22($sp)
/* 44F10 80069B10 A7A00020 */  sh        $zero, 0x20($sp)
.L80069B14:
/* 44F14 80069B14 94A20000 */  lhu       $v0, ($a1)
/* 44F18 80069B18 97A30020 */  lhu       $v1, 0x20($sp)
/* 44F1C 80069B1C 97A40022 */  lhu       $a0, 0x22($sp)
/* 44F20 80069B20 24A50002 */  addiu     $a1, $a1, 2
/* 44F24 80069B24 00623021 */  addu      $a2, $v1, $v0
/* 44F28 80069B28 00021027 */  nor       $v0, $zero, $v0
/* 44F2C 80069B2C 00822021 */  addu      $a0, $a0, $v0
/* 44F30 80069B30 00A7102B */  sltu      $v0, $a1, $a3
/* 44F34 80069B34 A7A60020 */  sh        $a2, 0x20($sp)
/* 44F38 80069B38 1440FFF6 */  bnez      $v0, .L80069B14
/* 44F3C 80069B3C A7A40022 */   sh       $a0, 0x22($sp)
/* 44F40 80069B40 9643001C */  lhu       $v1, 0x1c($s2)
/* 44F44 80069B44 30C2FFFF */  andi      $v0, $a2, 0xffff
/* 44F48 80069B48 54620006 */  bnel      $v1, $v0, .L80069B64
/* 44F4C 80069B4C 26730001 */   addiu    $s3, $s3, 1
/* 44F50 80069B50 9643001E */  lhu       $v1, 0x1e($s2)
/* 44F54 80069B54 3082FFFF */  andi      $v0, $a0, 0xffff
/* 44F58 80069B58 10620006 */  beq       $v1, $v0, .L80069B74
/* 44F5C 80069B5C 24020004 */   addiu    $v0, $zero, 4
/* 44F60 80069B60 26730001 */  addiu     $s3, $s3, 1
.L80069B64:
/* 44F64 80069B64 2A620004 */  slti      $v0, $s3, 4
/* 44F68 80069B68 1440FFE0 */  bnez      $v0, .L80069AEC
/* 44F6C 80069B6C 26100002 */   addiu    $s0, $s0, 2
/* 44F70 80069B70 24020004 */  addiu     $v0, $zero, 4
.L80069B74:
/* 44F74 80069B74 16620003 */  bne       $s3, $v0, .L80069B84
/* 44F78 80069B78 00008021 */   addu     $s0, $zero, $zero
/* 44F7C 80069B7C 0801A6F1 */  j         .L80069BC4
/* 44F80 80069B80 2402000A */   addiu    $v0, $zero, 0xa
.L80069B84:
/* 44F84 80069B84 24150001 */  addiu     $s5, $zero, 1
/* 44F88 80069B88 27B10018 */  addiu     $s1, $sp, 0x18
.L80069B8C:
/* 44F8C 80069B8C 52130009 */  beql      $s0, $s3, .L80069BB4
/* 44F90 80069B90 26100001 */   addiu    $s0, $s0, 1
/* 44F94 80069B94 96260000 */  lhu       $a2, ($s1)
/* 44F98 80069B98 AFB50010 */  sw        $s5, 0x10($sp)
/* 44F9C 80069B9C 8E840004 */  lw        $a0, 4($s4)
/* 44FA0 80069BA0 8E850008 */  lw        $a1, 8($s4)
/* 44FA4 80069BA4 0C01A8E8 */  jal       func_8006A3A0
/* 44FA8 80069BA8 02403821 */   addu     $a3, $s2, $zero
/* 44FAC 80069BAC 14400005 */  bnez      $v0, .L80069BC4
/* 44FB0 80069BB0 26100001 */   addiu    $s0, $s0, 1
.L80069BB4:
/* 44FB4 80069BB4 2A020004 */  slti      $v0, $s0, 4
/* 44FB8 80069BB8 1440FFF4 */  bnez      $v0, .L80069B8C
/* 44FBC 80069BBC 26310002 */   addiu    $s1, $s1, 2
/* 44FC0 80069BC0 00001021 */  addu      $v0, $zero, $zero
.L80069BC4:
/* 44FC4 80069BC4 8FBF0040 */  lw        $ra, 0x40($sp)
/* 44FC8 80069BC8 8FB5003C */  lw        $s5, 0x3c($sp)
/* 44FCC 80069BCC 8FB40038 */  lw        $s4, 0x38($sp)
/* 44FD0 80069BD0 8FB30034 */  lw        $s3, 0x34($sp)
/* 44FD4 80069BD4 8FB20030 */  lw        $s2, 0x30($sp)
/* 44FD8 80069BD8 8FB1002C */  lw        $s1, 0x2c($sp)
/* 44FDC 80069BDC 8FB00028 */  lw        $s0, 0x28($sp)
/* 44FE0 80069BE0 03E00008 */  jr        $ra
/* 44FE4 80069BE4 27BD0048 */   addiu    $sp, $sp, 0x48
