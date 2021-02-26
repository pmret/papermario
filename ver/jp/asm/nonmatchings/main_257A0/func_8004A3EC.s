.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004A3EC
/* 257EC 8004A3EC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 257F0 8004A3F0 AFB10014 */  sw        $s1, 0x14($sp)
/* 257F4 8004A3F4 0080882D */  daddu     $s1, $a0, $zero
/* 257F8 8004A3F8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 257FC 8004A3FC AFB00010 */  sw        $s0, 0x10($sp)
/* 25800 8004A400 8E300148 */  lw        $s0, 0x148($s1)
/* 25804 8004A404 0C00E9EB */  jal       func_8003A7AC
/* 25808 8004A408 86040008 */   lh       $a0, 8($s0)
/* 2580C 8004A40C 820200B4 */  lb        $v0, 0xb4($s0)
/* 25810 8004A410 14400003 */  bnez      $v0, .L8004A420
/* 25814 8004A414 00000000 */   nop
/* 25818 8004A418 8E220074 */  lw        $v0, 0x74($s1)
/* 2581C 8004A41C AE220070 */  sw        $v0, 0x70($s1)
.L8004A420:
/* 25820 8004A420 8FBF0018 */  lw        $ra, 0x18($sp)
/* 25824 8004A424 8FB10014 */  lw        $s1, 0x14($sp)
/* 25828 8004A428 8FB00010 */  lw        $s0, 0x10($sp)
/* 2582C 8004A42C 03E00008 */  jr        $ra
/* 25830 8004A430 27BD0020 */   addiu    $sp, $sp, 0x20
