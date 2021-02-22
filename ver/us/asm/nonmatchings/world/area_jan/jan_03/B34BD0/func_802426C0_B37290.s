.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802426C0_B37290
/* B37290 802426C0 3C028025 */  lui       $v0, %hi(D_8024FF00)
/* B37294 802426C4 8C42FF00 */  lw        $v0, %lo(D_8024FF00)($v0)
/* B37298 802426C8 8C43000C */  lw        $v1, 0xc($v0)
/* B3729C 802426CC 24020002 */  addiu     $v0, $zero, 2
/* B372A0 802426D0 03E00008 */  jr        $ra
/* B372A4 802426D4 AC62001C */   sw       $v0, 0x1c($v1)
