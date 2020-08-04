.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel PlaySoundAtActor
/* 18213C 8025385C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 182140 80253860 AFB1001C */  sw    $s1, 0x1c($sp)
/* 182144 80253864 0080882D */  daddu $s1, $a0, $zero
/* 182148 80253868 AFBF0020 */  sw    $ra, 0x20($sp)
/* 18214C 8025386C AFB00018 */  sw    $s0, 0x18($sp)
/* 182150 80253870 8E30000C */  lw    $s0, 0xc($s1)
/* 182154 80253874 8E050000 */  lw    $a1, ($s0)
/* 182158 80253878 0C0B1EAF */  jal   get_variable
/* 18215C 8025387C 26100004 */   addiu $s0, $s0, 4
/* 182160 80253880 0040202D */  daddu $a0, $v0, $zero
/* 182164 80253884 2402FF81 */  addiu $v0, $zero, -0x7f
/* 182168 80253888 14820002 */  bne   $a0, $v0, .L80253894
/* 18216C 8025388C 8E100000 */   lw    $s0, ($s0)
/* 182170 80253890 8E240148 */  lw    $a0, 0x148($s1)
.L80253894:
/* 182174 80253894 0C09A75B */  jal   get_actor
/* 182178 80253898 00000000 */   nop   
/* 18217C 8025389C C440014C */  lwc1  $f0, 0x14c($v0)
/* 182180 802538A0 0200202D */  daddu $a0, $s0, $zero
/* 182184 802538A4 E7A00010 */  swc1  $f0, 0x10($sp)
/* 182188 802538A8 8C460144 */  lw    $a2, 0x144($v0)
/* 18218C 802538AC 8C470148 */  lw    $a3, 0x148($v0)
/* 182190 802538B0 0C052757 */  jal   play_sound_at_position
/* 182194 802538B4 0000282D */   daddu $a1, $zero, $zero
/* 182198 802538B8 8FBF0020 */  lw    $ra, 0x20($sp)
/* 18219C 802538BC 8FB1001C */  lw    $s1, 0x1c($sp)
/* 1821A0 802538C0 8FB00018 */  lw    $s0, 0x18($sp)
/* 1821A4 802538C4 24020002 */  addiu $v0, $zero, 2
/* 1821A8 802538C8 03E00008 */  jr    $ra
/* 1821AC 802538CC 27BD0028 */   addiu $sp, $sp, 0x28

