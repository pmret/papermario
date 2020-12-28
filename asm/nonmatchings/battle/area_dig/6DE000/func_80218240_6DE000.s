.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218240_6DE000
/* 6DE000 80218240 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 6DE004 80218244 AFB10014 */  sw        $s1, 0x14($sp)
/* 6DE008 80218248 0080882D */  daddu     $s1, $a0, $zero
/* 6DE00C 8021824C AFBF0020 */  sw        $ra, 0x20($sp)
/* 6DE010 80218250 AFB3001C */  sw        $s3, 0x1c($sp)
/* 6DE014 80218254 AFB20018 */  sw        $s2, 0x18($sp)
/* 6DE018 80218258 AFB00010 */  sw        $s0, 0x10($sp)
/* 6DE01C 8021825C 8E30000C */  lw        $s0, 0xc($s1)
/* 6DE020 80218260 8E050000 */  lw        $a1, ($s0)
/* 6DE024 80218264 0C0B1EAF */  jal       get_variable
/* 6DE028 80218268 26100004 */   addiu    $s0, $s0, 4
/* 6DE02C 8021826C 8E050000 */  lw        $a1, ($s0)
/* 6DE030 80218270 26100004 */  addiu     $s0, $s0, 4
/* 6DE034 80218274 0220202D */  daddu     $a0, $s1, $zero
/* 6DE038 80218278 0C0B1EAF */  jal       get_variable
/* 6DE03C 8021827C 0040982D */   daddu    $s3, $v0, $zero
/* 6DE040 80218280 8E050000 */  lw        $a1, ($s0)
/* 6DE044 80218284 26100004 */  addiu     $s0, $s0, 4
/* 6DE048 80218288 0220202D */  daddu     $a0, $s1, $zero
/* 6DE04C 8021828C 0C0B1EAF */  jal       get_variable
/* 6DE050 80218290 0040902D */   daddu    $s2, $v0, $zero
/* 6DE054 80218294 0220202D */  daddu     $a0, $s1, $zero
/* 6DE058 80218298 8E050000 */  lw        $a1, ($s0)
/* 6DE05C 8021829C 0C0B1EAF */  jal       get_variable
/* 6DE060 802182A0 0040802D */   daddu    $s0, $v0, $zero
/* 6DE064 802182A4 8E240148 */  lw        $a0, 0x148($s1)
/* 6DE068 802182A8 0C09A75B */  jal       get_actor
/* 6DE06C 802182AC 0040882D */   daddu    $s1, $v0, $zero
/* 6DE070 802182B0 0040182D */  daddu     $v1, $v0, $zero
/* 6DE074 802182B4 8C620008 */  lw        $v0, 8($v1)
/* 6DE078 802182B8 90420024 */  lbu       $v0, 0x24($v0)
/* 6DE07C 802182BC 8C640008 */  lw        $a0, 8($v1)
/* 6DE080 802182C0 02629823 */  subu      $s3, $s3, $v0
/* 6DE084 802182C4 A0730194 */  sb        $s3, 0x194($v1)
/* 6DE088 802182C8 90820025 */  lbu       $v0, 0x25($a0)
/* 6DE08C 802182CC 02429023 */  subu      $s2, $s2, $v0
/* 6DE090 802182D0 A0720195 */  sb        $s2, 0x195($v1)
/* 6DE094 802182D4 90820026 */  lbu       $v0, 0x26($a0)
/* 6DE098 802182D8 02028023 */  subu      $s0, $s0, $v0
/* 6DE09C 802182DC A0700196 */  sb        $s0, 0x196($v1)
/* 6DE0A0 802182E0 90840027 */  lbu       $a0, 0x27($a0)
/* 6DE0A4 802182E4 02248823 */  subu      $s1, $s1, $a0
/* 6DE0A8 802182E8 A0710197 */  sb        $s1, 0x197($v1)
/* 6DE0AC 802182EC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 6DE0B0 802182F0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 6DE0B4 802182F4 8FB20018 */  lw        $s2, 0x18($sp)
/* 6DE0B8 802182F8 8FB10014 */  lw        $s1, 0x14($sp)
/* 6DE0BC 802182FC 8FB00010 */  lw        $s0, 0x10($sp)
/* 6DE0C0 80218300 24020002 */  addiu     $v0, $zero, 2
/* 6DE0C4 80218304 03E00008 */  jr        $ra
/* 6DE0C8 80218308 27BD0028 */   addiu    $sp, $sp, 0x28
/* 6DE0CC 8021830C 00000000 */  nop       
