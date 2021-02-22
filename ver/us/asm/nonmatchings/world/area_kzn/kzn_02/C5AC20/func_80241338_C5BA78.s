.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241338_C5BA78
/* C5BA78 80241338 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C5BA7C 8024133C AFB20030 */  sw        $s2, 0x30($sp)
/* C5BA80 80241340 0080902D */  daddu     $s2, $a0, $zero
/* C5BA84 80241344 AFBF0038 */  sw        $ra, 0x38($sp)
/* C5BA88 80241348 AFB30034 */  sw        $s3, 0x34($sp)
/* C5BA8C 8024134C AFB1002C */  sw        $s1, 0x2c($sp)
/* C5BA90 80241350 AFB00028 */  sw        $s0, 0x28($sp)
/* C5BA94 80241354 F7B60048 */  sdc1      $f22, 0x48($sp)
/* C5BA98 80241358 F7B40040 */  sdc1      $f20, 0x40($sp)
/* C5BA9C 8024135C 8E510148 */  lw        $s1, 0x148($s2)
/* C5BAA0 80241360 86240008 */  lh        $a0, 8($s1)
/* C5BAA4 80241364 0C00EABB */  jal       get_npc_unsafe
/* C5BAA8 80241368 00A0982D */   daddu    $s3, $a1, $zero
/* C5BAAC 8024136C 0040802D */  daddu     $s0, $v0, $zero
/* C5BAB0 80241370 0200202D */  daddu     $a0, $s0, $zero
/* C5BAB4 80241374 C6220088 */  lwc1      $f2, 0x88($s1)
/* C5BAB8 80241378 468010A0 */  cvt.s.w   $f2, $f2
/* C5BABC 8024137C 460010A1 */  cvt.d.s   $f2, $f2
/* C5BAC0 80241380 C604001C */  lwc1      $f4, 0x1c($s0)
/* C5BAC4 80241384 C6000014 */  lwc1      $f0, 0x14($s0)
/* C5BAC8 80241388 8E050018 */  lw        $a1, 0x18($s0)
/* C5BACC 8024138C 46002100 */  add.s     $f4, $f4, $f0
/* C5BAD0 80241390 8E06000C */  lw        $a2, 0xc($s0)
/* C5BAD4 80241394 C6200078 */  lwc1      $f0, 0x78($s1)
/* C5BAD8 80241398 46800020 */  cvt.s.w   $f0, $f0
/* C5BADC 8024139C E604001C */  swc1      $f4, 0x1c($s0)
/* C5BAE0 802413A0 3C014059 */  lui       $at, 0x4059
/* C5BAE4 802413A4 44812800 */  mtc1      $at, $f5
/* C5BAE8 802413A8 44802000 */  mtc1      $zero, $f4
/* C5BAEC 802413AC 46000021 */  cvt.d.s   $f0, $f0
/* C5BAF0 802413B0 46240003 */  div.d     $f0, $f0, $f4
/* C5BAF4 802413B4 46200520 */  cvt.s.d   $f20, $f0
/* C5BAF8 802413B8 46241083 */  div.d     $f2, $f2, $f4
/* C5BAFC 802413BC 0C00EA95 */  jal       npc_move_heading
/* C5BB00 802413C0 462015A0 */   cvt.s.d  $f22, $f2
/* C5BB04 802413C4 C604001C */  lwc1      $f4, 0x1c($s0)
/* C5BB08 802413C8 44801000 */  mtc1      $zero, $f2
/* C5BB0C 802413CC 44801800 */  mtc1      $zero, $f3
/* C5BB10 802413D0 46002021 */  cvt.d.s   $f0, $f4
/* C5BB14 802413D4 4620103E */  c.le.d    $f2, $f0
/* C5BB18 802413D8 00000000 */  nop
/* C5BB1C 802413DC 45000030 */  bc1f      .L802414A0
/* C5BB20 802413E0 00000000 */   nop
/* C5BB24 802413E4 C600003C */  lwc1      $f0, 0x3c($s0)
/* C5BB28 802413E8 46040000 */  add.s     $f0, $f0, $f4
/* C5BB2C 802413EC E600003C */  swc1      $f0, 0x3c($s0)
/* C5BB30 802413F0 8E2200CC */  lw        $v0, 0xcc($s1)
/* C5BB34 802413F4 8C420024 */  lw        $v0, 0x24($v0)
/* C5BB38 802413F8 AE020028 */  sw        $v0, 0x28($s0)
/* C5BB3C 802413FC A2200007 */  sb        $zero, 7($s1)
/* C5BB40 80241400 8E020000 */  lw        $v0, ($s0)
/* C5BB44 80241404 30420008 */  andi      $v0, $v0, 8
/* C5BB48 80241408 14400011 */  bnez      $v0, .L80241450
/* C5BB4C 8024140C 0000102D */   daddu    $v0, $zero, $zero
/* C5BB50 80241410 27A50018 */  addiu     $a1, $sp, 0x18
/* C5BB54 80241414 27A6001C */  addiu     $a2, $sp, 0x1c
/* C5BB58 80241418 C6000038 */  lwc1      $f0, 0x38($s0)
/* C5BB5C 8024141C C602003C */  lwc1      $f2, 0x3c($s0)
/* C5BB60 80241420 C6040040 */  lwc1      $f4, 0x40($s0)
/* C5BB64 80241424 3C01447A */  lui       $at, 0x447a
/* C5BB68 80241428 44813000 */  mtc1      $at, $f6
/* C5BB6C 8024142C 27A20024 */  addiu     $v0, $sp, 0x24
/* C5BB70 80241430 E7A00018 */  swc1      $f0, 0x18($sp)
/* C5BB74 80241434 E7A2001C */  swc1      $f2, 0x1c($sp)
/* C5BB78 80241438 E7A40020 */  swc1      $f4, 0x20($sp)
/* C5BB7C 8024143C E7A60024 */  swc1      $f6, 0x24($sp)
/* C5BB80 80241440 AFA20010 */  sw        $v0, 0x10($sp)
/* C5BB84 80241444 8E040080 */  lw        $a0, 0x80($s0)
/* C5BB88 80241448 0C0372DF */  jal       func_800DCB7C
/* C5BB8C 8024144C 27A70020 */   addiu    $a3, $sp, 0x20
.L80241450:
/* C5BB90 80241450 1040000B */  beqz      $v0, .L80241480
/* C5BB94 80241454 00000000 */   nop
/* C5BB98 80241458 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* C5BB9C 8024145C 46140080 */  add.s     $f2, $f0, $f20
/* C5BBA0 80241460 C600003C */  lwc1      $f0, 0x3c($s0)
/* C5BBA4 80241464 4600103E */  c.le.s    $f2, $f0
/* C5BBA8 80241468 00000000 */  nop
/* C5BBAC 8024146C 4500008D */  bc1f      .L802416A4
/* C5BBB0 80241470 00000000 */   nop
/* C5BBB4 80241474 E602003C */  swc1      $f2, 0x3c($s0)
/* C5BBB8 80241478 080905A9 */  j         .L802416A4
/* C5BBBC 8024147C AE400070 */   sw       $zero, 0x70($s2)
.L80241480:
/* C5BBC0 80241480 C602003C */  lwc1      $f2, 0x3c($s0)
/* C5BBC4 80241484 C6000064 */  lwc1      $f0, 0x64($s0)
/* C5BBC8 80241488 4602003E */  c.le.s    $f0, $f2
/* C5BBCC 8024148C 00000000 */  nop
/* C5BBD0 80241490 45030084 */  bc1tl     .L802416A4
/* C5BBD4 80241494 AE400070 */   sw       $zero, 0x70($s2)
/* C5BBD8 80241498 080905A9 */  j         .L802416A4
/* C5BBDC 8024149C 00000000 */   nop
.L802414A0:
/* C5BBE0 802414A0 4622003C */  c.lt.d    $f0, $f2
/* C5BBE4 802414A4 00000000 */  nop
/* C5BBE8 802414A8 4500007E */  bc1f      .L802416A4
/* C5BBEC 802414AC 00000000 */   nop
/* C5BBF0 802414B0 9602008E */  lhu       $v0, 0x8e($s0)
/* C5BBF4 802414B4 24420001 */  addiu     $v0, $v0, 1
/* C5BBF8 802414B8 A602008E */  sh        $v0, 0x8e($s0)
/* C5BBFC 802414BC 00021400 */  sll       $v0, $v0, 0x10
/* C5BC00 802414C0 8E630020 */  lw        $v1, 0x20($s3)
/* C5BC04 802414C4 00021403 */  sra       $v0, $v0, 0x10
/* C5BC08 802414C8 0043102A */  slt       $v0, $v0, $v1
/* C5BC0C 802414CC 14400026 */  bnez      $v0, .L80241568
/* C5BC10 802414D0 00000000 */   nop
/* C5BC14 802414D4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* C5BC18 802414D8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C5BC1C 802414DC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C5BC20 802414E0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C5BC24 802414E4 A600008E */  sh        $zero, 0x8e($s0)
/* C5BC28 802414E8 8C460028 */  lw        $a2, 0x28($v0)
/* C5BC2C 802414EC 0C00A720 */  jal       atan2
/* C5BC30 802414F0 8C470030 */   lw       $a3, 0x30($v0)
/* C5BC34 802414F4 46000506 */  mov.s     $f20, $f0
/* C5BC38 802414F8 C60C000C */  lwc1      $f12, 0xc($s0)
/* C5BC3C 802414FC 0C00A70A */  jal       get_clamped_angle_diff
/* C5BC40 80241500 4600A386 */   mov.s    $f14, $f20
/* C5BC44 80241504 46000086 */  mov.s     $f2, $f0
/* C5BC48 80241508 8E62001C */  lw        $v0, 0x1c($s3)
/* C5BC4C 8024150C 46001005 */  abs.s     $f0, $f2
/* C5BC50 80241510 44822000 */  mtc1      $v0, $f4
/* C5BC54 80241514 00000000 */  nop
/* C5BC58 80241518 46802120 */  cvt.s.w   $f4, $f4
/* C5BC5C 8024151C 4600203C */  c.lt.s    $f4, $f0
/* C5BC60 80241520 00000000 */  nop
/* C5BC64 80241524 4500000D */  bc1f      .L8024155C
/* C5BC68 80241528 00000000 */   nop
/* C5BC6C 8024152C 44800000 */  mtc1      $zero, $f0
/* C5BC70 80241530 C614000C */  lwc1      $f20, 0xc($s0)
/* C5BC74 80241534 4600103C */  c.lt.s    $f2, $f0
/* C5BC78 80241538 00000000 */  nop
/* C5BC7C 8024153C 45000006 */  bc1f      .L80241558
/* C5BC80 80241540 00021023 */   negu     $v0, $v0
/* C5BC84 80241544 44820000 */  mtc1      $v0, $f0
/* C5BC88 80241548 00000000 */  nop
/* C5BC8C 8024154C 46800020 */  cvt.s.w   $f0, $f0
/* C5BC90 80241550 08090557 */  j         .L8024155C
/* C5BC94 80241554 4600A500 */   add.s    $f20, $f20, $f0
.L80241558:
/* C5BC98 80241558 4604A500 */  add.s     $f20, $f20, $f4
.L8024155C:
/* C5BC9C 8024155C 0C00A6C9 */  jal       clamp_angle
/* C5BCA0 80241560 4600A306 */   mov.s    $f12, $f20
/* C5BCA4 80241564 E600000C */  swc1      $f0, 0xc($s0)
.L80241568:
/* C5BCA8 80241568 8E020000 */  lw        $v0, ($s0)
/* C5BCAC 8024156C 30420008 */  andi      $v0, $v0, 8
/* C5BCB0 80241570 1040000A */  beqz      $v0, .L8024159C
/* C5BCB4 80241574 27A50018 */   addiu    $a1, $sp, 0x18
/* C5BCB8 80241578 C602003C */  lwc1      $f2, 0x3c($s0)
/* C5BCBC 8024157C C600001C */  lwc1      $f0, 0x1c($s0)
/* C5BCC0 80241580 46001080 */  add.s     $f2, $f2, $f0
/* C5BCC4 80241584 4616103C */  c.lt.s    $f2, $f22
/* C5BCC8 80241588 00000000 */  nop
/* C5BCCC 8024158C 45020045 */  bc1fl     .L802416A4
/* C5BCD0 80241590 E602003C */   swc1     $f2, 0x3c($s0)
/* C5BCD4 80241594 080905A8 */  j         .L802416A0
/* C5BCD8 80241598 E616003C */   swc1     $f22, 0x3c($s0)
.L8024159C:
/* C5BCDC 8024159C C6000038 */  lwc1      $f0, 0x38($s0)
/* C5BCE0 802415A0 27A6001C */  addiu     $a2, $sp, 0x1c
/* C5BCE4 802415A4 E7A00018 */  swc1      $f0, 0x18($sp)
/* C5BCE8 802415A8 860200A8 */  lh        $v0, 0xa8($s0)
/* C5BCEC 802415AC C600001C */  lwc1      $f0, 0x1c($s0)
/* C5BCF0 802415B0 C604003C */  lwc1      $f4, 0x3c($s0)
/* C5BCF4 802415B4 44821000 */  mtc1      $v0, $f2
/* C5BCF8 802415B8 00000000 */  nop
/* C5BCFC 802415BC 468010A0 */  cvt.s.w   $f2, $f2
/* C5BD00 802415C0 46000005 */  abs.s     $f0, $f0
/* C5BD04 802415C4 46020000 */  add.s     $f0, $f0, $f2
/* C5BD08 802415C8 C6060040 */  lwc1      $f6, 0x40($s0)
/* C5BD0C 802415CC 27A20024 */  addiu     $v0, $sp, 0x24
/* C5BD10 802415D0 46022100 */  add.s     $f4, $f4, $f2
/* C5BD14 802415D4 3C014024 */  lui       $at, 0x4024
/* C5BD18 802415D8 44811800 */  mtc1      $at, $f3
/* C5BD1C 802415DC 44801000 */  mtc1      $zero, $f2
/* C5BD20 802415E0 46000021 */  cvt.d.s   $f0, $f0
/* C5BD24 802415E4 46220000 */  add.d     $f0, $f0, $f2
/* C5BD28 802415E8 E7A60020 */  swc1      $f6, 0x20($sp)
/* C5BD2C 802415EC E7A4001C */  swc1      $f4, 0x1c($sp)
/* C5BD30 802415F0 46200020 */  cvt.s.d   $f0, $f0
/* C5BD34 802415F4 E7A00024 */  swc1      $f0, 0x24($sp)
/* C5BD38 802415F8 AFA20010 */  sw        $v0, 0x10($sp)
/* C5BD3C 802415FC 8E040080 */  lw        $a0, 0x80($s0)
/* C5BD40 80241600 0C0372DF */  jal       func_800DCB7C
/* C5BD44 80241604 27A70020 */   addiu    $a3, $sp, 0x20
/* C5BD48 80241608 10400015 */  beqz      $v0, .L80241660
/* C5BD4C 8024160C 00000000 */   nop
/* C5BD50 80241610 860200A8 */  lh        $v0, 0xa8($s0)
/* C5BD54 80241614 C604001C */  lwc1      $f4, 0x1c($s0)
/* C5BD58 80241618 44820000 */  mtc1      $v0, $f0
/* C5BD5C 8024161C 00000000 */  nop
/* C5BD60 80241620 46800020 */  cvt.s.w   $f0, $f0
/* C5BD64 80241624 46002085 */  abs.s     $f2, $f4
/* C5BD68 80241628 46020000 */  add.s     $f0, $f0, $f2
/* C5BD6C 8024162C C7A20024 */  lwc1      $f2, 0x24($sp)
/* C5BD70 80241630 4600103E */  c.le.s    $f2, $f0
/* C5BD74 80241634 00000000 */  nop
/* C5BD78 80241638 45000005 */  bc1f      .L80241650
/* C5BD7C 8024163C 00000000 */   nop
/* C5BD80 80241640 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* C5BD84 80241644 AE00001C */  sw        $zero, 0x1c($s0)
/* C5BD88 80241648 080905A9 */  j         .L802416A4
/* C5BD8C 8024164C E600003C */   swc1     $f0, 0x3c($s0)
.L80241650:
/* C5BD90 80241650 C600003C */  lwc1      $f0, 0x3c($s0)
/* C5BD94 80241654 46040000 */  add.s     $f0, $f0, $f4
/* C5BD98 80241658 080905A9 */  j         .L802416A4
/* C5BD9C 8024165C E600003C */   swc1     $f0, 0x3c($s0)
.L80241660:
/* C5BDA0 80241660 C606003C */  lwc1      $f6, 0x3c($s0)
/* C5BDA4 80241664 860200A8 */  lh        $v0, 0xa8($s0)
/* C5BDA8 80241668 46163081 */  sub.s     $f2, $f6, $f22
/* C5BDAC 8024166C 44820000 */  mtc1      $v0, $f0
/* C5BDB0 80241670 00000000 */  nop
/* C5BDB4 80241674 46800020 */  cvt.s.w   $f0, $f0
/* C5BDB8 80241678 46001080 */  add.s     $f2, $f2, $f0
/* C5BDBC 8024167C C604001C */  lwc1      $f4, 0x1c($s0)
/* C5BDC0 80241680 46002005 */  abs.s     $f0, $f4
/* C5BDC4 80241684 4602003C */  c.lt.s    $f0, $f2
/* C5BDC8 80241688 00000000 */  nop
/* C5BDCC 8024168C 45020005 */  bc1fl     .L802416A4
/* C5BDD0 80241690 AE00001C */   sw       $zero, 0x1c($s0)
/* C5BDD4 80241694 46043000 */  add.s     $f0, $f6, $f4
/* C5BDD8 80241698 080905A9 */  j         .L802416A4
/* C5BDDC 8024169C E600003C */   swc1     $f0, 0x3c($s0)
.L802416A0:
/* C5BDE0 802416A0 AE00001C */  sw        $zero, 0x1c($s0)
.L802416A4:
/* C5BDE4 802416A4 8FBF0038 */  lw        $ra, 0x38($sp)
/* C5BDE8 802416A8 8FB30034 */  lw        $s3, 0x34($sp)
/* C5BDEC 802416AC 8FB20030 */  lw        $s2, 0x30($sp)
/* C5BDF0 802416B0 8FB1002C */  lw        $s1, 0x2c($sp)
/* C5BDF4 802416B4 8FB00028 */  lw        $s0, 0x28($sp)
/* C5BDF8 802416B8 D7B60048 */  ldc1      $f22, 0x48($sp)
/* C5BDFC 802416BC D7B40040 */  ldc1      $f20, 0x40($sp)
/* C5BE00 802416C0 03E00008 */  jr        $ra
/* C5BE04 802416C4 27BD0050 */   addiu    $sp, $sp, 0x50
