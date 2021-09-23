.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024101C_EDF9DC
/* EDF9DC 8024101C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* EDF9E0 80241020 AFB20030 */  sw        $s2, 0x30($sp)
/* EDF9E4 80241024 0080902D */  daddu     $s2, $a0, $zero
/* EDF9E8 80241028 AFBF0038 */  sw        $ra, 0x38($sp)
/* EDF9EC 8024102C AFB30034 */  sw        $s3, 0x34($sp)
/* EDF9F0 80241030 AFB1002C */  sw        $s1, 0x2c($sp)
/* EDF9F4 80241034 AFB00028 */  sw        $s0, 0x28($sp)
/* EDF9F8 80241038 F7B60048 */  sdc1      $f22, 0x48($sp)
/* EDF9FC 8024103C F7B40040 */  sdc1      $f20, 0x40($sp)
/* EDFA00 80241040 8E510148 */  lw        $s1, 0x148($s2)
/* EDFA04 80241044 86240008 */  lh        $a0, 8($s1)
/* EDFA08 80241048 0C00F92F */  jal       dead_get_npc_unsafe
/* EDFA0C 8024104C 00A0982D */   daddu    $s3, $a1, $zero
/* EDFA10 80241050 0040802D */  daddu     $s0, $v0, $zero
/* EDFA14 80241054 0200202D */  daddu     $a0, $s0, $zero
/* EDFA18 80241058 C6220088 */  lwc1      $f2, 0x88($s1)
/* EDFA1C 8024105C 468010A0 */  cvt.s.w   $f2, $f2
/* EDFA20 80241060 460010A1 */  cvt.d.s   $f2, $f2
/* EDFA24 80241064 C604001C */  lwc1      $f4, 0x1c($s0)
/* EDFA28 80241068 C6000014 */  lwc1      $f0, 0x14($s0)
/* EDFA2C 8024106C 8E050018 */  lw        $a1, 0x18($s0)
/* EDFA30 80241070 46002100 */  add.s     $f4, $f4, $f0
/* EDFA34 80241074 8E06000C */  lw        $a2, 0xc($s0)
/* EDFA38 80241078 C6200078 */  lwc1      $f0, 0x78($s1)
/* EDFA3C 8024107C 46800020 */  cvt.s.w   $f0, $f0
/* EDFA40 80241080 E604001C */  swc1      $f4, 0x1c($s0)
/* EDFA44 80241084 3C014059 */  lui       $at, 0x4059
/* EDFA48 80241088 44812800 */  mtc1      $at, $f5
/* EDFA4C 8024108C 44802000 */  mtc1      $zero, $f4
/* EDFA50 80241090 46000021 */  cvt.d.s   $f0, $f0
/* EDFA54 80241094 46240003 */  div.d     $f0, $f0, $f4
/* EDFA58 80241098 46200520 */  cvt.s.d   $f20, $f0
/* EDFA5C 8024109C 46241083 */  div.d     $f2, $f2, $f4
/* EDFA60 802410A0 0C00F909 */  jal       dead_npc_move_heading
/* EDFA64 802410A4 462015A0 */   cvt.s.d  $f22, $f2
/* EDFA68 802410A8 C604001C */  lwc1      $f4, 0x1c($s0)
/* EDFA6C 802410AC 44801000 */  mtc1      $zero, $f2
/* EDFA70 802410B0 44801800 */  mtc1      $zero, $f3
/* EDFA74 802410B4 46002021 */  cvt.d.s   $f0, $f4
/* EDFA78 802410B8 4620103E */  c.le.d    $f2, $f0
/* EDFA7C 802410BC 00000000 */  nop
/* EDFA80 802410C0 45000030 */  bc1f      .L80241184
/* EDFA84 802410C4 00000000 */   nop
/* EDFA88 802410C8 C600003C */  lwc1      $f0, 0x3c($s0)
/* EDFA8C 802410CC 46040000 */  add.s     $f0, $f0, $f4
/* EDFA90 802410D0 E600003C */  swc1      $f0, 0x3c($s0)
/* EDFA94 802410D4 8E2200CC */  lw        $v0, 0xcc($s1)
/* EDFA98 802410D8 8C420024 */  lw        $v0, 0x24($v0)
/* EDFA9C 802410DC AE020028 */  sw        $v0, 0x28($s0)
/* EDFAA0 802410E0 A2200007 */  sb        $zero, 7($s1)
/* EDFAA4 802410E4 8E020000 */  lw        $v0, ($s0)
/* EDFAA8 802410E8 30420008 */  andi      $v0, $v0, 8
/* EDFAAC 802410EC 14400011 */  bnez      $v0, .L80241134
/* EDFAB0 802410F0 0000102D */   daddu    $v0, $zero, $zero
/* EDFAB4 802410F4 27A50018 */  addiu     $a1, $sp, 0x18
/* EDFAB8 802410F8 27A6001C */  addiu     $a2, $sp, 0x1c
/* EDFABC 802410FC C6000038 */  lwc1      $f0, 0x38($s0)
/* EDFAC0 80241100 C602003C */  lwc1      $f2, 0x3c($s0)
/* EDFAC4 80241104 C6040040 */  lwc1      $f4, 0x40($s0)
/* EDFAC8 80241108 3C01447A */  lui       $at, 0x447a
/* EDFACC 8024110C 44813000 */  mtc1      $at, $f6
/* EDFAD0 80241110 27A20024 */  addiu     $v0, $sp, 0x24
/* EDFAD4 80241114 E7A00018 */  swc1      $f0, 0x18($sp)
/* EDFAD8 80241118 E7A2001C */  swc1      $f2, 0x1c($sp)
/* EDFADC 8024111C E7A40020 */  swc1      $f4, 0x20($sp)
/* EDFAE0 80241120 E7A60024 */  swc1      $f6, 0x24($sp)
/* EDFAE4 80241124 AFA20010 */  sw        $v0, 0x10($sp)
/* EDFAE8 80241128 8E040080 */  lw        $a0, 0x80($s0)
/* EDFAEC 8024112C 0C03908F */  jal       dead_npc_raycast_down_sides
/* EDFAF0 80241130 27A70020 */   addiu    $a3, $sp, 0x20
.L80241134:
/* EDFAF4 80241134 1040000B */  beqz      $v0, .L80241164
/* EDFAF8 80241138 00000000 */   nop
/* EDFAFC 8024113C C7A0001C */  lwc1      $f0, 0x1c($sp)
/* EDFB00 80241140 46140080 */  add.s     $f2, $f0, $f20
/* EDFB04 80241144 C600003C */  lwc1      $f0, 0x3c($s0)
/* EDFB08 80241148 4600103E */  c.le.s    $f2, $f0
/* EDFB0C 8024114C 00000000 */  nop
/* EDFB10 80241150 4500008D */  bc1f      .L80241388
/* EDFB14 80241154 00000000 */   nop
/* EDFB18 80241158 E602003C */  swc1      $f2, 0x3c($s0)
/* EDFB1C 8024115C 080904E2 */  j         .L80241388
/* EDFB20 80241160 AE400070 */   sw       $zero, 0x70($s2)
.L80241164:
/* EDFB24 80241164 C602003C */  lwc1      $f2, 0x3c($s0)
/* EDFB28 80241168 C6000064 */  lwc1      $f0, 0x64($s0)
/* EDFB2C 8024116C 4602003E */  c.le.s    $f0, $f2
/* EDFB30 80241170 00000000 */  nop
/* EDFB34 80241174 45030084 */  bc1tl     .L80241388
/* EDFB38 80241178 AE400070 */   sw       $zero, 0x70($s2)
/* EDFB3C 8024117C 080904E2 */  j         .L80241388
/* EDFB40 80241180 00000000 */   nop
.L80241184:
/* EDFB44 80241184 4622003C */  c.lt.d    $f0, $f2
/* EDFB48 80241188 00000000 */  nop
/* EDFB4C 8024118C 4500007E */  bc1f      .L80241388
/* EDFB50 80241190 00000000 */   nop
/* EDFB54 80241194 9602008E */  lhu       $v0, 0x8e($s0)
/* EDFB58 80241198 24420001 */  addiu     $v0, $v0, 1
/* EDFB5C 8024119C A602008E */  sh        $v0, 0x8e($s0)
/* EDFB60 802411A0 00021400 */  sll       $v0, $v0, 0x10
/* EDFB64 802411A4 8E630020 */  lw        $v1, 0x20($s3)
/* EDFB68 802411A8 00021403 */  sra       $v0, $v0, 0x10
/* EDFB6C 802411AC 0043102A */  slt       $v0, $v0, $v1
/* EDFB70 802411B0 14400026 */  bnez      $v0, .L8024124C
/* EDFB74 802411B4 00000000 */   nop
/* EDFB78 802411B8 C60C0038 */  lwc1      $f12, 0x38($s0)
/* EDFB7C 802411BC C60E0040 */  lwc1      $f14, 0x40($s0)
/* EDFB80 802411C0 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* EDFB84 802411C4 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* EDFB88 802411C8 A600008E */  sh        $zero, 0x8e($s0)
/* EDFB8C 802411CC 8C460028 */  lw        $a2, 0x28($v0)
/* EDFB90 802411D0 0C00ABDC */  jal       fio_validate_header_checksums
/* EDFB94 802411D4 8C470030 */   lw       $a3, 0x30($v0)
/* EDFB98 802411D8 46000506 */  mov.s     $f20, $f0
/* EDFB9C 802411DC C60C000C */  lwc1      $f12, 0xc($s0)
/* EDFBA0 802411E0 0C00ABC6 */  jal       dead_get_clamped_angle_diff
/* EDFBA4 802411E4 4600A386 */   mov.s    $f14, $f20
/* EDFBA8 802411E8 46000086 */  mov.s     $f2, $f0
/* EDFBAC 802411EC 8E62001C */  lw        $v0, 0x1c($s3)
/* EDFBB0 802411F0 46001005 */  abs.s     $f0, $f2
/* EDFBB4 802411F4 44822000 */  mtc1      $v0, $f4
/* EDFBB8 802411F8 00000000 */  nop
/* EDFBBC 802411FC 46802120 */  cvt.s.w   $f4, $f4
/* EDFBC0 80241200 4600203C */  c.lt.s    $f4, $f0
/* EDFBC4 80241204 00000000 */  nop
/* EDFBC8 80241208 4500000D */  bc1f      .L80241240
/* EDFBCC 8024120C 00000000 */   nop
/* EDFBD0 80241210 44800000 */  mtc1      $zero, $f0
/* EDFBD4 80241214 C614000C */  lwc1      $f20, 0xc($s0)
/* EDFBD8 80241218 4600103C */  c.lt.s    $f2, $f0
/* EDFBDC 8024121C 00000000 */  nop
/* EDFBE0 80241220 45000006 */  bc1f      .L8024123C
/* EDFBE4 80241224 00021023 */   negu     $v0, $v0
/* EDFBE8 80241228 44820000 */  mtc1      $v0, $f0
/* EDFBEC 8024122C 00000000 */  nop
/* EDFBF0 80241230 46800020 */  cvt.s.w   $f0, $f0
/* EDFBF4 80241234 08090490 */  j         .L80241240
/* EDFBF8 80241238 4600A500 */   add.s    $f20, $f20, $f0
.L8024123C:
/* EDFBFC 8024123C 4604A500 */  add.s     $f20, $f20, $f4
.L80241240:
/* EDFC00 80241240 0C00AB85 */  jal       dead_clamp_angle
/* EDFC04 80241244 4600A306 */   mov.s    $f12, $f20
/* EDFC08 80241248 E600000C */  swc1      $f0, 0xc($s0)
.L8024124C:
/* EDFC0C 8024124C 8E020000 */  lw        $v0, ($s0)
/* EDFC10 80241250 30420008 */  andi      $v0, $v0, 8
/* EDFC14 80241254 1040000A */  beqz      $v0, .L80241280
/* EDFC18 80241258 27A50018 */   addiu    $a1, $sp, 0x18
/* EDFC1C 8024125C C602003C */  lwc1      $f2, 0x3c($s0)
/* EDFC20 80241260 C600001C */  lwc1      $f0, 0x1c($s0)
/* EDFC24 80241264 46001080 */  add.s     $f2, $f2, $f0
/* EDFC28 80241268 4616103C */  c.lt.s    $f2, $f22
/* EDFC2C 8024126C 00000000 */  nop
/* EDFC30 80241270 45020045 */  bc1fl     .L80241388
/* EDFC34 80241274 E602003C */   swc1     $f2, 0x3c($s0)
/* EDFC38 80241278 080904E1 */  j         .L80241384
/* EDFC3C 8024127C E616003C */   swc1     $f22, 0x3c($s0)
.L80241280:
/* EDFC40 80241280 C6000038 */  lwc1      $f0, 0x38($s0)
/* EDFC44 80241284 27A6001C */  addiu     $a2, $sp, 0x1c
/* EDFC48 80241288 E7A00018 */  swc1      $f0, 0x18($sp)
/* EDFC4C 8024128C 860200A8 */  lh        $v0, 0xa8($s0)
/* EDFC50 80241290 C600001C */  lwc1      $f0, 0x1c($s0)
/* EDFC54 80241294 C604003C */  lwc1      $f4, 0x3c($s0)
/* EDFC58 80241298 44821000 */  mtc1      $v0, $f2
/* EDFC5C 8024129C 00000000 */  nop
/* EDFC60 802412A0 468010A0 */  cvt.s.w   $f2, $f2
/* EDFC64 802412A4 46000005 */  abs.s     $f0, $f0
/* EDFC68 802412A8 46020000 */  add.s     $f0, $f0, $f2
/* EDFC6C 802412AC C6060040 */  lwc1      $f6, 0x40($s0)
/* EDFC70 802412B0 27A20024 */  addiu     $v0, $sp, 0x24
/* EDFC74 802412B4 46022100 */  add.s     $f4, $f4, $f2
/* EDFC78 802412B8 3C014024 */  lui       $at, 0x4024
/* EDFC7C 802412BC 44811800 */  mtc1      $at, $f3
/* EDFC80 802412C0 44801000 */  mtc1      $zero, $f2
/* EDFC84 802412C4 46000021 */  cvt.d.s   $f0, $f0
/* EDFC88 802412C8 46220000 */  add.d     $f0, $f0, $f2
/* EDFC8C 802412CC E7A60020 */  swc1      $f6, 0x20($sp)
/* EDFC90 802412D0 E7A4001C */  swc1      $f4, 0x1c($sp)
/* EDFC94 802412D4 46200020 */  cvt.s.d   $f0, $f0
/* EDFC98 802412D8 E7A00024 */  swc1      $f0, 0x24($sp)
/* EDFC9C 802412DC AFA20010 */  sw        $v0, 0x10($sp)
/* EDFCA0 802412E0 8E040080 */  lw        $a0, 0x80($s0)
/* EDFCA4 802412E4 0C03908F */  jal       dead_npc_raycast_down_sides
/* EDFCA8 802412E8 27A70020 */   addiu    $a3, $sp, 0x20
/* EDFCAC 802412EC 10400015 */  beqz      $v0, .L80241344
/* EDFCB0 802412F0 00000000 */   nop
/* EDFCB4 802412F4 860200A8 */  lh        $v0, 0xa8($s0)
/* EDFCB8 802412F8 C604001C */  lwc1      $f4, 0x1c($s0)
/* EDFCBC 802412FC 44820000 */  mtc1      $v0, $f0
/* EDFCC0 80241300 00000000 */  nop
/* EDFCC4 80241304 46800020 */  cvt.s.w   $f0, $f0
/* EDFCC8 80241308 46002085 */  abs.s     $f2, $f4
/* EDFCCC 8024130C 46020000 */  add.s     $f0, $f0, $f2
/* EDFCD0 80241310 C7A20024 */  lwc1      $f2, 0x24($sp)
/* EDFCD4 80241314 4600103E */  c.le.s    $f2, $f0
/* EDFCD8 80241318 00000000 */  nop
/* EDFCDC 8024131C 45000005 */  bc1f      .L80241334
/* EDFCE0 80241320 00000000 */   nop
/* EDFCE4 80241324 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* EDFCE8 80241328 AE00001C */  sw        $zero, 0x1c($s0)
/* EDFCEC 8024132C 080904E2 */  j         .L80241388
/* EDFCF0 80241330 E600003C */   swc1     $f0, 0x3c($s0)
.L80241334:
/* EDFCF4 80241334 C600003C */  lwc1      $f0, 0x3c($s0)
/* EDFCF8 80241338 46040000 */  add.s     $f0, $f0, $f4
/* EDFCFC 8024133C 080904E2 */  j         .L80241388
/* EDFD00 80241340 E600003C */   swc1     $f0, 0x3c($s0)
.L80241344:
/* EDFD04 80241344 C606003C */  lwc1      $f6, 0x3c($s0)
/* EDFD08 80241348 860200A8 */  lh        $v0, 0xa8($s0)
/* EDFD0C 8024134C 46163081 */  sub.s     $f2, $f6, $f22
/* EDFD10 80241350 44820000 */  mtc1      $v0, $f0
/* EDFD14 80241354 00000000 */  nop
/* EDFD18 80241358 46800020 */  cvt.s.w   $f0, $f0
/* EDFD1C 8024135C 46001080 */  add.s     $f2, $f2, $f0
/* EDFD20 80241360 C604001C */  lwc1      $f4, 0x1c($s0)
/* EDFD24 80241364 46002005 */  abs.s     $f0, $f4
/* EDFD28 80241368 4602003C */  c.lt.s    $f0, $f2
/* EDFD2C 8024136C 00000000 */  nop
/* EDFD30 80241370 45020005 */  bc1fl     .L80241388
/* EDFD34 80241374 AE00001C */   sw       $zero, 0x1c($s0)
/* EDFD38 80241378 46043000 */  add.s     $f0, $f6, $f4
/* EDFD3C 8024137C 080904E2 */  j         .L80241388
/* EDFD40 80241380 E600003C */   swc1     $f0, 0x3c($s0)
.L80241384:
/* EDFD44 80241384 AE00001C */  sw        $zero, 0x1c($s0)
.L80241388:
/* EDFD48 80241388 8FBF0038 */  lw        $ra, 0x38($sp)
/* EDFD4C 8024138C 8FB30034 */  lw        $s3, 0x34($sp)
/* EDFD50 80241390 8FB20030 */  lw        $s2, 0x30($sp)
/* EDFD54 80241394 8FB1002C */  lw        $s1, 0x2c($sp)
/* EDFD58 80241398 8FB00028 */  lw        $s0, 0x28($sp)
/* EDFD5C 8024139C D7B60048 */  ldc1      $f22, 0x48($sp)
/* EDFD60 802413A0 D7B40040 */  ldc1      $f20, 0x40($sp)
/* EDFD64 802413A4 03E00008 */  jr        $ra
/* EDFD68 802413A8 27BD0050 */   addiu    $sp, $sp, 0x50
