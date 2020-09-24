.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004A3E8
/* 257E8 8004A3E8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 257EC 8004A3EC AFB20018 */  sw        $s2, 0x18($sp)
/* 257F0 8004A3F0 0080902D */  daddu     $s2, $a0, $zero
/* 257F4 8004A3F4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 257F8 8004A3F8 AFB10014 */  sw        $s1, 0x14($sp)
/* 257FC 8004A3FC AFB00010 */  sw        $s0, 0x10($sp)
/* 25800 8004A400 8E510148 */  lw        $s1, 0x148($s2)
/* 25804 8004A404 0C00EABB */  jal       get_npc_unsafe
/* 25808 8004A408 86240008 */   lh       $a0, 8($s1)
/* 2580C 8004A40C 0040802D */  daddu     $s0, $v0, $zero
/* 25810 8004A410 9602008E */  lhu       $v0, 0x8e($s0)
/* 25814 8004A414 2442FFFF */  addiu     $v0, $v0, -1
/* 25818 8004A418 A602008E */  sh        $v0, 0x8e($s0)
/* 2581C 8004A41C 00021400 */  sll       $v0, $v0, 0x10
/* 25820 8004A420 14400010 */  bnez      $v0, .L8004A464
/* 25824 8004A424 00000000 */   nop      
/* 25828 8004A428 8E2200D0 */  lw        $v0, 0xd0($s1)
/* 2582C 8004A42C C60C0038 */  lwc1      $f12, 0x38($s0)
/* 25830 8004A430 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 25834 8004A434 C4420000 */  lwc1      $f2, ($v0)
/* 25838 8004A438 468010A0 */  cvt.s.w   $f2, $f2
/* 2583C 8004A43C 44061000 */  mfc1      $a2, $f2
/* 25840 8004A440 C4420008 */  lwc1      $f2, 8($v0)
/* 25844 8004A444 468010A0 */  cvt.s.w   $f2, $f2
/* 25848 8004A448 44071000 */  mfc1      $a3, $f2
/* 2584C 8004A44C 0C00A720 */  jal       atan2
/* 25850 8004A450 00000000 */   nop      
/* 25854 8004A454 0C00A6C9 */  jal       clamp_angle
/* 25858 8004A458 46000306 */   mov.s    $f12, $f0
/* 2585C 8004A45C E600000C */  swc1      $f0, 0xc($s0)
/* 25860 8004A460 AE400070 */  sw        $zero, 0x70($s2)
.L8004A464:
/* 25864 8004A464 8FBF001C */  lw        $ra, 0x1c($sp)
/* 25868 8004A468 8FB20018 */  lw        $s2, 0x18($sp)
/* 2586C 8004A46C 8FB10014 */  lw        $s1, 0x14($sp)
/* 25870 8004A470 8FB00010 */  lw        $s0, 0x10($sp)
/* 25874 8004A474 03E00008 */  jr        $ra
/* 25878 8004A478 27BD0020 */   addiu    $sp, $sp, 0x20
