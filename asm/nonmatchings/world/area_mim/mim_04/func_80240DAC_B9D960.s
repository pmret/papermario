.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DAC_B9E70C
/* B9E70C 80240DAC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B9E710 80240DB0 AFB00010 */  sw        $s0, 0x10($sp)
/* B9E714 80240DB4 0080802D */  daddu     $s0, $a0, $zero
/* B9E718 80240DB8 AFBF0014 */  sw        $ra, 0x14($sp)
/* B9E71C 80240DBC 8E020148 */  lw        $v0, 0x148($s0)
/* B9E720 80240DC0 0C00EABB */  jal       get_npc_unsafe
/* B9E724 80240DC4 84440008 */   lh       $a0, 8($v0)
/* B9E728 80240DC8 9443008E */  lhu       $v1, 0x8e($v0)
/* B9E72C 80240DCC 2463FFFF */  addiu     $v1, $v1, -1
/* B9E730 80240DD0 A443008E */  sh        $v1, 0x8e($v0)
/* B9E734 80240DD4 00031C00 */  sll       $v1, $v1, 0x10
/* B9E738 80240DD8 58600001 */  blezl     $v1, .L80240DE0
/* B9E73C 80240DDC AE000070 */   sw       $zero, 0x70($s0)
.L80240DE0:
/* B9E740 80240DE0 8FBF0014 */  lw        $ra, 0x14($sp)
/* B9E744 80240DE4 8FB00010 */  lw        $s0, 0x10($sp)
/* B9E748 80240DE8 03E00008 */  jr        $ra
/* B9E74C 80240DEC 27BD0018 */   addiu    $sp, $sp, 0x18
