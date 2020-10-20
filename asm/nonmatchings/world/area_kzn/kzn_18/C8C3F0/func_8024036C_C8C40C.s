.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024036C_C8C40C
/* C8C40C 8024036C 3C03800B */  lui       $v1, %hi(gCameras)
/* C8C410 80240370 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* C8C414 80240374 94620000 */  lhu       $v0, ($v1)
/* C8C418 80240378 3042EFFF */  andi      $v0, $v0, 0xefff
/* C8C41C 8024037C A4620000 */  sh        $v0, ($v1)
/* C8C420 80240380 03E00008 */  jr        $ra
/* C8C424 80240384 24020002 */   addiu    $v0, $zero, 2
