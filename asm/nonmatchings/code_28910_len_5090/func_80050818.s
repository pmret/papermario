.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80050818
/* 02BC18 80050818 28A204B1 */  slti  $v0, $a1, 0x4b1
/* 02BC1C 8005081C 14400003 */  bnez  $v0, .L8005082C
/* 02BC20 80050820 28A2F6A0 */   slti  $v0, $a1, -0x960
/* 02BC24 80050824 0801420D */  j     .L80050834
/* 02BC28 80050828 240504B0 */   addiu $a1, $zero, 0x4b0

.L8005082C:
/* 02BC2C 8005082C 54400001 */  bnel  $v0, $zero, .L80050834
/* 02BC30 80050830 2405F6A0 */   addiu $a1, $zero, -0x960
.L80050834:
/* 02BC34 80050834 03E00008 */  jr    $ra
/* 02BC38 80050838 A485020E */   sh    $a1, 0x20e($a0)

