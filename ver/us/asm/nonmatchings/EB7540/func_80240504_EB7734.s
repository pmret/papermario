.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240504_EB7734
/* EB7734 80240504 3C03800C */  lui       $v1, %hi(dead_gCameras)
/* EB7738 80240508 24638D80 */  addiu     $v1, $v1, %lo(dead_gCameras)
/* EB773C 8024050C 94620002 */  lhu       $v0, 2($v1)
/* EB7740 80240510 3042FFFE */  andi      $v0, $v0, 0xfffe
/* EB7744 80240514 A4620002 */  sh        $v0, 2($v1)
/* EB7748 80240518 03E00008 */  jr        $ra
/* EB774C 8024051C 24020002 */   addiu    $v0, $zero, 2
