.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802423D0
/* C38900 802423D0 3C03800A */  lui       $v1, %hi(D_8009A650)
/* C38904 802423D4 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* C38908 802423D8 8C620000 */  lw        $v0, ($v1)
/* C3890C 802423DC 34420040 */  ori       $v0, $v0, 0x40
/* C38910 802423E0 AC620000 */  sw        $v0, ($v1)
/* C38914 802423E4 03E00008 */  jr        $ra
/* C38918 802423E8 24020002 */   addiu    $v0, $zero, 2
