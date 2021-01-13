.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D80_CAFAC0
/* CAFAC0 80240D80 27BDFF68 */  addiu     $sp, $sp, -0x98
/* CAFAC4 80240D84 AFB60060 */  sw        $s6, 0x60($sp)
/* CAFAC8 80240D88 0080B02D */  daddu     $s6, $a0, $zero
/* CAFACC 80240D8C AFBF0064 */  sw        $ra, 0x64($sp)
/* CAFAD0 80240D90 AFB5005C */  sw        $s5, 0x5c($sp)
/* CAFAD4 80240D94 AFB40058 */  sw        $s4, 0x58($sp)
/* CAFAD8 80240D98 AFB30054 */  sw        $s3, 0x54($sp)
/* CAFADC 80240D9C AFB20050 */  sw        $s2, 0x50($sp)
/* CAFAE0 80240DA0 AFB1004C */  sw        $s1, 0x4c($sp)
/* CAFAE4 80240DA4 AFB00048 */  sw        $s0, 0x48($sp)
/* CAFAE8 80240DA8 F7BE0090 */  sdc1      $f30, 0x90($sp)
/* CAFAEC 80240DAC F7BC0088 */  sdc1      $f28, 0x88($sp)
/* CAFAF0 80240DB0 F7BA0080 */  sdc1      $f26, 0x80($sp)
/* CAFAF4 80240DB4 F7B80078 */  sdc1      $f24, 0x78($sp)
/* CAFAF8 80240DB8 F7B60070 */  sdc1      $f22, 0x70($sp)
/* CAFAFC 80240DBC F7B40068 */  sdc1      $f20, 0x68($sp)
/* CAFB00 80240DC0 8ED20148 */  lw        $s2, 0x148($s6)
/* CAFB04 80240DC4 00A0882D */  daddu     $s1, $a1, $zero
/* CAFB08 80240DC8 86440008 */  lh        $a0, 8($s2)
/* CAFB0C 80240DCC 0C00EABB */  jal       get_npc_unsafe
/* CAFB10 80240DD0 00C0A82D */   daddu    $s5, $a2, $zero
/* CAFB14 80240DD4 8E240020 */  lw        $a0, 0x20($s1)
/* CAFB18 80240DD8 0040802D */  daddu     $s0, $v0, $zero
/* CAFB1C 80240DDC 00041FC2 */  srl       $v1, $a0, 0x1f
/* CAFB20 80240DE0 00832021 */  addu      $a0, $a0, $v1
/* CAFB24 80240DE4 00042043 */  sra       $a0, $a0, 1
/* CAFB28 80240DE8 0C00A67F */  jal       rand_int
/* CAFB2C 80240DEC 24840001 */   addiu    $a0, $a0, 1
/* CAFB30 80240DF0 8E230020 */  lw        $v1, 0x20($s1)
/* CAFB34 80240DF4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* CAFB38 80240DF8 000327C2 */  srl       $a0, $v1, 0x1f
/* CAFB3C 80240DFC 00641821 */  addu      $v1, $v1, $a0
/* CAFB40 80240E00 00031843 */  sra       $v1, $v1, 1
/* CAFB44 80240E04 00621821 */  addu      $v1, $v1, $v0
/* CAFB48 80240E08 A603008E */  sh        $v1, 0x8e($s0)
/* CAFB4C 80240E0C 8E4200CC */  lw        $v0, 0xcc($s2)
/* CAFB50 80240E10 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CAFB54 80240E14 8C42000C */  lw        $v0, 0xc($v0)
/* CAFB58 80240E18 AE020028 */  sw        $v0, 0x28($s0)
/* CAFB5C 80240E1C C6200018 */  lwc1      $f0, 0x18($s1)
/* CAFB60 80240E20 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CAFB64 80240E24 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CAFB68 80240E28 E6000018 */  swc1      $f0, 0x18($s0)
/* CAFB6C 80240E2C 8C460028 */  lw        $a2, 0x28($v0)
/* CAFB70 80240E30 8C470030 */  lw        $a3, 0x30($v0)
/* CAFB74 80240E34 0C00A720 */  jal       atan2
/* CAFB78 80240E38 0000982D */   daddu    $s3, $zero, $zero
/* CAFB7C 80240E3C 3C014334 */  lui       $at, 0x4334
/* CAFB80 80240E40 44816000 */  mtc1      $at, $f12
/* CAFB84 80240E44 0C00A6C9 */  jal       clamp_angle
/* CAFB88 80240E48 460C0300 */   add.s    $f12, $f0, $f12
/* CAFB8C 80240E4C 46000506 */  mov.s     $f20, $f0
/* CAFB90 80240E50 C60C000C */  lwc1      $f12, 0xc($s0)
/* CAFB94 80240E54 0C00A70A */  jal       get_clamped_angle_diff
/* CAFB98 80240E58 4600A386 */   mov.s    $f14, $f20
/* CAFB9C 80240E5C 46000086 */  mov.s     $f2, $f0
/* CAFBA0 80240E60 8E22001C */  lw        $v0, 0x1c($s1)
/* CAFBA4 80240E64 46001005 */  abs.s     $f0, $f2
/* CAFBA8 80240E68 44822000 */  mtc1      $v0, $f4
/* CAFBAC 80240E6C 00000000 */  nop
/* CAFBB0 80240E70 46802120 */  cvt.s.w   $f4, $f4
/* CAFBB4 80240E74 4600203C */  c.lt.s    $f4, $f0
/* CAFBB8 80240E78 00000000 */  nop
/* CAFBBC 80240E7C 4500000D */  bc1f      .L80240EB4
/* CAFBC0 80240E80 00000000 */   nop
/* CAFBC4 80240E84 44800000 */  mtc1      $zero, $f0
/* CAFBC8 80240E88 C614000C */  lwc1      $f20, 0xc($s0)
/* CAFBCC 80240E8C 4600103C */  c.lt.s    $f2, $f0
/* CAFBD0 80240E90 00000000 */  nop
/* CAFBD4 80240E94 45000006 */  bc1f      .L80240EB0
/* CAFBD8 80240E98 00021023 */   negu     $v0, $v0
/* CAFBDC 80240E9C 44820000 */  mtc1      $v0, $f0
/* CAFBE0 80240EA0 00000000 */  nop
/* CAFBE4 80240EA4 46800020 */  cvt.s.w   $f0, $f0
/* CAFBE8 80240EA8 080903AD */  j         .L80240EB4
/* CAFBEC 80240EAC 4600A500 */   add.s    $f20, $f20, $f0
.L80240EB0:
/* CAFBF0 80240EB0 4604A500 */  add.s     $f20, $f20, $f4
.L80240EB4:
/* CAFBF4 80240EB4 0C00A6C9 */  jal       clamp_angle
/* CAFBF8 80240EB8 4600A306 */   mov.s    $f12, $f20
/* CAFBFC 80240EBC 3C14800F */  lui       $s4, %hi(gPlayerStatusPtr)
/* CAFC00 80240EC0 26947B30 */  addiu     $s4, $s4, %lo(gPlayerStatusPtr)
/* CAFC04 80240EC4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* CAFC08 80240EC8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CAFC0C 80240ECC 8E820000 */  lw        $v0, ($s4)
/* CAFC10 80240ED0 C602003C */  lwc1      $f2, 0x3c($s0)
/* CAFC14 80240ED4 E600000C */  swc1      $f0, 0xc($s0)
/* CAFC18 80240ED8 46006006 */  mov.s     $f0, $f12
/* CAFC1C 80240EDC 8C460028 */  lw        $a2, 0x28($v0)
/* CAFC20 80240EE0 8C470030 */  lw        $a3, 0x30($v0)
/* CAFC24 80240EE4 46007106 */  mov.s     $f4, $f14
/* CAFC28 80240EE8 E7A00020 */  swc1      $f0, 0x20($sp)
/* CAFC2C 80240EEC E7A20024 */  swc1      $f2, 0x24($sp)
/* CAFC30 80240EF0 0C00A720 */  jal       atan2
/* CAFC34 80240EF4 E7A40028 */   swc1     $f4, 0x28($sp)
/* CAFC38 80240EF8 3C014334 */  lui       $at, 0x4334
/* CAFC3C 80240EFC 44816000 */  mtc1      $at, $f12
/* CAFC40 80240F00 0C00A6C9 */  jal       clamp_angle
/* CAFC44 80240F04 460C0300 */   add.s    $f12, $f0, $f12
/* CAFC48 80240F08 C6020018 */  lwc1      $f2, 0x18($s0)
/* CAFC4C 80240F0C 3C014012 */  lui       $at, 0x4012
/* CAFC50 80240F10 4481E800 */  mtc1      $at, $f29
/* CAFC54 80240F14 4480E000 */  mtc1      $zero, $f28
/* CAFC58 80240F18 460010A1 */  cvt.d.s   $f2, $f2
/* CAFC5C 80240F1C 463C1082 */  mul.d     $f2, $f2, $f28
/* CAFC60 80240F20 00000000 */  nop
/* CAFC64 80240F24 46000506 */  mov.s     $f20, $f0
/* CAFC68 80240F28 27A50020 */  addiu     $a1, $sp, 0x20
/* CAFC6C 80240F2C 27A60024 */  addiu     $a2, $sp, 0x24
/* CAFC70 80240F30 27A70028 */  addiu     $a3, $sp, 0x28
/* CAFC74 80240F34 E7B40014 */  swc1      $f20, 0x14($sp)
/* CAFC78 80240F38 462010A0 */  cvt.s.d   $f2, $f2
/* CAFC7C 80240F3C E7A20010 */  swc1      $f2, 0x10($sp)
/* CAFC80 80240F40 860200A8 */  lh        $v0, 0xa8($s0)
/* CAFC84 80240F44 4480B000 */  mtc1      $zero, $f22
/* CAFC88 80240F48 44820000 */  mtc1      $v0, $f0
/* CAFC8C 80240F4C 00000000 */  nop
/* CAFC90 80240F50 46800020 */  cvt.s.w   $f0, $f0
/* CAFC94 80240F54 E7A00018 */  swc1      $f0, 0x18($sp)
/* CAFC98 80240F58 860200A6 */  lh        $v0, 0xa6($s0)
/* CAFC9C 80240F5C 4600B606 */  mov.s     $f24, $f22
/* CAFCA0 80240F60 44820000 */  mtc1      $v0, $f0
/* CAFCA4 80240F64 00000000 */  nop
/* CAFCA8 80240F68 46800020 */  cvt.s.w   $f0, $f0
/* CAFCAC 80240F6C E7A0001C */  swc1      $f0, 0x1c($sp)
/* CAFCB0 80240F70 8E040080 */  lw        $a0, 0x80($s0)
/* CAFCB4 80240F74 0C03773B */  jal       func_800DDCEC
/* CAFCB8 80240F78 4600C686 */   mov.s    $f26, $f24
/* CAFCBC 80240F7C 104000E1 */  beqz      $v0, .L80241304
/* CAFCC0 80240F80 00000000 */   nop
/* CAFCC4 80240F84 C60C0038 */  lwc1      $f12, 0x38($s0)
/* CAFCC8 80240F88 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CAFCCC 80240F8C 8FA60020 */  lw        $a2, 0x20($sp)
/* CAFCD0 80240F90 0C00A7B5 */  jal       dist2D
/* CAFCD4 80240F94 8FA70028 */   lw       $a3, 0x28($sp)
/* CAFCD8 80240F98 46000586 */  mov.s     $f22, $f0
/* CAFCDC 80240F9C C6020038 */  lwc1      $f2, 0x38($s0)
/* CAFCE0 80240FA0 C604003C */  lwc1      $f4, 0x3c($s0)
/* CAFCE4 80240FA4 3C01420C */  lui       $at, 0x420c
/* CAFCE8 80240FA8 4481F000 */  mtc1      $at, $f30
/* CAFCEC 80240FAC C6000040 */  lwc1      $f0, 0x40($s0)
/* CAFCF0 80240FB0 461EA300 */  add.s     $f12, $f20, $f30
/* CAFCF4 80240FB4 E7A2002C */  swc1      $f2, 0x2c($sp)
/* CAFCF8 80240FB8 E7A40030 */  swc1      $f4, 0x30($sp)
/* CAFCFC 80240FBC 0C00A6C9 */  jal       clamp_angle
/* CAFD00 80240FC0 E7A00034 */   swc1     $f0, 0x34($sp)
/* CAFD04 80240FC4 C6020018 */  lwc1      $f2, 0x18($s0)
/* CAFD08 80240FC8 460010A1 */  cvt.d.s   $f2, $f2
/* CAFD0C 80240FCC 463C1082 */  mul.d     $f2, $f2, $f28
/* CAFD10 80240FD0 00000000 */  nop
/* CAFD14 80240FD4 E7A00014 */  swc1      $f0, 0x14($sp)
/* CAFD18 80240FD8 462010A0 */  cvt.s.d   $f2, $f2
/* CAFD1C 80240FDC E7A20010 */  swc1      $f2, 0x10($sp)
/* CAFD20 80240FE0 860200A8 */  lh        $v0, 0xa8($s0)
/* CAFD24 80240FE4 27A5002C */  addiu     $a1, $sp, 0x2c
/* CAFD28 80240FE8 44820000 */  mtc1      $v0, $f0
/* CAFD2C 80240FEC 00000000 */  nop
/* CAFD30 80240FF0 46800020 */  cvt.s.w   $f0, $f0
/* CAFD34 80240FF4 E7A00018 */  swc1      $f0, 0x18($sp)
/* CAFD38 80240FF8 860200A6 */  lh        $v0, 0xa6($s0)
/* CAFD3C 80240FFC 27A60030 */  addiu     $a2, $sp, 0x30
/* CAFD40 80241000 44820000 */  mtc1      $v0, $f0
/* CAFD44 80241004 00000000 */  nop
/* CAFD48 80241008 46800020 */  cvt.s.w   $f0, $f0
/* CAFD4C 8024100C E7A0001C */  swc1      $f0, 0x1c($sp)
/* CAFD50 80241010 8E040080 */  lw        $a0, 0x80($s0)
/* CAFD54 80241014 0C03773B */  jal       func_800DDCEC
/* CAFD58 80241018 27A70034 */   addiu    $a3, $sp, 0x34
/* CAFD5C 8024101C 10400007 */  beqz      $v0, .L8024103C
/* CAFD60 80241020 00000000 */   nop
/* CAFD64 80241024 C60C0038 */  lwc1      $f12, 0x38($s0)
/* CAFD68 80241028 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CAFD6C 8024102C 8FA6002C */  lw        $a2, 0x2c($sp)
/* CAFD70 80241030 0C00A7B5 */  jal       dist2D
/* CAFD74 80241034 8FA70034 */   lw       $a3, 0x34($sp)
/* CAFD78 80241038 46000606 */  mov.s     $f24, $f0
.L8024103C:
/* CAFD7C 8024103C C6000038 */  lwc1      $f0, 0x38($s0)
/* CAFD80 80241040 C602003C */  lwc1      $f2, 0x3c($s0)
/* CAFD84 80241044 C6040040 */  lwc1      $f4, 0x40($s0)
/* CAFD88 80241048 461EA301 */  sub.s     $f12, $f20, $f30
/* CAFD8C 8024104C E7A00038 */  swc1      $f0, 0x38($sp)
/* CAFD90 80241050 E7A2003C */  swc1      $f2, 0x3c($sp)
/* CAFD94 80241054 0C00A6C9 */  jal       clamp_angle
/* CAFD98 80241058 E7A40040 */   swc1     $f4, 0x40($sp)
/* CAFD9C 8024105C C6020018 */  lwc1      $f2, 0x18($s0)
/* CAFDA0 80241060 460010A1 */  cvt.d.s   $f2, $f2
/* CAFDA4 80241064 463C1082 */  mul.d     $f2, $f2, $f28
/* CAFDA8 80241068 00000000 */  nop
/* CAFDAC 8024106C E7A00014 */  swc1      $f0, 0x14($sp)
/* CAFDB0 80241070 462010A0 */  cvt.s.d   $f2, $f2
/* CAFDB4 80241074 E7A20010 */  swc1      $f2, 0x10($sp)
/* CAFDB8 80241078 860200A8 */  lh        $v0, 0xa8($s0)
/* CAFDBC 8024107C 27A50038 */  addiu     $a1, $sp, 0x38
/* CAFDC0 80241080 44820000 */  mtc1      $v0, $f0
/* CAFDC4 80241084 00000000 */  nop
/* CAFDC8 80241088 46800020 */  cvt.s.w   $f0, $f0
/* CAFDCC 8024108C E7A00018 */  swc1      $f0, 0x18($sp)
/* CAFDD0 80241090 860200A6 */  lh        $v0, 0xa6($s0)
/* CAFDD4 80241094 27A6003C */  addiu     $a2, $sp, 0x3c
/* CAFDD8 80241098 44820000 */  mtc1      $v0, $f0
/* CAFDDC 8024109C 00000000 */  nop
/* CAFDE0 802410A0 46800020 */  cvt.s.w   $f0, $f0
/* CAFDE4 802410A4 E7A0001C */  swc1      $f0, 0x1c($sp)
/* CAFDE8 802410A8 8E040080 */  lw        $a0, 0x80($s0)
/* CAFDEC 802410AC 0C03773B */  jal       func_800DDCEC
/* CAFDF0 802410B0 27A70040 */   addiu    $a3, $sp, 0x40
/* CAFDF4 802410B4 10400007 */  beqz      $v0, .L802410D4
/* CAFDF8 802410B8 00000000 */   nop
/* CAFDFC 802410BC C60C0038 */  lwc1      $f12, 0x38($s0)
/* CAFE00 802410C0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CAFE04 802410C4 8FA60038 */  lw        $a2, 0x38($sp)
/* CAFE08 802410C8 0C00A7B5 */  jal       dist2D
/* CAFE0C 802410CC 8FA70040 */   lw       $a3, 0x40($sp)
/* CAFE10 802410D0 46000686 */  mov.s     $f26, $f0
.L802410D4:
/* CAFE14 802410D4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* CAFE18 802410D8 8E820000 */  lw        $v0, ($s4)
/* CAFE1C 802410DC C60E0040 */  lwc1      $f14, 0x40($s0)
/* CAFE20 802410E0 8C460028 */  lw        $a2, 0x28($v0)
/* CAFE24 802410E4 0C00A7B5 */  jal       dist2D
/* CAFE28 802410E8 8C470030 */   lw       $a3, 0x30($v0)
/* CAFE2C 802410EC C6000018 */  lwc1      $f0, 0x18($s0)
/* CAFE30 802410F0 3C013FF8 */  lui       $at, 0x3ff8
/* CAFE34 802410F4 44811800 */  mtc1      $at, $f3
/* CAFE38 802410F8 44801000 */  mtc1      $zero, $f2
/* CAFE3C 802410FC 46000021 */  cvt.d.s   $f0, $f0
/* CAFE40 80241100 46220082 */  mul.d     $f2, $f0, $f2
/* CAFE44 80241104 00000000 */  nop
/* CAFE48 80241108 4600B021 */  cvt.d.s   $f0, $f22
/* CAFE4C 8024110C 4622003C */  c.lt.d    $f0, $f2
/* CAFE50 80241110 00000000 */  nop
/* CAFE54 80241114 45000012 */  bc1f      .L80241160
/* CAFE58 80241118 00000000 */   nop
/* CAFE5C 8024111C 4600C021 */  cvt.d.s   $f0, $f24
/* CAFE60 80241120 4622003C */  c.lt.d    $f0, $f2
/* CAFE64 80241124 00000000 */  nop
/* CAFE68 80241128 4500000D */  bc1f      .L80241160
/* CAFE6C 8024112C 00000000 */   nop
/* CAFE70 80241130 4600D021 */  cvt.d.s   $f0, $f26
/* CAFE74 80241134 4622003C */  c.lt.d    $f0, $f2
/* CAFE78 80241138 00000000 */  nop
/* CAFE7C 8024113C 45000008 */  bc1f      .L80241160
/* CAFE80 80241140 02A0202D */   daddu    $a0, $s5, $zero
/* CAFE84 80241144 AFA00010 */  sw        $zero, 0x10($sp)
/* CAFE88 80241148 8E26000C */  lw        $a2, 0xc($s1)
/* CAFE8C 8024114C 8E270010 */  lw        $a3, 0x10($s1)
/* CAFE90 80241150 0C01242D */  jal       func_800490B4
/* CAFE94 80241154 0240282D */   daddu    $a1, $s2, $zero
/* CAFE98 80241158 54400001 */  bnel      $v0, $zero, .L80241160
/* CAFE9C 8024115C 24130001 */   addiu    $s3, $zero, 1
.L80241160:
/* CAFEA0 80241160 1660006A */  bnez      $s3, .L8024130C
/* CAFEA4 80241164 2402000A */   addiu    $v0, $zero, 0xa
/* CAFEA8 80241168 4616C03C */  c.lt.s    $f24, $f22
/* CAFEAC 8024116C 00000000 */  nop
/* CAFEB0 80241170 4500000C */  bc1f      .L802411A4
/* CAFEB4 80241174 00000000 */   nop
/* CAFEB8 80241178 4618D03C */  c.lt.s    $f26, $f24
/* CAFEBC 8024117C 00000000 */  nop
/* CAFEC0 80241180 45000006 */  bc1f      .L8024119C
/* CAFEC4 80241184 00000000 */   nop
/* CAFEC8 80241188 C60C0038 */  lwc1      $f12, 0x38($s0)
/* CAFECC 8024118C C60E0040 */  lwc1      $f14, 0x40($s0)
/* CAFED0 80241190 8FA60020 */  lw        $a2, 0x20($sp)
/* CAFED4 80241194 080904A2 */  j         .L80241288
/* CAFED8 80241198 8FA70028 */   lw       $a3, 0x28($sp)
.L8024119C:
/* CAFEDC 8024119C 4616C03C */  c.lt.s    $f24, $f22
/* CAFEE0 802411A0 00000000 */  nop
.L802411A4:
/* CAFEE4 802411A4 4500000A */  bc1f      .L802411D0
/* CAFEE8 802411A8 00000000 */   nop
/* CAFEEC 802411AC 461AC03C */  c.lt.s    $f24, $f26
/* CAFEF0 802411B0 00000000 */  nop
/* CAFEF4 802411B4 45000006 */  bc1f      .L802411D0
/* CAFEF8 802411B8 00000000 */   nop
/* CAFEFC 802411BC C60C0038 */  lwc1      $f12, 0x38($s0)
/* CAFF00 802411C0 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CAFF04 802411C4 8FA60020 */  lw        $a2, 0x20($sp)
/* CAFF08 802411C8 080904A2 */  j         .L80241288
/* CAFF0C 802411CC 8FA70028 */   lw       $a3, 0x28($sp)
.L802411D0:
/* CAFF10 802411D0 4618B03C */  c.lt.s    $f22, $f24
/* CAFF14 802411D4 00000000 */  nop
/* CAFF18 802411D8 4500000A */  bc1f      .L80241204
/* CAFF1C 802411DC 00000000 */   nop
/* CAFF20 802411E0 4616D03C */  c.lt.s    $f26, $f22
/* CAFF24 802411E4 00000000 */  nop
/* CAFF28 802411E8 45000006 */  bc1f      .L80241204
/* CAFF2C 802411EC 00000000 */   nop
/* CAFF30 802411F0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* CAFF34 802411F4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CAFF38 802411F8 8FA6002C */  lw        $a2, 0x2c($sp)
/* CAFF3C 802411FC 080904A2 */  j         .L80241288
/* CAFF40 80241200 8FA70034 */   lw       $a3, 0x34($sp)
.L80241204:
/* CAFF44 80241204 4618D03C */  c.lt.s    $f26, $f24
/* CAFF48 80241208 00000000 */  nop
/* CAFF4C 8024120C 4500000A */  bc1f      .L80241238
/* CAFF50 80241210 00000000 */   nop
/* CAFF54 80241214 461AB03C */  c.lt.s    $f22, $f26
/* CAFF58 80241218 00000000 */  nop
/* CAFF5C 8024121C 45000008 */  bc1f      .L80241240
/* CAFF60 80241220 00000000 */   nop
/* CAFF64 80241224 C60C0038 */  lwc1      $f12, 0x38($s0)
/* CAFF68 80241228 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CAFF6C 8024122C 8FA6002C */  lw        $a2, 0x2c($sp)
/* CAFF70 80241230 080904A2 */  j         .L80241288
/* CAFF74 80241234 8FA70034 */   lw       $a3, 0x34($sp)
.L80241238:
/* CAFF78 80241238 461AB03C */  c.lt.s    $f22, $f26
/* CAFF7C 8024123C 00000000 */  nop
.L80241240:
/* CAFF80 80241240 45000005 */  bc1f      .L80241258
/* CAFF84 80241244 00000000 */   nop
/* CAFF88 80241248 4616C03C */  c.lt.s    $f24, $f22
/* CAFF8C 8024124C 00000000 */  nop
/* CAFF90 80241250 45010009 */  bc1t      .L80241278
/* CAFF94 80241254 00000000 */   nop
.L80241258:
/* CAFF98 80241258 461AC03C */  c.lt.s    $f24, $f26
/* CAFF9C 8024125C 00000000 */  nop
/* CAFFA0 80241260 4500000C */  bc1f      .L80241294
/* CAFFA4 80241264 00000000 */   nop
/* CAFFA8 80241268 4618B03C */  c.lt.s    $f22, $f24
/* CAFFAC 8024126C 00000000 */  nop
/* CAFFB0 80241270 45000008 */  bc1f      .L80241294
/* CAFFB4 80241274 00000000 */   nop
.L80241278:
/* CAFFB8 80241278 C60C0038 */  lwc1      $f12, 0x38($s0)
/* CAFFBC 8024127C C60E0040 */  lwc1      $f14, 0x40($s0)
/* CAFFC0 80241280 8FA60038 */  lw        $a2, 0x38($sp)
/* CAFFC4 80241284 8FA70040 */  lw        $a3, 0x40($sp)
.L80241288:
/* CAFFC8 80241288 0C00A720 */  jal       atan2
/* CAFFCC 8024128C 00000000 */   nop
/* CAFFD0 80241290 46000506 */  mov.s     $f20, $f0
.L80241294:
/* CAFFD4 80241294 C60C000C */  lwc1      $f12, 0xc($s0)
/* CAFFD8 80241298 0C00A70A */  jal       get_clamped_angle_diff
/* CAFFDC 8024129C 4600A386 */   mov.s    $f14, $f20
/* CAFFE0 802412A0 46000086 */  mov.s     $f2, $f0
/* CAFFE4 802412A4 8E22001C */  lw        $v0, 0x1c($s1)
/* CAFFE8 802412A8 46001005 */  abs.s     $f0, $f2
/* CAFFEC 802412AC 44822000 */  mtc1      $v0, $f4
/* CAFFF0 802412B0 00000000 */  nop
/* CAFFF4 802412B4 46802120 */  cvt.s.w   $f4, $f4
/* CAFFF8 802412B8 4600203C */  c.lt.s    $f4, $f0
/* CAFFFC 802412BC 00000000 */  nop
/* CB0000 802412C0 4500000D */  bc1f      .L802412F8
/* CB0004 802412C4 00000000 */   nop
/* CB0008 802412C8 44800000 */  mtc1      $zero, $f0
/* CB000C 802412CC C614000C */  lwc1      $f20, 0xc($s0)
/* CB0010 802412D0 4600103C */  c.lt.s    $f2, $f0
/* CB0014 802412D4 00000000 */  nop
/* CB0018 802412D8 45000006 */  bc1f      .L802412F4
/* CB001C 802412DC 00021023 */   negu     $v0, $v0
/* CB0020 802412E0 44820000 */  mtc1      $v0, $f0
/* CB0024 802412E4 00000000 */  nop
/* CB0028 802412E8 46800020 */  cvt.s.w   $f0, $f0
/* CB002C 802412EC 080904BE */  j         .L802412F8
/* CB0030 802412F0 4600A500 */   add.s    $f20, $f20, $f0
.L802412F4:
/* CB0034 802412F4 4604A500 */  add.s     $f20, $f20, $f4
.L802412F8:
/* CB0038 802412F8 0C00A6C9 */  jal       clamp_angle
/* CB003C 802412FC 4600A306 */   mov.s    $f12, $f20
/* CB0040 80241300 E600000C */  swc1      $f0, 0xc($s0)
.L80241304:
/* CB0044 80241304 12600005 */  beqz      $s3, .L8024131C
/* CB0048 80241308 2402000A */   addiu    $v0, $zero, 0xa
.L8024130C:
/* CB004C 8024130C A602008E */  sh        $v0, 0x8e($s0)
/* CB0050 80241310 8E4200CC */  lw        $v0, 0xcc($s2)
/* CB0054 80241314 8C420020 */  lw        $v0, 0x20($v0)
/* CB0058 80241318 AE020028 */  sw        $v0, 0x28($s0)
.L8024131C:
/* CB005C 8024131C 2402000D */  addiu     $v0, $zero, 0xd
/* CB0060 80241320 AEC20070 */  sw        $v0, 0x70($s6)
/* CB0064 80241324 8FBF0064 */  lw        $ra, 0x64($sp)
/* CB0068 80241328 8FB60060 */  lw        $s6, 0x60($sp)
/* CB006C 8024132C 8FB5005C */  lw        $s5, 0x5c($sp)
/* CB0070 80241330 8FB40058 */  lw        $s4, 0x58($sp)
/* CB0074 80241334 8FB30054 */  lw        $s3, 0x54($sp)
/* CB0078 80241338 8FB20050 */  lw        $s2, 0x50($sp)
/* CB007C 8024133C 8FB1004C */  lw        $s1, 0x4c($sp)
/* CB0080 80241340 8FB00048 */  lw        $s0, 0x48($sp)
/* CB0084 80241344 D7BE0090 */  ldc1      $f30, 0x90($sp)
/* CB0088 80241348 D7BC0088 */  ldc1      $f28, 0x88($sp)
/* CB008C 8024134C D7BA0080 */  ldc1      $f26, 0x80($sp)
/* CB0090 80241350 D7B80078 */  ldc1      $f24, 0x78($sp)
/* CB0094 80241354 D7B60070 */  ldc1      $f22, 0x70($sp)
/* CB0098 80241358 D7B40068 */  ldc1      $f20, 0x68($sp)
/* CB009C 8024135C 03E00008 */  jr        $ra
/* CB00A0 80241360 27BD0098 */   addiu    $sp, $sp, 0x98
