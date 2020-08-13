.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel DisablePlayerPhysics
/* 0F5794 802D0DE4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F5798 802D0DE8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F579C 802D0DEC 8C82000C */  lw    $v0, 0xc($a0)
/* 0F57A0 802D0DF0 0C0B1EAF */  jal   get_variable
/* 0F57A4 802D0DF4 8C450000 */   lw    $a1, ($v0)
/* 0F57A8 802D0DF8 10400005 */  beqz  $v0, .L802D0E10
/* 0F57AC 802D0DFC 00000000 */   nop   
/* 0F57B0 802D0E00 0C038045 */  jal   enable_player_physics
/* 0F57B4 802D0E04 00000000 */   nop   
/* 0F57B8 802D0E08 080B4386 */  j     .L802D0E18
/* 0F57BC 802D0E0C 00000000 */   nop   

.L802D0E10:
/* 0F57C0 802D0E10 0C038050 */  jal   disable_player_physics
/* 0F57C4 802D0E14 00000000 */   nop   
.L802D0E18:
/* 0F57C8 802D0E18 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F57CC 802D0E1C 24020002 */  addiu $v0, $zero, 2
/* 0F57D0 802D0E20 03E00008 */  jr    $ra
/* 0F57D4 802D0E24 27BD0018 */   addiu $sp, $sp, 0x18

