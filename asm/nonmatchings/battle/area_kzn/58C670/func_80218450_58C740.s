.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218450_58C740
/* 58C740 80218450 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 58C744 80218454 AFB10014 */  sw        $s1, 0x14($sp)
/* 58C748 80218458 0080882D */  daddu     $s1, $a0, $zero
/* 58C74C 8021845C AFBF0020 */  sw        $ra, 0x20($sp)
/* 58C750 80218460 AFB3001C */  sw        $s3, 0x1c($sp)
/* 58C754 80218464 AFB20018 */  sw        $s2, 0x18($sp)
/* 58C758 80218468 AFB00010 */  sw        $s0, 0x10($sp)
/* 58C75C 8021846C 8E30000C */  lw        $s0, 0xc($s1)
/* 58C760 80218470 8E050000 */  lw        $a1, ($s0)
/* 58C764 80218474 0C0B1EAF */  jal       get_variable
/* 58C768 80218478 26100004 */   addiu    $s0, $s0, 4
/* 58C76C 8021847C 8E050000 */  lw        $a1, ($s0)
/* 58C770 80218480 26100004 */  addiu     $s0, $s0, 4
/* 58C774 80218484 0220202D */  daddu     $a0, $s1, $zero
/* 58C778 80218488 0C0B1EAF */  jal       get_variable
/* 58C77C 8021848C 0040982D */   daddu    $s3, $v0, $zero
/* 58C780 80218490 8E050000 */  lw        $a1, ($s0)
/* 58C784 80218494 26100004 */  addiu     $s0, $s0, 4
/* 58C788 80218498 0220202D */  daddu     $a0, $s1, $zero
/* 58C78C 8021849C 0C0B1EAF */  jal       get_variable
/* 58C790 802184A0 0040902D */   daddu    $s2, $v0, $zero
/* 58C794 802184A4 0220202D */  daddu     $a0, $s1, $zero
/* 58C798 802184A8 8E050000 */  lw        $a1, ($s0)
/* 58C79C 802184AC 0C0B1EAF */  jal       get_variable
/* 58C7A0 802184B0 0040802D */   daddu    $s0, $v0, $zero
/* 58C7A4 802184B4 8E240148 */  lw        $a0, 0x148($s1)
/* 58C7A8 802184B8 0C09A75B */  jal       get_actor
/* 58C7AC 802184BC 0040882D */   daddu    $s1, $v0, $zero
/* 58C7B0 802184C0 0040182D */  daddu     $v1, $v0, $zero
/* 58C7B4 802184C4 8C620008 */  lw        $v0, 8($v1)
/* 58C7B8 802184C8 90420024 */  lbu       $v0, 0x24($v0)
/* 58C7BC 802184CC 8C640008 */  lw        $a0, 8($v1)
/* 58C7C0 802184D0 02629823 */  subu      $s3, $s3, $v0
/* 58C7C4 802184D4 A0730194 */  sb        $s3, 0x194($v1)
/* 58C7C8 802184D8 90820025 */  lbu       $v0, 0x25($a0)
/* 58C7CC 802184DC 02429023 */  subu      $s2, $s2, $v0
/* 58C7D0 802184E0 A0720195 */  sb        $s2, 0x195($v1)
/* 58C7D4 802184E4 90820026 */  lbu       $v0, 0x26($a0)
/* 58C7D8 802184E8 02028023 */  subu      $s0, $s0, $v0
/* 58C7DC 802184EC A0700196 */  sb        $s0, 0x196($v1)
/* 58C7E0 802184F0 90840027 */  lbu       $a0, 0x27($a0)
/* 58C7E4 802184F4 02248823 */  subu      $s1, $s1, $a0
/* 58C7E8 802184F8 A0710197 */  sb        $s1, 0x197($v1)
/* 58C7EC 802184FC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 58C7F0 80218500 8FB3001C */  lw        $s3, 0x1c($sp)
/* 58C7F4 80218504 8FB20018 */  lw        $s2, 0x18($sp)
/* 58C7F8 80218508 8FB10014 */  lw        $s1, 0x14($sp)
/* 58C7FC 8021850C 8FB00010 */  lw        $s0, 0x10($sp)
/* 58C800 80218510 24020002 */  addiu     $v0, $zero, 2
/* 58C804 80218514 03E00008 */  jr        $ra
/* 58C808 80218518 27BD0028 */   addiu    $sp, $sp, 0x28
