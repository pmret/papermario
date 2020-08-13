.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80243B00
/* 136E40 80243B00 3C05438C */  lui   $a1, 0x438c
/* 136E44 80243B04 3C06435F */  lui   $a2, 0x435f
/* 136E48 80243B08 0C019E40 */  jal   guTranslateF
/* 136E4C 80243B0C 0000382D */   daddu $a3, $zero, $zero
/* 136E50 80243B10 4405D000 */  mfc1  $a1, $f26
