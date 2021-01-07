.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024075C_8B07CC
/* 8B07CC 8024075C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B07D0 80240760 3C03800A */  lui       $v1, %hi(D_8009A634)
/* 8B07D4 80240764 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* 8B07D8 80240768 3C05800B */  lui       $a1, %hi(gCameras)
/* 8B07DC 8024076C 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* 8B07E0 80240770 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B07E4 80240774 00031080 */  sll       $v0, $v1, 2
/* 8B07E8 80240778 00431021 */  addu      $v0, $v0, $v1
/* 8B07EC 8024077C 00021080 */  sll       $v0, $v0, 2
/* 8B07F0 80240780 00431023 */  subu      $v0, $v0, $v1
/* 8B07F4 80240784 000218C0 */  sll       $v1, $v0, 3
/* 8B07F8 80240788 00431021 */  addu      $v0, $v0, $v1
/* 8B07FC 8024078C 8C830020 */  lw        $v1, 0x20($a0)
/* 8B0800 80240790 000210C0 */  sll       $v0, $v0, 3
/* 8B0804 80240794 8C630000 */  lw        $v1, ($v1)
/* 8B0808 80240798 30630001 */  andi      $v1, $v1, 1
/* 8B080C 8024079C 10600004 */  beqz      $v1, .L802407B0
/* 8B0810 802407A0 00451021 */   addu     $v0, $v0, $a1
/* 8B0814 802407A4 C44C006C */  lwc1      $f12, 0x6c($v0)
/* 8B0818 802407A8 0C00A6C9 */  jal       clamp_angle
/* 8B081C 802407AC 46006307 */   neg.s    $f12, $f12
.L802407B0:
/* 8B0820 802407B0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B0824 802407B4 03E00008 */  jr        $ra
/* 8B0828 802407B8 27BD0018 */   addiu    $sp, $sp, 0x18
