.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218B74_624714
/* 624714 80218B74 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 624718 80218B78 AFB10014 */  sw        $s1, 0x14($sp)
/* 62471C 80218B7C 0080882D */  daddu     $s1, $a0, $zero
/* 624720 80218B80 AFBF0020 */  sw        $ra, 0x20($sp)
/* 624724 80218B84 AFB3001C */  sw        $s3, 0x1c($sp)
/* 624728 80218B88 AFB20018 */  sw        $s2, 0x18($sp)
/* 62472C 80218B8C AFB00010 */  sw        $s0, 0x10($sp)
/* 624730 80218B90 8E30000C */  lw        $s0, 0xc($s1)
/* 624734 80218B94 8E050000 */  lw        $a1, ($s0)
/* 624738 80218B98 0C0B1EAF */  jal       get_variable
/* 62473C 80218B9C 26100004 */   addiu    $s0, $s0, 4
/* 624740 80218BA0 8E050000 */  lw        $a1, ($s0)
/* 624744 80218BA4 26100004 */  addiu     $s0, $s0, 4
/* 624748 80218BA8 0220202D */  daddu     $a0, $s1, $zero
/* 62474C 80218BAC 0C0B1EAF */  jal       get_variable
/* 624750 80218BB0 0040982D */   daddu    $s3, $v0, $zero
/* 624754 80218BB4 8E050000 */  lw        $a1, ($s0)
/* 624758 80218BB8 26100004 */  addiu     $s0, $s0, 4
/* 62475C 80218BBC 0220202D */  daddu     $a0, $s1, $zero
/* 624760 80218BC0 0C0B1EAF */  jal       get_variable
/* 624764 80218BC4 0040902D */   daddu    $s2, $v0, $zero
/* 624768 80218BC8 0220202D */  daddu     $a0, $s1, $zero
/* 62476C 80218BCC 8E050000 */  lw        $a1, ($s0)
/* 624770 80218BD0 0C0B1EAF */  jal       get_variable
/* 624774 80218BD4 0040802D */   daddu    $s0, $v0, $zero
/* 624778 80218BD8 8E240148 */  lw        $a0, 0x148($s1)
/* 62477C 80218BDC 0C09A75B */  jal       get_actor
/* 624780 80218BE0 0040882D */   daddu    $s1, $v0, $zero
/* 624784 80218BE4 0040182D */  daddu     $v1, $v0, $zero
/* 624788 80218BE8 8C620008 */  lw        $v0, 8($v1)
/* 62478C 80218BEC 90420024 */  lbu       $v0, 0x24($v0)
/* 624790 80218BF0 8C640008 */  lw        $a0, 8($v1)
/* 624794 80218BF4 02629823 */  subu      $s3, $s3, $v0
/* 624798 80218BF8 A0730194 */  sb        $s3, 0x194($v1)
/* 62479C 80218BFC 90820025 */  lbu       $v0, 0x25($a0)
/* 6247A0 80218C00 02429023 */  subu      $s2, $s2, $v0
/* 6247A4 80218C04 A0720195 */  sb        $s2, 0x195($v1)
/* 6247A8 80218C08 90820026 */  lbu       $v0, 0x26($a0)
/* 6247AC 80218C0C 02028023 */  subu      $s0, $s0, $v0
/* 6247B0 80218C10 A0700196 */  sb        $s0, 0x196($v1)
/* 6247B4 80218C14 90840027 */  lbu       $a0, 0x27($a0)
/* 6247B8 80218C18 02248823 */  subu      $s1, $s1, $a0
/* 6247BC 80218C1C A0710197 */  sb        $s1, 0x197($v1)
/* 6247C0 80218C20 8FBF0020 */  lw        $ra, 0x20($sp)
/* 6247C4 80218C24 8FB3001C */  lw        $s3, 0x1c($sp)
/* 6247C8 80218C28 8FB20018 */  lw        $s2, 0x18($sp)
/* 6247CC 80218C2C 8FB10014 */  lw        $s1, 0x14($sp)
/* 6247D0 80218C30 8FB00010 */  lw        $s0, 0x10($sp)
/* 6247D4 80218C34 24020002 */  addiu     $v0, $zero, 2
/* 6247D8 80218C38 03E00008 */  jr        $ra
/* 6247DC 80218C3C 27BD0028 */   addiu    $sp, $sp, 0x28
