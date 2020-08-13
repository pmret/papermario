.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80028FE0
/* 0043E0 80028FE0 2402012C */  addiu $v0, $zero, 0x12c
/* 0043E4 80028FE4 3C018007 */  lui   $at, 0x8007
/* 0043E8 80028FE8 03E00008 */  jr    $ra
/* 0043EC 80028FEC A4224260 */   sh    $v0, 0x4260($at)

