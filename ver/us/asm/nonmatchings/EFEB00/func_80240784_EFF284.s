.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240784_EFF284
/* EFF284 80240784 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EFF288 80240788 AFBF0010 */  sw        $ra, 0x10($sp)
/* EFF28C 8024078C C4800084 */  lwc1      $f0, 0x84($a0)
/* EFF290 80240790 46800020 */  cvt.s.w   $f0, $f0
/* EFF294 80240794 44050000 */  mfc1      $a1, $f0
/* EFF298 80240798 0C051065 */  jal       func_80144194
/* EFF29C 8024079C 24040001 */   addiu    $a0, $zero, 1
/* EFF2A0 802407A0 8FBF0010 */  lw        $ra, 0x10($sp)
/* EFF2A4 802407A4 24020002 */  addiu     $v0, $zero, 2
/* EFF2A8 802407A8 03E00008 */  jr        $ra
/* EFF2AC 802407AC 27BD0018 */   addiu    $sp, $sp, 0x18
