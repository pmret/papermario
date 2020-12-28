.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218A54_5B1F04
/* 5B1F04 80218A54 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 5B1F08 80218A58 AFB10014 */  sw        $s1, 0x14($sp)
/* 5B1F0C 80218A5C 0080882D */  daddu     $s1, $a0, $zero
/* 5B1F10 80218A60 AFBF0020 */  sw        $ra, 0x20($sp)
/* 5B1F14 80218A64 AFB3001C */  sw        $s3, 0x1c($sp)
/* 5B1F18 80218A68 AFB20018 */  sw        $s2, 0x18($sp)
/* 5B1F1C 80218A6C AFB00010 */  sw        $s0, 0x10($sp)
/* 5B1F20 80218A70 8E30000C */  lw        $s0, 0xc($s1)
/* 5B1F24 80218A74 8E050000 */  lw        $a1, ($s0)
/* 5B1F28 80218A78 0C0B1EAF */  jal       get_variable
/* 5B1F2C 80218A7C 26100004 */   addiu    $s0, $s0, 4
/* 5B1F30 80218A80 8E050000 */  lw        $a1, ($s0)
/* 5B1F34 80218A84 26100004 */  addiu     $s0, $s0, 4
/* 5B1F38 80218A88 0220202D */  daddu     $a0, $s1, $zero
/* 5B1F3C 80218A8C 0C0B1EAF */  jal       get_variable
/* 5B1F40 80218A90 0040982D */   daddu    $s3, $v0, $zero
/* 5B1F44 80218A94 8E050000 */  lw        $a1, ($s0)
/* 5B1F48 80218A98 26100004 */  addiu     $s0, $s0, 4
/* 5B1F4C 80218A9C 0220202D */  daddu     $a0, $s1, $zero
/* 5B1F50 80218AA0 0C0B1EAF */  jal       get_variable
/* 5B1F54 80218AA4 0040902D */   daddu    $s2, $v0, $zero
/* 5B1F58 80218AA8 0220202D */  daddu     $a0, $s1, $zero
/* 5B1F5C 80218AAC 8E050000 */  lw        $a1, ($s0)
/* 5B1F60 80218AB0 0C0B1EAF */  jal       get_variable
/* 5B1F64 80218AB4 0040802D */   daddu    $s0, $v0, $zero
/* 5B1F68 80218AB8 8E240148 */  lw        $a0, 0x148($s1)
/* 5B1F6C 80218ABC 0C09A75B */  jal       get_actor
/* 5B1F70 80218AC0 0040882D */   daddu    $s1, $v0, $zero
/* 5B1F74 80218AC4 0040182D */  daddu     $v1, $v0, $zero
/* 5B1F78 80218AC8 8C620008 */  lw        $v0, 8($v1)
/* 5B1F7C 80218ACC 90420024 */  lbu       $v0, 0x24($v0)
/* 5B1F80 80218AD0 8C640008 */  lw        $a0, 8($v1)
/* 5B1F84 80218AD4 02629823 */  subu      $s3, $s3, $v0
/* 5B1F88 80218AD8 A0730194 */  sb        $s3, 0x194($v1)
/* 5B1F8C 80218ADC 90820025 */  lbu       $v0, 0x25($a0)
/* 5B1F90 80218AE0 02429023 */  subu      $s2, $s2, $v0
/* 5B1F94 80218AE4 A0720195 */  sb        $s2, 0x195($v1)
/* 5B1F98 80218AE8 90820026 */  lbu       $v0, 0x26($a0)
/* 5B1F9C 80218AEC 02028023 */  subu      $s0, $s0, $v0
/* 5B1FA0 80218AF0 A0700196 */  sb        $s0, 0x196($v1)
/* 5B1FA4 80218AF4 90840027 */  lbu       $a0, 0x27($a0)
/* 5B1FA8 80218AF8 02248823 */  subu      $s1, $s1, $a0
/* 5B1FAC 80218AFC A0710197 */  sb        $s1, 0x197($v1)
/* 5B1FB0 80218B00 8FBF0020 */  lw        $ra, 0x20($sp)
/* 5B1FB4 80218B04 8FB3001C */  lw        $s3, 0x1c($sp)
/* 5B1FB8 80218B08 8FB20018 */  lw        $s2, 0x18($sp)
/* 5B1FBC 80218B0C 8FB10014 */  lw        $s1, 0x14($sp)
/* 5B1FC0 80218B10 8FB00010 */  lw        $s0, 0x10($sp)
/* 5B1FC4 80218B14 24020002 */  addiu     $v0, $zero, 2
/* 5B1FC8 80218B18 03E00008 */  jr        $ra
/* 5B1FCC 80218B1C 27BD0028 */   addiu    $sp, $sp, 0x28
