.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80247AF8_EE64B8
.double 0.09

glabel D_80247B00_EE64C0
.double 0.09

.section .text

glabel func_80240374_EDED34
/* EDED34 80240374 27BDFF80 */  addiu     $sp, $sp, -0x80
/* EDED38 80240378 AFB3004C */  sw        $s3, 0x4c($sp)
/* EDED3C 8024037C 0080982D */  daddu     $s3, $a0, $zero
/* EDED40 80240380 AFBF0058 */  sw        $ra, 0x58($sp)
/* EDED44 80240384 AFB50054 */  sw        $s5, 0x54($sp)
/* EDED48 80240388 AFB40050 */  sw        $s4, 0x50($sp)
/* EDED4C 8024038C AFB20048 */  sw        $s2, 0x48($sp)
/* EDED50 80240390 AFB10044 */  sw        $s1, 0x44($sp)
/* EDED54 80240394 AFB00040 */  sw        $s0, 0x40($sp)
/* EDED58 80240398 F7BA0078 */  sdc1      $f26, 0x78($sp)
/* EDED5C 8024039C F7B80070 */  sdc1      $f24, 0x70($sp)
/* EDED60 802403A0 F7B60068 */  sdc1      $f22, 0x68($sp)
/* EDED64 802403A4 F7B40060 */  sdc1      $f20, 0x60($sp)
/* EDED68 802403A8 8E710148 */  lw        $s1, 0x148($s3)
/* EDED6C 802403AC 00A0902D */  daddu     $s2, $a1, $zero
/* EDED70 802403B0 86240008 */  lh        $a0, 8($s1)
/* EDED74 802403B4 0C00F92F */  jal       func_8003E4BC
/* EDED78 802403B8 00C0A82D */   daddu    $s5, $a2, $zero
/* EDED7C 802403BC 0040802D */  daddu     $s0, $v0, $zero
/* EDED80 802403C0 0000A02D */  daddu     $s4, $zero, $zero
/* EDED84 802403C4 C624007C */  lwc1      $f4, 0x7c($s1)
/* EDED88 802403C8 46802120 */  cvt.s.w   $f4, $f4
/* EDED8C 802403CC C6220088 */  lwc1      $f2, 0x88($s1)
/* EDED90 802403D0 468010A0 */  cvt.s.w   $f2, $f2
/* EDED94 802403D4 460010A1 */  cvt.d.s   $f2, $f2
/* EDED98 802403D8 46002121 */  cvt.d.s   $f4, $f4
/* EDED9C 802403DC C600003C */  lwc1      $f0, 0x3c($s0)
/* EDEDA0 802403E0 3C014059 */  lui       $at, 0x4059
/* EDEDA4 802403E4 44813800 */  mtc1      $at, $f7
/* EDEDA8 802403E8 44803000 */  mtc1      $zero, $f6
/* EDEDAC 802403EC 46000021 */  cvt.d.s   $f0, $f0
/* EDEDB0 802403F0 46260002 */  mul.d     $f0, $f0, $f6
/* EDEDB4 802403F4 00000000 */  nop
/* EDEDB8 802403F8 24020001 */  addiu     $v0, $zero, 1
/* EDEDBC 802403FC 8E24006C */  lw        $a0, 0x6c($s1)
/* EDEDC0 80240400 46261083 */  div.d     $f2, $f2, $f6
/* EDEDC4 80240404 462010A0 */  cvt.s.d   $f2, $f2
/* EDEDC8 80240408 46262103 */  div.d     $f4, $f4, $f6
/* EDEDCC 8024040C 46202520 */  cvt.s.d   $f20, $f4
/* EDEDD0 80240410 30830011 */  andi      $v1, $a0, 0x11
/* EDEDD4 80240414 4620020D */  trunc.w.d $f8, $f0
/* EDEDD8 80240418 E628007C */  swc1      $f8, 0x7c($s1)
/* EDEDDC 8024041C C6200078 */  lwc1      $f0, 0x78($s1)
/* EDEDE0 80240420 46800020 */  cvt.s.w   $f0, $f0
/* EDEDE4 80240424 46000021 */  cvt.d.s   $f0, $f0
/* EDEDE8 80240428 46260003 */  div.d     $f0, $f0, $f6
/* EDEDEC 8024042C 462006A0 */  cvt.s.d   $f26, $f0
/* EDEDF0 80240430 C6200070 */  lwc1      $f0, 0x70($s1)
/* EDEDF4 80240434 46800020 */  cvt.s.w   $f0, $f0
/* EDEDF8 80240438 46000021 */  cvt.d.s   $f0, $f0
/* EDEDFC 8024043C 46260003 */  div.d     $f0, $f0, $f6
/* EDEE00 80240440 462005A0 */  cvt.s.d   $f22, $f0
/* EDEE04 80240444 14620025 */  bne       $v1, $v0, .L802404DC
/* EDEE08 80240448 4602D600 */   add.s    $f24, $f26, $f2
/* EDEE0C 8024044C 8E020000 */  lw        $v0, ($s0)
/* EDEE10 80240450 30420008 */  andi      $v0, $v0, 8
/* EDEE14 80240454 10400009 */  beqz      $v0, .L8024047C
/* EDEE18 80240458 27A50028 */   addiu    $a1, $sp, 0x28
/* EDEE1C 8024045C C600003C */  lwc1      $f0, 0x3c($s0)
/* EDEE20 80240460 4600C001 */  sub.s     $f0, $f24, $f0
/* EDEE24 80240464 4600B03C */  c.lt.s    $f22, $f0
/* EDEE28 80240468 00000000 */  nop
/* EDEE2C 8024046C 4500001B */  bc1f      .L802404DC
/* EDEE30 80240470 34820010 */   ori      $v0, $a0, 0x10
/* EDEE34 80240474 08090137 */  j         .L802404DC
/* EDEE38 80240478 AE22006C */   sw       $v0, 0x6c($s1)
.L8024047C:
/* EDEE3C 8024047C 27A6002C */  addiu     $a2, $sp, 0x2c
/* EDEE40 80240480 C6000038 */  lwc1      $f0, 0x38($s0)
/* EDEE44 80240484 C602003C */  lwc1      $f2, 0x3c($s0)
/* EDEE48 80240488 C6040040 */  lwc1      $f4, 0x40($s0)
/* EDEE4C 8024048C 3C01447A */  lui       $at, 0x447a
/* EDEE50 80240490 44813000 */  mtc1      $at, $f6
/* EDEE54 80240494 27A20034 */  addiu     $v0, $sp, 0x34
/* EDEE58 80240498 E7A00028 */  swc1      $f0, 0x28($sp)
/* EDEE5C 8024049C E7A2002C */  swc1      $f2, 0x2c($sp)
/* EDEE60 802404A0 E7A40030 */  swc1      $f4, 0x30($sp)
/* EDEE64 802404A4 E7A60034 */  swc1      $f6, 0x34($sp)
/* EDEE68 802404A8 AFA20010 */  sw        $v0, 0x10($sp)
/* EDEE6C 802404AC 8E040080 */  lw        $a0, 0x80($s0)
/* EDEE70 802404B0 0C03908F */  jal       func_800E423C
/* EDEE74 802404B4 27A70030 */   addiu    $a3, $sp, 0x30
/* EDEE78 802404B8 C7A00034 */  lwc1      $f0, 0x34($sp)
/* EDEE7C 802404BC 4600D001 */  sub.s     $f0, $f26, $f0
/* EDEE80 802404C0 4600B03C */  c.lt.s    $f22, $f0
/* EDEE84 802404C4 00000000 */  nop
/* EDEE88 802404C8 45000004 */  bc1f      .L802404DC
/* EDEE8C 802404CC 00000000 */   nop
/* EDEE90 802404D0 8E22006C */  lw        $v0, 0x6c($s1)
/* EDEE94 802404D4 34420010 */  ori       $v0, $v0, 0x10
/* EDEE98 802404D8 AE22006C */  sw        $v0, 0x6c($s1)
.L802404DC:
/* EDEE9C 802404DC 8E22006C */  lw        $v0, 0x6c($s1)
/* EDEEA0 802404E0 24030011 */  addiu     $v1, $zero, 0x11
/* EDEEA4 802404E4 30420011 */  andi      $v0, $v0, 0x11
/* EDEEA8 802404E8 14430039 */  bne       $v0, $v1, .L802405D0
/* EDEEAC 802404EC 00000000 */   nop
/* EDEEB0 802404F0 8E020000 */  lw        $v0, ($s0)
/* EDEEB4 802404F4 30420008 */  andi      $v0, $v0, 8
/* EDEEB8 802404F8 1040000A */  beqz      $v0, .L80240524
/* EDEEBC 802404FC 4600C106 */   mov.s    $f4, $f24
/* EDEEC0 80240500 4614C081 */  sub.s     $f2, $f24, $f20
/* EDEEC4 80240504 3C018024 */  lui       $at, %hi(D_80247AF8_EE64B8)
/* EDEEC8 80240508 D4207AF8 */  ldc1      $f0, %lo(D_80247AF8_EE64B8)($at)
/* EDEECC 8024050C 460010A1 */  cvt.d.s   $f2, $f2
/* EDEED0 80240510 46201082 */  mul.d     $f2, $f2, $f0
/* EDEED4 80240514 00000000 */  nop
/* EDEED8 80240518 4600A021 */  cvt.d.s   $f0, $f20
/* EDEEDC 8024051C 08090162 */  j         .L80240588
/* EDEEE0 80240520 46220000 */   add.d    $f0, $f0, $f2
.L80240524:
/* EDEEE4 80240524 27A50028 */  addiu     $a1, $sp, 0x28
/* EDEEE8 80240528 27A6002C */  addiu     $a2, $sp, 0x2c
/* EDEEEC 8024052C C6000038 */  lwc1      $f0, 0x38($s0)
/* EDEEF0 80240530 C6020040 */  lwc1      $f2, 0x40($s0)
/* EDEEF4 80240534 3C01447A */  lui       $at, 0x447a
/* EDEEF8 80240538 44812000 */  mtc1      $at, $f4
/* EDEEFC 8024053C 27A20034 */  addiu     $v0, $sp, 0x34
/* EDEF00 80240540 E7B4002C */  swc1      $f20, 0x2c($sp)
/* EDEF04 80240544 E7A00028 */  swc1      $f0, 0x28($sp)
/* EDEF08 80240548 E7A20030 */  swc1      $f2, 0x30($sp)
/* EDEF0C 8024054C E7A40034 */  swc1      $f4, 0x34($sp)
/* EDEF10 80240550 AFA20010 */  sw        $v0, 0x10($sp)
/* EDEF14 80240554 8E040080 */  lw        $a0, 0x80($s0)
/* EDEF18 80240558 0C03908F */  jal       func_800E423C
/* EDEF1C 8024055C 27A70030 */   addiu    $a3, $sp, 0x30
/* EDEF20 80240560 C7A4002C */  lwc1      $f4, 0x2c($sp)
/* EDEF24 80240564 461A2100 */  add.s     $f4, $f4, $f26
/* EDEF28 80240568 46142081 */  sub.s     $f2, $f4, $f20
/* EDEF2C 8024056C 3C018024 */  lui       $at, %hi(D_80247B00_EE64C0)
/* EDEF30 80240570 D4207B00 */  ldc1      $f0, %lo(D_80247B00_EE64C0)($at)
/* EDEF34 80240574 460010A1 */  cvt.d.s   $f2, $f2
/* EDEF38 80240578 46201082 */  mul.d     $f2, $f2, $f0
/* EDEF3C 8024057C 00000000 */  nop
/* EDEF40 80240580 4600A021 */  cvt.d.s   $f0, $f20
/* EDEF44 80240584 46220000 */  add.d     $f0, $f0, $f2
.L80240588:
/* EDEF48 80240588 46200020 */  cvt.s.d   $f0, $f0
/* EDEF4C 8024058C E600003C */  swc1      $f0, 0x3c($s0)
/* EDEF50 80240590 C600003C */  lwc1      $f0, 0x3c($s0)
/* EDEF54 80240594 46002001 */  sub.s     $f0, $f4, $f0
/* EDEF58 80240598 3C013FF0 */  lui       $at, 0x3ff0
/* EDEF5C 8024059C 44811800 */  mtc1      $at, $f3
/* EDEF60 802405A0 44801000 */  mtc1      $zero, $f2
/* EDEF64 802405A4 46000005 */  abs.s     $f0, $f0
/* EDEF68 802405A8 46000021 */  cvt.d.s   $f0, $f0
/* EDEF6C 802405AC 4622003C */  c.lt.d    $f0, $f2
/* EDEF70 802405B0 00000000 */  nop
/* EDEF74 802405B4 45000036 */  bc1f      .L80240690
/* EDEF78 802405B8 2403FFEF */   addiu    $v1, $zero, -0x11
/* EDEF7C 802405BC E604003C */  swc1      $f4, 0x3c($s0)
/* EDEF80 802405C0 8E22006C */  lw        $v0, 0x6c($s1)
/* EDEF84 802405C4 00431024 */  and       $v0, $v0, $v1
/* EDEF88 802405C8 080901A4 */  j         .L80240690
/* EDEF8C 802405CC AE22006C */   sw       $v0, 0x6c($s1)
.L802405D0:
/* EDEF90 802405D0 8E220070 */  lw        $v0, 0x70($s1)
/* EDEF94 802405D4 1840002E */  blez      $v0, .L80240690
/* EDEF98 802405D8 00000000 */   nop
/* EDEF9C 802405DC C62C0074 */  lwc1      $f12, 0x74($s1)
/* EDEFA0 802405E0 0C00AD77 */  jal       func_8002B5DC
/* EDEFA4 802405E4 46806320 */   cvt.s.w  $f12, $f12
/* EDEFA8 802405E8 8E020000 */  lw        $v0, ($s0)
/* EDEFAC 802405EC 30420008 */  andi      $v0, $v0, 8
/* EDEFB0 802405F0 10400003 */  beqz      $v0, .L80240600
/* EDEFB4 802405F4 46000506 */   mov.s    $f20, $f0
/* EDEFB8 802405F8 08090190 */  j         .L80240640
/* EDEFBC 802405FC 0000102D */   daddu    $v0, $zero, $zero
.L80240600:
/* EDEFC0 80240600 27A50028 */  addiu     $a1, $sp, 0x28
/* EDEFC4 80240604 27A6002C */  addiu     $a2, $sp, 0x2c
/* EDEFC8 80240608 C6000038 */  lwc1      $f0, 0x38($s0)
/* EDEFCC 8024060C C602003C */  lwc1      $f2, 0x3c($s0)
/* EDEFD0 80240610 C6040040 */  lwc1      $f4, 0x40($s0)
/* EDEFD4 80240614 3C01447A */  lui       $at, 0x447a
/* EDEFD8 80240618 44813000 */  mtc1      $at, $f6
/* EDEFDC 8024061C 27A20034 */  addiu     $v0, $sp, 0x34
/* EDEFE0 80240620 E7A00028 */  swc1      $f0, 0x28($sp)
/* EDEFE4 80240624 E7A2002C */  swc1      $f2, 0x2c($sp)
/* EDEFE8 80240628 E7A40030 */  swc1      $f4, 0x30($sp)
/* EDEFEC 8024062C E7A60034 */  swc1      $f6, 0x34($sp)
/* EDEFF0 80240630 AFA20010 */  sw        $v0, 0x10($sp)
/* EDEFF4 80240634 8E040080 */  lw        $a0, 0x80($s0)
/* EDEFF8 80240638 0C03908F */  jal       func_800E423C
/* EDEFFC 8024063C 27A70030 */   addiu    $a3, $sp, 0x30
.L80240640:
/* EDF000 80240640 10400007 */  beqz      $v0, .L80240660
/* EDF004 80240644 00000000 */   nop
/* EDF008 80240648 4616A082 */  mul.s     $f2, $f20, $f22
/* EDF00C 8024064C 00000000 */  nop
/* EDF010 80240650 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* EDF014 80240654 461A0000 */  add.s     $f0, $f0, $f26
/* EDF018 80240658 0809019B */  j         .L8024066C
/* EDF01C 8024065C 46020000 */   add.s    $f0, $f0, $f2
.L80240660:
/* EDF020 80240660 4616A002 */  mul.s     $f0, $f20, $f22
/* EDF024 80240664 00000000 */  nop
/* EDF028 80240668 4600C000 */  add.s     $f0, $f24, $f0
.L8024066C:
/* EDF02C 8024066C E600003C */  swc1      $f0, 0x3c($s0)
/* EDF030 80240670 8E220074 */  lw        $v0, 0x74($s1)
/* EDF034 80240674 2442000A */  addiu     $v0, $v0, 0xa
/* EDF038 80240678 44826000 */  mtc1      $v0, $f12
/* EDF03C 8024067C 00000000 */  nop
/* EDF040 80240680 0C00AB85 */  jal       func_8002AE14
/* EDF044 80240684 46806320 */   cvt.s.w  $f12, $f12
/* EDF048 80240688 4600020D */  trunc.w.s $f8, $f0
/* EDF04C 8024068C E6280074 */  swc1      $f8, 0x74($s1)
.L80240690:
/* EDF050 80240690 8E220090 */  lw        $v0, 0x90($s1)
/* EDF054 80240694 1C40004A */  bgtz      $v0, .L802407C0
/* EDF058 80240698 2442FFFF */   addiu    $v0, $v0, -1
/* EDF05C 8024069C 8E430014 */  lw        $v1, 0x14($s2)
/* EDF060 802406A0 04600048 */  bltz      $v1, .L802407C4
/* EDF064 802406A4 00000000 */   nop
/* EDF068 802406A8 8E620074 */  lw        $v0, 0x74($s3)
/* EDF06C 802406AC 1C400042 */  bgtz      $v0, .L802407B8
/* EDF070 802406B0 2442FFFF */   addiu    $v0, $v0, -1
/* EDF074 802406B4 AE630074 */  sw        $v1, 0x74($s3)
/* EDF078 802406B8 860200A8 */  lh        $v0, 0xa8($s0)
/* EDF07C 802406BC C602003C */  lwc1      $f2, 0x3c($s0)
/* EDF080 802406C0 44820000 */  mtc1      $v0, $f0
/* EDF084 802406C4 00000000 */  nop
/* EDF088 802406C8 46800020 */  cvt.s.w   $f0, $f0
/* EDF08C 802406CC 46001080 */  add.s     $f2, $f2, $f0
/* EDF090 802406D0 3C014024 */  lui       $at, 0x4024
/* EDF094 802406D4 44810800 */  mtc1      $at, $f1
/* EDF098 802406D8 44800000 */  mtc1      $zero, $f0
/* EDF09C 802406DC 3C028010 */  lui       $v0, %hi(D_800FFC90)
/* EDF0A0 802406E0 8C42FC90 */  lw        $v0, %lo(D_800FFC90)($v0)
/* EDF0A4 802406E4 460010A1 */  cvt.d.s   $f2, $f2
/* EDF0A8 802406E8 46201080 */  add.d     $f2, $f2, $f0
/* EDF0AC 802406EC C440002C */  lwc1      $f0, 0x2c($v0)
/* EDF0B0 802406F0 46000021 */  cvt.d.s   $f0, $f0
/* EDF0B4 802406F4 4622003C */  c.lt.d    $f0, $f2
/* EDF0B8 802406F8 00000000 */  nop
/* EDF0BC 802406FC 4500002C */  bc1f      .L802407B0
/* EDF0C0 80240700 02A0202D */   daddu    $a0, $s5, $zero
/* EDF0C4 80240704 AFA00010 */  sw        $zero, 0x10($sp)
/* EDF0C8 80240708 8E46000C */  lw        $a2, 0xc($s2)
/* EDF0CC 8024070C 8E470010 */  lw        $a3, 0x10($s2)
/* EDF0D0 80240710 0C013469 */  jal       func_8004D1A4
/* EDF0D4 80240714 0220282D */   daddu    $a1, $s1, $zero
/* EDF0D8 80240718 10400025 */  beqz      $v0, .L802407B0
/* EDF0DC 8024071C 0000202D */   daddu    $a0, $zero, $zero
/* EDF0E0 80240720 0200282D */  daddu     $a1, $s0, $zero
/* EDF0E4 80240724 0000302D */  daddu     $a2, $zero, $zero
/* EDF0E8 80240728 2412000C */  addiu     $s2, $zero, 0xc
/* EDF0EC 8024072C 860300A8 */  lh        $v1, 0xa8($s0)
/* EDF0F0 80240730 3C013F80 */  lui       $at, 0x3f80
/* EDF0F4 80240734 44810000 */  mtc1      $at, $f0
/* EDF0F8 80240738 3C014000 */  lui       $at, 0x4000
/* EDF0FC 8024073C 44811000 */  mtc1      $at, $f2
/* EDF100 80240740 3C01C1A0 */  lui       $at, 0xc1a0
/* EDF104 80240744 44812000 */  mtc1      $at, $f4
/* EDF108 80240748 44834000 */  mtc1      $v1, $f8
/* EDF10C 8024074C 00000000 */  nop
/* EDF110 80240750 46804220 */  cvt.s.w   $f8, $f8
/* EDF114 80240754 44074000 */  mfc1      $a3, $f8
/* EDF118 80240758 27A20038 */  addiu     $v0, $sp, 0x38
/* EDF11C 8024075C AFB2001C */  sw        $s2, 0x1c($sp)
/* EDF120 80240760 AFA20020 */  sw        $v0, 0x20($sp)
/* EDF124 80240764 E7A00010 */  swc1      $f0, 0x10($sp)
/* EDF128 80240768 E7A20014 */  swc1      $f2, 0x14($sp)
/* EDF12C 8024076C 0C01D444 */  jal       func_80075110
/* EDF130 80240770 E7A40018 */   swc1     $f4, 0x18($sp)
/* EDF134 80240774 0200202D */  daddu     $a0, $s0, $zero
/* EDF138 80240778 240502F4 */  addiu     $a1, $zero, 0x2f4
/* EDF13C 8024077C C480003C */  lwc1      $f0, 0x3c($a0)
/* EDF140 80240780 3C060020 */  lui       $a2, 0x20
/* EDF144 80240784 0C013600 */  jal       func_8004D800
/* EDF148 80240788 E4800064 */   swc1     $f0, 0x64($a0)
/* EDF14C 8024078C 8E220018 */  lw        $v0, 0x18($s1)
/* EDF150 80240790 9442002A */  lhu       $v0, 0x2a($v0)
/* EDF154 80240794 30420001 */  andi      $v0, $v0, 1
/* EDF158 80240798 10400003 */  beqz      $v0, .L802407A8
/* EDF15C 8024079C 2402000A */   addiu    $v0, $zero, 0xa
/* EDF160 802407A0 0809025A */  j         .L80240968
/* EDF164 802407A4 AE620070 */   sw       $v0, 0x70($s3)
.L802407A8:
/* EDF168 802407A8 0809025A */  j         .L80240968
/* EDF16C 802407AC AE720070 */   sw       $s2, 0x70($s3)
.L802407B0:
/* EDF170 802407B0 8E620074 */  lw        $v0, 0x74($s3)
/* EDF174 802407B4 2442FFFF */  addiu     $v0, $v0, -1
.L802407B8:
/* EDF178 802407B8 080901F1 */  j         .L802407C4
/* EDF17C 802407BC AE620074 */   sw       $v0, 0x74($s3)
.L802407C0:
/* EDF180 802407C0 AE220090 */  sw        $v0, 0x90($s1)
.L802407C4:
/* EDF184 802407C4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* EDF188 802407C8 C6000040 */  lwc1      $f0, 0x40($s0)
/* EDF18C 802407CC C4620000 */  lwc1      $f2, ($v1)
/* EDF190 802407D0 468010A0 */  cvt.s.w   $f2, $f2
/* EDF194 802407D4 C4640008 */  lwc1      $f4, 8($v1)
/* EDF198 802407D8 46802120 */  cvt.s.w   $f4, $f4
/* EDF19C 802407DC E7A00010 */  swc1      $f0, 0x10($sp)
/* EDF1A0 802407E0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EDF1A4 802407E4 44051000 */  mfc1      $a1, $f2
/* EDF1A8 802407E8 C440000C */  lwc1      $f0, 0xc($v0)
/* EDF1AC 802407EC 46800020 */  cvt.s.w   $f0, $f0
/* EDF1B0 802407F0 E7A00014 */  swc1      $f0, 0x14($sp)
/* EDF1B4 802407F4 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EDF1B8 802407F8 44062000 */  mfc1      $a2, $f4
/* EDF1BC 802407FC C4400010 */  lwc1      $f0, 0x10($v0)
/* EDF1C0 80240800 46800020 */  cvt.s.w   $f0, $f0
/* EDF1C4 80240804 E7A00018 */  swc1      $f0, 0x18($sp)
/* EDF1C8 80240808 8C640018 */  lw        $a0, 0x18($v1)
/* EDF1CC 8024080C 0C013431 */  jal       func_8004D0C4
/* EDF1D0 80240810 8E070038 */   lw       $a3, 0x38($s0)
/* EDF1D4 80240814 1040001A */  beqz      $v0, .L80240880
/* EDF1D8 80240818 00000000 */   nop
/* EDF1DC 8024081C 8E060038 */  lw        $a2, 0x38($s0)
/* EDF1E0 80240820 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EDF1E4 80240824 8E070040 */  lw        $a3, 0x40($s0)
/* EDF1E8 80240828 C44C0000 */  lwc1      $f12, ($v0)
/* EDF1EC 8024082C 46806320 */  cvt.s.w   $f12, $f12
/* EDF1F0 80240830 C44E0008 */  lwc1      $f14, 8($v0)
/* EDF1F4 80240834 0C00AC71 */  jal       func_8002B1C4
/* EDF1F8 80240838 468073A0 */   cvt.s.w  $f14, $f14
/* EDF1FC 8024083C C6020018 */  lwc1      $f2, 0x18($s0)
/* EDF200 80240840 4600103C */  c.lt.s    $f2, $f0
/* EDF204 80240844 00000000 */  nop
/* EDF208 80240848 4500000D */  bc1f      .L80240880
/* EDF20C 8024084C E7A00034 */   swc1     $f0, 0x34($sp)
/* EDF210 80240850 C60C0038 */  lwc1      $f12, 0x38($s0)
/* EDF214 80240854 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EDF218 80240858 C60E0040 */  lwc1      $f14, 0x40($s0)
/* EDF21C 8024085C C4480000 */  lwc1      $f8, ($v0)
/* EDF220 80240860 46804220 */  cvt.s.w   $f8, $f8
/* EDF224 80240864 44064000 */  mfc1      $a2, $f8
/* EDF228 80240868 C4480008 */  lwc1      $f8, 8($v0)
/* EDF22C 8024086C 46804220 */  cvt.s.w   $f8, $f8
/* EDF230 80240870 44074000 */  mfc1      $a3, $f8
/* EDF234 80240874 0C00ABDC */  jal       fio_validate_header_checksums
/* EDF238 80240878 24140001 */   addiu    $s4, $zero, 1
/* EDF23C 8024087C E600000C */  swc1      $f0, 0xc($s0)
.L80240880:
/* EDF240 80240880 8E2200D0 */  lw        $v0, 0xd0($s1)
/* EDF244 80240884 8C43000C */  lw        $v1, 0xc($v0)
/* EDF248 80240888 8C420010 */  lw        $v0, 0x10($v0)
/* EDF24C 8024088C 00621825 */  or        $v1, $v1, $v0
/* EDF250 80240890 00741825 */  or        $v1, $v1, $s4
/* EDF254 80240894 10600008 */  beqz      $v1, .L802408B8
/* EDF258 80240898 00000000 */   nop
/* EDF25C 8024089C 8602008C */  lh        $v0, 0x8c($s0)
/* EDF260 802408A0 14400031 */  bnez      $v0, .L80240968
/* EDF264 802408A4 00000000 */   nop
/* EDF268 802408A8 8E050018 */  lw        $a1, 0x18($s0)
/* EDF26C 802408AC 8E06000C */  lw        $a2, 0xc($s0)
/* EDF270 802408B0 0C00F909 */  jal       func_8003E424
/* EDF274 802408B4 0200202D */   daddu    $a0, $s0, $zero
.L802408B8:
/* EDF278 802408B8 C600003C */  lwc1      $f0, 0x3c($s0)
/* EDF27C 802408BC 3C014059 */  lui       $at, 0x4059
/* EDF280 802408C0 44811800 */  mtc1      $at, $f3
/* EDF284 802408C4 44801000 */  mtc1      $zero, $f2
/* EDF288 802408C8 46000021 */  cvt.d.s   $f0, $f0
/* EDF28C 802408CC 46220002 */  mul.d     $f0, $f0, $f2
/* EDF290 802408D0 00000000 */  nop
/* EDF294 802408D4 4620020D */  trunc.w.d $f8, $f0
/* EDF298 802408D8 E628007C */  swc1      $f8, 0x7c($s1)
/* EDF29C 802408DC 8E420004 */  lw        $v0, 4($s2)
/* EDF2A0 802408E0 18400021 */  blez      $v0, .L80240968
/* EDF2A4 802408E4 00000000 */   nop
/* EDF2A8 802408E8 8602008E */  lh        $v0, 0x8e($s0)
/* EDF2AC 802408EC 9603008E */  lhu       $v1, 0x8e($s0)
/* EDF2B0 802408F0 18400005 */  blez      $v0, .L80240908
/* EDF2B4 802408F4 2462FFFF */   addiu    $v0, $v1, -1
/* EDF2B8 802408F8 A602008E */  sh        $v0, 0x8e($s0)
/* EDF2BC 802408FC 00021400 */  sll       $v0, $v0, 0x10
/* EDF2C0 80240900 1C400019 */  bgtz      $v0, .L80240968
/* EDF2C4 80240904 00000000 */   nop
.L80240908:
/* EDF2C8 80240908 240403E8 */  addiu     $a0, $zero, 0x3e8
/* EDF2CC 8024090C 24020002 */  addiu     $v0, $zero, 2
/* EDF2D0 80240910 0C00AB3B */  jal       func_8002ACEC
/* EDF2D4 80240914 AE620070 */   sw       $v0, 0x70($s3)
/* EDF2D8 80240918 3C035555 */  lui       $v1, 0x5555
/* EDF2DC 8024091C 34635556 */  ori       $v1, $v1, 0x5556
/* EDF2E0 80240920 00430018 */  mult      $v0, $v1
/* EDF2E4 80240924 000227C3 */  sra       $a0, $v0, 0x1f
/* EDF2E8 80240928 00004010 */  mfhi      $t0
/* EDF2EC 8024092C 01042023 */  subu      $a0, $t0, $a0
/* EDF2F0 80240930 00041840 */  sll       $v1, $a0, 1
/* EDF2F4 80240934 00641821 */  addu      $v1, $v1, $a0
/* EDF2F8 80240938 00431023 */  subu      $v0, $v0, $v1
/* EDF2FC 8024093C 24430002 */  addiu     $v1, $v0, 2
/* EDF300 80240940 AE630074 */  sw        $v1, 0x74($s3)
/* EDF304 80240944 8E42002C */  lw        $v0, 0x2c($s2)
/* EDF308 80240948 58400007 */  blezl     $v0, .L80240968
/* EDF30C 8024094C AE600070 */   sw       $zero, 0x70($s3)
/* EDF310 80240950 8E420008 */  lw        $v0, 8($s2)
/* EDF314 80240954 18400003 */  blez      $v0, .L80240964
/* EDF318 80240958 28620003 */   slti     $v0, $v1, 3
/* EDF31C 8024095C 10400002 */  beqz      $v0, .L80240968
/* EDF320 80240960 00000000 */   nop
.L80240964:
/* EDF324 80240964 AE600070 */  sw        $zero, 0x70($s3)
.L80240968:
/* EDF328 80240968 8FBF0058 */  lw        $ra, 0x58($sp)
/* EDF32C 8024096C 8FB50054 */  lw        $s5, 0x54($sp)
/* EDF330 80240970 8FB40050 */  lw        $s4, 0x50($sp)
/* EDF334 80240974 8FB3004C */  lw        $s3, 0x4c($sp)
/* EDF338 80240978 8FB20048 */  lw        $s2, 0x48($sp)
/* EDF33C 8024097C 8FB10044 */  lw        $s1, 0x44($sp)
/* EDF340 80240980 8FB00040 */  lw        $s0, 0x40($sp)
/* EDF344 80240984 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* EDF348 80240988 D7B80070 */  ldc1      $f24, 0x70($sp)
/* EDF34C 8024098C D7B60068 */  ldc1      $f22, 0x68($sp)
/* EDF350 80240990 D7B40060 */  ldc1      $f20, 0x60($sp)
/* EDF354 80240994 03E00008 */  jr        $ra
/* EDF358 80240998 27BD0080 */   addiu    $sp, $sp, 0x80
