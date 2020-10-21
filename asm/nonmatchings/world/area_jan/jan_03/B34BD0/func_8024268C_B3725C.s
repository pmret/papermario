.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024268C_B3725C
/* B3725C 8024268C 3C028025 */  lui       $v0, 0x8025
/* B37260 80242690 8C42FF00 */  lw        $v0, -0x100($v0)
/* B37264 80242694 8C42000C */  lw        $v0, 0xc($v0)
/* B37268 80242698 AC40001C */  sw        $zero, 0x1c($v0)
/* B3726C 8024269C 03E00008 */  jr        $ra
/* B37270 802426A0 24020002 */   addiu    $v0, $zero, 2
