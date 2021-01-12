.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8026EBF8
/* 19D4D8 8026EBF8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19D4DC 8026EBFC AFB20018 */  sw        $s2, 0x18($sp)
/* 19D4E0 8026EC00 0080902D */  daddu     $s2, $a0, $zero
/* 19D4E4 8026EC04 AFBF0020 */  sw        $ra, 0x20($sp)
/* 19D4E8 8026EC08 AFB3001C */  sw        $s3, 0x1c($sp)
/* 19D4EC 8026EC0C AFB10014 */  sw        $s1, 0x14($sp)
/* 19D4F0 8026EC10 AFB00010 */  sw        $s0, 0x10($sp)
/* 19D4F4 8026EC14 8E51000C */  lw        $s1, 0xc($s2)
/* 19D4F8 8026EC18 8E250000 */  lw        $a1, ($s1)
/* 19D4FC 8026EC1C 0C0B1EAF */  jal       get_variable
/* 19D500 8026EC20 26310004 */   addiu    $s1, $s1, 4
/* 19D504 8026EC24 0040802D */  daddu     $s0, $v0, $zero
/* 19D508 8026EC28 8E250000 */  lw        $a1, ($s1)
/* 19D50C 8026EC2C 26310004 */  addiu     $s1, $s1, 4
/* 19D510 8026EC30 0C0B1EAF */  jal       get_variable
/* 19D514 8026EC34 0240202D */   daddu    $a0, $s2, $zero
/* 19D518 8026EC38 0040982D */  daddu     $s3, $v0, $zero
/* 19D51C 8026EC3C 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19D520 8026EC40 16020002 */  bne       $s0, $v0, .L8026EC4C
/* 19D524 8026EC44 00000000 */   nop
/* 19D528 8026EC48 8E500148 */  lw        $s0, 0x148($s2)
.L8026EC4C:
/* 19D52C 8026EC4C 0C09A75B */  jal       get_actor
/* 19D530 8026EC50 0200202D */   daddu    $a0, $s0, $zero
/* 19D534 8026EC54 0040202D */  daddu     $a0, $v0, $zero
/* 19D538 8026EC58 0C099117 */  jal       get_actor_part
/* 19D53C 8026EC5C 0260282D */   daddu    $a1, $s3, $zero
/* 19D540 8026EC60 8E250000 */  lw        $a1, ($s1)
/* 19D544 8026EC64 26310004 */  addiu     $s1, $s1, 4
/* 19D548 8026EC68 8C5000C0 */  lw        $s0, 0xc0($v0)
/* 19D54C 8026EC6C 0C0B1EAF */  jal       get_variable
/* 19D550 8026EC70 0240202D */   daddu    $a0, $s2, $zero
/* 19D554 8026EC74 A6020740 */  sh        $v0, 0x740($s0)
/* 19D558 8026EC78 8E250000 */  lw        $a1, ($s1)
/* 19D55C 8026EC7C 26310004 */  addiu     $s1, $s1, 4
/* 19D560 8026EC80 0C0B1EAF */  jal       get_variable
/* 19D564 8026EC84 0240202D */   daddu    $a0, $s2, $zero
/* 19D568 8026EC88 A6020742 */  sh        $v0, 0x742($s0)
/* 19D56C 8026EC8C 8E250000 */  lw        $a1, ($s1)
/* 19D570 8026EC90 26310004 */  addiu     $s1, $s1, 4
/* 19D574 8026EC94 0C0B1EAF */  jal       get_variable
/* 19D578 8026EC98 0240202D */   daddu    $a0, $s2, $zero
/* 19D57C 8026EC9C A6020744 */  sh        $v0, 0x744($s0)
/* 19D580 8026ECA0 8E250000 */  lw        $a1, ($s1)
/* 19D584 8026ECA4 26310004 */  addiu     $s1, $s1, 4
/* 19D588 8026ECA8 0C0B1EAF */  jal       get_variable
/* 19D58C 8026ECAC 0240202D */   daddu    $a0, $s2, $zero
/* 19D590 8026ECB0 A6020746 */  sh        $v0, 0x746($s0)
/* 19D594 8026ECB4 8E250000 */  lw        $a1, ($s1)
/* 19D598 8026ECB8 26310004 */  addiu     $s1, $s1, 4
/* 19D59C 8026ECBC 0C0B1EAF */  jal       get_variable
/* 19D5A0 8026ECC0 0240202D */   daddu    $a0, $s2, $zero
/* 19D5A4 8026ECC4 A6020748 */  sh        $v0, 0x748($s0)
/* 19D5A8 8026ECC8 8E250000 */  lw        $a1, ($s1)
/* 19D5AC 8026ECCC 26310004 */  addiu     $s1, $s1, 4
/* 19D5B0 8026ECD0 0C0B1EAF */  jal       get_variable
/* 19D5B4 8026ECD4 0240202D */   daddu    $a0, $s2, $zero
/* 19D5B8 8026ECD8 A602074A */  sh        $v0, 0x74a($s0)
/* 19D5BC 8026ECDC 8E250000 */  lw        $a1, ($s1)
/* 19D5C0 8026ECE0 26310004 */  addiu     $s1, $s1, 4
/* 19D5C4 8026ECE4 0C0B1EAF */  jal       get_variable
/* 19D5C8 8026ECE8 0240202D */   daddu    $a0, $s2, $zero
/* 19D5CC 8026ECEC A602074C */  sh        $v0, 0x74c($s0)
/* 19D5D0 8026ECF0 8E250000 */  lw        $a1, ($s1)
/* 19D5D4 8026ECF4 0C0B1EAF */  jal       get_variable
/* 19D5D8 8026ECF8 0240202D */   daddu    $a0, $s2, $zero
/* 19D5DC 8026ECFC A602074E */  sh        $v0, 0x74e($s0)
/* 19D5E0 8026ED00 8FBF0020 */  lw        $ra, 0x20($sp)
/* 19D5E4 8026ED04 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19D5E8 8026ED08 8FB20018 */  lw        $s2, 0x18($sp)
/* 19D5EC 8026ED0C 8FB10014 */  lw        $s1, 0x14($sp)
/* 19D5F0 8026ED10 8FB00010 */  lw        $s0, 0x10($sp)
/* 19D5F4 8026ED14 24020002 */  addiu     $v0, $zero, 2
/* 19D5F8 8026ED18 03E00008 */  jr        $ra
/* 19D5FC 8026ED1C 27BD0028 */   addiu    $sp, $sp, 0x28
