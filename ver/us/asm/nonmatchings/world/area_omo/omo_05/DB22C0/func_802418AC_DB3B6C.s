.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802418AC_DB3B6C
/* DB3B6C 802418AC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* DB3B70 802418B0 AFB20030 */  sw        $s2, 0x30($sp)
/* DB3B74 802418B4 0080902D */  daddu     $s2, $a0, $zero
/* DB3B78 802418B8 AFBF0038 */  sw        $ra, 0x38($sp)
/* DB3B7C 802418BC AFB30034 */  sw        $s3, 0x34($sp)
/* DB3B80 802418C0 AFB1002C */  sw        $s1, 0x2c($sp)
/* DB3B84 802418C4 AFB00028 */  sw        $s0, 0x28($sp)
/* DB3B88 802418C8 F7B60048 */  sdc1      $f22, 0x48($sp)
/* DB3B8C 802418CC F7B40040 */  sdc1      $f20, 0x40($sp)
/* DB3B90 802418D0 8E510148 */  lw        $s1, 0x148($s2)
/* DB3B94 802418D4 86240008 */  lh        $a0, 8($s1)
/* DB3B98 802418D8 0C00EABB */  jal       get_npc_unsafe
/* DB3B9C 802418DC 00A0982D */   daddu    $s3, $a1, $zero
/* DB3BA0 802418E0 0040802D */  daddu     $s0, $v0, $zero
/* DB3BA4 802418E4 0200202D */  daddu     $a0, $s0, $zero
/* DB3BA8 802418E8 C6220088 */  lwc1      $f2, 0x88($s1)
/* DB3BAC 802418EC 468010A0 */  cvt.s.w   $f2, $f2
/* DB3BB0 802418F0 460010A1 */  cvt.d.s   $f2, $f2
/* DB3BB4 802418F4 C604001C */  lwc1      $f4, 0x1c($s0)
/* DB3BB8 802418F8 C6000014 */  lwc1      $f0, 0x14($s0)
/* DB3BBC 802418FC 8E050018 */  lw        $a1, 0x18($s0)
/* DB3BC0 80241900 46002100 */  add.s     $f4, $f4, $f0
/* DB3BC4 80241904 8E06000C */  lw        $a2, 0xc($s0)
/* DB3BC8 80241908 C6200078 */  lwc1      $f0, 0x78($s1)
/* DB3BCC 8024190C 46800020 */  cvt.s.w   $f0, $f0
/* DB3BD0 80241910 E604001C */  swc1      $f4, 0x1c($s0)
/* DB3BD4 80241914 3C014059 */  lui       $at, 0x4059
/* DB3BD8 80241918 44812800 */  mtc1      $at, $f5
/* DB3BDC 8024191C 44802000 */  mtc1      $zero, $f4
/* DB3BE0 80241920 46000021 */  cvt.d.s   $f0, $f0
/* DB3BE4 80241924 46240003 */  div.d     $f0, $f0, $f4
/* DB3BE8 80241928 46200520 */  cvt.s.d   $f20, $f0
/* DB3BEC 8024192C 46241083 */  div.d     $f2, $f2, $f4
/* DB3BF0 80241930 0C00EA95 */  jal       npc_move_heading
/* DB3BF4 80241934 462015A0 */   cvt.s.d  $f22, $f2
/* DB3BF8 80241938 C604001C */  lwc1      $f4, 0x1c($s0)
/* DB3BFC 8024193C 44801000 */  mtc1      $zero, $f2
/* DB3C00 80241940 44801800 */  mtc1      $zero, $f3
/* DB3C04 80241944 46002021 */  cvt.d.s   $f0, $f4
/* DB3C08 80241948 4620103E */  c.le.d    $f2, $f0
/* DB3C0C 8024194C 00000000 */  nop
/* DB3C10 80241950 45000030 */  bc1f      .L80241A14
/* DB3C14 80241954 00000000 */   nop
/* DB3C18 80241958 C600003C */  lwc1      $f0, 0x3c($s0)
/* DB3C1C 8024195C 46040000 */  add.s     $f0, $f0, $f4
/* DB3C20 80241960 E600003C */  swc1      $f0, 0x3c($s0)
/* DB3C24 80241964 8E2200CC */  lw        $v0, 0xcc($s1)
/* DB3C28 80241968 8C420024 */  lw        $v0, 0x24($v0)
/* DB3C2C 8024196C AE020028 */  sw        $v0, 0x28($s0)
/* DB3C30 80241970 A2200007 */  sb        $zero, 7($s1)
/* DB3C34 80241974 8E020000 */  lw        $v0, ($s0)
/* DB3C38 80241978 30420008 */  andi      $v0, $v0, 8
/* DB3C3C 8024197C 14400011 */  bnez      $v0, .L802419C4
/* DB3C40 80241980 0000102D */   daddu    $v0, $zero, $zero
/* DB3C44 80241984 27A50018 */  addiu     $a1, $sp, 0x18
/* DB3C48 80241988 27A6001C */  addiu     $a2, $sp, 0x1c
/* DB3C4C 8024198C C6000038 */  lwc1      $f0, 0x38($s0)
/* DB3C50 80241990 C602003C */  lwc1      $f2, 0x3c($s0)
/* DB3C54 80241994 C6040040 */  lwc1      $f4, 0x40($s0)
/* DB3C58 80241998 3C01447A */  lui       $at, 0x447a
/* DB3C5C 8024199C 44813000 */  mtc1      $at, $f6
/* DB3C60 802419A0 27A20024 */  addiu     $v0, $sp, 0x24
/* DB3C64 802419A4 E7A00018 */  swc1      $f0, 0x18($sp)
/* DB3C68 802419A8 E7A2001C */  swc1      $f2, 0x1c($sp)
/* DB3C6C 802419AC E7A40020 */  swc1      $f4, 0x20($sp)
/* DB3C70 802419B0 E7A60024 */  swc1      $f6, 0x24($sp)
/* DB3C74 802419B4 AFA20010 */  sw        $v0, 0x10($sp)
/* DB3C78 802419B8 8E040080 */  lw        $a0, 0x80($s0)
/* DB3C7C 802419BC 0C0372DF */  jal       func_800DCB7C
/* DB3C80 802419C0 27A70020 */   addiu    $a3, $sp, 0x20
.L802419C4:
/* DB3C84 802419C4 1040000B */  beqz      $v0, .L802419F4
/* DB3C88 802419C8 00000000 */   nop
/* DB3C8C 802419CC C7A0001C */  lwc1      $f0, 0x1c($sp)
/* DB3C90 802419D0 46140080 */  add.s     $f2, $f0, $f20
/* DB3C94 802419D4 C600003C */  lwc1      $f0, 0x3c($s0)
/* DB3C98 802419D8 4600103E */  c.le.s    $f2, $f0
/* DB3C9C 802419DC 00000000 */  nop
/* DB3CA0 802419E0 4500008D */  bc1f      .L80241C18
/* DB3CA4 802419E4 00000000 */   nop
/* DB3CA8 802419E8 E602003C */  swc1      $f2, 0x3c($s0)
/* DB3CAC 802419EC 08090706 */  j         .L80241C18
/* DB3CB0 802419F0 AE400070 */   sw       $zero, 0x70($s2)
.L802419F4:
/* DB3CB4 802419F4 C602003C */  lwc1      $f2, 0x3c($s0)
/* DB3CB8 802419F8 C6000064 */  lwc1      $f0, 0x64($s0)
/* DB3CBC 802419FC 4602003E */  c.le.s    $f0, $f2
/* DB3CC0 80241A00 00000000 */  nop
/* DB3CC4 80241A04 45030084 */  bc1tl     .L80241C18
/* DB3CC8 80241A08 AE400070 */   sw       $zero, 0x70($s2)
/* DB3CCC 80241A0C 08090706 */  j         .L80241C18
/* DB3CD0 80241A10 00000000 */   nop
.L80241A14:
/* DB3CD4 80241A14 4622003C */  c.lt.d    $f0, $f2
/* DB3CD8 80241A18 00000000 */  nop
/* DB3CDC 80241A1C 4500007E */  bc1f      .L80241C18
/* DB3CE0 80241A20 00000000 */   nop
/* DB3CE4 80241A24 9602008E */  lhu       $v0, 0x8e($s0)
/* DB3CE8 80241A28 24420001 */  addiu     $v0, $v0, 1
/* DB3CEC 80241A2C A602008E */  sh        $v0, 0x8e($s0)
/* DB3CF0 80241A30 00021400 */  sll       $v0, $v0, 0x10
/* DB3CF4 80241A34 8E630020 */  lw        $v1, 0x20($s3)
/* DB3CF8 80241A38 00021403 */  sra       $v0, $v0, 0x10
/* DB3CFC 80241A3C 0043102A */  slt       $v0, $v0, $v1
/* DB3D00 80241A40 14400026 */  bnez      $v0, .L80241ADC
/* DB3D04 80241A44 00000000 */   nop
/* DB3D08 80241A48 C60C0038 */  lwc1      $f12, 0x38($s0)
/* DB3D0C 80241A4C C60E0040 */  lwc1      $f14, 0x40($s0)
/* DB3D10 80241A50 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* DB3D14 80241A54 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* DB3D18 80241A58 A600008E */  sh        $zero, 0x8e($s0)
/* DB3D1C 80241A5C 8C460028 */  lw        $a2, 0x28($v0)
/* DB3D20 80241A60 0C00A720 */  jal       atan2
/* DB3D24 80241A64 8C470030 */   lw       $a3, 0x30($v0)
/* DB3D28 80241A68 46000506 */  mov.s     $f20, $f0
/* DB3D2C 80241A6C C60C000C */  lwc1      $f12, 0xc($s0)
/* DB3D30 80241A70 0C00A70A */  jal       get_clamped_angle_diff
/* DB3D34 80241A74 4600A386 */   mov.s    $f14, $f20
/* DB3D38 80241A78 46000086 */  mov.s     $f2, $f0
/* DB3D3C 80241A7C 8E62001C */  lw        $v0, 0x1c($s3)
/* DB3D40 80241A80 46001005 */  abs.s     $f0, $f2
/* DB3D44 80241A84 44822000 */  mtc1      $v0, $f4
/* DB3D48 80241A88 00000000 */  nop
/* DB3D4C 80241A8C 46802120 */  cvt.s.w   $f4, $f4
/* DB3D50 80241A90 4600203C */  c.lt.s    $f4, $f0
/* DB3D54 80241A94 00000000 */  nop
/* DB3D58 80241A98 4500000D */  bc1f      .L80241AD0
/* DB3D5C 80241A9C 00000000 */   nop
/* DB3D60 80241AA0 44800000 */  mtc1      $zero, $f0
/* DB3D64 80241AA4 C614000C */  lwc1      $f20, 0xc($s0)
/* DB3D68 80241AA8 4600103C */  c.lt.s    $f2, $f0
/* DB3D6C 80241AAC 00000000 */  nop
/* DB3D70 80241AB0 45000006 */  bc1f      .L80241ACC
/* DB3D74 80241AB4 00021023 */   negu     $v0, $v0
/* DB3D78 80241AB8 44820000 */  mtc1      $v0, $f0
/* DB3D7C 80241ABC 00000000 */  nop
/* DB3D80 80241AC0 46800020 */  cvt.s.w   $f0, $f0
/* DB3D84 80241AC4 080906B4 */  j         .L80241AD0
/* DB3D88 80241AC8 4600A500 */   add.s    $f20, $f20, $f0
.L80241ACC:
/* DB3D8C 80241ACC 4604A500 */  add.s     $f20, $f20, $f4
.L80241AD0:
/* DB3D90 80241AD0 0C00A6C9 */  jal       clamp_angle
/* DB3D94 80241AD4 4600A306 */   mov.s    $f12, $f20
/* DB3D98 80241AD8 E600000C */  swc1      $f0, 0xc($s0)
.L80241ADC:
/* DB3D9C 80241ADC 8E020000 */  lw        $v0, ($s0)
/* DB3DA0 80241AE0 30420008 */  andi      $v0, $v0, 8
/* DB3DA4 80241AE4 1040000A */  beqz      $v0, .L80241B10
/* DB3DA8 80241AE8 27A50018 */   addiu    $a1, $sp, 0x18
/* DB3DAC 80241AEC C602003C */  lwc1      $f2, 0x3c($s0)
/* DB3DB0 80241AF0 C600001C */  lwc1      $f0, 0x1c($s0)
/* DB3DB4 80241AF4 46001080 */  add.s     $f2, $f2, $f0
/* DB3DB8 80241AF8 4616103C */  c.lt.s    $f2, $f22
/* DB3DBC 80241AFC 00000000 */  nop
/* DB3DC0 80241B00 45020045 */  bc1fl     .L80241C18
/* DB3DC4 80241B04 E602003C */   swc1     $f2, 0x3c($s0)
/* DB3DC8 80241B08 08090705 */  j         .L80241C14
/* DB3DCC 80241B0C E616003C */   swc1     $f22, 0x3c($s0)
.L80241B10:
/* DB3DD0 80241B10 C6000038 */  lwc1      $f0, 0x38($s0)
/* DB3DD4 80241B14 27A6001C */  addiu     $a2, $sp, 0x1c
/* DB3DD8 80241B18 E7A00018 */  swc1      $f0, 0x18($sp)
/* DB3DDC 80241B1C 860200A8 */  lh        $v0, 0xa8($s0)
/* DB3DE0 80241B20 C600001C */  lwc1      $f0, 0x1c($s0)
/* DB3DE4 80241B24 C604003C */  lwc1      $f4, 0x3c($s0)
/* DB3DE8 80241B28 44821000 */  mtc1      $v0, $f2
/* DB3DEC 80241B2C 00000000 */  nop
/* DB3DF0 80241B30 468010A0 */  cvt.s.w   $f2, $f2
/* DB3DF4 80241B34 46000005 */  abs.s     $f0, $f0
/* DB3DF8 80241B38 46020000 */  add.s     $f0, $f0, $f2
/* DB3DFC 80241B3C C6060040 */  lwc1      $f6, 0x40($s0)
/* DB3E00 80241B40 27A20024 */  addiu     $v0, $sp, 0x24
/* DB3E04 80241B44 46022100 */  add.s     $f4, $f4, $f2
/* DB3E08 80241B48 3C014024 */  lui       $at, 0x4024
/* DB3E0C 80241B4C 44811800 */  mtc1      $at, $f3
/* DB3E10 80241B50 44801000 */  mtc1      $zero, $f2
/* DB3E14 80241B54 46000021 */  cvt.d.s   $f0, $f0
/* DB3E18 80241B58 46220000 */  add.d     $f0, $f0, $f2
/* DB3E1C 80241B5C E7A60020 */  swc1      $f6, 0x20($sp)
/* DB3E20 80241B60 E7A4001C */  swc1      $f4, 0x1c($sp)
/* DB3E24 80241B64 46200020 */  cvt.s.d   $f0, $f0
/* DB3E28 80241B68 E7A00024 */  swc1      $f0, 0x24($sp)
/* DB3E2C 80241B6C AFA20010 */  sw        $v0, 0x10($sp)
/* DB3E30 80241B70 8E040080 */  lw        $a0, 0x80($s0)
/* DB3E34 80241B74 0C0372DF */  jal       func_800DCB7C
/* DB3E38 80241B78 27A70020 */   addiu    $a3, $sp, 0x20
/* DB3E3C 80241B7C 10400015 */  beqz      $v0, .L80241BD4
/* DB3E40 80241B80 00000000 */   nop
/* DB3E44 80241B84 860200A8 */  lh        $v0, 0xa8($s0)
/* DB3E48 80241B88 C604001C */  lwc1      $f4, 0x1c($s0)
/* DB3E4C 80241B8C 44820000 */  mtc1      $v0, $f0
/* DB3E50 80241B90 00000000 */  nop
/* DB3E54 80241B94 46800020 */  cvt.s.w   $f0, $f0
/* DB3E58 80241B98 46002085 */  abs.s     $f2, $f4
/* DB3E5C 80241B9C 46020000 */  add.s     $f0, $f0, $f2
/* DB3E60 80241BA0 C7A20024 */  lwc1      $f2, 0x24($sp)
/* DB3E64 80241BA4 4600103E */  c.le.s    $f2, $f0
/* DB3E68 80241BA8 00000000 */  nop
/* DB3E6C 80241BAC 45000005 */  bc1f      .L80241BC4
/* DB3E70 80241BB0 00000000 */   nop
/* DB3E74 80241BB4 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* DB3E78 80241BB8 AE00001C */  sw        $zero, 0x1c($s0)
/* DB3E7C 80241BBC 08090706 */  j         .L80241C18
/* DB3E80 80241BC0 E600003C */   swc1     $f0, 0x3c($s0)
.L80241BC4:
/* DB3E84 80241BC4 C600003C */  lwc1      $f0, 0x3c($s0)
/* DB3E88 80241BC8 46040000 */  add.s     $f0, $f0, $f4
/* DB3E8C 80241BCC 08090706 */  j         .L80241C18
/* DB3E90 80241BD0 E600003C */   swc1     $f0, 0x3c($s0)
.L80241BD4:
/* DB3E94 80241BD4 C606003C */  lwc1      $f6, 0x3c($s0)
/* DB3E98 80241BD8 860200A8 */  lh        $v0, 0xa8($s0)
/* DB3E9C 80241BDC 46163081 */  sub.s     $f2, $f6, $f22
/* DB3EA0 80241BE0 44820000 */  mtc1      $v0, $f0
/* DB3EA4 80241BE4 00000000 */  nop
/* DB3EA8 80241BE8 46800020 */  cvt.s.w   $f0, $f0
/* DB3EAC 80241BEC 46001080 */  add.s     $f2, $f2, $f0
/* DB3EB0 80241BF0 C604001C */  lwc1      $f4, 0x1c($s0)
/* DB3EB4 80241BF4 46002005 */  abs.s     $f0, $f4
/* DB3EB8 80241BF8 4602003C */  c.lt.s    $f0, $f2
/* DB3EBC 80241BFC 00000000 */  nop
/* DB3EC0 80241C00 45020005 */  bc1fl     .L80241C18
/* DB3EC4 80241C04 AE00001C */   sw       $zero, 0x1c($s0)
/* DB3EC8 80241C08 46043000 */  add.s     $f0, $f6, $f4
/* DB3ECC 80241C0C 08090706 */  j         .L80241C18
/* DB3ED0 80241C10 E600003C */   swc1     $f0, 0x3c($s0)
.L80241C14:
/* DB3ED4 80241C14 AE00001C */  sw        $zero, 0x1c($s0)
.L80241C18:
/* DB3ED8 80241C18 8FBF0038 */  lw        $ra, 0x38($sp)
/* DB3EDC 80241C1C 8FB30034 */  lw        $s3, 0x34($sp)
/* DB3EE0 80241C20 8FB20030 */  lw        $s2, 0x30($sp)
/* DB3EE4 80241C24 8FB1002C */  lw        $s1, 0x2c($sp)
/* DB3EE8 80241C28 8FB00028 */  lw        $s0, 0x28($sp)
/* DB3EEC 80241C2C D7B60048 */  ldc1      $f22, 0x48($sp)
/* DB3EF0 80241C30 D7B40040 */  ldc1      $f20, 0x40($sp)
/* DB3EF4 80241C34 03E00008 */  jr        $ra
/* DB3EF8 80241C38 27BD0050 */   addiu    $sp, $sp, 0x50
