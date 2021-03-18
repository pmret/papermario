.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400FC_CD1F2C
/* CD1F2C 802400FC 3C02800A */  lui       $v0, %hi(gOverrideFlags)
/* CD1F30 80240100 2442A650 */  addiu     $v0, $v0, %lo(gOverrideFlags)
/* CD1F34 80240104 8C430000 */  lw        $v1, ($v0)
/* CD1F38 80240108 2404FFBF */  addiu     $a0, $zero, -0x41
/* CD1F3C 8024010C 00641824 */  and       $v1, $v1, $a0
/* CD1F40 80240110 AC430000 */  sw        $v1, ($v0)
/* CD1F44 80240114 03E00008 */  jr        $ra
/* CD1F48 80240118 24020002 */   addiu    $v0, $zero, 2
