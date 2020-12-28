.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802186E4_5B1B94
/* 5B1B94 802186E4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 5B1B98 802186E8 AFB10014 */  sw        $s1, 0x14($sp)
/* 5B1B9C 802186EC 0080882D */  daddu     $s1, $a0, $zero
/* 5B1BA0 802186F0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 5B1BA4 802186F4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 5B1BA8 802186F8 AFB20018 */  sw        $s2, 0x18($sp)
/* 5B1BAC 802186FC AFB00010 */  sw        $s0, 0x10($sp)
/* 5B1BB0 80218700 8E30000C */  lw        $s0, 0xc($s1)
/* 5B1BB4 80218704 8E050000 */  lw        $a1, ($s0)
/* 5B1BB8 80218708 0C0B1EAF */  jal       get_variable
/* 5B1BBC 8021870C 26100004 */   addiu    $s0, $s0, 4
/* 5B1BC0 80218710 8E050000 */  lw        $a1, ($s0)
/* 5B1BC4 80218714 26100004 */  addiu     $s0, $s0, 4
/* 5B1BC8 80218718 0220202D */  daddu     $a0, $s1, $zero
/* 5B1BCC 8021871C 0C0B1EAF */  jal       get_variable
/* 5B1BD0 80218720 0040982D */   daddu    $s3, $v0, $zero
/* 5B1BD4 80218724 8E050000 */  lw        $a1, ($s0)
/* 5B1BD8 80218728 26100004 */  addiu     $s0, $s0, 4
/* 5B1BDC 8021872C 0220202D */  daddu     $a0, $s1, $zero
/* 5B1BE0 80218730 0C0B1EAF */  jal       get_variable
/* 5B1BE4 80218734 0040902D */   daddu    $s2, $v0, $zero
/* 5B1BE8 80218738 0220202D */  daddu     $a0, $s1, $zero
/* 5B1BEC 8021873C 8E050000 */  lw        $a1, ($s0)
/* 5B1BF0 80218740 0C0B1EAF */  jal       get_variable
/* 5B1BF4 80218744 0040802D */   daddu    $s0, $v0, $zero
/* 5B1BF8 80218748 8E240148 */  lw        $a0, 0x148($s1)
/* 5B1BFC 8021874C 0C09A75B */  jal       get_actor
/* 5B1C00 80218750 0040882D */   daddu    $s1, $v0, $zero
/* 5B1C04 80218754 0040182D */  daddu     $v1, $v0, $zero
/* 5B1C08 80218758 8C620008 */  lw        $v0, 8($v1)
/* 5B1C0C 8021875C 90420024 */  lbu       $v0, 0x24($v0)
/* 5B1C10 80218760 8C640008 */  lw        $a0, 8($v1)
/* 5B1C14 80218764 02629823 */  subu      $s3, $s3, $v0
/* 5B1C18 80218768 A0730194 */  sb        $s3, 0x194($v1)
/* 5B1C1C 8021876C 90820025 */  lbu       $v0, 0x25($a0)
/* 5B1C20 80218770 02429023 */  subu      $s2, $s2, $v0
/* 5B1C24 80218774 A0720195 */  sb        $s2, 0x195($v1)
/* 5B1C28 80218778 90820026 */  lbu       $v0, 0x26($a0)
/* 5B1C2C 8021877C 02028023 */  subu      $s0, $s0, $v0
/* 5B1C30 80218780 A0700196 */  sb        $s0, 0x196($v1)
/* 5B1C34 80218784 90840027 */  lbu       $a0, 0x27($a0)
/* 5B1C38 80218788 02248823 */  subu      $s1, $s1, $a0
/* 5B1C3C 8021878C A0710197 */  sb        $s1, 0x197($v1)
/* 5B1C40 80218790 8FBF0020 */  lw        $ra, 0x20($sp)
/* 5B1C44 80218794 8FB3001C */  lw        $s3, 0x1c($sp)
/* 5B1C48 80218798 8FB20018 */  lw        $s2, 0x18($sp)
/* 5B1C4C 8021879C 8FB10014 */  lw        $s1, 0x14($sp)
/* 5B1C50 802187A0 8FB00010 */  lw        $s0, 0x10($sp)
/* 5B1C54 802187A4 24020002 */  addiu     $v0, $zero, 2
/* 5B1C58 802187A8 03E00008 */  jr        $ra
/* 5B1C5C 802187AC 27BD0028 */   addiu    $sp, $sp, 0x28
