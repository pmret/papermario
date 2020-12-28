.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218A24_557E04
/* 557E04 80218A24 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 557E08 80218A28 AFB10014 */  sw        $s1, 0x14($sp)
/* 557E0C 80218A2C 0080882D */  daddu     $s1, $a0, $zero
/* 557E10 80218A30 AFBF0020 */  sw        $ra, 0x20($sp)
/* 557E14 80218A34 AFB3001C */  sw        $s3, 0x1c($sp)
/* 557E18 80218A38 AFB20018 */  sw        $s2, 0x18($sp)
/* 557E1C 80218A3C AFB00010 */  sw        $s0, 0x10($sp)
/* 557E20 80218A40 8E30000C */  lw        $s0, 0xc($s1)
/* 557E24 80218A44 8E050000 */  lw        $a1, ($s0)
/* 557E28 80218A48 0C0B1EAF */  jal       get_variable
/* 557E2C 80218A4C 26100004 */   addiu    $s0, $s0, 4
/* 557E30 80218A50 8E050000 */  lw        $a1, ($s0)
/* 557E34 80218A54 26100004 */  addiu     $s0, $s0, 4
/* 557E38 80218A58 0220202D */  daddu     $a0, $s1, $zero
/* 557E3C 80218A5C 0C0B1EAF */  jal       get_variable
/* 557E40 80218A60 0040982D */   daddu    $s3, $v0, $zero
/* 557E44 80218A64 8E050000 */  lw        $a1, ($s0)
/* 557E48 80218A68 26100004 */  addiu     $s0, $s0, 4
/* 557E4C 80218A6C 0220202D */  daddu     $a0, $s1, $zero
/* 557E50 80218A70 0C0B1EAF */  jal       get_variable
/* 557E54 80218A74 0040902D */   daddu    $s2, $v0, $zero
/* 557E58 80218A78 0220202D */  daddu     $a0, $s1, $zero
/* 557E5C 80218A7C 8E050000 */  lw        $a1, ($s0)
/* 557E60 80218A80 0C0B1EAF */  jal       get_variable
/* 557E64 80218A84 0040802D */   daddu    $s0, $v0, $zero
/* 557E68 80218A88 44936000 */  mtc1      $s3, $f12
/* 557E6C 80218A8C 00000000 */  nop       
/* 557E70 80218A90 46806320 */  cvt.s.w   $f12, $f12
/* 557E74 80218A94 44927000 */  mtc1      $s2, $f14
/* 557E78 80218A98 00000000 */  nop       
/* 557E7C 80218A9C 468073A0 */  cvt.s.w   $f14, $f14
/* 557E80 80218AA0 44900000 */  mtc1      $s0, $f0
/* 557E84 80218AA4 00000000 */  nop       
/* 557E88 80218AA8 46800020 */  cvt.s.w   $f0, $f0
/* 557E8C 80218AAC 44060000 */  mfc1      $a2, $f0
/* 557E90 80218AB0 0C0B5D30 */  jal       func_802D74C0
/* 557E94 80218AB4 0040382D */   daddu    $a3, $v0, $zero
/* 557E98 80218AB8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 557E9C 80218ABC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 557EA0 80218AC0 8FB20018 */  lw        $s2, 0x18($sp)
/* 557EA4 80218AC4 8FB10014 */  lw        $s1, 0x14($sp)
/* 557EA8 80218AC8 8FB00010 */  lw        $s0, 0x10($sp)
/* 557EAC 80218ACC 24020002 */  addiu     $v0, $zero, 2
/* 557EB0 80218AD0 03E00008 */  jr        $ra
/* 557EB4 80218AD4 27BD0028 */   addiu    $sp, $sp, 0x28
/* 557EB8 80218AD8 00000000 */  nop       
/* 557EBC 80218ADC 00000000 */  nop       
