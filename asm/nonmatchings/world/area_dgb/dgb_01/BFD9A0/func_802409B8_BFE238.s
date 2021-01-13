.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409B8_BFE238
/* BFE238 802409B8 27BDFF88 */  addiu     $sp, $sp, -0x78
/* BFE23C 802409BC AFB3004C */  sw        $s3, 0x4c($sp)
/* BFE240 802409C0 0080982D */  daddu     $s3, $a0, $zero
/* BFE244 802409C4 AFBF0054 */  sw        $ra, 0x54($sp)
/* BFE248 802409C8 AFB40050 */  sw        $s4, 0x50($sp)
/* BFE24C 802409CC AFB20048 */  sw        $s2, 0x48($sp)
/* BFE250 802409D0 AFB10044 */  sw        $s1, 0x44($sp)
/* BFE254 802409D4 AFB00040 */  sw        $s0, 0x40($sp)
/* BFE258 802409D8 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* BFE25C 802409DC F7B80068 */  sdc1      $f24, 0x68($sp)
/* BFE260 802409E0 F7B60060 */  sdc1      $f22, 0x60($sp)
/* BFE264 802409E4 F7B40058 */  sdc1      $f20, 0x58($sp)
/* BFE268 802409E8 8E710148 */  lw        $s1, 0x148($s3)
/* BFE26C 802409EC 00A0902D */  daddu     $s2, $a1, $zero
/* BFE270 802409F0 86240008 */  lh        $a0, 8($s1)
/* BFE274 802409F4 0C00EABB */  jal       get_npc_unsafe
/* BFE278 802409F8 00C0A02D */   daddu    $s4, $a2, $zero
/* BFE27C 802409FC 0040802D */  daddu     $s0, $v0, $zero
/* BFE280 80240A00 C6200078 */  lwc1      $f0, 0x78($s1)
/* BFE284 80240A04 46800020 */  cvt.s.w   $f0, $f0
/* BFE288 80240A08 46000021 */  cvt.d.s   $f0, $f0
/* BFE28C 80240A0C 3C014059 */  lui       $at, 0x4059
/* BFE290 80240A10 44811800 */  mtc1      $at, $f3
/* BFE294 80240A14 44801000 */  mtc1      $zero, $f2
/* BFE298 80240A18 8602008E */  lh        $v0, 0x8e($s0)
/* BFE29C 80240A1C 9603008E */  lhu       $v1, 0x8e($s0)
/* BFE2A0 80240A20 46220003 */  div.d     $f0, $f0, $f2
/* BFE2A4 80240A24 46200620 */  cvt.s.d   $f24, $f0
/* BFE2A8 80240A28 C6200088 */  lwc1      $f0, 0x88($s1)
/* BFE2AC 80240A2C 46800020 */  cvt.s.w   $f0, $f0
/* BFE2B0 80240A30 46000021 */  cvt.d.s   $f0, $f0
/* BFE2B4 80240A34 46220003 */  div.d     $f0, $f0, $f2
/* BFE2B8 80240A38 46200020 */  cvt.s.d   $f0, $f0
/* BFE2BC 80240A3C 18400003 */  blez      $v0, .L80240A4C
/* BFE2C0 80240A40 4600C680 */   add.s    $f26, $f24, $f0
/* BFE2C4 80240A44 2462FFFF */  addiu     $v0, $v1, -1
/* BFE2C8 80240A48 A602008E */  sh        $v0, 0x8e($s0)
.L80240A4C:
/* BFE2CC 80240A4C 8E220070 */  lw        $v0, 0x70($s1)
/* BFE2D0 80240A50 18400034 */  blez      $v0, .L80240B24
/* BFE2D4 80240A54 00000000 */   nop
/* BFE2D8 80240A58 C62C0074 */  lwc1      $f12, 0x74($s1)
/* BFE2DC 80240A5C 46806320 */  cvt.s.w   $f12, $f12
/* BFE2E0 80240A60 44820000 */  mtc1      $v0, $f0
/* BFE2E4 80240A64 00000000 */  nop
/* BFE2E8 80240A68 46800020 */  cvt.s.w   $f0, $f0
/* BFE2EC 80240A6C 46000021 */  cvt.d.s   $f0, $f0
/* BFE2F0 80240A70 46220003 */  div.d     $f0, $f0, $f2
/* BFE2F4 80240A74 0C00A8BB */  jal       sin_deg
/* BFE2F8 80240A78 462005A0 */   cvt.s.d  $f22, $f0
/* BFE2FC 80240A7C 8E020000 */  lw        $v0, ($s0)
/* BFE300 80240A80 30420008 */  andi      $v0, $v0, 8
/* BFE304 80240A84 10400003 */  beqz      $v0, .L80240A94
/* BFE308 80240A88 46000506 */   mov.s    $f20, $f0
/* BFE30C 80240A8C 080902B5 */  j         .L80240AD4
/* BFE310 80240A90 0000102D */   daddu    $v0, $zero, $zero
.L80240A94:
/* BFE314 80240A94 27A50028 */  addiu     $a1, $sp, 0x28
/* BFE318 80240A98 27A6002C */  addiu     $a2, $sp, 0x2c
/* BFE31C 80240A9C C6000038 */  lwc1      $f0, 0x38($s0)
/* BFE320 80240AA0 C602003C */  lwc1      $f2, 0x3c($s0)
/* BFE324 80240AA4 C6040040 */  lwc1      $f4, 0x40($s0)
/* BFE328 80240AA8 3C01447A */  lui       $at, 0x447a
/* BFE32C 80240AAC 44813000 */  mtc1      $at, $f6
/* BFE330 80240AB0 27A20034 */  addiu     $v0, $sp, 0x34
/* BFE334 80240AB4 E7A00028 */  swc1      $f0, 0x28($sp)
/* BFE338 80240AB8 E7A2002C */  swc1      $f2, 0x2c($sp)
/* BFE33C 80240ABC E7A40030 */  swc1      $f4, 0x30($sp)
/* BFE340 80240AC0 E7A60034 */  swc1      $f6, 0x34($sp)
/* BFE344 80240AC4 AFA20010 */  sw        $v0, 0x10($sp)
/* BFE348 80240AC8 8E040080 */  lw        $a0, 0x80($s0)
/* BFE34C 80240ACC 0C0372DF */  jal       func_800DCB7C
/* BFE350 80240AD0 27A70030 */   addiu    $a3, $sp, 0x30
.L80240AD4:
/* BFE354 80240AD4 10400007 */  beqz      $v0, .L80240AF4
/* BFE358 80240AD8 00000000 */   nop
/* BFE35C 80240ADC 4616A082 */  mul.s     $f2, $f20, $f22
/* BFE360 80240AE0 00000000 */  nop
/* BFE364 80240AE4 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* BFE368 80240AE8 46180000 */  add.s     $f0, $f0, $f24
/* BFE36C 80240AEC 080902C0 */  j         .L80240B00
/* BFE370 80240AF0 46020000 */   add.s    $f0, $f0, $f2
.L80240AF4:
/* BFE374 80240AF4 4616A002 */  mul.s     $f0, $f20, $f22
/* BFE378 80240AF8 00000000 */  nop
/* BFE37C 80240AFC 4600D000 */  add.s     $f0, $f26, $f0
.L80240B00:
/* BFE380 80240B00 E600003C */  swc1      $f0, 0x3c($s0)
/* BFE384 80240B04 8E220074 */  lw        $v0, 0x74($s1)
/* BFE388 80240B08 2442000A */  addiu     $v0, $v0, 0xa
/* BFE38C 80240B0C 44826000 */  mtc1      $v0, $f12
/* BFE390 80240B10 00000000 */  nop
/* BFE394 80240B14 0C00A6C9 */  jal       clamp_angle
/* BFE398 80240B18 46806320 */   cvt.s.w  $f12, $f12
/* BFE39C 80240B1C 4600020D */  trunc.w.s $f8, $f0
/* BFE3A0 80240B20 E6280074 */  swc1      $f8, 0x74($s1)
.L80240B24:
/* BFE3A4 80240B24 8E220090 */  lw        $v0, 0x90($s1)
/* BFE3A8 80240B28 1C400040 */  bgtz      $v0, .L80240C2C
/* BFE3AC 80240B2C 2442FFFF */   addiu    $v0, $v0, -1
/* BFE3B0 80240B30 860200A8 */  lh        $v0, 0xa8($s0)
/* BFE3B4 80240B34 C600003C */  lwc1      $f0, 0x3c($s0)
/* BFE3B8 80240B38 44821000 */  mtc1      $v0, $f2
/* BFE3BC 80240B3C 00000000 */  nop
/* BFE3C0 80240B40 468010A0 */  cvt.s.w   $f2, $f2
/* BFE3C4 80240B44 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BFE3C8 80240B48 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BFE3CC 80240B4C 46020000 */  add.s     $f0, $f0, $f2
/* BFE3D0 80240B50 3C014024 */  lui       $at, 0x4024
/* BFE3D4 80240B54 44812800 */  mtc1      $at, $f5
/* BFE3D8 80240B58 44802000 */  mtc1      $zero, $f4
/* BFE3DC 80240B5C C442002C */  lwc1      $f2, 0x2c($v0)
/* BFE3E0 80240B60 46000021 */  cvt.d.s   $f0, $f0
/* BFE3E4 80240B64 46240000 */  add.d     $f0, $f0, $f4
/* BFE3E8 80240B68 460010A1 */  cvt.d.s   $f2, $f2
/* BFE3EC 80240B6C 4620103C */  c.lt.d    $f2, $f0
/* BFE3F0 80240B70 00000000 */  nop
/* BFE3F4 80240B74 4500002E */  bc1f      .L80240C30
/* BFE3F8 80240B78 0280202D */   daddu    $a0, $s4, $zero
/* BFE3FC 80240B7C 24020001 */  addiu     $v0, $zero, 1
/* BFE400 80240B80 AFA20010 */  sw        $v0, 0x10($sp)
/* BFE404 80240B84 8E460024 */  lw        $a2, 0x24($s2)
/* BFE408 80240B88 8E470028 */  lw        $a3, 0x28($s2)
/* BFE40C 80240B8C 0C01242D */  jal       func_800490B4
/* BFE410 80240B90 0220282D */   daddu    $a1, $s1, $zero
/* BFE414 80240B94 10400026 */  beqz      $v0, .L80240C30
/* BFE418 80240B98 0000202D */   daddu    $a0, $zero, $zero
/* BFE41C 80240B9C 0200282D */  daddu     $a1, $s0, $zero
/* BFE420 80240BA0 0000302D */  daddu     $a2, $zero, $zero
/* BFE424 80240BA4 2412000C */  addiu     $s2, $zero, 0xc
/* BFE428 80240BA8 860300A8 */  lh        $v1, 0xa8($s0)
/* BFE42C 80240BAC 3C013F80 */  lui       $at, 0x3f80
/* BFE430 80240BB0 44810000 */  mtc1      $at, $f0
/* BFE434 80240BB4 3C014000 */  lui       $at, 0x4000
/* BFE438 80240BB8 44811000 */  mtc1      $at, $f2
/* BFE43C 80240BBC 3C01C1A0 */  lui       $at, 0xc1a0
/* BFE440 80240BC0 44812000 */  mtc1      $at, $f4
/* BFE444 80240BC4 44834000 */  mtc1      $v1, $f8
/* BFE448 80240BC8 00000000 */  nop
/* BFE44C 80240BCC 46804220 */  cvt.s.w   $f8, $f8
/* BFE450 80240BD0 44074000 */  mfc1      $a3, $f8
/* BFE454 80240BD4 27A20038 */  addiu     $v0, $sp, 0x38
/* BFE458 80240BD8 AFB2001C */  sw        $s2, 0x1c($sp)
/* BFE45C 80240BDC AFA20020 */  sw        $v0, 0x20($sp)
/* BFE460 80240BE0 E7A00010 */  swc1      $f0, 0x10($sp)
/* BFE464 80240BE4 E7A20014 */  swc1      $f2, 0x14($sp)
/* BFE468 80240BE8 0C01BFA4 */  jal       fx_emote
/* BFE46C 80240BEC E7A40018 */   swc1     $f4, 0x18($sp)
/* BFE470 80240BF0 0200202D */  daddu     $a0, $s0, $zero
/* BFE474 80240BF4 240502F4 */  addiu     $a1, $zero, 0x2f4
/* BFE478 80240BF8 C480003C */  lwc1      $f0, 0x3c($a0)
/* BFE47C 80240BFC 3C060020 */  lui       $a2, 0x20
/* BFE480 80240C00 0C012530 */  jal       func_800494C0
/* BFE484 80240C04 E4800064 */   swc1     $f0, 0x64($a0)
/* BFE488 80240C08 8E220018 */  lw        $v0, 0x18($s1)
/* BFE48C 80240C0C 9442002A */  lhu       $v0, 0x2a($v0)
/* BFE490 80240C10 30420001 */  andi      $v0, $v0, 1
/* BFE494 80240C14 10400003 */  beqz      $v0, .L80240C24
/* BFE498 80240C18 2402000A */   addiu    $v0, $zero, 0xa
/* BFE49C 80240C1C 08090333 */  j         .L80240CCC
/* BFE4A0 80240C20 AE620070 */   sw       $v0, 0x70($s3)
.L80240C24:
/* BFE4A4 80240C24 08090333 */  j         .L80240CCC
/* BFE4A8 80240C28 AE720070 */   sw       $s2, 0x70($s3)
.L80240C2C:
/* BFE4AC 80240C2C AE220090 */  sw        $v0, 0x90($s1)
.L80240C30:
/* BFE4B0 80240C30 8602008C */  lh        $v0, 0x8c($s0)
/* BFE4B4 80240C34 14400025 */  bnez      $v0, .L80240CCC
/* BFE4B8 80240C38 00000000 */   nop
/* BFE4BC 80240C3C 8602008E */  lh        $v0, 0x8e($s0)
/* BFE4C0 80240C40 1C400022 */  bgtz      $v0, .L80240CCC
/* BFE4C4 80240C44 00000000 */   nop
/* BFE4C8 80240C48 8E620074 */  lw        $v0, 0x74($s3)
/* BFE4CC 80240C4C 2442FFFF */  addiu     $v0, $v0, -1
/* BFE4D0 80240C50 1840001D */  blez      $v0, .L80240CC8
/* BFE4D4 80240C54 AE620074 */   sw       $v0, 0x74($s3)
/* BFE4D8 80240C58 8E220018 */  lw        $v0, 0x18($s1)
/* BFE4DC 80240C5C 9442002A */  lhu       $v0, 0x2a($v0)
/* BFE4E0 80240C60 30420010 */  andi      $v0, $v0, 0x10
/* BFE4E4 80240C64 14400007 */  bnez      $v0, .L80240C84
/* BFE4E8 80240C68 00000000 */   nop
/* BFE4EC 80240C6C C600000C */  lwc1      $f0, 0xc($s0)
/* BFE4F0 80240C70 3C014334 */  lui       $at, 0x4334
/* BFE4F4 80240C74 44816000 */  mtc1      $at, $f12
/* BFE4F8 80240C78 0C00A6C9 */  jal       clamp_angle
/* BFE4FC 80240C7C 460C0300 */   add.s    $f12, $f0, $f12
/* BFE500 80240C80 E600000C */  swc1      $f0, 0xc($s0)
.L80240C84:
/* BFE504 80240C84 0C00A67F */  jal       rand_int
/* BFE508 80240C88 240403E8 */   addiu    $a0, $zero, 0x3e8
/* BFE50C 80240C8C 3C032E8B */  lui       $v1, 0x2e8b
/* BFE510 80240C90 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* BFE514 80240C94 00430018 */  mult      $v0, $v1
/* BFE518 80240C98 00021FC3 */  sra       $v1, $v0, 0x1f
/* BFE51C 80240C9C 00004010 */  mfhi      $t0
/* BFE520 80240CA0 00082043 */  sra       $a0, $t0, 1
/* BFE524 80240CA4 00832023 */  subu      $a0, $a0, $v1
/* BFE528 80240CA8 00041840 */  sll       $v1, $a0, 1
/* BFE52C 80240CAC 00641821 */  addu      $v1, $v1, $a0
/* BFE530 80240CB0 00031880 */  sll       $v1, $v1, 2
/* BFE534 80240CB4 00641823 */  subu      $v1, $v1, $a0
/* BFE538 80240CB8 00431023 */  subu      $v0, $v0, $v1
/* BFE53C 80240CBC 24420005 */  addiu     $v0, $v0, 5
/* BFE540 80240CC0 08090333 */  j         .L80240CCC
/* BFE544 80240CC4 A602008E */   sh       $v0, 0x8e($s0)
.L80240CC8:
/* BFE548 80240CC8 AE600070 */  sw        $zero, 0x70($s3)
.L80240CCC:
/* BFE54C 80240CCC 8FBF0054 */  lw        $ra, 0x54($sp)
/* BFE550 80240CD0 8FB40050 */  lw        $s4, 0x50($sp)
/* BFE554 80240CD4 8FB3004C */  lw        $s3, 0x4c($sp)
/* BFE558 80240CD8 8FB20048 */  lw        $s2, 0x48($sp)
/* BFE55C 80240CDC 8FB10044 */  lw        $s1, 0x44($sp)
/* BFE560 80240CE0 8FB00040 */  lw        $s0, 0x40($sp)
/* BFE564 80240CE4 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* BFE568 80240CE8 D7B80068 */  ldc1      $f24, 0x68($sp)
/* BFE56C 80240CEC D7B60060 */  ldc1      $f22, 0x60($sp)
/* BFE570 80240CF0 D7B40058 */  ldc1      $f20, 0x58($sp)
/* BFE574 80240CF4 03E00008 */  jr        $ra
/* BFE578 80240CF8 27BD0078 */   addiu    $sp, $sp, 0x78
