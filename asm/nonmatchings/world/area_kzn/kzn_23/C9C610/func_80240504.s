.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240504
/* C9C804 80240504 3C03800B */  lui       $v1, %hi(gCameras)
/* C9C808 80240508 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* C9C80C 8024050C 94620002 */  lhu       $v0, 2($v1)
/* C9C810 80240510 3042FFFE */  andi      $v0, $v0, 0xfffe
/* C9C814 80240514 A4620002 */  sh        $v0, 2($v1)
/* C9C818 80240518 03E00008 */  jr        $ra
/* C9C81C 8024051C 24020002 */   addiu    $v0, $zero, 2
