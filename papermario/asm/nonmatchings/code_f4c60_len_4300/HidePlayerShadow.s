.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel HidePlayerShadow
/* 0F5750 802D0DA0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F5754 802D0DA4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F5758 802D0DA8 8C82000C */  lw    $v0, 0xc($a0)
/* 0F575C 802D0DAC 0C0B1EAF */  jal   get_variable
/* 0F5760 802D0DB0 8C450000 */   lw    $a1, ($v0)
/* 0F5764 802D0DB4 10400005 */  beqz  $v0, .L802D0DCC
/* 0F5768 802D0DB8 00000000 */   nop   
/* 0F576C 802D0DBC 0C038039 */  jal   disable_player_shadow
/* 0F5770 802D0DC0 00000000 */   nop   
/* 0F5774 802D0DC4 080B4375 */  j     .L802D0DD4
/* 0F5778 802D0DC8 00000000 */   nop   

.L802D0DCC:
/* 0F577C 802D0DCC 0C03802C */  jal   enable_player_shadow
/* 0F5780 802D0DD0 00000000 */   nop   
.L802D0DD4:
/* 0F5784 802D0DD4 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F5788 802D0DD8 24020002 */  addiu $v0, $zero, 2
/* 0F578C 802D0DDC 03E00008 */  jr    $ra
/* 0F5790 802D0DE0 27BD0018 */   addiu $sp, $sp, 0x18

