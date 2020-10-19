.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FC4_B85144
/* B85144 80240FC4 3C03800B */  lui       $v1, %hi(gCameras)
/* B85148 80240FC8 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* B8514C 80240FCC 94620000 */  lhu       $v0, ($v1)
/* B85150 80240FD0 3042EFFF */  andi      $v0, $v0, 0xefff
/* B85154 80240FD4 A4620000 */  sh        $v0, ($v1)
/* B85158 80240FD8 03E00008 */  jr        $ra
/* B8515C 80240FDC 24020002 */   addiu    $v0, $zero, 2
