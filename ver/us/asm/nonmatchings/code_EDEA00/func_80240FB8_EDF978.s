.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FB8_EDF978
/* EDF978 80240FB8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EDF97C 80240FBC AFB00010 */  sw        $s0, 0x10($sp)
/* EDF980 80240FC0 0080802D */  daddu     $s0, $a0, $zero
/* EDF984 80240FC4 AFBF0014 */  sw        $ra, 0x14($sp)
/* EDF988 80240FC8 8E020148 */  lw        $v0, 0x148($s0)
/* EDF98C 80240FCC 0C00F92F */  jal       func_8003E4BC
/* EDF990 80240FD0 84440008 */   lh       $a0, 8($v0)
/* EDF994 80240FD4 0040202D */  daddu     $a0, $v0, $zero
/* EDF998 80240FD8 8482008E */  lh        $v0, 0x8e($a0)
/* EDF99C 80240FDC 9483008E */  lhu       $v1, 0x8e($a0)
/* EDF9A0 80240FE0 18400005 */  blez      $v0, .L80240FF8
/* EDF9A4 80240FE4 2462FFFF */   addiu    $v0, $v1, -1
/* EDF9A8 80240FE8 A482008E */  sh        $v0, 0x8e($a0)
/* EDF9AC 80240FEC 00021400 */  sll       $v0, $v0, 0x10
/* EDF9B0 80240FF0 1C400006 */  bgtz      $v0, .L8024100C
/* EDF9B4 80240FF4 00000000 */   nop
.L80240FF8:
/* EDF9B8 80240FF8 8482008C */  lh        $v0, 0x8c($a0)
/* EDF9BC 80240FFC 14400003 */  bnez      $v0, .L8024100C
/* EDF9C0 80241000 2402000E */   addiu    $v0, $zero, 0xe
/* EDF9C4 80241004 A480008E */  sh        $zero, 0x8e($a0)
/* EDF9C8 80241008 AE020070 */  sw        $v0, 0x70($s0)
.L8024100C:
/* EDF9CC 8024100C 8FBF0014 */  lw        $ra, 0x14($sp)
/* EDF9D0 80241010 8FB00010 */  lw        $s0, 0x10($sp)
/* EDF9D4 80241014 03E00008 */  jr        $ra
/* EDF9D8 80241018 27BD0018 */   addiu    $sp, $sp, 0x18
