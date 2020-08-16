.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetNpcCollisionSize
/* 0F293C 802CDF8C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0F2940 802CDF90 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F2944 802CDF94 0080882D */  daddu $s1, $a0, $zero
/* 0F2948 802CDF98 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0F294C 802CDF9C AFB3001C */  sw    $s3, 0x1c($sp)
/* 0F2950 802CDFA0 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F2954 802CDFA4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F2958 802CDFA8 8E30000C */  lw    $s0, 0xc($s1)
/* 0F295C 802CDFAC 8E050000 */  lw    $a1, ($s0)
/* 0F2960 802CDFB0 0C0B1EAF */  jal   get_variable
/* 0F2964 802CDFB4 26100004 */   addiu $s0, $s0, 4
/* 0F2968 802CDFB8 8E050000 */  lw    $a1, ($s0)
/* 0F296C 802CDFBC 26100004 */  addiu $s0, $s0, 4
/* 0F2970 802CDFC0 0220202D */  daddu $a0, $s1, $zero
/* 0F2974 802CDFC4 0C0B1EAF */  jal   get_variable
/* 0F2978 802CDFC8 0040902D */   daddu $s2, $v0, $zero
/* 0F297C 802CDFCC 0220202D */  daddu $a0, $s1, $zero
/* 0F2980 802CDFD0 8E050000 */  lw    $a1, ($s0)
/* 0F2984 802CDFD4 0C0B1EAF */  jal   get_variable
/* 0F2988 802CDFD8 0040982D */   daddu $s3, $v0, $zero
/* 0F298C 802CDFDC 0220202D */  daddu $a0, $s1, $zero
/* 0F2990 802CDFE0 0240282D */  daddu $a1, $s2, $zero
/* 0F2994 802CDFE4 0C0B36B0 */  jal   resolve_npc
/* 0F2998 802CDFE8 0040802D */   daddu $s0, $v0, $zero
/* 0F299C 802CDFEC 0040182D */  daddu $v1, $v0, $zero
/* 0F29A0 802CDFF0 10600003 */  beqz  $v1, .L802CE000
/* 0F29A4 802CDFF4 24020002 */   addiu $v0, $zero, 2
/* 0F29A8 802CDFF8 A47300A8 */  sh    $s3, 0xa8($v1)
/* 0F29AC 802CDFFC A47000A6 */  sh    $s0, 0xa6($v1)
.L802CE000:
/* 0F29B0 802CE000 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0F29B4 802CE004 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0F29B8 802CE008 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F29BC 802CE00C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F29C0 802CE010 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F29C4 802CE014 03E00008 */  jr    $ra
/* 0F29C8 802CE018 27BD0028 */   addiu $sp, $sp, 0x28

