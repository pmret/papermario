.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404B0_CB96B0
/* CB96B0 802404B0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* CB96B4 802404B4 AFB60040 */  sw        $s6, 0x40($sp)
/* CB96B8 802404B8 0080B02D */  daddu     $s6, $a0, $zero
/* CB96BC 802404BC 3C028024 */  lui       $v0, %hi(D_80244070_CBD270)
/* CB96C0 802404C0 24424070 */  addiu     $v0, $v0, %lo(D_80244070_CBD270)
/* CB96C4 802404C4 AFBF004C */  sw        $ra, 0x4c($sp)
/* CB96C8 802404C8 AFBE0048 */  sw        $fp, 0x48($sp)
/* CB96CC 802404CC AFB70044 */  sw        $s7, 0x44($sp)
/* CB96D0 802404D0 AFB5003C */  sw        $s5, 0x3c($sp)
/* CB96D4 802404D4 AFB40038 */  sw        $s4, 0x38($sp)
/* CB96D8 802404D8 AFB30034 */  sw        $s3, 0x34($sp)
/* CB96DC 802404DC AFB20030 */  sw        $s2, 0x30($sp)
/* CB96E0 802404E0 AFB1002C */  sw        $s1, 0x2c($sp)
/* CB96E4 802404E4 AFB00028 */  sw        $s0, 0x28($sp)
/* CB96E8 802404E8 AFA50054 */  sw        $a1, 0x54($sp)
/* CB96EC 802404EC 8C430000 */  lw        $v1, ($v0)
/* CB96F0 802404F0 00C0A02D */  daddu     $s4, $a2, $zero
/* CB96F4 802404F4 24630005 */  addiu     $v1, $v1, 5
/* CB96F8 802404F8 AC430000 */  sw        $v1, ($v0)
/* CB96FC 802404FC 02D4102A */  slt       $v0, $s6, $s4
/* CB9700 80240500 10400159 */  beqz      $v0, .L80240A68
/* CB9704 80240504 00000000 */   nop
/* CB9708 80240508 8FAA0054 */  lw        $t2, 0x54($sp)
/* CB970C 8024050C 0147102A */  slt       $v0, $t2, $a3
/* CB9710 80240510 10400155 */  beqz      $v0, .L80240A68
/* CB9714 80240514 00000000 */   nop
/* CB9718 80240518 06C20002 */  bltzl     $s6, .L80240524
/* CB971C 8024051C 0000B02D */   daddu    $s6, $zero, $zero
/* CB9720 80240520 8FAA0054 */  lw        $t2, 0x54($sp)
.L80240524:
/* CB9724 80240524 05420001 */  bltzl     $t2, .L8024052C
/* CB9728 80240528 AFA00054 */   sw       $zero, 0x54($sp)
.L8024052C:
/* CB972C 8024052C 06820001 */  bltzl     $s4, .L80240534
/* CB9730 80240530 0000A02D */   daddu    $s4, $zero, $zero
.L80240534:
/* CB9734 80240534 04E20001 */  bltzl     $a3, .L8024053C
/* CB9738 80240538 0000382D */   daddu    $a3, $zero, $zero
.L8024053C:
/* CB973C 8024053C 2AC20140 */  slti      $v0, $s6, 0x140
/* CB9740 80240540 50400001 */  beql      $v0, $zero, .L80240548
/* CB9744 80240544 2416013F */   addiu    $s6, $zero, 0x13f
.L80240548:
/* CB9748 80240548 8FAA0054 */  lw        $t2, 0x54($sp)
/* CB974C 8024054C 294200F0 */  slti      $v0, $t2, 0xf0
/* CB9750 80240550 14400003 */  bnez      $v0, .L80240560
/* CB9754 80240554 2A820140 */   slti     $v0, $s4, 0x140
/* CB9758 80240558 240A00EF */  addiu     $t2, $zero, 0xef
/* CB975C 8024055C AFAA0054 */  sw        $t2, 0x54($sp)
.L80240560:
/* CB9760 80240560 50400001 */  beql      $v0, $zero, .L80240568
/* CB9764 80240564 2414013F */   addiu    $s4, $zero, 0x13f
.L80240568:
/* CB9768 80240568 28E200F0 */  slti      $v0, $a3, 0xf0
/* CB976C 8024056C 50400001 */  beql      $v0, $zero, .L80240574
/* CB9770 80240570 240700EF */   addiu    $a3, $zero, 0xef
.L80240574:
/* CB9774 80240574 12D4013C */  beq       $s6, $s4, .L80240A68
/* CB9778 80240578 00000000 */   nop
/* CB977C 8024057C 8FAA0054 */  lw        $t2, 0x54($sp)
/* CB9780 80240580 11470139 */  beq       $t2, $a3, .L80240A68
/* CB9784 80240584 00000000 */   nop
/* CB9788 80240588 06C10002 */  bgez      $s6, .L80240594
/* CB978C 8024058C 02C0102D */   daddu    $v0, $s6, $zero
/* CB9790 80240590 26C20003 */  addiu     $v0, $s6, 3
.L80240594:
/* CB9794 80240594 00021083 */  sra       $v0, $v0, 2
/* CB9798 80240598 0002B080 */  sll       $s6, $v0, 2
/* CB979C 8024059C 06810002 */  bgez      $s4, .L802405A8
/* CB97A0 802405A0 0280102D */   daddu    $v0, $s4, $zero
/* CB97A4 802405A4 26820003 */  addiu     $v0, $s4, 3
.L802405A8:
/* CB97A8 802405A8 3C042AAA */  lui       $a0, 0x2aaa
/* CB97AC 802405AC 3484AAAB */  ori       $a0, $a0, 0xaaab
/* CB97B0 802405B0 8FAA0054 */  lw        $t2, 0x54($sp)
/* CB97B4 802405B4 00021083 */  sra       $v0, $v0, 2
/* CB97B8 802405B8 00EA1823 */  subu      $v1, $a3, $t2
/* CB97BC 802405BC 00640018 */  mult      $v1, $a0
/* CB97C0 802405C0 00021080 */  sll       $v0, $v0, 2
/* CB97C4 802405C4 24540004 */  addiu     $s4, $v0, 4
/* CB97C8 802405C8 0000F02D */  daddu     $fp, $zero, $zero
/* CB97CC 802405CC 000317C3 */  sra       $v0, $v1, 0x1f
/* CB97D0 802405D0 00005010 */  mfhi      $t2
/* CB97D4 802405D4 01425023 */  subu      $t2, $t2, $v0
/* CB97D8 802405D8 000A1040 */  sll       $v0, $t2, 1
/* CB97DC 802405DC 004A1021 */  addu      $v0, $v0, $t2
/* CB97E0 802405E0 AFAA0014 */  sw        $t2, 0x14($sp)
/* CB97E4 802405E4 AFAA0010 */  sw        $t2, 0x10($sp)
/* CB97E8 802405E8 3C0A800A */  lui       $t2, %hi(D_8009A64C)
/* CB97EC 802405EC 8D4AA64C */  lw        $t2, %lo(D_8009A64C)($t2)
/* CB97F0 802405F0 00021040 */  sll       $v0, $v0, 1
/* CB97F4 802405F4 AFAA0018 */  sw        $t2, 0x18($sp)
/* CB97F8 802405F8 8FAA0010 */  lw        $t2, 0x10($sp)
/* CB97FC 802405FC 00621823 */  subu      $v1, $v1, $v0
/* CB9800 80240600 19400097 */  blez      $t2, .L80240860
/* CB9804 80240604 AFA30014 */   sw       $v1, 0x14($sp)
/* CB9808 80240608 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* CB980C 8024060C 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* CB9810 80240610 02961023 */  subu      $v0, $s4, $s6
/* CB9814 80240614 00021040 */  sll       $v0, $v0, 1
/* CB9818 80240618 24420007 */  addiu     $v0, $v0, 7
/* CB981C 8024061C 000210C3 */  sra       $v0, $v0, 3
/* CB9820 80240620 304201FF */  andi      $v0, $v0, 0x1ff
/* CB9824 80240624 00021240 */  sll       $v0, $v0, 9
/* CB9828 80240628 3C03F510 */  lui       $v1, 0xf510
/* CB982C 8024062C 8FB70054 */  lw        $s7, 0x54($sp)
/* CB9830 80240630 00431025 */  or        $v0, $v0, $v1
/* CB9834 80240634 AFA2001C */  sw        $v0, 0x1c($sp)
/* CB9838 80240638 AFA00020 */  sw        $zero, 0x20($sp)
/* CB983C 8024063C 02E0A82D */  daddu     $s5, $s7, $zero
.L80240640:
/* CB9840 80240640 26B2FFFA */  addiu     $s2, $s5, -6
/* CB9844 80240644 0640007D */  bltz      $s2, .L8024083C
/* CB9848 80240648 00123040 */   sll      $a2, $s2, 1
/* CB984C 8024064C 28C20100 */  slti      $v0, $a2, 0x100
/* CB9850 80240650 50400001 */  beql      $v0, $zero, .L80240658
/* CB9854 80240654 240600FF */   addiu    $a2, $zero, 0xff
.L80240658:
/* CB9858 80240658 3C05FD10 */  lui       $a1, 0xfd10
/* CB985C 8024065C 34A5013F */  ori       $a1, $a1, 0x13f
/* CB9860 80240660 3C02FA00 */  lui       $v0, 0xfa00
/* CB9864 80240664 8E700000 */  lw        $s0, ($s3)
/* CB9868 80240668 8FA40018 */  lw        $a0, 0x18($sp)
/* CB986C 8024066C 0200182D */  daddu     $v1, $s0, $zero
/* CB9870 80240670 26100008 */  addiu     $s0, $s0, 8
/* CB9874 80240674 AE700000 */  sw        $s0, ($s3)
/* CB9878 80240678 AC620000 */  sw        $v0, ($v1)
/* CB987C 8024067C 2402FF00 */  addiu     $v0, $zero, -0x100
/* CB9880 80240680 00C21025 */  or        $v0, $a2, $v0
/* CB9884 80240684 AC620004 */  sw        $v0, 4($v1)
/* CB9888 80240688 26020008 */  addiu     $v0, $s0, 8
/* CB988C 8024068C AE620000 */  sw        $v0, ($s3)
/* CB9890 80240690 0C0187A4 */  jal       osVirtualToPhysical
/* CB9894 80240694 AE050000 */   sw       $a1, ($s0)
/* CB9898 80240698 3C030700 */  lui       $v1, 0x700
/* CB989C 8024069C 34630090 */  ori       $v1, $v1, 0x90
/* CB98A0 802406A0 00163080 */  sll       $a2, $s6, 2
/* CB98A4 802406A4 30C60FFF */  andi      $a2, $a2, 0xfff
/* CB98A8 802406A8 00063300 */  sll       $a2, $a2, 0xc
/* CB98AC 802406AC 00122080 */  sll       $a0, $s2, 2
/* CB98B0 802406B0 30840FFF */  andi      $a0, $a0, 0xfff
/* CB98B4 802406B4 26A5FFFF */  addiu     $a1, $s5, -1
/* CB98B8 802406B8 8E710000 */  lw        $s1, ($s3)
/* CB98BC 802406BC 00052880 */  sll       $a1, $a1, 2
/* CB98C0 802406C0 AE020004 */  sw        $v0, 4($s0)
/* CB98C4 802406C4 0220102D */  daddu     $v0, $s1, $zero
/* CB98C8 802406C8 26310008 */  addiu     $s1, $s1, 8
/* CB98CC 802406CC AE710000 */  sw        $s1, ($s3)
/* CB98D0 802406D0 8FAA001C */  lw        $t2, 0x1c($sp)
/* CB98D4 802406D4 30A50FFF */  andi      $a1, $a1, 0xfff
/* CB98D8 802406D8 AC430004 */  sw        $v1, 4($v0)
/* CB98DC 802406DC 2683FFFF */  addiu     $v1, $s4, -1
/* CB98E0 802406E0 00031880 */  sll       $v1, $v1, 2
/* CB98E4 802406E4 30630FFF */  andi      $v1, $v1, 0xfff
/* CB98E8 802406E8 00031B00 */  sll       $v1, $v1, 0xc
/* CB98EC 802406EC AC4A0000 */  sw        $t2, ($v0)
/* CB98F0 802406F0 26220008 */  addiu     $v0, $s1, 8
/* CB98F4 802406F4 AE620000 */  sw        $v0, ($s3)
/* CB98F8 802406F8 3C02E600 */  lui       $v0, 0xe600
/* CB98FC 802406FC AE220000 */  sw        $v0, ($s1)
/* CB9900 80240700 26220010 */  addiu     $v0, $s1, 0x10
/* CB9904 80240704 AE200004 */  sw        $zero, 4($s1)
/* CB9908 80240708 AE620000 */  sw        $v0, ($s3)
/* CB990C 8024070C 3C02F400 */  lui       $v0, 0xf400
/* CB9910 80240710 00821025 */  or        $v0, $a0, $v0
/* CB9914 80240714 00C21025 */  or        $v0, $a2, $v0
/* CB9918 80240718 AE220008 */  sw        $v0, 8($s1)
/* CB991C 8024071C 3C020700 */  lui       $v0, 0x700
/* CB9920 80240720 00A21025 */  or        $v0, $a1, $v0
/* CB9924 80240724 00621025 */  or        $v0, $v1, $v0
/* CB9928 80240728 AE22000C */  sw        $v0, 0xc($s1)
/* CB992C 8024072C 26220018 */  addiu     $v0, $s1, 0x18
/* CB9930 80240730 AE620000 */  sw        $v0, ($s3)
/* CB9934 80240734 3C02E700 */  lui       $v0, 0xe700
/* CB9938 80240738 AE220010 */  sw        $v0, 0x10($s1)
/* CB993C 8024073C 26220020 */  addiu     $v0, $s1, 0x20
/* CB9940 80240740 AE200014 */  sw        $zero, 0x14($s1)
/* CB9944 80240744 AE620000 */  sw        $v0, ($s3)
/* CB9948 80240748 24020090 */  addiu     $v0, $zero, 0x90
/* CB994C 8024074C AE22001C */  sw        $v0, 0x1c($s1)
/* CB9950 80240750 26220028 */  addiu     $v0, $s1, 0x28
/* CB9954 80240754 AE2A0018 */  sw        $t2, 0x18($s1)
/* CB9958 80240758 AE620000 */  sw        $v0, ($s3)
/* CB995C 8024075C 3C02F200 */  lui       $v0, 0xf200
/* CB9960 80240760 00822025 */  or        $a0, $a0, $v0
/* CB9964 80240764 00C42025 */  or        $a0, $a2, $a0
/* CB9968 80240768 00651825 */  or        $v1, $v1, $a1
/* CB996C 8024076C 26220030 */  addiu     $v0, $s1, 0x30
/* CB9970 80240770 AE240020 */  sw        $a0, 0x20($s1)
/* CB9974 80240774 00142080 */  sll       $a0, $s4, 2
/* CB9978 80240778 30840FFF */  andi      $a0, $a0, 0xfff
/* CB997C 8024077C 00042300 */  sll       $a0, $a0, 0xc
/* CB9980 80240780 AE230024 */  sw        $v1, 0x24($s1)
/* CB9984 80240784 AE620000 */  sw        $v0, ($s3)
/* CB9988 80240788 26E20006 */  addiu     $v0, $s7, 6
/* CB998C 8024078C 00021080 */  sll       $v0, $v0, 2
/* CB9990 80240790 30420FFF */  andi      $v0, $v0, 0xfff
/* CB9994 80240794 3C03E400 */  lui       $v1, 0xe400
/* CB9998 80240798 00431025 */  or        $v0, $v0, $v1
/* CB999C 8024079C 00822025 */  or        $a0, $a0, $v0
/* CB99A0 802407A0 00171080 */  sll       $v0, $s7, 2
/* CB99A4 802407A4 30420FFF */  andi      $v0, $v0, 0xfff
/* CB99A8 802407A8 00C23025 */  or        $a2, $a2, $v0
/* CB99AC 802407AC 26220038 */  addiu     $v0, $s1, 0x38
/* CB99B0 802407B0 AE240028 */  sw        $a0, 0x28($s1)
/* CB99B4 802407B4 AE26002C */  sw        $a2, 0x2c($s1)
/* CB99B8 802407B8 AE620000 */  sw        $v0, ($s3)
/* CB99BC 802407BC 3C02E100 */  lui       $v0, 0xe100
/* CB99C0 802407C0 00161D40 */  sll       $v1, $s6, 0x15
/* CB99C4 802407C4 AE220030 */  sw        $v0, 0x30($s1)
/* CB99C8 802407C8 00151140 */  sll       $v0, $s5, 5
/* CB99CC 802407CC 3042FFFF */  andi      $v0, $v0, 0xffff
/* CB99D0 802407D0 00621825 */  or        $v1, $v1, $v0
/* CB99D4 802407D4 26220040 */  addiu     $v0, $s1, 0x40
/* CB99D8 802407D8 AE230034 */  sw        $v1, 0x34($s1)
/* CB99DC 802407DC AE620000 */  sw        $v0, ($s3)
/* CB99E0 802407E0 3C038024 */  lui       $v1, %hi(D_80244070_CBD270)
/* CB99E4 802407E4 8C634070 */  lw        $v1, %lo(D_80244070_CBD270)($v1)
/* CB99E8 802407E8 3C02F100 */  lui       $v0, 0xf100
/* CB99EC 802407EC AE220038 */  sw        $v0, 0x38($s1)
/* CB99F0 802407F0 8FAA0020 */  lw        $t2, 0x20($sp)
/* CB99F4 802407F4 006A1821 */  addu      $v1, $v1, $t2
/* CB99F8 802407F8 44836000 */  mtc1      $v1, $f12
/* CB99FC 802407FC 00000000 */  nop
/* CB9A00 80240800 0C00A8BB */  jal       sin_deg
/* CB9A04 80240804 46806320 */   cvt.s.w  $f12, $f12
/* CB9A08 80240808 3C0143FA */  lui       $at, 0x43fa
/* CB9A0C 8024080C 44811000 */  mtc1      $at, $f2
/* CB9A10 80240810 00000000 */  nop
/* CB9A14 80240814 46020002 */  mul.s     $f0, $f0, $f2
/* CB9A18 80240818 00000000 */  nop
/* CB9A1C 8024081C 3C030400 */  lui       $v1, 0x400
/* CB9A20 80240820 4600010D */  trunc.w.s $f4, $f0
/* CB9A24 80240824 44022000 */  mfc1      $v0, $f4
/* CB9A28 80240828 00000000 */  nop
/* CB9A2C 8024082C 2442FE0C */  addiu     $v0, $v0, -0x1f4
/* CB9A30 80240830 3042FFFF */  andi      $v0, $v0, 0xffff
/* CB9A34 80240834 00431025 */  or        $v0, $v0, $v1
/* CB9A38 80240838 AE22003C */  sw        $v0, 0x3c($s1)
.L8024083C:
/* CB9A3C 8024083C 26F70006 */  addiu     $s7, $s7, 6
/* CB9A40 80240840 8FAA0020 */  lw        $t2, 0x20($sp)
/* CB9A44 80240844 254A001E */  addiu     $t2, $t2, 0x1e
/* CB9A48 80240848 AFAA0020 */  sw        $t2, 0x20($sp)
/* CB9A4C 8024084C 8FAA0010 */  lw        $t2, 0x10($sp)
/* CB9A50 80240850 27DE0001 */  addiu     $fp, $fp, 1
/* CB9A54 80240854 03CA102A */  slt       $v0, $fp, $t2
/* CB9A58 80240858 1440FF79 */  bnez      $v0, .L80240640
/* CB9A5C 8024085C 26B5FFFA */   addiu    $s5, $s5, -6
.L80240860:
/* CB9A60 80240860 8FAA0014 */  lw        $t2, 0x14($sp)
/* CB9A64 80240864 11400080 */  beqz      $t2, .L80240A68
/* CB9A68 80240868 001E1040 */   sll      $v0, $fp, 1
/* CB9A6C 8024086C 005E1021 */  addu      $v0, $v0, $fp
/* CB9A70 80240870 8FAA0054 */  lw        $t2, 0x54($sp)
/* CB9A74 80240874 00029840 */  sll       $s3, $v0, 1
/* CB9A78 80240878 01539023 */  subu      $s2, $t2, $s3
/* CB9A7C 8024087C 2642FFFA */  addiu     $v0, $s2, -6
/* CB9A80 80240880 04400079 */  bltz      $v0, .L80240A68
/* CB9A84 80240884 00023040 */   sll      $a2, $v0, 1
/* CB9A88 80240888 28C20100 */  slti      $v0, $a2, 0x100
/* CB9A8C 8024088C 50400001 */  beql      $v0, $zero, .L80240894
/* CB9A90 80240890 240600FF */   addiu    $a2, $zero, 0xff
.L80240894:
/* CB9A94 80240894 3C05FD10 */  lui       $a1, 0xfd10
/* CB9A98 80240898 34A5013F */  ori       $a1, $a1, 0x13f
/* CB9A9C 8024089C 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* CB9AA0 802408A0 2631A66C */  addiu     $s1, $s1, %lo(gMasterGfxPos)
/* CB9AA4 802408A4 3C02FA00 */  lui       $v0, 0xfa00
/* CB9AA8 802408A8 8E300000 */  lw        $s0, ($s1)
/* CB9AAC 802408AC 8FA40018 */  lw        $a0, 0x18($sp)
/* CB9AB0 802408B0 0200182D */  daddu     $v1, $s0, $zero
/* CB9AB4 802408B4 26100008 */  addiu     $s0, $s0, 8
/* CB9AB8 802408B8 AE300000 */  sw        $s0, ($s1)
/* CB9ABC 802408BC AC620000 */  sw        $v0, ($v1)
/* CB9AC0 802408C0 2402FF00 */  addiu     $v0, $zero, -0x100
/* CB9AC4 802408C4 00C21025 */  or        $v0, $a2, $v0
/* CB9AC8 802408C8 AC620004 */  sw        $v0, 4($v1)
/* CB9ACC 802408CC 26020008 */  addiu     $v0, $s0, 8
/* CB9AD0 802408D0 AE220000 */  sw        $v0, ($s1)
/* CB9AD4 802408D4 0C0187A4 */  jal       osVirtualToPhysical
/* CB9AD8 802408D8 AE050000 */   sw       $a1, ($s0)
/* CB9ADC 802408DC 3C050700 */  lui       $a1, 0x700
/* CB9AE0 802408E0 34A50090 */  ori       $a1, $a1, 0x90
/* CB9AE4 802408E4 3C090400 */  lui       $t1, 0x400
/* CB9AE8 802408E8 3529FC00 */  ori       $t1, $t1, 0xfc00
/* CB9AEC 802408EC 02962023 */  subu      $a0, $s4, $s6
/* CB9AF0 802408F0 00042040 */  sll       $a0, $a0, 1
/* CB9AF4 802408F4 24840007 */  addiu     $a0, $a0, 7
/* CB9AF8 802408F8 000420C3 */  sra       $a0, $a0, 3
/* CB9AFC 802408FC 308401FF */  andi      $a0, $a0, 0x1ff
/* CB9B00 80240900 8E260000 */  lw        $a2, ($s1)
/* CB9B04 80240904 00042240 */  sll       $a0, $a0, 9
/* CB9B08 80240908 AE020004 */  sw        $v0, 4($s0)
/* CB9B0C 8024090C 3C02F510 */  lui       $v0, 0xf510
/* CB9B10 80240910 00822025 */  or        $a0, $a0, $v0
/* CB9B14 80240914 00164080 */  sll       $t0, $s6, 2
/* CB9B18 80240918 31080FFF */  andi      $t0, $t0, 0xfff
/* CB9B1C 8024091C 00084300 */  sll       $t0, $t0, 0xc
/* CB9B20 80240920 2647FFFF */  addiu     $a3, $s2, -1
/* CB9B24 80240924 00073880 */  sll       $a3, $a3, 2
/* CB9B28 80240928 30E70FFF */  andi      $a3, $a3, 0xfff
/* CB9B2C 8024092C 00C0182D */  daddu     $v1, $a2, $zero
/* CB9B30 80240930 24C60008 */  addiu     $a2, $a2, 8
/* CB9B34 80240934 24C20008 */  addiu     $v0, $a2, 8
/* CB9B38 80240938 AE260000 */  sw        $a2, ($s1)
/* CB9B3C 8024093C AC640000 */  sw        $a0, ($v1)
/* CB9B40 80240940 AC650004 */  sw        $a1, 4($v1)
/* CB9B44 80240944 AE220000 */  sw        $v0, ($s1)
/* CB9B48 80240948 3C02E600 */  lui       $v0, 0xe600
/* CB9B4C 8024094C ACC20000 */  sw        $v0, ($a2)
/* CB9B50 80240950 24C20010 */  addiu     $v0, $a2, 0x10
/* CB9B54 80240954 ACC00004 */  sw        $zero, 4($a2)
/* CB9B58 80240958 AE220000 */  sw        $v0, ($s1)
/* CB9B5C 8024095C 3C02F400 */  lui       $v0, 0xf400
/* CB9B60 80240960 2683FFFF */  addiu     $v1, $s4, -1
/* CB9B64 80240964 00031880 */  sll       $v1, $v1, 2
/* CB9B68 80240968 30630FFF */  andi      $v1, $v1, 0xfff
/* CB9B6C 8024096C 8FAA0014 */  lw        $t2, 0x14($sp)
/* CB9B70 80240970 00031B00 */  sll       $v1, $v1, 0xc
/* CB9B74 80240974 024A2823 */  subu      $a1, $s2, $t2
/* CB9B78 80240978 00052880 */  sll       $a1, $a1, 2
/* CB9B7C 8024097C 30A50FFF */  andi      $a1, $a1, 0xfff
/* CB9B80 80240980 00A21025 */  or        $v0, $a1, $v0
/* CB9B84 80240984 01021025 */  or        $v0, $t0, $v0
/* CB9B88 80240988 ACC20008 */  sw        $v0, 8($a2)
/* CB9B8C 8024098C 3C020700 */  lui       $v0, 0x700
/* CB9B90 80240990 00E21025 */  or        $v0, $a3, $v0
/* CB9B94 80240994 00621025 */  or        $v0, $v1, $v0
/* CB9B98 80240998 ACC2000C */  sw        $v0, 0xc($a2)
/* CB9B9C 8024099C 24C20018 */  addiu     $v0, $a2, 0x18
/* CB9BA0 802409A0 AE220000 */  sw        $v0, ($s1)
/* CB9BA4 802409A4 3C02E700 */  lui       $v0, 0xe700
/* CB9BA8 802409A8 ACC20010 */  sw        $v0, 0x10($a2)
/* CB9BAC 802409AC 24C20020 */  addiu     $v0, $a2, 0x20
/* CB9BB0 802409B0 ACC00014 */  sw        $zero, 0x14($a2)
/* CB9BB4 802409B4 AE220000 */  sw        $v0, ($s1)
/* CB9BB8 802409B8 24020090 */  addiu     $v0, $zero, 0x90
/* CB9BBC 802409BC ACC2001C */  sw        $v0, 0x1c($a2)
/* CB9BC0 802409C0 24C20028 */  addiu     $v0, $a2, 0x28
/* CB9BC4 802409C4 ACC40018 */  sw        $a0, 0x18($a2)
/* CB9BC8 802409C8 AE220000 */  sw        $v0, ($s1)
/* CB9BCC 802409CC 3C02F200 */  lui       $v0, 0xf200
/* CB9BD0 802409D0 00A22825 */  or        $a1, $a1, $v0
/* CB9BD4 802409D4 01052825 */  or        $a1, $t0, $a1
/* CB9BD8 802409D8 00671825 */  or        $v1, $v1, $a3
/* CB9BDC 802409DC 24C20030 */  addiu     $v0, $a2, 0x30
/* CB9BE0 802409E0 ACC30024 */  sw        $v1, 0x24($a2)
/* CB9BE4 802409E4 00141880 */  sll       $v1, $s4, 2
/* CB9BE8 802409E8 30630FFF */  andi      $v1, $v1, 0xfff
/* CB9BEC 802409EC ACC50020 */  sw        $a1, 0x20($a2)
/* CB9BF0 802409F0 AE220000 */  sw        $v0, ($s1)
/* CB9BF4 802409F4 8FAA0054 */  lw        $t2, 0x54($sp)
/* CB9BF8 802409F8 00031B00 */  sll       $v1, $v1, 0xc
/* CB9BFC 802409FC 01532821 */  addu      $a1, $t2, $s3
/* CB9C00 80240A00 8FAA0014 */  lw        $t2, 0x14($sp)
/* CB9C04 80240A04 3C04E400 */  lui       $a0, 0xe400
/* CB9C08 80240A08 00AA1021 */  addu      $v0, $a1, $t2
/* CB9C0C 80240A0C 00021080 */  sll       $v0, $v0, 2
/* CB9C10 80240A10 30420FFF */  andi      $v0, $v0, 0xfff
/* CB9C14 80240A14 00441025 */  or        $v0, $v0, $a0
/* CB9C18 80240A18 00621825 */  or        $v1, $v1, $v0
/* CB9C1C 80240A1C 00052880 */  sll       $a1, $a1, 2
/* CB9C20 80240A20 30A50FFF */  andi      $a1, $a1, 0xfff
/* CB9C24 80240A24 01054025 */  or        $t0, $t0, $a1
/* CB9C28 80240A28 24C20038 */  addiu     $v0, $a2, 0x38
/* CB9C2C 80240A2C ACC30028 */  sw        $v1, 0x28($a2)
/* CB9C30 80240A30 ACC8002C */  sw        $t0, 0x2c($a2)
/* CB9C34 80240A34 AE220000 */  sw        $v0, ($s1)
/* CB9C38 80240A38 3C02E100 */  lui       $v0, 0xe100
/* CB9C3C 80240A3C 00161D40 */  sll       $v1, $s6, 0x15
/* CB9C40 80240A40 ACC20030 */  sw        $v0, 0x30($a2)
/* CB9C44 80240A44 00121140 */  sll       $v0, $s2, 5
/* CB9C48 80240A48 3042FFFF */  andi      $v0, $v0, 0xffff
/* CB9C4C 80240A4C 00621825 */  or        $v1, $v1, $v0
/* CB9C50 80240A50 24C20040 */  addiu     $v0, $a2, 0x40
/* CB9C54 80240A54 ACC30034 */  sw        $v1, 0x34($a2)
/* CB9C58 80240A58 AE220000 */  sw        $v0, ($s1)
/* CB9C5C 80240A5C 3C02F100 */  lui       $v0, 0xf100
/* CB9C60 80240A60 ACC20038 */  sw        $v0, 0x38($a2)
/* CB9C64 80240A64 ACC9003C */  sw        $t1, 0x3c($a2)
.L80240A68:
/* CB9C68 80240A68 8FBF004C */  lw        $ra, 0x4c($sp)
/* CB9C6C 80240A6C 8FBE0048 */  lw        $fp, 0x48($sp)
/* CB9C70 80240A70 8FB70044 */  lw        $s7, 0x44($sp)
/* CB9C74 80240A74 8FB60040 */  lw        $s6, 0x40($sp)
/* CB9C78 80240A78 8FB5003C */  lw        $s5, 0x3c($sp)
/* CB9C7C 80240A7C 8FB40038 */  lw        $s4, 0x38($sp)
/* CB9C80 80240A80 8FB30034 */  lw        $s3, 0x34($sp)
/* CB9C84 80240A84 8FB20030 */  lw        $s2, 0x30($sp)
/* CB9C88 80240A88 8FB1002C */  lw        $s1, 0x2c($sp)
/* CB9C8C 80240A8C 8FB00028 */  lw        $s0, 0x28($sp)
/* CB9C90 80240A90 03E00008 */  jr        $ra
/* CB9C94 80240A94 27BD0050 */   addiu    $sp, $sp, 0x50
