.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409C4_A2AC04
/* A2AC04 802409C4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A2AC08 802409C8 AFB1001C */  sw        $s1, 0x1c($sp)
/* A2AC0C 802409CC 0080882D */  daddu     $s1, $a0, $zero
/* A2AC10 802409D0 AFBF0020 */  sw        $ra, 0x20($sp)
/* A2AC14 802409D4 AFB00018 */  sw        $s0, 0x18($sp)
/* A2AC18 802409D8 10A0003B */  beqz      $a1, .L80240AC8
/* A2AC1C 802409DC 8E30000C */   lw       $s0, 0xc($s1)
/* A2AC20 802409E0 3C048025 */  lui       $a0, %hi(D_8024F2A0)
/* A2AC24 802409E4 2484F2A0 */  addiu     $a0, $a0, %lo(D_8024F2A0)
/* A2AC28 802409E8 3C058025 */  lui       $a1, %hi(D_8024F2A1)
/* A2AC2C 802409EC 24A5F2A1 */  addiu     $a1, $a1, %lo(D_8024F2A1)
/* A2AC30 802409F0 3C068025 */  lui       $a2, %hi(D_8024F2A2)
/* A2AC34 802409F4 24C6F2A2 */  addiu     $a2, $a2, %lo(D_8024F2A2)
/* A2AC38 802409F8 3C078025 */  lui       $a3, %hi(D_8024F2A3)
/* A2AC3C 802409FC 24E7F2A3 */  addiu     $a3, $a3, %lo(D_8024F2A3)
/* A2AC40 80240A00 3C028025 */  lui       $v0, %hi(D_8024F2A4)
/* A2AC44 80240A04 2442F2A4 */  addiu     $v0, $v0, %lo(D_8024F2A4)
/* A2AC48 80240A08 AFA20010 */  sw        $v0, 0x10($sp)
/* A2AC4C 80240A0C 3C028025 */  lui       $v0, %hi(D_8024F2A5)
/* A2AC50 80240A10 2442F2A5 */  addiu     $v0, $v0, %lo(D_8024F2A5)
/* A2AC54 80240A14 0C046FF5 */  jal       func_8011BFD4
/* A2AC58 80240A18 AFA20014 */   sw       $v0, 0x14($sp)
/* A2AC5C 80240A1C 8E050000 */  lw        $a1, ($s0)
/* A2AC60 80240A20 26100004 */  addiu     $s0, $s0, 4
/* A2AC64 80240A24 0C0B1EAF */  jal       get_variable
/* A2AC68 80240A28 0220202D */   daddu    $a0, $s1, $zero
/* A2AC6C 80240A2C 3C018025 */  lui       $at, %hi(D_8024F2A8)
/* A2AC70 80240A30 AC22F2A8 */  sw        $v0, %lo(D_8024F2A8)($at)
/* A2AC74 80240A34 8E050000 */  lw        $a1, ($s0)
/* A2AC78 80240A38 26100004 */  addiu     $s0, $s0, 4
/* A2AC7C 80240A3C 0C0B1EAF */  jal       get_variable
/* A2AC80 80240A40 0220202D */   daddu    $a0, $s1, $zero
/* A2AC84 80240A44 3C018025 */  lui       $at, %hi(D_8024F2AC)
/* A2AC88 80240A48 AC22F2AC */  sw        $v0, %lo(D_8024F2AC)($at)
/* A2AC8C 80240A4C 8E050000 */  lw        $a1, ($s0)
/* A2AC90 80240A50 26100004 */  addiu     $s0, $s0, 4
/* A2AC94 80240A54 0C0B1EAF */  jal       get_variable
/* A2AC98 80240A58 0220202D */   daddu    $a0, $s1, $zero
/* A2AC9C 80240A5C 3C018025 */  lui       $at, %hi(D_8024F2B0)
/* A2ACA0 80240A60 AC22F2B0 */  sw        $v0, %lo(D_8024F2B0)($at)
/* A2ACA4 80240A64 8E050000 */  lw        $a1, ($s0)
/* A2ACA8 80240A68 26100004 */  addiu     $s0, $s0, 4
/* A2ACAC 80240A6C 0C0B1EAF */  jal       get_variable
/* A2ACB0 80240A70 0220202D */   daddu    $a0, $s1, $zero
/* A2ACB4 80240A74 3C018025 */  lui       $at, %hi(D_8024F2B4)
/* A2ACB8 80240A78 AC22F2B4 */  sw        $v0, %lo(D_8024F2B4)($at)
/* A2ACBC 80240A7C 8E050000 */  lw        $a1, ($s0)
/* A2ACC0 80240A80 26100004 */  addiu     $s0, $s0, 4
/* A2ACC4 80240A84 0C0B1EAF */  jal       get_variable
/* A2ACC8 80240A88 0220202D */   daddu    $a0, $s1, $zero
/* A2ACCC 80240A8C 3C018025 */  lui       $at, %hi(D_8024F2B8)
/* A2ACD0 80240A90 AC22F2B8 */  sw        $v0, %lo(D_8024F2B8)($at)
/* A2ACD4 80240A94 8E050000 */  lw        $a1, ($s0)
/* A2ACD8 80240A98 26100004 */  addiu     $s0, $s0, 4
/* A2ACDC 80240A9C 0C0B1EAF */  jal       get_variable
/* A2ACE0 80240AA0 0220202D */   daddu    $a0, $s1, $zero
/* A2ACE4 80240AA4 3C018025 */  lui       $at, %hi(D_8024F2BC)
/* A2ACE8 80240AA8 AC22F2BC */  sw        $v0, %lo(D_8024F2BC)($at)
/* A2ACEC 80240AAC 8E050000 */  lw        $a1, ($s0)
/* A2ACF0 80240AB0 0C0B1EAF */  jal       get_variable
/* A2ACF4 80240AB4 0220202D */   daddu    $a0, $s1, $zero
/* A2ACF8 80240AB8 3C018025 */  lui       $at, %hi(D_8024F2C0)
/* A2ACFC 80240ABC AC22F2C0 */  sw        $v0, %lo(D_8024F2C0)($at)
/* A2AD00 80240AC0 3C018025 */  lui       $at, %hi(D_8024F2C4)
/* A2AD04 80240AC4 AC20F2C4 */  sw        $zero, %lo(D_8024F2C4)($at)
.L80240AC8:
/* A2AD08 80240AC8 3C118025 */  lui       $s1, %hi(D_8024F2C0)
/* A2AD0C 80240ACC 2631F2C0 */  addiu     $s1, $s1, %lo(D_8024F2C0)
/* A2AD10 80240AD0 8E2F0000 */  lw        $t7, ($s1)
/* A2AD14 80240AD4 19E0008A */  blez      $t7, .L80240D00
/* A2AD18 80240AD8 00000000 */   nop      
/* A2AD1C 80240ADC 3C108025 */  lui       $s0, %hi(D_8024F2C4)
/* A2AD20 80240AE0 2610F2C4 */  addiu     $s0, $s0, %lo(D_8024F2C4)
/* A2AD24 80240AE4 8E030000 */  lw        $v1, ($s0)
/* A2AD28 80240AE8 006F102A */  slt       $v0, $v1, $t7
/* A2AD2C 80240AEC 10400093 */  beqz      $v0, .L80240D3C
/* A2AD30 80240AF0 24630001 */   addiu    $v1, $v1, 1
/* A2AD34 80240AF4 3C048025 */  lui       $a0, %hi(D_8024F2A0)
/* A2AD38 80240AF8 9084F2A0 */  lbu       $a0, %lo(D_8024F2A0)($a0)
/* A2AD3C 80240AFC 3C028025 */  lui       $v0, %hi(D_8024F2A8)
/* A2AD40 80240B00 8C42F2A8 */  lw        $v0, %lo(D_8024F2A8)($v0)
/* A2AD44 80240B04 00441023 */  subu      $v0, $v0, $a0
/* A2AD48 80240B08 00430018 */  mult      $v0, $v1
/* A2AD4C 80240B0C 00004012 */  mflo      $t0
/* A2AD50 80240B10 00000000 */  nop       
/* A2AD54 80240B14 15E00002 */  bnez      $t7, .L80240B20
/* A2AD58 80240B18 010F001A */   div      $zero, $t0, $t7
/* A2AD5C 80240B1C 0007000D */  break     7
.L80240B20:
/* A2AD60 80240B20 2401FFFF */   addiu    $at, $zero, -1
/* A2AD64 80240B24 15E10004 */  bne       $t7, $at, .L80240B38
/* A2AD68 80240B28 3C018000 */   lui      $at, 0x8000
/* A2AD6C 80240B2C 15010002 */  bne       $t0, $at, .L80240B38
/* A2AD70 80240B30 00000000 */   nop      
/* A2AD74 80240B34 0006000D */  break     6
.L80240B38:
/* A2AD78 80240B38 00007012 */   mflo     $t6
/* A2AD7C 80240B3C 3C058025 */  lui       $a1, %hi(D_8024F2A1)
/* A2AD80 80240B40 90A5F2A1 */  lbu       $a1, %lo(D_8024F2A1)($a1)
/* A2AD84 80240B44 3C028025 */  lui       $v0, %hi(D_8024F2AC)
/* A2AD88 80240B48 8C42F2AC */  lw        $v0, %lo(D_8024F2AC)($v0)
/* A2AD8C 80240B4C 00451023 */  subu      $v0, $v0, $a1
/* A2AD90 80240B50 00430018 */  mult      $v0, $v1
/* A2AD94 80240B54 00004012 */  mflo      $t0
/* A2AD98 80240B58 00000000 */  nop       
/* A2AD9C 80240B5C 15E00002 */  bnez      $t7, .L80240B68
/* A2ADA0 80240B60 010F001A */   div      $zero, $t0, $t7
/* A2ADA4 80240B64 0007000D */  break     7
.L80240B68:
/* A2ADA8 80240B68 2401FFFF */   addiu    $at, $zero, -1
/* A2ADAC 80240B6C 15E10004 */  bne       $t7, $at, .L80240B80
/* A2ADB0 80240B70 3C018000 */   lui      $at, 0x8000
/* A2ADB4 80240B74 15010002 */  bne       $t0, $at, .L80240B80
/* A2ADB8 80240B78 00000000 */   nop      
/* A2ADBC 80240B7C 0006000D */  break     6
.L80240B80:
/* A2ADC0 80240B80 00006812 */   mflo     $t5
/* A2ADC4 80240B84 3C068025 */  lui       $a2, %hi(D_8024F2A2)
/* A2ADC8 80240B88 90C6F2A2 */  lbu       $a2, %lo(D_8024F2A2)($a2)
/* A2ADCC 80240B8C 3C028025 */  lui       $v0, %hi(D_8024F2B0)
/* A2ADD0 80240B90 8C42F2B0 */  lw        $v0, %lo(D_8024F2B0)($v0)
/* A2ADD4 80240B94 00461023 */  subu      $v0, $v0, $a2
/* A2ADD8 80240B98 00430018 */  mult      $v0, $v1
/* A2ADDC 80240B9C 00004012 */  mflo      $t0
/* A2ADE0 80240BA0 00000000 */  nop       
/* A2ADE4 80240BA4 15E00002 */  bnez      $t7, .L80240BB0
/* A2ADE8 80240BA8 010F001A */   div      $zero, $t0, $t7
/* A2ADEC 80240BAC 0007000D */  break     7
.L80240BB0:
/* A2ADF0 80240BB0 2401FFFF */   addiu    $at, $zero, -1
/* A2ADF4 80240BB4 15E10004 */  bne       $t7, $at, .L80240BC8
/* A2ADF8 80240BB8 3C018000 */   lui      $at, 0x8000
/* A2ADFC 80240BBC 15010002 */  bne       $t0, $at, .L80240BC8
/* A2AE00 80240BC0 00000000 */   nop      
/* A2AE04 80240BC4 0006000D */  break     6
.L80240BC8:
/* A2AE08 80240BC8 00006012 */   mflo     $t4
/* A2AE0C 80240BCC 3C078025 */  lui       $a3, %hi(D_8024F2A3)
/* A2AE10 80240BD0 90E7F2A3 */  lbu       $a3, %lo(D_8024F2A3)($a3)
/* A2AE14 80240BD4 3C028025 */  lui       $v0, %hi(D_8024F2B4)
/* A2AE18 80240BD8 8C42F2B4 */  lw        $v0, %lo(D_8024F2B4)($v0)
/* A2AE1C 80240BDC 00471023 */  subu      $v0, $v0, $a3
/* A2AE20 80240BE0 00430018 */  mult      $v0, $v1
/* A2AE24 80240BE4 00004012 */  mflo      $t0
/* A2AE28 80240BE8 00000000 */  nop       
/* A2AE2C 80240BEC 15E00002 */  bnez      $t7, .L80240BF8
/* A2AE30 80240BF0 010F001A */   div      $zero, $t0, $t7
/* A2AE34 80240BF4 0007000D */  break     7
.L80240BF8:
/* A2AE38 80240BF8 2401FFFF */   addiu    $at, $zero, -1
/* A2AE3C 80240BFC 15E10004 */  bne       $t7, $at, .L80240C10
/* A2AE40 80240C00 3C018000 */   lui      $at, 0x8000
/* A2AE44 80240C04 15010002 */  bne       $t0, $at, .L80240C10
/* A2AE48 80240C08 00000000 */   nop      
/* A2AE4C 80240C0C 0006000D */  break     6
.L80240C10:
/* A2AE50 80240C10 00005812 */   mflo     $t3
/* A2AE54 80240C14 3C098025 */  lui       $t1, %hi(D_8024F2A4)
/* A2AE58 80240C18 9129F2A4 */  lbu       $t1, %lo(D_8024F2A4)($t1)
/* A2AE5C 80240C1C 3C028025 */  lui       $v0, %hi(D_8024F2B8)
/* A2AE60 80240C20 8C42F2B8 */  lw        $v0, %lo(D_8024F2B8)($v0)
/* A2AE64 80240C24 00491023 */  subu      $v0, $v0, $t1
/* A2AE68 80240C28 00430018 */  mult      $v0, $v1
/* A2AE6C 80240C2C 00004012 */  mflo      $t0
/* A2AE70 80240C30 00000000 */  nop       
/* A2AE74 80240C34 15E00002 */  bnez      $t7, .L80240C40
/* A2AE78 80240C38 010F001A */   div      $zero, $t0, $t7
/* A2AE7C 80240C3C 0007000D */  break     7
.L80240C40:
/* A2AE80 80240C40 2401FFFF */   addiu    $at, $zero, -1
/* A2AE84 80240C44 15E10004 */  bne       $t7, $at, .L80240C58
/* A2AE88 80240C48 3C018000 */   lui      $at, 0x8000
/* A2AE8C 80240C4C 15010002 */  bne       $t0, $at, .L80240C58
/* A2AE90 80240C50 00000000 */   nop      
/* A2AE94 80240C54 0006000D */  break     6
.L80240C58:
/* A2AE98 80240C58 00005012 */   mflo     $t2
/* A2AE9C 80240C5C 3C088025 */  lui       $t0, %hi(D_8024F2A5)
/* A2AEA0 80240C60 9108F2A5 */  lbu       $t0, %lo(D_8024F2A5)($t0)
/* A2AEA4 80240C64 3C028025 */  lui       $v0, %hi(D_8024F2BC)
/* A2AEA8 80240C68 8C42F2BC */  lw        $v0, %lo(D_8024F2BC)($v0)
/* A2AEAC 80240C6C 00481023 */  subu      $v0, $v0, $t0
/* A2AEB0 80240C70 00430018 */  mult      $v0, $v1
/* A2AEB4 80240C74 0000C812 */  mflo      $t9
/* A2AEB8 80240C78 00000000 */  nop       
/* A2AEBC 80240C7C 15E00002 */  bnez      $t7, .L80240C88
/* A2AEC0 80240C80 032F001A */   div      $zero, $t9, $t7
/* A2AEC4 80240C84 0007000D */  break     7
.L80240C88:
/* A2AEC8 80240C88 2401FFFF */   addiu    $at, $zero, -1
/* A2AECC 80240C8C 15E10004 */  bne       $t7, $at, .L80240CA0
/* A2AED0 80240C90 3C018000 */   lui      $at, 0x8000
/* A2AED4 80240C94 17210002 */  bne       $t9, $at, .L80240CA0
/* A2AED8 80240C98 00000000 */   nop      
/* A2AEDC 80240C9C 0006000D */  break     6
.L80240CA0:
/* A2AEE0 80240CA0 00001012 */   mflo     $v0
/* A2AEE4 80240CA4 AE030000 */  sw        $v1, ($s0)
/* A2AEE8 80240CA8 008E2021 */  addu      $a0, $a0, $t6
/* A2AEEC 80240CAC 308400FF */  andi      $a0, $a0, 0xff
/* A2AEF0 80240CB0 00AD2821 */  addu      $a1, $a1, $t5
/* A2AEF4 80240CB4 30A500FF */  andi      $a1, $a1, 0xff
/* A2AEF8 80240CB8 00CC3021 */  addu      $a2, $a2, $t4
/* A2AEFC 80240CBC 30C600FF */  andi      $a2, $a2, 0xff
/* A2AF00 80240CC0 00EB3821 */  addu      $a3, $a3, $t3
/* A2AF04 80240CC4 30E700FF */  andi      $a3, $a3, 0xff
/* A2AF08 80240CC8 012A4821 */  addu      $t1, $t1, $t2
/* A2AF0C 80240CCC 312900FF */  andi      $t1, $t1, 0xff
/* A2AF10 80240CD0 AFA90010 */  sw        $t1, 0x10($sp)
/* A2AF14 80240CD4 01024021 */  addu      $t0, $t0, $v0
/* A2AF18 80240CD8 310800FF */  andi      $t0, $t0, 0xff
/* A2AF1C 80240CDC 0C046FE6 */  jal       func_8011BF98
/* A2AF20 80240CE0 AFA80014 */   sw       $t0, 0x14($sp)
/* A2AF24 80240CE4 8E020000 */  lw        $v0, ($s0)
/* A2AF28 80240CE8 8E230000 */  lw        $v1, ($s1)
/* A2AF2C 80240CEC 0043102A */  slt       $v0, $v0, $v1
/* A2AF30 80240CF0 14400013 */  bnez      $v0, .L80240D40
/* A2AF34 80240CF4 0000102D */   daddu    $v0, $zero, $zero
/* A2AF38 80240CF8 08090350 */  j         .L80240D40
/* A2AF3C 80240CFC 24020002 */   addiu    $v0, $zero, 2
.L80240D00:
/* A2AF40 80240D00 3C028025 */  lui       $v0, %hi(D_8024F2BB)
/* A2AF44 80240D04 9042F2BB */  lbu       $v0, %lo(D_8024F2BB)($v0)
/* A2AF48 80240D08 3C048025 */  lui       $a0, %hi(D_8024F2AB)
/* A2AF4C 80240D0C 9084F2AB */  lbu       $a0, %lo(D_8024F2AB)($a0)
/* A2AF50 80240D10 3C058025 */  lui       $a1, %hi(D_8024F2AF)
/* A2AF54 80240D14 90A5F2AF */  lbu       $a1, %lo(D_8024F2AF)($a1)
/* A2AF58 80240D18 3C068025 */  lui       $a2, %hi(D_8024F2B3)
/* A2AF5C 80240D1C 90C6F2B3 */  lbu       $a2, %lo(D_8024F2B3)($a2)
/* A2AF60 80240D20 3C078025 */  lui       $a3, %hi(D_8024F2B7)
/* A2AF64 80240D24 90E7F2B7 */  lbu       $a3, %lo(D_8024F2B7)($a3)
/* A2AF68 80240D28 3C038025 */  lui       $v1, %hi(D_8024F2BF)
/* A2AF6C 80240D2C 9063F2BF */  lbu       $v1, %lo(D_8024F2BF)($v1)
/* A2AF70 80240D30 AFA20010 */  sw        $v0, 0x10($sp)
/* A2AF74 80240D34 0C046FE6 */  jal       func_8011BF98
/* A2AF78 80240D38 AFA30014 */   sw       $v1, 0x14($sp)
.L80240D3C:
/* A2AF7C 80240D3C 24020002 */  addiu     $v0, $zero, 2
.L80240D40:
/* A2AF80 80240D40 8FBF0020 */  lw        $ra, 0x20($sp)
/* A2AF84 80240D44 8FB1001C */  lw        $s1, 0x1c($sp)
/* A2AF88 80240D48 8FB00018 */  lw        $s0, 0x18($sp)
/* A2AF8C 80240D4C 03E00008 */  jr        $ra
/* A2AF90 80240D50 27BD0028 */   addiu    $sp, $sp, 0x28
