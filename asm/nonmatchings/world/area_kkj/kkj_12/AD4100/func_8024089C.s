.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024089C
/* AD492C 8024089C 3C028015 */  lui       $v0, %hi(D_80151328)
/* AD4930 802408A0 8C421328 */  lw        $v0, %lo(D_80151328)($v0)
/* AD4934 802408A4 A040001C */  sb        $zero, 0x1c($v0)
/* AD4938 802408A8 03E00008 */  jr        $ra
/* AD493C 802408AC 24020002 */   addiu    $v0, $zero, 2
