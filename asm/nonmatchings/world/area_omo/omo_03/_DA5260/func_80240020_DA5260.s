.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240020_DA5260
/* DA5260 80240020 3C03800B */  lui       $v1, %hi(gCameras)
/* DA5264 80240024 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* DA5268 80240028 94620002 */  lhu       $v0, 2($v1)
/* DA526C 8024002C 3042FFFE */  andi      $v0, $v0, 0xfffe
/* DA5270 80240030 A4620002 */  sh        $v0, 2($v1)
/* DA5274 80240034 03E00008 */  jr        $ra
/* DA5278 80240038 24020002 */   addiu    $v0, $zero, 2
