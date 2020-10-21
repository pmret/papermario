.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F68_B36B38
/* B36B38 80241F68 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B36B3C 80241F6C 3C03800A */  lui       $v1, 0x800a
/* B36B40 80241F70 8463A634 */  lh        $v1, -0x59cc($v1)
/* B36B44 80241F74 3C05800B */  lui       $a1, %hi(gCameras)
/* B36B48 80241F78 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* B36B4C 80241F7C AFBF0010 */  sw        $ra, 0x10($sp)
/* B36B50 80241F80 00031080 */  sll       $v0, $v1, 2
/* B36B54 80241F84 00431021 */  addu      $v0, $v0, $v1
/* B36B58 80241F88 00021080 */  sll       $v0, $v0, 2
/* B36B5C 80241F8C 00431023 */  subu      $v0, $v0, $v1
/* B36B60 80241F90 000218C0 */  sll       $v1, $v0, 3
/* B36B64 80241F94 00431021 */  addu      $v0, $v0, $v1
/* B36B68 80241F98 8C830020 */  lw        $v1, 0x20($a0)
/* B36B6C 80241F9C 000210C0 */  sll       $v0, $v0, 3
/* B36B70 80241FA0 8C630000 */  lw        $v1, ($v1)
/* B36B74 80241FA4 30630001 */  andi      $v1, $v1, 1
/* B36B78 80241FA8 10600004 */  beqz      $v1, .L80241FBC
/* B36B7C 80241FAC 00451021 */   addu     $v0, $v0, $a1
/* B36B80 80241FB0 C44C006C */  lwc1      $f12, 0x6c($v0)
/* B36B84 80241FB4 0C00A6C9 */  jal       clamp_angle
/* B36B88 80241FB8 46006307 */   neg.s    $f12, $f12
.L80241FBC:
/* B36B8C 80241FBC 8FBF0010 */  lw        $ra, 0x10($sp)
/* B36B90 80241FC0 03E00008 */  jr        $ra
/* B36B94 80241FC4 27BD0018 */   addiu    $sp, $sp, 0x18
