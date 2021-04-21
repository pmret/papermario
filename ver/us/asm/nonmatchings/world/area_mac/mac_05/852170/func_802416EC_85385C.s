.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416EC_85385C
/* 85385C 802416EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 853860 802416F0 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* 853864 802416F4 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* 853868 802416F8 3C05800B */  lui       $a1, %hi(gCameras)
/* 85386C 802416FC 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* 853870 80241700 AFBF0010 */  sw        $ra, 0x10($sp)
/* 853874 80241704 00031080 */  sll       $v0, $v1, 2
/* 853878 80241708 00431021 */  addu      $v0, $v0, $v1
/* 85387C 8024170C 00021080 */  sll       $v0, $v0, 2
/* 853880 80241710 00431023 */  subu      $v0, $v0, $v1
/* 853884 80241714 000218C0 */  sll       $v1, $v0, 3
/* 853888 80241718 00431021 */  addu      $v0, $v0, $v1
/* 85388C 8024171C 8C830020 */  lw        $v1, 0x20($a0)
/* 853890 80241720 000210C0 */  sll       $v0, $v0, 3
/* 853894 80241724 8C630000 */  lw        $v1, ($v1)
/* 853898 80241728 30630001 */  andi      $v1, $v1, 1
/* 85389C 8024172C 10600004 */  beqz      $v1, .L80241740
/* 8538A0 80241730 00451021 */   addu     $v0, $v0, $a1
/* 8538A4 80241734 C44C006C */  lwc1      $f12, 0x6c($v0)
/* 8538A8 80241738 0C00A6C9 */  jal       clamp_angle
/* 8538AC 8024173C 46006307 */   neg.s    $f12, $f12
.L80241740:
/* 8538B0 80241740 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8538B4 80241744 03E00008 */  jr        $ra
/* 8538B8 80241748 27BD0018 */   addiu    $sp, $sp, 0x18
