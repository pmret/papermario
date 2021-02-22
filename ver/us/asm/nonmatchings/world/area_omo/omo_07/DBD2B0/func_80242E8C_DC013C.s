.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242E8C_DC013C
/* DC013C 80242E8C 3C03800B */  lui       $v1, %hi(gCameras)
/* DC0140 80242E90 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* DC0144 80242E94 94620000 */  lhu       $v0, ($v1)
/* DC0148 80242E98 3042EFFF */  andi      $v0, $v0, 0xefff
/* DC014C 80242E9C A4620000 */  sh        $v0, ($v1)
/* DC0150 80242EA0 03E00008 */  jr        $ra
/* DC0154 80242EA4 24020002 */   addiu    $v0, $zero, 2
