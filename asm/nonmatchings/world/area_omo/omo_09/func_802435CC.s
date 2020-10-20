.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802435CC
/* DD029C 802435CC 3C03800B */  lui       $v1, %hi(gCameras)
/* DD02A0 802435D0 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* DD02A4 802435D4 94620000 */  lhu       $v0, ($v1)
/* DD02A8 802435D8 34421000 */  ori       $v0, $v0, 0x1000
/* DD02AC 802435DC A4620000 */  sh        $v0, ($v1)
/* DD02B0 802435E0 03E00008 */  jr        $ra
/* DD02B4 802435E4 24020002 */   addiu    $v0, $zero, 2
