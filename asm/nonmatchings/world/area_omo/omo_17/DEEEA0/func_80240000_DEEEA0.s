.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_DEEEA0
/* DEEEA0 80240000 3C03800B */  lui       $v1, %hi(gCameras)
/* DEEEA4 80240004 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* DEEEA8 80240008 94620002 */  lhu       $v0, 2($v1)
/* DEEEAC 8024000C 3042FFFE */  andi      $v0, $v0, 0xfffe
/* DEEEB0 80240010 A4620002 */  sh        $v0, 2($v1)
/* DEEEB4 80240014 03E00008 */  jr        $ra
/* DEEEB8 80240018 24020002 */   addiu    $v0, $zero, 2
