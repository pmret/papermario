.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024183C_95CA3C
/* 95CA3C 8024183C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 95CA40 80241840 3C03800A */  lui       $v1, %hi(gCurrentCamID)
/* 95CA44 80241844 8463A634 */  lh        $v1, %lo(gCurrentCamID)($v1)
/* 95CA48 80241848 3C05800B */  lui       $a1, %hi(gCameras)
/* 95CA4C 8024184C 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* 95CA50 80241850 AFBF0010 */  sw        $ra, 0x10($sp)
/* 95CA54 80241854 00031080 */  sll       $v0, $v1, 2
/* 95CA58 80241858 00431021 */  addu      $v0, $v0, $v1
/* 95CA5C 8024185C 00021080 */  sll       $v0, $v0, 2
/* 95CA60 80241860 00431023 */  subu      $v0, $v0, $v1
/* 95CA64 80241864 000218C0 */  sll       $v1, $v0, 3
/* 95CA68 80241868 00431021 */  addu      $v0, $v0, $v1
/* 95CA6C 8024186C 8C830020 */  lw        $v1, 0x20($a0)
/* 95CA70 80241870 000210C0 */  sll       $v0, $v0, 3
/* 95CA74 80241874 8C630000 */  lw        $v1, ($v1)
/* 95CA78 80241878 30630001 */  andi      $v1, $v1, 1
/* 95CA7C 8024187C 10600004 */  beqz      $v1, .L80241890
/* 95CA80 80241880 00451021 */   addu     $v0, $v0, $a1
/* 95CA84 80241884 C44C006C */  lwc1      $f12, 0x6c($v0)
/* 95CA88 80241888 0C00A6C9 */  jal       clamp_angle
/* 95CA8C 8024188C 46006307 */   neg.s    $f12, $f12
.L80241890:
/* 95CA90 80241890 8FBF0010 */  lw        $ra, 0x10($sp)
/* 95CA94 80241894 03E00008 */  jr        $ra
/* 95CA98 80241898 27BD0018 */   addiu    $sp, $sp, 0x18
