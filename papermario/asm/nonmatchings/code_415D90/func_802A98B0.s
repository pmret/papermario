.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802A98B0
/* 41E640 802A98B0 0240202D */  daddu $a0, $s2, $zero
/* 41E644 802A98B4 AC80031C */  sw    $zero, 0x31c($a0)
/* 41E648 802A98B8 AC800320 */  sw    $zero, 0x320($a0)
/* 41E64C 802A98BC 2442FFFF */  addiu $v0, $v0, -1
/* 41E650 802A98C0 0C03D44F */  jal   func_800F513C
/* 41E654 802A98C4 AC820328 */   sw    $v0, 0x328($a0)
/* 41E658 802A98C8 0C03D4AF */  jal   func_800F52BC
/* 41E65C 802A98CC 00000000 */   nop   
