.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241518
/* BD0108 80241518 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BD010C 8024151C AFB00010 */  sw        $s0, 0x10($sp)
/* BD0110 80241520 0080802D */  daddu     $s0, $a0, $zero
/* BD0114 80241524 AFBF0018 */  sw        $ra, 0x18($sp)
/* BD0118 80241528 0C090150 */  jal       func_80240540
/* BD011C 8024152C AFB10014 */   sw       $s1, 0x14($sp)
/* BD0120 80241530 0200202D */  daddu     $a0, $s0, $zero
/* BD0124 80241534 3C05FE36 */  lui       $a1, 0xfe36
/* BD0128 80241538 34A53C80 */  ori       $a1, $a1, 0x3c80
/* BD012C 8024153C 0C0B210B */  jal       get_float_variable
/* BD0130 80241540 0040882D */   daddu    $s1, $v0, $zero
/* BD0134 80241544 0C00A6C9 */  jal       clamp_angle
/* BD0138 80241548 46000306 */   mov.s    $f12, $f0
/* BD013C 8024154C 0200202D */  daddu     $a0, $s0, $zero
/* BD0140 80241550 3C05FE36 */  lui       $a1, 0xfe36
/* BD0144 80241554 44060000 */  mfc1      $a2, $f0
/* BD0148 80241558 34A53C80 */  ori       $a1, $a1, 0x3c80
/* BD014C 8024155C 0C0B2190 */  jal       set_float_variable
/* BD0150 80241560 AE2601CC */   sw       $a2, 0x1cc($s1)
/* BD0154 80241564 8FBF0018 */  lw        $ra, 0x18($sp)
/* BD0158 80241568 8FB10014 */  lw        $s1, 0x14($sp)
/* BD015C 8024156C 8FB00010 */  lw        $s0, 0x10($sp)
/* BD0160 80241570 24020002 */  addiu     $v0, $zero, 2
/* BD0164 80241574 03E00008 */  jr        $ra
/* BD0168 80241578 27BD0020 */   addiu    $sp, $sp, 0x20
