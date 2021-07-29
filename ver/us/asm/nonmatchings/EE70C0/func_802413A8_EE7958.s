.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413A8_EE7958
/* EE7958 802413A8 27BDFF88 */  addiu     $sp, $sp, -0x78
/* EE795C 802413AC AFB3004C */  sw        $s3, 0x4c($sp)
/* EE7960 802413B0 0080982D */  daddu     $s3, $a0, $zero
/* EE7964 802413B4 AFBF0054 */  sw        $ra, 0x54($sp)
/* EE7968 802413B8 AFB40050 */  sw        $s4, 0x50($sp)
/* EE796C 802413BC AFB20048 */  sw        $s2, 0x48($sp)
/* EE7970 802413C0 AFB10044 */  sw        $s1, 0x44($sp)
/* EE7974 802413C4 AFB00040 */  sw        $s0, 0x40($sp)
/* EE7978 802413C8 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* EE797C 802413CC F7B80068 */  sdc1      $f24, 0x68($sp)
/* EE7980 802413D0 F7B60060 */  sdc1      $f22, 0x60($sp)
/* EE7984 802413D4 F7B40058 */  sdc1      $f20, 0x58($sp)
/* EE7988 802413D8 8E710148 */  lw        $s1, 0x148($s3)
/* EE798C 802413DC 00A0902D */  daddu     $s2, $a1, $zero
/* EE7990 802413E0 86240008 */  lh        $a0, 8($s1)
/* EE7994 802413E4 0C00F92F */  jal       func_8003E4BC
/* EE7998 802413E8 00C0A02D */   daddu    $s4, $a2, $zero
/* EE799C 802413EC 0040802D */  daddu     $s0, $v0, $zero
/* EE79A0 802413F0 C6200078 */  lwc1      $f0, 0x78($s1)
/* EE79A4 802413F4 46800020 */  cvt.s.w   $f0, $f0
/* EE79A8 802413F8 46000021 */  cvt.d.s   $f0, $f0
/* EE79AC 802413FC 3C014059 */  lui       $at, 0x4059
/* EE79B0 80241400 44811800 */  mtc1      $at, $f3
/* EE79B4 80241404 44801000 */  mtc1      $zero, $f2
/* EE79B8 80241408 8602008E */  lh        $v0, 0x8e($s0)
/* EE79BC 8024140C 9603008E */  lhu       $v1, 0x8e($s0)
/* EE79C0 80241410 46220003 */  div.d     $f0, $f0, $f2
/* EE79C4 80241414 46200620 */  cvt.s.d   $f24, $f0
/* EE79C8 80241418 C6200088 */  lwc1      $f0, 0x88($s1)
/* EE79CC 8024141C 46800020 */  cvt.s.w   $f0, $f0
/* EE79D0 80241420 46000021 */  cvt.d.s   $f0, $f0
/* EE79D4 80241424 46220003 */  div.d     $f0, $f0, $f2
/* EE79D8 80241428 46200020 */  cvt.s.d   $f0, $f0
/* EE79DC 8024142C 18400003 */  blez      $v0, .L8024143C
/* EE79E0 80241430 4600C680 */   add.s    $f26, $f24, $f0
/* EE79E4 80241434 2462FFFF */  addiu     $v0, $v1, -1
/* EE79E8 80241438 A602008E */  sh        $v0, 0x8e($s0)
.L8024143C:
/* EE79EC 8024143C 8E220070 */  lw        $v0, 0x70($s1)
/* EE79F0 80241440 18400034 */  blez      $v0, .L80241514
/* EE79F4 80241444 00000000 */   nop
/* EE79F8 80241448 C62C0074 */  lwc1      $f12, 0x74($s1)
/* EE79FC 8024144C 46806320 */  cvt.s.w   $f12, $f12
/* EE7A00 80241450 44820000 */  mtc1      $v0, $f0
/* EE7A04 80241454 00000000 */  nop
/* EE7A08 80241458 46800020 */  cvt.s.w   $f0, $f0
/* EE7A0C 8024145C 46000021 */  cvt.d.s   $f0, $f0
/* EE7A10 80241460 46220003 */  div.d     $f0, $f0, $f2
/* EE7A14 80241464 0C00AD77 */  jal       func_8002B5DC
/* EE7A18 80241468 462005A0 */   cvt.s.d  $f22, $f0
/* EE7A1C 8024146C 8E020000 */  lw        $v0, ($s0)
/* EE7A20 80241470 30420008 */  andi      $v0, $v0, 8
/* EE7A24 80241474 10400003 */  beqz      $v0, .L80241484
/* EE7A28 80241478 46000506 */   mov.s    $f20, $f0
/* EE7A2C 8024147C 08090531 */  j         .L802414C4
/* EE7A30 80241480 0000102D */   daddu    $v0, $zero, $zero
.L80241484:
/* EE7A34 80241484 27A50028 */  addiu     $a1, $sp, 0x28
/* EE7A38 80241488 27A6002C */  addiu     $a2, $sp, 0x2c
/* EE7A3C 8024148C C6000038 */  lwc1      $f0, 0x38($s0)
/* EE7A40 80241490 C602003C */  lwc1      $f2, 0x3c($s0)
/* EE7A44 80241494 C6040040 */  lwc1      $f4, 0x40($s0)
/* EE7A48 80241498 3C01447A */  lui       $at, 0x447a
/* EE7A4C 8024149C 44813000 */  mtc1      $at, $f6
/* EE7A50 802414A0 27A20034 */  addiu     $v0, $sp, 0x34
/* EE7A54 802414A4 E7A00028 */  swc1      $f0, 0x28($sp)
/* EE7A58 802414A8 E7A2002C */  swc1      $f2, 0x2c($sp)
/* EE7A5C 802414AC E7A40030 */  swc1      $f4, 0x30($sp)
/* EE7A60 802414B0 E7A60034 */  swc1      $f6, 0x34($sp)
/* EE7A64 802414B4 AFA20010 */  sw        $v0, 0x10($sp)
/* EE7A68 802414B8 8E040080 */  lw        $a0, 0x80($s0)
/* EE7A6C 802414BC 0C03908F */  jal       func_800E423C
/* EE7A70 802414C0 27A70030 */   addiu    $a3, $sp, 0x30
.L802414C4:
/* EE7A74 802414C4 10400007 */  beqz      $v0, .L802414E4
/* EE7A78 802414C8 00000000 */   nop
/* EE7A7C 802414CC 4616A082 */  mul.s     $f2, $f20, $f22
/* EE7A80 802414D0 00000000 */  nop
/* EE7A84 802414D4 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* EE7A88 802414D8 46180000 */  add.s     $f0, $f0, $f24
/* EE7A8C 802414DC 0809053C */  j         .L802414F0
/* EE7A90 802414E0 46020000 */   add.s    $f0, $f0, $f2
.L802414E4:
/* EE7A94 802414E4 4616A002 */  mul.s     $f0, $f20, $f22
/* EE7A98 802414E8 00000000 */  nop
/* EE7A9C 802414EC 4600D000 */  add.s     $f0, $f26, $f0
.L802414F0:
/* EE7AA0 802414F0 E600003C */  swc1      $f0, 0x3c($s0)
/* EE7AA4 802414F4 8E220074 */  lw        $v0, 0x74($s1)
/* EE7AA8 802414F8 2442000A */  addiu     $v0, $v0, 0xa
/* EE7AAC 802414FC 44826000 */  mtc1      $v0, $f12
/* EE7AB0 80241500 00000000 */  nop
/* EE7AB4 80241504 0C00AB85 */  jal       func_8002AE14
/* EE7AB8 80241508 46806320 */   cvt.s.w  $f12, $f12
/* EE7ABC 8024150C 4600020D */  trunc.w.s $f8, $f0
/* EE7AC0 80241510 E6280074 */  swc1      $f8, 0x74($s1)
.L80241514:
/* EE7AC4 80241514 8E220090 */  lw        $v0, 0x90($s1)
/* EE7AC8 80241518 1C400040 */  bgtz      $v0, .L8024161C
/* EE7ACC 8024151C 2442FFFF */   addiu    $v0, $v0, -1
/* EE7AD0 80241520 860200A8 */  lh        $v0, 0xa8($s0)
/* EE7AD4 80241524 C600003C */  lwc1      $f0, 0x3c($s0)
/* EE7AD8 80241528 44821000 */  mtc1      $v0, $f2
/* EE7ADC 8024152C 00000000 */  nop
/* EE7AE0 80241530 468010A0 */  cvt.s.w   $f2, $f2
/* EE7AE4 80241534 3C028010 */  lui       $v0, %hi(dead_gPlayerStatusPtr)
/* EE7AE8 80241538 8C42FC90 */  lw        $v0, %lo(dead_gPlayerStatusPtr)($v0)
/* EE7AEC 8024153C 46020000 */  add.s     $f0, $f0, $f2
/* EE7AF0 80241540 3C014024 */  lui       $at, 0x4024
/* EE7AF4 80241544 44812800 */  mtc1      $at, $f5
/* EE7AF8 80241548 44802000 */  mtc1      $zero, $f4
/* EE7AFC 8024154C C442002C */  lwc1      $f2, 0x2c($v0)
/* EE7B00 80241550 46000021 */  cvt.d.s   $f0, $f0
/* EE7B04 80241554 46240000 */  add.d     $f0, $f0, $f4
/* EE7B08 80241558 460010A1 */  cvt.d.s   $f2, $f2
/* EE7B0C 8024155C 4620103C */  c.lt.d    $f2, $f0
/* EE7B10 80241560 00000000 */  nop
/* EE7B14 80241564 4500002E */  bc1f      .L80241620
/* EE7B18 80241568 0280202D */   daddu    $a0, $s4, $zero
/* EE7B1C 8024156C 24020001 */  addiu     $v0, $zero, 1
/* EE7B20 80241570 AFA20010 */  sw        $v0, 0x10($sp)
/* EE7B24 80241574 8E460024 */  lw        $a2, 0x24($s2)
/* EE7B28 80241578 8E470028 */  lw        $a3, 0x28($s2)
/* EE7B2C 8024157C 0C013469 */  jal       func_8004D1A4
/* EE7B30 80241580 0220282D */   daddu    $a1, $s1, $zero
/* EE7B34 80241584 10400026 */  beqz      $v0, .L80241620
/* EE7B38 80241588 0000202D */   daddu    $a0, $zero, $zero
/* EE7B3C 8024158C 0200282D */  daddu     $a1, $s0, $zero
/* EE7B40 80241590 0000302D */  daddu     $a2, $zero, $zero
/* EE7B44 80241594 2412000C */  addiu     $s2, $zero, 0xc
/* EE7B48 80241598 860300A8 */  lh        $v1, 0xa8($s0)
/* EE7B4C 8024159C 3C013F80 */  lui       $at, 0x3f80
/* EE7B50 802415A0 44810000 */  mtc1      $at, $f0
/* EE7B54 802415A4 3C014000 */  lui       $at, 0x4000
/* EE7B58 802415A8 44811000 */  mtc1      $at, $f2
/* EE7B5C 802415AC 3C01C1A0 */  lui       $at, 0xc1a0
/* EE7B60 802415B0 44812000 */  mtc1      $at, $f4
/* EE7B64 802415B4 44834000 */  mtc1      $v1, $f8
/* EE7B68 802415B8 00000000 */  nop
/* EE7B6C 802415BC 46804220 */  cvt.s.w   $f8, $f8
/* EE7B70 802415C0 44074000 */  mfc1      $a3, $f8
/* EE7B74 802415C4 27A20038 */  addiu     $v0, $sp, 0x38
/* EE7B78 802415C8 AFB2001C */  sw        $s2, 0x1c($sp)
/* EE7B7C 802415CC AFA20020 */  sw        $v0, 0x20($sp)
/* EE7B80 802415D0 E7A00010 */  swc1      $f0, 0x10($sp)
/* EE7B84 802415D4 E7A20014 */  swc1      $f2, 0x14($sp)
/* EE7B88 802415D8 0C01D444 */  jal       func_80075110
/* EE7B8C 802415DC E7A40018 */   swc1     $f4, 0x18($sp)
/* EE7B90 802415E0 0200202D */  daddu     $a0, $s0, $zero
/* EE7B94 802415E4 240502F4 */  addiu     $a1, $zero, 0x2f4
/* EE7B98 802415E8 C480003C */  lwc1      $f0, 0x3c($a0)
/* EE7B9C 802415EC 3C060020 */  lui       $a2, 0x20
/* EE7BA0 802415F0 0C013600 */  jal       func_8004D800
/* EE7BA4 802415F4 E4800064 */   swc1     $f0, 0x64($a0)
/* EE7BA8 802415F8 8E220018 */  lw        $v0, 0x18($s1)
/* EE7BAC 802415FC 9442002A */  lhu       $v0, 0x2a($v0)
/* EE7BB0 80241600 30420001 */  andi      $v0, $v0, 1
/* EE7BB4 80241604 10400003 */  beqz      $v0, .L80241614
/* EE7BB8 80241608 2402000A */   addiu    $v0, $zero, 0xa
/* EE7BBC 8024160C 080905AF */  j         .L802416BC
/* EE7BC0 80241610 AE620070 */   sw       $v0, 0x70($s3)
.L80241614:
/* EE7BC4 80241614 080905AF */  j         .L802416BC
/* EE7BC8 80241618 AE720070 */   sw       $s2, 0x70($s3)
.L8024161C:
/* EE7BCC 8024161C AE220090 */  sw        $v0, 0x90($s1)
.L80241620:
/* EE7BD0 80241620 8602008C */  lh        $v0, 0x8c($s0)
/* EE7BD4 80241624 14400025 */  bnez      $v0, .L802416BC
/* EE7BD8 80241628 00000000 */   nop
/* EE7BDC 8024162C 8602008E */  lh        $v0, 0x8e($s0)
/* EE7BE0 80241630 1C400022 */  bgtz      $v0, .L802416BC
/* EE7BE4 80241634 00000000 */   nop
/* EE7BE8 80241638 8E620074 */  lw        $v0, 0x74($s3)
/* EE7BEC 8024163C 2442FFFF */  addiu     $v0, $v0, -1
/* EE7BF0 80241640 1840001D */  blez      $v0, .L802416B8
/* EE7BF4 80241644 AE620074 */   sw       $v0, 0x74($s3)
/* EE7BF8 80241648 8E220018 */  lw        $v0, 0x18($s1)
/* EE7BFC 8024164C 9442002A */  lhu       $v0, 0x2a($v0)
/* EE7C00 80241650 30420010 */  andi      $v0, $v0, 0x10
/* EE7C04 80241654 14400007 */  bnez      $v0, .L80241674
/* EE7C08 80241658 00000000 */   nop
/* EE7C0C 8024165C C600000C */  lwc1      $f0, 0xc($s0)
/* EE7C10 80241660 3C014334 */  lui       $at, 0x4334
/* EE7C14 80241664 44816000 */  mtc1      $at, $f12
/* EE7C18 80241668 0C00AB85 */  jal       func_8002AE14
/* EE7C1C 8024166C 460C0300 */   add.s    $f12, $f0, $f12
/* EE7C20 80241670 E600000C */  swc1      $f0, 0xc($s0)
.L80241674:
/* EE7C24 80241674 0C00AB3B */  jal       func_8002ACEC
/* EE7C28 80241678 240403E8 */   addiu    $a0, $zero, 0x3e8
/* EE7C2C 8024167C 3C032E8B */  lui       $v1, 0x2e8b
/* EE7C30 80241680 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* EE7C34 80241684 00430018 */  mult      $v0, $v1
/* EE7C38 80241688 00021FC3 */  sra       $v1, $v0, 0x1f
/* EE7C3C 8024168C 00004010 */  mfhi      $t0
/* EE7C40 80241690 00082043 */  sra       $a0, $t0, 1
/* EE7C44 80241694 00832023 */  subu      $a0, $a0, $v1
/* EE7C48 80241698 00041840 */  sll       $v1, $a0, 1
/* EE7C4C 8024169C 00641821 */  addu      $v1, $v1, $a0
/* EE7C50 802416A0 00031880 */  sll       $v1, $v1, 2
/* EE7C54 802416A4 00641823 */  subu      $v1, $v1, $a0
/* EE7C58 802416A8 00431023 */  subu      $v0, $v0, $v1
/* EE7C5C 802416AC 24420005 */  addiu     $v0, $v0, 5
/* EE7C60 802416B0 080905AF */  j         .L802416BC
/* EE7C64 802416B4 A602008E */   sh       $v0, 0x8e($s0)
.L802416B8:
/* EE7C68 802416B8 AE600070 */  sw        $zero, 0x70($s3)
.L802416BC:
/* EE7C6C 802416BC 8FBF0054 */  lw        $ra, 0x54($sp)
/* EE7C70 802416C0 8FB40050 */  lw        $s4, 0x50($sp)
/* EE7C74 802416C4 8FB3004C */  lw        $s3, 0x4c($sp)
/* EE7C78 802416C8 8FB20048 */  lw        $s2, 0x48($sp)
/* EE7C7C 802416CC 8FB10044 */  lw        $s1, 0x44($sp)
/* EE7C80 802416D0 8FB00040 */  lw        $s0, 0x40($sp)
/* EE7C84 802416D4 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* EE7C88 802416D8 D7B80068 */  ldc1      $f24, 0x68($sp)
/* EE7C8C 802416DC D7B60060 */  ldc1      $f22, 0x60($sp)
/* EE7C90 802416E0 D7B40058 */  ldc1      $f20, 0x58($sp)
/* EE7C94 802416E4 03E00008 */  jr        $ra
/* EE7C98 802416E8 27BD0078 */   addiu    $sp, $sp, 0x78
