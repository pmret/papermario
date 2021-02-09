.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802430B8_8B3128
/* 8B3128 802430B8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8B312C 802430BC AFB10014 */  sw        $s1, 0x14($sp)
/* 8B3130 802430C0 0080882D */  daddu     $s1, $a0, $zero
/* 8B3134 802430C4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8B3138 802430C8 AFB00010 */  sw        $s0, 0x10($sp)
/* 8B313C 802430CC 8E30000C */  lw        $s0, 0xc($s1)
/* 8B3140 802430D0 8E050000 */  lw        $a1, ($s0)
/* 8B3144 802430D4 0C0B1EAF */  jal       get_variable
/* 8B3148 802430D8 26100004 */   addiu    $s0, $s0, 4
/* 8B314C 802430DC 0220202D */  daddu     $a0, $s1, $zero
/* 8B3150 802430E0 8E050000 */  lw        $a1, ($s0)
/* 8B3154 802430E4 0C0B1EAF */  jal       get_variable
/* 8B3158 802430E8 0040882D */   daddu    $s1, $v0, $zero
/* 8B315C 802430EC 0000202D */  daddu     $a0, $zero, $zero
/* 8B3160 802430F0 0080282D */  daddu     $a1, $a0, $zero
/* 8B3164 802430F4 0040802D */  daddu     $s0, $v0, $zero
/* 8B3168 802430F8 240600BE */  addiu     $a2, $zero, 0xbe
/* 8B316C 802430FC 0C04DF93 */  jal       set_transition_stencil_center
/* 8B3170 80243100 24070091 */   addiu    $a3, $zero, 0x91
/* 8B3174 80243104 44900000 */  mtc1      $s0, $f0
/* 8B3178 80243108 00000000 */  nop
/* 8B317C 8024310C 46800020 */  cvt.s.w   $f0, $f0
/* 8B3180 80243110 44050000 */  mfc1      $a1, $f0
/* 8B3184 80243114 0C04DF62 */  jal       set_transition_stencil_zoom_0
/* 8B3188 80243118 322400FF */   andi     $a0, $s1, 0xff
/* 8B318C 8024311C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8B3190 80243120 8FB10014 */  lw        $s1, 0x14($sp)
/* 8B3194 80243124 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B3198 80243128 24020002 */  addiu     $v0, $zero, 2
/* 8B319C 8024312C 03E00008 */  jr        $ra
/* 8B31A0 80243130 27BD0020 */   addiu    $sp, $sp, 0x20
