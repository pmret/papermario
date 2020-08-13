.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8024411C
/* 13745C 8024411C 0000882D */   daddu $s1, $zero, $zero
/* 137460 80244120 3C018027 */  lui   $at, 0x8027
/* 137464 80244124 AC200108 */  sw    $zero, 0x108($at)
/* 137468 80244128 3C018027 */  lui   $at, 0x8027
