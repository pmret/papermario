.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242D00_C63A10
/* C63A10 80242D00 3C03800B */  lui       $v1, %hi(gCameras)
/* C63A14 80242D04 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* C63A18 80242D08 94620002 */  lhu       $v0, 2($v1)
/* C63A1C 80242D0C 3042FFFE */  andi      $v0, $v0, 0xfffe
/* C63A20 80242D10 A4620002 */  sh        $v0, 2($v1)
/* C63A24 80242D14 03E00008 */  jr        $ra
/* C63A28 80242D18 24020002 */   addiu    $v0, $zero, 2
