.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240564_D3AB34
/* D3AB34 80240564 3C03800B */  lui       $v1, %hi(gCameras)
/* D3AB38 80240568 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* D3AB3C 8024056C 94620002 */  lhu       $v0, 2($v1)
/* D3AB40 80240570 3042FFFE */  andi      $v0, $v0, 0xfffe
/* D3AB44 80240574 A4620002 */  sh        $v0, 2($v1)
/* D3AB48 80240578 03E00008 */  jr        $ra
/* D3AB4C 8024057C 24020002 */   addiu    $v0, $zero, 2
