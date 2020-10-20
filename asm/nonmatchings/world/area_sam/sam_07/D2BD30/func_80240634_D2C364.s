.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240634_D2C364
/* D2C364 80240634 3C03800B */  lui       $v1, %hi(gCameras)
/* D2C368 80240638 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* D2C36C 8024063C 94620002 */  lhu       $v0, 2($v1)
/* D2C370 80240640 3042FFFE */  andi      $v0, $v0, 0xfffe
/* D2C374 80240644 A4620002 */  sh        $v0, 2($v1)
/* D2C378 80240648 03E00008 */  jr        $ra
/* D2C37C 8024064C 24020002 */   addiu    $v0, $zero, 2
