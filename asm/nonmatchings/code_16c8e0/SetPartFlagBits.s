.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetPartFlagBits
/* 19B8F0 8026D010 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 19B8F4 8026D014 AFB10014 */  sw    $s1, 0x14($sp)
/* 19B8F8 8026D018 0080882D */  daddu $s1, $a0, $zero
/* 19B8FC 8026D01C AFBF0020 */  sw    $ra, 0x20($sp)
/* 19B900 8026D020 AFB3001C */  sw    $s3, 0x1c($sp)
/* 19B904 8026D024 AFB20018 */  sw    $s2, 0x18($sp)
/* 19B908 8026D028 AFB00010 */  sw    $s0, 0x10($sp)
/* 19B90C 8026D02C 8E30000C */  lw    $s0, 0xc($s1)
/* 19B910 8026D030 8E050000 */  lw    $a1, ($s0)
/* 19B914 8026D034 0C0B1EAF */  jal   get_variable
/* 19B918 8026D038 26100004 */   addiu $s0, $s0, 4
/* 19B91C 8026D03C 0040902D */  daddu $s2, $v0, $zero
/* 19B920 8026D040 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19B924 8026D044 16420002 */  bne   $s2, $v0, .L8026D050
/* 19B928 8026D048 00000000 */   nop   
/* 19B92C 8026D04C 8E320148 */  lw    $s2, 0x148($s1)
.L8026D050:
/* 19B930 8026D050 8E050000 */  lw    $a1, ($s0)
/* 19B934 8026D054 26100004 */  addiu $s0, $s0, 4
/* 19B938 8026D058 0C0B1EAF */  jal   get_variable
/* 19B93C 8026D05C 0220202D */   daddu $a0, $s1, $zero
/* 19B940 8026D060 0220202D */  daddu $a0, $s1, $zero
/* 19B944 8026D064 8E050004 */  lw    $a1, 4($s0)
/* 19B948 8026D068 8E130000 */  lw    $s3, ($s0)
/* 19B94C 8026D06C 0C0B1EAF */  jal   get_variable
/* 19B950 8026D070 0040882D */   daddu $s1, $v0, $zero
/* 19B954 8026D074 0240202D */  daddu $a0, $s2, $zero
/* 19B958 8026D078 0C09A75B */  jal   get_actor
/* 19B95C 8026D07C 0040802D */   daddu $s0, $v0, $zero
/* 19B960 8026D080 0040202D */  daddu $a0, $v0, $zero
/* 19B964 8026D084 0C099117 */  jal   get_actor_part
/* 19B968 8026D088 0220282D */   daddu $a1, $s1, $zero
/* 19B96C 8026D08C 12000004 */  beqz  $s0, .L8026D0A0
/* 19B970 8026D090 0040202D */   daddu $a0, $v0, $zero
/* 19B974 8026D094 8C820000 */  lw    $v0, ($a0)
/* 19B978 8026D098 0809B42B */  j     .L8026D0AC
/* 19B97C 8026D09C 00531025 */   or    $v0, $v0, $s3

.L8026D0A0:
/* 19B980 8026D0A0 8C820000 */  lw    $v0, ($a0)
/* 19B984 8026D0A4 00131827 */  nor   $v1, $zero, $s3
/* 19B988 8026D0A8 00431024 */  and   $v0, $v0, $v1
.L8026D0AC:
/* 19B98C 8026D0AC AC820000 */  sw    $v0, ($a0)
/* 19B990 8026D0B0 8FBF0020 */  lw    $ra, 0x20($sp)
/* 19B994 8026D0B4 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19B998 8026D0B8 8FB20018 */  lw    $s2, 0x18($sp)
/* 19B99C 8026D0BC 8FB10014 */  lw    $s1, 0x14($sp)
/* 19B9A0 8026D0C0 8FB00010 */  lw    $s0, 0x10($sp)
/* 19B9A4 8026D0C4 24020002 */  addiu $v0, $zero, 2
/* 19B9A8 8026D0C8 03E00008 */  jr    $ra
/* 19B9AC 8026D0CC 27BD0028 */   addiu $sp, $sp, 0x28

