.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802418A8_C72D28
/* C72D28 802418A8 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C72D2C 802418AC AFB20030 */  sw        $s2, 0x30($sp)
/* C72D30 802418B0 0080902D */  daddu     $s2, $a0, $zero
/* C72D34 802418B4 AFBF0038 */  sw        $ra, 0x38($sp)
/* C72D38 802418B8 AFB30034 */  sw        $s3, 0x34($sp)
/* C72D3C 802418BC AFB1002C */  sw        $s1, 0x2c($sp)
/* C72D40 802418C0 AFB00028 */  sw        $s0, 0x28($sp)
/* C72D44 802418C4 F7B60048 */  sdc1      $f22, 0x48($sp)
/* C72D48 802418C8 F7B40040 */  sdc1      $f20, 0x40($sp)
/* C72D4C 802418CC 8E510148 */  lw        $s1, 0x148($s2)
/* C72D50 802418D0 86240008 */  lh        $a0, 8($s1)
/* C72D54 802418D4 0C00EABB */  jal       get_npc_unsafe
/* C72D58 802418D8 00A0982D */   daddu    $s3, $a1, $zero
/* C72D5C 802418DC 0040802D */  daddu     $s0, $v0, $zero
/* C72D60 802418E0 0200202D */  daddu     $a0, $s0, $zero
/* C72D64 802418E4 C6220088 */  lwc1      $f2, 0x88($s1)
/* C72D68 802418E8 468010A0 */  cvt.s.w   $f2, $f2
/* C72D6C 802418EC 460010A1 */  cvt.d.s   $f2, $f2
/* C72D70 802418F0 C604001C */  lwc1      $f4, 0x1c($s0)
/* C72D74 802418F4 C6000014 */  lwc1      $f0, 0x14($s0)
/* C72D78 802418F8 8E050018 */  lw        $a1, 0x18($s0)
/* C72D7C 802418FC 46002100 */  add.s     $f4, $f4, $f0
/* C72D80 80241900 8E06000C */  lw        $a2, 0xc($s0)
/* C72D84 80241904 C6200078 */  lwc1      $f0, 0x78($s1)
/* C72D88 80241908 46800020 */  cvt.s.w   $f0, $f0
/* C72D8C 8024190C E604001C */  swc1      $f4, 0x1c($s0)
/* C72D90 80241910 3C014059 */  lui       $at, 0x4059
/* C72D94 80241914 44812800 */  mtc1      $at, $f5
/* C72D98 80241918 44802000 */  mtc1      $zero, $f4
/* C72D9C 8024191C 46000021 */  cvt.d.s   $f0, $f0
/* C72DA0 80241920 46240003 */  div.d     $f0, $f0, $f4
/* C72DA4 80241924 46200520 */  cvt.s.d   $f20, $f0
/* C72DA8 80241928 46241083 */  div.d     $f2, $f2, $f4
/* C72DAC 8024192C 0C00EA95 */  jal       npc_move_heading
/* C72DB0 80241930 462015A0 */   cvt.s.d  $f22, $f2
/* C72DB4 80241934 C604001C */  lwc1      $f4, 0x1c($s0)
/* C72DB8 80241938 44801000 */  mtc1      $zero, $f2
/* C72DBC 8024193C 44801800 */  mtc1      $zero, $f3
/* C72DC0 80241940 46002021 */  cvt.d.s   $f0, $f4
/* C72DC4 80241944 4620103E */  c.le.d    $f2, $f0
/* C72DC8 80241948 00000000 */  nop       
/* C72DCC 8024194C 45000030 */  bc1f      .L80241A10
/* C72DD0 80241950 00000000 */   nop      
/* C72DD4 80241954 C600003C */  lwc1      $f0, 0x3c($s0)
/* C72DD8 80241958 46040000 */  add.s     $f0, $f0, $f4
/* C72DDC 8024195C E600003C */  swc1      $f0, 0x3c($s0)
/* C72DE0 80241960 8E2200CC */  lw        $v0, 0xcc($s1)
/* C72DE4 80241964 8C420024 */  lw        $v0, 0x24($v0)
/* C72DE8 80241968 AE020028 */  sw        $v0, 0x28($s0)
/* C72DEC 8024196C A2200007 */  sb        $zero, 7($s1)
/* C72DF0 80241970 8E020000 */  lw        $v0, ($s0)
/* C72DF4 80241974 30420008 */  andi      $v0, $v0, 8
/* C72DF8 80241978 14400011 */  bnez      $v0, .L802419C0
/* C72DFC 8024197C 0000102D */   daddu    $v0, $zero, $zero
/* C72E00 80241980 27A50018 */  addiu     $a1, $sp, 0x18
/* C72E04 80241984 27A6001C */  addiu     $a2, $sp, 0x1c
/* C72E08 80241988 C6000038 */  lwc1      $f0, 0x38($s0)
/* C72E0C 8024198C C602003C */  lwc1      $f2, 0x3c($s0)
/* C72E10 80241990 C6040040 */  lwc1      $f4, 0x40($s0)
/* C72E14 80241994 3C01447A */  lui       $at, 0x447a
/* C72E18 80241998 44813000 */  mtc1      $at, $f6
/* C72E1C 8024199C 27A20024 */  addiu     $v0, $sp, 0x24
/* C72E20 802419A0 E7A00018 */  swc1      $f0, 0x18($sp)
/* C72E24 802419A4 E7A2001C */  swc1      $f2, 0x1c($sp)
/* C72E28 802419A8 E7A40020 */  swc1      $f4, 0x20($sp)
/* C72E2C 802419AC E7A60024 */  swc1      $f6, 0x24($sp)
/* C72E30 802419B0 AFA20010 */  sw        $v0, 0x10($sp)
/* C72E34 802419B4 8E040080 */  lw        $a0, 0x80($s0)
/* C72E38 802419B8 0C0372DF */  jal       func_800DCB7C
/* C72E3C 802419BC 27A70020 */   addiu    $a3, $sp, 0x20
.L802419C0:
/* C72E40 802419C0 1040000B */  beqz      $v0, .L802419F0
/* C72E44 802419C4 00000000 */   nop      
/* C72E48 802419C8 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* C72E4C 802419CC 46140080 */  add.s     $f2, $f0, $f20
/* C72E50 802419D0 C600003C */  lwc1      $f0, 0x3c($s0)
/* C72E54 802419D4 4600103E */  c.le.s    $f2, $f0
/* C72E58 802419D8 00000000 */  nop       
/* C72E5C 802419DC 4500008D */  bc1f      .L80241C14
/* C72E60 802419E0 00000000 */   nop      
/* C72E64 802419E4 E602003C */  swc1      $f2, 0x3c($s0)
/* C72E68 802419E8 08090705 */  j         .L80241C14
/* C72E6C 802419EC AE400070 */   sw       $zero, 0x70($s2)
.L802419F0:
/* C72E70 802419F0 C602003C */  lwc1      $f2, 0x3c($s0)
/* C72E74 802419F4 C6000064 */  lwc1      $f0, 0x64($s0)
/* C72E78 802419F8 4602003E */  c.le.s    $f0, $f2
/* C72E7C 802419FC 00000000 */  nop       
/* C72E80 80241A00 45030084 */  bc1tl     .L80241C14
/* C72E84 80241A04 AE400070 */   sw       $zero, 0x70($s2)
/* C72E88 80241A08 08090705 */  j         .L80241C14
/* C72E8C 80241A0C 00000000 */   nop      
.L80241A10:
/* C72E90 80241A10 4622003C */  c.lt.d    $f0, $f2
/* C72E94 80241A14 00000000 */  nop       
/* C72E98 80241A18 4500007E */  bc1f      .L80241C14
/* C72E9C 80241A1C 00000000 */   nop      
/* C72EA0 80241A20 9602008E */  lhu       $v0, 0x8e($s0)
/* C72EA4 80241A24 24420001 */  addiu     $v0, $v0, 1
/* C72EA8 80241A28 A602008E */  sh        $v0, 0x8e($s0)
/* C72EAC 80241A2C 00021400 */  sll       $v0, $v0, 0x10
/* C72EB0 80241A30 8E630020 */  lw        $v1, 0x20($s3)
/* C72EB4 80241A34 00021403 */  sra       $v0, $v0, 0x10
/* C72EB8 80241A38 0043102A */  slt       $v0, $v0, $v1
/* C72EBC 80241A3C 14400026 */  bnez      $v0, .L80241AD8
/* C72EC0 80241A40 00000000 */   nop      
/* C72EC4 80241A44 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C72EC8 80241A48 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C72ECC 80241A4C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C72ED0 80241A50 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C72ED4 80241A54 A600008E */  sh        $zero, 0x8e($s0)
/* C72ED8 80241A58 8C460028 */  lw        $a2, 0x28($v0)
/* C72EDC 80241A5C 0C00A720 */  jal       atan2
/* C72EE0 80241A60 8C470030 */   lw       $a3, 0x30($v0)
/* C72EE4 80241A64 46000506 */  mov.s     $f20, $f0
/* C72EE8 80241A68 C60C000C */  lwc1      $f12, 0xc($s0)
/* C72EEC 80241A6C 0C00A70A */  jal       get_clamped_angle_diff
/* C72EF0 80241A70 4600A386 */   mov.s    $f14, $f20
/* C72EF4 80241A74 46000086 */  mov.s     $f2, $f0
/* C72EF8 80241A78 8E62001C */  lw        $v0, 0x1c($s3)
/* C72EFC 80241A7C 46001005 */  abs.s     $f0, $f2
/* C72F00 80241A80 44822000 */  mtc1      $v0, $f4
/* C72F04 80241A84 00000000 */  nop       
/* C72F08 80241A88 46802120 */  cvt.s.w   $f4, $f4
/* C72F0C 80241A8C 4600203C */  c.lt.s    $f4, $f0
/* C72F10 80241A90 00000000 */  nop       
/* C72F14 80241A94 4500000D */  bc1f      .L80241ACC
/* C72F18 80241A98 00000000 */   nop      
/* C72F1C 80241A9C 44800000 */  mtc1      $zero, $f0
/* C72F20 80241AA0 C614000C */  lwc1      $f20, 0xc($s0)
/* C72F24 80241AA4 4600103C */  c.lt.s    $f2, $f0
/* C72F28 80241AA8 00000000 */  nop       
/* C72F2C 80241AAC 45000006 */  bc1f      .L80241AC8
/* C72F30 80241AB0 00021023 */   negu     $v0, $v0
/* C72F34 80241AB4 44820000 */  mtc1      $v0, $f0
/* C72F38 80241AB8 00000000 */  nop       
/* C72F3C 80241ABC 46800020 */  cvt.s.w   $f0, $f0
/* C72F40 80241AC0 080906B3 */  j         .L80241ACC
/* C72F44 80241AC4 4600A500 */   add.s    $f20, $f20, $f0
.L80241AC8:
/* C72F48 80241AC8 4604A500 */  add.s     $f20, $f20, $f4
.L80241ACC:
/* C72F4C 80241ACC 0C00A6C9 */  jal       clamp_angle
/* C72F50 80241AD0 4600A306 */   mov.s    $f12, $f20
/* C72F54 80241AD4 E600000C */  swc1      $f0, 0xc($s0)
.L80241AD8:
/* C72F58 80241AD8 8E020000 */  lw        $v0, ($s0)
/* C72F5C 80241ADC 30420008 */  andi      $v0, $v0, 8
/* C72F60 80241AE0 1040000A */  beqz      $v0, .L80241B0C
/* C72F64 80241AE4 27A50018 */   addiu    $a1, $sp, 0x18
/* C72F68 80241AE8 C602003C */  lwc1      $f2, 0x3c($s0)
/* C72F6C 80241AEC C600001C */  lwc1      $f0, 0x1c($s0)
/* C72F70 80241AF0 46001080 */  add.s     $f2, $f2, $f0
/* C72F74 80241AF4 4616103C */  c.lt.s    $f2, $f22
/* C72F78 80241AF8 00000000 */  nop       
/* C72F7C 80241AFC 45020045 */  bc1fl     .L80241C14
/* C72F80 80241B00 E602003C */   swc1     $f2, 0x3c($s0)
/* C72F84 80241B04 08090704 */  j         .L80241C10
/* C72F88 80241B08 E616003C */   swc1     $f22, 0x3c($s0)
.L80241B0C:
/* C72F8C 80241B0C C6000038 */  lwc1      $f0, 0x38($s0)
/* C72F90 80241B10 27A6001C */  addiu     $a2, $sp, 0x1c
/* C72F94 80241B14 E7A00018 */  swc1      $f0, 0x18($sp)
/* C72F98 80241B18 860200A8 */  lh        $v0, 0xa8($s0)
/* C72F9C 80241B1C C600001C */  lwc1      $f0, 0x1c($s0)
/* C72FA0 80241B20 C604003C */  lwc1      $f4, 0x3c($s0)
/* C72FA4 80241B24 44821000 */  mtc1      $v0, $f2
/* C72FA8 80241B28 00000000 */  nop       
/* C72FAC 80241B2C 468010A0 */  cvt.s.w   $f2, $f2
/* C72FB0 80241B30 46000005 */  abs.s     $f0, $f0
/* C72FB4 80241B34 46020000 */  add.s     $f0, $f0, $f2
/* C72FB8 80241B38 C6060040 */  lwc1      $f6, 0x40($s0)
/* C72FBC 80241B3C 27A20024 */  addiu     $v0, $sp, 0x24
/* C72FC0 80241B40 46022100 */  add.s     $f4, $f4, $f2
/* C72FC4 80241B44 3C014024 */  lui       $at, 0x4024
/* C72FC8 80241B48 44811800 */  mtc1      $at, $f3
/* C72FCC 80241B4C 44801000 */  mtc1      $zero, $f2
/* C72FD0 80241B50 46000021 */  cvt.d.s   $f0, $f0
/* C72FD4 80241B54 46220000 */  add.d     $f0, $f0, $f2
/* C72FD8 80241B58 E7A60020 */  swc1      $f6, 0x20($sp)
/* C72FDC 80241B5C E7A4001C */  swc1      $f4, 0x1c($sp)
/* C72FE0 80241B60 46200020 */  cvt.s.d   $f0, $f0
/* C72FE4 80241B64 E7A00024 */  swc1      $f0, 0x24($sp)
/* C72FE8 80241B68 AFA20010 */  sw        $v0, 0x10($sp)
/* C72FEC 80241B6C 8E040080 */  lw        $a0, 0x80($s0)
/* C72FF0 80241B70 0C0372DF */  jal       func_800DCB7C
/* C72FF4 80241B74 27A70020 */   addiu    $a3, $sp, 0x20
/* C72FF8 80241B78 10400015 */  beqz      $v0, .L80241BD0
/* C72FFC 80241B7C 00000000 */   nop      
/* C73000 80241B80 860200A8 */  lh        $v0, 0xa8($s0)
/* C73004 80241B84 C604001C */  lwc1      $f4, 0x1c($s0)
/* C73008 80241B88 44820000 */  mtc1      $v0, $f0
/* C7300C 80241B8C 00000000 */  nop       
/* C73010 80241B90 46800020 */  cvt.s.w   $f0, $f0
/* C73014 80241B94 46002085 */  abs.s     $f2, $f4
/* C73018 80241B98 46020000 */  add.s     $f0, $f0, $f2
/* C7301C 80241B9C C7A20024 */  lwc1      $f2, 0x24($sp)
/* C73020 80241BA0 4600103E */  c.le.s    $f2, $f0
/* C73024 80241BA4 00000000 */  nop       
/* C73028 80241BA8 45000005 */  bc1f      .L80241BC0
/* C7302C 80241BAC 00000000 */   nop      
/* C73030 80241BB0 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* C73034 80241BB4 AE00001C */  sw        $zero, 0x1c($s0)
/* C73038 80241BB8 08090705 */  j         .L80241C14
/* C7303C 80241BBC E600003C */   swc1     $f0, 0x3c($s0)
.L80241BC0:
/* C73040 80241BC0 C600003C */  lwc1      $f0, 0x3c($s0)
/* C73044 80241BC4 46040000 */  add.s     $f0, $f0, $f4
/* C73048 80241BC8 08090705 */  j         .L80241C14
/* C7304C 80241BCC E600003C */   swc1     $f0, 0x3c($s0)
.L80241BD0:
/* C73050 80241BD0 C606003C */  lwc1      $f6, 0x3c($s0)
/* C73054 80241BD4 860200A8 */  lh        $v0, 0xa8($s0)
/* C73058 80241BD8 46163081 */  sub.s     $f2, $f6, $f22
/* C7305C 80241BDC 44820000 */  mtc1      $v0, $f0
/* C73060 80241BE0 00000000 */  nop       
/* C73064 80241BE4 46800020 */  cvt.s.w   $f0, $f0
/* C73068 80241BE8 46001080 */  add.s     $f2, $f2, $f0
/* C7306C 80241BEC C604001C */  lwc1      $f4, 0x1c($s0)
/* C73070 80241BF0 46002005 */  abs.s     $f0, $f4
/* C73074 80241BF4 4602003C */  c.lt.s    $f0, $f2
/* C73078 80241BF8 00000000 */  nop       
/* C7307C 80241BFC 45020005 */  bc1fl     .L80241C14
/* C73080 80241C00 AE00001C */   sw       $zero, 0x1c($s0)
/* C73084 80241C04 46043000 */  add.s     $f0, $f6, $f4
/* C73088 80241C08 08090705 */  j         .L80241C14
/* C7308C 80241C0C E600003C */   swc1     $f0, 0x3c($s0)
.L80241C10:
/* C73090 80241C10 AE00001C */  sw        $zero, 0x1c($s0)
.L80241C14:
/* C73094 80241C14 8FBF0038 */  lw        $ra, 0x38($sp)
/* C73098 80241C18 8FB30034 */  lw        $s3, 0x34($sp)
/* C7309C 80241C1C 8FB20030 */  lw        $s2, 0x30($sp)
/* C730A0 80241C20 8FB1002C */  lw        $s1, 0x2c($sp)
/* C730A4 80241C24 8FB00028 */  lw        $s0, 0x28($sp)
/* C730A8 80241C28 D7B60048 */  ldc1      $f22, 0x48($sp)
/* C730AC 80241C2C D7B40040 */  ldc1      $f20, 0x40($sp)
/* C730B0 80241C30 03E00008 */  jr        $ra
/* C730B4 80241C34 27BD0050 */   addiu    $sp, $sp, 0x50
