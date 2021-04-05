.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata
glabel D_80263428_C20CA8
.double 0.09

glabel D_80263430_C20CB0
.double 0.09

.section .text
glabel func_802402D0_BFDB50
/* BFDB50 802402D0 27BDFF80 */  addiu     $sp, $sp, -0x80
/* BFDB54 802402D4 AFB3004C */  sw        $s3, 0x4c($sp)
/* BFDB58 802402D8 0080982D */  daddu     $s3, $a0, $zero
/* BFDB5C 802402DC AFBF0058 */  sw        $ra, 0x58($sp)
/* BFDB60 802402E0 AFB50054 */  sw        $s5, 0x54($sp)
/* BFDB64 802402E4 AFB40050 */  sw        $s4, 0x50($sp)
/* BFDB68 802402E8 AFB20048 */  sw        $s2, 0x48($sp)
/* BFDB6C 802402EC AFB10044 */  sw        $s1, 0x44($sp)
/* BFDB70 802402F0 AFB00040 */  sw        $s0, 0x40($sp)
/* BFDB74 802402F4 F7BA0078 */  sdc1      $f26, 0x78($sp)
/* BFDB78 802402F8 F7B80070 */  sdc1      $f24, 0x70($sp)
/* BFDB7C 802402FC F7B60068 */  sdc1      $f22, 0x68($sp)
/* BFDB80 80240300 F7B40060 */  sdc1      $f20, 0x60($sp)
/* BFDB84 80240304 8E710148 */  lw        $s1, 0x148($s3)
/* BFDB88 80240308 00A0902D */  daddu     $s2, $a1, $zero
/* BFDB8C 8024030C 86240008 */  lh        $a0, 8($s1)
/* BFDB90 80240310 0C00EABB */  jal       get_npc_unsafe
/* BFDB94 80240314 00C0A82D */   daddu    $s5, $a2, $zero
/* BFDB98 80240318 0040802D */  daddu     $s0, $v0, $zero
/* BFDB9C 8024031C 0000A02D */  daddu     $s4, $zero, $zero
/* BFDBA0 80240320 C624007C */  lwc1      $f4, 0x7c($s1)
/* BFDBA4 80240324 46802120 */  cvt.s.w   $f4, $f4
/* BFDBA8 80240328 C6220088 */  lwc1      $f2, 0x88($s1)
/* BFDBAC 8024032C 468010A0 */  cvt.s.w   $f2, $f2
/* BFDBB0 80240330 460010A1 */  cvt.d.s   $f2, $f2
/* BFDBB4 80240334 46002121 */  cvt.d.s   $f4, $f4
/* BFDBB8 80240338 C600003C */  lwc1      $f0, 0x3c($s0)
/* BFDBBC 8024033C 3C014059 */  lui       $at, 0x4059
/* BFDBC0 80240340 44813800 */  mtc1      $at, $f7
/* BFDBC4 80240344 44803000 */  mtc1      $zero, $f6
/* BFDBC8 80240348 46000021 */  cvt.d.s   $f0, $f0
/* BFDBCC 8024034C 46260002 */  mul.d     $f0, $f0, $f6
/* BFDBD0 80240350 00000000 */  nop
/* BFDBD4 80240354 24020001 */  addiu     $v0, $zero, 1
/* BFDBD8 80240358 8E24006C */  lw        $a0, 0x6c($s1)
/* BFDBDC 8024035C 46261083 */  div.d     $f2, $f2, $f6
/* BFDBE0 80240360 462010A0 */  cvt.s.d   $f2, $f2
/* BFDBE4 80240364 46262103 */  div.d     $f4, $f4, $f6
/* BFDBE8 80240368 46202520 */  cvt.s.d   $f20, $f4
/* BFDBEC 8024036C 30830011 */  andi      $v1, $a0, 0x11
/* BFDBF0 80240370 4620020D */  trunc.w.d $f8, $f0
/* BFDBF4 80240374 E628007C */  swc1      $f8, 0x7c($s1)
/* BFDBF8 80240378 C6200078 */  lwc1      $f0, 0x78($s1)
/* BFDBFC 8024037C 46800020 */  cvt.s.w   $f0, $f0
/* BFDC00 80240380 46000021 */  cvt.d.s   $f0, $f0
/* BFDC04 80240384 46260003 */  div.d     $f0, $f0, $f6
/* BFDC08 80240388 462006A0 */  cvt.s.d   $f26, $f0
/* BFDC0C 8024038C C6200070 */  lwc1      $f0, 0x70($s1)
/* BFDC10 80240390 46800020 */  cvt.s.w   $f0, $f0
/* BFDC14 80240394 46000021 */  cvt.d.s   $f0, $f0
/* BFDC18 80240398 46260003 */  div.d     $f0, $f0, $f6
/* BFDC1C 8024039C 462005A0 */  cvt.s.d   $f22, $f0
/* BFDC20 802403A0 14620025 */  bne       $v1, $v0, .L80240438
/* BFDC24 802403A4 4602D600 */   add.s    $f24, $f26, $f2
/* BFDC28 802403A8 8E020000 */  lw        $v0, ($s0)
/* BFDC2C 802403AC 30420008 */  andi      $v0, $v0, 8
/* BFDC30 802403B0 10400009 */  beqz      $v0, .L802403D8
/* BFDC34 802403B4 27A50028 */   addiu    $a1, $sp, 0x28
/* BFDC38 802403B8 C600003C */  lwc1      $f0, 0x3c($s0)
/* BFDC3C 802403BC 4600C001 */  sub.s     $f0, $f24, $f0
/* BFDC40 802403C0 4600B03C */  c.lt.s    $f22, $f0
/* BFDC44 802403C4 00000000 */  nop
/* BFDC48 802403C8 4500001B */  bc1f      .L80240438
/* BFDC4C 802403CC 34820010 */   ori      $v0, $a0, 0x10
/* BFDC50 802403D0 0809010E */  j         .L80240438
/* BFDC54 802403D4 AE22006C */   sw       $v0, 0x6c($s1)
.L802403D8:
/* BFDC58 802403D8 27A6002C */  addiu     $a2, $sp, 0x2c
/* BFDC5C 802403DC C6000038 */  lwc1      $f0, 0x38($s0)
/* BFDC60 802403E0 C602003C */  lwc1      $f2, 0x3c($s0)
/* BFDC64 802403E4 C6040040 */  lwc1      $f4, 0x40($s0)
/* BFDC68 802403E8 3C01447A */  lui       $at, 0x447a
/* BFDC6C 802403EC 44813000 */  mtc1      $at, $f6
/* BFDC70 802403F0 27A20034 */  addiu     $v0, $sp, 0x34
/* BFDC74 802403F4 E7A00028 */  swc1      $f0, 0x28($sp)
/* BFDC78 802403F8 E7A2002C */  swc1      $f2, 0x2c($sp)
/* BFDC7C 802403FC E7A40030 */  swc1      $f4, 0x30($sp)
/* BFDC80 80240400 E7A60034 */  swc1      $f6, 0x34($sp)
/* BFDC84 80240404 AFA20010 */  sw        $v0, 0x10($sp)
/* BFDC88 80240408 8E040080 */  lw        $a0, 0x80($s0)
/* BFDC8C 8024040C 0C0372DF */  jal       func_800DCB7C
/* BFDC90 80240410 27A70030 */   addiu    $a3, $sp, 0x30
/* BFDC94 80240414 C7A00034 */  lwc1      $f0, 0x34($sp)
/* BFDC98 80240418 4600D001 */  sub.s     $f0, $f26, $f0
/* BFDC9C 8024041C 4600B03C */  c.lt.s    $f22, $f0
/* BFDCA0 80240420 00000000 */  nop
/* BFDCA4 80240424 45000004 */  bc1f      .L80240438
/* BFDCA8 80240428 00000000 */   nop
/* BFDCAC 8024042C 8E22006C */  lw        $v0, 0x6c($s1)
/* BFDCB0 80240430 34420010 */  ori       $v0, $v0, 0x10
/* BFDCB4 80240434 AE22006C */  sw        $v0, 0x6c($s1)
.L80240438:
/* BFDCB8 80240438 8E22006C */  lw        $v0, 0x6c($s1)
/* BFDCBC 8024043C 24030011 */  addiu     $v1, $zero, 0x11
/* BFDCC0 80240440 30420011 */  andi      $v0, $v0, 0x11
/* BFDCC4 80240444 14430039 */  bne       $v0, $v1, .L8024052C
/* BFDCC8 80240448 00000000 */   nop
/* BFDCCC 8024044C 8E020000 */  lw        $v0, ($s0)
/* BFDCD0 80240450 30420008 */  andi      $v0, $v0, 8
/* BFDCD4 80240454 1040000A */  beqz      $v0, .L80240480
/* BFDCD8 80240458 4600C106 */   mov.s    $f4, $f24
/* BFDCDC 8024045C 4614C081 */  sub.s     $f2, $f24, $f20
/* BFDCE0 80240460 3C018026 */  lui       $at, %hi(D_80263428_C20CA8)
/* BFDCE4 80240464 D4203428 */  ldc1      $f0, %lo(D_80263428_C20CA8)($at)
/* BFDCE8 80240468 460010A1 */  cvt.d.s   $f2, $f2
/* BFDCEC 8024046C 46201082 */  mul.d     $f2, $f2, $f0
/* BFDCF0 80240470 00000000 */  nop
/* BFDCF4 80240474 4600A021 */  cvt.d.s   $f0, $f20
/* BFDCF8 80240478 08090139 */  j         .L802404E4
/* BFDCFC 8024047C 46220000 */   add.d    $f0, $f0, $f2
.L80240480:
/* BFDD00 80240480 27A50028 */  addiu     $a1, $sp, 0x28
/* BFDD04 80240484 27A6002C */  addiu     $a2, $sp, 0x2c
/* BFDD08 80240488 C6000038 */  lwc1      $f0, 0x38($s0)
/* BFDD0C 8024048C C6020040 */  lwc1      $f2, 0x40($s0)
/* BFDD10 80240490 3C01447A */  lui       $at, 0x447a
/* BFDD14 80240494 44812000 */  mtc1      $at, $f4
/* BFDD18 80240498 27A20034 */  addiu     $v0, $sp, 0x34
/* BFDD1C 8024049C E7B4002C */  swc1      $f20, 0x2c($sp)
/* BFDD20 802404A0 E7A00028 */  swc1      $f0, 0x28($sp)
/* BFDD24 802404A4 E7A20030 */  swc1      $f2, 0x30($sp)
/* BFDD28 802404A8 E7A40034 */  swc1      $f4, 0x34($sp)
/* BFDD2C 802404AC AFA20010 */  sw        $v0, 0x10($sp)
/* BFDD30 802404B0 8E040080 */  lw        $a0, 0x80($s0)
/* BFDD34 802404B4 0C0372DF */  jal       func_800DCB7C
/* BFDD38 802404B8 27A70030 */   addiu    $a3, $sp, 0x30
/* BFDD3C 802404BC C7A4002C */  lwc1      $f4, 0x2c($sp)
/* BFDD40 802404C0 461A2100 */  add.s     $f4, $f4, $f26
/* BFDD44 802404C4 46142081 */  sub.s     $f2, $f4, $f20
/* BFDD48 802404C8 3C018026 */  lui       $at, %hi(D_80263430_C20CB0)
/* BFDD4C 802404CC D4203430 */  ldc1      $f0, %lo(D_80263430_C20CB0)($at)
/* BFDD50 802404D0 460010A1 */  cvt.d.s   $f2, $f2
/* BFDD54 802404D4 46201082 */  mul.d     $f2, $f2, $f0
/* BFDD58 802404D8 00000000 */  nop
/* BFDD5C 802404DC 4600A021 */  cvt.d.s   $f0, $f20
/* BFDD60 802404E0 46220000 */  add.d     $f0, $f0, $f2
.L802404E4:
/* BFDD64 802404E4 46200020 */  cvt.s.d   $f0, $f0
/* BFDD68 802404E8 E600003C */  swc1      $f0, 0x3c($s0)
/* BFDD6C 802404EC C600003C */  lwc1      $f0, 0x3c($s0)
/* BFDD70 802404F0 46002001 */  sub.s     $f0, $f4, $f0
/* BFDD74 802404F4 3C013FF0 */  lui       $at, 0x3ff0
/* BFDD78 802404F8 44811800 */  mtc1      $at, $f3
/* BFDD7C 802404FC 44801000 */  mtc1      $zero, $f2
/* BFDD80 80240500 46000005 */  abs.s     $f0, $f0
/* BFDD84 80240504 46000021 */  cvt.d.s   $f0, $f0
/* BFDD88 80240508 4622003C */  c.lt.d    $f0, $f2
/* BFDD8C 8024050C 00000000 */  nop
/* BFDD90 80240510 45000036 */  bc1f      .L802405EC
/* BFDD94 80240514 2403FFEF */   addiu    $v1, $zero, -0x11
/* BFDD98 80240518 E604003C */  swc1      $f4, 0x3c($s0)
/* BFDD9C 8024051C 8E22006C */  lw        $v0, 0x6c($s1)
/* BFDDA0 80240520 00431024 */  and       $v0, $v0, $v1
/* BFDDA4 80240524 0809017B */  j         .L802405EC
/* BFDDA8 80240528 AE22006C */   sw       $v0, 0x6c($s1)
.L8024052C:
/* BFDDAC 8024052C 8E220070 */  lw        $v0, 0x70($s1)
/* BFDDB0 80240530 1840002E */  blez      $v0, .L802405EC
/* BFDDB4 80240534 00000000 */   nop
/* BFDDB8 80240538 C62C0074 */  lwc1      $f12, 0x74($s1)
/* BFDDBC 8024053C 0C00A8BB */  jal       sin_deg
/* BFDDC0 80240540 46806320 */   cvt.s.w  $f12, $f12
/* BFDDC4 80240544 8E020000 */  lw        $v0, ($s0)
/* BFDDC8 80240548 30420008 */  andi      $v0, $v0, 8
/* BFDDCC 8024054C 10400003 */  beqz      $v0, .L8024055C
/* BFDDD0 80240550 46000506 */   mov.s    $f20, $f0
/* BFDDD4 80240554 08090167 */  j         .L8024059C
/* BFDDD8 80240558 0000102D */   daddu    $v0, $zero, $zero
.L8024055C:
/* BFDDDC 8024055C 27A50028 */  addiu     $a1, $sp, 0x28
/* BFDDE0 80240560 27A6002C */  addiu     $a2, $sp, 0x2c
/* BFDDE4 80240564 C6000038 */  lwc1      $f0, 0x38($s0)
/* BFDDE8 80240568 C602003C */  lwc1      $f2, 0x3c($s0)
/* BFDDEC 8024056C C6040040 */  lwc1      $f4, 0x40($s0)
/* BFDDF0 80240570 3C01447A */  lui       $at, 0x447a
/* BFDDF4 80240574 44813000 */  mtc1      $at, $f6
/* BFDDF8 80240578 27A20034 */  addiu     $v0, $sp, 0x34
/* BFDDFC 8024057C E7A00028 */  swc1      $f0, 0x28($sp)
/* BFDE00 80240580 E7A2002C */  swc1      $f2, 0x2c($sp)
/* BFDE04 80240584 E7A40030 */  swc1      $f4, 0x30($sp)
/* BFDE08 80240588 E7A60034 */  swc1      $f6, 0x34($sp)
/* BFDE0C 8024058C AFA20010 */  sw        $v0, 0x10($sp)
/* BFDE10 80240590 8E040080 */  lw        $a0, 0x80($s0)
/* BFDE14 80240594 0C0372DF */  jal       func_800DCB7C
/* BFDE18 80240598 27A70030 */   addiu    $a3, $sp, 0x30
.L8024059C:
/* BFDE1C 8024059C 10400007 */  beqz      $v0, .L802405BC
/* BFDE20 802405A0 00000000 */   nop
/* BFDE24 802405A4 4616A082 */  mul.s     $f2, $f20, $f22
/* BFDE28 802405A8 00000000 */  nop
/* BFDE2C 802405AC C7A0002C */  lwc1      $f0, 0x2c($sp)
/* BFDE30 802405B0 461A0000 */  add.s     $f0, $f0, $f26
/* BFDE34 802405B4 08090172 */  j         .L802405C8
/* BFDE38 802405B8 46020000 */   add.s    $f0, $f0, $f2
.L802405BC:
/* BFDE3C 802405BC 4616A002 */  mul.s     $f0, $f20, $f22
/* BFDE40 802405C0 00000000 */  nop
/* BFDE44 802405C4 4600C000 */  add.s     $f0, $f24, $f0
.L802405C8:
/* BFDE48 802405C8 E600003C */  swc1      $f0, 0x3c($s0)
/* BFDE4C 802405CC 8E220074 */  lw        $v0, 0x74($s1)
/* BFDE50 802405D0 2442000A */  addiu     $v0, $v0, 0xa
/* BFDE54 802405D4 44826000 */  mtc1      $v0, $f12
/* BFDE58 802405D8 00000000 */  nop
/* BFDE5C 802405DC 0C00A6C9 */  jal       clamp_angle
/* BFDE60 802405E0 46806320 */   cvt.s.w  $f12, $f12
/* BFDE64 802405E4 4600020D */  trunc.w.s $f8, $f0
/* BFDE68 802405E8 E6280074 */  swc1      $f8, 0x74($s1)
.L802405EC:
/* BFDE6C 802405EC 8E220090 */  lw        $v0, 0x90($s1)
/* BFDE70 802405F0 1C40004A */  bgtz      $v0, .L8024071C
/* BFDE74 802405F4 2442FFFF */   addiu    $v0, $v0, -1
/* BFDE78 802405F8 8E430014 */  lw        $v1, 0x14($s2)
/* BFDE7C 802405FC 04600048 */  bltz      $v1, .L80240720
/* BFDE80 80240600 00000000 */   nop
/* BFDE84 80240604 8E620074 */  lw        $v0, 0x74($s3)
/* BFDE88 80240608 1C400042 */  bgtz      $v0, .L80240714
/* BFDE8C 8024060C 2442FFFF */   addiu    $v0, $v0, -1
/* BFDE90 80240610 AE630074 */  sw        $v1, 0x74($s3)
/* BFDE94 80240614 860200A8 */  lh        $v0, 0xa8($s0)
/* BFDE98 80240618 C602003C */  lwc1      $f2, 0x3c($s0)
/* BFDE9C 8024061C 44820000 */  mtc1      $v0, $f0
/* BFDEA0 80240620 00000000 */  nop
/* BFDEA4 80240624 46800020 */  cvt.s.w   $f0, $f0
/* BFDEA8 80240628 46001080 */  add.s     $f2, $f2, $f0
/* BFDEAC 8024062C 3C014024 */  lui       $at, 0x4024
/* BFDEB0 80240630 44810800 */  mtc1      $at, $f1
/* BFDEB4 80240634 44800000 */  mtc1      $zero, $f0
/* BFDEB8 80240638 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BFDEBC 8024063C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BFDEC0 80240640 460010A1 */  cvt.d.s   $f2, $f2
/* BFDEC4 80240644 46201080 */  add.d     $f2, $f2, $f0
/* BFDEC8 80240648 C440002C */  lwc1      $f0, 0x2c($v0)
/* BFDECC 8024064C 46000021 */  cvt.d.s   $f0, $f0
/* BFDED0 80240650 4622003C */  c.lt.d    $f0, $f2
/* BFDED4 80240654 00000000 */  nop
/* BFDED8 80240658 4500002C */  bc1f      .L8024070C
/* BFDEDC 8024065C 02A0202D */   daddu    $a0, $s5, $zero
/* BFDEE0 80240660 AFA00010 */  sw        $zero, 0x10($sp)
/* BFDEE4 80240664 8E46000C */  lw        $a2, 0xc($s2)
/* BFDEE8 80240668 8E470010 */  lw        $a3, 0x10($s2)
/* BFDEEC 8024066C 0C01242D */  jal       func_800490B4
/* BFDEF0 80240670 0220282D */   daddu    $a1, $s1, $zero
/* BFDEF4 80240674 10400025 */  beqz      $v0, .L8024070C
/* BFDEF8 80240678 0000202D */   daddu    $a0, $zero, $zero
/* BFDEFC 8024067C 0200282D */  daddu     $a1, $s0, $zero
/* BFDF00 80240680 0000302D */  daddu     $a2, $zero, $zero
/* BFDF04 80240684 2412000C */  addiu     $s2, $zero, 0xc
/* BFDF08 80240688 860300A8 */  lh        $v1, 0xa8($s0)
/* BFDF0C 8024068C 3C013F80 */  lui       $at, 0x3f80
/* BFDF10 80240690 44810000 */  mtc1      $at, $f0
/* BFDF14 80240694 3C014000 */  lui       $at, 0x4000
/* BFDF18 80240698 44811000 */  mtc1      $at, $f2
/* BFDF1C 8024069C 3C01C1A0 */  lui       $at, 0xc1a0
/* BFDF20 802406A0 44812000 */  mtc1      $at, $f4
/* BFDF24 802406A4 44834000 */  mtc1      $v1, $f8
/* BFDF28 802406A8 00000000 */  nop
/* BFDF2C 802406AC 46804220 */  cvt.s.w   $f8, $f8
/* BFDF30 802406B0 44074000 */  mfc1      $a3, $f8
/* BFDF34 802406B4 27A20038 */  addiu     $v0, $sp, 0x38
/* BFDF38 802406B8 AFB2001C */  sw        $s2, 0x1c($sp)
/* BFDF3C 802406BC AFA20020 */  sw        $v0, 0x20($sp)
/* BFDF40 802406C0 E7A00010 */  swc1      $f0, 0x10($sp)
/* BFDF44 802406C4 E7A20014 */  swc1      $f2, 0x14($sp)
/* BFDF48 802406C8 0C01BFA4 */  jal       fx_emote
/* BFDF4C 802406CC E7A40018 */   swc1     $f4, 0x18($sp)
/* BFDF50 802406D0 0200202D */  daddu     $a0, $s0, $zero
/* BFDF54 802406D4 240502F4 */  addiu     $a1, $zero, 0x2f4
/* BFDF58 802406D8 C480003C */  lwc1      $f0, 0x3c($a0)
/* BFDF5C 802406DC 3C060020 */  lui       $a2, 0x20
/* BFDF60 802406E0 0C012530 */  jal       func_800494C0
/* BFDF64 802406E4 E4800064 */   swc1     $f0, 0x64($a0)
/* BFDF68 802406E8 8E220018 */  lw        $v0, 0x18($s1)
/* BFDF6C 802406EC 9442002A */  lhu       $v0, 0x2a($v0)
/* BFDF70 802406F0 30420001 */  andi      $v0, $v0, 1
/* BFDF74 802406F4 10400003 */  beqz      $v0, .L80240704
/* BFDF78 802406F8 2402000A */   addiu    $v0, $zero, 0xa
/* BFDF7C 802406FC 08090231 */  j         .L802408C4
/* BFDF80 80240700 AE620070 */   sw       $v0, 0x70($s3)
.L80240704:
/* BFDF84 80240704 08090231 */  j         .L802408C4
/* BFDF88 80240708 AE720070 */   sw       $s2, 0x70($s3)
.L8024070C:
/* BFDF8C 8024070C 8E620074 */  lw        $v0, 0x74($s3)
/* BFDF90 80240710 2442FFFF */  addiu     $v0, $v0, -1
.L80240714:
/* BFDF94 80240714 080901C8 */  j         .L80240720
/* BFDF98 80240718 AE620074 */   sw       $v0, 0x74($s3)
.L8024071C:
/* BFDF9C 8024071C AE220090 */  sw        $v0, 0x90($s1)
.L80240720:
/* BFDFA0 80240720 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BFDFA4 80240724 C6000040 */  lwc1      $f0, 0x40($s0)
/* BFDFA8 80240728 C4620000 */  lwc1      $f2, ($v1)
/* BFDFAC 8024072C 468010A0 */  cvt.s.w   $f2, $f2
/* BFDFB0 80240730 C4640008 */  lwc1      $f4, 8($v1)
/* BFDFB4 80240734 46802120 */  cvt.s.w   $f4, $f4
/* BFDFB8 80240738 E7A00010 */  swc1      $f0, 0x10($sp)
/* BFDFBC 8024073C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BFDFC0 80240740 44051000 */  mfc1      $a1, $f2
/* BFDFC4 80240744 C440000C */  lwc1      $f0, 0xc($v0)
/* BFDFC8 80240748 46800020 */  cvt.s.w   $f0, $f0
/* BFDFCC 8024074C E7A00014 */  swc1      $f0, 0x14($sp)
/* BFDFD0 80240750 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BFDFD4 80240754 44062000 */  mfc1      $a2, $f4
/* BFDFD8 80240758 C4400010 */  lwc1      $f0, 0x10($v0)
/* BFDFDC 8024075C 46800020 */  cvt.s.w   $f0, $f0
/* BFDFE0 80240760 E7A00018 */  swc1      $f0, 0x18($sp)
/* BFDFE4 80240764 8C640018 */  lw        $a0, 0x18($v1)
/* BFDFE8 80240768 0C0123F5 */  jal       is_point_within_region
/* BFDFEC 8024076C 8E070038 */   lw       $a3, 0x38($s0)
/* BFDFF0 80240770 1040001A */  beqz      $v0, .L802407DC
/* BFDFF4 80240774 00000000 */   nop
/* BFDFF8 80240778 8E060038 */  lw        $a2, 0x38($s0)
/* BFDFFC 8024077C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BFE000 80240780 8E070040 */  lw        $a3, 0x40($s0)
/* BFE004 80240784 C44C0000 */  lwc1      $f12, ($v0)
/* BFE008 80240788 46806320 */  cvt.s.w   $f12, $f12
/* BFE00C 8024078C C44E0008 */  lwc1      $f14, 8($v0)
/* BFE010 80240790 0C00A7B5 */  jal       dist2D
/* BFE014 80240794 468073A0 */   cvt.s.w  $f14, $f14
/* BFE018 80240798 C6020018 */  lwc1      $f2, 0x18($s0)
/* BFE01C 8024079C 4600103C */  c.lt.s    $f2, $f0
/* BFE020 802407A0 00000000 */  nop
/* BFE024 802407A4 4500000D */  bc1f      .L802407DC
/* BFE028 802407A8 E7A00034 */   swc1     $f0, 0x34($sp)
/* BFE02C 802407AC C60C0038 */  lwc1      $f12, 0x38($s0)
/* BFE030 802407B0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BFE034 802407B4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BFE038 802407B8 C4480000 */  lwc1      $f8, ($v0)
/* BFE03C 802407BC 46804220 */  cvt.s.w   $f8, $f8
/* BFE040 802407C0 44064000 */  mfc1      $a2, $f8
/* BFE044 802407C4 C4480008 */  lwc1      $f8, 8($v0)
/* BFE048 802407C8 46804220 */  cvt.s.w   $f8, $f8
/* BFE04C 802407CC 44074000 */  mfc1      $a3, $f8
/* BFE050 802407D0 0C00A720 */  jal       atan2
/* BFE054 802407D4 24140001 */   addiu    $s4, $zero, 1
/* BFE058 802407D8 E600000C */  swc1      $f0, 0xc($s0)
.L802407DC:
/* BFE05C 802407DC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BFE060 802407E0 8C43000C */  lw        $v1, 0xc($v0)
/* BFE064 802407E4 8C420010 */  lw        $v0, 0x10($v0)
/* BFE068 802407E8 00621825 */  or        $v1, $v1, $v0
/* BFE06C 802407EC 00741825 */  or        $v1, $v1, $s4
/* BFE070 802407F0 10600008 */  beqz      $v1, .L80240814
/* BFE074 802407F4 00000000 */   nop
/* BFE078 802407F8 8602008C */  lh        $v0, 0x8c($s0)
/* BFE07C 802407FC 14400031 */  bnez      $v0, .L802408C4
/* BFE080 80240800 00000000 */   nop
/* BFE084 80240804 8E050018 */  lw        $a1, 0x18($s0)
/* BFE088 80240808 8E06000C */  lw        $a2, 0xc($s0)
/* BFE08C 8024080C 0C00EA95 */  jal       npc_move_heading
/* BFE090 80240810 0200202D */   daddu    $a0, $s0, $zero
.L80240814:
/* BFE094 80240814 C600003C */  lwc1      $f0, 0x3c($s0)
/* BFE098 80240818 3C014059 */  lui       $at, 0x4059
/* BFE09C 8024081C 44811800 */  mtc1      $at, $f3
/* BFE0A0 80240820 44801000 */  mtc1      $zero, $f2
/* BFE0A4 80240824 46000021 */  cvt.d.s   $f0, $f0
/* BFE0A8 80240828 46220002 */  mul.d     $f0, $f0, $f2
/* BFE0AC 8024082C 00000000 */  nop
/* BFE0B0 80240830 4620020D */  trunc.w.d $f8, $f0
/* BFE0B4 80240834 E628007C */  swc1      $f8, 0x7c($s1)
/* BFE0B8 80240838 8E420004 */  lw        $v0, 4($s2)
/* BFE0BC 8024083C 18400021 */  blez      $v0, .L802408C4
/* BFE0C0 80240840 00000000 */   nop
/* BFE0C4 80240844 8602008E */  lh        $v0, 0x8e($s0)
/* BFE0C8 80240848 9603008E */  lhu       $v1, 0x8e($s0)
/* BFE0CC 8024084C 18400005 */  blez      $v0, .L80240864
/* BFE0D0 80240850 2462FFFF */   addiu    $v0, $v1, -1
/* BFE0D4 80240854 A602008E */  sh        $v0, 0x8e($s0)
/* BFE0D8 80240858 00021400 */  sll       $v0, $v0, 0x10
/* BFE0DC 8024085C 1C400019 */  bgtz      $v0, .L802408C4
/* BFE0E0 80240860 00000000 */   nop
.L80240864:
/* BFE0E4 80240864 240403E8 */  addiu     $a0, $zero, 0x3e8
/* BFE0E8 80240868 24020002 */  addiu     $v0, $zero, 2
/* BFE0EC 8024086C 0C00A67F */  jal       rand_int
/* BFE0F0 80240870 AE620070 */   sw       $v0, 0x70($s3)
/* BFE0F4 80240874 3C035555 */  lui       $v1, 0x5555
/* BFE0F8 80240878 34635556 */  ori       $v1, $v1, 0x5556
/* BFE0FC 8024087C 00430018 */  mult      $v0, $v1
/* BFE100 80240880 000227C3 */  sra       $a0, $v0, 0x1f
/* BFE104 80240884 00004010 */  mfhi      $t0
/* BFE108 80240888 01042023 */  subu      $a0, $t0, $a0
/* BFE10C 8024088C 00041840 */  sll       $v1, $a0, 1
/* BFE110 80240890 00641821 */  addu      $v1, $v1, $a0
/* BFE114 80240894 00431023 */  subu      $v0, $v0, $v1
/* BFE118 80240898 24430002 */  addiu     $v1, $v0, 2
/* BFE11C 8024089C AE630074 */  sw        $v1, 0x74($s3)
/* BFE120 802408A0 8E42002C */  lw        $v0, 0x2c($s2)
/* BFE124 802408A4 58400007 */  blezl     $v0, .L802408C4
/* BFE128 802408A8 AE600070 */   sw       $zero, 0x70($s3)
/* BFE12C 802408AC 8E420008 */  lw        $v0, 8($s2)
/* BFE130 802408B0 18400003 */  blez      $v0, .L802408C0
/* BFE134 802408B4 28620003 */   slti     $v0, $v1, 3
/* BFE138 802408B8 10400002 */  beqz      $v0, .L802408C4
/* BFE13C 802408BC 00000000 */   nop
.L802408C0:
/* BFE140 802408C0 AE600070 */  sw        $zero, 0x70($s3)
.L802408C4:
/* BFE144 802408C4 8FBF0058 */  lw        $ra, 0x58($sp)
/* BFE148 802408C8 8FB50054 */  lw        $s5, 0x54($sp)
/* BFE14C 802408CC 8FB40050 */  lw        $s4, 0x50($sp)
/* BFE150 802408D0 8FB3004C */  lw        $s3, 0x4c($sp)
/* BFE154 802408D4 8FB20048 */  lw        $s2, 0x48($sp)
/* BFE158 802408D8 8FB10044 */  lw        $s1, 0x44($sp)
/* BFE15C 802408DC 8FB00040 */  lw        $s0, 0x40($sp)
/* BFE160 802408E0 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* BFE164 802408E4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* BFE168 802408E8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* BFE16C 802408EC D7B40060 */  ldc1      $f20, 0x60($sp)
/* BFE170 802408F0 03E00008 */  jr        $ra
/* BFE174 802408F4 27BD0080 */   addiu    $sp, $sp, 0x80
