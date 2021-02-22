.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402FC_879EDC
/* 879EDC 802402FC 3C02800A */  lui       $v0, %hi(D_8009A650)
/* 879EE0 80240300 2442A650 */  addiu     $v0, $v0, %lo(D_8009A650)
/* 879EE4 80240304 8C430000 */  lw        $v1, ($v0)
/* 879EE8 80240308 2404FFBF */  addiu     $a0, $zero, -0x41
/* 879EEC 8024030C 00641824 */  and       $v1, $v1, $a0
/* 879EF0 80240310 AC430000 */  sw        $v1, ($v0)
/* 879EF4 80240314 03E00008 */  jr        $ra
/* 879EF8 80240318 24020002 */   addiu    $v0, $zero, 2
