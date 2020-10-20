.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802427E8
/* E07B48 802427E8 3C04800B */  lui       $a0, %hi(gCameras)
/* E07B4C 802427EC 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* E07B50 802427F0 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* E07B54 802427F4 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* E07B58 802427F8 3C013F2A */  lui       $at, 0x3f2a
/* E07B5C 802427FC 3421AAAB */  ori       $at, $at, 0xaaab
/* E07B60 80242800 44810000 */  mtc1      $at, $f0
/* E07B64 80242804 00031080 */  sll       $v0, $v1, 2
/* E07B68 80242808 00431021 */  addu      $v0, $v0, $v1
/* E07B6C 8024280C 00021080 */  sll       $v0, $v0, 2
/* E07B70 80242810 00431023 */  subu      $v0, $v0, $v1
/* E07B74 80242814 000218C0 */  sll       $v1, $v0, 3
/* E07B78 80242818 00431021 */  addu      $v0, $v0, $v1
/* E07B7C 8024281C 000210C0 */  sll       $v0, $v0, 3
/* E07B80 80242820 00441021 */  addu      $v0, $v0, $a0
/* E07B84 80242824 C44204B0 */  lwc1      $f2, 0x4b0($v0)
/* E07B88 80242828 46001080 */  add.s     $f2, $f2, $f0
/* E07B8C 8024282C 24030001 */  addiu     $v1, $zero, 1
/* E07B90 80242830 A4430506 */  sh        $v1, 0x506($v0)
/* E07B94 80242834 E44204B0 */  swc1      $f2, 0x4b0($v0)
/* E07B98 80242838 03E00008 */  jr        $ra
/* E07B9C 8024283C 24020002 */   addiu    $v0, $zero, 2
