.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402BC_DAD6BC
/* DAD6BC 802402BC 3C03800B */  lui       $v1, %hi(gCameras)
/* DAD6C0 802402C0 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* DAD6C4 802402C4 94620002 */  lhu       $v0, 2($v1)
/* DAD6C8 802402C8 3042FFFE */  andi      $v0, $v0, 0xfffe
/* DAD6CC 802402CC A4620002 */  sh        $v0, 2($v1)
/* DAD6D0 802402D0 03E00008 */  jr        $ra
/* DAD6D4 802402D4 24020002 */   addiu    $v0, $zero, 2
