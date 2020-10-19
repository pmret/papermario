.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802426A4_B37274
/* B37274 802426A4 3C028025 */  lui       $v0, 0x8025
/* B37278 802426A8 8C42FF00 */  lw        $v0, -0x100($v0)
/* B3727C 802426AC 8C43000C */  lw        $v1, 0xc($v0)
/* B37280 802426B0 24020001 */  addiu     $v0, $zero, 1
/* B37284 802426B4 AC62001C */  sw        $v0, 0x1c($v1)
/* B37288 802426B8 03E00008 */  jr        $ra
/* B3728C 802426BC 24020002 */   addiu    $v0, $zero, 2
