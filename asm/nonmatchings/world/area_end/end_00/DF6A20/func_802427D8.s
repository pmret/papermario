.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802427D8
/* DF91D8 802427D8 3C04800B */  lui       $a0, %hi(gCameras)
/* DF91DC 802427DC 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* DF91E0 802427E0 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* DF91E4 802427E4 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* DF91E8 802427E8 3C013F2A */  lui       $at, 0x3f2a
/* DF91EC 802427EC 3421AAAB */  ori       $at, $at, 0xaaab
/* DF91F0 802427F0 44810000 */  mtc1      $at, $f0
/* DF91F4 802427F4 00031080 */  sll       $v0, $v1, 2
/* DF91F8 802427F8 00431021 */  addu      $v0, $v0, $v1
/* DF91FC 802427FC 00021080 */  sll       $v0, $v0, 2
/* DF9200 80242800 00431023 */  subu      $v0, $v0, $v1
/* DF9204 80242804 000218C0 */  sll       $v1, $v0, 3
/* DF9208 80242808 00431021 */  addu      $v0, $v0, $v1
/* DF920C 8024280C 000210C0 */  sll       $v0, $v0, 3
/* DF9210 80242810 00441021 */  addu      $v0, $v0, $a0
/* DF9214 80242814 C44204B0 */  lwc1      $f2, 0x4b0($v0)
/* DF9218 80242818 46001080 */  add.s     $f2, $f2, $f0
/* DF921C 8024281C 24030001 */  addiu     $v1, $zero, 1
/* DF9220 80242820 A4430506 */  sh        $v1, 0x506($v0)
/* DF9224 80242824 E44204B0 */  swc1      $f2, 0x4b0($v0)
/* DF9228 80242828 03E00008 */  jr        $ra
/* DF922C 8024282C 24020002 */   addiu    $v0, $zero, 2
