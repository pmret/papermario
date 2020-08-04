.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetOwnerTarget
/* 19D18C 8026E8AC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 19D190 8026E8B0 AFB10014 */  sw    $s1, 0x14($sp)
/* 19D194 8026E8B4 0080882D */  daddu $s1, $a0, $zero
/* 19D198 8026E8B8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 19D19C 8026E8BC AFB20018 */  sw    $s2, 0x18($sp)
/* 19D1A0 8026E8C0 AFB00010 */  sw    $s0, 0x10($sp)
/* 19D1A4 8026E8C4 8E240148 */  lw    $a0, 0x148($s1)
/* 19D1A8 8026E8C8 0C09A75B */  jal   get_actor
/* 19D1AC 8026E8CC 8E30000C */   lw    $s0, 0xc($s1)
/* 19D1B0 8026E8D0 0040902D */  daddu $s2, $v0, $zero
/* 19D1B4 8026E8D4 8E050000 */  lw    $a1, ($s0)
/* 19D1B8 8026E8D8 86460428 */  lh    $a2, 0x428($s2)
/* 19D1BC 8026E8DC 8E100004 */  lw    $s0, 4($s0)
/* 19D1C0 8026E8E0 0C0B2026 */  jal   set_variable
/* 19D1C4 8026E8E4 0220202D */   daddu $a0, $s1, $zero
/* 19D1C8 8026E8E8 0220202D */  daddu $a0, $s1, $zero
/* 19D1CC 8026E8EC 82460426 */  lb    $a2, 0x426($s2)
/* 19D1D0 8026E8F0 0C0B2026 */  jal   set_variable
/* 19D1D4 8026E8F4 0200282D */   daddu $a1, $s0, $zero
/* 19D1D8 8026E8F8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 19D1DC 8026E8FC 8FB20018 */  lw    $s2, 0x18($sp)
/* 19D1E0 8026E900 8FB10014 */  lw    $s1, 0x14($sp)
/* 19D1E4 8026E904 8FB00010 */  lw    $s0, 0x10($sp)
/* 19D1E8 8026E908 24020002 */  addiu $v0, $zero, 2
/* 19D1EC 8026E90C 03E00008 */  jr    $ra
/* 19D1F0 8026E910 27BD0020 */   addiu $sp, $sp, 0x20

/* 19D1F4 8026E914 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 19D1F8 8026E918 AFB00010 */  sw    $s0, 0x10($sp)
/* 19D1FC 8026E91C 0080802D */  daddu $s0, $a0, $zero
/* 19D200 8026E920 AFB20018 */  sw    $s2, 0x18($sp)
/* 19D204 8026E924 3C12800E */  lui   $s2, 0x800e
/* 19D208 8026E928 2652C070 */  addiu $s2, $s2, -0x3f90
/* 19D20C 8026E92C AFBF001C */  sw    $ra, 0x1c($sp)
/* 19D210 8026E930 AFB10014 */  sw    $s1, 0x14($sp)
/* 19D214 8026E934 8E02000C */  lw    $v0, 0xc($s0)
/* 19D218 8026E938 864601A4 */  lh    $a2, 0x1a4($s2)
/* 19D21C 8026E93C 8C450000 */  lw    $a1, ($v0)
/* 19D220 8026E940 0C0B2026 */  jal   set_variable
/* 19D224 8026E944 8C510004 */   lw    $s1, 4($v0)
/* 19D228 8026E948 0200202D */  daddu $a0, $s0, $zero
/* 19D22C 8026E94C 824601A6 */  lb    $a2, 0x1a6($s2)
/* 19D230 8026E950 0C0B2026 */  jal   set_variable
/* 19D234 8026E954 0220282D */   daddu $a1, $s1, $zero
/* 19D238 8026E958 8FBF001C */  lw    $ra, 0x1c($sp)
/* 19D23C 8026E95C 8FB20018 */  lw    $s2, 0x18($sp)
/* 19D240 8026E960 8FB10014 */  lw    $s1, 0x14($sp)
/* 19D244 8026E964 8FB00010 */  lw    $s0, 0x10($sp)
/* 19D248 8026E968 24020002 */  addiu $v0, $zero, 2
/* 19D24C 8026E96C 03E00008 */  jr    $ra
/* 19D250 8026E970 27BD0020 */   addiu $sp, $sp, 0x20

