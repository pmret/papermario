.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_tabs_draw_invis
/* 137ED0 80244B90 03E00008 */  jr        $ra
/* 137ED4 80244B94 00000000 */   nop      
