.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel BindTakeTurn
/* 1A7210 80278930 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1A7214 80278934 AFB20018 */  sw    $s2, 0x18($sp)
/* 1A7218 80278938 0080902D */  daddu $s2, $a0, $zero
/* 1A721C 8027893C AFBF001C */  sw    $ra, 0x1c($sp)
/* 1A7220 80278940 AFB10014 */  sw    $s1, 0x14($sp)
/* 1A7224 80278944 AFB00010 */  sw    $s0, 0x10($sp)
/* 1A7228 80278948 8E51000C */  lw    $s1, 0xc($s2)
/* 1A722C 8027894C 8E250000 */  lw    $a1, ($s1)
/* 1A7230 80278950 0C0B1EAF */  jal   get_variable
/* 1A7234 80278954 26310004 */   addiu $s1, $s1, 4
/* 1A7238 80278958 0040802D */  daddu $s0, $v0, $zero
/* 1A723C 8027895C 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1A7240 80278960 16020002 */  bne   $s0, $v0, .L8027896C
/* 1A7244 80278964 00000000 */   nop   
/* 1A7248 80278968 8E500148 */  lw    $s0, 0x148($s2)
.L8027896C:
/* 1A724C 8027896C 8E250000 */  lw    $a1, ($s1)
/* 1A7250 80278970 0C0B1EAF */  jal   get_variable
/* 1A7254 80278974 0240202D */   daddu $a0, $s2, $zero
/* 1A7258 80278978 0200202D */  daddu $a0, $s0, $zero
/* 1A725C 8027897C 0C09A75B */  jal   get_actor
/* 1A7260 80278980 0040802D */   daddu $s0, $v0, $zero
/* 1A7264 80278984 AC5001C4 */  sw    $s0, 0x1c4($v0)
/* 1A7268 80278988 8FBF001C */  lw    $ra, 0x1c($sp)
/* 1A726C 8027898C 8FB20018 */  lw    $s2, 0x18($sp)
/* 1A7270 80278990 8FB10014 */  lw    $s1, 0x14($sp)
/* 1A7274 80278994 8FB00010 */  lw    $s0, 0x10($sp)
/* 1A7278 80278998 24020002 */  addiu $v0, $zero, 2
/* 1A727C 8027899C 03E00008 */  jr    $ra
/* 1A7280 802789A0 27BD0020 */   addiu $sp, $sp, 0x20

