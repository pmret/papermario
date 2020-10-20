.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407AC_DDCFDC
/* DDCFDC 802407AC 3C02800A */  lui       $v0, %hi(D_8009A650)
/* DDCFE0 802407B0 2442A650 */  addiu     $v0, $v0, %lo(D_8009A650)
/* DDCFE4 802407B4 8C430000 */  lw        $v1, ($v0)
/* DDCFE8 802407B8 2404FFBF */  addiu     $a0, $zero, -0x41
/* DDCFEC 802407BC 00641824 */  and       $v1, $v1, $a0
/* DDCFF0 802407C0 AC430000 */  sw        $v1, ($v0)
/* DDCFF4 802407C4 03E00008 */  jr        $ra
/* DDCFF8 802407C8 24020002 */   addiu    $v0, $zero, 2
