.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F8_DDF608
/* DDF608 802402F8 3C03800B */  lui       $v1, %hi(gCameras)
/* DDF60C 802402FC 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* DDF610 80240300 94620000 */  lhu       $v0, ($v1)
/* DDF614 80240304 3042EFFF */  andi      $v0, $v0, 0xefff
/* DDF618 80240308 A4620000 */  sh        $v0, ($v1)
/* DDF61C 8024030C 03E00008 */  jr        $ra
/* DDF620 80240310 24020002 */   addiu    $v0, $zero, 2
