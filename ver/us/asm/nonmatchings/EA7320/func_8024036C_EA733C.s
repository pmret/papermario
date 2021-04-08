.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024036C_EA733C
/* EA733C 8024036C 3C03800C */  lui       $v1, %hi(D_800B8D80)
/* EA7340 80240370 24638D80 */  addiu     $v1, $v1, %lo(D_800B8D80)
/* EA7344 80240374 94620000 */  lhu       $v0, ($v1)
/* EA7348 80240378 3042EFFF */  andi      $v0, $v0, 0xefff
/* EA734C 8024037C A4620000 */  sh        $v0, ($v1)
/* EA7350 80240380 03E00008 */  jr        $ra
/* EA7354 80240384 24020002 */   addiu    $v0, $zero, 2
