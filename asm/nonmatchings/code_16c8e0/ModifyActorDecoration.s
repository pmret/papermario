.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel ModifyActorDecoration
/* 19D8D0 8026EFF0 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 19D8D4 8026EFF4 AFB20018 */  sw    $s2, 0x18($sp)
/* 19D8D8 8026EFF8 0080902D */  daddu $s2, $a0, $zero
/* 19D8DC 8026EFFC AFBF0024 */  sw    $ra, 0x24($sp)
/* 19D8E0 8026F000 AFB40020 */  sw    $s4, 0x20($sp)
/* 19D8E4 8026F004 AFB3001C */  sw    $s3, 0x1c($sp)
/* 19D8E8 8026F008 AFB10014 */  sw    $s1, 0x14($sp)
/* 19D8EC 8026F00C AFB00010 */  sw    $s0, 0x10($sp)
/* 19D8F0 8026F010 8E51000C */  lw    $s1, 0xc($s2)
/* 19D8F4 8026F014 8E250000 */  lw    $a1, ($s1)
/* 19D8F8 8026F018 0C0B1EAF */  jal   get_variable
/* 19D8FC 8026F01C 26310004 */   addiu $s1, $s1, 4
/* 19D900 8026F020 0040802D */  daddu $s0, $v0, $zero
/* 19D904 8026F024 8E250000 */  lw    $a1, ($s1)
/* 19D908 8026F028 26310004 */  addiu $s1, $s1, 4
/* 19D90C 8026F02C 0C0B1EAF */  jal   get_variable
/* 19D910 8026F030 0240202D */   daddu $a0, $s2, $zero
/* 19D914 8026F034 8E250000 */  lw    $a1, ($s1)
/* 19D918 8026F038 26310004 */  addiu $s1, $s1, 4
/* 19D91C 8026F03C 0240202D */  daddu $a0, $s2, $zero
/* 19D920 8026F040 0C0B1EAF */  jal   get_variable
/* 19D924 8026F044 0040982D */   daddu $s3, $v0, $zero
/* 19D928 8026F048 0040A02D */  daddu $s4, $v0, $zero
/* 19D92C 8026F04C 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19D930 8026F050 16020002 */  bne   $s0, $v0, .L8026F05C
/* 19D934 8026F054 00000000 */   nop   
/* 19D938 8026F058 8E500148 */  lw    $s0, 0x148($s2)
.L8026F05C:
/* 19D93C 8026F05C 0C09A75B */  jal   get_actor
/* 19D940 8026F060 0200202D */   daddu $a0, $s0, $zero
/* 19D944 8026F064 0040202D */  daddu $a0, $v0, $zero
/* 19D948 8026F068 0C099117 */  jal   get_actor_part
/* 19D94C 8026F06C 0260282D */   daddu $a1, $s3, $zero
/* 19D950 8026F070 8E250000 */  lw    $a1, ($s1)
/* 19D954 8026F074 26310004 */  addiu $s1, $s1, 4
/* 19D958 8026F078 8C5000C0 */  lw    $s0, 0xc0($v0)
/* 19D95C 8026F07C 0C0B1EAF */  jal   get_variable
/* 19D960 8026F080 0240202D */   daddu $a0, $s2, $zero
/* 19D964 8026F084 00141900 */  sll   $v1, $s4, 4
/* 19D968 8026F088 02038021 */  addu  $s0, $s0, $v1
/* 19D96C 8026F08C A60208C6 */  sh    $v0, 0x8c6($s0)
/* 19D970 8026F090 8E250000 */  lw    $a1, ($s1)
/* 19D974 8026F094 26310004 */  addiu $s1, $s1, 4
/* 19D978 8026F098 0C0B1EAF */  jal   get_variable
/* 19D97C 8026F09C 0240202D */   daddu $a0, $s2, $zero
/* 19D980 8026F0A0 A60208C8 */  sh    $v0, 0x8c8($s0)
/* 19D984 8026F0A4 8E250000 */  lw    $a1, ($s1)
/* 19D988 8026F0A8 26310004 */  addiu $s1, $s1, 4
/* 19D98C 8026F0AC 0C0B1EAF */  jal   get_variable
/* 19D990 8026F0B0 0240202D */   daddu $a0, $s2, $zero
/* 19D994 8026F0B4 A60208CA */  sh    $v0, 0x8ca($s0)
/* 19D998 8026F0B8 8E250000 */  lw    $a1, ($s1)
/* 19D99C 8026F0BC 0C0B1EAF */  jal   get_variable
/* 19D9A0 8026F0C0 0240202D */   daddu $a0, $s2, $zero
/* 19D9A4 8026F0C4 A60208CC */  sh    $v0, 0x8cc($s0)
/* 19D9A8 8026F0C8 8FBF0024 */  lw    $ra, 0x24($sp)
/* 19D9AC 8026F0CC 8FB40020 */  lw    $s4, 0x20($sp)
/* 19D9B0 8026F0D0 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19D9B4 8026F0D4 8FB20018 */  lw    $s2, 0x18($sp)
/* 19D9B8 8026F0D8 8FB10014 */  lw    $s1, 0x14($sp)
/* 19D9BC 8026F0DC 8FB00010 */  lw    $s0, 0x10($sp)
/* 19D9C0 8026F0E0 24020002 */  addiu $v0, $zero, 2
/* 19D9C4 8026F0E4 03E00008 */  jr    $ra
/* 19D9C8 8026F0E8 27BD0028 */   addiu $sp, $sp, 0x28

