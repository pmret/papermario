.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004F9E8
/* 2ADE8 8004F9E8 908200D4 */  lbu       $v0, 0xd4($a0)
/* 2ADEC 8004F9EC 00823821 */  addu      $a3, $a0, $v0
/* 2ADF0 8004F9F0 2C420004 */  sltiu     $v0, $v0, 4
/* 2ADF4 8004F9F4 90E3004C */  lbu       $v1, 0x4c($a3)
/* 2ADF8 8004F9F8 10400010 */  beqz      $v0, .L8004FA3C
/* 2ADFC 8004F9FC 2C620080 */   sltiu    $v0, $v1, 0x80
/* 2AE00 8004FA00 1040000E */  beqz      $v0, .L8004FA3C
/* 2AE04 8004FA04 00033080 */   sll      $a2, $v1, 2
/* 2AE08 8004FA08 8C820000 */  lw        $v0, ($a0)
/* 2AE0C 8004FA0C 908300D5 */  lbu       $v1, 0xd5($a0)
/* 2AE10 8004FA10 00462821 */  addu      $a1, $v0, $a2
/* 2AE14 8004FA14 90A20040 */  lbu       $v0, 0x40($a1)
/* 2AE18 8004FA18 10430006 */  beq       $v0, $v1, .L8004FA34
/* 2AE1C 8004FA1C 00000000 */   nop
/* 2AE20 8004FA20 A0A30040 */  sb        $v1, 0x40($a1)
/* 2AE24 8004FA24 8C820000 */  lw        $v0, ($a0)
/* 2AE28 8004FA28 24030001 */  addiu     $v1, $zero, 1
/* 2AE2C 8004FA2C 00461021 */  addu      $v0, $v0, $a2
/* 2AE30 8004FA30 A0430041 */  sb        $v1, 0x41($v0)
.L8004FA34:
/* 2AE34 8004FA34 908200D5 */  lbu       $v0, 0xd5($a0)
/* 2AE38 8004FA38 A0E20224 */  sb        $v0, 0x224($a3)
.L8004FA3C:
/* 2AE3C 8004FA3C 03E00008 */  jr        $ra
/* 2AE40 8004FA40 00000000 */   nop
