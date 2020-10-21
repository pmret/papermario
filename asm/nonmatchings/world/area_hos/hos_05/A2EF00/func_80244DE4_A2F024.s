.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244DE4_A2F024
/* A2F024 80244DE4 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* A2F028 80244DE8 AFB10034 */  sw        $s1, 0x34($sp)
/* A2F02C 80244DEC 0080882D */  daddu     $s1, $a0, $zero
/* A2F030 80244DF0 AFBF0054 */  sw        $ra, 0x54($sp)
/* A2F034 80244DF4 AFBE0050 */  sw        $fp, 0x50($sp)
/* A2F038 80244DF8 AFB7004C */  sw        $s7, 0x4c($sp)
/* A2F03C 80244DFC AFB60048 */  sw        $s6, 0x48($sp)
/* A2F040 80244E00 AFB50044 */  sw        $s5, 0x44($sp)
/* A2F044 80244E04 AFB40040 */  sw        $s4, 0x40($sp)
/* A2F048 80244E08 AFB3003C */  sw        $s3, 0x3c($sp)
/* A2F04C 80244E0C AFB20038 */  sw        $s2, 0x38($sp)
/* A2F050 80244E10 AFB00030 */  sw        $s0, 0x30($sp)
/* A2F054 80244E14 8E30000C */  lw        $s0, 0xc($s1)
/* A2F058 80244E18 8E050000 */  lw        $a1, ($s0)
/* A2F05C 80244E1C 0C0B1EAF */  jal       get_variable
/* A2F060 80244E20 26100004 */   addiu    $s0, $s0, 4
/* A2F064 80244E24 8E050000 */  lw        $a1, ($s0)
/* A2F068 80244E28 26100004 */  addiu     $s0, $s0, 4
/* A2F06C 80244E2C 0220202D */  daddu     $a0, $s1, $zero
/* A2F070 80244E30 0C0B1EAF */  jal       get_variable
/* A2F074 80244E34 0040982D */   daddu    $s3, $v0, $zero
/* A2F078 80244E38 8E050000 */  lw        $a1, ($s0)
/* A2F07C 80244E3C 26100004 */  addiu     $s0, $s0, 4
/* A2F080 80244E40 0220202D */  daddu     $a0, $s1, $zero
/* A2F084 80244E44 0C0B1EAF */  jal       get_variable
/* A2F088 80244E48 0040B02D */   daddu    $s6, $v0, $zero
/* A2F08C 80244E4C 8E050000 */  lw        $a1, ($s0)
/* A2F090 80244E50 26100004 */  addiu     $s0, $s0, 4
/* A2F094 80244E54 0220202D */  daddu     $a0, $s1, $zero
/* A2F098 80244E58 0C0B1EAF */  jal       get_variable
/* A2F09C 80244E5C 0040A82D */   daddu    $s5, $v0, $zero
/* A2F0A0 80244E60 8E050000 */  lw        $a1, ($s0)
/* A2F0A4 80244E64 26100004 */  addiu     $s0, $s0, 4
/* A2F0A8 80244E68 0220202D */  daddu     $a0, $s1, $zero
/* A2F0AC 80244E6C 0C0B1EAF */  jal       get_variable
/* A2F0B0 80244E70 0040A02D */   daddu    $s4, $v0, $zero
/* A2F0B4 80244E74 8E050000 */  lw        $a1, ($s0)
/* A2F0B8 80244E78 26100004 */  addiu     $s0, $s0, 4
/* A2F0BC 80244E7C 0220202D */  daddu     $a0, $s1, $zero
/* A2F0C0 80244E80 0C0B1EAF */  jal       get_variable
/* A2F0C4 80244E84 0040902D */   daddu    $s2, $v0, $zero
/* A2F0C8 80244E88 8E050000 */  lw        $a1, ($s0)
/* A2F0CC 80244E8C 26100004 */  addiu     $s0, $s0, 4
/* A2F0D0 80244E90 0220202D */  daddu     $a0, $s1, $zero
/* A2F0D4 80244E94 0C0B1EAF */  jal       get_variable
/* A2F0D8 80244E98 AFA20028 */   sw       $v0, 0x28($sp)
/* A2F0DC 80244E9C 8E050000 */  lw        $a1, ($s0)
/* A2F0E0 80244EA0 26100004 */  addiu     $s0, $s0, 4
/* A2F0E4 80244EA4 0220202D */  daddu     $a0, $s1, $zero
/* A2F0E8 80244EA8 0C0B1EAF */  jal       get_variable
/* A2F0EC 80244EAC 0040F02D */   daddu    $fp, $v0, $zero
/* A2F0F0 80244EB0 8E050000 */  lw        $a1, ($s0)
/* A2F0F4 80244EB4 26100004 */  addiu     $s0, $s0, 4
/* A2F0F8 80244EB8 0220202D */  daddu     $a0, $s1, $zero
/* A2F0FC 80244EBC 0C0B1EAF */  jal       get_variable
/* A2F100 80244EC0 0040B82D */   daddu    $s7, $v0, $zero
/* A2F104 80244EC4 0220202D */  daddu     $a0, $s1, $zero
/* A2F108 80244EC8 8E050000 */  lw        $a1, ($s0)
/* A2F10C 80244ECC 0C0B1EAF */  jal       get_variable
/* A2F110 80244ED0 0040802D */   daddu    $s0, $v0, $zero
/* A2F114 80244ED4 0040182D */  daddu     $v1, $v0, $zero
/* A2F118 80244ED8 24020002 */  addiu     $v0, $zero, 2
/* A2F11C 80244EDC 12620012 */  beq       $s3, $v0, .L80244F28
/* A2F120 80244EE0 2A620003 */   slti     $v0, $s3, 3
/* A2F124 80244EE4 10400005 */  beqz      $v0, .L80244EFC
/* A2F128 80244EE8 24020001 */   addiu    $v0, $zero, 1
/* A2F12C 80244EEC 12620008 */  beq       $s3, $v0, .L80244F10
/* A2F130 80244EF0 32C400FF */   andi     $a0, $s6, 0xff
/* A2F134 80244EF4 080913E1 */  j         .L80244F84
/* A2F138 80244EF8 00000000 */   nop      
.L80244EFC:
/* A2F13C 80244EFC 24020003 */  addiu     $v0, $zero, 3
/* A2F140 80244F00 12620018 */  beq       $s3, $v0, .L80244F64
/* A2F144 80244F04 32C400FF */   andi     $a0, $s6, 0xff
/* A2F148 80244F08 080913E1 */  j         .L80244F84
/* A2F14C 80244F0C 00000000 */   nop      
.L80244F10:
/* A2F150 80244F10 32A500FF */  andi      $a1, $s5, 0xff
/* A2F154 80244F14 328600FF */  andi      $a2, $s4, 0xff
/* A2F158 80244F18 0C046F97 */  jal       set_background_color_blend
/* A2F15C 80244F1C 324700FF */   andi     $a3, $s2, 0xff
/* A2F160 80244F20 080913E1 */  j         .L80244F84
/* A2F164 80244F24 00000000 */   nop      
.L80244F28:
/* A2F168 80244F28 32C400FF */  andi      $a0, $s6, 0xff
/* A2F16C 80244F2C 32A500FF */  andi      $a1, $s5, 0xff
/* A2F170 80244F30 328600FF */  andi      $a2, $s4, 0xff
/* A2F174 80244F34 324700FF */  andi      $a3, $s2, 0xff
/* A2F178 80244F38 93A2002B */  lbu       $v0, 0x2b($sp)
/* A2F17C 80244F3C AFB0001C */  sw        $s0, 0x1c($sp)
/* A2F180 80244F40 AFA30020 */  sw        $v1, 0x20($sp)
/* A2F184 80244F44 AFA20010 */  sw        $v0, 0x10($sp)
/* A2F188 80244F48 33C200FF */  andi      $v0, $fp, 0xff
/* A2F18C 80244F4C AFA20014 */  sw        $v0, 0x14($sp)
/* A2F190 80244F50 32E200FF */  andi      $v0, $s7, 0xff
/* A2F194 80244F54 0C046FAD */  jal       func_8011BEB4
/* A2F198 80244F58 AFA20018 */   sw       $v0, 0x18($sp)
/* A2F19C 80244F5C 080913E1 */  j         .L80244F84
/* A2F1A0 80244F60 00000000 */   nop      
.L80244F64:
/* A2F1A4 80244F64 32A500FF */  andi      $a1, $s5, 0xff
/* A2F1A8 80244F68 328600FF */  andi      $a2, $s4, 0xff
/* A2F1AC 80244F6C 324700FF */  andi      $a3, $s2, 0xff
/* A2F1B0 80244F70 93A2002B */  lbu       $v0, 0x2b($sp)
/* A2F1B4 80244F74 AFA20010 */  sw        $v0, 0x10($sp)
/* A2F1B8 80244F78 33C200FF */  andi      $v0, $fp, 0xff
/* A2F1BC 80244F7C 0C046FE6 */  jal       func_8011BF98
/* A2F1C0 80244F80 AFA20014 */   sw       $v0, 0x14($sp)
.L80244F84:
/* A2F1C4 80244F84 8FBF0054 */  lw        $ra, 0x54($sp)
/* A2F1C8 80244F88 8FBE0050 */  lw        $fp, 0x50($sp)
/* A2F1CC 80244F8C 8FB7004C */  lw        $s7, 0x4c($sp)
/* A2F1D0 80244F90 8FB60048 */  lw        $s6, 0x48($sp)
/* A2F1D4 80244F94 8FB50044 */  lw        $s5, 0x44($sp)
/* A2F1D8 80244F98 8FB40040 */  lw        $s4, 0x40($sp)
/* A2F1DC 80244F9C 8FB3003C */  lw        $s3, 0x3c($sp)
/* A2F1E0 80244FA0 8FB20038 */  lw        $s2, 0x38($sp)
/* A2F1E4 80244FA4 8FB10034 */  lw        $s1, 0x34($sp)
/* A2F1E8 80244FA8 8FB00030 */  lw        $s0, 0x30($sp)
/* A2F1EC 80244FAC 24020002 */  addiu     $v0, $zero, 2
/* A2F1F0 80244FB0 03E00008 */  jr        $ra
/* A2F1F4 80244FB4 27BD0058 */   addiu    $sp, $sp, 0x58
