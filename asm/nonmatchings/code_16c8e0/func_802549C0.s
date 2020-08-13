.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802549C0
/* 1832A0 802549C0 3C05EFFF */  lui   $a1, 0xefff
/* 1832A4 802549C4 3C03800E */  lui   $v1, 0x800e
/* 1832A8 802549C8 8C63C148 */  lw    $v1, -0x3eb8($v1)
/* 1832AC 802549CC 34A5FFFF */  ori   $a1, $a1, 0xffff
/* 1832B0 802549D0 8C6401F4 */  lw    $a0, 0x1f4($v1)
/* 1832B4 802549D4 8C620000 */  lw    $v0, ($v1)
/* 1832B8 802549D8 8C8400C0 */  lw    $a0, 0xc0($a0)
/* 1832BC 802549DC 00451024 */  and   $v0, $v0, $a1
/* 1832C0 802549E0 AC620000 */  sw    $v0, ($v1)
/* 1832C4 802549E4 24020001 */  addiu $v0, $zero, 1
/* 1832C8 802549E8 A08007DB */  sb    $zero, 0x7db($a0)
/* 1832CC 802549EC 03E00008 */  jr    $ra
/* 1832D0 802549F0 A08208AC */   sb    $v0, 0x8ac($a0)

