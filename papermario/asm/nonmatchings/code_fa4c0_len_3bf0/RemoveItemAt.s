.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel RemoveItemAt
/* 0FB23C 802D688C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FB240 802D6890 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FB244 802D6894 8C82000C */  lw    $v0, 0xc($a0)
/* 0FB248 802D6898 0C0B1EAF */  jal   get_variable
/* 0FB24C 802D689C 8C450000 */   lw    $a1, ($v0)
/* 0FB250 802D68A0 00021040 */  sll   $v0, $v0, 1
/* 0FB254 802D68A4 3C018011 */  lui   $at, 0x8011
/* 0FB258 802D68A8 00220821 */  addu  $at, $at, $v0
/* 0FB25C 802D68AC A420F444 */  sh    $zero, -0xbbc($at)
/* 0FB260 802D68B0 0C039DB3 */  jal   sort_items
/* 0FB264 802D68B4 00000000 */   nop   
/* 0FB268 802D68B8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FB26C 802D68BC 24020002 */  addiu $v0, $zero, 2
/* 0FB270 802D68C0 03E00008 */  jr    $ra
/* 0FB274 802D68C4 27BD0018 */   addiu $sp, $sp, 0x18

