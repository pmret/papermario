.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218AB0_5ECF40
/* 5ECF40 80218AB0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 5ECF44 80218AB4 AFB10014 */  sw        $s1, 0x14($sp)
/* 5ECF48 80218AB8 0080882D */  daddu     $s1, $a0, $zero
/* 5ECF4C 80218ABC AFBF0020 */  sw        $ra, 0x20($sp)
/* 5ECF50 80218AC0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 5ECF54 80218AC4 AFB20018 */  sw        $s2, 0x18($sp)
/* 5ECF58 80218AC8 AFB00010 */  sw        $s0, 0x10($sp)
/* 5ECF5C 80218ACC 8E30000C */  lw        $s0, 0xc($s1)
/* 5ECF60 80218AD0 8E050000 */  lw        $a1, ($s0)
/* 5ECF64 80218AD4 0C0B1EAF */  jal       get_variable
/* 5ECF68 80218AD8 26100004 */   addiu    $s0, $s0, 4
/* 5ECF6C 80218ADC 8E050000 */  lw        $a1, ($s0)
/* 5ECF70 80218AE0 26100004 */  addiu     $s0, $s0, 4
/* 5ECF74 80218AE4 0220202D */  daddu     $a0, $s1, $zero
/* 5ECF78 80218AE8 0C0B1EAF */  jal       get_variable
/* 5ECF7C 80218AEC 0040982D */   daddu    $s3, $v0, $zero
/* 5ECF80 80218AF0 8E050000 */  lw        $a1, ($s0)
/* 5ECF84 80218AF4 26100004 */  addiu     $s0, $s0, 4
/* 5ECF88 80218AF8 0220202D */  daddu     $a0, $s1, $zero
/* 5ECF8C 80218AFC 0C0B1EAF */  jal       get_variable
/* 5ECF90 80218B00 0040902D */   daddu    $s2, $v0, $zero
/* 5ECF94 80218B04 0220202D */  daddu     $a0, $s1, $zero
/* 5ECF98 80218B08 8E050000 */  lw        $a1, ($s0)
/* 5ECF9C 80218B0C 0C0B1EAF */  jal       get_variable
/* 5ECFA0 80218B10 0040802D */   daddu    $s0, $v0, $zero
/* 5ECFA4 80218B14 8E240148 */  lw        $a0, 0x148($s1)
/* 5ECFA8 80218B18 0C09A75B */  jal       get_actor
/* 5ECFAC 80218B1C 0040882D */   daddu    $s1, $v0, $zero
/* 5ECFB0 80218B20 0040182D */  daddu     $v1, $v0, $zero
/* 5ECFB4 80218B24 8C620008 */  lw        $v0, 8($v1)
/* 5ECFB8 80218B28 90420024 */  lbu       $v0, 0x24($v0)
/* 5ECFBC 80218B2C 8C640008 */  lw        $a0, 8($v1)
/* 5ECFC0 80218B30 02629823 */  subu      $s3, $s3, $v0
/* 5ECFC4 80218B34 A0730194 */  sb        $s3, 0x194($v1)
/* 5ECFC8 80218B38 90820025 */  lbu       $v0, 0x25($a0)
/* 5ECFCC 80218B3C 02429023 */  subu      $s2, $s2, $v0
/* 5ECFD0 80218B40 A0720195 */  sb        $s2, 0x195($v1)
/* 5ECFD4 80218B44 90820026 */  lbu       $v0, 0x26($a0)
/* 5ECFD8 80218B48 02028023 */  subu      $s0, $s0, $v0
/* 5ECFDC 80218B4C A0700196 */  sb        $s0, 0x196($v1)
/* 5ECFE0 80218B50 90840027 */  lbu       $a0, 0x27($a0)
/* 5ECFE4 80218B54 02248823 */  subu      $s1, $s1, $a0
/* 5ECFE8 80218B58 A0710197 */  sb        $s1, 0x197($v1)
/* 5ECFEC 80218B5C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 5ECFF0 80218B60 8FB3001C */  lw        $s3, 0x1c($sp)
/* 5ECFF4 80218B64 8FB20018 */  lw        $s2, 0x18($sp)
/* 5ECFF8 80218B68 8FB10014 */  lw        $s1, 0x14($sp)
/* 5ECFFC 80218B6C 8FB00010 */  lw        $s0, 0x10($sp)
/* 5ED000 80218B70 24020002 */  addiu     $v0, $zero, 2
/* 5ED004 80218B74 03E00008 */  jr        $ra
/* 5ED008 80218B78 27BD0028 */   addiu    $sp, $sp, 0x28
/* 5ED00C 80218B7C 00000000 */  nop       
