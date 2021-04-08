.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240350_EA7320
/* EA7320 80240350 3C03800C */  lui       $v1, %hi(D_800B8D80)
/* EA7324 80240354 24638D80 */  addiu     $v1, $v1, %lo(D_800B8D80)
/* EA7328 80240358 94620000 */  lhu       $v0, ($v1)
/* EA732C 8024035C 34421000 */  ori       $v0, $v0, 0x1000
/* EA7330 80240360 A4620000 */  sh        $v0, ($v1)
/* EA7334 80240364 03E00008 */  jr        $ra
/* EA7338 80240368 24020002 */   addiu    $v0, $zero, 2
