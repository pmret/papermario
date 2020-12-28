.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802184A0_56E740
/* 56E740 802184A0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 56E744 802184A4 AFB10014 */  sw        $s1, 0x14($sp)
/* 56E748 802184A8 0080882D */  daddu     $s1, $a0, $zero
/* 56E74C 802184AC AFBF0018 */  sw        $ra, 0x18($sp)
/* 56E750 802184B0 AFB00010 */  sw        $s0, 0x10($sp)
/* 56E754 802184B4 8E30000C */  lw        $s0, 0xc($s1)
/* 56E758 802184B8 8E050000 */  lw        $a1, ($s0)
/* 56E75C 802184BC 0C0B1EAF */  jal       get_variable
/* 56E760 802184C0 26100004 */   addiu    $s0, $s0, 4
/* 56E764 802184C4 0220202D */  daddu     $a0, $s1, $zero
/* 56E768 802184C8 8E050000 */  lw        $a1, ($s0)
/* 56E76C 802184CC 0C0B1EAF */  jal       get_variable
/* 56E770 802184D0 0040802D */   daddu    $s0, $v0, $zero
/* 56E774 802184D4 0200202D */  daddu     $a0, $s0, $zero
/* 56E778 802184D8 0C00A3C2 */  jal       start_rumble
/* 56E77C 802184DC 0040282D */   daddu    $a1, $v0, $zero
/* 56E780 802184E0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 56E784 802184E4 8FB10014 */  lw        $s1, 0x14($sp)
/* 56E788 802184E8 8FB00010 */  lw        $s0, 0x10($sp)
/* 56E78C 802184EC 24020002 */  addiu     $v0, $zero, 2
/* 56E790 802184F0 03E00008 */  jr        $ra
/* 56E794 802184F4 27BD0020 */   addiu    $sp, $sp, 0x20
