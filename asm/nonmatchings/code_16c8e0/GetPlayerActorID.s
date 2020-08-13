.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetPlayerActorID
/* 19D254 8026E974 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 19D258 8026E978 AFBF0010 */  sw    $ra, 0x10($sp)
/* 19D25C 8026E97C 8C82000C */  lw    $v0, 0xc($a0)
/* 19D260 8026E980 3C06800E */  lui   $a2, 0x800e
/* 19D264 8026E984 84C6C218 */  lh    $a2, -0x3de8($a2)
/* 19D268 8026E988 0C0B2026 */  jal   set_variable
/* 19D26C 8026E98C 8C450000 */   lw    $a1, ($v0)
/* 19D270 8026E990 8FBF0010 */  lw    $ra, 0x10($sp)
/* 19D274 8026E994 24020002 */  addiu $v0, $zero, 2
/* 19D278 8026E998 03E00008 */  jr    $ra
/* 19D27C 8026E99C 27BD0018 */   addiu $sp, $sp, 0x18

/* 19D280 8026E9A0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 19D284 8026E9A4 AFB10014 */  sw    $s1, 0x14($sp)
/* 19D288 8026E9A8 0080882D */  daddu $s1, $a0, $zero
/* 19D28C 8026E9AC AFBF0018 */  sw    $ra, 0x18($sp)
/* 19D290 8026E9B0 AFB00010 */  sw    $s0, 0x10($sp)
/* 19D294 8026E9B4 8E30000C */  lw    $s0, 0xc($s1)
/* 19D298 8026E9B8 8E050000 */  lw    $a1, ($s0)
/* 19D29C 8026E9BC 0C0B1EAF */  jal   get_variable
/* 19D2A0 8026E9C0 26100004 */   addiu $s0, $s0, 4
/* 19D2A4 8026E9C4 0220202D */  daddu $a0, $s1, $zero
/* 19D2A8 8026E9C8 8E050000 */  lw    $a1, ($s0)
/* 19D2AC 8026E9CC 0C0B1EAF */  jal   get_variable
/* 19D2B0 8026E9D0 0040802D */   daddu $s0, $v0, $zero
/* 19D2B4 8026E9D4 3C03800E */  lui   $v1, 0x800e
/* 19D2B8 8026E9D8 2463C070 */  addiu $v1, $v1, -0x3f90
/* 19D2BC 8026E9DC A06201A6 */  sb    $v0, 0x1a6($v1)
/* 19D2C0 8026E9E0 A47001A4 */  sh    $s0, 0x1a4($v1)
/* 19D2C4 8026E9E4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 19D2C8 8026E9E8 8FB10014 */  lw    $s1, 0x14($sp)
/* 19D2CC 8026E9EC 8FB00010 */  lw    $s0, 0x10($sp)
/* 19D2D0 8026E9F0 24020002 */  addiu $v0, $zero, 2
/* 19D2D4 8026E9F4 03E00008 */  jr    $ra
/* 19D2D8 8026E9F8 27BD0020 */   addiu $sp, $sp, 0x20

