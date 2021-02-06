.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E18_87A9F8
/* 87A9F8 80240E18 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 87A9FC 80240E1C AFB10014 */  sw        $s1, 0x14($sp)
/* 87AA00 80240E20 0080882D */  daddu     $s1, $a0, $zero
/* 87AA04 80240E24 AFB20018 */  sw        $s2, 0x18($sp)
/* 87AA08 80240E28 AFBF001C */  sw        $ra, 0x1c($sp)
/* 87AA0C 80240E2C AFB00010 */  sw        $s0, 0x10($sp)
/* 87AA10 80240E30 8E30000C */  lw        $s0, 0xc($s1)
/* 87AA14 80240E34 10A00010 */  beqz      $a1, .L80240E78
/* 87AA18 80240E38 0000902D */   daddu    $s2, $zero, $zero
/* 87AA1C 80240E3C 8E050000 */  lw        $a1, ($s0)
/* 87AA20 80240E40 0C0B1EAF */  jal       get_variable
/* 87AA24 80240E44 26100004 */   addiu    $s0, $s0, 4
/* 87AA28 80240E48 AE220084 */  sw        $v0, 0x84($s1)
/* 87AA2C 80240E4C 8E050000 */  lw        $a1, ($s0)
/* 87AA30 80240E50 0C0B1EAF */  jal       get_variable
/* 87AA34 80240E54 0220202D */   daddu    $a0, $s1, $zero
/* 87AA38 80240E58 0240202D */  daddu     $a0, $s2, $zero
/* 87AA3C 80240E5C 240500D0 */  addiu     $a1, $zero, 0xd0
/* 87AA40 80240E60 00A0302D */  daddu     $a2, $a1, $zero
/* 87AA44 80240E64 00A0382D */  daddu     $a3, $a1, $zero
/* 87AA48 80240E68 AE220088 */  sw        $v0, 0x88($s1)
/* 87AA4C 80240E6C AE200070 */  sw        $zero, 0x70($s1)
/* 87AA50 80240E70 0C04DF84 */  jal       set_transition_stencil_color
/* 87AA54 80240E74 AE200074 */   sw       $zero, 0x74($s1)
.L80240E78:
/* 87AA58 80240E78 8E230070 */  lw        $v1, 0x70($s1)
/* 87AA5C 80240E7C 24040001 */  addiu     $a0, $zero, 1
/* 87AA60 80240E80 10640019 */  beq       $v1, $a0, .L80240EE8
/* 87AA64 80240E84 28620002 */   slti     $v0, $v1, 2
/* 87AA68 80240E88 10400005 */  beqz      $v0, .L80240EA0
/* 87AA6C 80240E8C 24020002 */   addiu    $v0, $zero, 2
/* 87AA70 80240E90 10600007 */  beqz      $v1, .L80240EB0
/* 87AA74 80240E94 240500FF */   addiu    $a1, $zero, 0xff
/* 87AA78 80240E98 080903CA */  j         .L80240F28
/* 87AA7C 80240E9C 00000000 */   nop
.L80240EA0:
/* 87AA80 80240EA0 10620019 */  beq       $v1, $v0, .L80240F08
/* 87AA84 80240EA4 00000000 */   nop
/* 87AA88 80240EA8 080903CA */  j         .L80240F28
/* 87AA8C 80240EAC 00000000 */   nop
.L80240EB0:
/* 87AA90 80240EB0 8E220074 */  lw        $v0, 0x74($s1)
/* 87AA94 80240EB4 14450004 */  bne       $v0, $a1, .L80240EC8
/* 87AA98 80240EB8 00000000 */   nop
/* 87AA9C 80240EBC AE240070 */  sw        $a0, 0x70($s1)
/* 87AAA0 80240EC0 AE200078 */  sw        $zero, 0x78($s1)
/* 87AAA4 80240EC4 8E220074 */  lw        $v0, 0x74($s1)
.L80240EC8:
/* 87AAA8 80240EC8 8E230084 */  lw        $v1, 0x84($s1)
/* 87AAAC 80240ECC 00431021 */  addu      $v0, $v0, $v1
/* 87AAB0 80240ED0 AE220074 */  sw        $v0, 0x74($s1)
/* 87AAB4 80240ED4 28420100 */  slti      $v0, $v0, 0x100
/* 87AAB8 80240ED8 50400013 */  beql      $v0, $zero, .L80240F28
/* 87AABC 80240EDC AE250074 */   sw       $a1, 0x74($s1)
/* 87AAC0 80240EE0 080903CA */  j         .L80240F28
/* 87AAC4 80240EE4 00000000 */   nop
.L80240EE8:
/* 87AAC8 80240EE8 8E220078 */  lw        $v0, 0x78($s1)
/* 87AACC 80240EEC 24420001 */  addiu     $v0, $v0, 1
/* 87AAD0 80240EF0 AE220078 */  sw        $v0, 0x78($s1)
/* 87AAD4 80240EF4 28420002 */  slti      $v0, $v0, 2
/* 87AAD8 80240EF8 1440000B */  bnez      $v0, .L80240F28
/* 87AADC 80240EFC 24020002 */   addiu    $v0, $zero, 2
/* 87AAE0 80240F00 080903CA */  j         .L80240F28
/* 87AAE4 80240F04 AE220070 */   sw       $v0, 0x70($s1)
.L80240F08:
/* 87AAE8 80240F08 8E230074 */  lw        $v1, 0x74($s1)
/* 87AAEC 80240F0C 50600001 */  beql      $v1, $zero, .L80240F14
/* 87AAF0 80240F10 24120001 */   addiu    $s2, $zero, 1
.L80240F14:
/* 87AAF4 80240F14 8E220088 */  lw        $v0, 0x88($s1)
/* 87AAF8 80240F18 00621023 */  subu      $v0, $v1, $v0
/* 87AAFC 80240F1C 04410002 */  bgez      $v0, .L80240F28
/* 87AB00 80240F20 AE220074 */   sw       $v0, 0x74($s1)
/* 87AB04 80240F24 AE200074 */  sw        $zero, 0x74($s1)
.L80240F28:
/* 87AB08 80240F28 C6200074 */  lwc1      $f0, 0x74($s1)
/* 87AB0C 80240F2C 46800020 */  cvt.s.w   $f0, $f0
/* 87AB10 80240F30 44050000 */  mfc1      $a1, $f0
/* 87AB14 80240F34 0C04DF62 */  jal       set_transition_stencil_zoom_0
/* 87AB18 80240F38 24040001 */   addiu    $a0, $zero, 1
/* 87AB1C 80240F3C 0240102D */  daddu     $v0, $s2, $zero
/* 87AB20 80240F40 8FBF001C */  lw        $ra, 0x1c($sp)
/* 87AB24 80240F44 8FB20018 */  lw        $s2, 0x18($sp)
/* 87AB28 80240F48 8FB10014 */  lw        $s1, 0x14($sp)
/* 87AB2C 80240F4C 8FB00010 */  lw        $s0, 0x10($sp)
/* 87AB30 80240F50 03E00008 */  jr        $ra
/* 87AB34 80240F54 27BD0020 */   addiu    $sp, $sp, 0x20
