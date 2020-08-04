.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_801473F0
/* 0DDAF0 801473F0 3C038016 */  lui   $v1, 0x8016
/* 0DDAF4 801473F4 24639D50 */  addiu $v1, $v1, -0x62b0
/* 0DDAF8 801473F8 2402003F */  addiu $v0, $zero, 0x3f
.L801473FC:
/* 0DDAFC 801473FC A0600000 */  sb    $zero, ($v1)
/* 0DDB00 80147400 2442FFFF */  addiu $v0, $v0, -1
/* 0DDB04 80147404 0441FFFD */  bgez  $v0, .L801473FC
/* 0DDB08 80147408 24630020 */   addiu $v1, $v1, 0x20
/* 0DDB0C 8014740C 03E00008 */  jr    $ra
/* 0DDB10 80147410 00000000 */   nop   

