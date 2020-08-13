.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetGoalPos
/* 199100 8026A820 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 199104 8026A824 AFB40020 */  sw    $s4, 0x20($sp)
/* 199108 8026A828 0080A02D */  daddu $s4, $a0, $zero
/* 19910C 8026A82C AFBF0024 */  sw    $ra, 0x24($sp)
/* 199110 8026A830 AFB3001C */  sw    $s3, 0x1c($sp)
/* 199114 8026A834 AFB20018 */  sw    $s2, 0x18($sp)
/* 199118 8026A838 AFB10014 */  sw    $s1, 0x14($sp)
/* 19911C 8026A83C AFB00010 */  sw    $s0, 0x10($sp)
/* 199120 8026A840 8E92000C */  lw    $s2, 0xc($s4)
/* 199124 8026A844 8E450000 */  lw    $a1, ($s2)
/* 199128 8026A848 0C0B1EAF */  jal   get_variable
/* 19912C 8026A84C 26520004 */   addiu $s2, $s2, 4
/* 199130 8026A850 0040202D */  daddu $a0, $v0, $zero
/* 199134 8026A854 2402FF81 */  addiu $v0, $zero, -0x7f
/* 199138 8026A858 14820002 */  bne   $a0, $v0, .L8026A864
/* 19913C 8026A85C 00000000 */   nop   
/* 199140 8026A860 8E840148 */  lw    $a0, 0x148($s4)
.L8026A864:
/* 199144 8026A864 0C09A75B */  jal   get_actor
/* 199148 8026A868 00000000 */   nop   
/* 19914C 8026A86C 8E450000 */  lw    $a1, ($s2)
/* 199150 8026A870 26520004 */  addiu $s2, $s2, 4
/* 199154 8026A874 C4400018 */  lwc1  $f0, 0x18($v0)
/* 199158 8026A878 C4420020 */  lwc1  $f2, 0x20($v0)
/* 19915C 8026A87C 8E500000 */  lw    $s0, ($s2)
/* 199160 8026A880 4600010D */  trunc.w.s $f4, $f0
/* 199164 8026A884 44062000 */  mfc1  $a2, $f4
/* 199168 8026A888 C440001C */  lwc1  $f0, 0x1c($v0)
/* 19916C 8026A88C 8E520004 */  lw    $s2, 4($s2)
/* 199170 8026A890 4600010D */  trunc.w.s $f4, $f0
/* 199174 8026A894 44112000 */  mfc1  $s1, $f4
/* 199178 8026A898 4600110D */  trunc.w.s $f4, $f2
/* 19917C 8026A89C 44132000 */  mfc1  $s3, $f4
/* 199180 8026A8A0 0C0B2026 */  jal   set_variable
/* 199184 8026A8A4 0280202D */   daddu $a0, $s4, $zero
/* 199188 8026A8A8 0280202D */  daddu $a0, $s4, $zero
/* 19918C 8026A8AC 0200282D */  daddu $a1, $s0, $zero
/* 199190 8026A8B0 0C0B2026 */  jal   set_variable
/* 199194 8026A8B4 0220302D */   daddu $a2, $s1, $zero
/* 199198 8026A8B8 0280202D */  daddu $a0, $s4, $zero
/* 19919C 8026A8BC 0240282D */  daddu $a1, $s2, $zero
/* 1991A0 8026A8C0 0C0B2026 */  jal   set_variable
/* 1991A4 8026A8C4 0260302D */   daddu $a2, $s3, $zero
/* 1991A8 8026A8C8 8FBF0024 */  lw    $ra, 0x24($sp)
/* 1991AC 8026A8CC 8FB40020 */  lw    $s4, 0x20($sp)
/* 1991B0 8026A8D0 8FB3001C */  lw    $s3, 0x1c($sp)
/* 1991B4 8026A8D4 8FB20018 */  lw    $s2, 0x18($sp)
/* 1991B8 8026A8D8 8FB10014 */  lw    $s1, 0x14($sp)
/* 1991BC 8026A8DC 8FB00010 */  lw    $s0, 0x10($sp)
/* 1991C0 8026A8E0 24020002 */  addiu $v0, $zero, 2
/* 1991C4 8026A8E4 03E00008 */  jr    $ra
/* 1991C8 8026A8E8 27BD0028 */   addiu $sp, $sp, 0x28

