.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel hos_03_UnkFunc6
/* A1CC08 80241B08 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* A1CC0C 80241B0C AFB20030 */  sw        $s2, 0x30($sp)
/* A1CC10 80241B10 0080902D */  daddu     $s2, $a0, $zero
/* A1CC14 80241B14 AFBF0038 */  sw        $ra, 0x38($sp)
/* A1CC18 80241B18 AFB30034 */  sw        $s3, 0x34($sp)
/* A1CC1C 80241B1C AFB1002C */  sw        $s1, 0x2c($sp)
/* A1CC20 80241B20 AFB00028 */  sw        $s0, 0x28($sp)
/* A1CC24 80241B24 F7B60048 */  sdc1      $f22, 0x48($sp)
/* A1CC28 80241B28 F7B40040 */  sdc1      $f20, 0x40($sp)
/* A1CC2C 80241B2C 8E510148 */  lw        $s1, 0x148($s2)
/* A1CC30 80241B30 86240008 */  lh        $a0, 8($s1)
/* A1CC34 80241B34 0C00EABB */  jal       get_npc_unsafe
/* A1CC38 80241B38 00A0982D */   daddu    $s3, $a1, $zero
/* A1CC3C 80241B3C 0040802D */  daddu     $s0, $v0, $zero
/* A1CC40 80241B40 0200202D */  daddu     $a0, $s0, $zero
/* A1CC44 80241B44 C6220088 */  lwc1      $f2, 0x88($s1)
/* A1CC48 80241B48 468010A0 */  cvt.s.w   $f2, $f2
/* A1CC4C 80241B4C 460010A1 */  cvt.d.s   $f2, $f2
/* A1CC50 80241B50 C604001C */  lwc1      $f4, 0x1c($s0)
/* A1CC54 80241B54 C6000014 */  lwc1      $f0, 0x14($s0)
/* A1CC58 80241B58 8E050018 */  lw        $a1, 0x18($s0)
/* A1CC5C 80241B5C 46002100 */  add.s     $f4, $f4, $f0
/* A1CC60 80241B60 8E06000C */  lw        $a2, 0xc($s0)
/* A1CC64 80241B64 C6200078 */  lwc1      $f0, 0x78($s1)
/* A1CC68 80241B68 46800020 */  cvt.s.w   $f0, $f0
/* A1CC6C 80241B6C E604001C */  swc1      $f4, 0x1c($s0)
/* A1CC70 80241B70 3C014059 */  lui       $at, 0x4059
/* A1CC74 80241B74 44812800 */  mtc1      $at, $f5
/* A1CC78 80241B78 44802000 */  mtc1      $zero, $f4
/* A1CC7C 80241B7C 46000021 */  cvt.d.s   $f0, $f0
/* A1CC80 80241B80 46240003 */  div.d     $f0, $f0, $f4
/* A1CC84 80241B84 46200520 */  cvt.s.d   $f20, $f0
/* A1CC88 80241B88 46241083 */  div.d     $f2, $f2, $f4
/* A1CC8C 80241B8C 0C00EA95 */  jal       npc_move_heading
/* A1CC90 80241B90 462015A0 */   cvt.s.d  $f22, $f2
/* A1CC94 80241B94 C604001C */  lwc1      $f4, 0x1c($s0)
/* A1CC98 80241B98 44801000 */  mtc1      $zero, $f2
/* A1CC9C 80241B9C 44801800 */  mtc1      $zero, $f3
/* A1CCA0 80241BA0 46002021 */  cvt.d.s   $f0, $f4
/* A1CCA4 80241BA4 4620103E */  c.le.d    $f2, $f0
/* A1CCA8 80241BA8 00000000 */  nop
/* A1CCAC 80241BAC 45000030 */  bc1f      .L80241C70
/* A1CCB0 80241BB0 00000000 */   nop
/* A1CCB4 80241BB4 C600003C */  lwc1      $f0, 0x3c($s0)
/* A1CCB8 80241BB8 46040000 */  add.s     $f0, $f0, $f4
/* A1CCBC 80241BBC E600003C */  swc1      $f0, 0x3c($s0)
/* A1CCC0 80241BC0 8E2200CC */  lw        $v0, 0xcc($s1)
/* A1CCC4 80241BC4 8C420024 */  lw        $v0, 0x24($v0)
/* A1CCC8 80241BC8 AE020028 */  sw        $v0, 0x28($s0)
/* A1CCCC 80241BCC A2200007 */  sb        $zero, 7($s1)
/* A1CCD0 80241BD0 8E020000 */  lw        $v0, ($s0)
/* A1CCD4 80241BD4 30420008 */  andi      $v0, $v0, 8
/* A1CCD8 80241BD8 14400011 */  bnez      $v0, .L80241C20
/* A1CCDC 80241BDC 0000102D */   daddu    $v0, $zero, $zero
/* A1CCE0 80241BE0 27A50018 */  addiu     $a1, $sp, 0x18
/* A1CCE4 80241BE4 27A6001C */  addiu     $a2, $sp, 0x1c
/* A1CCE8 80241BE8 C6000038 */  lwc1      $f0, 0x38($s0)
/* A1CCEC 80241BEC C602003C */  lwc1      $f2, 0x3c($s0)
/* A1CCF0 80241BF0 C6040040 */  lwc1      $f4, 0x40($s0)
/* A1CCF4 80241BF4 3C01447A */  lui       $at, 0x447a
/* A1CCF8 80241BF8 44813000 */  mtc1      $at, $f6
/* A1CCFC 80241BFC 27A20024 */  addiu     $v0, $sp, 0x24
/* A1CD00 80241C00 E7A00018 */  swc1      $f0, 0x18($sp)
/* A1CD04 80241C04 E7A2001C */  swc1      $f2, 0x1c($sp)
/* A1CD08 80241C08 E7A40020 */  swc1      $f4, 0x20($sp)
/* A1CD0C 80241C0C E7A60024 */  swc1      $f6, 0x24($sp)
/* A1CD10 80241C10 AFA20010 */  sw        $v0, 0x10($sp)
/* A1CD14 80241C14 8E040080 */  lw        $a0, 0x80($s0)
/* A1CD18 80241C18 0C0372DF */  jal       func_800DCB7C
/* A1CD1C 80241C1C 27A70020 */   addiu    $a3, $sp, 0x20
.L80241C20:
/* A1CD20 80241C20 1040000B */  beqz      $v0, .L80241C50
/* A1CD24 80241C24 00000000 */   nop
/* A1CD28 80241C28 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* A1CD2C 80241C2C 46140080 */  add.s     $f2, $f0, $f20
/* A1CD30 80241C30 C600003C */  lwc1      $f0, 0x3c($s0)
/* A1CD34 80241C34 4600103E */  c.le.s    $f2, $f0
/* A1CD38 80241C38 00000000 */  nop
/* A1CD3C 80241C3C 4500008D */  bc1f      .L80241E74
/* A1CD40 80241C40 00000000 */   nop
/* A1CD44 80241C44 E602003C */  swc1      $f2, 0x3c($s0)
/* A1CD48 80241C48 0809079D */  j         .L80241E74
/* A1CD4C 80241C4C AE400070 */   sw       $zero, 0x70($s2)
.L80241C50:
/* A1CD50 80241C50 C602003C */  lwc1      $f2, 0x3c($s0)
/* A1CD54 80241C54 C6000064 */  lwc1      $f0, 0x64($s0)
/* A1CD58 80241C58 4602003E */  c.le.s    $f0, $f2
/* A1CD5C 80241C5C 00000000 */  nop
/* A1CD60 80241C60 45030084 */  bc1tl     .L80241E74
/* A1CD64 80241C64 AE400070 */   sw       $zero, 0x70($s2)
/* A1CD68 80241C68 0809079D */  j         .L80241E74
/* A1CD6C 80241C6C 00000000 */   nop
.L80241C70:
/* A1CD70 80241C70 4622003C */  c.lt.d    $f0, $f2
/* A1CD74 80241C74 00000000 */  nop
/* A1CD78 80241C78 4500007E */  bc1f      .L80241E74
/* A1CD7C 80241C7C 00000000 */   nop
/* A1CD80 80241C80 9602008E */  lhu       $v0, 0x8e($s0)
/* A1CD84 80241C84 24420001 */  addiu     $v0, $v0, 1
/* A1CD88 80241C88 A602008E */  sh        $v0, 0x8e($s0)
/* A1CD8C 80241C8C 00021400 */  sll       $v0, $v0, 0x10
/* A1CD90 80241C90 8E630020 */  lw        $v1, 0x20($s3)
/* A1CD94 80241C94 00021403 */  sra       $v0, $v0, 0x10
/* A1CD98 80241C98 0043102A */  slt       $v0, $v0, $v1
/* A1CD9C 80241C9C 14400026 */  bnez      $v0, .L80241D38
/* A1CDA0 80241CA0 00000000 */   nop
/* A1CDA4 80241CA4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A1CDA8 80241CA8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A1CDAC 80241CAC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A1CDB0 80241CB0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A1CDB4 80241CB4 A600008E */  sh        $zero, 0x8e($s0)
/* A1CDB8 80241CB8 8C460028 */  lw        $a2, 0x28($v0)
/* A1CDBC 80241CBC 0C00A720 */  jal       atan2
/* A1CDC0 80241CC0 8C470030 */   lw       $a3, 0x30($v0)
/* A1CDC4 80241CC4 46000506 */  mov.s     $f20, $f0
/* A1CDC8 80241CC8 C60C000C */  lwc1      $f12, 0xc($s0)
/* A1CDCC 80241CCC 0C00A70A */  jal       get_clamped_angle_diff
/* A1CDD0 80241CD0 4600A386 */   mov.s    $f14, $f20
/* A1CDD4 80241CD4 46000086 */  mov.s     $f2, $f0
/* A1CDD8 80241CD8 8E62001C */  lw        $v0, 0x1c($s3)
/* A1CDDC 80241CDC 46001005 */  abs.s     $f0, $f2
/* A1CDE0 80241CE0 44822000 */  mtc1      $v0, $f4
/* A1CDE4 80241CE4 00000000 */  nop
/* A1CDE8 80241CE8 46802120 */  cvt.s.w   $f4, $f4
/* A1CDEC 80241CEC 4600203C */  c.lt.s    $f4, $f0
/* A1CDF0 80241CF0 00000000 */  nop
/* A1CDF4 80241CF4 4500000D */  bc1f      .L80241D2C
/* A1CDF8 80241CF8 00000000 */   nop
/* A1CDFC 80241CFC 44800000 */  mtc1      $zero, $f0
/* A1CE00 80241D00 C614000C */  lwc1      $f20, 0xc($s0)
/* A1CE04 80241D04 4600103C */  c.lt.s    $f2, $f0
/* A1CE08 80241D08 00000000 */  nop
/* A1CE0C 80241D0C 45000006 */  bc1f      .L80241D28
/* A1CE10 80241D10 00021023 */   negu     $v0, $v0
/* A1CE14 80241D14 44820000 */  mtc1      $v0, $f0
/* A1CE18 80241D18 00000000 */  nop
/* A1CE1C 80241D1C 46800020 */  cvt.s.w   $f0, $f0
/* A1CE20 80241D20 0809074B */  j         .L80241D2C
/* A1CE24 80241D24 4600A500 */   add.s    $f20, $f20, $f0
.L80241D28:
/* A1CE28 80241D28 4604A500 */  add.s     $f20, $f20, $f4
.L80241D2C:
/* A1CE2C 80241D2C 0C00A6C9 */  jal       clamp_angle
/* A1CE30 80241D30 4600A306 */   mov.s    $f12, $f20
/* A1CE34 80241D34 E600000C */  swc1      $f0, 0xc($s0)
.L80241D38:
/* A1CE38 80241D38 8E020000 */  lw        $v0, ($s0)
/* A1CE3C 80241D3C 30420008 */  andi      $v0, $v0, 8
/* A1CE40 80241D40 1040000A */  beqz      $v0, .L80241D6C
/* A1CE44 80241D44 27A50018 */   addiu    $a1, $sp, 0x18
/* A1CE48 80241D48 C602003C */  lwc1      $f2, 0x3c($s0)
/* A1CE4C 80241D4C C600001C */  lwc1      $f0, 0x1c($s0)
/* A1CE50 80241D50 46001080 */  add.s     $f2, $f2, $f0
/* A1CE54 80241D54 4616103C */  c.lt.s    $f2, $f22
/* A1CE58 80241D58 00000000 */  nop
/* A1CE5C 80241D5C 45020045 */  bc1fl     .L80241E74
/* A1CE60 80241D60 E602003C */   swc1     $f2, 0x3c($s0)
/* A1CE64 80241D64 0809079C */  j         .L80241E70
/* A1CE68 80241D68 E616003C */   swc1     $f22, 0x3c($s0)
.L80241D6C:
/* A1CE6C 80241D6C C6000038 */  lwc1      $f0, 0x38($s0)
/* A1CE70 80241D70 27A6001C */  addiu     $a2, $sp, 0x1c
/* A1CE74 80241D74 E7A00018 */  swc1      $f0, 0x18($sp)
/* A1CE78 80241D78 860200A8 */  lh        $v0, 0xa8($s0)
/* A1CE7C 80241D7C C600001C */  lwc1      $f0, 0x1c($s0)
/* A1CE80 80241D80 C604003C */  lwc1      $f4, 0x3c($s0)
/* A1CE84 80241D84 44821000 */  mtc1      $v0, $f2
/* A1CE88 80241D88 00000000 */  nop
/* A1CE8C 80241D8C 468010A0 */  cvt.s.w   $f2, $f2
/* A1CE90 80241D90 46000005 */  abs.s     $f0, $f0
/* A1CE94 80241D94 46020000 */  add.s     $f0, $f0, $f2
/* A1CE98 80241D98 C6060040 */  lwc1      $f6, 0x40($s0)
/* A1CE9C 80241D9C 27A20024 */  addiu     $v0, $sp, 0x24
/* A1CEA0 80241DA0 46022100 */  add.s     $f4, $f4, $f2
/* A1CEA4 80241DA4 3C014024 */  lui       $at, 0x4024
/* A1CEA8 80241DA8 44811800 */  mtc1      $at, $f3
/* A1CEAC 80241DAC 44801000 */  mtc1      $zero, $f2
/* A1CEB0 80241DB0 46000021 */  cvt.d.s   $f0, $f0
/* A1CEB4 80241DB4 46220000 */  add.d     $f0, $f0, $f2
/* A1CEB8 80241DB8 E7A60020 */  swc1      $f6, 0x20($sp)
/* A1CEBC 80241DBC E7A4001C */  swc1      $f4, 0x1c($sp)
/* A1CEC0 80241DC0 46200020 */  cvt.s.d   $f0, $f0
/* A1CEC4 80241DC4 E7A00024 */  swc1      $f0, 0x24($sp)
/* A1CEC8 80241DC8 AFA20010 */  sw        $v0, 0x10($sp)
/* A1CECC 80241DCC 8E040080 */  lw        $a0, 0x80($s0)
/* A1CED0 80241DD0 0C0372DF */  jal       func_800DCB7C
/* A1CED4 80241DD4 27A70020 */   addiu    $a3, $sp, 0x20
/* A1CED8 80241DD8 10400015 */  beqz      $v0, .L80241E30
/* A1CEDC 80241DDC 00000000 */   nop
/* A1CEE0 80241DE0 860200A8 */  lh        $v0, 0xa8($s0)
/* A1CEE4 80241DE4 C604001C */  lwc1      $f4, 0x1c($s0)
/* A1CEE8 80241DE8 44820000 */  mtc1      $v0, $f0
/* A1CEEC 80241DEC 00000000 */  nop
/* A1CEF0 80241DF0 46800020 */  cvt.s.w   $f0, $f0
/* A1CEF4 80241DF4 46002085 */  abs.s     $f2, $f4
/* A1CEF8 80241DF8 46020000 */  add.s     $f0, $f0, $f2
/* A1CEFC 80241DFC C7A20024 */  lwc1      $f2, 0x24($sp)
/* A1CF00 80241E00 4600103E */  c.le.s    $f2, $f0
/* A1CF04 80241E04 00000000 */  nop
/* A1CF08 80241E08 45000005 */  bc1f      .L80241E20
/* A1CF0C 80241E0C 00000000 */   nop
/* A1CF10 80241E10 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* A1CF14 80241E14 AE00001C */  sw        $zero, 0x1c($s0)
/* A1CF18 80241E18 0809079D */  j         .L80241E74
/* A1CF1C 80241E1C E600003C */   swc1     $f0, 0x3c($s0)
.L80241E20:
/* A1CF20 80241E20 C600003C */  lwc1      $f0, 0x3c($s0)
/* A1CF24 80241E24 46040000 */  add.s     $f0, $f0, $f4
/* A1CF28 80241E28 0809079D */  j         .L80241E74
/* A1CF2C 80241E2C E600003C */   swc1     $f0, 0x3c($s0)
.L80241E30:
/* A1CF30 80241E30 C606003C */  lwc1      $f6, 0x3c($s0)
/* A1CF34 80241E34 860200A8 */  lh        $v0, 0xa8($s0)
/* A1CF38 80241E38 46163081 */  sub.s     $f2, $f6, $f22
/* A1CF3C 80241E3C 44820000 */  mtc1      $v0, $f0
/* A1CF40 80241E40 00000000 */  nop
/* A1CF44 80241E44 46800020 */  cvt.s.w   $f0, $f0
/* A1CF48 80241E48 46001080 */  add.s     $f2, $f2, $f0
/* A1CF4C 80241E4C C604001C */  lwc1      $f4, 0x1c($s0)
/* A1CF50 80241E50 46002005 */  abs.s     $f0, $f4
/* A1CF54 80241E54 4602003C */  c.lt.s    $f0, $f2
/* A1CF58 80241E58 00000000 */  nop
/* A1CF5C 80241E5C 45020005 */  bc1fl     .L80241E74
/* A1CF60 80241E60 AE00001C */   sw       $zero, 0x1c($s0)
/* A1CF64 80241E64 46043000 */  add.s     $f0, $f6, $f4
/* A1CF68 80241E68 0809079D */  j         .L80241E74
/* A1CF6C 80241E6C E600003C */   swc1     $f0, 0x3c($s0)
.L80241E70:
/* A1CF70 80241E70 AE00001C */  sw        $zero, 0x1c($s0)
.L80241E74:
/* A1CF74 80241E74 8FBF0038 */  lw        $ra, 0x38($sp)
/* A1CF78 80241E78 8FB30034 */  lw        $s3, 0x34($sp)
/* A1CF7C 80241E7C 8FB20030 */  lw        $s2, 0x30($sp)
/* A1CF80 80241E80 8FB1002C */  lw        $s1, 0x2c($sp)
/* A1CF84 80241E84 8FB00028 */  lw        $s0, 0x28($sp)
/* A1CF88 80241E88 D7B60048 */  ldc1      $f22, 0x48($sp)
/* A1CF8C 80241E8C D7B40040 */  ldc1      $f20, 0x40($sp)
/* A1CF90 80241E90 03E00008 */  jr        $ra
/* A1CF94 80241E94 27BD0050 */   addiu    $sp, $sp, 0x50
