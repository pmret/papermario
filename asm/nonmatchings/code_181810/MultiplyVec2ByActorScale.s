.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel MultiplyVec2ByActorScale
/* 182928 80254048 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 18292C 8025404C AFB00010 */  sw        $s0, 0x10($sp)
/* 182930 80254050 0080802D */  daddu     $s0, $a0, $zero
/* 182934 80254054 AFBF001C */  sw        $ra, 0x1c($sp)
/* 182938 80254058 AFB20018 */  sw        $s2, 0x18($sp)
/* 18293C 8025405C AFB10014 */  sw        $s1, 0x14($sp)
/* 182940 80254060 8E040148 */  lw        $a0, 0x148($s0)
/* 182944 80254064 0C09A75B */  jal       get_actor
/* 182948 80254068 8E11000C */   lw       $s1, 0xc($s0)
/* 18294C 8025406C 0200202D */  daddu     $a0, $s0, $zero
/* 182950 80254070 8E250000 */  lw        $a1, ($s1)
/* 182954 80254074 0C0B210B */  jal       get_float_variable
/* 182958 80254078 0040902D */   daddu    $s2, $v0, $zero
/* 18295C 8025407C C6420188 */  lwc1      $f2, 0x188($s2)
/* 182960 80254080 46020002 */  mul.s     $f0, $f0, $f2
/* 182964 80254084 00000000 */  nop       
/* 182968 80254088 8E250000 */  lw        $a1, ($s1)
/* 18296C 8025408C 44060000 */  mfc1      $a2, $f0
/* 182970 80254090 0C0B2190 */  jal       set_float_variable
/* 182974 80254094 0200202D */   daddu    $a0, $s0, $zero
/* 182978 80254098 8E250004 */  lw        $a1, 4($s1)
/* 18297C 8025409C 0C0B210B */  jal       get_float_variable
/* 182980 802540A0 0200202D */   daddu    $a0, $s0, $zero
/* 182984 802540A4 C6420188 */  lwc1      $f2, 0x188($s2)
/* 182988 802540A8 46020002 */  mul.s     $f0, $f0, $f2
/* 18298C 802540AC 00000000 */  nop       
/* 182990 802540B0 8E250004 */  lw        $a1, 4($s1)
/* 182994 802540B4 44060000 */  mfc1      $a2, $f0
/* 182998 802540B8 0C0B2190 */  jal       set_float_variable
/* 18299C 802540BC 0200202D */   daddu    $a0, $s0, $zero
/* 1829A0 802540C0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 1829A4 802540C4 8FB20018 */  lw        $s2, 0x18($sp)
/* 1829A8 802540C8 8FB10014 */  lw        $s1, 0x14($sp)
/* 1829AC 802540CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 1829B0 802540D0 24020002 */  addiu     $v0, $zero, 2
/* 1829B4 802540D4 03E00008 */  jr        $ra
/* 1829B8 802540D8 27BD0020 */   addiu    $sp, $sp, 0x20
