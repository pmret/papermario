.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80247020
/* 13A360 80247020 00031400 */  sll   $v0, $v1, 0x10
/* 13A364 80247024 00021C03 */  sra   $v1, $v0, 0x10
/* 13A368 80247028 00041400 */  sll   $v0, $a0, 0x10
/* 13A36C 8024702C 00022403 */  sra   $a0, $v0, 0x10
/* 13A370 80247030 10640005 */  beq   $v1, $a0, .L80247048
/* 13A374 80247034 0064182A */   slt   $v1, $v1, $a0
/* 13A378 80247038 14600004 */  bnez  $v1, .L8024704C
/* 13A37C 8024703C 2402FFFF */   addiu $v0, $zero, -1
/* 13A380 80247040 03E00008 */  jr    $ra
/* 13A384 80247044 24020001 */   addiu $v0, $zero, 1

.L80247048:
/* 13A388 80247048 0000102D */  daddu $v0, $zero, $zero
.L8024704C:
/* 13A38C 8024704C 03E00008 */  jr    $ra
/* 13A390 80247050 00000000 */   nop   

