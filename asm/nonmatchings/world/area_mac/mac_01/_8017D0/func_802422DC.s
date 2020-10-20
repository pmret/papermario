.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802422DC
/* 802B5C 802422DC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 802B60 802422E0 3C03800A */  lui       $v1, 0x800a
/* 802B64 802422E4 8463A634 */  lh        $v1, -0x59cc($v1)
/* 802B68 802422E8 3C05800B */  lui       $a1, %hi(gCameras)
/* 802B6C 802422EC 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* 802B70 802422F0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 802B74 802422F4 00031080 */  sll       $v0, $v1, 2
/* 802B78 802422F8 00431021 */  addu      $v0, $v0, $v1
/* 802B7C 802422FC 00021080 */  sll       $v0, $v0, 2
/* 802B80 80242300 00431023 */  subu      $v0, $v0, $v1
/* 802B84 80242304 000218C0 */  sll       $v1, $v0, 3
/* 802B88 80242308 00431021 */  addu      $v0, $v0, $v1
/* 802B8C 8024230C 8C830020 */  lw        $v1, 0x20($a0)
/* 802B90 80242310 000210C0 */  sll       $v0, $v0, 3
/* 802B94 80242314 8C630000 */  lw        $v1, ($v1)
/* 802B98 80242318 30630001 */  andi      $v1, $v1, 1
/* 802B9C 8024231C 10600004 */  beqz      $v1, .L80242330
/* 802BA0 80242320 00451021 */   addu     $v0, $v0, $a1
/* 802BA4 80242324 C44C006C */  lwc1      $f12, 0x6c($v0)
/* 802BA8 80242328 0C00A6C9 */  jal       clamp_angle
/* 802BAC 8024232C 46006307 */   neg.s    $f12, $f12
.L80242330:
/* 802BB0 80242330 8FBF0010 */  lw        $ra, 0x10($sp)
/* 802BB4 80242334 03E00008 */  jr        $ra
/* 802BB8 80242338 27BD0018 */   addiu    $sp, $sp, 0x18
