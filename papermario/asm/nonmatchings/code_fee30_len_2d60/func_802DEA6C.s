.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802DEA6C
/* 101B5C 802DEA6C 00042080 */  sll   $a0, $a0, 2
/* 101B60 802DEA70 3C02802E */  lui   $v0, 0x802e
/* 101B64 802DEA74 00441021 */  addu  $v0, $v0, $a0
/* 101B68 802DEA78 8C42F5B0 */  lw    $v0, -0xa50($v0)
/* 101B6C 802DEA7C 14400003 */  bnez  $v0, .L802DEA8C
/* 101B70 802DEA80 00000000 */   nop   
/* 101B74 802DEA84 03E00008 */  jr    $ra
/* 101B78 802DEA88 2402FFFF */   addiu $v0, $zero, -1

.L802DEA8C:
/* 101B7C 802DEA8C 8C42000C */  lw    $v0, 0xc($v0)
/* 101B80 802DEA90 03E00008 */  jr    $ra
/* 101B84 802DEA94 00000000 */   nop   

/* 101B88 802DEA98 00000000 */  nop   
/* 101B8C 802DEA9C 00000000 */  nop   

.set reorder
