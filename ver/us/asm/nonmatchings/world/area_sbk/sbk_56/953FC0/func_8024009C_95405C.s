.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024009C_95405C
/* 95405C 8024009C 3C02800A */  lui       $v0, %hi(D_8009A650)
/* 954060 802400A0 2442A650 */  addiu     $v0, $v0, %lo(D_8009A650)
/* 954064 802400A4 8C430000 */  lw        $v1, ($v0)
/* 954068 802400A8 2404FFBF */  addiu     $a0, $zero, -0x41
/* 95406C 802400AC 00641824 */  and       $v1, $v1, $a0
/* 954070 802400B0 AC430000 */  sw        $v1, ($v0)
/* 954074 802400B4 03E00008 */  jr        $ra
/* 954078 802400B8 24020002 */   addiu    $v0, $zero, 2
