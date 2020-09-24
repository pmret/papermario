.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel si_handle_OR
/* EACDC 802C632C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EACE0 802C6330 AFB10014 */  sw        $s1, 0x14($sp)
/* EACE4 802C6334 0080882D */  daddu     $s1, $a0, $zero
/* EACE8 802C6338 AFBF001C */  sw        $ra, 0x1c($sp)
/* EACEC 802C633C AFB20018 */  sw        $s2, 0x18($sp)
/* EACF0 802C6340 AFB00010 */  sw        $s0, 0x10($sp)
/* EACF4 802C6344 8E22000C */  lw        $v0, 0xc($s1)
/* EACF8 802C6348 8C450004 */  lw        $a1, 4($v0)
/* EACFC 802C634C 0C0B1EAF */  jal       get_variable
/* EAD00 802C6350 8C520000 */   lw       $s2, ($v0)
/* EAD04 802C6354 0040802D */  daddu     $s0, $v0, $zero
/* EAD08 802C6358 0220202D */  daddu     $a0, $s1, $zero
/* EAD0C 802C635C 0C0B1EAF */  jal       get_variable
/* EAD10 802C6360 0240282D */   daddu    $a1, $s2, $zero
/* EAD14 802C6364 0220202D */  daddu     $a0, $s1, $zero
/* EAD18 802C6368 0240282D */  daddu     $a1, $s2, $zero
/* EAD1C 802C636C 0C0B2026 */  jal       set_variable
/* EAD20 802C6370 02023025 */   or       $a2, $s0, $v0
/* EAD24 802C6374 8FBF001C */  lw        $ra, 0x1c($sp)
/* EAD28 802C6378 8FB20018 */  lw        $s2, 0x18($sp)
/* EAD2C 802C637C 8FB10014 */  lw        $s1, 0x14($sp)
/* EAD30 802C6380 8FB00010 */  lw        $s0, 0x10($sp)
/* EAD34 802C6384 24020002 */  addiu     $v0, $zero, 2
/* EAD38 802C6388 03E00008 */  jr        $ra
/* EAD3C 802C638C 27BD0020 */   addiu    $sp, $sp, 0x20
