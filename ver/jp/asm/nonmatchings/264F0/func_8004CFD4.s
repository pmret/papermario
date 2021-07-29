.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004CFD4
/* 283D4 8004CFD4 8CA20000 */  lw        $v0, ($a1)
/* 283D8 8004CFD8 90430000 */  lbu       $v1, ($v0)
/* 283DC 8004CFDC 24420001 */  addiu     $v0, $v0, 1
/* 283E0 8004CFE0 ACA20000 */  sw        $v0, ($a1)
/* 283E4 8004CFE4 03E00008 */  jr        $ra
/* 283E8 8004CFE8 A0A300A1 */   sb       $v1, 0xa1($a1)
