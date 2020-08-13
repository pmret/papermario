.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8025C918
/* 18B1F8 8025C918 27BDFF58 */  addiu $sp, $sp, -0xa8
/* 18B1FC 8025C91C AFB70084 */  sw    $s7, 0x84($sp)
/* 18B200 8025C920 00A0B82D */  daddu $s7, $a1, $zero
/* 18B204 8025C924 AFBF008C */  sw    $ra, 0x8c($sp)
/* 18B208 8025C928 AFBE0088 */  sw    $fp, 0x88($sp)
/* 18B20C 8025C92C AFB60080 */  sw    $s6, 0x80($sp)
/* 18B210 8025C930 AFB5007C */  sw    $s5, 0x7c($sp)
/* 18B214 8025C934 AFB40078 */  sw    $s4, 0x78($sp)
/* 18B218 8025C938 AFB30074 */  sw    $s3, 0x74($sp)
/* 18B21C 8025C93C AFB20070 */  sw    $s2, 0x70($sp)
/* 18B220 8025C940 AFB1006C */  sw    $s1, 0x6c($sp)
/* 18B224 8025C944 AFB00068 */  sw    $s0, 0x68($sp)
/* 18B228 8025C948 F7B800A0 */  sdc1  $f24, 0xa0($sp)
/* 18B22C 8025C94C F7B60098 */  sdc1  $f22, 0x98($sp)
/* 18B230 8025C950 F7B40090 */  sdc1  $f20, 0x90($sp)
/* 18B234 8025C954 AFA700B4 */  sw    $a3, 0xb4($sp)
/* 18B238 8025C958 8EF200C0 */  lw    $s2, 0xc0($s7)
/* 18B23C 8025C95C 82420751 */  lb    $v0, 0x751($s2)
/* 18B240 8025C960 1040001B */  beqz  $v0, .L8025C9D0
/* 18B244 8025C964 0080F02D */   daddu $fp, $a0, $zero
/* 18B248 8025C968 2402FFFE */  addiu $v0, $zero, -2
/* 18B24C 8025C96C A2420752 */  sb    $v0, 0x752($s2)
/* 18B250 8025C970 A640075A */  sh    $zero, 0x75a($s2)
/* 18B254 8025C974 A2400751 */  sb    $zero, 0x751($s2)
/* 18B258 8025C978 17C0000C */  bnez  $fp, .L8025C9AC
/* 18B25C 8025C97C A6400758 */   sh    $zero, 0x758($s2)
/* 18B260 8025C980 0000202D */  daddu $a0, $zero, $zero
/* 18B264 8025C984 24050011 */  addiu $a1, $zero, 0x11
/* 18B268 8025C988 24060014 */  addiu $a2, $zero, 0x14
/* 18B26C 8025C98C 0080382D */  daddu $a3, $a0, $zero
/* 18B270 8025C990 240200FF */  addiu $v0, $zero, 0xff
/* 18B274 8025C994 AFA00010 */  sw    $zero, 0x10($sp)
/* 18B278 8025C998 AFA20014 */  sw    $v0, 0x14($sp)
/* 18B27C 8025C99C 0C0B77FE */  jal   func_802DDFF8
/* 18B280 8025C9A0 AFA00018 */   sw    $zero, 0x18($sp)
/* 18B284 8025C9A4 08097274 */  j     .L8025C9D0
/* 18B288 8025C9A8 00000000 */   nop   

.L8025C9AC:
/* 18B28C 8025C9AC 24050011 */  addiu $a1, $zero, 0x11
/* 18B290 8025C9B0 24060014 */  addiu $a2, $zero, 0x14
/* 18B294 8025C9B4 240200FF */  addiu $v0, $zero, 0xff
/* 18B298 8025C9B8 AFA00010 */  sw    $zero, 0x10($sp)
/* 18B29C 8025C9BC AFA20014 */  sw    $v0, 0x14($sp)
/* 18B2A0 8025C9C0 AFA00018 */  sw    $zero, 0x18($sp)
/* 18B2A4 8025C9C4 8EE40084 */  lw    $a0, 0x84($s7)
/* 18B2A8 8025C9C8 0C0B7A25 */  jal   func_802DE894
/* 18B2AC 8025C9CC 0000382D */   daddu $a3, $zero, $zero
.L8025C9D0:
.L8025C9D0:
/* 18B2B0 8025C9D0 9642075C */  lhu   $v0, 0x75c($s2)
/* 18B2B4 8025C9D4 24420007 */  addiu $v0, $v0, 7
/* 18B2B8 8025C9D8 00021C00 */  sll   $v1, $v0, 0x10
/* 18B2BC 8025C9DC 00032403 */  sra   $a0, $v1, 0x10
/* 18B2C0 8025C9E0 A642075C */  sh    $v0, 0x75c($s2)
/* 18B2C4 8025C9E4 28820168 */  slti  $v0, $a0, 0x168
/* 18B2C8 8025C9E8 14400010 */  bnez  $v0, .L8025CA2C
/* 18B2CC 8025C9EC 0000802D */   daddu $s0, $zero, $zero
/* 18B2D0 8025C9F0 3C02B60B */  lui   $v0, 0xb60b
/* 18B2D4 8025C9F4 344260B7 */  ori   $v0, $v0, 0x60b7
/* 18B2D8 8025C9F8 00820018 */  mult  $a0, $v0
/* 18B2DC 8025C9FC 00031FC3 */  sra   $v1, $v1, 0x1f
/* 18B2E0 8025CA00 00004010 */  mfhi  $t0
/* 18B2E4 8025CA04 01041021 */  addu  $v0, $t0, $a0
/* 18B2E8 8025CA08 00021203 */  sra   $v0, $v0, 8
/* 18B2EC 8025CA0C 00431023 */  subu  $v0, $v0, $v1
/* 18B2F0 8025CA10 00021840 */  sll   $v1, $v0, 1
/* 18B2F4 8025CA14 00621821 */  addu  $v1, $v1, $v0
/* 18B2F8 8025CA18 00031100 */  sll   $v0, $v1, 4
/* 18B2FC 8025CA1C 00431023 */  subu  $v0, $v0, $v1
/* 18B300 8025CA20 000210C0 */  sll   $v0, $v0, 3
/* 18B304 8025CA24 00821023 */  subu  $v0, $a0, $v0
/* 18B308 8025CA28 A642075C */  sh    $v0, 0x75c($s2)
.L8025CA2C:
/* 18B30C 8025CA2C 3C138000 */  lui   $s3, 0x8000
/* 18B310 8025CA30 0200882D */  daddu $s1, $s0, $zero
/* 18B314 8025CA34 3C013FF0 */  lui   $at, 0x3ff0
/* 18B318 8025CA38 4481C800 */  mtc1  $at, $f25
/* 18B31C 8025CA3C 4480C000 */  mtc1  $zero, $f24
/* 18B320 8025CA40 3C01405C */  lui   $at, 0x405c
/* 18B324 8025CA44 4481B800 */  mtc1  $at, $f23
/* 18B328 8025CA48 4480B000 */  mtc1  $zero, $f22
/* 18B32C 8025CA4C 3C0141E0 */  lui   $at, 0x41e0
/* 18B330 8025CA50 4481A800 */  mtc1  $at, $f21
/* 18B334 8025CA54 4480A000 */  mtc1  $zero, $f20
.L8025CA58:
/* 18B338 8025CA58 9644075C */  lhu   $a0, 0x75c($s2)
/* 18B33C 8025CA5C 00912021 */  addu  $a0, $a0, $s1
/* 18B340 8025CA60 00042400 */  sll   $a0, $a0, 0x10
/* 18B344 8025CA64 0C00A4F5 */  jal   cosine
/* 18B348 8025CA68 00042403 */   sra   $a0, $a0, 0x10
/* 18B34C 8025CA6C 46000021 */  cvt.d.s $f0, $f0
/* 18B350 8025CA70 46380000 */  add.d $f0, $f0, $f24
/* 18B354 8025CA74 46360002 */  mul.d $f0, $f0, $f22
/* 18B358 8025CA78 00000000 */  nop   
/* 18B35C 8025CA7C 27A20020 */  addiu $v0, $sp, 0x20
/* 18B360 8025CA80 4620A03E */  c.le.d $f20, $f0
/* 18B364 8025CA84 00000000 */  nop   
/* 18B368 8025CA88 45010005 */  bc1t  .L8025CAA0
/* 18B36C 8025CA8C 00501021 */   addu  $v0, $v0, $s0
/* 18B370 8025CA90 4620008D */  trunc.w.d $f2, $f0
/* 18B374 8025CA94 44031000 */  mfc1  $v1, $f2
/* 18B378 8025CA98 080972AE */  j     .L8025CAB8
/* 18B37C 8025CA9C A0430000 */   sb    $v1, ($v0)

.L8025CAA0:
/* 18B380 8025CAA0 46340001 */  sub.d $f0, $f0, $f20
/* 18B384 8025CAA4 4620008D */  trunc.w.d $f2, $f0
/* 18B388 8025CAA8 44031000 */  mfc1  $v1, $f2
/* 18B38C 8025CAAC 00000000 */  nop   
/* 18B390 8025CAB0 00731825 */  or    $v1, $v1, $s3
/* 18B394 8025CAB4 A0430000 */  sb    $v1, ($v0)
.L8025CAB8:
/* 18B398 8025CAB8 9644075C */  lhu   $a0, 0x75c($s2)
/* 18B39C 8025CABC 00912021 */  addu  $a0, $a0, $s1
/* 18B3A0 8025CAC0 2484002D */  addiu $a0, $a0, 0x2d
/* 18B3A4 8025CAC4 00042400 */  sll   $a0, $a0, 0x10
/* 18B3A8 8025CAC8 0C00A4F5 */  jal   cosine
/* 18B3AC 8025CACC 00042403 */   sra   $a0, $a0, 0x10
/* 18B3B0 8025CAD0 46000021 */  cvt.d.s $f0, $f0
/* 18B3B4 8025CAD4 46380000 */  add.d $f0, $f0, $f24
/* 18B3B8 8025CAD8 46360002 */  mul.d $f0, $f0, $f22
/* 18B3BC 8025CADC 00000000 */  nop   
/* 18B3C0 8025CAE0 27A20038 */  addiu $v0, $sp, 0x38
/* 18B3C4 8025CAE4 4620A03E */  c.le.d $f20, $f0
/* 18B3C8 8025CAE8 00000000 */  nop   
/* 18B3CC 8025CAEC 45010005 */  bc1t  .L8025CB04
/* 18B3D0 8025CAF0 00501021 */   addu  $v0, $v0, $s0
/* 18B3D4 8025CAF4 4620008D */  trunc.w.d $f2, $f0
/* 18B3D8 8025CAF8 44031000 */  mfc1  $v1, $f2
/* 18B3DC 8025CAFC 080972C7 */  j     .L8025CB1C
/* 18B3E0 8025CB00 A0430000 */   sb    $v1, ($v0)

.L8025CB04:
/* 18B3E4 8025CB04 46340001 */  sub.d $f0, $f0, $f20
/* 18B3E8 8025CB08 4620008D */  trunc.w.d $f2, $f0
/* 18B3EC 8025CB0C 44031000 */  mfc1  $v1, $f2
/* 18B3F0 8025CB10 00000000 */  nop   
/* 18B3F4 8025CB14 00731825 */  or    $v1, $v1, $s3
/* 18B3F8 8025CB18 A0430000 */  sb    $v1, ($v0)
.L8025CB1C:
/* 18B3FC 8025CB1C 9644075C */  lhu   $a0, 0x75c($s2)
/* 18B400 8025CB20 00912021 */  addu  $a0, $a0, $s1
/* 18B404 8025CB24 2484005A */  addiu $a0, $a0, 0x5a
/* 18B408 8025CB28 00042400 */  sll   $a0, $a0, 0x10
/* 18B40C 8025CB2C 0C00A4F5 */  jal   cosine
/* 18B410 8025CB30 00042403 */   sra   $a0, $a0, 0x10
/* 18B414 8025CB34 46000021 */  cvt.d.s $f0, $f0
/* 18B418 8025CB38 46380000 */  add.d $f0, $f0, $f24
/* 18B41C 8025CB3C 46360002 */  mul.d $f0, $f0, $f22
/* 18B420 8025CB40 00000000 */  nop   
/* 18B424 8025CB44 27A20050 */  addiu $v0, $sp, 0x50
/* 18B428 8025CB48 4620A03E */  c.le.d $f20, $f0
/* 18B42C 8025CB4C 00000000 */  nop   
/* 18B430 8025CB50 45010005 */  bc1t  .L8025CB68
/* 18B434 8025CB54 00501021 */   addu  $v0, $v0, $s0
/* 18B438 8025CB58 4620008D */  trunc.w.d $f2, $f0
/* 18B43C 8025CB5C 44031000 */  mfc1  $v1, $f2
/* 18B440 8025CB60 080972E0 */  j     .L8025CB80
/* 18B444 8025CB64 A0430000 */   sb    $v1, ($v0)

.L8025CB68:
/* 18B448 8025CB68 46340001 */  sub.d $f0, $f0, $f20
/* 18B44C 8025CB6C 4620008D */  trunc.w.d $f2, $f0
/* 18B450 8025CB70 44031000 */  mfc1  $v1, $f2
/* 18B454 8025CB74 00000000 */  nop   
/* 18B458 8025CB78 00731825 */  or    $v1, $v1, $s3
/* 18B45C 8025CB7C A0430000 */  sb    $v1, ($v0)
.L8025CB80:
/* 18B460 8025CB80 26100001 */  addiu $s0, $s0, 1
/* 18B464 8025CB84 2A020014 */  slti  $v0, $s0, 0x14
/* 18B468 8025CB88 1440FFB3 */  bnez  $v0, .L8025CA58
/* 18B46C 8025CB8C 26310019 */   addiu $s1, $s1, 0x19
/* 18B470 8025CB90 86E30098 */  lh    $v1, 0x98($s7)
/* 18B474 8025CB94 241100FF */  addiu $s1, $zero, 0xff
/* 18B478 8025CB98 0071102A */  slt   $v0, $v1, $s1
/* 18B47C 8025CB9C 54400001 */  bnezl $v0, .L8025CBA4
/* 18B480 8025CBA0 0060882D */   daddu $s1, $v1, $zero
.L8025CBA4:
/* 18B484 8025CBA4 8EE20000 */  lw    $v0, ($s7)
/* 18B488 8025CBA8 30420100 */  andi  $v0, $v0, 0x100
/* 18B48C 8025CBAC 1040000B */  beqz  $v0, .L8025CBDC
/* 18B490 8025CBB0 3C038080 */   lui   $v1, 0x8080
/* 18B494 8025CBB4 34638081 */  ori   $v1, $v1, 0x8081
/* 18B498 8025CBB8 00111100 */  sll   $v0, $s1, 4
/* 18B49C 8025CBBC 00511023 */  subu  $v0, $v0, $s1
/* 18B4A0 8025CBC0 000210C0 */  sll   $v0, $v0, 3
/* 18B4A4 8025CBC4 00430018 */  mult  $v0, $v1
/* 18B4A8 8025CBC8 00004010 */  mfhi  $t0
/* 18B4AC 8025CBCC 01021821 */  addu  $v1, $t0, $v0
/* 18B4B0 8025CBD0 000319C3 */  sra   $v1, $v1, 7
/* 18B4B4 8025CBD4 000217C3 */  sra   $v0, $v0, 0x1f
/* 18B4B8 8025CBD8 00628823 */  subu  $s1, $v1, $v0
.L8025CBDC:
/* 18B4BC 8025CBDC 0000802D */  daddu $s0, $zero, $zero
/* 18B4C0 8025CBE0 27B60020 */  addiu $s6, $sp, 0x20
/* 18B4C4 8025CBE4 27B50038 */  addiu $s5, $sp, 0x38
/* 18B4C8 8025CBE8 27B40050 */  addiu $s4, $sp, 0x50
/* 18B4CC 8025CBEC 241300FF */  addiu $s3, $zero, 0xff
/* 18B4D0 8025CBF0 02D01021 */  addu  $v0, $s6, $s0
.L8025CBF4:
/* 18B4D4 8025CBF4 02B02021 */  addu  $a0, $s5, $s0
/* 18B4D8 8025CBF8 90430000 */  lbu   $v1, ($v0)
/* 18B4DC 8025CBFC 02901021 */  addu  $v0, $s4, $s0
/* 18B4E0 8025CC00 90840000 */  lbu   $a0, ($a0)
/* 18B4E4 8025CC04 90420000 */  lbu   $v0, ($v0)
/* 18B4E8 8025CC08 00031E00 */  sll   $v1, $v1, 0x18
/* 18B4EC 8025CC0C 00042400 */  sll   $a0, $a0, 0x10
/* 18B4F0 8025CC10 00641825 */  or    $v1, $v1, $a0
/* 18B4F4 8025CC14 00021200 */  sll   $v0, $v0, 8
/* 18B4F8 8025CC18 00621825 */  or    $v1, $v1, $v0
/* 18B4FC 8025CC1C 17C0000A */  bnez  $fp, .L8025CC48
/* 18B500 8025CC20 00713825 */   or    $a3, $v1, $s1
/* 18B504 8025CC24 0000202D */  daddu $a0, $zero, $zero
/* 18B508 8025CC28 2405000C */  addiu $a1, $zero, 0xc
/* 18B50C 8025CC2C 0200302D */  daddu $a2, $s0, $zero
/* 18B510 8025CC30 AFA00010 */  sw    $zero, 0x10($sp)
/* 18B514 8025CC34 AFB30014 */  sw    $s3, 0x14($sp)
/* 18B518 8025CC38 0C0B77FE */  jal   func_802DDFF8
/* 18B51C 8025CC3C AFA00018 */   sw    $zero, 0x18($sp)
/* 18B520 8025CC40 0809731A */  j     .L8025CC68
/* 18B524 8025CC44 26100001 */   addiu $s0, $s0, 1

.L8025CC48:
/* 18B528 8025CC48 2405000C */  addiu $a1, $zero, 0xc
/* 18B52C 8025CC4C AFA00010 */  sw    $zero, 0x10($sp)
/* 18B530 8025CC50 AFB30014 */  sw    $s3, 0x14($sp)
/* 18B534 8025CC54 AFA00018 */  sw    $zero, 0x18($sp)
/* 18B538 8025CC58 8EE40084 */  lw    $a0, 0x84($s7)
/* 18B53C 8025CC5C 0C0B7A25 */  jal   func_802DE894
/* 18B540 8025CC60 0200302D */   daddu $a2, $s0, $zero
/* 18B544 8025CC64 26100001 */  addiu $s0, $s0, 1
.L8025CC68:
/* 18B548 8025CC68 2A020014 */  slti  $v0, $s0, 0x14
/* 18B54C 8025CC6C 1440FFE1 */  bnez  $v0, .L8025CBF4
/* 18B550 8025CC70 02D01021 */   addu  $v0, $s6, $s0
/* 18B554 8025CC74 8FA800B4 */  lw    $t0, 0xb4($sp)
/* 18B558 8025CC78 15000004 */  bnez  $t0, .L8025CC8C
/* 18B55C 8025CC7C 00000000 */   nop   
/* 18B560 8025CC80 9642075A */  lhu   $v0, 0x75a($s2)
/* 18B564 8025CC84 2442FFFF */  addiu $v0, $v0, -1
/* 18B568 8025CC88 A642075A */  sh    $v0, 0x75a($s2)
.L8025CC8C:
/* 18B56C 8025CC8C 8FBF008C */  lw    $ra, 0x8c($sp)
/* 18B570 8025CC90 8FBE0088 */  lw    $fp, 0x88($sp)
/* 18B574 8025CC94 8FB70084 */  lw    $s7, 0x84($sp)
/* 18B578 8025CC98 8FB60080 */  lw    $s6, 0x80($sp)
/* 18B57C 8025CC9C 8FB5007C */  lw    $s5, 0x7c($sp)
/* 18B580 8025CCA0 8FB40078 */  lw    $s4, 0x78($sp)
/* 18B584 8025CCA4 8FB30074 */  lw    $s3, 0x74($sp)
/* 18B588 8025CCA8 8FB20070 */  lw    $s2, 0x70($sp)
/* 18B58C 8025CCAC 8FB1006C */  lw    $s1, 0x6c($sp)
/* 18B590 8025CCB0 8FB00068 */  lw    $s0, 0x68($sp)
/* 18B594 8025CCB4 D7B800A0 */  ldc1  $f24, 0xa0($sp)
/* 18B598 8025CCB8 D7B60098 */  ldc1  $f22, 0x98($sp)
/* 18B59C 8025CCBC D7B40090 */  ldc1  $f20, 0x90($sp)
/* 18B5A0 8025CCC0 03E00008 */  jr    $ra
/* 18B5A4 8025CCC4 27BD00A8 */   addiu $sp, $sp, 0xa8

