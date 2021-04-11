.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kpa_95_UnkFunc32
/* A8E0D0 80241650 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A8E0D4 80241654 AFB10014 */  sw        $s1, 0x14($sp)
/* A8E0D8 80241658 0080882D */  daddu     $s1, $a0, $zero
/* A8E0DC 8024165C AFBF0018 */  sw        $ra, 0x18($sp)
/* A8E0E0 80241660 AFB00010 */  sw        $s0, 0x10($sp)
/* A8E0E4 80241664 8E30000C */  lw        $s0, 0xc($s1)
/* A8E0E8 80241668 8E050000 */  lw        $a1, ($s0)
/* A8E0EC 8024166C 0C0B1EAF */  jal       get_variable
/* A8E0F0 80241670 26100004 */   addiu    $s0, $s0, 4
/* A8E0F4 80241674 0220202D */  daddu     $a0, $s1, $zero
/* A8E0F8 80241678 8E050000 */  lw        $a1, ($s0)
/* A8E0FC 8024167C 0C0B1EAF */  jal       get_variable
/* A8E100 80241680 0040882D */   daddu    $s1, $v0, $zero
/* A8E104 80241684 0000202D */  daddu     $a0, $zero, $zero
/* A8E108 80241688 0080282D */  daddu     $a1, $a0, $zero
/* A8E10C 8024168C 0040802D */  daddu     $s0, $v0, $zero
/* A8E110 80241690 240600BE */  addiu     $a2, $zero, 0xbe
/* A8E114 80241694 0C04DF93 */  jal       set_transition_stencil_center
/* A8E118 80241698 24070091 */   addiu    $a3, $zero, 0x91
/* A8E11C 8024169C 44900000 */  mtc1      $s0, $f0
/* A8E120 802416A0 00000000 */  nop
/* A8E124 802416A4 46800020 */  cvt.s.w   $f0, $f0
/* A8E128 802416A8 44050000 */  mfc1      $a1, $f0
/* A8E12C 802416AC 0C04DF62 */  jal       set_transition_stencil_zoom_0
/* A8E130 802416B0 322400FF */   andi     $a0, $s1, 0xff
/* A8E134 802416B4 8FBF0018 */  lw        $ra, 0x18($sp)
/* A8E138 802416B8 8FB10014 */  lw        $s1, 0x14($sp)
/* A8E13C 802416BC 8FB00010 */  lw        $s0, 0x10($sp)
/* A8E140 802416C0 24020002 */  addiu     $v0, $zero, 2
/* A8E144 802416C4 03E00008 */  jr        $ra
/* A8E148 802416C8 27BD0020 */   addiu    $sp, $sp, 0x20
