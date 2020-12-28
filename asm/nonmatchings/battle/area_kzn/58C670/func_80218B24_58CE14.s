.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218B24_58CE14
/* 58CE14 80218B24 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 58CE18 80218B28 AFB10014 */  sw        $s1, 0x14($sp)
/* 58CE1C 80218B2C 0080882D */  daddu     $s1, $a0, $zero
/* 58CE20 80218B30 AFBF0020 */  sw        $ra, 0x20($sp)
/* 58CE24 80218B34 AFB3001C */  sw        $s3, 0x1c($sp)
/* 58CE28 80218B38 AFB20018 */  sw        $s2, 0x18($sp)
/* 58CE2C 80218B3C AFB00010 */  sw        $s0, 0x10($sp)
/* 58CE30 80218B40 8E30000C */  lw        $s0, 0xc($s1)
/* 58CE34 80218B44 8E050000 */  lw        $a1, ($s0)
/* 58CE38 80218B48 0C0B1EAF */  jal       get_variable
/* 58CE3C 80218B4C 26100004 */   addiu    $s0, $s0, 4
/* 58CE40 80218B50 8E050000 */  lw        $a1, ($s0)
/* 58CE44 80218B54 26100004 */  addiu     $s0, $s0, 4
/* 58CE48 80218B58 0220202D */  daddu     $a0, $s1, $zero
/* 58CE4C 80218B5C 0C0B1EAF */  jal       get_variable
/* 58CE50 80218B60 0040982D */   daddu    $s3, $v0, $zero
/* 58CE54 80218B64 8E050000 */  lw        $a1, ($s0)
/* 58CE58 80218B68 26100004 */  addiu     $s0, $s0, 4
/* 58CE5C 80218B6C 0220202D */  daddu     $a0, $s1, $zero
/* 58CE60 80218B70 0C0B1EAF */  jal       get_variable
/* 58CE64 80218B74 0040902D */   daddu    $s2, $v0, $zero
/* 58CE68 80218B78 0220202D */  daddu     $a0, $s1, $zero
/* 58CE6C 80218B7C 8E050000 */  lw        $a1, ($s0)
/* 58CE70 80218B80 0C0B1EAF */  jal       get_variable
/* 58CE74 80218B84 0040802D */   daddu    $s0, $v0, $zero
/* 58CE78 80218B88 8E240148 */  lw        $a0, 0x148($s1)
/* 58CE7C 80218B8C 0C09A75B */  jal       get_actor
/* 58CE80 80218B90 0040882D */   daddu    $s1, $v0, $zero
/* 58CE84 80218B94 0040182D */  daddu     $v1, $v0, $zero
/* 58CE88 80218B98 8C620008 */  lw        $v0, 8($v1)
/* 58CE8C 80218B9C 90420024 */  lbu       $v0, 0x24($v0)
/* 58CE90 80218BA0 8C640008 */  lw        $a0, 8($v1)
/* 58CE94 80218BA4 02629823 */  subu      $s3, $s3, $v0
/* 58CE98 80218BA8 A0730194 */  sb        $s3, 0x194($v1)
/* 58CE9C 80218BAC 90820025 */  lbu       $v0, 0x25($a0)
/* 58CEA0 80218BB0 02429023 */  subu      $s2, $s2, $v0
/* 58CEA4 80218BB4 A0720195 */  sb        $s2, 0x195($v1)
/* 58CEA8 80218BB8 90820026 */  lbu       $v0, 0x26($a0)
/* 58CEAC 80218BBC 02028023 */  subu      $s0, $s0, $v0
/* 58CEB0 80218BC0 A0700196 */  sb        $s0, 0x196($v1)
/* 58CEB4 80218BC4 90840027 */  lbu       $a0, 0x27($a0)
/* 58CEB8 80218BC8 02248823 */  subu      $s1, $s1, $a0
/* 58CEBC 80218BCC A0710197 */  sb        $s1, 0x197($v1)
/* 58CEC0 80218BD0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 58CEC4 80218BD4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 58CEC8 80218BD8 8FB20018 */  lw        $s2, 0x18($sp)
/* 58CECC 80218BDC 8FB10014 */  lw        $s1, 0x14($sp)
/* 58CED0 80218BE0 8FB00010 */  lw        $s0, 0x10($sp)
/* 58CED4 80218BE4 24020002 */  addiu     $v0, $zero, 2
/* 58CED8 80218BE8 03E00008 */  jr        $ra
/* 58CEDC 80218BEC 27BD0028 */   addiu    $sp, $sp, 0x28
