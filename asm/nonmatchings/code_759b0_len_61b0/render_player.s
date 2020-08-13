.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel render_player
/* 07A5E8 800E1138 3C028007 */  lui   $v0, 0x8007
/* 07A5EC 800E113C 8C42419C */  lw    $v0, 0x419c($v0)
/* 07A5F0 800E1140 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 07A5F4 800E1144 AFBF0010 */  sw    $ra, 0x10($sp)
/* 07A5F8 800E1148 80420078 */  lb    $v0, 0x78($v0)
/* 07A5FC 800E114C 14400003 */  bnez  $v0, .L800E115C
/* 07A600 800E1150 00000000 */   nop   
/* 07A604 800E1154 0C03845A */  jal   render_player_model
/* 07A608 800E1158 00000000 */   nop   
.L800E115C:
/* 07A60C 800E115C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 07A610 800E1160 03E00008 */  jr    $ra
/* 07A614 800E1164 27BD0018 */   addiu $sp, $sp, 0x18

