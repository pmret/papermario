.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel CountFortessKeys
/* 0FB5FC 802D6C4C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0FB600 802D6C50 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FB604 802D6C54 0080802D */  daddu $s0, $a0, $zero
/* 0FB608 802D6C58 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0FB60C 802D6C5C AFB10014 */  sw    $s1, 0x14($sp)
/* 0FB610 802D6C60 8E02000C */  lw    $v0, 0xc($s0)
/* 0FB614 802D6C64 0C03A8F9 */  jal   get_fortress_key_count
/* 0FB618 802D6C68 8C510000 */   lw    $s1, ($v0)
/* 0FB61C 802D6C6C 0200202D */  daddu $a0, $s0, $zero
/* 0FB620 802D6C70 0040302D */  daddu $a2, $v0, $zero
/* 0FB624 802D6C74 0C0B2026 */  jal   set_variable
/* 0FB628 802D6C78 0220282D */   daddu $a1, $s1, $zero
/* 0FB62C 802D6C7C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0FB630 802D6C80 8FB10014 */  lw    $s1, 0x14($sp)
/* 0FB634 802D6C84 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FB638 802D6C88 24020002 */  addiu $v0, $zero, 2
/* 0FB63C 802D6C8C 03E00008 */  jr    $ra
/* 0FB640 802D6C90 27BD0020 */   addiu $sp, $sp, 0x20

