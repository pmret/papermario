.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400E0_EED1E0
/* EED1E0 802400E0 3C03800A */  lui       $v1, %hi(D_800A15A8)
/* EED1E4 802400E4 246315A8 */  addiu     $v1, $v1, %lo(D_800A15A8)
/* EED1E8 802400E8 8C620000 */  lw        $v0, ($v1)
/* EED1EC 802400EC 34420040 */  ori       $v0, $v0, 0x40
/* EED1F0 802400F0 AC620000 */  sw        $v0, ($v1)
/* EED1F4 802400F4 03E00008 */  jr        $ra
/* EED1F8 802400F8 24020002 */   addiu    $v0, $zero, 2
