.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel AddBadge
/* 0FB9A8 802D6FF8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FB9AC 802D6FFC AFB10014 */  sw    $s1, 0x14($sp)
/* 0FB9B0 802D7000 0080882D */  daddu $s1, $a0, $zero
/* 0FB9B4 802D7004 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FB9B8 802D7008 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FB9BC 802D700C 8E30000C */  lw    $s0, 0xc($s1)
/* 0FB9C0 802D7010 8E050000 */  lw    $a1, ($s0)
/* 0FB9C4 802D7014 0C0B1EAF */  jal   get_variable
/* 0FB9C8 802D7018 26100004 */   addiu $s0, $s0, 4
/* 0FB9CC 802D701C 8E100000 */  lw    $s0, ($s0)
/* 0FB9D0 802D7020 0C039DCF */  jal   add_badge
/* 0FB9D4 802D7024 0040202D */   daddu $a0, $v0, $zero
/* 0FB9D8 802D7028 0220202D */  daddu $a0, $s1, $zero
/* 0FB9DC 802D702C 0040302D */  daddu $a2, $v0, $zero
/* 0FB9E0 802D7030 0C0B2026 */  jal   set_variable
/* 0FB9E4 802D7034 0200282D */   daddu $a1, $s0, $zero
/* 0FB9E8 802D7038 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FB9EC 802D703C 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FB9F0 802D7040 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FB9F4 802D7044 24020002 */  addiu $v0, $zero, 2
/* 0FB9F8 802D7048 03E00008 */  jr    $ra
/* 0FB9FC 802D704C 27BD0020 */   addiu $sp, $sp, 0x20

