.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel ShowCoinCounter
/* 082BA8 800E96F8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 082BAC 800E96FC AFBF0010 */  sw    $ra, 0x10($sp)
/* 082BB0 800E9700 8C82000C */  lw    $v0, 0xc($a0)
/* 082BB4 800E9704 0C0B1EAF */  jal   get_variable
/* 082BB8 800E9708 8C450000 */   lw    $a1, ($v0)
/* 082BBC 800E970C 10400005 */  beqz  $v0, .L800E9724
/* 082BC0 800E9710 00000000 */   nop   
/* 082BC4 800E9714 0C03A546 */  jal   show_coin_counter
/* 082BC8 800E9718 00000000 */   nop   
/* 082BCC 800E971C 0803A5CB */  j     .L800E972C
/* 082BD0 800E9720 00000000 */   nop   

.L800E9724:
/* 082BD4 800E9724 0C03A5A6 */  jal   hide_coin_counter
/* 082BD8 800E9728 00000000 */   nop   
.L800E972C:
/* 082BDC 800E972C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 082BE0 800E9730 24020002 */  addiu $v0, $zero, 2
/* 082BE4 800E9734 03E00008 */  jr    $ra
/* 082BE8 800E9738 27BD0018 */   addiu $sp, $sp, 0x18

