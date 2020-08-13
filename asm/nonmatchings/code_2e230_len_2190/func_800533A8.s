.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_800533A8
/* 02E7A8 800533A8 24022010 */  addiu $v0, $zero, 0x2010
/* 02E7AC 800533AC A4820000 */  sh    $v0, ($a0)
/* 02E7B0 800533B0 2402007F */  addiu $v0, $zero, 0x7f
/* 02E7B4 800533B4 A0820002 */  sb    $v0, 2($a0)
/* 02E7B8 800533B8 24020040 */  addiu $v0, $zero, 0x40
/* 02E7BC 800533BC A0820003 */  sb    $v0, 3($a0)
/* 02E7C0 800533C0 A0800004 */  sb    $zero, 4($a0)
/* 02E7C4 800533C4 A0800005 */  sb    $zero, 5($a0)
/* 02E7C8 800533C8 03E00008 */  jr    $ra
/* 02E7CC 800533CC A0800006 */   sb    $zero, 6($a0)

