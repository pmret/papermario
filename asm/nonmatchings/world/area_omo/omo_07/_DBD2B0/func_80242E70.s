.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242E70
/* DC0120 80242E70 3C03800B */  lui       $v1, %hi(gCameras)
/* DC0124 80242E74 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* DC0128 80242E78 94620000 */  lhu       $v0, ($v1)
/* DC012C 80242E7C 34421000 */  ori       $v0, $v0, 0x1000
/* DC0130 80242E80 A4620000 */  sh        $v0, ($v1)
/* DC0134 80242E84 03E00008 */  jr        $ra
/* DC0138 80242E88 24020002 */   addiu    $v0, $zero, 2
