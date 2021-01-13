.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E0C_DF0CAC
/* DF0CAC 80241E0C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* DF0CB0 80241E10 AFB20030 */  sw        $s2, 0x30($sp)
/* DF0CB4 80241E14 0080902D */  daddu     $s2, $a0, $zero
/* DF0CB8 80241E18 AFBF0038 */  sw        $ra, 0x38($sp)
/* DF0CBC 80241E1C AFB30034 */  sw        $s3, 0x34($sp)
/* DF0CC0 80241E20 AFB1002C */  sw        $s1, 0x2c($sp)
/* DF0CC4 80241E24 AFB00028 */  sw        $s0, 0x28($sp)
/* DF0CC8 80241E28 F7B60048 */  sdc1      $f22, 0x48($sp)
/* DF0CCC 80241E2C F7B40040 */  sdc1      $f20, 0x40($sp)
/* DF0CD0 80241E30 8E510148 */  lw        $s1, 0x148($s2)
/* DF0CD4 80241E34 86240008 */  lh        $a0, 8($s1)
/* DF0CD8 80241E38 0C00EABB */  jal       get_npc_unsafe
/* DF0CDC 80241E3C 00A0982D */   daddu    $s3, $a1, $zero
/* DF0CE0 80241E40 0040802D */  daddu     $s0, $v0, $zero
/* DF0CE4 80241E44 0200202D */  daddu     $a0, $s0, $zero
/* DF0CE8 80241E48 C6220088 */  lwc1      $f2, 0x88($s1)
/* DF0CEC 80241E4C 468010A0 */  cvt.s.w   $f2, $f2
/* DF0CF0 80241E50 460010A1 */  cvt.d.s   $f2, $f2
/* DF0CF4 80241E54 C604001C */  lwc1      $f4, 0x1c($s0)
/* DF0CF8 80241E58 C6000014 */  lwc1      $f0, 0x14($s0)
/* DF0CFC 80241E5C 8E050018 */  lw        $a1, 0x18($s0)
/* DF0D00 80241E60 46002100 */  add.s     $f4, $f4, $f0
/* DF0D04 80241E64 8E06000C */  lw        $a2, 0xc($s0)
/* DF0D08 80241E68 C6200078 */  lwc1      $f0, 0x78($s1)
/* DF0D0C 80241E6C 46800020 */  cvt.s.w   $f0, $f0
/* DF0D10 80241E70 E604001C */  swc1      $f4, 0x1c($s0)
/* DF0D14 80241E74 3C014059 */  lui       $at, 0x4059
/* DF0D18 80241E78 44812800 */  mtc1      $at, $f5
/* DF0D1C 80241E7C 44802000 */  mtc1      $zero, $f4
/* DF0D20 80241E80 46000021 */  cvt.d.s   $f0, $f0
/* DF0D24 80241E84 46240003 */  div.d     $f0, $f0, $f4
/* DF0D28 80241E88 46200520 */  cvt.s.d   $f20, $f0
/* DF0D2C 80241E8C 46241083 */  div.d     $f2, $f2, $f4
/* DF0D30 80241E90 0C00EA95 */  jal       npc_move_heading
/* DF0D34 80241E94 462015A0 */   cvt.s.d  $f22, $f2
/* DF0D38 80241E98 C604001C */  lwc1      $f4, 0x1c($s0)
/* DF0D3C 80241E9C 44801000 */  mtc1      $zero, $f2
/* DF0D40 80241EA0 44801800 */  mtc1      $zero, $f3
/* DF0D44 80241EA4 46002021 */  cvt.d.s   $f0, $f4
/* DF0D48 80241EA8 4620103E */  c.le.d    $f2, $f0
/* DF0D4C 80241EAC 00000000 */  nop
/* DF0D50 80241EB0 45000030 */  bc1f      .L80241F74
/* DF0D54 80241EB4 00000000 */   nop
/* DF0D58 80241EB8 C600003C */  lwc1      $f0, 0x3c($s0)
/* DF0D5C 80241EBC 46040000 */  add.s     $f0, $f0, $f4
/* DF0D60 80241EC0 E600003C */  swc1      $f0, 0x3c($s0)
/* DF0D64 80241EC4 8E2200CC */  lw        $v0, 0xcc($s1)
/* DF0D68 80241EC8 8C420024 */  lw        $v0, 0x24($v0)
/* DF0D6C 80241ECC AE020028 */  sw        $v0, 0x28($s0)
/* DF0D70 80241ED0 A2200007 */  sb        $zero, 7($s1)
/* DF0D74 80241ED4 8E020000 */  lw        $v0, ($s0)
/* DF0D78 80241ED8 30420008 */  andi      $v0, $v0, 8
/* DF0D7C 80241EDC 14400011 */  bnez      $v0, .L80241F24
/* DF0D80 80241EE0 0000102D */   daddu    $v0, $zero, $zero
/* DF0D84 80241EE4 27A50018 */  addiu     $a1, $sp, 0x18
/* DF0D88 80241EE8 27A6001C */  addiu     $a2, $sp, 0x1c
/* DF0D8C 80241EEC C6000038 */  lwc1      $f0, 0x38($s0)
/* DF0D90 80241EF0 C602003C */  lwc1      $f2, 0x3c($s0)
/* DF0D94 80241EF4 C6040040 */  lwc1      $f4, 0x40($s0)
/* DF0D98 80241EF8 3C01447A */  lui       $at, 0x447a
/* DF0D9C 80241EFC 44813000 */  mtc1      $at, $f6
/* DF0DA0 80241F00 27A20024 */  addiu     $v0, $sp, 0x24
/* DF0DA4 80241F04 E7A00018 */  swc1      $f0, 0x18($sp)
/* DF0DA8 80241F08 E7A2001C */  swc1      $f2, 0x1c($sp)
/* DF0DAC 80241F0C E7A40020 */  swc1      $f4, 0x20($sp)
/* DF0DB0 80241F10 E7A60024 */  swc1      $f6, 0x24($sp)
/* DF0DB4 80241F14 AFA20010 */  sw        $v0, 0x10($sp)
/* DF0DB8 80241F18 8E040080 */  lw        $a0, 0x80($s0)
/* DF0DBC 80241F1C 0C0372DF */  jal       func_800DCB7C
/* DF0DC0 80241F20 27A70020 */   addiu    $a3, $sp, 0x20
.L80241F24:
/* DF0DC4 80241F24 1040000B */  beqz      $v0, .L80241F54
/* DF0DC8 80241F28 00000000 */   nop
/* DF0DCC 80241F2C C7A0001C */  lwc1      $f0, 0x1c($sp)
/* DF0DD0 80241F30 46140080 */  add.s     $f2, $f0, $f20
/* DF0DD4 80241F34 C600003C */  lwc1      $f0, 0x3c($s0)
/* DF0DD8 80241F38 4600103E */  c.le.s    $f2, $f0
/* DF0DDC 80241F3C 00000000 */  nop
/* DF0DE0 80241F40 4500008D */  bc1f      .L80242178
/* DF0DE4 80241F44 00000000 */   nop
/* DF0DE8 80241F48 E602003C */  swc1      $f2, 0x3c($s0)
/* DF0DEC 80241F4C 0809085E */  j         .L80242178
/* DF0DF0 80241F50 AE400070 */   sw       $zero, 0x70($s2)
.L80241F54:
/* DF0DF4 80241F54 C602003C */  lwc1      $f2, 0x3c($s0)
/* DF0DF8 80241F58 C6000064 */  lwc1      $f0, 0x64($s0)
/* DF0DFC 80241F5C 4602003E */  c.le.s    $f0, $f2
/* DF0E00 80241F60 00000000 */  nop
/* DF0E04 80241F64 45030084 */  bc1tl     .L80242178
/* DF0E08 80241F68 AE400070 */   sw       $zero, 0x70($s2)
/* DF0E0C 80241F6C 0809085E */  j         .L80242178
/* DF0E10 80241F70 00000000 */   nop
.L80241F74:
/* DF0E14 80241F74 4622003C */  c.lt.d    $f0, $f2
/* DF0E18 80241F78 00000000 */  nop
/* DF0E1C 80241F7C 4500007E */  bc1f      .L80242178
/* DF0E20 80241F80 00000000 */   nop
/* DF0E24 80241F84 9602008E */  lhu       $v0, 0x8e($s0)
/* DF0E28 80241F88 24420001 */  addiu     $v0, $v0, 1
/* DF0E2C 80241F8C A602008E */  sh        $v0, 0x8e($s0)
/* DF0E30 80241F90 00021400 */  sll       $v0, $v0, 0x10
/* DF0E34 80241F94 8E630020 */  lw        $v1, 0x20($s3)
/* DF0E38 80241F98 00021403 */  sra       $v0, $v0, 0x10
/* DF0E3C 80241F9C 0043102A */  slt       $v0, $v0, $v1
/* DF0E40 80241FA0 14400026 */  bnez      $v0, .L8024203C
/* DF0E44 80241FA4 00000000 */   nop
/* DF0E48 80241FA8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* DF0E4C 80241FAC C60E0040 */  lwc1      $f14, 0x40($s0)
/* DF0E50 80241FB0 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* DF0E54 80241FB4 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* DF0E58 80241FB8 A600008E */  sh        $zero, 0x8e($s0)
/* DF0E5C 80241FBC 8C460028 */  lw        $a2, 0x28($v0)
/* DF0E60 80241FC0 0C00A720 */  jal       atan2
/* DF0E64 80241FC4 8C470030 */   lw       $a3, 0x30($v0)
/* DF0E68 80241FC8 46000506 */  mov.s     $f20, $f0
/* DF0E6C 80241FCC C60C000C */  lwc1      $f12, 0xc($s0)
/* DF0E70 80241FD0 0C00A70A */  jal       get_clamped_angle_diff
/* DF0E74 80241FD4 4600A386 */   mov.s    $f14, $f20
/* DF0E78 80241FD8 46000086 */  mov.s     $f2, $f0
/* DF0E7C 80241FDC 8E62001C */  lw        $v0, 0x1c($s3)
/* DF0E80 80241FE0 46001005 */  abs.s     $f0, $f2
/* DF0E84 80241FE4 44822000 */  mtc1      $v0, $f4
/* DF0E88 80241FE8 00000000 */  nop
/* DF0E8C 80241FEC 46802120 */  cvt.s.w   $f4, $f4
/* DF0E90 80241FF0 4600203C */  c.lt.s    $f4, $f0
/* DF0E94 80241FF4 00000000 */  nop
/* DF0E98 80241FF8 4500000D */  bc1f      .L80242030
/* DF0E9C 80241FFC 00000000 */   nop
/* DF0EA0 80242000 44800000 */  mtc1      $zero, $f0
/* DF0EA4 80242004 C614000C */  lwc1      $f20, 0xc($s0)
/* DF0EA8 80242008 4600103C */  c.lt.s    $f2, $f0
/* DF0EAC 8024200C 00000000 */  nop
/* DF0EB0 80242010 45000006 */  bc1f      .L8024202C
/* DF0EB4 80242014 00021023 */   negu     $v0, $v0
/* DF0EB8 80242018 44820000 */  mtc1      $v0, $f0
/* DF0EBC 8024201C 00000000 */  nop
/* DF0EC0 80242020 46800020 */  cvt.s.w   $f0, $f0
/* DF0EC4 80242024 0809080C */  j         .L80242030
/* DF0EC8 80242028 4600A500 */   add.s    $f20, $f20, $f0
.L8024202C:
/* DF0ECC 8024202C 4604A500 */  add.s     $f20, $f20, $f4
.L80242030:
/* DF0ED0 80242030 0C00A6C9 */  jal       clamp_angle
/* DF0ED4 80242034 4600A306 */   mov.s    $f12, $f20
/* DF0ED8 80242038 E600000C */  swc1      $f0, 0xc($s0)
.L8024203C:
/* DF0EDC 8024203C 8E020000 */  lw        $v0, ($s0)
/* DF0EE0 80242040 30420008 */  andi      $v0, $v0, 8
/* DF0EE4 80242044 1040000A */  beqz      $v0, .L80242070
/* DF0EE8 80242048 27A50018 */   addiu    $a1, $sp, 0x18
/* DF0EEC 8024204C C602003C */  lwc1      $f2, 0x3c($s0)
/* DF0EF0 80242050 C600001C */  lwc1      $f0, 0x1c($s0)
/* DF0EF4 80242054 46001080 */  add.s     $f2, $f2, $f0
/* DF0EF8 80242058 4616103C */  c.lt.s    $f2, $f22
/* DF0EFC 8024205C 00000000 */  nop
/* DF0F00 80242060 45020045 */  bc1fl     .L80242178
/* DF0F04 80242064 E602003C */   swc1     $f2, 0x3c($s0)
/* DF0F08 80242068 0809085D */  j         .L80242174
/* DF0F0C 8024206C E616003C */   swc1     $f22, 0x3c($s0)
.L80242070:
/* DF0F10 80242070 C6000038 */  lwc1      $f0, 0x38($s0)
/* DF0F14 80242074 27A6001C */  addiu     $a2, $sp, 0x1c
/* DF0F18 80242078 E7A00018 */  swc1      $f0, 0x18($sp)
/* DF0F1C 8024207C 860200A8 */  lh        $v0, 0xa8($s0)
/* DF0F20 80242080 C600001C */  lwc1      $f0, 0x1c($s0)
/* DF0F24 80242084 C604003C */  lwc1      $f4, 0x3c($s0)
/* DF0F28 80242088 44821000 */  mtc1      $v0, $f2
/* DF0F2C 8024208C 00000000 */  nop
/* DF0F30 80242090 468010A0 */  cvt.s.w   $f2, $f2
/* DF0F34 80242094 46000005 */  abs.s     $f0, $f0
/* DF0F38 80242098 46020000 */  add.s     $f0, $f0, $f2
/* DF0F3C 8024209C C6060040 */  lwc1      $f6, 0x40($s0)
/* DF0F40 802420A0 27A20024 */  addiu     $v0, $sp, 0x24
/* DF0F44 802420A4 46022100 */  add.s     $f4, $f4, $f2
/* DF0F48 802420A8 3C014024 */  lui       $at, 0x4024
/* DF0F4C 802420AC 44811800 */  mtc1      $at, $f3
/* DF0F50 802420B0 44801000 */  mtc1      $zero, $f2
/* DF0F54 802420B4 46000021 */  cvt.d.s   $f0, $f0
/* DF0F58 802420B8 46220000 */  add.d     $f0, $f0, $f2
/* DF0F5C 802420BC E7A60020 */  swc1      $f6, 0x20($sp)
/* DF0F60 802420C0 E7A4001C */  swc1      $f4, 0x1c($sp)
/* DF0F64 802420C4 46200020 */  cvt.s.d   $f0, $f0
/* DF0F68 802420C8 E7A00024 */  swc1      $f0, 0x24($sp)
/* DF0F6C 802420CC AFA20010 */  sw        $v0, 0x10($sp)
/* DF0F70 802420D0 8E040080 */  lw        $a0, 0x80($s0)
/* DF0F74 802420D4 0C0372DF */  jal       func_800DCB7C
/* DF0F78 802420D8 27A70020 */   addiu    $a3, $sp, 0x20
/* DF0F7C 802420DC 10400015 */  beqz      $v0, .L80242134
/* DF0F80 802420E0 00000000 */   nop
/* DF0F84 802420E4 860200A8 */  lh        $v0, 0xa8($s0)
/* DF0F88 802420E8 C604001C */  lwc1      $f4, 0x1c($s0)
/* DF0F8C 802420EC 44820000 */  mtc1      $v0, $f0
/* DF0F90 802420F0 00000000 */  nop
/* DF0F94 802420F4 46800020 */  cvt.s.w   $f0, $f0
/* DF0F98 802420F8 46002085 */  abs.s     $f2, $f4
/* DF0F9C 802420FC 46020000 */  add.s     $f0, $f0, $f2
/* DF0FA0 80242100 C7A20024 */  lwc1      $f2, 0x24($sp)
/* DF0FA4 80242104 4600103E */  c.le.s    $f2, $f0
/* DF0FA8 80242108 00000000 */  nop
/* DF0FAC 8024210C 45000005 */  bc1f      .L80242124
/* DF0FB0 80242110 00000000 */   nop
/* DF0FB4 80242114 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* DF0FB8 80242118 AE00001C */  sw        $zero, 0x1c($s0)
/* DF0FBC 8024211C 0809085E */  j         .L80242178
/* DF0FC0 80242120 E600003C */   swc1     $f0, 0x3c($s0)
.L80242124:
/* DF0FC4 80242124 C600003C */  lwc1      $f0, 0x3c($s0)
/* DF0FC8 80242128 46040000 */  add.s     $f0, $f0, $f4
/* DF0FCC 8024212C 0809085E */  j         .L80242178
/* DF0FD0 80242130 E600003C */   swc1     $f0, 0x3c($s0)
.L80242134:
/* DF0FD4 80242134 C606003C */  lwc1      $f6, 0x3c($s0)
/* DF0FD8 80242138 860200A8 */  lh        $v0, 0xa8($s0)
/* DF0FDC 8024213C 46163081 */  sub.s     $f2, $f6, $f22
/* DF0FE0 80242140 44820000 */  mtc1      $v0, $f0
/* DF0FE4 80242144 00000000 */  nop
/* DF0FE8 80242148 46800020 */  cvt.s.w   $f0, $f0
/* DF0FEC 8024214C 46001080 */  add.s     $f2, $f2, $f0
/* DF0FF0 80242150 C604001C */  lwc1      $f4, 0x1c($s0)
/* DF0FF4 80242154 46002005 */  abs.s     $f0, $f4
/* DF0FF8 80242158 4602003C */  c.lt.s    $f0, $f2
/* DF0FFC 8024215C 00000000 */  nop
/* DF1000 80242160 45020005 */  bc1fl     .L80242178
/* DF1004 80242164 AE00001C */   sw       $zero, 0x1c($s0)
/* DF1008 80242168 46043000 */  add.s     $f0, $f6, $f4
/* DF100C 8024216C 0809085E */  j         .L80242178
/* DF1010 80242170 E600003C */   swc1     $f0, 0x3c($s0)
.L80242174:
/* DF1014 80242174 AE00001C */  sw        $zero, 0x1c($s0)
.L80242178:
/* DF1018 80242178 8FBF0038 */  lw        $ra, 0x38($sp)
/* DF101C 8024217C 8FB30034 */  lw        $s3, 0x34($sp)
/* DF1020 80242180 8FB20030 */  lw        $s2, 0x30($sp)
/* DF1024 80242184 8FB1002C */  lw        $s1, 0x2c($sp)
/* DF1028 80242188 8FB00028 */  lw        $s0, 0x28($sp)
/* DF102C 8024218C D7B60048 */  ldc1      $f22, 0x48($sp)
/* DF1030 80242190 D7B40040 */  ldc1      $f20, 0x40($sp)
/* DF1034 80242194 03E00008 */  jr        $ra
/* DF1038 80242198 27BD0050 */   addiu    $sp, $sp, 0x50
