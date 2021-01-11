.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400FC_EED1FC
/* EED1FC 802400FC 3C02800A */  lui       $v0, %hi(D_800A15A8)
/* EED200 80240100 244215A8 */  addiu     $v0, $v0, %lo(D_800A15A8)
/* EED204 80240104 8C430000 */  lw        $v1, ($v0)
/* EED208 80240108 2404FFBF */  addiu     $a0, $zero, -0x41
/* EED20C 8024010C 00641824 */  and       $v1, $v1, $a0
/* EED210 80240110 AC430000 */  sw        $v1, ($v0)
/* EED214 80240114 03E00008 */  jr        $ra
/* EED218 80240118 24020002 */   addiu    $v0, $zero, 2
