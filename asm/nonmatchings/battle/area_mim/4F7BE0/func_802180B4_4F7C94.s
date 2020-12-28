.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802180B4_4F7C94
/* 4F7C94 802180B4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4F7C98 802180B8 AFB10014 */  sw        $s1, 0x14($sp)
/* 4F7C9C 802180BC 0080882D */  daddu     $s1, $a0, $zero
/* 4F7CA0 802180C0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 4F7CA4 802180C4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4F7CA8 802180C8 AFB20018 */  sw        $s2, 0x18($sp)
/* 4F7CAC 802180CC AFB00010 */  sw        $s0, 0x10($sp)
/* 4F7CB0 802180D0 8E30000C */  lw        $s0, 0xc($s1)
/* 4F7CB4 802180D4 8E050000 */  lw        $a1, ($s0)
/* 4F7CB8 802180D8 0C0B1EAF */  jal       get_variable
/* 4F7CBC 802180DC 26100004 */   addiu    $s0, $s0, 4
/* 4F7CC0 802180E0 8E050000 */  lw        $a1, ($s0)
/* 4F7CC4 802180E4 26100004 */  addiu     $s0, $s0, 4
/* 4F7CC8 802180E8 0220202D */  daddu     $a0, $s1, $zero
/* 4F7CCC 802180EC 0C0B1EAF */  jal       get_variable
/* 4F7CD0 802180F0 0040982D */   daddu    $s3, $v0, $zero
/* 4F7CD4 802180F4 8E050000 */  lw        $a1, ($s0)
/* 4F7CD8 802180F8 26100004 */  addiu     $s0, $s0, 4
/* 4F7CDC 802180FC 0220202D */  daddu     $a0, $s1, $zero
/* 4F7CE0 80218100 0C0B1EAF */  jal       get_variable
/* 4F7CE4 80218104 0040902D */   daddu    $s2, $v0, $zero
/* 4F7CE8 80218108 0220202D */  daddu     $a0, $s1, $zero
/* 4F7CEC 8021810C 8E050000 */  lw        $a1, ($s0)
/* 4F7CF0 80218110 0C0B1EAF */  jal       get_variable
/* 4F7CF4 80218114 0040802D */   daddu    $s0, $v0, $zero
/* 4F7CF8 80218118 44936000 */  mtc1      $s3, $f12
/* 4F7CFC 8021811C 00000000 */  nop       
/* 4F7D00 80218120 46806320 */  cvt.s.w   $f12, $f12
/* 4F7D04 80218124 44927000 */  mtc1      $s2, $f14
/* 4F7D08 80218128 00000000 */  nop       
/* 4F7D0C 8021812C 468073A0 */  cvt.s.w   $f14, $f14
/* 4F7D10 80218130 44900000 */  mtc1      $s0, $f0
/* 4F7D14 80218134 00000000 */  nop       
/* 4F7D18 80218138 46800020 */  cvt.s.w   $f0, $f0
/* 4F7D1C 8021813C 44060000 */  mfc1      $a2, $f0
/* 4F7D20 80218140 0C0B5D30 */  jal       func_802D74C0
/* 4F7D24 80218144 0040382D */   daddu    $a3, $v0, $zero
/* 4F7D28 80218148 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4F7D2C 8021814C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4F7D30 80218150 8FB20018 */  lw        $s2, 0x18($sp)
/* 4F7D34 80218154 8FB10014 */  lw        $s1, 0x14($sp)
/* 4F7D38 80218158 8FB00010 */  lw        $s0, 0x10($sp)
/* 4F7D3C 8021815C 24020002 */  addiu     $v0, $zero, 2
/* 4F7D40 80218160 03E00008 */  jr        $ra
/* 4F7D44 80218164 27BD0028 */   addiu    $sp, $sp, 0x28
/* 4F7D48 80218168 00000000 */  nop       
/* 4F7D4C 8021816C 00000000 */  nop       
