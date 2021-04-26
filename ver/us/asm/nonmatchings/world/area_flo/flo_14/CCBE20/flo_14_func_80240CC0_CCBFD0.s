.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata
glabel D_80245358_CD0668
.double 0.09
glabel D_80245360_CD0670
.double 0.09

.section .text
glabel func_80240CC0_CCBFD0
/* CCBFD0 80240CC0 27BDFF80 */  addiu     $sp, $sp, -0x80
/* CCBFD4 80240CC4 AFB3004C */  sw        $s3, 0x4c($sp)
/* CCBFD8 80240CC8 0080982D */  daddu     $s3, $a0, $zero
/* CCBFDC 80240CCC AFBF0058 */  sw        $ra, 0x58($sp)
/* CCBFE0 80240CD0 AFB50054 */  sw        $s5, 0x54($sp)
/* CCBFE4 80240CD4 AFB40050 */  sw        $s4, 0x50($sp)
/* CCBFE8 80240CD8 AFB20048 */  sw        $s2, 0x48($sp)
/* CCBFEC 80240CDC AFB10044 */  sw        $s1, 0x44($sp)
/* CCBFF0 80240CE0 AFB00040 */  sw        $s0, 0x40($sp)
/* CCBFF4 80240CE4 F7BA0078 */  sdc1      $f26, 0x78($sp)
/* CCBFF8 80240CE8 F7B80070 */  sdc1      $f24, 0x70($sp)
/* CCBFFC 80240CEC F7B60068 */  sdc1      $f22, 0x68($sp)
/* CCC000 80240CF0 F7B40060 */  sdc1      $f20, 0x60($sp)
/* CCC004 80240CF4 8E710148 */  lw        $s1, 0x148($s3)
/* CCC008 80240CF8 00A0902D */  daddu     $s2, $a1, $zero
/* CCC00C 80240CFC 86240008 */  lh        $a0, 8($s1)
/* CCC010 80240D00 0C00EABB */  jal       get_npc_unsafe
/* CCC014 80240D04 00C0A82D */   daddu    $s5, $a2, $zero
/* CCC018 80240D08 0040802D */  daddu     $s0, $v0, $zero
/* CCC01C 80240D0C 0000A02D */  daddu     $s4, $zero, $zero
/* CCC020 80240D10 C624007C */  lwc1      $f4, 0x7c($s1)
/* CCC024 80240D14 46802120 */  cvt.s.w   $f4, $f4
/* CCC028 80240D18 C6220088 */  lwc1      $f2, 0x88($s1)
/* CCC02C 80240D1C 468010A0 */  cvt.s.w   $f2, $f2
/* CCC030 80240D20 460010A1 */  cvt.d.s   $f2, $f2
/* CCC034 80240D24 46002121 */  cvt.d.s   $f4, $f4
/* CCC038 80240D28 C600003C */  lwc1      $f0, 0x3c($s0)
/* CCC03C 80240D2C 3C014059 */  lui       $at, 0x4059
/* CCC040 80240D30 44813800 */  mtc1      $at, $f7
/* CCC044 80240D34 44803000 */  mtc1      $zero, $f6
/* CCC048 80240D38 46000021 */  cvt.d.s   $f0, $f0
/* CCC04C 80240D3C 46260002 */  mul.d     $f0, $f0, $f6
/* CCC050 80240D40 00000000 */  nop
/* CCC054 80240D44 24020001 */  addiu     $v0, $zero, 1
/* CCC058 80240D48 8E24006C */  lw        $a0, 0x6c($s1)
/* CCC05C 80240D4C 46261083 */  div.d     $f2, $f2, $f6
/* CCC060 80240D50 462010A0 */  cvt.s.d   $f2, $f2
/* CCC064 80240D54 46262103 */  div.d     $f4, $f4, $f6
/* CCC068 80240D58 46202520 */  cvt.s.d   $f20, $f4
/* CCC06C 80240D5C 30830011 */  andi      $v1, $a0, 0x11
/* CCC070 80240D60 4620020D */  trunc.w.d $f8, $f0
/* CCC074 80240D64 E628007C */  swc1      $f8, 0x7c($s1)
/* CCC078 80240D68 C6200078 */  lwc1      $f0, 0x78($s1)
/* CCC07C 80240D6C 46800020 */  cvt.s.w   $f0, $f0
/* CCC080 80240D70 46000021 */  cvt.d.s   $f0, $f0
/* CCC084 80240D74 46260003 */  div.d     $f0, $f0, $f6
/* CCC088 80240D78 462006A0 */  cvt.s.d   $f26, $f0
/* CCC08C 80240D7C C6200070 */  lwc1      $f0, 0x70($s1)
/* CCC090 80240D80 46800020 */  cvt.s.w   $f0, $f0
/* CCC094 80240D84 46000021 */  cvt.d.s   $f0, $f0
/* CCC098 80240D88 46260003 */  div.d     $f0, $f0, $f6
/* CCC09C 80240D8C 462005A0 */  cvt.s.d   $f22, $f0
/* CCC0A0 80240D90 14620025 */  bne       $v1, $v0, .L80240E28
/* CCC0A4 80240D94 4602D600 */   add.s    $f24, $f26, $f2
/* CCC0A8 80240D98 8E020000 */  lw        $v0, ($s0)
/* CCC0AC 80240D9C 30420008 */  andi      $v0, $v0, 8
/* CCC0B0 80240DA0 10400009 */  beqz      $v0, .L80240DC8
/* CCC0B4 80240DA4 27A50028 */   addiu    $a1, $sp, 0x28
/* CCC0B8 80240DA8 C600003C */  lwc1      $f0, 0x3c($s0)
/* CCC0BC 80240DAC 4600C001 */  sub.s     $f0, $f24, $f0
/* CCC0C0 80240DB0 4600B03C */  c.lt.s    $f22, $f0
/* CCC0C4 80240DB4 00000000 */  nop
/* CCC0C8 80240DB8 4500001B */  bc1f      .L80240E28
/* CCC0CC 80240DBC 34820010 */   ori      $v0, $a0, 0x10
/* CCC0D0 80240DC0 0809038A */  j         .L80240E28
/* CCC0D4 80240DC4 AE22006C */   sw       $v0, 0x6c($s1)
.L80240DC8:
/* CCC0D8 80240DC8 27A6002C */  addiu     $a2, $sp, 0x2c
/* CCC0DC 80240DCC C6000038 */  lwc1      $f0, 0x38($s0)
/* CCC0E0 80240DD0 C602003C */  lwc1      $f2, 0x3c($s0)
/* CCC0E4 80240DD4 C6040040 */  lwc1      $f4, 0x40($s0)
/* CCC0E8 80240DD8 3C01447A */  lui       $at, 0x447a
/* CCC0EC 80240DDC 44813000 */  mtc1      $at, $f6
/* CCC0F0 80240DE0 27A20034 */  addiu     $v0, $sp, 0x34
/* CCC0F4 80240DE4 E7A00028 */  swc1      $f0, 0x28($sp)
/* CCC0F8 80240DE8 E7A2002C */  swc1      $f2, 0x2c($sp)
/* CCC0FC 80240DEC E7A40030 */  swc1      $f4, 0x30($sp)
/* CCC100 80240DF0 E7A60034 */  swc1      $f6, 0x34($sp)
/* CCC104 80240DF4 AFA20010 */  sw        $v0, 0x10($sp)
/* CCC108 80240DF8 8E040080 */  lw        $a0, 0x80($s0)
/* CCC10C 80240DFC 0C0372DF */  jal       func_800DCB7C
/* CCC110 80240E00 27A70030 */   addiu    $a3, $sp, 0x30
/* CCC114 80240E04 C7A00034 */  lwc1      $f0, 0x34($sp)
/* CCC118 80240E08 4600D001 */  sub.s     $f0, $f26, $f0
/* CCC11C 80240E0C 4600B03C */  c.lt.s    $f22, $f0
/* CCC120 80240E10 00000000 */  nop
/* CCC124 80240E14 45000004 */  bc1f      .L80240E28
/* CCC128 80240E18 00000000 */   nop
/* CCC12C 80240E1C 8E22006C */  lw        $v0, 0x6c($s1)
/* CCC130 80240E20 34420010 */  ori       $v0, $v0, 0x10
/* CCC134 80240E24 AE22006C */  sw        $v0, 0x6c($s1)
.L80240E28:
/* CCC138 80240E28 8E22006C */  lw        $v0, 0x6c($s1)
/* CCC13C 80240E2C 24030011 */  addiu     $v1, $zero, 0x11
/* CCC140 80240E30 30420011 */  andi      $v0, $v0, 0x11
/* CCC144 80240E34 14430039 */  bne       $v0, $v1, .L80240F1C
/* CCC148 80240E38 00000000 */   nop
/* CCC14C 80240E3C 8E020000 */  lw        $v0, ($s0)
/* CCC150 80240E40 30420008 */  andi      $v0, $v0, 8
/* CCC154 80240E44 1040000A */  beqz      $v0, .L80240E70
/* CCC158 80240E48 4600C106 */   mov.s    $f4, $f24
/* CCC15C 80240E4C 4614C081 */  sub.s     $f2, $f24, $f20
/* CCC160 80240E50 3C018024 */  lui       $at, %hi(D_80245358_CD0668)
/* CCC164 80240E54 D4205358 */  ldc1      $f0, %lo(D_80245358_CD0668)($at)
/* CCC168 80240E58 460010A1 */  cvt.d.s   $f2, $f2
/* CCC16C 80240E5C 46201082 */  mul.d     $f2, $f2, $f0
/* CCC170 80240E60 00000000 */  nop
/* CCC174 80240E64 4600A021 */  cvt.d.s   $f0, $f20
/* CCC178 80240E68 080903B5 */  j         .L80240ED4
/* CCC17C 80240E6C 46220000 */   add.d    $f0, $f0, $f2
.L80240E70:
/* CCC180 80240E70 27A50028 */  addiu     $a1, $sp, 0x28
/* CCC184 80240E74 27A6002C */  addiu     $a2, $sp, 0x2c
/* CCC188 80240E78 C6000038 */  lwc1      $f0, 0x38($s0)
/* CCC18C 80240E7C C6020040 */  lwc1      $f2, 0x40($s0)
/* CCC190 80240E80 3C01447A */  lui       $at, 0x447a
/* CCC194 80240E84 44812000 */  mtc1      $at, $f4
/* CCC198 80240E88 27A20034 */  addiu     $v0, $sp, 0x34
/* CCC19C 80240E8C E7B4002C */  swc1      $f20, 0x2c($sp)
/* CCC1A0 80240E90 E7A00028 */  swc1      $f0, 0x28($sp)
/* CCC1A4 80240E94 E7A20030 */  swc1      $f2, 0x30($sp)
/* CCC1A8 80240E98 E7A40034 */  swc1      $f4, 0x34($sp)
/* CCC1AC 80240E9C AFA20010 */  sw        $v0, 0x10($sp)
/* CCC1B0 80240EA0 8E040080 */  lw        $a0, 0x80($s0)
/* CCC1B4 80240EA4 0C0372DF */  jal       func_800DCB7C
/* CCC1B8 80240EA8 27A70030 */   addiu    $a3, $sp, 0x30
/* CCC1BC 80240EAC C7A4002C */  lwc1      $f4, 0x2c($sp)
/* CCC1C0 80240EB0 461A2100 */  add.s     $f4, $f4, $f26
/* CCC1C4 80240EB4 46142081 */  sub.s     $f2, $f4, $f20
/* CCC1C8 80240EB8 3C018024 */  lui       $at, %hi(D_80245360_CD0670)
/* CCC1CC 80240EBC D4205360 */  ldc1      $f0, %lo(D_80245360_CD0670)($at)
/* CCC1D0 80240EC0 460010A1 */  cvt.d.s   $f2, $f2
/* CCC1D4 80240EC4 46201082 */  mul.d     $f2, $f2, $f0
/* CCC1D8 80240EC8 00000000 */  nop
/* CCC1DC 80240ECC 4600A021 */  cvt.d.s   $f0, $f20
/* CCC1E0 80240ED0 46220000 */  add.d     $f0, $f0, $f2
.L80240ED4:
/* CCC1E4 80240ED4 46200020 */  cvt.s.d   $f0, $f0
/* CCC1E8 80240ED8 E600003C */  swc1      $f0, 0x3c($s0)
/* CCC1EC 80240EDC C600003C */  lwc1      $f0, 0x3c($s0)
/* CCC1F0 80240EE0 46002001 */  sub.s     $f0, $f4, $f0
/* CCC1F4 80240EE4 3C013FF0 */  lui       $at, 0x3ff0
/* CCC1F8 80240EE8 44811800 */  mtc1      $at, $f3
/* CCC1FC 80240EEC 44801000 */  mtc1      $zero, $f2
/* CCC200 80240EF0 46000005 */  abs.s     $f0, $f0
/* CCC204 80240EF4 46000021 */  cvt.d.s   $f0, $f0
/* CCC208 80240EF8 4622003C */  c.lt.d    $f0, $f2
/* CCC20C 80240EFC 00000000 */  nop
/* CCC210 80240F00 45000036 */  bc1f      .L80240FDC
/* CCC214 80240F04 2403FFEF */   addiu    $v1, $zero, -0x11
/* CCC218 80240F08 E604003C */  swc1      $f4, 0x3c($s0)
/* CCC21C 80240F0C 8E22006C */  lw        $v0, 0x6c($s1)
/* CCC220 80240F10 00431024 */  and       $v0, $v0, $v1
/* CCC224 80240F14 080903F7 */  j         .L80240FDC
/* CCC228 80240F18 AE22006C */   sw       $v0, 0x6c($s1)
.L80240F1C:
/* CCC22C 80240F1C 8E220070 */  lw        $v0, 0x70($s1)
/* CCC230 80240F20 1840002E */  blez      $v0, .L80240FDC
/* CCC234 80240F24 00000000 */   nop
/* CCC238 80240F28 C62C0074 */  lwc1      $f12, 0x74($s1)
/* CCC23C 80240F2C 0C00A8BB */  jal       sin_deg
/* CCC240 80240F30 46806320 */   cvt.s.w  $f12, $f12
/* CCC244 80240F34 8E020000 */  lw        $v0, ($s0)
/* CCC248 80240F38 30420008 */  andi      $v0, $v0, 8
/* CCC24C 80240F3C 10400003 */  beqz      $v0, .L80240F4C
/* CCC250 80240F40 46000506 */   mov.s    $f20, $f0
/* CCC254 80240F44 080903E3 */  j         .L80240F8C
/* CCC258 80240F48 0000102D */   daddu    $v0, $zero, $zero
.L80240F4C:
/* CCC25C 80240F4C 27A50028 */  addiu     $a1, $sp, 0x28
/* CCC260 80240F50 27A6002C */  addiu     $a2, $sp, 0x2c
/* CCC264 80240F54 C6000038 */  lwc1      $f0, 0x38($s0)
/* CCC268 80240F58 C602003C */  lwc1      $f2, 0x3c($s0)
/* CCC26C 80240F5C C6040040 */  lwc1      $f4, 0x40($s0)
/* CCC270 80240F60 3C01447A */  lui       $at, 0x447a
/* CCC274 80240F64 44813000 */  mtc1      $at, $f6
/* CCC278 80240F68 27A20034 */  addiu     $v0, $sp, 0x34
/* CCC27C 80240F6C E7A00028 */  swc1      $f0, 0x28($sp)
/* CCC280 80240F70 E7A2002C */  swc1      $f2, 0x2c($sp)
/* CCC284 80240F74 E7A40030 */  swc1      $f4, 0x30($sp)
/* CCC288 80240F78 E7A60034 */  swc1      $f6, 0x34($sp)
/* CCC28C 80240F7C AFA20010 */  sw        $v0, 0x10($sp)
/* CCC290 80240F80 8E040080 */  lw        $a0, 0x80($s0)
/* CCC294 80240F84 0C0372DF */  jal       func_800DCB7C
/* CCC298 80240F88 27A70030 */   addiu    $a3, $sp, 0x30
.L80240F8C:
/* CCC29C 80240F8C 10400007 */  beqz      $v0, .L80240FAC
/* CCC2A0 80240F90 00000000 */   nop
/* CCC2A4 80240F94 4616A082 */  mul.s     $f2, $f20, $f22
/* CCC2A8 80240F98 00000000 */  nop
/* CCC2AC 80240F9C C7A0002C */  lwc1      $f0, 0x2c($sp)
/* CCC2B0 80240FA0 461A0000 */  add.s     $f0, $f0, $f26
/* CCC2B4 80240FA4 080903EE */  j         .L80240FB8
/* CCC2B8 80240FA8 46020000 */   add.s    $f0, $f0, $f2
.L80240FAC:
/* CCC2BC 80240FAC 4616A002 */  mul.s     $f0, $f20, $f22
/* CCC2C0 80240FB0 00000000 */  nop
/* CCC2C4 80240FB4 4600C000 */  add.s     $f0, $f24, $f0
.L80240FB8:
/* CCC2C8 80240FB8 E600003C */  swc1      $f0, 0x3c($s0)
/* CCC2CC 80240FBC 8E220074 */  lw        $v0, 0x74($s1)
/* CCC2D0 80240FC0 2442000A */  addiu     $v0, $v0, 0xa
/* CCC2D4 80240FC4 44826000 */  mtc1      $v0, $f12
/* CCC2D8 80240FC8 00000000 */  nop
/* CCC2DC 80240FCC 0C00A6C9 */  jal       clamp_angle
/* CCC2E0 80240FD0 46806320 */   cvt.s.w  $f12, $f12
/* CCC2E4 80240FD4 4600020D */  trunc.w.s $f8, $f0
/* CCC2E8 80240FD8 E6280074 */  swc1      $f8, 0x74($s1)
.L80240FDC:
/* CCC2EC 80240FDC 8E220090 */  lw        $v0, 0x90($s1)
/* CCC2F0 80240FE0 1C40004A */  bgtz      $v0, .L8024110C
/* CCC2F4 80240FE4 2442FFFF */   addiu    $v0, $v0, -1
/* CCC2F8 80240FE8 8E430014 */  lw        $v1, 0x14($s2)
/* CCC2FC 80240FEC 04600048 */  bltz      $v1, .L80241110
/* CCC300 80240FF0 00000000 */   nop
/* CCC304 80240FF4 8E620074 */  lw        $v0, 0x74($s3)
/* CCC308 80240FF8 1C400042 */  bgtz      $v0, .L80241104
/* CCC30C 80240FFC 2442FFFF */   addiu    $v0, $v0, -1
/* CCC310 80241000 AE630074 */  sw        $v1, 0x74($s3)
/* CCC314 80241004 860200A8 */  lh        $v0, 0xa8($s0)
/* CCC318 80241008 C602003C */  lwc1      $f2, 0x3c($s0)
/* CCC31C 8024100C 44820000 */  mtc1      $v0, $f0
/* CCC320 80241010 00000000 */  nop
/* CCC324 80241014 46800020 */  cvt.s.w   $f0, $f0
/* CCC328 80241018 46001080 */  add.s     $f2, $f2, $f0
/* CCC32C 8024101C 3C014024 */  lui       $at, 0x4024
/* CCC330 80241020 44810800 */  mtc1      $at, $f1
/* CCC334 80241024 44800000 */  mtc1      $zero, $f0
/* CCC338 80241028 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CCC33C 8024102C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CCC340 80241030 460010A1 */  cvt.d.s   $f2, $f2
/* CCC344 80241034 46201080 */  add.d     $f2, $f2, $f0
/* CCC348 80241038 C440002C */  lwc1      $f0, 0x2c($v0)
/* CCC34C 8024103C 46000021 */  cvt.d.s   $f0, $f0
/* CCC350 80241040 4622003C */  c.lt.d    $f0, $f2
/* CCC354 80241044 00000000 */  nop
/* CCC358 80241048 4500002C */  bc1f      .L802410FC
/* CCC35C 8024104C 02A0202D */   daddu    $a0, $s5, $zero
/* CCC360 80241050 AFA00010 */  sw        $zero, 0x10($sp)
/* CCC364 80241054 8E46000C */  lw        $a2, 0xc($s2)
/* CCC368 80241058 8E470010 */  lw        $a3, 0x10($s2)
/* CCC36C 8024105C 0C01242D */  jal       func_800490B4
/* CCC370 80241060 0220282D */   daddu    $a1, $s1, $zero
/* CCC374 80241064 10400025 */  beqz      $v0, .L802410FC
/* CCC378 80241068 0000202D */   daddu    $a0, $zero, $zero
/* CCC37C 8024106C 0200282D */  daddu     $a1, $s0, $zero
/* CCC380 80241070 0000302D */  daddu     $a2, $zero, $zero
/* CCC384 80241074 2412000C */  addiu     $s2, $zero, 0xc
/* CCC388 80241078 860300A8 */  lh        $v1, 0xa8($s0)
/* CCC38C 8024107C 3C013F80 */  lui       $at, 0x3f80
/* CCC390 80241080 44810000 */  mtc1      $at, $f0
/* CCC394 80241084 3C014000 */  lui       $at, 0x4000
/* CCC398 80241088 44811000 */  mtc1      $at, $f2
/* CCC39C 8024108C 3C01C1A0 */  lui       $at, 0xc1a0
/* CCC3A0 80241090 44812000 */  mtc1      $at, $f4
/* CCC3A4 80241094 44834000 */  mtc1      $v1, $f8
/* CCC3A8 80241098 00000000 */  nop
/* CCC3AC 8024109C 46804220 */  cvt.s.w   $f8, $f8
/* CCC3B0 802410A0 44074000 */  mfc1      $a3, $f8
/* CCC3B4 802410A4 27A20038 */  addiu     $v0, $sp, 0x38
/* CCC3B8 802410A8 AFB2001C */  sw        $s2, 0x1c($sp)
/* CCC3BC 802410AC AFA20020 */  sw        $v0, 0x20($sp)
/* CCC3C0 802410B0 E7A00010 */  swc1      $f0, 0x10($sp)
/* CCC3C4 802410B4 E7A20014 */  swc1      $f2, 0x14($sp)
/* CCC3C8 802410B8 0C01BFA4 */  jal       fx_emote
/* CCC3CC 802410BC E7A40018 */   swc1     $f4, 0x18($sp)
/* CCC3D0 802410C0 0200202D */  daddu     $a0, $s0, $zero
/* CCC3D4 802410C4 240502F4 */  addiu     $a1, $zero, 0x2f4
/* CCC3D8 802410C8 C480003C */  lwc1      $f0, 0x3c($a0)
/* CCC3DC 802410CC 3C060020 */  lui       $a2, 0x20
/* CCC3E0 802410D0 0C012530 */  jal       func_800494C0
/* CCC3E4 802410D4 E4800064 */   swc1     $f0, 0x64($a0)
/* CCC3E8 802410D8 8E220018 */  lw        $v0, 0x18($s1)
/* CCC3EC 802410DC 9442002A */  lhu       $v0, 0x2a($v0)
/* CCC3F0 802410E0 30420001 */  andi      $v0, $v0, 1
/* CCC3F4 802410E4 10400003 */  beqz      $v0, .L802410F4
/* CCC3F8 802410E8 2402000A */   addiu    $v0, $zero, 0xa
/* CCC3FC 802410EC 080904AD */  j         .L802412B4
/* CCC400 802410F0 AE620070 */   sw       $v0, 0x70($s3)
.L802410F4:
/* CCC404 802410F4 080904AD */  j         .L802412B4
/* CCC408 802410F8 AE720070 */   sw       $s2, 0x70($s3)
.L802410FC:
/* CCC40C 802410FC 8E620074 */  lw        $v0, 0x74($s3)
/* CCC410 80241100 2442FFFF */  addiu     $v0, $v0, -1
.L80241104:
/* CCC414 80241104 08090444 */  j         .L80241110
/* CCC418 80241108 AE620074 */   sw       $v0, 0x74($s3)
.L8024110C:
/* CCC41C 8024110C AE220090 */  sw        $v0, 0x90($s1)
.L80241110:
/* CCC420 80241110 8E2300D0 */  lw        $v1, 0xd0($s1)
/* CCC424 80241114 C6000040 */  lwc1      $f0, 0x40($s0)
/* CCC428 80241118 C4620000 */  lwc1      $f2, ($v1)
/* CCC42C 8024111C 468010A0 */  cvt.s.w   $f2, $f2
/* CCC430 80241120 C4640008 */  lwc1      $f4, 8($v1)
/* CCC434 80241124 46802120 */  cvt.s.w   $f4, $f4
/* CCC438 80241128 E7A00010 */  swc1      $f0, 0x10($sp)
/* CCC43C 8024112C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CCC440 80241130 44051000 */  mfc1      $a1, $f2
/* CCC444 80241134 C440000C */  lwc1      $f0, 0xc($v0)
/* CCC448 80241138 46800020 */  cvt.s.w   $f0, $f0
/* CCC44C 8024113C E7A00014 */  swc1      $f0, 0x14($sp)
/* CCC450 80241140 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CCC454 80241144 44062000 */  mfc1      $a2, $f4
/* CCC458 80241148 C4400010 */  lwc1      $f0, 0x10($v0)
/* CCC45C 8024114C 46800020 */  cvt.s.w   $f0, $f0
/* CCC460 80241150 E7A00018 */  swc1      $f0, 0x18($sp)
/* CCC464 80241154 8C640018 */  lw        $a0, 0x18($v1)
/* CCC468 80241158 0C0123F5 */  jal       is_point_within_region
/* CCC46C 8024115C 8E070038 */   lw       $a3, 0x38($s0)
/* CCC470 80241160 1040001A */  beqz      $v0, .L802411CC
/* CCC474 80241164 00000000 */   nop
/* CCC478 80241168 8E060038 */  lw        $a2, 0x38($s0)
/* CCC47C 8024116C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CCC480 80241170 8E070040 */  lw        $a3, 0x40($s0)
/* CCC484 80241174 C44C0000 */  lwc1      $f12, ($v0)
/* CCC488 80241178 46806320 */  cvt.s.w   $f12, $f12
/* CCC48C 8024117C C44E0008 */  lwc1      $f14, 8($v0)
/* CCC490 80241180 0C00A7B5 */  jal       dist2D
/* CCC494 80241184 468073A0 */   cvt.s.w  $f14, $f14
/* CCC498 80241188 C6020018 */  lwc1      $f2, 0x18($s0)
/* CCC49C 8024118C 4600103C */  c.lt.s    $f2, $f0
/* CCC4A0 80241190 00000000 */  nop
/* CCC4A4 80241194 4500000D */  bc1f      .L802411CC
/* CCC4A8 80241198 E7A00034 */   swc1     $f0, 0x34($sp)
/* CCC4AC 8024119C C60C0038 */  lwc1      $f12, 0x38($s0)
/* CCC4B0 802411A0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CCC4B4 802411A4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CCC4B8 802411A8 C4480000 */  lwc1      $f8, ($v0)
/* CCC4BC 802411AC 46804220 */  cvt.s.w   $f8, $f8
/* CCC4C0 802411B0 44064000 */  mfc1      $a2, $f8
/* CCC4C4 802411B4 C4480008 */  lwc1      $f8, 8($v0)
/* CCC4C8 802411B8 46804220 */  cvt.s.w   $f8, $f8
/* CCC4CC 802411BC 44074000 */  mfc1      $a3, $f8
/* CCC4D0 802411C0 0C00A720 */  jal       atan2
/* CCC4D4 802411C4 24140001 */   addiu    $s4, $zero, 1
/* CCC4D8 802411C8 E600000C */  swc1      $f0, 0xc($s0)
.L802411CC:
/* CCC4DC 802411CC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* CCC4E0 802411D0 8C43000C */  lw        $v1, 0xc($v0)
/* CCC4E4 802411D4 8C420010 */  lw        $v0, 0x10($v0)
/* CCC4E8 802411D8 00621825 */  or        $v1, $v1, $v0
/* CCC4EC 802411DC 00741825 */  or        $v1, $v1, $s4
/* CCC4F0 802411E0 10600008 */  beqz      $v1, .L80241204
/* CCC4F4 802411E4 00000000 */   nop
/* CCC4F8 802411E8 8602008C */  lh        $v0, 0x8c($s0)
/* CCC4FC 802411EC 14400031 */  bnez      $v0, .L802412B4
/* CCC500 802411F0 00000000 */   nop
/* CCC504 802411F4 8E050018 */  lw        $a1, 0x18($s0)
/* CCC508 802411F8 8E06000C */  lw        $a2, 0xc($s0)
/* CCC50C 802411FC 0C00EA95 */  jal       npc_move_heading
/* CCC510 80241200 0200202D */   daddu    $a0, $s0, $zero
.L80241204:
/* CCC514 80241204 C600003C */  lwc1      $f0, 0x3c($s0)
/* CCC518 80241208 3C014059 */  lui       $at, 0x4059
/* CCC51C 8024120C 44811800 */  mtc1      $at, $f3
/* CCC520 80241210 44801000 */  mtc1      $zero, $f2
/* CCC524 80241214 46000021 */  cvt.d.s   $f0, $f0
/* CCC528 80241218 46220002 */  mul.d     $f0, $f0, $f2
/* CCC52C 8024121C 00000000 */  nop
/* CCC530 80241220 4620020D */  trunc.w.d $f8, $f0
/* CCC534 80241224 E628007C */  swc1      $f8, 0x7c($s1)
/* CCC538 80241228 8E420004 */  lw        $v0, 4($s2)
/* CCC53C 8024122C 18400021 */  blez      $v0, .L802412B4
/* CCC540 80241230 00000000 */   nop
/* CCC544 80241234 8602008E */  lh        $v0, 0x8e($s0)
/* CCC548 80241238 9603008E */  lhu       $v1, 0x8e($s0)
/* CCC54C 8024123C 18400005 */  blez      $v0, .L80241254
/* CCC550 80241240 2462FFFF */   addiu    $v0, $v1, -1
/* CCC554 80241244 A602008E */  sh        $v0, 0x8e($s0)
/* CCC558 80241248 00021400 */  sll       $v0, $v0, 0x10
/* CCC55C 8024124C 1C400019 */  bgtz      $v0, .L802412B4
/* CCC560 80241250 00000000 */   nop
.L80241254:
/* CCC564 80241254 240403E8 */  addiu     $a0, $zero, 0x3e8
/* CCC568 80241258 24020002 */  addiu     $v0, $zero, 2
/* CCC56C 8024125C 0C00A67F */  jal       rand_int
/* CCC570 80241260 AE620070 */   sw       $v0, 0x70($s3)
/* CCC574 80241264 3C035555 */  lui       $v1, 0x5555
/* CCC578 80241268 34635556 */  ori       $v1, $v1, 0x5556
/* CCC57C 8024126C 00430018 */  mult      $v0, $v1
/* CCC580 80241270 000227C3 */  sra       $a0, $v0, 0x1f
/* CCC584 80241274 00004010 */  mfhi      $t0
/* CCC588 80241278 01042023 */  subu      $a0, $t0, $a0
/* CCC58C 8024127C 00041840 */  sll       $v1, $a0, 1
/* CCC590 80241280 00641821 */  addu      $v1, $v1, $a0
/* CCC594 80241284 00431023 */  subu      $v0, $v0, $v1
/* CCC598 80241288 24430002 */  addiu     $v1, $v0, 2
/* CCC59C 8024128C AE630074 */  sw        $v1, 0x74($s3)
/* CCC5A0 80241290 8E42002C */  lw        $v0, 0x2c($s2)
/* CCC5A4 80241294 58400007 */  blezl     $v0, .L802412B4
/* CCC5A8 80241298 AE600070 */   sw       $zero, 0x70($s3)
/* CCC5AC 8024129C 8E420008 */  lw        $v0, 8($s2)
/* CCC5B0 802412A0 18400003 */  blez      $v0, .L802412B0
/* CCC5B4 802412A4 28620003 */   slti     $v0, $v1, 3
/* CCC5B8 802412A8 10400002 */  beqz      $v0, .L802412B4
/* CCC5BC 802412AC 00000000 */   nop
.L802412B0:
/* CCC5C0 802412B0 AE600070 */  sw        $zero, 0x70($s3)
.L802412B4:
/* CCC5C4 802412B4 8FBF0058 */  lw        $ra, 0x58($sp)
/* CCC5C8 802412B8 8FB50054 */  lw        $s5, 0x54($sp)
/* CCC5CC 802412BC 8FB40050 */  lw        $s4, 0x50($sp)
/* CCC5D0 802412C0 8FB3004C */  lw        $s3, 0x4c($sp)
/* CCC5D4 802412C4 8FB20048 */  lw        $s2, 0x48($sp)
/* CCC5D8 802412C8 8FB10044 */  lw        $s1, 0x44($sp)
/* CCC5DC 802412CC 8FB00040 */  lw        $s0, 0x40($sp)
/* CCC5E0 802412D0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* CCC5E4 802412D4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* CCC5E8 802412D8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* CCC5EC 802412DC D7B40060 */  ldc1      $f20, 0x60($sp)
/* CCC5F0 802412E0 03E00008 */  jr        $ra
/* CCC5F4 802412E4 27BD0080 */   addiu    $sp, $sp, 0x80
