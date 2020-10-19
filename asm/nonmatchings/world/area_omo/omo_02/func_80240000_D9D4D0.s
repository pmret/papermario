.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_D9D4D0
/* D9D4D0 80240000 3C03800B */  lui       $v1, %hi(gCameras)
/* D9D4D4 80240004 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* D9D4D8 80240008 94620002 */  lhu       $v0, 2($v1)
/* D9D4DC 8024000C 3042FFFE */  andi      $v0, $v0, 0xfffe
/* D9D4E0 80240010 A4620002 */  sh        $v0, 2($v1)
/* D9D4E4 80240014 03E00008 */  jr        $ra
/* D9D4E8 80240018 24020002 */   addiu    $v0, $zero, 2
