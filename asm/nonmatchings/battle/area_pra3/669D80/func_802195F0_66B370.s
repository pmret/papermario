.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802195F0_66B370
/* 66B370 802195F0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 66B374 802195F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 66B378 802195F8 0080882D */  daddu     $s1, $a0, $zero
/* 66B37C 802195FC AFBF0020 */  sw        $ra, 0x20($sp)
/* 66B380 80219600 AFB3001C */  sw        $s3, 0x1c($sp)
/* 66B384 80219604 AFB20018 */  sw        $s2, 0x18($sp)
/* 66B388 80219608 AFB00010 */  sw        $s0, 0x10($sp)
/* 66B38C 8021960C 8E30000C */  lw        $s0, 0xc($s1)
/* 66B390 80219610 8E050000 */  lw        $a1, ($s0)
/* 66B394 80219614 0C0B1EAF */  jal       get_variable
/* 66B398 80219618 26100004 */   addiu    $s0, $s0, 4
/* 66B39C 8021961C 8E050000 */  lw        $a1, ($s0)
/* 66B3A0 80219620 26100004 */  addiu     $s0, $s0, 4
/* 66B3A4 80219624 0220202D */  daddu     $a0, $s1, $zero
/* 66B3A8 80219628 0C0B1EAF */  jal       get_variable
/* 66B3AC 8021962C 0040982D */   daddu    $s3, $v0, $zero
/* 66B3B0 80219630 8E050000 */  lw        $a1, ($s0)
/* 66B3B4 80219634 26100004 */  addiu     $s0, $s0, 4
/* 66B3B8 80219638 0220202D */  daddu     $a0, $s1, $zero
/* 66B3BC 8021963C 0C0B1EAF */  jal       get_variable
/* 66B3C0 80219640 0040902D */   daddu    $s2, $v0, $zero
/* 66B3C4 80219644 0220202D */  daddu     $a0, $s1, $zero
/* 66B3C8 80219648 8E050000 */  lw        $a1, ($s0)
/* 66B3CC 8021964C 0C0B1EAF */  jal       get_variable
/* 66B3D0 80219650 0040802D */   daddu    $s0, $v0, $zero
/* 66B3D4 80219654 8E240148 */  lw        $a0, 0x148($s1)
/* 66B3D8 80219658 0C09A75B */  jal       get_actor
/* 66B3DC 8021965C 0040882D */   daddu    $s1, $v0, $zero
/* 66B3E0 80219660 0040182D */  daddu     $v1, $v0, $zero
/* 66B3E4 80219664 8C620008 */  lw        $v0, 8($v1)
/* 66B3E8 80219668 90420024 */  lbu       $v0, 0x24($v0)
/* 66B3EC 8021966C 8C640008 */  lw        $a0, 8($v1)
/* 66B3F0 80219670 02629823 */  subu      $s3, $s3, $v0
/* 66B3F4 80219674 A0730194 */  sb        $s3, 0x194($v1)
/* 66B3F8 80219678 90820025 */  lbu       $v0, 0x25($a0)
/* 66B3FC 8021967C 02429023 */  subu      $s2, $s2, $v0
/* 66B400 80219680 A0720195 */  sb        $s2, 0x195($v1)
/* 66B404 80219684 90820026 */  lbu       $v0, 0x26($a0)
/* 66B408 80219688 02028023 */  subu      $s0, $s0, $v0
/* 66B40C 8021968C A0700196 */  sb        $s0, 0x196($v1)
/* 66B410 80219690 90840027 */  lbu       $a0, 0x27($a0)
/* 66B414 80219694 02248823 */  subu      $s1, $s1, $a0
/* 66B418 80219698 A0710197 */  sb        $s1, 0x197($v1)
/* 66B41C 8021969C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 66B420 802196A0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 66B424 802196A4 8FB20018 */  lw        $s2, 0x18($sp)
/* 66B428 802196A8 8FB10014 */  lw        $s1, 0x14($sp)
/* 66B42C 802196AC 8FB00010 */  lw        $s0, 0x10($sp)
/* 66B430 802196B0 24020002 */  addiu     $v0, $zero, 2
/* 66B434 802196B4 03E00008 */  jr        $ra
/* 66B438 802196B8 27BD0028 */   addiu    $sp, $sp, 0x28
