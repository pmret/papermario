.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DD0_A11650
/* A11650 80240DD0 3C03800B */  lui       $v1, %hi(gCameras)
/* A11654 80240DD4 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* A11658 80240DD8 94620002 */  lhu       $v0, 2($v1)
/* A1165C 80240DDC 3042FFFE */  andi      $v0, $v0, 0xfffe
/* A11660 80240DE0 A4620002 */  sh        $v0, 2($v1)
/* A11664 80240DE4 03E00008 */  jr        $ra
/* A11668 80240DE8 24020002 */   addiu    $v0, $zero, 2
