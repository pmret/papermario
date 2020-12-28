.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218000_6BBB90
/* 6BBB90 80218000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 6BBB94 80218004 AFB10014 */  sw        $s1, 0x14($sp)
/* 6BBB98 80218008 0080882D */  daddu     $s1, $a0, $zero
/* 6BBB9C 8021800C AFBF0020 */  sw        $ra, 0x20($sp)
/* 6BBBA0 80218010 AFB3001C */  sw        $s3, 0x1c($sp)
/* 6BBBA4 80218014 AFB20018 */  sw        $s2, 0x18($sp)
/* 6BBBA8 80218018 AFB00010 */  sw        $s0, 0x10($sp)
/* 6BBBAC 8021801C 8E30000C */  lw        $s0, 0xc($s1)
/* 6BBBB0 80218020 8E050000 */  lw        $a1, ($s0)
/* 6BBBB4 80218024 0C0B1EAF */  jal       get_variable
/* 6BBBB8 80218028 26100004 */   addiu    $s0, $s0, 4
/* 6BBBBC 8021802C 8E050000 */  lw        $a1, ($s0)
/* 6BBBC0 80218030 26100004 */  addiu     $s0, $s0, 4
/* 6BBBC4 80218034 0220202D */  daddu     $a0, $s1, $zero
/* 6BBBC8 80218038 0C0B1EAF */  jal       get_variable
/* 6BBBCC 8021803C 0040982D */   daddu    $s3, $v0, $zero
/* 6BBBD0 80218040 8E050000 */  lw        $a1, ($s0)
/* 6BBBD4 80218044 26100004 */  addiu     $s0, $s0, 4
/* 6BBBD8 80218048 0220202D */  daddu     $a0, $s1, $zero
/* 6BBBDC 8021804C 0C0B1EAF */  jal       get_variable
/* 6BBBE0 80218050 0040902D */   daddu    $s2, $v0, $zero
/* 6BBBE4 80218054 0220202D */  daddu     $a0, $s1, $zero
/* 6BBBE8 80218058 8E050000 */  lw        $a1, ($s0)
/* 6BBBEC 8021805C 0C0B1EAF */  jal       get_variable
/* 6BBBF0 80218060 0040802D */   daddu    $s0, $v0, $zero
/* 6BBBF4 80218064 8E240148 */  lw        $a0, 0x148($s1)
/* 6BBBF8 80218068 0C09A75B */  jal       get_actor
/* 6BBBFC 8021806C 0040882D */   daddu    $s1, $v0, $zero
/* 6BBC00 80218070 0040182D */  daddu     $v1, $v0, $zero
/* 6BBC04 80218074 8C620008 */  lw        $v0, 8($v1)
/* 6BBC08 80218078 90420024 */  lbu       $v0, 0x24($v0)
/* 6BBC0C 8021807C 8C640008 */  lw        $a0, 8($v1)
/* 6BBC10 80218080 02629823 */  subu      $s3, $s3, $v0
/* 6BBC14 80218084 A0730194 */  sb        $s3, 0x194($v1)
/* 6BBC18 80218088 90820025 */  lbu       $v0, 0x25($a0)
/* 6BBC1C 8021808C 02429023 */  subu      $s2, $s2, $v0
/* 6BBC20 80218090 A0720195 */  sb        $s2, 0x195($v1)
/* 6BBC24 80218094 90820026 */  lbu       $v0, 0x26($a0)
/* 6BBC28 80218098 02028023 */  subu      $s0, $s0, $v0
/* 6BBC2C 8021809C A0700196 */  sb        $s0, 0x196($v1)
/* 6BBC30 802180A0 90840027 */  lbu       $a0, 0x27($a0)
/* 6BBC34 802180A4 02248823 */  subu      $s1, $s1, $a0
/* 6BBC38 802180A8 A0710197 */  sb        $s1, 0x197($v1)
/* 6BBC3C 802180AC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 6BBC40 802180B0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 6BBC44 802180B4 8FB20018 */  lw        $s2, 0x18($sp)
/* 6BBC48 802180B8 8FB10014 */  lw        $s1, 0x14($sp)
/* 6BBC4C 802180BC 8FB00010 */  lw        $s0, 0x10($sp)
/* 6BBC50 802180C0 24020002 */  addiu     $v0, $zero, 2
/* 6BBC54 802180C4 03E00008 */  jr        $ra
/* 6BBC58 802180C8 27BD0028 */   addiu    $sp, $sp, 0x28
/* 6BBC5C 802180CC 00000000 */  nop       
