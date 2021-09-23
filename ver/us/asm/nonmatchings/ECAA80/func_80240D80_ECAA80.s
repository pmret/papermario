.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D80_ECAA80
/* ECAA80 80240D80 27BDFF68 */  addiu     $sp, $sp, -0x98
/* ECAA84 80240D84 AFB60060 */  sw        $s6, 0x60($sp)
/* ECAA88 80240D88 0080B02D */  daddu     $s6, $a0, $zero
/* ECAA8C 80240D8C AFBF0064 */  sw        $ra, 0x64($sp)
/* ECAA90 80240D90 AFB5005C */  sw        $s5, 0x5c($sp)
/* ECAA94 80240D94 AFB40058 */  sw        $s4, 0x58($sp)
/* ECAA98 80240D98 AFB30054 */  sw        $s3, 0x54($sp)
/* ECAA9C 80240D9C AFB20050 */  sw        $s2, 0x50($sp)
/* ECAAA0 80240DA0 AFB1004C */  sw        $s1, 0x4c($sp)
/* ECAAA4 80240DA4 AFB00048 */  sw        $s0, 0x48($sp)
/* ECAAA8 80240DA8 F7BE0090 */  sdc1      $f30, 0x90($sp)
/* ECAAAC 80240DAC F7BC0088 */  sdc1      $f28, 0x88($sp)
/* ECAAB0 80240DB0 F7BA0080 */  sdc1      $f26, 0x80($sp)
/* ECAAB4 80240DB4 F7B80078 */  sdc1      $f24, 0x78($sp)
/* ECAAB8 80240DB8 F7B60070 */  sdc1      $f22, 0x70($sp)
/* ECAABC 80240DBC F7B40068 */  sdc1      $f20, 0x68($sp)
/* ECAAC0 80240DC0 8ED20148 */  lw        $s2, 0x148($s6)
/* ECAAC4 80240DC4 00A0882D */  daddu     $s1, $a1, $zero
/* ECAAC8 80240DC8 86440008 */  lh        $a0, 8($s2)
/* ECAACC 80240DCC 0C00F92F */  jal       dead_get_npc_unsafe
/* ECAAD0 80240DD0 00C0A82D */   daddu    $s5, $a2, $zero
/* ECAAD4 80240DD4 8E240020 */  lw        $a0, 0x20($s1)
/* ECAAD8 80240DD8 0040802D */  daddu     $s0, $v0, $zero
/* ECAADC 80240DDC 00041FC2 */  srl       $v1, $a0, 0x1f
/* ECAAE0 80240DE0 00832021 */  addu      $a0, $a0, $v1
/* ECAAE4 80240DE4 00042043 */  sra       $a0, $a0, 1
/* ECAAE8 80240DE8 0C00AB3B */  jal       dead_rand_int
/* ECAAEC 80240DEC 24840001 */   addiu    $a0, $a0, 1
/* ECAAF0 80240DF0 8E230020 */  lw        $v1, 0x20($s1)
/* ECAAF4 80240DF4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* ECAAF8 80240DF8 000327C2 */  srl       $a0, $v1, 0x1f
/* ECAAFC 80240DFC 00641821 */  addu      $v1, $v1, $a0
/* ECAB00 80240E00 00031843 */  sra       $v1, $v1, 1
/* ECAB04 80240E04 00621821 */  addu      $v1, $v1, $v0
/* ECAB08 80240E08 A603008E */  sh        $v1, 0x8e($s0)
/* ECAB0C 80240E0C 8E4200CC */  lw        $v0, 0xcc($s2)
/* ECAB10 80240E10 C60E0040 */  lwc1      $f14, 0x40($s0)
/* ECAB14 80240E14 8C42000C */  lw        $v0, 0xc($v0)
/* ECAB18 80240E18 AE020028 */  sw        $v0, 0x28($s0)
/* ECAB1C 80240E1C C6200018 */  lwc1      $f0, 0x18($s1)
/* ECAB20 80240E20 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* ECAB24 80240E24 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* ECAB28 80240E28 E6000018 */  swc1      $f0, 0x18($s0)
/* ECAB2C 80240E2C 8C460028 */  lw        $a2, 0x28($v0)
/* ECAB30 80240E30 8C470030 */  lw        $a3, 0x30($v0)
/* ECAB34 80240E34 0C00ABDC */  jal       fio_validate_header_checksums
/* ECAB38 80240E38 0000982D */   daddu    $s3, $zero, $zero
/* ECAB3C 80240E3C 3C014334 */  lui       $at, 0x4334
/* ECAB40 80240E40 44816000 */  mtc1      $at, $f12
/* ECAB44 80240E44 0C00AB85 */  jal       dead_clamp_angle
/* ECAB48 80240E48 460C0300 */   add.s    $f12, $f0, $f12
/* ECAB4C 80240E4C 46000506 */  mov.s     $f20, $f0
/* ECAB50 80240E50 C60C000C */  lwc1      $f12, 0xc($s0)
/* ECAB54 80240E54 0C00ABC6 */  jal       dead_get_clamped_angle_diff
/* ECAB58 80240E58 4600A386 */   mov.s    $f14, $f20
/* ECAB5C 80240E5C 46000086 */  mov.s     $f2, $f0
/* ECAB60 80240E60 8E22001C */  lw        $v0, 0x1c($s1)
/* ECAB64 80240E64 46001005 */  abs.s     $f0, $f2
/* ECAB68 80240E68 44822000 */  mtc1      $v0, $f4
/* ECAB6C 80240E6C 00000000 */  nop
/* ECAB70 80240E70 46802120 */  cvt.s.w   $f4, $f4
/* ECAB74 80240E74 4600203C */  c.lt.s    $f4, $f0
/* ECAB78 80240E78 00000000 */  nop
/* ECAB7C 80240E7C 4500000D */  bc1f      .L80240EB4
/* ECAB80 80240E80 00000000 */   nop
/* ECAB84 80240E84 44800000 */  mtc1      $zero, $f0
/* ECAB88 80240E88 C614000C */  lwc1      $f20, 0xc($s0)
/* ECAB8C 80240E8C 4600103C */  c.lt.s    $f2, $f0
/* ECAB90 80240E90 00000000 */  nop
/* ECAB94 80240E94 45000006 */  bc1f      .L80240EB0
/* ECAB98 80240E98 00021023 */   negu     $v0, $v0
/* ECAB9C 80240E9C 44820000 */  mtc1      $v0, $f0
/* ECABA0 80240EA0 00000000 */  nop
/* ECABA4 80240EA4 46800020 */  cvt.s.w   $f0, $f0
/* ECABA8 80240EA8 080903AD */  j         .L80240EB4
/* ECABAC 80240EAC 4600A500 */   add.s    $f20, $f20, $f0
.L80240EB0:
/* ECABB0 80240EB0 4604A500 */  add.s     $f20, $f20, $f4
.L80240EB4:
/* ECABB4 80240EB4 0C00AB85 */  jal       dead_clamp_angle
/* ECABB8 80240EB8 4600A306 */   mov.s    $f12, $f20
/* ECABBC 80240EBC 3C148010 */  lui       $s4, %hi(dead_gPlayerStatusPtr)
/* ECABC0 80240EC0 2694FC90 */  addiu     $s4, $s4, %lo(dead_gPlayerStatusPtr)
/* ECABC4 80240EC4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* ECABC8 80240EC8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* ECABCC 80240ECC 8E820000 */  lw        $v0, ($s4)
/* ECABD0 80240ED0 C602003C */  lwc1      $f2, 0x3c($s0)
/* ECABD4 80240ED4 E600000C */  swc1      $f0, 0xc($s0)
/* ECABD8 80240ED8 46006006 */  mov.s     $f0, $f12
/* ECABDC 80240EDC 8C460028 */  lw        $a2, 0x28($v0)
/* ECABE0 80240EE0 8C470030 */  lw        $a3, 0x30($v0)
/* ECABE4 80240EE4 46007106 */  mov.s     $f4, $f14
/* ECABE8 80240EE8 E7A00020 */  swc1      $f0, 0x20($sp)
/* ECABEC 80240EEC E7A20024 */  swc1      $f2, 0x24($sp)
/* ECABF0 80240EF0 0C00ABDC */  jal       fio_validate_header_checksums
/* ECABF4 80240EF4 E7A40028 */   swc1     $f4, 0x28($sp)
/* ECABF8 80240EF8 3C014334 */  lui       $at, 0x4334
/* ECABFC 80240EFC 44816000 */  mtc1      $at, $f12
/* ECAC00 80240F00 0C00AB85 */  jal       dead_clamp_angle
/* ECAC04 80240F04 460C0300 */   add.s    $f12, $f0, $f12
/* ECAC08 80240F08 C6020018 */  lwc1      $f2, 0x18($s0)
/* ECAC0C 80240F0C 3C014012 */  lui       $at, 0x4012
/* ECAC10 80240F10 4481E800 */  mtc1      $at, $f29
/* ECAC14 80240F14 4480E000 */  mtc1      $zero, $f28
/* ECAC18 80240F18 460010A1 */  cvt.d.s   $f2, $f2
/* ECAC1C 80240F1C 463C1082 */  mul.d     $f2, $f2, $f28
/* ECAC20 80240F20 00000000 */  nop
/* ECAC24 80240F24 46000506 */  mov.s     $f20, $f0
/* ECAC28 80240F28 27A50020 */  addiu     $a1, $sp, 0x20
/* ECAC2C 80240F2C 27A60024 */  addiu     $a2, $sp, 0x24
/* ECAC30 80240F30 27A70028 */  addiu     $a3, $sp, 0x28
/* ECAC34 80240F34 E7B40014 */  swc1      $f20, 0x14($sp)
/* ECAC38 80240F38 462010A0 */  cvt.s.d   $f2, $f2
/* ECAC3C 80240F3C E7A20010 */  swc1      $f2, 0x10($sp)
/* ECAC40 80240F40 860200A8 */  lh        $v0, 0xa8($s0)
/* ECAC44 80240F44 4480B000 */  mtc1      $zero, $f22
/* ECAC48 80240F48 44820000 */  mtc1      $v0, $f0
/* ECAC4C 80240F4C 00000000 */  nop
/* ECAC50 80240F50 46800020 */  cvt.s.w   $f0, $f0
/* ECAC54 80240F54 E7A00018 */  swc1      $f0, 0x18($sp)
/* ECAC58 80240F58 860200A6 */  lh        $v0, 0xa6($s0)
/* ECAC5C 80240F5C 4600B606 */  mov.s     $f24, $f22
/* ECAC60 80240F60 44820000 */  mtc1      $v0, $f0
/* ECAC64 80240F64 00000000 */  nop
/* ECAC68 80240F68 46800020 */  cvt.s.w   $f0, $f0
/* ECAC6C 80240F6C E7A0001C */  swc1      $f0, 0x1c($sp)
/* ECAC70 80240F70 8E040080 */  lw        $a0, 0x80($s0)
/* ECAC74 80240F74 0C0394EB */  jal       func_800E53AC
/* ECAC78 80240F78 4600C686 */   mov.s    $f26, $f24
/* ECAC7C 80240F7C 104000E1 */  beqz      $v0, .L80241304
/* ECAC80 80240F80 00000000 */   nop
/* ECAC84 80240F84 C60C0038 */  lwc1      $f12, 0x38($s0)
/* ECAC88 80240F88 C60E0040 */  lwc1      $f14, 0x40($s0)
/* ECAC8C 80240F8C 8FA60020 */  lw        $a2, 0x20($sp)
/* ECAC90 80240F90 0C00AC71 */  jal       dead_dist2D
/* ECAC94 80240F94 8FA70028 */   lw       $a3, 0x28($sp)
/* ECAC98 80240F98 46000586 */  mov.s     $f22, $f0
/* ECAC9C 80240F9C C6020038 */  lwc1      $f2, 0x38($s0)
/* ECACA0 80240FA0 C604003C */  lwc1      $f4, 0x3c($s0)
/* ECACA4 80240FA4 3C01420C */  lui       $at, 0x420c
/* ECACA8 80240FA8 4481F000 */  mtc1      $at, $f30
/* ECACAC 80240FAC C6000040 */  lwc1      $f0, 0x40($s0)
/* ECACB0 80240FB0 461EA300 */  add.s     $f12, $f20, $f30
/* ECACB4 80240FB4 E7A2002C */  swc1      $f2, 0x2c($sp)
/* ECACB8 80240FB8 E7A40030 */  swc1      $f4, 0x30($sp)
/* ECACBC 80240FBC 0C00AB85 */  jal       dead_clamp_angle
/* ECACC0 80240FC0 E7A00034 */   swc1     $f0, 0x34($sp)
/* ECACC4 80240FC4 C6020018 */  lwc1      $f2, 0x18($s0)
/* ECACC8 80240FC8 460010A1 */  cvt.d.s   $f2, $f2
/* ECACCC 80240FCC 463C1082 */  mul.d     $f2, $f2, $f28
/* ECACD0 80240FD0 00000000 */  nop
/* ECACD4 80240FD4 E7A00014 */  swc1      $f0, 0x14($sp)
/* ECACD8 80240FD8 462010A0 */  cvt.s.d   $f2, $f2
/* ECACDC 80240FDC E7A20010 */  swc1      $f2, 0x10($sp)
/* ECACE0 80240FE0 860200A8 */  lh        $v0, 0xa8($s0)
/* ECACE4 80240FE4 27A5002C */  addiu     $a1, $sp, 0x2c
/* ECACE8 80240FE8 44820000 */  mtc1      $v0, $f0
/* ECACEC 80240FEC 00000000 */  nop
/* ECACF0 80240FF0 46800020 */  cvt.s.w   $f0, $f0
/* ECACF4 80240FF4 E7A00018 */  swc1      $f0, 0x18($sp)
/* ECACF8 80240FF8 860200A6 */  lh        $v0, 0xa6($s0)
/* ECACFC 80240FFC 27A60030 */  addiu     $a2, $sp, 0x30
/* ECAD00 80241000 44820000 */  mtc1      $v0, $f0
/* ECAD04 80241004 00000000 */  nop
/* ECAD08 80241008 46800020 */  cvt.s.w   $f0, $f0
/* ECAD0C 8024100C E7A0001C */  swc1      $f0, 0x1c($sp)
/* ECAD10 80241010 8E040080 */  lw        $a0, 0x80($s0)
/* ECAD14 80241014 0C0394EB */  jal       func_800E53AC
/* ECAD18 80241018 27A70034 */   addiu    $a3, $sp, 0x34
/* ECAD1C 8024101C 10400007 */  beqz      $v0, .L8024103C
/* ECAD20 80241020 00000000 */   nop
/* ECAD24 80241024 C60C0038 */  lwc1      $f12, 0x38($s0)
/* ECAD28 80241028 C60E0040 */  lwc1      $f14, 0x40($s0)
/* ECAD2C 8024102C 8FA6002C */  lw        $a2, 0x2c($sp)
/* ECAD30 80241030 0C00AC71 */  jal       dead_dist2D
/* ECAD34 80241034 8FA70034 */   lw       $a3, 0x34($sp)
/* ECAD38 80241038 46000606 */  mov.s     $f24, $f0
.L8024103C:
/* ECAD3C 8024103C C6000038 */  lwc1      $f0, 0x38($s0)
/* ECAD40 80241040 C602003C */  lwc1      $f2, 0x3c($s0)
/* ECAD44 80241044 C6040040 */  lwc1      $f4, 0x40($s0)
/* ECAD48 80241048 461EA301 */  sub.s     $f12, $f20, $f30
/* ECAD4C 8024104C E7A00038 */  swc1      $f0, 0x38($sp)
/* ECAD50 80241050 E7A2003C */  swc1      $f2, 0x3c($sp)
/* ECAD54 80241054 0C00AB85 */  jal       dead_clamp_angle
/* ECAD58 80241058 E7A40040 */   swc1     $f4, 0x40($sp)
/* ECAD5C 8024105C C6020018 */  lwc1      $f2, 0x18($s0)
/* ECAD60 80241060 460010A1 */  cvt.d.s   $f2, $f2
/* ECAD64 80241064 463C1082 */  mul.d     $f2, $f2, $f28
/* ECAD68 80241068 00000000 */  nop
/* ECAD6C 8024106C E7A00014 */  swc1      $f0, 0x14($sp)
/* ECAD70 80241070 462010A0 */  cvt.s.d   $f2, $f2
/* ECAD74 80241074 E7A20010 */  swc1      $f2, 0x10($sp)
/* ECAD78 80241078 860200A8 */  lh        $v0, 0xa8($s0)
/* ECAD7C 8024107C 27A50038 */  addiu     $a1, $sp, 0x38
/* ECAD80 80241080 44820000 */  mtc1      $v0, $f0
/* ECAD84 80241084 00000000 */  nop
/* ECAD88 80241088 46800020 */  cvt.s.w   $f0, $f0
/* ECAD8C 8024108C E7A00018 */  swc1      $f0, 0x18($sp)
/* ECAD90 80241090 860200A6 */  lh        $v0, 0xa6($s0)
/* ECAD94 80241094 27A6003C */  addiu     $a2, $sp, 0x3c
/* ECAD98 80241098 44820000 */  mtc1      $v0, $f0
/* ECAD9C 8024109C 00000000 */  nop
/* ECADA0 802410A0 46800020 */  cvt.s.w   $f0, $f0
/* ECADA4 802410A4 E7A0001C */  swc1      $f0, 0x1c($sp)
/* ECADA8 802410A8 8E040080 */  lw        $a0, 0x80($s0)
/* ECADAC 802410AC 0C0394EB */  jal       func_800E53AC
/* ECADB0 802410B0 27A70040 */   addiu    $a3, $sp, 0x40
/* ECADB4 802410B4 10400007 */  beqz      $v0, .L802410D4
/* ECADB8 802410B8 00000000 */   nop
/* ECADBC 802410BC C60C0038 */  lwc1      $f12, 0x38($s0)
/* ECADC0 802410C0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* ECADC4 802410C4 8FA60038 */  lw        $a2, 0x38($sp)
/* ECADC8 802410C8 0C00AC71 */  jal       dead_dist2D
/* ECADCC 802410CC 8FA70040 */   lw       $a3, 0x40($sp)
/* ECADD0 802410D0 46000686 */  mov.s     $f26, $f0
.L802410D4:
/* ECADD4 802410D4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* ECADD8 802410D8 8E820000 */  lw        $v0, ($s4)
/* ECADDC 802410DC C60E0040 */  lwc1      $f14, 0x40($s0)
/* ECADE0 802410E0 8C460028 */  lw        $a2, 0x28($v0)
/* ECADE4 802410E4 0C00AC71 */  jal       dead_dist2D
/* ECADE8 802410E8 8C470030 */   lw       $a3, 0x30($v0)
/* ECADEC 802410EC C6000018 */  lwc1      $f0, 0x18($s0)
/* ECADF0 802410F0 3C013FF8 */  lui       $at, 0x3ff8
/* ECADF4 802410F4 44811800 */  mtc1      $at, $f3
/* ECADF8 802410F8 44801000 */  mtc1      $zero, $f2
/* ECADFC 802410FC 46000021 */  cvt.d.s   $f0, $f0
/* ECAE00 80241100 46220082 */  mul.d     $f2, $f0, $f2
/* ECAE04 80241104 00000000 */  nop
/* ECAE08 80241108 4600B021 */  cvt.d.s   $f0, $f22
/* ECAE0C 8024110C 4622003C */  c.lt.d    $f0, $f2
/* ECAE10 80241110 00000000 */  nop
/* ECAE14 80241114 45000012 */  bc1f      .L80241160
/* ECAE18 80241118 00000000 */   nop
/* ECAE1C 8024111C 4600C021 */  cvt.d.s   $f0, $f24
/* ECAE20 80241120 4622003C */  c.lt.d    $f0, $f2
/* ECAE24 80241124 00000000 */  nop
/* ECAE28 80241128 4500000D */  bc1f      .L80241160
/* ECAE2C 8024112C 00000000 */   nop
/* ECAE30 80241130 4600D021 */  cvt.d.s   $f0, $f26
/* ECAE34 80241134 4622003C */  c.lt.d    $f0, $f2
/* ECAE38 80241138 00000000 */  nop
/* ECAE3C 8024113C 45000008 */  bc1f      .L80241160
/* ECAE40 80241140 02A0202D */   daddu    $a0, $s5, $zero
/* ECAE44 80241144 AFA00010 */  sw        $zero, 0x10($sp)
/* ECAE48 80241148 8E26000C */  lw        $a2, 0xc($s1)
/* ECAE4C 8024114C 8E270010 */  lw        $a3, 0x10($s1)
/* ECAE50 80241150 0C013469 */  jal       func_8004D1A4
/* ECAE54 80241154 0240282D */   daddu    $a1, $s2, $zero
/* ECAE58 80241158 54400001 */  bnel      $v0, $zero, .L80241160
/* ECAE5C 8024115C 24130001 */   addiu    $s3, $zero, 1
.L80241160:
/* ECAE60 80241160 1660006A */  bnez      $s3, .L8024130C
/* ECAE64 80241164 2402000A */   addiu    $v0, $zero, 0xa
/* ECAE68 80241168 4616C03C */  c.lt.s    $f24, $f22
/* ECAE6C 8024116C 00000000 */  nop
/* ECAE70 80241170 4500000C */  bc1f      .L802411A4
/* ECAE74 80241174 00000000 */   nop
/* ECAE78 80241178 4618D03C */  c.lt.s    $f26, $f24
/* ECAE7C 8024117C 00000000 */  nop
/* ECAE80 80241180 45000006 */  bc1f      .L8024119C
/* ECAE84 80241184 00000000 */   nop
/* ECAE88 80241188 C60C0038 */  lwc1      $f12, 0x38($s0)
/* ECAE8C 8024118C C60E0040 */  lwc1      $f14, 0x40($s0)
/* ECAE90 80241190 8FA60020 */  lw        $a2, 0x20($sp)
/* ECAE94 80241194 080904A2 */  j         .L80241288
/* ECAE98 80241198 8FA70028 */   lw       $a3, 0x28($sp)
.L8024119C:
/* ECAE9C 8024119C 4616C03C */  c.lt.s    $f24, $f22
/* ECAEA0 802411A0 00000000 */  nop
.L802411A4:
/* ECAEA4 802411A4 4500000A */  bc1f      .L802411D0
/* ECAEA8 802411A8 00000000 */   nop
/* ECAEAC 802411AC 461AC03C */  c.lt.s    $f24, $f26
/* ECAEB0 802411B0 00000000 */  nop
/* ECAEB4 802411B4 45000006 */  bc1f      .L802411D0
/* ECAEB8 802411B8 00000000 */   nop
/* ECAEBC 802411BC C60C0038 */  lwc1      $f12, 0x38($s0)
/* ECAEC0 802411C0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* ECAEC4 802411C4 8FA60020 */  lw        $a2, 0x20($sp)
/* ECAEC8 802411C8 080904A2 */  j         .L80241288
/* ECAECC 802411CC 8FA70028 */   lw       $a3, 0x28($sp)
.L802411D0:
/* ECAED0 802411D0 4618B03C */  c.lt.s    $f22, $f24
/* ECAED4 802411D4 00000000 */  nop
/* ECAED8 802411D8 4500000A */  bc1f      .L80241204
/* ECAEDC 802411DC 00000000 */   nop
/* ECAEE0 802411E0 4616D03C */  c.lt.s    $f26, $f22
/* ECAEE4 802411E4 00000000 */  nop
/* ECAEE8 802411E8 45000006 */  bc1f      .L80241204
/* ECAEEC 802411EC 00000000 */   nop
/* ECAEF0 802411F0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* ECAEF4 802411F4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* ECAEF8 802411F8 8FA6002C */  lw        $a2, 0x2c($sp)
/* ECAEFC 802411FC 080904A2 */  j         .L80241288
/* ECAF00 80241200 8FA70034 */   lw       $a3, 0x34($sp)
.L80241204:
/* ECAF04 80241204 4618D03C */  c.lt.s    $f26, $f24
/* ECAF08 80241208 00000000 */  nop
/* ECAF0C 8024120C 4500000A */  bc1f      .L80241238
/* ECAF10 80241210 00000000 */   nop
/* ECAF14 80241214 461AB03C */  c.lt.s    $f22, $f26
/* ECAF18 80241218 00000000 */  nop
/* ECAF1C 8024121C 45000008 */  bc1f      .L80241240
/* ECAF20 80241220 00000000 */   nop
/* ECAF24 80241224 C60C0038 */  lwc1      $f12, 0x38($s0)
/* ECAF28 80241228 C60E0040 */  lwc1      $f14, 0x40($s0)
/* ECAF2C 8024122C 8FA6002C */  lw        $a2, 0x2c($sp)
/* ECAF30 80241230 080904A2 */  j         .L80241288
/* ECAF34 80241234 8FA70034 */   lw       $a3, 0x34($sp)
.L80241238:
/* ECAF38 80241238 461AB03C */  c.lt.s    $f22, $f26
/* ECAF3C 8024123C 00000000 */  nop
.L80241240:
/* ECAF40 80241240 45000005 */  bc1f      .L80241258
/* ECAF44 80241244 00000000 */   nop
/* ECAF48 80241248 4616C03C */  c.lt.s    $f24, $f22
/* ECAF4C 8024124C 00000000 */  nop
/* ECAF50 80241250 45010009 */  bc1t      .L80241278
/* ECAF54 80241254 00000000 */   nop
.L80241258:
/* ECAF58 80241258 461AC03C */  c.lt.s    $f24, $f26
/* ECAF5C 8024125C 00000000 */  nop
/* ECAF60 80241260 4500000C */  bc1f      .L80241294
/* ECAF64 80241264 00000000 */   nop
/* ECAF68 80241268 4618B03C */  c.lt.s    $f22, $f24
/* ECAF6C 8024126C 00000000 */  nop
/* ECAF70 80241270 45000008 */  bc1f      .L80241294
/* ECAF74 80241274 00000000 */   nop
.L80241278:
/* ECAF78 80241278 C60C0038 */  lwc1      $f12, 0x38($s0)
/* ECAF7C 8024127C C60E0040 */  lwc1      $f14, 0x40($s0)
/* ECAF80 80241280 8FA60038 */  lw        $a2, 0x38($sp)
/* ECAF84 80241284 8FA70040 */  lw        $a3, 0x40($sp)
.L80241288:
/* ECAF88 80241288 0C00ABDC */  jal       fio_validate_header_checksums
/* ECAF8C 8024128C 00000000 */   nop
/* ECAF90 80241290 46000506 */  mov.s     $f20, $f0
.L80241294:
/* ECAF94 80241294 C60C000C */  lwc1      $f12, 0xc($s0)
/* ECAF98 80241298 0C00ABC6 */  jal       dead_get_clamped_angle_diff
/* ECAF9C 8024129C 4600A386 */   mov.s    $f14, $f20
/* ECAFA0 802412A0 46000086 */  mov.s     $f2, $f0
/* ECAFA4 802412A4 8E22001C */  lw        $v0, 0x1c($s1)
/* ECAFA8 802412A8 46001005 */  abs.s     $f0, $f2
/* ECAFAC 802412AC 44822000 */  mtc1      $v0, $f4
/* ECAFB0 802412B0 00000000 */  nop
/* ECAFB4 802412B4 46802120 */  cvt.s.w   $f4, $f4
/* ECAFB8 802412B8 4600203C */  c.lt.s    $f4, $f0
/* ECAFBC 802412BC 00000000 */  nop
/* ECAFC0 802412C0 4500000D */  bc1f      .L802412F8
/* ECAFC4 802412C4 00000000 */   nop
/* ECAFC8 802412C8 44800000 */  mtc1      $zero, $f0
/* ECAFCC 802412CC C614000C */  lwc1      $f20, 0xc($s0)
/* ECAFD0 802412D0 4600103C */  c.lt.s    $f2, $f0
/* ECAFD4 802412D4 00000000 */  nop
/* ECAFD8 802412D8 45000006 */  bc1f      .L802412F4
/* ECAFDC 802412DC 00021023 */   negu     $v0, $v0
/* ECAFE0 802412E0 44820000 */  mtc1      $v0, $f0
/* ECAFE4 802412E4 00000000 */  nop
/* ECAFE8 802412E8 46800020 */  cvt.s.w   $f0, $f0
/* ECAFEC 802412EC 080904BE */  j         .L802412F8
/* ECAFF0 802412F0 4600A500 */   add.s    $f20, $f20, $f0
.L802412F4:
/* ECAFF4 802412F4 4604A500 */  add.s     $f20, $f20, $f4
.L802412F8:
/* ECAFF8 802412F8 0C00AB85 */  jal       dead_clamp_angle
/* ECAFFC 802412FC 4600A306 */   mov.s    $f12, $f20
/* ECB000 80241300 E600000C */  swc1      $f0, 0xc($s0)
.L80241304:
/* ECB004 80241304 12600005 */  beqz      $s3, .L8024131C
/* ECB008 80241308 2402000A */   addiu    $v0, $zero, 0xa
.L8024130C:
/* ECB00C 8024130C A602008E */  sh        $v0, 0x8e($s0)
/* ECB010 80241310 8E4200CC */  lw        $v0, 0xcc($s2)
/* ECB014 80241314 8C420020 */  lw        $v0, 0x20($v0)
/* ECB018 80241318 AE020028 */  sw        $v0, 0x28($s0)
.L8024131C:
/* ECB01C 8024131C 2402000D */  addiu     $v0, $zero, 0xd
/* ECB020 80241320 AEC20070 */  sw        $v0, 0x70($s6)
/* ECB024 80241324 8FBF0064 */  lw        $ra, 0x64($sp)
/* ECB028 80241328 8FB60060 */  lw        $s6, 0x60($sp)
/* ECB02C 8024132C 8FB5005C */  lw        $s5, 0x5c($sp)
/* ECB030 80241330 8FB40058 */  lw        $s4, 0x58($sp)
/* ECB034 80241334 8FB30054 */  lw        $s3, 0x54($sp)
/* ECB038 80241338 8FB20050 */  lw        $s2, 0x50($sp)
/* ECB03C 8024133C 8FB1004C */  lw        $s1, 0x4c($sp)
/* ECB040 80241340 8FB00048 */  lw        $s0, 0x48($sp)
/* ECB044 80241344 D7BE0090 */  ldc1      $f30, 0x90($sp)
/* ECB048 80241348 D7BC0088 */  ldc1      $f28, 0x88($sp)
/* ECB04C 8024134C D7BA0080 */  ldc1      $f26, 0x80($sp)
/* ECB050 80241350 D7B80078 */  ldc1      $f24, 0x78($sp)
/* ECB054 80241354 D7B60070 */  ldc1      $f22, 0x70($sp)
/* ECB058 80241358 D7B40068 */  ldc1      $f20, 0x68($sp)
/* ECB05C 8024135C 03E00008 */  jr        $ra
/* ECB060 80241360 27BD0098 */   addiu    $sp, $sp, 0x98
