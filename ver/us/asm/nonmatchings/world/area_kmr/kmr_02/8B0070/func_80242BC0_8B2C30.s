.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242BC0_8B2C30
/* 8B2C30 80242BC0 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 8B2C34 80242BC4 AFB20020 */  sw        $s2, 0x20($sp)
/* 8B2C38 80242BC8 0080902D */  daddu     $s2, $a0, $zero
/* 8B2C3C 80242BCC AFB1001C */  sw        $s1, 0x1c($sp)
/* 8B2C40 80242BD0 00A0882D */  daddu     $s1, $a1, $zero
/* 8B2C44 80242BD4 AFBF003C */  sw        $ra, 0x3c($sp)
/* 8B2C48 80242BD8 AFBE0038 */  sw        $fp, 0x38($sp)
/* 8B2C4C 80242BDC AFB70034 */  sw        $s7, 0x34($sp)
/* 8B2C50 80242BE0 AFB60030 */  sw        $s6, 0x30($sp)
/* 8B2C54 80242BE4 AFB5002C */  sw        $s5, 0x2c($sp)
/* 8B2C58 80242BE8 AFB40028 */  sw        $s4, 0x28($sp)
/* 8B2C5C 80242BEC AFB30024 */  sw        $s3, 0x24($sp)
/* 8B2C60 80242BF0 AFB00018 */  sw        $s0, 0x18($sp)
/* 8B2C64 80242BF4 8E50000C */  lw        $s0, 0xc($s2)
/* 8B2C68 80242BF8 8E050000 */  lw        $a1, ($s0)
/* 8B2C6C 80242BFC 0C0B1EAF */  jal       get_variable
/* 8B2C70 80242C00 26100004 */   addiu    $s0, $s0, 4
/* 8B2C74 80242C04 8E050000 */  lw        $a1, ($s0)
/* 8B2C78 80242C08 26100004 */  addiu     $s0, $s0, 4
/* 8B2C7C 80242C0C 0240202D */  daddu     $a0, $s2, $zero
/* 8B2C80 80242C10 0C0B1EAF */  jal       get_variable
/* 8B2C84 80242C14 0040B02D */   daddu    $s6, $v0, $zero
/* 8B2C88 80242C18 8E050000 */  lw        $a1, ($s0)
/* 8B2C8C 80242C1C 26100004 */  addiu     $s0, $s0, 4
/* 8B2C90 80242C20 0240202D */  daddu     $a0, $s2, $zero
/* 8B2C94 80242C24 0C0B1EAF */  jal       get_variable
/* 8B2C98 80242C28 0040A82D */   daddu    $s5, $v0, $zero
/* 8B2C9C 80242C2C 8E050000 */  lw        $a1, ($s0)
/* 8B2CA0 80242C30 26100004 */  addiu     $s0, $s0, 4
/* 8B2CA4 80242C34 0240202D */  daddu     $a0, $s2, $zero
/* 8B2CA8 80242C38 0C0B1EAF */  jal       get_variable
/* 8B2CAC 80242C3C 0040A02D */   daddu    $s4, $v0, $zero
/* 8B2CB0 80242C40 8E050000 */  lw        $a1, ($s0)
/* 8B2CB4 80242C44 26100004 */  addiu     $s0, $s0, 4
/* 8B2CB8 80242C48 0240202D */  daddu     $a0, $s2, $zero
/* 8B2CBC 80242C4C 0C0B1EAF */  jal       get_variable
/* 8B2CC0 80242C50 0040B82D */   daddu    $s7, $v0, $zero
/* 8B2CC4 80242C54 8E050000 */  lw        $a1, ($s0)
/* 8B2CC8 80242C58 26100004 */  addiu     $s0, $s0, 4
/* 8B2CCC 80242C5C 0240202D */  daddu     $a0, $s2, $zero
/* 8B2CD0 80242C60 0C0B1EAF */  jal       get_variable
/* 8B2CD4 80242C64 0040982D */   daddu    $s3, $v0, $zero
/* 8B2CD8 80242C68 0240202D */  daddu     $a0, $s2, $zero
/* 8B2CDC 80242C6C 8E050000 */  lw        $a1, ($s0)
/* 8B2CE0 80242C70 0C0B1EAF */  jal       get_variable
/* 8B2CE4 80242C74 0040F02D */   daddu    $fp, $v0, $zero
/* 8B2CE8 80242C78 12200011 */  beqz      $s1, .L80242CC0
/* 8B2CEC 80242C7C 0040802D */   daddu    $s0, $v0, $zero
/* 8B2CF0 80242C80 3C048025 */  lui       $a0, %hi(D_80257F24)
/* 8B2CF4 80242C84 24847F24 */  addiu     $a0, $a0, %lo(D_80257F24)
/* 8B2CF8 80242C88 3C058025 */  lui       $a1, %hi(D_80257F25)
/* 8B2CFC 80242C8C 24A57F25 */  addiu     $a1, $a1, %lo(D_80257F25)
/* 8B2D00 80242C90 3C068025 */  lui       $a2, %hi(D_80257F26)
/* 8B2D04 80242C94 24C67F26 */  addiu     $a2, $a2, %lo(D_80257F26)
/* 8B2D08 80242C98 3C078025 */  lui       $a3, %hi(D_80257F27)
/* 8B2D0C 80242C9C 24E77F27 */  addiu     $a3, $a3, %lo(D_80257F27)
/* 8B2D10 80242CA0 3C028025 */  lui       $v0, %hi(D_80257F28)
/* 8B2D14 80242CA4 24427F28 */  addiu     $v0, $v0, %lo(D_80257F28)
/* 8B2D18 80242CA8 AFA20010 */  sw        $v0, 0x10($sp)
/* 8B2D1C 80242CAC 3C028025 */  lui       $v0, %hi(D_80257F29)
/* 8B2D20 80242CB0 24427F29 */  addiu     $v0, $v0, %lo(D_80257F29)
/* 8B2D24 80242CB4 0C046FF5 */  jal       get_model_env_color_parameters
/* 8B2D28 80242CB8 AFA20014 */   sw       $v0, 0x14($sp)
/* 8B2D2C 80242CBC AE400070 */  sw        $zero, 0x70($s2)
.L80242CC0:
/* 8B2D30 80242CC0 1A00007A */  blez      $s0, .L80242EAC
/* 8B2D34 80242CC4 32C400FF */   andi     $a0, $s6, 0xff
/* 8B2D38 80242CC8 3C048025 */  lui       $a0, %hi(D_80257F24)
/* 8B2D3C 80242CCC 90847F24 */  lbu       $a0, %lo(D_80257F24)($a0)
/* 8B2D40 80242CD0 8E480070 */  lw        $t0, 0x70($s2)
/* 8B2D44 80242CD4 02C41023 */  subu      $v0, $s6, $a0
/* 8B2D48 80242CD8 00480018 */  mult      $v0, $t0
/* 8B2D4C 80242CDC 00001812 */  mflo      $v1
/* 8B2D50 80242CE0 00000000 */  nop
/* 8B2D54 80242CE4 16000002 */  bnez      $s0, .L80242CF0
/* 8B2D58 80242CE8 0070001A */   div      $zero, $v1, $s0
/* 8B2D5C 80242CEC 0007000D */  break     7
.L80242CF0:
/* 8B2D60 80242CF0 2401FFFF */   addiu    $at, $zero, -1
/* 8B2D64 80242CF4 16010004 */  bne       $s0, $at, .L80242D08
/* 8B2D68 80242CF8 3C018000 */   lui      $at, 0x8000
/* 8B2D6C 80242CFC 14610002 */  bne       $v1, $at, .L80242D08
/* 8B2D70 80242D00 00000000 */   nop
/* 8B2D74 80242D04 0006000D */  break     6
.L80242D08:
/* 8B2D78 80242D08 00006812 */   mflo     $t5
/* 8B2D7C 80242D0C 3C058025 */  lui       $a1, %hi(D_80257F25)
/* 8B2D80 80242D10 90A57F25 */  lbu       $a1, %lo(D_80257F25)($a1)
/* 8B2D84 80242D14 02A51023 */  subu      $v0, $s5, $a1
/* 8B2D88 80242D18 00480018 */  mult      $v0, $t0
/* 8B2D8C 80242D1C 00001812 */  mflo      $v1
/* 8B2D90 80242D20 00000000 */  nop
/* 8B2D94 80242D24 16000002 */  bnez      $s0, .L80242D30
/* 8B2D98 80242D28 0070001A */   div      $zero, $v1, $s0
/* 8B2D9C 80242D2C 0007000D */  break     7
.L80242D30:
/* 8B2DA0 80242D30 2401FFFF */   addiu    $at, $zero, -1
/* 8B2DA4 80242D34 16010004 */  bne       $s0, $at, .L80242D48
/* 8B2DA8 80242D38 3C018000 */   lui      $at, 0x8000
/* 8B2DAC 80242D3C 14610002 */  bne       $v1, $at, .L80242D48
/* 8B2DB0 80242D40 00000000 */   nop
/* 8B2DB4 80242D44 0006000D */  break     6
.L80242D48:
/* 8B2DB8 80242D48 00006012 */   mflo     $t4
/* 8B2DBC 80242D4C 3C068025 */  lui       $a2, %hi(D_80257F26)
/* 8B2DC0 80242D50 90C67F26 */  lbu       $a2, %lo(D_80257F26)($a2)
/* 8B2DC4 80242D54 02861023 */  subu      $v0, $s4, $a2
/* 8B2DC8 80242D58 00480018 */  mult      $v0, $t0
/* 8B2DCC 80242D5C 00001812 */  mflo      $v1
/* 8B2DD0 80242D60 00000000 */  nop
/* 8B2DD4 80242D64 16000002 */  bnez      $s0, .L80242D70
/* 8B2DD8 80242D68 0070001A */   div      $zero, $v1, $s0
/* 8B2DDC 80242D6C 0007000D */  break     7
.L80242D70:
/* 8B2DE0 80242D70 2401FFFF */   addiu    $at, $zero, -1
/* 8B2DE4 80242D74 16010004 */  bne       $s0, $at, .L80242D88
/* 8B2DE8 80242D78 3C018000 */   lui      $at, 0x8000
/* 8B2DEC 80242D7C 14610002 */  bne       $v1, $at, .L80242D88
/* 8B2DF0 80242D80 00000000 */   nop
/* 8B2DF4 80242D84 0006000D */  break     6
.L80242D88:
/* 8B2DF8 80242D88 00005812 */   mflo     $t3
/* 8B2DFC 80242D8C 3C038025 */  lui       $v1, %hi(D_80257F28)
/* 8B2E00 80242D90 90637F28 */  lbu       $v1, %lo(D_80257F28)($v1)
/* 8B2E04 80242D94 02631023 */  subu      $v0, $s3, $v1
/* 8B2E08 80242D98 00480018 */  mult      $v0, $t0
/* 8B2E0C 80242D9C 00004812 */  mflo      $t1
/* 8B2E10 80242DA0 00000000 */  nop
/* 8B2E14 80242DA4 16000002 */  bnez      $s0, .L80242DB0
/* 8B2E18 80242DA8 0130001A */   div      $zero, $t1, $s0
/* 8B2E1C 80242DAC 0007000D */  break     7
.L80242DB0:
/* 8B2E20 80242DB0 2401FFFF */   addiu    $at, $zero, -1
/* 8B2E24 80242DB4 16010004 */  bne       $s0, $at, .L80242DC8
/* 8B2E28 80242DB8 3C018000 */   lui      $at, 0x8000
/* 8B2E2C 80242DBC 15210002 */  bne       $t1, $at, .L80242DC8
/* 8B2E30 80242DC0 00000000 */   nop
/* 8B2E34 80242DC4 0006000D */  break     6
.L80242DC8:
/* 8B2E38 80242DC8 00004812 */   mflo     $t1
/* 8B2E3C 80242DCC 3C078025 */  lui       $a3, %hi(D_80257F27)
/* 8B2E40 80242DD0 90E77F27 */  lbu       $a3, %lo(D_80257F27)($a3)
/* 8B2E44 80242DD4 02E71023 */  subu      $v0, $s7, $a3
/* 8B2E48 80242DD8 00480018 */  mult      $v0, $t0
/* 8B2E4C 80242DDC 00004012 */  mflo      $t0
/* 8B2E50 80242DE0 00000000 */  nop
/* 8B2E54 80242DE4 16000002 */  bnez      $s0, .L80242DF0
/* 8B2E58 80242DE8 0110001A */   div      $zero, $t0, $s0
/* 8B2E5C 80242DEC 0007000D */  break     7
.L80242DF0:
/* 8B2E60 80242DF0 2401FFFF */   addiu    $at, $zero, -1
/* 8B2E64 80242DF4 16010004 */  bne       $s0, $at, .L80242E08
/* 8B2E68 80242DF8 3C018000 */   lui      $at, 0x8000
/* 8B2E6C 80242DFC 15010002 */  bne       $t0, $at, .L80242E08
/* 8B2E70 80242E00 00000000 */   nop
/* 8B2E74 80242E04 0006000D */  break     6
.L80242E08:
/* 8B2E78 80242E08 00005012 */   mflo     $t2
/* 8B2E7C 80242E0C 3C088025 */  lui       $t0, %hi(D_80257F29)
/* 8B2E80 80242E10 91087F29 */  lbu       $t0, %lo(D_80257F29)($t0)
/* 8B2E84 80242E14 00691821 */  addu      $v1, $v1, $t1
/* 8B2E88 80242E18 306300FF */  andi      $v1, $v1, 0xff
/* 8B2E8C 80242E1C AFA30010 */  sw        $v1, 0x10($sp)
/* 8B2E90 80242E20 8E430070 */  lw        $v1, 0x70($s2)
/* 8B2E94 80242E24 03C81023 */  subu      $v0, $fp, $t0
/* 8B2E98 80242E28 00430018 */  mult      $v0, $v1
/* 8B2E9C 80242E2C 00001812 */  mflo      $v1
/* 8B2EA0 80242E30 00000000 */  nop
/* 8B2EA4 80242E34 16000002 */  bnez      $s0, .L80242E40
/* 8B2EA8 80242E38 0070001A */   div      $zero, $v1, $s0
/* 8B2EAC 80242E3C 0007000D */  break     7
.L80242E40:
/* 8B2EB0 80242E40 2401FFFF */   addiu    $at, $zero, -1
/* 8B2EB4 80242E44 16010004 */  bne       $s0, $at, .L80242E58
/* 8B2EB8 80242E48 3C018000 */   lui      $at, 0x8000
/* 8B2EBC 80242E4C 14610002 */  bne       $v1, $at, .L80242E58
/* 8B2EC0 80242E50 00000000 */   nop
/* 8B2EC4 80242E54 0006000D */  break     6
.L80242E58:
/* 8B2EC8 80242E58 00001012 */   mflo     $v0
/* 8B2ECC 80242E5C 008D2021 */  addu      $a0, $a0, $t5
/* 8B2ED0 80242E60 308400FF */  andi      $a0, $a0, 0xff
/* 8B2ED4 80242E64 00AC2821 */  addu      $a1, $a1, $t4
/* 8B2ED8 80242E68 30A500FF */  andi      $a1, $a1, 0xff
/* 8B2EDC 80242E6C 00CB3021 */  addu      $a2, $a2, $t3
/* 8B2EE0 80242E70 30C600FF */  andi      $a2, $a2, 0xff
/* 8B2EE4 80242E74 00EA3821 */  addu      $a3, $a3, $t2
/* 8B2EE8 80242E78 30E700FF */  andi      $a3, $a3, 0xff
/* 8B2EEC 80242E7C 01024021 */  addu      $t0, $t0, $v0
/* 8B2EF0 80242E80 310800FF */  andi      $t0, $t0, 0xff
/* 8B2EF4 80242E84 0C046FE6 */  jal       set_model_env_color_parameters
/* 8B2EF8 80242E88 AFA80014 */   sw       $t0, 0x14($sp)
/* 8B2EFC 80242E8C 8E420070 */  lw        $v0, 0x70($s2)
/* 8B2F00 80242E90 24420001 */  addiu     $v0, $v0, 1
/* 8B2F04 80242E94 AE420070 */  sw        $v0, 0x70($s2)
/* 8B2F08 80242E98 0202102A */  slt       $v0, $s0, $v0
/* 8B2F0C 80242E9C 1040000D */  beqz      $v0, .L80242ED4
/* 8B2F10 80242EA0 24020002 */   addiu    $v0, $zero, 2
/* 8B2F14 80242EA4 08090BB6 */  j         .L80242ED8
/* 8B2F18 80242EA8 00000000 */   nop
.L80242EAC:
/* 8B2F1C 80242EAC 32A500FF */  andi      $a1, $s5, 0xff
/* 8B2F20 80242EB0 328600FF */  andi      $a2, $s4, 0xff
/* 8B2F24 80242EB4 32E700FF */  andi      $a3, $s7, 0xff
/* 8B2F28 80242EB8 326200FF */  andi      $v0, $s3, 0xff
/* 8B2F2C 80242EBC AFA20010 */  sw        $v0, 0x10($sp)
/* 8B2F30 80242EC0 33C200FF */  andi      $v0, $fp, 0xff
/* 8B2F34 80242EC4 0C046FE6 */  jal       set_model_env_color_parameters
/* 8B2F38 80242EC8 AFA20014 */   sw       $v0, 0x14($sp)
/* 8B2F3C 80242ECC 08090BB6 */  j         .L80242ED8
/* 8B2F40 80242ED0 24020002 */   addiu    $v0, $zero, 2
.L80242ED4:
/* 8B2F44 80242ED4 0000102D */  daddu     $v0, $zero, $zero
.L80242ED8:
/* 8B2F48 80242ED8 8FBF003C */  lw        $ra, 0x3c($sp)
/* 8B2F4C 80242EDC 8FBE0038 */  lw        $fp, 0x38($sp)
/* 8B2F50 80242EE0 8FB70034 */  lw        $s7, 0x34($sp)
/* 8B2F54 80242EE4 8FB60030 */  lw        $s6, 0x30($sp)
/* 8B2F58 80242EE8 8FB5002C */  lw        $s5, 0x2c($sp)
/* 8B2F5C 80242EEC 8FB40028 */  lw        $s4, 0x28($sp)
/* 8B2F60 80242EF0 8FB30024 */  lw        $s3, 0x24($sp)
/* 8B2F64 80242EF4 8FB20020 */  lw        $s2, 0x20($sp)
/* 8B2F68 80242EF8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 8B2F6C 80242EFC 8FB00018 */  lw        $s0, 0x18($sp)
/* 8B2F70 80242F00 03E00008 */  jr        $ra
/* 8B2F74 80242F04 27BD0040 */   addiu    $sp, $sp, 0x40
