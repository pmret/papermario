.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CA8_EEEDA8
/* EEEDA8 80241CA8 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* EEEDAC 80241CAC AFB20030 */  sw        $s2, 0x30($sp)
/* EEEDB0 80241CB0 0080902D */  daddu     $s2, $a0, $zero
/* EEEDB4 80241CB4 AFBF0038 */  sw        $ra, 0x38($sp)
/* EEEDB8 80241CB8 AFB30034 */  sw        $s3, 0x34($sp)
/* EEEDBC 80241CBC AFB1002C */  sw        $s1, 0x2c($sp)
/* EEEDC0 80241CC0 AFB00028 */  sw        $s0, 0x28($sp)
/* EEEDC4 80241CC4 F7B60048 */  sdc1      $f22, 0x48($sp)
/* EEEDC8 80241CC8 F7B40040 */  sdc1      $f20, 0x40($sp)
/* EEEDCC 80241CCC 8E510148 */  lw        $s1, 0x148($s2)
/* EEEDD0 80241CD0 86240008 */  lh        $a0, 8($s1)
/* EEEDD4 80241CD4 0C00F92F */  jal       dead_get_npc_unsafe
/* EEEDD8 80241CD8 00A0982D */   daddu    $s3, $a1, $zero
/* EEEDDC 80241CDC 0040802D */  daddu     $s0, $v0, $zero
/* EEEDE0 80241CE0 0200202D */  daddu     $a0, $s0, $zero
/* EEEDE4 80241CE4 C6220088 */  lwc1      $f2, 0x88($s1)
/* EEEDE8 80241CE8 468010A0 */  cvt.s.w   $f2, $f2
/* EEEDEC 80241CEC 460010A1 */  cvt.d.s   $f2, $f2
/* EEEDF0 80241CF0 C604001C */  lwc1      $f4, 0x1c($s0)
/* EEEDF4 80241CF4 C6000014 */  lwc1      $f0, 0x14($s0)
/* EEEDF8 80241CF8 8E050018 */  lw        $a1, 0x18($s0)
/* EEEDFC 80241CFC 46002100 */  add.s     $f4, $f4, $f0
/* EEEE00 80241D00 8E06000C */  lw        $a2, 0xc($s0)
/* EEEE04 80241D04 C6200078 */  lwc1      $f0, 0x78($s1)
/* EEEE08 80241D08 46800020 */  cvt.s.w   $f0, $f0
/* EEEE0C 80241D0C E604001C */  swc1      $f4, 0x1c($s0)
/* EEEE10 80241D10 3C014059 */  lui       $at, 0x4059
/* EEEE14 80241D14 44812800 */  mtc1      $at, $f5
/* EEEE18 80241D18 44802000 */  mtc1      $zero, $f4
/* EEEE1C 80241D1C 46000021 */  cvt.d.s   $f0, $f0
/* EEEE20 80241D20 46240003 */  div.d     $f0, $f0, $f4
/* EEEE24 80241D24 46200520 */  cvt.s.d   $f20, $f0
/* EEEE28 80241D28 46241083 */  div.d     $f2, $f2, $f4
/* EEEE2C 80241D2C 0C00F909 */  jal       func_8003E424
/* EEEE30 80241D30 462015A0 */   cvt.s.d  $f22, $f2
/* EEEE34 80241D34 C604001C */  lwc1      $f4, 0x1c($s0)
/* EEEE38 80241D38 44801000 */  mtc1      $zero, $f2
/* EEEE3C 80241D3C 44801800 */  mtc1      $zero, $f3
/* EEEE40 80241D40 46002021 */  cvt.d.s   $f0, $f4
/* EEEE44 80241D44 4620103E */  c.le.d    $f2, $f0
/* EEEE48 80241D48 00000000 */  nop
/* EEEE4C 80241D4C 45000030 */  bc1f      .L80241E10
/* EEEE50 80241D50 00000000 */   nop
/* EEEE54 80241D54 C600003C */  lwc1      $f0, 0x3c($s0)
/* EEEE58 80241D58 46040000 */  add.s     $f0, $f0, $f4
/* EEEE5C 80241D5C E600003C */  swc1      $f0, 0x3c($s0)
/* EEEE60 80241D60 8E2200CC */  lw        $v0, 0xcc($s1)
/* EEEE64 80241D64 8C420024 */  lw        $v0, 0x24($v0)
/* EEEE68 80241D68 AE020028 */  sw        $v0, 0x28($s0)
/* EEEE6C 80241D6C A2200007 */  sb        $zero, 7($s1)
/* EEEE70 80241D70 8E020000 */  lw        $v0, ($s0)
/* EEEE74 80241D74 30420008 */  andi      $v0, $v0, 8
/* EEEE78 80241D78 14400011 */  bnez      $v0, .L80241DC0
/* EEEE7C 80241D7C 0000102D */   daddu    $v0, $zero, $zero
/* EEEE80 80241D80 27A50018 */  addiu     $a1, $sp, 0x18
/* EEEE84 80241D84 27A6001C */  addiu     $a2, $sp, 0x1c
/* EEEE88 80241D88 C6000038 */  lwc1      $f0, 0x38($s0)
/* EEEE8C 80241D8C C602003C */  lwc1      $f2, 0x3c($s0)
/* EEEE90 80241D90 C6040040 */  lwc1      $f4, 0x40($s0)
/* EEEE94 80241D94 3C01447A */  lui       $at, 0x447a
/* EEEE98 80241D98 44813000 */  mtc1      $at, $f6
/* EEEE9C 80241D9C 27A20024 */  addiu     $v0, $sp, 0x24
/* EEEEA0 80241DA0 E7A00018 */  swc1      $f0, 0x18($sp)
/* EEEEA4 80241DA4 E7A2001C */  swc1      $f2, 0x1c($sp)
/* EEEEA8 80241DA8 E7A40020 */  swc1      $f4, 0x20($sp)
/* EEEEAC 80241DAC E7A60024 */  swc1      $f6, 0x24($sp)
/* EEEEB0 80241DB0 AFA20010 */  sw        $v0, 0x10($sp)
/* EEEEB4 80241DB4 8E040080 */  lw        $a0, 0x80($s0)
/* EEEEB8 80241DB8 0C03908F */  jal       func_800E423C
/* EEEEBC 80241DBC 27A70020 */   addiu    $a3, $sp, 0x20
.L80241DC0:
/* EEEEC0 80241DC0 1040000B */  beqz      $v0, .L80241DF0
/* EEEEC4 80241DC4 00000000 */   nop
/* EEEEC8 80241DC8 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* EEEECC 80241DCC 46140080 */  add.s     $f2, $f0, $f20
/* EEEED0 80241DD0 C600003C */  lwc1      $f0, 0x3c($s0)
/* EEEED4 80241DD4 4600103E */  c.le.s    $f2, $f0
/* EEEED8 80241DD8 00000000 */  nop
/* EEEEDC 80241DDC 4500008D */  bc1f      .L80242014
/* EEEEE0 80241DE0 00000000 */   nop
/* EEEEE4 80241DE4 E602003C */  swc1      $f2, 0x3c($s0)
/* EEEEE8 80241DE8 08090805 */  j         .L80242014
/* EEEEEC 80241DEC AE400070 */   sw       $zero, 0x70($s2)
.L80241DF0:
/* EEEEF0 80241DF0 C602003C */  lwc1      $f2, 0x3c($s0)
/* EEEEF4 80241DF4 C6000064 */  lwc1      $f0, 0x64($s0)
/* EEEEF8 80241DF8 4602003E */  c.le.s    $f0, $f2
/* EEEEFC 80241DFC 00000000 */  nop
/* EEEF00 80241E00 45030084 */  bc1tl     .L80242014
/* EEEF04 80241E04 AE400070 */   sw       $zero, 0x70($s2)
/* EEEF08 80241E08 08090805 */  j         .L80242014
/* EEEF0C 80241E0C 00000000 */   nop
.L80241E10:
/* EEEF10 80241E10 4622003C */  c.lt.d    $f0, $f2
/* EEEF14 80241E14 00000000 */  nop
/* EEEF18 80241E18 4500007E */  bc1f      .L80242014
/* EEEF1C 80241E1C 00000000 */   nop
/* EEEF20 80241E20 9602008E */  lhu       $v0, 0x8e($s0)
/* EEEF24 80241E24 24420001 */  addiu     $v0, $v0, 1
/* EEEF28 80241E28 A602008E */  sh        $v0, 0x8e($s0)
/* EEEF2C 80241E2C 00021400 */  sll       $v0, $v0, 0x10
/* EEEF30 80241E30 8E630020 */  lw        $v1, 0x20($s3)
/* EEEF34 80241E34 00021403 */  sra       $v0, $v0, 0x10
/* EEEF38 80241E38 0043102A */  slt       $v0, $v0, $v1
/* EEEF3C 80241E3C 14400026 */  bnez      $v0, .L80241ED8
/* EEEF40 80241E40 00000000 */   nop
/* EEEF44 80241E44 C60C0038 */  lwc1      $f12, 0x38($s0)
/* EEEF48 80241E48 C60E0040 */  lwc1      $f14, 0x40($s0)
/* EEEF4C 80241E4C 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* EEEF50 80241E50 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* EEEF54 80241E54 A600008E */  sh        $zero, 0x8e($s0)
/* EEEF58 80241E58 8C460028 */  lw        $a2, 0x28($v0)
/* EEEF5C 80241E5C 0C00ABDC */  jal       fio_validate_header_checksums
/* EEEF60 80241E60 8C470030 */   lw       $a3, 0x30($v0)
/* EEEF64 80241E64 46000506 */  mov.s     $f20, $f0
/* EEEF68 80241E68 C60C000C */  lwc1      $f12, 0xc($s0)
/* EEEF6C 80241E6C 0C00ABC6 */  jal       func_8002AF18
/* EEEF70 80241E70 4600A386 */   mov.s    $f14, $f20
/* EEEF74 80241E74 46000086 */  mov.s     $f2, $f0
/* EEEF78 80241E78 8E62001C */  lw        $v0, 0x1c($s3)
/* EEEF7C 80241E7C 46001005 */  abs.s     $f0, $f2
/* EEEF80 80241E80 44822000 */  mtc1      $v0, $f4
/* EEEF84 80241E84 00000000 */  nop
/* EEEF88 80241E88 46802120 */  cvt.s.w   $f4, $f4
/* EEEF8C 80241E8C 4600203C */  c.lt.s    $f4, $f0
/* EEEF90 80241E90 00000000 */  nop
/* EEEF94 80241E94 4500000D */  bc1f      .L80241ECC
/* EEEF98 80241E98 00000000 */   nop
/* EEEF9C 80241E9C 44800000 */  mtc1      $zero, $f0
/* EEEFA0 80241EA0 C614000C */  lwc1      $f20, 0xc($s0)
/* EEEFA4 80241EA4 4600103C */  c.lt.s    $f2, $f0
/* EEEFA8 80241EA8 00000000 */  nop
/* EEEFAC 80241EAC 45000006 */  bc1f      .L80241EC8
/* EEEFB0 80241EB0 00021023 */   negu     $v0, $v0
/* EEEFB4 80241EB4 44820000 */  mtc1      $v0, $f0
/* EEEFB8 80241EB8 00000000 */  nop
/* EEEFBC 80241EBC 46800020 */  cvt.s.w   $f0, $f0
/* EEEFC0 80241EC0 080907B3 */  j         .L80241ECC
/* EEEFC4 80241EC4 4600A500 */   add.s    $f20, $f20, $f0
.L80241EC8:
/* EEEFC8 80241EC8 4604A500 */  add.s     $f20, $f20, $f4
.L80241ECC:
/* EEEFCC 80241ECC 0C00AB85 */  jal       dead_clamp_angle
/* EEEFD0 80241ED0 4600A306 */   mov.s    $f12, $f20
/* EEEFD4 80241ED4 E600000C */  swc1      $f0, 0xc($s0)
.L80241ED8:
/* EEEFD8 80241ED8 8E020000 */  lw        $v0, ($s0)
/* EEEFDC 80241EDC 30420008 */  andi      $v0, $v0, 8
/* EEEFE0 80241EE0 1040000A */  beqz      $v0, .L80241F0C
/* EEEFE4 80241EE4 27A50018 */   addiu    $a1, $sp, 0x18
/* EEEFE8 80241EE8 C602003C */  lwc1      $f2, 0x3c($s0)
/* EEEFEC 80241EEC C600001C */  lwc1      $f0, 0x1c($s0)
/* EEEFF0 80241EF0 46001080 */  add.s     $f2, $f2, $f0
/* EEEFF4 80241EF4 4616103C */  c.lt.s    $f2, $f22
/* EEEFF8 80241EF8 00000000 */  nop
/* EEEFFC 80241EFC 45020045 */  bc1fl     .L80242014
/* EEF000 80241F00 E602003C */   swc1     $f2, 0x3c($s0)
/* EEF004 80241F04 08090804 */  j         .L80242010
/* EEF008 80241F08 E616003C */   swc1     $f22, 0x3c($s0)
.L80241F0C:
/* EEF00C 80241F0C C6000038 */  lwc1      $f0, 0x38($s0)
/* EEF010 80241F10 27A6001C */  addiu     $a2, $sp, 0x1c
/* EEF014 80241F14 E7A00018 */  swc1      $f0, 0x18($sp)
/* EEF018 80241F18 860200A8 */  lh        $v0, 0xa8($s0)
/* EEF01C 80241F1C C600001C */  lwc1      $f0, 0x1c($s0)
/* EEF020 80241F20 C604003C */  lwc1      $f4, 0x3c($s0)
/* EEF024 80241F24 44821000 */  mtc1      $v0, $f2
/* EEF028 80241F28 00000000 */  nop
/* EEF02C 80241F2C 468010A0 */  cvt.s.w   $f2, $f2
/* EEF030 80241F30 46000005 */  abs.s     $f0, $f0
/* EEF034 80241F34 46020000 */  add.s     $f0, $f0, $f2
/* EEF038 80241F38 C6060040 */  lwc1      $f6, 0x40($s0)
/* EEF03C 80241F3C 27A20024 */  addiu     $v0, $sp, 0x24
/* EEF040 80241F40 46022100 */  add.s     $f4, $f4, $f2
/* EEF044 80241F44 3C014024 */  lui       $at, 0x4024
/* EEF048 80241F48 44811800 */  mtc1      $at, $f3
/* EEF04C 80241F4C 44801000 */  mtc1      $zero, $f2
/* EEF050 80241F50 46000021 */  cvt.d.s   $f0, $f0
/* EEF054 80241F54 46220000 */  add.d     $f0, $f0, $f2
/* EEF058 80241F58 E7A60020 */  swc1      $f6, 0x20($sp)
/* EEF05C 80241F5C E7A4001C */  swc1      $f4, 0x1c($sp)
/* EEF060 80241F60 46200020 */  cvt.s.d   $f0, $f0
/* EEF064 80241F64 E7A00024 */  swc1      $f0, 0x24($sp)
/* EEF068 80241F68 AFA20010 */  sw        $v0, 0x10($sp)
/* EEF06C 80241F6C 8E040080 */  lw        $a0, 0x80($s0)
/* EEF070 80241F70 0C03908F */  jal       func_800E423C
/* EEF074 80241F74 27A70020 */   addiu    $a3, $sp, 0x20
/* EEF078 80241F78 10400015 */  beqz      $v0, .L80241FD0
/* EEF07C 80241F7C 00000000 */   nop
/* EEF080 80241F80 860200A8 */  lh        $v0, 0xa8($s0)
/* EEF084 80241F84 C604001C */  lwc1      $f4, 0x1c($s0)
/* EEF088 80241F88 44820000 */  mtc1      $v0, $f0
/* EEF08C 80241F8C 00000000 */  nop
/* EEF090 80241F90 46800020 */  cvt.s.w   $f0, $f0
/* EEF094 80241F94 46002085 */  abs.s     $f2, $f4
/* EEF098 80241F98 46020000 */  add.s     $f0, $f0, $f2
/* EEF09C 80241F9C C7A20024 */  lwc1      $f2, 0x24($sp)
/* EEF0A0 80241FA0 4600103E */  c.le.s    $f2, $f0
/* EEF0A4 80241FA4 00000000 */  nop
/* EEF0A8 80241FA8 45000005 */  bc1f      .L80241FC0
/* EEF0AC 80241FAC 00000000 */   nop
/* EEF0B0 80241FB0 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* EEF0B4 80241FB4 AE00001C */  sw        $zero, 0x1c($s0)
/* EEF0B8 80241FB8 08090805 */  j         .L80242014
/* EEF0BC 80241FBC E600003C */   swc1     $f0, 0x3c($s0)
.L80241FC0:
/* EEF0C0 80241FC0 C600003C */  lwc1      $f0, 0x3c($s0)
/* EEF0C4 80241FC4 46040000 */  add.s     $f0, $f0, $f4
/* EEF0C8 80241FC8 08090805 */  j         .L80242014
/* EEF0CC 80241FCC E600003C */   swc1     $f0, 0x3c($s0)
.L80241FD0:
/* EEF0D0 80241FD0 C606003C */  lwc1      $f6, 0x3c($s0)
/* EEF0D4 80241FD4 860200A8 */  lh        $v0, 0xa8($s0)
/* EEF0D8 80241FD8 46163081 */  sub.s     $f2, $f6, $f22
/* EEF0DC 80241FDC 44820000 */  mtc1      $v0, $f0
/* EEF0E0 80241FE0 00000000 */  nop
/* EEF0E4 80241FE4 46800020 */  cvt.s.w   $f0, $f0
/* EEF0E8 80241FE8 46001080 */  add.s     $f2, $f2, $f0
/* EEF0EC 80241FEC C604001C */  lwc1      $f4, 0x1c($s0)
/* EEF0F0 80241FF0 46002005 */  abs.s     $f0, $f4
/* EEF0F4 80241FF4 4602003C */  c.lt.s    $f0, $f2
/* EEF0F8 80241FF8 00000000 */  nop
/* EEF0FC 80241FFC 45020005 */  bc1fl     .L80242014
/* EEF100 80242000 AE00001C */   sw       $zero, 0x1c($s0)
/* EEF104 80242004 46043000 */  add.s     $f0, $f6, $f4
/* EEF108 80242008 08090805 */  j         .L80242014
/* EEF10C 8024200C E600003C */   swc1     $f0, 0x3c($s0)
.L80242010:
/* EEF110 80242010 AE00001C */  sw        $zero, 0x1c($s0)
.L80242014:
/* EEF114 80242014 8FBF0038 */  lw        $ra, 0x38($sp)
/* EEF118 80242018 8FB30034 */  lw        $s3, 0x34($sp)
/* EEF11C 8024201C 8FB20030 */  lw        $s2, 0x30($sp)
/* EEF120 80242020 8FB1002C */  lw        $s1, 0x2c($sp)
/* EEF124 80242024 8FB00028 */  lw        $s0, 0x28($sp)
/* EEF128 80242028 D7B60048 */  ldc1      $f22, 0x48($sp)
/* EEF12C 8024202C D7B40040 */  ldc1      $f20, 0x40($sp)
/* EEF130 80242030 03E00008 */  jr        $ra
/* EEF134 80242034 27BD0050 */   addiu    $sp, $sp, 0x50
