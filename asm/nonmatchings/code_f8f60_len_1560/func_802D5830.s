.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802D5830
/* 0FA1E0 802D5830 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FA1E4 802D5834 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FA1E8 802D5838 8C82000C */  lw    $v0, 0xc($a0)
/* 0FA1EC 802D583C 0C0B1EAF */  jal   get_variable
/* 0FA1F0 802D5840 8C450000 */   lw    $a1, ($v0)
/* 0FA1F4 802D5844 0C009C22 */  jal   func_80027088
/* 0FA1F8 802D5848 0040202D */   daddu $a0, $v0, $zero
/* 0FA1FC 802D584C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FA200 802D5850 24020002 */  addiu $v0, $zero, 2
/* 0FA204 802D5854 03E00008 */  jr    $ra
/* 0FA208 802D5858 27BD0018 */   addiu $sp, $sp, 0x18

