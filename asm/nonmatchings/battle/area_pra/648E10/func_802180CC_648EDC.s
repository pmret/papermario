.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802180CC_648EDC
/* 648EDC 802180CC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 648EE0 802180D0 AFB10014 */  sw        $s1, 0x14($sp)
/* 648EE4 802180D4 0080882D */  daddu     $s1, $a0, $zero
/* 648EE8 802180D8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 648EEC 802180DC AFB3001C */  sw        $s3, 0x1c($sp)
/* 648EF0 802180E0 AFB20018 */  sw        $s2, 0x18($sp)
/* 648EF4 802180E4 AFB00010 */  sw        $s0, 0x10($sp)
/* 648EF8 802180E8 8E30000C */  lw        $s0, 0xc($s1)
/* 648EFC 802180EC 8E050000 */  lw        $a1, ($s0)
/* 648F00 802180F0 0C0B1EAF */  jal       get_variable
/* 648F04 802180F4 26100004 */   addiu    $s0, $s0, 4
/* 648F08 802180F8 8E050000 */  lw        $a1, ($s0)
/* 648F0C 802180FC 26100004 */  addiu     $s0, $s0, 4
/* 648F10 80218100 0220202D */  daddu     $a0, $s1, $zero
/* 648F14 80218104 0C0B1EAF */  jal       get_variable
/* 648F18 80218108 0040982D */   daddu    $s3, $v0, $zero
/* 648F1C 8021810C 8E050000 */  lw        $a1, ($s0)
/* 648F20 80218110 26100004 */  addiu     $s0, $s0, 4
/* 648F24 80218114 0220202D */  daddu     $a0, $s1, $zero
/* 648F28 80218118 0C0B1EAF */  jal       get_variable
/* 648F2C 8021811C 0040902D */   daddu    $s2, $v0, $zero
/* 648F30 80218120 0220202D */  daddu     $a0, $s1, $zero
/* 648F34 80218124 8E050000 */  lw        $a1, ($s0)
/* 648F38 80218128 0C0B1EAF */  jal       get_variable
/* 648F3C 8021812C 0040802D */   daddu    $s0, $v0, $zero
/* 648F40 80218130 44936000 */  mtc1      $s3, $f12
/* 648F44 80218134 00000000 */  nop       
/* 648F48 80218138 46806320 */  cvt.s.w   $f12, $f12
/* 648F4C 8021813C 44927000 */  mtc1      $s2, $f14
/* 648F50 80218140 00000000 */  nop       
/* 648F54 80218144 468073A0 */  cvt.s.w   $f14, $f14
/* 648F58 80218148 44900000 */  mtc1      $s0, $f0
/* 648F5C 8021814C 00000000 */  nop       
/* 648F60 80218150 46800020 */  cvt.s.w   $f0, $f0
/* 648F64 80218154 44060000 */  mfc1      $a2, $f0
/* 648F68 80218158 0C0B5D18 */  jal       func_802D7460
/* 648F6C 8021815C 0040382D */   daddu    $a3, $v0, $zero
/* 648F70 80218160 8FBF0020 */  lw        $ra, 0x20($sp)
/* 648F74 80218164 8FB3001C */  lw        $s3, 0x1c($sp)
/* 648F78 80218168 8FB20018 */  lw        $s2, 0x18($sp)
/* 648F7C 8021816C 8FB10014 */  lw        $s1, 0x14($sp)
/* 648F80 80218170 8FB00010 */  lw        $s0, 0x10($sp)
/* 648F84 80218174 24020002 */  addiu     $v0, $zero, 2
/* 648F88 80218178 03E00008 */  jr        $ra
/* 648F8C 8021817C 27BD0028 */   addiu    $sp, $sp, 0x28
