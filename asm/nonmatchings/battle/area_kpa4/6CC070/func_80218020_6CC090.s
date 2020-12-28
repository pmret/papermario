.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218020_6CC090
/* 6CC090 80218020 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 6CC094 80218024 AFB10014 */  sw        $s1, 0x14($sp)
/* 6CC098 80218028 0080882D */  daddu     $s1, $a0, $zero
/* 6CC09C 8021802C AFBF0020 */  sw        $ra, 0x20($sp)
/* 6CC0A0 80218030 AFB3001C */  sw        $s3, 0x1c($sp)
/* 6CC0A4 80218034 AFB20018 */  sw        $s2, 0x18($sp)
/* 6CC0A8 80218038 AFB00010 */  sw        $s0, 0x10($sp)
/* 6CC0AC 8021803C 8E30000C */  lw        $s0, 0xc($s1)
/* 6CC0B0 80218040 8E050000 */  lw        $a1, ($s0)
/* 6CC0B4 80218044 0C0B1EAF */  jal       get_variable
/* 6CC0B8 80218048 26100004 */   addiu    $s0, $s0, 4
/* 6CC0BC 8021804C 8E050000 */  lw        $a1, ($s0)
/* 6CC0C0 80218050 26100004 */  addiu     $s0, $s0, 4
/* 6CC0C4 80218054 0220202D */  daddu     $a0, $s1, $zero
/* 6CC0C8 80218058 0C0B1EAF */  jal       get_variable
/* 6CC0CC 8021805C 0040982D */   daddu    $s3, $v0, $zero
/* 6CC0D0 80218060 8E050000 */  lw        $a1, ($s0)
/* 6CC0D4 80218064 26100004 */  addiu     $s0, $s0, 4
/* 6CC0D8 80218068 0220202D */  daddu     $a0, $s1, $zero
/* 6CC0DC 8021806C 0C0B1EAF */  jal       get_variable
/* 6CC0E0 80218070 0040902D */   daddu    $s2, $v0, $zero
/* 6CC0E4 80218074 0220202D */  daddu     $a0, $s1, $zero
/* 6CC0E8 80218078 8E050000 */  lw        $a1, ($s0)
/* 6CC0EC 8021807C 0C0B1EAF */  jal       get_variable
/* 6CC0F0 80218080 0040802D */   daddu    $s0, $v0, $zero
/* 6CC0F4 80218084 8E240148 */  lw        $a0, 0x148($s1)
/* 6CC0F8 80218088 0C09A75B */  jal       get_actor
/* 6CC0FC 8021808C 0040882D */   daddu    $s1, $v0, $zero
/* 6CC100 80218090 0040182D */  daddu     $v1, $v0, $zero
/* 6CC104 80218094 8C620008 */  lw        $v0, 8($v1)
/* 6CC108 80218098 90420024 */  lbu       $v0, 0x24($v0)
/* 6CC10C 8021809C 8C640008 */  lw        $a0, 8($v1)
/* 6CC110 802180A0 02629823 */  subu      $s3, $s3, $v0
/* 6CC114 802180A4 A0730194 */  sb        $s3, 0x194($v1)
/* 6CC118 802180A8 90820025 */  lbu       $v0, 0x25($a0)
/* 6CC11C 802180AC 02429023 */  subu      $s2, $s2, $v0
/* 6CC120 802180B0 A0720195 */  sb        $s2, 0x195($v1)
/* 6CC124 802180B4 90820026 */  lbu       $v0, 0x26($a0)
/* 6CC128 802180B8 02028023 */  subu      $s0, $s0, $v0
/* 6CC12C 802180BC A0700196 */  sb        $s0, 0x196($v1)
/* 6CC130 802180C0 90840027 */  lbu       $a0, 0x27($a0)
/* 6CC134 802180C4 02248823 */  subu      $s1, $s1, $a0
/* 6CC138 802180C8 A0710197 */  sb        $s1, 0x197($v1)
/* 6CC13C 802180CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 6CC140 802180D0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 6CC144 802180D4 8FB20018 */  lw        $s2, 0x18($sp)
/* 6CC148 802180D8 8FB10014 */  lw        $s1, 0x14($sp)
/* 6CC14C 802180DC 8FB00010 */  lw        $s0, 0x10($sp)
/* 6CC150 802180E0 24020002 */  addiu     $v0, $zero, 2
/* 6CC154 802180E4 03E00008 */  jr        $ra
/* 6CC158 802180E8 27BD0028 */   addiu    $sp, $sp, 0x28
