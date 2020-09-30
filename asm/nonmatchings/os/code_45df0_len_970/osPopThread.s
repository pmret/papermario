.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osPopThread
/* 465BC 8006B1BC 8C820000 */  lw        $v0, ($a0)
/* 465C0 8006B1C0 8C590000 */  lw        $t9, ($v0)
/* 465C4 8006B1C4 03E00008 */  jr        $ra
/* 465C8 8006B1C8 AC990000 */   sw       $t9, ($a0)
