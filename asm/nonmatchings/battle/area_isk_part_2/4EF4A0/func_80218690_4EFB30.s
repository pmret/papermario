.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218690_4EFB30
/* 4EFB30 80218690 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4EFB34 80218694 AFB10014 */  sw        $s1, 0x14($sp)
/* 4EFB38 80218698 0080882D */  daddu     $s1, $a0, $zero
/* 4EFB3C 8021869C AFBF0020 */  sw        $ra, 0x20($sp)
/* 4EFB40 802186A0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4EFB44 802186A4 AFB20018 */  sw        $s2, 0x18($sp)
/* 4EFB48 802186A8 AFB00010 */  sw        $s0, 0x10($sp)
/* 4EFB4C 802186AC 8E30000C */  lw        $s0, 0xc($s1)
/* 4EFB50 802186B0 8E050000 */  lw        $a1, ($s0)
/* 4EFB54 802186B4 0C0B1EAF */  jal       get_variable
/* 4EFB58 802186B8 26100004 */   addiu    $s0, $s0, 4
/* 4EFB5C 802186BC 8E050000 */  lw        $a1, ($s0)
/* 4EFB60 802186C0 26100004 */  addiu     $s0, $s0, 4
/* 4EFB64 802186C4 0220202D */  daddu     $a0, $s1, $zero
/* 4EFB68 802186C8 0C0B1EAF */  jal       get_variable
/* 4EFB6C 802186CC 0040982D */   daddu    $s3, $v0, $zero
/* 4EFB70 802186D0 8E050000 */  lw        $a1, ($s0)
/* 4EFB74 802186D4 26100004 */  addiu     $s0, $s0, 4
/* 4EFB78 802186D8 0220202D */  daddu     $a0, $s1, $zero
/* 4EFB7C 802186DC 0C0B1EAF */  jal       get_variable
/* 4EFB80 802186E0 0040902D */   daddu    $s2, $v0, $zero
/* 4EFB84 802186E4 0220202D */  daddu     $a0, $s1, $zero
/* 4EFB88 802186E8 8E050000 */  lw        $a1, ($s0)
/* 4EFB8C 802186EC 0C0B1EAF */  jal       get_variable
/* 4EFB90 802186F0 0040802D */   daddu    $s0, $v0, $zero
/* 4EFB94 802186F4 8E240148 */  lw        $a0, 0x148($s1)
/* 4EFB98 802186F8 0C09A75B */  jal       get_actor
/* 4EFB9C 802186FC 0040882D */   daddu    $s1, $v0, $zero
/* 4EFBA0 80218700 0040182D */  daddu     $v1, $v0, $zero
/* 4EFBA4 80218704 8C620008 */  lw        $v0, 8($v1)
/* 4EFBA8 80218708 90420024 */  lbu       $v0, 0x24($v0)
/* 4EFBAC 8021870C 8C640008 */  lw        $a0, 8($v1)
/* 4EFBB0 80218710 02629823 */  subu      $s3, $s3, $v0
/* 4EFBB4 80218714 A0730194 */  sb        $s3, 0x194($v1)
/* 4EFBB8 80218718 90820025 */  lbu       $v0, 0x25($a0)
/* 4EFBBC 8021871C 02429023 */  subu      $s2, $s2, $v0
/* 4EFBC0 80218720 A0720195 */  sb        $s2, 0x195($v1)
/* 4EFBC4 80218724 90820026 */  lbu       $v0, 0x26($a0)
/* 4EFBC8 80218728 02028023 */  subu      $s0, $s0, $v0
/* 4EFBCC 8021872C A0700196 */  sb        $s0, 0x196($v1)
/* 4EFBD0 80218730 90840027 */  lbu       $a0, 0x27($a0)
/* 4EFBD4 80218734 02248823 */  subu      $s1, $s1, $a0
/* 4EFBD8 80218738 A0710197 */  sb        $s1, 0x197($v1)
/* 4EFBDC 8021873C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4EFBE0 80218740 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4EFBE4 80218744 8FB20018 */  lw        $s2, 0x18($sp)
/* 4EFBE8 80218748 8FB10014 */  lw        $s1, 0x14($sp)
/* 4EFBEC 8021874C 8FB00010 */  lw        $s0, 0x10($sp)
/* 4EFBF0 80218750 24020002 */  addiu     $v0, $zero, 2
/* 4EFBF4 80218754 03E00008 */  jr        $ra
/* 4EFBF8 80218758 27BD0028 */   addiu    $sp, $sp, 0x28
