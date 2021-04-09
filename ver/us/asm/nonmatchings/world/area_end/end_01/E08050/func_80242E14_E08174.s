.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel end_01_UnkFunc26
/* E08174 80242E14 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* E08178 80242E18 AFB10034 */  sw        $s1, 0x34($sp)
/* E0817C 80242E1C 0080882D */  daddu     $s1, $a0, $zero
/* E08180 80242E20 AFBF0054 */  sw        $ra, 0x54($sp)
/* E08184 80242E24 AFBE0050 */  sw        $fp, 0x50($sp)
/* E08188 80242E28 AFB7004C */  sw        $s7, 0x4c($sp)
/* E0818C 80242E2C AFB60048 */  sw        $s6, 0x48($sp)
/* E08190 80242E30 AFB50044 */  sw        $s5, 0x44($sp)
/* E08194 80242E34 AFB40040 */  sw        $s4, 0x40($sp)
/* E08198 80242E38 AFB3003C */  sw        $s3, 0x3c($sp)
/* E0819C 80242E3C AFB20038 */  sw        $s2, 0x38($sp)
/* E081A0 80242E40 AFB00030 */  sw        $s0, 0x30($sp)
/* E081A4 80242E44 8E30000C */  lw        $s0, 0xc($s1)
/* E081A8 80242E48 8E050000 */  lw        $a1, ($s0)
/* E081AC 80242E4C 0C0B1EAF */  jal       get_variable
/* E081B0 80242E50 26100004 */   addiu    $s0, $s0, 4
/* E081B4 80242E54 8E050000 */  lw        $a1, ($s0)
/* E081B8 80242E58 26100004 */  addiu     $s0, $s0, 4
/* E081BC 80242E5C 0220202D */  daddu     $a0, $s1, $zero
/* E081C0 80242E60 0C0B1EAF */  jal       get_variable
/* E081C4 80242E64 0040982D */   daddu    $s3, $v0, $zero
/* E081C8 80242E68 8E050000 */  lw        $a1, ($s0)
/* E081CC 80242E6C 26100004 */  addiu     $s0, $s0, 4
/* E081D0 80242E70 0220202D */  daddu     $a0, $s1, $zero
/* E081D4 80242E74 0C0B1EAF */  jal       get_variable
/* E081D8 80242E78 0040B02D */   daddu    $s6, $v0, $zero
/* E081DC 80242E7C 8E050000 */  lw        $a1, ($s0)
/* E081E0 80242E80 26100004 */  addiu     $s0, $s0, 4
/* E081E4 80242E84 0220202D */  daddu     $a0, $s1, $zero
/* E081E8 80242E88 0C0B1EAF */  jal       get_variable
/* E081EC 80242E8C 0040A82D */   daddu    $s5, $v0, $zero
/* E081F0 80242E90 8E050000 */  lw        $a1, ($s0)
/* E081F4 80242E94 26100004 */  addiu     $s0, $s0, 4
/* E081F8 80242E98 0220202D */  daddu     $a0, $s1, $zero
/* E081FC 80242E9C 0C0B1EAF */  jal       get_variable
/* E08200 80242EA0 0040A02D */   daddu    $s4, $v0, $zero
/* E08204 80242EA4 8E050000 */  lw        $a1, ($s0)
/* E08208 80242EA8 26100004 */  addiu     $s0, $s0, 4
/* E0820C 80242EAC 0220202D */  daddu     $a0, $s1, $zero
/* E08210 80242EB0 0C0B1EAF */  jal       get_variable
/* E08214 80242EB4 0040902D */   daddu    $s2, $v0, $zero
/* E08218 80242EB8 8E050000 */  lw        $a1, ($s0)
/* E0821C 80242EBC 26100004 */  addiu     $s0, $s0, 4
/* E08220 80242EC0 0220202D */  daddu     $a0, $s1, $zero
/* E08224 80242EC4 0C0B1EAF */  jal       get_variable
/* E08228 80242EC8 AFA20028 */   sw       $v0, 0x28($sp)
/* E0822C 80242ECC 8E050000 */  lw        $a1, ($s0)
/* E08230 80242ED0 26100004 */  addiu     $s0, $s0, 4
/* E08234 80242ED4 0220202D */  daddu     $a0, $s1, $zero
/* E08238 80242ED8 0C0B1EAF */  jal       get_variable
/* E0823C 80242EDC 0040F02D */   daddu    $fp, $v0, $zero
/* E08240 80242EE0 8E050000 */  lw        $a1, ($s0)
/* E08244 80242EE4 26100004 */  addiu     $s0, $s0, 4
/* E08248 80242EE8 0220202D */  daddu     $a0, $s1, $zero
/* E0824C 80242EEC 0C0B1EAF */  jal       get_variable
/* E08250 80242EF0 0040B82D */   daddu    $s7, $v0, $zero
/* E08254 80242EF4 0220202D */  daddu     $a0, $s1, $zero
/* E08258 80242EF8 8E050000 */  lw        $a1, ($s0)
/* E0825C 80242EFC 0C0B1EAF */  jal       get_variable
/* E08260 80242F00 0040802D */   daddu    $s0, $v0, $zero
/* E08264 80242F04 0040182D */  daddu     $v1, $v0, $zero
/* E08268 80242F08 24020002 */  addiu     $v0, $zero, 2
/* E0826C 80242F0C 12620012 */  beq       $s3, $v0, .L80242F58
/* E08270 80242F10 2A620003 */   slti     $v0, $s3, 3
/* E08274 80242F14 10400005 */  beqz      $v0, .L80242F2C
/* E08278 80242F18 24020001 */   addiu    $v0, $zero, 1
/* E0827C 80242F1C 12620008 */  beq       $s3, $v0, .L80242F40
/* E08280 80242F20 32C400FF */   andi     $a0, $s6, 0xff
/* E08284 80242F24 08090BED */  j         .L80242FB4
/* E08288 80242F28 00000000 */   nop
.L80242F2C:
/* E0828C 80242F2C 24020003 */  addiu     $v0, $zero, 3
/* E08290 80242F30 12620018 */  beq       $s3, $v0, .L80242F94
/* E08294 80242F34 32C400FF */   andi     $a0, $s6, 0xff
/* E08298 80242F38 08090BED */  j         .L80242FB4
/* E0829C 80242F3C 00000000 */   nop
.L80242F40:
/* E082A0 80242F40 32A500FF */  andi      $a1, $s5, 0xff
/* E082A4 80242F44 328600FF */  andi      $a2, $s4, 0xff
/* E082A8 80242F48 0C046F97 */  jal       set_background_color_blend
/* E082AC 80242F4C 324700FF */   andi     $a3, $s2, 0xff
/* E082B0 80242F50 08090BED */  j         .L80242FB4
/* E082B4 80242F54 00000000 */   nop
.L80242F58:
/* E082B8 80242F58 32C400FF */  andi      $a0, $s6, 0xff
/* E082BC 80242F5C 32A500FF */  andi      $a1, $s5, 0xff
/* E082C0 80242F60 328600FF */  andi      $a2, $s4, 0xff
/* E082C4 80242F64 324700FF */  andi      $a3, $s2, 0xff
/* E082C8 80242F68 93A2002B */  lbu       $v0, 0x2b($sp)
/* E082CC 80242F6C AFB0001C */  sw        $s0, 0x1c($sp)
/* E082D0 80242F70 AFA30020 */  sw        $v1, 0x20($sp)
/* E082D4 80242F74 AFA20010 */  sw        $v0, 0x10($sp)
/* E082D8 80242F78 33C200FF */  andi      $v0, $fp, 0xff
/* E082DC 80242F7C AFA20014 */  sw        $v0, 0x14($sp)
/* E082E0 80242F80 32E200FF */  andi      $v0, $s7, 0xff
/* E082E4 80242F84 0C046FAD */  jal       func_8011BEB4
/* E082E8 80242F88 AFA20018 */   sw       $v0, 0x18($sp)
/* E082EC 80242F8C 08090BED */  j         .L80242FB4
/* E082F0 80242F90 00000000 */   nop
.L80242F94:
/* E082F4 80242F94 32A500FF */  andi      $a1, $s5, 0xff
/* E082F8 80242F98 328600FF */  andi      $a2, $s4, 0xff
/* E082FC 80242F9C 324700FF */  andi      $a3, $s2, 0xff
/* E08300 80242FA0 93A2002B */  lbu       $v0, 0x2b($sp)
/* E08304 80242FA4 AFA20010 */  sw        $v0, 0x10($sp)
/* E08308 80242FA8 33C200FF */  andi      $v0, $fp, 0xff
/* E0830C 80242FAC 0C046FE6 */  jal       func_8011BF98
/* E08310 80242FB0 AFA20014 */   sw       $v0, 0x14($sp)
.L80242FB4:
/* E08314 80242FB4 8FBF0054 */  lw        $ra, 0x54($sp)
/* E08318 80242FB8 8FBE0050 */  lw        $fp, 0x50($sp)
/* E0831C 80242FBC 8FB7004C */  lw        $s7, 0x4c($sp)
/* E08320 80242FC0 8FB60048 */  lw        $s6, 0x48($sp)
/* E08324 80242FC4 8FB50044 */  lw        $s5, 0x44($sp)
/* E08328 80242FC8 8FB40040 */  lw        $s4, 0x40($sp)
/* E0832C 80242FCC 8FB3003C */  lw        $s3, 0x3c($sp)
/* E08330 80242FD0 8FB20038 */  lw        $s2, 0x38($sp)
/* E08334 80242FD4 8FB10034 */  lw        $s1, 0x34($sp)
/* E08338 80242FD8 8FB00030 */  lw        $s0, 0x30($sp)
/* E0833C 80242FDC 24020002 */  addiu     $v0, $zero, 2
/* E08340 80242FE0 03E00008 */  jr        $ra
/* E08344 80242FE4 27BD0058 */   addiu    $sp, $sp, 0x58
/* E08348 80242FE8 00000000 */  nop
/* E0834C 80242FEC 00000000 */  nop
