.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_curtain_fade_goal
/* 7314 8002BF14 3C01800A */  lui       $at, 0x800a
/* 7318 8002BF18 E42CBA9C */  swc1      $f12, -0x4564($at)
/* 731C 8002BF1C 03E00008 */  jr        $ra
/* 7320 8002BF20 00000000 */   nop      
