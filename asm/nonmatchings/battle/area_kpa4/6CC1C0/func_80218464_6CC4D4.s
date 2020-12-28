.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218464_6CC4D4
/* 6CC4D4 80218464 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 6CC4D8 80218468 AFB10014 */  sw        $s1, 0x14($sp)
/* 6CC4DC 8021846C 0080882D */  daddu     $s1, $a0, $zero
/* 6CC4E0 80218470 AFBF0020 */  sw        $ra, 0x20($sp)
/* 6CC4E4 80218474 AFB3001C */  sw        $s3, 0x1c($sp)
/* 6CC4E8 80218478 AFB20018 */  sw        $s2, 0x18($sp)
/* 6CC4EC 8021847C AFB00010 */  sw        $s0, 0x10($sp)
/* 6CC4F0 80218480 8E30000C */  lw        $s0, 0xc($s1)
/* 6CC4F4 80218484 8E050000 */  lw        $a1, ($s0)
/* 6CC4F8 80218488 0C0B1EAF */  jal       get_variable
/* 6CC4FC 8021848C 26100004 */   addiu    $s0, $s0, 4
/* 6CC500 80218490 8E050000 */  lw        $a1, ($s0)
/* 6CC504 80218494 26100004 */  addiu     $s0, $s0, 4
/* 6CC508 80218498 0220202D */  daddu     $a0, $s1, $zero
/* 6CC50C 8021849C 0C0B1EAF */  jal       get_variable
/* 6CC510 802184A0 0040982D */   daddu    $s3, $v0, $zero
/* 6CC514 802184A4 8E050000 */  lw        $a1, ($s0)
/* 6CC518 802184A8 26100004 */  addiu     $s0, $s0, 4
/* 6CC51C 802184AC 0220202D */  daddu     $a0, $s1, $zero
/* 6CC520 802184B0 0C0B1EAF */  jal       get_variable
/* 6CC524 802184B4 0040902D */   daddu    $s2, $v0, $zero
/* 6CC528 802184B8 0220202D */  daddu     $a0, $s1, $zero
/* 6CC52C 802184BC 8E050000 */  lw        $a1, ($s0)
/* 6CC530 802184C0 0C0B1EAF */  jal       get_variable
/* 6CC534 802184C4 0040802D */   daddu    $s0, $v0, $zero
/* 6CC538 802184C8 8E240148 */  lw        $a0, 0x148($s1)
/* 6CC53C 802184CC 0C09A75B */  jal       get_actor
/* 6CC540 802184D0 0040882D */   daddu    $s1, $v0, $zero
/* 6CC544 802184D4 0040182D */  daddu     $v1, $v0, $zero
/* 6CC548 802184D8 8C620008 */  lw        $v0, 8($v1)
/* 6CC54C 802184DC 90420024 */  lbu       $v0, 0x24($v0)
/* 6CC550 802184E0 8C640008 */  lw        $a0, 8($v1)
/* 6CC554 802184E4 02629823 */  subu      $s3, $s3, $v0
/* 6CC558 802184E8 A0730194 */  sb        $s3, 0x194($v1)
/* 6CC55C 802184EC 90820025 */  lbu       $v0, 0x25($a0)
/* 6CC560 802184F0 02429023 */  subu      $s2, $s2, $v0
/* 6CC564 802184F4 A0720195 */  sb        $s2, 0x195($v1)
/* 6CC568 802184F8 90820026 */  lbu       $v0, 0x26($a0)
/* 6CC56C 802184FC 02028023 */  subu      $s0, $s0, $v0
/* 6CC570 80218500 A0700196 */  sb        $s0, 0x196($v1)
/* 6CC574 80218504 90840027 */  lbu       $a0, 0x27($a0)
/* 6CC578 80218508 02248823 */  subu      $s1, $s1, $a0
/* 6CC57C 8021850C A0710197 */  sb        $s1, 0x197($v1)
/* 6CC580 80218510 8FBF0020 */  lw        $ra, 0x20($sp)
/* 6CC584 80218514 8FB3001C */  lw        $s3, 0x1c($sp)
/* 6CC588 80218518 8FB20018 */  lw        $s2, 0x18($sp)
/* 6CC58C 8021851C 8FB10014 */  lw        $s1, 0x14($sp)
/* 6CC590 80218520 8FB00010 */  lw        $s0, 0x10($sp)
/* 6CC594 80218524 24020002 */  addiu     $v0, $zero, 2
/* 6CC598 80218528 03E00008 */  jr        $ra
/* 6CC59C 8021852C 27BD0028 */   addiu    $sp, $sp, 0x28
