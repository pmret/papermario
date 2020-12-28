.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802180D0_6DDE90
/* 6DDE90 802180D0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 6DDE94 802180D4 AFB10014 */  sw        $s1, 0x14($sp)
/* 6DDE98 802180D8 0080882D */  daddu     $s1, $a0, $zero
/* 6DDE9C 802180DC AFBF0020 */  sw        $ra, 0x20($sp)
/* 6DDEA0 802180E0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 6DDEA4 802180E4 AFB20018 */  sw        $s2, 0x18($sp)
/* 6DDEA8 802180E8 AFB00010 */  sw        $s0, 0x10($sp)
/* 6DDEAC 802180EC 8E30000C */  lw        $s0, 0xc($s1)
/* 6DDEB0 802180F0 8E050000 */  lw        $a1, ($s0)
/* 6DDEB4 802180F4 0C0B1EAF */  jal       get_variable
/* 6DDEB8 802180F8 26100004 */   addiu    $s0, $s0, 4
/* 6DDEBC 802180FC 8E050000 */  lw        $a1, ($s0)
/* 6DDEC0 80218100 26100004 */  addiu     $s0, $s0, 4
/* 6DDEC4 80218104 0220202D */  daddu     $a0, $s1, $zero
/* 6DDEC8 80218108 0C0B1EAF */  jal       get_variable
/* 6DDECC 8021810C 0040982D */   daddu    $s3, $v0, $zero
/* 6DDED0 80218110 8E050000 */  lw        $a1, ($s0)
/* 6DDED4 80218114 26100004 */  addiu     $s0, $s0, 4
/* 6DDED8 80218118 0220202D */  daddu     $a0, $s1, $zero
/* 6DDEDC 8021811C 0C0B1EAF */  jal       get_variable
/* 6DDEE0 80218120 0040902D */   daddu    $s2, $v0, $zero
/* 6DDEE4 80218124 0220202D */  daddu     $a0, $s1, $zero
/* 6DDEE8 80218128 8E050000 */  lw        $a1, ($s0)
/* 6DDEEC 8021812C 0C0B1EAF */  jal       get_variable
/* 6DDEF0 80218130 0040802D */   daddu    $s0, $v0, $zero
/* 6DDEF4 80218134 44936000 */  mtc1      $s3, $f12
/* 6DDEF8 80218138 00000000 */  nop       
/* 6DDEFC 8021813C 46806320 */  cvt.s.w   $f12, $f12
/* 6DDF00 80218140 44927000 */  mtc1      $s2, $f14
/* 6DDF04 80218144 00000000 */  nop       
/* 6DDF08 80218148 468073A0 */  cvt.s.w   $f14, $f14
/* 6DDF0C 8021814C 44900000 */  mtc1      $s0, $f0
/* 6DDF10 80218150 00000000 */  nop       
/* 6DDF14 80218154 46800020 */  cvt.s.w   $f0, $f0
/* 6DDF18 80218158 44060000 */  mfc1      $a2, $f0
/* 6DDF1C 8021815C 0C0B5D18 */  jal       func_802D7460
/* 6DDF20 80218160 0040382D */   daddu    $a3, $v0, $zero
/* 6DDF24 80218164 8FBF0020 */  lw        $ra, 0x20($sp)
/* 6DDF28 80218168 8FB3001C */  lw        $s3, 0x1c($sp)
/* 6DDF2C 8021816C 8FB20018 */  lw        $s2, 0x18($sp)
/* 6DDF30 80218170 8FB10014 */  lw        $s1, 0x14($sp)
/* 6DDF34 80218174 8FB00010 */  lw        $s0, 0x10($sp)
/* 6DDF38 80218178 24020002 */  addiu     $v0, $zero, 2
/* 6DDF3C 8021817C 03E00008 */  jr        $ra
/* 6DDF40 80218180 27BD0028 */   addiu    $sp, $sp, 0x28
