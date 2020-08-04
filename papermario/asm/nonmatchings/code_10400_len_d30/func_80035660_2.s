.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80035660_2
/* 010A60 80035660 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 010A64 80035664 AFBF0018 */  sw    $ra, 0x18($sp)
/* 010A68 80035668 3C01800A */  lui   $at, 0x800a
/* 010A6C 8003566C A0200931 */  sb    $zero, 0x931($at)
/* 010A70 80035670 3C01800A */  lui   $at, 0x800a
/* 010A74 80035674 A4200932 */  sh    $zero, 0x932($at)
/* 010A78 80035678 3C01800A */  lui   $at, 0x800a
/* 010A7C 8003567C A0200930 */  sb    $zero, 0x930($at)
/* 010A80 80035680 0C0912F1 */  jal   func_80244BC4
/* 010A84 80035684 00000000 */   nop   
/* 010A88 80035688 14400005 */  bnez  $v0, .L800356A0
/* 010A8C 8003568C 00000000 */   nop   
/* 010A90 80035690 0C04E0A8 */  jal   set_map_transition_effect
/* 010A94 80035694 24040007 */   addiu $a0, $zero, 7
/* 010A98 80035698 0800D5B8 */  j     .L800356E0
/* 010A9C 8003569C 00000000 */   nop   

.L800356A0:
/* 010AA0 800356A0 0C04E0A8 */  jal   set_map_transition_effect
/* 010AA4 800356A4 24040008 */   addiu $a0, $zero, 8
/* 010AA8 800356A8 3C06FFFE */  lui   $a2, 0xfffe
/* 010AAC 800356AC 34C6FFFF */  ori   $a2, $a2, 0xffff
/* 010AB0 800356B0 0000202D */  daddu $a0, $zero, $zero
/* 010AB4 800356B4 3C05800A */  lui   $a1, 0x800a
/* 010AB8 800356B8 24A5A650 */  addiu $a1, $a1, -0x59b0
/* 010ABC 800356BC 24030008 */  addiu $v1, $zero, 8
/* 010AC0 800356C0 8CA20000 */  lw    $v0, ($a1)
/* 010AC4 800356C4 240703E8 */  addiu $a3, $zero, 0x3e8
/* 010AC8 800356C8 AFA30010 */  sw    $v1, 0x10($sp)
/* 010ACC 800356CC 00461024 */  and   $v0, $v0, $a2
/* 010AD0 800356D0 ACA20000 */  sw    $v0, ($a1)
/* 010AD4 800356D4 2405FFFF */  addiu $a1, $zero, -1
/* 010AD8 800356D8 0C052A46 */  jal   set_music_track
/* 010ADC 800356DC 0080302D */   daddu $a2, $a0, $zero
.L800356E0:
/* 010AE0 800356E0 3C02800A */  lui   $v0, 0x800a
/* 010AE4 800356E4 2442A650 */  addiu $v0, $v0, -0x59b0
/* 010AE8 800356E8 8C430000 */  lw    $v1, ($v0)
/* 010AEC 800356EC 2404FFBF */  addiu $a0, $zero, -0x41
/* 010AF0 800356F0 00641824 */  and   $v1, $v1, $a0
/* 010AF4 800356F4 AC430000 */  sw    $v1, ($v0)
/* 010AF8 800356F8 8FBF0018 */  lw    $ra, 0x18($sp)
/* 010AFC 800356FC 03E00008 */  jr    $ra
/* 010B00 80035700 27BD0020 */   addiu $sp, $sp, 0x20

