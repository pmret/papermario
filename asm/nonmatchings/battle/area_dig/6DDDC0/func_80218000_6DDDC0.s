.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218000_6DDDC0
/* 6DDDC0 80218000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 6DDDC4 80218004 AFB10014 */  sw        $s1, 0x14($sp)
/* 6DDDC8 80218008 0080882D */  daddu     $s1, $a0, $zero
/* 6DDDCC 8021800C AFBF0020 */  sw        $ra, 0x20($sp)
/* 6DDDD0 80218010 AFB3001C */  sw        $s3, 0x1c($sp)
/* 6DDDD4 80218014 AFB20018 */  sw        $s2, 0x18($sp)
/* 6DDDD8 80218018 AFB00010 */  sw        $s0, 0x10($sp)
/* 6DDDDC 8021801C 8E30000C */  lw        $s0, 0xc($s1)
/* 6DDDE0 80218020 8E050000 */  lw        $a1, ($s0)
/* 6DDDE4 80218024 0C0B1EAF */  jal       get_variable
/* 6DDDE8 80218028 26100004 */   addiu    $s0, $s0, 4
/* 6DDDEC 8021802C 8E050000 */  lw        $a1, ($s0)
/* 6DDDF0 80218030 26100004 */  addiu     $s0, $s0, 4
/* 6DDDF4 80218034 0220202D */  daddu     $a0, $s1, $zero
/* 6DDDF8 80218038 0C0B1EAF */  jal       get_variable
/* 6DDDFC 8021803C 0040982D */   daddu    $s3, $v0, $zero
/* 6DDE00 80218040 8E050000 */  lw        $a1, ($s0)
/* 6DDE04 80218044 26100004 */  addiu     $s0, $s0, 4
/* 6DDE08 80218048 0220202D */  daddu     $a0, $s1, $zero
/* 6DDE0C 8021804C 0C0B1EAF */  jal       get_variable
/* 6DDE10 80218050 0040902D */   daddu    $s2, $v0, $zero
/* 6DDE14 80218054 0220202D */  daddu     $a0, $s1, $zero
/* 6DDE18 80218058 8E050000 */  lw        $a1, ($s0)
/* 6DDE1C 8021805C 0C0B1EAF */  jal       get_variable
/* 6DDE20 80218060 0040802D */   daddu    $s0, $v0, $zero
/* 6DDE24 80218064 8E240148 */  lw        $a0, 0x148($s1)
/* 6DDE28 80218068 0C09A75B */  jal       get_actor
/* 6DDE2C 8021806C 0040882D */   daddu    $s1, $v0, $zero
/* 6DDE30 80218070 0040182D */  daddu     $v1, $v0, $zero
/* 6DDE34 80218074 8C620008 */  lw        $v0, 8($v1)
/* 6DDE38 80218078 90420024 */  lbu       $v0, 0x24($v0)
/* 6DDE3C 8021807C 8C640008 */  lw        $a0, 8($v1)
/* 6DDE40 80218080 02629823 */  subu      $s3, $s3, $v0
/* 6DDE44 80218084 A0730194 */  sb        $s3, 0x194($v1)
/* 6DDE48 80218088 90820025 */  lbu       $v0, 0x25($a0)
/* 6DDE4C 8021808C 02429023 */  subu      $s2, $s2, $v0
/* 6DDE50 80218090 A0720195 */  sb        $s2, 0x195($v1)
/* 6DDE54 80218094 90820026 */  lbu       $v0, 0x26($a0)
/* 6DDE58 80218098 02028023 */  subu      $s0, $s0, $v0
/* 6DDE5C 8021809C A0700196 */  sb        $s0, 0x196($v1)
/* 6DDE60 802180A0 90840027 */  lbu       $a0, 0x27($a0)
/* 6DDE64 802180A4 02248823 */  subu      $s1, $s1, $a0
/* 6DDE68 802180A8 A0710197 */  sb        $s1, 0x197($v1)
/* 6DDE6C 802180AC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 6DDE70 802180B0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 6DDE74 802180B4 8FB20018 */  lw        $s2, 0x18($sp)
/* 6DDE78 802180B8 8FB10014 */  lw        $s1, 0x14($sp)
/* 6DDE7C 802180BC 8FB00010 */  lw        $s0, 0x10($sp)
/* 6DDE80 802180C0 24020002 */  addiu     $v0, $zero, 2
/* 6DDE84 802180C4 03E00008 */  jr        $ra
/* 6DDE88 802180C8 27BD0028 */   addiu    $sp, $sp, 0x28
/* 6DDE8C 802180CC 00000000 */  nop       
