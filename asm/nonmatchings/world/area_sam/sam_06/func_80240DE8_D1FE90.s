.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DE8_D20C78
/* D20C78 80240DE8 27BDFF88 */  addiu     $sp, $sp, -0x78
/* D20C7C 80240DEC AFB3004C */  sw        $s3, 0x4c($sp)
/* D20C80 80240DF0 0080982D */  daddu     $s3, $a0, $zero
/* D20C84 80240DF4 AFBF0054 */  sw        $ra, 0x54($sp)
/* D20C88 80240DF8 AFB40050 */  sw        $s4, 0x50($sp)
/* D20C8C 80240DFC AFB20048 */  sw        $s2, 0x48($sp)
/* D20C90 80240E00 AFB10044 */  sw        $s1, 0x44($sp)
/* D20C94 80240E04 AFB00040 */  sw        $s0, 0x40($sp)
/* D20C98 80240E08 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* D20C9C 80240E0C F7B80068 */  sdc1      $f24, 0x68($sp)
/* D20CA0 80240E10 F7B60060 */  sdc1      $f22, 0x60($sp)
/* D20CA4 80240E14 F7B40058 */  sdc1      $f20, 0x58($sp)
/* D20CA8 80240E18 8E710148 */  lw        $s1, 0x148($s3)
/* D20CAC 80240E1C 00A0902D */  daddu     $s2, $a1, $zero
/* D20CB0 80240E20 86240008 */  lh        $a0, 8($s1)
/* D20CB4 80240E24 0C00EABB */  jal       get_npc_unsafe
/* D20CB8 80240E28 00C0A02D */   daddu    $s4, $a2, $zero
/* D20CBC 80240E2C 0040802D */  daddu     $s0, $v0, $zero
/* D20CC0 80240E30 C6200078 */  lwc1      $f0, 0x78($s1)
/* D20CC4 80240E34 46800020 */  cvt.s.w   $f0, $f0
/* D20CC8 80240E38 46000021 */  cvt.d.s   $f0, $f0
/* D20CCC 80240E3C 3C014059 */  lui       $at, 0x4059
/* D20CD0 80240E40 44811800 */  mtc1      $at, $f3
/* D20CD4 80240E44 44801000 */  mtc1      $zero, $f2
/* D20CD8 80240E48 8602008E */  lh        $v0, 0x8e($s0)
/* D20CDC 80240E4C 9603008E */  lhu       $v1, 0x8e($s0)
/* D20CE0 80240E50 46220003 */  div.d     $f0, $f0, $f2
/* D20CE4 80240E54 46200620 */  cvt.s.d   $f24, $f0
/* D20CE8 80240E58 C6200088 */  lwc1      $f0, 0x88($s1)
/* D20CEC 80240E5C 46800020 */  cvt.s.w   $f0, $f0
/* D20CF0 80240E60 46000021 */  cvt.d.s   $f0, $f0
/* D20CF4 80240E64 46220003 */  div.d     $f0, $f0, $f2
/* D20CF8 80240E68 46200020 */  cvt.s.d   $f0, $f0
/* D20CFC 80240E6C 18400003 */  blez      $v0, .L80240E7C
/* D20D00 80240E70 4600C680 */   add.s    $f26, $f24, $f0
/* D20D04 80240E74 2462FFFF */  addiu     $v0, $v1, -1
/* D20D08 80240E78 A602008E */  sh        $v0, 0x8e($s0)
.L80240E7C:
/* D20D0C 80240E7C 8E220070 */  lw        $v0, 0x70($s1)
/* D20D10 80240E80 18400034 */  blez      $v0, .L80240F54
/* D20D14 80240E84 00000000 */   nop      
/* D20D18 80240E88 C62C0074 */  lwc1      $f12, 0x74($s1)
/* D20D1C 80240E8C 46806320 */  cvt.s.w   $f12, $f12
/* D20D20 80240E90 44820000 */  mtc1      $v0, $f0
/* D20D24 80240E94 00000000 */  nop       
/* D20D28 80240E98 46800020 */  cvt.s.w   $f0, $f0
/* D20D2C 80240E9C 46000021 */  cvt.d.s   $f0, $f0
/* D20D30 80240EA0 46220003 */  div.d     $f0, $f0, $f2
/* D20D34 80240EA4 0C00A8BB */  jal       sin_deg
/* D20D38 80240EA8 462005A0 */   cvt.s.d  $f22, $f0
/* D20D3C 80240EAC 8E020000 */  lw        $v0, ($s0)
/* D20D40 80240EB0 30420008 */  andi      $v0, $v0, 8
/* D20D44 80240EB4 10400003 */  beqz      $v0, .L80240EC4
/* D20D48 80240EB8 46000506 */   mov.s    $f20, $f0
/* D20D4C 80240EBC 080903C1 */  j         .L80240F04
/* D20D50 80240EC0 0000102D */   daddu    $v0, $zero, $zero
.L80240EC4:
/* D20D54 80240EC4 27A50028 */  addiu     $a1, $sp, 0x28
/* D20D58 80240EC8 27A6002C */  addiu     $a2, $sp, 0x2c
/* D20D5C 80240ECC C6000038 */  lwc1      $f0, 0x38($s0)
/* D20D60 80240ED0 C602003C */  lwc1      $f2, 0x3c($s0)
/* D20D64 80240ED4 C6040040 */  lwc1      $f4, 0x40($s0)
/* D20D68 80240ED8 3C01447A */  lui       $at, 0x447a
/* D20D6C 80240EDC 44813000 */  mtc1      $at, $f6
/* D20D70 80240EE0 27A20034 */  addiu     $v0, $sp, 0x34
/* D20D74 80240EE4 E7A00028 */  swc1      $f0, 0x28($sp)
/* D20D78 80240EE8 E7A2002C */  swc1      $f2, 0x2c($sp)
/* D20D7C 80240EEC E7A40030 */  swc1      $f4, 0x30($sp)
/* D20D80 80240EF0 E7A60034 */  swc1      $f6, 0x34($sp)
/* D20D84 80240EF4 AFA20010 */  sw        $v0, 0x10($sp)
/* D20D88 80240EF8 8E040080 */  lw        $a0, 0x80($s0)
/* D20D8C 80240EFC 0C0372DF */  jal       func_800DCB7C
/* D20D90 80240F00 27A70030 */   addiu    $a3, $sp, 0x30
.L80240F04:
/* D20D94 80240F04 10400007 */  beqz      $v0, .L80240F24
/* D20D98 80240F08 00000000 */   nop      
/* D20D9C 80240F0C 4616A082 */  mul.s     $f2, $f20, $f22
/* D20DA0 80240F10 00000000 */  nop       
/* D20DA4 80240F14 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* D20DA8 80240F18 46180000 */  add.s     $f0, $f0, $f24
/* D20DAC 80240F1C 080903CC */  j         .L80240F30
/* D20DB0 80240F20 46020000 */   add.s    $f0, $f0, $f2
.L80240F24:
/* D20DB4 80240F24 4616A002 */  mul.s     $f0, $f20, $f22
/* D20DB8 80240F28 00000000 */  nop       
/* D20DBC 80240F2C 4600D000 */  add.s     $f0, $f26, $f0
.L80240F30:
/* D20DC0 80240F30 E600003C */  swc1      $f0, 0x3c($s0)
/* D20DC4 80240F34 8E220074 */  lw        $v0, 0x74($s1)
/* D20DC8 80240F38 2442000A */  addiu     $v0, $v0, 0xa
/* D20DCC 80240F3C 44826000 */  mtc1      $v0, $f12
/* D20DD0 80240F40 00000000 */  nop       
/* D20DD4 80240F44 0C00A6C9 */  jal       clamp_angle
/* D20DD8 80240F48 46806320 */   cvt.s.w  $f12, $f12
/* D20DDC 80240F4C 4600020D */  trunc.w.s $f8, $f0
/* D20DE0 80240F50 E6280074 */  swc1      $f8, 0x74($s1)
.L80240F54:
/* D20DE4 80240F54 8E220090 */  lw        $v0, 0x90($s1)
/* D20DE8 80240F58 1C400040 */  bgtz      $v0, .L8024105C
/* D20DEC 80240F5C 2442FFFF */   addiu    $v0, $v0, -1
/* D20DF0 80240F60 860200A8 */  lh        $v0, 0xa8($s0)
/* D20DF4 80240F64 C600003C */  lwc1      $f0, 0x3c($s0)
/* D20DF8 80240F68 44821000 */  mtc1      $v0, $f2
/* D20DFC 80240F6C 00000000 */  nop       
/* D20E00 80240F70 468010A0 */  cvt.s.w   $f2, $f2
/* D20E04 80240F74 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* D20E08 80240F78 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* D20E0C 80240F7C 46020000 */  add.s     $f0, $f0, $f2
/* D20E10 80240F80 3C014024 */  lui       $at, 0x4024
/* D20E14 80240F84 44812800 */  mtc1      $at, $f5
/* D20E18 80240F88 44802000 */  mtc1      $zero, $f4
/* D20E1C 80240F8C C442002C */  lwc1      $f2, 0x2c($v0)
/* D20E20 80240F90 46000021 */  cvt.d.s   $f0, $f0
/* D20E24 80240F94 46240000 */  add.d     $f0, $f0, $f4
/* D20E28 80240F98 460010A1 */  cvt.d.s   $f2, $f2
/* D20E2C 80240F9C 4620103C */  c.lt.d    $f2, $f0
/* D20E30 80240FA0 00000000 */  nop       
/* D20E34 80240FA4 4500002E */  bc1f      .L80241060
/* D20E38 80240FA8 0280202D */   daddu    $a0, $s4, $zero
/* D20E3C 80240FAC 24020001 */  addiu     $v0, $zero, 1
/* D20E40 80240FB0 AFA20010 */  sw        $v0, 0x10($sp)
/* D20E44 80240FB4 8E460024 */  lw        $a2, 0x24($s2)
/* D20E48 80240FB8 8E470028 */  lw        $a3, 0x28($s2)
/* D20E4C 80240FBC 0C01242D */  jal       func_800490B4
/* D20E50 80240FC0 0220282D */   daddu    $a1, $s1, $zero
/* D20E54 80240FC4 10400026 */  beqz      $v0, .L80241060
/* D20E58 80240FC8 0000202D */   daddu    $a0, $zero, $zero
/* D20E5C 80240FCC 0200282D */  daddu     $a1, $s0, $zero
/* D20E60 80240FD0 0000302D */  daddu     $a2, $zero, $zero
/* D20E64 80240FD4 2412000C */  addiu     $s2, $zero, 0xc
/* D20E68 80240FD8 860300A8 */  lh        $v1, 0xa8($s0)
/* D20E6C 80240FDC 3C013F80 */  lui       $at, 0x3f80
/* D20E70 80240FE0 44810000 */  mtc1      $at, $f0
/* D20E74 80240FE4 3C014000 */  lui       $at, 0x4000
/* D20E78 80240FE8 44811000 */  mtc1      $at, $f2
/* D20E7C 80240FEC 3C01C1A0 */  lui       $at, 0xc1a0
/* D20E80 80240FF0 44812000 */  mtc1      $at, $f4
/* D20E84 80240FF4 44834000 */  mtc1      $v1, $f8
/* D20E88 80240FF8 00000000 */  nop       
/* D20E8C 80240FFC 46804220 */  cvt.s.w   $f8, $f8
/* D20E90 80241000 44074000 */  mfc1      $a3, $f8
/* D20E94 80241004 27A20038 */  addiu     $v0, $sp, 0x38
/* D20E98 80241008 AFB2001C */  sw        $s2, 0x1c($sp)
/* D20E9C 8024100C AFA20020 */  sw        $v0, 0x20($sp)
/* D20EA0 80241010 E7A00010 */  swc1      $f0, 0x10($sp)
/* D20EA4 80241014 E7A20014 */  swc1      $f2, 0x14($sp)
/* D20EA8 80241018 0C01BFA4 */  jal       fx_emote
/* D20EAC 8024101C E7A40018 */   swc1     $f4, 0x18($sp)
/* D20EB0 80241020 0200202D */  daddu     $a0, $s0, $zero
/* D20EB4 80241024 240502F4 */  addiu     $a1, $zero, 0x2f4
/* D20EB8 80241028 C480003C */  lwc1      $f0, 0x3c($a0)
/* D20EBC 8024102C 3C060020 */  lui       $a2, 0x20
/* D20EC0 80241030 0C012530 */  jal       func_800494C0
/* D20EC4 80241034 E4800064 */   swc1     $f0, 0x64($a0)
/* D20EC8 80241038 8E220018 */  lw        $v0, 0x18($s1)
/* D20ECC 8024103C 9442002A */  lhu       $v0, 0x2a($v0)
/* D20ED0 80241040 30420001 */  andi      $v0, $v0, 1
/* D20ED4 80241044 10400003 */  beqz      $v0, .L80241054
/* D20ED8 80241048 2402000A */   addiu    $v0, $zero, 0xa
/* D20EDC 8024104C 0809043F */  j         .L802410FC
/* D20EE0 80241050 AE620070 */   sw       $v0, 0x70($s3)
.L80241054:
/* D20EE4 80241054 0809043F */  j         .L802410FC
/* D20EE8 80241058 AE720070 */   sw       $s2, 0x70($s3)
.L8024105C:
/* D20EEC 8024105C AE220090 */  sw        $v0, 0x90($s1)
.L80241060:
/* D20EF0 80241060 8602008C */  lh        $v0, 0x8c($s0)
/* D20EF4 80241064 14400025 */  bnez      $v0, .L802410FC
/* D20EF8 80241068 00000000 */   nop      
/* D20EFC 8024106C 8602008E */  lh        $v0, 0x8e($s0)
/* D20F00 80241070 1C400022 */  bgtz      $v0, .L802410FC
/* D20F04 80241074 00000000 */   nop      
/* D20F08 80241078 8E620074 */  lw        $v0, 0x74($s3)
/* D20F0C 8024107C 2442FFFF */  addiu     $v0, $v0, -1
/* D20F10 80241080 1840001D */  blez      $v0, .L802410F8
/* D20F14 80241084 AE620074 */   sw       $v0, 0x74($s3)
/* D20F18 80241088 8E220018 */  lw        $v0, 0x18($s1)
/* D20F1C 8024108C 9442002A */  lhu       $v0, 0x2a($v0)
/* D20F20 80241090 30420010 */  andi      $v0, $v0, 0x10
/* D20F24 80241094 14400007 */  bnez      $v0, .L802410B4
/* D20F28 80241098 00000000 */   nop      
/* D20F2C 8024109C C600000C */  lwc1      $f0, 0xc($s0)
/* D20F30 802410A0 3C014334 */  lui       $at, 0x4334
/* D20F34 802410A4 44816000 */  mtc1      $at, $f12
/* D20F38 802410A8 0C00A6C9 */  jal       clamp_angle
/* D20F3C 802410AC 460C0300 */   add.s    $f12, $f0, $f12
/* D20F40 802410B0 E600000C */  swc1      $f0, 0xc($s0)
.L802410B4:
/* D20F44 802410B4 0C00A67F */  jal       rand_int
/* D20F48 802410B8 240403E8 */   addiu    $a0, $zero, 0x3e8
/* D20F4C 802410BC 3C032E8B */  lui       $v1, 0x2e8b
/* D20F50 802410C0 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* D20F54 802410C4 00430018 */  mult      $v0, $v1
/* D20F58 802410C8 00021FC3 */  sra       $v1, $v0, 0x1f
/* D20F5C 802410CC 00004010 */  mfhi      $t0
/* D20F60 802410D0 00082043 */  sra       $a0, $t0, 1
/* D20F64 802410D4 00832023 */  subu      $a0, $a0, $v1
/* D20F68 802410D8 00041840 */  sll       $v1, $a0, 1
/* D20F6C 802410DC 00641821 */  addu      $v1, $v1, $a0
/* D20F70 802410E0 00031880 */  sll       $v1, $v1, 2
/* D20F74 802410E4 00641823 */  subu      $v1, $v1, $a0
/* D20F78 802410E8 00431023 */  subu      $v0, $v0, $v1
/* D20F7C 802410EC 24420005 */  addiu     $v0, $v0, 5
/* D20F80 802410F0 0809043F */  j         .L802410FC
/* D20F84 802410F4 A602008E */   sh       $v0, 0x8e($s0)
.L802410F8:
/* D20F88 802410F8 AE600070 */  sw        $zero, 0x70($s3)
.L802410FC:
/* D20F8C 802410FC 8FBF0054 */  lw        $ra, 0x54($sp)
/* D20F90 80241100 8FB40050 */  lw        $s4, 0x50($sp)
/* D20F94 80241104 8FB3004C */  lw        $s3, 0x4c($sp)
/* D20F98 80241108 8FB20048 */  lw        $s2, 0x48($sp)
/* D20F9C 8024110C 8FB10044 */  lw        $s1, 0x44($sp)
/* D20FA0 80241110 8FB00040 */  lw        $s0, 0x40($sp)
/* D20FA4 80241114 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* D20FA8 80241118 D7B80068 */  ldc1      $f24, 0x68($sp)
/* D20FAC 8024111C D7B60060 */  ldc1      $f22, 0x60($sp)
/* D20FB0 80241120 D7B40058 */  ldc1      $f20, 0x58($sp)
/* D20FB4 80241124 03E00008 */  jr        $ra
/* D20FB8 80241128 27BD0078 */   addiu    $sp, $sp, 0x78
