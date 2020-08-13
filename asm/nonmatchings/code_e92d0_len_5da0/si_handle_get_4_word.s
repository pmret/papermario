.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel si_handle_get_4_word
/* 0EA764 802C5DB4 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0EA768 802C5DB8 AFB00010 */  sw    $s0, 0x10($sp)
/* 0EA76C 802C5DBC 0080802D */  daddu $s0, $a0, $zero
/* 0EA770 802C5DC0 AFBF0018 */  sw    $ra, 0x18($sp)
/* 0EA774 802C5DC4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0EA778 802C5DC8 8E11000C */  lw    $s1, 0xc($s0)
/* 0EA77C 802C5DCC 8E020138 */  lw    $v0, 0x138($s0)
/* 0EA780 802C5DD0 8E250000 */  lw    $a1, ($s1)
/* 0EA784 802C5DD4 26310004 */  addiu $s1, $s1, 4
/* 0EA788 802C5DD8 8C460000 */  lw    $a2, ($v0)
/* 0EA78C 802C5DDC 24420004 */  addiu $v0, $v0, 4
/* 0EA790 802C5DE0 0C0B2026 */  jal   set_variable
/* 0EA794 802C5DE4 AE020138 */   sw    $v0, 0x138($s0)
/* 0EA798 802C5DE8 8E250000 */  lw    $a1, ($s1)
/* 0EA79C 802C5DEC 26310004 */  addiu $s1, $s1, 4
/* 0EA7A0 802C5DF0 8E020138 */  lw    $v0, 0x138($s0)
/* 0EA7A4 802C5DF4 0200202D */  daddu $a0, $s0, $zero
/* 0EA7A8 802C5DF8 8C460000 */  lw    $a2, ($v0)
/* 0EA7AC 802C5DFC 24420004 */  addiu $v0, $v0, 4
/* 0EA7B0 802C5E00 0C0B2026 */  jal   set_variable
/* 0EA7B4 802C5E04 AE020138 */   sw    $v0, 0x138($s0)
/* 0EA7B8 802C5E08 8E250000 */  lw    $a1, ($s1)
/* 0EA7BC 802C5E0C 26310004 */  addiu $s1, $s1, 4
/* 0EA7C0 802C5E10 8E020138 */  lw    $v0, 0x138($s0)
/* 0EA7C4 802C5E14 0200202D */  daddu $a0, $s0, $zero
/* 0EA7C8 802C5E18 8C460000 */  lw    $a2, ($v0)
/* 0EA7CC 802C5E1C 24420004 */  addiu $v0, $v0, 4
/* 0EA7D0 802C5E20 0C0B2026 */  jal   set_variable
/* 0EA7D4 802C5E24 AE020138 */   sw    $v0, 0x138($s0)
/* 0EA7D8 802C5E28 0200202D */  daddu $a0, $s0, $zero
/* 0EA7DC 802C5E2C 8C820138 */  lw    $v0, 0x138($a0)
/* 0EA7E0 802C5E30 8E250000 */  lw    $a1, ($s1)
/* 0EA7E4 802C5E34 8C460000 */  lw    $a2, ($v0)
/* 0EA7E8 802C5E38 24420004 */  addiu $v0, $v0, 4
/* 0EA7EC 802C5E3C 0C0B2026 */  jal   set_variable
/* 0EA7F0 802C5E40 AC820138 */   sw    $v0, 0x138($a0)
/* 0EA7F4 802C5E44 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0EA7F8 802C5E48 8FB10014 */  lw    $s1, 0x14($sp)
/* 0EA7FC 802C5E4C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0EA800 802C5E50 24020002 */  addiu $v0, $zero, 2
/* 0EA804 802C5E54 03E00008 */  jr    $ra
/* 0EA808 802C5E58 27BD0020 */   addiu $sp, $sp, 0x20

