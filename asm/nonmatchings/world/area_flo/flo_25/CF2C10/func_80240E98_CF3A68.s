.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E98_CF3A68
/* CF3A68 80240E98 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* CF3A6C 80240E9C AFB20030 */  sw        $s2, 0x30($sp)
/* CF3A70 80240EA0 0080902D */  daddu     $s2, $a0, $zero
/* CF3A74 80240EA4 AFBF0038 */  sw        $ra, 0x38($sp)
/* CF3A78 80240EA8 AFB30034 */  sw        $s3, 0x34($sp)
/* CF3A7C 80240EAC AFB1002C */  sw        $s1, 0x2c($sp)
/* CF3A80 80240EB0 AFB00028 */  sw        $s0, 0x28($sp)
/* CF3A84 80240EB4 F7B60048 */  sdc1      $f22, 0x48($sp)
/* CF3A88 80240EB8 F7B40040 */  sdc1      $f20, 0x40($sp)
/* CF3A8C 80240EBC 8E510148 */  lw        $s1, 0x148($s2)
/* CF3A90 80240EC0 86240008 */  lh        $a0, 8($s1)
/* CF3A94 80240EC4 0C00EABB */  jal       get_npc_unsafe
/* CF3A98 80240EC8 00A0982D */   daddu    $s3, $a1, $zero
/* CF3A9C 80240ECC 0040802D */  daddu     $s0, $v0, $zero
/* CF3AA0 80240ED0 0200202D */  daddu     $a0, $s0, $zero
/* CF3AA4 80240ED4 C6220088 */  lwc1      $f2, 0x88($s1)
/* CF3AA8 80240ED8 468010A0 */  cvt.s.w   $f2, $f2
/* CF3AAC 80240EDC 460010A1 */  cvt.d.s   $f2, $f2
/* CF3AB0 80240EE0 C604001C */  lwc1      $f4, 0x1c($s0)
/* CF3AB4 80240EE4 C6000014 */  lwc1      $f0, 0x14($s0)
/* CF3AB8 80240EE8 8E050018 */  lw        $a1, 0x18($s0)
/* CF3ABC 80240EEC 46002100 */  add.s     $f4, $f4, $f0
/* CF3AC0 80240EF0 8E06000C */  lw        $a2, 0xc($s0)
/* CF3AC4 80240EF4 C6200078 */  lwc1      $f0, 0x78($s1)
/* CF3AC8 80240EF8 46800020 */  cvt.s.w   $f0, $f0
/* CF3ACC 80240EFC E604001C */  swc1      $f4, 0x1c($s0)
/* CF3AD0 80240F00 3C014059 */  lui       $at, 0x4059
/* CF3AD4 80240F04 44812800 */  mtc1      $at, $f5
/* CF3AD8 80240F08 44802000 */  mtc1      $zero, $f4
/* CF3ADC 80240F0C 46000021 */  cvt.d.s   $f0, $f0
/* CF3AE0 80240F10 46240003 */  div.d     $f0, $f0, $f4
/* CF3AE4 80240F14 46200520 */  cvt.s.d   $f20, $f0
/* CF3AE8 80240F18 46241083 */  div.d     $f2, $f2, $f4
/* CF3AEC 80240F1C 0C00EA95 */  jal       npc_move_heading
/* CF3AF0 80240F20 462015A0 */   cvt.s.d  $f22, $f2
/* CF3AF4 80240F24 C604001C */  lwc1      $f4, 0x1c($s0)
/* CF3AF8 80240F28 44801000 */  mtc1      $zero, $f2
/* CF3AFC 80240F2C 44801800 */  mtc1      $zero, $f3
/* CF3B00 80240F30 46002021 */  cvt.d.s   $f0, $f4
/* CF3B04 80240F34 4620103E */  c.le.d    $f2, $f0
/* CF3B08 80240F38 00000000 */  nop       
/* CF3B0C 80240F3C 45000030 */  bc1f      .L80241000
/* CF3B10 80240F40 00000000 */   nop      
/* CF3B14 80240F44 C600003C */  lwc1      $f0, 0x3c($s0)
/* CF3B18 80240F48 46040000 */  add.s     $f0, $f0, $f4
/* CF3B1C 80240F4C E600003C */  swc1      $f0, 0x3c($s0)
/* CF3B20 80240F50 8E2200CC */  lw        $v0, 0xcc($s1)
/* CF3B24 80240F54 8C420024 */  lw        $v0, 0x24($v0)
/* CF3B28 80240F58 AE020028 */  sw        $v0, 0x28($s0)
/* CF3B2C 80240F5C A2200007 */  sb        $zero, 7($s1)
/* CF3B30 80240F60 8E020000 */  lw        $v0, ($s0)
/* CF3B34 80240F64 30420008 */  andi      $v0, $v0, 8
/* CF3B38 80240F68 14400011 */  bnez      $v0, .L80240FB0
/* CF3B3C 80240F6C 0000102D */   daddu    $v0, $zero, $zero
/* CF3B40 80240F70 27A50018 */  addiu     $a1, $sp, 0x18
/* CF3B44 80240F74 27A6001C */  addiu     $a2, $sp, 0x1c
/* CF3B48 80240F78 C6000038 */  lwc1      $f0, 0x38($s0)
/* CF3B4C 80240F7C C602003C */  lwc1      $f2, 0x3c($s0)
/* CF3B50 80240F80 C6040040 */  lwc1      $f4, 0x40($s0)
/* CF3B54 80240F84 3C01447A */  lui       $at, 0x447a
/* CF3B58 80240F88 44813000 */  mtc1      $at, $f6
/* CF3B5C 80240F8C 27A20024 */  addiu     $v0, $sp, 0x24
/* CF3B60 80240F90 E7A00018 */  swc1      $f0, 0x18($sp)
/* CF3B64 80240F94 E7A2001C */  swc1      $f2, 0x1c($sp)
/* CF3B68 80240F98 E7A40020 */  swc1      $f4, 0x20($sp)
/* CF3B6C 80240F9C E7A60024 */  swc1      $f6, 0x24($sp)
/* CF3B70 80240FA0 AFA20010 */  sw        $v0, 0x10($sp)
/* CF3B74 80240FA4 8E040080 */  lw        $a0, 0x80($s0)
/* CF3B78 80240FA8 0C0372DF */  jal       func_800DCB7C
/* CF3B7C 80240FAC 27A70020 */   addiu    $a3, $sp, 0x20
.L80240FB0:
/* CF3B80 80240FB0 1040000B */  beqz      $v0, .L80240FE0
/* CF3B84 80240FB4 00000000 */   nop      
/* CF3B88 80240FB8 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* CF3B8C 80240FBC 46140080 */  add.s     $f2, $f0, $f20
/* CF3B90 80240FC0 C600003C */  lwc1      $f0, 0x3c($s0)
/* CF3B94 80240FC4 4600103E */  c.le.s    $f2, $f0
/* CF3B98 80240FC8 00000000 */  nop       
/* CF3B9C 80240FCC 4500008D */  bc1f      .L80241204
/* CF3BA0 80240FD0 00000000 */   nop      
/* CF3BA4 80240FD4 E602003C */  swc1      $f2, 0x3c($s0)
/* CF3BA8 80240FD8 08090481 */  j         .L80241204
/* CF3BAC 80240FDC AE400070 */   sw       $zero, 0x70($s2)
.L80240FE0:
/* CF3BB0 80240FE0 C602003C */  lwc1      $f2, 0x3c($s0)
/* CF3BB4 80240FE4 C6000064 */  lwc1      $f0, 0x64($s0)
/* CF3BB8 80240FE8 4602003E */  c.le.s    $f0, $f2
/* CF3BBC 80240FEC 00000000 */  nop       
/* CF3BC0 80240FF0 45030084 */  bc1tl     .L80241204
/* CF3BC4 80240FF4 AE400070 */   sw       $zero, 0x70($s2)
/* CF3BC8 80240FF8 08090481 */  j         .L80241204
/* CF3BCC 80240FFC 00000000 */   nop      
.L80241000:
/* CF3BD0 80241000 4622003C */  c.lt.d    $f0, $f2
/* CF3BD4 80241004 00000000 */  nop       
/* CF3BD8 80241008 4500007E */  bc1f      .L80241204
/* CF3BDC 8024100C 00000000 */   nop      
/* CF3BE0 80241010 9602008E */  lhu       $v0, 0x8e($s0)
/* CF3BE4 80241014 24420001 */  addiu     $v0, $v0, 1
/* CF3BE8 80241018 A602008E */  sh        $v0, 0x8e($s0)
/* CF3BEC 8024101C 00021400 */  sll       $v0, $v0, 0x10
/* CF3BF0 80241020 8E630020 */  lw        $v1, 0x20($s3)
/* CF3BF4 80241024 00021403 */  sra       $v0, $v0, 0x10
/* CF3BF8 80241028 0043102A */  slt       $v0, $v0, $v1
/* CF3BFC 8024102C 14400026 */  bnez      $v0, .L802410C8
/* CF3C00 80241030 00000000 */   nop      
/* CF3C04 80241034 C60C0038 */  lwc1      $f12, 0x38($s0)
/* CF3C08 80241038 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CF3C0C 8024103C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CF3C10 80241040 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CF3C14 80241044 A600008E */  sh        $zero, 0x8e($s0)
/* CF3C18 80241048 8C460028 */  lw        $a2, 0x28($v0)
/* CF3C1C 8024104C 0C00A720 */  jal       atan2
/* CF3C20 80241050 8C470030 */   lw       $a3, 0x30($v0)
/* CF3C24 80241054 46000506 */  mov.s     $f20, $f0
/* CF3C28 80241058 C60C000C */  lwc1      $f12, 0xc($s0)
/* CF3C2C 8024105C 0C00A70A */  jal       get_clamped_angle_diff
/* CF3C30 80241060 4600A386 */   mov.s    $f14, $f20
/* CF3C34 80241064 46000086 */  mov.s     $f2, $f0
/* CF3C38 80241068 8E62001C */  lw        $v0, 0x1c($s3)
/* CF3C3C 8024106C 46001005 */  abs.s     $f0, $f2
/* CF3C40 80241070 44822000 */  mtc1      $v0, $f4
/* CF3C44 80241074 00000000 */  nop       
/* CF3C48 80241078 46802120 */  cvt.s.w   $f4, $f4
/* CF3C4C 8024107C 4600203C */  c.lt.s    $f4, $f0
/* CF3C50 80241080 00000000 */  nop       
/* CF3C54 80241084 4500000D */  bc1f      .L802410BC
/* CF3C58 80241088 00000000 */   nop      
/* CF3C5C 8024108C 44800000 */  mtc1      $zero, $f0
/* CF3C60 80241090 C614000C */  lwc1      $f20, 0xc($s0)
/* CF3C64 80241094 4600103C */  c.lt.s    $f2, $f0
/* CF3C68 80241098 00000000 */  nop       
/* CF3C6C 8024109C 45000006 */  bc1f      .L802410B8
/* CF3C70 802410A0 00021023 */   negu     $v0, $v0
/* CF3C74 802410A4 44820000 */  mtc1      $v0, $f0
/* CF3C78 802410A8 00000000 */  nop       
/* CF3C7C 802410AC 46800020 */  cvt.s.w   $f0, $f0
/* CF3C80 802410B0 0809042F */  j         .L802410BC
/* CF3C84 802410B4 4600A500 */   add.s    $f20, $f20, $f0
.L802410B8:
/* CF3C88 802410B8 4604A500 */  add.s     $f20, $f20, $f4
.L802410BC:
/* CF3C8C 802410BC 0C00A6C9 */  jal       clamp_angle
/* CF3C90 802410C0 4600A306 */   mov.s    $f12, $f20
/* CF3C94 802410C4 E600000C */  swc1      $f0, 0xc($s0)
.L802410C8:
/* CF3C98 802410C8 8E020000 */  lw        $v0, ($s0)
/* CF3C9C 802410CC 30420008 */  andi      $v0, $v0, 8
/* CF3CA0 802410D0 1040000A */  beqz      $v0, .L802410FC
/* CF3CA4 802410D4 27A50018 */   addiu    $a1, $sp, 0x18
/* CF3CA8 802410D8 C602003C */  lwc1      $f2, 0x3c($s0)
/* CF3CAC 802410DC C600001C */  lwc1      $f0, 0x1c($s0)
/* CF3CB0 802410E0 46001080 */  add.s     $f2, $f2, $f0
/* CF3CB4 802410E4 4616103C */  c.lt.s    $f2, $f22
/* CF3CB8 802410E8 00000000 */  nop       
/* CF3CBC 802410EC 45020045 */  bc1fl     .L80241204
/* CF3CC0 802410F0 E602003C */   swc1     $f2, 0x3c($s0)
/* CF3CC4 802410F4 08090480 */  j         .L80241200
/* CF3CC8 802410F8 E616003C */   swc1     $f22, 0x3c($s0)
.L802410FC:
/* CF3CCC 802410FC C6000038 */  lwc1      $f0, 0x38($s0)
/* CF3CD0 80241100 27A6001C */  addiu     $a2, $sp, 0x1c
/* CF3CD4 80241104 E7A00018 */  swc1      $f0, 0x18($sp)
/* CF3CD8 80241108 860200A8 */  lh        $v0, 0xa8($s0)
/* CF3CDC 8024110C C600001C */  lwc1      $f0, 0x1c($s0)
/* CF3CE0 80241110 C604003C */  lwc1      $f4, 0x3c($s0)
/* CF3CE4 80241114 44821000 */  mtc1      $v0, $f2
/* CF3CE8 80241118 00000000 */  nop       
/* CF3CEC 8024111C 468010A0 */  cvt.s.w   $f2, $f2
/* CF3CF0 80241120 46000005 */  abs.s     $f0, $f0
/* CF3CF4 80241124 46020000 */  add.s     $f0, $f0, $f2
/* CF3CF8 80241128 C6060040 */  lwc1      $f6, 0x40($s0)
/* CF3CFC 8024112C 27A20024 */  addiu     $v0, $sp, 0x24
/* CF3D00 80241130 46022100 */  add.s     $f4, $f4, $f2
/* CF3D04 80241134 3C014024 */  lui       $at, 0x4024
/* CF3D08 80241138 44811800 */  mtc1      $at, $f3
/* CF3D0C 8024113C 44801000 */  mtc1      $zero, $f2
/* CF3D10 80241140 46000021 */  cvt.d.s   $f0, $f0
/* CF3D14 80241144 46220000 */  add.d     $f0, $f0, $f2
/* CF3D18 80241148 E7A60020 */  swc1      $f6, 0x20($sp)
/* CF3D1C 8024114C E7A4001C */  swc1      $f4, 0x1c($sp)
/* CF3D20 80241150 46200020 */  cvt.s.d   $f0, $f0
/* CF3D24 80241154 E7A00024 */  swc1      $f0, 0x24($sp)
/* CF3D28 80241158 AFA20010 */  sw        $v0, 0x10($sp)
/* CF3D2C 8024115C 8E040080 */  lw        $a0, 0x80($s0)
/* CF3D30 80241160 0C0372DF */  jal       func_800DCB7C
/* CF3D34 80241164 27A70020 */   addiu    $a3, $sp, 0x20
/* CF3D38 80241168 10400015 */  beqz      $v0, .L802411C0
/* CF3D3C 8024116C 00000000 */   nop      
/* CF3D40 80241170 860200A8 */  lh        $v0, 0xa8($s0)
/* CF3D44 80241174 C604001C */  lwc1      $f4, 0x1c($s0)
/* CF3D48 80241178 44820000 */  mtc1      $v0, $f0
/* CF3D4C 8024117C 00000000 */  nop       
/* CF3D50 80241180 46800020 */  cvt.s.w   $f0, $f0
/* CF3D54 80241184 46002085 */  abs.s     $f2, $f4
/* CF3D58 80241188 46020000 */  add.s     $f0, $f0, $f2
/* CF3D5C 8024118C C7A20024 */  lwc1      $f2, 0x24($sp)
/* CF3D60 80241190 4600103E */  c.le.s    $f2, $f0
/* CF3D64 80241194 00000000 */  nop       
/* CF3D68 80241198 45000005 */  bc1f      .L802411B0
/* CF3D6C 8024119C 00000000 */   nop      
/* CF3D70 802411A0 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* CF3D74 802411A4 AE00001C */  sw        $zero, 0x1c($s0)
/* CF3D78 802411A8 08090481 */  j         .L80241204
/* CF3D7C 802411AC E600003C */   swc1     $f0, 0x3c($s0)
.L802411B0:
/* CF3D80 802411B0 C600003C */  lwc1      $f0, 0x3c($s0)
/* CF3D84 802411B4 46040000 */  add.s     $f0, $f0, $f4
/* CF3D88 802411B8 08090481 */  j         .L80241204
/* CF3D8C 802411BC E600003C */   swc1     $f0, 0x3c($s0)
.L802411C0:
/* CF3D90 802411C0 C606003C */  lwc1      $f6, 0x3c($s0)
/* CF3D94 802411C4 860200A8 */  lh        $v0, 0xa8($s0)
/* CF3D98 802411C8 46163081 */  sub.s     $f2, $f6, $f22
/* CF3D9C 802411CC 44820000 */  mtc1      $v0, $f0
/* CF3DA0 802411D0 00000000 */  nop       
/* CF3DA4 802411D4 46800020 */  cvt.s.w   $f0, $f0
/* CF3DA8 802411D8 46001080 */  add.s     $f2, $f2, $f0
/* CF3DAC 802411DC C604001C */  lwc1      $f4, 0x1c($s0)
/* CF3DB0 802411E0 46002005 */  abs.s     $f0, $f4
/* CF3DB4 802411E4 4602003C */  c.lt.s    $f0, $f2
/* CF3DB8 802411E8 00000000 */  nop       
/* CF3DBC 802411EC 45020005 */  bc1fl     .L80241204
/* CF3DC0 802411F0 AE00001C */   sw       $zero, 0x1c($s0)
/* CF3DC4 802411F4 46043000 */  add.s     $f0, $f6, $f4
/* CF3DC8 802411F8 08090481 */  j         .L80241204
/* CF3DCC 802411FC E600003C */   swc1     $f0, 0x3c($s0)
.L80241200:
/* CF3DD0 80241200 AE00001C */  sw        $zero, 0x1c($s0)
.L80241204:
/* CF3DD4 80241204 8FBF0038 */  lw        $ra, 0x38($sp)
/* CF3DD8 80241208 8FB30034 */  lw        $s3, 0x34($sp)
/* CF3DDC 8024120C 8FB20030 */  lw        $s2, 0x30($sp)
/* CF3DE0 80241210 8FB1002C */  lw        $s1, 0x2c($sp)
/* CF3DE4 80241214 8FB00028 */  lw        $s0, 0x28($sp)
/* CF3DE8 80241218 D7B60048 */  ldc1      $f22, 0x48($sp)
/* CF3DEC 8024121C D7B40040 */  ldc1      $f20, 0x40($sp)
/* CF3DF0 80241220 03E00008 */  jr        $ra
/* CF3DF4 80241224 27BD0050 */   addiu    $sp, $sp, 0x50
