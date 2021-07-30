.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002CA00
/* 7E00 8002CA00 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 7E04 8002CA04 AFB60030 */  sw        $s6, 0x30($sp)
/* 7E08 8002CA08 3C16759A */  lui       $s6, 0x759a
/* 7E0C 8002CA0C 26D6F6D8 */  addiu     $s6, $s6, -0x928
/* 7E10 8002CA10 AFB5002C */  sw        $s5, 0x2c($sp)
/* 7E14 8002CA14 3C15F79E */  lui       $s5, %hi(D_F79E611F)
/* 7E18 8002CA18 26B5611F */  addiu     $s5, $s5, %lo(D_F79E611F)
/* 7E1C 8002CA1C AFB30024 */  sw        $s3, 0x24($sp)
/* 7E20 8002CA20 3C130B11 */  lui       $s3, 0xb11
/* 7E24 8002CA24 36732D28 */  ori       $s3, $s3, 0x2d28
/* 7E28 8002CA28 AFB00018 */  sw        $s0, 0x18($sp)
/* 7E2C 8002CA2C 0000802D */  daddu     $s0, $zero, $zero
/* 7E30 8002CA30 3C05B000 */  lui       $a1, 0xb000
/* 7E34 8002CA34 34A50D10 */  ori       $a1, $a1, 0xd10
/* 7E38 8002CA38 3C04800A */  lui       $a0, %hi(nuPiCartHandle)
/* 7E3C 8002CA3C 8C84A618 */  lw        $a0, %lo(nuPiCartHandle)($a0)
/* 7E40 8002CA40 27A60010 */  addiu     $a2, $sp, 0x10
/* 7E44 8002CA44 AFB20020 */  sw        $s2, 0x20($sp)
/* 7E48 8002CA48 0200902D */  daddu     $s2, $s0, $zero
/* 7E4C 8002CA4C AFB40028 */  sw        $s4, 0x28($sp)
/* 7E50 8002CA50 3C148006 */  lui       $s4, %hi(osEPiReadIo)
/* 7E54 8002CA54 26940D90 */  addiu     $s4, $s4, %lo(osEPiReadIo)
/* 7E58 8002CA58 AFBF003C */  sw        $ra, 0x3c($sp)
/* 7E5C 8002CA5C AFBE0038 */  sw        $fp, 0x38($sp)
/* 7E60 8002CA60 AFB70034 */  sw        $s7, 0x34($sp)
/* 7E64 8002CA64 0280F809 */  jalr      $s4
/* 7E68 8002CA68 AFB1001C */   sw       $s1, 0x1c($sp)
/* 7E6C 8002CA6C 3C110032 */  lui       $s1, 0x32
/* 7E70 8002CA70 2631F1A0 */  addiu     $s1, $s1, -0xe60
/* 7E74 8002CA74 8FA20010 */  lw        $v0, 0x10($sp)
/* 7E78 8002CA78 3C030032 */  lui       $v1, 0x32
/* 7E7C 8002CA7C 2463F340 */  addiu     $v1, $v1, -0xcc0
/* 7E80 8002CA80 02629823 */  subu      $s3, $s3, $v0
/* 7E84 8002CA84 0223102B */  sltu      $v0, $s1, $v1
/* 7E88 8002CA88 1040002B */  beqz      $v0, .L8002CB38
/* 7E8C 8002CA8C 241E0003 */   addiu    $fp, $zero, 3
/* 7E90 8002CA90 0060B82D */  daddu     $s7, $v1, $zero
.L8002CA94:
/* 7E94 8002CA94 0220282D */  daddu     $a1, $s1, $zero
/* 7E98 8002CA98 3C04800A */  lui       $a0, %hi(nuPiCartHandle)
/* 7E9C 8002CA9C 8C84A618 */  lw        $a0, %lo(nuPiCartHandle)($a0)
/* 7EA0 8002CAA0 0280F809 */  jalr      $s4
/* 7EA4 8002CAA4 27A60010 */   addiu    $a2, $sp, 0x10
/* 7EA8 8002CAA8 8FA30010 */  lw        $v1, 0x10($sp)
/* 7EAC 8002CAAC 2407000F */  addiu     $a3, $zero, 0xf
/* 7EB0 8002CAB0 3065FFFF */  andi      $a1, $v1, 0xffff
/* 7EB4 8002CAB4 00032402 */  srl       $a0, $v1, 0x10
/* 7EB8 8002CAB8 00A41021 */  addu      $v0, $a1, $a0
/* 7EBC 8002CABC 02028021 */  addu      $s0, $s0, $v0
/* 7EC0 8002CAC0 00121682 */  srl       $v0, $s2, 0x1a
/* 7EC4 8002CAC4 14470010 */  bne       $v0, $a3, .L8002CB08
/* 7EC8 8002CAC8 00031682 */   srl      $v0, $v1, 0x1a
/* 7ECC 8002CACC 24070009 */  addiu     $a3, $zero, 9
/* 7ED0 8002CAD0 50470004 */  beql      $v0, $a3, .L8002CAE4
/* 7ED4 8002CAD4 00031542 */   srl      $v0, $v1, 0x15
/* 7ED8 8002CAD8 24070023 */  addiu     $a3, $zero, 0x23
/* 7EDC 8002CADC 1447000A */  bne       $v0, $a3, .L8002CB08
/* 7EE0 8002CAE0 00031542 */   srl      $v0, $v1, 0x15
.L8002CAE4:
/* 7EE4 8002CAE4 3043001F */  andi      $v1, $v0, 0x1f
/* 7EE8 8002CAE8 00121402 */  srl       $v0, $s2, 0x10
/* 7EEC 8002CAEC 3042001F */  andi      $v0, $v0, 0x1f
/* 7EF0 8002CAF0 14620005 */  bne       $v1, $v0, .L8002CB08
/* 7EF4 8002CAF4 3082001F */   andi     $v0, $a0, 0x1f
/* 7EF8 8002CAF8 14620003 */  bne       $v1, $v0, .L8002CB08
/* 7EFC 8002CAFC 3242FFFF */   andi     $v0, $s2, 0xffff
/* 7F00 8002CB00 02058023 */  subu      $s0, $s0, $a1
/* 7F04 8002CB04 02028023 */  subu      $s0, $s0, $v0
.L8002CB08:
/* 7F08 8002CB08 8FA40010 */  lw        $a0, 0x10($sp)
/* 7F0C 8002CB0C 00041682 */  srl       $v0, $a0, 0x1a
/* 7F10 8002CB10 145E0006 */  bne       $v0, $fp, .L8002CB2C
/* 7F14 8002CB14 26310004 */   addiu    $s1, $s1, 4
/* 7F18 8002CB18 3083FFFF */  andi      $v1, $a0, 0xffff
/* 7F1C 8002CB1C 00041402 */  srl       $v0, $a0, 0x10
/* 7F20 8002CB20 3042FC00 */  andi      $v0, $v0, 0xfc00
/* 7F24 8002CB24 00621821 */  addu      $v1, $v1, $v0
/* 7F28 8002CB28 02038023 */  subu      $s0, $s0, $v1
.L8002CB2C:
/* 7F2C 8002CB2C 0237102B */  sltu      $v0, $s1, $s7
/* 7F30 8002CB30 1440FFD8 */  bnez      $v0, .L8002CA94
/* 7F34 8002CB34 0080902D */   daddu    $s2, $a0, $zero
.L8002CB38:
/* 7F38 8002CB38 3C02FFD5 */  lui       $v0, 0xffd5
/* 7F3C 8002CB3C 3442B14A */  ori       $v0, $v0, 0xb14a
/* 7F40 8002CB40 02021021 */  addu      $v0, $s0, $v0
/* 7F44 8002CB44 02621023 */  subu      $v0, $s3, $v0
/* 7F48 8002CB48 02C2B021 */  addu      $s6, $s6, $v0
/* 7F4C 8002CB4C 3C1318F4 */  lui       $s3, 0x18f4
/* 7F50 8002CB50 367314AB */  ori       $s3, $s3, 0x14ab
/* 7F54 8002CB54 0000802D */  daddu     $s0, $zero, $zero
/* 7F58 8002CB58 3C05B000 */  lui       $a1, 0xb000
/* 7F5C 8002CB5C 34A50E38 */  ori       $a1, $a1, 0xe38
/* 7F60 8002CB60 27A60014 */  addiu     $a2, $sp, 0x14
/* 7F64 8002CB64 3C04800A */  lui       $a0, %hi(nuPiCartHandle)
/* 7F68 8002CB68 8C84A618 */  lw        $a0, %lo(nuPiCartHandle)($a0)
/* 7F6C 8002CB6C 3C148006 */  lui       $s4, %hi(osEPiReadIo)
/* 7F70 8002CB70 26940D90 */  addiu     $s4, $s4, %lo(osEPiReadIo)
/* 7F74 8002CB74 0280F809 */  jalr      $s4
/* 7F78 8002CB78 0200902D */   daddu    $s2, $s0, $zero
/* 7F7C 8002CB7C 3C110032 */  lui       $s1, 0x32
/* 7F80 8002CB80 2631F340 */  addiu     $s1, $s1, -0xcc0
/* 7F84 8002CB84 8FA20014 */  lw        $v0, 0x14($sp)
/* 7F88 8002CB88 3C030032 */  lui       $v1, 0x32
/* 7F8C 8002CB8C 2463F430 */  addiu     $v1, $v1, -0xbd0
/* 7F90 8002CB90 02629823 */  subu      $s3, $s3, $v0
/* 7F94 8002CB94 0223102B */  sltu      $v0, $s1, $v1
/* 7F98 8002CB98 1040002B */  beqz      $v0, .L8002CC48
/* 7F9C 8002CB9C 241E0003 */   addiu    $fp, $zero, 3
/* 7FA0 8002CBA0 0060B82D */  daddu     $s7, $v1, $zero
.L8002CBA4:
/* 7FA4 8002CBA4 0220282D */  daddu     $a1, $s1, $zero
/* 7FA8 8002CBA8 3C04800A */  lui       $a0, %hi(nuPiCartHandle)
/* 7FAC 8002CBAC 8C84A618 */  lw        $a0, %lo(nuPiCartHandle)($a0)
/* 7FB0 8002CBB0 0280F809 */  jalr      $s4
/* 7FB4 8002CBB4 27A60014 */   addiu    $a2, $sp, 0x14
/* 7FB8 8002CBB8 8FA30014 */  lw        $v1, 0x14($sp)
/* 7FBC 8002CBBC 2407000F */  addiu     $a3, $zero, 0xf
/* 7FC0 8002CBC0 3065FFFF */  andi      $a1, $v1, 0xffff
/* 7FC4 8002CBC4 00032402 */  srl       $a0, $v1, 0x10
/* 7FC8 8002CBC8 00A41021 */  addu      $v0, $a1, $a0
/* 7FCC 8002CBCC 02028021 */  addu      $s0, $s0, $v0
/* 7FD0 8002CBD0 00121682 */  srl       $v0, $s2, 0x1a
/* 7FD4 8002CBD4 14470010 */  bne       $v0, $a3, .L8002CC18
/* 7FD8 8002CBD8 00031682 */   srl      $v0, $v1, 0x1a
/* 7FDC 8002CBDC 24070009 */  addiu     $a3, $zero, 9
/* 7FE0 8002CBE0 50470004 */  beql      $v0, $a3, .L8002CBF4
/* 7FE4 8002CBE4 00031542 */   srl      $v0, $v1, 0x15
/* 7FE8 8002CBE8 24070023 */  addiu     $a3, $zero, 0x23
/* 7FEC 8002CBEC 1447000A */  bne       $v0, $a3, .L8002CC18
/* 7FF0 8002CBF0 00031542 */   srl      $v0, $v1, 0x15
.L8002CBF4:
/* 7FF4 8002CBF4 3043001F */  andi      $v1, $v0, 0x1f
/* 7FF8 8002CBF8 00121402 */  srl       $v0, $s2, 0x10
/* 7FFC 8002CBFC 3042001F */  andi      $v0, $v0, 0x1f
/* 8000 8002CC00 14620005 */  bne       $v1, $v0, .L8002CC18
/* 8004 8002CC04 3082001F */   andi     $v0, $a0, 0x1f
/* 8008 8002CC08 14620003 */  bne       $v1, $v0, .L8002CC18
/* 800C 8002CC0C 3242FFFF */   andi     $v0, $s2, 0xffff
/* 8010 8002CC10 02058023 */  subu      $s0, $s0, $a1
/* 8014 8002CC14 02028023 */  subu      $s0, $s0, $v0
.L8002CC18:
/* 8018 8002CC18 8FA40014 */  lw        $a0, 0x14($sp)
/* 801C 8002CC1C 00041682 */  srl       $v0, $a0, 0x1a
/* 8020 8002CC20 145E0006 */  bne       $v0, $fp, .L8002CC3C
/* 8024 8002CC24 26310004 */   addiu    $s1, $s1, 4
/* 8028 8002CC28 3083FFFF */  andi      $v1, $a0, 0xffff
/* 802C 8002CC2C 00041402 */  srl       $v0, $a0, 0x10
/* 8030 8002CC30 3042FC00 */  andi      $v0, $v0, 0xfc00
/* 8034 8002CC34 00621821 */  addu      $v1, $v1, $v0
/* 8038 8002CC38 02038023 */  subu      $s0, $s0, $v1
.L8002CC3C:
/* 803C 8002CC3C 0237102B */  sltu      $v0, $s1, $s7
/* 8040 8002CC40 1440FFD8 */  bnez      $v0, .L8002CBA4
/* 8044 8002CC44 0080902D */   daddu    $s2, $a0, $zero
.L8002CC48:
/* 8048 8002CC48 3C04FFF1 */  lui       $a0, 0xfff1
/* 804C 8002CC4C 34842BE4 */  ori       $a0, $a0, 0x2be4
/* 8050 8002CC50 02042021 */  addu      $a0, $s0, $a0
/* 8054 8002CC54 02642023 */  subu      $a0, $s3, $a0
/* 8058 8002CC58 02A42021 */  addu      $a0, $s5, $a0
/* 805C 8002CC5C 3C050032 */  lui       $a1, 0x32
/* 8060 8002CC60 24A5F430 */  addiu     $a1, $a1, -0xbd0
/* 8064 8002CC64 0C00A5BF */  jal       func_800296FC
/* 8068 8002CC68 02C0302D */   daddu    $a2, $s6, $zero
/* 806C 8002CC6C 8FBF003C */  lw        $ra, 0x3c($sp)
/* 8070 8002CC70 8FBE0038 */  lw        $fp, 0x38($sp)
/* 8074 8002CC74 8FB70034 */  lw        $s7, 0x34($sp)
/* 8078 8002CC78 8FB60030 */  lw        $s6, 0x30($sp)
/* 807C 8002CC7C 8FB5002C */  lw        $s5, 0x2c($sp)
/* 8080 8002CC80 8FB40028 */  lw        $s4, 0x28($sp)
/* 8084 8002CC84 8FB30024 */  lw        $s3, 0x24($sp)
/* 8088 8002CC88 8FB20020 */  lw        $s2, 0x20($sp)
/* 808C 8002CC8C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 8090 8002CC90 8FB00018 */  lw        $s0, 0x18($sp)
/* 8094 8002CC94 03E00008 */  jr        $ra
/* 8098 8002CC98 27BD0040 */   addiu    $sp, $sp, 0x40
/* 809C 8002CC9C 00000000 */  nop
