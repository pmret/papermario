.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_A4F000
/* A4F000 80240000 3C03800B */  lui       $v1, %hi(gCameras)
/* A4F004 80240004 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* A4F008 80240008 94620002 */  lhu       $v0, 2($v1)
/* A4F00C 8024000C 3042FFFE */  andi      $v0, $v0, 0xfffe
/* A4F010 80240010 A4620002 */  sh        $v0, 2($v1)
/* A4F014 80240014 03E00008 */  jr        $ra
/* A4F018 80240018 24020002 */   addiu    $v0, $zero, 2
