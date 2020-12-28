.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218E74_465304
/* 465304 80218E74 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 465308 80218E78 AFB10014 */  sw        $s1, 0x14($sp)
/* 46530C 80218E7C 0080882D */  daddu     $s1, $a0, $zero
/* 465310 80218E80 AFBF0020 */  sw        $ra, 0x20($sp)
/* 465314 80218E84 AFB3001C */  sw        $s3, 0x1c($sp)
/* 465318 80218E88 AFB20018 */  sw        $s2, 0x18($sp)
/* 46531C 80218E8C AFB00010 */  sw        $s0, 0x10($sp)
/* 465320 80218E90 8E30000C */  lw        $s0, 0xc($s1)
/* 465324 80218E94 8E050000 */  lw        $a1, ($s0)
/* 465328 80218E98 0C0B1EAF */  jal       get_variable
/* 46532C 80218E9C 26100004 */   addiu    $s0, $s0, 4
/* 465330 80218EA0 8E050000 */  lw        $a1, ($s0)
/* 465334 80218EA4 26100004 */  addiu     $s0, $s0, 4
/* 465338 80218EA8 0220202D */  daddu     $a0, $s1, $zero
/* 46533C 80218EAC 0C0B1EAF */  jal       get_variable
/* 465340 80218EB0 0040982D */   daddu    $s3, $v0, $zero
/* 465344 80218EB4 8E050000 */  lw        $a1, ($s0)
/* 465348 80218EB8 26100004 */  addiu     $s0, $s0, 4
/* 46534C 80218EBC 0220202D */  daddu     $a0, $s1, $zero
/* 465350 80218EC0 0C0B1EAF */  jal       get_variable
/* 465354 80218EC4 0040902D */   daddu    $s2, $v0, $zero
/* 465358 80218EC8 0220202D */  daddu     $a0, $s1, $zero
/* 46535C 80218ECC 8E050000 */  lw        $a1, ($s0)
/* 465360 80218ED0 0C0B1EAF */  jal       get_variable
/* 465364 80218ED4 0040802D */   daddu    $s0, $v0, $zero
/* 465368 80218ED8 8E240148 */  lw        $a0, 0x148($s1)
/* 46536C 80218EDC 0C09A75B */  jal       get_actor
/* 465370 80218EE0 0040882D */   daddu    $s1, $v0, $zero
/* 465374 80218EE4 0040182D */  daddu     $v1, $v0, $zero
/* 465378 80218EE8 8C620008 */  lw        $v0, 8($v1)
/* 46537C 80218EEC 90420024 */  lbu       $v0, 0x24($v0)
/* 465380 80218EF0 8C640008 */  lw        $a0, 8($v1)
/* 465384 80218EF4 02629823 */  subu      $s3, $s3, $v0
/* 465388 80218EF8 A0730194 */  sb        $s3, 0x194($v1)
/* 46538C 80218EFC 90820025 */  lbu       $v0, 0x25($a0)
/* 465390 80218F00 02429023 */  subu      $s2, $s2, $v0
/* 465394 80218F04 A0720195 */  sb        $s2, 0x195($v1)
/* 465398 80218F08 90820026 */  lbu       $v0, 0x26($a0)
/* 46539C 80218F0C 02028023 */  subu      $s0, $s0, $v0
/* 4653A0 80218F10 A0700196 */  sb        $s0, 0x196($v1)
/* 4653A4 80218F14 90840027 */  lbu       $a0, 0x27($a0)
/* 4653A8 80218F18 02248823 */  subu      $s1, $s1, $a0
/* 4653AC 80218F1C A0710197 */  sb        $s1, 0x197($v1)
/* 4653B0 80218F20 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4653B4 80218F24 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4653B8 80218F28 8FB20018 */  lw        $s2, 0x18($sp)
/* 4653BC 80218F2C 8FB10014 */  lw        $s1, 0x14($sp)
/* 4653C0 80218F30 8FB00010 */  lw        $s0, 0x10($sp)
/* 4653C4 80218F34 24020002 */  addiu     $v0, $zero, 2
/* 4653C8 80218F38 03E00008 */  jr        $ra
/* 4653CC 80218F3C 27BD0028 */   addiu    $sp, $sp, 0x28
