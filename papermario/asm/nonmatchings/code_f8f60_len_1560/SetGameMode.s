.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetGameMode
/* 0FA3D8 802D5A28 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FA3DC 802D5A2C AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FA3E0 802D5A30 8C82000C */  lw    $v0, 0xc($a0)
/* 0FA3E4 802D5A34 0C0B1EAF */  jal   get_variable
/* 0FA3E8 802D5A38 8C450000 */   lw    $a1, ($v0)
/* 0FA3EC 802D5A3C 00021400 */  sll   $v0, $v0, 0x10
/* 0FA3F0 802D5A40 0C00CD3C */  jal   set_game_mode
/* 0FA3F4 802D5A44 00022403 */   sra   $a0, $v0, 0x10
/* 0FA3F8 802D5A48 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FA3FC 802D5A4C 24020002 */  addiu $v0, $zero, 2
/* 0FA400 802D5A50 03E00008 */  jr    $ra
/* 0FA404 802D5A54 27BD0018 */   addiu $sp, $sp, 0x18

