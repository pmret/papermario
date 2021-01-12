.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CBC_C4889C
/* C4889C 80241CBC 27BDFF88 */  addiu     $sp, $sp, -0x78
/* C488A0 80241CC0 AFB3004C */  sw        $s3, 0x4c($sp)
/* C488A4 80241CC4 0080982D */  daddu     $s3, $a0, $zero
/* C488A8 80241CC8 AFBF0054 */  sw        $ra, 0x54($sp)
/* C488AC 80241CCC AFB40050 */  sw        $s4, 0x50($sp)
/* C488B0 80241CD0 AFB20048 */  sw        $s2, 0x48($sp)
/* C488B4 80241CD4 AFB10044 */  sw        $s1, 0x44($sp)
/* C488B8 80241CD8 AFB00040 */  sw        $s0, 0x40($sp)
/* C488BC 80241CDC F7BA0070 */  sdc1      $f26, 0x70($sp)
/* C488C0 80241CE0 F7B80068 */  sdc1      $f24, 0x68($sp)
/* C488C4 80241CE4 F7B60060 */  sdc1      $f22, 0x60($sp)
/* C488C8 80241CE8 F7B40058 */  sdc1      $f20, 0x58($sp)
/* C488CC 80241CEC 8E710148 */  lw        $s1, 0x148($s3)
/* C488D0 80241CF0 00A0902D */  daddu     $s2, $a1, $zero
/* C488D4 80241CF4 86240008 */  lh        $a0, 8($s1)
/* C488D8 80241CF8 0C00EABB */  jal       get_npc_unsafe
/* C488DC 80241CFC 00C0A02D */   daddu    $s4, $a2, $zero
/* C488E0 80241D00 0040802D */  daddu     $s0, $v0, $zero
/* C488E4 80241D04 C6200078 */  lwc1      $f0, 0x78($s1)
/* C488E8 80241D08 46800020 */  cvt.s.w   $f0, $f0
/* C488EC 80241D0C 46000021 */  cvt.d.s   $f0, $f0
/* C488F0 80241D10 3C014059 */  lui       $at, 0x4059
/* C488F4 80241D14 44811800 */  mtc1      $at, $f3
/* C488F8 80241D18 44801000 */  mtc1      $zero, $f2
/* C488FC 80241D1C 8602008E */  lh        $v0, 0x8e($s0)
/* C48900 80241D20 9603008E */  lhu       $v1, 0x8e($s0)
/* C48904 80241D24 46220003 */  div.d     $f0, $f0, $f2
/* C48908 80241D28 46200620 */  cvt.s.d   $f24, $f0
/* C4890C 80241D2C C6200088 */  lwc1      $f0, 0x88($s1)
/* C48910 80241D30 46800020 */  cvt.s.w   $f0, $f0
/* C48914 80241D34 46000021 */  cvt.d.s   $f0, $f0
/* C48918 80241D38 46220003 */  div.d     $f0, $f0, $f2
/* C4891C 80241D3C 46200020 */  cvt.s.d   $f0, $f0
/* C48920 80241D40 18400003 */  blez      $v0, .L80241D50
/* C48924 80241D44 4600C680 */   add.s    $f26, $f24, $f0
/* C48928 80241D48 2462FFFF */  addiu     $v0, $v1, -1
/* C4892C 80241D4C A602008E */  sh        $v0, 0x8e($s0)
.L80241D50:
/* C48930 80241D50 8E220070 */  lw        $v0, 0x70($s1)
/* C48934 80241D54 18400034 */  blez      $v0, .L80241E28
/* C48938 80241D58 00000000 */   nop
/* C4893C 80241D5C C62C0074 */  lwc1      $f12, 0x74($s1)
/* C48940 80241D60 46806320 */  cvt.s.w   $f12, $f12
/* C48944 80241D64 44820000 */  mtc1      $v0, $f0
/* C48948 80241D68 00000000 */  nop
/* C4894C 80241D6C 46800020 */  cvt.s.w   $f0, $f0
/* C48950 80241D70 46000021 */  cvt.d.s   $f0, $f0
/* C48954 80241D74 46220003 */  div.d     $f0, $f0, $f2
/* C48958 80241D78 0C00A8BB */  jal       sin_deg
/* C4895C 80241D7C 462005A0 */   cvt.s.d  $f22, $f0
/* C48960 80241D80 8E020000 */  lw        $v0, ($s0)
/* C48964 80241D84 30420008 */  andi      $v0, $v0, 8
/* C48968 80241D88 10400003 */  beqz      $v0, .L80241D98
/* C4896C 80241D8C 46000506 */   mov.s    $f20, $f0
/* C48970 80241D90 08090776 */  j         .L80241DD8
/* C48974 80241D94 0000102D */   daddu    $v0, $zero, $zero
.L80241D98:
/* C48978 80241D98 27A50028 */  addiu     $a1, $sp, 0x28
/* C4897C 80241D9C 27A6002C */  addiu     $a2, $sp, 0x2c
/* C48980 80241DA0 C6000038 */  lwc1      $f0, 0x38($s0)
/* C48984 80241DA4 C602003C */  lwc1      $f2, 0x3c($s0)
/* C48988 80241DA8 C6040040 */  lwc1      $f4, 0x40($s0)
/* C4898C 80241DAC 3C01447A */  lui       $at, 0x447a
/* C48990 80241DB0 44813000 */  mtc1      $at, $f6
/* C48994 80241DB4 27A20034 */  addiu     $v0, $sp, 0x34
/* C48998 80241DB8 E7A00028 */  swc1      $f0, 0x28($sp)
/* C4899C 80241DBC E7A2002C */  swc1      $f2, 0x2c($sp)
/* C489A0 80241DC0 E7A40030 */  swc1      $f4, 0x30($sp)
/* C489A4 80241DC4 E7A60034 */  swc1      $f6, 0x34($sp)
/* C489A8 80241DC8 AFA20010 */  sw        $v0, 0x10($sp)
/* C489AC 80241DCC 8E040080 */  lw        $a0, 0x80($s0)
/* C489B0 80241DD0 0C0372DF */  jal       func_800DCB7C
/* C489B4 80241DD4 27A70030 */   addiu    $a3, $sp, 0x30
.L80241DD8:
/* C489B8 80241DD8 10400007 */  beqz      $v0, .L80241DF8
/* C489BC 80241DDC 00000000 */   nop
/* C489C0 80241DE0 4616A082 */  mul.s     $f2, $f20, $f22
/* C489C4 80241DE4 00000000 */  nop
/* C489C8 80241DE8 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* C489CC 80241DEC 46180000 */  add.s     $f0, $f0, $f24
/* C489D0 80241DF0 08090781 */  j         .L80241E04
/* C489D4 80241DF4 46020000 */   add.s    $f0, $f0, $f2
.L80241DF8:
/* C489D8 80241DF8 4616A002 */  mul.s     $f0, $f20, $f22
/* C489DC 80241DFC 00000000 */  nop
/* C489E0 80241E00 4600D000 */  add.s     $f0, $f26, $f0
.L80241E04:
/* C489E4 80241E04 E600003C */  swc1      $f0, 0x3c($s0)
/* C489E8 80241E08 8E220074 */  lw        $v0, 0x74($s1)
/* C489EC 80241E0C 2442000A */  addiu     $v0, $v0, 0xa
/* C489F0 80241E10 44826000 */  mtc1      $v0, $f12
/* C489F4 80241E14 00000000 */  nop
/* C489F8 80241E18 0C00A6C9 */  jal       clamp_angle
/* C489FC 80241E1C 46806320 */   cvt.s.w  $f12, $f12
/* C48A00 80241E20 4600020D */  trunc.w.s $f8, $f0
/* C48A04 80241E24 E6280074 */  swc1      $f8, 0x74($s1)
.L80241E28:
/* C48A08 80241E28 8E220090 */  lw        $v0, 0x90($s1)
/* C48A0C 80241E2C 1C400040 */  bgtz      $v0, .L80241F30
/* C48A10 80241E30 2442FFFF */   addiu    $v0, $v0, -1
/* C48A14 80241E34 860200A8 */  lh        $v0, 0xa8($s0)
/* C48A18 80241E38 C600003C */  lwc1      $f0, 0x3c($s0)
/* C48A1C 80241E3C 44821000 */  mtc1      $v0, $f2
/* C48A20 80241E40 00000000 */  nop
/* C48A24 80241E44 468010A0 */  cvt.s.w   $f2, $f2
/* C48A28 80241E48 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C48A2C 80241E4C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C48A30 80241E50 46020000 */  add.s     $f0, $f0, $f2
/* C48A34 80241E54 3C014024 */  lui       $at, 0x4024
/* C48A38 80241E58 44812800 */  mtc1      $at, $f5
/* C48A3C 80241E5C 44802000 */  mtc1      $zero, $f4
/* C48A40 80241E60 C442002C */  lwc1      $f2, 0x2c($v0)
/* C48A44 80241E64 46000021 */  cvt.d.s   $f0, $f0
/* C48A48 80241E68 46240000 */  add.d     $f0, $f0, $f4
/* C48A4C 80241E6C 460010A1 */  cvt.d.s   $f2, $f2
/* C48A50 80241E70 4620103C */  c.lt.d    $f2, $f0
/* C48A54 80241E74 00000000 */  nop
/* C48A58 80241E78 4500002E */  bc1f      .L80241F34
/* C48A5C 80241E7C 0280202D */   daddu    $a0, $s4, $zero
/* C48A60 80241E80 24020001 */  addiu     $v0, $zero, 1
/* C48A64 80241E84 AFA20010 */  sw        $v0, 0x10($sp)
/* C48A68 80241E88 8E460024 */  lw        $a2, 0x24($s2)
/* C48A6C 80241E8C 8E470028 */  lw        $a3, 0x28($s2)
/* C48A70 80241E90 0C01242D */  jal       func_800490B4
/* C48A74 80241E94 0220282D */   daddu    $a1, $s1, $zero
/* C48A78 80241E98 10400026 */  beqz      $v0, .L80241F34
/* C48A7C 80241E9C 0000202D */   daddu    $a0, $zero, $zero
/* C48A80 80241EA0 0200282D */  daddu     $a1, $s0, $zero
/* C48A84 80241EA4 0000302D */  daddu     $a2, $zero, $zero
/* C48A88 80241EA8 2412000C */  addiu     $s2, $zero, 0xc
/* C48A8C 80241EAC 860300A8 */  lh        $v1, 0xa8($s0)
/* C48A90 80241EB0 3C013F80 */  lui       $at, 0x3f80
/* C48A94 80241EB4 44810000 */  mtc1      $at, $f0
/* C48A98 80241EB8 3C014000 */  lui       $at, 0x4000
/* C48A9C 80241EBC 44811000 */  mtc1      $at, $f2
/* C48AA0 80241EC0 3C01C1A0 */  lui       $at, 0xc1a0
/* C48AA4 80241EC4 44812000 */  mtc1      $at, $f4
/* C48AA8 80241EC8 44834000 */  mtc1      $v1, $f8
/* C48AAC 80241ECC 00000000 */  nop
/* C48AB0 80241ED0 46804220 */  cvt.s.w   $f8, $f8
/* C48AB4 80241ED4 44074000 */  mfc1      $a3, $f8
/* C48AB8 80241ED8 27A20038 */  addiu     $v0, $sp, 0x38
/* C48ABC 80241EDC AFB2001C */  sw        $s2, 0x1c($sp)
/* C48AC0 80241EE0 AFA20020 */  sw        $v0, 0x20($sp)
/* C48AC4 80241EE4 E7A00010 */  swc1      $f0, 0x10($sp)
/* C48AC8 80241EE8 E7A20014 */  swc1      $f2, 0x14($sp)
/* C48ACC 80241EEC 0C01BFA4 */  jal       fx_emote
/* C48AD0 80241EF0 E7A40018 */   swc1     $f4, 0x18($sp)
/* C48AD4 80241EF4 0200202D */  daddu     $a0, $s0, $zero
/* C48AD8 80241EF8 240502F4 */  addiu     $a1, $zero, 0x2f4
/* C48ADC 80241EFC C480003C */  lwc1      $f0, 0x3c($a0)
/* C48AE0 80241F00 3C060020 */  lui       $a2, 0x20
/* C48AE4 80241F04 0C012530 */  jal       func_800494C0
/* C48AE8 80241F08 E4800064 */   swc1     $f0, 0x64($a0)
/* C48AEC 80241F0C 8E220018 */  lw        $v0, 0x18($s1)
/* C48AF0 80241F10 9442002A */  lhu       $v0, 0x2a($v0)
/* C48AF4 80241F14 30420001 */  andi      $v0, $v0, 1
/* C48AF8 80241F18 10400003 */  beqz      $v0, .L80241F28
/* C48AFC 80241F1C 2402000A */   addiu    $v0, $zero, 0xa
/* C48B00 80241F20 080907F4 */  j         .L80241FD0
/* C48B04 80241F24 AE620070 */   sw       $v0, 0x70($s3)
.L80241F28:
/* C48B08 80241F28 080907F4 */  j         .L80241FD0
/* C48B0C 80241F2C AE720070 */   sw       $s2, 0x70($s3)
.L80241F30:
/* C48B10 80241F30 AE220090 */  sw        $v0, 0x90($s1)
.L80241F34:
/* C48B14 80241F34 8602008C */  lh        $v0, 0x8c($s0)
/* C48B18 80241F38 14400025 */  bnez      $v0, .L80241FD0
/* C48B1C 80241F3C 00000000 */   nop
/* C48B20 80241F40 8602008E */  lh        $v0, 0x8e($s0)
/* C48B24 80241F44 1C400022 */  bgtz      $v0, .L80241FD0
/* C48B28 80241F48 00000000 */   nop
/* C48B2C 80241F4C 8E620074 */  lw        $v0, 0x74($s3)
/* C48B30 80241F50 2442FFFF */  addiu     $v0, $v0, -1
/* C48B34 80241F54 1840001D */  blez      $v0, .L80241FCC
/* C48B38 80241F58 AE620074 */   sw       $v0, 0x74($s3)
/* C48B3C 80241F5C 8E220018 */  lw        $v0, 0x18($s1)
/* C48B40 80241F60 9442002A */  lhu       $v0, 0x2a($v0)
/* C48B44 80241F64 30420010 */  andi      $v0, $v0, 0x10
/* C48B48 80241F68 14400007 */  bnez      $v0, .L80241F88
/* C48B4C 80241F6C 00000000 */   nop
/* C48B50 80241F70 C600000C */  lwc1      $f0, 0xc($s0)
/* C48B54 80241F74 3C014334 */  lui       $at, 0x4334
/* C48B58 80241F78 44816000 */  mtc1      $at, $f12
/* C48B5C 80241F7C 0C00A6C9 */  jal       clamp_angle
/* C48B60 80241F80 460C0300 */   add.s    $f12, $f0, $f12
/* C48B64 80241F84 E600000C */  swc1      $f0, 0xc($s0)
.L80241F88:
/* C48B68 80241F88 0C00A67F */  jal       rand_int
/* C48B6C 80241F8C 240403E8 */   addiu    $a0, $zero, 0x3e8
/* C48B70 80241F90 3C032E8B */  lui       $v1, 0x2e8b
/* C48B74 80241F94 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* C48B78 80241F98 00430018 */  mult      $v0, $v1
/* C48B7C 80241F9C 00021FC3 */  sra       $v1, $v0, 0x1f
/* C48B80 80241FA0 00004010 */  mfhi      $t0
/* C48B84 80241FA4 00082043 */  sra       $a0, $t0, 1
/* C48B88 80241FA8 00832023 */  subu      $a0, $a0, $v1
/* C48B8C 80241FAC 00041840 */  sll       $v1, $a0, 1
/* C48B90 80241FB0 00641821 */  addu      $v1, $v1, $a0
/* C48B94 80241FB4 00031880 */  sll       $v1, $v1, 2
/* C48B98 80241FB8 00641823 */  subu      $v1, $v1, $a0
/* C48B9C 80241FBC 00431023 */  subu      $v0, $v0, $v1
/* C48BA0 80241FC0 24420005 */  addiu     $v0, $v0, 5
/* C48BA4 80241FC4 080907F4 */  j         .L80241FD0
/* C48BA8 80241FC8 A602008E */   sh       $v0, 0x8e($s0)
.L80241FCC:
/* C48BAC 80241FCC AE600070 */  sw        $zero, 0x70($s3)
.L80241FD0:
/* C48BB0 80241FD0 8FBF0054 */  lw        $ra, 0x54($sp)
/* C48BB4 80241FD4 8FB40050 */  lw        $s4, 0x50($sp)
/* C48BB8 80241FD8 8FB3004C */  lw        $s3, 0x4c($sp)
/* C48BBC 80241FDC 8FB20048 */  lw        $s2, 0x48($sp)
/* C48BC0 80241FE0 8FB10044 */  lw        $s1, 0x44($sp)
/* C48BC4 80241FE4 8FB00040 */  lw        $s0, 0x40($sp)
/* C48BC8 80241FE8 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* C48BCC 80241FEC D7B80068 */  ldc1      $f24, 0x68($sp)
/* C48BD0 80241FF0 D7B60060 */  ldc1      $f22, 0x60($sp)
/* C48BD4 80241FF4 D7B40058 */  ldc1      $f20, 0x58($sp)
/* C48BD8 80241FF8 03E00008 */  jr        $ra
/* C48BDC 80241FFC 27BD0078 */   addiu    $sp, $sp, 0x78
