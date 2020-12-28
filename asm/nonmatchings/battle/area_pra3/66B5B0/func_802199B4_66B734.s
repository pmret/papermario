.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802199B4_66B734
/* 66B734 802199B4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 66B738 802199B8 AFB10014 */  sw        $s1, 0x14($sp)
/* 66B73C 802199BC 0080882D */  daddu     $s1, $a0, $zero
/* 66B740 802199C0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 66B744 802199C4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 66B748 802199C8 AFB20018 */  sw        $s2, 0x18($sp)
/* 66B74C 802199CC AFB00010 */  sw        $s0, 0x10($sp)
/* 66B750 802199D0 8E30000C */  lw        $s0, 0xc($s1)
/* 66B754 802199D4 8E050000 */  lw        $a1, ($s0)
/* 66B758 802199D8 0C0B1EAF */  jal       get_variable
/* 66B75C 802199DC 26100004 */   addiu    $s0, $s0, 4
/* 66B760 802199E0 8E050000 */  lw        $a1, ($s0)
/* 66B764 802199E4 26100004 */  addiu     $s0, $s0, 4
/* 66B768 802199E8 0220202D */  daddu     $a0, $s1, $zero
/* 66B76C 802199EC 0C0B1EAF */  jal       get_variable
/* 66B770 802199F0 0040982D */   daddu    $s3, $v0, $zero
/* 66B774 802199F4 8E050000 */  lw        $a1, ($s0)
/* 66B778 802199F8 26100004 */  addiu     $s0, $s0, 4
/* 66B77C 802199FC 0220202D */  daddu     $a0, $s1, $zero
/* 66B780 80219A00 0C0B1EAF */  jal       get_variable
/* 66B784 80219A04 0040902D */   daddu    $s2, $v0, $zero
/* 66B788 80219A08 0220202D */  daddu     $a0, $s1, $zero
/* 66B78C 80219A0C 8E050000 */  lw        $a1, ($s0)
/* 66B790 80219A10 0C0B1EAF */  jal       get_variable
/* 66B794 80219A14 0040802D */   daddu    $s0, $v0, $zero
/* 66B798 80219A18 8E240148 */  lw        $a0, 0x148($s1)
/* 66B79C 80219A1C 0C09A75B */  jal       get_actor
/* 66B7A0 80219A20 0040882D */   daddu    $s1, $v0, $zero
/* 66B7A4 80219A24 0040182D */  daddu     $v1, $v0, $zero
/* 66B7A8 80219A28 8C620008 */  lw        $v0, 8($v1)
/* 66B7AC 80219A2C 90420024 */  lbu       $v0, 0x24($v0)
/* 66B7B0 80219A30 8C640008 */  lw        $a0, 8($v1)
/* 66B7B4 80219A34 02629823 */  subu      $s3, $s3, $v0
/* 66B7B8 80219A38 A0730194 */  sb        $s3, 0x194($v1)
/* 66B7BC 80219A3C 90820025 */  lbu       $v0, 0x25($a0)
/* 66B7C0 80219A40 02429023 */  subu      $s2, $s2, $v0
/* 66B7C4 80219A44 A0720195 */  sb        $s2, 0x195($v1)
/* 66B7C8 80219A48 90820026 */  lbu       $v0, 0x26($a0)
/* 66B7CC 80219A4C 02028023 */  subu      $s0, $s0, $v0
/* 66B7D0 80219A50 A0700196 */  sb        $s0, 0x196($v1)
/* 66B7D4 80219A54 90840027 */  lbu       $a0, 0x27($a0)
/* 66B7D8 80219A58 02248823 */  subu      $s1, $s1, $a0
/* 66B7DC 80219A5C A0710197 */  sb        $s1, 0x197($v1)
/* 66B7E0 80219A60 8FBF0020 */  lw        $ra, 0x20($sp)
/* 66B7E4 80219A64 8FB3001C */  lw        $s3, 0x1c($sp)
/* 66B7E8 80219A68 8FB20018 */  lw        $s2, 0x18($sp)
/* 66B7EC 80219A6C 8FB10014 */  lw        $s1, 0x14($sp)
/* 66B7F0 80219A70 8FB00010 */  lw        $s0, 0x10($sp)
/* 66B7F4 80219A74 24020002 */  addiu     $v0, $zero, 2
/* 66B7F8 80219A78 03E00008 */  jr        $ra
/* 66B7FC 80219A7C 27BD0028 */   addiu    $sp, $sp, 0x28
