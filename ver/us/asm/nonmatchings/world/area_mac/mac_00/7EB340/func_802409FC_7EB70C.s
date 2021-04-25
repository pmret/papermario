.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409FC_7EB70C
/* 7EB70C 802409FC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7EB710 80240A00 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* 7EB714 80240A04 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* 7EB718 80240A08 3C05800B */  lui       $a1, %hi(gCameras)
/* 7EB71C 80240A0C 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* 7EB720 80240A10 AFBF0010 */  sw        $ra, 0x10($sp)
/* 7EB724 80240A14 00031080 */  sll       $v0, $v1, 2
/* 7EB728 80240A18 00431021 */  addu      $v0, $v0, $v1
/* 7EB72C 80240A1C 00021080 */  sll       $v0, $v0, 2
/* 7EB730 80240A20 00431023 */  subu      $v0, $v0, $v1
/* 7EB734 80240A24 000218C0 */  sll       $v1, $v0, 3
/* 7EB738 80240A28 00431021 */  addu      $v0, $v0, $v1
/* 7EB73C 80240A2C 8C830020 */  lw        $v1, 0x20($a0)
/* 7EB740 80240A30 000210C0 */  sll       $v0, $v0, 3
/* 7EB744 80240A34 8C630000 */  lw        $v1, ($v1)
/* 7EB748 80240A38 30630001 */  andi      $v1, $v1, 1
/* 7EB74C 80240A3C 10600004 */  beqz      $v1, .L80240A50
/* 7EB750 80240A40 00451021 */   addu     $v0, $v0, $a1
/* 7EB754 80240A44 C44C006C */  lwc1      $f12, 0x6c($v0)
/* 7EB758 80240A48 0C00A6C9 */  jal       clamp_angle
/* 7EB75C 80240A4C 46006307 */   neg.s    $f12, $f12
.L80240A50:
/* 7EB760 80240A50 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7EB764 80240A54 03E00008 */  jr        $ra
/* 7EB768 80240A58 27BD0018 */   addiu    $sp, $sp, 0x18
