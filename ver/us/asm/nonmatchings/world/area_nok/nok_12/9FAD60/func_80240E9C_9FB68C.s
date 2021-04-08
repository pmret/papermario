.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nok_12_UnkFunc13
/* 9FB68C 80240E9C 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 9FB690 80240EA0 AFB20038 */  sw        $s2, 0x38($sp)
/* 9FB694 80240EA4 0080902D */  daddu     $s2, $a0, $zero
/* 9FB698 80240EA8 AFBF0044 */  sw        $ra, 0x44($sp)
/* 9FB69C 80240EAC AFB40040 */  sw        $s4, 0x40($sp)
/* 9FB6A0 80240EB0 AFB3003C */  sw        $s3, 0x3c($sp)
/* 9FB6A4 80240EB4 AFB10034 */  sw        $s1, 0x34($sp)
/* 9FB6A8 80240EB8 AFB00030 */  sw        $s0, 0x30($sp)
/* 9FB6AC 80240EBC F7B60050 */  sdc1      $f22, 0x50($sp)
/* 9FB6B0 80240EC0 F7B40048 */  sdc1      $f20, 0x48($sp)
/* 9FB6B4 80240EC4 8E510148 */  lw        $s1, 0x148($s2)
/* 9FB6B8 80240EC8 00A0982D */  daddu     $s3, $a1, $zero
/* 9FB6BC 80240ECC 86240008 */  lh        $a0, 8($s1)
/* 9FB6C0 80240ED0 0C00EABB */  jal       get_npc_unsafe
/* 9FB6C4 80240ED4 00C0A02D */   daddu    $s4, $a2, $zero
/* 9FB6C8 80240ED8 8E630014 */  lw        $v1, 0x14($s3)
/* 9FB6CC 80240EDC 04600030 */  bltz      $v1, .L80240FA0
/* 9FB6D0 80240EE0 0040802D */   daddu    $s0, $v0, $zero
/* 9FB6D4 80240EE4 8E420074 */  lw        $v0, 0x74($s2)
/* 9FB6D8 80240EE8 1C40002C */  bgtz      $v0, .L80240F9C
/* 9FB6DC 80240EEC 2442FFFF */   addiu    $v0, $v0, -1
/* 9FB6E0 80240EF0 0280202D */  daddu     $a0, $s4, $zero
/* 9FB6E4 80240EF4 AE430074 */  sw        $v1, 0x74($s2)
/* 9FB6E8 80240EF8 AFA00010 */  sw        $zero, 0x10($sp)
/* 9FB6EC 80240EFC 8E66000C */  lw        $a2, 0xc($s3)
/* 9FB6F0 80240F00 8E670010 */  lw        $a3, 0x10($s3)
/* 9FB6F4 80240F04 0C01242D */  jal       func_800490B4
/* 9FB6F8 80240F08 0220282D */   daddu    $a1, $s1, $zero
/* 9FB6FC 80240F0C 10400021 */  beqz      $v0, .L80240F94
/* 9FB700 80240F10 0000202D */   daddu    $a0, $zero, $zero
/* 9FB704 80240F14 0200282D */  daddu     $a1, $s0, $zero
/* 9FB708 80240F18 0000302D */  daddu     $a2, $zero, $zero
/* 9FB70C 80240F1C 860300A8 */  lh        $v1, 0xa8($s0)
/* 9FB710 80240F20 3C013F80 */  lui       $at, 0x3f80
/* 9FB714 80240F24 44810000 */  mtc1      $at, $f0
/* 9FB718 80240F28 3C014000 */  lui       $at, 0x4000
/* 9FB71C 80240F2C 44811000 */  mtc1      $at, $f2
/* 9FB720 80240F30 3C01C1A0 */  lui       $at, 0xc1a0
/* 9FB724 80240F34 44812000 */  mtc1      $at, $f4
/* 9FB728 80240F38 2402000F */  addiu     $v0, $zero, 0xf
/* 9FB72C 80240F3C AFA2001C */  sw        $v0, 0x1c($sp)
/* 9FB730 80240F40 44833000 */  mtc1      $v1, $f6
/* 9FB734 80240F44 00000000 */  nop
/* 9FB738 80240F48 468031A0 */  cvt.s.w   $f6, $f6
/* 9FB73C 80240F4C 44073000 */  mfc1      $a3, $f6
/* 9FB740 80240F50 27A20028 */  addiu     $v0, $sp, 0x28
/* 9FB744 80240F54 AFA20020 */  sw        $v0, 0x20($sp)
/* 9FB748 80240F58 E7A00010 */  swc1      $f0, 0x10($sp)
/* 9FB74C 80240F5C E7A20014 */  swc1      $f2, 0x14($sp)
/* 9FB750 80240F60 0C01BFA4 */  jal       fx_emote
/* 9FB754 80240F64 E7A40018 */   swc1     $f4, 0x18($sp)
/* 9FB758 80240F68 0200202D */  daddu     $a0, $s0, $zero
/* 9FB75C 80240F6C 240502F4 */  addiu     $a1, $zero, 0x2f4
/* 9FB760 80240F70 0C012530 */  jal       func_800494C0
/* 9FB764 80240F74 3C060020 */   lui      $a2, 0x20
/* 9FB768 80240F78 8E220018 */  lw        $v0, 0x18($s1)
/* 9FB76C 80240F7C 9442002A */  lhu       $v0, 0x2a($v0)
/* 9FB770 80240F80 30420001 */  andi      $v0, $v0, 1
/* 9FB774 80240F84 14400064 */  bnez      $v0, .L80241118
/* 9FB778 80240F88 2402000A */   addiu    $v0, $zero, 0xa
/* 9FB77C 80240F8C 08090446 */  j         .L80241118
/* 9FB780 80240F90 2402000C */   addiu    $v0, $zero, 0xc
.L80240F94:
/* 9FB784 80240F94 8E420074 */  lw        $v0, 0x74($s2)
/* 9FB788 80240F98 2442FFFF */  addiu     $v0, $v0, -1
.L80240F9C:
/* 9FB78C 80240F9C AE420074 */  sw        $v0, 0x74($s2)
.L80240FA0:
/* 9FB790 80240FA0 8602008C */  lh        $v0, 0x8c($s0)
/* 9FB794 80240FA4 1440005D */  bnez      $v0, .L8024111C
/* 9FB798 80240FA8 00000000 */   nop
/* 9FB79C 80240FAC C6000018 */  lwc1      $f0, 0x18($s0)
/* 9FB7A0 80240FB0 3C014010 */  lui       $at, 0x4010
/* 9FB7A4 80240FB4 44811800 */  mtc1      $at, $f3
/* 9FB7A8 80240FB8 44801000 */  mtc1      $zero, $f2
/* 9FB7AC 80240FBC 46000021 */  cvt.d.s   $f0, $f0
/* 9FB7B0 80240FC0 4622003C */  c.lt.d    $f0, $f2
/* 9FB7B4 80240FC4 00000000 */  nop
/* 9FB7B8 80240FC8 45000003 */  bc1f      .L80240FD8
/* 9FB7BC 80240FCC 0200202D */   daddu    $a0, $s0, $zero
/* 9FB7C0 80240FD0 080903F7 */  j         .L80240FDC
/* 9FB7C4 80240FD4 0000282D */   daddu    $a1, $zero, $zero
.L80240FD8:
/* 9FB7C8 80240FD8 24050001 */  addiu     $a1, $zero, 1
.L80240FDC:
/* 9FB7CC 80240FDC 0C00F598 */  jal       func_8003D660
/* 9FB7D0 80240FE0 00000000 */   nop
/* 9FB7D4 80240FE4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9FB7D8 80240FE8 8E430078 */  lw        $v1, 0x78($s2)
/* 9FB7DC 80240FEC C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9FB7E0 80240FF0 00031040 */  sll       $v0, $v1, 1
/* 9FB7E4 80240FF4 00431021 */  addu      $v0, $v0, $v1
/* 9FB7E8 80240FF8 8E2300D0 */  lw        $v1, 0xd0($s1)
/* 9FB7EC 80240FFC 00021080 */  sll       $v0, $v0, 2
/* 9FB7F0 80241000 00431021 */  addu      $v0, $v0, $v1
/* 9FB7F4 80241004 C4560004 */  lwc1      $f22, 4($v0)
/* 9FB7F8 80241008 4680B5A0 */  cvt.s.w   $f22, $f22
/* 9FB7FC 8024100C C454000C */  lwc1      $f20, 0xc($v0)
/* 9FB800 80241010 4680A520 */  cvt.s.w   $f20, $f20
/* 9FB804 80241014 4406B000 */  mfc1      $a2, $f22
/* 9FB808 80241018 4407A000 */  mfc1      $a3, $f20
/* 9FB80C 8024101C 0C00A720 */  jal       atan2
/* 9FB810 80241020 00000000 */   nop
/* 9FB814 80241024 8E050018 */  lw        $a1, 0x18($s0)
/* 9FB818 80241028 44060000 */  mfc1      $a2, $f0
/* 9FB81C 8024102C 0200202D */  daddu     $a0, $s0, $zero
/* 9FB820 80241030 0C00EA95 */  jal       npc_move_heading
/* 9FB824 80241034 AE06000C */   sw       $a2, 0xc($s0)
/* 9FB828 80241038 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9FB82C 8024103C C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9FB830 80241040 4406B000 */  mfc1      $a2, $f22
/* 9FB834 80241044 4407A000 */  mfc1      $a3, $f20
/* 9FB838 80241048 0C00A7B5 */  jal       dist2D
/* 9FB83C 8024104C 00000000 */   nop
/* 9FB840 80241050 C6020018 */  lwc1      $f2, 0x18($s0)
/* 9FB844 80241054 4602003E */  c.le.s    $f0, $f2
/* 9FB848 80241058 00000000 */  nop
/* 9FB84C 8024105C 4500002F */  bc1f      .L8024111C
/* 9FB850 80241060 240403E8 */   addiu    $a0, $zero, 0x3e8
/* 9FB854 80241064 24020002 */  addiu     $v0, $zero, 2
/* 9FB858 80241068 0C00A67F */  jal       rand_int
/* 9FB85C 8024106C AE420070 */   sw       $v0, 0x70($s2)
/* 9FB860 80241070 3C035555 */  lui       $v1, 0x5555
/* 9FB864 80241074 34635556 */  ori       $v1, $v1, 0x5556
/* 9FB868 80241078 00430018 */  mult      $v0, $v1
/* 9FB86C 8024107C 000227C3 */  sra       $a0, $v0, 0x1f
/* 9FB870 80241080 00004010 */  mfhi      $t0
/* 9FB874 80241084 01042023 */  subu      $a0, $t0, $a0
/* 9FB878 80241088 00041840 */  sll       $v1, $a0, 1
/* 9FB87C 8024108C 00641821 */  addu      $v1, $v1, $a0
/* 9FB880 80241090 00431023 */  subu      $v0, $v0, $v1
/* 9FB884 80241094 24430002 */  addiu     $v1, $v0, 2
/* 9FB888 80241098 AE430074 */  sw        $v1, 0x74($s2)
/* 9FB88C 8024109C 8E62002C */  lw        $v0, 0x2c($s3)
/* 9FB890 802410A0 18400009 */  blez      $v0, .L802410C8
/* 9FB894 802410A4 24020004 */   addiu    $v0, $zero, 4
/* 9FB898 802410A8 8E620004 */  lw        $v0, 4($s3)
/* 9FB89C 802410AC 18400006 */  blez      $v0, .L802410C8
/* 9FB8A0 802410B0 24020004 */   addiu    $v0, $zero, 4
/* 9FB8A4 802410B4 8E620008 */  lw        $v0, 8($s3)
/* 9FB8A8 802410B8 18400003 */  blez      $v0, .L802410C8
/* 9FB8AC 802410BC 24020004 */   addiu    $v0, $zero, 4
/* 9FB8B0 802410C0 14600002 */  bnez      $v1, .L802410CC
/* 9FB8B4 802410C4 00000000 */   nop
.L802410C8:
/* 9FB8B8 802410C8 AE420070 */  sw        $v0, 0x70($s2)
.L802410CC:
/* 9FB8BC 802410CC 0C00A67F */  jal       rand_int
/* 9FB8C0 802410D0 24042710 */   addiu    $a0, $zero, 0x2710
/* 9FB8C4 802410D4 3C0351EB */  lui       $v1, 0x51eb
/* 9FB8C8 802410D8 3463851F */  ori       $v1, $v1, 0x851f
/* 9FB8CC 802410DC 00430018 */  mult      $v0, $v1
/* 9FB8D0 802410E0 00021FC3 */  sra       $v1, $v0, 0x1f
/* 9FB8D4 802410E4 00004010 */  mfhi      $t0
/* 9FB8D8 802410E8 00082143 */  sra       $a0, $t0, 5
/* 9FB8DC 802410EC 00832023 */  subu      $a0, $a0, $v1
/* 9FB8E0 802410F0 00041840 */  sll       $v1, $a0, 1
/* 9FB8E4 802410F4 00641821 */  addu      $v1, $v1, $a0
/* 9FB8E8 802410F8 000318C0 */  sll       $v1, $v1, 3
/* 9FB8EC 802410FC 00641821 */  addu      $v1, $v1, $a0
/* 9FB8F0 80241100 00031880 */  sll       $v1, $v1, 2
/* 9FB8F4 80241104 8E640004 */  lw        $a0, 4($s3)
/* 9FB8F8 80241108 00431023 */  subu      $v0, $v0, $v1
/* 9FB8FC 8024110C 0044102A */  slt       $v0, $v0, $a0
/* 9FB900 80241110 10400002 */  beqz      $v0, .L8024111C
/* 9FB904 80241114 24020004 */   addiu    $v0, $zero, 4
.L80241118:
/* 9FB908 80241118 AE420070 */  sw        $v0, 0x70($s2)
.L8024111C:
/* 9FB90C 8024111C 8FBF0044 */  lw        $ra, 0x44($sp)
/* 9FB910 80241120 8FB40040 */  lw        $s4, 0x40($sp)
/* 9FB914 80241124 8FB3003C */  lw        $s3, 0x3c($sp)
/* 9FB918 80241128 8FB20038 */  lw        $s2, 0x38($sp)
/* 9FB91C 8024112C 8FB10034 */  lw        $s1, 0x34($sp)
/* 9FB920 80241130 8FB00030 */  lw        $s0, 0x30($sp)
/* 9FB924 80241134 D7B60050 */  ldc1      $f22, 0x50($sp)
/* 9FB928 80241138 D7B40048 */  ldc1      $f20, 0x48($sp)
/* 9FB92C 8024113C 03E00008 */  jr        $ra
/* 9FB930 80241140 27BD0058 */   addiu    $sp, $sp, 0x58
