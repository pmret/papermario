.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802425F0_9AA9E0
/* 9AA9E0 802425F0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9AA9E4 802425F4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9AA9E8 802425F8 0080982D */  daddu     $s3, $a0, $zero
/* 9AA9EC 802425FC AFBF0020 */  sw        $ra, 0x20($sp)
/* 9AA9F0 80242600 AFB20018 */  sw        $s2, 0x18($sp)
/* 9AA9F4 80242604 AFB10014 */  sw        $s1, 0x14($sp)
/* 9AA9F8 80242608 AFB00010 */  sw        $s0, 0x10($sp)
/* 9AA9FC 8024260C 8E720148 */  lw        $s2, 0x148($s3)
/* 9AAA00 80242610 86440008 */  lh        $a0, 8($s2)
/* 9AAA04 80242614 0C00EABB */  jal       get_npc_unsafe
/* 9AAA08 80242618 00A0882D */   daddu    $s1, $a1, $zero
/* 9AAA0C 8024261C 8E240008 */  lw        $a0, 8($s1)
/* 9AAA10 80242620 0040802D */  daddu     $s0, $v0, $zero
/* 9AAA14 80242624 00041FC2 */  srl       $v1, $a0, 0x1f
/* 9AAA18 80242628 00832021 */  addu      $a0, $a0, $v1
/* 9AAA1C 8024262C 00042043 */  sra       $a0, $a0, 1
/* 9AAA20 80242630 0C00A67F */  jal       rand_int
/* 9AAA24 80242634 24840001 */   addiu    $a0, $a0, 1
/* 9AAA28 80242638 8E230008 */  lw        $v1, 8($s1)
/* 9AAA2C 8024263C 240400B4 */  addiu     $a0, $zero, 0xb4
/* 9AAA30 80242640 00032FC2 */  srl       $a1, $v1, 0x1f
/* 9AAA34 80242644 00651821 */  addu      $v1, $v1, $a1
/* 9AAA38 80242648 00031843 */  sra       $v1, $v1, 1
/* 9AAA3C 8024264C 00621821 */  addu      $v1, $v1, $v0
/* 9AAA40 80242650 0C00A67F */  jal       rand_int
/* 9AAA44 80242654 A603008E */   sh       $v1, 0x8e($s0)
/* 9AAA48 80242658 C60C000C */  lwc1      $f12, 0xc($s0)
/* 9AAA4C 8024265C 44820000 */  mtc1      $v0, $f0
/* 9AAA50 80242660 00000000 */  nop       
/* 9AAA54 80242664 46800020 */  cvt.s.w   $f0, $f0
/* 9AAA58 80242668 46006300 */  add.s     $f12, $f12, $f0
/* 9AAA5C 8024266C 3C0142B4 */  lui       $at, 0x42b4
/* 9AAA60 80242670 44810000 */  mtc1      $at, $f0
/* 9AAA64 80242674 0C00A6C9 */  jal       clamp_angle
/* 9AAA68 80242678 46006301 */   sub.s    $f12, $f12, $f0
/* 9AAA6C 8024267C E600000C */  swc1      $f0, 0xc($s0)
/* 9AAA70 80242680 8E4200CC */  lw        $v0, 0xcc($s2)
/* 9AAA74 80242684 8C420000 */  lw        $v0, ($v0)
/* 9AAA78 80242688 AE020028 */  sw        $v0, 0x28($s0)
/* 9AAA7C 8024268C 24020003 */  addiu     $v0, $zero, 3
/* 9AAA80 80242690 AE620070 */  sw        $v0, 0x70($s3)
/* 9AAA84 80242694 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9AAA88 80242698 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9AAA8C 8024269C 8FB20018 */  lw        $s2, 0x18($sp)
/* 9AAA90 802426A0 8FB10014 */  lw        $s1, 0x14($sp)
/* 9AAA94 802426A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 9AAA98 802426A8 03E00008 */  jr        $ra
/* 9AAA9C 802426AC 27BD0028 */   addiu    $sp, $sp, 0x28
