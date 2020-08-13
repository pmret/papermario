.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80247F98
/* 13B2D8 80247F98 00431025 */  or    $v0, $v0, $v1
/* 13B2DC 80247F9C 34420080 */  ori   $v0, $v0, 0x80
/* 13B2E0 80247FA0 AC860000 */  sw    $a2, ($a0)
