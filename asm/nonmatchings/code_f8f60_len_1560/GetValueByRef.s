.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel GetValueByRef
/* 0FA2EC 802D593C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FA2F0 802D5940 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FA2F4 802D5944 0080882D */  daddu $s1, $a0, $zero
/* 0FA2F8 802D5948 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FA2FC 802D594C AFB00010 */  sw    $s0, 0x10($sp)
/* 0FA300 802D5950 8E30000C */  lw    $s0, 0xc($s1)
/* 0FA304 802D5954 8E050000 */  lw    $a1, ($s0)
/* 0FA308 802D5958 0C0B1EAF */  jal   get_variable
/* 0FA30C 802D595C 26100004 */   addiu $s0, $s0, 4
/* 0FA310 802D5960 0220202D */  daddu $a0, $s1, $zero
/* 0FA314 802D5964 8E100000 */  lw    $s0, ($s0)
/* 0FA318 802D5968 0C0B1EAF */  jal   get_variable
/* 0FA31C 802D596C 0040282D */   daddu $a1, $v0, $zero
/* 0FA320 802D5970 0220202D */  daddu $a0, $s1, $zero
/* 0FA324 802D5974 0040302D */  daddu $a2, $v0, $zero
/* 0FA328 802D5978 0C0B2026 */  jal   set_variable
/* 0FA32C 802D597C 0200282D */   daddu $a1, $s0, $zero
/* 0FA330 802D5980 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FA334 802D5984 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FA338 802D5988 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FA33C 802D598C 24020002 */  addiu $v0, $zero, 2
/* 0FA340 802D5990 03E00008 */  jr    $ra
/* 0FA344 802D5994 27BD0020 */   addiu $sp, $sp, 0x20

