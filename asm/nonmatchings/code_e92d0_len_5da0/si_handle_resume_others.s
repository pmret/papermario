.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_resume_others
/* 0EB394 802C69E4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EB398 802C69E8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EB39C 802C69EC 0080802D */  daddu $s0, $a0, $zero
/* 0EB3A0 802C69F0 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EB3A4 802C69F4 8E02000C */  lw    $v0, 0xc($s0)
/* 0EB3A8 802C69F8 0C0B1EAF */  jal   get_variable
/* 0EB3AC 802C69FC 8C450000 */   lw    $a1, ($v0)
/* 0EB3B0 802C6A00 0200202D */  daddu $a0, $s0, $zero
/* 0EB3B4 802C6A04 0C0B11C7 */  jal   resume_group_others
/* 0EB3B8 802C6A08 0040282D */   daddu $a1, $v0, $zero
/* 0EB3BC 802C6A0C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0EB3C0 802C6A10 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EB3C4 802C6A14 24020002 */  addiu $v0, $zero, 2
/* 0EB3C8 802C6A18 03E00008 */  jr    $ra
/* 0EB3CC 802C6A1C 27BD0018 */   addiu $sp, $sp, 0x18

