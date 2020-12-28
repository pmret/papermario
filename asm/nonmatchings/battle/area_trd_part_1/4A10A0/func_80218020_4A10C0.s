.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218020_4A10C0
/* 4A10C0 80218020 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4A10C4 80218024 AFB10014 */  sw        $s1, 0x14($sp)
/* 4A10C8 80218028 0080882D */  daddu     $s1, $a0, $zero
/* 4A10CC 8021802C AFBF0020 */  sw        $ra, 0x20($sp)
/* 4A10D0 80218030 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4A10D4 80218034 AFB20018 */  sw        $s2, 0x18($sp)
/* 4A10D8 80218038 AFB00010 */  sw        $s0, 0x10($sp)
/* 4A10DC 8021803C 8E30000C */  lw        $s0, 0xc($s1)
/* 4A10E0 80218040 8E050000 */  lw        $a1, ($s0)
/* 4A10E4 80218044 0C0B1EAF */  jal       get_variable
/* 4A10E8 80218048 26100004 */   addiu    $s0, $s0, 4
/* 4A10EC 8021804C 8E050000 */  lw        $a1, ($s0)
/* 4A10F0 80218050 26100004 */  addiu     $s0, $s0, 4
/* 4A10F4 80218054 0220202D */  daddu     $a0, $s1, $zero
/* 4A10F8 80218058 0C0B1EAF */  jal       get_variable
/* 4A10FC 8021805C 0040982D */   daddu    $s3, $v0, $zero
/* 4A1100 80218060 8E050000 */  lw        $a1, ($s0)
/* 4A1104 80218064 26100004 */  addiu     $s0, $s0, 4
/* 4A1108 80218068 0220202D */  daddu     $a0, $s1, $zero
/* 4A110C 8021806C 0C0B1EAF */  jal       get_variable
/* 4A1110 80218070 0040902D */   daddu    $s2, $v0, $zero
/* 4A1114 80218074 0220202D */  daddu     $a0, $s1, $zero
/* 4A1118 80218078 8E050000 */  lw        $a1, ($s0)
/* 4A111C 8021807C 0C0B1EAF */  jal       get_variable
/* 4A1120 80218080 0040802D */   daddu    $s0, $v0, $zero
/* 4A1124 80218084 8E240148 */  lw        $a0, 0x148($s1)
/* 4A1128 80218088 0C09A75B */  jal       get_actor
/* 4A112C 8021808C 0040882D */   daddu    $s1, $v0, $zero
/* 4A1130 80218090 0040182D */  daddu     $v1, $v0, $zero
/* 4A1134 80218094 8C620008 */  lw        $v0, 8($v1)
/* 4A1138 80218098 90420024 */  lbu       $v0, 0x24($v0)
/* 4A113C 8021809C 8C640008 */  lw        $a0, 8($v1)
/* 4A1140 802180A0 02629823 */  subu      $s3, $s3, $v0
/* 4A1144 802180A4 A0730194 */  sb        $s3, 0x194($v1)
/* 4A1148 802180A8 90820025 */  lbu       $v0, 0x25($a0)
/* 4A114C 802180AC 02429023 */  subu      $s2, $s2, $v0
/* 4A1150 802180B0 A0720195 */  sb        $s2, 0x195($v1)
/* 4A1154 802180B4 90820026 */  lbu       $v0, 0x26($a0)
/* 4A1158 802180B8 02028023 */  subu      $s0, $s0, $v0
/* 4A115C 802180BC A0700196 */  sb        $s0, 0x196($v1)
/* 4A1160 802180C0 90840027 */  lbu       $a0, 0x27($a0)
/* 4A1164 802180C4 02248823 */  subu      $s1, $s1, $a0
/* 4A1168 802180C8 A0710197 */  sb        $s1, 0x197($v1)
/* 4A116C 802180CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4A1170 802180D0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4A1174 802180D4 8FB20018 */  lw        $s2, 0x18($sp)
/* 4A1178 802180D8 8FB10014 */  lw        $s1, 0x14($sp)
/* 4A117C 802180DC 8FB00010 */  lw        $s0, 0x10($sp)
/* 4A1180 802180E0 24020002 */  addiu     $v0, $zero, 2
/* 4A1184 802180E4 03E00008 */  jr        $ra
/* 4A1188 802180E8 27BD0028 */   addiu    $sp, $sp, 0x28
/* 4A118C 802180EC 00000000 */  nop       
