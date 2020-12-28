.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802187E0_48D980
/* 48D980 802187E0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 48D984 802187E4 AFB10014 */  sw        $s1, 0x14($sp)
/* 48D988 802187E8 0080882D */  daddu     $s1, $a0, $zero
/* 48D98C 802187EC AFBF0020 */  sw        $ra, 0x20($sp)
/* 48D990 802187F0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 48D994 802187F4 AFB20018 */  sw        $s2, 0x18($sp)
/* 48D998 802187F8 AFB00010 */  sw        $s0, 0x10($sp)
/* 48D99C 802187FC 8E30000C */  lw        $s0, 0xc($s1)
/* 48D9A0 80218800 8E050000 */  lw        $a1, ($s0)
/* 48D9A4 80218804 0C0B1EAF */  jal       get_variable
/* 48D9A8 80218808 26100004 */   addiu    $s0, $s0, 4
/* 48D9AC 8021880C 8E050000 */  lw        $a1, ($s0)
/* 48D9B0 80218810 26100004 */  addiu     $s0, $s0, 4
/* 48D9B4 80218814 0220202D */  daddu     $a0, $s1, $zero
/* 48D9B8 80218818 0C0B1EAF */  jal       get_variable
/* 48D9BC 8021881C 0040982D */   daddu    $s3, $v0, $zero
/* 48D9C0 80218820 8E050000 */  lw        $a1, ($s0)
/* 48D9C4 80218824 26100004 */  addiu     $s0, $s0, 4
/* 48D9C8 80218828 0220202D */  daddu     $a0, $s1, $zero
/* 48D9CC 8021882C 0C0B1EAF */  jal       get_variable
/* 48D9D0 80218830 0040902D */   daddu    $s2, $v0, $zero
/* 48D9D4 80218834 0220202D */  daddu     $a0, $s1, $zero
/* 48D9D8 80218838 8E050000 */  lw        $a1, ($s0)
/* 48D9DC 8021883C 0C0B1EAF */  jal       get_variable
/* 48D9E0 80218840 0040802D */   daddu    $s0, $v0, $zero
/* 48D9E4 80218844 8E240148 */  lw        $a0, 0x148($s1)
/* 48D9E8 80218848 0C09A75B */  jal       get_actor
/* 48D9EC 8021884C 0040882D */   daddu    $s1, $v0, $zero
/* 48D9F0 80218850 0040182D */  daddu     $v1, $v0, $zero
/* 48D9F4 80218854 8C620008 */  lw        $v0, 8($v1)
/* 48D9F8 80218858 90420024 */  lbu       $v0, 0x24($v0)
/* 48D9FC 8021885C 8C640008 */  lw        $a0, 8($v1)
/* 48DA00 80218860 02629823 */  subu      $s3, $s3, $v0
/* 48DA04 80218864 A0730194 */  sb        $s3, 0x194($v1)
/* 48DA08 80218868 90820025 */  lbu       $v0, 0x25($a0)
/* 48DA0C 8021886C 02429023 */  subu      $s2, $s2, $v0
/* 48DA10 80218870 A0720195 */  sb        $s2, 0x195($v1)
/* 48DA14 80218874 90820026 */  lbu       $v0, 0x26($a0)
/* 48DA18 80218878 02028023 */  subu      $s0, $s0, $v0
/* 48DA1C 8021887C A0700196 */  sb        $s0, 0x196($v1)
/* 48DA20 80218880 90840027 */  lbu       $a0, 0x27($a0)
/* 48DA24 80218884 02248823 */  subu      $s1, $s1, $a0
/* 48DA28 80218888 A0710197 */  sb        $s1, 0x197($v1)
/* 48DA2C 8021888C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 48DA30 80218890 8FB3001C */  lw        $s3, 0x1c($sp)
/* 48DA34 80218894 8FB20018 */  lw        $s2, 0x18($sp)
/* 48DA38 80218898 8FB10014 */  lw        $s1, 0x14($sp)
/* 48DA3C 8021889C 8FB00010 */  lw        $s0, 0x10($sp)
/* 48DA40 802188A0 24020002 */  addiu     $v0, $zero, 2
/* 48DA44 802188A4 03E00008 */  jr        $ra
/* 48DA48 802188A8 27BD0028 */   addiu    $sp, $sp, 0x28
/* 48DA4C 802188AC 00000000 */  nop       
