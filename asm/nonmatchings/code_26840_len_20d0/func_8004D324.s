.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D324
/* 28724 8004D324 8CA20000 */  lw        $v0, ($a1)
/* 28728 8004D328 90430000 */  lbu       $v1, ($v0)
/* 2872C 8004D32C 24420001 */  addiu     $v0, $v0, 1
/* 28730 8004D330 ACA20000 */  sw        $v0, ($a1)
/* 28734 8004D334 03E00008 */  jr        $ra
/* 28738 8004D338 A0A300A1 */   sb       $v1, 0xa1($a1)
