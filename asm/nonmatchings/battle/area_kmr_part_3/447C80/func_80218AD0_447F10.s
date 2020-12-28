.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218AD0_447F10
/* 447F10 80218AD0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 447F14 80218AD4 AFB10014 */  sw        $s1, 0x14($sp)
/* 447F18 80218AD8 0080882D */  daddu     $s1, $a0, $zero
/* 447F1C 80218ADC AFBF0020 */  sw        $ra, 0x20($sp)
/* 447F20 80218AE0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 447F24 80218AE4 AFB20018 */  sw        $s2, 0x18($sp)
/* 447F28 80218AE8 AFB00010 */  sw        $s0, 0x10($sp)
/* 447F2C 80218AEC 8E30000C */  lw        $s0, 0xc($s1)
/* 447F30 80218AF0 8E050000 */  lw        $a1, ($s0)
/* 447F34 80218AF4 0C0B1EAF */  jal       get_variable
/* 447F38 80218AF8 26100004 */   addiu    $s0, $s0, 4
/* 447F3C 80218AFC 8E050000 */  lw        $a1, ($s0)
/* 447F40 80218B00 26100004 */  addiu     $s0, $s0, 4
/* 447F44 80218B04 0220202D */  daddu     $a0, $s1, $zero
/* 447F48 80218B08 0C0B1EAF */  jal       get_variable
/* 447F4C 80218B0C 0040982D */   daddu    $s3, $v0, $zero
/* 447F50 80218B10 8E050000 */  lw        $a1, ($s0)
/* 447F54 80218B14 26100004 */  addiu     $s0, $s0, 4
/* 447F58 80218B18 0220202D */  daddu     $a0, $s1, $zero
/* 447F5C 80218B1C 0C0B1EAF */  jal       get_variable
/* 447F60 80218B20 0040902D */   daddu    $s2, $v0, $zero
/* 447F64 80218B24 0220202D */  daddu     $a0, $s1, $zero
/* 447F68 80218B28 8E050000 */  lw        $a1, ($s0)
/* 447F6C 80218B2C 0C0B1EAF */  jal       get_variable
/* 447F70 80218B30 0040802D */   daddu    $s0, $v0, $zero
/* 447F74 80218B34 8E240148 */  lw        $a0, 0x148($s1)
/* 447F78 80218B38 0C09A75B */  jal       get_actor
/* 447F7C 80218B3C 0040882D */   daddu    $s1, $v0, $zero
/* 447F80 80218B40 0040182D */  daddu     $v1, $v0, $zero
/* 447F84 80218B44 8C620008 */  lw        $v0, 8($v1)
/* 447F88 80218B48 90420024 */  lbu       $v0, 0x24($v0)
/* 447F8C 80218B4C 8C640008 */  lw        $a0, 8($v1)
/* 447F90 80218B50 02629823 */  subu      $s3, $s3, $v0
/* 447F94 80218B54 A0730194 */  sb        $s3, 0x194($v1)
/* 447F98 80218B58 90820025 */  lbu       $v0, 0x25($a0)
/* 447F9C 80218B5C 02429023 */  subu      $s2, $s2, $v0
/* 447FA0 80218B60 A0720195 */  sb        $s2, 0x195($v1)
/* 447FA4 80218B64 90820026 */  lbu       $v0, 0x26($a0)
/* 447FA8 80218B68 02028023 */  subu      $s0, $s0, $v0
/* 447FAC 80218B6C A0700196 */  sb        $s0, 0x196($v1)
/* 447FB0 80218B70 90840027 */  lbu       $a0, 0x27($a0)
/* 447FB4 80218B74 02248823 */  subu      $s1, $s1, $a0
/* 447FB8 80218B78 A0710197 */  sb        $s1, 0x197($v1)
/* 447FBC 80218B7C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 447FC0 80218B80 8FB3001C */  lw        $s3, 0x1c($sp)
/* 447FC4 80218B84 8FB20018 */  lw        $s2, 0x18($sp)
/* 447FC8 80218B88 8FB10014 */  lw        $s1, 0x14($sp)
/* 447FCC 80218B8C 8FB00010 */  lw        $s0, 0x10($sp)
/* 447FD0 80218B90 24020002 */  addiu     $v0, $zero, 2
/* 447FD4 80218B94 03E00008 */  jr        $ra
/* 447FD8 80218B98 27BD0028 */   addiu    $sp, $sp, 0x28
