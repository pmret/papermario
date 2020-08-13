.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_goto
/* 0E9370 802C49C0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0E9374 802C49C4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E9378 802C49C8 0080802D */  daddu $s0, $a0, $zero
/* 0E937C 802C49CC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0E9380 802C49D0 8E02000C */  lw    $v0, 0xc($s0)
/* 0E9384 802C49D4 0C0B1EAF */  jal   get_variable
/* 0E9388 802C49D8 8C450000 */   lw    $a1, ($v0)
/* 0E938C 802C49DC 0200202D */  daddu $a0, $s0, $zero
/* 0E9390 802C49E0 0C0B2224 */  jal   si_goto_label
/* 0E9394 802C49E4 0040282D */   daddu $a1, $v0, $zero
/* 0E9398 802C49E8 AE020008 */  sw    $v0, 8($s0)
/* 0E939C 802C49EC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0E93A0 802C49F0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E93A4 802C49F4 24020002 */  addiu $v0, $zero, 2
/* 0E93A8 802C49F8 03E00008 */  jr    $ra
/* 0E93AC 802C49FC 27BD0018 */   addiu $sp, $sp, 0x18

