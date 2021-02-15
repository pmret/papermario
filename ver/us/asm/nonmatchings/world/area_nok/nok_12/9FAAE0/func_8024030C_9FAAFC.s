.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024030C_9FAAFC
/* 9FAAFC 8024030C 3C03800B */  lui       $v1, %hi(gCameras)
/* 9FAB00 80240310 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 9FAB04 80240314 94620000 */  lhu       $v0, ($v1)
/* 9FAB08 80240318 3042EFFF */  andi      $v0, $v0, 0xefff
/* 9FAB0C 8024031C A4620000 */  sh        $v0, ($v1)
/* 9FAB10 80240320 03E00008 */  jr        $ra
/* 9FAB14 80240324 24020002 */   addiu    $v0, $zero, 2
/* 9FAB18 80240328 00000000 */  nop
/* 9FAB1C 8024032C 00000000 */  nop
