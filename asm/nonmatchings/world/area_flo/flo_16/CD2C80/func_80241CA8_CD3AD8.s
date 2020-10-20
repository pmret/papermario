.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CA8_CD3AD8
/* CD3AD8 80241CA8 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* CD3ADC 80241CAC AFB20030 */  sw        $s2, 0x30($sp)
/* CD3AE0 80241CB0 0080902D */  daddu     $s2, $a0, $zero
/* CD3AE4 80241CB4 AFBF0038 */  sw        $ra, 0x38($sp)
/* CD3AE8 80241CB8 AFB30034 */  sw        $s3, 0x34($sp)
/* CD3AEC 80241CBC AFB1002C */  sw        $s1, 0x2c($sp)
/* CD3AF0 80241CC0 AFB00028 */  sw        $s0, 0x28($sp)
/* CD3AF4 80241CC4 F7B60048 */  sdc1      $f22, 0x48($sp)
/* CD3AF8 80241CC8 F7B40040 */  sdc1      $f20, 0x40($sp)
/* CD3AFC 80241CCC 8E510148 */  lw        $s1, 0x148($s2)
/* CD3B00 80241CD0 86240008 */  lh        $a0, 8($s1)
/* CD3B04 80241CD4 0C00EABB */  jal       get_npc_unsafe
/* CD3B08 80241CD8 00A0982D */   daddu    $s3, $a1, $zero
/* CD3B0C 80241CDC 0040802D */  daddu     $s0, $v0, $zero
/* CD3B10 80241CE0 0200202D */  daddu     $a0, $s0, $zero
/* CD3B14 80241CE4 C6220088 */  lwc1      $f2, 0x88($s1)
/* CD3B18 80241CE8 468010A0 */  cvt.s.w   $f2, $f2
/* CD3B1C 80241CEC 460010A1 */  cvt.d.s   $f2, $f2
/* CD3B20 80241CF0 C604001C */  lwc1      $f4, 0x1c($s0)
/* CD3B24 80241CF4 C6000014 */  lwc1      $f0, 0x14($s0)
/* CD3B28 80241CF8 8E050018 */  lw        $a1, 0x18($s0)
/* CD3B2C 80241CFC 46002100 */  add.s     $f4, $f4, $f0
/* CD3B30 80241D00 8E06000C */  lw        $a2, 0xc($s0)
/* CD3B34 80241D04 C6200078 */  lwc1      $f0, 0x78($s1)
/* CD3B38 80241D08 46800020 */  cvt.s.w   $f0, $f0
/* CD3B3C 80241D0C E604001C */  swc1      $f4, 0x1c($s0)
/* CD3B40 80241D10 3C014059 */  lui       $at, 0x4059
/* CD3B44 80241D14 44812800 */  mtc1      $at, $f5
/* CD3B48 80241D18 44802000 */  mtc1      $zero, $f4
/* CD3B4C 80241D1C 46000021 */  cvt.d.s   $f0, $f0
/* CD3B50 80241D20 46240003 */  div.d     $f0, $f0, $f4
/* CD3B54 80241D24 46200520 */  cvt.s.d   $f20, $f0
/* CD3B58 80241D28 46241083 */  div.d     $f2, $f2, $f4
/* CD3B5C 80241D2C 0C00EA95 */  jal       npc_move_heading
/* CD3B60 80241D30 462015A0 */   cvt.s.d  $f22, $f2
/* CD3B64 80241D34 C604001C */  lwc1      $f4, 0x1c($s0)
/* CD3B68 80241D38 44801000 */  mtc1      $zero, $f2
/* CD3B6C 80241D3C 44801800 */  mtc1      $zero, $f3
/* CD3B70 80241D40 46002021 */  cvt.d.s   $f0, $f4
/* CD3B74 80241D44 4620103E */  c.le.d    $f2, $f0
/* CD3B78 80241D48 00000000 */  nop       
/* CD3B7C 80241D4C 45000030 */  bc1f      .L80241E10
/* CD3B80 80241D50 00000000 */   nop      
/* CD3B84 80241D54 C600003C */  lwc1      $f0, 0x3c($s0)
/* CD3B88 80241D58 46040000 */  add.s     $f0, $f0, $f4
/* CD3B8C 80241D5C E600003C */  swc1      $f0, 0x3c($s0)
/* CD3B90 80241D60 8E2200CC */  lw        $v0, 0xcc($s1)
/* CD3B94 80241D64 8C420024 */  lw        $v0, 0x24($v0)
/* CD3B98 80241D68 AE020028 */  sw        $v0, 0x28($s0)
/* CD3B9C 80241D6C A2200007 */  sb        $zero, 7($s1)
/* CD3BA0 80241D70 8E020000 */  lw        $v0, ($s0)
/* CD3BA4 80241D74 30420008 */  andi      $v0, $v0, 8
/* CD3BA8 80241D78 14400011 */  bnez      $v0, .L80241DC0
/* CD3BAC 80241D7C 0000102D */   daddu    $v0, $zero, $zero
/* CD3BB0 80241D80 27A50018 */  addiu     $a1, $sp, 0x18
/* CD3BB4 80241D84 27A6001C */  addiu     $a2, $sp, 0x1c
/* CD3BB8 80241D88 C6000038 */  lwc1      $f0, 0x38($s0)
/* CD3BBC 80241D8C C602003C */  lwc1      $f2, 0x3c($s0)
/* CD3BC0 80241D90 C6040040 */  lwc1      $f4, 0x40($s0)
/* CD3BC4 80241D94 3C01447A */  lui       $at, 0x447a
/* CD3BC8 80241D98 44813000 */  mtc1      $at, $f6
/* CD3BCC 80241D9C 27A20024 */  addiu     $v0, $sp, 0x24
/* CD3BD0 80241DA0 E7A00018 */  swc1      $f0, 0x18($sp)
/* CD3BD4 80241DA4 E7A2001C */  swc1      $f2, 0x1c($sp)
/* CD3BD8 80241DA8 E7A40020 */  swc1      $f4, 0x20($sp)
/* CD3BDC 80241DAC E7A60024 */  swc1      $f6, 0x24($sp)
/* CD3BE0 80241DB0 AFA20010 */  sw        $v0, 0x10($sp)
/* CD3BE4 80241DB4 8E040080 */  lw        $a0, 0x80($s0)
/* CD3BE8 80241DB8 0C0372DF */  jal       func_800DCB7C
/* CD3BEC 80241DBC 27A70020 */   addiu    $a3, $sp, 0x20
.L80241DC0:
/* CD3BF0 80241DC0 1040000B */  beqz      $v0, .L80241DF0
/* CD3BF4 80241DC4 00000000 */   nop      
/* CD3BF8 80241DC8 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* CD3BFC 80241DCC 46140080 */  add.s     $f2, $f0, $f20
/* CD3C00 80241DD0 C600003C */  lwc1      $f0, 0x3c($s0)
/* CD3C04 80241DD4 4600103E */  c.le.s    $f2, $f0
/* CD3C08 80241DD8 00000000 */  nop       
/* CD3C0C 80241DDC 4500008D */  bc1f      .L80242014
/* CD3C10 80241DE0 00000000 */   nop      
/* CD3C14 80241DE4 E602003C */  swc1      $f2, 0x3c($s0)
/* CD3C18 80241DE8 08090805 */  j         .L80242014
/* CD3C1C 80241DEC AE400070 */   sw       $zero, 0x70($s2)
.L80241DF0:
/* CD3C20 80241DF0 C602003C */  lwc1      $f2, 0x3c($s0)
/* CD3C24 80241DF4 C6000064 */  lwc1      $f0, 0x64($s0)
/* CD3C28 80241DF8 4602003E */  c.le.s    $f0, $f2
/* CD3C2C 80241DFC 00000000 */  nop       
/* CD3C30 80241E00 45030084 */  bc1tl     .L80242014
/* CD3C34 80241E04 AE400070 */   sw       $zero, 0x70($s2)
/* CD3C38 80241E08 08090805 */  j         .L80242014
/* CD3C3C 80241E0C 00000000 */   nop      
.L80241E10:
/* CD3C40 80241E10 4622003C */  c.lt.d    $f0, $f2
/* CD3C44 80241E14 00000000 */  nop       
/* CD3C48 80241E18 4500007E */  bc1f      .L80242014
/* CD3C4C 80241E1C 00000000 */   nop      
/* CD3C50 80241E20 9602008E */  lhu       $v0, 0x8e($s0)
/* CD3C54 80241E24 24420001 */  addiu     $v0, $v0, 1
/* CD3C58 80241E28 A602008E */  sh        $v0, 0x8e($s0)
/* CD3C5C 80241E2C 00021400 */  sll       $v0, $v0, 0x10
/* CD3C60 80241E30 8E630020 */  lw        $v1, 0x20($s3)
/* CD3C64 80241E34 00021403 */  sra       $v0, $v0, 0x10
/* CD3C68 80241E38 0043102A */  slt       $v0, $v0, $v1
/* CD3C6C 80241E3C 14400026 */  bnez      $v0, .L80241ED8
/* CD3C70 80241E40 00000000 */   nop      
/* CD3C74 80241E44 C60C0038 */  lwc1      $f12, 0x38($s0)
/* CD3C78 80241E48 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CD3C7C 80241E4C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CD3C80 80241E50 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CD3C84 80241E54 A600008E */  sh        $zero, 0x8e($s0)
/* CD3C88 80241E58 8C460028 */  lw        $a2, 0x28($v0)
/* CD3C8C 80241E5C 0C00A720 */  jal       atan2
/* CD3C90 80241E60 8C470030 */   lw       $a3, 0x30($v0)
/* CD3C94 80241E64 46000506 */  mov.s     $f20, $f0
/* CD3C98 80241E68 C60C000C */  lwc1      $f12, 0xc($s0)
/* CD3C9C 80241E6C 0C00A70A */  jal       get_clamped_angle_diff
/* CD3CA0 80241E70 4600A386 */   mov.s    $f14, $f20
/* CD3CA4 80241E74 46000086 */  mov.s     $f2, $f0
/* CD3CA8 80241E78 8E62001C */  lw        $v0, 0x1c($s3)
/* CD3CAC 80241E7C 46001005 */  abs.s     $f0, $f2
/* CD3CB0 80241E80 44822000 */  mtc1      $v0, $f4
/* CD3CB4 80241E84 00000000 */  nop       
/* CD3CB8 80241E88 46802120 */  cvt.s.w   $f4, $f4
/* CD3CBC 80241E8C 4600203C */  c.lt.s    $f4, $f0
/* CD3CC0 80241E90 00000000 */  nop       
/* CD3CC4 80241E94 4500000D */  bc1f      .L80241ECC
/* CD3CC8 80241E98 00000000 */   nop      
/* CD3CCC 80241E9C 44800000 */  mtc1      $zero, $f0
/* CD3CD0 80241EA0 C614000C */  lwc1      $f20, 0xc($s0)
/* CD3CD4 80241EA4 4600103C */  c.lt.s    $f2, $f0
/* CD3CD8 80241EA8 00000000 */  nop       
/* CD3CDC 80241EAC 45000006 */  bc1f      .L80241EC8
/* CD3CE0 80241EB0 00021023 */   negu     $v0, $v0
/* CD3CE4 80241EB4 44820000 */  mtc1      $v0, $f0
/* CD3CE8 80241EB8 00000000 */  nop       
/* CD3CEC 80241EBC 46800020 */  cvt.s.w   $f0, $f0
/* CD3CF0 80241EC0 080907B3 */  j         .L80241ECC
/* CD3CF4 80241EC4 4600A500 */   add.s    $f20, $f20, $f0
.L80241EC8:
/* CD3CF8 80241EC8 4604A500 */  add.s     $f20, $f20, $f4
.L80241ECC:
/* CD3CFC 80241ECC 0C00A6C9 */  jal       clamp_angle
/* CD3D00 80241ED0 4600A306 */   mov.s    $f12, $f20
/* CD3D04 80241ED4 E600000C */  swc1      $f0, 0xc($s0)
.L80241ED8:
/* CD3D08 80241ED8 8E020000 */  lw        $v0, ($s0)
/* CD3D0C 80241EDC 30420008 */  andi      $v0, $v0, 8
/* CD3D10 80241EE0 1040000A */  beqz      $v0, .L80241F0C
/* CD3D14 80241EE4 27A50018 */   addiu    $a1, $sp, 0x18
/* CD3D18 80241EE8 C602003C */  lwc1      $f2, 0x3c($s0)
/* CD3D1C 80241EEC C600001C */  lwc1      $f0, 0x1c($s0)
/* CD3D20 80241EF0 46001080 */  add.s     $f2, $f2, $f0
/* CD3D24 80241EF4 4616103C */  c.lt.s    $f2, $f22
/* CD3D28 80241EF8 00000000 */  nop       
/* CD3D2C 80241EFC 45020045 */  bc1fl     .L80242014
/* CD3D30 80241F00 E602003C */   swc1     $f2, 0x3c($s0)
/* CD3D34 80241F04 08090804 */  j         .L80242010
/* CD3D38 80241F08 E616003C */   swc1     $f22, 0x3c($s0)
.L80241F0C:
/* CD3D3C 80241F0C C6000038 */  lwc1      $f0, 0x38($s0)
/* CD3D40 80241F10 27A6001C */  addiu     $a2, $sp, 0x1c
/* CD3D44 80241F14 E7A00018 */  swc1      $f0, 0x18($sp)
/* CD3D48 80241F18 860200A8 */  lh        $v0, 0xa8($s0)
/* CD3D4C 80241F1C C600001C */  lwc1      $f0, 0x1c($s0)
/* CD3D50 80241F20 C604003C */  lwc1      $f4, 0x3c($s0)
/* CD3D54 80241F24 44821000 */  mtc1      $v0, $f2
/* CD3D58 80241F28 00000000 */  nop       
/* CD3D5C 80241F2C 468010A0 */  cvt.s.w   $f2, $f2
/* CD3D60 80241F30 46000005 */  abs.s     $f0, $f0
/* CD3D64 80241F34 46020000 */  add.s     $f0, $f0, $f2
/* CD3D68 80241F38 C6060040 */  lwc1      $f6, 0x40($s0)
/* CD3D6C 80241F3C 27A20024 */  addiu     $v0, $sp, 0x24
/* CD3D70 80241F40 46022100 */  add.s     $f4, $f4, $f2
/* CD3D74 80241F44 3C014024 */  lui       $at, 0x4024
/* CD3D78 80241F48 44811800 */  mtc1      $at, $f3
/* CD3D7C 80241F4C 44801000 */  mtc1      $zero, $f2
/* CD3D80 80241F50 46000021 */  cvt.d.s   $f0, $f0
/* CD3D84 80241F54 46220000 */  add.d     $f0, $f0, $f2
/* CD3D88 80241F58 E7A60020 */  swc1      $f6, 0x20($sp)
/* CD3D8C 80241F5C E7A4001C */  swc1      $f4, 0x1c($sp)
/* CD3D90 80241F60 46200020 */  cvt.s.d   $f0, $f0
/* CD3D94 80241F64 E7A00024 */  swc1      $f0, 0x24($sp)
/* CD3D98 80241F68 AFA20010 */  sw        $v0, 0x10($sp)
/* CD3D9C 80241F6C 8E040080 */  lw        $a0, 0x80($s0)
/* CD3DA0 80241F70 0C0372DF */  jal       func_800DCB7C
/* CD3DA4 80241F74 27A70020 */   addiu    $a3, $sp, 0x20
/* CD3DA8 80241F78 10400015 */  beqz      $v0, .L80241FD0
/* CD3DAC 80241F7C 00000000 */   nop      
/* CD3DB0 80241F80 860200A8 */  lh        $v0, 0xa8($s0)
/* CD3DB4 80241F84 C604001C */  lwc1      $f4, 0x1c($s0)
/* CD3DB8 80241F88 44820000 */  mtc1      $v0, $f0
/* CD3DBC 80241F8C 00000000 */  nop       
/* CD3DC0 80241F90 46800020 */  cvt.s.w   $f0, $f0
/* CD3DC4 80241F94 46002085 */  abs.s     $f2, $f4
/* CD3DC8 80241F98 46020000 */  add.s     $f0, $f0, $f2
/* CD3DCC 80241F9C C7A20024 */  lwc1      $f2, 0x24($sp)
/* CD3DD0 80241FA0 4600103E */  c.le.s    $f2, $f0
/* CD3DD4 80241FA4 00000000 */  nop       
/* CD3DD8 80241FA8 45000005 */  bc1f      .L80241FC0
/* CD3DDC 80241FAC 00000000 */   nop      
/* CD3DE0 80241FB0 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* CD3DE4 80241FB4 AE00001C */  sw        $zero, 0x1c($s0)
/* CD3DE8 80241FB8 08090805 */  j         .L80242014
/* CD3DEC 80241FBC E600003C */   swc1     $f0, 0x3c($s0)
.L80241FC0:
/* CD3DF0 80241FC0 C600003C */  lwc1      $f0, 0x3c($s0)
/* CD3DF4 80241FC4 46040000 */  add.s     $f0, $f0, $f4
/* CD3DF8 80241FC8 08090805 */  j         .L80242014
/* CD3DFC 80241FCC E600003C */   swc1     $f0, 0x3c($s0)
.L80241FD0:
/* CD3E00 80241FD0 C606003C */  lwc1      $f6, 0x3c($s0)
/* CD3E04 80241FD4 860200A8 */  lh        $v0, 0xa8($s0)
/* CD3E08 80241FD8 46163081 */  sub.s     $f2, $f6, $f22
/* CD3E0C 80241FDC 44820000 */  mtc1      $v0, $f0
/* CD3E10 80241FE0 00000000 */  nop       
/* CD3E14 80241FE4 46800020 */  cvt.s.w   $f0, $f0
/* CD3E18 80241FE8 46001080 */  add.s     $f2, $f2, $f0
/* CD3E1C 80241FEC C604001C */  lwc1      $f4, 0x1c($s0)
/* CD3E20 80241FF0 46002005 */  abs.s     $f0, $f4
/* CD3E24 80241FF4 4602003C */  c.lt.s    $f0, $f2
/* CD3E28 80241FF8 00000000 */  nop       
/* CD3E2C 80241FFC 45020005 */  bc1fl     .L80242014
/* CD3E30 80242000 AE00001C */   sw       $zero, 0x1c($s0)
/* CD3E34 80242004 46043000 */  add.s     $f0, $f6, $f4
/* CD3E38 80242008 08090805 */  j         .L80242014
/* CD3E3C 8024200C E600003C */   swc1     $f0, 0x3c($s0)
.L80242010:
/* CD3E40 80242010 AE00001C */  sw        $zero, 0x1c($s0)
.L80242014:
/* CD3E44 80242014 8FBF0038 */  lw        $ra, 0x38($sp)
/* CD3E48 80242018 8FB30034 */  lw        $s3, 0x34($sp)
/* CD3E4C 8024201C 8FB20030 */  lw        $s2, 0x30($sp)
/* CD3E50 80242020 8FB1002C */  lw        $s1, 0x2c($sp)
/* CD3E54 80242024 8FB00028 */  lw        $s0, 0x28($sp)
/* CD3E58 80242028 D7B60048 */  ldc1      $f22, 0x48($sp)
/* CD3E5C 8024202C D7B40040 */  ldc1      $f20, 0x40($sp)
/* CD3E60 80242030 03E00008 */  jr        $ra
/* CD3E64 80242034 27BD0050 */   addiu    $sp, $sp, 0x50
