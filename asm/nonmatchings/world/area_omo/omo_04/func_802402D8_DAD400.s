.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402D8_DAD6D8
/* DAD6D8 802402D8 3C03800B */  lui       $v1, %hi(gCameras)
/* DAD6DC 802402DC 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* DAD6E0 802402E0 94620002 */  lhu       $v0, 2($v1)
/* DAD6E4 802402E4 34420001 */  ori       $v0, $v0, 1
/* DAD6E8 802402E8 A4620002 */  sh        $v0, 2($v1)
/* DAD6EC 802402EC 03E00008 */  jr        $ra
/* DAD6F0 802402F0 24020002 */   addiu    $v0, $zero, 2
