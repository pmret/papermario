.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_A4CA20
/* A4CA20 80240000 3C03800B */  lui       $v1, %hi(gCameras)
/* A4CA24 80240004 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* A4CA28 80240008 94620002 */  lhu       $v0, 2($v1)
/* A4CA2C 8024000C 3042FFFE */  andi      $v0, $v0, 0xfffe
/* A4CA30 80240010 A4620002 */  sh        $v0, 2($v1)
/* A4CA34 80240014 03E00008 */  jr        $ra
/* A4CA38 80240018 24020002 */   addiu    $v0, $zero, 2
