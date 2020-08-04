.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800EA5B8
/* 083A68 800EA5B8 3C03FDFF */  lui   $v1, 0xfdff
/* 083A6C 800EA5BC 8C820000 */  lw    $v0, ($a0)
/* 083A70 800EA5C0 346387FF */  ori   $v1, $v1, 0x87ff
/* 083A74 800EA5C4 00431024 */  and   $v0, $v0, $v1
/* 083A78 800EA5C8 03E00008 */  jr    $ra
/* 083A7C 800EA5CC AC820000 */   sw    $v0, ($a0)

