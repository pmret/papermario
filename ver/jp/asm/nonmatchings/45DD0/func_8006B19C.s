.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006B19C
/* 4659C 8006B19C 8C820000 */  lw        $v0, ($a0)
/* 465A0 8006B1A0 8C590000 */  lw        $t9, ($v0)
/* 465A4 8006B1A4 03E00008 */  jr        $ra
/* 465A8 8006B1A8 AC990000 */   sw       $t9, ($a0)
/* 465AC 8006B1AC 03E00008 */  jr        $ra
/* 465B0 8006B1B0 00000000 */   nop
