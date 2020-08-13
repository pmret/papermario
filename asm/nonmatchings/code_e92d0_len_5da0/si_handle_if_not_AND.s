.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel si_handle_if_not_AND
/* 0E9898 802C4EE8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0E989C 802C4EEC AFB10014 */  sw    $s1, 0x14($sp)
/* 0E98A0 802C4EF0 0080882D */  daddu $s1, $a0, $zero
/* 0E98A4 802C4EF4 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0E98A8 802C4EF8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E98AC 802C4EFC 8E30000C */  lw    $s0, 0xc($s1)
/* 0E98B0 802C4F00 8E050000 */  lw    $a1, ($s0)
/* 0E98B4 802C4F04 0C0B1EAF */  jal   get_variable
/* 0E98B8 802C4F08 26100004 */   addiu $s0, $s0, 4
/* 0E98BC 802C4F0C 8E030000 */  lw    $v1, ($s0)
/* 0E98C0 802C4F10 00431024 */  and   $v0, $v0, $v1
/* 0E98C4 802C4F14 10400005 */  beqz  $v0, .L802C4F2C
/* 0E98C8 802C4F18 24020002 */   addiu $v0, $zero, 2
/* 0E98CC 802C4F1C 0C0B223F */  jal   si_skip_if
/* 0E98D0 802C4F20 0220202D */   daddu $a0, $s1, $zero
/* 0E98D4 802C4F24 AE220008 */  sw    $v0, 8($s1)
/* 0E98D8 802C4F28 24020002 */  addiu $v0, $zero, 2
.L802C4F2C:
/* 0E98DC 802C4F2C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0E98E0 802C4F30 8FB10014 */  lw    $s1, 0x14($sp)
/* 0E98E4 802C4F34 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E98E8 802C4F38 03E00008 */  jr    $ra
/* 0E98EC 802C4F3C 27BD0020 */   addiu $sp, $sp, 0x20

