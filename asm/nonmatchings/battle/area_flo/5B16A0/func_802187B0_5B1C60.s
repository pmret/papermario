.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802187B0_5B1C60
/* 5B1C60 802187B0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 5B1C64 802187B4 AFB10014 */  sw        $s1, 0x14($sp)
/* 5B1C68 802187B8 0080882D */  daddu     $s1, $a0, $zero
/* 5B1C6C 802187BC AFBF0018 */  sw        $ra, 0x18($sp)
/* 5B1C70 802187C0 AFB00010 */  sw        $s0, 0x10($sp)
/* 5B1C74 802187C4 8E30000C */  lw        $s0, 0xc($s1)
/* 5B1C78 802187C8 8E050000 */  lw        $a1, ($s0)
/* 5B1C7C 802187CC 0C0B1EAF */  jal       get_variable
/* 5B1C80 802187D0 26100004 */   addiu    $s0, $s0, 4
/* 5B1C84 802187D4 0220202D */  daddu     $a0, $s1, $zero
/* 5B1C88 802187D8 8E050000 */  lw        $a1, ($s0)
/* 5B1C8C 802187DC 0C0B1EAF */  jal       get_variable
/* 5B1C90 802187E0 0040802D */   daddu    $s0, $v0, $zero
/* 5B1C94 802187E4 0200202D */  daddu     $a0, $s0, $zero
/* 5B1C98 802187E8 0C00A3C2 */  jal       start_rumble
/* 5B1C9C 802187EC 0040282D */   daddu    $a1, $v0, $zero
/* 5B1CA0 802187F0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 5B1CA4 802187F4 8FB10014 */  lw        $s1, 0x14($sp)
/* 5B1CA8 802187F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 5B1CAC 802187FC 24020002 */  addiu     $v0, $zero, 2
/* 5B1CB0 80218800 03E00008 */  jr        $ra
/* 5B1CB4 80218804 27BD0020 */   addiu    $sp, $sp, 0x20
