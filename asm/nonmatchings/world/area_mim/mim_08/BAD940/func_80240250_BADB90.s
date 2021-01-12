.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240250_BADB90
/* BADB90 80240250 27BDFF80 */  addiu     $sp, $sp, -0x80
/* BADB94 80240254 AFB3004C */  sw        $s3, 0x4c($sp)
/* BADB98 80240258 0080982D */  daddu     $s3, $a0, $zero
/* BADB9C 8024025C AFBF0058 */  sw        $ra, 0x58($sp)
/* BADBA0 80240260 AFB50054 */  sw        $s5, 0x54($sp)
/* BADBA4 80240264 AFB40050 */  sw        $s4, 0x50($sp)
/* BADBA8 80240268 AFB20048 */  sw        $s2, 0x48($sp)
/* BADBAC 8024026C AFB10044 */  sw        $s1, 0x44($sp)
/* BADBB0 80240270 AFB00040 */  sw        $s0, 0x40($sp)
/* BADBB4 80240274 F7BA0078 */  sdc1      $f26, 0x78($sp)
/* BADBB8 80240278 F7B80070 */  sdc1      $f24, 0x70($sp)
/* BADBBC 8024027C F7B60068 */  sdc1      $f22, 0x68($sp)
/* BADBC0 80240280 F7B40060 */  sdc1      $f20, 0x60($sp)
/* BADBC4 80240284 8E710148 */  lw        $s1, 0x148($s3)
/* BADBC8 80240288 00A0902D */  daddu     $s2, $a1, $zero
/* BADBCC 8024028C 86240008 */  lh        $a0, 8($s1)
/* BADBD0 80240290 0C00EABB */  jal       get_npc_unsafe
/* BADBD4 80240294 00C0A82D */   daddu    $s5, $a2, $zero
/* BADBD8 80240298 0040802D */  daddu     $s0, $v0, $zero
/* BADBDC 8024029C 0000A02D */  daddu     $s4, $zero, $zero
/* BADBE0 802402A0 C624007C */  lwc1      $f4, 0x7c($s1)
/* BADBE4 802402A4 46802120 */  cvt.s.w   $f4, $f4
/* BADBE8 802402A8 C6220088 */  lwc1      $f2, 0x88($s1)
/* BADBEC 802402AC 468010A0 */  cvt.s.w   $f2, $f2
/* BADBF0 802402B0 460010A1 */  cvt.d.s   $f2, $f2
/* BADBF4 802402B4 46002121 */  cvt.d.s   $f4, $f4
/* BADBF8 802402B8 C600003C */  lwc1      $f0, 0x3c($s0)
/* BADBFC 802402BC 3C014059 */  lui       $at, 0x4059
/* BADC00 802402C0 44813800 */  mtc1      $at, $f7
/* BADC04 802402C4 44803000 */  mtc1      $zero, $f6
/* BADC08 802402C8 46000021 */  cvt.d.s   $f0, $f0
/* BADC0C 802402CC 46260002 */  mul.d     $f0, $f0, $f6
/* BADC10 802402D0 00000000 */  nop
/* BADC14 802402D4 24020001 */  addiu     $v0, $zero, 1
/* BADC18 802402D8 8E24006C */  lw        $a0, 0x6c($s1)
/* BADC1C 802402DC 46261083 */  div.d     $f2, $f2, $f6
/* BADC20 802402E0 462010A0 */  cvt.s.d   $f2, $f2
/* BADC24 802402E4 46262103 */  div.d     $f4, $f4, $f6
/* BADC28 802402E8 46202520 */  cvt.s.d   $f20, $f4
/* BADC2C 802402EC 30830011 */  andi      $v1, $a0, 0x11
/* BADC30 802402F0 4620020D */  trunc.w.d $f8, $f0
/* BADC34 802402F4 E628007C */  swc1      $f8, 0x7c($s1)
/* BADC38 802402F8 C6200078 */  lwc1      $f0, 0x78($s1)
/* BADC3C 802402FC 46800020 */  cvt.s.w   $f0, $f0
/* BADC40 80240300 46000021 */  cvt.d.s   $f0, $f0
/* BADC44 80240304 46260003 */  div.d     $f0, $f0, $f6
/* BADC48 80240308 462006A0 */  cvt.s.d   $f26, $f0
/* BADC4C 8024030C C6200070 */  lwc1      $f0, 0x70($s1)
/* BADC50 80240310 46800020 */  cvt.s.w   $f0, $f0
/* BADC54 80240314 46000021 */  cvt.d.s   $f0, $f0
/* BADC58 80240318 46260003 */  div.d     $f0, $f0, $f6
/* BADC5C 8024031C 462005A0 */  cvt.s.d   $f22, $f0
/* BADC60 80240320 14620025 */  bne       $v1, $v0, .L802403B8
/* BADC64 80240324 4602D600 */   add.s    $f24, $f26, $f2
/* BADC68 80240328 8E020000 */  lw        $v0, ($s0)
/* BADC6C 8024032C 30420008 */  andi      $v0, $v0, 8
/* BADC70 80240330 10400009 */  beqz      $v0, .L80240358
/* BADC74 80240334 27A50028 */   addiu    $a1, $sp, 0x28
/* BADC78 80240338 C600003C */  lwc1      $f0, 0x3c($s0)
/* BADC7C 8024033C 4600C001 */  sub.s     $f0, $f24, $f0
/* BADC80 80240340 4600B03C */  c.lt.s    $f22, $f0
/* BADC84 80240344 00000000 */  nop
/* BADC88 80240348 4500001B */  bc1f      .L802403B8
/* BADC8C 8024034C 34820010 */   ori      $v0, $a0, 0x10
/* BADC90 80240350 080900EE */  j         .L802403B8
/* BADC94 80240354 AE22006C */   sw       $v0, 0x6c($s1)
.L80240358:
/* BADC98 80240358 27A6002C */  addiu     $a2, $sp, 0x2c
/* BADC9C 8024035C C6000038 */  lwc1      $f0, 0x38($s0)
/* BADCA0 80240360 C602003C */  lwc1      $f2, 0x3c($s0)
/* BADCA4 80240364 C6040040 */  lwc1      $f4, 0x40($s0)
/* BADCA8 80240368 3C01447A */  lui       $at, 0x447a
/* BADCAC 8024036C 44813000 */  mtc1      $at, $f6
/* BADCB0 80240370 27A20034 */  addiu     $v0, $sp, 0x34
/* BADCB4 80240374 E7A00028 */  swc1      $f0, 0x28($sp)
/* BADCB8 80240378 E7A2002C */  swc1      $f2, 0x2c($sp)
/* BADCBC 8024037C E7A40030 */  swc1      $f4, 0x30($sp)
/* BADCC0 80240380 E7A60034 */  swc1      $f6, 0x34($sp)
/* BADCC4 80240384 AFA20010 */  sw        $v0, 0x10($sp)
/* BADCC8 80240388 8E040080 */  lw        $a0, 0x80($s0)
/* BADCCC 8024038C 0C0372DF */  jal       func_800DCB7C
/* BADCD0 80240390 27A70030 */   addiu    $a3, $sp, 0x30
/* BADCD4 80240394 C7A00034 */  lwc1      $f0, 0x34($sp)
/* BADCD8 80240398 4600D001 */  sub.s     $f0, $f26, $f0
/* BADCDC 8024039C 4600B03C */  c.lt.s    $f22, $f0
/* BADCE0 802403A0 00000000 */  nop
/* BADCE4 802403A4 45000004 */  bc1f      .L802403B8
/* BADCE8 802403A8 00000000 */   nop
/* BADCEC 802403AC 8E22006C */  lw        $v0, 0x6c($s1)
/* BADCF0 802403B0 34420010 */  ori       $v0, $v0, 0x10
/* BADCF4 802403B4 AE22006C */  sw        $v0, 0x6c($s1)
.L802403B8:
/* BADCF8 802403B8 8E22006C */  lw        $v0, 0x6c($s1)
/* BADCFC 802403BC 24030011 */  addiu     $v1, $zero, 0x11
/* BADD00 802403C0 30420011 */  andi      $v0, $v0, 0x11
/* BADD04 802403C4 14430039 */  bne       $v0, $v1, .L802404AC
/* BADD08 802403C8 00000000 */   nop
/* BADD0C 802403CC 8E020000 */  lw        $v0, ($s0)
/* BADD10 802403D0 30420008 */  andi      $v0, $v0, 8
/* BADD14 802403D4 1040000A */  beqz      $v0, .L80240400
/* BADD18 802403D8 4600C106 */   mov.s    $f4, $f24
/* BADD1C 802403DC 4614C081 */  sub.s     $f2, $f24, $f20
/* BADD20 802403E0 3C018024 */  lui       $at, %hi(D_802452A8)
/* BADD24 802403E4 D42052A8 */  ldc1      $f0, %lo(D_802452A8)($at)
/* BADD28 802403E8 460010A1 */  cvt.d.s   $f2, $f2
/* BADD2C 802403EC 46201082 */  mul.d     $f2, $f2, $f0
/* BADD30 802403F0 00000000 */  nop
/* BADD34 802403F4 4600A021 */  cvt.d.s   $f0, $f20
/* BADD38 802403F8 08090119 */  j         .L80240464
/* BADD3C 802403FC 46220000 */   add.d    $f0, $f0, $f2
.L80240400:
/* BADD40 80240400 27A50028 */  addiu     $a1, $sp, 0x28
/* BADD44 80240404 27A6002C */  addiu     $a2, $sp, 0x2c
/* BADD48 80240408 C6000038 */  lwc1      $f0, 0x38($s0)
/* BADD4C 8024040C C6020040 */  lwc1      $f2, 0x40($s0)
/* BADD50 80240410 3C01447A */  lui       $at, 0x447a
/* BADD54 80240414 44812000 */  mtc1      $at, $f4
/* BADD58 80240418 27A20034 */  addiu     $v0, $sp, 0x34
/* BADD5C 8024041C E7B4002C */  swc1      $f20, 0x2c($sp)
/* BADD60 80240420 E7A00028 */  swc1      $f0, 0x28($sp)
/* BADD64 80240424 E7A20030 */  swc1      $f2, 0x30($sp)
/* BADD68 80240428 E7A40034 */  swc1      $f4, 0x34($sp)
/* BADD6C 8024042C AFA20010 */  sw        $v0, 0x10($sp)
/* BADD70 80240430 8E040080 */  lw        $a0, 0x80($s0)
/* BADD74 80240434 0C0372DF */  jal       func_800DCB7C
/* BADD78 80240438 27A70030 */   addiu    $a3, $sp, 0x30
/* BADD7C 8024043C C7A4002C */  lwc1      $f4, 0x2c($sp)
/* BADD80 80240440 461A2100 */  add.s     $f4, $f4, $f26
/* BADD84 80240444 46142081 */  sub.s     $f2, $f4, $f20
/* BADD88 80240448 3C018024 */  lui       $at, %hi(D_802452B0)
/* BADD8C 8024044C D42052B0 */  ldc1      $f0, %lo(D_802452B0)($at)
/* BADD90 80240450 460010A1 */  cvt.d.s   $f2, $f2
/* BADD94 80240454 46201082 */  mul.d     $f2, $f2, $f0
/* BADD98 80240458 00000000 */  nop
/* BADD9C 8024045C 4600A021 */  cvt.d.s   $f0, $f20
/* BADDA0 80240460 46220000 */  add.d     $f0, $f0, $f2
.L80240464:
/* BADDA4 80240464 46200020 */  cvt.s.d   $f0, $f0
/* BADDA8 80240468 E600003C */  swc1      $f0, 0x3c($s0)
/* BADDAC 8024046C C600003C */  lwc1      $f0, 0x3c($s0)
/* BADDB0 80240470 46002001 */  sub.s     $f0, $f4, $f0
/* BADDB4 80240474 3C013FF0 */  lui       $at, 0x3ff0
/* BADDB8 80240478 44811800 */  mtc1      $at, $f3
/* BADDBC 8024047C 44801000 */  mtc1      $zero, $f2
/* BADDC0 80240480 46000005 */  abs.s     $f0, $f0
/* BADDC4 80240484 46000021 */  cvt.d.s   $f0, $f0
/* BADDC8 80240488 4622003C */  c.lt.d    $f0, $f2
/* BADDCC 8024048C 00000000 */  nop
/* BADDD0 80240490 45000036 */  bc1f      .L8024056C
/* BADDD4 80240494 2403FFEF */   addiu    $v1, $zero, -0x11
/* BADDD8 80240498 E604003C */  swc1      $f4, 0x3c($s0)
/* BADDDC 8024049C 8E22006C */  lw        $v0, 0x6c($s1)
/* BADDE0 802404A0 00431024 */  and       $v0, $v0, $v1
/* BADDE4 802404A4 0809015B */  j         .L8024056C
/* BADDE8 802404A8 AE22006C */   sw       $v0, 0x6c($s1)
.L802404AC:
/* BADDEC 802404AC 8E220070 */  lw        $v0, 0x70($s1)
/* BADDF0 802404B0 1840002E */  blez      $v0, .L8024056C
/* BADDF4 802404B4 00000000 */   nop
/* BADDF8 802404B8 C62C0074 */  lwc1      $f12, 0x74($s1)
/* BADDFC 802404BC 0C00A8BB */  jal       sin_deg
/* BADE00 802404C0 46806320 */   cvt.s.w  $f12, $f12
/* BADE04 802404C4 8E020000 */  lw        $v0, ($s0)
/* BADE08 802404C8 30420008 */  andi      $v0, $v0, 8
/* BADE0C 802404CC 10400003 */  beqz      $v0, .L802404DC
/* BADE10 802404D0 46000506 */   mov.s    $f20, $f0
/* BADE14 802404D4 08090147 */  j         .L8024051C
/* BADE18 802404D8 0000102D */   daddu    $v0, $zero, $zero
.L802404DC:
/* BADE1C 802404DC 27A50028 */  addiu     $a1, $sp, 0x28
/* BADE20 802404E0 27A6002C */  addiu     $a2, $sp, 0x2c
/* BADE24 802404E4 C6000038 */  lwc1      $f0, 0x38($s0)
/* BADE28 802404E8 C602003C */  lwc1      $f2, 0x3c($s0)
/* BADE2C 802404EC C6040040 */  lwc1      $f4, 0x40($s0)
/* BADE30 802404F0 3C01447A */  lui       $at, 0x447a
/* BADE34 802404F4 44813000 */  mtc1      $at, $f6
/* BADE38 802404F8 27A20034 */  addiu     $v0, $sp, 0x34
/* BADE3C 802404FC E7A00028 */  swc1      $f0, 0x28($sp)
/* BADE40 80240500 E7A2002C */  swc1      $f2, 0x2c($sp)
/* BADE44 80240504 E7A40030 */  swc1      $f4, 0x30($sp)
/* BADE48 80240508 E7A60034 */  swc1      $f6, 0x34($sp)
/* BADE4C 8024050C AFA20010 */  sw        $v0, 0x10($sp)
/* BADE50 80240510 8E040080 */  lw        $a0, 0x80($s0)
/* BADE54 80240514 0C0372DF */  jal       func_800DCB7C
/* BADE58 80240518 27A70030 */   addiu    $a3, $sp, 0x30
.L8024051C:
/* BADE5C 8024051C 10400007 */  beqz      $v0, .L8024053C
/* BADE60 80240520 00000000 */   nop
/* BADE64 80240524 4616A082 */  mul.s     $f2, $f20, $f22
/* BADE68 80240528 00000000 */  nop
/* BADE6C 8024052C C7A0002C */  lwc1      $f0, 0x2c($sp)
/* BADE70 80240530 461A0000 */  add.s     $f0, $f0, $f26
/* BADE74 80240534 08090152 */  j         .L80240548
/* BADE78 80240538 46020000 */   add.s    $f0, $f0, $f2
.L8024053C:
/* BADE7C 8024053C 4616A002 */  mul.s     $f0, $f20, $f22
/* BADE80 80240540 00000000 */  nop
/* BADE84 80240544 4600C000 */  add.s     $f0, $f24, $f0
.L80240548:
/* BADE88 80240548 E600003C */  swc1      $f0, 0x3c($s0)
/* BADE8C 8024054C 8E220074 */  lw        $v0, 0x74($s1)
/* BADE90 80240550 2442000A */  addiu     $v0, $v0, 0xa
/* BADE94 80240554 44826000 */  mtc1      $v0, $f12
/* BADE98 80240558 00000000 */  nop
/* BADE9C 8024055C 0C00A6C9 */  jal       clamp_angle
/* BADEA0 80240560 46806320 */   cvt.s.w  $f12, $f12
/* BADEA4 80240564 4600020D */  trunc.w.s $f8, $f0
/* BADEA8 80240568 E6280074 */  swc1      $f8, 0x74($s1)
.L8024056C:
/* BADEAC 8024056C 8E220090 */  lw        $v0, 0x90($s1)
/* BADEB0 80240570 1C40004A */  bgtz      $v0, .L8024069C
/* BADEB4 80240574 2442FFFF */   addiu    $v0, $v0, -1
/* BADEB8 80240578 8E430014 */  lw        $v1, 0x14($s2)
/* BADEBC 8024057C 04600048 */  bltz      $v1, .L802406A0
/* BADEC0 80240580 00000000 */   nop
/* BADEC4 80240584 8E620074 */  lw        $v0, 0x74($s3)
/* BADEC8 80240588 1C400042 */  bgtz      $v0, .L80240694
/* BADECC 8024058C 2442FFFF */   addiu    $v0, $v0, -1
/* BADED0 80240590 AE630074 */  sw        $v1, 0x74($s3)
/* BADED4 80240594 860200A8 */  lh        $v0, 0xa8($s0)
/* BADED8 80240598 C602003C */  lwc1      $f2, 0x3c($s0)
/* BADEDC 8024059C 44820000 */  mtc1      $v0, $f0
/* BADEE0 802405A0 00000000 */  nop
/* BADEE4 802405A4 46800020 */  cvt.s.w   $f0, $f0
/* BADEE8 802405A8 46001080 */  add.s     $f2, $f2, $f0
/* BADEEC 802405AC 3C014024 */  lui       $at, 0x4024
/* BADEF0 802405B0 44810800 */  mtc1      $at, $f1
/* BADEF4 802405B4 44800000 */  mtc1      $zero, $f0
/* BADEF8 802405B8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BADEFC 802405BC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BADF00 802405C0 460010A1 */  cvt.d.s   $f2, $f2
/* BADF04 802405C4 46201080 */  add.d     $f2, $f2, $f0
/* BADF08 802405C8 C440002C */  lwc1      $f0, 0x2c($v0)
/* BADF0C 802405CC 46000021 */  cvt.d.s   $f0, $f0
/* BADF10 802405D0 4622003C */  c.lt.d    $f0, $f2
/* BADF14 802405D4 00000000 */  nop
/* BADF18 802405D8 4500002C */  bc1f      .L8024068C
/* BADF1C 802405DC 02A0202D */   daddu    $a0, $s5, $zero
/* BADF20 802405E0 AFA00010 */  sw        $zero, 0x10($sp)
/* BADF24 802405E4 8E46000C */  lw        $a2, 0xc($s2)
/* BADF28 802405E8 8E470010 */  lw        $a3, 0x10($s2)
/* BADF2C 802405EC 0C01242D */  jal       func_800490B4
/* BADF30 802405F0 0220282D */   daddu    $a1, $s1, $zero
/* BADF34 802405F4 10400025 */  beqz      $v0, .L8024068C
/* BADF38 802405F8 0000202D */   daddu    $a0, $zero, $zero
/* BADF3C 802405FC 0200282D */  daddu     $a1, $s0, $zero
/* BADF40 80240600 0000302D */  daddu     $a2, $zero, $zero
/* BADF44 80240604 2412000C */  addiu     $s2, $zero, 0xc
/* BADF48 80240608 860300A8 */  lh        $v1, 0xa8($s0)
/* BADF4C 8024060C 3C013F80 */  lui       $at, 0x3f80
/* BADF50 80240610 44810000 */  mtc1      $at, $f0
/* BADF54 80240614 3C014000 */  lui       $at, 0x4000
/* BADF58 80240618 44811000 */  mtc1      $at, $f2
/* BADF5C 8024061C 3C01C1A0 */  lui       $at, 0xc1a0
/* BADF60 80240620 44812000 */  mtc1      $at, $f4
/* BADF64 80240624 44834000 */  mtc1      $v1, $f8
/* BADF68 80240628 00000000 */  nop
/* BADF6C 8024062C 46804220 */  cvt.s.w   $f8, $f8
/* BADF70 80240630 44074000 */  mfc1      $a3, $f8
/* BADF74 80240634 27A20038 */  addiu     $v0, $sp, 0x38
/* BADF78 80240638 AFB2001C */  sw        $s2, 0x1c($sp)
/* BADF7C 8024063C AFA20020 */  sw        $v0, 0x20($sp)
/* BADF80 80240640 E7A00010 */  swc1      $f0, 0x10($sp)
/* BADF84 80240644 E7A20014 */  swc1      $f2, 0x14($sp)
/* BADF88 80240648 0C01BFA4 */  jal       fx_emote
/* BADF8C 8024064C E7A40018 */   swc1     $f4, 0x18($sp)
/* BADF90 80240650 0200202D */  daddu     $a0, $s0, $zero
/* BADF94 80240654 240502F4 */  addiu     $a1, $zero, 0x2f4
/* BADF98 80240658 C480003C */  lwc1      $f0, 0x3c($a0)
/* BADF9C 8024065C 3C060020 */  lui       $a2, 0x20
/* BADFA0 80240660 0C012530 */  jal       func_800494C0
/* BADFA4 80240664 E4800064 */   swc1     $f0, 0x64($a0)
/* BADFA8 80240668 8E220018 */  lw        $v0, 0x18($s1)
/* BADFAC 8024066C 9442002A */  lhu       $v0, 0x2a($v0)
/* BADFB0 80240670 30420001 */  andi      $v0, $v0, 1
/* BADFB4 80240674 10400003 */  beqz      $v0, .L80240684
/* BADFB8 80240678 2402000A */   addiu    $v0, $zero, 0xa
/* BADFBC 8024067C 08090211 */  j         .L80240844
/* BADFC0 80240680 AE620070 */   sw       $v0, 0x70($s3)
.L80240684:
/* BADFC4 80240684 08090211 */  j         .L80240844
/* BADFC8 80240688 AE720070 */   sw       $s2, 0x70($s3)
.L8024068C:
/* BADFCC 8024068C 8E620074 */  lw        $v0, 0x74($s3)
/* BADFD0 80240690 2442FFFF */  addiu     $v0, $v0, -1
.L80240694:
/* BADFD4 80240694 080901A8 */  j         .L802406A0
/* BADFD8 80240698 AE620074 */   sw       $v0, 0x74($s3)
.L8024069C:
/* BADFDC 8024069C AE220090 */  sw        $v0, 0x90($s1)
.L802406A0:
/* BADFE0 802406A0 8E2300D0 */  lw        $v1, 0xd0($s1)
/* BADFE4 802406A4 C6000040 */  lwc1      $f0, 0x40($s0)
/* BADFE8 802406A8 C4620000 */  lwc1      $f2, ($v1)
/* BADFEC 802406AC 468010A0 */  cvt.s.w   $f2, $f2
/* BADFF0 802406B0 C4640008 */  lwc1      $f4, 8($v1)
/* BADFF4 802406B4 46802120 */  cvt.s.w   $f4, $f4
/* BADFF8 802406B8 E7A00010 */  swc1      $f0, 0x10($sp)
/* BADFFC 802406BC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BAE000 802406C0 44051000 */  mfc1      $a1, $f2
/* BAE004 802406C4 C440000C */  lwc1      $f0, 0xc($v0)
/* BAE008 802406C8 46800020 */  cvt.s.w   $f0, $f0
/* BAE00C 802406CC E7A00014 */  swc1      $f0, 0x14($sp)
/* BAE010 802406D0 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BAE014 802406D4 44062000 */  mfc1      $a2, $f4
/* BAE018 802406D8 C4400010 */  lwc1      $f0, 0x10($v0)
/* BAE01C 802406DC 46800020 */  cvt.s.w   $f0, $f0
/* BAE020 802406E0 E7A00018 */  swc1      $f0, 0x18($sp)
/* BAE024 802406E4 8C640018 */  lw        $a0, 0x18($v1)
/* BAE028 802406E8 0C0123F5 */  jal       is_point_within_region
/* BAE02C 802406EC 8E070038 */   lw       $a3, 0x38($s0)
/* BAE030 802406F0 1040001A */  beqz      $v0, .L8024075C
/* BAE034 802406F4 00000000 */   nop
/* BAE038 802406F8 8E060038 */  lw        $a2, 0x38($s0)
/* BAE03C 802406FC 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BAE040 80240700 8E070040 */  lw        $a3, 0x40($s0)
/* BAE044 80240704 C44C0000 */  lwc1      $f12, ($v0)
/* BAE048 80240708 46806320 */  cvt.s.w   $f12, $f12
/* BAE04C 8024070C C44E0008 */  lwc1      $f14, 8($v0)
/* BAE050 80240710 0C00A7B5 */  jal       dist2D
/* BAE054 80240714 468073A0 */   cvt.s.w  $f14, $f14
/* BAE058 80240718 C6020018 */  lwc1      $f2, 0x18($s0)
/* BAE05C 8024071C 4600103C */  c.lt.s    $f2, $f0
/* BAE060 80240720 00000000 */  nop
/* BAE064 80240724 4500000D */  bc1f      .L8024075C
/* BAE068 80240728 E7A00034 */   swc1     $f0, 0x34($sp)
/* BAE06C 8024072C C60C0038 */  lwc1      $f12, 0x38($s0)
/* BAE070 80240730 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BAE074 80240734 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BAE078 80240738 C4480000 */  lwc1      $f8, ($v0)
/* BAE07C 8024073C 46804220 */  cvt.s.w   $f8, $f8
/* BAE080 80240740 44064000 */  mfc1      $a2, $f8
/* BAE084 80240744 C4480008 */  lwc1      $f8, 8($v0)
/* BAE088 80240748 46804220 */  cvt.s.w   $f8, $f8
/* BAE08C 8024074C 44074000 */  mfc1      $a3, $f8
/* BAE090 80240750 0C00A720 */  jal       atan2
/* BAE094 80240754 24140001 */   addiu    $s4, $zero, 1
/* BAE098 80240758 E600000C */  swc1      $f0, 0xc($s0)
.L8024075C:
/* BAE09C 8024075C 8E2200D0 */  lw        $v0, 0xd0($s1)
/* BAE0A0 80240760 8C43000C */  lw        $v1, 0xc($v0)
/* BAE0A4 80240764 8C420010 */  lw        $v0, 0x10($v0)
/* BAE0A8 80240768 00621825 */  or        $v1, $v1, $v0
/* BAE0AC 8024076C 00741825 */  or        $v1, $v1, $s4
/* BAE0B0 80240770 10600008 */  beqz      $v1, .L80240794
/* BAE0B4 80240774 00000000 */   nop
/* BAE0B8 80240778 8602008C */  lh        $v0, 0x8c($s0)
/* BAE0BC 8024077C 14400031 */  bnez      $v0, .L80240844
/* BAE0C0 80240780 00000000 */   nop
/* BAE0C4 80240784 8E050018 */  lw        $a1, 0x18($s0)
/* BAE0C8 80240788 8E06000C */  lw        $a2, 0xc($s0)
/* BAE0CC 8024078C 0C00EA95 */  jal       npc_move_heading
/* BAE0D0 80240790 0200202D */   daddu    $a0, $s0, $zero
.L80240794:
/* BAE0D4 80240794 C600003C */  lwc1      $f0, 0x3c($s0)
/* BAE0D8 80240798 3C014059 */  lui       $at, 0x4059
/* BAE0DC 8024079C 44811800 */  mtc1      $at, $f3
/* BAE0E0 802407A0 44801000 */  mtc1      $zero, $f2
/* BAE0E4 802407A4 46000021 */  cvt.d.s   $f0, $f0
/* BAE0E8 802407A8 46220002 */  mul.d     $f0, $f0, $f2
/* BAE0EC 802407AC 00000000 */  nop
/* BAE0F0 802407B0 4620020D */  trunc.w.d $f8, $f0
/* BAE0F4 802407B4 E628007C */  swc1      $f8, 0x7c($s1)
/* BAE0F8 802407B8 8E420004 */  lw        $v0, 4($s2)
/* BAE0FC 802407BC 18400021 */  blez      $v0, .L80240844
/* BAE100 802407C0 00000000 */   nop
/* BAE104 802407C4 8602008E */  lh        $v0, 0x8e($s0)
/* BAE108 802407C8 9603008E */  lhu       $v1, 0x8e($s0)
/* BAE10C 802407CC 18400005 */  blez      $v0, .L802407E4
/* BAE110 802407D0 2462FFFF */   addiu    $v0, $v1, -1
/* BAE114 802407D4 A602008E */  sh        $v0, 0x8e($s0)
/* BAE118 802407D8 00021400 */  sll       $v0, $v0, 0x10
/* BAE11C 802407DC 1C400019 */  bgtz      $v0, .L80240844
/* BAE120 802407E0 00000000 */   nop
.L802407E4:
/* BAE124 802407E4 240403E8 */  addiu     $a0, $zero, 0x3e8
/* BAE128 802407E8 24020002 */  addiu     $v0, $zero, 2
/* BAE12C 802407EC 0C00A67F */  jal       rand_int
/* BAE130 802407F0 AE620070 */   sw       $v0, 0x70($s3)
/* BAE134 802407F4 3C035555 */  lui       $v1, 0x5555
/* BAE138 802407F8 34635556 */  ori       $v1, $v1, 0x5556
/* BAE13C 802407FC 00430018 */  mult      $v0, $v1
/* BAE140 80240800 000227C3 */  sra       $a0, $v0, 0x1f
/* BAE144 80240804 00004010 */  mfhi      $t0
/* BAE148 80240808 01042023 */  subu      $a0, $t0, $a0
/* BAE14C 8024080C 00041840 */  sll       $v1, $a0, 1
/* BAE150 80240810 00641821 */  addu      $v1, $v1, $a0
/* BAE154 80240814 00431023 */  subu      $v0, $v0, $v1
/* BAE158 80240818 24430002 */  addiu     $v1, $v0, 2
/* BAE15C 8024081C AE630074 */  sw        $v1, 0x74($s3)
/* BAE160 80240820 8E42002C */  lw        $v0, 0x2c($s2)
/* BAE164 80240824 58400007 */  blezl     $v0, .L80240844
/* BAE168 80240828 AE600070 */   sw       $zero, 0x70($s3)
/* BAE16C 8024082C 8E420008 */  lw        $v0, 8($s2)
/* BAE170 80240830 18400003 */  blez      $v0, .L80240840
/* BAE174 80240834 28620003 */   slti     $v0, $v1, 3
/* BAE178 80240838 10400002 */  beqz      $v0, .L80240844
/* BAE17C 8024083C 00000000 */   nop
.L80240840:
/* BAE180 80240840 AE600070 */  sw        $zero, 0x70($s3)
.L80240844:
/* BAE184 80240844 8FBF0058 */  lw        $ra, 0x58($sp)
/* BAE188 80240848 8FB50054 */  lw        $s5, 0x54($sp)
/* BAE18C 8024084C 8FB40050 */  lw        $s4, 0x50($sp)
/* BAE190 80240850 8FB3004C */  lw        $s3, 0x4c($sp)
/* BAE194 80240854 8FB20048 */  lw        $s2, 0x48($sp)
/* BAE198 80240858 8FB10044 */  lw        $s1, 0x44($sp)
/* BAE19C 8024085C 8FB00040 */  lw        $s0, 0x40($sp)
/* BAE1A0 80240860 D7BA0078 */  ldc1      $f26, 0x78($sp)
/* BAE1A4 80240864 D7B80070 */  ldc1      $f24, 0x70($sp)
/* BAE1A8 80240868 D7B60068 */  ldc1      $f22, 0x68($sp)
/* BAE1AC 8024086C D7B40060 */  ldc1      $f20, 0x60($sp)
/* BAE1B0 80240870 03E00008 */  jr        $ra
/* BAE1B4 80240874 27BD0080 */   addiu    $sp, $sp, 0x80
