.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel YieldTurn
/* 1AC0D0 8027D7F0 3C02800E */  lui       $v0, 0x800e
/* 1AC0D4 8027D7F4 2442C070 */  addiu     $v0, $v0, -0x3f90
/* 1AC0D8 8027D7F8 8C430000 */  lw        $v1, ($v0)
/* 1AC0DC 8027D7FC 3C040020 */  lui       $a0, 0x20
/* 1AC0E0 8027D800 00641825 */  or        $v1, $v1, $a0
/* 1AC0E4 8027D804 AC430000 */  sw        $v1, ($v0)
/* 1AC0E8 8027D808 03E00008 */  jr        $ra
/* 1AC0EC 8027D80C 24020002 */   addiu    $v0, $zero, 2
