.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80053370
/* 02E770 80053370 24022010 */  addiu $v0, $zero, 0x2010
/* 02E774 80053374 A4820000 */  sh    $v0, ($a0)
/* 02E778 80053378 240212C0 */  addiu $v0, $zero, 0x12c0
/* 02E77C 8005337C A4820002 */  sh    $v0, 2($a0)
/* 02E780 80053380 2402007F */  addiu $v0, $zero, 0x7f
/* 02E784 80053384 A0820004 */  sb    $v0, 4($a0)
/* 02E788 80053388 24020040 */  addiu $v0, $zero, 0x40
/* 02E78C 8005338C A0820005 */  sb    $v0, 5($a0)
/* 02E790 80053390 A0800006 */  sb    $zero, 6($a0)
/* 02E794 80053394 A0800007 */  sb    $zero, 7($a0)
/* 02E798 80053398 A0800008 */  sb    $zero, 8($a0)
/* 02E79C 8005339C A0800009 */  sb    $zero, 9($a0)
/* 02E7A0 800533A0 03E00008 */  jr    $ra
/* 02E7A4 800533A4 A080000A */   sb    $zero, 0xa($a0)

