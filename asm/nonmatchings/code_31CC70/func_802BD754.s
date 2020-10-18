.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD754
/* 31D2C4 802BD754 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 31D2C8 802BD758 AFB3001C */  sw        $s3, 0x1c($sp)
/* 31D2CC 802BD75C 0080982D */  daddu     $s3, $a0, $zero
/* 31D2D0 802BD760 AFB20018 */  sw        $s2, 0x18($sp)
/* 31D2D4 802BD764 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* 31D2D8 802BD768 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* 31D2DC 802BD76C AFB50024 */  sw        $s5, 0x24($sp)
/* 31D2E0 802BD770 3C158011 */  lui       $s5, %hi(D_8010EBB0)
/* 31D2E4 802BD774 26B5EBB0 */  addiu     $s5, $s5, %lo(D_8010EBB0)
/* 31D2E8 802BD778 AFBF0028 */  sw        $ra, 0x28($sp)
/* 31D2EC 802BD77C AFB40020 */  sw        $s4, 0x20($sp)
/* 31D2F0 802BD780 AFB10014 */  sw        $s1, 0x14($sp)
/* 31D2F4 802BD784 AFB00010 */  sw        $s0, 0x10($sp)
/* 31D2F8 802BD788 10A0003B */  beqz      $a1, .L802BD878
/* 31D2FC 802BD78C 8E71014C */   lw       $s1, 0x14c($s3)
/* 31D300 802BD790 0C0AF5C4 */  jal       func_802BD710
/* 31D304 802BD794 0220202D */   daddu    $a0, $s1, $zero
/* 31D308 802BD798 8E430004 */  lw        $v1, 4($s2)
/* 31D30C 802BD79C 3C020010 */  lui       $v0, 0x10
/* 31D310 802BD7A0 00621024 */  and       $v0, $v1, $v0
/* 31D314 802BD7A4 14400150 */  bnez      $v0, .L802BDCE8
/* 31D318 802BD7A8 24020002 */   addiu    $v0, $zero, 2
/* 31D31C 802BD7AC 82A20001 */  lb        $v0, 1($s5)
/* 31D320 802BD7B0 14400026 */  bnez      $v0, .L802BD84C
/* 31D324 802BD7B4 34620003 */   ori      $v0, $v1, 3
/* 31D328 802BD7B8 82A20000 */  lb        $v0, ($s5)
/* 31D32C 802BD7BC 14400009 */  bnez      $v0, .L802BD7E4
/* 31D330 802BD7C0 00000000 */   nop      
/* 31D334 802BD7C4 0C03A94B */  jal       func_800EA52C
/* 31D338 802BD7C8 24040006 */   addiu    $a0, $zero, 6
/* 31D33C 802BD7CC 10400146 */  beqz      $v0, .L802BDCE8
/* 31D340 802BD7D0 24020002 */   addiu    $v0, $zero, 2
/* 31D344 802BD7D4 0C011052 */  jal       func_80044148
/* 31D348 802BD7D8 00000000 */   nop      
/* 31D34C 802BD7DC 14400142 */  bnez      $v0, .L802BDCE8
/* 31D350 802BD7E0 24020002 */   addiu    $v0, $zero, 2
.L802BD7E4:
/* 31D354 802BD7E4 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 31D358 802BD7E8 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 31D35C 802BD7EC 8042007D */  lb        $v0, 0x7d($v0)
/* 31D360 802BD7F0 10400009 */  beqz      $v0, .L802BD818
/* 31D364 802BD7F4 00000000 */   nop      
/* 31D368 802BD7F8 8E420004 */  lw        $v0, 4($s2)
/* 31D36C 802BD7FC 30420003 */  andi      $v0, $v0, 3
/* 31D370 802BD800 1040000D */  beqz      $v0, .L802BD838
/* 31D374 802BD804 24020014 */   addiu    $v0, $zero, 0x14
/* 31D378 802BD808 3C01802C */  lui       $at, 0x802c
/* 31D37C 802BD80C AC22E304 */  sw        $v0, -0x1cfc($at)
/* 31D380 802BD810 080AF61E */  j         .L802BD878
/* 31D384 802BD814 00000000 */   nop      
.L802BD818:
/* 31D388 802BD818 8E420004 */  lw        $v0, 4($s2)
/* 31D38C 802BD81C 30420001 */  andi      $v0, $v0, 1
/* 31D390 802BD820 10400005 */  beqz      $v0, .L802BD838
/* 31D394 802BD824 24020002 */   addiu    $v0, $zero, 2
/* 31D398 802BD828 3C01802C */  lui       $at, 0x802c
/* 31D39C 802BD82C AC22E304 */  sw        $v0, -0x1cfc($at)
/* 31D3A0 802BD830 080AF61E */  j         .L802BD878
/* 31D3A4 802BD834 00000000 */   nop      
.L802BD838:
/* 31D3A8 802BD838 24020028 */  addiu     $v0, $zero, 0x28
/* 31D3AC 802BD83C 3C01802C */  lui       $at, 0x802c
/* 31D3B0 802BD840 AC22E304 */  sw        $v0, -0x1cfc($at)
/* 31D3B4 802BD844 080AF61E */  j         .L802BD878
/* 31D3B8 802BD848 00000000 */   nop      
.L802BD84C:
/* 31D3BC 802BD84C A2A00001 */  sb        $zero, 1($s5)
/* 31D3C0 802BD850 0C0AF805 */  jal       func_802BE014
/* 31D3C4 802BD854 AE420004 */   sw       $v0, 4($s2)
/* 31D3C8 802BD858 3C020006 */  lui       $v0, 6
/* 31D3CC 802BD85C 34420001 */  ori       $v0, $v0, 1
/* 31D3D0 802BD860 AE220028 */  sw        $v0, 0x28($s1)
/* 31D3D4 802BD864 24020001 */  addiu     $v0, $zero, 1
/* 31D3D8 802BD868 3C01802C */  lui       $at, 0x802c
/* 31D3DC 802BD86C AC22E304 */  sw        $v0, -0x1cfc($at)
/* 31D3E0 802BD870 24020002 */  addiu     $v0, $zero, 2
/* 31D3E4 802BD874 AE620074 */  sw        $v0, 0x74($s3)
.L802BD878:
/* 31D3E8 802BD878 3C10802C */  lui       $s0, 0x802c
/* 31D3EC 802BD87C 2610E304 */  addiu     $s0, $s0, -0x1cfc
/* 31D3F0 802BD880 8E030000 */  lw        $v1, ($s0)
/* 31D3F4 802BD884 24020028 */  addiu     $v0, $zero, 0x28
/* 31D3F8 802BD888 10620005 */  beq       $v1, $v0, .L802BD8A0
/* 31D3FC 802BD88C 24020029 */   addiu    $v0, $zero, 0x29
/* 31D400 802BD890 1062000E */  beq       $v1, $v0, .L802BD8CC
/* 31D404 802BD894 00000000 */   nop      
/* 31D408 802BD898 080AF64C */  j         .L802BD930
/* 31D40C 802BD89C 00000000 */   nop      
.L802BD8A0:
/* 31D410 802BD8A0 82420015 */  lb        $v0, 0x15($s2)
/* 31D414 802BD8A4 10400003 */  beqz      $v0, .L802BD8B4
/* 31D418 802BD8A8 24020003 */   addiu    $v0, $zero, 3
/* 31D41C 802BD8AC 080AF73A */  j         .L802BDCE8
/* 31D420 802BD8B0 24020002 */   addiu    $v0, $zero, 2
.L802BD8B4:
/* 31D424 802BD8B4 AE620074 */  sw        $v0, 0x74($s3)
/* 31D428 802BD8B8 82430015 */  lb        $v1, 0x15($s2)
/* 31D42C 802BD8BC 24020029 */  addiu     $v0, $zero, 0x29
/* 31D430 802BD8C0 AE020000 */  sw        $v0, ($s0)
/* 31D434 802BD8C4 080AF64C */  j         .L802BD930
/* 31D438 802BD8C8 AE630078 */   sw       $v1, 0x78($s3)
.L802BD8CC:
/* 31D43C 802BD8CC 8E620074 */  lw        $v0, 0x74($s3)
/* 31D440 802BD8D0 14400016 */  bnez      $v0, .L802BD92C
/* 31D444 802BD8D4 2442FFFF */   addiu    $v0, $v0, -1
/* 31D448 802BD8D8 82430015 */  lb        $v1, 0x15($s2)
/* 31D44C 802BD8DC 8E620078 */  lw        $v0, 0x78($s3)
/* 31D450 802BD8E0 0043102A */  slt       $v0, $v0, $v1
/* 31D454 802BD8E4 14400100 */  bnez      $v0, .L802BDCE8
/* 31D458 802BD8E8 24020002 */   addiu    $v0, $zero, 2
/* 31D45C 802BD8EC 8E420004 */  lw        $v0, 4($s2)
/* 31D460 802BD8F0 3C030010 */  lui       $v1, 0x10
/* 31D464 802BD8F4 00431024 */  and       $v0, $v0, $v1
/* 31D468 802BD8F8 144000FB */  bnez      $v0, .L802BDCE8
/* 31D46C 802BD8FC 24020002 */   addiu    $v0, $zero, 2
/* 31D470 802BD900 0C03A94B */  jal       func_800EA52C
/* 31D474 802BD904 24040006 */   addiu    $a0, $zero, 6
/* 31D478 802BD908 104000F7 */  beqz      $v0, .L802BDCE8
/* 31D47C 802BD90C 24020002 */   addiu    $v0, $zero, 2
/* 31D480 802BD910 0C011052 */  jal       func_80044148
/* 31D484 802BD914 00000000 */   nop      
/* 31D488 802BD918 144000F3 */  bnez      $v0, .L802BDCE8
/* 31D48C 802BD91C 24020002 */   addiu    $v0, $zero, 2
/* 31D490 802BD920 24020014 */  addiu     $v0, $zero, 0x14
/* 31D494 802BD924 080AF64C */  j         .L802BD930
/* 31D498 802BD928 AE020000 */   sw       $v0, ($s0)
.L802BD92C:
/* 31D49C 802BD92C AE620074 */  sw        $v0, 0x74($s3)
.L802BD930:
/* 31D4A0 802BD930 3C14802C */  lui       $s4, 0x802c
/* 31D4A4 802BD934 2694E304 */  addiu     $s4, $s4, -0x1cfc
/* 31D4A8 802BD938 8E830000 */  lw        $v1, ($s4)
/* 31D4AC 802BD93C 24020014 */  addiu     $v0, $zero, 0x14
/* 31D4B0 802BD940 1062000C */  beq       $v1, $v0, .L802BD974
/* 31D4B4 802BD944 28620015 */   slti     $v0, $v1, 0x15
/* 31D4B8 802BD948 10400005 */  beqz      $v0, .L802BD960
/* 31D4BC 802BD94C 24020001 */   addiu    $v0, $zero, 1
/* 31D4C0 802BD950 10620099 */  beq       $v1, $v0, .L802BDBB8
/* 31D4C4 802BD954 00000000 */   nop      
/* 31D4C8 802BD958 080AF707 */  j         .L802BDC1C
/* 31D4CC 802BD95C 00000000 */   nop      
.L802BD960:
/* 31D4D0 802BD960 24020015 */  addiu     $v0, $zero, 0x15
/* 31D4D4 802BD964 10620062 */  beq       $v1, $v0, .L802BDAF0
/* 31D4D8 802BD968 00000000 */   nop      
/* 31D4DC 802BD96C 080AF707 */  j         .L802BDC1C
/* 31D4E0 802BD970 00000000 */   nop      
.L802BD974:
/* 31D4E4 802BD974 3C058007 */  lui       $a1, %hi(gGameStatusPtr)
/* 31D4E8 802BD978 8CA5419C */  lw        $a1, %lo(gGameStatusPtr)($a1)
/* 31D4EC 802BD97C 80A2007D */  lb        $v0, 0x7d($a1)
/* 31D4F0 802BD980 10400030 */  beqz      $v0, .L802BDA44
/* 31D4F4 802BD984 24100001 */   addiu    $s0, $zero, 1
/* 31D4F8 802BD988 8E420004 */  lw        $v0, 4($s2)
/* 31D4FC 802BD98C 3C0140A0 */  lui       $at, 0x40a0
/* 31D500 802BD990 44811000 */  mtc1      $at, $f2
/* 31D504 802BD994 34420001 */  ori       $v0, $v0, 1
/* 31D508 802BD998 AE420004 */  sw        $v0, 4($s2)
/* 31D50C 802BD99C 8E220000 */  lw        $v0, ($s1)
/* 31D510 802BD9A0 2403F5FF */  addiu     $v1, $zero, -0xa01
/* 31D514 802BD9A4 3C01802C */  lui       $at, 0x802c
/* 31D518 802BD9A8 AC30E30C */  sw        $s0, -0x1cf4($at)
/* 31D51C 802BD9AC 34420108 */  ori       $v0, $v0, 0x108
/* 31D520 802BD9B0 00431024 */  and       $v0, $v0, $v1
/* 31D524 802BD9B4 AE220000 */  sw        $v0, ($s1)
/* 31D528 802BD9B8 A0A0007D */  sb        $zero, 0x7d($a1)
/* 31D52C 802BD9BC A2B00000 */  sb        $s0, ($s5)
/* 31D530 802BD9C0 C6400028 */  lwc1      $f0, 0x28($s2)
/* 31D534 802BD9C4 24020006 */  addiu     $v0, $zero, 6
/* 31D538 802BD9C8 A2A20003 */  sb        $v0, 3($s5)
/* 31D53C 802BD9CC E6200060 */  swc1      $f0, 0x60($s1)
/* 31D540 802BD9D0 C640002C */  lwc1      $f0, 0x2c($s2)
/* 31D544 802BD9D4 26240060 */  addiu     $a0, $s1, 0x60
/* 31D548 802BD9D8 46020000 */  add.s     $f0, $f0, $f2
/* 31D54C 802BD9DC 3C064170 */  lui       $a2, 0x4170
/* 31D550 802BD9E0 3C020006 */  lui       $v0, 6
/* 31D554 802BD9E4 E6200064 */  swc1      $f0, 0x64($s1)
/* 31D558 802BD9E8 C6400030 */  lwc1      $f0, 0x30($s2)
/* 31D55C 802BD9EC 34420002 */  ori       $v0, $v0, 2
/* 31D560 802BD9F0 AE220028 */  sw        $v0, 0x28($s1)
/* 31D564 802BD9F4 E6200068 */  swc1      $f0, 0x68($s1)
/* 31D568 802BD9F8 8E470080 */  lw        $a3, 0x80($s2)
/* 31D56C 802BD9FC 0C00A7E7 */  jal       add_vec2D_polar
/* 31D570 802BDA00 26250068 */   addiu    $a1, $s1, 0x68
/* 31D574 802BDA04 3C020006 */  lui       $v0, 6
/* 31D578 802BDA08 C6400080 */  lwc1      $f0, 0x80($s2)
/* 31D57C 802BDA0C 00501025 */  or        $v0, $v0, $s0
/* 31D580 802BDA10 AE220028 */  sw        $v0, 0x28($s1)
/* 31D584 802BDA14 E620000C */  swc1      $f0, 0xc($s1)
/* 31D588 802BDA18 8E420004 */  lw        $v0, 4($s2)
/* 31D58C 802BDA1C 34420002 */  ori       $v0, $v0, 2
/* 31D590 802BDA20 0C0AF805 */  jal       func_802BE014
/* 31D594 802BDA24 AE420004 */   sw       $v0, 4($s2)
/* 31D598 802BDA28 0220202D */  daddu     $a0, $s1, $zero
/* 31D59C 802BDA2C 0C00ECF4 */  jal       func_8003B3D0
/* 31D5A0 802BDA30 0200282D */   daddu    $a1, $s0, $zero
/* 31D5A4 802BDA34 24020002 */  addiu     $v0, $zero, 2
/* 31D5A8 802BDA38 AE620074 */  sw        $v0, 0x74($s3)
/* 31D5AC 802BDA3C 080AF707 */  j         .L802BDC1C
/* 31D5B0 802BDA40 AE900000 */   sw       $s0, ($s4)
.L802BDA44:
/* 31D5B4 802BDA44 8E420004 */  lw        $v0, 4($s2)
/* 31D5B8 802BDA48 24040001 */  addiu     $a0, $zero, 1
/* 31D5BC 802BDA4C 00441025 */  or        $v0, $v0, $a0
/* 31D5C0 802BDA50 AE420004 */  sw        $v0, 4($s2)
/* 31D5C4 802BDA54 8E220000 */  lw        $v0, ($s1)
/* 31D5C8 802BDA58 2403F5FF */  addiu     $v1, $zero, -0xa01
/* 31D5CC 802BDA5C 3C01802C */  lui       $at, 0x802c
/* 31D5D0 802BDA60 AC24E30C */  sw        $a0, -0x1cf4($at)
/* 31D5D4 802BDA64 00431024 */  and       $v0, $v0, $v1
/* 31D5D8 802BDA68 AE220000 */  sw        $v0, ($s1)
/* 31D5DC 802BDA6C 24020006 */  addiu     $v0, $zero, 6
/* 31D5E0 802BDA70 A0A0007D */  sb        $zero, 0x7d($a1)
/* 31D5E4 802BDA74 A2A40000 */  sb        $a0, ($s5)
/* 31D5E8 802BDA78 0C03BD38 */  jal       func_800EF4E0
/* 31D5EC 802BDA7C A2A20003 */   sb       $v0, 3($s5)
/* 31D5F0 802BDA80 C6400028 */  lwc1      $f0, 0x28($s2)
/* 31D5F4 802BDA84 3C0140A0 */  lui       $at, 0x40a0
/* 31D5F8 802BDA88 44811000 */  mtc1      $at, $f2
/* 31D5FC 802BDA8C E6200060 */  swc1      $f0, 0x60($s1)
/* 31D600 802BDA90 C640002C */  lwc1      $f0, 0x2c($s2)
/* 31D604 802BDA94 3C020006 */  lui       $v0, 6
/* 31D608 802BDA98 46020000 */  add.s     $f0, $f0, $f2
/* 31D60C 802BDA9C 3C064170 */  lui       $a2, 0x4170
/* 31D610 802BDAA0 34420002 */  ori       $v0, $v0, 2
/* 31D614 802BDAA4 E6200064 */  swc1      $f0, 0x64($s1)
/* 31D618 802BDAA8 C6400030 */  lwc1      $f0, 0x30($s2)
/* 31D61C 802BDAAC 26240060 */  addiu     $a0, $s1, 0x60
/* 31D620 802BDAB0 AE220028 */  sw        $v0, 0x28($s1)
/* 31D624 802BDAB4 E6200068 */  swc1      $f0, 0x68($s1)
/* 31D628 802BDAB8 8E470080 */  lw        $a3, 0x80($s2)
/* 31D62C 802BDABC 0C00A7E7 */  jal       add_vec2D_polar
/* 31D630 802BDAC0 26250068 */   addiu    $a1, $s1, 0x68
/* 31D634 802BDAC4 24020008 */  addiu     $v0, $zero, 8
/* 31D638 802BDAC8 A622008E */  sh        $v0, 0x8e($s1)
/* 31D63C 802BDACC 8E460028 */  lw        $a2, 0x28($s2)
/* 31D640 802BDAD0 8E470030 */  lw        $a3, 0x30($s2)
/* 31D644 802BDAD4 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 31D648 802BDAD8 0C00A720 */  jal       atan2
/* 31D64C 802BDADC C62E0040 */   lwc1     $f14, 0x40($s1)
/* 31D650 802BDAE0 8E820000 */  lw        $v0, ($s4)
/* 31D654 802BDAE4 E620000C */  swc1      $f0, 0xc($s1)
/* 31D658 802BDAE8 080AF706 */  j         .L802BDC18
/* 31D65C 802BDAEC 24420001 */   addiu    $v0, $v0, 1
.L802BDAF0:
/* 31D660 802BDAF0 C6200060 */  lwc1      $f0, 0x60($s1)
/* 31D664 802BDAF4 C62A0038 */  lwc1      $f10, 0x38($s1)
/* 31D668 802BDAF8 8622008E */  lh        $v0, 0x8e($s1)
/* 31D66C 802BDAFC C6240064 */  lwc1      $f4, 0x64($s1)
/* 31D670 802BDB00 C628003C */  lwc1      $f8, 0x3c($s1)
/* 31D674 802BDB04 C6260040 */  lwc1      $f6, 0x40($s1)
/* 31D678 802BDB08 44821000 */  mtc1      $v0, $f2
/* 31D67C 802BDB0C 00000000 */  nop       
/* 31D680 802BDB10 468010A0 */  cvt.s.w   $f2, $f2
/* 31D684 802BDB14 0040202D */  daddu     $a0, $v0, $zero
/* 31D688 802BDB18 460A0001 */  sub.s     $f0, $f0, $f10
/* 31D68C 802BDB1C 0080182D */  daddu     $v1, $a0, $zero
/* 31D690 802BDB20 9622008E */  lhu       $v0, 0x8e($s1)
/* 31D694 802BDB24 46082101 */  sub.s     $f4, $f4, $f8
/* 31D698 802BDB28 2442FFFF */  addiu     $v0, $v0, -1
/* 31D69C 802BDB2C A622008E */  sh        $v0, 0x8e($s1)
/* 31D6A0 802BDB30 46020003 */  div.s     $f0, $f0, $f2
/* 31D6A4 802BDB34 46005280 */  add.s     $f10, $f10, $f0
/* 31D6A8 802BDB38 C6220068 */  lwc1      $f2, 0x68($s1)
/* 31D6AC 802BDB3C 00021400 */  sll       $v0, $v0, 0x10
/* 31D6B0 802BDB40 46061081 */  sub.s     $f2, $f2, $f6
/* 31D6B4 802BDB44 44840000 */  mtc1      $a0, $f0
/* 31D6B8 802BDB48 00000000 */  nop       
/* 31D6BC 802BDB4C 46800020 */  cvt.s.w   $f0, $f0
/* 31D6C0 802BDB50 46002103 */  div.s     $f4, $f4, $f0
/* 31D6C4 802BDB54 46044200 */  add.s     $f8, $f8, $f4
/* 31D6C8 802BDB58 44830000 */  mtc1      $v1, $f0
/* 31D6CC 802BDB5C 00000000 */  nop       
/* 31D6D0 802BDB60 46800020 */  cvt.s.w   $f0, $f0
/* 31D6D4 802BDB64 46001083 */  div.s     $f2, $f2, $f0
/* 31D6D8 802BDB68 46023180 */  add.s     $f6, $f6, $f2
/* 31D6DC 802BDB6C E62A0038 */  swc1      $f10, 0x38($s1)
/* 31D6E0 802BDB70 E628003C */  swc1      $f8, 0x3c($s1)
/* 31D6E4 802BDB74 14400029 */  bnez      $v0, .L802BDC1C
/* 31D6E8 802BDB78 E6260040 */   swc1     $f6, 0x40($s1)
/* 31D6EC 802BDB7C 3C020006 */  lui       $v0, 6
/* 31D6F0 802BDB80 C6400080 */  lwc1      $f0, 0x80($s2)
/* 31D6F4 802BDB84 34420001 */  ori       $v0, $v0, 1
/* 31D6F8 802BDB88 AE220028 */  sw        $v0, 0x28($s1)
/* 31D6FC 802BDB8C E620000C */  swc1      $f0, 0xc($s1)
/* 31D700 802BDB90 8E420004 */  lw        $v0, 4($s2)
/* 31D704 802BDB94 24030006 */  addiu     $v1, $zero, 6
/* 31D708 802BDB98 A2A30003 */  sb        $v1, 3($s5)
/* 31D70C 802BDB9C 34420002 */  ori       $v0, $v0, 2
/* 31D710 802BDBA0 0C0AF805 */  jal       func_802BE014
/* 31D714 802BDBA4 AE420004 */   sw       $v0, 4($s2)
/* 31D718 802BDBA8 24020002 */  addiu     $v0, $zero, 2
/* 31D71C 802BDBAC AE620074 */  sw        $v0, 0x74($s3)
/* 31D720 802BDBB0 080AF706 */  j         .L802BDC18
/* 31D724 802BDBB4 24020001 */   addiu    $v0, $zero, 1
.L802BDBB8:
/* 31D728 802BDBB8 0C0AF81C */  jal       func_802BE070
/* 31D72C 802BDBBC 00000000 */   nop      
/* 31D730 802BDBC0 8E420000 */  lw        $v0, ($s2)
/* 31D734 802BDBC4 30420800 */  andi      $v0, $v0, 0x800
/* 31D738 802BDBC8 14400013 */  bnez      $v0, .L802BDC18
/* 31D73C 802BDBCC 24020002 */   addiu    $v0, $zero, 2
/* 31D740 802BDBD0 824300B4 */  lb        $v1, 0xb4($s2)
/* 31D744 802BDBD4 2402001D */  addiu     $v0, $zero, 0x1d
/* 31D748 802BDBD8 10620010 */  beq       $v1, $v0, .L802BDC1C
/* 31D74C 802BDBDC 00000000 */   nop      
/* 31D750 802BDBE0 8E620074 */  lw        $v0, 0x74($s3)
/* 31D754 802BDBE4 10400003 */  beqz      $v0, .L802BDBF4
/* 31D758 802BDBE8 2442FFFF */   addiu    $v0, $v0, -1
/* 31D75C 802BDBEC 080AF707 */  j         .L802BDC1C
/* 31D760 802BDBF0 AE620074 */   sw       $v0, 0x74($s3)
.L802BDBF4:
/* 31D764 802BDBF4 2C620003 */  sltiu     $v0, $v1, 3
/* 31D768 802BDBF8 14400003 */  bnez      $v0, .L802BDC08
/* 31D76C 802BDBFC 2402000A */   addiu    $v0, $zero, 0xa
/* 31D770 802BDC00 14620006 */  bne       $v1, $v0, .L802BDC1C
/* 31D774 802BDC04 00000000 */   nop      
.L802BDC08:
/* 31D778 802BDC08 8EA2000C */  lw        $v0, 0xc($s5)
/* 31D77C 802BDC0C 30424000 */  andi      $v0, $v0, 0x4000
/* 31D780 802BDC10 10400002 */  beqz      $v0, .L802BDC1C
/* 31D784 802BDC14 24020002 */   addiu    $v0, $zero, 2
.L802BDC18:
/* 31D788 802BDC18 AE820000 */  sw        $v0, ($s4)
.L802BDC1C:
/* 31D78C 802BDC1C 3C10802C */  lui       $s0, 0x802c
/* 31D790 802BDC20 2610E304 */  addiu     $s0, $s0, -0x1cfc
/* 31D794 802BDC24 8E030000 */  lw        $v1, ($s0)
/* 31D798 802BDC28 24020002 */  addiu     $v0, $zero, 2
/* 31D79C 802BDC2C 1462001D */  bne       $v1, $v0, .L802BDCA4
/* 31D7A0 802BDC30 3C050006 */   lui      $a1, 6
/* 31D7A4 802BDC34 34A50001 */  ori       $a1, $a1, 1
/* 31D7A8 802BDC38 0220202D */  daddu     $a0, $s1, $zero
/* 31D7AC 802BDC3C 8E420004 */  lw        $v0, 4($s2)
/* 31D7B0 802BDC40 2403FFFC */  addiu     $v1, $zero, -4
/* 31D7B4 802BDC44 00431024 */  and       $v0, $v0, $v1
/* 31D7B8 802BDC48 AE420004 */  sw        $v0, 4($s2)
/* 31D7BC 802BDC4C 0C03BD17 */  jal       clear_partner_move_history
/* 31D7C0 802BDC50 AE250028 */   sw       $a1, 0x28($s1)
/* 31D7C4 802BDC54 0220202D */  daddu     $a0, $s1, $zero
/* 31D7C8 802BDC58 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 31D7CC 802BDC5C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 31D7D0 802BDC60 0000282D */  daddu     $a1, $zero, $zero
/* 31D7D4 802BDC64 3C01802C */  lui       $at, 0x802c
/* 31D7D8 802BDC68 AC20E30C */  sw        $zero, -0x1cf4($at)
/* 31D7DC 802BDC6C A2A00003 */  sb        $zero, 3($s5)
/* 31D7E0 802BDC70 A2A00000 */  sb        $zero, ($s5)
/* 31D7E4 802BDC74 A040007D */  sb        $zero, 0x7d($v0)
/* 31D7E8 802BDC78 24020014 */  addiu     $v0, $zero, 0x14
/* 31D7EC 802BDC7C 0C00ECF4 */  jal       func_8003B3D0
/* 31D7F0 802BDC80 AE020000 */   sw       $v0, ($s0)
/* 31D7F4 802BDC84 8E420000 */  lw        $v0, ($s2)
/* 31D7F8 802BDC88 30420800 */  andi      $v0, $v0, 0x800
/* 31D7FC 802BDC8C 14400016 */  bnez      $v0, .L802BDCE8
/* 31D800 802BDC90 24020001 */   addiu    $v0, $zero, 1
/* 31D804 802BDC94 0C039769 */  jal       set_action_state
/* 31D808 802BDC98 0000202D */   daddu    $a0, $zero, $zero
/* 31D80C 802BDC9C 080AF73A */  j         .L802BDCE8
/* 31D810 802BDCA0 24020001 */   addiu    $v0, $zero, 1
.L802BDCA4:
/* 31D814 802BDCA4 3C03802C */  lui       $v1, 0x802c
/* 31D818 802BDCA8 8C63E310 */  lw        $v1, -0x1cf0($v1)
/* 31D81C 802BDCAC 1060000E */  beqz      $v1, .L802BDCE8
/* 31D820 802BDCB0 0000102D */   daddu    $v0, $zero, $zero
/* 31D824 802BDCB4 8C62000C */  lw        $v0, 0xc($v1)
/* 31D828 802BDCB8 C6200038 */  lwc1      $f0, 0x38($s1)
/* 31D82C 802BDCBC 3C014150 */  lui       $at, 0x4150
/* 31D830 802BDCC0 44811000 */  mtc1      $at, $f2
/* 31D834 802BDCC4 E4400004 */  swc1      $f0, 4($v0)
/* 31D838 802BDCC8 C620003C */  lwc1      $f0, 0x3c($s1)
/* 31D83C 802BDCCC 46020000 */  add.s     $f0, $f0, $f2
/* 31D840 802BDCD0 8C62000C */  lw        $v0, 0xc($v1)
/* 31D844 802BDCD4 E4400008 */  swc1      $f0, 8($v0)
/* 31D848 802BDCD8 8C62000C */  lw        $v0, 0xc($v1)
/* 31D84C 802BDCDC C6200040 */  lwc1      $f0, 0x40($s1)
/* 31D850 802BDCE0 E440000C */  swc1      $f0, 0xc($v0)
/* 31D854 802BDCE4 0000102D */  daddu     $v0, $zero, $zero
.L802BDCE8:
/* 31D858 802BDCE8 8FBF0028 */  lw        $ra, 0x28($sp)
/* 31D85C 802BDCEC 8FB50024 */  lw        $s5, 0x24($sp)
/* 31D860 802BDCF0 8FB40020 */  lw        $s4, 0x20($sp)
/* 31D864 802BDCF4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 31D868 802BDCF8 8FB20018 */  lw        $s2, 0x18($sp)
/* 31D86C 802BDCFC 8FB10014 */  lw        $s1, 0x14($sp)
/* 31D870 802BDD00 8FB00010 */  lw        $s0, 0x10($sp)
/* 31D874 802BDD04 03E00008 */  jr        $ra
/* 31D878 802BDD08 27BD0030 */   addiu    $sp, $sp, 0x30
