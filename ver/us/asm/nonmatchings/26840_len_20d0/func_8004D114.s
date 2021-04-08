.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D114
/* 28514 8004D114 8CA20000 */  lw        $v0, ($a1)
/* 28518 8004D118 90430000 */  lbu       $v1, ($v0)
/* 2851C 8004D11C 24420001 */  addiu     $v0, $v0, 1
/* 28520 8004D120 ACA20000 */  sw        $v0, ($a1)
/* 28524 8004D124 ACA20088 */  sw        $v0, 0x88($a1)
/* 28528 8004D128 03E00008 */  jr        $ra
/* 2852C 8004D12C A0A3008C */   sb       $v1, 0x8c($a1)
