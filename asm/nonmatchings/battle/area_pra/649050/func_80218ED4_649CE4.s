.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218ED4_649CE4
/* 649CE4 80218ED4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 649CE8 80218ED8 AFB10014 */  sw        $s1, 0x14($sp)
/* 649CEC 80218EDC 0080882D */  daddu     $s1, $a0, $zero
/* 649CF0 80218EE0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 649CF4 80218EE4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 649CF8 80218EE8 AFB20018 */  sw        $s2, 0x18($sp)
/* 649CFC 80218EEC AFB00010 */  sw        $s0, 0x10($sp)
/* 649D00 80218EF0 8E30000C */  lw        $s0, 0xc($s1)
/* 649D04 80218EF4 8E050000 */  lw        $a1, ($s0)
/* 649D08 80218EF8 0C0B1EAF */  jal       get_variable
/* 649D0C 80218EFC 26100004 */   addiu    $s0, $s0, 4
/* 649D10 80218F00 8E050000 */  lw        $a1, ($s0)
/* 649D14 80218F04 26100004 */  addiu     $s0, $s0, 4
/* 649D18 80218F08 0220202D */  daddu     $a0, $s1, $zero
/* 649D1C 80218F0C 0C0B1EAF */  jal       get_variable
/* 649D20 80218F10 0040982D */   daddu    $s3, $v0, $zero
/* 649D24 80218F14 8E050000 */  lw        $a1, ($s0)
/* 649D28 80218F18 26100004 */  addiu     $s0, $s0, 4
/* 649D2C 80218F1C 0220202D */  daddu     $a0, $s1, $zero
/* 649D30 80218F20 0C0B1EAF */  jal       get_variable
/* 649D34 80218F24 0040902D */   daddu    $s2, $v0, $zero
/* 649D38 80218F28 0220202D */  daddu     $a0, $s1, $zero
/* 649D3C 80218F2C 8E050000 */  lw        $a1, ($s0)
/* 649D40 80218F30 0C0B1EAF */  jal       get_variable
/* 649D44 80218F34 0040802D */   daddu    $s0, $v0, $zero
/* 649D48 80218F38 8E240148 */  lw        $a0, 0x148($s1)
/* 649D4C 80218F3C 0C09A75B */  jal       get_actor
/* 649D50 80218F40 0040882D */   daddu    $s1, $v0, $zero
/* 649D54 80218F44 0040182D */  daddu     $v1, $v0, $zero
/* 649D58 80218F48 8C620008 */  lw        $v0, 8($v1)
/* 649D5C 80218F4C 90420024 */  lbu       $v0, 0x24($v0)
/* 649D60 80218F50 8C640008 */  lw        $a0, 8($v1)
/* 649D64 80218F54 02629823 */  subu      $s3, $s3, $v0
/* 649D68 80218F58 A0730194 */  sb        $s3, 0x194($v1)
/* 649D6C 80218F5C 90820025 */  lbu       $v0, 0x25($a0)
/* 649D70 80218F60 02429023 */  subu      $s2, $s2, $v0
/* 649D74 80218F64 A0720195 */  sb        $s2, 0x195($v1)
/* 649D78 80218F68 90820026 */  lbu       $v0, 0x26($a0)
/* 649D7C 80218F6C 02028023 */  subu      $s0, $s0, $v0
/* 649D80 80218F70 A0700196 */  sb        $s0, 0x196($v1)
/* 649D84 80218F74 90840027 */  lbu       $a0, 0x27($a0)
/* 649D88 80218F78 02248823 */  subu      $s1, $s1, $a0
/* 649D8C 80218F7C A0710197 */  sb        $s1, 0x197($v1)
/* 649D90 80218F80 8FBF0020 */  lw        $ra, 0x20($sp)
/* 649D94 80218F84 8FB3001C */  lw        $s3, 0x1c($sp)
/* 649D98 80218F88 8FB20018 */  lw        $s2, 0x18($sp)
/* 649D9C 80218F8C 8FB10014 */  lw        $s1, 0x14($sp)
/* 649DA0 80218F90 8FB00010 */  lw        $s0, 0x10($sp)
/* 649DA4 80218F94 24020002 */  addiu     $v0, $zero, 2
/* 649DA8 80218F98 03E00008 */  jr        $ra
/* 649DAC 80218F9C 27BD0028 */   addiu    $sp, $sp, 0x28
