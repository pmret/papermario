.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240098_BBD238
/* BBD238 80240098 27BDFF68 */  addiu     $sp, $sp, -0x98
/* BBD23C 8024009C AFB40078 */  sw        $s4, 0x78($sp)
/* BBD240 802400A0 0080A02D */  daddu     $s4, $a0, $zero
/* BBD244 802400A4 AFB5007C */  sw        $s5, 0x7c($sp)
/* BBD248 802400A8 3C158011 */  lui       $s5, %hi(gPlayerStatus)
/* BBD24C 802400AC 26B5EFC8 */  addiu     $s5, $s5, %lo(gPlayerStatus)
/* BBD250 802400B0 AFBF0080 */  sw        $ra, 0x80($sp)
/* BBD254 802400B4 AFB30074 */  sw        $s3, 0x74($sp)
/* BBD258 802400B8 AFB20070 */  sw        $s2, 0x70($sp)
/* BBD25C 802400BC AFB1006C */  sw        $s1, 0x6c($sp)
/* BBD260 802400C0 AFB00068 */  sw        $s0, 0x68($sp)
/* BBD264 802400C4 F7B60090 */  sdc1      $f22, 0x90($sp)
/* BBD268 802400C8 F7B40088 */  sdc1      $f20, 0x88($sp)
/* BBD26C 802400CC 10A00029 */  beqz      $a1, .L80240174
/* BBD270 802400D0 8E90000C */   lw       $s0, 0xc($s4)
/* BBD274 802400D4 0C00AB39 */  jal       heap_malloc
/* BBD278 802400D8 2404006C */   addiu    $a0, $zero, 0x6c
/* BBD27C 802400DC 0040882D */  daddu     $s1, $v0, $zero
/* BBD280 802400E0 0280202D */  daddu     $a0, $s4, $zero
/* BBD284 802400E4 0000982D */  daddu     $s3, $zero, $zero
/* BBD288 802400E8 AE910074 */  sw        $s1, 0x74($s4)
/* BBD28C 802400EC 8E050000 */  lw        $a1, ($s0)
/* BBD290 802400F0 3C108024 */  lui       $s0, %hi(D_80241C58_BBEDF8)
/* BBD294 802400F4 26101C58 */  addiu     $s0, $s0, %lo(D_80241C58_BBEDF8)
/* BBD298 802400F8 0C0B1EAF */  jal       get_variable
/* BBD29C 802400FC 0220902D */   daddu    $s2, $s1, $zero
/* BBD2A0 80240100 AE220008 */  sw        $v0, 8($s1)
/* BBD2A4 80240104 AC510000 */  sw        $s1, ($v0)
.L80240108:
/* BBD2A8 80240108 8E040000 */  lw        $a0, ($s0)
/* BBD2AC 8024010C 26100004 */  addiu     $s0, $s0, 4
/* BBD2B0 80240110 0C046C04 */  jal       get_model_list_index_from_tree_index
/* BBD2B4 80240114 26730001 */   addiu    $s3, $s3, 1
/* BBD2B8 80240118 0C046B4C */  jal       get_model_from_list_index
/* BBD2BC 8024011C 0040202D */   daddu    $a0, $v0, $zero
/* BBD2C0 80240120 AE42005C */  sw        $v0, 0x5c($s2)
/* BBD2C4 80240124 2A620004 */  slti      $v0, $s3, 4
/* BBD2C8 80240128 1440FFF7 */  bnez      $v0, .L80240108
/* BBD2CC 8024012C 26520004 */   addiu    $s2, $s2, 4
/* BBD2D0 80240130 2625001C */  addiu     $a1, $s1, 0x1c
/* BBD2D4 80240134 8E32005C */  lw        $s2, 0x5c($s1)
/* BBD2D8 80240138 4480B000 */  mtc1      $zero, $f22
/* BBD2DC 8024013C 0C00A5C8 */  jal       copy_matrix
/* BBD2E0 80240140 26440058 */   addiu    $a0, $s2, 0x58
/* BBD2E4 80240144 3C014334 */  lui       $at, 0x4334
/* BBD2E8 80240148 44810000 */  mtc1      $at, $f0
/* BBD2EC 8024014C 3C014120 */  lui       $at, 0x4120
/* BBD2F0 80240150 44811000 */  mtc1      $at, $f2
/* BBD2F4 80240154 E6360010 */  swc1      $f22, 0x10($s1)
/* BBD2F8 80240158 E6360014 */  swc1      $f22, 0x14($s1)
/* BBD2FC 8024015C AE200000 */  sw        $zero, ($s1)
/* BBD300 80240160 E620000C */  swc1      $f0, 0xc($s1)
/* BBD304 80240164 E6220018 */  swc1      $f2, 0x18($s1)
/* BBD308 80240168 AE800070 */  sw        $zero, 0x70($s4)
/* BBD30C 8024016C AE800078 */  sw        $zero, 0x78($s4)
/* BBD310 80240170 AE80007C */  sw        $zero, 0x7c($s4)
.L80240174:
/* BBD314 80240174 8E910074 */  lw        $s1, 0x74($s4)
/* BBD318 80240178 8E32005C */  lw        $s2, 0x5c($s1)
/* BBD31C 8024017C 8E220008 */  lw        $v0, 8($s1)
/* BBD320 80240180 C6360010 */  lwc1      $f22, 0x10($s1)
/* BBD324 80240184 8C430004 */  lw        $v1, 4($v0)
/* BBD328 80240188 24020002 */  addiu     $v0, $zero, 2
/* BBD32C 8024018C 14620006 */  bne       $v1, $v0, .L802401A8
/* BBD330 80240190 2404000A */   addiu    $a0, $zero, 0xa
/* BBD334 80240194 AE840070 */  sw        $a0, 0x70($s4)
/* BBD338 80240198 8E230008 */  lw        $v1, 8($s1)
/* BBD33C 8024019C 24020003 */  addiu     $v0, $zero, 3
/* BBD340 802401A0 AC620004 */  sw        $v0, 4($v1)
/* BBD344 802401A4 AE240004 */  sw        $a0, 4($s1)
.L802401A8:
/* BBD348 802401A8 8E830070 */  lw        $v1, 0x70($s4)
/* BBD34C 802401AC 2C62000C */  sltiu     $v0, $v1, 0xc
/* BBD350 802401B0 10400076 */  beqz      $v0, .L8024038C
/* BBD354 802401B4 00031080 */   sll      $v0, $v1, 2
/* BBD358 802401B8 3C018024 */  lui       $at, %hi(jtbl_802458C0_BC2A60)
/* BBD35C 802401BC 00220821 */  addu      $at, $at, $v0
/* BBD360 802401C0 8C2258C0 */  lw        $v0, %lo(jtbl_802458C0_BC2A60)($at)
/* BBD364 802401C4 00400008 */  jr        $v0
/* BBD368 802401C8 00000000 */   nop
glabel L802401CC_BBD36C
/* BBD36C 802401CC 8E220008 */  lw        $v0, 8($s1)
/* BBD370 802401D0 8C420004 */  lw        $v0, 4($v0)
/* BBD374 802401D4 1040006D */  beqz      $v0, .L8024038C
/* BBD378 802401D8 24020023 */   addiu    $v0, $zero, 0x23
/* BBD37C 802401DC AE220004 */  sw        $v0, 4($s1)
/* BBD380 802401E0 24020001 */  addiu     $v0, $zero, 1
/* BBD384 802401E4 4480B000 */  mtc1      $zero, $f22
/* BBD388 802401E8 3C014120 */  lui       $at, 0x4120
/* BBD38C 802401EC 44810000 */  mtc1      $at, $f0
/* BBD390 802401F0 8E230000 */  lw        $v1, ($s1)
/* BBD394 802401F4 3C014334 */  lui       $at, 0x4334
/* BBD398 802401F8 44811000 */  mtc1      $at, $f2
/* BBD39C 802401FC 34630003 */  ori       $v1, $v1, 3
/* BBD3A0 80240200 E6360010 */  swc1      $f22, 0x10($s1)
/* BBD3A4 80240204 E6360014 */  swc1      $f22, 0x14($s1)
/* BBD3A8 80240208 E6200018 */  swc1      $f0, 0x18($s1)
/* BBD3AC 8024020C E622000C */  swc1      $f2, 0xc($s1)
/* BBD3B0 80240210 AE230000 */  sw        $v1, ($s1)
/* BBD3B4 80240214 080900E3 */  j         .L8024038C
/* BBD3B8 80240218 AE820070 */   sw       $v0, 0x70($s4)
glabel L8024021C_BBD3BC
/* BBD3BC 8024021C 8E220004 */  lw        $v0, 4($s1)
/* BBD3C0 80240220 2403FFFF */  addiu     $v1, $zero, -1
/* BBD3C4 80240224 2442FFFF */  addiu     $v0, $v0, -1
/* BBD3C8 80240228 14430058 */  bne       $v0, $v1, .L8024038C
/* BBD3CC 8024022C AE220004 */   sw       $v0, 4($s1)
/* BBD3D0 80240230 24020002 */  addiu     $v0, $zero, 2
/* BBD3D4 80240234 080900E3 */  j         .L8024038C
/* BBD3D8 80240238 AE820070 */   sw       $v0, 0x70($s4)
glabel L8024023C_BBD3DC
/* BBD3DC 8024023C C6200010 */  lwc1      $f0, 0x10($s1)
/* BBD3E0 80240240 3C01BFBB */  lui       $at, 0xbfbb
/* BBD3E4 80240244 3421BBBC */  ori       $at, $at, 0xbbbc
/* BBD3E8 80240248 44811000 */  mtc1      $at, $f2
/* BBD3EC 8024024C 00000000 */  nop
/* BBD3F0 80240250 46020000 */  add.s     $f0, $f0, $f2
/* BBD3F4 80240254 3C01C35C */  lui       $at, 0xc35c
/* BBD3F8 80240258 44811000 */  mtc1      $at, $f2
/* BBD3FC 8024025C 00000000 */  nop
/* BBD400 80240260 4602003C */  c.lt.s    $f0, $f2
/* BBD404 80240264 00000000 */  nop
/* BBD408 80240268 45000048 */  bc1f      .L8024038C
/* BBD40C 8024026C E6200010 */   swc1     $f0, 0x10($s1)
/* BBD410 80240270 24020003 */  addiu     $v0, $zero, 3
/* BBD414 80240274 E6220010 */  swc1      $f2, 0x10($s1)
/* BBD418 80240278 080900E3 */  j         .L8024038C
/* BBD41C 8024027C AE820070 */   sw       $v0, 0x70($s4)
glabel L80240280_BBD420
/* BBD420 80240280 C6200018 */  lwc1      $f0, 0x18($s1)
/* BBD424 80240284 3C013D88 */  lui       $at, 0x3d88
/* BBD428 80240288 34218889 */  ori       $at, $at, 0x8889
/* BBD42C 8024028C 44811000 */  mtc1      $at, $f2
/* BBD430 80240290 00000000 */  nop
/* BBD434 80240294 46020001 */  sub.s     $f0, $f0, $f2
/* BBD438 80240298 44801000 */  mtc1      $zero, $f2
/* BBD43C 8024029C 00000000 */  nop
/* BBD440 802402A0 4602003C */  c.lt.s    $f0, $f2
/* BBD444 802402A4 00000000 */  nop
/* BBD448 802402A8 45000038 */  bc1f      .L8024038C
/* BBD44C 802402AC E6200018 */   swc1     $f0, 0x18($s1)
/* BBD450 802402B0 24020004 */  addiu     $v0, $zero, 4
/* BBD454 802402B4 E6220018 */  swc1      $f2, 0x18($s1)
/* BBD458 802402B8 AE820070 */  sw        $v0, 0x70($s4)
/* BBD45C 802402BC 8E220000 */  lw        $v0, ($s1)
/* BBD460 802402C0 2403FFFE */  addiu     $v1, $zero, -2
/* BBD464 802402C4 00431024 */  and       $v0, $v0, $v1
/* BBD468 802402C8 34420004 */  ori       $v0, $v0, 4
/* BBD46C 802402CC 080900E3 */  j         .L8024038C
/* BBD470 802402D0 AE220000 */   sw       $v0, ($s1)
glabel L802402D4_BBD474
/* BBD474 802402D4 8E220004 */  lw        $v0, 4($s1)
/* BBD478 802402D8 2403FFFF */  addiu     $v1, $zero, -1
/* BBD47C 802402DC 2442FFFF */  addiu     $v0, $v0, -1
/* BBD480 802402E0 1443002A */  bne       $v0, $v1, .L8024038C
/* BBD484 802402E4 AE220004 */   sw       $v0, 4($s1)
/* BBD488 802402E8 2402000B */  addiu     $v0, $zero, 0xb
/* BBD48C 802402EC 080900E3 */  j         .L8024038C
/* BBD490 802402F0 AE820070 */   sw       $v0, 0x70($s4)
glabel L802402F4_BBD494
/* BBD494 802402F4 0000202D */  daddu     $a0, $zero, $zero
/* BBD498 802402F8 2403FFFB */  addiu     $v1, $zero, -5
/* BBD49C 802402FC C6200010 */  lwc1      $f0, 0x10($s1)
/* BBD4A0 80240300 3C014080 */  lui       $at, 0x4080
/* BBD4A4 80240304 44811000 */  mtc1      $at, $f2
/* BBD4A8 80240308 8E220000 */  lw        $v0, ($s1)
/* BBD4AC 8024030C 44802000 */  mtc1      $zero, $f4
/* BBD4B0 80240310 46020000 */  add.s     $f0, $f0, $f2
/* BBD4B4 80240314 00431024 */  and       $v0, $v0, $v1
/* BBD4B8 80240318 AE220000 */  sw        $v0, ($s1)
/* BBD4BC 8024031C 4600203E */  c.le.s    $f4, $f0
/* BBD4C0 80240320 00000000 */  nop
/* BBD4C4 80240324 45000003 */  bc1f      .L80240334
/* BBD4C8 80240328 E6200010 */   swc1     $f0, 0x10($s1)
/* BBD4CC 8024032C E6240010 */  swc1      $f4, 0x10($s1)
/* BBD4D0 80240330 24040001 */  addiu     $a0, $zero, 1
.L80240334:
/* BBD4D4 80240334 C6200018 */  lwc1      $f0, 0x18($s1)
/* BBD4D8 80240338 3C013E4C */  lui       $at, 0x3e4c
/* BBD4DC 8024033C 3421CCCD */  ori       $at, $at, 0xcccd
/* BBD4E0 80240340 44811000 */  mtc1      $at, $f2
/* BBD4E4 80240344 00000000 */  nop
/* BBD4E8 80240348 46020001 */  sub.s     $f0, $f0, $f2
/* BBD4EC 8024034C 4604003C */  c.lt.s    $f0, $f4
/* BBD4F0 80240350 00000000 */  nop
/* BBD4F4 80240354 45000007 */  bc1f      .L80240374
/* BBD4F8 80240358 E6200018 */   swc1     $f0, 0x18($s1)
/* BBD4FC 8024035C 24840001 */  addiu     $a0, $a0, 1
/* BBD500 80240360 8E220000 */  lw        $v0, ($s1)
/* BBD504 80240364 2403FFFE */  addiu     $v1, $zero, -2
/* BBD508 80240368 E6240018 */  swc1      $f4, 0x18($s1)
/* BBD50C 8024036C 00431024 */  and       $v0, $v0, $v1
/* BBD510 80240370 AE220000 */  sw        $v0, ($s1)
.L80240374:
/* BBD514 80240374 24020002 */  addiu     $v0, $zero, 2
/* BBD518 80240378 14820004 */  bne       $a0, $v0, .L8024038C
/* BBD51C 8024037C 00000000 */   nop
/* BBD520 80240380 8E220008 */  lw        $v0, 8($s1)
/* BBD524 80240384 AC400004 */  sw        $zero, 4($v0)
/* BBD528 80240388 AE800070 */  sw        $zero, 0x70($s4)
.L8024038C:
glabel L8024038C_BBD52C
/* BBD52C 8024038C 8E220000 */  lw        $v0, ($s1)
/* BBD530 80240390 30420001 */  andi      $v0, $v0, 1
/* BBD534 80240394 10400020 */  beqz      $v0, .L80240418
/* BBD538 80240398 00000000 */   nop
/* BBD53C 8024039C C620000C */  lwc1      $f0, 0xc($s1)
/* BBD540 802403A0 3C014066 */  lui       $at, 0x4066
/* BBD544 802403A4 34216666 */  ori       $at, $at, 0x6666
/* BBD548 802403A8 44816000 */  mtc1      $at, $f12
/* BBD54C 802403AC 0C00A6C9 */  jal       clamp_angle
/* BBD550 802403B0 460C0300 */   add.s    $f12, $f0, $f12
/* BBD554 802403B4 46000306 */  mov.s     $f12, $f0
/* BBD558 802403B8 0C00A8BB */  jal       sin_deg
/* BBD55C 802403BC E62C000C */   swc1     $f12, 0xc($s1)
/* BBD560 802403C0 C6240014 */  lwc1      $f4, 0x14($s1)
/* BBD564 802403C4 44803000 */  mtc1      $zero, $f6
/* BBD568 802403C8 C6220018 */  lwc1      $f2, 0x18($s1)
/* BBD56C 802403CC 46062032 */  c.eq.s    $f4, $f6
/* BBD570 802403D0 46020502 */  mul.s     $f20, $f0, $f2
/* BBD574 802403D4 00000000 */  nop
/* BBD578 802403D8 45000005 */  bc1f      .L802403F0
/* BBD57C 802403DC 00000000 */   nop
/* BBD580 802403E0 3C013F80 */  lui       $at, 0x3f80
/* BBD584 802403E4 44810000 */  mtc1      $at, $f0
/* BBD588 802403E8 00000000 */  nop
/* BBD58C 802403EC E6200014 */  swc1      $f0, 0x14($s1)
.L802403F0:
/* BBD590 802403F0 C6200014 */  lwc1      $f0, 0x14($s1)
/* BBD594 802403F4 4600A002 */  mul.s     $f0, $f20, $f0
/* BBD598 802403F8 00000000 */  nop
/* BBD59C 802403FC 4606003E */  c.le.s    $f0, $f6
/* BBD5A0 80240400 00000000 */  nop
/* BBD5A4 80240404 45000003 */  bc1f      .L80240414
/* BBD5A8 80240408 2404009D */   addiu    $a0, $zero, 0x9d
/* BBD5AC 8024040C 0C052736 */  jal       play_sound_at_player
/* BBD5B0 80240410 0000282D */   daddu    $a1, $zero, $zero
.L80240414:
/* BBD5B4 80240414 E6340014 */  swc1      $f20, 0x14($s1)
.L80240418:
/* BBD5B8 80240418 8E820078 */  lw        $v0, 0x78($s4)
/* BBD5BC 8024041C 14400013 */  bnez      $v0, .L8024046C
/* BBD5C0 80240420 00000000 */   nop
/* BBD5C4 80240424 C6200010 */  lwc1      $f0, 0x10($s1)
/* BBD5C8 80240428 46160032 */  c.eq.s    $f0, $f22
/* BBD5CC 8024042C 00000000 */  nop
/* BBD5D0 80240430 45010017 */  bc1t      .L80240490
/* BBD5D4 80240434 0280202D */   daddu    $a0, $s4, $zero
/* BBD5D8 80240438 3C048000 */  lui       $a0, 0x8000
/* BBD5DC 8024043C 3C0643DC */  lui       $a2, 0x43dc
/* BBD5E0 80240440 3C014387 */  lui       $at, 0x4387
/* BBD5E4 80240444 34218000 */  ori       $at, $at, 0x8000
/* BBD5E8 80240448 44810000 */  mtc1      $at, $f0
/* BBD5EC 8024044C 3484000F */  ori       $a0, $a0, 0xf
/* BBD5F0 80240450 E7A00010 */  swc1      $f0, 0x10($sp)
/* BBD5F4 80240454 8E270010 */  lw        $a3, 0x10($s1)
/* BBD5F8 80240458 0C052757 */  jal       play_sound_at_position
/* BBD5FC 8024045C 0000282D */   daddu    $a1, $zero, $zero
/* BBD600 80240460 24020001 */  addiu     $v0, $zero, 1
/* BBD604 80240464 08090123 */  j         .L8024048C
/* BBD608 80240468 AE820078 */   sw       $v0, 0x78($s4)
.L8024046C:
/* BBD60C 8024046C C6200010 */  lwc1      $f0, 0x10($s1)
/* BBD610 80240470 46160032 */  c.eq.s    $f0, $f22
/* BBD614 80240474 00000000 */  nop
/* BBD618 80240478 45000004 */  bc1f      .L8024048C
/* BBD61C 8024047C 3C048000 */   lui      $a0, 0x8000
/* BBD620 80240480 0C05271B */  jal       stop_sound
/* BBD624 80240484 3484000F */   ori      $a0, $a0, 0xf
/* BBD628 80240488 AE800078 */  sw        $zero, 0x78($s4)
.L8024048C:
/* BBD62C 8024048C 0280202D */  daddu     $a0, $s4, $zero
.L80240490:
/* BBD630 80240490 3C05FD05 */  lui       $a1, 0xfd05
/* BBD634 80240494 0C0B1EAF */  jal       get_variable
/* BBD638 80240498 34A50F8B */   ori      $a1, $a1, 0xf8b
/* BBD63C 8024049C 8E83007C */  lw        $v1, 0x7c($s4)
/* BBD640 802404A0 14600015 */  bnez      $v1, .L802404F8
/* BBD644 802404A4 0040802D */   daddu    $s0, $v0, $zero
/* BBD648 802404A8 8E820088 */  lw        $v0, 0x88($s4)
/* BBD64C 802404AC 12020019 */  beq       $s0, $v0, .L80240514
/* BBD650 802404B0 2404006E */   addiu    $a0, $zero, 0x6e
/* BBD654 802404B4 27A50058 */  addiu     $a1, $sp, 0x58
/* BBD658 802404B8 27A6005C */  addiu     $a2, $sp, 0x5c
/* BBD65C 802404BC 0C016F84 */  jal       get_collider_center
/* BBD660 802404C0 27A70060 */   addiu    $a3, $sp, 0x60
/* BBD664 802404C4 3C048000 */  lui       $a0, 0x8000
/* BBD668 802404C8 34840010 */  ori       $a0, $a0, 0x10
/* BBD66C 802404CC C7A00058 */  lwc1      $f0, 0x58($sp)
/* BBD670 802404D0 C7A2005C */  lwc1      $f2, 0x5c($sp)
/* BBD674 802404D4 44060000 */  mfc1      $a2, $f0
/* BBD678 802404D8 44071000 */  mfc1      $a3, $f2
/* BBD67C 802404DC C7A00060 */  lwc1      $f0, 0x60($sp)
/* BBD680 802404E0 0000282D */  daddu     $a1, $zero, $zero
/* BBD684 802404E4 0C052757 */  jal       play_sound_at_position
/* BBD688 802404E8 E7A00010 */   swc1     $f0, 0x10($sp)
/* BBD68C 802404EC 24020001 */  addiu     $v0, $zero, 1
/* BBD690 802404F0 08090145 */  j         .L80240514
/* BBD694 802404F4 AE82007C */   sw       $v0, 0x7c($s4)
.L802404F8:
/* BBD698 802404F8 8E820088 */  lw        $v0, 0x88($s4)
/* BBD69C 802404FC 56020006 */  bnel      $s0, $v0, .L80240518
/* BBD6A0 80240500 AE900088 */   sw       $s0, 0x88($s4)
/* BBD6A4 80240504 3C048000 */  lui       $a0, 0x8000
/* BBD6A8 80240508 0C05271B */  jal       stop_sound
/* BBD6AC 8024050C 34840010 */   ori      $a0, $a0, 0x10
/* BBD6B0 80240510 AE80007C */  sw        $zero, 0x7c($s4)
.L80240514:
/* BBD6B4 80240514 AE900088 */  sw        $s0, 0x88($s4)
.L80240518:
/* BBD6B8 80240518 26500058 */  addiu     $s0, $s2, 0x58
/* BBD6BC 8024051C C6200010 */  lwc1      $f0, 0x10($s1)
/* BBD6C0 80240520 3C014396 */  lui       $at, 0x4396
/* BBD6C4 80240524 4481B000 */  mtc1      $at, $f22
/* BBD6C8 80240528 4480A000 */  mtc1      $zero, $f20
/* BBD6CC 8024052C 46160001 */  sub.s     $f0, $f0, $f22
/* BBD6D0 80240530 4405A000 */  mfc1      $a1, $f20
/* BBD6D4 80240534 4407A000 */  mfc1      $a3, $f20
/* BBD6D8 80240538 44060000 */  mfc1      $a2, $f0
/* BBD6DC 8024053C 0C019E40 */  jal       guTranslateF
/* BBD6E0 80240540 0200202D */   daddu    $a0, $s0, $zero
/* BBD6E4 80240544 4406A000 */  mfc1      $a2, $f20
/* BBD6E8 80240548 4407A000 */  mfc1      $a3, $f20
/* BBD6EC 8024054C 3C013F80 */  lui       $at, 0x3f80
/* BBD6F0 80240550 44810000 */  mtc1      $at, $f0
/* BBD6F4 80240554 24130001 */  addiu     $s3, $zero, 1
/* BBD6F8 80240558 E7A00010 */  swc1      $f0, 0x10($sp)
/* BBD6FC 8024055C 8E250014 */  lw        $a1, 0x14($s1)
/* BBD700 80240560 0C019EC8 */  jal       guRotateF
/* BBD704 80240564 27A40018 */   addiu    $a0, $sp, 0x18
/* BBD708 80240568 0200202D */  daddu     $a0, $s0, $zero
/* BBD70C 8024056C 27A50018 */  addiu     $a1, $sp, 0x18
/* BBD710 80240570 0C019D80 */  jal       guMtxCatF
/* BBD714 80240574 0200302D */   daddu    $a2, $s0, $zero
/* BBD718 80240578 27A40018 */  addiu     $a0, $sp, 0x18
/* BBD71C 8024057C 4405A000 */  mfc1      $a1, $f20
/* BBD720 80240580 4406B000 */  mfc1      $a2, $f22
/* BBD724 80240584 0C019E40 */  jal       guTranslateF
/* BBD728 80240588 00A0382D */   daddu    $a3, $a1, $zero
/* BBD72C 8024058C 0200202D */  daddu     $a0, $s0, $zero
/* BBD730 80240590 27A50018 */  addiu     $a1, $sp, 0x18
/* BBD734 80240594 0C019D80 */  jal       guMtxCatF
/* BBD738 80240598 0200302D */   daddu    $a2, $s0, $zero
/* BBD73C 8024059C 2624001C */  addiu     $a0, $s1, 0x1c
/* BBD740 802405A0 0200282D */  daddu     $a1, $s0, $zero
/* BBD744 802405A4 0C019D80 */  jal       guMtxCatF
/* BBD748 802405A8 00A0302D */   daddu    $a2, $a1, $zero
/* BBD74C 802405AC 96420000 */  lhu       $v0, ($s2)
/* BBD750 802405B0 26300004 */  addiu     $s0, $s1, 4
/* BBD754 802405B4 34421400 */  ori       $v0, $v0, 0x1400
/* BBD758 802405B8 A6420000 */  sh        $v0, ($s2)
.L802405BC:
/* BBD75C 802405BC 8E05005C */  lw        $a1, 0x5c($s0)
/* BBD760 802405C0 26440058 */  addiu     $a0, $s2, 0x58
/* BBD764 802405C4 0C00A5C8 */  jal       copy_matrix
/* BBD768 802405C8 24A50058 */   addiu    $a1, $a1, 0x58
/* BBD76C 802405CC 8E03005C */  lw        $v1, 0x5c($s0)
/* BBD770 802405D0 26730001 */  addiu     $s3, $s3, 1
/* BBD774 802405D4 94620000 */  lhu       $v0, ($v1)
/* BBD778 802405D8 34421400 */  ori       $v0, $v0, 0x1400
/* BBD77C 802405DC A4620000 */  sh        $v0, ($v1)
/* BBD780 802405E0 2A620004 */  slti      $v0, $s3, 4
/* BBD784 802405E4 1440FFF5 */  bnez      $v0, .L802405BC
/* BBD788 802405E8 26100004 */   addiu    $s0, $s0, 4
/* BBD78C 802405EC 8E220000 */  lw        $v0, ($s1)
/* BBD790 802405F0 30420002 */  andi      $v0, $v0, 2
/* BBD794 802405F4 10400021 */  beqz      $v0, .L8024067C
/* BBD798 802405F8 00000000 */   nop
/* BBD79C 802405FC 0C00A8BB */  jal       sin_deg
/* BBD7A0 80240600 C62C0014 */   lwc1     $f12, 0x14($s1)
/* BBD7A4 80240604 C6220010 */  lwc1      $f2, 0x10($s1)
/* BBD7A8 80240608 3C014396 */  lui       $at, 0x4396
/* BBD7AC 8024060C 4481A000 */  mtc1      $at, $f20
/* BBD7B0 80240610 00000000 */  nop
/* BBD7B4 80240614 46141081 */  sub.s     $f2, $f2, $f20
/* BBD7B8 80240618 46000007 */  neg.s     $f0, $f0
/* BBD7BC 8024061C 46020002 */  mul.s     $f0, $f0, $f2
/* BBD7C0 80240620 00000000 */  nop
/* BBD7C4 80240624 3C0143DE */  lui       $at, 0x43de
/* BBD7C8 80240628 34218000 */  ori       $at, $at, 0x8000
/* BBD7CC 8024062C 44811000 */  mtc1      $at, $f2
/* BBD7D0 80240630 00000000 */  nop
/* BBD7D4 80240634 46020000 */  add.s     $f0, $f0, $f2
/* BBD7D8 80240638 E6A00028 */  swc1      $f0, 0x28($s5)
/* BBD7DC 8024063C 0C00A8D4 */  jal       cos_deg
/* BBD7E0 80240640 C62C0014 */   lwc1     $f12, 0x14($s1)
/* BBD7E4 80240644 C6220010 */  lwc1      $f2, 0x10($s1)
/* BBD7E8 80240648 46141081 */  sub.s     $f2, $f2, $f20
/* BBD7EC 8024064C 46020002 */  mul.s     $f0, $f0, $f2
/* BBD7F0 80240650 00000000 */  nop
/* BBD7F4 80240654 3C014307 */  lui       $at, 0x4307
/* BBD7F8 80240658 44811000 */  mtc1      $at, $f2
/* BBD7FC 8024065C 00000000 */  nop
/* BBD800 80240660 46020001 */  sub.s     $f0, $f0, $f2
/* BBD804 80240664 3C01438B */  lui       $at, 0x438b
/* BBD808 80240668 34218000 */  ori       $at, $at, 0x8000
/* BBD80C 8024066C 44811000 */  mtc1      $at, $f2
/* BBD810 80240670 46140000 */  add.s     $f0, $f0, $f20
/* BBD814 80240674 E6A20030 */  swc1      $f2, 0x30($s5)
/* BBD818 80240678 E6A0002C */  swc1      $f0, 0x2c($s5)
.L8024067C:
/* BBD81C 8024067C 8FBF0080 */  lw        $ra, 0x80($sp)
/* BBD820 80240680 8FB5007C */  lw        $s5, 0x7c($sp)
/* BBD824 80240684 8FB40078 */  lw        $s4, 0x78($sp)
/* BBD828 80240688 8FB30074 */  lw        $s3, 0x74($sp)
/* BBD82C 8024068C 8FB20070 */  lw        $s2, 0x70($sp)
/* BBD830 80240690 8FB1006C */  lw        $s1, 0x6c($sp)
/* BBD834 80240694 8FB00068 */  lw        $s0, 0x68($sp)
/* BBD838 80240698 D7B60090 */  ldc1      $f22, 0x90($sp)
/* BBD83C 8024069C D7B40088 */  ldc1      $f20, 0x88($sp)
/* BBD840 802406A0 0000102D */  daddu     $v0, $zero, $zero
/* BBD844 802406A4 03E00008 */  jr        $ra
/* BBD848 802406A8 27BD0098 */   addiu    $sp, $sp, 0x98
