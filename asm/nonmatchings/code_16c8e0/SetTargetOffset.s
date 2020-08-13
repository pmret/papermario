.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetTargetOffset
/* 1ABC60 8027D380 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 1ABC64 8027D384 AFB3001C */  sw    $s3, 0x1c($sp)
/* 1ABC68 8027D388 0080982D */  daddu $s3, $a0, $zero
/* 1ABC6C 8027D38C AFBF0020 */  sw    $ra, 0x20($sp)
/* 1ABC70 8027D390 AFB20018 */  sw    $s2, 0x18($sp)
/* 1ABC74 8027D394 AFB10014 */  sw    $s1, 0x14($sp)
/* 1ABC78 8027D398 AFB00010 */  sw    $s0, 0x10($sp)
/* 1ABC7C 8027D39C 8E72000C */  lw    $s2, 0xc($s3)
/* 1ABC80 8027D3A0 8E450000 */  lw    $a1, ($s2)
/* 1ABC84 8027D3A4 0C0B1EAF */  jal   get_variable
/* 1ABC88 8027D3A8 26520004 */   addiu $s2, $s2, 4
/* 1ABC8C 8027D3AC 0040802D */  daddu $s0, $v0, $zero
/* 1ABC90 8027D3B0 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1ABC94 8027D3B4 16020002 */  bne   $s0, $v0, .L8027D3C0
/* 1ABC98 8027D3B8 00000000 */   nop   
/* 1ABC9C 8027D3BC 8E700148 */  lw    $s0, 0x148($s3)
.L8027D3C0:
/* 1ABCA0 8027D3C0 8E450000 */  lw    $a1, ($s2)
/* 1ABCA4 8027D3C4 26520004 */  addiu $s2, $s2, 4
/* 1ABCA8 8027D3C8 0C0B1EAF */  jal   get_variable
/* 1ABCAC 8027D3CC 0260202D */   daddu $a0, $s3, $zero
/* 1ABCB0 8027D3D0 0200202D */  daddu $a0, $s0, $zero
/* 1ABCB4 8027D3D4 0C09A75B */  jal   get_actor
/* 1ABCB8 8027D3D8 0040802D */   daddu $s0, $v0, $zero
/* 1ABCBC 8027D3DC 0040202D */  daddu $a0, $v0, $zero
/* 1ABCC0 8027D3E0 0C099117 */  jal   get_actor_part
/* 1ABCC4 8027D3E4 0200282D */   daddu $a1, $s0, $zero
/* 1ABCC8 8027D3E8 8E450000 */  lw    $a1, ($s2)
/* 1ABCCC 8027D3EC 26520004 */  addiu $s2, $s2, 4
/* 1ABCD0 8027D3F0 0260202D */  daddu $a0, $s3, $zero
/* 1ABCD4 8027D3F4 0C0B1EAF */  jal   get_variable
/* 1ABCD8 8027D3F8 0040882D */   daddu $s1, $v0, $zero
/* 1ABCDC 8027D3FC 0260202D */  daddu $a0, $s3, $zero
/* 1ABCE0 8027D400 8E450000 */  lw    $a1, ($s2)
/* 1ABCE4 8027D404 0C0B1EAF */  jal   get_variable
/* 1ABCE8 8027D408 0040802D */   daddu $s0, $v0, $zero
/* 1ABCEC 8027D40C A622006E */  sh    $v0, 0x6e($s1)
/* 1ABCF0 8027D410 A630006C */  sh    $s0, 0x6c($s1)
/* 1ABCF4 8027D414 8FBF0020 */  lw    $ra, 0x20($sp)
/* 1ABCF8 8027D418 8FB3001C */  lw    $s3, 0x1c($sp)
/* 1ABCFC 8027D41C 8FB20018 */  lw    $s2, 0x18($sp)
/* 1ABD00 8027D420 8FB10014 */  lw    $s1, 0x14($sp)
/* 1ABD04 8027D424 8FB00010 */  lw    $s0, 0x10($sp)
/* 1ABD08 8027D428 24020002 */  addiu $v0, $zero, 2
/* 1ABD0C 8027D42C 03E00008 */  jr    $ra
/* 1ABD10 8027D430 27BD0028 */   addiu $sp, $sp, 0x28

/* 1ABD14 8027D434 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 1ABD18 8027D438 AFB20018 */  sw    $s2, 0x18($sp)
/* 1ABD1C 8027D43C 0080902D */  daddu $s2, $a0, $zero
/* 1ABD20 8027D440 AFBF001C */  sw    $ra, 0x1c($sp)
/* 1ABD24 8027D444 AFB10014 */  sw    $s1, 0x14($sp)
/* 1ABD28 8027D448 AFB00010 */  sw    $s0, 0x10($sp)
/* 1ABD2C 8027D44C 8E51000C */  lw    $s1, 0xc($s2)
/* 1ABD30 8027D450 8E250000 */  lw    $a1, ($s1)
/* 1ABD34 8027D454 0C0B1EAF */  jal   get_variable
/* 1ABD38 8027D458 26310004 */   addiu $s1, $s1, 4
/* 1ABD3C 8027D45C 0040802D */  daddu $s0, $v0, $zero
/* 1ABD40 8027D460 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1ABD44 8027D464 16020002 */  bne   $s0, $v0, .L8027D470
/* 1ABD48 8027D468 00000000 */   nop   
/* 1ABD4C 8027D46C 8E500148 */  lw    $s0, 0x148($s2)
.L8027D470:
/* 1ABD50 8027D470 8E250000 */  lw    $a1, ($s1)
/* 1ABD54 8027D474 26310004 */  addiu $s1, $s1, 4
/* 1ABD58 8027D478 0C0B1EAF */  jal   get_variable
/* 1ABD5C 8027D47C 0240202D */   daddu $a0, $s2, $zero
/* 1ABD60 8027D480 0200202D */  daddu $a0, $s0, $zero
/* 1ABD64 8027D484 0C09A75B */  jal   get_actor
/* 1ABD68 8027D488 0040802D */   daddu $s0, $v0, $zero
/* 1ABD6C 8027D48C 0040202D */  daddu $a0, $v0, $zero
/* 1ABD70 8027D490 0C099117 */  jal   get_actor_part
/* 1ABD74 8027D494 0200282D */   daddu $a1, $s0, $zero
/* 1ABD78 8027D498 0240202D */  daddu $a0, $s2, $zero
/* 1ABD7C 8027D49C 8E250000 */  lw    $a1, ($s1)
/* 1ABD80 8027D4A0 0C0B1EAF */  jal   get_variable
/* 1ABD84 8027D4A4 0040802D */   daddu $s0, $v0, $zero
/* 1ABD88 8027D4A8 A6020070 */  sh    $v0, 0x70($s0)
/* 1ABD8C 8027D4AC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 1ABD90 8027D4B0 8FB20018 */  lw    $s2, 0x18($sp)
/* 1ABD94 8027D4B4 8FB10014 */  lw    $s1, 0x14($sp)
/* 1ABD98 8027D4B8 8FB00010 */  lw    $s0, 0x10($sp)
/* 1ABD9C 8027D4BC 24020002 */  addiu $v0, $zero, 2
/* 1ABDA0 8027D4C0 03E00008 */  jr    $ra
/* 1ABDA4 8027D4C4 27BD0020 */   addiu $sp, $sp, 0x20

/* 1ABDA8 8027D4C8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 1ABDAC 8027D4CC AFB3001C */  sw    $s3, 0x1c($sp)
/* 1ABDB0 8027D4D0 0080982D */  daddu $s3, $a0, $zero
/* 1ABDB4 8027D4D4 AFBF0020 */  sw    $ra, 0x20($sp)
/* 1ABDB8 8027D4D8 AFB20018 */  sw    $s2, 0x18($sp)
/* 1ABDBC 8027D4DC AFB10014 */  sw    $s1, 0x14($sp)
/* 1ABDC0 8027D4E0 AFB00010 */  sw    $s0, 0x10($sp)
/* 1ABDC4 8027D4E4 8E72000C */  lw    $s2, 0xc($s3)
/* 1ABDC8 8027D4E8 8E450000 */  lw    $a1, ($s2)
/* 1ABDCC 8027D4EC 0C0B1EAF */  jal   get_variable
/* 1ABDD0 8027D4F0 26520004 */   addiu $s2, $s2, 4
/* 1ABDD4 8027D4F4 0040802D */  daddu $s0, $v0, $zero
/* 1ABDD8 8027D4F8 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1ABDDC 8027D4FC 16020002 */  bne   $s0, $v0, .L8027D508
/* 1ABDE0 8027D500 00000000 */   nop   
/* 1ABDE4 8027D504 8E700148 */  lw    $s0, 0x148($s3)
.L8027D508:
/* 1ABDE8 8027D508 8E450000 */  lw    $a1, ($s2)
/* 1ABDEC 8027D50C 26520004 */  addiu $s2, $s2, 4
/* 1ABDF0 8027D510 0C0B1EAF */  jal   get_variable
/* 1ABDF4 8027D514 0260202D */   daddu $a0, $s3, $zero
/* 1ABDF8 8027D518 0200202D */  daddu $a0, $s0, $zero
/* 1ABDFC 8027D51C 0C09A75B */  jal   get_actor
/* 1ABE00 8027D520 0040802D */   daddu $s0, $v0, $zero
/* 1ABE04 8027D524 0040202D */  daddu $a0, $v0, $zero
/* 1ABE08 8027D528 0C099117 */  jal   get_actor_part
/* 1ABE0C 8027D52C 0200282D */   daddu $a1, $s0, $zero
/* 1ABE10 8027D530 8E450000 */  lw    $a1, ($s2)
/* 1ABE14 8027D534 26520004 */  addiu $s2, $s2, 4
/* 1ABE18 8027D538 0260202D */  daddu $a0, $s3, $zero
/* 1ABE1C 8027D53C 0C0B1EAF */  jal   get_variable
/* 1ABE20 8027D540 0040882D */   daddu $s1, $v0, $zero
/* 1ABE24 8027D544 0260202D */  daddu $a0, $s3, $zero
/* 1ABE28 8027D548 8E450000 */  lw    $a1, ($s2)
/* 1ABE2C 8027D54C 0C0B1EAF */  jal   get_variable
/* 1ABE30 8027D550 0040802D */   daddu $s0, $v0, $zero
/* 1ABE34 8027D554 A2220076 */  sb    $v0, 0x76($s1)
/* 1ABE38 8027D558 A2300075 */  sb    $s0, 0x75($s1)
/* 1ABE3C 8027D55C 8FBF0020 */  lw    $ra, 0x20($sp)
/* 1ABE40 8027D560 8FB3001C */  lw    $s3, 0x1c($sp)
/* 1ABE44 8027D564 8FB20018 */  lw    $s2, 0x18($sp)
/* 1ABE48 8027D568 8FB10014 */  lw    $s1, 0x14($sp)
/* 1ABE4C 8027D56C 8FB00010 */  lw    $s0, 0x10($sp)
/* 1ABE50 8027D570 24020002 */  addiu $v0, $zero, 2
/* 1ABE54 8027D574 03E00008 */  jr    $ra
/* 1ABE58 8027D578 27BD0028 */   addiu $sp, $sp, 0x28

