.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F0_9FAAE0
/* 9FAAE0 802402F0 3C03800B */  lui       $v1, %hi(gCameras)
/* 9FAAE4 802402F4 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 9FAAE8 802402F8 94620000 */  lhu       $v0, ($v1)
/* 9FAAEC 802402FC 34421000 */  ori       $v0, $v0, 0x1000
/* 9FAAF0 80240300 A4620000 */  sh        $v0, ($v1)
/* 9FAAF4 80240304 03E00008 */  jr        $ra
/* 9FAAF8 80240308 24020002 */   addiu    $v0, $zero, 2
