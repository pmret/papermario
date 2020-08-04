.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8005083C
/* 02BC3C 8005083C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 02BC40 80050840 00051040 */  sll   $v0, $a1, 1
/* 02BC44 80050844 00451021 */  addu  $v0, $v0, $a1
/* 02BC48 80050848 00021140 */  sll   $v0, $v0, 5
/* 02BC4C 8005084C 2442025C */  addiu $v0, $v0, 0x25c
/* 02BC50 80050850 00822821 */  addu  $a1, $a0, $v0
/* 02BC54 80050854 AFBF0010 */  sw    $ra, 0x10($sp)
/* 02BC58 80050858 8CA20000 */  lw    $v0, ($a1)
/* 02BC5C 8005085C 10400004 */  beqz  $v0, .L80050870
/* 02BC60 80050860 00000000 */   nop   
/* 02BC64 80050864 A48600D4 */  sh    $a2, 0xd4($a0)
/* 02BC68 80050868 0C013FB4 */  jal   func_8004FED0
/* 02BC6C 8005086C A08700D6 */   sb    $a3, 0xd6($a0)
.L80050870:
/* 02BC70 80050870 8FBF0010 */  lw    $ra, 0x10($sp)
/* 02BC74 80050874 03E00008 */  jr    $ra
/* 02BC78 80050878 27BD0018 */   addiu $sp, $sp, 0x18

