.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802A9834
/* 41E5C4 802A9834 AC820000 */  sw    $v0, ($a0)
/* 41E5C8 802A9838 8C620000 */  lw    $v0, ($v1)
/* 41E5CC 802A983C AC820084 */  sw    $v0, 0x84($a0)
/* 41E5D0 802A9840 8C62000C */  lw    $v0, 0xc($v1)
/* 41E5D4 802A9844 AC820294 */  sw    $v0, 0x294($a0)
/* 41E5D8 802A9848 80C20015 */  lb    $v0, 0x15($a2)
