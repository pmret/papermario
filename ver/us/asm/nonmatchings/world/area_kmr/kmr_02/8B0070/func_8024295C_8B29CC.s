.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024295C_8B29CC
/* 8B29CC 8024295C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 8B29D0 80242960 AFB20018 */  sw        $s2, 0x18($sp)
/* 8B29D4 80242964 0080902D */  daddu     $s2, $a0, $zero
/* 8B29D8 80242968 AFB10014 */  sw        $s1, 0x14($sp)
/* 8B29DC 8024296C 00A0882D */  daddu     $s1, $a1, $zero
/* 8B29E0 80242970 AFBF002C */  sw        $ra, 0x2c($sp)
/* 8B29E4 80242974 AFB60028 */  sw        $s6, 0x28($sp)
/* 8B29E8 80242978 AFB50024 */  sw        $s5, 0x24($sp)
/* 8B29EC 8024297C AFB40020 */  sw        $s4, 0x20($sp)
/* 8B29F0 80242980 AFB3001C */  sw        $s3, 0x1c($sp)
/* 8B29F4 80242984 AFB00010 */  sw        $s0, 0x10($sp)
/* 8B29F8 80242988 8E50000C */  lw        $s0, 0xc($s2)
/* 8B29FC 8024298C 8E050000 */  lw        $a1, ($s0)
/* 8B2A00 80242990 0C0B1EAF */  jal       evt_get_variable
/* 8B2A04 80242994 26100004 */   addiu    $s0, $s0, 4
/* 8B2A08 80242998 8E050000 */  lw        $a1, ($s0)
/* 8B2A0C 8024299C 26100004 */  addiu     $s0, $s0, 4
/* 8B2A10 802429A0 0240202D */  daddu     $a0, $s2, $zero
/* 8B2A14 802429A4 0C0B1EAF */  jal       evt_get_variable
/* 8B2A18 802429A8 0040B02D */   daddu    $s6, $v0, $zero
/* 8B2A1C 802429AC 8E050000 */  lw        $a1, ($s0)
/* 8B2A20 802429B0 26100004 */  addiu     $s0, $s0, 4
/* 8B2A24 802429B4 0240202D */  daddu     $a0, $s2, $zero
/* 8B2A28 802429B8 0C0B1EAF */  jal       evt_get_variable
/* 8B2A2C 802429BC 0040A02D */   daddu    $s4, $v0, $zero
/* 8B2A30 802429C0 8E050000 */  lw        $a1, ($s0)
/* 8B2A34 802429C4 26100004 */  addiu     $s0, $s0, 4
/* 8B2A38 802429C8 0240202D */  daddu     $a0, $s2, $zero
/* 8B2A3C 802429CC 0C0B1EAF */  jal       evt_get_variable
/* 8B2A40 802429D0 0040982D */   daddu    $s3, $v0, $zero
/* 8B2A44 802429D4 0240202D */  daddu     $a0, $s2, $zero
/* 8B2A48 802429D8 8E050000 */  lw        $a1, ($s0)
/* 8B2A4C 802429DC 0C0B1EAF */  jal       evt_get_variable
/* 8B2A50 802429E0 0040A82D */   daddu    $s5, $v0, $zero
/* 8B2A54 802429E4 1220000B */  beqz      $s1, .L80242A14
/* 8B2A58 802429E8 0040802D */   daddu    $s0, $v0, $zero
/* 8B2A5C 802429EC 3C048025 */  lui       $a0, %hi(D_80257F20)
/* 8B2A60 802429F0 24847F20 */  addiu     $a0, $a0, %lo(D_80257F20)
/* 8B2A64 802429F4 3C058025 */  lui       $a1, %hi(D_80257F21)
/* 8B2A68 802429F8 24A57F21 */  addiu     $a1, $a1, %lo(D_80257F21)
/* 8B2A6C 802429FC 3C068025 */  lui       $a2, %hi(D_80257F22)
/* 8B2A70 80242A00 24C67F22 */  addiu     $a2, $a2, %lo(D_80257F22)
/* 8B2A74 80242A04 3C078025 */  lui       $a3, %hi(D_80257F23)
/* 8B2A78 80242A08 0C046FA0 */  jal       get_background_color_blend
/* 8B2A7C 80242A0C 24E77F23 */   addiu    $a3, $a3, %lo(D_80257F23)
/* 8B2A80 80242A10 AE400070 */  sw        $zero, 0x70($s2)
.L80242A14:
/* 8B2A84 80242A14 1A000053 */  blez      $s0, .L80242B64
/* 8B2A88 80242A18 32C400FF */   andi     $a0, $s6, 0xff
/* 8B2A8C 80242A1C 3C048025 */  lui       $a0, %hi(D_80257F20)
/* 8B2A90 80242A20 90847F20 */  lbu       $a0, %lo(D_80257F20)($a0)
/* 8B2A94 80242A24 8E430070 */  lw        $v1, 0x70($s2)
/* 8B2A98 80242A28 02C41023 */  subu      $v0, $s6, $a0
/* 8B2A9C 80242A2C 00430018 */  mult      $v0, $v1
/* 8B2AA0 80242A30 00004012 */  mflo      $t0
/* 8B2AA4 80242A34 00000000 */  nop
/* 8B2AA8 80242A38 16000002 */  bnez      $s0, .L80242A44
/* 8B2AAC 80242A3C 0110001A */   div      $zero, $t0, $s0
/* 8B2AB0 80242A40 0007000D */  break     7
.L80242A44:
/* 8B2AB4 80242A44 2401FFFF */   addiu    $at, $zero, -1
/* 8B2AB8 80242A48 16010004 */  bne       $s0, $at, .L80242A5C
/* 8B2ABC 80242A4C 3C018000 */   lui      $at, 0x8000
/* 8B2AC0 80242A50 15010002 */  bne       $t0, $at, .L80242A5C
/* 8B2AC4 80242A54 00000000 */   nop
/* 8B2AC8 80242A58 0006000D */  break     6
.L80242A5C:
/* 8B2ACC 80242A5C 00005012 */   mflo     $t2
/* 8B2AD0 80242A60 3C058025 */  lui       $a1, %hi(D_80257F21)
/* 8B2AD4 80242A64 90A57F21 */  lbu       $a1, %lo(D_80257F21)($a1)
/* 8B2AD8 80242A68 02851023 */  subu      $v0, $s4, $a1
/* 8B2ADC 80242A6C 00430018 */  mult      $v0, $v1
/* 8B2AE0 80242A70 00004012 */  mflo      $t0
/* 8B2AE4 80242A74 00000000 */  nop
/* 8B2AE8 80242A78 16000002 */  bnez      $s0, .L80242A84
/* 8B2AEC 80242A7C 0110001A */   div      $zero, $t0, $s0
/* 8B2AF0 80242A80 0007000D */  break     7
.L80242A84:
/* 8B2AF4 80242A84 2401FFFF */   addiu    $at, $zero, -1
/* 8B2AF8 80242A88 16010004 */  bne       $s0, $at, .L80242A9C
/* 8B2AFC 80242A8C 3C018000 */   lui      $at, 0x8000
/* 8B2B00 80242A90 15010002 */  bne       $t0, $at, .L80242A9C
/* 8B2B04 80242A94 00000000 */   nop
/* 8B2B08 80242A98 0006000D */  break     6
.L80242A9C:
/* 8B2B0C 80242A9C 00004812 */   mflo     $t1
/* 8B2B10 80242AA0 3C068025 */  lui       $a2, %hi(D_80257F22)
/* 8B2B14 80242AA4 90C67F22 */  lbu       $a2, %lo(D_80257F22)($a2)
/* 8B2B18 80242AA8 02661023 */  subu      $v0, $s3, $a2
/* 8B2B1C 80242AAC 00430018 */  mult      $v0, $v1
/* 8B2B20 80242AB0 00004012 */  mflo      $t0
/* 8B2B24 80242AB4 00000000 */  nop
/* 8B2B28 80242AB8 16000002 */  bnez      $s0, .L80242AC4
/* 8B2B2C 80242ABC 0110001A */   div      $zero, $t0, $s0
/* 8B2B30 80242AC0 0007000D */  break     7
.L80242AC4:
/* 8B2B34 80242AC4 2401FFFF */   addiu    $at, $zero, -1
/* 8B2B38 80242AC8 16010004 */  bne       $s0, $at, .L80242ADC
/* 8B2B3C 80242ACC 3C018000 */   lui      $at, 0x8000
/* 8B2B40 80242AD0 15010002 */  bne       $t0, $at, .L80242ADC
/* 8B2B44 80242AD4 00000000 */   nop
/* 8B2B48 80242AD8 0006000D */  break     6
.L80242ADC:
/* 8B2B4C 80242ADC 00004012 */   mflo     $t0
/* 8B2B50 80242AE0 3C078025 */  lui       $a3, %hi(D_80257F23)
/* 8B2B54 80242AE4 90E77F23 */  lbu       $a3, %lo(D_80257F23)($a3)
/* 8B2B58 80242AE8 02A71023 */  subu      $v0, $s5, $a3
/* 8B2B5C 80242AEC 00430018 */  mult      $v0, $v1
/* 8B2B60 80242AF0 00001812 */  mflo      $v1
/* 8B2B64 80242AF4 00000000 */  nop
/* 8B2B68 80242AF8 16000002 */  bnez      $s0, .L80242B04
/* 8B2B6C 80242AFC 0070001A */   div      $zero, $v1, $s0
/* 8B2B70 80242B00 0007000D */  break     7
.L80242B04:
/* 8B2B74 80242B04 2401FFFF */   addiu    $at, $zero, -1
/* 8B2B78 80242B08 16010004 */  bne       $s0, $at, .L80242B1C
/* 8B2B7C 80242B0C 3C018000 */   lui      $at, 0x8000
/* 8B2B80 80242B10 14610002 */  bne       $v1, $at, .L80242B1C
/* 8B2B84 80242B14 00000000 */   nop
/* 8B2B88 80242B18 0006000D */  break     6
.L80242B1C:
/* 8B2B8C 80242B1C 00001012 */   mflo     $v0
/* 8B2B90 80242B20 008A2021 */  addu      $a0, $a0, $t2
/* 8B2B94 80242B24 308400FF */  andi      $a0, $a0, 0xff
/* 8B2B98 80242B28 00A92821 */  addu      $a1, $a1, $t1
/* 8B2B9C 80242B2C 30A500FF */  andi      $a1, $a1, 0xff
/* 8B2BA0 80242B30 00C83021 */  addu      $a2, $a2, $t0
/* 8B2BA4 80242B34 30C600FF */  andi      $a2, $a2, 0xff
/* 8B2BA8 80242B38 00E23821 */  addu      $a3, $a3, $v0
/* 8B2BAC 80242B3C 0C046F97 */  jal       set_background_color_blend
/* 8B2BB0 80242B40 30E700FF */   andi     $a3, $a3, 0xff
/* 8B2BB4 80242B44 8E420070 */  lw        $v0, 0x70($s2)
/* 8B2BB8 80242B48 24420001 */  addiu     $v0, $v0, 1
/* 8B2BBC 80242B4C AE420070 */  sw        $v0, 0x70($s2)
/* 8B2BC0 80242B50 0202102A */  slt       $v0, $s0, $v0
/* 8B2BC4 80242B54 10400009 */  beqz      $v0, .L80242B7C
/* 8B2BC8 80242B58 24020002 */   addiu    $v0, $zero, 2
/* 8B2BCC 80242B5C 08090AE0 */  j         .L80242B80
/* 8B2BD0 80242B60 00000000 */   nop
.L80242B64:
/* 8B2BD4 80242B64 328500FF */  andi      $a1, $s4, 0xff
/* 8B2BD8 80242B68 326600FF */  andi      $a2, $s3, 0xff
/* 8B2BDC 80242B6C 0C046F97 */  jal       set_background_color_blend
/* 8B2BE0 80242B70 32A700FF */   andi     $a3, $s5, 0xff
/* 8B2BE4 80242B74 08090AE0 */  j         .L80242B80
/* 8B2BE8 80242B78 24020002 */   addiu    $v0, $zero, 2
.L80242B7C:
/* 8B2BEC 80242B7C 0000102D */  daddu     $v0, $zero, $zero
.L80242B80:
/* 8B2BF0 80242B80 8FBF002C */  lw        $ra, 0x2c($sp)
/* 8B2BF4 80242B84 8FB60028 */  lw        $s6, 0x28($sp)
/* 8B2BF8 80242B88 8FB50024 */  lw        $s5, 0x24($sp)
/* 8B2BFC 80242B8C 8FB40020 */  lw        $s4, 0x20($sp)
/* 8B2C00 80242B90 8FB3001C */  lw        $s3, 0x1c($sp)
/* 8B2C04 80242B94 8FB20018 */  lw        $s2, 0x18($sp)
/* 8B2C08 80242B98 8FB10014 */  lw        $s1, 0x14($sp)
/* 8B2C0C 80242B9C 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B2C10 80242BA0 03E00008 */  jr        $ra
/* 8B2C14 80242BA4 27BD0030 */   addiu    $sp, $sp, 0x30
