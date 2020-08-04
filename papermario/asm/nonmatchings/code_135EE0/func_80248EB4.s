.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80248EB4
/* 13C1F4 80248EB4 3C018027 */  lui   $at, 0x8027
/* 13C1F8 80248EB8 AC200378 */  sw    $zero, 0x378($at)
/* 13C1FC 80248EBC 3C018027 */  lui   $at, 0x8027
/* 13C200 80248EC0 AC200380 */  sw    $zero, 0x380($at)
/* 13C204 80248EC4 3C018027 */  lui   $at, 0x8027
/* 13C208 80248EC8 AC20037C */  sw    $zero, 0x37c($at)
/* 13C20C 80248ECC 3C018027 */  lui   $at, 0x8027
/* 13C210 80248ED0 AC200394 */  sw    $zero, 0x394($at)
/* 13C214 80248ED4 3C018027 */  lui   $at, 0x8027
/* 13C218 80248ED8 AC200280 */  sw    $zero, 0x280($at)
