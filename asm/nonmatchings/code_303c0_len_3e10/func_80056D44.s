.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80056D44
/* 032144 80056D44 3C018008 */  lui   $at, 0x8008
/* 032148 80056D48 03E00008 */  jr    $ra
/* 03214C 80056D4C A4248E5A */   sh    $a0, -0x71a6($at)

