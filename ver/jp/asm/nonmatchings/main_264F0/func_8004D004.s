.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D004
/* 28404 8004D004 8CA20000 */  lw        $v0, ($a1)
/* 28408 8004D008 90430000 */  lbu       $v1, ($v0)
/* 2840C 8004D00C 24420001 */  addiu     $v0, $v0, 1
/* 28410 8004D010 ACA20000 */  sw        $v0, ($a1)
/* 28414 8004D014 03E00008 */  jr        $ra
/* 28418 8004D018 A0A300A3 */   sb       $v1, 0xa3($a1)
