.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400E0_CD1F10
/* CD1F10 802400E0 3C03800A */  lui       $v1, %hi(D_8009A650)
/* CD1F14 802400E4 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* CD1F18 802400E8 8C620000 */  lw        $v0, ($v1)
/* CD1F1C 802400EC 34420040 */  ori       $v0, $v0, 0x40
/* CD1F20 802400F0 AC620000 */  sw        $v0, ($v1)
/* CD1F24 802400F4 03E00008 */  jr        $ra
/* CD1F28 802400F8 24020002 */   addiu    $v0, $zero, 2
