.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8023A19C_70DEAC
/* 70DEAC 8023A19C 3C028024 */  lui       $v0, %hi(D_8023D330)
/* 70DEB0 8023A1A0 8C42D330 */  lw        $v0, %lo(D_8023D330)($v0)
/* 70DEB4 8023A1A4 2C420001 */  sltiu     $v0, $v0, 1
/* 70DEB8 8023A1A8 03E00008 */  jr        $ra
/* 70DEBC 8023A1AC 00021040 */   sll      $v0, $v0, 1
