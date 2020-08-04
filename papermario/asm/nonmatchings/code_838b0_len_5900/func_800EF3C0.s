.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800EF3C0
/* 088870 800EF3C0 3C018010 */  lui   $at, 0x8010
/* 088874 800EF3C4 AC248024 */  sw    $a0, -0x7fdc($at)
/* 088878 800EF3C8 3C018010 */  lui   $at, 0x8010
/* 08887C 800EF3CC 03E00008 */  jr    $ra
/* 088880 800EF3D0 AC258028 */   sw    $a1, -0x7fd8($at)

