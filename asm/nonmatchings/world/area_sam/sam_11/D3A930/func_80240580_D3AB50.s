.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240580_D3AB50
/* D3AB50 80240580 3C03800B */  lui       $v1, %hi(gCameras)
/* D3AB54 80240584 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* D3AB58 80240588 94620002 */  lhu       $v0, 2($v1)
/* D3AB5C 8024058C 34420001 */  ori       $v0, $v0, 1
/* D3AB60 80240590 A4620002 */  sh        $v0, 2($v1)
/* D3AB64 80240594 03E00008 */  jr        $ra
/* D3AB68 80240598 24020002 */   addiu    $v0, $zero, 2
