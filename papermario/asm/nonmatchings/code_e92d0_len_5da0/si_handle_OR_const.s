.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_OR_const
/* 0EAD40 802C6390 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EAD44 802C6394 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EAD48 802C6398 0080882D */  daddu $s1, $a0, $zero
/* 0EAD4C 802C639C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EAD50 802C63A0 AFB20018 */  sw    $s2, 0x18($sp)
/* 0EAD54 802C63A4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EAD58 802C63A8 8E22000C */  lw    $v0, 0xc($s1)
/* 0EAD5C 802C63AC 8C520000 */  lw    $s2, ($v0)
/* 0EAD60 802C63B0 8C500004 */  lw    $s0, 4($v0)
/* 0EAD64 802C63B4 0C0B1EAF */  jal   get_variable
/* 0EAD68 802C63B8 0240282D */   daddu $a1, $s2, $zero
/* 0EAD6C 802C63BC 0220202D */  daddu $a0, $s1, $zero
/* 0EAD70 802C63C0 0240282D */  daddu $a1, $s2, $zero
/* 0EAD74 802C63C4 0C0B2026 */  jal   set_variable
/* 0EAD78 802C63C8 02023025 */   or    $a2, $s0, $v0
/* 0EAD7C 802C63CC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EAD80 802C63D0 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EAD84 802C63D4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EAD88 802C63D8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EAD8C 802C63DC 24020002 */  addiu $v0, $zero, 2
/* 0EAD90 802C63E0 03E00008 */  jr    $ra
/* 0EAD94 802C63E4 27BD0020 */   addiu $sp, $sp, 0x20

