.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_set_priority
/* 0EB24C 802C689C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0EB250 802C68A0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EB254 802C68A4 0080802D */  daddu $s0, $a0, $zero
/* 0EB258 802C68A8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0EB25C 802C68AC 8E02000C */  lw    $v0, 0xc($s0)
/* 0EB260 802C68B0 0C0B1EAF */  jal   get_variable
/* 0EB264 802C68B4 8C450000 */   lw    $a1, ($v0)
/* 0EB268 802C68B8 0200202D */  daddu $a0, $s0, $zero
/* 0EB26C 802C68BC 0C0B1076 */  jal   set_script_priority
/* 0EB270 802C68C0 0040282D */   daddu $a1, $v0, $zero
/* 0EB274 802C68C4 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0EB278 802C68C8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EB27C 802C68CC 24020002 */  addiu $v0, $zero, 2
/* 0EB280 802C68D0 03E00008 */  jr    $ra
/* 0EB284 802C68D4 27BD0018 */   addiu $sp, $sp, 0x18

