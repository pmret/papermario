.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel FXRecoverFP
/* 190548 80261C68 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 19054C 80261C6C AFB1001C */  sw    $s1, 0x1c($sp)
/* 190550 80261C70 0080882D */  daddu $s1, $a0, $zero
/* 190554 80261C74 AFBF0028 */  sw    $ra, 0x28($sp)
/* 190558 80261C78 AFB30024 */  sw    $s3, 0x24($sp)
/* 19055C 80261C7C AFB20020 */  sw    $s2, 0x20($sp)
/* 190560 80261C80 AFB00018 */  sw    $s0, 0x18($sp)
/* 190564 80261C84 8E30000C */  lw    $s0, 0xc($s1)
/* 190568 80261C88 8E050000 */  lw    $a1, ($s0)
/* 19056C 80261C8C 0C0B1EAF */  jal   get_variable
/* 190570 80261C90 26100004 */   addiu $s0, $s0, 4
/* 190574 80261C94 8E050000 */  lw    $a1, ($s0)
/* 190578 80261C98 26100004 */  addiu $s0, $s0, 4
/* 19057C 80261C9C 0220202D */  daddu $a0, $s1, $zero
/* 190580 80261CA0 0C0B1EAF */  jal   get_variable
/* 190584 80261CA4 0040982D */   daddu $s3, $v0, $zero
/* 190588 80261CA8 8E050000 */  lw    $a1, ($s0)
/* 19058C 80261CAC 26100004 */  addiu $s0, $s0, 4
/* 190590 80261CB0 0220202D */  daddu $a0, $s1, $zero
/* 190594 80261CB4 0C0B1EAF */  jal   get_variable
/* 190598 80261CB8 0040902D */   daddu $s2, $v0, $zero
/* 19059C 80261CBC 0220202D */  daddu $a0, $s1, $zero
/* 1905A0 80261CC0 8E050000 */  lw    $a1, ($s0)
/* 1905A4 80261CC4 0C0B1EAF */  jal   get_variable
/* 1905A8 80261CC8 0040802D */   daddu $s0, $v0, $zero
/* 1905AC 80261CCC 44930000 */  mtc1  $s3, $f0
/* 1905B0 80261CD0 00000000 */  nop   
/* 1905B4 80261CD4 46800020 */  cvt.s.w $f0, $f0
/* 1905B8 80261CD8 44050000 */  mfc1  $a1, $f0
/* 1905BC 80261CDC 44920000 */  mtc1  $s2, $f0
/* 1905C0 80261CE0 00000000 */  nop   
/* 1905C4 80261CE4 46800020 */  cvt.s.w $f0, $f0
/* 1905C8 80261CE8 44060000 */  mfc1  $a2, $f0
/* 1905CC 80261CEC 44900000 */  mtc1  $s0, $f0
/* 1905D0 80261CF0 00000000 */  nop   
/* 1905D4 80261CF4 46800020 */  cvt.s.w $f0, $f0
/* 1905D8 80261CF8 44070000 */  mfc1  $a3, $f0
/* 1905DC 80261CFC 24040001 */  addiu $a0, $zero, 1
/* 1905E0 80261D00 0C01C424 */  jal   func_80071090
/* 1905E4 80261D04 AFA20010 */   sw    $v0, 0x10($sp)
/* 1905E8 80261D08 8FBF0028 */  lw    $ra, 0x28($sp)
/* 1905EC 80261D0C 8FB30024 */  lw    $s3, 0x24($sp)
/* 1905F0 80261D10 8FB20020 */  lw    $s2, 0x20($sp)
/* 1905F4 80261D14 8FB1001C */  lw    $s1, 0x1c($sp)
/* 1905F8 80261D18 8FB00018 */  lw    $s0, 0x18($sp)
/* 1905FC 80261D1C 24020002 */  addiu $v0, $zero, 2
/* 190600 80261D20 03E00008 */  jr    $ra
/* 190604 80261D24 27BD0030 */   addiu $sp, $sp, 0x30

