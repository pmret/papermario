.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_curtain_scale
/* 72EC 8002BEEC 3C01800A */  lui       $at, 0x800a
/* 72F0 8002BEF0 E42CBA94 */  swc1      $f12, -0x456c($at)
/* 72F4 8002BEF4 3C01800A */  lui       $at, 0x800a
/* 72F8 8002BEF8 E42CBA90 */  swc1      $f12, -0x4570($at)
/* 72FC 8002BEFC 03E00008 */  jr        $ra
/* 7300 8002BF00 00000000 */   nop      
