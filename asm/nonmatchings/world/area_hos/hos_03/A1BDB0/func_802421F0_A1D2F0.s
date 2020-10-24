.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802421F0_A1D2F0
/* A1D2F0 802421F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A1D2F4 802421F4 AFB10014 */  sw        $s1, 0x14($sp)
/* A1D2F8 802421F8 0080882D */  daddu     $s1, $a0, $zero
/* A1D2FC 802421FC AFBF0018 */  sw        $ra, 0x18($sp)
/* A1D300 80242200 AFB00010 */  sw        $s0, 0x10($sp)
/* A1D304 80242204 8E30000C */  lw        $s0, 0xc($s1)
/* A1D308 80242208 8E050000 */  lw        $a1, ($s0)
/* A1D30C 8024220C 0C0B1EAF */  jal       get_variable
/* A1D310 80242210 26100004 */   addiu    $s0, $s0, 4
/* A1D314 80242214 0220202D */  daddu     $a0, $s1, $zero
/* A1D318 80242218 8E050000 */  lw        $a1, ($s0)
/* A1D31C 8024221C 0C0B1EAF */  jal       get_variable
/* A1D320 80242220 0040882D */   daddu    $s1, $v0, $zero
/* A1D324 80242224 0000202D */  daddu     $a0, $zero, $zero
/* A1D328 80242228 0080282D */  daddu     $a1, $a0, $zero
/* A1D32C 8024222C 0040802D */  daddu     $s0, $v0, $zero
/* A1D330 80242230 240600BE */  addiu     $a2, $zero, 0xbe
/* A1D334 80242234 0C04DF93 */  jal       func_80137E4C
/* A1D338 80242238 24070091 */   addiu    $a3, $zero, 0x91
/* A1D33C 8024223C 44900000 */  mtc1      $s0, $f0
/* A1D340 80242240 00000000 */  nop       
/* A1D344 80242244 46800020 */  cvt.s.w   $f0, $f0
/* A1D348 80242248 44050000 */  mfc1      $a1, $f0
/* A1D34C 8024224C 0C04DF62 */  jal       func_80137D88
/* A1D350 80242250 322400FF */   andi     $a0, $s1, 0xff
/* A1D354 80242254 8FBF0018 */  lw        $ra, 0x18($sp)
/* A1D358 80242258 8FB10014 */  lw        $s1, 0x14($sp)
/* A1D35C 8024225C 8FB00010 */  lw        $s0, 0x10($sp)
/* A1D360 80242260 24020002 */  addiu     $v0, $zero, 2
/* A1D364 80242264 03E00008 */  jr        $ra
/* A1D368 80242268 27BD0020 */   addiu    $sp, $sp, 0x20
