.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406CC_96988C
/* 96988C 802406CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 969890 802406D0 3C03800A */  lui       $v1, 0x800a
/* 969894 802406D4 8463A634 */  lh        $v1, -0x59cc($v1)
/* 969898 802406D8 3C05800B */  lui       $a1, %hi(gCameras)
/* 96989C 802406DC 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* 9698A0 802406E0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9698A4 802406E4 00031080 */  sll       $v0, $v1, 2
/* 9698A8 802406E8 00431021 */  addu      $v0, $v0, $v1
/* 9698AC 802406EC 00021080 */  sll       $v0, $v0, 2
/* 9698B0 802406F0 00431023 */  subu      $v0, $v0, $v1
/* 9698B4 802406F4 000218C0 */  sll       $v1, $v0, 3
/* 9698B8 802406F8 00431021 */  addu      $v0, $v0, $v1
/* 9698BC 802406FC 8C830020 */  lw        $v1, 0x20($a0)
/* 9698C0 80240700 000210C0 */  sll       $v0, $v0, 3
/* 9698C4 80240704 8C630000 */  lw        $v1, ($v1)
/* 9698C8 80240708 30630001 */  andi      $v1, $v1, 1
/* 9698CC 8024070C 10600004 */  beqz      $v1, .L80240720
/* 9698D0 80240710 00451021 */   addu     $v0, $v0, $a1
/* 9698D4 80240714 C44C006C */  lwc1      $f12, 0x6c($v0)
/* 9698D8 80240718 0C00A6C9 */  jal       clamp_angle
/* 9698DC 8024071C 46006307 */   neg.s    $f12, $f12
.L80240720:
/* 9698E0 80240720 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9698E4 80240724 03E00008 */  jr        $ra
/* 9698E8 80240728 27BD0018 */   addiu    $sp, $sp, 0x18
