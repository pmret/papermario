.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240320_8C82B0
/* 8C82B0 80240320 3C03800B */  lui       $v1, %hi(gCameras)
/* 8C82B4 80240324 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 8C82B8 80240328 94620002 */  lhu       $v0, 2($v1)
/* 8C82BC 8024032C 3042FFFE */  andi      $v0, $v0, 0xfffe
/* 8C82C0 80240330 A4620002 */  sh        $v0, 2($v1)
/* 8C82C4 80240334 03E00008 */  jr        $ra
/* 8C82C8 80240338 24020002 */   addiu    $v0, $zero, 2
