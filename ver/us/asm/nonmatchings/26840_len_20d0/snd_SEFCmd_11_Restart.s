.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel snd_SEFCmd_11_Restart
/* 28710 8004D310 8CA20050 */  lw        $v0, 0x50($a1)
/* 28714 8004D314 03E00008 */  jr        $ra
/* 28718 8004D318 ACA20000 */   sw       $v0, ($a1)
