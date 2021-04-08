.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80033504
/* E904 80033504 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E908 80033508 AFB00010 */  sw        $s0, 0x10($sp)
/* E90C 8003350C 3C108007 */  lui       $s0, %hi(D_8007417C)
/* E910 80033510 2610417C */  addiu     $s0, $s0, %lo(D_8007417C)
/* E914 80033514 AFBF0014 */  sw        $ra, 0x14($sp)
/* E918 80033518 8E020000 */  lw        $v0, ($s0)
/* E91C 8003351C 844200B6 */  lh        $v0, 0xb6($v0)
/* E920 80033520 44820000 */  mtc1      $v0, $f0
/* E924 80033524 00000000 */  nop
/* E928 80033528 46800020 */  cvt.s.w   $f0, $f0
/* E92C 8003352C 44050000 */  mfc1      $a1, $f0
/* E930 80033530 0C04F38E */  jal       func_8013CE38
/* E934 80033534 0000202D */   daddu    $a0, $zero, $zero
/* E938 80033538 8E020000 */  lw        $v0, ($s0)
/* E93C 8003353C 904500B9 */  lbu       $a1, 0xb9($v0)
/* E940 80033540 904600BB */  lbu       $a2, 0xbb($v0)
/* E944 80033544 904700BD */  lbu       $a3, 0xbd($v0)
/* E948 80033548 0C04F3B0 */  jal       func_8013CEC0
/* E94C 8003354C 0000202D */   daddu    $a0, $zero, $zero
/* E950 80033550 8FBF0014 */  lw        $ra, 0x14($sp)
/* E954 80033554 8FB00010 */  lw        $s0, 0x10($sp)
/* E958 80033558 03E00008 */  jr        $ra
/* E95C 8003355C 27BD0018 */   addiu    $sp, $sp, 0x18
