.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80282324
/* 7E31A4 80282324 8C820074 */  lw        $v0, 0x74($a0)
/* 7E31A8 80282328 8C420000 */  lw        $v0, ($v0)
/* 7E31AC 8028232C AC820084 */  sw        $v0, 0x84($a0)
/* 7E31B0 80282330 03E00008 */  jr        $ra
/* 7E31B4 80282334 24020002 */   addiu    $v0, $zero, 2
