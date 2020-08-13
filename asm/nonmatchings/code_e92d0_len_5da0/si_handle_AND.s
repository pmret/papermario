.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_AND
/* 0EAC20 802C6270 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EAC24 802C6274 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EAC28 802C6278 0080882D */  daddu $s1, $a0, $zero
/* 0EAC2C 802C627C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0EAC30 802C6280 AFB20018 */  sw    $s2, 0x18($sp)
/* 0EAC34 802C6284 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EAC38 802C6288 8E22000C */  lw    $v0, 0xc($s1)
/* 0EAC3C 802C628C 8C450004 */  lw    $a1, 4($v0)
/* 0EAC40 802C6290 0C0B1EAF */  jal   get_variable
/* 0EAC44 802C6294 8C520000 */   lw    $s2, ($v0)
/* 0EAC48 802C6298 0040802D */  daddu $s0, $v0, $zero
/* 0EAC4C 802C629C 0220202D */  daddu $a0, $s1, $zero
/* 0EAC50 802C62A0 0C0B1EAF */  jal   get_variable
/* 0EAC54 802C62A4 0240282D */   daddu $a1, $s2, $zero
/* 0EAC58 802C62A8 0220202D */  daddu $a0, $s1, $zero
/* 0EAC5C 802C62AC 0240282D */  daddu $a1, $s2, $zero
/* 0EAC60 802C62B0 0C0B2026 */  jal   set_variable
/* 0EAC64 802C62B4 02023024 */   and   $a2, $s0, $v0
/* 0EAC68 802C62B8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0EAC6C 802C62BC 8FB20018 */  lw    $s2, 0x18($sp)
/* 0EAC70 802C62C0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EAC74 802C62C4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EAC78 802C62C8 24020002 */  addiu $v0, $zero, 2
/* 0EAC7C 802C62CC 03E00008 */  jr    $ra
/* 0EAC80 802C62D0 27BD0020 */   addiu $sp, $sp, 0x20

