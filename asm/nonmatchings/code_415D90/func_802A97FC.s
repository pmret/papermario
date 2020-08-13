.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802A97FC
/* 41E58C 802A97FC 0240202D */  daddu $a0, $s2, $zero
.L802A9800:
/* 41E590 802A9800 8D050000 */  lw    $a1, ($t0)
/* 41E594 802A9804 000510C0 */  sll   $v0, $a1, 3
/* 41E598 802A9808 02E23021 */  addu  $a2, $s7, $v0
/* 41E59C 802A980C 90C20014 */  lbu   $v0, 0x14($a2)
