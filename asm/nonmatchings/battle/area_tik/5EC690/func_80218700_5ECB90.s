.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218700_5ECB90
/* 5ECB90 80218700 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 5ECB94 80218704 AFB10014 */  sw        $s1, 0x14($sp)
/* 5ECB98 80218708 0080882D */  daddu     $s1, $a0, $zero
/* 5ECB9C 8021870C AFBF0018 */  sw        $ra, 0x18($sp)
/* 5ECBA0 80218710 AFB00010 */  sw        $s0, 0x10($sp)
/* 5ECBA4 80218714 8E30000C */  lw        $s0, 0xc($s1)
/* 5ECBA8 80218718 8E050000 */  lw        $a1, ($s0)
/* 5ECBAC 8021871C 0C0B1EAF */  jal       get_variable
/* 5ECBB0 80218720 26100004 */   addiu    $s0, $s0, 4
/* 5ECBB4 80218724 0220202D */  daddu     $a0, $s1, $zero
/* 5ECBB8 80218728 8E050000 */  lw        $a1, ($s0)
/* 5ECBBC 8021872C 0C0B1EAF */  jal       get_variable
/* 5ECBC0 80218730 0040802D */   daddu    $s0, $v0, $zero
/* 5ECBC4 80218734 0200202D */  daddu     $a0, $s0, $zero
/* 5ECBC8 80218738 0C00A3C2 */  jal       start_rumble
/* 5ECBCC 8021873C 0040282D */   daddu    $a1, $v0, $zero
/* 5ECBD0 80218740 8FBF0018 */  lw        $ra, 0x18($sp)
/* 5ECBD4 80218744 8FB10014 */  lw        $s1, 0x14($sp)
/* 5ECBD8 80218748 8FB00010 */  lw        $s0, 0x10($sp)
/* 5ECBDC 8021874C 24020002 */  addiu     $v0, $zero, 2
/* 5ECBE0 80218750 03E00008 */  jr        $ra
/* 5ECBE4 80218754 27BD0020 */   addiu    $sp, $sp, 0x20
