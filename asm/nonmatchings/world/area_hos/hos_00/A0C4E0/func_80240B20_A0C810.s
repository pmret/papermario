.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B20_A0C810
/* A0C810 80240B20 3C03800B */  lui       $v1, %hi(gCameras)
/* A0C814 80240B24 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* A0C818 80240B28 94620000 */  lhu       $v0, ($v1)
/* A0C81C 80240B2C 34421000 */  ori       $v0, $v0, 0x1000
/* A0C820 80240B30 A4620000 */  sh        $v0, ($v1)
/* A0C824 80240B34 03E00008 */  jr        $ra
/* A0C828 80240B38 24020002 */   addiu    $v0, $zero, 2
