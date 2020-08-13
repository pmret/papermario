.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetActorSize
/* 1AC1C0 8027D8E0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 1AC1C4 8027D8E4 AFB10014 */  sw    $s1, 0x14($sp)
/* 1AC1C8 8027D8E8 0080882D */  daddu $s1, $a0, $zero
/* 1AC1CC 8027D8EC AFBF0020 */  sw    $ra, 0x20($sp)
/* 1AC1D0 8027D8F0 AFB3001C */  sw    $s3, 0x1c($sp)
/* 1AC1D4 8027D8F4 AFB20018 */  sw    $s2, 0x18($sp)
/* 1AC1D8 8027D8F8 AFB00010 */  sw    $s0, 0x10($sp)
/* 1AC1DC 8027D8FC 8E30000C */  lw    $s0, 0xc($s1)
/* 1AC1E0 8027D900 8E050000 */  lw    $a1, ($s0)
/* 1AC1E4 8027D904 0C0B1EAF */  jal   get_variable
/* 1AC1E8 8027D908 26100004 */   addiu $s0, $s0, 4
/* 1AC1EC 8027D90C 0040202D */  daddu $a0, $v0, $zero
/* 1AC1F0 8027D910 2402FF81 */  addiu $v0, $zero, -0x7f
/* 1AC1F4 8027D914 8E120000 */  lw    $s2, ($s0)
/* 1AC1F8 8027D918 14820002 */  bne   $a0, $v0, .L8027D924
/* 1AC1FC 8027D91C 8E130004 */   lw    $s3, 4($s0)
/* 1AC200 8027D920 8E240148 */  lw    $a0, 0x148($s1)
.L8027D924:
/* 1AC204 8027D924 0C09A75B */  jal   get_actor
/* 1AC208 8027D928 00000000 */   nop   
/* 1AC20C 8027D92C 0220202D */  daddu $a0, $s1, $zero
/* 1AC210 8027D930 0040802D */  daddu $s0, $v0, $zero
/* 1AC214 8027D934 92060191 */  lbu   $a2, 0x191($s0)
/* 1AC218 8027D938 0C0B2026 */  jal   set_variable
/* 1AC21C 8027D93C 0240282D */   daddu $a1, $s2, $zero
/* 1AC220 8027D940 0220202D */  daddu $a0, $s1, $zero
/* 1AC224 8027D944 92060190 */  lbu   $a2, 0x190($s0)
/* 1AC228 8027D948 0C0B2026 */  jal   set_variable
/* 1AC22C 8027D94C 0260282D */   daddu $a1, $s3, $zero
/* 1AC230 8027D950 8FBF0020 */  lw    $ra, 0x20($sp)
/* 1AC234 8027D954 8FB3001C */  lw    $s3, 0x1c($sp)
/* 1AC238 8027D958 8FB20018 */  lw    $s2, 0x18($sp)
/* 1AC23C 8027D95C 8FB10014 */  lw    $s1, 0x14($sp)
/* 1AC240 8027D960 8FB00010 */  lw    $s0, 0x10($sp)
/* 1AC244 8027D964 24020002 */  addiu $v0, $zero, 2
/* 1AC248 8027D968 03E00008 */  jr    $ra
/* 1AC24C 8027D96C 27BD0028 */   addiu $sp, $sp, 0x28

