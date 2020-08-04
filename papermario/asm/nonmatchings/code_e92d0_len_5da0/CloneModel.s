.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel CloneModel
/* 0ED8D8 802C8F28 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0ED8DC 802C8F2C AFB10014 */  sw    $s1, 0x14($sp)
/* 0ED8E0 802C8F30 0080882D */  daddu $s1, $a0, $zero
/* 0ED8E4 802C8F34 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0ED8E8 802C8F38 AFB00010 */  sw    $s0, 0x10($sp)
/* 0ED8EC 802C8F3C 8E30000C */  lw    $s0, 0xc($s1)
/* 0ED8F0 802C8F40 8E050000 */  lw    $a1, ($s0)
/* 0ED8F4 802C8F44 0C0B1EAF */  jal   get_variable
/* 0ED8F8 802C8F48 26100004 */   addiu $s0, $s0, 4
/* 0ED8FC 802C8F4C 0220202D */  daddu $a0, $s1, $zero
/* 0ED900 802C8F50 8E050000 */  lw    $a1, ($s0)
/* 0ED904 802C8F54 0C0B1EAF */  jal   get_variable
/* 0ED908 802C8F58 0040802D */   daddu $s0, $v0, $zero
/* 0ED90C 802C8F5C 3204FFFF */  andi  $a0, $s0, 0xffff
/* 0ED910 802C8F60 0C046DBC */  jal   clone_model
/* 0ED914 802C8F64 3045FFFF */   andi  $a1, $v0, 0xffff
/* 0ED918 802C8F68 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0ED91C 802C8F6C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0ED920 802C8F70 8FB00010 */  lw    $s0, 0x10($sp)
/* 0ED924 802C8F74 24020002 */  addiu $v0, $zero, 2
/* 0ED928 802C8F78 03E00008 */  jr    $ra
/* 0ED92C 802C8F7C 27BD0020 */   addiu $sp, $sp, 0x20

