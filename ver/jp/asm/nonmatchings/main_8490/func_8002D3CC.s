.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002D3CC
/* 87CC 8002D3CC 27BDFF90 */  addiu     $sp, $sp, -0x70
/* 87D0 8002D3D0 AFBF0054 */  sw        $ra, 0x54($sp)
/* 87D4 8002D3D4 AFBE0050 */  sw        $fp, 0x50($sp)
/* 87D8 8002D3D8 AFB7004C */  sw        $s7, 0x4c($sp)
/* 87DC 8002D3DC AFB60048 */  sw        $s6, 0x48($sp)
/* 87E0 8002D3E0 AFB50044 */  sw        $s5, 0x44($sp)
/* 87E4 8002D3E4 AFB40040 */  sw        $s4, 0x40($sp)
/* 87E8 8002D3E8 AFB3003C */  sw        $s3, 0x3c($sp)
/* 87EC 8002D3EC AFB20038 */  sw        $s2, 0x38($sp)
/* 87F0 8002D3F0 AFB10034 */  sw        $s1, 0x34($sp)
/* 87F4 8002D3F4 AFB00030 */  sw        $s0, 0x30($sp)
/* 87F8 8002D3F8 F7B80068 */  sdc1      $f24, 0x68($sp)
/* 87FC 8002D3FC F7B60060 */  sdc1      $f22, 0x60($sp)
/* 8800 8002D400 F7B40058 */  sdc1      $f20, 0x58($sp)
/* 8804 8002D404 14800005 */  bnez      $a0, .L8002D41C
/* 8808 8002D408 AFA40070 */   sw       $a0, 0x70($sp)
/* 880C 8002D40C 3C01800A */  lui       $at, %hi(D_8009A614)
/* 8810 8002D410 A420A614 */  sh        $zero, %lo(D_8009A614)($at)
/* 8814 8002D414 0C046E2A */  jal       func_8011B8A8
/* 8818 8002D418 00000000 */   nop
.L8002D41C:
/* 881C 8002D41C 8FAB0070 */  lw        $t3, 0x70($sp)
/* 8820 8002D420 11600003 */  beqz      $t3, .L8002D430
/* 8824 8002D424 AFA00020 */   sw       $zero, 0x20($sp)
/* 8828 8002D428 240B0003 */  addiu     $t3, $zero, 3
/* 882C 8002D42C AFAB0020 */  sw        $t3, 0x20($sp)
.L8002D430:
/* 8830 8002D430 8FAB0070 */  lw        $t3, 0x70($sp)
/* 8834 8002D434 24020001 */  addiu     $v0, $zero, 1
/* 8838 8002D438 004B5823 */  subu      $t3, $v0, $t3
/* 883C 8002D43C 24020004 */  addiu     $v0, $zero, 4
/* 8840 8002D440 004B1023 */  subu      $v0, $v0, $t3
/* 8844 8002D444 AFAB0070 */  sw        $t3, 0x70($sp)
/* 8848 8002D448 8FAB0020 */  lw        $t3, 0x20($sp)
/* 884C 8002D44C 0162102A */  slt       $v0, $t3, $v0
/* 8850 8002D450 104001BD */  beqz      $v0, .L8002DB48
/* 8854 8002D454 000B1880 */   sll      $v1, $t3, 2
/* 8858 8002D458 3C17800A */  lui       $s7, %hi(D_8009A64C)
/* 885C 8002D45C 26F7A64C */  addiu     $s7, $s7, %lo(D_8009A64C)
/* 8860 8002D460 3C02800B */  lui       $v0, %hi(D_800B1D60)
/* 8864 8002D464 24421D60 */  addiu     $v0, $v0, %lo(D_800B1D60)
/* 8868 8002D468 006B1821 */  addu      $v1, $v1, $t3
/* 886C 8002D46C 00031880 */  sll       $v1, $v1, 2
/* 8870 8002D470 006B1823 */  subu      $v1, $v1, $t3
/* 8874 8002D474 000320C0 */  sll       $a0, $v1, 3
/* 8878 8002D478 00641821 */  addu      $v1, $v1, $a0
/* 887C 8002D47C 000318C0 */  sll       $v1, $v1, 3
/* 8880 8002D480 0062B021 */  addu      $s6, $v1, $v0
/* 8884 8002D484 3C014080 */  lui       $at, 0x4080
/* 8888 8002D488 4481B000 */  mtc1      $at, $f22
/* 888C 8002D48C 4480A000 */  mtc1      $zero, $f20
/* 8890 8002D490 3C013F80 */  lui       $at, 0x3f80
/* 8894 8002D494 4481C000 */  mtc1      $at, $f24
.L8002D498:
/* 8898 8002D498 96C20000 */  lhu       $v0, ($s6)
/* 889C 8002D49C 104001A0 */  beqz      $v0, .L8002DB20
/* 88A0 8002D4A0 30420082 */   andi     $v0, $v0, 0x82
/* 88A4 8002D4A4 1440019E */  bnez      $v0, .L8002DB20
/* 88A8 8002D4A8 00000000 */   nop
/* 88AC 8002D4AC 8EC201FC */  lw        $v0, 0x1fc($s6)
/* 88B0 8002D4B0 97AB0022 */  lhu       $t3, 0x22($sp)
/* 88B4 8002D4B4 3C01800A */  lui       $at, %hi(D_8009A614)
/* 88B8 8002D4B8 A42BA614 */  sh        $t3, %lo(D_8009A614)($at)
/* 88BC 8002D4BC 50400005 */  beql      $v0, $zero, .L8002D4D4
/* 88C0 8002D4C0 3C02DC08 */   lui      $v0, 0xdc08
/* 88C4 8002D4C4 0040F809 */  jalr      $v0
/* 88C8 8002D4C8 02C0202D */   daddu    $a0, $s6, $zero
/* 88CC 8002D4CC 0800B637 */  j         .L8002D8DC
/* 88D0 8002D4D0 3C0A0001 */   lui      $t2, 1
.L8002D4D4:
/* 88D4 8002D4D4 34420008 */  ori       $v0, $v0, 8
/* 88D8 8002D4D8 3C04D9C0 */  lui       $a0, 0xd9c0
/* 88DC 8002D4DC 3484F9FB */  ori       $a0, $a0, 0xf9fb
/* 88E0 8002D4E0 3C05E300 */  lui       $a1, 0xe300
/* 88E4 8002D4E4 34A50A01 */  ori       $a1, $a1, 0xa01
/* 88E8 8002D4E8 3C06E300 */  lui       $a2, 0xe300
/* 88EC 8002D4EC 8EF50000 */  lw        $s5, ($s7)
/* 88F0 8002D4F0 34C60800 */  ori       $a2, $a2, 0x800
/* 88F4 8002D4F4 02A0182D */  daddu     $v1, $s5, $zero
/* 88F8 8002D4F8 26B50008 */  addiu     $s5, $s5, 8
/* 88FC 8002D4FC AC620000 */  sw        $v0, ($v1)
/* 8900 8002D500 26C200A0 */  addiu     $v0, $s6, 0xa0
/* 8904 8002D504 AC620004 */  sw        $v0, 4($v1)
/* 8908 8002D508 3C02D700 */  lui       $v0, 0xd700
/* 890C 8002D50C AEA40000 */  sw        $a0, ($s5)
/* 8910 8002D510 AEA00004 */  sw        $zero, 4($s5)
/* 8914 8002D514 AEA20008 */  sw        $v0, 8($s5)
/* 8918 8002D518 AEA0000C */  sw        $zero, 0xc($s5)
/* 891C 8002D51C AEA50010 */  sw        $a1, 0x10($s5)
/* 8920 8002D520 AEA00014 */  sw        $zero, 0x14($s5)
/* 8924 8002D524 AEA60018 */  sw        $a2, 0x18($s5)
/* 8928 8002D528 AEA0001C */  sw        $zero, 0x1c($s5)
/* 892C 8002D52C 86D8000E */  lh        $t8, 0xe($s6)
/* 8930 8002D530 86D90010 */  lh        $t9, 0x10($s6)
/* 8934 8002D534 26A20008 */  addiu     $v0, $s5, 8
/* 8938 8002D538 AEF50000 */  sw        $s5, ($s7)
/* 893C 8002D53C AEE20000 */  sw        $v0, ($s7)
/* 8940 8002D540 26A20010 */  addiu     $v0, $s5, 0x10
/* 8944 8002D544 AEE20000 */  sw        $v0, ($s7)
/* 8948 8002D548 26A20018 */  addiu     $v0, $s5, 0x18
/* 894C 8002D54C AEE20000 */  sw        $v0, ($s7)
/* 8950 8002D550 26A20020 */  addiu     $v0, $s5, 0x20
/* 8954 8002D554 AEE20000 */  sw        $v0, ($s7)
/* 8958 8002D558 86C2000A */  lh        $v0, 0xa($s6)
/* 895C 8002D55C 86C3000C */  lh        $v1, 0xc($s6)
/* 8960 8002D560 0302F021 */  addu      $fp, $t8, $v0
/* 8964 8002D564 07010002 */  bgez      $t8, .L8002D570
/* 8968 8002D568 0323A021 */   addu     $s4, $t9, $v1
/* 896C 8002D56C 0000C02D */  daddu     $t8, $zero, $zero
.L8002D570:
/* 8970 8002D570 07220001 */  bltzl     $t9, .L8002D578
/* 8974 8002D574 0000C82D */   daddu    $t9, $zero, $zero
.L8002D578:
/* 8978 8002D578 5BC00001 */  blezl     $fp, .L8002D580
/* 897C 8002D57C 241E0001 */   addiu    $fp, $zero, 1
.L8002D580:
/* 8980 8002D580 5A800001 */  blezl     $s4, .L8002D588
/* 8984 8002D584 24140001 */   addiu    $s4, $zero, 1
.L8002D588:
/* 8988 8002D588 2B020140 */  slti      $v0, $t8, 0x140
/* 898C 8002D58C 50400001 */  beql      $v0, $zero, .L8002D594
/* 8990 8002D590 2418013F */   addiu    $t8, $zero, 0x13f
.L8002D594:
/* 8994 8002D594 2B2200F0 */  slti      $v0, $t9, 0xf0
/* 8998 8002D598 50400001 */  beql      $v0, $zero, .L8002D5A0
/* 899C 8002D59C 241900EF */   addiu    $t9, $zero, 0xef
.L8002D5A0:
/* 89A0 8002D5A0 2BC20141 */  slti      $v0, $fp, 0x141
/* 89A4 8002D5A4 50400001 */  beql      $v0, $zero, .L8002D5AC
/* 89A8 8002D5A8 241E0140 */   addiu    $fp, $zero, 0x140
.L8002D5AC:
/* 89AC 8002D5AC 2A8200F1 */  slti      $v0, $s4, 0xf1
/* 89B0 8002D5B0 50400001 */  beql      $v0, $zero, .L8002D5B8
/* 89B4 8002D5B4 241400F0 */   addiu    $s4, $zero, 0xf0
.L8002D5B8:
/* 89B8 8002D5B8 3C03E300 */  lui       $v1, 0xe300
/* 89BC 8002D5BC 34630F00 */  ori       $v1, $v1, 0xf00
/* 89C0 8002D5C0 3C04E300 */  lui       $a0, 0xe300
/* 89C4 8002D5C4 34841001 */  ori       $a0, $a0, 0x1001
/* 89C8 8002D5C8 3C05E300 */  lui       $a1, 0xe300
/* 89CC 8002D5CC 34A50D01 */  ori       $a1, $a1, 0xd01
/* 89D0 8002D5D0 3C06E300 */  lui       $a2, 0xe300
/* 89D4 8002D5D4 34C60C00 */  ori       $a2, $a2, 0xc00
/* 89D8 8002D5D8 3C07E300 */  lui       $a3, 0xe300
/* 89DC 8002D5DC 34E71201 */  ori       $a3, $a3, 0x1201
/* 89E0 8002D5E0 3C08E300 */  lui       $t0, 0xe300
/* 89E4 8002D5E4 35081402 */  ori       $t0, $t0, 0x1402
/* 89E8 8002D5E8 3C0AFCFF */  lui       $t2, 0xfcff
/* 89EC 8002D5EC 354AFFFF */  ori       $t2, $t2, 0xffff
/* 89F0 8002D5F0 3C09FFFE */  lui       $t1, 0xfffe
/* 89F4 8002D5F4 3529793C */  ori       $t1, $t1, 0x793c
/* 89F8 8002D5F8 3C0BE300 */  lui       $t3, 0xe300
/* 89FC 8002D5FC 356B1700 */  ori       $t3, $t3, 0x1700
/* 8A00 8002D600 3C0CE200 */  lui       $t4, 0xe200
/* 8A04 8002D604 358C1E01 */  ori       $t4, $t4, 0x1e01
/* 8A08 8002D608 3C0DE200 */  lui       $t5, 0xe200
/* 8A0C 8002D60C 35AD001C */  ori       $t5, $t5, 0x1c
/* 8A10 8002D610 3C0E0F0A */  lui       $t6, 0xf0a
/* 8A14 8002D614 35CE4000 */  ori       $t6, $t6, 0x4000
/* 8A18 8002D618 3C0FE300 */  lui       $t7, 0xe300
/* 8A1C 8002D61C 35EF1801 */  ori       $t7, $t7, 0x1801
/* 8A20 8002D620 3C10DB04 */  lui       $s0, 0xdb04
/* 8A24 8002D624 36100004 */  ori       $s0, $s0, 4
/* 8A28 8002D628 3C11DB04 */  lui       $s1, 0xdb04
/* 8A2C 8002D62C 3631000C */  ori       $s1, $s1, 0xc
/* 8A30 8002D630 3C12DB04 */  lui       $s2, 0xdb04
/* 8A34 8002D634 36520014 */  ori       $s2, $s2, 0x14
/* 8A38 8002D638 3C13DB04 */  lui       $s3, 0xdb04
/* 8A3C 8002D63C 3673001C */  ori       $s3, $s3, 0x1c
/* 8A40 8002D640 AFAB0028 */  sw        $t3, 0x28($sp)
/* 8A44 8002D644 3C0BFF10 */  lui       $t3, 0xff10
/* 8A48 8002D648 26A20028 */  addiu     $v0, $s5, 0x28
/* 8A4C 8002D64C AFAB0024 */  sw        $t3, 0x24($sp)
/* 8A50 8002D650 AEE20000 */  sw        $v0, ($s7)
/* 8A54 8002D654 26A20030 */  addiu     $v0, $s5, 0x30
/* 8A58 8002D658 AEE20000 */  sw        $v0, ($s7)
/* 8A5C 8002D65C 26A20038 */  addiu     $v0, $s5, 0x38
/* 8A60 8002D660 AEA30028 */  sw        $v1, 0x28($s5)
/* 8A64 8002D664 AEA0002C */  sw        $zero, 0x2c($s5)
/* 8A68 8002D668 AEE20000 */  sw        $v0, ($s7)
/* 8A6C 8002D66C 26A20040 */  addiu     $v0, $s5, 0x40
/* 8A70 8002D670 AEA40030 */  sw        $a0, 0x30($s5)
/* 8A74 8002D674 AEA00034 */  sw        $zero, 0x34($s5)
/* 8A78 8002D678 AEE20000 */  sw        $v0, ($s7)
/* 8A7C 8002D67C 26A20048 */  addiu     $v0, $s5, 0x48
/* 8A80 8002D680 AEA50038 */  sw        $a1, 0x38($s5)
/* 8A84 8002D684 AEA0003C */  sw        $zero, 0x3c($s5)
/* 8A88 8002D688 AEE20000 */  sw        $v0, ($s7)
/* 8A8C 8002D68C 3C020008 */  lui       $v0, 8
/* 8A90 8002D690 AEA20044 */  sw        $v0, 0x44($s5)
/* 8A94 8002D694 26A20050 */  addiu     $v0, $s5, 0x50
/* 8A98 8002D698 AEA60040 */  sw        $a2, 0x40($s5)
/* 8A9C 8002D69C AEE20000 */  sw        $v0, ($s7)
/* 8AA0 8002D6A0 24022000 */  addiu     $v0, $zero, 0x2000
/* 8AA4 8002D6A4 AEA2004C */  sw        $v0, 0x4c($s5)
/* 8AA8 8002D6A8 26A20058 */  addiu     $v0, $s5, 0x58
/* 8AAC 8002D6AC AEA70048 */  sw        $a3, 0x48($s5)
/* 8AB0 8002D6B0 AEE20000 */  sw        $v0, ($s7)
/* 8AB4 8002D6B4 24020C00 */  addiu     $v0, $zero, 0xc00
/* 8AB8 8002D6B8 AEA20054 */  sw        $v0, 0x54($s5)
/* 8ABC 8002D6BC 26A20060 */  addiu     $v0, $s5, 0x60
/* 8AC0 8002D6C0 AEA80050 */  sw        $t0, 0x50($s5)
/* 8AC4 8002D6C4 AEE20000 */  sw        $v0, ($s7)
/* 8AC8 8002D6C8 26A20068 */  addiu     $v0, $s5, 0x68
/* 8ACC 8002D6CC 44981000 */  mtc1      $t8, $f2
/* 8AD0 8002D6D0 00000000 */  nop
/* 8AD4 8002D6D4 468010A0 */  cvt.s.w   $f2, $f2
/* 8AD8 8002D6D8 46161082 */  mul.s     $f2, $f2, $f22
/* 8ADC 8002D6DC 00000000 */  nop
/* 8AE0 8002D6E0 AEAA0058 */  sw        $t2, 0x58($s5)
/* 8AE4 8002D6E4 AEA9005C */  sw        $t1, 0x5c($s5)
/* 8AE8 8002D6E8 AEE20000 */  sw        $v0, ($s7)
/* 8AEC 8002D6EC 26A20070 */  addiu     $v0, $s5, 0x70
/* 8AF0 8002D6F0 44990000 */  mtc1      $t9, $f0
/* 8AF4 8002D6F4 00000000 */  nop
/* 8AF8 8002D6F8 46800020 */  cvt.s.w   $f0, $f0
/* 8AFC 8002D6FC 8FAB0028 */  lw        $t3, 0x28($sp)
/* 8B00 8002D700 46160002 */  mul.s     $f0, $f0, $f22
/* 8B04 8002D704 00000000 */  nop
/* 8B08 8002D708 AEAB0060 */  sw        $t3, 0x60($s5)
/* 8B0C 8002D70C AEA00064 */  sw        $zero, 0x64($s5)
/* 8B10 8002D710 AEE20000 */  sw        $v0, ($s7)
/* 8B14 8002D714 26A20078 */  addiu     $v0, $s5, 0x78
/* 8B18 8002D718 AEAC0068 */  sw        $t4, 0x68($s5)
/* 8B1C 8002D71C AEA0006C */  sw        $zero, 0x6c($s5)
/* 8B20 8002D720 AEE20000 */  sw        $v0, ($s7)
/* 8B24 8002D724 3C02ED00 */  lui       $v0, 0xed00
/* 8B28 8002D728 AEAD0070 */  sw        $t5, 0x70($s5)
/* 8B2C 8002D72C AEAE0074 */  sw        $t6, 0x74($s5)
/* 8B30 8002D730 4600110D */  trunc.w.s $f4, $f2
/* 8B34 8002D734 44042000 */  mfc1      $a0, $f4
/* 8B38 8002D738 00000000 */  nop
/* 8B3C 8002D73C 30840FFF */  andi      $a0, $a0, 0xfff
/* 8B40 8002D740 00042300 */  sll       $a0, $a0, 0xc
/* 8B44 8002D744 4600010D */  trunc.w.s $f4, $f0
/* 8B48 8002D748 44032000 */  mfc1      $v1, $f4
/* 8B4C 8002D74C 449E1000 */  mtc1      $fp, $f2
/* 8B50 8002D750 00000000 */  nop
/* 8B54 8002D754 468010A0 */  cvt.s.w   $f2, $f2
/* 8B58 8002D758 46161082 */  mul.s     $f2, $f2, $f22
/* 8B5C 8002D75C 00000000 */  nop
/* 8B60 8002D760 30630FFF */  andi      $v1, $v1, 0xfff
/* 8B64 8002D764 00621825 */  or        $v1, $v1, $v0
/* 8B68 8002D768 00832025 */  or        $a0, $a0, $v1
/* 8B6C 8002D76C 44940000 */  mtc1      $s4, $f0
/* 8B70 8002D770 00000000 */  nop
/* 8B74 8002D774 46800020 */  cvt.s.w   $f0, $f0
/* 8B78 8002D778 46160002 */  mul.s     $f0, $f0, $f22
/* 8B7C 8002D77C 00000000 */  nop
/* 8B80 8002D780 AEA40020 */  sw        $a0, 0x20($s5)
/* 8B84 8002D784 4600110D */  trunc.w.s $f4, $f2
/* 8B88 8002D788 44032000 */  mfc1      $v1, $f4
/* 8B8C 8002D78C 00000000 */  nop
/* 8B90 8002D790 30630FFF */  andi      $v1, $v1, 0xfff
/* 8B94 8002D794 00031B00 */  sll       $v1, $v1, 0xc
/* 8B98 8002D798 4600010D */  trunc.w.s $f4, $f0
/* 8B9C 8002D79C 44022000 */  mfc1      $v0, $f4
/* 8BA0 8002D7A0 00000000 */  nop
/* 8BA4 8002D7A4 30420FFF */  andi      $v0, $v0, 0xfff
/* 8BA8 8002D7A8 00621825 */  or        $v1, $v1, $v0
/* 8BAC 8002D7AC 26A20080 */  addiu     $v0, $s5, 0x80
/* 8BB0 8002D7B0 AEA30024 */  sw        $v1, 0x24($s5)
/* 8BB4 8002D7B4 AEE20000 */  sw        $v0, ($s7)
/* 8BB8 8002D7B8 240200C0 */  addiu     $v0, $zero, 0xc0
/* 8BBC 8002D7BC 8FAB0024 */  lw        $t3, 0x24($sp)
/* 8BC0 8002D7C0 3C04800A */  lui       $a0, %hi(D_8009A62C)
/* 8BC4 8002D7C4 8C84A62C */  lw        $a0, %lo(D_8009A62C)($a0)
/* 8BC8 8002D7C8 356B013F */  ori       $t3, $t3, 0x13f
/* 8BCC 8002D7CC AFAB0024 */  sw        $t3, 0x24($sp)
/* 8BD0 8002D7D0 AEA2007C */  sw        $v0, 0x7c($s5)
/* 8BD4 8002D7D4 26A20088 */  addiu     $v0, $s5, 0x88
/* 8BD8 8002D7D8 240B0002 */  addiu     $t3, $zero, 2
/* 8BDC 8002D7DC AEAF0078 */  sw        $t7, 0x78($s5)
/* 8BE0 8002D7E0 AEE20000 */  sw        $v0, ($s7)
/* 8BE4 8002D7E4 26A20090 */  addiu     $v0, $s5, 0x90
/* 8BE8 8002D7E8 AEB00080 */  sw        $s0, 0x80($s5)
/* 8BEC 8002D7EC AEAB0084 */  sw        $t3, 0x84($s5)
/* 8BF0 8002D7F0 AEE20000 */  sw        $v0, ($s7)
/* 8BF4 8002D7F4 26A20098 */  addiu     $v0, $s5, 0x98
/* 8BF8 8002D7F8 AEAB008C */  sw        $t3, 0x8c($s5)
/* 8BFC 8002D7FC 340BFFFE */  ori       $t3, $zero, 0xfffe
/* 8C00 8002D800 AEB10088 */  sw        $s1, 0x88($s5)
/* 8C04 8002D804 AEE20000 */  sw        $v0, ($s7)
/* 8C08 8002D808 26A200A0 */  addiu     $v0, $s5, 0xa0
/* 8C0C 8002D80C AEB20090 */  sw        $s2, 0x90($s5)
/* 8C10 8002D810 AEAB0094 */  sw        $t3, 0x94($s5)
/* 8C14 8002D814 AEE20000 */  sw        $v0, ($s7)
/* 8C18 8002D818 26A200A8 */  addiu     $v0, $s5, 0xa8
/* 8C1C 8002D81C AEB30098 */  sw        $s3, 0x98($s5)
/* 8C20 8002D820 AEAB009C */  sw        $t3, 0x9c($s5)
/* 8C24 8002D824 AEE20000 */  sw        $v0, ($s7)
/* 8C28 8002D828 8FAB0024 */  lw        $t3, 0x24($sp)
/* 8C2C 8002D82C 0C018798 */  jal       func_80061E60
/* 8C30 8002D830 AEAB00A0 */   sw       $t3, 0xa0($s5)
/* 8C34 8002D834 8EE40000 */  lw        $a0, ($s7)
/* 8C38 8002D838 AEA200A4 */  sw        $v0, 0xa4($s5)
/* 8C3C 8002D83C 0080102D */  daddu     $v0, $a0, $zero
/* 8C40 8002D840 3C0BE700 */  lui       $t3, 0xe700
/* 8C44 8002D844 AC4B0000 */  sw        $t3, ($v0)
/* 8C48 8002D848 AC400004 */  sw        $zero, 4($v0)
/* 8C4C 8002D84C 96C20000 */  lhu       $v0, ($s6)
/* 8C50 8002D850 24840008 */  addiu     $a0, $a0, 8
/* 8C54 8002D854 30420010 */  andi      $v0, $v0, 0x10
/* 8C58 8002D858 14400007 */  bnez      $v0, .L8002D878
/* 8C5C 8002D85C AEE40000 */   sw       $a0, ($s7)
/* 8C60 8002D860 3C02DB0E */  lui       $v0, 0xdb0e
/* 8C64 8002D864 AC820000 */  sw        $v0, ($a0)
/* 8C68 8002D868 96C30038 */  lhu       $v1, 0x38($s6)
/* 8C6C 8002D86C 24820008 */  addiu     $v0, $a0, 8
/* 8C70 8002D870 AEE20000 */  sw        $v0, ($s7)
/* 8C74 8002D874 AC830004 */  sw        $v1, 4($a0)
.L8002D878:
/* 8C78 8002D878 26C400D4 */  addiu     $a0, $s6, 0xd4
/* 8C7C 8002D87C 3C05800A */  lui       $a1, %hi(D_8009A614)
/* 8C80 8002D880 84A5A614 */  lh        $a1, %lo(D_8009A614)($a1)
/* 8C84 8002D884 3C02800A */  lui       $v0, %hi(D_8009A654)
/* 8C88 8002D888 8C42A654 */  lw        $v0, %lo(D_8009A654)($v0)
/* 8C8C 8002D88C 00052980 */  sll       $a1, $a1, 6
/* 8C90 8002D890 24A50030 */  addiu     $a1, $a1, 0x30
/* 8C94 8002D894 0C019D38 */  jal       func_800674E0
/* 8C98 8002D898 00452821 */   addu     $a1, $v0, $a1
/* 8C9C 8002D89C 3C05DA38 */  lui       $a1, 0xda38
/* 8CA0 8002D8A0 34A50007 */  ori       $a1, $a1, 7
/* 8CA4 8002D8A4 8EE20000 */  lw        $v0, ($s7)
/* 8CA8 8002D8A8 3C03800A */  lui       $v1, %hi(D_8009A614)
/* 8CAC 8002D8AC 8463A614 */  lh        $v1, %lo(D_8009A614)($v1)
/* 8CB0 8002D8B0 0040202D */  daddu     $a0, $v0, $zero
/* 8CB4 8002D8B4 24420008 */  addiu     $v0, $v0, 8
/* 8CB8 8002D8B8 00031980 */  sll       $v1, $v1, 6
/* 8CBC 8002D8BC AEE20000 */  sw        $v0, ($s7)
/* 8CC0 8002D8C0 3C02800A */  lui       $v0, %hi(D_8009A654)
/* 8CC4 8002D8C4 8C42A654 */  lw        $v0, %lo(D_8009A654)($v0)
/* 8CC8 8002D8C8 24630030 */  addiu     $v1, $v1, 0x30
/* 8CCC 8002D8CC AC850000 */  sw        $a1, ($a0)
/* 8CD0 8002D8D0 00431021 */  addu      $v0, $v0, $v1
/* 8CD4 8002D8D4 AC820004 */  sw        $v0, 4($a0)
/* 8CD8 8002D8D8 3C0A0001 */  lui       $t2, 1
.L8002D8DC:
/* 8CDC 8002D8DC 354A1230 */  ori       $t2, $t2, 0x1230
/* 8CE0 8002D8E0 3C098007 */  lui       $t1, %hi(D_800741D0)
/* 8CE4 8002D8E4 252941D0 */  addiu     $t1, $t1, %lo(D_800741D0)
/* 8CE8 8002D8E8 4406A000 */  mfc1      $a2, $f20
/* 8CEC 8002D8EC 95280000 */  lhu       $t0, ($t1)
/* 8CF0 8002D8F0 4407C000 */  mfc1      $a3, $f24
/* 8CF4 8002D8F4 3C03800A */  lui       $v1, %hi(D_8009A654)
/* 8CF8 8002D8F8 8C63A654 */  lw        $v1, %lo(D_8009A654)($v1)
/* 8CFC 8002D8FC C6C00084 */  lwc1      $f0, 0x84($s6)
/* 8D00 8002D900 3104FFFF */  andi      $a0, $t0, 0xffff
/* 8D04 8002D904 00042180 */  sll       $a0, $a0, 6
/* 8D08 8002D908 008A2021 */  addu      $a0, $a0, $t2
/* 8D0C 8002D90C 00642021 */  addu      $a0, $v1, $a0
/* 8D10 8002D910 3102FFFF */  andi      $v0, $t0, 0xffff
/* 8D14 8002D914 00021180 */  sll       $v0, $v0, 6
/* 8D18 8002D918 004A1021 */  addu      $v0, $v0, $t2
/* 8D1C 8002D91C 00621821 */  addu      $v1, $v1, $v0
/* 8D20 8002D920 46000007 */  neg.s     $f0, $f0
/* 8D24 8002D924 44050000 */  mfc1      $a1, $f0
/* 8D28 8002D928 25080001 */  addiu     $t0, $t0, 1
/* 8D2C 8002D92C AEC30204 */  sw        $v1, 0x204($s6)
/* 8D30 8002D930 A5280000 */  sh        $t0, ($t1)
/* 8D34 8002D934 0C019F18 */  jal       func_80067C60
/* 8D38 8002D938 E7B40010 */   swc1     $f20, 0x10($sp)
/* 8D3C 8002D93C 3C048007 */  lui       $a0, %hi(D_8007417C)
/* 8D40 8002D940 8C84417C */  lw        $a0, %lo(D_8007417C)($a0)
/* 8D44 8002D944 90820082 */  lbu       $v0, 0x82($a0)
/* 8D48 8002D948 96C300A8 */  lhu       $v1, 0xa8($s6)
/* 8D4C 8002D94C 00021600 */  sll       $v0, $v0, 0x18
/* 8D50 8002D950 00021603 */  sra       $v0, $v0, 0x18
/* 8D54 8002D954 00621821 */  addu      $v1, $v1, $v0
/* 8D58 8002D958 A6C300B8 */  sh        $v1, 0xb8($s6)
/* 8D5C 8002D95C 90830083 */  lbu       $v1, 0x83($a0)
/* 8D60 8002D960 96C200AA */  lhu       $v0, 0xaa($s6)
/* 8D64 8002D964 96C40000 */  lhu       $a0, ($s6)
/* 8D68 8002D968 00031E00 */  sll       $v1, $v1, 0x18
/* 8D6C 8002D96C 00031E03 */  sra       $v1, $v1, 0x18
/* 8D70 8002D970 00431021 */  addu      $v0, $v0, $v1
/* 8D74 8002D974 A6C200BA */  sh        $v0, 0xba($s6)
/* 8D78 8002D978 30820010 */  andi      $v0, $a0, 0x10
/* 8D7C 8002D97C 14400048 */  bnez      $v0, .L8002DAA0
/* 8D80 8002D980 24020003 */   addiu    $v0, $zero, 3
/* 8D84 8002D984 3C03800A */  lui       $v1, %hi(D_8009A614)
/* 8D88 8002D988 8463A614 */  lh        $v1, %lo(D_8009A614)($v1)
/* 8D8C 8002D98C 10620019 */  beq       $v1, $v0, .L8002D9F4
/* 8D90 8002D990 30820200 */   andi     $v0, $a0, 0x200
/* 8D94 8002D994 14400003 */  bnez      $v0, .L8002D9A4
/* 8D98 8002D998 00000000 */   nop
/* 8D9C 8002D99C 0C045431 */  jal       func_801150C4
/* 8DA0 8002D9A0 00000000 */   nop
.L8002D9A4:
/* 8DA4 8002D9A4 96C20000 */  lhu       $v0, ($s6)
/* 8DA8 8002D9A8 30420400 */  andi      $v0, $v0, 0x400
/* 8DAC 8002D9AC 14400003 */  bnez      $v0, .L8002D9BC
/* 8DB0 8002D9B0 00000000 */   nop
/* 8DB4 8002D9B4 0C046F68 */  jal       func_8011BDA0
/* 8DB8 8002D9B8 00000000 */   nop
.L8002D9BC:
/* 8DBC 8002D9BC 0C038446 */  jal       func_800E1118
/* 8DC0 8002D9C0 00000000 */   nop
/* 8DC4 8002D9C4 0C00E92C */  jal       func_8003A4B0
/* 8DC8 8002D9C8 00000000 */   nop
/* 8DCC 8002D9CC 0C04A1A0 */  jal       func_80128680
/* 8DD0 8002D9D0 00000000 */   nop
/* 8DD4 8002D9D4 0C0166E9 */  jal       func_80059BA4
/* 8DD8 8002D9D8 00000000 */   nop
/* 8DDC 8002D9DC 0C048AF2 */  jal       func_80122BC8
/* 8DE0 8002D9E0 00000000 */   nop
/* 8DE4 8002D9E4 0C0521D9 */  jal       func_80148764
/* 8DE8 8002D9E8 00000000 */   nop
/* 8DEC 8002D9EC 0800B6AC */  j         .L8002DAB0
/* 8DF0 8002D9F0 00000000 */   nop
.L8002D9F4:
/* 8DF4 8002D9F4 26D000D4 */  addiu     $s0, $s6, 0xd4
/* 8DF8 8002D9F8 4405A000 */  mfc1      $a1, $f20
/* 8DFC 8002D9FC 3C0643A0 */  lui       $a2, 0x43a0
/* 8E00 8002DA00 3C07C370 */  lui       $a3, 0xc370
/* 8E04 8002DA04 3C01C47A */  lui       $at, 0xc47a
/* 8E08 8002DA08 44810000 */  mtc1      $at, $f0
/* 8E0C 8002DA0C 3C01447A */  lui       $at, 0x447a
/* 8E10 8002DA10 44811000 */  mtc1      $at, $f2
/* 8E14 8002DA14 0200202D */  daddu     $a0, $s0, $zero
/* 8E18 8002DA18 E7B40010 */  swc1      $f20, 0x10($sp)
/* 8E1C 8002DA1C E7B8001C */  swc1      $f24, 0x1c($sp)
/* 8E20 8002DA20 E7A00014 */  swc1      $f0, 0x14($sp)
/* 8E24 8002DA24 0C018E38 */  jal       func_800638E0
/* 8E28 8002DA28 E7A20018 */   swc1     $f2, 0x18($sp)
/* 8E2C 8002DA2C 0200202D */  daddu     $a0, $s0, $zero
/* 8E30 8002DA30 3C05800A */  lui       $a1, %hi(D_8009A614)
/* 8E34 8002DA34 84A5A614 */  lh        $a1, %lo(D_8009A614)($a1)
/* 8E38 8002DA38 3C02800A */  lui       $v0, %hi(D_8009A654)
/* 8E3C 8002DA3C 8C42A654 */  lw        $v0, %lo(D_8009A654)($v0)
/* 8E40 8002DA40 00052980 */  sll       $a1, $a1, 6
/* 8E44 8002DA44 24A50030 */  addiu     $a1, $a1, 0x30
/* 8E48 8002DA48 0C019D38 */  jal       func_800674E0
/* 8E4C 8002DA4C 00452821 */   addu     $a1, $v0, $a1
/* 8E50 8002DA50 3C05DA38 */  lui       $a1, 0xda38
/* 8E54 8002DA54 34A50007 */  ori       $a1, $a1, 7
/* 8E58 8002DA58 8EE20000 */  lw        $v0, ($s7)
/* 8E5C 8002DA5C 3C03800A */  lui       $v1, %hi(D_8009A614)
/* 8E60 8002DA60 8463A614 */  lh        $v1, %lo(D_8009A614)($v1)
/* 8E64 8002DA64 0040202D */  daddu     $a0, $v0, $zero
/* 8E68 8002DA68 24420008 */  addiu     $v0, $v0, 8
/* 8E6C 8002DA6C 00031980 */  sll       $v1, $v1, 6
/* 8E70 8002DA70 AEE20000 */  sw        $v0, ($s7)
/* 8E74 8002DA74 3C02800A */  lui       $v0, %hi(D_8009A654)
/* 8E78 8002DA78 8C42A654 */  lw        $v0, %lo(D_8009A654)($v0)
/* 8E7C 8002DA7C 24630030 */  addiu     $v1, $v1, 0x30
/* 8E80 8002DA80 AC850000 */  sw        $a1, ($a0)
/* 8E84 8002DA84 00431021 */  addu      $v0, $v0, $v1
/* 8E88 8002DA88 0C0521D9 */  jal       func_80148764
/* 8E8C 8002DA8C AC820004 */   sw       $v0, 4($a0)
/* 8E90 8002DA90 0C04DFF1 */  jal       func_80137FC4
/* 8E94 8002DA94 00000000 */   nop
/* 8E98 8002DA98 0800B6AC */  j         .L8002DAB0
/* 8E9C 8002DA9C 00000000 */   nop
.L8002DAA0:
/* 8EA0 8002DAA0 0C04A1A0 */  jal       func_80128680
/* 8EA4 8002DAA4 00000000 */   nop
/* 8EA8 8002DAA8 0C048AF2 */  jal       func_80122BC8
/* 8EAC 8002DAAC 00000000 */   nop
.L8002DAB0:
/* 8EB0 8002DAB0 8EC20200 */  lw        $v0, 0x200($s6)
/* 8EB4 8002DAB4 10400004 */  beqz      $v0, .L8002DAC8
/* 8EB8 8002DAB8 3C03FF10 */   lui      $v1, 0xff10
/* 8EBC 8002DABC 0040F809 */  jalr      $v0
/* 8EC0 8002DAC0 02C0202D */   daddu    $a0, $s6, $zero
/* 8EC4 8002DAC4 3C03FF10 */  lui       $v1, 0xff10
.L8002DAC8:
/* 8EC8 8002DAC8 3463013F */  ori       $v1, $v1, 0x13f
/* 8ECC 8002DACC 8EF00000 */  lw        $s0, ($s7)
/* 8ED0 8002DAD0 3C04800A */  lui       $a0, %hi(D_8009A62C)
/* 8ED4 8002DAD4 8C84A62C */  lw        $a0, %lo(D_8009A62C)($a0)
/* 8ED8 8002DAD8 0200102D */  daddu     $v0, $s0, $zero
/* 8EDC 8002DADC 26100008 */  addiu     $s0, $s0, 8
/* 8EE0 8002DAE0 3C0BE700 */  lui       $t3, 0xe700
/* 8EE4 8002DAE4 AEF00000 */  sw        $s0, ($s7)
/* 8EE8 8002DAE8 AC4B0000 */  sw        $t3, ($v0)
/* 8EEC 8002DAEC AC400004 */  sw        $zero, 4($v0)
/* 8EF0 8002DAF0 26020008 */  addiu     $v0, $s0, 8
/* 8EF4 8002DAF4 AEE20000 */  sw        $v0, ($s7)
/* 8EF8 8002DAF8 0C018798 */  jal       func_80061E60
/* 8EFC 8002DAFC AE030000 */   sw       $v1, ($s0)
/* 8F00 8002DB00 8EE30000 */  lw        $v1, ($s7)
/* 8F04 8002DB04 AE020004 */  sw        $v0, 4($s0)
/* 8F08 8002DB08 0060102D */  daddu     $v0, $v1, $zero
/* 8F0C 8002DB0C 24630008 */  addiu     $v1, $v1, 8
/* 8F10 8002DB10 3C0BE700 */  lui       $t3, %hi(D_E7000001)
/* 8F14 8002DB14 AEE30000 */  sw        $v1, ($s7)
/* 8F18 8002DB18 AC4B0000 */  sw        $t3, ($v0)
/* 8F1C 8002DB1C AC400004 */  sw        $zero, 4($v0)
.L8002DB20:
/* 8F20 8002DB20 8FAB0020 */  lw        $t3, 0x20($sp)
/* 8F24 8002DB24 256B0001 */  addiu     $t3, $t3, %lo(D_E7000001)
/* 8F28 8002DB28 AFAB0020 */  sw        $t3, 0x20($sp)
/* 8F2C 8002DB2C 8FAB0070 */  lw        $t3, 0x70($sp)
/* 8F30 8002DB30 24020004 */  addiu     $v0, $zero, 4
/* 8F34 8002DB34 004B1023 */  subu      $v0, $v0, $t3
/* 8F38 8002DB38 8FAB0020 */  lw        $t3, 0x20($sp)
/* 8F3C 8002DB3C 0162102A */  slt       $v0, $t3, $v0
/* 8F40 8002DB40 1440FE55 */  bnez      $v0, .L8002D498
/* 8F44 8002DB44 26D60558 */   addiu    $s6, $s6, 0x558
.L8002DB48:
/* 8F48 8002DB48 8FBF0054 */  lw        $ra, 0x54($sp)
/* 8F4C 8002DB4C 8FBE0050 */  lw        $fp, 0x50($sp)
/* 8F50 8002DB50 8FB7004C */  lw        $s7, 0x4c($sp)
/* 8F54 8002DB54 8FB60048 */  lw        $s6, 0x48($sp)
/* 8F58 8002DB58 8FB50044 */  lw        $s5, 0x44($sp)
/* 8F5C 8002DB5C 8FB40040 */  lw        $s4, 0x40($sp)
/* 8F60 8002DB60 8FB3003C */  lw        $s3, 0x3c($sp)
/* 8F64 8002DB64 8FB20038 */  lw        $s2, 0x38($sp)
/* 8F68 8002DB68 8FB10034 */  lw        $s1, 0x34($sp)
/* 8F6C 8002DB6C 8FB00030 */  lw        $s0, 0x30($sp)
/* 8F70 8002DB70 D7B80068 */  ldc1      $f24, 0x68($sp)
/* 8F74 8002DB74 D7B60060 */  ldc1      $f22, 0x60($sp)
/* 8F78 8002DB78 D7B40058 */  ldc1      $f20, 0x58($sp)
/* 8F7C 8002DB7C 03E00008 */  jr        $ra
/* 8F80 8002DB80 27BD0070 */   addiu    $sp, $sp, 0x70
