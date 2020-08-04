.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel ShowStatusMenu
/* 0FA38C 802D59DC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FA390 802D59E0 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FA394 802D59E4 8C82000C */  lw    $v0, 0xc($a0)
/* 0FA398 802D59E8 0C0B1EAF */  jal   get_variable
/* 0FA39C 802D59EC 8C450000 */   lw    $a1, ($v0)
/* 0FA3A0 802D59F0 10400007 */  beqz  $v0, .L802D5A10
/* 0FA3A4 802D59F4 00000000 */   nop   
/* 0FA3A8 802D59F8 0C03A625 */  jal   func_800E9894
/* 0FA3AC 802D59FC 00000000 */   nop   
/* 0FA3B0 802D5A00 0C03A5EE */  jal   func_800E97B8
/* 0FA3B4 802D5A04 00000000 */   nop   
/* 0FA3B8 802D5A08 080B5686 */  j     .L802D5A18
/* 0FA3BC 802D5A0C 00000000 */   nop   

.L802D5A10:
/* 0FA3C0 802D5A10 0C03A631 */  jal   func_800E98C4
/* 0FA3C4 802D5A14 00000000 */   nop   
.L802D5A18:
/* 0FA3C8 802D5A18 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FA3CC 802D5A1C 24020002 */  addiu $v0, $zero, 2
/* 0FA3D0 802D5A20 03E00008 */  jr    $ra
/* 0FA3D4 802D5A24 27BD0018 */   addiu $sp, $sp, 0x18

