.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242870_A1D970
/* A1D970 80242870 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A1D974 80242874 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* A1D978 80242878 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* A1D97C 8024287C 3C05800B */  lui       $a1, %hi(gCameras)
/* A1D980 80242880 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* A1D984 80242884 AFBF0010 */  sw        $ra, 0x10($sp)
/* A1D988 80242888 00031080 */  sll       $v0, $v1, 2
/* A1D98C 8024288C 00431021 */  addu      $v0, $v0, $v1
/* A1D990 80242890 00021080 */  sll       $v0, $v0, 2
/* A1D994 80242894 00431023 */  subu      $v0, $v0, $v1
/* A1D998 80242898 000218C0 */  sll       $v1, $v0, 3
/* A1D99C 8024289C 00431021 */  addu      $v0, $v0, $v1
/* A1D9A0 802428A0 8C830020 */  lw        $v1, 0x20($a0)
/* A1D9A4 802428A4 000210C0 */  sll       $v0, $v0, 3
/* A1D9A8 802428A8 8C630000 */  lw        $v1, ($v1)
/* A1D9AC 802428AC 30630001 */  andi      $v1, $v1, 1
/* A1D9B0 802428B0 10600004 */  beqz      $v1, .L802428C4
/* A1D9B4 802428B4 00451021 */   addu     $v0, $v0, $a1
/* A1D9B8 802428B8 C44C006C */  lwc1      $f12, 0x6c($v0)
/* A1D9BC 802428BC 0C00A6C9 */  jal       clamp_angle
/* A1D9C0 802428C0 46006307 */   neg.s    $f12, $f12
.L802428C4:
/* A1D9C4 802428C4 8FBF0010 */  lw        $ra, 0x10($sp)
/* A1D9C8 802428C8 03E00008 */  jr        $ra
/* A1D9CC 802428CC 27BD0018 */   addiu    $sp, $sp, 0x18
