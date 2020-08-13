.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80056D5C
/* 03215C 80056D5C 3C028008 */  lui   $v0, 0x8008
/* 032160 80056D60 24428181 */  addiu $v0, $v0, -0x7e7f
/* 032164 80056D64 A0440000 */  sb    $a0, ($v0)
/* 032168 80056D68 24020001 */  addiu $v0, $zero, 1
/* 03216C 80056D6C 3C018008 */  lui   $at, 0x8008
/* 032170 80056D70 03E00008 */  jr    $ra
/* 032174 80056D74 A0228E5C */   sb    $v0, -0x71a4($at)

