.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240350_C8C3F0
/* C8C3F0 80240350 3C03800B */  lui       $v1, %hi(gCameras)
/* C8C3F4 80240354 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* C8C3F8 80240358 94620000 */  lhu       $v0, ($v1)
/* C8C3FC 8024035C 34421000 */  ori       $v0, $v0, 0x1000
/* C8C400 80240360 A4620000 */  sh        $v0, ($v1)
/* C8C404 80240364 03E00008 */  jr        $ra
/* C8C408 80240368 24020002 */   addiu    $v0, $zero, 2
