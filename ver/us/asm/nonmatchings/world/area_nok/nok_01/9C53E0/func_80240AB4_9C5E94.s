.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AB4_9C5E94
/* 9C5E94 80240AB4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9C5E98 80240AB8 AFB10014 */  sw        $s1, 0x14($sp)
/* 9C5E9C 80240ABC 0080882D */  daddu     $s1, $a0, $zero
/* 9C5EA0 80240AC0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9C5EA4 80240AC4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9C5EA8 80240AC8 8E30000C */  lw        $s0, 0xc($s1)
/* 9C5EAC 80240ACC 8E050000 */  lw        $a1, ($s0)
/* 9C5EB0 80240AD0 0C0B1EAF */  jal       get_variable
/* 9C5EB4 80240AD4 26100004 */   addiu    $s0, $s0, 4
/* 9C5EB8 80240AD8 0220202D */  daddu     $a0, $s1, $zero
/* 9C5EBC 80240ADC 8E050000 */  lw        $a1, ($s0)
/* 9C5EC0 80240AE0 0C0B1EAF */  jal       get_variable
/* 9C5EC4 80240AE4 0040882D */   daddu    $s1, $v0, $zero
/* 9C5EC8 80240AE8 0000202D */  daddu     $a0, $zero, $zero
/* 9C5ECC 80240AEC 0080282D */  daddu     $a1, $a0, $zero
/* 9C5ED0 80240AF0 0040802D */  daddu     $s0, $v0, $zero
/* 9C5ED4 80240AF4 240600BE */  addiu     $a2, $zero, 0xbe
/* 9C5ED8 80240AF8 0C04DF93 */  jal       set_transition_stencil_center
/* 9C5EDC 80240AFC 24070091 */   addiu    $a3, $zero, 0x91
/* 9C5EE0 80240B00 44900000 */  mtc1      $s0, $f0
/* 9C5EE4 80240B04 00000000 */  nop
/* 9C5EE8 80240B08 46800020 */  cvt.s.w   $f0, $f0
/* 9C5EEC 80240B0C 44050000 */  mfc1      $a1, $f0
/* 9C5EF0 80240B10 0C04DF62 */  jal       set_transition_stencil_zoom_0
/* 9C5EF4 80240B14 322400FF */   andi     $a0, $s1, 0xff
/* 9C5EF8 80240B18 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9C5EFC 80240B1C 8FB10014 */  lw        $s1, 0x14($sp)
/* 9C5F00 80240B20 8FB00010 */  lw        $s0, 0x10($sp)
/* 9C5F04 80240B24 24020002 */  addiu     $v0, $zero, 2
/* 9C5F08 80240B28 03E00008 */  jr        $ra
/* 9C5F0C 80240B2C 27BD0020 */   addiu    $sp, $sp, 0x20
