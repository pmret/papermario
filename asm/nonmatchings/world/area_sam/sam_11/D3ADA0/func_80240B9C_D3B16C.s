.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B9C_D3B16C
/* D3B16C 80240B9C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D3B170 80240BA0 3C03800A */  lui       $v1, 0x800a
/* D3B174 80240BA4 8463A634 */  lh        $v1, -0x59cc($v1)
/* D3B178 80240BA8 3C05800B */  lui       $a1, %hi(gCameras)
/* D3B17C 80240BAC 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* D3B180 80240BB0 AFBF0010 */  sw        $ra, 0x10($sp)
/* D3B184 80240BB4 00031080 */  sll       $v0, $v1, 2
/* D3B188 80240BB8 00431021 */  addu      $v0, $v0, $v1
/* D3B18C 80240BBC 00021080 */  sll       $v0, $v0, 2
/* D3B190 80240BC0 00431023 */  subu      $v0, $v0, $v1
/* D3B194 80240BC4 000218C0 */  sll       $v1, $v0, 3
/* D3B198 80240BC8 00431021 */  addu      $v0, $v0, $v1
/* D3B19C 80240BCC 8C830020 */  lw        $v1, 0x20($a0)
/* D3B1A0 80240BD0 000210C0 */  sll       $v0, $v0, 3
/* D3B1A4 80240BD4 8C630000 */  lw        $v1, ($v1)
/* D3B1A8 80240BD8 30630001 */  andi      $v1, $v1, 1
/* D3B1AC 80240BDC 10600004 */  beqz      $v1, .L80240BF0
/* D3B1B0 80240BE0 00451021 */   addu     $v0, $v0, $a1
/* D3B1B4 80240BE4 C44C006C */  lwc1      $f12, 0x6c($v0)
/* D3B1B8 80240BE8 0C00A6C9 */  jal       clamp_angle
/* D3B1BC 80240BEC 46006307 */   neg.s    $f12, $f12
.L80240BF0:
/* D3B1C0 80240BF0 8FBF0010 */  lw        $ra, 0x10($sp)
/* D3B1C4 80240BF4 03E00008 */  jr        $ra
/* D3B1C8 80240BF8 27BD0018 */   addiu    $sp, $sp, 0x18
