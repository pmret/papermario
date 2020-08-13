.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802DDEC4
/* 100FB4 802DDEC4 00041040 */  sll   $v0, $a0, 1
/* 100FB8 802DDEC8 00441021 */  addu  $v0, $v0, $a0
/* 100FBC 802DDECC 00021080 */  sll   $v0, $v0, 2
/* 100FC0 802DDED0 3C01802E */  lui   $at, 0x802e
/* 100FC4 802DDED4 00220821 */  addu  $at, $at, $v0
/* 100FC8 802DDED8 8C22F590 */  lw    $v0, -0xa70($at)
/* 100FCC 802DDEDC 03E00008 */  jr    $ra
/* 100FD0 802DDEE0 00000000 */   nop   

