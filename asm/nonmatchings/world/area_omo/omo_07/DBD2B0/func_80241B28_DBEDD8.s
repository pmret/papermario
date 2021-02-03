.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B28_DBEDD8
/* DBEDD8 80241B28 27BDFF80 */  addiu     $sp, $sp, -0x80
/* DBEDDC 80241B2C AFB3004C */  sw        $s3, 0x4c($sp)
/* DBEDE0 80241B30 0080982D */  daddu     $s3, $a0, $zero
/* DBEDE4 80241B34 AFBF0058 */  sw        $ra, 0x58($sp)
/* DBEDE8 80241B38 AFB50054 */  sw        $s5, 0x54($sp)
/* DBEDEC 80241B3C AFB40050 */  sw        $s4, 0x50($sp)
/* DBEDF0 80241B40 AFB20048 */  sw        $s2, 0x48($sp)
/* DBEDF4 80241B44 AFB10044 */  sw        $s1, 0x44($sp)
/* DBEDF8 80241B48 AFB00040 */  sw        $s0, 0x40($sp)
/* DBEDFC 80241B4C F7BA0078 */  sdc1      $f26, 0x78($sp)
/* DBEE00 80241B50 F7B80070 */  sdc1      $f24, 0x70($sp)
/* DBEE04 80241B54 F7B60068 */  sdc1      $f22, 0x68($sp)
/* DBEE08 80241B58 F7B40060 */  sdc1      $f20, 0x60($sp)
/* DBEE0C 80241B5C 8E710148 */  lw        $s1, 0x148($s3)
/* DBEE10 80241B60 00A0902D */  daddu     $s2, $a1, $zero
/* DBEE14 80241B64 86240008 */  lh        $a0, 8($s1)
/* DBEE18 80241B68 0C00EABB */  jal       get_npc_unsafe
/* DBEE1C 80241B6C 00C0A82D */   daddu    $s5, $a2, $zero
/* DBEE20 80241B70 0040802D */  daddu     $s0, $v0, $zero
/* DBEE24 80241B74 0000A02D */  daddu     $s4, $zero, $zero
/* DBEE28 80241B78 C624007C */  lwc1      $f4, 0x7c($s1)
/* DBEE2C 80241B7C 46802120 */  cvt.s.w   $f4, $f4
/* DBEE30 80241B80 C6220088 */  lwc1      $f2, 0x88($s1)
/* DBEE34 80241B84 468010A0 */  cvt.s.w   $f2, $f2
/* DBEE38 80241B88 460010A1 */  cvt.d.s   $f2, $f2
/* DBEE3C 80241B8C 46002121 */  cvt.d.s   $f4, $f4
/* DBEE40 80241B90 C600003C */  lwc1      $f0, 0x3c($s0)
/* DBEE44 80241B94 3C014059 */  lui       $at, 0x4059
/* DBEE48 80241B98 44813800 */  mtc1      $at, $f7
/* DBEE4C 80241B9C 44803000 */  mtc1      $zero, $f6
/* DBEE50 80241BA0 46000021 */  cvt.d.s   $f0, $f0
/* DBEE54 80241BA4 46260002 */  mul.d     $f0, $f0, $f6
/* DBEE58 80241BA8 00000000 */  nop
/* DBEE5C 80241BAC 24020001 */  addiu     $v0, $zero, 1
/* DBEE60 80241BB0 8E24006C */  lw        $a0, 0x6c($s1)
/* DBEE64 80241BB4 46261083 */  div.d     $f2, $f2, $f6
/* DBEE68 80241BB8 462010A0 */  cvt.s.d   $f2, $f2
/* DBEE6C 80241BBC 46262103 */  div.d     $f4, $f4, $f6
/* DBEE70 80241BC0 46202520 */  cvt.s.d   $f20, $f4
/* DBEE74 80241BC4 30830011 */  andi      $v1, $a0, 0x11
/* DBEE78 80241BC8 4620020D */  trunc.w.d $f8, $f0
/* DBEE7C 80241BCC E628007C */  swc1      $f8, 0x7c($s1)
/* DBEE80 80241BD0 C6200078 */  lwc1      $f0, 0x78($s1)
/* DBEE84 80241BD4 46800020 */  cvt.s.w   $f0, $f0
/* DBEE88 80241BD8 46000021 */  cvt.d.s   $f0, $f0
/* DBEE8C 80241BDC 46260003 */  div.d     $f0, $f0, $f6
/* DBEE90 80241BE0 462006A0 */  cvt.s.d   $f26, $f0
/* DBEE94 80241BE4 C6200070 */  lwc1      $f0, 0x70($s1)
/* DBEE98 80241BE8 46800020 */  cvt.s.w   $f0, $f0
/* DBEE9C 80241BEC 46000021 */  cvt.d.s   $f0, $f0
/* DBEEA0 80241BF0 46260003 */  div.d     $f0, $f0, $f6
/* DBEEA4 80241BF4 462005A0 */  cvt.s.d   $f22, $f0
/* DBEEA8 80241BF8 14620025 */  bne       $v1, $v0, .L80241C90
/* DBEEAC 80241BFC 4602D600 */   add.s    $f24, $f26, $f2
/* DBEEB0 80241C00 8E020000 */  lw        $v0, ($s0)
/* DBEEB4 80241C04 30420008 */  andi      $v0, $v0, 8
/* DBEEB8 80241C08 10400009 */  beqz      $v0, .L80241C30
/* DBEEBC 80241C0C 27A50028 */   addiu    $a1, $sp, 0x28
/* DBEEC0 80241C10 C600003C */  lwc1      $f0, 0x3c($s0)
/* DBEEC4 80241C14 4600C001 */  sub.s     $f0, $f24, $f0
/* DBEEC8 80241C18 4600B03C */  c.lt.s    $f22, $f0
/* DBEECC 80241C1C 00000000 */  nop
/* DBEED0 80241C20 4500001B */  bc1f      .L80241C90
/* DBEED4 80241C24 34820010 */   ori      $v0, $a0, 0x10
/* DBEED8 80241C28 08090724 */  j         .L80241C90
/* DBEEDC 80241C2C AE22006C */   sw       $v0, 0x6c($s1)
.L80241C30:
/* DBEEE0 80241C30 27A6002C */  addiu     $a2, $sp, 0x2c
/* DBEEE4 80241C34 C6000038 */  lwc1      $f0, 0x38($s0)
/* DBEEE8 80241C38 C602003C */  lwc1      $f2, 0x3c($s0)
/* DBEEEC 80241C3C C6040040 */  lwc1      $f4, 0x40($s0)
/* DBEEF0 80241C40 3C01447A */  lui       $at, 0x447a
/* DBEEF4 80241C44 44813000 */  mtc1      $at, $f6
/* DBEEF8 80241C48 27A20034 */  addiu     $v0, $sp, 0x34
/* DBEEFC 80241C4C E7A00028 */  swc1      $f0, 0x28($sp)
/* DBEF00 80241C50 E7A2002C */  swc1      $f2, 0x2c($sp)
/* DBEF04 80241C54 E7A40030 */  swc1      $f4, 0x30($sp)
/* DBEF08 80241C58 E7A60034 */  swc1      $f6, 0x34($sp)
/* DBEF0C 80241C5C AFA20010 */  sw        $v0, 0x10($sp)
/* DBEF10 80241C60 8E040080 */  lw        $a0, 0x80($s0)
/* DBEF14 80241C64 0C0372DF */  jal       func_800DCB7C
/* DBEF18 80241C68 27A70030 */   addiu    $a3, $sp, 0x30
/* DBEF1C 80241C6C C7A00034 */  lwc1      $f0, 0x34($sp)
/* DBEF20 80241C70 4600D001 */  sub.s     $f0, $f26, $f0
/* DBEF24 80241C74 4600B03C */  c.lt.s    $f22, $f0
/* DBEF28 80241C78 00000000 */  nop
/* DBEF2C 80241C7C 45000004 */  bc1f      .L80241C90
/* DBEF30 80241C80 00000000 */   nop
/* DBEF34 80241C84 8E22006C */  lw        $v0, 0x6c($s1)
/* DBEF38 80241C88 34420010 */  ori       $v0, $v0, 0x10
/* DBEF3C 80241C8C AE22006C */  sw        $v0, 0x6c($s1)
.L80241C90:
/* DBEF40 80241C90 8E22006C */  lw        $v0, 0x6c($s1)
/* DBEF44 80241C94 24030011 */  addiu     $v1, $zero, 0x11
/* DBEF48 80241C98 30420011 */  andi      $v0, $v0, 0x11
/* DBEF4C 80241C9C 14430039 */  bne       $v0, $v1, .L80241D84
/* DBEF50 80241CA0 00000000 */   nop
/* DBEF54 80241CA4 8E020000 */  lw        $v0, ($s0)
/* DBEF58 80241CA8 30420008 */  andi      $v0, $v0, 8
/* DBEF5C 80241CAC 1040000A */  beqz      $v0, .L80241CD8
/* DBEF60 80241CB0 4600C106 */   mov.s    $f4, $f24
/* DBEF64 80241CB4 4614C081 */  sub.s     $f2, $f24, $f20
/* DBEF68 80241CB8 3C018024 */  lui       $at, %hi(D_802470B8_DC4368)
/* DBEF6C 80241CBC D42070B8 */  ldc1      $f0, %lo(D_802470B8_DC4368)($at)
/* DBEF70 80241CC0 460010A1 */  cvt.d.s   $f2, $f2
/* DBEF74 80241CC4 46201082 */  mul.d     $f2, $f2, $f0
/* DBEF78 80241CC8 00000000 */  nop
/* DBEF7C 80241CCC 4600A021 */  cvt.d.s   $f0, $f20
/* DBEF80 80241CD0 0809074F */  j         .L80241D3C
/* DBEF84 80241CD4 46220000 */   add.d    $f0, $f0, $f2
.L80241CD8:
/* DBEF88 80241CD8 27A50028 */  addiu     $a1, $sp, 0x28
/* DBEF8C 80241CDC 27A6002C */  addiu     $a2, $sp, 0x2c
/* DBEF90 80241CE0 C6000038 */  lwc1      $f0, 0x38($s0)
/* DBEF94 80241CE4 C6020040 */  lwc1      $f2, 0x40($s0)
/* DBEF98 80241CE8 3C01447A */  lui       $at, 0x447a
/* DBEF9C 80241CEC 44812000 */  mtc1      $at, $f4
/* DBEFA0 80241CF0 27A20034 */  addiu     $v0, $sp, 0x34
/* DBEFA4 80241CF4 E7B4002C */  swc1      $f20, 0x2c($sp)
/* DBEFA8 80241CF8 E7A00028 */  swc1      $f0, 0x28($sp)
/* DBEFAC 80241CFC E7A20030 */  swc1      $f2, 0x30($sp)
/* DBEFB0 80241D00 E7A40034 */  swc1      $f4, 0x34($sp)
/* DBEFB4 80241D04 AFA20010 */  sw        $v0, 0x10($sp)
/* DBEFB8 80241D08 8E040080 */  lw        $a0, 0x80($s0)
/* DBEFBC 80241D0C 0C0372DF */  jal       func_800DCB7C
/* DBEFC0 80241D10 27A70030 */   addiu    $a3, $sp, 0x30
/* DBEFC4 80241D14 C7A4002C */  lwc1      $f4, 0x2c($sp)
/* DBEFC8 80241D18 461A2100 */  add.s     $f4, $f4, $f26
/* DBEFCC 80241D1C 46142081 */  sub.s     $f2, $f4, $f20
/* DBEFD0 80241D20 3C018024 */  lui       $at, %hi(D_802470C0_DC4370)
/* DBEFD4 80241D24 D42070C0 */  ldc1      $f0, %lo(D_802470C0_DC4370)($at)
/* DBEFD8 80241D28 460010A1 */  cvt.d.s   $f2, $f2
/* DBEFDC 80241D2C 46201082 */  mul.d     $f2, $f2, $f0
/* DBEFE0 80241D30 00000000 */  nop
/* DBEFE4 80241D34 4600A021 */  cvt.d.s   $f0, $f20
/* DBEFE8 80241D38 46220000 */  add.d     $f0, $f0, $f2
.L80241D3C:
/* DBEFEC 80241D3C 46200020 */  cvt.s.d   $f0, $f0
/* DBEFF0 80241D40 E600003C */  swc1      $f0, 0x3c($s0)
/* DBEFF4 80241D44 C600003C */  lwc1      $f0, 0x3c($s0)
/* DBEFF8 80241D48 46002001 */  sub.s     $f0, $f4, $f0
/* DBEFFC 80241D4C 3C013FF0 */  lui       $at, 0x3ff0
/* DBF000 80241D50 44811800 */  mtc1      $at, $f3
/* DBF004 80241D54 44801000 */  mtc1      $zero, $f2
/* DBF008 80241D58 46000005 */  abs.s     $f0, $f0
/* DBF00C 80241D5C 46000021 */  cvt.d.s   $f0, $f0
/* DBF010 80241D60 4622003C */  c.lt.d    $f0, $f2
/* DBF014 80241D64 00000000 */  nop
/* DBF018 80241D68 45000036 */  bc1f      .L80241E44
/* DBF01C 80241D6C 2403FFEF */   addiu    $v1, $zero, -0x11
/* DBF020 80241D70 E604003C */  swc1      $f4, 0x3c($s0)
/* DBF024 80241D74 8E22006C */  lw        $v0, 0x6c($s1)
/* DBF028 80241D78 00431024 */  and       $v0, $v0, $v1
/* DBF02C 80241D7C 08090791 */  j         .L80241E44
/* DBF030 80241D80 AE22006C */   sw       $v0, 0x6c($s1)
.L80241D84:
/* DBF034 80241D84 8E220070 */  lw        $v0, 0x70($s1)
/* DBF038 80241D88 1840002E */  blez      $v0, .L80241E44
/* DBF03C 80241D8C 00000000 */   nop
/* DBF040 80241D90 C62C0074 */  lwc1      $f12, 0x74($s1)
/* DBF044 80241D94 0C00A8BB */  jal       sin_deg
/* DBF048 80241D98 46806320 */   cvt.s.w  $f12, $f12
/* DBF04C 80241D9C 8E020000 */  lw        $v0, ($s0)
/* DBF050 80241DA0 30420008 */  andi      $v0, $v0, 8
/* DBF054 80241DA4 10400003 */  beqz      $v0, .L80241DB4
/* DBF058 80241DA8 46000506 */   mov.s    $f20, $f0
/* DBF05C 80241DAC 0809077D */  j         .L80241DF4
/* DBF060 80241DB0 0000102D */   daddu    $v0, $zero, $zero
.L80241DB4:
/* DBF064 80241DB4 27A50028 */  addiu     $a1, $sp, 0x28
/* DBF068 80241DB8 27A6002C */  addiu     $a2, $sp, 0x2c
/* DBF06C 80241DBC C6000038 */  lwc1      $f0, 0x38($s0)
/* DBF070 80241DC0 C602003C */  lwc1      $f2, 0x3c($s0)
/* DBF074 80241DC4 C6040040 */  lwc1      $f4, 0x40($s0)
/* DBF078 80241DC8 3C01447A */  lui       $at, 0x447a
/* DBF07C 80241DCC 44813000 */  mtc1      $at, $f6
/* DBF080 80241DD0 27A20034 */  addiu     $v0, $sp, 0x34
/* DBF084 80241DD4 E7A00028 */  swc1      $f0, 0x28($sp)
/* DBF088 80241DD8 E7A2002C */  swc1      $f2, 0x2c($sp)
/* DBF08C 80241DDC E7A40030 */  swc1      $f4, 0x30($sp)
/* DBF090 80241DE0 E7A60034 */  swc1      $f6, 0x34($sp)
/* DBF094 80241DE4 AFA20010 */  sw        $v0, 0x10($sp)
/* DBF098 80241DE8 8E040080 */  lw        $a0, 0x80($s0)
/* DBF09C 80241DEC 0C0372DF */  jal       func_800DCB7C
/* DBF0A0 80241DF0 27A70030 */   addiu    $a3, $sp, 0x30
.L80241DF4:
/* DBF0A4 80241DF4 10400007 */  beqz      $v0, .L80241E14
/* DBF0A8 80241DF8 00000000 */   nop
/* DBF0AC 80241DFC 4616A082 */  mul.s     $f2, $f20, $f22
/* DBF0B0 80241E00 00000000 */  nop
/* DBF0B4 80241E04 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* DBF0B8 80241E08 461A0000 */  add.s     $f0, $f0, $f26
/* DBF0BC 80241E0C 08090788 */  j         .L80241E20
/* DBF0C0 80241E10 46020000 */   add.s    $f0, $f0, $f2
.L80241E14:
/* DBF0C4 80241E14 4616A002 */  mul.s     $f0, $f20, $f22
/* DBF0C8 80241E18 00000000 */  nop
/* DBF0CC 80241E1C 4600C000 */  add.s     $f0, $f24, $f0
.L80241E20:
/* DBF0D0 80241E20 E600003C */  swc1      $f0, 0x3c($s0)
/* DBF0D4 80241E24 8E220074 */  lw        $v0, 0x74($s1)
/* DBF0D8 80241E28 2442000A */  addiu     $v0, $v0, 0xa
/* DBF0DC 80241E2C 44826000 */  mtc1      $v0, $f12
/* DBF0E0 80241E30 00000000 */  nop
/* DBF0E4 80241E34 0C00A6C9 */  jal       clamp_angle
/* DBF0E8 80241E38 46806320 */   cvt.s.w  $f12, $f12
/* DBF0EC 80241E3C 4600020D */  trunc.w.s $f8, $f0
/* DBF0F0 80241E40 E6280074 */  swc1      $f8, 0x74($s1)
.L80241E44:
/* DBF0F4 80241E44 8E220090 */  lw        $v0, 0x90($s1)
/* DBF0F8 80241E48 1C40004A */  bgtz      $v0, .L80241F74
/* DBF0FC 80241E4C 2442FFFF */   addiu    $v0, $v0, -1
/* DBF100 80241E50 8E430014 */  lw        $v1, 0x14($s2)
/* DBF104 80241E54 04600048 */  bltz      $v1, .L80241F78
/* DBF108 80241E58 00000000 */   nop
/* DBF10C 80241E5C 8E620074 */  lw        $v0, 0x74($s3)
/* DBF110 80241E60 1C400042 */  bgtz      $v0, .L80241F6C
/* DBF114 80241E64 2442FFFF */   addiu    $v0, $v0, -1
/* DBF118 80241E68 AE630074 */  sw        $v1, 0x74($s3)
/* DBF11C 80241E6C 860200A8 */  lh        $v0, 0xa8($s0)
/* DBF120 80241E70 C602003C */  lwc1      $f2, 0x3c($s0)
/* DBF124 80241E74 44820000 */  mtc1      $v0, $f0
/* DBF128 80241E78 00000000 */  nop
/* DBF12C 80241E7C 46800020 */  cvt.s.w   $f0, $f0
/* DBF130 80241E80 46001080 */  add.s     $f2, $f2, $f0
/* DBF134 80241E84 3C014024 */  lui       $at, 0x4024
/* DBF138 80241E88 44810800 */  mtc1      $at, $f1
/* DBF13C 80241E8C 44800000 */  mtc1      $zero, $f0
/* DBF140 80241E90 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* DBF144 80241E94 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* DBF148 80241E98 460010A1 */  cvt.d.s   $f2, $f2
/* DBF14C 80241E9C 46201080 */  add.d     $f2, $f2, $f0
/* DBF150 80241EA0 C440002C */  lwc1      $f0, 0x2c($v0)
/* DBF154 80241EA4 46000021 */  cvt.d.s   $f0, $f0
/* DBF158 80241EA8 4622003C */  c.lt.d    $f0, $f2
/* DBF15C 80241EAC 00000000 */  nop
/* DBF160 80241EB0 4500002C */  bc1f      .L80241F64
/* DBF164 80241EB4 02A0202D */   daddu    $a0, $s5, $zero
/* DBF168 80241EB8 AFA00010 */  sw        $zero, 0x10($sp)
/* DBF16C 80241EBC 8E46000C */  lw        $a2, 0xc($s2)
/* DBF170 80241EC0 8E470010 */  lw        $a3, 0x10($s2)
/* DBF174 80241EC4 0C01242D */  jal       func_800490B4
/* DBF178 80241EC8 0220282D */   daddu    $a1, $s1, $zero
/* DBF17C 80241ECC 10400025 */  beqz      $v0, .L80241F64
/* DBF180 80241ED0 0000202D */   daddu    $a0, $zero, $zero
/* DBF184 80241ED4 0200282D */  daddu     $a1, $s0, $zero
/* DBF188 80241ED8 0000302D */  daddu     $a2, $zero, $zero
/* DBF18C 80241EDC 2412000C */  addiu     $s2, $zero, 0xc
/* DBF190 80241EE0 860300A8 */  lh        $v1, 0xa8($s0)
/* DBF194 80241EE4 3C013F80 */  lui       $at, 0x3f80
/* DBF198 80241EE8 44810000 */  mtc1      $at, $f0
/* DBF19C 80241EEC 3C014000 */  lui       $at, 0x4000
/* DBF1A0 80241EF0 44811000 */  mtc1      $at, $f2
/* DBF1A4 80241EF4 3C01C1A0 */  lui       $at, 0xc1a0
/* DBF1A8 80241EF8 44812000 */  mtc1      $at, $f4
/* DBF1AC 80241EFC 44834000 */  mtc1      $v1, $f8
/* DBF1B0 80241F00 00000000 */  nop
/* DBF1B4 80241F04 46804220 */  cvt.s.w   $f8, $f8
/* DBF1B8 80241F08 44074000 */  mfc1      $a3, $f8
/* DBF1BC 80241F0C 27A20038 */  addiu     $v0, $sp, 0x38
/* DBF1C0 80241F10 AFB2001C */  sw        $s2, 0x1c($sp)
/* DBF1C4 80241F14 AFA20020 */  sw        $v0, 0x20($sp)
/* DBF1C8 80241F18 E7A00010 */  swc1      $f0, 0x10($sp)
/* DBF1CC 80241F1C E7A20014 */  swc1      $f2, 0x14($sp)
/* DBF1D0 80241F20 0C01BFA4 */  jal       fx_emote
/* DBF1D4 80241F24 E7A40018 */   swc1     $f4, 0x18($sp)
/* DBF1D8 80241F28 0200202D */  daddu     $a0, $s0, $zero
/* DBF1DC 80241F2C 240502F4 */  addiu     $a1, $zero, 0x2f4
/* DBF1E0 80241F30 C480003C */  lwc1      $f0, 0x3c($a0)
/* DBF1E4 80241F34 3C060020 */  lui       $a2, 0x20
/* DBF1E8 80241F38 0C012530 */  jal       func_800494C0
/* DBF1EC 80241F3C E4800064 */   swc1     $f0, 0x64($a0)
/* DBF1F0 80241F40 8E220018 */  lw        $v0, 0x18($s1)
/* DBF1F4 80241F44 9442002A */  lhu       $v0, 0x2a($v0)
/* DBF1F8 80241F48 30420001 */  andi      $v0, $v0, 1
/* DBF1FC 80241F4C 10400003 */  beqz      $v0, .L80241F5C
/* DBF200 80241F50 2402000A */   addiu    $v0, $zero, 0xa
/* DBF204 80241F54 08090847 */  j         .L8024211C
/* DBF208 80241F58 AE620070 */   sw       $v0, 0x70($s3)
.L80241F5C:
/* DBF20C 80241F5C 08090847 */  j         .L8024211C
/* DBF210 80241F60 AE720070 */   sw       $s2, 0x70($s3)
.L80241F64:
/* DBF214 80241F64 8E620074 */  lw        $v0, 0x74($s3)
/* DBF218 80241F68 2442FFFF */  addiu     $v0, $v0, -1
.L80241F6C:
/* DBF21C 80241F6C 080907DE */  j         .L80241F78
/* DBF220 80241F70 AE620074 */   sw       $v0, 0x74($s3)
.L80241F74:
/* DBF224 80241F74 AE220090 */  sw        $v0, 0x90($s1)
.L80241F78:
/* DBF228 80241F78 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DBF22C 80241F7C C6000040 */  lwc1      $f0, 0x40($s0)
/* DBF230 80241F80 C4620000 */  lwc1      $f2, ($v1)
/* DBF234 80241F84 468010A0 */  cvt.s.w   $f2, $f2
/* DBF238 80241F88 C4640008 */  lwc1      $f4, 8($v1)
/* DBF23C 80241F8C 46802120 */  cvt.s.w   $f4, $f4
/* DBF240 80241F90 E7A00010 */  swc1      $f0, 0x10($sp)
/* DBF244 80241F94 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DBF248 80241F98 44051000 */  mfc1      $a1, $f2
/* DBF24C 80241F9C C440000C */  lwc1      $f0, 0xc($v0)
/* DBF250 80241FA0 46800020 */  cvt.s.w   $f0, $f0
/* DBF254 80241FA4 E7A00014 */  swc1      $f0, 0x14($sp)
/* DBF258 80241FA8 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DBF25C 80241FAC 44062000 */  mfc1      $a2, $f4
/* DBF260 80241FB0 C4400010 */  lwc1      $f0, 0x10($v0)
/* DBF264 80241FB4 46800020 */  cvt.s.w   $f0, $f0
/* DBF268 80241FB8 E7A00018 */  swc1      $f0, 0x18($sp)
/* DBF26C 80241FBC 8C640018 */  lw        $a0, 0x18($v1)
/* DBF270 80241FC0 0C0123F5 */  jal       is_point_within_region
/* DBF274 80241FC4 8E070038 */   lw       $a3, 0x38($s0)
/* DBF278 80241FC8 1040001A */  beqz      $v0, .L80242034
/* DBF27C 80241FCC 00000000 */   nop
/* DBF280 80241FD0 8E060038 */  lw        $a2, 0x38($s0)
/* DBF284 80241FD4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DBF288 80241FD8 8E070040 */  lw        $a3, 0x40($s0)
/* DBF28C 80241FDC C44C0000 */  lwc1      $f12, ($v0)
/* DBF290 80241FE0 46806320 */  cvt.s.w   $f12, $f12
/* DBF294 80241FE4 C44E0008 */  lwc1      $f14, 8($v0)
/* DBF298 80241FE8 0C00A7B5 */  jal       dist2D
/* DBF29C 80241FEC 468073A0 */   cvt.s.w  $f14, $f14
/* DBF2A0 80241FF0 C6020018 */  lwc1      $f2, 0x18($s0)
/* DBF2A4 80241FF4 4600103C */  c.lt.s    $f2, $f0
/* DBF2A8 80241FF8 00000000 */  nop
/* DBF2AC 80241FFC 4500000D */  bc1f      .L80242034
/* DBF2B0 80242000 E7A00034 */   swc1     $f0, 0x34($sp)
/* DBF2B4 80242004 C60C0038 */  lwc1      $f12, 0x38($s0)
/* DBF2B8 80242008 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DBF2BC 8024200C C60E0040 */  lwc1      $f14, 0x40($s0)
/* DBF2C0 80242010 C4480000 */  lwc1      $f8, ($v0)
/* DBF2C4 80242014 46804220 */  cvt.s.w   $f8, $f8
/* DBF2C8 80242018 44064000 */  mfc1      $a2, $f8
/* DBF2CC 8024201C C4480008 */  lwc1      $f8, 8($v0)
/* DBF2D0 80242020 46804220 */  cvt.s.w   $f8, $f8
/* DBF2D4 80242024 44074000 */  mfc1      $a3, $f8
/* DBF2D8 80242028 0C00A720 */  jal       atan2
/* DBF2DC 8024202C 24140001 */   addiu    $s4, $zero, 1
/* DBF2E0 80242030 E600000C */  swc1      $f0, 0xc($s0)
.L80242034:
/* DBF2E4 80242034 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DBF2E8 80242038 8C43000C */  lw        $v1, 0xc($v0)
/* DBF2EC 8024203C 8C420010 */  lw        $v0, 0x10($v0)
/* DBF2F0 80242040 00621825 */  or        $v1, $v1, $v0
/* DBF2F4 80242044 00741825 */  or        $v1, $v1, $s4
/* DBF2F8 80242048 10600008 */  beqz      $v1, .L8024206C
/* DBF2FC 8024204C 00000000 */   nop
/* DBF300 80242050 8602008C */  lh        $v0, 0x8c($s0)
/* DBF304 80242054 14400031 */  bnez      $v0, .L8024211C
/* DBF308 80242058 00000000 */   nop
/* DBF30C 8024205C 8E050018 */  lw        $a1, 0x18($s0)
/* DBF310 80242060 8E06000C */  lw        $a2, 0xc($s0)
/* DBF314 80242064 0C00EA95 */  jal       npc_move_heading
/* DBF318 80242068 0200202D */   daddu    $a0, $s0, $zero
.L8024206C:
/* DBF31C 8024206C C600003C */  lwc1      $f0, 0x3c($s0)
/* DBF320 80242070 3C014059 */  lui       $at, 0x4059
/* DBF324 80242074 44811800 */  mtc1      $at, $f3
/* DBF328 80242078 44801000 */  mtc1      $zero, $f2
/* DBF32C 8024207C 46000021 */  cvt.d.s   $f0, $f0
/* DBF330 80242080 46220002 */  mul.d     $f0, $f0, $f2
/* DBF334 80242084 00000000 */  nop
/* DBF338 80242088 4620020D */  trunc.w.d $f8, $f0
/* DBF33C 8024208C E628007C */  swc1      $f8, 0x7c($s1)
/* DBF340 80242090 8E420004 */  lw        $v0, 4($s2)
/* DBF344 80242094 18400021 */  blez      $v0, .L8024211C
/* DBF348 80242098 00000000 */   nop
/* DBF34C 8024209C 8602008E */  lh        $v0, 0x8e($s0)
/* DBF350 802420A0 9603008E */  lhu       $v1, 0x8e($s0)
/* DBF354 802420A4 18400005 */  blez      $v0, .L802420BC
/* DBF358 802420A8 2462FFFF */   addiu    $v0, $v1, -1
/* DBF35C 802420AC A602008E */  sh        $v0, 0x8e($s0)
/* DBF360 802420B0 00021400 */  sll       $v0, $v0, 0x10
/* DBF364 802420B4 1C400019 */  bgtz      $v0, .L8024211C
/* DBF368 802420B8 00000000 */   nop
.L802420BC:
/* DBF36C 802420BC 240403E8 */  addiu     $a0, $zero, 0x3e8
/* DBF370 802420C0 24020002 */  addiu     $v0, $zero, 2
/* DBF374 802420C4 0C00A67F */  jal       rand_int
/* DBF378 802420C8 AE620070 */   sw       $v0, 0x70($s3)
/* DBF37C 802420CC 3C035555 */  lui       $v1, 0x5555
/* DBF380 802420D0 34635556 */  ori       $v1, $v1, 0x5556
/* DBF384 802420D4 00430018 */  mult      $v0, $v1
/* DBF388 802420D8 000227C3 */  sra       $a0, $v0, 0x1f
/* DBF38C 802420DC 00004010 */  mfhi      $t0
/* DBF390 802420E0 01042023 */  subu      $a0, $t0, $a0
/* DBF394 802420E4 00041840 */  sll       $v1, $a0, 1
/* DBF398 802420E8 00641821 */  addu      $v1, $v1, $a0
/* DBF39C 802420EC 00431023 */  subu      $v0, $v0, $v1
/* DBF3A0 802420F0 24430002 */  addiu     $v1, $v0, 2
/* DBF3A4 802420F4 AE630074 */  sw        $v1, 0x74($s3)
/* DBF3A8 802420F8 8E42002C */  lw        $v0, 0x2c($s2)
/* DBF3AC 802420FC 58400007 */  blezl     $v0, .L8024211C
/* DBF3B0 80242100 AE600070 */   sw       $zero, 0x70($s3)
/* DBF3B4 80242104 8E420008 */  lw        $v0, 8($s2)
/* DBF3B8 80242108 18400003 */  blez      $v0, .L80242118
/* DBF3BC 8024210C 28620003 */   slti     $v0, $v1, 3
/* DBF3C0 80242110 10400002 */  beqz      $v0, .L8024211C
/* DBF3C4 80242114 00000000 */   nop
.L80242118:
/* DBF3C8 80242118 AE600070 */  sw        $zero, 0x70($s3)
.L8024211C:
/* DBF3CC 8024211C 8FBF0058 */  lw        $ra, 0x58($sp)
/* DBF3D0 80242120 8FB50054 */  lw        $s5, 0x54($sp)
/* DBF3D4 80242124 8FB40050 */  lw        $s4, 0x50($sp)
/* DBF3D8 80242128 8FB3004C */  lw        $s3, 0x4c($sp)
/* DBF3DC 8024212C 8FB20048 */  lw        $s2, 0x48($sp)
/* DBF3E0 80242130 8FB10044 */  lw        $s1, 0x44($sp)
/* DBF3E4 80242134 8FB00040 */  lw        $s0, 0x40($sp)
/* DBF3E8 80242138 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* DBF3EC 8024213C D7B80070 */  ldc1      $f24, 0x70($sp)
/* DBF3F0 80242140 D7B60068 */  ldc1      $f22, 0x68($sp)
/* DBF3F4 80242144 D7B40060 */  ldc1      $f20, 0x60($sp)
/* DBF3F8 80242148 03E00008 */  jr        $ra
/* DBF3FC 8024214C 27BD0080 */   addiu    $sp, $sp, 0x80
