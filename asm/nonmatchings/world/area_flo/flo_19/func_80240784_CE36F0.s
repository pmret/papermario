.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240784_CE3E74
/* CE3E74 80240784 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CE3E78 80240788 AFBF0010 */  sw        $ra, 0x10($sp)
/* CE3E7C 8024078C C4800084 */  lwc1      $f0, 0x84($a0)
/* CE3E80 80240790 46800020 */  cvt.s.w   $f0, $f0
/* CE3E84 80240794 44050000 */  mfc1      $a1, $f0
/* CE3E88 80240798 0C04DF69 */  jal       func_80137DA4
/* CE3E8C 8024079C 24040001 */   addiu    $a0, $zero, 1
/* CE3E90 802407A0 8FBF0010 */  lw        $ra, 0x10($sp)
/* CE3E94 802407A4 24020002 */  addiu     $v0, $zero, 2
/* CE3E98 802407A8 03E00008 */  jr        $ra
/* CE3E9C 802407AC 27BD0018 */   addiu    $sp, $sp, 0x18
