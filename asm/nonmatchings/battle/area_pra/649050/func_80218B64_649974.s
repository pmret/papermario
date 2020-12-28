.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218B64_649974
/* 649974 80218B64 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 649978 80218B68 AFB10014 */  sw        $s1, 0x14($sp)
/* 64997C 80218B6C 0080882D */  daddu     $s1, $a0, $zero
/* 649980 80218B70 AFBF0020 */  sw        $ra, 0x20($sp)
/* 649984 80218B74 AFB3001C */  sw        $s3, 0x1c($sp)
/* 649988 80218B78 AFB20018 */  sw        $s2, 0x18($sp)
/* 64998C 80218B7C AFB00010 */  sw        $s0, 0x10($sp)
/* 649990 80218B80 8E30000C */  lw        $s0, 0xc($s1)
/* 649994 80218B84 8E050000 */  lw        $a1, ($s0)
/* 649998 80218B88 0C0B1EAF */  jal       get_variable
/* 64999C 80218B8C 26100004 */   addiu    $s0, $s0, 4
/* 6499A0 80218B90 8E050000 */  lw        $a1, ($s0)
/* 6499A4 80218B94 26100004 */  addiu     $s0, $s0, 4
/* 6499A8 80218B98 0220202D */  daddu     $a0, $s1, $zero
/* 6499AC 80218B9C 0C0B1EAF */  jal       get_variable
/* 6499B0 80218BA0 0040982D */   daddu    $s3, $v0, $zero
/* 6499B4 80218BA4 8E050000 */  lw        $a1, ($s0)
/* 6499B8 80218BA8 26100004 */  addiu     $s0, $s0, 4
/* 6499BC 80218BAC 0220202D */  daddu     $a0, $s1, $zero
/* 6499C0 80218BB0 0C0B1EAF */  jal       get_variable
/* 6499C4 80218BB4 0040902D */   daddu    $s2, $v0, $zero
/* 6499C8 80218BB8 0220202D */  daddu     $a0, $s1, $zero
/* 6499CC 80218BBC 8E050000 */  lw        $a1, ($s0)
/* 6499D0 80218BC0 0C0B1EAF */  jal       get_variable
/* 6499D4 80218BC4 0040802D */   daddu    $s0, $v0, $zero
/* 6499D8 80218BC8 8E240148 */  lw        $a0, 0x148($s1)
/* 6499DC 80218BCC 0C09A75B */  jal       get_actor
/* 6499E0 80218BD0 0040882D */   daddu    $s1, $v0, $zero
/* 6499E4 80218BD4 0040182D */  daddu     $v1, $v0, $zero
/* 6499E8 80218BD8 8C620008 */  lw        $v0, 8($v1)
/* 6499EC 80218BDC 90420024 */  lbu       $v0, 0x24($v0)
/* 6499F0 80218BE0 8C640008 */  lw        $a0, 8($v1)
/* 6499F4 80218BE4 02629823 */  subu      $s3, $s3, $v0
/* 6499F8 80218BE8 A0730194 */  sb        $s3, 0x194($v1)
/* 6499FC 80218BEC 90820025 */  lbu       $v0, 0x25($a0)
/* 649A00 80218BF0 02429023 */  subu      $s2, $s2, $v0
/* 649A04 80218BF4 A0720195 */  sb        $s2, 0x195($v1)
/* 649A08 80218BF8 90820026 */  lbu       $v0, 0x26($a0)
/* 649A0C 80218BFC 02028023 */  subu      $s0, $s0, $v0
/* 649A10 80218C00 A0700196 */  sb        $s0, 0x196($v1)
/* 649A14 80218C04 90840027 */  lbu       $a0, 0x27($a0)
/* 649A18 80218C08 02248823 */  subu      $s1, $s1, $a0
/* 649A1C 80218C0C A0710197 */  sb        $s1, 0x197($v1)
/* 649A20 80218C10 8FBF0020 */  lw        $ra, 0x20($sp)
/* 649A24 80218C14 8FB3001C */  lw        $s3, 0x1c($sp)
/* 649A28 80218C18 8FB20018 */  lw        $s2, 0x18($sp)
/* 649A2C 80218C1C 8FB10014 */  lw        $s1, 0x14($sp)
/* 649A30 80218C20 8FB00010 */  lw        $s0, 0x10($sp)
/* 649A34 80218C24 24020002 */  addiu     $v0, $zero, 2
/* 649A38 80218C28 03E00008 */  jr        $ra
/* 649A3C 80218C2C 27BD0028 */   addiu    $sp, $sp, 0x28
