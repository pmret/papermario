.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_AND_const
/* 0EAC84 802C62D4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EAC88 802C62D8 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EAC8C 802C62DC 0080882D */  daddu $s1, $a0, $zero
/* 0EAC90 802C62E0 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EAC94 802C62E4 AFB20018 */  sw    $s2, 0x18($sp)
/* 0EAC98 802C62E8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EAC9C 802C62EC 8E22000C */  lw    $v0, 0xc($s1)
/* 0EACA0 802C62F0 8C520000 */  lw    $s2, ($v0)
/* 0EACA4 802C62F4 8C500004 */  lw    $s0, 4($v0)
/* 0EACA8 802C62F8 0C0B1EAF */  jal   get_variable
/* 0EACAC 802C62FC 0240282D */   daddu $a1, $s2, $zero
/* 0EACB0 802C6300 0220202D */  daddu $a0, $s1, $zero
/* 0EACB4 802C6304 0240282D */  daddu $a1, $s2, $zero
/* 0EACB8 802C6308 0C0B2026 */  jal   set_variable
/* 0EACBC 802C630C 02023024 */   and   $a2, $s0, $v0
/* 0EACC0 802C6310 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EACC4 802C6314 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EACC8 802C6318 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EACCC 802C631C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EACD0 802C6320 24020002 */  addiu $v0, $zero, 2
/* 0EACD4 802C6324 03E00008 */  jr    $ra
/* 0EACD8 802C6328 27BD0020 */   addiu $sp, $sp, 0x20

