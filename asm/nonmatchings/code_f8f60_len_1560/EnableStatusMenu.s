.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel EnableStatusMenu
/* 0FA348 802D5998 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FA34C 802D599C AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FA350 802D59A0 8C82000C */  lw    $v0, 0xc($a0)
/* 0FA354 802D59A4 0C0B1EAF */  jal   get_variable
/* 0FA358 802D59A8 8C450000 */   lw    $a1, ($v0)
/* 0FA35C 802D59AC 10400005 */  beqz  $v0, .L802D59C4
/* 0FA360 802D59B0 00000000 */   nop   
/* 0FA364 802D59B4 0C03A6CC */  jal   decrement_status_menu_disabled
/* 0FA368 802D59B8 00000000 */   nop   
/* 0FA36C 802D59BC 080B5673 */  j     .L802D59CC
/* 0FA370 802D59C0 00000000 */   nop   

.L802D59C4:
/* 0FA374 802D59C4 0C03A6D5 */  jal   increment_status_menu_disabled
/* 0FA378 802D59C8 00000000 */   nop   
.L802D59CC:
/* 0FA37C 802D59CC 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FA380 802D59D0 24020002 */  addiu $v0, $zero, 2
/* 0FA384 802D59D4 03E00008 */  jr    $ra
/* 0FA388 802D59D8 27BD0018 */   addiu $sp, $sp, 0x18

