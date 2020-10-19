.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240180_A029C0
/* A029C0 80240180 3C03800B */  lui       $v1, %hi(gCameras)
/* A029C4 80240184 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* A029C8 80240188 94620000 */  lhu       $v0, ($v1)
/* A029CC 8024018C 34421000 */  ori       $v0, $v0, 0x1000
/* A029D0 80240190 A4620000 */  sh        $v0, ($v1)
/* A029D4 80240194 03E00008 */  jr        $ra
/* A029D8 80240198 24020002 */   addiu    $v0, $zero, 2
