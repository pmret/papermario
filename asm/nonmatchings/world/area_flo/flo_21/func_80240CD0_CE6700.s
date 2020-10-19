.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CD0_CE73D0
/* CE73D0 80240CD0 3C03800B */  lui       $v1, %hi(gCameras)
/* CE73D4 80240CD4 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* CE73D8 80240CD8 94620002 */  lhu       $v0, 2($v1)
/* CE73DC 80240CDC 3042FFFE */  andi      $v0, $v0, 0xfffe
/* CE73E0 80240CE0 A4620002 */  sh        $v0, 2($v1)
/* CE73E4 80240CE4 03E00008 */  jr        $ra
/* CE73E8 80240CE8 24020002 */   addiu    $v0, $zero, 2
/* CE73EC 80240CEC 00000000 */  nop       
