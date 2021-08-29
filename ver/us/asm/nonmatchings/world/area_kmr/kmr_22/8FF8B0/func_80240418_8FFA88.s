.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240418_8FFA88
/* 8FFA88 80240418 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8FFA8C 8024041C AFB10014 */  sw        $s1, 0x14($sp)
/* 8FFA90 80240420 0080882D */  daddu     $s1, $a0, $zero
/* 8FFA94 80240424 AFBF0020 */  sw        $ra, 0x20($sp)
/* 8FFA98 80240428 AFB3001C */  sw        $s3, 0x1c($sp)
/* 8FFA9C 8024042C AFB20018 */  sw        $s2, 0x18($sp)
/* 8FFAA0 80240430 AFB00010 */  sw        $s0, 0x10($sp)
/* 8FFAA4 80240434 8E30000C */  lw        $s0, 0xc($s1)
/* 8FFAA8 80240438 8E050000 */  lw        $a1, ($s0)
/* 8FFAAC 8024043C 0C0B1EAF */  jal       evt_get_variable
/* 8FFAB0 80240440 26100004 */   addiu    $s0, $s0, 4
/* 8FFAB4 80240444 8E050000 */  lw        $a1, ($s0)
/* 8FFAB8 80240448 26100004 */  addiu     $s0, $s0, 4
/* 8FFABC 8024044C 0220202D */  daddu     $a0, $s1, $zero
/* 8FFAC0 80240450 0C0B1EAF */  jal       evt_get_variable
/* 8FFAC4 80240454 0040982D */   daddu    $s3, $v0, $zero
/* 8FFAC8 80240458 8E050000 */  lw        $a1, ($s0)
/* 8FFACC 8024045C 26100004 */  addiu     $s0, $s0, 4
/* 8FFAD0 80240460 0220202D */  daddu     $a0, $s1, $zero
/* 8FFAD4 80240464 0C0B1EAF */  jal       evt_get_variable
/* 8FFAD8 80240468 0040902D */   daddu    $s2, $v0, $zero
/* 8FFADC 8024046C 8E050000 */  lw        $a1, ($s0)
/* 8FFAE0 80240470 26100004 */  addiu     $s0, $s0, 4
/* 8FFAE4 80240474 0C0B1EAF */  jal       evt_get_variable
/* 8FFAE8 80240478 0220202D */   daddu    $a0, $s1, $zero
/* 8FFAEC 8024047C 8E050000 */  lw        $a1, ($s0)
/* 8FFAF0 80240480 0C0B1EAF */  jal       evt_get_variable
/* 8FFAF4 80240484 0220202D */   daddu    $a0, $s1, $zero
/* 8FFAF8 80240488 0000202D */  daddu     $a0, $zero, $zero
/* 8FFAFC 8024048C 3C05FD05 */  lui       $a1, 0xfd05
/* 8FFB00 80240490 34A50F80 */  ori       $a1, $a1, 0xf80
/* 8FFB04 80240494 0C0B1EAF */  jal       evt_get_variable
/* 8FFB08 80240498 0040802D */   daddu    $s0, $v0, $zero
/* 8FFB0C 8024049C 00131900 */  sll       $v1, $s3, 4
/* 8FFB10 802404A0 00731823 */  subu      $v1, $v1, $s3
/* 8FFB14 802404A4 00031940 */  sll       $v1, $v1, 5
/* 8FFB18 802404A8 00431821 */  addu      $v1, $v0, $v1
/* 8FFB1C 802404AC 24020002 */  addiu     $v0, $zero, 2
/* 8FFB20 802404B0 00529004 */  sllv      $s2, $s2, $v0
/* 8FFB24 802404B4 00721821 */  addu      $v1, $v1, $s2
/* 8FFB28 802404B8 44900000 */  mtc1      $s0, $f0
/* 8FFB2C 802404BC 00000000 */  nop
/* 8FFB30 802404C0 46800020 */  cvt.s.w   $f0, $f0
/* 8FFB34 802404C4 E460006C */  swc1      $f0, 0x6c($v1)
/* 8FFB38 802404C8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 8FFB3C 802404CC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 8FFB40 802404D0 8FB20018 */  lw        $s2, 0x18($sp)
/* 8FFB44 802404D4 8FB10014 */  lw        $s1, 0x14($sp)
/* 8FFB48 802404D8 8FB00010 */  lw        $s0, 0x10($sp)
/* 8FFB4C 802404DC 03E00008 */  jr        $ra
/* 8FFB50 802404E0 27BD0028 */   addiu    $sp, $sp, 0x28
