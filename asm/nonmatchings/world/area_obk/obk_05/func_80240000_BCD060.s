.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_BCD060
/* BCD060 80240000 3C03800B */  lui       $v1, %hi(gCameras)
/* BCD064 80240004 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* BCD068 80240008 94620002 */  lhu       $v0, 2($v1)
/* BCD06C 8024000C 3042FFFE */  andi      $v0, $v0, 0xfffe
/* BCD070 80240010 A4620002 */  sh        $v0, 2($v1)
/* BCD074 80240014 03E00008 */  jr        $ra
/* BCD078 80240018 24020002 */   addiu    $v0, $zero, 2
