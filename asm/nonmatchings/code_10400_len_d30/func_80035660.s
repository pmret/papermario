.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80035660
/* 10A60 80035660 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 10A64 80035664 AFBF0018 */  sw        $ra, 0x18($sp)
/* 10A68 80035668 3C01800A */  lui       $at, 0x800a
/* 10A6C 8003566C A0200931 */  sb        $zero, 0x931($at)
/* 10A70 80035670 3C01800A */  lui       $at, 0x800a
/* 10A74 80035674 A4200932 */  sh        $zero, 0x932($at)
/* 10A78 80035678 3C01800A */  lui       $at, 0x800a
/* 10A7C 8003567C A0200930 */  sb        $zero, 0x930($at)
/* 10A80 80035680 0C0912F1 */  jal       func_80244BC4
/* 10A84 80035684 00000000 */   nop      
/* 10A88 80035688 14400005 */  bnez      $v0, .L800356A0
/* 10A8C 8003568C 00000000 */   nop      
/* 10A90 80035690 0C04E0A8 */  jal       set_map_transition_effect
/* 10A94 80035694 24040007 */   addiu    $a0, $zero, 7
/* 10A98 80035698 0800D5B8 */  j         .L800356E0
/* 10A9C 8003569C 00000000 */   nop      
.L800356A0:
/* 10AA0 800356A0 0C04E0A8 */  jal       set_map_transition_effect
/* 10AA4 800356A4 24040008 */   addiu    $a0, $zero, 8
/* 10AA8 800356A8 3C06FFFE */  lui       $a2, 0xfffe
/* 10AAC 800356AC 34C6FFFF */  ori       $a2, $a2, 0xffff
/* 10AB0 800356B0 0000202D */  daddu     $a0, $zero, $zero
/* 10AB4 800356B4 3C05800A */  lui       $a1, 0x800a
/* 10AB8 800356B8 24A5A650 */  addiu     $a1, $a1, -0x59b0
/* 10ABC 800356BC 24030008 */  addiu     $v1, $zero, 8
/* 10AC0 800356C0 8CA20000 */  lw        $v0, ($a1)
/* 10AC4 800356C4 240703E8 */  addiu     $a3, $zero, 0x3e8
/* 10AC8 800356C8 AFA30010 */  sw        $v1, 0x10($sp)
/* 10ACC 800356CC 00461024 */  and       $v0, $v0, $a2
/* 10AD0 800356D0 ACA20000 */  sw        $v0, ($a1)
/* 10AD4 800356D4 2405FFFF */  addiu     $a1, $zero, -1
/* 10AD8 800356D8 0C052A46 */  jal       set_music_track
/* 10ADC 800356DC 0080302D */   daddu    $a2, $a0, $zero
.L800356E0:
/* 10AE0 800356E0 3C02800A */  lui       $v0, 0x800a
/* 10AE4 800356E4 2442A650 */  addiu     $v0, $v0, -0x59b0
/* 10AE8 800356E8 8C430000 */  lw        $v1, ($v0)
/* 10AEC 800356EC 2404FFBF */  addiu     $a0, $zero, -0x41
/* 10AF0 800356F0 00641824 */  and       $v1, $v1, $a0
/* 10AF4 800356F4 AC430000 */  sw        $v1, ($v0)
/* 10AF8 800356F8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 10AFC 800356FC 03E00008 */  jr        $ra
/* 10B00 80035700 27BD0020 */   addiu    $sp, $sp, 0x20
