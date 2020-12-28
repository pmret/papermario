.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802186C0_512C90
/* 512C90 802186C0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 512C94 802186C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 512C98 802186C8 0080882D */  daddu     $s1, $a0, $zero
/* 512C9C 802186CC AFBF0020 */  sw        $ra, 0x20($sp)
/* 512CA0 802186D0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 512CA4 802186D4 AFB20018 */  sw        $s2, 0x18($sp)
/* 512CA8 802186D8 AFB00010 */  sw        $s0, 0x10($sp)
/* 512CAC 802186DC 8E30000C */  lw        $s0, 0xc($s1)
/* 512CB0 802186E0 8E050000 */  lw        $a1, ($s0)
/* 512CB4 802186E4 0C0B1EAF */  jal       get_variable
/* 512CB8 802186E8 26100004 */   addiu    $s0, $s0, 4
/* 512CBC 802186EC 8E050000 */  lw        $a1, ($s0)
/* 512CC0 802186F0 26100004 */  addiu     $s0, $s0, 4
/* 512CC4 802186F4 0220202D */  daddu     $a0, $s1, $zero
/* 512CC8 802186F8 0C0B1EAF */  jal       get_variable
/* 512CCC 802186FC 0040982D */   daddu    $s3, $v0, $zero
/* 512CD0 80218700 8E050000 */  lw        $a1, ($s0)
/* 512CD4 80218704 26100004 */  addiu     $s0, $s0, 4
/* 512CD8 80218708 0220202D */  daddu     $a0, $s1, $zero
/* 512CDC 8021870C 0C0B1EAF */  jal       get_variable
/* 512CE0 80218710 0040902D */   daddu    $s2, $v0, $zero
/* 512CE4 80218714 0220202D */  daddu     $a0, $s1, $zero
/* 512CE8 80218718 8E050000 */  lw        $a1, ($s0)
/* 512CEC 8021871C 0C0B1EAF */  jal       get_variable
/* 512CF0 80218720 0040802D */   daddu    $s0, $v0, $zero
/* 512CF4 80218724 8E240148 */  lw        $a0, 0x148($s1)
/* 512CF8 80218728 0C09A75B */  jal       get_actor
/* 512CFC 8021872C 0040882D */   daddu    $s1, $v0, $zero
/* 512D00 80218730 0040182D */  daddu     $v1, $v0, $zero
/* 512D04 80218734 8C620008 */  lw        $v0, 8($v1)
/* 512D08 80218738 90420024 */  lbu       $v0, 0x24($v0)
/* 512D0C 8021873C 8C640008 */  lw        $a0, 8($v1)
/* 512D10 80218740 02629823 */  subu      $s3, $s3, $v0
/* 512D14 80218744 A0730194 */  sb        $s3, 0x194($v1)
/* 512D18 80218748 90820025 */  lbu       $v0, 0x25($a0)
/* 512D1C 8021874C 02429023 */  subu      $s2, $s2, $v0
/* 512D20 80218750 A0720195 */  sb        $s2, 0x195($v1)
/* 512D24 80218754 90820026 */  lbu       $v0, 0x26($a0)
/* 512D28 80218758 02028023 */  subu      $s0, $s0, $v0
/* 512D2C 8021875C A0700196 */  sb        $s0, 0x196($v1)
/* 512D30 80218760 90840027 */  lbu       $a0, 0x27($a0)
/* 512D34 80218764 02248823 */  subu      $s1, $s1, $a0
/* 512D38 80218768 A0710197 */  sb        $s1, 0x197($v1)
/* 512D3C 8021876C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 512D40 80218770 8FB3001C */  lw        $s3, 0x1c($sp)
/* 512D44 80218774 8FB20018 */  lw        $s2, 0x18($sp)
/* 512D48 80218778 8FB10014 */  lw        $s1, 0x14($sp)
/* 512D4C 8021877C 8FB00010 */  lw        $s0, 0x10($sp)
/* 512D50 80218780 24020002 */  addiu     $v0, $zero, 2
/* 512D54 80218784 03E00008 */  jr        $ra
/* 512D58 80218788 27BD0028 */   addiu    $sp, $sp, 0x28
