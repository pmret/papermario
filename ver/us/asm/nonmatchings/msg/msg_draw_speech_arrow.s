.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80150A08
.double 0.7

glabel D_80150A10
.double 0.005

glabel D_80150A18
.double 0.67

glabel D_80150A20
.double 0.3

glabel D_80150A28
.double 0.005

glabel D_80150A30
.double 0.38, 0.0

.section .text

glabel msg_draw_speech_arrow
/* C3ADC 8012D3DC 27BDFF58 */  addiu     $sp, $sp, -0xa8
/* C3AE0 8012D3E0 AFB10064 */  sw        $s1, 0x64($sp)
/* C3AE4 8012D3E4 0080882D */  daddu     $s1, $a0, $zero
/* C3AE8 8012D3E8 0000282D */  daddu     $a1, $zero, $zero
/* C3AEC 8012D3EC AFBF0084 */  sw        $ra, 0x84($sp)
/* C3AF0 8012D3F0 AFBE0080 */  sw        $fp, 0x80($sp)
/* C3AF4 8012D3F4 AFB7007C */  sw        $s7, 0x7c($sp)
/* C3AF8 8012D3F8 AFB60078 */  sw        $s6, 0x78($sp)
/* C3AFC 8012D3FC AFB50074 */  sw        $s5, 0x74($sp)
/* C3B00 8012D400 AFB40070 */  sw        $s4, 0x70($sp)
/* C3B04 8012D404 AFB3006C */  sw        $s3, 0x6c($sp)
/* C3B08 8012D408 AFB20068 */  sw        $s2, 0x68($sp)
/* C3B0C 8012D40C AFB00060 */  sw        $s0, 0x60($sp)
/* C3B10 8012D410 F7BA00A0 */  sdc1      $f26, 0xa0($sp)
/* C3B14 8012D414 F7B80098 */  sdc1      $f24, 0x98($sp)
/* C3B18 8012D418 F7B60090 */  sdc1      $f22, 0x90($sp)
/* C3B1C 8012D41C F7B40088 */  sdc1      $f20, 0x88($sp)
/* C3B20 8012D420 96230456 */  lhu       $v1, 0x456($s1)
/* C3B24 8012D424 9622045A */  lhu       $v0, 0x45a($s1)
/* C3B28 8012D428 96240458 */  lhu       $a0, 0x458($s1)
/* C3B2C 8012D42C 00623021 */  addu      $a2, $v1, $v0
/* C3B30 8012D430 9622045C */  lhu       $v0, 0x45c($s1)
/* C3B34 8012D434 9623050E */  lhu       $v1, 0x50e($s1)
/* C3B38 8012D438 106001B7 */  beqz      $v1, .L8012DB18
/* C3B3C 8012D43C 00822021 */   addu     $a0, $a0, $v0
/* C3B40 8012D440 92220508 */  lbu       $v0, 0x508($s1)
/* C3B44 8012D444 2442FFFF */  addiu     $v0, $v0, -1
/* C3B48 8012D448 2C420003 */  sltiu     $v0, $v0, 3
/* C3B4C 8012D44C 14400004 */  bnez      $v0, .L8012D460
/* C3B50 8012D450 24020003 */   addiu    $v0, $zero, 3
/* C3B54 8012D454 9223053C */  lbu       $v1, 0x53c($s1)
/* C3B58 8012D458 14620005 */  bne       $v1, $v0, .L8012D470
/* C3B5C 8012D45C 00000000 */   nop
.L8012D460:
/* C3B60 8012D460 96220516 */  lhu       $v0, 0x516($s1)
/* C3B64 8012D464 00821021 */  addu      $v0, $a0, $v0
/* C3B68 8012D468 0804B51F */  j         .L8012D47C
/* C3B6C 8012D46C 2454FFFC */   addiu    $s4, $v0, -4
.L8012D470:
/* C3B70 8012D470 96220516 */  lhu       $v0, 0x516($s1)
/* C3B74 8012D474 00821021 */  addu      $v0, $a0, $v0
/* C3B78 8012D478 2454FFFD */  addiu     $s4, $v0, -3
.L8012D47C:
/* C3B7C 8012D47C 92230508 */  lbu       $v1, 0x508($s1)
/* C3B80 8012D480 24020002 */  addiu     $v0, $zero, 2
/* C3B84 8012D484 14620003 */  bne       $v1, $v0, .L8012D494
/* C3B88 8012D488 24020003 */   addiu    $v0, $zero, 3
/* C3B8C 8012D48C 0804B52C */  j         .L8012D4B0
/* C3B90 8012D490 0000282D */   daddu    $a1, $zero, $zero
.L8012D494:
/* C3B94 8012D494 50620006 */  beql      $v1, $v0, .L8012D4B0
/* C3B98 8012D498 24050001 */   addiu    $a1, $zero, 1
/* C3B9C 8012D49C 9622050E */  lhu       $v0, 0x50e($s1)
/* C3BA0 8012D4A0 2C4200A0 */  sltiu     $v0, $v0, 0xa0
/* C3BA4 8012D4A4 14400003 */  bnez      $v0, .L8012D4B4
/* C3BA8 8012D4A8 30A200FF */   andi     $v0, $a1, 0xff
/* C3BAC 8012D4AC 24050001 */  addiu     $a1, $zero, 1
.L8012D4B0:
/* C3BB0 8012D4B0 30A200FF */  andi      $v0, $a1, 0xff
.L8012D4B4:
/* C3BB4 8012D4B4 10400056 */  beqz      $v0, .L8012D610
/* C3BB8 8012D4B8 00000000 */   nop
/* C3BBC 8012D4BC 96220514 */  lhu       $v0, 0x514($s1)
/* C3BC0 8012D4C0 3C018015 */  lui       $at, %hi(D_80150A08)
/* C3BC4 8012D4C4 D4200A08 */  ldc1      $f0, %lo(D_80150A08)($at)
/* C3BC8 8012D4C8 44821000 */  mtc1      $v0, $f2
/* C3BCC 8012D4CC 00000000 */  nop
/* C3BD0 8012D4D0 468010A0 */  cvt.s.w   $f2, $f2
/* C3BD4 8012D4D4 460010A1 */  cvt.d.s   $f2, $f2
/* C3BD8 8012D4D8 46201082 */  mul.d     $f2, $f2, $f0
/* C3BDC 8012D4DC 00000000 */  nop
/* C3BE0 8012D4E0 00061400 */  sll       $v0, $a2, 0x10
/* C3BE4 8012D4E4 00022403 */  sra       $a0, $v0, 0x10
/* C3BE8 8012D4E8 44840000 */  mtc1      $a0, $f0
/* C3BEC 8012D4EC 00000000 */  nop
/* C3BF0 8012D4F0 46800021 */  cvt.d.w   $f0, $f0
/* C3BF4 8012D4F4 46220000 */  add.d     $f0, $f0, $f2
/* C3BF8 8012D4F8 9623050E */  lhu       $v1, 0x50e($s1)
/* C3BFC 8012D4FC 4620010D */  trunc.w.d $f4, $f0
/* C3C00 8012D500 44022000 */  mfc1      $v0, $f4
/* C3C04 8012D504 00000000 */  nop
/* C3C08 8012D508 0040902D */  daddu     $s2, $v0, $zero
/* C3C0C 8012D50C 00021400 */  sll       $v0, $v0, 0x10
/* C3C10 8012D510 00021403 */  sra       $v0, $v0, 0x10
/* C3C14 8012D514 0062182A */  slt       $v1, $v1, $v0
/* C3C18 8012D518 10600090 */  beqz      $v1, .L8012D75C
/* C3C1C 8012D51C 00141400 */   sll      $v0, $s4, 0x10
/* C3C20 8012D520 4484D000 */  mtc1      $a0, $f26
/* C3C24 8012D524 00000000 */  nop
/* C3C28 8012D528 4680D6A0 */  cvt.s.w   $f26, $f26
/* C3C2C 8012D52C 00029C03 */  sra       $s3, $v0, 0x10
/* C3C30 8012D530 3C013F33 */  lui       $at, 0x3f33
/* C3C34 8012D534 34213333 */  ori       $at, $at, 0x3333
/* C3C38 8012D538 4481A000 */  mtc1      $at, $f20
/* C3C3C 8012D53C 3C018015 */  lui       $at, %hi(D_80150A10)
/* C3C40 8012D540 D4380A10 */  ldc1      $f24, %lo(D_80150A10)($at)
/* C3C44 8012D544 3C018015 */  lui       $at, %hi(D_80150A18)
/* C3C48 8012D548 D4360A18 */  ldc1      $f22, %lo(D_80150A18)($at)
.L8012D54C:
/* C3C4C 8012D54C 96220514 */  lhu       $v0, 0x514($s1)
/* C3C50 8012D550 44820000 */  mtc1      $v0, $f0
/* C3C54 8012D554 00000000 */  nop
/* C3C58 8012D558 46800020 */  cvt.s.w   $f0, $f0
/* C3C5C 8012D55C 46140002 */  mul.s     $f0, $f0, $f20
/* C3C60 8012D560 00000000 */  nop
/* C3C64 8012D564 44932000 */  mtc1      $s3, $f4
/* C3C68 8012D568 00000000 */  nop
/* C3C6C 8012D56C 46802120 */  cvt.s.w   $f4, $f4
/* C3C70 8012D570 44072000 */  mfc1      $a3, $f4
/* C3C74 8012D574 9622050E */  lhu       $v0, 0x50e($s1)
/* C3C78 8012D578 4600D000 */  add.s     $f0, $f26, $f0
/* C3C7C 8012D57C 96230510 */  lhu       $v1, 0x510($s1)
/* C3C80 8012D580 44826000 */  mtc1      $v0, $f12
/* C3C84 8012D584 00000000 */  nop
/* C3C88 8012D588 46806320 */  cvt.s.w   $f12, $f12
/* C3C8C 8012D58C 4600010D */  trunc.w.s $f4, $f0
/* C3C90 8012D590 44022000 */  mfc1      $v0, $f4
/* C3C94 8012D594 00000000 */  nop
/* C3C98 8012D598 0040902D */  daddu     $s2, $v0, $zero
/* C3C9C 8012D59C 00021400 */  sll       $v0, $v0, 0x10
/* C3CA0 8012D5A0 00021403 */  sra       $v0, $v0, 0x10
/* C3CA4 8012D5A4 44822000 */  mtc1      $v0, $f4
/* C3CA8 8012D5A8 00000000 */  nop
/* C3CAC 8012D5AC 46802120 */  cvt.s.w   $f4, $f4
/* C3CB0 8012D5B0 44062000 */  mfc1      $a2, $f4
/* C3CB4 8012D5B4 44837000 */  mtc1      $v1, $f14
/* C3CB8 8012D5B8 00000000 */  nop
/* C3CBC 8012D5BC 0C00A720 */  jal       atan2
/* C3CC0 8012D5C0 468073A0 */   cvt.s.w  $f14, $f14
/* C3CC4 8012D5C4 4600010D */  trunc.w.s $f4, $f0
/* C3CC8 8012D5C8 44102000 */  mfc1      $s0, $f4
/* C3CCC 8012D5CC 00000000 */  nop
/* C3CD0 8012D5D0 06010002 */  bgez      $s0, .L8012D5DC
/* C3CD4 8012D5D4 0200102D */   daddu    $v0, $s0, $zero
/* C3CD8 8012D5D8 00021023 */  negu      $v0, $v0
.L8012D5DC:
/* C3CDC 8012D5DC 2842002D */  slti      $v0, $v0, 0x2d
/* C3CE0 8012D5E0 1440005F */  bnez      $v0, .L8012D760
/* C3CE4 8012D5E4 00121400 */   sll      $v0, $s2, 0x10
/* C3CE8 8012D5E8 4600A021 */  cvt.d.s   $f0, $f20
/* C3CEC 8012D5EC 46380001 */  sub.d     $f0, $f0, $f24
/* C3CF0 8012D5F0 46200520 */  cvt.s.d   $f20, $f0
/* C3CF4 8012D5F4 4600A021 */  cvt.d.s   $f0, $f20
/* C3CF8 8012D5F8 4620B03E */  c.le.d    $f22, $f0
/* C3CFC 8012D5FC 00000000 */  nop
/* C3D00 8012D600 45000058 */  bc1f      .L8012D764
/* C3D04 8012D604 00021403 */   sra      $v0, $v0, 0x10
/* C3D08 8012D608 0804B553 */  j         .L8012D54C
/* C3D0C 8012D60C 00000000 */   nop
.L8012D610:
/* C3D10 8012D610 96220514 */  lhu       $v0, 0x514($s1)
/* C3D14 8012D614 3C018015 */  lui       $at, %hi(D_80150A20)
/* C3D18 8012D618 D4200A20 */  ldc1      $f0, %lo(D_80150A20)($at)
/* C3D1C 8012D61C 44821000 */  mtc1      $v0, $f2
/* C3D20 8012D620 00000000 */  nop
/* C3D24 8012D624 468010A0 */  cvt.s.w   $f2, $f2
/* C3D28 8012D628 460010A1 */  cvt.d.s   $f2, $f2
/* C3D2C 8012D62C 46201082 */  mul.d     $f2, $f2, $f0
/* C3D30 8012D630 00000000 */  nop
/* C3D34 8012D634 00061400 */  sll       $v0, $a2, 0x10
/* C3D38 8012D638 00022403 */  sra       $a0, $v0, 0x10
/* C3D3C 8012D63C 44840000 */  mtc1      $a0, $f0
/* C3D40 8012D640 00000000 */  nop
/* C3D44 8012D644 46800021 */  cvt.d.w   $f0, $f0
/* C3D48 8012D648 46220000 */  add.d     $f0, $f0, $f2
/* C3D4C 8012D64C 9623050E */  lhu       $v1, 0x50e($s1)
/* C3D50 8012D650 4620010D */  trunc.w.d $f4, $f0
/* C3D54 8012D654 44022000 */  mfc1      $v0, $f4
/* C3D58 8012D658 00000000 */  nop
/* C3D5C 8012D65C 0040902D */  daddu     $s2, $v0, $zero
/* C3D60 8012D660 00021400 */  sll       $v0, $v0, 0x10
/* C3D64 8012D664 00021403 */  sra       $v0, $v0, 0x10
/* C3D68 8012D668 0043102A */  slt       $v0, $v0, $v1
/* C3D6C 8012D66C 1040003B */  beqz      $v0, .L8012D75C
/* C3D70 8012D670 00141400 */   sll      $v0, $s4, 0x10
/* C3D74 8012D674 4484D000 */  mtc1      $a0, $f26
/* C3D78 8012D678 00000000 */  nop
/* C3D7C 8012D67C 4680D6A0 */  cvt.s.w   $f26, $f26
/* C3D80 8012D680 00029C03 */  sra       $s3, $v0, 0x10
/* C3D84 8012D684 3C013E99 */  lui       $at, 0x3e99
/* C3D88 8012D688 3421999A */  ori       $at, $at, 0x999a
/* C3D8C 8012D68C 4481A000 */  mtc1      $at, $f20
/* C3D90 8012D690 3C018015 */  lui       $at, %hi(D_80150A28)
/* C3D94 8012D694 D4380A28 */  ldc1      $f24, %lo(D_80150A28)($at)
/* C3D98 8012D698 3C018015 */  lui       $at, %hi(D_80150A30)
/* C3D9C 8012D69C D4360A30 */  ldc1      $f22, %lo(D_80150A30)($at)
.L8012D6A0:
/* C3DA0 8012D6A0 96220514 */  lhu       $v0, 0x514($s1)
/* C3DA4 8012D6A4 44820000 */  mtc1      $v0, $f0
/* C3DA8 8012D6A8 00000000 */  nop
/* C3DAC 8012D6AC 46800020 */  cvt.s.w   $f0, $f0
/* C3DB0 8012D6B0 46140002 */  mul.s     $f0, $f0, $f20
/* C3DB4 8012D6B4 00000000 */  nop
/* C3DB8 8012D6B8 44932000 */  mtc1      $s3, $f4
/* C3DBC 8012D6BC 00000000 */  nop
/* C3DC0 8012D6C0 46802120 */  cvt.s.w   $f4, $f4
/* C3DC4 8012D6C4 44072000 */  mfc1      $a3, $f4
/* C3DC8 8012D6C8 9622050E */  lhu       $v0, 0x50e($s1)
/* C3DCC 8012D6CC 4600D000 */  add.s     $f0, $f26, $f0
/* C3DD0 8012D6D0 96230510 */  lhu       $v1, 0x510($s1)
/* C3DD4 8012D6D4 44826000 */  mtc1      $v0, $f12
/* C3DD8 8012D6D8 00000000 */  nop
/* C3DDC 8012D6DC 46806320 */  cvt.s.w   $f12, $f12
/* C3DE0 8012D6E0 4600010D */  trunc.w.s $f4, $f0
/* C3DE4 8012D6E4 44022000 */  mfc1      $v0, $f4
/* C3DE8 8012D6E8 00000000 */  nop
/* C3DEC 8012D6EC 0040902D */  daddu     $s2, $v0, $zero
/* C3DF0 8012D6F0 00021400 */  sll       $v0, $v0, 0x10
/* C3DF4 8012D6F4 00021403 */  sra       $v0, $v0, 0x10
/* C3DF8 8012D6F8 44822000 */  mtc1      $v0, $f4
/* C3DFC 8012D6FC 00000000 */  nop
/* C3E00 8012D700 46802120 */  cvt.s.w   $f4, $f4
/* C3E04 8012D704 44062000 */  mfc1      $a2, $f4
/* C3E08 8012D708 44837000 */  mtc1      $v1, $f14
/* C3E0C 8012D70C 00000000 */  nop
/* C3E10 8012D710 0C00A720 */  jal       atan2
/* C3E14 8012D714 468073A0 */   cvt.s.w  $f14, $f14
/* C3E18 8012D718 4600010D */  trunc.w.s $f4, $f0
/* C3E1C 8012D71C 44102000 */  mfc1      $s0, $f4
/* C3E20 8012D720 00000000 */  nop
/* C3E24 8012D724 06010002 */  bgez      $s0, .L8012D730
/* C3E28 8012D728 0200102D */   daddu    $v0, $s0, $zero
/* C3E2C 8012D72C 00021023 */  negu      $v0, $v0
.L8012D730:
/* C3E30 8012D730 2842002D */  slti      $v0, $v0, 0x2d
/* C3E34 8012D734 1440000A */  bnez      $v0, .L8012D760
/* C3E38 8012D738 00121400 */   sll      $v0, $s2, 0x10
/* C3E3C 8012D73C 4600A021 */  cvt.d.s   $f0, $f20
/* C3E40 8012D740 46380000 */  add.d     $f0, $f0, $f24
/* C3E44 8012D744 46200520 */  cvt.s.d   $f20, $f0
/* C3E48 8012D748 4600A021 */  cvt.d.s   $f0, $f20
/* C3E4C 8012D74C 4636003E */  c.le.d    $f0, $f22
/* C3E50 8012D750 00000000 */  nop
/* C3E54 8012D754 4501FFD2 */  bc1t      .L8012D6A0
/* C3E58 8012D758 00000000 */   nop
.L8012D75C:
/* C3E5C 8012D75C 00121400 */  sll       $v0, $s2, 0x10
.L8012D760:
/* C3E60 8012D760 00021403 */  sra       $v0, $v0, 0x10
.L8012D764:
/* C3E64 8012D764 4482C000 */  mtc1      $v0, $f24
/* C3E68 8012D768 00000000 */  nop
/* C3E6C 8012D76C 4680C620 */  cvt.s.w   $f24, $f24
/* C3E70 8012D770 00141400 */  sll       $v0, $s4, 0x10
/* C3E74 8012D774 0002B403 */  sra       $s6, $v0, 0x10
/* C3E78 8012D778 4496B000 */  mtc1      $s6, $f22
/* C3E7C 8012D77C 00000000 */  nop
/* C3E80 8012D780 4680B5A0 */  cvt.s.w   $f22, $f22
/* C3E84 8012D784 4406C000 */  mfc1      $a2, $f24
/* C3E88 8012D788 4407B000 */  mfc1      $a3, $f22
/* C3E8C 8012D78C 8622050A */  lh        $v0, 0x50a($s1)
/* C3E90 8012D790 8623050C */  lh        $v1, 0x50c($s1)
/* C3E94 8012D794 44826000 */  mtc1      $v0, $f12
/* C3E98 8012D798 00000000 */  nop
/* C3E9C 8012D79C 46806320 */  cvt.s.w   $f12, $f12
/* C3EA0 8012D7A0 44837000 */  mtc1      $v1, $f14
/* C3EA4 8012D7A4 00000000 */  nop
/* C3EA8 8012D7A8 468073A0 */  cvt.s.w   $f14, $f14
/* C3EAC 8012D7AC 0C00A7B5 */  jal       dist2D
/* C3EB0 8012D7B0 2655FFF7 */   addiu    $s5, $s2, -9
/* C3EB4 8012D7B4 4600010D */  trunc.w.s $f4, $f0
/* C3EB8 8012D7B8 44172000 */  mfc1      $s7, $f4
/* C3EBC 8012D7BC 26520009 */  addiu     $s2, $s2, 9
/* C3EC0 8012D7C0 2AE2000A */  slti      $v0, $s7, 0xa
/* C3EC4 8012D7C4 144000D4 */  bnez      $v0, .L8012DB18
/* C3EC8 8012D7C8 AFB20050 */   sw       $s2, 0x50($sp)
/* C3ECC 8012D7CC 2AE2001A */  slti      $v0, $s7, 0x1a
/* C3ED0 8012D7D0 50400001 */  beql      $v0, $zero, .L8012D7D8
/* C3ED4 8012D7D4 24170019 */   addiu    $s7, $zero, 0x19
.L8012D7D8:
/* C3ED8 8012D7D8 3C028007 */  lui       $v0, %hi(gCurrentDisplayContextIndex)
/* C3EDC 8012D7DC 8C4241F4 */  lw        $v0, %lo(gCurrentDisplayContextIndex)($v0)
/* C3EE0 8012D7E0 3C1E8015 */  lui       $fp, %hi(D_8014C4C0)
/* C3EE4 8012D7E4 27DEC4C0 */  addiu     $fp, $fp, %lo(D_8014C4C0)
/* C3EE8 8012D7E8 10400003 */  beqz      $v0, .L8012D7F8
/* C3EEC 8012D7EC 4600C306 */   mov.s    $f12, $f24
/* C3EF0 8012D7F0 3C1E8015 */  lui       $fp, %hi(D_8014C480)
/* C3EF4 8012D7F4 27DEC480 */  addiu     $fp, $fp, %lo(D_8014C480)
.L8012D7F8:
/* C3EF8 8012D7F8 8622050A */  lh        $v0, 0x50a($s1)
/* C3EFC 8012D7FC 8623050C */  lh        $v1, 0x50c($s1)
/* C3F00 8012D800 44822000 */  mtc1      $v0, $f4
/* C3F04 8012D804 00000000 */  nop
/* C3F08 8012D808 46802120 */  cvt.s.w   $f4, $f4
/* C3F0C 8012D80C 44062000 */  mfc1      $a2, $f4
/* C3F10 8012D810 44832000 */  mtc1      $v1, $f4
/* C3F14 8012D814 00000000 */  nop
/* C3F18 8012D818 46802120 */  cvt.s.w   $f4, $f4
/* C3F1C 8012D81C 44072000 */  mfc1      $a3, $f4
/* C3F20 8012D820 0C00A720 */  jal       atan2
/* C3F24 8012D824 4600B386 */   mov.s    $f14, $f22
/* C3F28 8012D828 4600010D */  trunc.w.s $f4, $f0
/* C3F2C 8012D82C 44102000 */  mfc1      $s0, $f4
/* C3F30 8012D830 00000000 */  nop
/* C3F34 8012D834 2610FF4C */  addiu     $s0, $s0, -0xb4
/* C3F38 8012D838 06010002 */  bgez      $s0, .L8012D844
/* C3F3C 8012D83C 0200102D */   daddu    $v0, $s0, $zero
/* C3F40 8012D840 00021023 */  negu      $v0, $v0
.L8012D844:
/* C3F44 8012D844 2842004B */  slti      $v0, $v0, 0x4b
/* C3F48 8012D848 104000B3 */  beqz      $v0, .L8012DB18
/* C3F4C 8012D84C 00102400 */   sll      $a0, $s0, 0x10
/* C3F50 8012D850 0C00A4F5 */  jal       cosine
/* C3F54 8012D854 00042403 */   sra      $a0, $a0, 0x10
/* C3F58 8012D858 2604005A */  addiu     $a0, $s0, 0x5a
/* C3F5C 8012D85C 00042400 */  sll       $a0, $a0, 0x10
/* C3F60 8012D860 00042403 */  sra       $a0, $a0, 0x10
/* C3F64 8012D864 0C00A4F5 */  jal       cosine
/* C3F68 8012D868 46000506 */   mov.s    $f20, $f0
/* C3F6C 8012D86C 3C13E200 */  lui       $s3, 0xe200
/* C3F70 8012D870 3673001C */  ori       $s3, $s3, 0x1c
/* C3F74 8012D874 3C0F0F0A */  lui       $t7, 0xf0a
/* C3F78 8012D878 35EF4000 */  ori       $t7, $t7, 0x4000
/* C3F7C 8012D87C 3C0CFCFF */  lui       $t4, 0xfcff
/* C3F80 8012D880 358CFFFF */  ori       $t4, $t4, 0xffff
/* C3F84 8012D884 3C0BFFFC */  lui       $t3, 0xfffc
/* C3F88 8012D888 356BFC7E */  ori       $t3, $t3, 0xfc7e
/* C3F8C 8012D88C 3C0AE300 */  lui       $t2, 0xe300
/* C3F90 8012D890 354A1201 */  ori       $t2, $t2, 0x1201
/* C3F94 8012D894 3C112020 */  lui       $s1, 0x2020
/* C3F98 8012D898 363120FF */  ori       $s1, $s1, 0x20ff
/* C3F9C 8012D89C 3C0DFD48 */  lui       $t5, 0xfd48
/* C3FA0 8012D8A0 35AD0007 */  ori       $t5, $t5, 7
/* C3FA4 8012D8A4 3C12F548 */  lui       $s2, 0xf548
/* C3FA8 8012D8A8 36520200 */  ori       $s2, $s2, 0x200
/* C3FAC 8012D8AC 3C0E0701 */  lui       $t6, 0x701
/* C3FB0 8012D8B0 35CE0040 */  ori       $t6, $t6, 0x40
/* C3FB4 8012D8B4 3C190701 */  lui       $t9, 0x701
/* C3FB8 8012D8B8 3739E03C */  ori       $t9, $t9, 0xe03c
/* C3FBC 8012D8BC AFB90054 */  sw        $t9, 0x54($sp)
/* C3FC0 8012D8C0 3C19F540 */  lui       $t9, 0xf540
/* C3FC4 8012D8C4 37390200 */  ori       $t9, $t9, 0x200
/* C3FC8 8012D8C8 AFB90058 */  sw        $t9, 0x58($sp)
/* C3FCC 8012D8CC 3C190001 */  lui       $t9, 1
/* C3FD0 8012D8D0 37390040 */  ori       $t9, $t9, 0x40
/* C3FD4 8012D8D4 3C180003 */  lui       $t8, 3
/* C3FD8 8012D8D8 3718C03C */  ori       $t8, $t8, 0xc03c
/* C3FDC 8012D8DC 27A40010 */  addiu     $a0, $sp, 0x10
/* C3FE0 8012D8E0 3C140001 */  lui       $s4, 1
/* C3FE4 8012D8E4 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* C3FE8 8012D8E8 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* C3FEC 8012D8EC 36941630 */  ori       $s4, $s4, 0x1630
/* C3FF0 8012D8F0 AFB9005C */  sw        $t9, 0x5c($sp)
/* C3FF4 8012D8F4 8E030000 */  lw        $v1, ($s0)
/* C3FF8 8012D8F8 44801000 */  mtc1      $zero, $f2
/* C3FFC 8012D8FC 00161023 */  negu      $v0, $s6
/* C4000 8012D900 A7D50000 */  sh        $s5, ($fp)
/* C4004 8012D904 A7C20002 */  sh        $v0, 2($fp)
/* C4008 8012D908 97B90052 */  lhu       $t9, 0x52($sp)
/* C400C 8012D90C A7C20012 */  sh        $v0, 0x12($fp)
/* C4010 8012D910 0060482D */  daddu     $t1, $v1, $zero
/* C4014 8012D914 24630008 */  addiu     $v1, $v1, 8
/* C4018 8012D918 24620008 */  addiu     $v0, $v1, 8
/* C401C 8012D91C A7D90010 */  sh        $t9, 0x10($fp)
/* C4020 8012D920 AE030000 */  sw        $v1, ($s0)
/* C4024 8012D924 AE020000 */  sw        $v0, ($s0)
/* C4028 8012D928 24620010 */  addiu     $v0, $v1, 0x10
/* C402C 8012D92C 44051000 */  mfc1      $a1, $f2
/* C4030 8012D930 44971000 */  mtc1      $s7, $f2
/* C4034 8012D934 00000000 */  nop
/* C4038 8012D938 468010A0 */  cvt.s.w   $f2, $f2
/* C403C 8012D93C 46141502 */  mul.s     $f20, $f2, $f20
/* C4040 8012D940 00000000 */  nop
/* C4044 8012D944 AE020000 */  sw        $v0, ($s0)
/* C4048 8012D948 24620018 */  addiu     $v0, $v1, 0x18
/* C404C 8012D94C AE020000 */  sw        $v0, ($s0)
/* C4050 8012D950 24620020 */  addiu     $v0, $v1, 0x20
/* C4054 8012D954 46001082 */  mul.s     $f2, $f2, $f0
/* C4058 8012D958 00000000 */  nop
/* C405C 8012D95C AE020000 */  sw        $v0, ($s0)
/* C4060 8012D960 24620028 */  addiu     $v0, $v1, 0x28
/* C4064 8012D964 AE020000 */  sw        $v0, ($s0)
/* C4068 8012D968 24620030 */  addiu     $v0, $v1, 0x30
/* C406C 8012D96C AE020000 */  sw        $v0, ($s0)
/* C4070 8012D970 4614C501 */  sub.s     $f20, $f24, $f20
/* C4074 8012D974 24620038 */  addiu     $v0, $v1, 0x38
/* C4078 8012D978 AE020000 */  sw        $v0, ($s0)
/* C407C 8012D97C 4602B080 */  add.s     $f2, $f22, $f2
/* C4080 8012D980 00A0302D */  daddu     $a2, $a1, $zero
/* C4084 8012D984 4600A10D */  trunc.w.s $f4, $f20
/* C4088 8012D988 44082000 */  mfc1      $t0, $f4
/* C408C 8012D98C 4600110D */  trunc.w.s $f4, $f2
/* C4090 8012D990 44022000 */  mfc1      $v0, $f4
/* C4094 8012D994 00000000 */  nop
/* C4098 8012D998 00021400 */  sll       $v0, $v0, 0x10
/* C409C 8012D99C 00021403 */  sra       $v0, $v0, 0x10
/* C40A0 8012D9A0 00021023 */  negu      $v0, $v0
/* C40A4 8012D9A4 A7C80020 */  sh        $t0, 0x20($fp)
/* C40A8 8012D9A8 25080001 */  addiu     $t0, $t0, 1
/* C40AC 8012D9AC A7C80030 */  sh        $t0, 0x30($fp)
/* C40B0 8012D9B0 3C08E700 */  lui       $t0, 0xe700
/* C40B4 8012D9B4 A7C20022 */  sh        $v0, 0x22($fp)
/* C40B8 8012D9B8 A7C20032 */  sh        $v0, 0x32($fp)
/* C40BC 8012D9BC 24022000 */  addiu     $v0, $zero, 0x2000
/* C40C0 8012D9C0 AD280000 */  sw        $t0, ($t1)
/* C40C4 8012D9C4 AD200004 */  sw        $zero, 4($t1)
/* C40C8 8012D9C8 AC620014 */  sw        $v0, 0x14($v1)
/* C40CC 8012D9CC 3C02FA00 */  lui       $v0, 0xfa00
/* C40D0 8012D9D0 AC620018 */  sw        $v0, 0x18($v1)
/* C40D4 8012D9D4 3C02802F */  lui       $v0, %hi(D_802EBF70)
/* C40D8 8012D9D8 2442BF70 */  addiu     $v0, $v0, %lo(D_802EBF70)
/* C40DC 8012D9DC AC730000 */  sw        $s3, ($v1)
/* C40E0 8012D9E0 AC6F0004 */  sw        $t7, 4($v1)
/* C40E4 8012D9E4 AC6C0008 */  sw        $t4, 8($v1)
/* C40E8 8012D9E8 AC6B000C */  sw        $t3, 0xc($v1)
/* C40EC 8012D9EC AC6A0010 */  sw        $t2, 0x10($v1)
/* C40F0 8012D9F0 AC71001C */  sw        $s1, 0x1c($v1)
/* C40F4 8012D9F4 AC6D0020 */  sw        $t5, 0x20($v1)
/* C40F8 8012D9F8 AC620024 */  sw        $v0, 0x24($v1)
/* C40FC 8012D9FC 3C02E600 */  lui       $v0, 0xe600
/* C4100 8012DA00 AC620030 */  sw        $v0, 0x30($v1)
/* C4104 8012DA04 24620040 */  addiu     $v0, $v1, 0x40
/* C4108 8012DA08 AC720028 */  sw        $s2, 0x28($v1)
/* C410C 8012DA0C AC6E002C */  sw        $t6, 0x2c($v1)
/* C4110 8012DA10 AC600034 */  sw        $zero, 0x34($v1)
/* C4114 8012DA14 AE020000 */  sw        $v0, ($s0)
/* C4118 8012DA18 3C02F400 */  lui       $v0, 0xf400
/* C411C 8012DA1C AC620038 */  sw        $v0, 0x38($v1)
/* C4120 8012DA20 8FB90054 */  lw        $t9, 0x54($sp)
/* C4124 8012DA24 24620048 */  addiu     $v0, $v1, 0x48
/* C4128 8012DA28 AC79003C */  sw        $t9, 0x3c($v1)
/* C412C 8012DA2C AE020000 */  sw        $v0, ($s0)
/* C4130 8012DA30 24620050 */  addiu     $v0, $v1, 0x50
/* C4134 8012DA34 AC680040 */  sw        $t0, 0x40($v1)
/* C4138 8012DA38 AC600044 */  sw        $zero, 0x44($v1)
/* C413C 8012DA3C AE020000 */  sw        $v0, ($s0)
/* C4140 8012DA40 8FB90058 */  lw        $t9, 0x58($sp)
/* C4144 8012DA44 00A0382D */  daddu     $a3, $a1, $zero
/* C4148 8012DA48 AC790048 */  sw        $t9, 0x48($v1)
/* C414C 8012DA4C 8FB9005C */  lw        $t9, 0x5c($sp)
/* C4150 8012DA50 24620058 */  addiu     $v0, $v1, 0x58
/* C4154 8012DA54 AC79004C */  sw        $t9, 0x4c($v1)
/* C4158 8012DA58 AE020000 */  sw        $v0, ($s0)
/* C415C 8012DA5C 3C02F200 */  lui       $v0, 0xf200
/* C4160 8012DA60 AC620050 */  sw        $v0, 0x50($v1)
/* C4164 8012DA64 0C019E40 */  jal       guTranslateF
/* C4168 8012DA68 AC780054 */   sw       $t8, 0x54($v1)
/* C416C 8012DA6C 27A40010 */  addiu     $a0, $sp, 0x10
/* C4170 8012DA70 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* C4174 8012DA74 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* C4178 8012DA78 3C12800A */  lui       $s2, %hi(gDisplayContext)
/* C417C 8012DA7C 2652A674 */  addiu     $s2, $s2, %lo(gDisplayContext)
/* C4180 8012DA80 96250000 */  lhu       $a1, ($s1)
/* C4184 8012DA84 8E420000 */  lw        $v0, ($s2)
/* C4188 8012DA88 00052980 */  sll       $a1, $a1, 6
/* C418C 8012DA8C 00B42821 */  addu      $a1, $a1, $s4
/* C4190 8012DA90 0C019D40 */  jal       guMtxF2L
/* C4194 8012DA94 00452821 */   addu     $a1, $v0, $a1
/* C4198 8012DA98 3C03DA38 */  lui       $v1, 0xda38
/* C419C 8012DA9C 34630003 */  ori       $v1, $v1, 3
/* C41A0 8012DAA0 3C060100 */  lui       $a2, 0x100
/* C41A4 8012DAA4 34C64008 */  ori       $a2, $a2, 0x4008
/* C41A8 8012DAA8 3C080600 */  lui       $t0, 0x600
/* C41AC 8012DAAC 35080402 */  ori       $t0, $t0, 0x402
/* C41B0 8012DAB0 3C070002 */  lui       $a3, 2
/* C41B4 8012DAB4 34E70406 */  ori       $a3, $a3, 0x406
/* C41B8 8012DAB8 8E040000 */  lw        $a0, ($s0)
/* C41BC 8012DABC 96220000 */  lhu       $v0, ($s1)
/* C41C0 8012DAC0 0080282D */  daddu     $a1, $a0, $zero
/* C41C4 8012DAC4 24840008 */  addiu     $a0, $a0, 8
/* C41C8 8012DAC8 AE040000 */  sw        $a0, ($s0)
/* C41CC 8012DACC ACA30000 */  sw        $v1, ($a1)
/* C41D0 8012DAD0 24430001 */  addiu     $v1, $v0, 1
/* C41D4 8012DAD4 3042FFFF */  andi      $v0, $v0, 0xffff
/* C41D8 8012DAD8 00021180 */  sll       $v0, $v0, 6
/* C41DC 8012DADC A6230000 */  sh        $v1, ($s1)
/* C41E0 8012DAE0 8E430000 */  lw        $v1, ($s2)
/* C41E4 8012DAE4 00541021 */  addu      $v0, $v0, $s4
/* C41E8 8012DAE8 00621821 */  addu      $v1, $v1, $v0
/* C41EC 8012DAEC 3C028000 */  lui       $v0, 0x8000
/* C41F0 8012DAF0 00621821 */  addu      $v1, $v1, $v0
/* C41F4 8012DAF4 24820008 */  addiu     $v0, $a0, 8
/* C41F8 8012DAF8 ACA30004 */  sw        $v1, 4($a1)
/* C41FC 8012DAFC AE020000 */  sw        $v0, ($s0)
/* C4200 8012DB00 24820010 */  addiu     $v0, $a0, 0x10
/* C4204 8012DB04 AC860000 */  sw        $a2, ($a0)
/* C4208 8012DB08 AC9E0004 */  sw        $fp, 4($a0)
/* C420C 8012DB0C AE020000 */  sw        $v0, ($s0)
/* C4210 8012DB10 AC880008 */  sw        $t0, 8($a0)
/* C4214 8012DB14 AC87000C */  sw        $a3, 0xc($a0)
.L8012DB18:
/* C4218 8012DB18 8FBF0084 */  lw        $ra, 0x84($sp)
/* C421C 8012DB1C 8FBE0080 */  lw        $fp, 0x80($sp)
/* C4220 8012DB20 8FB7007C */  lw        $s7, 0x7c($sp)
/* C4224 8012DB24 8FB60078 */  lw        $s6, 0x78($sp)
/* C4228 8012DB28 8FB50074 */  lw        $s5, 0x74($sp)
/* C422C 8012DB2C 8FB40070 */  lw        $s4, 0x70($sp)
/* C4230 8012DB30 8FB3006C */  lw        $s3, 0x6c($sp)
/* C4234 8012DB34 8FB20068 */  lw        $s2, 0x68($sp)
/* C4238 8012DB38 8FB10064 */  lw        $s1, 0x64($sp)
/* C423C 8012DB3C 8FB00060 */  lw        $s0, 0x60($sp)
/* C4240 8012DB40 D7BA00A0 */  ldc1      $f26, 0xa0($sp)
/* C4244 8012DB44 D7B80098 */  ldc1      $f24, 0x98($sp)
/* C4248 8012DB48 D7B60090 */  ldc1      $f22, 0x90($sp)
/* C424C 8012DB4C D7B40088 */  ldc1      $f20, 0x88($sp)
/* C4250 8012DB50 03E00008 */  jr        $ra
/* C4254 8012DB54 27BD00A8 */   addiu    $sp, $sp, 0xa8
