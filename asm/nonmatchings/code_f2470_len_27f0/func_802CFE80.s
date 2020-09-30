.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802CFE80
/* F4830 802CFE80 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F4834 802CFE84 AFB10014 */  sw        $s1, 0x14($sp)
/* F4838 802CFE88 0080882D */  daddu     $s1, $a0, $zero
/* F483C 802CFE8C AFBF0018 */  sw        $ra, 0x18($sp)
/* F4840 802CFE90 AFB00010 */  sw        $s0, 0x10($sp)
/* F4844 802CFE94 8E30000C */  lw        $s0, 0xc($s1)
/* F4848 802CFE98 8E050000 */  lw        $a1, ($s0)
/* F484C 802CFE9C 0C0B1EAF */  jal       get_variable
/* F4850 802CFEA0 26100004 */   addiu    $s0, $s0, 4
/* F4854 802CFEA4 0220202D */  daddu     $a0, $s1, $zero
/* F4858 802CFEA8 8E050000 */  lw        $a1, ($s0)
/* F485C 802CFEAC 0C0B1EAF */  jal       get_variable
/* F4860 802CFEB0 0040802D */   daddu    $s0, $v0, $zero
/* F4864 802CFEB4 0220202D */  daddu     $a0, $s1, $zero
/* F4868 802CFEB8 0200282D */  daddu     $a1, $s0, $zero
/* F486C 802CFEBC 0C0B36B0 */  jal       resolve_npc
/* F4870 802CFEC0 0040802D */   daddu    $s0, $v0, $zero
/* F4874 802CFEC4 10400003 */  beqz      $v0, .L802CFED4
/* F4878 802CFEC8 0040202D */   daddu    $a0, $v0, $zero
/* F487C 802CFECC 0C00ECF4 */  jal       func_8003B3D0
/* F4880 802CFED0 0200282D */   daddu    $a1, $s0, $zero
.L802CFED4:
/* F4884 802CFED4 24020002 */  addiu     $v0, $zero, 2
/* F4888 802CFED8 8FBF0018 */  lw        $ra, 0x18($sp)
/* F488C 802CFEDC 8FB10014 */  lw        $s1, 0x14($sp)
/* F4890 802CFEE0 8FB00010 */  lw        $s0, 0x10($sp)
/* F4894 802CFEE4 03E00008 */  jr        $ra
/* F4898 802CFEE8 27BD0020 */   addiu    $sp, $sp, 0x20
