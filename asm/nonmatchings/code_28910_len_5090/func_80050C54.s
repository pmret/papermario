.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050C54
/* 2C054 80050C54 3C02800A */  lui       $v0, %hi(D_8009A628)
/* 2C058 80050C58 8C42A628 */  lw        $v0, %lo(D_8009A628)($v0)
/* 2C05C 80050C5C 03E00008 */  jr        $ra
/* 2C060 80050C60 A0450021 */   sb       $a1, 0x21($v0)
