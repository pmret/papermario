.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219D24_66BAA4
/* 66BAA4 80219D24 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 66BAA8 80219D28 AFB10014 */  sw        $s1, 0x14($sp)
/* 66BAAC 80219D2C 0080882D */  daddu     $s1, $a0, $zero
/* 66BAB0 80219D30 AFBF0020 */  sw        $ra, 0x20($sp)
/* 66BAB4 80219D34 AFB3001C */  sw        $s3, 0x1c($sp)
/* 66BAB8 80219D38 AFB20018 */  sw        $s2, 0x18($sp)
/* 66BABC 80219D3C AFB00010 */  sw        $s0, 0x10($sp)
/* 66BAC0 80219D40 8E30000C */  lw        $s0, 0xc($s1)
/* 66BAC4 80219D44 8E050000 */  lw        $a1, ($s0)
/* 66BAC8 80219D48 0C0B1EAF */  jal       get_variable
/* 66BACC 80219D4C 26100004 */   addiu    $s0, $s0, 4
/* 66BAD0 80219D50 8E050000 */  lw        $a1, ($s0)
/* 66BAD4 80219D54 26100004 */  addiu     $s0, $s0, 4
/* 66BAD8 80219D58 0220202D */  daddu     $a0, $s1, $zero
/* 66BADC 80219D5C 0C0B1EAF */  jal       get_variable
/* 66BAE0 80219D60 0040982D */   daddu    $s3, $v0, $zero
/* 66BAE4 80219D64 8E050000 */  lw        $a1, ($s0)
/* 66BAE8 80219D68 26100004 */  addiu     $s0, $s0, 4
/* 66BAEC 80219D6C 0220202D */  daddu     $a0, $s1, $zero
/* 66BAF0 80219D70 0C0B1EAF */  jal       get_variable
/* 66BAF4 80219D74 0040902D */   daddu    $s2, $v0, $zero
/* 66BAF8 80219D78 0220202D */  daddu     $a0, $s1, $zero
/* 66BAFC 80219D7C 8E050000 */  lw        $a1, ($s0)
/* 66BB00 80219D80 0C0B1EAF */  jal       get_variable
/* 66BB04 80219D84 0040802D */   daddu    $s0, $v0, $zero
/* 66BB08 80219D88 8E240148 */  lw        $a0, 0x148($s1)
/* 66BB0C 80219D8C 0C09A75B */  jal       get_actor
/* 66BB10 80219D90 0040882D */   daddu    $s1, $v0, $zero
/* 66BB14 80219D94 0040182D */  daddu     $v1, $v0, $zero
/* 66BB18 80219D98 8C620008 */  lw        $v0, 8($v1)
/* 66BB1C 80219D9C 90420024 */  lbu       $v0, 0x24($v0)
/* 66BB20 80219DA0 8C640008 */  lw        $a0, 8($v1)
/* 66BB24 80219DA4 02629823 */  subu      $s3, $s3, $v0
/* 66BB28 80219DA8 A0730194 */  sb        $s3, 0x194($v1)
/* 66BB2C 80219DAC 90820025 */  lbu       $v0, 0x25($a0)
/* 66BB30 80219DB0 02429023 */  subu      $s2, $s2, $v0
/* 66BB34 80219DB4 A0720195 */  sb        $s2, 0x195($v1)
/* 66BB38 80219DB8 90820026 */  lbu       $v0, 0x26($a0)
/* 66BB3C 80219DBC 02028023 */  subu      $s0, $s0, $v0
/* 66BB40 80219DC0 A0700196 */  sb        $s0, 0x196($v1)
/* 66BB44 80219DC4 90840027 */  lbu       $a0, 0x27($a0)
/* 66BB48 80219DC8 02248823 */  subu      $s1, $s1, $a0
/* 66BB4C 80219DCC A0710197 */  sb        $s1, 0x197($v1)
/* 66BB50 80219DD0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 66BB54 80219DD4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 66BB58 80219DD8 8FB20018 */  lw        $s2, 0x18($sp)
/* 66BB5C 80219DDC 8FB10014 */  lw        $s1, 0x14($sp)
/* 66BB60 80219DE0 8FB00010 */  lw        $s0, 0x10($sp)
/* 66BB64 80219DE4 24020002 */  addiu     $v0, $zero, 2
/* 66BB68 80219DE8 03E00008 */  jr        $ra
/* 66BB6C 80219DEC 27BD0028 */   addiu    $sp, $sp, 0x28
