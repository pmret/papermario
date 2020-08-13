.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel FullyRestoreSP
/* 0F6890 802D1EE0 3C038011 */  lui   $v1, 0x8011
/* 0F6894 802D1EE4 2463F290 */  addiu $v1, $v1, -0xd70
/* 0F6898 802D1EE8 8062028E */  lb    $v0, 0x28e($v1)
/* 0F689C 802D1EEC 00021200 */  sll   $v0, $v0, 8
/* 0F68A0 802D1EF0 A4620290 */  sh    $v0, 0x290($v1)
/* 0F68A4 802D1EF4 03E00008 */  jr    $ra
/* 0F68A8 802D1EF8 24020002 */   addiu $v0, $zero, 2

