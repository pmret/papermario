.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003C970
/* 17D70 8003C970 27BDFF60 */  addiu     $sp, $sp, -0xa0
/* 17D74 8003C974 AFB60080 */  sw        $s6, 0x80($sp)
/* 17D78 8003C978 0080B02D */  daddu     $s6, $a0, $zero
/* 17D7C 8003C97C AFB1006C */  sw        $s1, 0x6c($sp)
/* 17D80 8003C980 00A0882D */  daddu     $s1, $a1, $zero
/* 17D84 8003C984 AFB00068 */  sw        $s0, 0x68($sp)
/* 17D88 8003C988 02D18021 */  addu      $s0, $s6, $s1
/* 17D8C 8003C98C AFBF0084 */  sw        $ra, 0x84($sp)
/* 17D90 8003C990 AFB5007C */  sw        $s5, 0x7c($sp)
/* 17D94 8003C994 AFB40078 */  sw        $s4, 0x78($sp)
/* 17D98 8003C998 AFB30074 */  sw        $s3, 0x74($sp)
/* 17D9C 8003C99C AFB20070 */  sw        $s2, 0x70($sp)
/* 17DA0 8003C9A0 F7B80098 */  sdc1      $f24, 0x98($sp)
/* 17DA4 8003C9A4 F7B60090 */  sdc1      $f22, 0x90($sp)
/* 17DA8 8003C9A8 F7B40088 */  sdc1      $f20, 0x88($sp)
/* 17DAC 8003C9AC 82020330 */  lb        $v0, 0x330($s0)
/* 17DB0 8003C9B0 1440000B */  bnez      $v0, .L8003C9E0
/* 17DB4 8003C9B4 24050011 */   addiu    $a1, $zero, 0x11
/* 17DB8 8003C9B8 24060014 */  addiu     $a2, $zero, 0x14
/* 17DBC 8003C9BC 240200FF */  addiu     $v0, $zero, 0xff
/* 17DC0 8003C9C0 AFA00010 */  sw        $zero, 0x10($sp)
/* 17DC4 8003C9C4 AFA20014 */  sw        $v0, 0x14($sp)
/* 17DC8 8003C9C8 AFA00018 */  sw        $zero, 0x18($sp)
/* 17DCC 8003C9CC 8EC40024 */  lw        $a0, 0x24($s6)
/* 17DD0 8003C9D0 0C0448F9 */  jal       func_801123E4
/* 17DD4 8003C9D4 0000382D */   daddu    $a3, $zero, $zero
/* 17DD8 8003C9D8 24020001 */  addiu     $v0, $zero, 1
/* 17DDC 8003C9DC A2020330 */  sb        $v0, 0x330($s0)
.L8003C9E0:
/* 17DE0 8003C9E0 82030330 */  lb        $v1, 0x330($s0)
/* 17DE4 8003C9E4 24020001 */  addiu     $v0, $zero, 1
/* 17DE8 8003C9E8 14620090 */  bne       $v1, $v0, .L8003CC2C
/* 17DEC 8003C9EC 00511004 */   sllv     $v0, $s1, $v0
/* 17DF0 8003C9F0 02C22821 */  addu      $a1, $s6, $v0
/* 17DF4 8003C9F4 94A20332 */  lhu       $v0, 0x332($a1)
/* 17DF8 8003C9F8 24420007 */  addiu     $v0, $v0, 7
/* 17DFC 8003C9FC 00021C00 */  sll       $v1, $v0, 0x10
/* 17E00 8003CA00 00032403 */  sra       $a0, $v1, 0x10
/* 17E04 8003CA04 A4A20332 */  sh        $v0, 0x332($a1)
/* 17E08 8003CA08 28820168 */  slti      $v0, $a0, 0x168
/* 17E0C 8003CA0C 14400010 */  bnez      $v0, .L8003CA50
/* 17E10 8003CA10 0000802D */   daddu    $s0, $zero, $zero
/* 17E14 8003CA14 3C02B60B */  lui       $v0, 0xb60b
/* 17E18 8003CA18 344260B7 */  ori       $v0, $v0, 0x60b7
/* 17E1C 8003CA1C 00820018 */  mult      $a0, $v0
/* 17E20 8003CA20 00031FC3 */  sra       $v1, $v1, 0x1f
/* 17E24 8003CA24 00004010 */  mfhi      $t0
/* 17E28 8003CA28 01041021 */  addu      $v0, $t0, $a0
/* 17E2C 8003CA2C 00021203 */  sra       $v0, $v0, 8
/* 17E30 8003CA30 00431023 */  subu      $v0, $v0, $v1
/* 17E34 8003CA34 00021840 */  sll       $v1, $v0, 1
/* 17E38 8003CA38 00621821 */  addu      $v1, $v1, $v0
/* 17E3C 8003CA3C 00031100 */  sll       $v0, $v1, 4
/* 17E40 8003CA40 00431023 */  subu      $v0, $v0, $v1
/* 17E44 8003CA44 000210C0 */  sll       $v0, $v0, 3
/* 17E48 8003CA48 00821023 */  subu      $v0, $a0, $v0
/* 17E4C 8003CA4C A4A20332 */  sh        $v0, 0x332($a1)
.L8003CA50:
/* 17E50 8003CA50 00A0902D */  daddu     $s2, $a1, $zero
/* 17E54 8003CA54 3C138000 */  lui       $s3, 0x8000
/* 17E58 8003CA58 0200882D */  daddu     $s1, $s0, $zero
/* 17E5C 8003CA5C 3C013FF0 */  lui       $at, 0x3ff0
/* 17E60 8003CA60 4481C800 */  mtc1      $at, $f25
/* 17E64 8003CA64 4480C000 */  mtc1      $zero, $f24
/* 17E68 8003CA68 3C014054 */  lui       $at, 0x4054
/* 17E6C 8003CA6C 4481B800 */  mtc1      $at, $f23
/* 17E70 8003CA70 4480B000 */  mtc1      $zero, $f22
/* 17E74 8003CA74 3C0141E0 */  lui       $at, 0x41e0
/* 17E78 8003CA78 4481A800 */  mtc1      $at, $f21
/* 17E7C 8003CA7C 4480A000 */  mtc1      $zero, $f20
.L8003CA80:
/* 17E80 8003CA80 96440332 */  lhu       $a0, 0x332($s2)
/* 17E84 8003CA84 00912021 */  addu      $a0, $a0, $s1
/* 17E88 8003CA88 00042400 */  sll       $a0, $a0, 0x10
/* 17E8C 8003CA8C 0C00A4E5 */  jal       func_80029394
/* 17E90 8003CA90 00042403 */   sra      $a0, $a0, 0x10
/* 17E94 8003CA94 46000021 */  cvt.d.s   $f0, $f0
/* 17E98 8003CA98 46380000 */  add.d     $f0, $f0, $f24
/* 17E9C 8003CA9C 46360002 */  mul.d     $f0, $f0, $f22
/* 17EA0 8003CAA0 00000000 */  nop
/* 17EA4 8003CAA4 27A20020 */  addiu     $v0, $sp, 0x20
/* 17EA8 8003CAA8 4620A03E */  c.le.d    $f20, $f0
/* 17EAC 8003CAAC 00000000 */  nop
/* 17EB0 8003CAB0 45010005 */  bc1t      .L8003CAC8
/* 17EB4 8003CAB4 00501021 */   addu     $v0, $v0, $s0
/* 17EB8 8003CAB8 4620008D */  trunc.w.d $f2, $f0
/* 17EBC 8003CABC 44031000 */  mfc1      $v1, $f2
/* 17EC0 8003CAC0 0800F2B8 */  j         .L8003CAE0
/* 17EC4 8003CAC4 A0430000 */   sb       $v1, ($v0)
.L8003CAC8:
/* 17EC8 8003CAC8 46340001 */  sub.d     $f0, $f0, $f20
/* 17ECC 8003CACC 4620008D */  trunc.w.d $f2, $f0
/* 17ED0 8003CAD0 44031000 */  mfc1      $v1, $f2
/* 17ED4 8003CAD4 00000000 */  nop
/* 17ED8 8003CAD8 00731825 */  or        $v1, $v1, $s3
/* 17EDC 8003CADC A0430000 */  sb        $v1, ($v0)
.L8003CAE0:
/* 17EE0 8003CAE0 96440332 */  lhu       $a0, 0x332($s2)
/* 17EE4 8003CAE4 00912021 */  addu      $a0, $a0, $s1
/* 17EE8 8003CAE8 2484002D */  addiu     $a0, $a0, 0x2d
/* 17EEC 8003CAEC 00042400 */  sll       $a0, $a0, 0x10
/* 17EF0 8003CAF0 0C00A4E5 */  jal       func_80029394
/* 17EF4 8003CAF4 00042403 */   sra      $a0, $a0, 0x10
/* 17EF8 8003CAF8 46000021 */  cvt.d.s   $f0, $f0
/* 17EFC 8003CAFC 46380000 */  add.d     $f0, $f0, $f24
/* 17F00 8003CB00 46360002 */  mul.d     $f0, $f0, $f22
/* 17F04 8003CB04 00000000 */  nop
/* 17F08 8003CB08 27A20038 */  addiu     $v0, $sp, 0x38
/* 17F0C 8003CB0C 4620A03E */  c.le.d    $f20, $f0
/* 17F10 8003CB10 00000000 */  nop
/* 17F14 8003CB14 45010005 */  bc1t      .L8003CB2C
/* 17F18 8003CB18 00501021 */   addu     $v0, $v0, $s0
/* 17F1C 8003CB1C 4620008D */  trunc.w.d $f2, $f0
/* 17F20 8003CB20 44031000 */  mfc1      $v1, $f2
/* 17F24 8003CB24 0800F2D1 */  j         .L8003CB44
/* 17F28 8003CB28 A0430000 */   sb       $v1, ($v0)
.L8003CB2C:
/* 17F2C 8003CB2C 46340001 */  sub.d     $f0, $f0, $f20
/* 17F30 8003CB30 4620008D */  trunc.w.d $f2, $f0
/* 17F34 8003CB34 44031000 */  mfc1      $v1, $f2
/* 17F38 8003CB38 00000000 */  nop
/* 17F3C 8003CB3C 00731825 */  or        $v1, $v1, $s3
/* 17F40 8003CB40 A0430000 */  sb        $v1, ($v0)
.L8003CB44:
/* 17F44 8003CB44 96440332 */  lhu       $a0, 0x332($s2)
/* 17F48 8003CB48 00912021 */  addu      $a0, $a0, $s1
/* 17F4C 8003CB4C 2484005A */  addiu     $a0, $a0, 0x5a
/* 17F50 8003CB50 00042400 */  sll       $a0, $a0, 0x10
/* 17F54 8003CB54 0C00A4E5 */  jal       func_80029394
/* 17F58 8003CB58 00042403 */   sra      $a0, $a0, 0x10
/* 17F5C 8003CB5C 46000021 */  cvt.d.s   $f0, $f0
/* 17F60 8003CB60 46380000 */  add.d     $f0, $f0, $f24
/* 17F64 8003CB64 46360002 */  mul.d     $f0, $f0, $f22
/* 17F68 8003CB68 00000000 */  nop
/* 17F6C 8003CB6C 27A20050 */  addiu     $v0, $sp, 0x50
/* 17F70 8003CB70 4620A03E */  c.le.d    $f20, $f0
/* 17F74 8003CB74 00000000 */  nop
/* 17F78 8003CB78 45010005 */  bc1t      .L8003CB90
/* 17F7C 8003CB7C 00501021 */   addu     $v0, $v0, $s0
/* 17F80 8003CB80 4620008D */  trunc.w.d $f2, $f0
/* 17F84 8003CB84 44031000 */  mfc1      $v1, $f2
/* 17F88 8003CB88 0800F2EA */  j         .L8003CBA8
/* 17F8C 8003CB8C A0430000 */   sb       $v1, ($v0)
.L8003CB90:
/* 17F90 8003CB90 46340001 */  sub.d     $f0, $f0, $f20
/* 17F94 8003CB94 4620008D */  trunc.w.d $f2, $f0
/* 17F98 8003CB98 44031000 */  mfc1      $v1, $f2
/* 17F9C 8003CB9C 00000000 */  nop
/* 17FA0 8003CBA0 00731825 */  or        $v1, $v1, $s3
/* 17FA4 8003CBA4 A0430000 */  sb        $v1, ($v0)
.L8003CBA8:
/* 17FA8 8003CBA8 26100001 */  addiu     $s0, $s0, 1
/* 17FAC 8003CBAC 2A020014 */  slti      $v0, $s0, 0x14
/* 17FB0 8003CBB0 1440FFB3 */  bnez      $v0, .L8003CA80
/* 17FB4 8003CBB4 26310019 */   addiu    $s1, $s1, 0x19
/* 17FB8 8003CBB8 241500FF */  addiu     $s5, $zero, 0xff
/* 17FBC 8003CBBC 0000802D */  daddu     $s0, $zero, $zero
/* 17FC0 8003CBC0 27B30020 */  addiu     $s3, $sp, 0x20
/* 17FC4 8003CBC4 27B20038 */  addiu     $s2, $sp, 0x38
/* 17FC8 8003CBC8 27B10050 */  addiu     $s1, $sp, 0x50
/* 17FCC 8003CBCC 02A0A02D */  daddu     $s4, $s5, $zero
/* 17FD0 8003CBD0 2405000C */  addiu     $a1, $zero, 0xc
.L8003CBD4:
/* 17FD4 8003CBD4 0200302D */  daddu     $a2, $s0, $zero
/* 17FD8 8003CBD8 02701021 */  addu      $v0, $s3, $s0
/* 17FDC 8003CBDC 02501821 */  addu      $v1, $s2, $s0
/* 17FE0 8003CBE0 02302021 */  addu      $a0, $s1, $s0
/* 17FE4 8003CBE4 90470000 */  lbu       $a3, ($v0)
/* 17FE8 8003CBE8 90620000 */  lbu       $v0, ($v1)
/* 17FEC 8003CBEC 90830000 */  lbu       $v1, ($a0)
/* 17FF0 8003CBF0 26100001 */  addiu     $s0, $s0, 1
/* 17FF4 8003CBF4 AFA00010 */  sw        $zero, 0x10($sp)
/* 17FF8 8003CBF8 AFB40014 */  sw        $s4, 0x14($sp)
/* 17FFC 8003CBFC AFA00018 */  sw        $zero, 0x18($sp)
/* 18000 8003CC00 8EC40024 */  lw        $a0, 0x24($s6)
/* 18004 8003CC04 00073E00 */  sll       $a3, $a3, 0x18
/* 18008 8003CC08 00021400 */  sll       $v0, $v0, 0x10
/* 1800C 8003CC0C 00E23825 */  or        $a3, $a3, $v0
/* 18010 8003CC10 00031A00 */  sll       $v1, $v1, 8
/* 18014 8003CC14 00E33825 */  or        $a3, $a3, $v1
/* 18018 8003CC18 0C0448F9 */  jal       func_801123E4
/* 1801C 8003CC1C 00F53825 */   or       $a3, $a3, $s5
/* 18020 8003CC20 2A020014 */  slti      $v0, $s0, 0x14
/* 18024 8003CC24 1440FFEB */  bnez      $v0, .L8003CBD4
/* 18028 8003CC28 2405000C */   addiu    $a1, $zero, 0xc
.L8003CC2C:
/* 1802C 8003CC2C 8FBF0084 */  lw        $ra, 0x84($sp)
/* 18030 8003CC30 8FB60080 */  lw        $s6, 0x80($sp)
/* 18034 8003CC34 8FB5007C */  lw        $s5, 0x7c($sp)
/* 18038 8003CC38 8FB40078 */  lw        $s4, 0x78($sp)
/* 1803C 8003CC3C 8FB30074 */  lw        $s3, 0x74($sp)
/* 18040 8003CC40 8FB20070 */  lw        $s2, 0x70($sp)
/* 18044 8003CC44 8FB1006C */  lw        $s1, 0x6c($sp)
/* 18048 8003CC48 8FB00068 */  lw        $s0, 0x68($sp)
/* 1804C 8003CC4C D7B80098 */  ldc1      $f24, 0x98($sp)
/* 18050 8003CC50 D7B60090 */  ldc1      $f22, 0x90($sp)
/* 18054 8003CC54 D7B40088 */  ldc1      $f20, 0x88($sp)
/* 18058 8003CC58 03E00008 */  jr        $ra
/* 1805C 8003CC5C 27BD00A0 */   addiu    $sp, $sp, 0xa0
