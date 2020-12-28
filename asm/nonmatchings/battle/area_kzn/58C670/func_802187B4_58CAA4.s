.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802187B4_58CAA4
/* 58CAA4 802187B4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 58CAA8 802187B8 AFB10014 */  sw        $s1, 0x14($sp)
/* 58CAAC 802187BC 0080882D */  daddu     $s1, $a0, $zero
/* 58CAB0 802187C0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 58CAB4 802187C4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 58CAB8 802187C8 AFB20018 */  sw        $s2, 0x18($sp)
/* 58CABC 802187CC AFB00010 */  sw        $s0, 0x10($sp)
/* 58CAC0 802187D0 8E30000C */  lw        $s0, 0xc($s1)
/* 58CAC4 802187D4 8E050000 */  lw        $a1, ($s0)
/* 58CAC8 802187D8 0C0B1EAF */  jal       get_variable
/* 58CACC 802187DC 26100004 */   addiu    $s0, $s0, 4
/* 58CAD0 802187E0 8E050000 */  lw        $a1, ($s0)
/* 58CAD4 802187E4 26100004 */  addiu     $s0, $s0, 4
/* 58CAD8 802187E8 0220202D */  daddu     $a0, $s1, $zero
/* 58CADC 802187EC 0C0B1EAF */  jal       get_variable
/* 58CAE0 802187F0 0040982D */   daddu    $s3, $v0, $zero
/* 58CAE4 802187F4 8E050000 */  lw        $a1, ($s0)
/* 58CAE8 802187F8 26100004 */  addiu     $s0, $s0, 4
/* 58CAEC 802187FC 0220202D */  daddu     $a0, $s1, $zero
/* 58CAF0 80218800 0C0B1EAF */  jal       get_variable
/* 58CAF4 80218804 0040902D */   daddu    $s2, $v0, $zero
/* 58CAF8 80218808 0220202D */  daddu     $a0, $s1, $zero
/* 58CAFC 8021880C 8E050000 */  lw        $a1, ($s0)
/* 58CB00 80218810 0C0B1EAF */  jal       get_variable
/* 58CB04 80218814 0040802D */   daddu    $s0, $v0, $zero
/* 58CB08 80218818 8E240148 */  lw        $a0, 0x148($s1)
/* 58CB0C 8021881C 0C09A75B */  jal       get_actor
/* 58CB10 80218820 0040882D */   daddu    $s1, $v0, $zero
/* 58CB14 80218824 0040182D */  daddu     $v1, $v0, $zero
/* 58CB18 80218828 8C620008 */  lw        $v0, 8($v1)
/* 58CB1C 8021882C 90420024 */  lbu       $v0, 0x24($v0)
/* 58CB20 80218830 8C640008 */  lw        $a0, 8($v1)
/* 58CB24 80218834 02629823 */  subu      $s3, $s3, $v0
/* 58CB28 80218838 A0730194 */  sb        $s3, 0x194($v1)
/* 58CB2C 8021883C 90820025 */  lbu       $v0, 0x25($a0)
/* 58CB30 80218840 02429023 */  subu      $s2, $s2, $v0
/* 58CB34 80218844 A0720195 */  sb        $s2, 0x195($v1)
/* 58CB38 80218848 90820026 */  lbu       $v0, 0x26($a0)
/* 58CB3C 8021884C 02028023 */  subu      $s0, $s0, $v0
/* 58CB40 80218850 A0700196 */  sb        $s0, 0x196($v1)
/* 58CB44 80218854 90840027 */  lbu       $a0, 0x27($a0)
/* 58CB48 80218858 02248823 */  subu      $s1, $s1, $a0
/* 58CB4C 8021885C A0710197 */  sb        $s1, 0x197($v1)
/* 58CB50 80218860 8FBF0020 */  lw        $ra, 0x20($sp)
/* 58CB54 80218864 8FB3001C */  lw        $s3, 0x1c($sp)
/* 58CB58 80218868 8FB20018 */  lw        $s2, 0x18($sp)
/* 58CB5C 8021886C 8FB10014 */  lw        $s1, 0x14($sp)
/* 58CB60 80218870 8FB00010 */  lw        $s0, 0x10($sp)
/* 58CB64 80218874 24020002 */  addiu     $v0, $zero, 2
/* 58CB68 80218878 03E00008 */  jr        $ra
/* 58CB6C 8021887C 27BD0028 */   addiu    $sp, $sp, 0x28
