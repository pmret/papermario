.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419E0_B2DE50
/* B2DE50 802419E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B2DE54 802419E4 3C03800A */  lui       $v1, %hi(D_8009A634)
/* B2DE58 802419E8 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* B2DE5C 802419EC 3C05800B */  lui       $a1, %hi(gCameras)
/* B2DE60 802419F0 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* B2DE64 802419F4 AFBF0010 */  sw        $ra, 0x10($sp)
/* B2DE68 802419F8 00031080 */  sll       $v0, $v1, 2
/* B2DE6C 802419FC 00431021 */  addu      $v0, $v0, $v1
/* B2DE70 80241A00 00021080 */  sll       $v0, $v0, 2
/* B2DE74 80241A04 00431023 */  subu      $v0, $v0, $v1
/* B2DE78 80241A08 000218C0 */  sll       $v1, $v0, 3
/* B2DE7C 80241A0C 00431021 */  addu      $v0, $v0, $v1
/* B2DE80 80241A10 8C830020 */  lw        $v1, 0x20($a0)
/* B2DE84 80241A14 000210C0 */  sll       $v0, $v0, 3
/* B2DE88 80241A18 8C630000 */  lw        $v1, ($v1)
/* B2DE8C 80241A1C 30630001 */  andi      $v1, $v1, 1
/* B2DE90 80241A20 10600004 */  beqz      $v1, .L80241A34
/* B2DE94 80241A24 00451021 */   addu     $v0, $v0, $a1
/* B2DE98 80241A28 C44C006C */  lwc1      $f12, 0x6c($v0)
/* B2DE9C 80241A2C 0C00A6C9 */  jal       clamp_angle
/* B2DEA0 80241A30 46006307 */   neg.s    $f12, $f12
.L80241A34:
/* B2DEA4 80241A34 8FBF0010 */  lw        $ra, 0x10($sp)
/* B2DEA8 80241A38 03E00008 */  jr        $ra
/* B2DEAC 80241A3C 27BD0018 */   addiu    $sp, $sp, 0x18
