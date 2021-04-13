.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004CFC0
/* 283C0 8004CFC0 8CA20050 */  lw        $v0, 0x50($a1)
/* 283C4 8004CFC4 03E00008 */  jr        $ra
/* 283C8 8004CFC8 ACA20000 */   sw       $v0, ($a1)
