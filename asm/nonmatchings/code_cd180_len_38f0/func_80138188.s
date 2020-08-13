.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80138188
/* 0CE888 80138188 3C018015 */  lui   $at, 0x8015
/* 0CE88C 8013818C AC20690C */  sw    $zero, 0x690c($at)
/* 0CE890 80138190 03E00008 */  jr    $ra
/* 0CE894 80138194 00000000 */   nop   

