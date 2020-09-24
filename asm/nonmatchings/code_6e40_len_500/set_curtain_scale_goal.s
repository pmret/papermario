.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_curtain_scale_goal
/* 72DC 8002BEDC 3C01800A */  lui       $at, 0x800a
/* 72E0 8002BEE0 E42CBA94 */  swc1      $f12, -0x456c($at)
/* 72E4 8002BEE4 03E00008 */  jr        $ra
/* 72E8 8002BEE8 00000000 */   nop      
