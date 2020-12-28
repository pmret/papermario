.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802180B8_6DBE58
/* 6DBE58 802180B8 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 6DBE5C 802180BC AFB10014 */  sw        $s1, 0x14($sp)
/* 6DBE60 802180C0 0080882D */  daddu     $s1, $a0, $zero
/* 6DBE64 802180C4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 6DBE68 802180C8 AFB20018 */  sw        $s2, 0x18($sp)
/* 6DBE6C 802180CC AFB00010 */  sw        $s0, 0x10($sp)
/* 6DBE70 802180D0 F7B80030 */  sdc1      $f24, 0x30($sp)
/* 6DBE74 802180D4 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 6DBE78 802180D8 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 6DBE7C 802180DC 8E30000C */  lw        $s0, 0xc($s1)
/* 6DBE80 802180E0 8E050000 */  lw        $a1, ($s0)
/* 6DBE84 802180E4 0C0B1EAF */  jal       get_variable
/* 6DBE88 802180E8 26100004 */   addiu    $s0, $s0, 4
/* 6DBE8C 802180EC 8E050000 */  lw        $a1, ($s0)
/* 6DBE90 802180F0 26100004 */  addiu     $s0, $s0, 4
/* 6DBE94 802180F4 0220202D */  daddu     $a0, $s1, $zero
/* 6DBE98 802180F8 0C0B1EAF */  jal       get_variable
/* 6DBE9C 802180FC 0040902D */   daddu    $s2, $v0, $zero
/* 6DBEA0 80218100 8E050000 */  lw        $a1, ($s0)
/* 6DBEA4 80218104 26100004 */  addiu     $s0, $s0, 4
/* 6DBEA8 80218108 4482C000 */  mtc1      $v0, $f24
/* 6DBEAC 8021810C 00000000 */  nop       
/* 6DBEB0 80218110 4680C620 */  cvt.s.w   $f24, $f24
/* 6DBEB4 80218114 0C0B1EAF */  jal       get_variable
/* 6DBEB8 80218118 0220202D */   daddu    $a0, $s1, $zero
/* 6DBEBC 8021811C 8E050000 */  lw        $a1, ($s0)
/* 6DBEC0 80218120 4482B000 */  mtc1      $v0, $f22
/* 6DBEC4 80218124 00000000 */  nop       
/* 6DBEC8 80218128 4680B5A0 */  cvt.s.w   $f22, $f22
/* 6DBECC 8021812C 0C0B1EAF */  jal       get_variable
/* 6DBED0 80218130 0220202D */   daddu    $a0, $s1, $zero
/* 6DBED4 80218134 4482A000 */  mtc1      $v0, $f20
/* 6DBED8 80218138 00000000 */  nop       
/* 6DBEDC 8021813C 4680A520 */  cvt.s.w   $f20, $f20
/* 6DBEE0 80218140 0C04417A */  jal       get_entity_by_index
/* 6DBEE4 80218144 0240202D */   daddu    $a0, $s2, $zero
/* 6DBEE8 80218148 0040182D */  daddu     $v1, $v0, $zero
/* 6DBEEC 8021814C E4780048 */  swc1      $f24, 0x48($v1)
/* 6DBEF0 80218150 E476004C */  swc1      $f22, 0x4c($v1)
/* 6DBEF4 80218154 E4740050 */  swc1      $f20, 0x50($v1)
/* 6DBEF8 80218158 8FBF001C */  lw        $ra, 0x1c($sp)
/* 6DBEFC 8021815C 8FB20018 */  lw        $s2, 0x18($sp)
/* 6DBF00 80218160 8FB10014 */  lw        $s1, 0x14($sp)
/* 6DBF04 80218164 8FB00010 */  lw        $s0, 0x10($sp)
/* 6DBF08 80218168 D7B80030 */  ldc1      $f24, 0x30($sp)
/* 6DBF0C 8021816C D7B60028 */  ldc1      $f22, 0x28($sp)
/* 6DBF10 80218170 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 6DBF14 80218174 24020002 */  addiu     $v0, $zero, 2
/* 6DBF18 80218178 03E00008 */  jr        $ra
/* 6DBF1C 8021817C 27BD0038 */   addiu    $sp, $sp, 0x38
