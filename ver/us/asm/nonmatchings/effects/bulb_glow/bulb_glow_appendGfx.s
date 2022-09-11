.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel bulb_glow_appendGfx
/* 37A66C E007827C 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 37A670 E0078280 0080302D */  daddu     $a2, $a0, $zero
/* 37A674 E0078284 AFBF005C */  sw        $ra, 0x5c($sp)
/* 37A678 E0078288 AFBE0058 */  sw        $fp, 0x58($sp)
/* 37A67C E007828C AFB70054 */  sw        $s7, 0x54($sp)
/* 37A680 E0078290 AFB60050 */  sw        $s6, 0x50($sp)
/* 37A684 E0078294 AFB5004C */  sw        $s5, 0x4c($sp)
/* 37A688 E0078298 AFB40048 */  sw        $s4, 0x48($sp)
/* 37A68C E007829C AFB30044 */  sw        $s3, 0x44($sp)
/* 37A690 E00782A0 AFB20040 */  sw        $s2, 0x40($sp)
/* 37A694 E00782A4 AFB1003C */  sw        $s1, 0x3c($sp)
/* 37A698 E00782A8 AFB00038 */  sw        $s0, 0x38($sp)
/* 37A69C E00782AC 8CD0000C */  lw        $s0, 0xc($a2)
/* 37A6A0 E00782B0 8E140010 */  lw        $s4, 0x10($s0)
/* 37A6A4 E00782B4 8E120000 */  lw        $s2, ($s0)
/* 37A6A8 E00782B8 2A820080 */  slti      $v0, $s4, 0x80
/* 37A6AC E00782BC 50400001 */  beql      $v0, $zero, .LE00782C4
/* 37A6B0 E00782C0 2414007F */   addiu    $s4, $zero, 0x7f
.LE00782C4:
/* 37A6B4 E00782C4 3C05DB06 */  lui       $a1, 0xdb06
/* 37A6B8 E00782C8 3C15800A */  lui       $s5, %hi(gMasterGfxPos)
/* 37A6BC E00782CC 26B5A66C */  addiu     $s5, $s5, %lo(gMasterGfxPos)
/* 37A6C0 E00782D0 34A50024 */  ori       $a1, $a1, 0x24
/* 37A6C4 E00782D4 8EA40000 */  lw        $a0, ($s5)
/* 37A6C8 E00782D8 3C02E700 */  lui       $v0, 0xe700
/* 37A6CC E00782DC 0080182D */  daddu     $v1, $a0, $zero
/* 37A6D0 E00782E0 24840008 */  addiu     $a0, $a0, 8
/* 37A6D4 E00782E4 AC620000 */  sw        $v0, ($v1)
/* 37A6D8 E00782E8 AC600004 */  sw        $zero, 4($v1)
/* 37A6DC E00782EC AC850000 */  sw        $a1, ($a0)
/* 37A6E0 E00782F0 8CC20010 */  lw        $v0, 0x10($a2)
/* 37A6E4 E00782F4 AEA40000 */  sw        $a0, ($s5)
/* 37A6E8 E00782F8 8C42001C */  lw        $v0, 0x1c($v0)
/* 37A6EC E00782FC 3C038000 */  lui       $v1, 0x8000
/* 37A6F0 E0078300 00431021 */  addu      $v0, $v0, $v1
/* 37A6F4 E0078304 3C03E008 */  lui       $v1, %hi(D_E0078918)
/* 37A6F8 E0078308 24638918 */  addiu     $v1, $v1, %lo(D_E0078918)
/* 37A6FC E007830C AC820004 */  sw        $v0, 4($a0)
/* 37A700 E0078310 00121040 */  sll       $v0, $s2, 1
/* 37A704 E0078314 00521021 */  addu      $v0, $v0, $s2
/* 37A708 E0078318 000210C0 */  sll       $v0, $v0, 3
/* 37A70C E007831C 00438821 */  addu      $s1, $v0, $v1
/* 37A710 E0078320 8E360010 */  lw        $s6, 0x10($s1)
/* 37A714 E0078324 8E330014 */  lw        $s3, 0x14($s1)
/* 37A718 E0078328 27A20018 */  addiu     $v0, $sp, 0x18
/* 37A71C E007832C AFA20010 */  sw        $v0, 0x10($sp)
/* 37A720 E0078330 27A2001C */  addiu     $v0, $sp, 0x1c
/* 37A724 E0078334 AFA20014 */  sw        $v0, 0x14($sp)
/* 37A728 E0078338 C60C0004 */  lwc1      $f12, 4($s0)
/* 37A72C E007833C C60E0008 */  lwc1      $f14, 8($s0)
/* 37A730 E0078340 8E06000C */  lw        $a2, 0xc($s0)
/* 37A734 E0078344 8E07001C */  lw        $a3, 0x1c($s0)
/* 37A738 E0078348 24840008 */  addiu     $a0, $a0, 8
/* 37A73C E007834C 0C08015C */  jal       shim_func_8011CFBC
/* 37A740 E0078350 AEA40000 */   sw       $a0, ($s5)
/* 37A744 E0078354 0040182D */  daddu     $v1, $v0, $zero
/* 37A748 E0078358 24020005 */  addiu     $v0, $zero, 5
/* 37A74C E007835C 52420001 */  beql      $s2, $v0, .LE0078364
/* 37A750 E0078360 24030001 */   addiu    $v1, $zero, 1
.LE0078364:
/* 37A754 E0078364 10600157 */  beqz      $v1, .LE00788C4
/* 37A758 E0078368 00000000 */   nop
/* 37A75C E007836C C7A20018 */  lwc1      $f2, 0x18($sp)
/* 37A760 E0078370 44800000 */  mtc1      $zero, $f0
/* 37A764 E0078374 00000000 */  nop
/* 37A768 E0078378 4600103C */  c.lt.s    $f2, $f0
/* 37A76C E007837C 00000000 */  nop
/* 37A770 E0078380 45010150 */  bc1t      .LE00788C4
/* 37A774 E0078384 00000000 */   nop
/* 37A778 E0078388 C7A4001C */  lwc1      $f4, 0x1c($sp)
/* 37A77C E007838C 4600203C */  c.lt.s    $f4, $f0
/* 37A780 E0078390 00000000 */  nop
/* 37A784 E0078394 4501014B */  bc1t      .LE00788C4
/* 37A788 E0078398 00000000 */   nop
/* 37A78C E007839C 3C0143A0 */  lui       $at, 0x43a0
/* 37A790 E00783A0 44810000 */  mtc1      $at, $f0
/* 37A794 E00783A4 00000000 */  nop
/* 37A798 E00783A8 4602003E */  c.le.s    $f0, $f2
/* 37A79C E00783AC 00000000 */  nop
/* 37A7A0 E00783B0 45010144 */  bc1t      .LE00788C4
/* 37A7A4 E00783B4 00000000 */   nop
/* 37A7A8 E00783B8 3C014370 */  lui       $at, 0x4370
/* 37A7AC E00783BC 44810000 */  mtc1      $at, $f0
/* 37A7B0 E00783C0 00000000 */  nop
/* 37A7B4 E00783C4 4604003E */  c.le.s    $f0, $f4
/* 37A7B8 E00783C8 00000000 */  nop
/* 37A7BC E00783CC 4501013D */  bc1t      .LE00788C4
/* 37A7C0 E00783D0 3C02DE00 */   lui      $v0, 0xde00
/* 37A7C4 E00783D4 8EA70000 */  lw        $a3, ($s5)
/* 37A7C8 E00783D8 00E0182D */  daddu     $v1, $a3, $zero
/* 37A7CC E00783DC AC620000 */  sw        $v0, ($v1)
/* 37A7D0 E00783E0 00121080 */  sll       $v0, $s2, 2
/* 37A7D4 E00783E4 3C01E008 */  lui       $at, %hi(D_E0078900)
/* 37A7D8 E00783E8 00220821 */  addu      $at, $at, $v0
/* 37A7DC E00783EC 8C228900 */  lw        $v0, %lo(D_E0078900)($at)
/* 37A7E0 E00783F0 24E70008 */  addiu     $a3, $a3, 8
/* 37A7E4 E00783F4 AEA70000 */  sw        $a3, ($s5)
/* 37A7E8 E00783F8 AC620004 */  sw        $v0, 4($v1)
/* 37A7EC E00783FC 8E030020 */  lw        $v1, 0x20($s0)
/* 37A7F0 E0078400 3C04E008 */  lui       $a0, %hi(D_E00789AC)
/* 37A7F4 E0078404 248489AC */  addiu     $a0, $a0, %lo(D_E00789AC)
/* 37A7F8 E0078408 00031040 */  sll       $v0, $v1, 1
/* 37A7FC E007840C 00431021 */  addu      $v0, $v0, $v1
/* 37A800 E0078410 00441021 */  addu      $v0, $v0, $a0
/* 37A804 E0078414 90430000 */  lbu       $v1, ($v0)
/* 37A808 E0078418 00144040 */  sll       $t0, $s4, 1
/* 37A80C E007841C 00680018 */  mult      $v1, $t0
/* 37A810 E0078420 00001812 */  mflo      $v1
/* 37A814 E0078424 3C098080 */  lui       $t1, 0x8080
/* 37A818 E0078428 35298081 */  ori       $t1, $t1, 0x8081
/* 37A81C E007842C 00690018 */  mult      $v1, $t1
/* 37A820 E0078430 44960000 */  mtc1      $s6, $f0
/* 37A824 E0078434 00000000 */  nop
/* 37A828 E0078438 46800020 */  cvt.s.w   $f0, $f0
/* 37A82C E007843C 46001081 */  sub.s     $f2, $f2, $f0
/* 37A830 E0078440 46002001 */  sub.s     $f0, $f4, $f0
/* 37A834 E0078444 4600118D */  trunc.w.s $f6, $f2
/* 37A838 E0078448 E7A60020 */  swc1      $f6, 0x20($sp)
/* 37A83C E007844C 00007010 */  mfhi      $t6
/* 37A840 E0078450 90460001 */  lbu       $a2, 1($v0)
/* 37A844 E0078454 00000000 */  nop
/* 37A848 E0078458 00C80018 */  mult      $a2, $t0
/* 37A84C E007845C 00162040 */  sll       $a0, $s6, 1
/* 37A850 E0078460 90450002 */  lbu       $a1, 2($v0)
/* 37A854 E0078464 24E20008 */  addiu     $v0, $a3, 8
/* 37A858 E0078468 8FB70020 */  lw        $s7, 0x20($sp)
/* 37A85C E007846C 00003012 */  mflo      $a2
/* 37A860 E0078470 AEA20000 */  sw        $v0, ($s5)
/* 37A864 E0078474 3C02FA00 */  lui       $v0, 0xfa00
/* 37A868 E0078478 00C90018 */  mult      $a2, $t1
/* 37A86C E007847C ACE20000 */  sw        $v0, ($a3)
/* 37A870 E0078480 02E47821 */  addu      $t7, $s7, $a0
/* 37A874 E0078484 4600018D */  trunc.w.s $f6, $f0
/* 37A878 E0078488 440A3000 */  mfc1      $t2, $f6
/* 37A87C E007848C 00000000 */  nop
/* 37A880 E0078490 01446021 */  addu      $t4, $t2, $a0
/* 37A884 E0078494 00005810 */  mfhi      $t3
/* 37A888 E0078498 01C32021 */  addu      $a0, $t6, $v1
/* 37A88C E007849C 000421C3 */  sra       $a0, $a0, 7
/* 37A890 E00784A0 00A80018 */  mult      $a1, $t0
/* 37A894 E00784A4 00031FC3 */  sra       $v1, $v1, 0x1f
/* 37A898 E00784A8 00832023 */  subu      $a0, $a0, $v1
/* 37A89C E00784AC 00042600 */  sll       $a0, $a0, 0x18
/* 37A8A0 E00784B0 01661821 */  addu      $v1, $t3, $a2
/* 37A8A4 E00784B4 00002812 */  mflo      $a1
/* 37A8A8 E00784B8 000319C3 */  sra       $v1, $v1, 7
/* 37A8AC E00784BC 000637C3 */  sra       $a2, $a2, 0x1f
/* 37A8B0 E00784C0 00A90018 */  mult      $a1, $t1
/* 37A8B4 E00784C4 00661823 */  subu      $v1, $v1, $a2
/* 37A8B8 E00784C8 306300FF */  andi      $v1, $v1, 0xff
/* 37A8BC E00784CC 00031C00 */  sll       $v1, $v1, 0x10
/* 37A8C0 E00784D0 00832025 */  or        $a0, $a0, $v1
/* 37A8C4 E00784D4 00004010 */  mfhi      $t0
/* 37A8C8 E00784D8 01051021 */  addu      $v0, $t0, $a1
/* 37A8CC E00784DC 000211C3 */  sra       $v0, $v0, 7
/* 37A8D0 E00784E0 00052FC3 */  sra       $a1, $a1, 0x1f
/* 37A8D4 E00784E4 00451023 */  subu      $v0, $v0, $a1
/* 37A8D8 E00784E8 304200FF */  andi      $v0, $v0, 0xff
/* 37A8DC E00784EC 00021200 */  sll       $v0, $v0, 8
/* 37A8E0 E00784F0 00822025 */  or        $a0, $a0, $v0
/* 37A8E4 E00784F4 3484007F */  ori       $a0, $a0, 0x7f
/* 37A8E8 E00784F8 ACE40004 */  sw        $a0, 4($a3)
/* 37A8EC E00784FC 8FB70020 */  lw        $s7, 0x20($sp)
/* 37A8F0 E0078500 06E10002 */  bgez      $s7, .LE007850C
/* 37A8F4 E0078504 0000682D */   daddu    $t5, $zero, $zero
/* 37A8F8 E0078508 00176823 */  negu      $t5, $s7
.LE007850C:
/* 37A8FC E007850C 05410002 */  bgez      $t2, .LE0078518
/* 37A900 E0078510 0000182D */   daddu    $v1, $zero, $zero
/* 37A904 E0078514 000A1823 */  negu      $v1, $t2
.LE0078518:
/* 37A908 E0078518 29E20141 */  slti      $v0, $t7, 0x141
/* 37A90C E007851C 50400001 */  beql      $v0, $zero, .LE0078524
/* 37A910 E0078520 240F013F */   addiu    $t7, $zero, 0x13f
.LE0078524:
/* 37A914 E0078524 298200F1 */  slti      $v0, $t4, 0xf1
/* 37A918 E0078528 50400001 */  beql      $v0, $zero, .LE0078530
/* 37A91C E007852C 240C00EF */   addiu    $t4, $zero, 0xef
.LE0078530:
/* 37A920 E0078530 16600002 */  bnez      $s3, .LE007853C
/* 37A924 E0078534 0073001A */   div      $zero, $v1, $s3
/* 37A928 E0078538 0007000D */  break     7
.LE007853C:
/* 37A92C E007853C 2401FFFF */   addiu    $at, $zero, -1
/* 37A930 E0078540 16610004 */  bne       $s3, $at, .LE0078554
/* 37A934 E0078544 3C018000 */   lui      $at, 0x8000
/* 37A938 E0078548 14610002 */  bne       $v1, $at, .LE0078554
/* 37A93C E007854C 00000000 */   nop
/* 37A940 E0078550 0006000D */  break     6
.LE0078554:
/* 37A944 E0078554 00005812 */   mflo     $t3
/* 37A948 E0078558 018A1023 */  subu      $v0, $t4, $t2
/* 37A94C E007855C 16600002 */  bnez      $s3, .LE0078568
/* 37A950 E0078560 0053001A */   div      $zero, $v0, $s3
/* 37A954 E0078564 0007000D */  break     7
.LE0078568:
/* 37A958 E0078568 2401FFFF */   addiu    $at, $zero, -1
/* 37A95C E007856C 16610004 */  bne       $s3, $at, .LE0078580
/* 37A960 E0078570 3C018000 */   lui      $at, 0x8000
/* 37A964 E0078574 14410002 */  bne       $v0, $at, .LE0078580
/* 37A968 E0078578 00000000 */   nop
/* 37A96C E007857C 0006000D */  break     6
.LE0078580:
/* 37A970 E0078580 0000B812 */   mflo     $s7
/* 37A974 E0078584 0177102A */  slt       $v0, $t3, $s7
/* 37A978 E0078588 104000CE */  beqz      $v0, .LE00788C4
/* 37A97C E007858C AFB70024 */   sw       $s7, 0x24($sp)
/* 37A980 E0078590 02A0482D */  daddu     $t1, $s5, $zero
/* 37A984 E0078594 8FB70020 */  lw        $s7, 0x20($sp)
/* 37A988 E0078598 01730018 */  mult      $t3, $s3
/* 37A98C E007859C 02EDB021 */  addu      $s6, $s7, $t5
/* 37A990 E00785A0 01F61023 */  subu      $v0, $t7, $s6
/* 37A994 E00785A4 00021040 */  sll       $v0, $v0, 1
/* 37A998 E00785A8 AFA20028 */  sw        $v0, 0x28($sp)
/* 37A99C E00785AC 0000B812 */  mflo      $s7
/* 37A9A0 E00785B0 02EA5021 */  addu      $t2, $s7, $t2
.LE00785B4:
/* 37A9A4 E00785B4 01531021 */  addu      $v0, $t2, $s3
/* 37A9A8 E00785B8 284200F0 */  slti      $v0, $v0, 0xf0
/* 37A9AC E00785BC 104000C1 */  beqz      $v0, .LE00788C4
/* 37A9B0 E00785C0 3C03F510 */   lui      $v1, 0xf510
/* 37A9B4 E00785C4 000A3080 */  sll       $a2, $t2, 2
/* 37A9B8 E00785C8 00CA1021 */  addu      $v0, $a2, $t2
/* 37A9BC E00785CC 0002F1C0 */  sll       $fp, $v0, 7
/* 37A9C0 E00785D0 34630100 */  ori       $v1, $v1, 0x100
/* 37A9C4 E00785D4 8FB70028 */  lw        $s7, 0x28($sp)
/* 37A9C8 E00785D8 C7A40020 */  lwc1      $f4, 0x20($sp)
/* 37A9CC E00785DC 46802120 */  cvt.s.w   $f4, $f4
/* 37A9D0 E00785E0 26E20007 */  addiu     $v0, $s7, 7
/* 37A9D4 E00785E4 000210C3 */  sra       $v0, $v0, 3
/* 37A9D8 E00785E8 304201FF */  andi      $v0, $v0, 0x1ff
/* 37A9DC E00785EC 00021240 */  sll       $v0, $v0, 9
/* 37A9E0 E00785F0 00437025 */  or        $t6, $v0, $v1
/* 37A9E4 E00785F4 00161080 */  sll       $v0, $s6, 2
/* 37A9E8 E00785F8 30420FFF */  andi      $v0, $v0, 0xfff
/* 37A9EC E00785FC 00026B00 */  sll       $t5, $v0, 0xc
/* 37A9F0 E0078600 3C02F400 */  lui       $v0, 0xf400
/* 37A9F4 E0078604 01A21025 */  or        $v0, $t5, $v0
/* 37A9F8 E0078608 AFA20030 */  sw        $v0, 0x30($sp)
/* 37A9FC E007860C 25E2FFFF */  addiu     $v0, $t7, -1
/* 37AA00 E0078610 00021080 */  sll       $v0, $v0, 2
/* 37AA04 E0078614 30420FFF */  andi      $v0, $v0, 0xfff
/* 37AA08 E0078618 00029300 */  sll       $s2, $v0, 0xc
/* 37AA0C E007861C 2662FFFF */  addiu     $v0, $s3, -1
/* 37AA10 E0078620 00021080 */  sll       $v0, $v0, 2
/* 37AA14 E0078624 30500FFF */  andi      $s0, $v0, 0xfff
/* 37AA18 E0078628 3C020700 */  lui       $v0, 0x700
/* 37AA1C E007862C C6200008 */  lwc1      $f0, 8($s1)
/* 37AA20 E0078630 02021025 */  or        $v0, $s0, $v0
/* 37AA24 E0078634 46002002 */  mul.s     $f0, $f4, $f0
/* 37AA28 E0078638 00000000 */  nop
/* 37AA2C E007863C 0242C825 */  or        $t9, $s2, $v0
/* 37AA30 E0078640 8E220014 */  lw        $v0, 0x14($s1)
/* 37AA34 E0078644 8D250000 */  lw        $a1, ($t1)
/* 37AA38 E0078648 8E240004 */  lw        $a0, 4($s1)
/* 37AA3C E007864C 01620018 */  mult      $t3, $v0
/* 37AA40 E0078650 00A0382D */  daddu     $a3, $a1, $zero
/* 37AA44 E0078654 00041080 */  sll       $v0, $a0, 2
/* 37AA48 E0078658 00441021 */  addu      $v0, $v0, $a0
/* 37AA4C E007865C 4600018D */  trunc.w.s $f6, $f0
/* 37AA50 E0078660 44033000 */  mfc1      $v1, $f6
/* 37AA54 E0078664 0000B812 */  mflo      $s7
/* 37AA58 E0078668 C620000C */  lwc1      $f0, 0xc($s1)
/* 37AA5C E007866C 44971000 */  mtc1      $s7, $f2
/* 37AA60 E0078670 00000000 */  nop
/* 37AA64 E0078674 468010A0 */  cvt.s.w   $f2, $f2
/* 37AA68 E0078678 46001082 */  mul.s     $f2, $f2, $f0
/* 37AA6C E007867C 00000000 */  nop
/* 37AA70 E0078680 00021080 */  sll       $v0, $v0, 2
/* 37AA74 E0078684 24A50008 */  addiu     $a1, $a1, 8
/* 37AA78 E0078688 00031880 */  sll       $v1, $v1, 2
/* 37AA7C E007868C 44820000 */  mtc1      $v0, $f0
/* 37AA80 E0078690 00000000 */  nop
/* 37AA84 E0078694 46800020 */  cvt.s.w   $f0, $f0
/* 37AA88 E0078698 46020001 */  sub.s     $f0, $f0, $f2
/* 37AA8C E007869C 30630FFF */  andi      $v1, $v1, 0xfff
/* 37AA90 E00786A0 00031B00 */  sll       $v1, $v1, 0xc
/* 37AA94 E00786A4 4600018D */  trunc.w.s $f6, $f0
/* 37AA98 E00786A8 44023000 */  mfc1      $v0, $f6
/* 37AA9C E00786AC 00000000 */  nop
/* 37AAA0 E00786B0 00021080 */  sll       $v0, $v0, 2
/* 37AAA4 E00786B4 30420FFF */  andi      $v0, $v0, 0xfff
/* 37AAA8 E00786B8 3C17F200 */  lui       $s7, 0xf200
/* 37AAAC E00786BC 00571025 */  or        $v0, $v0, $s7
/* 37AAB0 E00786C0 00621825 */  or        $v1, $v1, $v0
/* 37AAB4 E00786C4 32C201FF */  andi      $v0, $s6, 0x1ff
/* 37AAB8 E00786C8 ACE30000 */  sw        $v1, ($a3)
/* 37AABC E00786CC C6200008 */  lwc1      $f0, 8($s1)
/* 37AAC0 E00786D0 0002A540 */  sll       $s4, $v0, 0x15
/* 37AAC4 E00786D4 46002102 */  mul.s     $f4, $f4, $f0
/* 37AAC8 E00786D8 00000000 */  nop
/* 37AACC E00786DC C6200000 */  lwc1      $f0, ($s1)
/* 37AAD0 E00786E0 46800020 */  cvt.s.w   $f0, $f0
/* 37AAD4 E00786E4 AD250000 */  sw        $a1, ($t1)
/* 37AAD8 E00786E8 8E220014 */  lw        $v0, 0x14($s1)
/* 37AADC E00786EC 0000602D */  daddu     $t4, $zero, $zero
/* 37AAE0 E00786F0 01620018 */  mult      $t3, $v0
/* 37AAE4 E00786F4 3C15E700 */  lui       $s5, 0xe700
/* 37AAE8 E00786F8 30C60FFF */  andi      $a2, $a2, 0xfff
/* 37AAEC E00786FC 01A6C025 */  or        $t8, $t5, $a2
/* 37AAF0 E0078700 8E240004 */  lw        $a0, 4($s1)
/* 37AAF4 E0078704 46002100 */  add.s     $f4, $f4, $f0
/* 37AAF8 E0078708 00041080 */  sll       $v0, $a0, 2
/* 37AAFC E007870C 00441021 */  addu      $v0, $v0, $a0
/* 37AB00 E0078710 4600218D */  trunc.w.s $f6, $f4
/* 37AB04 E0078714 44033000 */  mfc1      $v1, $f6
/* 37AB08 E0078718 0000B812 */  mflo      $s7
/* 37AB0C E007871C C620000C */  lwc1      $f0, 0xc($s1)
/* 37AB10 E0078720 44971000 */  mtc1      $s7, $f2
/* 37AB14 E0078724 00000000 */  nop
/* 37AB18 E0078728 468010A0 */  cvt.s.w   $f2, $f2
/* 37AB1C E007872C 46001082 */  mul.s     $f2, $f2, $f0
/* 37AB20 E0078730 00000000 */  nop
/* 37AB24 E0078734 00021080 */  sll       $v0, $v0, 2
/* 37AB28 E0078738 00441021 */  addu      $v0, $v0, $a0
/* 37AB2C E007873C 00031880 */  sll       $v1, $v1, 2
/* 37AB30 E0078740 44820000 */  mtc1      $v0, $f0
/* 37AB34 E0078744 00000000 */  nop
/* 37AB38 E0078748 46800020 */  cvt.s.w   $f0, $f0
/* 37AB3C E007874C 46020001 */  sub.s     $f0, $f0, $f2
/* 37AB40 E0078750 30630FFF */  andi      $v1, $v1, 0xfff
/* 37AB44 E0078754 00031B00 */  sll       $v1, $v1, 0xc
/* 37AB48 E0078758 4600018D */  trunc.w.s $f6, $f0
/* 37AB4C E007875C 44023000 */  mfc1      $v0, $f6
/* 37AB50 E0078760 00000000 */  nop
/* 37AB54 E0078764 00021080 */  sll       $v0, $v0, 2
/* 37AB58 E0078768 30420FFF */  andi      $v0, $v0, 0xfff
/* 37AB5C E007876C 00621825 */  or        $v1, $v1, $v0
/* 37AB60 E0078770 ACE30004 */  sw        $v1, 4($a3)
.LE0078774:
/* 37AB64 E0078774 3C02FD10 */  lui       $v0, 0xfd10
/* 37AB68 E0078778 3442013F */  ori       $v0, $v0, 0x13f
/* 37AB6C E007877C 3C060702 */  lui       $a2, 0x702
/* 37AB70 E0078780 34C60090 */  ori       $a2, $a2, 0x90
/* 37AB74 E0078784 3C070102 */  lui       $a3, 0x102
/* 37AB78 E0078788 34E70090 */  ori       $a3, $a3, 0x90
/* 37AB7C E007878C 3C080400 */  lui       $t0, 0x400
/* 37AB80 E0078790 35080400 */  ori       $t0, $t0, 0x400
/* 37AB84 E0078794 258C0001 */  addiu     $t4, $t4, 1
/* 37AB88 E0078798 8D250000 */  lw        $a1, ($t1)
/* 37AB8C E007879C 3C03800A */  lui       $v1, %hi(nuGfxCfb_ptr)
/* 37AB90 E00787A0 8C63A64C */  lw        $v1, %lo(nuGfxCfb_ptr)($v1)
/* 37AB94 E00787A4 00A0202D */  daddu     $a0, $a1, $zero
/* 37AB98 E00787A8 24A50008 */  addiu     $a1, $a1, 8
/* 37AB9C E00787AC 007E1821 */  addu      $v1, $v1, $fp
/* 37ABA0 E00787B0 AD250000 */  sw        $a1, ($t1)
/* 37ABA4 E00787B4 AC820000 */  sw        $v0, ($a0)
/* 37ABA8 E00787B8 3C028000 */  lui       $v0, 0x8000
/* 37ABAC E00787BC 00621821 */  addu      $v1, $v1, $v0
/* 37ABB0 E00787C0 24A20008 */  addiu     $v0, $a1, 8
/* 37ABB4 E00787C4 AC830004 */  sw        $v1, 4($a0)
/* 37ABB8 E00787C8 AD220000 */  sw        $v0, ($t1)
/* 37ABBC E00787CC 24A20010 */  addiu     $v0, $a1, 0x10
/* 37ABC0 E00787D0 ACAE0000 */  sw        $t6, ($a1)
/* 37ABC4 E00787D4 ACA60004 */  sw        $a2, 4($a1)
/* 37ABC8 E00787D8 AD220000 */  sw        $v0, ($t1)
/* 37ABCC E00787DC 3C02E600 */  lui       $v0, 0xe600
/* 37ABD0 E00787E0 ACA20008 */  sw        $v0, 8($a1)
/* 37ABD4 E00787E4 24A20018 */  addiu     $v0, $a1, 0x18
/* 37ABD8 E00787E8 ACA0000C */  sw        $zero, 0xc($a1)
/* 37ABDC E00787EC AD220000 */  sw        $v0, ($t1)
/* 37ABE0 E00787F0 24A20020 */  addiu     $v0, $a1, 0x20
/* 37ABE4 E00787F4 000F2080 */  sll       $a0, $t7, 2
/* 37ABE8 E00787F8 30840FFF */  andi      $a0, $a0, 0xfff
/* 37ABEC E00787FC 00042300 */  sll       $a0, $a0, 0xc
/* 37ABF0 E0078800 01533021 */  addu      $a2, $t2, $s3
/* 37ABF4 E0078804 8FB70030 */  lw        $s7, 0x30($sp)
/* 37ABF8 E0078808 3C03E400 */  lui       $v1, 0xe400
/* 37ABFC E007880C ACB90014 */  sw        $t9, 0x14($a1)
/* 37AC00 E0078810 ACB70010 */  sw        $s7, 0x10($a1)
/* 37AC04 E0078814 AD220000 */  sw        $v0, ($t1)
/* 37AC08 E0078818 24A20028 */  addiu     $v0, $a1, 0x28
/* 37AC0C E007881C ACB50018 */  sw        $s5, 0x18($a1)
/* 37AC10 E0078820 ACA0001C */  sw        $zero, 0x1c($a1)
/* 37AC14 E0078824 AD220000 */  sw        $v0, ($t1)
/* 37AC18 E0078828 24A20030 */  addiu     $v0, $a1, 0x30
/* 37AC1C E007882C 3C17F200 */  lui       $s7, 0xf200
/* 37AC20 E0078830 ACAE0020 */  sw        $t6, 0x20($a1)
/* 37AC24 E0078834 ACA70024 */  sw        $a3, 0x24($a1)
/* 37AC28 E0078838 AD220000 */  sw        $v0, ($t1)
/* 37AC2C E007883C 01B71025 */  or        $v0, $t5, $s7
/* 37AC30 E0078840 ACA20028 */  sw        $v0, 0x28($a1)
/* 37AC34 E0078844 3C020100 */  lui       $v0, 0x100
/* 37AC38 E0078848 02021025 */  or        $v0, $s0, $v0
/* 37AC3C E007884C 02421025 */  or        $v0, $s2, $v0
/* 37AC40 E0078850 ACA2002C */  sw        $v0, 0x2c($a1)
/* 37AC44 E0078854 24A20038 */  addiu     $v0, $a1, 0x38
/* 37AC48 E0078858 AD220000 */  sw        $v0, ($t1)
/* 37AC4C E007885C 00061080 */  sll       $v0, $a2, 2
/* 37AC50 E0078860 30420FFF */  andi      $v0, $v0, 0xfff
/* 37AC54 E0078864 00431025 */  or        $v0, $v0, $v1
/* 37AC58 E0078868 00822025 */  or        $a0, $a0, $v0
/* 37AC5C E007886C 24A20040 */  addiu     $v0, $a1, 0x40
/* 37AC60 E0078870 ACA40030 */  sw        $a0, 0x30($a1)
/* 37AC64 E0078874 ACB80034 */  sw        $t8, 0x34($a1)
/* 37AC68 E0078878 AD220000 */  sw        $v0, ($t1)
/* 37AC6C E007887C 3C02E100 */  lui       $v0, 0xe100
/* 37AC70 E0078880 ACA20038 */  sw        $v0, 0x38($a1)
/* 37AC74 E0078884 24A20048 */  addiu     $v0, $a1, 0x48
/* 37AC78 E0078888 ACB4003C */  sw        $s4, 0x3c($a1)
/* 37AC7C E007888C AD220000 */  sw        $v0, ($t1)
/* 37AC80 E0078890 3C02F100 */  lui       $v0, 0xf100
/* 37AC84 E0078894 ACA20040 */  sw        $v0, 0x40($a1)
/* 37AC88 E0078898 24A20050 */  addiu     $v0, $a1, 0x50
/* 37AC8C E007889C ACA80044 */  sw        $t0, 0x44($a1)
/* 37AC90 E00788A0 AD220000 */  sw        $v0, ($t1)
/* 37AC94 E00788A4 ACB50048 */  sw        $s5, 0x48($a1)
/* 37AC98 E00788A8 1980FFB2 */  blez      $t4, .LE0078774
/* 37AC9C E00788AC ACA0004C */   sw       $zero, 0x4c($a1)
/* 37ACA0 E00788B0 8FB70024 */  lw        $s7, 0x24($sp)
/* 37ACA4 E00788B4 256B0001 */  addiu     $t3, $t3, 1
/* 37ACA8 E00788B8 0177102A */  slt       $v0, $t3, $s7
/* 37ACAC E00788BC 1440FF3D */  bnez      $v0, .LE00785B4
/* 37ACB0 E00788C0 00C0502D */   daddu    $t2, $a2, $zero
.LE00788C4:
/* 37ACB4 E00788C4 8FBF005C */  lw        $ra, 0x5c($sp)
/* 37ACB8 E00788C8 8FBE0058 */  lw        $fp, 0x58($sp)
/* 37ACBC E00788CC 8FB70054 */  lw        $s7, 0x54($sp)
/* 37ACC0 E00788D0 8FB60050 */  lw        $s6, 0x50($sp)
/* 37ACC4 E00788D4 8FB5004C */  lw        $s5, 0x4c($sp)
/* 37ACC8 E00788D8 8FB40048 */  lw        $s4, 0x48($sp)
/* 37ACCC E00788DC 8FB30044 */  lw        $s3, 0x44($sp)
/* 37ACD0 E00788E0 8FB20040 */  lw        $s2, 0x40($sp)
/* 37ACD4 E00788E4 8FB1003C */  lw        $s1, 0x3c($sp)
/* 37ACD8 E00788E8 8FB00038 */  lw        $s0, 0x38($sp)
/* 37ACDC E00788EC 03E00008 */  jr        $ra
/* 37ACE0 E00788F0 27BD0060 */   addiu    $sp, $sp, 0x60
/* 37ACE4 E00788F4 00000000 */  nop
/* 37ACE8 E00788F8 00000000 */  nop
/* 37ACEC E00788FC 00000000 */  nop
