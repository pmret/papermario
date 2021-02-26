.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050904
/* 2BD04 80050904 3C02800A */  lui       $v0, %hi(D_8009A608)
/* 2BD08 80050908 8C42A608 */  lw        $v0, %lo(D_8009A608)($v0)
/* 2BD0C 8005090C 03E00008 */  jr        $ra
/* 2BD10 80050910 A0450021 */   sb       $a1, 0x21($v0)
