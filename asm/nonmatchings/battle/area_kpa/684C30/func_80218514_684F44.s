.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218514_684F44
/* 684F44 80218514 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 684F48 80218518 AFB10014 */  sw        $s1, 0x14($sp)
/* 684F4C 8021851C 0080882D */  daddu     $s1, $a0, $zero
/* 684F50 80218520 AFBF0020 */  sw        $ra, 0x20($sp)
/* 684F54 80218524 AFB3001C */  sw        $s3, 0x1c($sp)
/* 684F58 80218528 AFB20018 */  sw        $s2, 0x18($sp)
/* 684F5C 8021852C AFB00010 */  sw        $s0, 0x10($sp)
/* 684F60 80218530 8E30000C */  lw        $s0, 0xc($s1)
/* 684F64 80218534 8E050000 */  lw        $a1, ($s0)
/* 684F68 80218538 0C0B1EAF */  jal       get_variable
/* 684F6C 8021853C 26100004 */   addiu    $s0, $s0, 4
/* 684F70 80218540 8E050000 */  lw        $a1, ($s0)
/* 684F74 80218544 26100004 */  addiu     $s0, $s0, 4
/* 684F78 80218548 0220202D */  daddu     $a0, $s1, $zero
/* 684F7C 8021854C 0C0B1EAF */  jal       get_variable
/* 684F80 80218550 0040982D */   daddu    $s3, $v0, $zero
/* 684F84 80218554 8E050000 */  lw        $a1, ($s0)
/* 684F88 80218558 26100004 */  addiu     $s0, $s0, 4
/* 684F8C 8021855C 0220202D */  daddu     $a0, $s1, $zero
/* 684F90 80218560 0C0B1EAF */  jal       get_variable
/* 684F94 80218564 0040902D */   daddu    $s2, $v0, $zero
/* 684F98 80218568 0220202D */  daddu     $a0, $s1, $zero
/* 684F9C 8021856C 8E050000 */  lw        $a1, ($s0)
/* 684FA0 80218570 0C0B1EAF */  jal       get_variable
/* 684FA4 80218574 0040802D */   daddu    $s0, $v0, $zero
/* 684FA8 80218578 8E240148 */  lw        $a0, 0x148($s1)
/* 684FAC 8021857C 0C09A75B */  jal       get_actor
/* 684FB0 80218580 0040882D */   daddu    $s1, $v0, $zero
/* 684FB4 80218584 0040182D */  daddu     $v1, $v0, $zero
/* 684FB8 80218588 8C620008 */  lw        $v0, 8($v1)
/* 684FBC 8021858C 90420024 */  lbu       $v0, 0x24($v0)
/* 684FC0 80218590 8C640008 */  lw        $a0, 8($v1)
/* 684FC4 80218594 02629823 */  subu      $s3, $s3, $v0
/* 684FC8 80218598 A0730194 */  sb        $s3, 0x194($v1)
/* 684FCC 8021859C 90820025 */  lbu       $v0, 0x25($a0)
/* 684FD0 802185A0 02429023 */  subu      $s2, $s2, $v0
/* 684FD4 802185A4 A0720195 */  sb        $s2, 0x195($v1)
/* 684FD8 802185A8 90820026 */  lbu       $v0, 0x26($a0)
/* 684FDC 802185AC 02028023 */  subu      $s0, $s0, $v0
/* 684FE0 802185B0 A0700196 */  sb        $s0, 0x196($v1)
/* 684FE4 802185B4 90840027 */  lbu       $a0, 0x27($a0)
/* 684FE8 802185B8 02248823 */  subu      $s1, $s1, $a0
/* 684FEC 802185BC A0710197 */  sb        $s1, 0x197($v1)
/* 684FF0 802185C0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 684FF4 802185C4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 684FF8 802185C8 8FB20018 */  lw        $s2, 0x18($sp)
/* 684FFC 802185CC 8FB10014 */  lw        $s1, 0x14($sp)
/* 685000 802185D0 8FB00010 */  lw        $s0, 0x10($sp)
/* 685004 802185D4 24020002 */  addiu     $v0, $zero, 2
/* 685008 802185D8 03E00008 */  jr        $ra
/* 68500C 802185DC 27BD0028 */   addiu    $sp, $sp, 0x28
