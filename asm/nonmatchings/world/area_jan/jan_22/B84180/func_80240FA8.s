.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FA8
/* B85128 80240FA8 3C03800B */  lui       $v1, %hi(gCameras)
/* B8512C 80240FAC 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* B85130 80240FB0 94620000 */  lhu       $v0, ($v1)
/* B85134 80240FB4 34421000 */  ori       $v0, $v0, 0x1000
/* B85138 80240FB8 A4620000 */  sh        $v0, ($v1)
/* B8513C 80240FBC 03E00008 */  jr        $ra
/* B85140 80240FC0 24020002 */   addiu    $v0, $zero, 2
