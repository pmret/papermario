.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D6C_B7ADBC
/* B7ADBC 80240D6C 27BDFF90 */  addiu     $sp, $sp, -0x70
/* B7ADC0 80240D70 AFB40050 */  sw        $s4, 0x50($sp)
/* B7ADC4 80240D74 0080A02D */  daddu     $s4, $a0, $zero
/* B7ADC8 80240D78 AFBF0060 */  sw        $ra, 0x60($sp)
/* B7ADCC 80240D7C AFB7005C */  sw        $s7, 0x5c($sp)
/* B7ADD0 80240D80 AFB60058 */  sw        $s6, 0x58($sp)
/* B7ADD4 80240D84 AFB50054 */  sw        $s5, 0x54($sp)
/* B7ADD8 80240D88 AFB3004C */  sw        $s3, 0x4c($sp)
/* B7ADDC 80240D8C AFB20048 */  sw        $s2, 0x48($sp)
/* B7ADE0 80240D90 AFB10044 */  sw        $s1, 0x44($sp)
/* B7ADE4 80240D94 AFB00040 */  sw        $s0, 0x40($sp)
/* B7ADE8 80240D98 F7B40068 */  sdc1      $f20, 0x68($sp)
/* B7ADEC 80240D9C 8E950148 */  lw        $s5, 0x148($s4)
/* B7ADF0 80240DA0 00A0B02D */  daddu     $s6, $a1, $zero
/* B7ADF4 80240DA4 86A40008 */  lh        $a0, 8($s5)
/* B7ADF8 80240DA8 0C00EABB */  jal       get_npc_unsafe
/* B7ADFC 80240DAC 00C0B82D */   daddu    $s7, $a2, $zero
/* B7AE00 80240DB0 0040982D */  daddu     $s3, $v0, $zero
/* B7AE04 80240DB4 C6600018 */  lwc1      $f0, 0x18($s3)
/* B7AE08 80240DB8 44801000 */  mtc1      $zero, $f2
/* B7AE0C 80240DBC 44801800 */  mtc1      $zero, $f3
/* B7AE10 80240DC0 46000021 */  cvt.d.s   $f0, $f0
/* B7AE14 80240DC4 4620103C */  c.lt.d    $f2, $f0
/* B7AE18 80240DC8 00000000 */  nop
/* B7AE1C 80240DCC 45000021 */  bc1f      .L80240E54
/* B7AE20 80240DD0 27A50028 */   addiu    $a1, $sp, 0x28
/* B7AE24 80240DD4 C6600038 */  lwc1      $f0, 0x38($s3)
/* B7AE28 80240DD8 C662003C */  lwc1      $f2, 0x3c($s3)
/* B7AE2C 80240DDC C6640040 */  lwc1      $f4, 0x40($s3)
/* B7AE30 80240DE0 C6660018 */  lwc1      $f6, 0x18($s3)
/* B7AE34 80240DE4 E7A00028 */  swc1      $f0, 0x28($sp)
/* B7AE38 80240DE8 E7A2002C */  swc1      $f2, 0x2c($sp)
/* B7AE3C 80240DEC E7A40030 */  swc1      $f4, 0x30($sp)
/* B7AE40 80240DF0 E7A60010 */  swc1      $f6, 0x10($sp)
/* B7AE44 80240DF4 C660000C */  lwc1      $f0, 0xc($s3)
/* B7AE48 80240DF8 E7A00014 */  swc1      $f0, 0x14($sp)
/* B7AE4C 80240DFC 866200A8 */  lh        $v0, 0xa8($s3)
/* B7AE50 80240E00 44820000 */  mtc1      $v0, $f0
/* B7AE54 80240E04 00000000 */  nop
/* B7AE58 80240E08 46800020 */  cvt.s.w   $f0, $f0
/* B7AE5C 80240E0C E7A00018 */  swc1      $f0, 0x18($sp)
/* B7AE60 80240E10 866200A6 */  lh        $v0, 0xa6($s3)
/* B7AE64 80240E14 27A6002C */  addiu     $a2, $sp, 0x2c
/* B7AE68 80240E18 44820000 */  mtc1      $v0, $f0
/* B7AE6C 80240E1C 00000000 */  nop
/* B7AE70 80240E20 46800020 */  cvt.s.w   $f0, $f0
/* B7AE74 80240E24 E7A0001C */  swc1      $f0, 0x1c($sp)
/* B7AE78 80240E28 8E640080 */  lw        $a0, 0x80($s3)
/* B7AE7C 80240E2C 0C037711 */  jal       func_800DDC44
/* B7AE80 80240E30 27A70030 */   addiu    $a3, $sp, 0x30
/* B7AE84 80240E34 10400003 */  beqz      $v0, .L80240E44
/* B7AE88 80240E38 00000000 */   nop
/* B7AE8C 80240E3C 08090395 */  j         .L80240E54
/* B7AE90 80240E40 AE600018 */   sw       $zero, 0x18($s3)
.L80240E44:
/* B7AE94 80240E44 8E650018 */  lw        $a1, 0x18($s3)
/* B7AE98 80240E48 8E66000C */  lw        $a2, 0xc($s3)
/* B7AE9C 80240E4C 0C00EA95 */  jal       npc_move_heading
/* B7AEA0 80240E50 0260202D */   daddu    $a0, $s3, $zero
.L80240E54:
/* B7AEA4 80240E54 C660001C */  lwc1      $f0, 0x1c($s3)
/* B7AEA8 80240E58 44801000 */  mtc1      $zero, $f2
/* B7AEAC 80240E5C 44801800 */  mtc1      $zero, $f3
/* B7AEB0 80240E60 46000021 */  cvt.d.s   $f0, $f0
/* B7AEB4 80240E64 4622003C */  c.lt.d    $f0, $f2
/* B7AEB8 80240E68 00000000 */  nop
/* B7AEBC 80240E6C 4500006C */  bc1f      .L80241020
/* B7AEC0 80240E70 27B00028 */   addiu    $s0, $sp, 0x28
/* B7AEC4 80240E74 0200282D */  daddu     $a1, $s0, $zero
/* B7AEC8 80240E78 27A60034 */  addiu     $a2, $sp, 0x34
/* B7AECC 80240E7C 27B20038 */  addiu     $s2, $sp, 0x38
/* B7AED0 80240E80 C6600038 */  lwc1      $f0, 0x38($s3)
/* B7AED4 80240E84 3C0142C8 */  lui       $at, 0x42c8
/* B7AED8 80240E88 44811000 */  mtc1      $at, $f2
/* B7AEDC 80240E8C C6640040 */  lwc1      $f4, 0x40($s3)
/* B7AEE0 80240E90 3C01447A */  lui       $at, 0x447a
/* B7AEE4 80240E94 44813000 */  mtc1      $at, $f6
/* B7AEE8 80240E98 27B10030 */  addiu     $s1, $sp, 0x30
/* B7AEEC 80240E9C E7A00028 */  swc1      $f0, 0x28($sp)
/* B7AEF0 80240EA0 E7A20034 */  swc1      $f2, 0x34($sp)
/* B7AEF4 80240EA4 E7A40030 */  swc1      $f4, 0x30($sp)
/* B7AEF8 80240EA8 E7A60038 */  swc1      $f6, 0x38($sp)
/* B7AEFC 80240EAC AFB20010 */  sw        $s2, 0x10($sp)
/* B7AF00 80240EB0 8E640080 */  lw        $a0, 0x80($s3)
/* B7AF04 80240EB4 0C0372DF */  jal       func_800DCB7C
/* B7AF08 80240EB8 0220382D */   daddu    $a3, $s1, $zero
/* B7AF0C 80240EBC 0200282D */  daddu     $a1, $s0, $zero
/* B7AF10 80240EC0 27A6002C */  addiu     $a2, $sp, 0x2c
/* B7AF14 80240EC4 C662003C */  lwc1      $f2, 0x3c($s3)
/* B7AF18 80240EC8 C6660038 */  lwc1      $f6, 0x38($s3)
/* B7AF1C 80240ECC 3C01402A */  lui       $at, 0x402a
/* B7AF20 80240ED0 4481A800 */  mtc1      $at, $f21
/* B7AF24 80240ED4 4480A000 */  mtc1      $zero, $f20
/* B7AF28 80240ED8 460010A1 */  cvt.d.s   $f2, $f2
/* B7AF2C 80240EDC 46341080 */  add.d     $f2, $f2, $f20
/* B7AF30 80240EE0 C660001C */  lwc1      $f0, 0x1c($s3)
/* B7AF34 80240EE4 C6640040 */  lwc1      $f4, 0x40($s3)
/* B7AF38 80240EE8 46000005 */  abs.s     $f0, $f0
/* B7AF3C 80240EEC E7A40030 */  swc1      $f4, 0x30($sp)
/* B7AF40 80240EF0 3C014030 */  lui       $at, 0x4030
/* B7AF44 80240EF4 44812800 */  mtc1      $at, $f5
/* B7AF48 80240EF8 44802000 */  mtc1      $zero, $f4
/* B7AF4C 80240EFC 46000021 */  cvt.d.s   $f0, $f0
/* B7AF50 80240F00 E7A60028 */  swc1      $f6, 0x28($sp)
/* B7AF54 80240F04 46240000 */  add.d     $f0, $f0, $f4
/* B7AF58 80240F08 462010A0 */  cvt.s.d   $f2, $f2
/* B7AF5C 80240F0C E7A2002C */  swc1      $f2, 0x2c($sp)
/* B7AF60 80240F10 46200020 */  cvt.s.d   $f0, $f0
/* B7AF64 80240F14 E7A00038 */  swc1      $f0, 0x38($sp)
/* B7AF68 80240F18 AFB20010 */  sw        $s2, 0x10($sp)
/* B7AF6C 80240F1C 8E640080 */  lw        $a0, 0x80($s3)
/* B7AF70 80240F20 0C0372DF */  jal       func_800DCB7C
/* B7AF74 80240F24 0220382D */   daddu    $a3, $s1, $zero
/* B7AF78 80240F28 1040003D */  beqz      $v0, .L80241020
/* B7AF7C 80240F2C 00000000 */   nop
/* B7AF80 80240F30 C660001C */  lwc1      $f0, 0x1c($s3)
/* B7AF84 80240F34 C7A20038 */  lwc1      $f2, 0x38($sp)
/* B7AF88 80240F38 46000005 */  abs.s     $f0, $f0
/* B7AF8C 80240F3C 46000021 */  cvt.d.s   $f0, $f0
/* B7AF90 80240F40 46340000 */  add.d     $f0, $f0, $f20
/* B7AF94 80240F44 460010A1 */  cvt.d.s   $f2, $f2
/* B7AF98 80240F48 4620103E */  c.le.d    $f2, $f0
/* B7AF9C 80240F4C 00000000 */  nop
/* B7AFA0 80240F50 45000033 */  bc1f      .L80241020
/* B7AFA4 80240F54 2403F7FF */   addiu    $v1, $zero, -0x801
/* B7AFA8 80240F58 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* B7AFAC 80240F5C 8E620000 */  lw        $v0, ($s3)
/* B7AFB0 80240F60 AE60001C */  sw        $zero, 0x1c($s3)
/* B7AFB4 80240F64 00431024 */  and       $v0, $v0, $v1
/* B7AFB8 80240F68 E660003C */  swc1      $f0, 0x3c($s3)
/* B7AFBC 80240F6C AE620000 */  sw        $v0, ($s3)
/* B7AFC0 80240F70 AFA00010 */  sw        $zero, 0x10($sp)
/* B7AFC4 80240F74 AFA00014 */  sw        $zero, 0x14($sp)
/* B7AFC8 80240F78 8E650038 */  lw        $a1, 0x38($s3)
/* B7AFCC 80240F7C 8E66003C */  lw        $a2, 0x3c($s3)
/* B7AFD0 80240F80 8E670040 */  lw        $a3, 0x40($s3)
/* B7AFD4 80240F84 0C01BECC */  jal       fx_walk_normal
/* B7AFD8 80240F88 24040002 */   addiu    $a0, $zero, 2
/* B7AFDC 80240F8C 02E0202D */  daddu     $a0, $s7, $zero
/* B7AFE0 80240F90 2402000C */  addiu     $v0, $zero, 0xc
/* B7AFE4 80240F94 AE820070 */  sw        $v0, 0x70($s4)
/* B7AFE8 80240F98 24020001 */  addiu     $v0, $zero, 1
/* B7AFEC 80240F9C AFA20010 */  sw        $v0, 0x10($sp)
/* B7AFF0 80240FA0 8EC60024 */  lw        $a2, 0x24($s6)
/* B7AFF4 80240FA4 8EC70028 */  lw        $a3, 0x28($s6)
/* B7AFF8 80240FA8 0C01242D */  jal       func_800490B4
/* B7AFFC 80240FAC 02A0282D */   daddu    $a1, $s5, $zero
/* B7B000 80240FB0 14400022 */  bnez      $v0, .L8024103C
/* B7B004 80240FB4 24040002 */   addiu    $a0, $zero, 2
/* B7B008 80240FB8 0260282D */  daddu     $a1, $s3, $zero
/* B7B00C 80240FBC 0000302D */  daddu     $a2, $zero, $zero
/* B7B010 80240FC0 866300A8 */  lh        $v1, 0xa8($s3)
/* B7B014 80240FC4 3C013F80 */  lui       $at, 0x3f80
/* B7B018 80240FC8 44810000 */  mtc1      $at, $f0
/* B7B01C 80240FCC 3C014000 */  lui       $at, 0x4000
/* B7B020 80240FD0 44811000 */  mtc1      $at, $f2
/* B7B024 80240FD4 3C01C1A0 */  lui       $at, 0xc1a0
/* B7B028 80240FD8 44812000 */  mtc1      $at, $f4
/* B7B02C 80240FDC 2402000F */  addiu     $v0, $zero, 0xf
/* B7B030 80240FE0 AFA2001C */  sw        $v0, 0x1c($sp)
/* B7B034 80240FE4 44834000 */  mtc1      $v1, $f8
/* B7B038 80240FE8 00000000 */  nop
/* B7B03C 80240FEC 46804220 */  cvt.s.w   $f8, $f8
/* B7B040 80240FF0 44074000 */  mfc1      $a3, $f8
/* B7B044 80240FF4 27A2003C */  addiu     $v0, $sp, 0x3c
/* B7B048 80240FF8 AFA20020 */  sw        $v0, 0x20($sp)
/* B7B04C 80240FFC E7A00010 */  swc1      $f0, 0x10($sp)
/* B7B050 80241000 E7A20014 */  swc1      $f2, 0x14($sp)
/* B7B054 80241004 0C01BFA4 */  jal       fx_emote
/* B7B058 80241008 E7A40018 */   swc1     $f4, 0x18($sp)
/* B7B05C 8024100C 24020019 */  addiu     $v0, $zero, 0x19
/* B7B060 80241010 A662008E */  sh        $v0, 0x8e($s3)
/* B7B064 80241014 2402000E */  addiu     $v0, $zero, 0xe
/* B7B068 80241018 0809040F */  j         .L8024103C
/* B7B06C 8024101C AE820070 */   sw       $v0, 0x70($s4)
.L80241020:
/* B7B070 80241020 C664003C */  lwc1      $f4, 0x3c($s3)
/* B7B074 80241024 C660001C */  lwc1      $f0, 0x1c($s3)
/* B7B078 80241028 46002100 */  add.s     $f4, $f4, $f0
/* B7B07C 8024102C C6620014 */  lwc1      $f2, 0x14($s3)
/* B7B080 80241030 46020001 */  sub.s     $f0, $f0, $f2
/* B7B084 80241034 E664003C */  swc1      $f4, 0x3c($s3)
/* B7B088 80241038 E660001C */  swc1      $f0, 0x1c($s3)
.L8024103C:
/* B7B08C 8024103C 8FBF0060 */  lw        $ra, 0x60($sp)
/* B7B090 80241040 8FB7005C */  lw        $s7, 0x5c($sp)
/* B7B094 80241044 8FB60058 */  lw        $s6, 0x58($sp)
/* B7B098 80241048 8FB50054 */  lw        $s5, 0x54($sp)
/* B7B09C 8024104C 8FB40050 */  lw        $s4, 0x50($sp)
/* B7B0A0 80241050 8FB3004C */  lw        $s3, 0x4c($sp)
/* B7B0A4 80241054 8FB20048 */  lw        $s2, 0x48($sp)
/* B7B0A8 80241058 8FB10044 */  lw        $s1, 0x44($sp)
/* B7B0AC 8024105C 8FB00040 */  lw        $s0, 0x40($sp)
/* B7B0B0 80241060 D7B40068 */  ldc1      $f20, 0x68($sp)
/* B7B0B4 80241064 03E00008 */  jr        $ra
/* B7B0B8 80241068 27BD0070 */   addiu    $sp, $sp, 0x70
