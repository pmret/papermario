.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C88
/* 87B868 80241C88 27BDFF88 */  addiu     $sp, $sp, -0x78
/* 87B86C 80241C8C AFB3004C */  sw        $s3, 0x4c($sp)
/* 87B870 80241C90 0080982D */  daddu     $s3, $a0, $zero
/* 87B874 80241C94 AFBF0054 */  sw        $ra, 0x54($sp)
/* 87B878 80241C98 AFB40050 */  sw        $s4, 0x50($sp)
/* 87B87C 80241C9C AFB20048 */  sw        $s2, 0x48($sp)
/* 87B880 80241CA0 AFB10044 */  sw        $s1, 0x44($sp)
/* 87B884 80241CA4 AFB00040 */  sw        $s0, 0x40($sp)
/* 87B888 80241CA8 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* 87B88C 80241CAC F7B80068 */  sdc1      $f24, 0x68($sp)
/* 87B890 80241CB0 F7B60060 */  sdc1      $f22, 0x60($sp)
/* 87B894 80241CB4 F7B40058 */  sdc1      $f20, 0x58($sp)
/* 87B898 80241CB8 8E710148 */  lw        $s1, 0x148($s3)
/* 87B89C 80241CBC 00A0902D */  daddu     $s2, $a1, $zero
/* 87B8A0 80241CC0 86240008 */  lh        $a0, 8($s1)
/* 87B8A4 80241CC4 0C00EABB */  jal       get_npc_unsafe
/* 87B8A8 80241CC8 00C0A02D */   daddu    $s4, $a2, $zero
/* 87B8AC 80241CCC 0040802D */  daddu     $s0, $v0, $zero
/* 87B8B0 80241CD0 C6200078 */  lwc1      $f0, 0x78($s1)
/* 87B8B4 80241CD4 46800020 */  cvt.s.w   $f0, $f0
/* 87B8B8 80241CD8 46000021 */  cvt.d.s   $f0, $f0
/* 87B8BC 80241CDC 3C014059 */  lui       $at, 0x4059
/* 87B8C0 80241CE0 44811800 */  mtc1      $at, $f3
/* 87B8C4 80241CE4 44801000 */  mtc1      $zero, $f2
/* 87B8C8 80241CE8 8602008E */  lh        $v0, 0x8e($s0)
/* 87B8CC 80241CEC 9603008E */  lhu       $v1, 0x8e($s0)
/* 87B8D0 80241CF0 46220003 */  div.d     $f0, $f0, $f2
/* 87B8D4 80241CF4 46200620 */  cvt.s.d   $f24, $f0
/* 87B8D8 80241CF8 C6200088 */  lwc1      $f0, 0x88($s1)
/* 87B8DC 80241CFC 46800020 */  cvt.s.w   $f0, $f0
/* 87B8E0 80241D00 46000021 */  cvt.d.s   $f0, $f0
/* 87B8E4 80241D04 46220003 */  div.d     $f0, $f0, $f2
/* 87B8E8 80241D08 46200020 */  cvt.s.d   $f0, $f0
/* 87B8EC 80241D0C 18400003 */  blez      $v0, .L80241D1C
/* 87B8F0 80241D10 4600C680 */   add.s    $f26, $f24, $f0
/* 87B8F4 80241D14 2462FFFF */  addiu     $v0, $v1, -1
/* 87B8F8 80241D18 A602008E */  sh        $v0, 0x8e($s0)
.L80241D1C:
/* 87B8FC 80241D1C 8E220070 */  lw        $v0, 0x70($s1)
/* 87B900 80241D20 18400034 */  blez      $v0, .L80241DF4
/* 87B904 80241D24 00000000 */   nop      
/* 87B908 80241D28 C62C0074 */  lwc1      $f12, 0x74($s1)
/* 87B90C 80241D2C 46806320 */  cvt.s.w   $f12, $f12
/* 87B910 80241D30 44820000 */  mtc1      $v0, $f0
/* 87B914 80241D34 00000000 */  nop       
/* 87B918 80241D38 46800020 */  cvt.s.w   $f0, $f0
/* 87B91C 80241D3C 46000021 */  cvt.d.s   $f0, $f0
/* 87B920 80241D40 46220003 */  div.d     $f0, $f0, $f2
/* 87B924 80241D44 0C00A8BB */  jal       sin_deg
/* 87B928 80241D48 462005A0 */   cvt.s.d  $f22, $f0
/* 87B92C 80241D4C 8E020000 */  lw        $v0, ($s0)
/* 87B930 80241D50 30420008 */  andi      $v0, $v0, 8
/* 87B934 80241D54 10400003 */  beqz      $v0, .L80241D64
/* 87B938 80241D58 46000506 */   mov.s    $f20, $f0
/* 87B93C 80241D5C 08090769 */  j         .L80241DA4
/* 87B940 80241D60 0000102D */   daddu    $v0, $zero, $zero
.L80241D64:
/* 87B944 80241D64 27A50028 */  addiu     $a1, $sp, 0x28
/* 87B948 80241D68 27A6002C */  addiu     $a2, $sp, 0x2c
/* 87B94C 80241D6C C6000038 */  lwc1      $f0, 0x38($s0)
/* 87B950 80241D70 C602003C */  lwc1      $f2, 0x3c($s0)
/* 87B954 80241D74 C6040040 */  lwc1      $f4, 0x40($s0)
/* 87B958 80241D78 3C01447A */  lui       $at, 0x447a
/* 87B95C 80241D7C 44813000 */  mtc1      $at, $f6
/* 87B960 80241D80 27A20034 */  addiu     $v0, $sp, 0x34
/* 87B964 80241D84 E7A00028 */  swc1      $f0, 0x28($sp)
/* 87B968 80241D88 E7A2002C */  swc1      $f2, 0x2c($sp)
/* 87B96C 80241D8C E7A40030 */  swc1      $f4, 0x30($sp)
/* 87B970 80241D90 E7A60034 */  swc1      $f6, 0x34($sp)
/* 87B974 80241D94 AFA20010 */  sw        $v0, 0x10($sp)
/* 87B978 80241D98 8E040080 */  lw        $a0, 0x80($s0)
/* 87B97C 80241D9C 0C0372DF */  jal       func_800DCB7C
/* 87B980 80241DA0 27A70030 */   addiu    $a3, $sp, 0x30
.L80241DA4:
/* 87B984 80241DA4 10400007 */  beqz      $v0, .L80241DC4
/* 87B988 80241DA8 00000000 */   nop      
/* 87B98C 80241DAC 4616A082 */  mul.s     $f2, $f20, $f22
/* 87B990 80241DB0 00000000 */  nop       
/* 87B994 80241DB4 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 87B998 80241DB8 46180000 */  add.s     $f0, $f0, $f24
/* 87B99C 80241DBC 08090774 */  j         .L80241DD0
/* 87B9A0 80241DC0 46020000 */   add.s    $f0, $f0, $f2
.L80241DC4:
/* 87B9A4 80241DC4 4616A002 */  mul.s     $f0, $f20, $f22
/* 87B9A8 80241DC8 00000000 */  nop       
/* 87B9AC 80241DCC 4600D000 */  add.s     $f0, $f26, $f0
.L80241DD0:
/* 87B9B0 80241DD0 E600003C */  swc1      $f0, 0x3c($s0)
/* 87B9B4 80241DD4 8E220074 */  lw        $v0, 0x74($s1)
/* 87B9B8 80241DD8 2442000A */  addiu     $v0, $v0, 0xa
/* 87B9BC 80241DDC 44826000 */  mtc1      $v0, $f12
/* 87B9C0 80241DE0 00000000 */  nop       
/* 87B9C4 80241DE4 0C00A6C9 */  jal       clamp_angle
/* 87B9C8 80241DE8 46806320 */   cvt.s.w  $f12, $f12
/* 87B9CC 80241DEC 4600020D */  trunc.w.s $f8, $f0
/* 87B9D0 80241DF0 E6280074 */  swc1      $f8, 0x74($s1)
.L80241DF4:
/* 87B9D4 80241DF4 8E220090 */  lw        $v0, 0x90($s1)
/* 87B9D8 80241DF8 1C400040 */  bgtz      $v0, .L80241EFC
/* 87B9DC 80241DFC 2442FFFF */   addiu    $v0, $v0, -1
/* 87B9E0 80241E00 860200A8 */  lh        $v0, 0xa8($s0)
/* 87B9E4 80241E04 C600003C */  lwc1      $f0, 0x3c($s0)
/* 87B9E8 80241E08 44821000 */  mtc1      $v0, $f2
/* 87B9EC 80241E0C 00000000 */  nop       
/* 87B9F0 80241E10 468010A0 */  cvt.s.w   $f2, $f2
/* 87B9F4 80241E14 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 87B9F8 80241E18 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 87B9FC 80241E1C 46020000 */  add.s     $f0, $f0, $f2
/* 87BA00 80241E20 3C014024 */  lui       $at, 0x4024
/* 87BA04 80241E24 44812800 */  mtc1      $at, $f5
/* 87BA08 80241E28 44802000 */  mtc1      $zero, $f4
/* 87BA0C 80241E2C C442002C */  lwc1      $f2, 0x2c($v0)
/* 87BA10 80241E30 46000021 */  cvt.d.s   $f0, $f0
/* 87BA14 80241E34 46240000 */  add.d     $f0, $f0, $f4
/* 87BA18 80241E38 460010A1 */  cvt.d.s   $f2, $f2
/* 87BA1C 80241E3C 4620103C */  c.lt.d    $f2, $f0
/* 87BA20 80241E40 00000000 */  nop       
/* 87BA24 80241E44 4500002E */  bc1f      .L80241F00
/* 87BA28 80241E48 0280202D */   daddu    $a0, $s4, $zero
/* 87BA2C 80241E4C 24020001 */  addiu     $v0, $zero, 1
/* 87BA30 80241E50 AFA20010 */  sw        $v0, 0x10($sp)
/* 87BA34 80241E54 8E460024 */  lw        $a2, 0x24($s2)
/* 87BA38 80241E58 8E470028 */  lw        $a3, 0x28($s2)
/* 87BA3C 80241E5C 0C01242D */  jal       func_800490B4
/* 87BA40 80241E60 0220282D */   daddu    $a1, $s1, $zero
/* 87BA44 80241E64 10400026 */  beqz      $v0, .L80241F00
/* 87BA48 80241E68 0000202D */   daddu    $a0, $zero, $zero
/* 87BA4C 80241E6C 0200282D */  daddu     $a1, $s0, $zero
/* 87BA50 80241E70 0000302D */  daddu     $a2, $zero, $zero
/* 87BA54 80241E74 2412000C */  addiu     $s2, $zero, 0xc
/* 87BA58 80241E78 860300A8 */  lh        $v1, 0xa8($s0)
/* 87BA5C 80241E7C 3C013F80 */  lui       $at, 0x3f80
/* 87BA60 80241E80 44810000 */  mtc1      $at, $f0
/* 87BA64 80241E84 3C014000 */  lui       $at, 0x4000
/* 87BA68 80241E88 44811000 */  mtc1      $at, $f2
/* 87BA6C 80241E8C 3C01C1A0 */  lui       $at, 0xc1a0
/* 87BA70 80241E90 44812000 */  mtc1      $at, $f4
/* 87BA74 80241E94 44834000 */  mtc1      $v1, $f8
/* 87BA78 80241E98 00000000 */  nop       
/* 87BA7C 80241E9C 46804220 */  cvt.s.w   $f8, $f8
/* 87BA80 80241EA0 44074000 */  mfc1      $a3, $f8
/* 87BA84 80241EA4 27A20038 */  addiu     $v0, $sp, 0x38
/* 87BA88 80241EA8 AFB2001C */  sw        $s2, 0x1c($sp)
/* 87BA8C 80241EAC AFA20020 */  sw        $v0, 0x20($sp)
/* 87BA90 80241EB0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 87BA94 80241EB4 E7A20014 */  swc1      $f2, 0x14($sp)
/* 87BA98 80241EB8 0C01BFA4 */  jal       fx_emote
/* 87BA9C 80241EBC E7A40018 */   swc1     $f4, 0x18($sp)
/* 87BAA0 80241EC0 0200202D */  daddu     $a0, $s0, $zero
/* 87BAA4 80241EC4 240502F4 */  addiu     $a1, $zero, 0x2f4
/* 87BAA8 80241EC8 C480003C */  lwc1      $f0, 0x3c($a0)
/* 87BAAC 80241ECC 3C060020 */  lui       $a2, 0x20
/* 87BAB0 80241ED0 0C012530 */  jal       func_800494C0
/* 87BAB4 80241ED4 E4800064 */   swc1     $f0, 0x64($a0)
/* 87BAB8 80241ED8 8E220018 */  lw        $v0, 0x18($s1)
/* 87BABC 80241EDC 9442002A */  lhu       $v0, 0x2a($v0)
/* 87BAC0 80241EE0 30420001 */  andi      $v0, $v0, 1
/* 87BAC4 80241EE4 10400003 */  beqz      $v0, .L80241EF4
/* 87BAC8 80241EE8 2402000A */   addiu    $v0, $zero, 0xa
/* 87BACC 80241EEC 080907E7 */  j         .L80241F9C
/* 87BAD0 80241EF0 AE620070 */   sw       $v0, 0x70($s3)
.L80241EF4:
/* 87BAD4 80241EF4 080907E7 */  j         .L80241F9C
/* 87BAD8 80241EF8 AE720070 */   sw       $s2, 0x70($s3)
.L80241EFC:
/* 87BADC 80241EFC AE220090 */  sw        $v0, 0x90($s1)
.L80241F00:
/* 87BAE0 80241F00 8602008C */  lh        $v0, 0x8c($s0)
/* 87BAE4 80241F04 14400025 */  bnez      $v0, .L80241F9C
/* 87BAE8 80241F08 00000000 */   nop      
/* 87BAEC 80241F0C 8602008E */  lh        $v0, 0x8e($s0)
/* 87BAF0 80241F10 1C400022 */  bgtz      $v0, .L80241F9C
/* 87BAF4 80241F14 00000000 */   nop      
/* 87BAF8 80241F18 8E620074 */  lw        $v0, 0x74($s3)
/* 87BAFC 80241F1C 2442FFFF */  addiu     $v0, $v0, -1
/* 87BB00 80241F20 1840001D */  blez      $v0, .L80241F98
/* 87BB04 80241F24 AE620074 */   sw       $v0, 0x74($s3)
/* 87BB08 80241F28 8E220018 */  lw        $v0, 0x18($s1)
/* 87BB0C 80241F2C 9442002A */  lhu       $v0, 0x2a($v0)
/* 87BB10 80241F30 30420010 */  andi      $v0, $v0, 0x10
/* 87BB14 80241F34 14400007 */  bnez      $v0, .L80241F54
/* 87BB18 80241F38 00000000 */   nop      
/* 87BB1C 80241F3C C600000C */  lwc1      $f0, 0xc($s0)
/* 87BB20 80241F40 3C014334 */  lui       $at, 0x4334
/* 87BB24 80241F44 44816000 */  mtc1      $at, $f12
/* 87BB28 80241F48 0C00A6C9 */  jal       clamp_angle
/* 87BB2C 80241F4C 460C0300 */   add.s    $f12, $f0, $f12
/* 87BB30 80241F50 E600000C */  swc1      $f0, 0xc($s0)
.L80241F54:
/* 87BB34 80241F54 0C00A67F */  jal       rand_int
/* 87BB38 80241F58 240403E8 */   addiu    $a0, $zero, 0x3e8
/* 87BB3C 80241F5C 3C032E8B */  lui       $v1, 0x2e8b
/* 87BB40 80241F60 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* 87BB44 80241F64 00430018 */  mult      $v0, $v1
/* 87BB48 80241F68 00021FC3 */  sra       $v1, $v0, 0x1f
/* 87BB4C 80241F6C 00004010 */  mfhi      $t0
/* 87BB50 80241F70 00082043 */  sra       $a0, $t0, 1
/* 87BB54 80241F74 00832023 */  subu      $a0, $a0, $v1
/* 87BB58 80241F78 00041840 */  sll       $v1, $a0, 1
/* 87BB5C 80241F7C 00641821 */  addu      $v1, $v1, $a0
/* 87BB60 80241F80 00031880 */  sll       $v1, $v1, 2
/* 87BB64 80241F84 00641823 */  subu      $v1, $v1, $a0
/* 87BB68 80241F88 00431023 */  subu      $v0, $v0, $v1
/* 87BB6C 80241F8C 24420005 */  addiu     $v0, $v0, 5
/* 87BB70 80241F90 080907E7 */  j         .L80241F9C
/* 87BB74 80241F94 A602008E */   sh       $v0, 0x8e($s0)
.L80241F98:
/* 87BB78 80241F98 AE600070 */  sw        $zero, 0x70($s3)
.L80241F9C:
/* 87BB7C 80241F9C 8FBF0054 */  lw        $ra, 0x54($sp)
/* 87BB80 80241FA0 8FB40050 */  lw        $s4, 0x50($sp)
/* 87BB84 80241FA4 8FB3004C */  lw        $s3, 0x4c($sp)
/* 87BB88 80241FA8 8FB20048 */  lw        $s2, 0x48($sp)
/* 87BB8C 80241FAC 8FB10044 */  lw        $s1, 0x44($sp)
/* 87BB90 80241FB0 8FB00040 */  lw        $s0, 0x40($sp)
/* 87BB94 80241FB4 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* 87BB98 80241FB8 D7B80068 */  ldc1      $f24, 0x68($sp)
/* 87BB9C 80241FBC D7B60060 */  ldc1      $f22, 0x60($sp)
/* 87BBA0 80241FC0 D7B40058 */  ldc1      $f20, 0x58($sp)
/* 87BBA4 80241FC4 03E00008 */  jr        $ra
/* 87BBA8 80241FC8 27BD0078 */   addiu    $sp, $sp, 0x78
