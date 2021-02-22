.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D354
/* 28754 8004D354 8CA20000 */  lw        $v0, ($a1)
/* 28758 8004D358 90430000 */  lbu       $v1, ($v0)
/* 2875C 8004D35C 24420001 */  addiu     $v0, $v0, 1
/* 28760 8004D360 ACA20000 */  sw        $v0, ($a1)
/* 28764 8004D364 03E00008 */  jr        $ra
/* 28768 8004D368 A0A300A3 */   sb       $v1, 0xa3($a1)
