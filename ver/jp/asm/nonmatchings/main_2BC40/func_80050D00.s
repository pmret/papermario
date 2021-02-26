.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050D00
/* 2C100 80050D00 00041100 */  sll       $v0, $a0, 4
/* 2C104 80050D04 00441023 */  subu      $v0, $v0, $a0
/* 2C108 80050D08 000210C0 */  sll       $v0, $v0, 3
/* 2C10C 80050D0C 00441021 */  addu      $v0, $v0, $a0
/* 2C110 80050D10 00021080 */  sll       $v0, $v0, 2
/* 2C114 80050D14 3C03800A */  lui       $v1, %hi(D_8009A608)
/* 2C118 80050D18 8C63A608 */  lw        $v1, %lo(D_8009A608)($v1)
/* 2C11C 80050D1C 24420024 */  addiu     $v0, $v0, 0x24
/* 2C120 80050D20 00621821 */  addu      $v1, $v1, $v0
/* 2C124 80050D24 8C620004 */  lw        $v0, 4($v1)
/* 2C128 80050D28 10400008 */  beqz      $v0, .L80050D4C
/* 2C12C 80050D2C 0000202D */   daddu    $a0, $zero, $zero
/* 2C130 80050D30 8C620008 */  lw        $v0, 8($v1)
/* 2C134 80050D34 10400005 */  beqz      $v0, .L80050D4C
/* 2C138 80050D38 00000000 */   nop
/* 2C13C 80050D3C 90620024 */  lbu       $v0, 0x24($v1)
/* 2C140 80050D40 10400002 */  beqz      $v0, .L80050D4C
/* 2C144 80050D44 24040001 */   addiu    $a0, $zero, 1
/* 2C148 80050D48 24040002 */  addiu     $a0, $zero, 2
.L80050D4C:
/* 2C14C 80050D4C 03E00008 */  jr        $ra
/* 2C150 80050D50 0080102D */   daddu    $v0, $a0, $zero
