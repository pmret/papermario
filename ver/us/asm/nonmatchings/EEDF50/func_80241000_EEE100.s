.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80245458_EF2558
.double 0.09

glabel D_80245460_EF2560
.double 0.09

.section .text

glabel func_80241000_EEE100
/* EEE100 80241000 27BDFF80 */  addiu     $sp, $sp, -0x80
/* EEE104 80241004 AFB3004C */  sw        $s3, 0x4c($sp)
/* EEE108 80241008 0080982D */  daddu     $s3, $a0, $zero
/* EEE10C 8024100C AFBF0058 */  sw        $ra, 0x58($sp)
/* EEE110 80241010 AFB50054 */  sw        $s5, 0x54($sp)
/* EEE114 80241014 AFB40050 */  sw        $s4, 0x50($sp)
/* EEE118 80241018 AFB20048 */  sw        $s2, 0x48($sp)
/* EEE11C 8024101C AFB10044 */  sw        $s1, 0x44($sp)
/* EEE120 80241020 AFB00040 */  sw        $s0, 0x40($sp)
/* EEE124 80241024 F7BA0078 */  sdc1      $f26, 0x78($sp)
/* EEE128 80241028 F7B80070 */  sdc1      $f24, 0x70($sp)
/* EEE12C 8024102C F7B60068 */  sdc1      $f22, 0x68($sp)
/* EEE130 80241030 F7B40060 */  sdc1      $f20, 0x60($sp)
/* EEE134 80241034 8E710148 */  lw        $s1, 0x148($s3)
/* EEE138 80241038 00A0902D */  daddu     $s2, $a1, $zero
/* EEE13C 8024103C 86240008 */  lh        $a0, 8($s1)
/* EEE140 80241040 0C00F92F */  jal       dead_get_npc_unsafe
/* EEE144 80241044 00C0A82D */   daddu    $s5, $a2, $zero
/* EEE148 80241048 0040802D */  daddu     $s0, $v0, $zero
/* EEE14C 8024104C 0000A02D */  daddu     $s4, $zero, $zero
/* EEE150 80241050 C624007C */  lwc1      $f4, 0x7c($s1)
/* EEE154 80241054 46802120 */  cvt.s.w   $f4, $f4
/* EEE158 80241058 C6220088 */  lwc1      $f2, 0x88($s1)
/* EEE15C 8024105C 468010A0 */  cvt.s.w   $f2, $f2
/* EEE160 80241060 460010A1 */  cvt.d.s   $f2, $f2
/* EEE164 80241064 46002121 */  cvt.d.s   $f4, $f4
/* EEE168 80241068 C600003C */  lwc1      $f0, 0x3c($s0)
/* EEE16C 8024106C 3C014059 */  lui       $at, 0x4059
/* EEE170 80241070 44813800 */  mtc1      $at, $f7
/* EEE174 80241074 44803000 */  mtc1      $zero, $f6
/* EEE178 80241078 46000021 */  cvt.d.s   $f0, $f0
/* EEE17C 8024107C 46260002 */  mul.d     $f0, $f0, $f6
/* EEE180 80241080 00000000 */  nop
/* EEE184 80241084 24020001 */  addiu     $v0, $zero, 1
/* EEE188 80241088 8E24006C */  lw        $a0, 0x6c($s1)
/* EEE18C 8024108C 46261083 */  div.d     $f2, $f2, $f6
/* EEE190 80241090 462010A0 */  cvt.s.d   $f2, $f2
/* EEE194 80241094 46262103 */  div.d     $f4, $f4, $f6
/* EEE198 80241098 46202520 */  cvt.s.d   $f20, $f4
/* EEE19C 8024109C 30830011 */  andi      $v1, $a0, 0x11
/* EEE1A0 802410A0 4620020D */  trunc.w.d $f8, $f0
/* EEE1A4 802410A4 E628007C */  swc1      $f8, 0x7c($s1)
/* EEE1A8 802410A8 C6200078 */  lwc1      $f0, 0x78($s1)
/* EEE1AC 802410AC 46800020 */  cvt.s.w   $f0, $f0
/* EEE1B0 802410B0 46000021 */  cvt.d.s   $f0, $f0
/* EEE1B4 802410B4 46260003 */  div.d     $f0, $f0, $f6
/* EEE1B8 802410B8 462006A0 */  cvt.s.d   $f26, $f0
/* EEE1BC 802410BC C6200070 */  lwc1      $f0, 0x70($s1)
/* EEE1C0 802410C0 46800020 */  cvt.s.w   $f0, $f0
/* EEE1C4 802410C4 46000021 */  cvt.d.s   $f0, $f0
/* EEE1C8 802410C8 46260003 */  div.d     $f0, $f0, $f6
/* EEE1CC 802410CC 462005A0 */  cvt.s.d   $f22, $f0
/* EEE1D0 802410D0 14620025 */  bne       $v1, $v0, .L80241168
/* EEE1D4 802410D4 4602D600 */   add.s    $f24, $f26, $f2
/* EEE1D8 802410D8 8E020000 */  lw        $v0, ($s0)
/* EEE1DC 802410DC 30420008 */  andi      $v0, $v0, 8
/* EEE1E0 802410E0 10400009 */  beqz      $v0, .L80241108
/* EEE1E4 802410E4 27A50028 */   addiu    $a1, $sp, 0x28
/* EEE1E8 802410E8 C600003C */  lwc1      $f0, 0x3c($s0)
/* EEE1EC 802410EC 4600C001 */  sub.s     $f0, $f24, $f0
/* EEE1F0 802410F0 4600B03C */  c.lt.s    $f22, $f0
/* EEE1F4 802410F4 00000000 */  nop
/* EEE1F8 802410F8 4500001B */  bc1f      .L80241168
/* EEE1FC 802410FC 34820010 */   ori      $v0, $a0, 0x10
/* EEE200 80241100 0809045A */  j         .L80241168
/* EEE204 80241104 AE22006C */   sw       $v0, 0x6c($s1)
.L80241108:
/* EEE208 80241108 27A6002C */  addiu     $a2, $sp, 0x2c
/* EEE20C 8024110C C6000038 */  lwc1      $f0, 0x38($s0)
/* EEE210 80241110 C602003C */  lwc1      $f2, 0x3c($s0)
/* EEE214 80241114 C6040040 */  lwc1      $f4, 0x40($s0)
/* EEE218 80241118 3C01447A */  lui       $at, 0x447a
/* EEE21C 8024111C 44813000 */  mtc1      $at, $f6
/* EEE220 80241120 27A20034 */  addiu     $v0, $sp, 0x34
/* EEE224 80241124 E7A00028 */  swc1      $f0, 0x28($sp)
/* EEE228 80241128 E7A2002C */  swc1      $f2, 0x2c($sp)
/* EEE22C 8024112C E7A40030 */  swc1      $f4, 0x30($sp)
/* EEE230 80241130 E7A60034 */  swc1      $f6, 0x34($sp)
/* EEE234 80241134 AFA20010 */  sw        $v0, 0x10($sp)
/* EEE238 80241138 8E040080 */  lw        $a0, 0x80($s0)
/* EEE23C 8024113C 0C03908F */  jal       dead_npc_raycast_down_sides
/* EEE240 80241140 27A70030 */   addiu    $a3, $sp, 0x30
/* EEE244 80241144 C7A00034 */  lwc1      $f0, 0x34($sp)
/* EEE248 80241148 4600D001 */  sub.s     $f0, $f26, $f0
/* EEE24C 8024114C 4600B03C */  c.lt.s    $f22, $f0
/* EEE250 80241150 00000000 */  nop
/* EEE254 80241154 45000004 */  bc1f      .L80241168
/* EEE258 80241158 00000000 */   nop
/* EEE25C 8024115C 8E22006C */  lw        $v0, 0x6c($s1)
/* EEE260 80241160 34420010 */  ori       $v0, $v0, 0x10
/* EEE264 80241164 AE22006C */  sw        $v0, 0x6c($s1)
.L80241168:
/* EEE268 80241168 8E22006C */  lw        $v0, 0x6c($s1)
/* EEE26C 8024116C 24030011 */  addiu     $v1, $zero, 0x11
/* EEE270 80241170 30420011 */  andi      $v0, $v0, 0x11
/* EEE274 80241174 14430039 */  bne       $v0, $v1, .L8024125C
/* EEE278 80241178 00000000 */   nop
/* EEE27C 8024117C 8E020000 */  lw        $v0, ($s0)
/* EEE280 80241180 30420008 */  andi      $v0, $v0, 8
/* EEE284 80241184 1040000A */  beqz      $v0, .L802411B0
/* EEE288 80241188 4600C106 */   mov.s    $f4, $f24
/* EEE28C 8024118C 4614C081 */  sub.s     $f2, $f24, $f20
/* EEE290 80241190 3C018024 */  lui       $at, %hi(D_80245458_EF2558)
/* EEE294 80241194 D4205458 */  ldc1      $f0, %lo(D_80245458_EF2558)($at)
/* EEE298 80241198 460010A1 */  cvt.d.s   $f2, $f2
/* EEE29C 8024119C 46201082 */  mul.d     $f2, $f2, $f0
/* EEE2A0 802411A0 00000000 */  nop
/* EEE2A4 802411A4 4600A021 */  cvt.d.s   $f0, $f20
/* EEE2A8 802411A8 08090485 */  j         .L80241214
/* EEE2AC 802411AC 46220000 */   add.d    $f0, $f0, $f2
.L802411B0:
/* EEE2B0 802411B0 27A50028 */  addiu     $a1, $sp, 0x28
/* EEE2B4 802411B4 27A6002C */  addiu     $a2, $sp, 0x2c
/* EEE2B8 802411B8 C6000038 */  lwc1      $f0, 0x38($s0)
/* EEE2BC 802411BC C6020040 */  lwc1      $f2, 0x40($s0)
/* EEE2C0 802411C0 3C01447A */  lui       $at, 0x447a
/* EEE2C4 802411C4 44812000 */  mtc1      $at, $f4
/* EEE2C8 802411C8 27A20034 */  addiu     $v0, $sp, 0x34
/* EEE2CC 802411CC E7B4002C */  swc1      $f20, 0x2c($sp)
/* EEE2D0 802411D0 E7A00028 */  swc1      $f0, 0x28($sp)
/* EEE2D4 802411D4 E7A20030 */  swc1      $f2, 0x30($sp)
/* EEE2D8 802411D8 E7A40034 */  swc1      $f4, 0x34($sp)
/* EEE2DC 802411DC AFA20010 */  sw        $v0, 0x10($sp)
/* EEE2E0 802411E0 8E040080 */  lw        $a0, 0x80($s0)
/* EEE2E4 802411E4 0C03908F */  jal       dead_npc_raycast_down_sides
/* EEE2E8 802411E8 27A70030 */   addiu    $a3, $sp, 0x30
/* EEE2EC 802411EC C7A4002C */  lwc1      $f4, 0x2c($sp)
/* EEE2F0 802411F0 461A2100 */  add.s     $f4, $f4, $f26
/* EEE2F4 802411F4 46142081 */  sub.s     $f2, $f4, $f20
/* EEE2F8 802411F8 3C018024 */  lui       $at, %hi(D_80245460_EF2560)
/* EEE2FC 802411FC D4205460 */  ldc1      $f0, %lo(D_80245460_EF2560)($at)
/* EEE300 80241200 460010A1 */  cvt.d.s   $f2, $f2
/* EEE304 80241204 46201082 */  mul.d     $f2, $f2, $f0
/* EEE308 80241208 00000000 */  nop
/* EEE30C 8024120C 4600A021 */  cvt.d.s   $f0, $f20
/* EEE310 80241210 46220000 */  add.d     $f0, $f0, $f2
.L80241214:
/* EEE314 80241214 46200020 */  cvt.s.d   $f0, $f0
/* EEE318 80241218 E600003C */  swc1      $f0, 0x3c($s0)
/* EEE31C 8024121C C600003C */  lwc1      $f0, 0x3c($s0)
/* EEE320 80241220 46002001 */  sub.s     $f0, $f4, $f0
/* EEE324 80241224 3C013FF0 */  lui       $at, 0x3ff0
/* EEE328 80241228 44811800 */  mtc1      $at, $f3
/* EEE32C 8024122C 44801000 */  mtc1      $zero, $f2
/* EEE330 80241230 46000005 */  abs.s     $f0, $f0
/* EEE334 80241234 46000021 */  cvt.d.s   $f0, $f0
/* EEE338 80241238 4622003C */  c.lt.d    $f0, $f2
/* EEE33C 8024123C 00000000 */  nop
/* EEE340 80241240 45000036 */  bc1f      .L8024131C
/* EEE344 80241244 2403FFEF */   addiu    $v1, $zero, -0x11
/* EEE348 80241248 E604003C */  swc1      $f4, 0x3c($s0)
/* EEE34C 8024124C 8E22006C */  lw        $v0, 0x6c($s1)
/* EEE350 80241250 00431024 */  and       $v0, $v0, $v1
/* EEE354 80241254 080904C7 */  j         .L8024131C
/* EEE358 80241258 AE22006C */   sw       $v0, 0x6c($s1)
.L8024125C:
/* EEE35C 8024125C 8E220070 */  lw        $v0, 0x70($s1)
/* EEE360 80241260 1840002E */  blez      $v0, .L8024131C
/* EEE364 80241264 00000000 */   nop
/* EEE368 80241268 C62C0074 */  lwc1      $f12, 0x74($s1)
/* EEE36C 8024126C 0C00AD77 */  jal       dead_sin_deg
/* EEE370 80241270 46806320 */   cvt.s.w  $f12, $f12
/* EEE374 80241274 8E020000 */  lw        $v0, ($s0)
/* EEE378 80241278 30420008 */  andi      $v0, $v0, 8
/* EEE37C 8024127C 10400003 */  beqz      $v0, .L8024128C
/* EEE380 80241280 46000506 */   mov.s    $f20, $f0
/* EEE384 80241284 080904B3 */  j         .L802412CC
/* EEE388 80241288 0000102D */   daddu    $v0, $zero, $zero
.L8024128C:
/* EEE38C 8024128C 27A50028 */  addiu     $a1, $sp, 0x28
/* EEE390 80241290 27A6002C */  addiu     $a2, $sp, 0x2c
/* EEE394 80241294 C6000038 */  lwc1      $f0, 0x38($s0)
/* EEE398 80241298 C602003C */  lwc1      $f2, 0x3c($s0)
/* EEE39C 8024129C C6040040 */  lwc1      $f4, 0x40($s0)
/* EEE3A0 802412A0 3C01447A */  lui       $at, 0x447a
/* EEE3A4 802412A4 44813000 */  mtc1      $at, $f6
/* EEE3A8 802412A8 27A20034 */  addiu     $v0, $sp, 0x34
/* EEE3AC 802412AC E7A00028 */  swc1      $f0, 0x28($sp)
/* EEE3B0 802412B0 E7A2002C */  swc1      $f2, 0x2c($sp)
/* EEE3B4 802412B4 E7A40030 */  swc1      $f4, 0x30($sp)
/* EEE3B8 802412B8 E7A60034 */  swc1      $f6, 0x34($sp)
/* EEE3BC 802412BC AFA20010 */  sw        $v0, 0x10($sp)
/* EEE3C0 802412C0 8E040080 */  lw        $a0, 0x80($s0)
/* EEE3C4 802412C4 0C03908F */  jal       dead_npc_raycast_down_sides
/* EEE3C8 802412C8 27A70030 */   addiu    $a3, $sp, 0x30
.L802412CC:
/* EEE3CC 802412CC 10400007 */  beqz      $v0, .L802412EC
/* EEE3D0 802412D0 00000000 */   nop
/* EEE3D4 802412D4 4616A082 */  mul.s     $f2, $f20, $f22
/* EEE3D8 802412D8 00000000 */  nop
/* EEE3DC 802412DC C7A0002C */  lwc1      $f0, 0x2c($sp)
/* EEE3E0 802412E0 461A0000 */  add.s     $f0, $f0, $f26
/* EEE3E4 802412E4 080904BE */  j         .L802412F8
/* EEE3E8 802412E8 46020000 */   add.s    $f0, $f0, $f2
.L802412EC:
/* EEE3EC 802412EC 4616A002 */  mul.s     $f0, $f20, $f22
/* EEE3F0 802412F0 00000000 */  nop
/* EEE3F4 802412F4 4600C000 */  add.s     $f0, $f24, $f0
.L802412F8:
/* EEE3F8 802412F8 E600003C */  swc1      $f0, 0x3c($s0)
/* EEE3FC 802412FC 8E220074 */  lw        $v0, 0x74($s1)
/* EEE400 80241300 2442000A */  addiu     $v0, $v0, 0xa
/* EEE404 80241304 44826000 */  mtc1      $v0, $f12
/* EEE408 80241308 00000000 */  nop
/* EEE40C 8024130C 0C00AB85 */  jal       dead_clamp_angle
/* EEE410 80241310 46806320 */   cvt.s.w  $f12, $f12
/* EEE414 80241314 4600020D */  trunc.w.s $f8, $f0
/* EEE418 80241318 E6280074 */  swc1      $f8, 0x74($s1)
.L8024131C:
/* EEE41C 8024131C 8E220090 */  lw        $v0, 0x90($s1)
/* EEE420 80241320 1C40004A */  bgtz      $v0, .L8024144C
/* EEE424 80241324 2442FFFF */   addiu    $v0, $v0, -1
/* EEE428 80241328 8E430014 */  lw        $v1, 0x14($s2)
/* EEE42C 8024132C 04600048 */  bltz      $v1, .L80241450
/* EEE430 80241330 00000000 */   nop
/* EEE434 80241334 8E620074 */  lw        $v0, 0x74($s3)
/* EEE438 80241338 1C400042 */  bgtz      $v0, .L80241444
/* EEE43C 8024133C 2442FFFF */   addiu    $v0, $v0, -1
/* EEE440 80241340 AE630074 */  sw        $v1, 0x74($s3)
/* EEE444 80241344 860200A8 */  lh        $v0, 0xa8($s0)
/* EEE448 80241348 C602003C */  lwc1      $f2, 0x3c($s0)
/* EEE44C 8024134C 44820000 */  mtc1      $v0, $f0
/* EEE450 80241350 00000000 */  nop
/* EEE454 80241354 46800020 */  cvt.s.w   $f0, $f0
/* EEE458 80241358 46001080 */  add.s     $f2, $f2, $f0
/* EEE45C 8024135C 3C014024 */  lui       $at, 0x4024
/* EEE460 80241360 44810800 */  mtc1      $at, $f1
/* EEE464 80241364 44800000 */  mtc1      $zero, $f0
/* EEE468 80241368 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* EEE46C 8024136C 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* EEE470 80241370 460010A1 */  cvt.d.s   $f2, $f2
/* EEE474 80241374 46201080 */  add.d     $f2, $f2, $f0
/* EEE478 80241378 C440002C */  lwc1      $f0, 0x2c($v0)
/* EEE47C 8024137C 46000021 */  cvt.d.s   $f0, $f0
/* EEE480 80241380 4622003C */  c.lt.d    $f0, $f2
/* EEE484 80241384 00000000 */  nop
/* EEE488 80241388 4500002C */  bc1f      .L8024143C
/* EEE48C 8024138C 02A0202D */   daddu    $a0, $s5, $zero
/* EEE490 80241390 AFA00010 */  sw        $zero, 0x10($sp)
/* EEE494 80241394 8E46000C */  lw        $a2, 0xc($s2)
/* EEE498 80241398 8E470010 */  lw        $a3, 0x10($s2)
/* EEE49C 8024139C 0C013469 */  jal       func_8004D1A4
/* EEE4A0 802413A0 0220282D */   daddu    $a1, $s1, $zero
/* EEE4A4 802413A4 10400025 */  beqz      $v0, .L8024143C
/* EEE4A8 802413A8 0000202D */   daddu    $a0, $zero, $zero
/* EEE4AC 802413AC 0200282D */  daddu     $a1, $s0, $zero
/* EEE4B0 802413B0 0000302D */  daddu     $a2, $zero, $zero
/* EEE4B4 802413B4 2412000C */  addiu     $s2, $zero, 0xc
/* EEE4B8 802413B8 860300A8 */  lh        $v1, 0xa8($s0)
/* EEE4BC 802413BC 3C013F80 */  lui       $at, 0x3f80
/* EEE4C0 802413C0 44810000 */  mtc1      $at, $f0
/* EEE4C4 802413C4 3C014000 */  lui       $at, 0x4000
/* EEE4C8 802413C8 44811000 */  mtc1      $at, $f2
/* EEE4CC 802413CC 3C01C1A0 */  lui       $at, 0xc1a0
/* EEE4D0 802413D0 44812000 */  mtc1      $at, $f4
/* EEE4D4 802413D4 44834000 */  mtc1      $v1, $f8
/* EEE4D8 802413D8 00000000 */  nop
/* EEE4DC 802413DC 46804220 */  cvt.s.w   $f8, $f8
/* EEE4E0 802413E0 44074000 */  mfc1      $a3, $f8
/* EEE4E4 802413E4 27A20038 */  addiu     $v0, $sp, 0x38
/* EEE4E8 802413E8 AFB2001C */  sw        $s2, 0x1c($sp)
/* EEE4EC 802413EC AFA20020 */  sw        $v0, 0x20($sp)
/* EEE4F0 802413F0 E7A00010 */  swc1      $f0, 0x10($sp)
/* EEE4F4 802413F4 E7A20014 */  swc1      $f2, 0x14($sp)
/* EEE4F8 802413F8 0C01D444 */  jal       dead_fx_emote
/* EEE4FC 802413FC E7A40018 */   swc1     $f4, 0x18($sp)
/* EEE500 80241400 0200202D */  daddu     $a0, $s0, $zero
/* EEE504 80241404 240502F4 */  addiu     $a1, $zero, 0x2f4
/* EEE508 80241408 C480003C */  lwc1      $f0, 0x3c($a0)
/* EEE50C 8024140C 3C060020 */  lui       $a2, 0x20
/* EEE510 80241410 0C013600 */  jal       dead_ai_enemy_play_sound
/* EEE514 80241414 E4800064 */   swc1     $f0, 0x64($a0)
/* EEE518 80241418 8E220018 */  lw        $v0, 0x18($s1)
/* EEE51C 8024141C 9442002A */  lhu       $v0, 0x2a($v0)
/* EEE520 80241420 30420001 */  andi      $v0, $v0, 1
/* EEE524 80241424 10400003 */  beqz      $v0, .L80241434
/* EEE528 80241428 2402000A */   addiu    $v0, $zero, 0xa
/* EEE52C 8024142C 0809057D */  j         .L802415F4
/* EEE530 80241430 AE620070 */   sw       $v0, 0x70($s3)
.L80241434:
/* EEE534 80241434 0809057D */  j         .L802415F4
/* EEE538 80241438 AE720070 */   sw       $s2, 0x70($s3)
.L8024143C:
/* EEE53C 8024143C 8E620074 */  lw        $v0, 0x74($s3)
/* EEE540 80241440 2442FFFF */  addiu     $v0, $v0, -1
.L80241444:
/* EEE544 80241444 08090514 */  j         .L80241450
/* EEE548 80241448 AE620074 */   sw       $v0, 0x74($s3)
.L8024144C:
/* EEE54C 8024144C AE220090 */  sw        $v0, 0x90($s1)
.L80241450:
/* EEE550 80241450 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EEE554 80241454 C6000040 */  lwc1      $f0, 0x40($s0)
/* EEE558 80241458 C4620000 */  lwc1      $f2, ($v1)
/* EEE55C 8024145C 468010A0 */  cvt.s.w   $f2, $f2
/* EEE560 80241460 C4640008 */  lwc1      $f4, 8($v1)
/* EEE564 80241464 46802120 */  cvt.s.w   $f4, $f4
/* EEE568 80241468 E7A00010 */  swc1      $f0, 0x10($sp)
/* EEE56C 8024146C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EEE570 80241470 44051000 */  mfc1      $a1, $f2
/* EEE574 80241474 C440000C */  lwc1      $f0, 0xc($v0)
/* EEE578 80241478 46800020 */  cvt.s.w   $f0, $f0
/* EEE57C 8024147C E7A00014 */  swc1      $f0, 0x14($sp)
/* EEE580 80241480 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EEE584 80241484 44062000 */  mfc1      $a2, $f4
/* EEE588 80241488 C4400010 */  lwc1      $f0, 0x10($v0)
/* EEE58C 8024148C 46800020 */  cvt.s.w   $f0, $f0
/* EEE590 80241490 E7A00018 */  swc1      $f0, 0x18($sp)
/* EEE594 80241494 8C640018 */  lw        $a0, 0x18($v1)
/* EEE598 80241498 0C013431 */  jal       dead_is_point_within_region
/* EEE59C 8024149C 8E070038 */   lw       $a3, 0x38($s0)
/* EEE5A0 802414A0 1040001A */  beqz      $v0, .L8024150C
/* EEE5A4 802414A4 00000000 */   nop
/* EEE5A8 802414A8 8E060038 */  lw        $a2, 0x38($s0)
/* EEE5AC 802414AC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EEE5B0 802414B0 8E070040 */  lw        $a3, 0x40($s0)
/* EEE5B4 802414B4 C44C0000 */  lwc1      $f12, ($v0)
/* EEE5B8 802414B8 46806320 */  cvt.s.w   $f12, $f12
/* EEE5BC 802414BC C44E0008 */  lwc1      $f14, 8($v0)
/* EEE5C0 802414C0 0C00AC71 */  jal       dead_dist2D
/* EEE5C4 802414C4 468073A0 */   cvt.s.w  $f14, $f14
/* EEE5C8 802414C8 C6020018 */  lwc1      $f2, 0x18($s0)
/* EEE5CC 802414CC 4600103C */  c.lt.s    $f2, $f0
/* EEE5D0 802414D0 00000000 */  nop
/* EEE5D4 802414D4 4500000D */  bc1f      .L8024150C
/* EEE5D8 802414D8 E7A00034 */   swc1     $f0, 0x34($sp)
/* EEE5DC 802414DC C60C0038 */  lwc1      $f12, 0x38($s0)
/* EEE5E0 802414E0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EEE5E4 802414E4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* EEE5E8 802414E8 C4480000 */  lwc1      $f8, ($v0)
/* EEE5EC 802414EC 46804220 */  cvt.s.w   $f8, $f8
/* EEE5F0 802414F0 44064000 */  mfc1      $a2, $f8
/* EEE5F4 802414F4 C4480008 */  lwc1      $f8, 8($v0)
/* EEE5F8 802414F8 46804220 */  cvt.s.w   $f8, $f8
/* EEE5FC 802414FC 44074000 */  mfc1      $a3, $f8
/* EEE600 80241500 0C00ABDC */  jal       fio_validate_header_checksums
/* EEE604 80241504 24140001 */   addiu    $s4, $zero, 1
/* EEE608 80241508 E600000C */  swc1      $f0, 0xc($s0)
.L8024150C:
/* EEE60C 8024150C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EEE610 80241510 8C43000C */  lw        $v1, 0xc($v0)
/* EEE614 80241514 8C420010 */  lw        $v0, 0x10($v0)
/* EEE618 80241518 00621825 */  or        $v1, $v1, $v0
/* EEE61C 8024151C 00741825 */  or        $v1, $v1, $s4
/* EEE620 80241520 10600008 */  beqz      $v1, .L80241544
/* EEE624 80241524 00000000 */   nop
/* EEE628 80241528 8602008C */  lh        $v0, 0x8c($s0)
/* EEE62C 8024152C 14400031 */  bnez      $v0, .L802415F4
/* EEE630 80241530 00000000 */   nop
/* EEE634 80241534 8E050018 */  lw        $a1, 0x18($s0)
/* EEE638 80241538 8E06000C */  lw        $a2, 0xc($s0)
/* EEE63C 8024153C 0C00F909 */  jal       dead_npc_move_heading
/* EEE640 80241540 0200202D */   daddu    $a0, $s0, $zero
.L80241544:
/* EEE644 80241544 C600003C */  lwc1      $f0, 0x3c($s0)
/* EEE648 80241548 3C014059 */  lui       $at, 0x4059
/* EEE64C 8024154C 44811800 */  mtc1      $at, $f3
/* EEE650 80241550 44801000 */  mtc1      $zero, $f2
/* EEE654 80241554 46000021 */  cvt.d.s   $f0, $f0
/* EEE658 80241558 46220002 */  mul.d     $f0, $f0, $f2
/* EEE65C 8024155C 00000000 */  nop
/* EEE660 80241560 4620020D */  trunc.w.d $f8, $f0
/* EEE664 80241564 E628007C */  swc1      $f8, 0x7c($s1)
/* EEE668 80241568 8E420004 */  lw        $v0, 4($s2)
/* EEE66C 8024156C 18400021 */  blez      $v0, .L802415F4
/* EEE670 80241570 00000000 */   nop
/* EEE674 80241574 8602008E */  lh        $v0, 0x8e($s0)
/* EEE678 80241578 9603008E */  lhu       $v1, 0x8e($s0)
/* EEE67C 8024157C 18400005 */  blez      $v0, .L80241594
/* EEE680 80241580 2462FFFF */   addiu    $v0, $v1, -1
/* EEE684 80241584 A602008E */  sh        $v0, 0x8e($s0)
/* EEE688 80241588 00021400 */  sll       $v0, $v0, 0x10
/* EEE68C 8024158C 1C400019 */  bgtz      $v0, .L802415F4
/* EEE690 80241590 00000000 */   nop
.L80241594:
/* EEE694 80241594 240403E8 */  addiu     $a0, $zero, 0x3e8
/* EEE698 80241598 24020002 */  addiu     $v0, $zero, 2
/* EEE69C 8024159C 0C00AB3B */  jal       dead_rand_int
/* EEE6A0 802415A0 AE620070 */   sw       $v0, 0x70($s3)
/* EEE6A4 802415A4 3C035555 */  lui       $v1, 0x5555
/* EEE6A8 802415A8 34635556 */  ori       $v1, $v1, 0x5556
/* EEE6AC 802415AC 00430018 */  mult      $v0, $v1
/* EEE6B0 802415B0 000227C3 */  sra       $a0, $v0, 0x1f
/* EEE6B4 802415B4 00004010 */  mfhi      $t0
/* EEE6B8 802415B8 01042023 */  subu      $a0, $t0, $a0
/* EEE6BC 802415BC 00041840 */  sll       $v1, $a0, 1
/* EEE6C0 802415C0 00641821 */  addu      $v1, $v1, $a0
/* EEE6C4 802415C4 00431023 */  subu      $v0, $v0, $v1
/* EEE6C8 802415C8 24430002 */  addiu     $v1, $v0, 2
/* EEE6CC 802415CC AE630074 */  sw        $v1, 0x74($s3)
/* EEE6D0 802415D0 8E42002C */  lw        $v0, 0x2c($s2)
/* EEE6D4 802415D4 58400007 */  blezl     $v0, .L802415F4
/* EEE6D8 802415D8 AE600070 */   sw       $zero, 0x70($s3)
/* EEE6DC 802415DC 8E420008 */  lw        $v0, 8($s2)
/* EEE6E0 802415E0 18400003 */  blez      $v0, .L802415F0
/* EEE6E4 802415E4 28620003 */   slti     $v0, $v1, 3
/* EEE6E8 802415E8 10400002 */  beqz      $v0, .L802415F4
/* EEE6EC 802415EC 00000000 */   nop
.L802415F0:
/* EEE6F0 802415F0 AE600070 */  sw        $zero, 0x70($s3)
.L802415F4:
/* EEE6F4 802415F4 8FBF0058 */  lw        $ra, 0x58($sp)
/* EEE6F8 802415F8 8FB50054 */  lw        $s5, 0x54($sp)
/* EEE6FC 802415FC 8FB40050 */  lw        $s4, 0x50($sp)
/* EEE700 80241600 8FB3004C */  lw        $s3, 0x4c($sp)
/* EEE704 80241604 8FB20048 */  lw        $s2, 0x48($sp)
/* EEE708 80241608 8FB10044 */  lw        $s1, 0x44($sp)
/* EEE70C 8024160C 8FB00040 */  lw        $s0, 0x40($sp)
/* EEE710 80241610 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* EEE714 80241614 D7B80070 */  ldc1      $f24, 0x70($sp)
/* EEE718 80241618 D7B60068 */  ldc1      $f22, 0x68($sp)
/* EEE71C 8024161C D7B40060 */  ldc1      $f20, 0x60($sp)
/* EEE720 80241620 03E00008 */  jr        $ra
/* EEE724 80241624 27BD0080 */   addiu    $sp, $sp, 0x80
