.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024087C_83207C
/* 83207C 8024087C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 832080 80240880 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* 832084 80240884 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* 832088 80240888 3C05800B */  lui       $a1, %hi(gCameras)
/* 83208C 8024088C 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* 832090 80240890 AFBF0010 */  sw        $ra, 0x10($sp)
/* 832094 80240894 00031080 */  sll       $v0, $v1, 2
/* 832098 80240898 00431021 */  addu      $v0, $v0, $v1
/* 83209C 8024089C 00021080 */  sll       $v0, $v0, 2
/* 8320A0 802408A0 00431023 */  subu      $v0, $v0, $v1
/* 8320A4 802408A4 000218C0 */  sll       $v1, $v0, 3
/* 8320A8 802408A8 00431021 */  addu      $v0, $v0, $v1
/* 8320AC 802408AC 8C830020 */  lw        $v1, 0x20($a0)
/* 8320B0 802408B0 000210C0 */  sll       $v0, $v0, 3
/* 8320B4 802408B4 8C630000 */  lw        $v1, ($v1)
/* 8320B8 802408B8 30630001 */  andi      $v1, $v1, 1
/* 8320BC 802408BC 10600004 */  beqz      $v1, .L802408D0
/* 8320C0 802408C0 00451021 */   addu     $v0, $v0, $a1
/* 8320C4 802408C4 C44C006C */  lwc1      $f12, 0x6c($v0)
/* 8320C8 802408C8 0C00A6C9 */  jal       clamp_angle
/* 8320CC 802408CC 46006307 */   neg.s    $f12, $f12
.L802408D0:
/* 8320D0 802408D0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8320D4 802408D4 03E00008 */  jr        $ra
/* 8320D8 802408D8 27BD0018 */   addiu    $sp, $sp, 0x18
