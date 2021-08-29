.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E80_7ECB90
/* 7ECB90 80241E80 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 7ECB94 80241E84 AFB40020 */  sw        $s4, 0x20($sp)
/* 7ECB98 80241E88 0080A02D */  daddu     $s4, $a0, $zero
/* 7ECB9C 80241E8C AFB3001C */  sw        $s3, 0x1c($sp)
/* 7ECBA0 80241E90 3C138025 */  lui       $s3, %hi(D_80248F18_7F3C28)
/* 7ECBA4 80241E94 26738F18 */  addiu     $s3, $s3, %lo(D_80248F18_7F3C28)
/* 7ECBA8 80241E98 AFB50024 */  sw        $s5, 0x24($sp)
/* 7ECBAC 80241E9C 0000A82D */  daddu     $s5, $zero, $zero
/* 7ECBB0 80241EA0 AFB20018 */  sw        $s2, 0x18($sp)
/* 7ECBB4 80241EA4 02A0902D */  daddu     $s2, $s5, $zero
/* 7ECBB8 80241EA8 AFB10014 */  sw        $s1, 0x14($sp)
/* 7ECBBC 80241EAC 02A0882D */  daddu     $s1, $s5, $zero
/* 7ECBC0 80241EB0 AFB00010 */  sw        $s0, 0x10($sp)
/* 7ECBC4 80241EB4 26700010 */  addiu     $s0, $s3, 0x10
/* 7ECBC8 80241EB8 AFBF002C */  sw        $ra, 0x2c($sp)
/* 7ECBCC 80241EBC AFB60028 */  sw        $s6, 0x28($sp)
.L80241EC0:
/* 7ECBD0 80241EC0 8E05FFF8 */  lw        $a1, -8($s0)
/* 7ECBD4 80241EC4 0C0B1EAF */  jal       get_variable
/* 7ECBD8 80241EC8 0280202D */   daddu    $a0, $s4, $zero
/* 7ECBDC 80241ECC 5040000E */  beql      $v0, $zero, .L80241F08
/* 7ECBE0 80241ED0 26310001 */   addiu    $s1, $s1, 1
/* 7ECBE4 80241ED4 8E05FFFC */  lw        $a1, -4($s0)
/* 7ECBE8 80241ED8 0C0B1EAF */  jal       get_variable
/* 7ECBEC 80241EDC 0280202D */   daddu    $a0, $s4, $zero
/* 7ECBF0 80241EE0 14400003 */  bnez      $v0, .L80241EF0
/* 7ECBF4 80241EE4 00000000 */   nop
/* 7ECBF8 80241EE8 080907C6 */  j         .L80241F18
/* 7ECBFC 80241EEC 24150001 */   addiu    $s5, $zero, 1
.L80241EF0:
/* 7ECC00 80241EF0 8E050000 */  lw        $a1, ($s0)
/* 7ECC04 80241EF4 0C0B1EAF */  jal       get_variable
/* 7ECC08 80241EF8 0280202D */   daddu    $a0, $s4, $zero
/* 7ECC0C 80241EFC 50400001 */  beql      $v0, $zero, .L80241F04
/* 7ECC10 80241F00 26520001 */   addiu    $s2, $s2, 1
.L80241F04:
/* 7ECC14 80241F04 26310001 */  addiu     $s1, $s1, 1
.L80241F08:
/* 7ECC18 80241F08 26100014 */  addiu     $s0, $s0, 0x14
/* 7ECC1C 80241F0C 2E220024 */  sltiu     $v0, $s1, 0x24
/* 7ECC20 80241F10 1440FFEB */  bnez      $v0, .L80241EC0
/* 7ECC24 80241F14 26730014 */   addiu    $s3, $s3, 0x14
.L80241F18:
/* 7ECC28 80241F18 56A0001F */  bnel      $s5, $zero, .L80241F98
/* 7ECC2C 80241F1C AE910084 */   sw       $s1, 0x84($s4)
/* 7ECC30 80241F20 3C138025 */  lui       $s3, %hi(D_80248F18_7F3C28)
/* 7ECC34 80241F24 26738F18 */  addiu     $s3, $s3, %lo(D_80248F18_7F3C28)
/* 7ECC38 80241F28 1240001A */  beqz      $s2, .L80241F94
/* 7ECC3C 80241F2C 0000882D */   daddu    $s1, $zero, $zero
/* 7ECC40 80241F30 0C00A67F */  jal       rand_int
/* 7ECC44 80241F34 2644FFFF */   addiu    $a0, $s2, -1
/* 7ECC48 80241F38 0040B02D */  daddu     $s6, $v0, $zero
/* 7ECC4C 80241F3C 0220902D */  daddu     $s2, $s1, $zero
/* 7ECC50 80241F40 02A0882D */  daddu     $s1, $s5, $zero
/* 7ECC54 80241F44 26700010 */  addiu     $s0, $s3, 0x10
.L80241F48:
/* 7ECC58 80241F48 8E05FFF8 */  lw        $a1, -8($s0)
/* 7ECC5C 80241F4C 0C0B1EAF */  jal       get_variable
/* 7ECC60 80241F50 0280202D */   daddu    $a0, $s4, $zero
/* 7ECC64 80241F54 5040000B */  beql      $v0, $zero, .L80241F84
/* 7ECC68 80241F58 26310001 */   addiu    $s1, $s1, 1
/* 7ECC6C 80241F5C 8E050000 */  lw        $a1, ($s0)
/* 7ECC70 80241F60 0C0B1EAF */  jal       get_variable
/* 7ECC74 80241F64 0280202D */   daddu    $a0, $s4, $zero
/* 7ECC78 80241F68 54400006 */  bnel      $v0, $zero, .L80241F84
/* 7ECC7C 80241F6C 26310001 */   addiu    $s1, $s1, 1
/* 7ECC80 80241F70 0240102D */  daddu     $v0, $s2, $zero
/* 7ECC84 80241F74 0056102A */  slt       $v0, $v0, $s6
/* 7ECC88 80241F78 10400006 */  beqz      $v0, .L80241F94
/* 7ECC8C 80241F7C 26520001 */   addiu    $s2, $s2, 1
/* 7ECC90 80241F80 26310001 */  addiu     $s1, $s1, 1
.L80241F84:
/* 7ECC94 80241F84 26100014 */  addiu     $s0, $s0, 0x14
/* 7ECC98 80241F88 2E220024 */  sltiu     $v0, $s1, 0x24
/* 7ECC9C 80241F8C 1440FFEE */  bnez      $v0, .L80241F48
/* 7ECCA0 80241F90 26730014 */   addiu    $s3, $s3, 0x14
.L80241F94:
/* 7ECCA4 80241F94 AE910084 */  sw        $s1, 0x84($s4)
.L80241F98:
/* 7ECCA8 80241F98 8E620000 */  lw        $v0, ($s3)
/* 7ECCAC 80241F9C 0280202D */  daddu     $a0, $s4, $zero
/* 7ECCB0 80241FA0 AE95008C */  sw        $s5, 0x8c($s4)
/* 7ECCB4 80241FA4 AE820088 */  sw        $v0, 0x88($s4)
/* 7ECCB8 80241FA8 8E65000C */  lw        $a1, 0xc($s3)
/* 7ECCBC 80241FAC 0C0B2026 */  jal       evt_set_variable
/* 7ECCC0 80241FB0 24060001 */   addiu    $a2, $zero, 1
/* 7ECCC4 80241FB4 0280202D */  daddu     $a0, $s4, $zero
/* 7ECCC8 80241FB8 8E650010 */  lw        $a1, 0x10($s3)
/* 7ECCCC 80241FBC 0C0B2026 */  jal       evt_set_variable
/* 7ECCD0 80241FC0 24060001 */   addiu    $a2, $zero, 1
/* 7ECCD4 80241FC4 8FBF002C */  lw        $ra, 0x2c($sp)
/* 7ECCD8 80241FC8 8FB60028 */  lw        $s6, 0x28($sp)
/* 7ECCDC 80241FCC 8FB50024 */  lw        $s5, 0x24($sp)
/* 7ECCE0 80241FD0 8FB40020 */  lw        $s4, 0x20($sp)
/* 7ECCE4 80241FD4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 7ECCE8 80241FD8 8FB20018 */  lw        $s2, 0x18($sp)
/* 7ECCEC 80241FDC 8FB10014 */  lw        $s1, 0x14($sp)
/* 7ECCF0 80241FE0 8FB00010 */  lw        $s0, 0x10($sp)
/* 7ECCF4 80241FE4 24020002 */  addiu     $v0, $zero, 2
/* 7ECCF8 80241FE8 03E00008 */  jr        $ra
/* 7ECCFC 80241FEC 27BD0030 */   addiu    $sp, $sp, 0x30
