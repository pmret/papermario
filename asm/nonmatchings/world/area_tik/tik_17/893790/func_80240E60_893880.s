.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E60_893880
/* 893880 80240E60 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 893884 80240E64 AFB10014 */  sw        $s1, 0x14($sp)
/* 893888 80240E68 0080882D */  daddu     $s1, $a0, $zero
/* 89388C 80240E6C AFBF001C */  sw        $ra, 0x1c($sp)
/* 893890 80240E70 AFB20018 */  sw        $s2, 0x18($sp)
/* 893894 80240E74 0C016AFA */  jal       get_current_map_header
/* 893898 80240E78 AFB00010 */   sw       $s0, 0x10($sp)
/* 89389C 80240E7C 0220202D */  daddu     $a0, $s1, $zero
/* 8938A0 80240E80 3C05FE36 */  lui       $a1, 0xfe36
/* 8938A4 80240E84 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 8938A8 80240E88 0C0B1EAF */  jal       get_variable
/* 8938AC 80240E8C 0040902D */   daddu    $s2, $v0, $zero
/* 8938B0 80240E90 0220202D */  daddu     $a0, $s1, $zero
/* 8938B4 80240E94 3C05FE36 */  lui       $a1, 0xfe36
/* 8938B8 80240E98 8E430014 */  lw        $v1, 0x14($s2)
/* 8938BC 80240E9C 00028100 */  sll       $s0, $v0, 4
/* 8938C0 80240EA0 02031821 */  addu      $v1, $s0, $v1
/* 8938C4 80240EA4 C4600000 */  lwc1      $f0, ($v1)
/* 8938C8 80240EA8 4600008D */  trunc.w.s $f2, $f0
/* 8938CC 80240EAC 44061000 */  mfc1      $a2, $f2
/* 8938D0 80240EB0 0C0B2026 */  jal       set_variable
/* 8938D4 80240EB4 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 8938D8 80240EB8 0220202D */  daddu     $a0, $s1, $zero
/* 8938DC 80240EBC 8E420014 */  lw        $v0, 0x14($s2)
/* 8938E0 80240EC0 3C05FE36 */  lui       $a1, 0xfe36
/* 8938E4 80240EC4 02021021 */  addu      $v0, $s0, $v0
/* 8938E8 80240EC8 C4400004 */  lwc1      $f0, 4($v0)
/* 8938EC 80240ECC 4600008D */  trunc.w.s $f2, $f0
/* 8938F0 80240ED0 44061000 */  mfc1      $a2, $f2
/* 8938F4 80240ED4 0C0B2026 */  jal       set_variable
/* 8938F8 80240ED8 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 8938FC 80240EDC 0220202D */  daddu     $a0, $s1, $zero
/* 893900 80240EE0 8E420014 */  lw        $v0, 0x14($s2)
/* 893904 80240EE4 3C05FE36 */  lui       $a1, 0xfe36
/* 893908 80240EE8 02021021 */  addu      $v0, $s0, $v0
/* 89390C 80240EEC C4400008 */  lwc1      $f0, 8($v0)
/* 893910 80240EF0 4600008D */  trunc.w.s $f2, $f0
/* 893914 80240EF4 44061000 */  mfc1      $a2, $f2
/* 893918 80240EF8 0C0B2026 */  jal       set_variable
/* 89391C 80240EFC 34A53C83 */   ori      $a1, $a1, 0x3c83
/* 893920 80240F00 0220202D */  daddu     $a0, $s1, $zero
/* 893924 80240F04 8E420014 */  lw        $v0, 0x14($s2)
/* 893928 80240F08 3C05FE36 */  lui       $a1, 0xfe36
/* 89392C 80240F0C 02028021 */  addu      $s0, $s0, $v0
/* 893930 80240F10 C600000C */  lwc1      $f0, 0xc($s0)
/* 893934 80240F14 4600008D */  trunc.w.s $f2, $f0
/* 893938 80240F18 44061000 */  mfc1      $a2, $f2
/* 89393C 80240F1C 0C0B2026 */  jal       set_variable
/* 893940 80240F20 34A53C84 */   ori      $a1, $a1, 0x3c84
/* 893944 80240F24 8FBF001C */  lw        $ra, 0x1c($sp)
/* 893948 80240F28 8FB20018 */  lw        $s2, 0x18($sp)
/* 89394C 80240F2C 8FB10014 */  lw        $s1, 0x14($sp)
/* 893950 80240F30 8FB00010 */  lw        $s0, 0x10($sp)
/* 893954 80240F34 24020002 */  addiu     $v0, $zero, 2
/* 893958 80240F38 03E00008 */  jr        $ra
/* 89395C 80240F3C 27BD0020 */   addiu    $sp, $sp, 0x20
