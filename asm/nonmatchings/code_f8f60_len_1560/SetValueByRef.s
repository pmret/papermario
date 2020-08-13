.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetValueByRef
/* 0FA290 802D58E0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FA294 802D58E4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0FA298 802D58E8 0080882D */  daddu $s1, $a0, $zero
/* 0FA29C 802D58EC AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FA2A0 802D58F0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FA2A4 802D58F4 8E30000C */  lw    $s0, 0xc($s1)
/* 0FA2A8 802D58F8 8E050000 */  lw    $a1, ($s0)
/* 0FA2AC 802D58FC 0C0B1EAF */  jal   get_variable
/* 0FA2B0 802D5900 26100004 */   addiu $s0, $s0, 4
/* 0FA2B4 802D5904 0220202D */  daddu $a0, $s1, $zero
/* 0FA2B8 802D5908 8E050000 */  lw    $a1, ($s0)
/* 0FA2BC 802D590C 0C0B1EAF */  jal   get_variable
/* 0FA2C0 802D5910 0040802D */   daddu $s0, $v0, $zero
/* 0FA2C4 802D5914 0220202D */  daddu $a0, $s1, $zero
/* 0FA2C8 802D5918 0200282D */  daddu $a1, $s0, $zero
/* 0FA2CC 802D591C 0C0B2026 */  jal   set_variable
/* 0FA2D0 802D5920 0040302D */   daddu $a2, $v0, $zero
/* 0FA2D4 802D5924 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FA2D8 802D5928 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FA2DC 802D592C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FA2E0 802D5930 24020002 */  addiu $v0, $zero, 2
/* 0FA2E4 802D5934 03E00008 */  jr    $ra
/* 0FA2E8 802D5938 27BD0020 */   addiu $sp, $sp, 0x20

