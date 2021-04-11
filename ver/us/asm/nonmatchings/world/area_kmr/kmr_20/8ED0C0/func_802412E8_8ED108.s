.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kmr_20_UnkFunc32
/* 8ED108 802412E8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8ED10C 802412EC AFB10014 */  sw        $s1, 0x14($sp)
/* 8ED110 802412F0 0080882D */  daddu     $s1, $a0, $zero
/* 8ED114 802412F4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8ED118 802412F8 AFB00010 */  sw        $s0, 0x10($sp)
/* 8ED11C 802412FC 8E30000C */  lw        $s0, 0xc($s1)
/* 8ED120 80241300 8E050000 */  lw        $a1, ($s0)
/* 8ED124 80241304 0C0B1EAF */  jal       get_variable
/* 8ED128 80241308 26100004 */   addiu    $s0, $s0, 4
/* 8ED12C 8024130C 0220202D */  daddu     $a0, $s1, $zero
/* 8ED130 80241310 8E050000 */  lw        $a1, ($s0)
/* 8ED134 80241314 0C0B1EAF */  jal       get_variable
/* 8ED138 80241318 0040882D */   daddu    $s1, $v0, $zero
/* 8ED13C 8024131C 0000202D */  daddu     $a0, $zero, $zero
/* 8ED140 80241320 0080282D */  daddu     $a1, $a0, $zero
/* 8ED144 80241324 0040802D */  daddu     $s0, $v0, $zero
/* 8ED148 80241328 240600BE */  addiu     $a2, $zero, 0xbe
/* 8ED14C 8024132C 0C04DF93 */  jal       set_transition_stencil_center
/* 8ED150 80241330 24070091 */   addiu    $a3, $zero, 0x91
/* 8ED154 80241334 44900000 */  mtc1      $s0, $f0
/* 8ED158 80241338 00000000 */  nop
/* 8ED15C 8024133C 46800020 */  cvt.s.w   $f0, $f0
/* 8ED160 80241340 44050000 */  mfc1      $a1, $f0
/* 8ED164 80241344 0C04DF62 */  jal       set_transition_stencil_zoom_0
/* 8ED168 80241348 322400FF */   andi     $a0, $s1, 0xff
/* 8ED16C 8024134C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8ED170 80241350 8FB10014 */  lw        $s1, 0x14($sp)
/* 8ED174 80241354 8FB00010 */  lw        $s0, 0x10($sp)
/* 8ED178 80241358 24020002 */  addiu     $v0, $zero, 2
/* 8ED17C 8024135C 03E00008 */  jr        $ra
/* 8ED180 80241360 27BD0020 */   addiu    $sp, $sp, 0x20
