.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel trd_04_UnkFunc6
/* 9AB060 80242C70 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 9AB064 80242C74 AFB20030 */  sw        $s2, 0x30($sp)
/* 9AB068 80242C78 0080902D */  daddu     $s2, $a0, $zero
/* 9AB06C 80242C7C AFBF0038 */  sw        $ra, 0x38($sp)
/* 9AB070 80242C80 AFB30034 */  sw        $s3, 0x34($sp)
/* 9AB074 80242C84 AFB1002C */  sw        $s1, 0x2c($sp)
/* 9AB078 80242C88 AFB00028 */  sw        $s0, 0x28($sp)
/* 9AB07C 80242C8C F7B60048 */  sdc1      $f22, 0x48($sp)
/* 9AB080 80242C90 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 9AB084 80242C94 8E510148 */  lw        $s1, 0x148($s2)
/* 9AB088 80242C98 86240008 */  lh        $a0, 8($s1)
/* 9AB08C 80242C9C 0C00EABB */  jal       get_npc_unsafe
/* 9AB090 80242CA0 00A0982D */   daddu    $s3, $a1, $zero
/* 9AB094 80242CA4 0040802D */  daddu     $s0, $v0, $zero
/* 9AB098 80242CA8 0200202D */  daddu     $a0, $s0, $zero
/* 9AB09C 80242CAC C6220088 */  lwc1      $f2, 0x88($s1)
/* 9AB0A0 80242CB0 468010A0 */  cvt.s.w   $f2, $f2
/* 9AB0A4 80242CB4 460010A1 */  cvt.d.s   $f2, $f2
/* 9AB0A8 80242CB8 C604001C */  lwc1      $f4, 0x1c($s0)
/* 9AB0AC 80242CBC C6000014 */  lwc1      $f0, 0x14($s0)
/* 9AB0B0 80242CC0 8E050018 */  lw        $a1, 0x18($s0)
/* 9AB0B4 80242CC4 46002100 */  add.s     $f4, $f4, $f0
/* 9AB0B8 80242CC8 8E06000C */  lw        $a2, 0xc($s0)
/* 9AB0BC 80242CCC C6200078 */  lwc1      $f0, 0x78($s1)
/* 9AB0C0 80242CD0 46800020 */  cvt.s.w   $f0, $f0
/* 9AB0C4 80242CD4 E604001C */  swc1      $f4, 0x1c($s0)
/* 9AB0C8 80242CD8 3C014059 */  lui       $at, 0x4059
/* 9AB0CC 80242CDC 44812800 */  mtc1      $at, $f5
/* 9AB0D0 80242CE0 44802000 */  mtc1      $zero, $f4
/* 9AB0D4 80242CE4 46000021 */  cvt.d.s   $f0, $f0
/* 9AB0D8 80242CE8 46240003 */  div.d     $f0, $f0, $f4
/* 9AB0DC 80242CEC 46200520 */  cvt.s.d   $f20, $f0
/* 9AB0E0 80242CF0 46241083 */  div.d     $f2, $f2, $f4
/* 9AB0E4 80242CF4 0C00EA95 */  jal       npc_move_heading
/* 9AB0E8 80242CF8 462015A0 */   cvt.s.d  $f22, $f2
/* 9AB0EC 80242CFC C604001C */  lwc1      $f4, 0x1c($s0)
/* 9AB0F0 80242D00 44801000 */  mtc1      $zero, $f2
/* 9AB0F4 80242D04 44801800 */  mtc1      $zero, $f3
/* 9AB0F8 80242D08 46002021 */  cvt.d.s   $f0, $f4
/* 9AB0FC 80242D0C 4620103E */  c.le.d    $f2, $f0
/* 9AB100 80242D10 00000000 */  nop
/* 9AB104 80242D14 45000030 */  bc1f      .L80242DD8
/* 9AB108 80242D18 00000000 */   nop
/* 9AB10C 80242D1C C600003C */  lwc1      $f0, 0x3c($s0)
/* 9AB110 80242D20 46040000 */  add.s     $f0, $f0, $f4
/* 9AB114 80242D24 E600003C */  swc1      $f0, 0x3c($s0)
/* 9AB118 80242D28 8E2200CC */  lw        $v0, 0xcc($s1)
/* 9AB11C 80242D2C 8C420024 */  lw        $v0, 0x24($v0)
/* 9AB120 80242D30 AE020028 */  sw        $v0, 0x28($s0)
/* 9AB124 80242D34 A2200007 */  sb        $zero, 7($s1)
/* 9AB128 80242D38 8E020000 */  lw        $v0, ($s0)
/* 9AB12C 80242D3C 30420008 */  andi      $v0, $v0, 8
/* 9AB130 80242D40 14400011 */  bnez      $v0, .L80242D88
/* 9AB134 80242D44 0000102D */   daddu    $v0, $zero, $zero
/* 9AB138 80242D48 27A50018 */  addiu     $a1, $sp, 0x18
/* 9AB13C 80242D4C 27A6001C */  addiu     $a2, $sp, 0x1c
/* 9AB140 80242D50 C6000038 */  lwc1      $f0, 0x38($s0)
/* 9AB144 80242D54 C602003C */  lwc1      $f2, 0x3c($s0)
/* 9AB148 80242D58 C6040040 */  lwc1      $f4, 0x40($s0)
/* 9AB14C 80242D5C 3C01447A */  lui       $at, 0x447a
/* 9AB150 80242D60 44813000 */  mtc1      $at, $f6
/* 9AB154 80242D64 27A20024 */  addiu     $v0, $sp, 0x24
/* 9AB158 80242D68 E7A00018 */  swc1      $f0, 0x18($sp)
/* 9AB15C 80242D6C E7A2001C */  swc1      $f2, 0x1c($sp)
/* 9AB160 80242D70 E7A40020 */  swc1      $f4, 0x20($sp)
/* 9AB164 80242D74 E7A60024 */  swc1      $f6, 0x24($sp)
/* 9AB168 80242D78 AFA20010 */  sw        $v0, 0x10($sp)
/* 9AB16C 80242D7C 8E040080 */  lw        $a0, 0x80($s0)
/* 9AB170 80242D80 0C0372DF */  jal       func_800DCB7C
/* 9AB174 80242D84 27A70020 */   addiu    $a3, $sp, 0x20
.L80242D88:
/* 9AB178 80242D88 1040000B */  beqz      $v0, .L80242DB8
/* 9AB17C 80242D8C 00000000 */   nop
/* 9AB180 80242D90 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 9AB184 80242D94 46140080 */  add.s     $f2, $f0, $f20
/* 9AB188 80242D98 C600003C */  lwc1      $f0, 0x3c($s0)
/* 9AB18C 80242D9C 4600103E */  c.le.s    $f2, $f0
/* 9AB190 80242DA0 00000000 */  nop
/* 9AB194 80242DA4 4500008D */  bc1f      .L80242FDC
/* 9AB198 80242DA8 00000000 */   nop
/* 9AB19C 80242DAC E602003C */  swc1      $f2, 0x3c($s0)
/* 9AB1A0 80242DB0 08090BF7 */  j         .L80242FDC
/* 9AB1A4 80242DB4 AE400070 */   sw       $zero, 0x70($s2)
.L80242DB8:
/* 9AB1A8 80242DB8 C602003C */  lwc1      $f2, 0x3c($s0)
/* 9AB1AC 80242DBC C6000064 */  lwc1      $f0, 0x64($s0)
/* 9AB1B0 80242DC0 4602003E */  c.le.s    $f0, $f2
/* 9AB1B4 80242DC4 00000000 */  nop
/* 9AB1B8 80242DC8 45030084 */  bc1tl     .L80242FDC
/* 9AB1BC 80242DCC AE400070 */   sw       $zero, 0x70($s2)
/* 9AB1C0 80242DD0 08090BF7 */  j         .L80242FDC
/* 9AB1C4 80242DD4 00000000 */   nop
.L80242DD8:
/* 9AB1C8 80242DD8 4622003C */  c.lt.d    $f0, $f2
/* 9AB1CC 80242DDC 00000000 */  nop
/* 9AB1D0 80242DE0 4500007E */  bc1f      .L80242FDC
/* 9AB1D4 80242DE4 00000000 */   nop
/* 9AB1D8 80242DE8 9602008E */  lhu       $v0, 0x8e($s0)
/* 9AB1DC 80242DEC 24420001 */  addiu     $v0, $v0, 1
/* 9AB1E0 80242DF0 A602008E */  sh        $v0, 0x8e($s0)
/* 9AB1E4 80242DF4 00021400 */  sll       $v0, $v0, 0x10
/* 9AB1E8 80242DF8 8E630020 */  lw        $v1, 0x20($s3)
/* 9AB1EC 80242DFC 00021403 */  sra       $v0, $v0, 0x10
/* 9AB1F0 80242E00 0043102A */  slt       $v0, $v0, $v1
/* 9AB1F4 80242E04 14400026 */  bnez      $v0, .L80242EA0
/* 9AB1F8 80242E08 00000000 */   nop
/* 9AB1FC 80242E0C C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9AB200 80242E10 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9AB204 80242E14 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 9AB208 80242E18 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 9AB20C 80242E1C A600008E */  sh        $zero, 0x8e($s0)
/* 9AB210 80242E20 8C460028 */  lw        $a2, 0x28($v0)
/* 9AB214 80242E24 0C00A720 */  jal       atan2
/* 9AB218 80242E28 8C470030 */   lw       $a3, 0x30($v0)
/* 9AB21C 80242E2C 46000506 */  mov.s     $f20, $f0
/* 9AB220 80242E30 C60C000C */  lwc1      $f12, 0xc($s0)
/* 9AB224 80242E34 0C00A70A */  jal       get_clamped_angle_diff
/* 9AB228 80242E38 4600A386 */   mov.s    $f14, $f20
/* 9AB22C 80242E3C 46000086 */  mov.s     $f2, $f0
/* 9AB230 80242E40 8E62001C */  lw        $v0, 0x1c($s3)
/* 9AB234 80242E44 46001005 */  abs.s     $f0, $f2
/* 9AB238 80242E48 44822000 */  mtc1      $v0, $f4
/* 9AB23C 80242E4C 00000000 */  nop
/* 9AB240 80242E50 46802120 */  cvt.s.w   $f4, $f4
/* 9AB244 80242E54 4600203C */  c.lt.s    $f4, $f0
/* 9AB248 80242E58 00000000 */  nop
/* 9AB24C 80242E5C 4500000D */  bc1f      .L80242E94
/* 9AB250 80242E60 00000000 */   nop
/* 9AB254 80242E64 44800000 */  mtc1      $zero, $f0
/* 9AB258 80242E68 C614000C */  lwc1      $f20, 0xc($s0)
/* 9AB25C 80242E6C 4600103C */  c.lt.s    $f2, $f0
/* 9AB260 80242E70 00000000 */  nop
/* 9AB264 80242E74 45000006 */  bc1f      .L80242E90
/* 9AB268 80242E78 00021023 */   negu     $v0, $v0
/* 9AB26C 80242E7C 44820000 */  mtc1      $v0, $f0
/* 9AB270 80242E80 00000000 */  nop
/* 9AB274 80242E84 46800020 */  cvt.s.w   $f0, $f0
/* 9AB278 80242E88 08090BA5 */  j         .L80242E94
/* 9AB27C 80242E8C 4600A500 */   add.s    $f20, $f20, $f0
.L80242E90:
/* 9AB280 80242E90 4604A500 */  add.s     $f20, $f20, $f4
.L80242E94:
/* 9AB284 80242E94 0C00A6C9 */  jal       clamp_angle
/* 9AB288 80242E98 4600A306 */   mov.s    $f12, $f20
/* 9AB28C 80242E9C E600000C */  swc1      $f0, 0xc($s0)
.L80242EA0:
/* 9AB290 80242EA0 8E020000 */  lw        $v0, ($s0)
/* 9AB294 80242EA4 30420008 */  andi      $v0, $v0, 8
/* 9AB298 80242EA8 1040000A */  beqz      $v0, .L80242ED4
/* 9AB29C 80242EAC 27A50018 */   addiu    $a1, $sp, 0x18
/* 9AB2A0 80242EB0 C602003C */  lwc1      $f2, 0x3c($s0)
/* 9AB2A4 80242EB4 C600001C */  lwc1      $f0, 0x1c($s0)
/* 9AB2A8 80242EB8 46001080 */  add.s     $f2, $f2, $f0
/* 9AB2AC 80242EBC 4616103C */  c.lt.s    $f2, $f22
/* 9AB2B0 80242EC0 00000000 */  nop
/* 9AB2B4 80242EC4 45020045 */  bc1fl     .L80242FDC
/* 9AB2B8 80242EC8 E602003C */   swc1     $f2, 0x3c($s0)
/* 9AB2BC 80242ECC 08090BF6 */  j         .L80242FD8
/* 9AB2C0 80242ED0 E616003C */   swc1     $f22, 0x3c($s0)
.L80242ED4:
/* 9AB2C4 80242ED4 C6000038 */  lwc1      $f0, 0x38($s0)
/* 9AB2C8 80242ED8 27A6001C */  addiu     $a2, $sp, 0x1c
/* 9AB2CC 80242EDC E7A00018 */  swc1      $f0, 0x18($sp)
/* 9AB2D0 80242EE0 860200A8 */  lh        $v0, 0xa8($s0)
/* 9AB2D4 80242EE4 C600001C */  lwc1      $f0, 0x1c($s0)
/* 9AB2D8 80242EE8 C604003C */  lwc1      $f4, 0x3c($s0)
/* 9AB2DC 80242EEC 44821000 */  mtc1      $v0, $f2
/* 9AB2E0 80242EF0 00000000 */  nop
/* 9AB2E4 80242EF4 468010A0 */  cvt.s.w   $f2, $f2
/* 9AB2E8 80242EF8 46000005 */  abs.s     $f0, $f0
/* 9AB2EC 80242EFC 46020000 */  add.s     $f0, $f0, $f2
/* 9AB2F0 80242F00 C6060040 */  lwc1      $f6, 0x40($s0)
/* 9AB2F4 80242F04 27A20024 */  addiu     $v0, $sp, 0x24
/* 9AB2F8 80242F08 46022100 */  add.s     $f4, $f4, $f2
/* 9AB2FC 80242F0C 3C014024 */  lui       $at, 0x4024
/* 9AB300 80242F10 44811800 */  mtc1      $at, $f3
/* 9AB304 80242F14 44801000 */  mtc1      $zero, $f2
/* 9AB308 80242F18 46000021 */  cvt.d.s   $f0, $f0
/* 9AB30C 80242F1C 46220000 */  add.d     $f0, $f0, $f2
/* 9AB310 80242F20 E7A60020 */  swc1      $f6, 0x20($sp)
/* 9AB314 80242F24 E7A4001C */  swc1      $f4, 0x1c($sp)
/* 9AB318 80242F28 46200020 */  cvt.s.d   $f0, $f0
/* 9AB31C 80242F2C E7A00024 */  swc1      $f0, 0x24($sp)
/* 9AB320 80242F30 AFA20010 */  sw        $v0, 0x10($sp)
/* 9AB324 80242F34 8E040080 */  lw        $a0, 0x80($s0)
/* 9AB328 80242F38 0C0372DF */  jal       func_800DCB7C
/* 9AB32C 80242F3C 27A70020 */   addiu    $a3, $sp, 0x20
/* 9AB330 80242F40 10400015 */  beqz      $v0, .L80242F98
/* 9AB334 80242F44 00000000 */   nop
/* 9AB338 80242F48 860200A8 */  lh        $v0, 0xa8($s0)
/* 9AB33C 80242F4C C604001C */  lwc1      $f4, 0x1c($s0)
/* 9AB340 80242F50 44820000 */  mtc1      $v0, $f0
/* 9AB344 80242F54 00000000 */  nop
/* 9AB348 80242F58 46800020 */  cvt.s.w   $f0, $f0
/* 9AB34C 80242F5C 46002085 */  abs.s     $f2, $f4
/* 9AB350 80242F60 46020000 */  add.s     $f0, $f0, $f2
/* 9AB354 80242F64 C7A20024 */  lwc1      $f2, 0x24($sp)
/* 9AB358 80242F68 4600103E */  c.le.s    $f2, $f0
/* 9AB35C 80242F6C 00000000 */  nop
/* 9AB360 80242F70 45000005 */  bc1f      .L80242F88
/* 9AB364 80242F74 00000000 */   nop
/* 9AB368 80242F78 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 9AB36C 80242F7C AE00001C */  sw        $zero, 0x1c($s0)
/* 9AB370 80242F80 08090BF7 */  j         .L80242FDC
/* 9AB374 80242F84 E600003C */   swc1     $f0, 0x3c($s0)
.L80242F88:
/* 9AB378 80242F88 C600003C */  lwc1      $f0, 0x3c($s0)
/* 9AB37C 80242F8C 46040000 */  add.s     $f0, $f0, $f4
/* 9AB380 80242F90 08090BF7 */  j         .L80242FDC
/* 9AB384 80242F94 E600003C */   swc1     $f0, 0x3c($s0)
.L80242F98:
/* 9AB388 80242F98 C606003C */  lwc1      $f6, 0x3c($s0)
/* 9AB38C 80242F9C 860200A8 */  lh        $v0, 0xa8($s0)
/* 9AB390 80242FA0 46163081 */  sub.s     $f2, $f6, $f22
/* 9AB394 80242FA4 44820000 */  mtc1      $v0, $f0
/* 9AB398 80242FA8 00000000 */  nop
/* 9AB39C 80242FAC 46800020 */  cvt.s.w   $f0, $f0
/* 9AB3A0 80242FB0 46001080 */  add.s     $f2, $f2, $f0
/* 9AB3A4 80242FB4 C604001C */  lwc1      $f4, 0x1c($s0)
/* 9AB3A8 80242FB8 46002005 */  abs.s     $f0, $f4
/* 9AB3AC 80242FBC 4602003C */  c.lt.s    $f0, $f2
/* 9AB3B0 80242FC0 00000000 */  nop
/* 9AB3B4 80242FC4 45020005 */  bc1fl     .L80242FDC
/* 9AB3B8 80242FC8 AE00001C */   sw       $zero, 0x1c($s0)
/* 9AB3BC 80242FCC 46043000 */  add.s     $f0, $f6, $f4
/* 9AB3C0 80242FD0 08090BF7 */  j         .L80242FDC
/* 9AB3C4 80242FD4 E600003C */   swc1     $f0, 0x3c($s0)
.L80242FD8:
/* 9AB3C8 80242FD8 AE00001C */  sw        $zero, 0x1c($s0)
.L80242FDC:
/* 9AB3CC 80242FDC 8FBF0038 */  lw        $ra, 0x38($sp)
/* 9AB3D0 80242FE0 8FB30034 */  lw        $s3, 0x34($sp)
/* 9AB3D4 80242FE4 8FB20030 */  lw        $s2, 0x30($sp)
/* 9AB3D8 80242FE8 8FB1002C */  lw        $s1, 0x2c($sp)
/* 9AB3DC 80242FEC 8FB00028 */  lw        $s0, 0x28($sp)
/* 9AB3E0 80242FF0 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 9AB3E4 80242FF4 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 9AB3E8 80242FF8 03E00008 */  jr        $ra
/* 9AB3EC 80242FFC 27BD0050 */   addiu    $sp, $sp, 0x50
