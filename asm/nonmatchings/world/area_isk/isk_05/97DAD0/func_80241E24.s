.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E24
/* 97F8F4 80241E24 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 97F8F8 80241E28 AFB00018 */  sw        $s0, 0x18($sp)
/* 97F8FC 80241E2C 0080802D */  daddu     $s0, $a0, $zero
/* 97F900 80241E30 3C05FE36 */  lui       $a1, 0xfe36
/* 97F904 80241E34 AFBF001C */  sw        $ra, 0x1c($sp)
/* 97F908 80241E38 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 97F90C 80241E3C F7B40020 */  sdc1      $f20, 0x20($sp)
/* 97F910 80241E40 0C0B1EAF */  jal       get_variable
/* 97F914 80241E44 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 97F918 80241E48 0200202D */  daddu     $a0, $s0, $zero
/* 97F91C 80241E4C 3C05FE36 */  lui       $a1, 0xfe36
/* 97F920 80241E50 4482B000 */  mtc1      $v0, $f22
/* 97F924 80241E54 00000000 */  nop       
/* 97F928 80241E58 4680B5A0 */  cvt.s.w   $f22, $f22
/* 97F92C 80241E5C 0C0B1EAF */  jal       get_variable
/* 97F930 80241E60 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 97F934 80241E64 0200202D */  daddu     $a0, $s0, $zero
/* 97F938 80241E68 3C05FE36 */  lui       $a1, 0xfe36
/* 97F93C 80241E6C 4482A000 */  mtc1      $v0, $f20
/* 97F940 80241E70 00000000 */  nop       
/* 97F944 80241E74 4680A520 */  cvt.s.w   $f20, $f20
/* 97F948 80241E78 0C0B1EAF */  jal       get_variable
/* 97F94C 80241E7C 34A53C84 */   ori      $a1, $a1, 0x3c84
/* 97F950 80241E80 44820000 */  mtc1      $v0, $f0
/* 97F954 80241E84 00000000 */  nop       
/* 97F958 80241E88 46800020 */  cvt.s.w   $f0, $f0
/* 97F95C 80241E8C 4405B000 */  mfc1      $a1, $f22
/* 97F960 80241E90 4406A000 */  mfc1      $a2, $f20
/* 97F964 80241E94 44070000 */  mfc1      $a3, $f0
/* 97F968 80241E98 0000202D */  daddu     $a0, $zero, $zero
/* 97F96C 80241E9C 0C01BEB4 */  jal       fx_walk_large
/* 97F970 80241EA0 AFA00010 */   sw       $zero, 0x10($sp)
/* 97F974 80241EA4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 97F978 80241EA8 8FB00018 */  lw        $s0, 0x18($sp)
/* 97F97C 80241EAC D7B60028 */  ldc1      $f22, 0x28($sp)
/* 97F980 80241EB0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 97F984 80241EB4 24020002 */  addiu     $v0, $zero, 2
/* 97F988 80241EB8 03E00008 */  jr        $ra
/* 97F98C 80241EBC 27BD0030 */   addiu    $sp, $sp, 0x30
