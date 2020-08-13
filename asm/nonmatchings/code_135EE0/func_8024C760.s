.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024C760
/* 13FAA0 8024C760 00621821 */  addu  $v1, $v1, $v0
/* 13FAA4 8024C764 8C63F6F0 */  lw    $v1, -0x910($v1)
/* 13FAA8 8024C768 24820002 */  addiu $v0, $a0, 2
/* 13FAAC 8024C76C 00621821 */  addu  $v1, $v1, $v0
/* 13FAB0 8024C770 00031080 */  sll   $v0, $v1, 2
