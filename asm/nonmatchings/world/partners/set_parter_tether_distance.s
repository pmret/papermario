.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_parter_tether_distance
/* 88844 800EF394 3C018011 */  lui       $at, %hi(D_8010CFC0)
/* 88848 800EF398 E42CCFC0 */  swc1      $f12, %lo(D_8010CFC0)($at)
/* 8884C 800EF39C 03E00008 */  jr        $ra
/* 88850 800EF3A0 00000000 */   nop
