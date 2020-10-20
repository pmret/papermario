.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BB0_E16930
/* E16930 80240BB0 27BDFF18 */  addiu     $sp, $sp, -0xe8
/* E16934 80240BB4 0000202D */  daddu     $a0, $zero, $zero
/* E16938 80240BB8 AFBF00B4 */  sw        $ra, 0xb4($sp)
/* E1693C 80240BBC AFBE00B0 */  sw        $fp, 0xb0($sp)
/* E16940 80240BC0 AFB700AC */  sw        $s7, 0xac($sp)
/* E16944 80240BC4 AFB600A8 */  sw        $s6, 0xa8($sp)
/* E16948 80240BC8 AFB500A4 */  sw        $s5, 0xa4($sp)
/* E1694C 80240BCC AFB400A0 */  sw        $s4, 0xa0($sp)
/* E16950 80240BD0 AFB3009C */  sw        $s3, 0x9c($sp)
/* E16954 80240BD4 AFB20098 */  sw        $s2, 0x98($sp)
/* E16958 80240BD8 AFB10094 */  sw        $s1, 0x94($sp)
/* E1695C 80240BDC AFB00090 */  sw        $s0, 0x90($sp)
/* E16960 80240BE0 F7BE00E0 */  sdc1      $f30, 0xe0($sp)
/* E16964 80240BE4 F7BC00D8 */  sdc1      $f28, 0xd8($sp)
/* E16968 80240BE8 F7BA00D0 */  sdc1      $f26, 0xd0($sp)
/* E1696C 80240BEC F7B800C8 */  sdc1      $f24, 0xc8($sp)
/* E16970 80240BF0 F7B600C0 */  sdc1      $f22, 0xc0($sp)
/* E16974 80240BF4 F7B400B8 */  sdc1      $f20, 0xb8($sp)
/* E16978 80240BF8 AFA00084 */  sw        $zero, 0x84($sp)
/* E1697C 80240BFC 0C00FB3A */  jal       get_enemy
/* E16980 80240C00 AFA00088 */   sw       $zero, 0x88($sp)
/* E16984 80240C04 27BE0074 */  addiu     $fp, $sp, 0x74
/* E16988 80240C08 27B60078 */  addiu     $s6, $sp, 0x78
/* E1698C 80240C0C 27B7007C */  addiu     $s7, $sp, 0x7c
/* E16990 80240C10 3C01C47A */  lui       $at, 0xc47a
/* E16994 80240C14 4481D000 */  mtc1      $at, $f26
/* E16998 80240C18 3C014000 */  lui       $at, 0x4000
/* E1699C 80240C1C 4481C800 */  mtc1      $at, $f25
/* E169A0 80240C20 4480C000 */  mtc1      $zero, $f24
/* E169A4 80240C24 4480E000 */  mtc1      $zero, $f28
/* E169A8 80240C28 3C014000 */  lui       $at, 0x4000
/* E169AC 80240C2C 4481F000 */  mtc1      $at, $f30
/* E169B0 80240C30 3C014120 */  lui       $at, 0x4120
/* E169B4 80240C34 4481B000 */  mtc1      $at, $f22
/* E169B8 80240C38 8C55006C */  lw        $s5, 0x6c($v0)
/* E169BC 80240C3C 3C014024 */  lui       $at, 0x4024
/* E169C0 80240C40 4481A800 */  mtc1      $at, $f21
/* E169C4 80240C44 4480A000 */  mtc1      $zero, $f20
/* E169C8 80240C48 02A0A02D */  daddu     $s4, $s5, $zero
.L80240C4C:
/* E169CC 80240C4C 8E840040 */  lw        $a0, 0x40($s4)
/* E169D0 80240C50 2402FFFF */  addiu     $v0, $zero, -1
/* E169D4 80240C54 108203B2 */  beq       $a0, $v0, .L80241B20
/* E169D8 80240C58 24020032 */   addiu    $v0, $zero, 0x32
/* E169DC 80240C5C 0C00FB3A */  jal       get_enemy
/* E169E0 80240C60 00000000 */   nop      
/* E169E4 80240C64 84440008 */  lh        $a0, 8($v0)
/* E169E8 80240C68 0C00EABB */  jal       get_npc_unsafe
/* E169EC 80240C6C 0040802D */   daddu    $s0, $v0, $zero
/* E169F0 80240C70 8E83002C */  lw        $v1, 0x2c($s4)
/* E169F4 80240C74 0040982D */  daddu     $s3, $v0, $zero
/* E169F8 80240C78 2463FFF6 */  addiu     $v1, $v1, -0xa
/* E169FC 80240C7C 2C620042 */  sltiu     $v0, $v1, 0x42
/* E16A00 80240C80 104003AD */  beqz      $v0, .L80241B38
/* E16A04 80240C84 00031080 */   sll      $v0, $v1, 2
/* E16A08 80240C88 3C018025 */  lui       $at, 0x8025
/* E16A0C 80240C8C 00220821 */  addu      $at, $at, $v0
/* E16A10 80240C90 8C2284E8 */  lw        $v0, -0x7b18($at)
/* E16A14 80240C94 00400008 */  jr        $v0
/* E16A18 80240C98 00000000 */   nop      
/* E16A1C 80240C9C 240400D2 */  addiu     $a0, $zero, 0xd2
/* E16A20 80240CA0 2402000B */  addiu     $v0, $zero, 0xb
/* E16A24 80240CA4 0C00A67F */  jal       rand_int
/* E16A28 80240CA8 AE82002C */   sw       $v0, 0x2c($s4)
/* E16A2C 80240CAC 0260202D */  daddu     $a0, $s3, $zero
/* E16A30 80240CB0 AE820030 */  sw        $v0, 0x30($s4)
/* E16A34 80240CB4 8E620000 */  lw        $v0, ($s3)
/* E16A38 80240CB8 2403FFFD */  addiu     $v1, $zero, -3
/* E16A3C 80240CBC E67A003C */  swc1      $f26, 0x3c($s3)
/* E16A40 80240CC0 00431024 */  and       $v0, $v0, $v1
/* E16A44 80240CC4 0C00EAFF */  jal       disable_npc_shadow
/* E16A48 80240CC8 AE620000 */   sw       $v0, ($s3)
/* E16A4C 80240CCC 8E820030 */  lw        $v0, 0x30($s4)
/* E16A50 80240CD0 2442FFFF */  addiu     $v0, $v0, -1
/* E16A54 80240CD4 1C400398 */  bgtz      $v0, .L80241B38
/* E16A58 80240CD8 AE820030 */   sw       $v0, 0x30($s4)
/* E16A5C 80240CDC 3C02002B */  lui       $v0, 0x2b
/* E16A60 80240CE0 34420002 */  ori       $v0, $v0, 2
/* E16A64 80240CE4 AE620028 */  sw        $v0, 0x28($s3)
/* E16A68 80240CE8 2402000C */  addiu     $v0, $zero, 0xc
/* E16A6C 80240CEC AE82002C */  sw        $v0, 0x2c($s4)
/* E16A70 80240CF0 C6600040 */  lwc1      $f0, 0x40($s3)
/* E16A74 80240CF4 E7A00010 */  swc1      $f0, 0x10($sp)
/* E16A78 80240CF8 8E04008C */  lw        $a0, 0x8c($s0)
/* E16A7C 80240CFC 8E660038 */  lw        $a2, 0x38($s3)
/* E16A80 80240D00 8E67003C */  lw        $a3, 0x3c($s3)
/* E16A84 80240D04 0C052757 */  jal       play_sound_at_position
/* E16A88 80240D08 3C050010 */   lui      $a1, 0x10
/* E16A8C 80240D0C 27A50068 */  addiu     $a1, $sp, 0x68
/* E16A90 80240D10 27A6006C */  addiu     $a2, $sp, 0x6c
/* E16A94 80240D14 9684003A */  lhu       $a0, 0x3a($s4)
/* E16A98 80240D18 27A70070 */  addiu     $a3, $sp, 0x70
/* E16A9C 80240D1C AFBE0010 */  sw        $fp, 0x10($sp)
/* E16AA0 80240D20 AFB60014 */  sw        $s6, 0x14($sp)
/* E16AA4 80240D24 0C046C3B */  jal       get_model_center_and_size
/* E16AA8 80240D28 AFB70018 */   sw       $s7, 0x18($sp)
/* E16AAC 80240D2C 3C014128 */  lui       $at, 0x4128
/* E16AB0 80240D30 44810000 */  mtc1      $at, $f0
/* E16AB4 80240D34 C7A40068 */  lwc1      $f4, 0x68($sp)
/* E16AB8 80240D38 C7A2006C */  lwc1      $f2, 0x6c($sp)
/* E16ABC 80240D3C E660001C */  swc1      $f0, 0x1c($s3)
/* E16AC0 80240D40 3C014029 */  lui       $at, 0x4029
/* E16AC4 80240D44 44810800 */  mtc1      $at, $f1
/* E16AC8 80240D48 44800000 */  mtc1      $zero, $f0
/* E16ACC 80240D4C 460010A1 */  cvt.d.s   $f2, $f2
/* E16AD0 80240D50 E6640038 */  swc1      $f4, 0x38($s3)
/* E16AD4 80240D54 3C013FC0 */  lui       $at, 0x3fc0
/* E16AD8 80240D58 44812000 */  mtc1      $at, $f4
/* E16ADC 80240D5C 46201081 */  sub.d     $f2, $f2, $f0
/* E16AE0 80240D60 E6640014 */  swc1      $f4, 0x14($s3)
/* E16AE4 80240D64 C7A00070 */  lwc1      $f0, 0x70($sp)
/* E16AE8 80240D68 46000021 */  cvt.d.s   $f0, $f0
/* E16AEC 80240D6C 46380000 */  add.d     $f0, $f0, $f24
/* E16AF0 80240D70 462010A0 */  cvt.s.d   $f2, $f2
/* E16AF4 80240D74 E662003C */  swc1      $f2, 0x3c($s3)
/* E16AF8 80240D78 E6620064 */  swc1      $f2, 0x64($s3)
/* E16AFC 80240D7C 46200020 */  cvt.s.d   $f0, $f0
/* E16B00 80240D80 080906CD */  j         .L80241B34
/* E16B04 80240D84 E6600040 */   swc1     $f0, 0x40($s3)
/* E16B08 80240D88 8E820030 */  lw        $v0, 0x30($s4)
/* E16B0C 80240D8C 24420001 */  addiu     $v0, $v0, 1
/* E16B10 80240D90 AE820030 */  sw        $v0, 0x30($s4)
/* E16B14 80240D94 C660001C */  lwc1      $f0, 0x1c($s3)
/* E16B18 80240D98 C664003C */  lwc1      $f4, 0x3c($s3)
/* E16B1C 80240D9C 46000186 */  mov.s     $f6, $f0
/* E16B20 80240DA0 46002100 */  add.s     $f4, $f4, $f0
/* E16B24 80240DA4 C6600014 */  lwc1      $f0, 0x14($s3)
/* E16B28 80240DA8 3C0141A0 */  lui       $at, 0x41a0
/* E16B2C 80240DAC 44811000 */  mtc1      $at, $f2
/* E16B30 80240DB0 46003181 */  sub.s     $f6, $f6, $f0
/* E16B34 80240DB4 C6600064 */  lwc1      $f0, 0x64($s3)
/* E16B38 80240DB8 46020000 */  add.s     $f0, $f0, $f2
/* E16B3C 80240DBC E664003C */  swc1      $f4, 0x3c($s3)
/* E16B40 80240DC0 46002086 */  mov.s     $f2, $f4
/* E16B44 80240DC4 4602003C */  c.lt.s    $f0, $f2
/* E16B48 80240DC8 00000000 */  nop       
/* E16B4C 80240DCC 45000005 */  bc1f      .L80240DE4
/* E16B50 80240DD0 E666001C */   swc1     $f6, 0x1c($s3)
/* E16B54 80240DD4 0C00EAE8 */  jal       enable_npc_shadow
/* E16B58 80240DD8 0260202D */   daddu    $a0, $s3, $zero
/* E16B5C 80240DDC 0809037B */  j         .L80240DEC
/* E16B60 80240DE0 00000000 */   nop      
.L80240DE4:
/* E16B64 80240DE4 0C00EAFF */  jal       disable_npc_shadow
/* E16B68 80240DE8 0260202D */   daddu    $a0, $s3, $zero
.L80240DEC:
/* E16B6C 80240DEC C660001C */  lwc1      $f0, 0x1c($s3)
/* E16B70 80240DF0 44801000 */  mtc1      $zero, $f2
/* E16B74 80240DF4 44801800 */  mtc1      $zero, $f3
/* E16B78 80240DF8 46000021 */  cvt.d.s   $f0, $f0
/* E16B7C 80240DFC 4622003C */  c.lt.d    $f0, $f2
/* E16B80 80240E00 00000000 */  nop       
/* E16B84 80240E04 4502034D */  bc1fl     .L80241B3C
/* E16B88 80240E08 2694001C */   addiu    $s4, $s4, 0x1c
/* E16B8C 80240E0C C662003C */  lwc1      $f2, 0x3c($s3)
/* E16B90 80240E10 C6600064 */  lwc1      $f0, 0x64($s3)
/* E16B94 80240E14 4600103E */  c.le.s    $f2, $f0
/* E16B98 80240E18 00000000 */  nop       
/* E16B9C 80240E1C 45000346 */  bc1f      .L80241B38
/* E16BA0 80240E20 2404014A */   addiu    $a0, $zero, 0x14a
/* E16BA4 80240E24 2402000B */  addiu     $v0, $zero, 0xb
/* E16BA8 80240E28 0C00A67F */  jal       rand_int
/* E16BAC 80240E2C AE82002C */   sw       $v0, 0x2c($s4)
/* E16BB0 80240E30 24040064 */  addiu     $a0, $zero, 0x64
/* E16BB4 80240E34 2442005A */  addiu     $v0, $v0, 0x5a
/* E16BB8 80240E38 AE820030 */  sw        $v0, 0x30($s4)
/* E16BBC 80240E3C 0C00A67F */  jal       rand_int
/* E16BC0 80240E40 E67A003C */   swc1     $f26, 0x3c($s3)
/* E16BC4 80240E44 28420032 */  slti      $v0, $v0, 0x32
/* E16BC8 80240E48 104001B0 */  beqz      $v0, .L8024150C
/* E16BCC 80240E4C 00000000 */   nop      
/* E16BD0 80240E50 3C014387 */  lui       $at, 0x4387
/* E16BD4 80240E54 44810000 */  mtc1      $at, $f0
/* E16BD8 80240E58 08090547 */  j         .L8024151C
/* E16BDC 80240E5C E660000C */   swc1     $f0, 0xc($s3)
/* E16BE0 80240E60 8EA4000C */  lw        $a0, 0xc($s5)
/* E16BE4 80240E64 3C058011 */  lui       $a1, 0x8011
/* E16BE8 80240E68 24A58B28 */  addiu     $a1, $a1, -0x74d8
/* E16BEC 80240E6C 0C0511FF */  jal       set_menu_icon_script
/* E16BF0 80240E70 00000000 */   nop      
/* E16BF4 80240E74 8EA4000C */  lw        $a0, 0xc($s5)
/* E16BF8 80240E78 0C0513AC */  jal       icon_set_opacity
/* E16BFC 80240E7C 240500A0 */   addiu    $a1, $zero, 0xa0
/* E16C00 80240E80 8EA40010 */  lw        $a0, 0x10($s5)
/* E16C04 80240E84 0C0513AC */  jal       icon_set_opacity
/* E16C08 80240E88 240500A0 */   addiu    $a1, $zero, 0xa0
/* E16C0C 80240E8C 8EA20028 */  lw        $v0, 0x28($s5)
/* E16C10 80240E90 0260202D */  daddu     $a0, $s3, $zero
/* E16C14 80240E94 AEA00024 */  sw        $zero, 0x24($s5)
/* E16C18 80240E98 34420004 */  ori       $v0, $v0, 4
/* E16C1C 80240E9C 0C00EAE8 */  jal       enable_npc_shadow
/* E16C20 80240EA0 AEA20028 */   sw       $v0, 0x28($s5)
/* E16C24 80240EA4 8EA20028 */  lw        $v0, 0x28($s5)
/* E16C28 80240EA8 34420003 */  ori       $v0, $v0, 3
/* E16C2C 80240EAC AEA20028 */  sw        $v0, 0x28($s5)
/* E16C30 80240EB0 24020008 */  addiu     $v0, $zero, 8
/* E16C34 80240EB4 A662008E */  sh        $v0, 0x8e($s3)
/* E16C38 80240EB8 0C05272D */  jal       play_sound
/* E16C3C 80240EBC 8E04008C */   lw       $a0, 0x8c($s0)
/* E16C40 80240EC0 3C070001 */  lui       $a3, 1
/* E16C44 80240EC4 34E70001 */  ori       $a3, $a3, 1
/* E16C48 80240EC8 3C04002B */  lui       $a0, 0x2b
/* E16C4C 80240ECC 34840003 */  ori       $a0, $a0, 3
/* E16C50 80240ED0 27A50068 */  addiu     $a1, $sp, 0x68
/* E16C54 80240ED4 27A6006C */  addiu     $a2, $sp, 0x6c
/* E16C58 80240ED8 3C03800F */  lui       $v1, %hi(gPlayerStatusPtr)
/* E16C5C 80240EDC 8C637B30 */  lw        $v1, %lo(gPlayerStatusPtr)($v1)
/* E16C60 80240EE0 2402000E */  addiu     $v0, $zero, 0xe
/* E16C64 80240EE4 AE82002C */  sw        $v0, 0x2c($s4)
/* E16C68 80240EE8 AC6700B8 */  sw        $a3, 0xb8($v1)
/* E16C6C 80240EEC AE640028 */  sw        $a0, 0x28($s3)
/* E16C70 80240EF0 9684003A */  lhu       $a0, 0x3a($s4)
/* E16C74 80240EF4 27A70070 */  addiu     $a3, $sp, 0x70
/* E16C78 80240EF8 AFBE0010 */  sw        $fp, 0x10($sp)
/* E16C7C 80240EFC AFB60014 */  sw        $s6, 0x14($sp)
/* E16C80 80240F00 0C046C3B */  jal       get_model_center_and_size
/* E16C84 80240F04 AFB70018 */   sw       $s7, 0x18($sp)
/* E16C88 80240F08 0000202D */  daddu     $a0, $zero, $zero
/* E16C8C 80240F0C 0260282D */  daddu     $a1, $s3, $zero
/* E16C90 80240F10 4406E000 */  mfc1      $a2, $f28
/* E16C94 80240F14 C7A20068 */  lwc1      $f2, 0x68($sp)
/* E16C98 80240F18 C7A00070 */  lwc1      $f0, 0x70($sp)
/* E16C9C 80240F1C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* E16CA0 80240F20 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* E16CA4 80240F24 3C014128 */  lui       $at, 0x4128
/* E16CA8 80240F28 44812000 */  mtc1      $at, $f4
/* E16CAC 80240F2C 46000021 */  cvt.d.s   $f0, $f0
/* E16CB0 80240F30 E6620038 */  swc1      $f2, 0x38($s3)
/* E16CB4 80240F34 C7A2006C */  lwc1      $f2, 0x6c($sp)
/* E16CB8 80240F38 46380000 */  add.d     $f0, $f0, $f24
/* E16CBC 80240F3C E662003C */  swc1      $f2, 0x3c($s3)
/* E16CC0 80240F40 3C01420C */  lui       $at, 0x420c
/* E16CC4 80240F44 44811000 */  mtc1      $at, $f2
/* E16CC8 80240F48 46200020 */  cvt.s.d   $f0, $f0
/* E16CCC 80240F4C E6600040 */  swc1      $f0, 0x40($s3)
/* E16CD0 80240F50 C440002C */  lwc1      $f0, 0x2c($v0)
/* E16CD4 80240F54 3C013FC0 */  lui       $at, 0x3fc0
/* E16CD8 80240F58 44813000 */  mtc1      $at, $f6
/* E16CDC 80240F5C 46020000 */  add.s     $f0, $f0, $f2
/* E16CE0 80240F60 E664001C */  swc1      $f4, 0x1c($s3)
/* E16CE4 80240F64 E6660014 */  swc1      $f6, 0x14($s3)
/* E16CE8 80240F68 E6600064 */  swc1      $f0, 0x64($s3)
/* E16CEC 80240F6C AE800030 */  sw        $zero, 0x30($s4)
/* E16CF0 80240F70 866300A8 */  lh        $v1, 0xa8($s3)
/* E16CF4 80240F74 3C013F80 */  lui       $at, 0x3f80
/* E16CF8 80240F78 44810000 */  mtc1      $at, $f0
/* E16CFC 80240F7C 2402000A */  addiu     $v0, $zero, 0xa
/* E16D00 80240F80 AFA2001C */  sw        $v0, 0x1c($sp)
/* E16D04 80240F84 44834000 */  mtc1      $v1, $f8
/* E16D08 80240F88 00000000 */  nop       
/* E16D0C 80240F8C 46804220 */  cvt.s.w   $f8, $f8
/* E16D10 80240F90 44074000 */  mfc1      $a3, $f8
/* E16D14 80240F94 27A20080 */  addiu     $v0, $sp, 0x80
/* E16D18 80240F98 E7BE0014 */  swc1      $f30, 0x14($sp)
/* E16D1C 80240F9C E7BC0018 */  swc1      $f28, 0x18($sp)
/* E16D20 80240FA0 AFA20020 */  sw        $v0, 0x20($sp)
/* E16D24 80240FA4 0C01BFA4 */  jal       fx_emote
/* E16D28 80240FA8 E7A00010 */   swc1     $f0, 0x10($sp)
/* E16D2C 80240FAC C6600038 */  lwc1      $f0, 0x38($s3)
/* E16D30 80240FB0 46160002 */  mul.s     $f0, $f0, $f22
/* E16D34 80240FB4 00000000 */  nop       
/* E16D38 80240FB8 4600020D */  trunc.w.s $f8, $f0
/* E16D3C 80240FBC E6080070 */  swc1      $f8, 0x70($s0)
/* E16D40 80240FC0 C660003C */  lwc1      $f0, 0x3c($s3)
/* E16D44 80240FC4 46160002 */  mul.s     $f0, $f0, $f22
/* E16D48 80240FC8 00000000 */  nop       
/* E16D4C 80240FCC 4600020D */  trunc.w.s $f8, $f0
/* E16D50 80240FD0 E6080074 */  swc1      $f8, 0x74($s0)
/* E16D54 80240FD4 C6600040 */  lwc1      $f0, 0x40($s3)
/* E16D58 80240FD8 46160002 */  mul.s     $f0, $f0, $f22
/* E16D5C 80240FDC 00000000 */  nop       
/* E16D60 80240FE0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* E16D64 80240FE4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* E16D68 80240FE8 4600020D */  trunc.w.s $f8, $f0
/* E16D6C 80240FEC E6080078 */  swc1      $f8, 0x78($s0)
/* E16D70 80240FF0 C4400028 */  lwc1      $f0, 0x28($v0)
/* E16D74 80240FF4 46160002 */  mul.s     $f0, $f0, $f22
/* E16D78 80240FF8 00000000 */  nop       
/* E16D7C 80240FFC 3C0141E0 */  lui       $at, 0x41e0
/* E16D80 80241000 44811000 */  mtc1      $at, $f2
/* E16D84 80241004 4600020D */  trunc.w.s $f8, $f0
/* E16D88 80241008 E608007C */  swc1      $f8, 0x7c($s0)
/* E16D8C 8024100C C440002C */  lwc1      $f0, 0x2c($v0)
/* E16D90 80241010 46020000 */  add.s     $f0, $f0, $f2
/* E16D94 80241014 46160002 */  mul.s     $f0, $f0, $f22
/* E16D98 80241018 00000000 */  nop       
/* E16D9C 8024101C 4600020D */  trunc.w.s $f8, $f0
/* E16DA0 80241020 E6080080 */  swc1      $f8, 0x80($s0)
/* E16DA4 80241024 C4400030 */  lwc1      $f0, 0x30($v0)
/* E16DA8 80241028 461E0000 */  add.s     $f0, $f0, $f30
/* E16DAC 8024102C 46160002 */  mul.s     $f0, $f0, $f22
/* E16DB0 80241030 00000000 */  nop       
/* E16DB4 80241034 AE000088 */  sw        $zero, 0x88($s0)
/* E16DB8 80241038 4600020D */  trunc.w.s $f8, $f0
/* E16DBC 8024103C E6080084 */  swc1      $f8, 0x84($s0)
/* E16DC0 80241040 080906CF */  j         .L80241B3C
/* E16DC4 80241044 2694001C */   addiu    $s4, $s4, 0x1c
/* E16DC8 80241048 C6000070 */  lwc1      $f0, 0x70($s0)
/* E16DCC 8024104C 46800020 */  cvt.s.w   $f0, $f0
/* E16DD0 80241050 46000021 */  cvt.d.s   $f0, $f0
/* E16DD4 80241054 46340003 */  div.d     $f0, $f0, $f20
/* E16DD8 80241058 46200020 */  cvt.s.d   $f0, $f0
/* E16DDC 8024105C 44050000 */  mfc1      $a1, $f0
/* E16DE0 80241060 C600007C */  lwc1      $f0, 0x7c($s0)
/* E16DE4 80241064 46800020 */  cvt.s.w   $f0, $f0
/* E16DE8 80241068 46000021 */  cvt.d.s   $f0, $f0
/* E16DEC 8024106C 46340003 */  div.d     $f0, $f0, $f20
/* E16DF0 80241070 46200020 */  cvt.s.d   $f0, $f0
/* E16DF4 80241074 8E020088 */  lw        $v0, 0x88($s0)
/* E16DF8 80241078 44060000 */  mfc1      $a2, $f0
/* E16DFC 8024107C 24420001 */  addiu     $v0, $v0, 1
/* E16E00 80241080 AE020088 */  sw        $v0, 0x88($s0)
/* E16E04 80241084 24080008 */  addiu     $t0, $zero, 8
/* E16E08 80241088 AFA80010 */  sw        $t0, 0x10($sp)
/* E16E0C 8024108C 8E070088 */  lw        $a3, 0x88($s0)
/* E16E10 80241090 0C00A8ED */  jal       update_lerp
/* E16E14 80241094 0000202D */   daddu    $a0, $zero, $zero
/* E16E18 80241098 E6600038 */  swc1      $f0, 0x38($s3)
/* E16E1C 8024109C C6000074 */  lwc1      $f0, 0x74($s0)
/* E16E20 802410A0 46800020 */  cvt.s.w   $f0, $f0
/* E16E24 802410A4 46000021 */  cvt.d.s   $f0, $f0
/* E16E28 802410A8 46340003 */  div.d     $f0, $f0, $f20
/* E16E2C 802410AC 46200020 */  cvt.s.d   $f0, $f0
/* E16E30 802410B0 44050000 */  mfc1      $a1, $f0
/* E16E34 802410B4 C6000080 */  lwc1      $f0, 0x80($s0)
/* E16E38 802410B8 46800020 */  cvt.s.w   $f0, $f0
/* E16E3C 802410BC 24080008 */  addiu     $t0, $zero, 8
/* E16E40 802410C0 46000021 */  cvt.d.s   $f0, $f0
/* E16E44 802410C4 46340003 */  div.d     $f0, $f0, $f20
/* E16E48 802410C8 46200020 */  cvt.s.d   $f0, $f0
/* E16E4C 802410CC AFA80010 */  sw        $t0, 0x10($sp)
/* E16E50 802410D0 8E070088 */  lw        $a3, 0x88($s0)
/* E16E54 802410D4 44060000 */  mfc1      $a2, $f0
/* E16E58 802410D8 0C00A8ED */  jal       update_lerp
/* E16E5C 802410DC 0000202D */   daddu    $a0, $zero, $zero
/* E16E60 802410E0 E660003C */  swc1      $f0, 0x3c($s3)
/* E16E64 802410E4 C6000078 */  lwc1      $f0, 0x78($s0)
/* E16E68 802410E8 46800020 */  cvt.s.w   $f0, $f0
/* E16E6C 802410EC 46000021 */  cvt.d.s   $f0, $f0
/* E16E70 802410F0 46340003 */  div.d     $f0, $f0, $f20
/* E16E74 802410F4 46200020 */  cvt.s.d   $f0, $f0
/* E16E78 802410F8 44050000 */  mfc1      $a1, $f0
/* E16E7C 802410FC C6000084 */  lwc1      $f0, 0x84($s0)
/* E16E80 80241100 46800020 */  cvt.s.w   $f0, $f0
/* E16E84 80241104 24080008 */  addiu     $t0, $zero, 8
/* E16E88 80241108 46000021 */  cvt.d.s   $f0, $f0
/* E16E8C 8024110C 46340003 */  div.d     $f0, $f0, $f20
/* E16E90 80241110 46200020 */  cvt.s.d   $f0, $f0
/* E16E94 80241114 AFA80010 */  sw        $t0, 0x10($sp)
/* E16E98 80241118 8E070088 */  lw        $a3, 0x88($s0)
/* E16E9C 8024111C 44060000 */  mfc1      $a2, $f0
/* E16EA0 80241120 0C00A8ED */  jal       update_lerp
/* E16EA4 80241124 0000202D */   daddu    $a0, $zero, $zero
/* E16EA8 80241128 3C020001 */  lui       $v0, 1
/* E16EAC 8024112C 3C04800F */  lui       $a0, %hi(gPlayerStatusPtr)
/* E16EB0 80241130 8C847B30 */  lw        $a0, %lo(gPlayerStatusPtr)($a0)
/* E16EB4 80241134 34420001 */  ori       $v0, $v0, 1
/* E16EB8 80241138 E6600040 */  swc1      $f0, 0x40($s3)
/* E16EBC 8024113C AC8200B8 */  sw        $v0, 0xb8($a0)
/* E16EC0 80241140 9662008E */  lhu       $v0, 0x8e($s3)
/* E16EC4 80241144 2442FFFF */  addiu     $v0, $v0, -1
/* E16EC8 80241148 A662008E */  sh        $v0, 0x8e($s3)
/* E16ECC 8024114C 00021400 */  sll       $v0, $v0, 0x10
/* E16ED0 80241150 5C40027A */  bgtzl     $v0, .L80241B3C
/* E16ED4 80241154 2694001C */   addiu    $s4, $s4, 0x1c
/* E16ED8 80241158 3C03002B */  lui       $v1, 0x2b
/* E16EDC 8024115C 3463000F */  ori       $v1, $v1, 0xf
/* E16EE0 80241160 3C020001 */  lui       $v0, 1
/* E16EE4 80241164 3442001B */  ori       $v0, $v0, 0x1b
/* E16EE8 80241168 AE630028 */  sw        $v1, 0x28($s3)
/* E16EEC 8024116C AC8200B8 */  sw        $v0, 0xb8($a0)
/* E16EF0 80241170 AEA00024 */  sw        $zero, 0x24($s5)
/* E16EF4 80241174 C4800028 */  lwc1      $f0, 0x28($a0)
/* E16EF8 80241178 E6600038 */  swc1      $f0, 0x38($s3)
/* E16EFC 8024117C C480002C */  lwc1      $f0, 0x2c($a0)
/* E16F00 80241180 3C01403C */  lui       $at, 0x403c
/* E16F04 80241184 44811800 */  mtc1      $at, $f3
/* E16F08 80241188 44801000 */  mtc1      $zero, $f2
/* E16F0C 8024118C 46000021 */  cvt.d.s   $f0, $f0
/* E16F10 80241190 46220000 */  add.d     $f0, $f0, $f2
/* E16F14 80241194 46200020 */  cvt.s.d   $f0, $f0
/* E16F18 80241198 E660003C */  swc1      $f0, 0x3c($s3)
/* E16F1C 8024119C C4800030 */  lwc1      $f0, 0x30($a0)
/* E16F20 802411A0 46000021 */  cvt.d.s   $f0, $f0
/* E16F24 802411A4 46380000 */  add.d     $f0, $f0, $f24
/* E16F28 802411A8 46200020 */  cvt.s.d   $f0, $f0
/* E16F2C 802411AC E6600040 */  swc1      $f0, 0x40($s3)
/* E16F30 802411B0 8EA4000C */  lw        $a0, 0xc($s5)
/* E16F34 802411B4 3C058011 */  lui       $a1, 0x8011
/* E16F38 802411B8 24A58B80 */  addiu     $a1, $a1, -0x7480
/* E16F3C 802411BC 0C0511FF */  jal       set_menu_icon_script
/* E16F40 802411C0 00000000 */   nop      
/* E16F44 802411C4 8EA4000C */  lw        $a0, 0xc($s5)
/* E16F48 802411C8 0C0513AC */  jal       icon_set_opacity
/* E16F4C 802411CC 240500FF */   addiu    $a1, $zero, 0xff
/* E16F50 802411D0 8EA40010 */  lw        $a0, 0x10($s5)
/* E16F54 802411D4 0C0513AC */  jal       icon_set_opacity
/* E16F58 802411D8 240500FF */   addiu    $a1, $zero, 0xff
/* E16F5C 802411DC 2402000F */  addiu     $v0, $zero, 0xf
/* E16F60 802411E0 080906CE */  j         .L80241B38
/* E16F64 802411E4 AE82002C */   sw       $v0, 0x2c($s4)
/* E16F68 802411E8 3C040001 */  lui       $a0, 1
/* E16F6C 802411EC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* E16F70 802411F0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* E16F74 802411F4 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* E16F78 802411F8 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* E16F7C 802411FC 3484001B */  ori       $a0, $a0, 0x1b
/* E16F80 80241200 AC4400B8 */  sw        $a0, 0xb8($v0)
/* E16F84 80241204 8C620010 */  lw        $v0, 0x10($v1)
/* E16F88 80241208 30428000 */  andi      $v0, $v0, 0x8000
/* E16F8C 8024120C 10400004 */  beqz      $v0, .L80241220
/* E16F90 80241210 00000000 */   nop      
/* E16F94 80241214 8EA20024 */  lw        $v0, 0x24($s5)
/* E16F98 80241218 24420001 */  addiu     $v0, $v0, 1
/* E16F9C 8024121C AEA20024 */  sw        $v0, 0x24($s5)
.L80241220:
/* E16FA0 80241220 8EA20024 */  lw        $v0, 0x24($s5)
/* E16FA4 80241224 2842000C */  slti      $v0, $v0, 0xc
/* E16FA8 80241228 54400244 */  bnel      $v0, $zero, .L80241B3C
/* E16FAC 8024122C 2694001C */   addiu    $s4, $s4, 0x1c
/* E16FB0 80241230 3C030001 */  lui       $v1, 1
/* E16FB4 80241234 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* E16FB8 80241238 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* E16FBC 8024123C 34630002 */  ori       $v1, $v1, 2
/* E16FC0 80241240 AC4300B8 */  sw        $v1, 0xb8($v0)
/* E16FC4 80241244 8EA20028 */  lw        $v0, 0x28($s5)
/* E16FC8 80241248 2403FFFE */  addiu     $v1, $zero, -2
/* E16FCC 8024124C 00431024 */  and       $v0, $v0, $v1
/* E16FD0 80241250 34420002 */  ori       $v0, $v0, 2
/* E16FD4 80241254 AEA20028 */  sw        $v0, 0x28($s5)
/* E16FD8 80241258 24020010 */  addiu     $v0, $zero, 0x10
/* E16FDC 8024125C AE82002C */  sw        $v0, 0x2c($s4)
/* E16FE0 80241260 2402000A */  addiu     $v0, $zero, 0xa
/* E16FE4 80241264 A662008E */  sh        $v0, 0x8e($s3)
/* E16FE8 80241268 8EA4000C */  lw        $a0, 0xc($s5)
/* E16FEC 8024126C 3C058011 */  lui       $a1, 0x8011
/* E16FF0 80241270 24A58B28 */  addiu     $a1, $a1, -0x74d8
/* E16FF4 80241274 0C0511FF */  jal       set_menu_icon_script
/* E16FF8 80241278 2694001C */   addiu    $s4, $s4, 0x1c
/* E16FFC 8024127C 8EA4000C */  lw        $a0, 0xc($s5)
/* E17000 80241280 0C0513AC */  jal       icon_set_opacity
/* E17004 80241284 240500A0 */   addiu    $a1, $zero, 0xa0
/* E17008 80241288 8EA40010 */  lw        $a0, 0x10($s5)
/* E1700C 8024128C 0C0513AC */  jal       icon_set_opacity
/* E17010 80241290 240500A0 */   addiu    $a1, $zero, 0xa0
/* E17014 80241294 3C02002B */  lui       $v0, 0x2b
/* E17018 80241298 C660003C */  lwc1      $f0, 0x3c($s3)
/* E1701C 8024129C 3C014008 */  lui       $at, 0x4008
/* E17020 802412A0 44811800 */  mtc1      $at, $f3
/* E17024 802412A4 44801000 */  mtc1      $zero, $f2
/* E17028 802412A8 46000021 */  cvt.d.s   $f0, $f0
/* E1702C 802412AC 46220000 */  add.d     $f0, $f0, $f2
/* E17030 802412B0 34420008 */  ori       $v0, $v0, 8
/* E17034 802412B4 AE620028 */  sw        $v0, 0x28($s3)
/* E17038 802412B8 46200020 */  cvt.s.d   $f0, $f0
/* E1703C 802412BC 080906CF */  j         .L80241B3C
/* E17040 802412C0 E660003C */   swc1     $f0, 0x3c($s3)
/* E17044 802412C4 9662008E */  lhu       $v0, 0x8e($s3)
/* E17048 802412C8 24080008 */  addiu     $t0, $zero, 8
/* E1704C 802412CC 2442FFFF */  addiu     $v0, $v0, -1
/* E17050 802412D0 A662008E */  sh        $v0, 0x8e($s3)
/* E17054 802412D4 00021400 */  sll       $v0, $v0, 0x10
/* E17058 802412D8 00021403 */  sra       $v0, $v0, 0x10
/* E1705C 802412DC 14480004 */  bne       $v0, $t0, .L802412F0
/* E17060 802412E0 2403FFFB */   addiu    $v1, $zero, -5
/* E17064 802412E4 8EA20028 */  lw        $v0, 0x28($s5)
/* E17068 802412E8 00431024 */  and       $v0, $v0, $v1
/* E1706C 802412EC AEA20028 */  sw        $v0, 0x28($s5)
.L802412F0:
/* E17070 802412F0 8662008E */  lh        $v0, 0x8e($s3)
/* E17074 802412F4 5C400211 */  bgtzl     $v0, .L80241B3C
/* E17078 802412F8 2694001C */   addiu    $s4, $s4, 0x1c
/* E1707C 802412FC 0260202D */  daddu     $a0, $s3, $zero
/* E17080 80241300 24020011 */  addiu     $v0, $zero, 0x11
/* E17084 80241304 0C00EAFF */  jal       disable_npc_shadow
/* E17088 80241308 AE82002C */   sw       $v0, 0x2c($s4)
/* E1708C 8024130C C660003C */  lwc1      $f0, 0x3c($s3)
/* E17090 80241310 46160000 */  add.s     $f0, $f0, $f22
/* E17094 80241314 C6620040 */  lwc1      $f2, 0x40($s3)
/* E17098 80241318 8E620000 */  lw        $v0, ($s3)
/* E1709C 8024131C 44060000 */  mfc1      $a2, $f0
/* E170A0 80241320 3C013F80 */  lui       $at, 0x3f80
/* E170A4 80241324 44810000 */  mtc1      $at, $f0
/* E170A8 80241328 34420002 */  ori       $v0, $v0, 2
/* E170AC 8024132C AE620000 */  sw        $v0, ($s3)
/* E170B0 80241330 AFA00010 */  sw        $zero, 0x10($sp)
/* E170B4 80241334 46001080 */  add.s     $f2, $f2, $f0
/* E170B8 80241338 AFA00014 */  sw        $zero, 0x14($sp)
/* E170BC 8024133C 8E650038 */  lw        $a1, 0x38($s3)
/* E170C0 80241340 44071000 */  mfc1      $a3, $f2
/* E170C4 80241344 0C01BECC */  jal       fx_walk_normal
/* E170C8 80241348 24040001 */   addiu    $a0, $zero, 1
/* E170CC 8024134C 080906CF */  j         .L80241B3C
/* E170D0 80241350 2694001C */   addiu    $s4, $s4, 0x1c
/* E170D4 80241354 240400D2 */  addiu     $a0, $zero, 0xd2
/* E170D8 80241358 2402001F */  addiu     $v0, $zero, 0x1f
/* E170DC 8024135C 0C00A67F */  jal       rand_int
/* E170E0 80241360 AE82002C */   sw       $v0, 0x2c($s4)
/* E170E4 80241364 0260202D */  daddu     $a0, $s3, $zero
/* E170E8 80241368 AE820030 */  sw        $v0, 0x30($s4)
/* E170EC 8024136C 0C00EAFF */  jal       disable_npc_shadow
/* E170F0 80241370 E67A003C */   swc1     $f26, 0x3c($s3)
/* E170F4 80241374 8E620000 */  lw        $v0, ($s3)
/* E170F8 80241378 2403FFFD */  addiu     $v1, $zero, -3
/* E170FC 8024137C 00431024 */  and       $v0, $v0, $v1
/* E17100 80241380 AE620000 */  sw        $v0, ($s3)
/* E17104 80241384 8E820030 */  lw        $v0, 0x30($s4)
/* E17108 80241388 2442FFFF */  addiu     $v0, $v0, -1
/* E1710C 8024138C 1C4001EA */  bgtz      $v0, .L80241B38
/* E17110 80241390 AE820030 */   sw       $v0, 0x30($s4)
/* E17114 80241394 24020020 */  addiu     $v0, $zero, 0x20
/* E17118 80241398 AE82002C */  sw        $v0, 0x2c($s4)
/* E1711C 8024139C C6600040 */  lwc1      $f0, 0x40($s3)
/* E17120 802413A0 E7A00010 */  swc1      $f0, 0x10($sp)
/* E17124 802413A4 8E04008C */  lw        $a0, 0x8c($s0)
/* E17128 802413A8 8E660038 */  lw        $a2, 0x38($s3)
/* E1712C 802413AC 8E67003C */  lw        $a3, 0x3c($s3)
/* E17130 802413B0 0C052757 */  jal       play_sound_at_position
/* E17134 802413B4 3C050010 */   lui      $a1, 0x10
/* E17138 802413B8 27A50068 */  addiu     $a1, $sp, 0x68
/* E1713C 802413BC 27A6006C */  addiu     $a2, $sp, 0x6c
/* E17140 802413C0 9684003A */  lhu       $a0, 0x3a($s4)
/* E17144 802413C4 27A70070 */  addiu     $a3, $sp, 0x70
/* E17148 802413C8 AFBE0010 */  sw        $fp, 0x10($sp)
/* E1714C 802413CC AFB60014 */  sw        $s6, 0x14($sp)
/* E17150 802413D0 0C046C3B */  jal       get_model_center_and_size
/* E17154 802413D4 AFB70018 */   sw       $s7, 0x18($sp)
/* E17158 802413D8 3C014128 */  lui       $at, 0x4128
/* E1715C 802413DC 44810000 */  mtc1      $at, $f0
/* E17160 802413E0 C7A40068 */  lwc1      $f4, 0x68($sp)
/* E17164 802413E4 C7A2006C */  lwc1      $f2, 0x6c($sp)
/* E17168 802413E8 E660001C */  swc1      $f0, 0x1c($s3)
/* E1716C 802413EC 3C014029 */  lui       $at, 0x4029
/* E17170 802413F0 44810800 */  mtc1      $at, $f1
/* E17174 802413F4 44800000 */  mtc1      $zero, $f0
/* E17178 802413F8 460010A1 */  cvt.d.s   $f2, $f2
/* E1717C 802413FC E6640038 */  swc1      $f4, 0x38($s3)
/* E17180 80241400 3C013FC0 */  lui       $at, 0x3fc0
/* E17184 80241404 44812000 */  mtc1      $at, $f4
/* E17188 80241408 46201081 */  sub.d     $f2, $f2, $f0
/* E1718C 8024140C E6640014 */  swc1      $f4, 0x14($s3)
/* E17190 80241410 C7A00070 */  lwc1      $f0, 0x70($sp)
/* E17194 80241414 46000021 */  cvt.d.s   $f0, $f0
/* E17198 80241418 46380000 */  add.d     $f0, $f0, $f24
/* E1719C 8024141C 462010A0 */  cvt.s.d   $f2, $f2
/* E171A0 80241420 E662003C */  swc1      $f2, 0x3c($s3)
/* E171A4 80241424 E6620064 */  swc1      $f2, 0x64($s3)
/* E171A8 80241428 46200020 */  cvt.s.d   $f0, $f0
/* E171AC 8024142C 080906CD */  j         .L80241B34
/* E171B0 80241430 E6600040 */   swc1     $f0, 0x40($s3)
/* E171B4 80241434 8E820030 */  lw        $v0, 0x30($s4)
/* E171B8 80241438 24420001 */  addiu     $v0, $v0, 1
/* E171BC 8024143C AE820030 */  sw        $v0, 0x30($s4)
/* E171C0 80241440 C660001C */  lwc1      $f0, 0x1c($s3)
/* E171C4 80241444 C664003C */  lwc1      $f4, 0x3c($s3)
/* E171C8 80241448 46000186 */  mov.s     $f6, $f0
/* E171CC 8024144C 46002100 */  add.s     $f4, $f4, $f0
/* E171D0 80241450 C6600014 */  lwc1      $f0, 0x14($s3)
/* E171D4 80241454 3C0141A0 */  lui       $at, 0x41a0
/* E171D8 80241458 44811000 */  mtc1      $at, $f2
/* E171DC 8024145C 46003181 */  sub.s     $f6, $f6, $f0
/* E171E0 80241460 C6600064 */  lwc1      $f0, 0x64($s3)
/* E171E4 80241464 46020000 */  add.s     $f0, $f0, $f2
/* E171E8 80241468 E664003C */  swc1      $f4, 0x3c($s3)
/* E171EC 8024146C 46002086 */  mov.s     $f2, $f4
/* E171F0 80241470 4602003C */  c.lt.s    $f0, $f2
/* E171F4 80241474 00000000 */  nop       
/* E171F8 80241478 45000005 */  bc1f      .L80241490
/* E171FC 8024147C E666001C */   swc1     $f6, 0x1c($s3)
/* E17200 80241480 0C00EAE8 */  jal       enable_npc_shadow
/* E17204 80241484 0260202D */   daddu    $a0, $s3, $zero
/* E17208 80241488 08090526 */  j         .L80241498
/* E1720C 8024148C 00000000 */   nop      
.L80241490:
/* E17210 80241490 0C00EAFF */  jal       disable_npc_shadow
/* E17214 80241494 0260202D */   daddu    $a0, $s3, $zero
.L80241498:
/* E17218 80241498 C660001C */  lwc1      $f0, 0x1c($s3)
/* E1721C 8024149C 44801000 */  mtc1      $zero, $f2
/* E17220 802414A0 44801800 */  mtc1      $zero, $f3
/* E17224 802414A4 46000021 */  cvt.d.s   $f0, $f0
/* E17228 802414A8 4622003C */  c.lt.d    $f0, $f2
/* E1722C 802414AC 00000000 */  nop       
/* E17230 802414B0 450201A2 */  bc1fl     .L80241B3C
/* E17234 802414B4 2694001C */   addiu    $s4, $s4, 0x1c
/* E17238 802414B8 C662003C */  lwc1      $f2, 0x3c($s3)
/* E1723C 802414BC C6600064 */  lwc1      $f0, 0x64($s3)
/* E17240 802414C0 4600103E */  c.le.s    $f2, $f0
/* E17244 802414C4 00000000 */  nop       
/* E17248 802414C8 4500019B */  bc1f      .L80241B38
/* E1724C 802414CC 2404014A */   addiu    $a0, $zero, 0x14a
/* E17250 802414D0 2402001F */  addiu     $v0, $zero, 0x1f
/* E17254 802414D4 0C00A67F */  jal       rand_int
/* E17258 802414D8 AE82002C */   sw       $v0, 0x2c($s4)
/* E1725C 802414DC 24040064 */  addiu     $a0, $zero, 0x64
/* E17260 802414E0 2442005A */  addiu     $v0, $v0, 0x5a
/* E17264 802414E4 AE820030 */  sw        $v0, 0x30($s4)
/* E17268 802414E8 0C00A67F */  jal       rand_int
/* E1726C 802414EC E67A003C */   swc1     $f26, 0x3c($s3)
/* E17270 802414F0 28420032 */  slti      $v0, $v0, 0x32
/* E17274 802414F4 10400005 */  beqz      $v0, .L8024150C
/* E17278 802414F8 00000000 */   nop      
/* E1727C 802414FC 3C014387 */  lui       $at, 0x4387
/* E17280 80241500 44810000 */  mtc1      $at, $f0
/* E17284 80241504 08090547 */  j         .L8024151C
/* E17288 80241508 E660000C */   swc1     $f0, 0xc($s3)
.L8024150C:
/* E1728C 8024150C 3C0142B4 */  lui       $at, 0x42b4
/* E17290 80241510 44810000 */  mtc1      $at, $f0
/* E17294 80241514 00000000 */  nop       
/* E17298 80241518 E660000C */  swc1      $f0, 0xc($s3)
.L8024151C:
/* E1729C 8024151C 0C00EAFF */  jal       disable_npc_shadow
/* E172A0 80241520 0260202D */   daddu    $a0, $s3, $zero
/* E172A4 80241524 080906CF */  j         .L80241B3C
/* E172A8 80241528 2694001C */   addiu    $s4, $s4, 0x1c
/* E172AC 8024152C 0C00EAE8 */  jal       enable_npc_shadow
/* E172B0 80241530 0260202D */   daddu    $a0, $s3, $zero
/* E172B4 80241534 3C03002C */  lui       $v1, 0x2c
/* E172B8 80241538 34630005 */  ori       $v1, $v1, 5
/* E172BC 8024153C 27A50068 */  addiu     $a1, $sp, 0x68
/* E172C0 80241540 27A6006C */  addiu     $a2, $sp, 0x6c
/* E172C4 80241544 2402000F */  addiu     $v0, $zero, 0xf
/* E172C8 80241548 A662008E */  sh        $v0, 0x8e($s3)
/* E172CC 8024154C AE630028 */  sw        $v1, 0x28($s3)
/* E172D0 80241550 8EA20028 */  lw        $v0, 0x28($s5)
/* E172D4 80241554 27A70070 */  addiu     $a3, $sp, 0x70
/* E172D8 80241558 34420003 */  ori       $v0, $v0, 3
/* E172DC 8024155C AEA20028 */  sw        $v0, 0x28($s5)
/* E172E0 80241560 9684003A */  lhu       $a0, 0x3a($s4)
/* E172E4 80241564 24020022 */  addiu     $v0, $zero, 0x22
/* E172E8 80241568 AE82002C */  sw        $v0, 0x2c($s4)
/* E172EC 8024156C AFBE0010 */  sw        $fp, 0x10($sp)
/* E172F0 80241570 AFB60014 */  sw        $s6, 0x14($sp)
/* E172F4 80241574 0C046C3B */  jal       get_model_center_and_size
/* E172F8 80241578 AFB70018 */   sw       $s7, 0x18($sp)
/* E172FC 8024157C 0000202D */  daddu     $a0, $zero, $zero
/* E17300 80241580 0260282D */  daddu     $a1, $s3, $zero
/* E17304 80241584 4406E000 */  mfc1      $a2, $f28
/* E17308 80241588 C7A00068 */  lwc1      $f0, 0x68($sp)
/* E1730C 8024158C 866200A8 */  lh        $v0, 0xa8($s3)
/* E17310 80241590 C7A4006C */  lwc1      $f4, 0x6c($sp)
/* E17314 80241594 3C014020 */  lui       $at, 0x4020
/* E17318 80241598 44811800 */  mtc1      $at, $f3
/* E1731C 8024159C 44801000 */  mtc1      $zero, $f2
/* E17320 802415A0 44824000 */  mtc1      $v0, $f8
/* E17324 802415A4 00000000 */  nop       
/* E17328 802415A8 46804220 */  cvt.s.w   $f8, $f8
/* E1732C 802415AC 46162101 */  sub.s     $f4, $f4, $f22
/* E17330 802415B0 E6600038 */  swc1      $f0, 0x38($s3)
/* E17334 802415B4 C7A00070 */  lwc1      $f0, 0x70($sp)
/* E17338 802415B8 44074000 */  mfc1      $a3, $f8
/* E1733C 802415BC 46000021 */  cvt.d.s   $f0, $f0
/* E17340 802415C0 46220000 */  add.d     $f0, $f0, $f2
/* E17344 802415C4 3C013F80 */  lui       $at, 0x3f80
/* E17348 802415C8 44811000 */  mtc1      $at, $f2
/* E1734C 802415CC 2402000A */  addiu     $v0, $zero, 0xa
/* E17350 802415D0 E664003C */  swc1      $f4, 0x3c($s3)
/* E17354 802415D4 46200020 */  cvt.s.d   $f0, $f0
/* E17358 802415D8 E6600040 */  swc1      $f0, 0x40($s3)
/* E1735C 802415DC AFA2001C */  sw        $v0, 0x1c($sp)
/* E17360 802415E0 27A20080 */  addiu     $v0, $sp, 0x80
/* E17364 802415E4 E7A20010 */  swc1      $f2, 0x10($sp)
/* E17368 802415E8 E7BE0014 */  swc1      $f30, 0x14($sp)
/* E1736C 802415EC E7BC0018 */  swc1      $f28, 0x18($sp)
/* E17370 802415F0 0C01BFA4 */  jal       fx_emote
/* E17374 802415F4 AFA20020 */   sw       $v0, 0x20($sp)
/* E17378 802415F8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* E1737C 802415FC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* E17380 80241600 C6620038 */  lwc1      $f2, 0x38($s3)
/* E17384 80241604 C4400028 */  lwc1      $f0, 0x28($v0)
/* E17388 80241608 4602003C */  c.lt.s    $f0, $f2
/* E1738C 8024160C 00000000 */  nop       
/* E17390 80241610 45000007 */  bc1f      .L80241630
/* E17394 80241614 00000000 */   nop      
/* E17398 80241618 3C014387 */  lui       $at, 0x4387
/* E1739C 8024161C 44810000 */  mtc1      $at, $f0
/* E173A0 80241620 3C0142BE */  lui       $at, 0x42be
/* E173A4 80241624 44811000 */  mtc1      $at, $f2
/* E173A8 80241628 08090592 */  j         .L80241648
/* E173AC 8024162C E660000C */   swc1     $f0, 0xc($s3)
.L80241630:
/* E173B0 80241630 3C0142B4 */  lui       $at, 0x42b4
/* E173B4 80241634 44810000 */  mtc1      $at, $f0
/* E173B8 80241638 3C014384 */  lui       $at, 0x4384
/* E173BC 8024163C 34218000 */  ori       $at, $at, 0x8000
/* E173C0 80241640 44811000 */  mtc1      $at, $f2
/* E173C4 80241644 E660000C */  swc1      $f0, 0xc($s3)
.L80241648:
/* E173C8 80241648 E4420080 */  swc1      $f2, 0x80($v0)
/* E173CC 8024164C 3C030001 */  lui       $v1, 1
/* E173D0 80241650 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* E173D4 80241654 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* E173D8 80241658 34630001 */  ori       $v1, $v1, 1
/* E173DC 8024165C AC4300B8 */  sw        $v1, 0xb8($v0)
/* E173E0 80241660 9662008E */  lhu       $v0, 0x8e($s3)
/* E173E4 80241664 2442FFFF */  addiu     $v0, $v0, -1
/* E173E8 80241668 A662008E */  sh        $v0, 0x8e($s3)
/* E173EC 8024166C 00021400 */  sll       $v0, $v0, 0x10
/* E173F0 80241670 5C400132 */  bgtzl     $v0, .L80241B3C
/* E173F4 80241674 2694001C */   addiu    $s4, $s4, 0x1c
/* E173F8 80241678 C6620040 */  lwc1      $f2, 0x40($s3)
/* E173FC 8024167C 3C013F80 */  lui       $at, 0x3f80
/* E17400 80241680 44810000 */  mtc1      $at, $f0
/* E17404 80241684 00000000 */  nop       
/* E17408 80241688 46001080 */  add.s     $f2, $f2, $f0
/* E1740C 8024168C 8E650038 */  lw        $a1, 0x38($s3)
/* E17410 80241690 8E66003C */  lw        $a2, 0x3c($s3)
/* E17414 80241694 44071000 */  mfc1      $a3, $f2
/* E17418 80241698 0C01C07C */  jal       func_800701F0
/* E1741C 8024169C 0000202D */   daddu    $a0, $zero, $zero
/* E17420 802416A0 24042076 */  addiu     $a0, $zero, 0x2076
/* E17424 802416A4 2402001E */  addiu     $v0, $zero, 0x1e
/* E17428 802416A8 A662008E */  sh        $v0, 0x8e($s3)
/* E1742C 802416AC 24020023 */  addiu     $v0, $zero, 0x23
/* E17430 802416B0 E67A003C */  swc1      $f26, 0x3c($s3)
/* E17434 802416B4 0C05272D */  jal       play_sound
/* E17438 802416B8 AE82002C */   sw       $v0, 0x2c($s4)
/* E1743C 802416BC 080906CF */  j         .L80241B3C
/* E17440 802416C0 2694001C */   addiu    $s4, $s4, 0x1c
/* E17444 802416C4 9662008E */  lhu       $v0, 0x8e($s3)
/* E17448 802416C8 24030019 */  addiu     $v1, $zero, 0x19
/* E1744C 802416CC 2442FFFF */  addiu     $v0, $v0, -1
/* E17450 802416D0 A662008E */  sh        $v0, 0x8e($s3)
/* E17454 802416D4 00021400 */  sll       $v0, $v0, 0x10
/* E17458 802416D8 00021403 */  sra       $v0, $v0, 0x10
/* E1745C 802416DC 14430005 */  bne       $v0, $v1, .L802416F4
/* E17460 802416E0 3C030001 */   lui      $v1, 1
/* E17464 802416E4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* E17468 802416E8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* E1746C 802416EC 3463002F */  ori       $v1, $v1, 0x2f
/* E17470 802416F0 AC4300B8 */  sw        $v1, 0xb8($v0)
.L802416F4:
/* E17474 802416F4 8662008E */  lh        $v0, 0x8e($s3)
/* E17478 802416F8 5C400110 */  bgtzl     $v0, .L80241B3C
/* E1747C 802416FC 2694001C */   addiu    $s4, $s4, 0x1c
/* E17480 80241700 3C030001 */  lui       $v1, 1
/* E17484 80241704 34630002 */  ori       $v1, $v1, 2
/* E17488 80241708 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* E1748C 8024170C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* E17490 80241710 0260202D */  daddu     $a0, $s3, $zero
/* E17494 80241714 AC4300B8 */  sw        $v1, 0xb8($v0)
/* E17498 80241718 8EA20028 */  lw        $v0, 0x28($s5)
/* E1749C 8024171C 2403FFFE */  addiu     $v1, $zero, -2
/* E174A0 80241720 00431024 */  and       $v0, $v0, $v1
/* E174A4 80241724 34420002 */  ori       $v0, $v0, 2
/* E174A8 80241728 AEA20028 */  sw        $v0, 0x28($s5)
/* E174AC 8024172C 24020024 */  addiu     $v0, $zero, 0x24
/* E174B0 80241730 0C00EAFF */  jal       disable_npc_shadow
/* E174B4 80241734 AE82002C */   sw       $v0, 0x2c($s4)
/* E174B8 80241738 8E620000 */  lw        $v0, ($s3)
/* E174BC 8024173C 34420002 */  ori       $v0, $v0, 2
/* E174C0 80241740 080906CE */  j         .L80241B38
/* E174C4 80241744 AE620000 */   sw       $v0, ($s3)
/* E174C8 80241748 27A50068 */  addiu     $a1, $sp, 0x68
/* E174CC 8024174C 27A6006C */  addiu     $a2, $sp, 0x6c
/* E174D0 80241750 9684003A */  lhu       $a0, 0x3a($s4)
/* E174D4 80241754 27A70070 */  addiu     $a3, $sp, 0x70
/* E174D8 80241758 AFBE0010 */  sw        $fp, 0x10($sp)
/* E174DC 8024175C AFB60014 */  sw        $s6, 0x14($sp)
/* E174E0 80241760 0C046C3B */  jal       get_model_center_and_size
/* E174E4 80241764 AFB70018 */   sw       $s7, 0x18($sp)
/* E174E8 80241768 240400D2 */  addiu     $a0, $zero, 0xd2
/* E174EC 8024176C 24020047 */  addiu     $v0, $zero, 0x47
/* E174F0 80241770 0C00A67F */  jal       rand_int
/* E174F4 80241774 AE82002C */   sw       $v0, 0x2c($s4)
/* E174F8 80241778 C7A20068 */  lwc1      $f2, 0x68($sp)
/* E174FC 8024177C C7A00070 */  lwc1      $f0, 0x70($sp)
/* E17500 80241780 0260202D */  daddu     $a0, $s3, $zero
/* E17504 80241784 AE820030 */  sw        $v0, 0x30($s4)
/* E17508 80241788 46000021 */  cvt.d.s   $f0, $f0
/* E1750C 8024178C E6620038 */  swc1      $f2, 0x38($s3)
/* E17510 80241790 C7A2006C */  lwc1      $f2, 0x6c($sp)
/* E17514 80241794 46380000 */  add.d     $f0, $f0, $f24
/* E17518 80241798 E662003C */  swc1      $f2, 0x3c($s3)
/* E1751C 8024179C E6620064 */  swc1      $f2, 0x64($s3)
/* E17520 802417A0 46200020 */  cvt.s.d   $f0, $f0
/* E17524 802417A4 0C00EAFF */  jal       disable_npc_shadow
/* E17528 802417A8 E6600040 */   swc1     $f0, 0x40($s3)
/* E1752C 802417AC 8E820030 */  lw        $v0, 0x30($s4)
/* E17530 802417B0 2442FFFF */  addiu     $v0, $v0, -1
/* E17534 802417B4 1C4000E0 */  bgtz      $v0, .L80241B38
/* E17538 802417B8 AE820030 */   sw       $v0, 0x30($s4)
/* E1753C 802417BC 27B20068 */  addiu     $s2, $sp, 0x68
/* E17540 802417C0 0240282D */  daddu     $a1, $s2, $zero
/* E17544 802417C4 27B0006C */  addiu     $s0, $sp, 0x6c
/* E17548 802417C8 0200302D */  daddu     $a2, $s0, $zero
/* E1754C 802417CC 27B10070 */  addiu     $s1, $sp, 0x70
/* E17550 802417D0 9684003A */  lhu       $a0, 0x3a($s4)
/* E17554 802417D4 0220382D */  daddu     $a3, $s1, $zero
/* E17558 802417D8 AFBE0010 */  sw        $fp, 0x10($sp)
/* E1755C 802417DC AFB60014 */  sw        $s6, 0x14($sp)
/* E17560 802417E0 0C046C3B */  jal       get_model_center_and_size
/* E17564 802417E4 AFB70018 */   sw       $s7, 0x18($sp)
/* E17568 802417E8 24020048 */  addiu     $v0, $zero, 0x48
/* E1756C 802417EC AE82002C */  sw        $v0, 0x2c($s4)
/* E17570 802417F0 C6600040 */  lwc1      $f0, 0x40($s3)
/* E17574 802417F4 24040214 */  addiu     $a0, $zero, 0x214
/* E17578 802417F8 E7A00010 */  swc1      $f0, 0x10($sp)
/* E1757C 802417FC 8E660038 */  lw        $a2, 0x38($s3)
/* E17580 80241800 8E67003C */  lw        $a3, 0x3c($s3)
/* E17584 80241804 0C052757 */  jal       play_sound_at_position
/* E17588 80241808 3C050020 */   lui      $a1, 0x20
/* E1758C 8024180C 0240282D */  daddu     $a1, $s2, $zero
/* E17590 80241810 0200302D */  daddu     $a2, $s0, $zero
/* E17594 80241814 9684003A */  lhu       $a0, 0x3a($s4)
/* E17598 80241818 0220382D */  daddu     $a3, $s1, $zero
/* E1759C 8024181C AFBE0010 */  sw        $fp, 0x10($sp)
/* E175A0 80241820 AFB60014 */  sw        $s6, 0x14($sp)
/* E175A4 80241824 0C046C3B */  jal       get_model_center_and_size
/* E175A8 80241828 AFB70018 */   sw       $s7, 0x18($sp)
/* E175AC 8024182C C6600064 */  lwc1      $f0, 0x64($s3)
/* E175B0 80241830 3C013F8C */  lui       $at, 0x3f8c
/* E175B4 80241834 3421CCCD */  ori       $at, $at, 0xcccd
/* E175B8 80241838 44811000 */  mtc1      $at, $f2
/* E175BC 8024183C E676001C */  swc1      $f22, 0x1c($s3)
/* E175C0 80241840 E660003C */  swc1      $f0, 0x3c($s3)
/* E175C4 80241844 E6620014 */  swc1      $f2, 0x14($s3)
/* E175C8 80241848 8E840044 */  lw        $a0, 0x44($s4)
/* E175CC 8024184C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* E175D0 80241850 AE800030 */   sw       $zero, 0x30($s4)
/* E175D4 80241854 0C046B4C */  jal       get_model_from_list_index
/* E175D8 80241858 0040202D */   daddu    $a0, $v0, $zero
/* E175DC 8024185C 0040802D */  daddu     $s0, $v0, $zero
/* E175E0 80241860 96030000 */  lhu       $v1, ($s0)
/* E175E4 80241864 3062FFFD */  andi      $v0, $v1, 0xfffd
/* E175E8 80241868 30630400 */  andi      $v1, $v1, 0x400
/* E175EC 8024186C 1460000A */  bnez      $v1, .L80241898
/* E175F0 80241870 A6020000 */   sh       $v0, ($s0)
/* E175F4 80241874 8E650038 */  lw        $a1, 0x38($s3)
/* E175F8 80241878 8E66003C */  lw        $a2, 0x3c($s3)
/* E175FC 8024187C 8E670040 */  lw        $a3, 0x40($s3)
/* E17600 80241880 0C019E40 */  jal       guTranslateF
/* E17604 80241884 26040058 */   addiu    $a0, $s0, 0x58
/* E17608 80241888 96020000 */  lhu       $v0, ($s0)
/* E1760C 8024188C 34421400 */  ori       $v0, $v0, 0x1400
/* E17610 80241890 080906CE */  j         .L80241B38
/* E17614 80241894 A6020000 */   sh       $v0, ($s0)
.L80241898:
/* E17618 80241898 8E650038 */  lw        $a1, 0x38($s3)
/* E1761C 8024189C 8E66003C */  lw        $a2, 0x3c($s3)
/* E17620 802418A0 8E670040 */  lw        $a3, 0x40($s3)
/* E17624 802418A4 0C019E40 */  jal       guTranslateF
/* E17628 802418A8 27A40028 */   addiu    $a0, $sp, 0x28
/* E1762C 802418AC 27A40028 */  addiu     $a0, $sp, 0x28
/* E17630 802418B0 26050058 */  addiu     $a1, $s0, 0x58
/* E17634 802418B4 0C019D80 */  jal       guMtxCatF
/* E17638 802418B8 00A0302D */   daddu    $a2, $a1, $zero
/* E1763C 802418BC 080906CF */  j         .L80241B3C
/* E17640 802418C0 2694001C */   addiu    $s4, $s4, 0x1c
/* E17644 802418C4 8E820030 */  lw        $v0, 0x30($s4)
/* E17648 802418C8 24420001 */  addiu     $v0, $v0, 1
/* E1764C 802418CC AE820030 */  sw        $v0, 0x30($s4)
/* E17650 802418D0 C660001C */  lwc1      $f0, 0x1c($s3)
/* E17654 802418D4 C664003C */  lwc1      $f4, 0x3c($s3)
/* E17658 802418D8 46000086 */  mov.s     $f2, $f0
/* E1765C 802418DC 46002100 */  add.s     $f4, $f4, $f0
/* E17660 802418E0 C6600014 */  lwc1      $f0, 0x14($s3)
/* E17664 802418E4 46001081 */  sub.s     $f2, $f2, $f0
/* E17668 802418E8 E664003C */  swc1      $f4, 0x3c($s3)
/* E1766C 802418EC E662001C */  swc1      $f2, 0x1c($s3)
/* E17670 802418F0 0C046C04 */  jal       get_model_list_index_from_tree_index
/* E17674 802418F4 8E840044 */   lw       $a0, 0x44($s4)
/* E17678 802418F8 0C046B4C */  jal       get_model_from_list_index
/* E1767C 802418FC 0040202D */   daddu    $a0, $v0, $zero
/* E17680 80241900 0040802D */  daddu     $s0, $v0, $zero
/* E17684 80241904 96020000 */  lhu       $v0, ($s0)
/* E17688 80241908 30420400 */  andi      $v0, $v0, 0x400
/* E1768C 8024190C 1440000A */  bnez      $v0, .L80241938
/* E17690 80241910 00000000 */   nop      
/* E17694 80241914 8E650038 */  lw        $a1, 0x38($s3)
/* E17698 80241918 8E66003C */  lw        $a2, 0x3c($s3)
/* E1769C 8024191C 8E670040 */  lw        $a3, 0x40($s3)
/* E176A0 80241920 0C019E40 */  jal       guTranslateF
/* E176A4 80241924 26040058 */   addiu    $a0, $s0, 0x58
/* E176A8 80241928 96020000 */  lhu       $v0, ($s0)
/* E176AC 8024192C 34421400 */  ori       $v0, $v0, 0x1400
/* E176B0 80241930 08090657 */  j         .L8024195C
/* E176B4 80241934 A6020000 */   sh       $v0, ($s0)
.L80241938:
/* E176B8 80241938 8E650038 */  lw        $a1, 0x38($s3)
/* E176BC 8024193C 8E66003C */  lw        $a2, 0x3c($s3)
/* E176C0 80241940 8E670040 */  lw        $a3, 0x40($s3)
/* E176C4 80241944 0C019E40 */  jal       guTranslateF
/* E176C8 80241948 27A40028 */   addiu    $a0, $sp, 0x28
/* E176CC 8024194C 27A40028 */  addiu     $a0, $sp, 0x28
/* E176D0 80241950 26050058 */  addiu     $a1, $s0, 0x58
/* E176D4 80241954 0C019D80 */  jal       guMtxCatF
/* E176D8 80241958 00A0302D */   daddu    $a2, $a1, $zero
.L8024195C:
/* E176DC 8024195C C6600064 */  lwc1      $f0, 0x64($s3)
/* E176E0 80241960 3C0141A0 */  lui       $at, 0x41a0
/* E176E4 80241964 44811000 */  mtc1      $at, $f2
/* E176E8 80241968 00000000 */  nop       
/* E176EC 8024196C 46020000 */  add.s     $f0, $f0, $f2
/* E176F0 80241970 C662003C */  lwc1      $f2, 0x3c($s3)
/* E176F4 80241974 4602003C */  c.lt.s    $f0, $f2
/* E176F8 80241978 00000000 */  nop       
/* E176FC 8024197C 45000005 */  bc1f      .L80241994
/* E17700 80241980 00000000 */   nop      
/* E17704 80241984 0C00EAE8 */  jal       enable_npc_shadow
/* E17708 80241988 0260202D */   daddu    $a0, $s3, $zero
/* E1770C 8024198C 08090667 */  j         .L8024199C
/* E17710 80241990 00000000 */   nop      
.L80241994:
/* E17714 80241994 0C00EAFF */  jal       disable_npc_shadow
/* E17718 80241998 0260202D */   daddu    $a0, $s3, $zero
.L8024199C:
/* E1771C 8024199C C660001C */  lwc1      $f0, 0x1c($s3)
/* E17720 802419A0 44801000 */  mtc1      $zero, $f2
/* E17724 802419A4 44801800 */  mtc1      $zero, $f3
/* E17728 802419A8 46000021 */  cvt.d.s   $f0, $f0
/* E1772C 802419AC 4622003C */  c.lt.d    $f0, $f2
/* E17730 802419B0 00000000 */  nop       
/* E17734 802419B4 45020061 */  bc1fl     .L80241B3C
/* E17738 802419B8 2694001C */   addiu    $s4, $s4, 0x1c
/* E1773C 802419BC C662003C */  lwc1      $f2, 0x3c($s3)
/* E17740 802419C0 C6600064 */  lwc1      $f0, 0x64($s3)
/* E17744 802419C4 4600103E */  c.le.s    $f2, $f0
/* E17748 802419C8 00000000 */  nop       
/* E1774C 802419CC 4500005A */  bc1f      .L80241B38
/* E17750 802419D0 2404014A */   addiu    $a0, $zero, 0x14a
/* E17754 802419D4 24020047 */  addiu     $v0, $zero, 0x47
/* E17758 802419D8 0C00A67F */  jal       rand_int
/* E1775C 802419DC AE82002C */   sw       $v0, 0x2c($s4)
/* E17760 802419E0 0260202D */  daddu     $a0, $s3, $zero
/* E17764 802419E4 2442005A */  addiu     $v0, $v0, 0x5a
/* E17768 802419E8 080906C2 */  j         .L80241B08
/* E1776C 802419EC AE820030 */   sw       $v0, 0x30($s4)
/* E17770 802419F0 0C05272D */  jal       play_sound
/* E17774 802419F4 2404021C */   addiu    $a0, $zero, 0x21c
/* E17778 802419F8 8E840044 */  lw        $a0, 0x44($s4)
/* E1777C 802419FC 0C046C04 */  jal       get_model_list_index_from_tree_index
/* E17780 80241A00 00000000 */   nop      
/* E17784 80241A04 0C046B4C */  jal       get_model_from_list_index
/* E17788 80241A08 0040202D */   daddu    $a0, $v0, $zero
/* E1778C 80241A0C 0040802D */  daddu     $s0, $v0, $zero
/* E17790 80241A10 0C00EAE8 */  jal       enable_npc_shadow
/* E17794 80241A14 0260202D */   daddu    $a0, $s3, $zero
/* E17798 80241A18 2402004A */  addiu     $v0, $zero, 0x4a
/* E1779C 80241A1C A660008E */  sh        $zero, 0x8e($s3)
/* E177A0 80241A20 AE82002C */  sw        $v0, 0x2c($s4)
/* E177A4 80241A24 96020000 */  lhu       $v0, ($s0)
/* E177A8 80241A28 3042FFFD */  andi      $v0, $v0, 0xfffd
/* E177AC 80241A2C A6020000 */  sh        $v0, ($s0)
/* E177B0 80241A30 8E840044 */  lw        $a0, 0x44($s4)
/* E177B4 80241A34 24080001 */  addiu     $t0, $zero, 1
/* E177B8 80241A38 0C046C04 */  jal       get_model_list_index_from_tree_index
/* E177BC 80241A3C AFA80088 */   sw       $t0, 0x88($sp)
/* E177C0 80241A40 0C046B4C */  jal       get_model_from_list_index
/* E177C4 80241A44 0040202D */   daddu    $a0, $v0, $zero
/* E177C8 80241A48 0040802D */  daddu     $s0, $v0, $zero
/* E177CC 80241A4C 2402001E */  addiu     $v0, $zero, 0x1e
/* E177D0 80241A50 C6600064 */  lwc1      $f0, 0x64($s3)
/* E177D4 80241A54 8667008E */  lh        $a3, 0x8e($s3)
/* E177D8 80241A58 3C01403E */  lui       $at, 0x403e
/* E177DC 80241A5C 44811800 */  mtc1      $at, $f3
/* E177E0 80241A60 44801000 */  mtc1      $zero, $f2
/* E177E4 80241A64 46000021 */  cvt.d.s   $f0, $f0
/* E177E8 80241A68 46220000 */  add.d     $f0, $f0, $f2
/* E177EC 80241A6C AFA20010 */  sw        $v0, 0x10($sp)
/* E177F0 80241A70 8E650064 */  lw        $a1, 0x64($s3)
/* E177F4 80241A74 46200020 */  cvt.s.d   $f0, $f0
/* E177F8 80241A78 44060000 */  mfc1      $a2, $f0
/* E177FC 80241A7C 0C00A8ED */  jal       update_lerp
/* E17800 80241A80 24040004 */   addiu    $a0, $zero, 4
/* E17804 80241A84 96020000 */  lhu       $v0, ($s0)
/* E17808 80241A88 30420400 */  andi      $v0, $v0, 0x400
/* E1780C 80241A8C 1440000A */  bnez      $v0, .L80241AB8
/* E17810 80241A90 E7A0006C */   swc1     $f0, 0x6c($sp)
/* E17814 80241A94 8E650038 */  lw        $a1, 0x38($s3)
/* E17818 80241A98 44060000 */  mfc1      $a2, $f0
/* E1781C 80241A9C 8E670040 */  lw        $a3, 0x40($s3)
/* E17820 80241AA0 0C019E40 */  jal       guTranslateF
/* E17824 80241AA4 26040058 */   addiu    $a0, $s0, 0x58
/* E17828 80241AA8 96020000 */  lhu       $v0, ($s0)
/* E1782C 80241AAC 34421400 */  ori       $v0, $v0, 0x1400
/* E17830 80241AB0 080906B7 */  j         .L80241ADC
/* E17834 80241AB4 A6020000 */   sh       $v0, ($s0)
.L80241AB8:
/* E17838 80241AB8 8E650038 */  lw        $a1, 0x38($s3)
/* E1783C 80241ABC 44060000 */  mfc1      $a2, $f0
/* E17840 80241AC0 8E670040 */  lw        $a3, 0x40($s3)
/* E17844 80241AC4 0C019E40 */  jal       guTranslateF
/* E17848 80241AC8 27A40028 */   addiu    $a0, $sp, 0x28
/* E1784C 80241ACC 27A40028 */  addiu     $a0, $sp, 0x28
/* E17850 80241AD0 26050058 */  addiu     $a1, $s0, 0x58
/* E17854 80241AD4 0C019D80 */  jal       guMtxCatF
/* E17858 80241AD8 00A0302D */   daddu    $a2, $a1, $zero
.L80241ADC:
/* E1785C 80241ADC 9662008E */  lhu       $v0, 0x8e($s3)
/* E17860 80241AE0 24420001 */  addiu     $v0, $v0, 1
/* E17864 80241AE4 A662008E */  sh        $v0, 0x8e($s3)
/* E17868 80241AE8 00021400 */  sll       $v0, $v0, 0x10
/* E1786C 80241AEC 00021403 */  sra       $v0, $v0, 0x10
/* E17870 80241AF0 2842001E */  slti      $v0, $v0, 0x1e
/* E17874 80241AF4 54400011 */  bnel      $v0, $zero, .L80241B3C
/* E17878 80241AF8 2694001C */   addiu    $s4, $s4, 0x1c
/* E1787C 80241AFC 0260202D */  daddu     $a0, $s3, $zero
/* E17880 80241B00 2402004B */  addiu     $v0, $zero, 0x4b
/* E17884 80241B04 AE82002C */  sw        $v0, 0x2c($s4)
.L80241B08:
/* E17888 80241B08 0C00EAFF */  jal       disable_npc_shadow
/* E1788C 80241B0C 2694001C */   addiu    $s4, $s4, 0x1c
/* E17890 80241B10 96020000 */  lhu       $v0, ($s0)
/* E17894 80241B14 34420002 */  ori       $v0, $v0, 2
/* E17898 80241B18 080906CF */  j         .L80241B3C
/* E1789C 80241B1C A6020000 */   sh       $v0, ($s0)
.L80241B20:
/* E178A0 80241B20 8E83002C */  lw        $v1, 0x2c($s4)
/* E178A4 80241B24 54620005 */  bnel      $v1, $v0, .L80241B3C
/* E178A8 80241B28 2694001C */   addiu    $s4, $s4, 0x1c
/* E178AC 80241B2C 24020033 */  addiu     $v0, $zero, 0x33
/* E178B0 80241B30 AE82002C */  sw        $v0, 0x2c($s4)
.L80241B34:
/* E178B4 80241B34 AE800030 */  sw        $zero, 0x30($s4)
.L80241B38:
/* E178B8 80241B38 2694001C */  addiu     $s4, $s4, 0x1c
.L80241B3C:
/* E178BC 80241B3C 26A203D4 */  addiu     $v0, $s5, 0x3d4
/* E178C0 80241B40 0282102A */  slt       $v0, $s4, $v0
/* E178C4 80241B44 1440FC41 */  bnez      $v0, .L80240C4C
/* E178C8 80241B48 00000000 */   nop      
/* E178CC 80241B4C 8EA30008 */  lw        $v1, 8($s5)
/* E178D0 80241B50 18600040 */  blez      $v1, .L80241C54
/* E178D4 80241B54 00000000 */   nop      
/* E178D8 80241B58 8EA20004 */  lw        $v0, 4($s5)
/* E178DC 80241B5C 2842000A */  slti      $v0, $v0, 0xa
/* E178E0 80241B60 10400031 */  beqz      $v0, .L80241C28
/* E178E4 80241B64 2463FFFF */   addiu    $v1, $v1, -1
/* E178E8 80241B68 240202EE */  addiu     $v0, $zero, 0x2ee
/* E178EC 80241B6C 14620003 */  bne       $v1, $v0, .L80241B7C
/* E178F0 80241B70 AEA30008 */   sw       $v1, 8($s5)
/* E178F4 80241B74 08090708 */  j         .L80241C20
/* E178F8 80241B78 240401A5 */   addiu    $a0, $zero, 0x1a5
.L80241B7C:
/* E178FC 80241B7C 24020258 */  addiu     $v0, $zero, 0x258
/* E17900 80241B80 14620003 */  bne       $v1, $v0, .L80241B90
/* E17904 80241B84 240201C2 */   addiu    $v0, $zero, 0x1c2
/* E17908 80241B88 08090708 */  j         .L80241C20
/* E1790C 80241B8C 240401A5 */   addiu    $a0, $zero, 0x1a5
.L80241B90:
/* E17910 80241B90 14620003 */  bne       $v1, $v0, .L80241BA0
/* E17914 80241B94 2402012C */   addiu    $v0, $zero, 0x12c
/* E17918 80241B98 08090708 */  j         .L80241C20
/* E1791C 80241B9C 240401A5 */   addiu    $a0, $zero, 0x1a5
.L80241BA0:
/* E17920 80241BA0 14620003 */  bne       $v1, $v0, .L80241BB0
/* E17924 80241BA4 2402010E */   addiu    $v0, $zero, 0x10e
/* E17928 80241BA8 08090708 */  j         .L80241C20
/* E1792C 80241BAC 240401A6 */   addiu    $a0, $zero, 0x1a6
.L80241BB0:
/* E17930 80241BB0 14620003 */  bne       $v1, $v0, .L80241BC0
/* E17934 80241BB4 240200F0 */   addiu    $v0, $zero, 0xf0
/* E17938 80241BB8 08090708 */  j         .L80241C20
/* E1793C 80241BBC 240401A6 */   addiu    $a0, $zero, 0x1a6
.L80241BC0:
/* E17940 80241BC0 14620003 */  bne       $v1, $v0, .L80241BD0
/* E17944 80241BC4 240200D2 */   addiu    $v0, $zero, 0xd2
/* E17948 80241BC8 08090708 */  j         .L80241C20
/* E1794C 80241BCC 240401A6 */   addiu    $a0, $zero, 0x1a6
.L80241BD0:
/* E17950 80241BD0 14620003 */  bne       $v1, $v0, .L80241BE0
/* E17954 80241BD4 240200B4 */   addiu    $v0, $zero, 0xb4
/* E17958 80241BD8 08090708 */  j         .L80241C20
/* E1795C 80241BDC 240401A6 */   addiu    $a0, $zero, 0x1a6
.L80241BE0:
/* E17960 80241BE0 14620003 */  bne       $v1, $v0, .L80241BF0
/* E17964 80241BE4 24020096 */   addiu    $v0, $zero, 0x96
/* E17968 80241BE8 08090708 */  j         .L80241C20
/* E1796C 80241BEC 240401A6 */   addiu    $a0, $zero, 0x1a6
.L80241BF0:
/* E17970 80241BF0 1062000A */  beq       $v1, $v0, .L80241C1C
/* E17974 80241BF4 24020078 */   addiu    $v0, $zero, 0x78
/* E17978 80241BF8 10620008 */  beq       $v1, $v0, .L80241C1C
/* E1797C 80241BFC 2402005A */   addiu    $v0, $zero, 0x5a
/* E17980 80241C00 8EA30008 */  lw        $v1, 8($s5)
/* E17984 80241C04 10620005 */  beq       $v1, $v0, .L80241C1C
/* E17988 80241C08 2402003C */   addiu    $v0, $zero, 0x3c
/* E1798C 80241C0C 10620003 */  beq       $v1, $v0, .L80241C1C
/* E17990 80241C10 2402001E */   addiu    $v0, $zero, 0x1e
/* E17994 80241C14 14620004 */  bne       $v1, $v0, .L80241C28
/* E17998 80241C18 00000000 */   nop      
.L80241C1C:
/* E1799C 80241C1C 240401A7 */  addiu     $a0, $zero, 0x1a7
.L80241C20:
/* E179A0 80241C20 0C05272D */  jal       play_sound
/* E179A4 80241C24 00000000 */   nop      
.L80241C28:
/* E179A8 80241C28 8EA20008 */  lw        $v0, 8($s5)
/* E179AC 80241C2C 18400009 */  blez      $v0, .L80241C54
/* E179B0 80241C30 2402000A */   addiu    $v0, $zero, 0xa
/* E179B4 80241C34 8EA30004 */  lw        $v1, 4($s5)
/* E179B8 80241C38 14620006 */  bne       $v1, $v0, .L80241C54
/* E179BC 80241C3C 00000000 */   nop      
/* E179C0 80241C40 8EA30028 */  lw        $v1, 0x28($s5)
/* E179C4 80241C44 30620001 */  andi      $v0, $v1, 1
/* E179C8 80241C48 14400002 */  bnez      $v0, .L80241C54
/* E179CC 80241C4C 34620003 */   ori      $v0, $v1, 3
/* E179D0 80241C50 AEA20028 */  sw        $v0, 0x28($s5)
.L80241C54:
/* E179D4 80241C54 8EA20008 */  lw        $v0, 8($s5)
/* E179D8 80241C58 1440000A */  bnez      $v0, .L80241C84
/* E179DC 80241C5C 00000000 */   nop      
/* E179E0 80241C60 8FA80088 */  lw        $t0, 0x88($sp)
/* E179E4 80241C64 11000007 */  beqz      $t0, .L80241C84
/* E179E8 80241C68 00000000 */   nop      
/* E179EC 80241C6C 8EA30028 */  lw        $v1, 0x28($s5)
/* E179F0 80241C70 30620001 */  andi      $v0, $v1, 1
/* E179F4 80241C74 14400005 */  bnez      $v0, .L80241C8C
/* E179F8 80241C78 30620002 */   andi     $v0, $v1, 2
/* E179FC 80241C7C 34620003 */  ori       $v0, $v1, 3
/* E17A00 80241C80 AEA20028 */  sw        $v0, 0x28($s5)
.L80241C84:
/* E17A04 80241C84 8EA30028 */  lw        $v1, 0x28($s5)
/* E17A08 80241C88 30620002 */  andi      $v0, $v1, 2
.L80241C8C:
/* E17A0C 80241C8C 10400010 */  beqz      $v0, .L80241CD0
/* E17A10 80241C90 2402FFFD */   addiu    $v0, $zero, -3
/* E17A14 80241C94 00621024 */  and       $v0, $v1, $v0
/* E17A18 80241C98 AEA20028 */  sw        $v0, 0x28($s5)
/* E17A1C 80241C9C 30620001 */  andi      $v0, $v1, 1
/* E17A20 80241CA0 10400007 */  beqz      $v0, .L80241CC0
/* E17A24 80241CA4 00000000 */   nop      
/* E17A28 80241CA8 0C03805E */  jal       disable_player_input
/* E17A2C 80241CAC 00000000 */   nop      
/* E17A30 80241CB0 0C03BD8A */  jal       func_800EF628
/* E17A34 80241CB4 00000000 */   nop      
/* E17A38 80241CB8 08090734 */  j         .L80241CD0
/* E17A3C 80241CBC 00000000 */   nop      
.L80241CC0:
/* E17A40 80241CC0 0C038069 */  jal       enable_player_input
/* E17A44 80241CC4 00000000 */   nop      
/* E17A48 80241CC8 0C03BD80 */  jal       func_800EF600
/* E17A4C 80241CCC 00000000 */   nop      
.L80241CD0:
/* E17A50 80241CD0 8FA80088 */  lw        $t0, 0x88($sp)
/* E17A54 80241CD4 1500000E */  bnez      $t0, .L80241D10
/* E17A58 80241CD8 2402000A */   addiu    $v0, $zero, 0xa
/* E17A5C 80241CDC 8EA30004 */  lw        $v1, 4($s5)
/* E17A60 80241CE0 5062000A */  beql      $v1, $v0, .L80241D0C
/* E17A64 80241CE4 24080001 */   addiu    $t0, $zero, 1
/* E17A68 80241CE8 8EA20008 */  lw        $v0, 8($s5)
/* E17A6C 80241CEC 14400008 */  bnez      $v0, .L80241D10
/* E17A70 80241CF0 00000000 */   nop      
/* E17A74 80241CF4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* E17A78 80241CF8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* E17A7C 80241CFC 804300B4 */  lb        $v1, 0xb4($v0)
/* E17A80 80241D00 24020012 */  addiu     $v0, $zero, 0x12
/* E17A84 80241D04 10620002 */  beq       $v1, $v0, .L80241D10
/* E17A88 80241D08 24080001 */   addiu    $t0, $zero, 1
.L80241D0C:
/* E17A8C 80241D0C AFA80084 */  sw        $t0, 0x84($sp)
.L80241D10:
/* E17A90 80241D10 8FA80084 */  lw        $t0, 0x84($sp)
/* E17A94 80241D14 1100001B */  beqz      $t0, .L80241D84
/* E17A98 80241D18 0000102D */   daddu    $v0, $zero, $zero
/* E17A9C 80241D1C 8EA20028 */  lw        $v0, 0x28($s5)
/* E17AA0 80241D20 30420001 */  andi      $v0, $v0, 1
/* E17AA4 80241D24 10400005 */  beqz      $v0, .L80241D3C
/* E17AA8 80241D28 00000000 */   nop      
/* E17AAC 80241D2C 0C038069 */  jal       enable_player_input
/* E17AB0 80241D30 00000000 */   nop      
/* E17AB4 80241D34 0C03BD80 */  jal       func_800EF600
/* E17AB8 80241D38 00000000 */   nop      
.L80241D3C:
/* E17ABC 80241D3C 3C10800F */  lui       $s0, %hi(gPlayerStatusPtr)
/* E17AC0 80241D40 26107B30 */  addiu     $s0, $s0, %lo(gPlayerStatusPtr)
/* E17AC4 80241D44 8E020000 */  lw        $v0, ($s0)
/* E17AC8 80241D48 3C014334 */  lui       $at, 0x4334
/* E17ACC 80241D4C 44810000 */  mtc1      $at, $f0
/* E17AD0 80241D50 AEA00028 */  sw        $zero, 0x28($s5)
/* E17AD4 80241D54 E4400080 */  swc1      $f0, 0x80($v0)
/* E17AD8 80241D58 8EA20008 */  lw        $v0, 8($s5)
/* E17ADC 80241D5C 14400002 */  bnez      $v0, .L80241D68
/* E17AE0 80241D60 240400D4 */   addiu    $a0, $zero, 0xd4
/* E17AE4 80241D64 2404021D */  addiu     $a0, $zero, 0x21d
.L80241D68:
/* E17AE8 80241D68 0C05272D */  jal       play_sound
/* E17AEC 80241D6C 00000000 */   nop      
/* E17AF0 80241D70 3C030001 */  lui       $v1, 1
/* E17AF4 80241D74 8E020000 */  lw        $v0, ($s0)
/* E17AF8 80241D78 34630002 */  ori       $v1, $v1, 2
/* E17AFC 80241D7C AC4300B8 */  sw        $v1, 0xb8($v0)
/* E17B00 80241D80 24020002 */  addiu     $v0, $zero, 2
.L80241D84:
/* E17B04 80241D84 8FBF00B4 */  lw        $ra, 0xb4($sp)
/* E17B08 80241D88 8FBE00B0 */  lw        $fp, 0xb0($sp)
/* E17B0C 80241D8C 8FB700AC */  lw        $s7, 0xac($sp)
/* E17B10 80241D90 8FB600A8 */  lw        $s6, 0xa8($sp)
/* E17B14 80241D94 8FB500A4 */  lw        $s5, 0xa4($sp)
/* E17B18 80241D98 8FB400A0 */  lw        $s4, 0xa0($sp)
/* E17B1C 80241D9C 8FB3009C */  lw        $s3, 0x9c($sp)
/* E17B20 80241DA0 8FB20098 */  lw        $s2, 0x98($sp)
/* E17B24 80241DA4 8FB10094 */  lw        $s1, 0x94($sp)
/* E17B28 80241DA8 8FB00090 */  lw        $s0, 0x90($sp)
/* E17B2C 80241DAC D7BE00E0 */  ldc1      $f30, 0xe0($sp)
/* E17B30 80241DB0 D7BC00D8 */  ldc1      $f28, 0xd8($sp)
/* E17B34 80241DB4 D7BA00D0 */  ldc1      $f26, 0xd0($sp)
/* E17B38 80241DB8 D7B800C8 */  ldc1      $f24, 0xc8($sp)
/* E17B3C 80241DBC D7B600C0 */  ldc1      $f22, 0xc0($sp)
/* E17B40 80241DC0 D7B400B8 */  ldc1      $f20, 0xb8($sp)
/* E17B44 80241DC4 03E00008 */  jr        $ra
/* E17B48 80241DC8 27BD00E8 */   addiu    $sp, $sp, 0xe8
