.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_DB7910
/* DB7910 80240000 3C03800B */  lui       $v1, %hi(gCameras)
/* DB7914 80240004 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* DB7918 80240008 94620002 */  lhu       $v0, 2($v1)
/* DB791C 8024000C 3042FFFE */  andi      $v0, $v0, 0xfffe
/* DB7920 80240010 A4620002 */  sh        $v0, 2($v1)
/* DB7924 80240014 03E00008 */  jr        $ra
/* DB7928 80240018 24020002 */   addiu    $v0, $zero, 2
