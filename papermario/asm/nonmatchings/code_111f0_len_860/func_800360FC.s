.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800360FC
/* 0114FC 800360FC 3C028007 */  lui   $v0, 0x8007
/* 011500 80036100 8C42419C */  lw    $v0, 0x419c($v0)
/* 011504 80036104 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 011508 80036108 AFBF0010 */  sw    $ra, 0x10($sp)
/* 01150C 8003610C 804300AC */  lb    $v1, 0xac($v0)
/* 011510 80036110 24020002 */  addiu $v0, $zero, 2
/* 011514 80036114 14620003 */  bne   $v1, $v0, .L80036124
/* 011518 80036118 00000000 */   nop   
/* 01151C 8003611C 0C03A5CF */  jal   func_800E973C
/* 011520 80036120 00000000 */   nop   
.L80036124:
/* 011524 80036124 8FBF0010 */  lw    $ra, 0x10($sp)
/* 011528 80036128 03E00008 */  jr    $ra
/* 01152C 8003612C 27BD0018 */   addiu $sp, $sp, 0x18

