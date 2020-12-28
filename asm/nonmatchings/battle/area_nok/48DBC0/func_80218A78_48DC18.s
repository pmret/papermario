.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218A78_48DC18
/* 48DC18 80218A78 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 48DC1C 80218A7C AFB10014 */  sw        $s1, 0x14($sp)
/* 48DC20 80218A80 0080882D */  daddu     $s1, $a0, $zero
/* 48DC24 80218A84 AFBF0020 */  sw        $ra, 0x20($sp)
/* 48DC28 80218A88 AFB3001C */  sw        $s3, 0x1c($sp)
/* 48DC2C 80218A8C AFB20018 */  sw        $s2, 0x18($sp)
/* 48DC30 80218A90 AFB00010 */  sw        $s0, 0x10($sp)
/* 48DC34 80218A94 8E30000C */  lw        $s0, 0xc($s1)
/* 48DC38 80218A98 8E050000 */  lw        $a1, ($s0)
/* 48DC3C 80218A9C 0C0B1EAF */  jal       get_variable
/* 48DC40 80218AA0 26100004 */   addiu    $s0, $s0, 4
/* 48DC44 80218AA4 8E050000 */  lw        $a1, ($s0)
/* 48DC48 80218AA8 26100004 */  addiu     $s0, $s0, 4
/* 48DC4C 80218AAC 0220202D */  daddu     $a0, $s1, $zero
/* 48DC50 80218AB0 0C0B1EAF */  jal       get_variable
/* 48DC54 80218AB4 0040982D */   daddu    $s3, $v0, $zero
/* 48DC58 80218AB8 8E050000 */  lw        $a1, ($s0)
/* 48DC5C 80218ABC 26100004 */  addiu     $s0, $s0, 4
/* 48DC60 80218AC0 0220202D */  daddu     $a0, $s1, $zero
/* 48DC64 80218AC4 0C0B1EAF */  jal       get_variable
/* 48DC68 80218AC8 0040902D */   daddu    $s2, $v0, $zero
/* 48DC6C 80218ACC 0220202D */  daddu     $a0, $s1, $zero
/* 48DC70 80218AD0 8E050000 */  lw        $a1, ($s0)
/* 48DC74 80218AD4 0C0B1EAF */  jal       get_variable
/* 48DC78 80218AD8 0040802D */   daddu    $s0, $v0, $zero
/* 48DC7C 80218ADC 8E240148 */  lw        $a0, 0x148($s1)
/* 48DC80 80218AE0 0C09A75B */  jal       get_actor
/* 48DC84 80218AE4 0040882D */   daddu    $s1, $v0, $zero
/* 48DC88 80218AE8 0040182D */  daddu     $v1, $v0, $zero
/* 48DC8C 80218AEC 8C620008 */  lw        $v0, 8($v1)
/* 48DC90 80218AF0 90420024 */  lbu       $v0, 0x24($v0)
/* 48DC94 80218AF4 8C640008 */  lw        $a0, 8($v1)
/* 48DC98 80218AF8 02629823 */  subu      $s3, $s3, $v0
/* 48DC9C 80218AFC A0730194 */  sb        $s3, 0x194($v1)
/* 48DCA0 80218B00 90820025 */  lbu       $v0, 0x25($a0)
/* 48DCA4 80218B04 02429023 */  subu      $s2, $s2, $v0
/* 48DCA8 80218B08 A0720195 */  sb        $s2, 0x195($v1)
/* 48DCAC 80218B0C 90820026 */  lbu       $v0, 0x26($a0)
/* 48DCB0 80218B10 02028023 */  subu      $s0, $s0, $v0
/* 48DCB4 80218B14 A0700196 */  sb        $s0, 0x196($v1)
/* 48DCB8 80218B18 90840027 */  lbu       $a0, 0x27($a0)
/* 48DCBC 80218B1C 02248823 */  subu      $s1, $s1, $a0
/* 48DCC0 80218B20 A0710197 */  sb        $s1, 0x197($v1)
/* 48DCC4 80218B24 8FBF0020 */  lw        $ra, 0x20($sp)
/* 48DCC8 80218B28 8FB3001C */  lw        $s3, 0x1c($sp)
/* 48DCCC 80218B2C 8FB20018 */  lw        $s2, 0x18($sp)
/* 48DCD0 80218B30 8FB10014 */  lw        $s1, 0x14($sp)
/* 48DCD4 80218B34 8FB00010 */  lw        $s0, 0x10($sp)
/* 48DCD8 80218B38 24020002 */  addiu     $v0, $zero, 2
/* 48DCDC 80218B3C 03E00008 */  jr        $ra
/* 48DCE0 80218B40 27BD0028 */   addiu    $sp, $sp, 0x28
/* 48DCE4 80218B44 00000000 */  nop       
/* 48DCE8 80218B48 00000000 */  nop       
/* 48DCEC 80218B4C 00000000 */  nop       
