.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241170_B291A0
/* B291A0 80241170 3C03800B */  lui       $v1, %hi(gCameras)
/* B291A4 80241174 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* B291A8 80241178 94620000 */  lhu       $v0, ($v1)
/* B291AC 8024117C 3042EFFF */  andi      $v0, $v0, 0xefff
/* B291B0 80241180 A4620000 */  sh        $v0, ($v1)
/* B291B4 80241184 03E00008 */  jr        $ra
/* B291B8 80241188 24020002 */   addiu    $v0, $zero, 2
/* B291BC 8024118C 00000000 */  nop
