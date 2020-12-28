.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218AE0_557EC0
/* 557EC0 80218AE0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 557EC4 80218AE4 AFB10014 */  sw        $s1, 0x14($sp)
/* 557EC8 80218AE8 0080882D */  daddu     $s1, $a0, $zero
/* 557ECC 80218AEC AFBF0020 */  sw        $ra, 0x20($sp)
/* 557ED0 80218AF0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 557ED4 80218AF4 AFB20018 */  sw        $s2, 0x18($sp)
/* 557ED8 80218AF8 AFB00010 */  sw        $s0, 0x10($sp)
/* 557EDC 80218AFC 8E30000C */  lw        $s0, 0xc($s1)
/* 557EE0 80218B00 8E050000 */  lw        $a1, ($s0)
/* 557EE4 80218B04 0C0B1EAF */  jal       get_variable
/* 557EE8 80218B08 26100004 */   addiu    $s0, $s0, 4
/* 557EEC 80218B0C 8E050000 */  lw        $a1, ($s0)
/* 557EF0 80218B10 26100004 */  addiu     $s0, $s0, 4
/* 557EF4 80218B14 0220202D */  daddu     $a0, $s1, $zero
/* 557EF8 80218B18 0C0B1EAF */  jal       get_variable
/* 557EFC 80218B1C 0040982D */   daddu    $s3, $v0, $zero
/* 557F00 80218B20 8E050000 */  lw        $a1, ($s0)
/* 557F04 80218B24 26100004 */  addiu     $s0, $s0, 4
/* 557F08 80218B28 0220202D */  daddu     $a0, $s1, $zero
/* 557F0C 80218B2C 0C0B1EAF */  jal       get_variable
/* 557F10 80218B30 0040902D */   daddu    $s2, $v0, $zero
/* 557F14 80218B34 0220202D */  daddu     $a0, $s1, $zero
/* 557F18 80218B38 8E050000 */  lw        $a1, ($s0)
/* 557F1C 80218B3C 0C0B1EAF */  jal       get_variable
/* 557F20 80218B40 0040802D */   daddu    $s0, $v0, $zero
/* 557F24 80218B44 8E240148 */  lw        $a0, 0x148($s1)
/* 557F28 80218B48 0C09A75B */  jal       get_actor
/* 557F2C 80218B4C 0040882D */   daddu    $s1, $v0, $zero
/* 557F30 80218B50 0040182D */  daddu     $v1, $v0, $zero
/* 557F34 80218B54 8C620008 */  lw        $v0, 8($v1)
/* 557F38 80218B58 90420024 */  lbu       $v0, 0x24($v0)
/* 557F3C 80218B5C 8C640008 */  lw        $a0, 8($v1)
/* 557F40 80218B60 02629823 */  subu      $s3, $s3, $v0
/* 557F44 80218B64 A0730194 */  sb        $s3, 0x194($v1)
/* 557F48 80218B68 90820025 */  lbu       $v0, 0x25($a0)
/* 557F4C 80218B6C 02429023 */  subu      $s2, $s2, $v0
/* 557F50 80218B70 A0720195 */  sb        $s2, 0x195($v1)
/* 557F54 80218B74 90820026 */  lbu       $v0, 0x26($a0)
/* 557F58 80218B78 02028023 */  subu      $s0, $s0, $v0
/* 557F5C 80218B7C A0700196 */  sb        $s0, 0x196($v1)
/* 557F60 80218B80 90840027 */  lbu       $a0, 0x27($a0)
/* 557F64 80218B84 02248823 */  subu      $s1, $s1, $a0
/* 557F68 80218B88 A0710197 */  sb        $s1, 0x197($v1)
/* 557F6C 80218B8C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 557F70 80218B90 8FB3001C */  lw        $s3, 0x1c($sp)
/* 557F74 80218B94 8FB20018 */  lw        $s2, 0x18($sp)
/* 557F78 80218B98 8FB10014 */  lw        $s1, 0x14($sp)
/* 557F7C 80218B9C 8FB00010 */  lw        $s0, 0x10($sp)
/* 557F80 80218BA0 24020002 */  addiu     $v0, $zero, 2
/* 557F84 80218BA4 03E00008 */  jr        $ra
/* 557F88 80218BA8 27BD0028 */   addiu    $sp, $sp, 0x28
/* 557F8C 80218BAC 00000000 */  nop       
