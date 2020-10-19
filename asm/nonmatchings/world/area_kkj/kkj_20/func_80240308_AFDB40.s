.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240308_AFDE48
/* AFDE48 80240308 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AFDE4C 8024030C AFB10014 */  sw        $s1, 0x14($sp)
/* AFDE50 80240310 0080882D */  daddu     $s1, $a0, $zero
/* AFDE54 80240314 AFBF0018 */  sw        $ra, 0x18($sp)
/* AFDE58 80240318 AFB00010 */  sw        $s0, 0x10($sp)
/* AFDE5C 8024031C 8E30000C */  lw        $s0, 0xc($s1)
/* AFDE60 80240320 8E050000 */  lw        $a1, ($s0)
/* AFDE64 80240324 0C0B1EAF */  jal       get_variable
/* AFDE68 80240328 26100004 */   addiu    $s0, $s0, 4
/* AFDE6C 8024032C 0220202D */  daddu     $a0, $s1, $zero
/* AFDE70 80240330 8E050000 */  lw        $a1, ($s0)
/* AFDE74 80240334 0C0B1EAF */  jal       get_variable
/* AFDE78 80240338 0040882D */   daddu    $s1, $v0, $zero
/* AFDE7C 8024033C 0000202D */  daddu     $a0, $zero, $zero
/* AFDE80 80240340 0080282D */  daddu     $a1, $a0, $zero
/* AFDE84 80240344 0040802D */  daddu     $s0, $v0, $zero
/* AFDE88 80240348 240600BE */  addiu     $a2, $zero, 0xbe
/* AFDE8C 8024034C 0C04DF93 */  jal       func_80137E4C
/* AFDE90 80240350 24070091 */   addiu    $a3, $zero, 0x91
/* AFDE94 80240354 44900000 */  mtc1      $s0, $f0
/* AFDE98 80240358 00000000 */  nop       
/* AFDE9C 8024035C 46800020 */  cvt.s.w   $f0, $f0
/* AFDEA0 80240360 44050000 */  mfc1      $a1, $f0
/* AFDEA4 80240364 0C04DF62 */  jal       func_80137D88
/* AFDEA8 80240368 322400FF */   andi     $a0, $s1, 0xff
/* AFDEAC 8024036C 8FBF0018 */  lw        $ra, 0x18($sp)
/* AFDEB0 80240370 8FB10014 */  lw        $s1, 0x14($sp)
/* AFDEB4 80240374 8FB00010 */  lw        $s0, 0x10($sp)
/* AFDEB8 80240378 24020002 */  addiu     $v0, $zero, 2
/* AFDEBC 8024037C 03E00008 */  jr        $ra
/* AFDEC0 80240380 27BD0020 */   addiu    $sp, $sp, 0x20
