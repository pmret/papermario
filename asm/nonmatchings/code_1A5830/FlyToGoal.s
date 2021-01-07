.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel FlyToGoal
/* 1A9F04 8027B624 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 1A9F08 8027B628 AFB20020 */  sw        $s2, 0x20($sp)
/* 1A9F0C 8027B62C 0080902D */  daddu     $s2, $a0, $zero
/* 1A9F10 8027B630 AFBF0024 */  sw        $ra, 0x24($sp)
/* 1A9F14 8027B634 AFB1001C */  sw        $s1, 0x1c($sp)
/* 1A9F18 8027B638 AFB00018 */  sw        $s0, 0x18($sp)
/* 1A9F1C 8027B63C F7B40028 */  sdc1      $f20, 0x28($sp)
/* 1A9F20 8027B640 10A0006C */  beqz      $a1, .L8027B7F4
/* 1A9F24 8027B644 8E51000C */   lw       $s1, 0xc($s2)
/* 1A9F28 8027B648 8E250000 */  lw        $a1, ($s1)
/* 1A9F2C 8027B64C 0C0B1EAF */  jal       get_variable
/* 1A9F30 8027B650 26310004 */   addiu    $s1, $s1, 4
/* 1A9F34 8027B654 0040202D */  daddu     $a0, $v0, $zero
/* 1A9F38 8027B658 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 1A9F3C 8027B65C 14820002 */  bne       $a0, $v0, .L8027B668
/* 1A9F40 8027B660 00000000 */   nop      
/* 1A9F44 8027B664 8E440148 */  lw        $a0, 0x148($s2)
.L8027B668:
/* 1A9F48 8027B668 0C09A75B */  jal       get_actor
/* 1A9F4C 8027B66C 00000000 */   nop      
/* 1A9F50 8027B670 0040802D */  daddu     $s0, $v0, $zero
/* 1A9F54 8027B674 AE500074 */  sw        $s0, 0x74($s2)
/* 1A9F58 8027B678 8E250000 */  lw        $a1, ($s1)
/* 1A9F5C 8027B67C 26310004 */  addiu     $s1, $s1, 4
/* 1A9F60 8027B680 0C0B1EAF */  jal       get_variable
/* 1A9F64 8027B684 0240202D */   daddu    $a0, $s2, $zero
/* 1A9F68 8027B688 A6020070 */  sh        $v0, 0x70($s0)
/* 1A9F6C 8027B68C 8E250000 */  lw        $a1, ($s1)
/* 1A9F70 8027B690 26310004 */  addiu     $s1, $s1, 4
/* 1A9F74 8027B694 0C0B1EAF */  jal       get_variable
/* 1A9F78 8027B698 0240202D */   daddu    $a0, $s2, $zero
/* 1A9F7C 8027B69C A6020072 */  sh        $v0, 0x72($s0)
/* 1A9F80 8027B6A0 8E250000 */  lw        $a1, ($s1)
/* 1A9F84 8027B6A4 0C0B1EAF */  jal       get_variable
/* 1A9F88 8027B6A8 0240202D */   daddu    $a0, $s2, $zero
/* 1A9F8C 8027B6AC AE42007C */  sw        $v0, 0x7c($s2)
/* 1A9F90 8027B6B0 AE000078 */  sw        $zero, 0x78($s0)
/* 1A9F94 8027B6B4 8E43007C */  lw        $v1, 0x7c($s2)
/* 1A9F98 8027B6B8 28620064 */  slti      $v0, $v1, 0x64
/* 1A9F9C 8027B6BC 14400005 */  bnez      $v0, .L8027B6D4
/* 1A9FA0 8027B6C0 2611000C */   addiu    $s1, $s0, 0xc
/* 1A9FA4 8027B6C4 2462FF9C */  addiu     $v0, $v1, -0x64
/* 1A9FA8 8027B6C8 AE42007C */  sw        $v0, 0x7c($s2)
/* 1A9FAC 8027B6CC 24020001 */  addiu     $v0, $zero, 1
/* 1A9FB0 8027B6D0 AE020078 */  sw        $v0, 0x78($s0)
.L8027B6D4:
/* 1A9FB4 8027B6D4 C6000018 */  lwc1      $f0, 0x18($s0)
/* 1A9FB8 8027B6D8 C6060144 */  lwc1      $f6, 0x144($s0)
/* 1A9FBC 8027B6DC 46003081 */  sub.s     $f2, $f6, $f0
/* 1A9FC0 8027B6E0 46021202 */  mul.s     $f8, $f2, $f2
/* 1A9FC4 8027B6E4 00000000 */  nop       
/* 1A9FC8 8027B6E8 C6040148 */  lwc1      $f4, 0x148($s0)
/* 1A9FCC 8027B6EC C600001C */  lwc1      $f0, 0x1c($s0)
/* 1A9FD0 8027B6F0 46002081 */  sub.s     $f2, $f4, $f0
/* 1A9FD4 8027B6F4 46021282 */  mul.s     $f10, $f2, $f2
/* 1A9FD8 8027B6F8 00000000 */  nop       
/* 1A9FDC 8027B6FC C6000020 */  lwc1      $f0, 0x20($s0)
/* 1A9FE0 8027B700 C602014C */  lwc1      $f2, 0x14c($s0)
/* 1A9FE4 8027B704 46001001 */  sub.s     $f0, $f2, $f0
/* 1A9FE8 8027B708 46000002 */  mul.s     $f0, $f0, $f0
/* 1A9FEC 8027B70C 00000000 */  nop       
/* 1A9FF0 8027B710 E606000C */  swc1      $f6, 0xc($s0)
/* 1A9FF4 8027B714 E6060024 */  swc1      $f6, 0x24($s0)
/* 1A9FF8 8027B718 460A4200 */  add.s     $f8, $f8, $f10
/* 1A9FFC 8027B71C E6040010 */  swc1      $f4, 0x10($s0)
/* 1AA000 8027B720 E6040028 */  swc1      $f4, 0x28($s0)
/* 1AA004 8027B724 46004300 */  add.s     $f12, $f8, $f0
/* 1AA008 8027B728 E6020014 */  swc1      $f2, 0x14($s0)
/* 1AA00C 8027B72C E602002C */  swc1      $f2, 0x2c($s0)
/* 1AA010 8027B730 46006084 */  sqrt.s    $f2, $f12
/* 1AA014 8027B734 46021032 */  c.eq.s    $f2, $f2
/* 1AA018 8027B738 00000000 */  nop       
/* 1AA01C 8027B73C 45010004 */  bc1t      .L8027B750
/* 1AA020 8027B740 00000000 */   nop      
/* 1AA024 8027B744 0C0187BC */  jal       sqrtf
/* 1AA028 8027B748 00000000 */   nop      
/* 1AA02C 8027B74C 46000086 */  mov.s     $f2, $f0
.L8027B750:
/* 1AA030 8027B750 86020070 */  lh        $v0, 0x70($s0)
/* 1AA034 8027B754 14400007 */  bnez      $v0, .L8027B774
/* 1AA038 8027B758 E6020058 */   swc1     $f2, 0x58($s0)
/* 1AA03C 8027B75C C600004C */  lwc1      $f0, 0x4c($s0)
/* 1AA040 8027B760 46001003 */  div.s     $f0, $f2, $f0
/* 1AA044 8027B764 4600038D */  trunc.w.s $f14, $f0
/* 1AA048 8027B768 44027000 */  mfc1      $v0, $f14
/* 1AA04C 8027B76C 0809EDE2 */  j         .L8027B788
/* 1AA050 8027B770 A6020070 */   sh       $v0, 0x70($s0)
.L8027B774:
/* 1AA054 8027B774 44820000 */  mtc1      $v0, $f0
/* 1AA058 8027B778 00000000 */  nop       
/* 1AA05C 8027B77C 46800020 */  cvt.s.w   $f0, $f0
/* 1AA060 8027B780 46001003 */  div.s     $f0, $f2, $f0
/* 1AA064 8027B784 E600004C */  swc1      $f0, 0x4c($s0)
.L8027B788:
/* 1AA068 8027B788 86220064 */  lh        $v0, 0x64($s1)
/* 1AA06C 8027B78C 54400003 */  bnel      $v0, $zero, .L8027B79C
/* 1AA070 8027B790 AE200050 */   sw       $zero, 0x50($s1)
.L8027B794:
/* 1AA074 8027B794 0809EEE7 */  j         .L8027BB9C
/* 1AA078 8027B798 24020002 */   addiu    $v0, $zero, 2
.L8027B79C:
/* 1AA07C 8027B79C AE200048 */  sw        $zero, 0x48($s1)
/* 1AA080 8027B7A0 860201B6 */  lh        $v0, 0x1b6($s0)
/* 1AA084 8027B7A4 04420002 */  bltzl     $v0, .L8027B7B0
/* 1AA088 8027B7A8 00021027 */   nor      $v0, $zero, $v0
/* 1AA08C 8027B7AC 24420001 */  addiu     $v0, $v0, 1
.L8027B7B0:
/* 1AA090 8027B7B0 44820000 */  mtc1      $v0, $f0
/* 1AA094 8027B7B4 00000000 */  nop       
/* 1AA098 8027B7B8 46800020 */  cvt.s.w   $f0, $f0
/* 1AA09C 8027B7BC E6200044 */  swc1      $f0, 0x44($s1)
/* 1AA0A0 8027B7C0 8E0201A4 */  lw        $v0, 0x1a4($s0)
/* 1AA0A4 8027B7C4 1040000B */  beqz      $v0, .L8027B7F4
/* 1AA0A8 8027B7C8 00000000 */   nop      
/* 1AA0AC 8027B7CC 8E0201A8 */  lw        $v0, 0x1a8($s0)
/* 1AA0B0 8027B7D0 14400008 */  bnez      $v0, .L8027B7F4
/* 1AA0B4 8027B7D4 00000000 */   nop      
/* 1AA0B8 8027B7D8 C600014C */  lwc1      $f0, 0x14c($s0)
/* 1AA0BC 8027B7DC E7A00010 */  swc1      $f0, 0x10($sp)
/* 1AA0C0 8027B7E0 8E0401A4 */  lw        $a0, 0x1a4($s0)
/* 1AA0C4 8027B7E4 8E060144 */  lw        $a2, 0x144($s0)
/* 1AA0C8 8027B7E8 8E070148 */  lw        $a3, 0x148($s0)
/* 1AA0CC 8027B7EC 0C052757 */  jal       play_sound_at_position
/* 1AA0D0 8027B7F0 0000282D */   daddu    $a1, $zero, $zero
.L8027B7F4:
/* 1AA0D4 8027B7F4 8E500074 */  lw        $s0, 0x74($s2)
/* 1AA0D8 8027B7F8 86020070 */  lh        $v0, 0x70($s0)
/* 1AA0DC 8027B7FC C600005C */  lwc1      $f0, 0x5c($s0)
/* 1AA0E0 8027B800 AFA20010 */  sw        $v0, 0x10($sp)
/* 1AA0E4 8027B804 8E44007C */  lw        $a0, 0x7c($s2)
/* 1AA0E8 8027B808 8E050024 */  lw        $a1, 0x24($s0)
/* 1AA0EC 8027B80C 8E060018 */  lw        $a2, 0x18($s0)
/* 1AA0F0 8027B810 4600038D */  trunc.w.s $f14, $f0
/* 1AA0F4 8027B814 44077000 */  mfc1      $a3, $f14
/* 1AA0F8 8027B818 0C09EC37 */  jal       update_lerp_battle
/* 1AA0FC 8027B81C 2611000C */   addiu    $s1, $s0, 0xc
/* 1AA100 8027B820 C602005C */  lwc1      $f2, 0x5c($s0)
/* 1AA104 8027B824 86020070 */  lh        $v0, 0x70($s0)
/* 1AA108 8027B828 E600000C */  swc1      $f0, 0xc($s0)
/* 1AA10C 8027B82C AFA20010 */  sw        $v0, 0x10($sp)
/* 1AA110 8027B830 8E44007C */  lw        $a0, 0x7c($s2)
/* 1AA114 8027B834 8E050028 */  lw        $a1, 0x28($s0)
/* 1AA118 8027B838 8E06001C */  lw        $a2, 0x1c($s0)
/* 1AA11C 8027B83C 4600138D */  trunc.w.s $f14, $f2
/* 1AA120 8027B840 44077000 */  mfc1      $a3, $f14
/* 1AA124 8027B844 0C09EC37 */  jal       update_lerp_battle
/* 1AA128 8027B848 00000000 */   nop      
/* 1AA12C 8027B84C C602005C */  lwc1      $f2, 0x5c($s0)
/* 1AA130 8027B850 86020070 */  lh        $v0, 0x70($s0)
/* 1AA134 8027B854 E6000010 */  swc1      $f0, 0x10($s0)
/* 1AA138 8027B858 AFA20010 */  sw        $v0, 0x10($sp)
/* 1AA13C 8027B85C 8E44007C */  lw        $a0, 0x7c($s2)
/* 1AA140 8027B860 8E05002C */  lw        $a1, 0x2c($s0)
/* 1AA144 8027B864 8E060020 */  lw        $a2, 0x20($s0)
/* 1AA148 8027B868 4600138D */  trunc.w.s $f14, $f2
/* 1AA14C 8027B86C 44077000 */  mfc1      $a3, $f14
/* 1AA150 8027B870 0C09EC37 */  jal       update_lerp_battle
/* 1AA154 8027B874 00000000 */   nop      
/* 1AA158 8027B878 8E020078 */  lw        $v0, 0x78($s0)
/* 1AA15C 8027B87C 10400012 */  beqz      $v0, .L8027B8C8
/* 1AA160 8027B880 E6000014 */   swc1     $f0, 0x14($s0)
/* 1AA164 8027B884 C6000010 */  lwc1      $f0, 0x10($s0)
/* 1AA168 8027B888 44801000 */  mtc1      $zero, $f2
/* 1AA16C 8027B88C 00000000 */  nop       
/* 1AA170 8027B890 4602003C */  c.lt.s    $f0, $f2
/* 1AA174 8027B894 00000000 */  nop       
/* 1AA178 8027B898 4500000B */  bc1f      .L8027B8C8
/* 1AA17C 8027B89C 00000000 */   nop      
/* 1AA180 8027B8A0 86020070 */  lh        $v0, 0x70($s0)
/* 1AA184 8027B8A4 E602001C */  swc1      $f2, 0x1c($s0)
/* 1AA188 8027B8A8 C602000C */  lwc1      $f2, 0xc($s0)
/* 1AA18C 8027B8AC C6040014 */  lwc1      $f4, 0x14($s0)
/* 1AA190 8027B8B0 44820000 */  mtc1      $v0, $f0
/* 1AA194 8027B8B4 00000000 */  nop       
/* 1AA198 8027B8B8 46800020 */  cvt.s.w   $f0, $f0
/* 1AA19C 8027B8BC E600005C */  swc1      $f0, 0x5c($s0)
/* 1AA1A0 8027B8C0 E6020018 */  swc1      $f2, 0x18($s0)
/* 1AA1A4 8027B8C4 E6040020 */  swc1      $f4, 0x20($s0)
.L8027B8C8:
/* 1AA1A8 8027B8C8 C6200050 */  lwc1      $f0, 0x50($s1)
/* 1AA1AC 8027B8CC 3C013F80 */  lui       $at, 0x3f80
/* 1AA1B0 8027B8D0 44812000 */  mtc1      $at, $f4
/* 1AA1B4 8027B8D4 86220064 */  lh        $v0, 0x64($s1)
/* 1AA1B8 8027B8D8 46040000 */  add.s     $f0, $f0, $f4
/* 1AA1BC 8027B8DC 44821000 */  mtc1      $v0, $f2
/* 1AA1C0 8027B8E0 00000000 */  nop       
/* 1AA1C4 8027B8E4 468010A0 */  cvt.s.w   $f2, $f2
/* 1AA1C8 8027B8E8 4600103C */  c.lt.s    $f2, $f0
/* 1AA1CC 8027B8EC 00000000 */  nop       
/* 1AA1D0 8027B8F0 45000010 */  bc1f      .L8027B934
/* 1AA1D4 8027B8F4 E6200050 */   swc1     $f0, 0x50($s1)
/* 1AA1D8 8027B8F8 C620000C */  lwc1      $f0, 0xc($s1)
/* 1AA1DC 8027B8FC 8E0401A4 */  lw        $a0, 0x1a4($s0)
/* 1AA1E0 8027B900 E6000144 */  swc1      $f0, 0x144($s0)
/* 1AA1E4 8027B904 C6200010 */  lwc1      $f0, 0x10($s1)
/* 1AA1E8 8027B908 E6000148 */  swc1      $f0, 0x148($s0)
/* 1AA1EC 8027B90C C6200014 */  lwc1      $f0, 0x14($s1)
/* 1AA1F0 8027B910 1080FFA0 */  beqz      $a0, .L8027B794
/* 1AA1F4 8027B914 E600014C */   swc1     $f0, 0x14c($s0)
/* 1AA1F8 8027B918 8E0201A8 */  lw        $v0, 0x1a8($s0)
/* 1AA1FC 8027B91C 1440009F */  bnez      $v0, .L8027BB9C
/* 1AA200 8027B920 24020002 */   addiu    $v0, $zero, 2
/* 1AA204 8027B924 0C0154F0 */  jal       func_800553C0
/* 1AA208 8027B928 00000000 */   nop      
/* 1AA20C 8027B92C 0809EEE7 */  j         .L8027BB9C
/* 1AA210 8027B930 24020002 */   addiu    $v0, $zero, 2
.L8027B934:
/* 1AA214 8027B934 8E0201A4 */  lw        $v0, 0x1a4($s0)
/* 1AA218 8027B938 10400047 */  beqz      $v0, .L8027BA58
/* 1AA21C 8027B93C 00000000 */   nop      
/* 1AA220 8027B940 8E0201A8 */  lw        $v0, 0x1a8($s0)
/* 1AA224 8027B944 10400044 */  beqz      $v0, .L8027BA58
/* 1AA228 8027B948 00000000 */   nop      
/* 1AA22C 8027B94C 860201B6 */  lh        $v0, 0x1b6($s0)
/* 1AA230 8027B950 0440001C */  bltz      $v0, .L8027B9C4
/* 1AA234 8027B954 00000000 */   nop      
/* 1AA238 8027B958 C6220044 */  lwc1      $f2, 0x44($s1)
/* 1AA23C 8027B95C C6200040 */  lwc1      $f0, 0x40($s1)
/* 1AA240 8027B960 46001080 */  add.s     $f2, $f2, $f0
/* 1AA244 8027B964 E6220044 */  swc1      $f2, 0x44($s1)
/* 1AA248 8027B968 860201B6 */  lh        $v0, 0x1b6($s0)
/* 1AA24C 8027B96C 44820000 */  mtc1      $v0, $f0
/* 1AA250 8027B970 00000000 */  nop       
/* 1AA254 8027B974 46800020 */  cvt.s.w   $f0, $f0
/* 1AA258 8027B978 4602003C */  c.lt.s    $f0, $f2
/* 1AA25C 8027B97C 00000000 */  nop       
/* 1AA260 8027B980 45000035 */  bc1f      .L8027BA58
/* 1AA264 8027B984 00000000 */   nop      
/* 1AA268 8027B988 92020135 */  lbu       $v0, 0x135($s0)
/* 1AA26C 8027B98C 24420001 */  addiu     $v0, $v0, 1
/* 1AA270 8027B990 A2020135 */  sb        $v0, 0x135($s0)
/* 1AA274 8027B994 AE200044 */  sw        $zero, 0x44($s1)
/* 1AA278 8027B998 92020135 */  lbu       $v0, 0x135($s0)
/* 1AA27C 8027B99C 30420001 */  andi      $v0, $v0, 1
/* 1AA280 8027B9A0 10400023 */  beqz      $v0, .L8027BA30
/* 1AA284 8027B9A4 00000000 */   nop      
/* 1AA288 8027B9A8 8E0201A4 */  lw        $v0, 0x1a4($s0)
/* 1AA28C 8027B9AC 1040002A */  beqz      $v0, .L8027BA58
/* 1AA290 8027B9B0 00000000 */   nop      
/* 1AA294 8027B9B4 C600014C */  lwc1      $f0, 0x14c($s0)
/* 1AA298 8027B9B8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1AA29C 8027B9BC 0809EE92 */  j         .L8027BA48
/* 1AA2A0 8027B9C0 8E0401A4 */   lw       $a0, 0x1a4($s0)
.L8027B9C4:
/* 1AA2A4 8027B9C4 C6200044 */  lwc1      $f0, 0x44($s1)
/* 1AA2A8 8027B9C8 46040000 */  add.s     $f0, $f0, $f4
/* 1AA2AC 8027B9CC E6200044 */  swc1      $f0, 0x44($s1)
/* 1AA2B0 8027B9D0 860201B6 */  lh        $v0, 0x1b6($s0)
/* 1AA2B4 8027B9D4 00021023 */  negu      $v0, $v0
/* 1AA2B8 8027B9D8 44821000 */  mtc1      $v0, $f2
/* 1AA2BC 8027B9DC 00000000 */  nop       
/* 1AA2C0 8027B9E0 468010A0 */  cvt.s.w   $f2, $f2
/* 1AA2C4 8027B9E4 4600103E */  c.le.s    $f2, $f0
/* 1AA2C8 8027B9E8 00000000 */  nop       
/* 1AA2CC 8027B9EC 4500001A */  bc1f      .L8027BA58
/* 1AA2D0 8027B9F0 00000000 */   nop      
/* 1AA2D4 8027B9F4 92020135 */  lbu       $v0, 0x135($s0)
/* 1AA2D8 8027B9F8 24420001 */  addiu     $v0, $v0, 1
/* 1AA2DC 8027B9FC A2020135 */  sb        $v0, 0x135($s0)
/* 1AA2E0 8027BA00 AE200044 */  sw        $zero, 0x44($s1)
/* 1AA2E4 8027BA04 92020135 */  lbu       $v0, 0x135($s0)
/* 1AA2E8 8027BA08 30420001 */  andi      $v0, $v0, 1
/* 1AA2EC 8027BA0C 10400008 */  beqz      $v0, .L8027BA30
/* 1AA2F0 8027BA10 00000000 */   nop      
/* 1AA2F4 8027BA14 8E0201A4 */  lw        $v0, 0x1a4($s0)
/* 1AA2F8 8027BA18 1040000F */  beqz      $v0, .L8027BA58
/* 1AA2FC 8027BA1C 00000000 */   nop      
/* 1AA300 8027BA20 C600014C */  lwc1      $f0, 0x14c($s0)
/* 1AA304 8027BA24 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1AA308 8027BA28 0809EE92 */  j         .L8027BA48
/* 1AA30C 8027BA2C 8E0401A4 */   lw       $a0, 0x1a4($s0)
.L8027BA30:
/* 1AA310 8027BA30 8E0201A8 */  lw        $v0, 0x1a8($s0)
/* 1AA314 8027BA34 10400008 */  beqz      $v0, .L8027BA58
/* 1AA318 8027BA38 00000000 */   nop      
/* 1AA31C 8027BA3C C600014C */  lwc1      $f0, 0x14c($s0)
/* 1AA320 8027BA40 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1AA324 8027BA44 8E0401A8 */  lw        $a0, 0x1a8($s0)
.L8027BA48:
/* 1AA328 8027BA48 8E060144 */  lw        $a2, 0x144($s0)
/* 1AA32C 8027BA4C 8E070148 */  lw        $a3, 0x148($s0)
/* 1AA330 8027BA50 0C052757 */  jal       play_sound_at_position
/* 1AA334 8027BA54 0000282D */   daddu    $a1, $zero, $zero
.L8027BA58:
/* 1AA338 8027BA58 C622000C */  lwc1      $f2, 0xc($s1)
/* 1AA33C 8027BA5C C6200000 */  lwc1      $f0, ($s1)
/* 1AA340 8027BA60 46001081 */  sub.s     $f2, $f2, $f0
/* 1AA344 8027BA64 46021102 */  mul.s     $f4, $f2, $f2
/* 1AA348 8027BA68 00000000 */  nop       
/* 1AA34C 8027BA6C C6200004 */  lwc1      $f0, 4($s1)
/* 1AA350 8027BA70 C6220010 */  lwc1      $f2, 0x10($s1)
/* 1AA354 8027BA74 46001081 */  sub.s     $f2, $f2, $f0
/* 1AA358 8027BA78 46021182 */  mul.s     $f6, $f2, $f2
/* 1AA35C 8027BA7C 00000000 */  nop       
/* 1AA360 8027BA80 C6200008 */  lwc1      $f0, 8($s1)
/* 1AA364 8027BA84 C6220014 */  lwc1      $f2, 0x14($s1)
/* 1AA368 8027BA88 46001001 */  sub.s     $f0, $f2, $f0
/* 1AA36C 8027BA8C 46000002 */  mul.s     $f0, $f0, $f0
/* 1AA370 8027BA90 00000000 */  nop       
/* 1AA374 8027BA94 46062100 */  add.s     $f4, $f4, $f6
/* 1AA378 8027BA98 46002300 */  add.s     $f12, $f4, $f0
/* 1AA37C 8027BA9C 46006004 */  sqrt.s    $f0, $f12
/* 1AA380 8027BAA0 46000032 */  c.eq.s    $f0, $f0
/* 1AA384 8027BAA4 00000000 */  nop       
/* 1AA388 8027BAA8 45010003 */  bc1t      .L8027BAB8
/* 1AA38C 8027BAAC 00000000 */   nop      
/* 1AA390 8027BAB0 0C0187BC */  jal       sqrtf
/* 1AA394 8027BAB4 00000000 */   nop      
.L8027BAB8:
/* 1AA398 8027BAB8 4480A000 */  mtc1      $zero, $f20
/* 1AA39C 8027BABC 46000086 */  mov.s     $f2, $f0
/* 1AA3A0 8027BAC0 46141032 */  c.eq.s    $f2, $f20
/* 1AA3A4 8027BAC4 00000000 */  nop       
/* 1AA3A8 8027BAC8 45000003 */  bc1f      .L8027BAD8
/* 1AA3AC 8027BACC 00000000 */   nop      
/* 1AA3B0 8027BAD0 3C013F80 */  lui       $at, 0x3f80
/* 1AA3B4 8027BAD4 44811000 */  mtc1      $at, $f2
.L8027BAD8:
/* 1AA3B8 8027BAD8 C620004C */  lwc1      $f0, 0x4c($s1)
/* 1AA3BC 8027BADC 46140032 */  c.eq.s    $f0, $f20
/* 1AA3C0 8027BAE0 00000000 */  nop       
/* 1AA3C4 8027BAE4 45000006 */  bc1f      .L8027BB00
/* 1AA3C8 8027BAE8 00000000 */   nop      
/* 1AA3CC 8027BAEC 3C013F80 */  lui       $at, 0x3f80
/* 1AA3D0 8027BAF0 44810000 */  mtc1      $at, $f0
/* 1AA3D4 8027BAF4 00000000 */  nop       
/* 1AA3D8 8027BAF8 E620004C */  swc1      $f0, 0x4c($s1)
/* 1AA3DC 8027BAFC C620004C */  lwc1      $f0, 0x4c($s1)
.L8027BB00:
/* 1AA3E0 8027BB00 3C013FF0 */  lui       $at, 0x3ff0
/* 1AA3E4 8027BB04 44816800 */  mtc1      $at, $f13
/* 1AA3E8 8027BB08 44806000 */  mtc1      $zero, $f12
/* 1AA3EC 8027BB0C 46001003 */  div.s     $f0, $f2, $f0
/* 1AA3F0 8027BB10 46000021 */  cvt.d.s   $f0, $f0
/* 1AA3F4 8027BB14 46206301 */  sub.d     $f12, $f12, $f0
/* 1AA3F8 8027BB18 3C01802A */  lui       $at, %hi(D_8029DA10)
/* 1AA3FC 8027BB1C D420DA10 */  ldc1      $f0, %lo(D_8029DA10)($at)
/* 1AA400 8027BB20 46206302 */  mul.d     $f12, $f12, $f0
/* 1AA404 8027BB24 00000000 */  nop       
/* 1AA408 8027BB28 0C00A8BB */  jal       sin_deg
/* 1AA40C 8027BB2C 46206320 */   cvt.s.d  $f12, $f12
/* 1AA410 8027BB30 86230066 */  lh        $v1, 0x66($s1)
/* 1AA414 8027BB34 14600002 */  bnez      $v1, .L8027BB40
/* 1AA418 8027BB38 46000106 */   mov.s    $f4, $f0
/* 1AA41C 8027BB3C 4600A106 */  mov.s     $f4, $f20
.L8027BB40:
/* 1AA420 8027BB40 04610007 */  bgez      $v1, .L8027BB60
/* 1AA424 8027BB44 00031023 */   negu     $v0, $v1
/* 1AA428 8027BB48 44821000 */  mtc1      $v0, $f2
/* 1AA42C 8027BB4C 00000000 */  nop       
/* 1AA430 8027BB50 468010A0 */  cvt.s.w   $f2, $f2
/* 1AA434 8027BB54 46002007 */  neg.s     $f0, $f4
/* 1AA438 8027BB58 46020102 */  mul.s     $f4, $f0, $f2
/* 1AA43C 8027BB5C 00000000 */  nop       
.L8027BB60:
/* 1AA440 8027BB60 18600006 */  blez      $v1, .L8027BB7C
/* 1AA444 8027BB64 00000000 */   nop      
/* 1AA448 8027BB68 44830000 */  mtc1      $v1, $f0
/* 1AA44C 8027BB6C 00000000 */  nop       
/* 1AA450 8027BB70 46800020 */  cvt.s.w   $f0, $f0
/* 1AA454 8027BB74 46002102 */  mul.s     $f4, $f4, $f0
/* 1AA458 8027BB78 00000000 */  nop       
.L8027BB7C:
/* 1AA45C 8027BB7C C6200000 */  lwc1      $f0, ($s1)
/* 1AA460 8027BB80 E6000144 */  swc1      $f0, 0x144($s0)
/* 1AA464 8027BB84 C6200004 */  lwc1      $f0, 4($s1)
/* 1AA468 8027BB88 46040000 */  add.s     $f0, $f0, $f4
/* 1AA46C 8027BB8C E6000148 */  swc1      $f0, 0x148($s0)
/* 1AA470 8027BB90 C6200008 */  lwc1      $f0, 8($s1)
/* 1AA474 8027BB94 0000102D */  daddu     $v0, $zero, $zero
/* 1AA478 8027BB98 E600014C */  swc1      $f0, 0x14c($s0)
.L8027BB9C:
/* 1AA47C 8027BB9C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 1AA480 8027BBA0 8FB20020 */  lw        $s2, 0x20($sp)
/* 1AA484 8027BBA4 8FB1001C */  lw        $s1, 0x1c($sp)
/* 1AA488 8027BBA8 8FB00018 */  lw        $s0, 0x18($sp)
/* 1AA48C 8027BBAC D7B40028 */  ldc1      $f20, 0x28($sp)
/* 1AA490 8027BBB0 03E00008 */  jr        $ra
/* 1AA494 8027BBB4 27BD0030 */   addiu    $sp, $sp, 0x30
