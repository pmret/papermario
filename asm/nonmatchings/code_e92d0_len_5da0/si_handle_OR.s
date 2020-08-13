.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_OR
/* 0EACDC 802C632C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EACE0 802C6330 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EACE4 802C6334 0080882D */  daddu $s1, $a0, $zero
/* 0EACE8 802C6338 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EACEC 802C633C AFB20018 */  sw    $s2, 0x18($sp)
/* 0EACF0 802C6340 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EACF4 802C6344 8E22000C */  lw    $v0, 0xc($s1)
/* 0EACF8 802C6348 8C450004 */  lw    $a1, 4($v0)
/* 0EACFC 802C634C 0C0B1EAF */  jal   get_variable
/* 0EAD00 802C6350 8C520000 */   lw    $s2, ($v0)
/* 0EAD04 802C6354 0040802D */  daddu $s0, $v0, $zero
/* 0EAD08 802C6358 0220202D */  daddu $a0, $s1, $zero
/* 0EAD0C 802C635C 0C0B1EAF */  jal   get_variable
/* 0EAD10 802C6360 0240282D */   daddu $a1, $s2, $zero
/* 0EAD14 802C6364 0220202D */  daddu $a0, $s1, $zero
/* 0EAD18 802C6368 0240282D */  daddu $a1, $s2, $zero
/* 0EAD1C 802C636C 0C0B2026 */  jal   set_variable
/* 0EAD20 802C6370 02023025 */   or    $a2, $s0, $v0
/* 0EAD24 802C6374 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EAD28 802C6378 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EAD2C 802C637C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EAD30 802C6380 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EAD34 802C6384 24020002 */  addiu $v0, $zero, 2
/* 0EAD38 802C6388 03E00008 */  jr    $ra
/* 0EAD3C 802C638C 27BD0020 */   addiu $sp, $sp, 0x20

