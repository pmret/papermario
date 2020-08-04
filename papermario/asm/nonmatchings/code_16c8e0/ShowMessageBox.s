.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel ShowMessageBox
/* 17FB94 802512B4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 17FB98 802512B8 AFB10014 */  sw    $s1, 0x14($sp)
/* 17FB9C 802512BC 0080882D */  daddu $s1, $a0, $zero
/* 17FBA0 802512C0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 17FBA4 802512C4 AFB00010 */  sw    $s0, 0x10($sp)
/* 17FBA8 802512C8 8E30000C */  lw    $s0, 0xc($s1)
/* 17FBAC 802512CC 8E050000 */  lw    $a1, ($s0)
/* 17FBB0 802512D0 0C0B1EAF */  jal   get_variable
/* 17FBB4 802512D4 26100004 */   addiu $s0, $s0, 4
/* 17FBB8 802512D8 0220202D */  daddu $a0, $s1, $zero
/* 17FBBC 802512DC 8E050000 */  lw    $a1, ($s0)
/* 17FBC0 802512E0 0C0B1EAF */  jal   get_variable
/* 17FBC4 802512E4 0040802D */   daddu $s0, $v0, $zero
/* 17FBC8 802512E8 0200202D */  daddu $a0, $s0, $zero
/* 17FBCC 802512EC 0C093E58 */  jal   show_battle_message
/* 17FBD0 802512F0 0040282D */   daddu $a1, $v0, $zero
/* 17FBD4 802512F4 8FBF0018 */  lw    $ra, 0x18($sp)
/* 17FBD8 802512F8 8FB10014 */  lw    $s1, 0x14($sp)
/* 17FBDC 802512FC 8FB00010 */  lw    $s0, 0x10($sp)
/* 17FBE0 80251300 24020002 */  addiu $v0, $zero, 2
/* 17FBE4 80251304 03E00008 */  jr    $ra
/* 17FBE8 80251308 27BD0020 */   addiu $sp, $sp, 0x20

