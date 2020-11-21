.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_cleanup
/* 172FE8 80244708 03E00008 */  jr        $ra
/* 172FEC 8024470C 00000000 */   nop
