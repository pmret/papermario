.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802A981C
/* 41E5AC 802A981C 00053880 */  sll   $a3, $a1, 2
/* 41E5B0 802A9820 00EB1021 */  addu  $v0, $a3, $t3
/* 41E5B4 802A9824 8C420000 */  lw    $v0, ($v0)
/* 41E5B8 802A9828 006C1821 */  addu  $v1, $v1, $t4
/* 41E5BC 802A982C AC850108 */  sw    $a1, 0x108($a0)
/* 41E5C0 802A9830 AC8A018C */  sw    $t2, 0x18c($a0)
