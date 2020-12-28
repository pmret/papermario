.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219A80_66B800
/* 66B800 80219A80 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 66B804 80219A84 AFB10014 */  sw        $s1, 0x14($sp)
/* 66B808 80219A88 0080882D */  daddu     $s1, $a0, $zero
/* 66B80C 80219A8C AFBF0018 */  sw        $ra, 0x18($sp)
/* 66B810 80219A90 AFB00010 */  sw        $s0, 0x10($sp)
/* 66B814 80219A94 8E30000C */  lw        $s0, 0xc($s1)
/* 66B818 80219A98 8E050000 */  lw        $a1, ($s0)
/* 66B81C 80219A9C 0C0B1EAF */  jal       get_variable
/* 66B820 80219AA0 26100004 */   addiu    $s0, $s0, 4
/* 66B824 80219AA4 0220202D */  daddu     $a0, $s1, $zero
/* 66B828 80219AA8 8E050000 */  lw        $a1, ($s0)
/* 66B82C 80219AAC 0C0B1EAF */  jal       get_variable
/* 66B830 80219AB0 0040802D */   daddu    $s0, $v0, $zero
/* 66B834 80219AB4 0200202D */  daddu     $a0, $s0, $zero
/* 66B838 80219AB8 0C00A3C2 */  jal       start_rumble
/* 66B83C 80219ABC 0040282D */   daddu    $a1, $v0, $zero
/* 66B840 80219AC0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 66B844 80219AC4 8FB10014 */  lw        $s1, 0x14($sp)
/* 66B848 80219AC8 8FB00010 */  lw        $s0, 0x10($sp)
/* 66B84C 80219ACC 24020002 */  addiu     $v0, $zero, 2
/* 66B850 80219AD0 03E00008 */  jr        $ra
/* 66B854 80219AD4 27BD0020 */   addiu    $sp, $sp, 0x20
