.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242D1C_C63A2C
/* C63A2C 80242D1C 3C03800B */  lui       $v1, %hi(gCameras)
/* C63A30 80242D20 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* C63A34 80242D24 94620002 */  lhu       $v0, 2($v1)
/* C63A38 80242D28 34420001 */  ori       $v0, $v0, 1
/* C63A3C 80242D2C A4620002 */  sh        $v0, 2($v1)
/* C63A40 80242D30 03E00008 */  jr        $ra
/* C63A44 80242D34 24020002 */   addiu    $v0, $zero, 2
