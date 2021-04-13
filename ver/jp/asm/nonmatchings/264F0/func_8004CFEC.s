.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004CFEC
/* 283EC 8004CFEC 8CA20000 */  lw        $v0, ($a1)
/* 283F0 8004CFF0 90430000 */  lbu       $v1, ($v0)
/* 283F4 8004CFF4 24420001 */  addiu     $v0, $v0, 1
/* 283F8 8004CFF8 ACA20000 */  sw        $v0, ($a1)
/* 283FC 8004CFFC 03E00008 */  jr        $ra
/* 28400 8004D000 A0A300A2 */   sb       $v1, 0xa2($a1)
