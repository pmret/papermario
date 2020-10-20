.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240938_BAE278
/* BAE278 80240938 27BDFF88 */  addiu     $sp, $sp, -0x78
/* BAE27C 8024093C AFB3004C */  sw        $s3, 0x4c($sp)
/* BAE280 80240940 0080982D */  daddu     $s3, $a0, $zero
/* BAE284 80240944 AFBF0054 */  sw        $ra, 0x54($sp)
/* BAE288 80240948 AFB40050 */  sw        $s4, 0x50($sp)
/* BAE28C 8024094C AFB20048 */  sw        $s2, 0x48($sp)
/* BAE290 80240950 AFB10044 */  sw        $s1, 0x44($sp)
/* BAE294 80240954 AFB00040 */  sw        $s0, 0x40($sp)
/* BAE298 80240958 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* BAE29C 8024095C F7B80068 */  sdc1      $f24, 0x68($sp)
/* BAE2A0 80240960 F7B60060 */  sdc1      $f22, 0x60($sp)
/* BAE2A4 80240964 F7B40058 */  sdc1      $f20, 0x58($sp)
/* BAE2A8 80240968 8E710148 */  lw        $s1, 0x148($s3)
/* BAE2AC 8024096C 00A0902D */  daddu     $s2, $a1, $zero
/* BAE2B0 80240970 86240008 */  lh        $a0, 8($s1)
/* BAE2B4 80240974 0C00EABB */  jal       get_npc_unsafe
/* BAE2B8 80240978 00C0A02D */   daddu    $s4, $a2, $zero
/* BAE2BC 8024097C 0040802D */  daddu     $s0, $v0, $zero
/* BAE2C0 80240980 C6200078 */  lwc1      $f0, 0x78($s1)
/* BAE2C4 80240984 46800020 */  cvt.s.w   $f0, $f0
/* BAE2C8 80240988 46000021 */  cvt.d.s   $f0, $f0
/* BAE2CC 8024098C 3C014059 */  lui       $at, 0x4059
/* BAE2D0 80240990 44811800 */  mtc1      $at, $f3
/* BAE2D4 80240994 44801000 */  mtc1      $zero, $f2
/* BAE2D8 80240998 8602008E */  lh        $v0, 0x8e($s0)
/* BAE2DC 8024099C 9603008E */  lhu       $v1, 0x8e($s0)
/* BAE2E0 802409A0 46220003 */  div.d     $f0, $f0, $f2
/* BAE2E4 802409A4 46200620 */  cvt.s.d   $f24, $f0
/* BAE2E8 802409A8 C6200088 */  lwc1      $f0, 0x88($s1)
/* BAE2EC 802409AC 46800020 */  cvt.s.w   $f0, $f0
/* BAE2F0 802409B0 46000021 */  cvt.d.s   $f0, $f0
/* BAE2F4 802409B4 46220003 */  div.d     $f0, $f0, $f2
/* BAE2F8 802409B8 46200020 */  cvt.s.d   $f0, $f0
/* BAE2FC 802409BC 18400003 */  blez      $v0, .L802409CC
/* BAE300 802409C0 4600C680 */   add.s    $f26, $f24, $f0
/* BAE304 802409C4 2462FFFF */  addiu     $v0, $v1, -1
/* BAE308 802409C8 A602008E */  sh        $v0, 0x8e($s0)
.L802409CC:
/* BAE30C 802409CC 8E220070 */  lw        $v0, 0x70($s1)
/* BAE310 802409D0 18400034 */  blez      $v0, .L80240AA4
/* BAE314 802409D4 00000000 */   nop      
/* BAE318 802409D8 C62C0074 */  lwc1      $f12, 0x74($s1)
/* BAE31C 802409DC 46806320 */  cvt.s.w   $f12, $f12
/* BAE320 802409E0 44820000 */  mtc1      $v0, $f0
/* BAE324 802409E4 00000000 */  nop       
/* BAE328 802409E8 46800020 */  cvt.s.w   $f0, $f0
/* BAE32C 802409EC 46000021 */  cvt.d.s   $f0, $f0
/* BAE330 802409F0 46220003 */  div.d     $f0, $f0, $f2
/* BAE334 802409F4 0C00A8BB */  jal       sin_deg
/* BAE338 802409F8 462005A0 */   cvt.s.d  $f22, $f0
/* BAE33C 802409FC 8E020000 */  lw        $v0, ($s0)
/* BAE340 80240A00 30420008 */  andi      $v0, $v0, 8
/* BAE344 80240A04 10400003 */  beqz      $v0, .L80240A14
/* BAE348 80240A08 46000506 */   mov.s    $f20, $f0
/* BAE34C 80240A0C 08090295 */  j         .L80240A54
/* BAE350 80240A10 0000102D */   daddu    $v0, $zero, $zero
.L80240A14:
/* BAE354 80240A14 27A50028 */  addiu     $a1, $sp, 0x28
/* BAE358 80240A18 27A6002C */  addiu     $a2, $sp, 0x2c
/* BAE35C 80240A1C C6000038 */  lwc1      $f0, 0x38($s0)
/* BAE360 80240A20 C602003C */  lwc1      $f2, 0x3c($s0)
/* BAE364 80240A24 C6040040 */  lwc1      $f4, 0x40($s0)
/* BAE368 80240A28 3C01447A */  lui       $at, 0x447a
/* BAE36C 80240A2C 44813000 */  mtc1      $at, $f6
/* BAE370 80240A30 27A20034 */  addiu     $v0, $sp, 0x34
/* BAE374 80240A34 E7A00028 */  swc1      $f0, 0x28($sp)
/* BAE378 80240A38 E7A2002C */  swc1      $f2, 0x2c($sp)
/* BAE37C 80240A3C E7A40030 */  swc1      $f4, 0x30($sp)
/* BAE380 80240A40 E7A60034 */  swc1      $f6, 0x34($sp)
/* BAE384 80240A44 AFA20010 */  sw        $v0, 0x10($sp)
/* BAE388 80240A48 8E040080 */  lw        $a0, 0x80($s0)
/* BAE38C 80240A4C 0C0372DF */  jal       func_800DCB7C
/* BAE390 80240A50 27A70030 */   addiu    $a3, $sp, 0x30
.L80240A54:
/* BAE394 80240A54 10400007 */  beqz      $v0, .L80240A74
/* BAE398 80240A58 00000000 */   nop      
/* BAE39C 80240A5C 4616A082 */  mul.s     $f2, $f20, $f22
/* BAE3A0 80240A60 00000000 */  nop       
/* BAE3A4 80240A64 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* BAE3A8 80240A68 46180000 */  add.s     $f0, $f0, $f24
/* BAE3AC 80240A6C 080902A0 */  j         .L80240A80
/* BAE3B0 80240A70 46020000 */   add.s    $f0, $f0, $f2
.L80240A74:
/* BAE3B4 80240A74 4616A002 */  mul.s     $f0, $f20, $f22
/* BAE3B8 80240A78 00000000 */  nop       
/* BAE3BC 80240A7C 4600D000 */  add.s     $f0, $f26, $f0
.L80240A80:
/* BAE3C0 80240A80 E600003C */  swc1      $f0, 0x3c($s0)
/* BAE3C4 80240A84 8E220074 */  lw        $v0, 0x74($s1)
/* BAE3C8 80240A88 2442000A */  addiu     $v0, $v0, 0xa
/* BAE3CC 80240A8C 44826000 */  mtc1      $v0, $f12
/* BAE3D0 80240A90 00000000 */  nop       
/* BAE3D4 80240A94 0C00A6C9 */  jal       clamp_angle
/* BAE3D8 80240A98 46806320 */   cvt.s.w  $f12, $f12
/* BAE3DC 80240A9C 4600020D */  trunc.w.s $f8, $f0
/* BAE3E0 80240AA0 E6280074 */  swc1      $f8, 0x74($s1)
.L80240AA4:
/* BAE3E4 80240AA4 8E220090 */  lw        $v0, 0x90($s1)
/* BAE3E8 80240AA8 1C400040 */  bgtz      $v0, .L80240BAC
/* BAE3EC 80240AAC 2442FFFF */   addiu    $v0, $v0, -1
/* BAE3F0 80240AB0 860200A8 */  lh        $v0, 0xa8($s0)
/* BAE3F4 80240AB4 C600003C */  lwc1      $f0, 0x3c($s0)
/* BAE3F8 80240AB8 44821000 */  mtc1      $v0, $f2
/* BAE3FC 80240ABC 00000000 */  nop       
/* BAE400 80240AC0 468010A0 */  cvt.s.w   $f2, $f2
/* BAE404 80240AC4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BAE408 80240AC8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BAE40C 80240ACC 46020000 */  add.s     $f0, $f0, $f2
/* BAE410 80240AD0 3C014024 */  lui       $at, 0x4024
/* BAE414 80240AD4 44812800 */  mtc1      $at, $f5
/* BAE418 80240AD8 44802000 */  mtc1      $zero, $f4
/* BAE41C 80240ADC C442002C */  lwc1      $f2, 0x2c($v0)
/* BAE420 80240AE0 46000021 */  cvt.d.s   $f0, $f0
/* BAE424 80240AE4 46240000 */  add.d     $f0, $f0, $f4
/* BAE428 80240AE8 460010A1 */  cvt.d.s   $f2, $f2
/* BAE42C 80240AEC 4620103C */  c.lt.d    $f2, $f0
/* BAE430 80240AF0 00000000 */  nop       
/* BAE434 80240AF4 4500002E */  bc1f      .L80240BB0
/* BAE438 80240AF8 0280202D */   daddu    $a0, $s4, $zero
/* BAE43C 80240AFC 24020001 */  addiu     $v0, $zero, 1
/* BAE440 80240B00 AFA20010 */  sw        $v0, 0x10($sp)
/* BAE444 80240B04 8E460024 */  lw        $a2, 0x24($s2)
/* BAE448 80240B08 8E470028 */  lw        $a3, 0x28($s2)
/* BAE44C 80240B0C 0C01242D */  jal       func_800490B4
/* BAE450 80240B10 0220282D */   daddu    $a1, $s1, $zero
/* BAE454 80240B14 10400026 */  beqz      $v0, .L80240BB0
/* BAE458 80240B18 0000202D */   daddu    $a0, $zero, $zero
/* BAE45C 80240B1C 0200282D */  daddu     $a1, $s0, $zero
/* BAE460 80240B20 0000302D */  daddu     $a2, $zero, $zero
/* BAE464 80240B24 2412000C */  addiu     $s2, $zero, 0xc
/* BAE468 80240B28 860300A8 */  lh        $v1, 0xa8($s0)
/* BAE46C 80240B2C 3C013F80 */  lui       $at, 0x3f80
/* BAE470 80240B30 44810000 */  mtc1      $at, $f0
/* BAE474 80240B34 3C014000 */  lui       $at, 0x4000
/* BAE478 80240B38 44811000 */  mtc1      $at, $f2
/* BAE47C 80240B3C 3C01C1A0 */  lui       $at, 0xc1a0
/* BAE480 80240B40 44812000 */  mtc1      $at, $f4
/* BAE484 80240B44 44834000 */  mtc1      $v1, $f8
/* BAE488 80240B48 00000000 */  nop       
/* BAE48C 80240B4C 46804220 */  cvt.s.w   $f8, $f8
/* BAE490 80240B50 44074000 */  mfc1      $a3, $f8
/* BAE494 80240B54 27A20038 */  addiu     $v0, $sp, 0x38
/* BAE498 80240B58 AFB2001C */  sw        $s2, 0x1c($sp)
/* BAE49C 80240B5C AFA20020 */  sw        $v0, 0x20($sp)
/* BAE4A0 80240B60 E7A00010 */  swc1      $f0, 0x10($sp)
/* BAE4A4 80240B64 E7A20014 */  swc1      $f2, 0x14($sp)
/* BAE4A8 80240B68 0C01BFA4 */  jal       fx_emote
/* BAE4AC 80240B6C E7A40018 */   swc1     $f4, 0x18($sp)
/* BAE4B0 80240B70 0200202D */  daddu     $a0, $s0, $zero
/* BAE4B4 80240B74 240502F4 */  addiu     $a1, $zero, 0x2f4
/* BAE4B8 80240B78 C480003C */  lwc1      $f0, 0x3c($a0)
/* BAE4BC 80240B7C 3C060020 */  lui       $a2, 0x20
/* BAE4C0 80240B80 0C012530 */  jal       func_800494C0
/* BAE4C4 80240B84 E4800064 */   swc1     $f0, 0x64($a0)
/* BAE4C8 80240B88 8E220018 */  lw        $v0, 0x18($s1)
/* BAE4CC 80240B8C 9442002A */  lhu       $v0, 0x2a($v0)
/* BAE4D0 80240B90 30420001 */  andi      $v0, $v0, 1
/* BAE4D4 80240B94 10400003 */  beqz      $v0, .L80240BA4
/* BAE4D8 80240B98 2402000A */   addiu    $v0, $zero, 0xa
/* BAE4DC 80240B9C 08090313 */  j         .L80240C4C
/* BAE4E0 80240BA0 AE620070 */   sw       $v0, 0x70($s3)
.L80240BA4:
/* BAE4E4 80240BA4 08090313 */  j         .L80240C4C
/* BAE4E8 80240BA8 AE720070 */   sw       $s2, 0x70($s3)
.L80240BAC:
/* BAE4EC 80240BAC AE220090 */  sw        $v0, 0x90($s1)
.L80240BB0:
/* BAE4F0 80240BB0 8602008C */  lh        $v0, 0x8c($s0)
/* BAE4F4 80240BB4 14400025 */  bnez      $v0, .L80240C4C
/* BAE4F8 80240BB8 00000000 */   nop      
/* BAE4FC 80240BBC 8602008E */  lh        $v0, 0x8e($s0)
/* BAE500 80240BC0 1C400022 */  bgtz      $v0, .L80240C4C
/* BAE504 80240BC4 00000000 */   nop      
/* BAE508 80240BC8 8E620074 */  lw        $v0, 0x74($s3)
/* BAE50C 80240BCC 2442FFFF */  addiu     $v0, $v0, -1
/* BAE510 80240BD0 1840001D */  blez      $v0, .L80240C48
/* BAE514 80240BD4 AE620074 */   sw       $v0, 0x74($s3)
/* BAE518 80240BD8 8E220018 */  lw        $v0, 0x18($s1)
/* BAE51C 80240BDC 9442002A */  lhu       $v0, 0x2a($v0)
/* BAE520 80240BE0 30420010 */  andi      $v0, $v0, 0x10
/* BAE524 80240BE4 14400007 */  bnez      $v0, .L80240C04
/* BAE528 80240BE8 00000000 */   nop      
/* BAE52C 80240BEC C600000C */  lwc1      $f0, 0xc($s0)
/* BAE530 80240BF0 3C014334 */  lui       $at, 0x4334
/* BAE534 80240BF4 44816000 */  mtc1      $at, $f12
/* BAE538 80240BF8 0C00A6C9 */  jal       clamp_angle
/* BAE53C 80240BFC 460C0300 */   add.s    $f12, $f0, $f12
/* BAE540 80240C00 E600000C */  swc1      $f0, 0xc($s0)
.L80240C04:
/* BAE544 80240C04 0C00A67F */  jal       rand_int
/* BAE548 80240C08 240403E8 */   addiu    $a0, $zero, 0x3e8
/* BAE54C 80240C0C 3C032E8B */  lui       $v1, 0x2e8b
/* BAE550 80240C10 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* BAE554 80240C14 00430018 */  mult      $v0, $v1
/* BAE558 80240C18 00021FC3 */  sra       $v1, $v0, 0x1f
/* BAE55C 80240C1C 00004010 */  mfhi      $t0
/* BAE560 80240C20 00082043 */  sra       $a0, $t0, 1
/* BAE564 80240C24 00832023 */  subu      $a0, $a0, $v1
/* BAE568 80240C28 00041840 */  sll       $v1, $a0, 1
/* BAE56C 80240C2C 00641821 */  addu      $v1, $v1, $a0
/* BAE570 80240C30 00031880 */  sll       $v1, $v1, 2
/* BAE574 80240C34 00641823 */  subu      $v1, $v1, $a0
/* BAE578 80240C38 00431023 */  subu      $v0, $v0, $v1
/* BAE57C 80240C3C 24420005 */  addiu     $v0, $v0, 5
/* BAE580 80240C40 08090313 */  j         .L80240C4C
/* BAE584 80240C44 A602008E */   sh       $v0, 0x8e($s0)
.L80240C48:
/* BAE588 80240C48 AE600070 */  sw        $zero, 0x70($s3)
.L80240C4C:
/* BAE58C 80240C4C 8FBF0054 */  lw        $ra, 0x54($sp)
/* BAE590 80240C50 8FB40050 */  lw        $s4, 0x50($sp)
/* BAE594 80240C54 8FB3004C */  lw        $s3, 0x4c($sp)
/* BAE598 80240C58 8FB20048 */  lw        $s2, 0x48($sp)
/* BAE59C 80240C5C 8FB10044 */  lw        $s1, 0x44($sp)
/* BAE5A0 80240C60 8FB00040 */  lw        $s0, 0x40($sp)
/* BAE5A4 80240C64 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* BAE5A8 80240C68 D7B80068 */  ldc1      $f24, 0x68($sp)
/* BAE5AC 80240C6C D7B60060 */  ldc1      $f22, 0x60($sp)
/* BAE5B0 80240C70 D7B40058 */  ldc1      $f20, 0x58($sp)
/* BAE5B4 80240C74 03E00008 */  jr        $ra
/* BAE5B8 80240C78 27BD0078 */   addiu    $sp, $sp, 0x78
