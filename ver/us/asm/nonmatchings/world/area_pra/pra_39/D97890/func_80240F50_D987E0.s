.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel jtbl_802420D0_D99960
.word L802410B0_D98940, L802410DC_D9896C, L802416AC_D98F3C, L802416AC_D98F3C, L802416AC_D98F3C, L802416AC_D98F3C, L802416AC_D98F3C, L802416AC_D98F3C, L802416AC_D98F3C, L802416AC_D98F3C, L80241148_D989D8, L8024124C_D98ADC, L80241334_D98BC4, L80241440_D98CD0, L80241664_D98EF4, L80241694_D98F24

dlabel D_80242110_D999A0
.double 0.7

dlabel D_80242118_D999A8
.double 0.7

.section .text

glabel func_80240F50_D987E0
/* D987E0 80240F50 27BDFF88 */  addiu     $sp, $sp, -0x78
/* D987E4 80240F54 AFB3005C */  sw        $s3, 0x5c($sp)
/* D987E8 80240F58 0080982D */  daddu     $s3, $a0, $zero
/* D987EC 80240F5C AFBF006C */  sw        $ra, 0x6c($sp)
/* D987F0 80240F60 AFB60068 */  sw        $s6, 0x68($sp)
/* D987F4 80240F64 AFB50064 */  sw        $s5, 0x64($sp)
/* D987F8 80240F68 AFB40060 */  sw        $s4, 0x60($sp)
/* D987FC 80240F6C AFB20058 */  sw        $s2, 0x58($sp)
/* D98800 80240F70 AFB10054 */  sw        $s1, 0x54($sp)
/* D98804 80240F74 AFB00050 */  sw        $s0, 0x50($sp)
/* D98808 80240F78 F7B40070 */  sdc1      $f20, 0x70($sp)
/* D9880C 80240F7C 8E720148 */  lw        $s2, 0x148($s3)
/* D98810 80240F80 86440008 */  lh        $a0, 8($s2)
/* D98814 80240F84 0C00EABB */  jal       get_npc_unsafe
/* D98818 80240F88 00A0802D */   daddu    $s0, $a1, $zero
/* D9881C 80240F8C 8E63000C */  lw        $v1, 0xc($s3)
/* D98820 80240F90 0260202D */  daddu     $a0, $s3, $zero
/* D98824 80240F94 8C650000 */  lw        $a1, ($v1)
/* D98828 80240F98 0C0B1EAF */  jal       evt_get_variable
/* D9882C 80240F9C 0040882D */   daddu    $s1, $v0, $zero
/* D98830 80240FA0 AFA00020 */  sw        $zero, 0x20($sp)
/* D98834 80240FA4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D98838 80240FA8 8C630030 */  lw        $v1, 0x30($v1)
/* D9883C 80240FAC AFA30024 */  sw        $v1, 0x24($sp)
/* D98840 80240FB0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D98844 80240FB4 8C63001C */  lw        $v1, 0x1c($v1)
/* D98848 80240FB8 AFA30028 */  sw        $v1, 0x28($sp)
/* D9884C 80240FBC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D98850 80240FC0 8C630024 */  lw        $v1, 0x24($v1)
/* D98854 80240FC4 AFA3002C */  sw        $v1, 0x2c($sp)
/* D98858 80240FC8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D9885C 80240FCC 3C158011 */  lui       $s5, %hi(gPlayerStatus)
/* D98860 80240FD0 26B5EFC8 */  addiu     $s5, $s5, %lo(gPlayerStatus)
/* D98864 80240FD4 8C630028 */  lw        $v1, 0x28($v1)
/* D98868 80240FD8 27B60020 */  addiu     $s6, $sp, 0x20
/* D9886C 80240FDC AFA30030 */  sw        $v1, 0x30($sp)
/* D98870 80240FE0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D98874 80240FE4 3C0143FA */  lui       $at, 0x43fa
/* D98878 80240FE8 44810000 */  mtc1      $at, $f0
/* D9887C 80240FEC 8C63002C */  lw        $v1, 0x2c($v1)
/* D98880 80240FF0 0040A02D */  daddu     $s4, $v0, $zero
/* D98884 80240FF4 E7A00038 */  swc1      $f0, 0x38($sp)
/* D98888 80240FF8 A7A0003C */  sh        $zero, 0x3c($sp)
/* D9888C 80240FFC 12000019 */  beqz      $s0, .L80241064
/* D98890 80241000 AFA30034 */   sw       $v1, 0x34($sp)
/* D98894 80241004 27A50040 */  addiu     $a1, $sp, 0x40
/* D98898 80241008 27A60044 */  addiu     $a2, $sp, 0x44
/* D9889C 8024100C AE600070 */  sw        $zero, 0x70($s3)
/* D988A0 80241010 A620008E */  sh        $zero, 0x8e($s1)
/* D988A4 80241014 8E4200B0 */  lw        $v0, 0xb0($s2)
/* D988A8 80241018 3C01447A */  lui       $at, 0x447a
/* D988AC 8024101C 44810000 */  mtc1      $at, $f0
/* D988B0 80241020 34420010 */  ori       $v0, $v0, 0x10
/* D988B4 80241024 AE4200B0 */  sw        $v0, 0xb0($s2)
/* D988B8 80241028 C6220038 */  lwc1      $f2, 0x38($s1)
/* D988BC 8024102C C624003C */  lwc1      $f4, 0x3c($s1)
/* D988C0 80241030 C6260040 */  lwc1      $f6, 0x40($s1)
/* D988C4 80241034 27A2004C */  addiu     $v0, $sp, 0x4c
/* D988C8 80241038 E7A0004C */  swc1      $f0, 0x4c($sp)
/* D988CC 8024103C E7A20040 */  swc1      $f2, 0x40($sp)
/* D988D0 80241040 E7A40044 */  swc1      $f4, 0x44($sp)
/* D988D4 80241044 E7A60048 */  swc1      $f6, 0x48($sp)
/* D988D8 80241048 AFA20010 */  sw        $v0, 0x10($sp)
/* D988DC 8024104C 8E240080 */  lw        $a0, 0x80($s1)
/* D988E0 80241050 0C0372DF */  jal       npc_raycast_down_sides
/* D988E4 80241054 27A70048 */   addiu    $a3, $sp, 0x48
/* D988E8 80241058 C7A00044 */  lwc1      $f0, 0x44($sp)
/* D988EC 8024105C 4600028D */  trunc.w.s $f10, $f0
/* D988F0 80241060 E64A0070 */  swc1      $f10, 0x70($s2)
.L80241064:
/* D988F4 80241064 8E4300B0 */  lw        $v1, 0xb0($s2)
/* D988F8 80241068 30620004 */  andi      $v0, $v1, 4
/* D988FC 8024106C 10400007 */  beqz      $v0, .L8024108C
/* D98900 80241070 00000000 */   nop
/* D98904 80241074 824200B4 */  lb        $v0, 0xb4($s2)
/* D98908 80241078 1440018D */  bnez      $v0, .L802416B0
/* D9890C 8024107C 0000102D */   daddu    $v0, $zero, $zero
/* D98910 80241080 2402FFFB */  addiu     $v0, $zero, -5
/* D98914 80241084 00621024 */  and       $v0, $v1, $v0
/* D98918 80241088 AE4200B0 */  sw        $v0, 0xb0($s2)
.L8024108C:
/* D9891C 8024108C 8E630070 */  lw        $v1, 0x70($s3)
/* D98920 80241090 2C620010 */  sltiu     $v0, $v1, 0x10
/* D98924 80241094 10400185 */  beqz      $v0, L802416AC_D98F3C
/* D98928 80241098 00031080 */   sll      $v0, $v1, 2
/* D9892C 8024109C 3C018024 */  lui       $at, %hi(jtbl_802420D0_D99960)
/* D98930 802410A0 00220821 */  addu      $at, $at, $v0
/* D98934 802410A4 8C2220D0 */  lw        $v0, %lo(jtbl_802420D0_D99960)($at)
/* D98938 802410A8 00400008 */  jr        $v0
/* D9893C 802410AC 00000000 */   nop
dlabel L802410B0_D98940
/* D98940 802410B0 8E4200CC */  lw        $v0, 0xcc($s2)
/* D98944 802410B4 922300A9 */  lbu       $v1, 0xa9($s1)
/* D98948 802410B8 8C440000 */  lw        $a0, ($v0)
/* D9894C 802410BC 8E220000 */  lw        $v0, ($s1)
/* D98950 802410C0 A22300AB */  sb        $v1, 0xab($s1)
/* D98954 802410C4 34420080 */  ori       $v0, $v0, 0x80
/* D98958 802410C8 AE220000 */  sw        $v0, ($s1)
/* D9895C 802410CC 24020001 */  addiu     $v0, $zero, 1
/* D98960 802410D0 AE240028 */  sw        $a0, 0x28($s1)
/* D98964 802410D4 AE600074 */  sw        $zero, 0x74($s3)
/* D98968 802410D8 AE620070 */  sw        $v0, 0x70($s3)
dlabel L802410DC_D9896C
/* D9896C 802410DC 8E830014 */  lw        $v1, 0x14($s4)
/* D98970 802410E0 04600015 */  bltz      $v1, .L80241138
/* D98974 802410E4 00000000 */   nop
/* D98978 802410E8 8E620074 */  lw        $v0, 0x74($s3)
/* D9897C 802410EC 1C400011 */  bgtz      $v0, .L80241134
/* D98980 802410F0 2442FFFF */   addiu    $v0, $v0, -1
/* D98984 802410F4 02C0202D */  daddu     $a0, $s6, $zero
/* D98988 802410F8 AE630074 */  sw        $v1, 0x74($s3)
/* D9898C 802410FC AFA00010 */  sw        $zero, 0x10($sp)
/* D98990 80241100 8E86000C */  lw        $a2, 0xc($s4)
/* D98994 80241104 8E870010 */  lw        $a3, 0x10($s4)
/* D98998 80241108 0C01242D */  jal       func_800490B4
/* D9899C 8024110C 0240282D */   daddu    $a1, $s2, $zero
/* D989A0 80241110 10400006 */  beqz      $v0, .L8024112C
/* D989A4 80241114 0220202D */   daddu    $a0, $s1, $zero
/* D989A8 80241118 240502F4 */  addiu     $a1, $zero, 0x2f4
/* D989AC 8024111C 0C012530 */  jal       ai_enemy_play_sound
/* D989B0 80241120 3C060020 */   lui      $a2, 0x20
/* D989B4 80241124 2402000A */  addiu     $v0, $zero, 0xa
/* D989B8 80241128 AE620070 */  sw        $v0, 0x70($s3)
.L8024112C:
/* D989BC 8024112C 8E620074 */  lw        $v0, 0x74($s3)
/* D989C0 80241130 2442FFFF */  addiu     $v0, $v0, -1
.L80241134:
/* D989C4 80241134 AE620074 */  sw        $v0, 0x74($s3)
.L80241138:
/* D989C8 80241138 8E630070 */  lw        $v1, 0x70($s3)
/* D989CC 8024113C 2402000A */  addiu     $v0, $zero, 0xa
/* D989D0 80241140 1462015B */  bne       $v1, $v0, .L802416B0
/* D989D4 80241144 0000102D */   daddu    $v0, $zero, $zero
dlabel L80241148_D989D8
/* D989D8 80241148 C62C0038 */  lwc1      $f12, 0x38($s1)
/* D989DC 8024114C 8E4200CC */  lw        $v0, 0xcc($s2)
/* D989E0 80241150 C62E0040 */  lwc1      $f14, 0x40($s1)
/* D989E4 80241154 8C42000C */  lw        $v0, 0xc($v0)
/* D989E8 80241158 AE220028 */  sw        $v0, 0x28($s1)
/* D989EC 8024115C 8EA60028 */  lw        $a2, 0x28($s5)
/* D989F0 80241160 0C00A720 */  jal       atan2
/* D989F4 80241164 8EA70030 */   lw       $a3, 0x30($s5)
/* D989F8 80241168 3C013FA6 */  lui       $at, 0x3fa6
/* D989FC 8024116C 34216666 */  ori       $at, $at, 0x6666
/* D98A00 80241170 44811000 */  mtc1      $at, $f2
/* D98A04 80241174 27A50040 */  addiu     $a1, $sp, 0x40
/* D98A08 80241178 E6200010 */  swc1      $f0, 0x10($s1)
/* D98A0C 8024117C C6200038 */  lwc1      $f0, 0x38($s1)
/* D98A10 80241180 C6240040 */  lwc1      $f4, 0x40($s1)
/* D98A14 80241184 3C01447A */  lui       $at, 0x447a
/* D98A18 80241188 44813000 */  mtc1      $at, $f6
/* D98A1C 8024118C 27A60044 */  addiu     $a2, $sp, 0x44
/* D98A20 80241190 AE20001C */  sw        $zero, 0x1c($s1)
/* D98A24 80241194 E6220014 */  swc1      $f2, 0x14($s1)
/* D98A28 80241198 C6880000 */  lwc1      $f8, ($s4)
/* D98A2C 8024119C C622003C */  lwc1      $f2, 0x3c($s1)
/* D98A30 802411A0 27A2004C */  addiu     $v0, $sp, 0x4c
/* D98A34 802411A4 E7A00040 */  swc1      $f0, 0x40($sp)
/* D98A38 802411A8 E7A40048 */  swc1      $f4, 0x48($sp)
/* D98A3C 802411AC E7A6004C */  swc1      $f6, 0x4c($sp)
/* D98A40 802411B0 E7A20044 */  swc1      $f2, 0x44($sp)
/* D98A44 802411B4 E6280018 */  swc1      $f8, 0x18($s1)
/* D98A48 802411B8 AFA20010 */  sw        $v0, 0x10($sp)
/* D98A4C 802411BC 8E240080 */  lw        $a0, 0x80($s1)
/* D98A50 802411C0 0C0372DF */  jal       npc_raycast_down_sides
/* D98A54 802411C4 27A70048 */   addiu    $a3, $sp, 0x48
/* D98A58 802411C8 10400010 */  beqz      $v0, .L8024120C
/* D98A5C 802411CC 00000000 */   nop
/* D98A60 802411D0 C620003C */  lwc1      $f0, 0x3c($s1)
/* D98A64 802411D4 C6440070 */  lwc1      $f4, 0x70($s2)
/* D98A68 802411D8 46802120 */  cvt.s.w   $f4, $f4
/* D98A6C 802411DC 46040001 */  sub.s     $f0, $f0, $f4
/* D98A70 802411E0 3C018024 */  lui       $at, %hi(D_80242110_D999A0)
/* D98A74 802411E4 D4222110 */  ldc1      $f2, %lo(D_80242110_D999A0)($at)
/* D98A78 802411E8 46000021 */  cvt.d.s   $f0, $f0
/* D98A7C 802411EC 46220002 */  mul.d     $f0, $f0, $f2
/* D98A80 802411F0 00000000 */  nop
/* D98A84 802411F4 460020A1 */  cvt.d.s   $f2, $f4
/* D98A88 802411F8 46201080 */  add.d     $f2, $f2, $f0
/* D98A8C 802411FC E7A40044 */  swc1      $f4, 0x44($sp)
/* D98A90 80241200 462010A0 */  cvt.s.d   $f2, $f2
/* D98A94 80241204 0809048F */  j         .L8024123C
/* D98A98 80241208 E6220064 */   swc1     $f2, 0x64($s1)
.L8024120C:
/* D98A9C 8024120C C6A0002C */  lwc1      $f0, 0x2c($s5)
/* D98AA0 80241210 C622003C */  lwc1      $f2, 0x3c($s1)
/* D98AA4 80241214 46001081 */  sub.s     $f2, $f2, $f0
/* D98AA8 80241218 3C018024 */  lui       $at, %hi(D_80242118_D999A8)
/* D98AAC 8024121C D4242118 */  ldc1      $f4, %lo(D_80242118_D999A8)($at)
/* D98AB0 80241220 460010A1 */  cvt.d.s   $f2, $f2
/* D98AB4 80241224 46241082 */  mul.d     $f2, $f2, $f4
/* D98AB8 80241228 00000000 */  nop
/* D98ABC 8024122C 46000021 */  cvt.d.s   $f0, $f0
/* D98AC0 80241230 46220000 */  add.d     $f0, $f0, $f2
/* D98AC4 80241234 46200020 */  cvt.s.d   $f0, $f0
/* D98AC8 80241238 E6200064 */  swc1      $f0, 0x64($s1)
.L8024123C:
/* D98ACC 8024123C C620003C */  lwc1      $f0, 0x3c($s1)
/* D98AD0 80241240 2402000B */  addiu     $v0, $zero, 0xb
/* D98AD4 80241244 E6200068 */  swc1      $f0, 0x68($s1)
/* D98AD8 80241248 AE620070 */  sw        $v0, 0x70($s3)
dlabel L8024124C_D98ADC
/* D98ADC 8024124C C6200018 */  lwc1      $f0, 0x18($s1)
/* D98AE0 80241250 44801000 */  mtc1      $zero, $f2
/* D98AE4 80241254 44801800 */  mtc1      $zero, $f3
/* D98AE8 80241258 46000021 */  cvt.d.s   $f0, $f0
/* D98AEC 8024125C 4620103C */  c.lt.d    $f2, $f0
/* D98AF0 80241260 00000000 */  nop
/* D98AF4 80241264 45000025 */  bc1f      .L802412FC
/* D98AF8 80241268 27A50040 */   addiu    $a1, $sp, 0x40
/* D98AFC 8024126C C6200038 */  lwc1      $f0, 0x38($s1)
/* D98B00 80241270 C622003C */  lwc1      $f2, 0x3c($s1)
/* D98B04 80241274 C6240040 */  lwc1      $f4, 0x40($s1)
/* D98B08 80241278 C6260018 */  lwc1      $f6, 0x18($s1)
/* D98B0C 8024127C E7A00040 */  swc1      $f0, 0x40($sp)
/* D98B10 80241280 E7A20044 */  swc1      $f2, 0x44($sp)
/* D98B14 80241284 E7A40048 */  swc1      $f4, 0x48($sp)
/* D98B18 80241288 E7A60010 */  swc1      $f6, 0x10($sp)
/* D98B1C 8024128C C620000C */  lwc1      $f0, 0xc($s1)
/* D98B20 80241290 E7A00014 */  swc1      $f0, 0x14($sp)
/* D98B24 80241294 862200A8 */  lh        $v0, 0xa8($s1)
/* D98B28 80241298 44820000 */  mtc1      $v0, $f0
/* D98B2C 8024129C 00000000 */  nop
/* D98B30 802412A0 46800020 */  cvt.s.w   $f0, $f0
/* D98B34 802412A4 E7A00018 */  swc1      $f0, 0x18($sp)
/* D98B38 802412A8 862200A6 */  lh        $v0, 0xa6($s1)
/* D98B3C 802412AC 27A60044 */  addiu     $a2, $sp, 0x44
/* D98B40 802412B0 44820000 */  mtc1      $v0, $f0
/* D98B44 802412B4 00000000 */  nop
/* D98B48 802412B8 46800020 */  cvt.s.w   $f0, $f0
/* D98B4C 802412BC E7A0001C */  swc1      $f0, 0x1c($sp)
/* D98B50 802412C0 8E240080 */  lw        $a0, 0x80($s1)
/* D98B54 802412C4 0C037711 */  jal       npc_test_move_simple_with_slipping
/* D98B58 802412C8 27A70048 */   addiu    $a3, $sp, 0x48
/* D98B5C 802412CC 54400001 */  bnel      $v0, $zero, .L802412D4
/* D98B60 802412D0 AE200018 */   sw       $zero, 0x18($s1)
.L802412D4:
/* D98B64 802412D4 C62C0038 */  lwc1      $f12, 0x38($s1)
/* D98B68 802412D8 C62E0040 */  lwc1      $f14, 0x40($s1)
/* D98B6C 802412DC 8EA60028 */  lw        $a2, 0x28($s5)
/* D98B70 802412E0 0C00A720 */  jal       atan2
/* D98B74 802412E4 8EA70030 */   lw       $a3, 0x30($s5)
/* D98B78 802412E8 8E250018 */  lw        $a1, 0x18($s1)
/* D98B7C 802412EC 44060000 */  mfc1      $a2, $f0
/* D98B80 802412F0 0220202D */  daddu     $a0, $s1, $zero
/* D98B84 802412F4 0C00EA95 */  jal       npc_move_heading
/* D98B88 802412F8 AE26000C */   sw       $a2, 0xc($s1)
.L802412FC:
/* D98B8C 802412FC C620001C */  lwc1      $f0, 0x1c($s1)
/* D98B90 80241300 C6220014 */  lwc1      $f2, 0x14($s1)
/* D98B94 80241304 46020001 */  sub.s     $f0, $f0, $f2
/* D98B98 80241308 C622003C */  lwc1      $f2, 0x3c($s1)
/* D98B9C 8024130C C6240064 */  lwc1      $f4, 0x64($s1)
/* D98BA0 80241310 46001080 */  add.s     $f2, $f2, $f0
/* D98BA4 80241314 E620001C */  swc1      $f0, 0x1c($s1)
/* D98BA8 80241318 4604103C */  c.lt.s    $f2, $f4
/* D98BAC 8024131C 00000000 */  nop
/* D98BB0 80241320 450000E2 */  bc1f      L802416AC_D98F3C
/* D98BB4 80241324 E622003C */   swc1     $f2, 0x3c($s1)
/* D98BB8 80241328 2402000C */  addiu     $v0, $zero, 0xc
/* D98BBC 8024132C E624003C */  swc1      $f4, 0x3c($s1)
/* D98BC0 80241330 AE620070 */  sw        $v0, 0x70($s3)
dlabel L80241334_D98BC4
/* D98BC4 80241334 C62C0038 */  lwc1      $f12, 0x38($s1)
/* D98BC8 80241338 C62E0040 */  lwc1      $f14, 0x40($s1)
/* D98BCC 8024133C 8EA60028 */  lw        $a2, 0x28($s5)
/* D98BD0 80241340 0C00A7B5 */  jal       dist2D
/* D98BD4 80241344 8EA70030 */   lw       $a3, 0x30($s5)
/* D98BD8 80241348 3C014270 */  lui       $at, 0x4270
/* D98BDC 8024134C 44811000 */  mtc1      $at, $f2
/* D98BE0 80241350 00000000 */  nop
/* D98BE4 80241354 4602003C */  c.lt.s    $f0, $f2
/* D98BE8 80241358 00000000 */  nop
/* D98BEC 8024135C 45000002 */  bc1f      .L80241368
/* D98BF0 80241360 E6200010 */   swc1     $f0, 0x10($s1)
/* D98BF4 80241364 E6220010 */  swc1      $f2, 0x10($s1)
.L80241368:
/* D98BF8 80241368 C6860018 */  lwc1      $f6, 0x18($s4)
/* D98BFC 8024136C C6400070 */  lwc1      $f0, 0x70($s2)
/* D98C00 80241370 46800020 */  cvt.s.w   $f0, $f0
/* D98C04 80241374 E7A00044 */  swc1      $f0, 0x44($sp)
/* D98C08 80241378 46000021 */  cvt.d.s   $f0, $f0
/* D98C0C 8024137C C6240010 */  lwc1      $f4, 0x10($s1)
/* D98C10 80241380 3C014024 */  lui       $at, 0x4024
/* D98C14 80241384 44811800 */  mtc1      $at, $f3
/* D98C18 80241388 44801000 */  mtc1      $zero, $f2
/* D98C1C 8024138C 46062103 */  div.s     $f4, $f4, $f6
/* D98C20 80241390 46220000 */  add.d     $f0, $f0, $f2
/* D98C24 80241394 C622003C */  lwc1      $f2, 0x3c($s1)
/* D98C28 80241398 4600228D */  trunc.w.s $f10, $f4
/* D98C2C 8024139C 44025000 */  mfc1      $v0, $f10
/* D98C30 802413A0 00000000 */  nop
/* D98C34 802413A4 A622008E */  sh        $v0, 0x8e($s1)
/* D98C38 802413A8 460010A1 */  cvt.d.s   $f2, $f2
/* D98C3C 802413AC 46220001 */  sub.d     $f0, $f0, $f2
/* D98C40 802413B0 00021400 */  sll       $v0, $v0, 0x10
/* D98C44 802413B4 E6260018 */  swc1      $f6, 0x18($s1)
/* D98C48 802413B8 14400003 */  bnez      $v0, .L802413C8
/* D98C4C 802413BC 46200120 */   cvt.s.d  $f4, $f0
/* D98C50 802413C0 24020001 */  addiu     $v0, $zero, 1
/* D98C54 802413C4 A622008E */  sh        $v0, 0x8e($s1)
.L802413C8:
/* D98C58 802413C8 8622008E */  lh        $v0, 0x8e($s1)
/* D98C5C 802413CC C620001C */  lwc1      $f0, 0x1c($s1)
/* D98C60 802413D0 44821000 */  mtc1      $v0, $f2
/* D98C64 802413D4 00000000 */  nop
/* D98C68 802413D8 468010A0 */  cvt.s.w   $f2, $f2
/* D98C6C 802413DC 46000007 */  neg.s     $f0, $f0
/* D98C70 802413E0 46020002 */  mul.s     $f0, $f0, $f2
/* D98C74 802413E4 00000000 */  nop
/* D98C78 802413E8 00420018 */  mult      $v0, $v0
/* D98C7C 802413EC 8E230000 */  lw        $v1, ($s1)
/* D98C80 802413F0 46040000 */  add.s     $f0, $f0, $f4
/* D98C84 802413F4 A22000AB */  sb        $zero, 0xab($s1)
/* D98C88 802413F8 2402FF7F */  addiu     $v0, $zero, -0x81
/* D98C8C 802413FC 00004012 */  mflo      $t0
/* D98C90 80241400 00621824 */  and       $v1, $v1, $v0
/* D98C94 80241404 24020005 */  addiu     $v0, $zero, 5
/* D98C98 80241408 46000000 */  add.s     $f0, $f0, $f0
/* D98C9C 8024140C AE230000 */  sw        $v1, ($s1)
/* D98CA0 80241410 44881000 */  mtc1      $t0, $f2
/* D98CA4 80241414 00000000 */  nop
/* D98CA8 80241418 468010A0 */  cvt.s.w   $f2, $f2
/* D98CAC 8024141C 46000007 */  neg.s     $f0, $f0
/* D98CB0 80241420 46020003 */  div.s     $f0, $f0, $f2
/* D98CB4 80241424 46000005 */  abs.s     $f0, $f0
/* D98CB8 80241428 46000007 */  neg.s     $f0, $f0
/* D98CBC 8024142C E6200014 */  swc1      $f0, 0x14($s1)
/* D98CC0 80241430 AE42006C */  sw        $v0, 0x6c($s2)
/* D98CC4 80241434 2402000D */  addiu     $v0, $zero, 0xd
/* D98CC8 80241438 A620008E */  sh        $zero, 0x8e($s1)
/* D98CCC 8024143C AE620070 */  sw        $v0, 0x70($s3)
dlabel L80241440_D98CD0
/* D98CD0 80241440 C620001C */  lwc1      $f0, 0x1c($s1)
/* D98CD4 80241444 C6220014 */  lwc1      $f2, 0x14($s1)
/* D98CD8 80241448 46020001 */  sub.s     $f0, $f0, $f2
/* D98CDC 8024144C 4480A000 */  mtc1      $zero, $f20
/* D98CE0 80241450 00000000 */  nop
/* D98CE4 80241454 4614003C */  c.lt.s    $f0, $f20
/* D98CE8 80241458 00000000 */  nop
/* D98CEC 8024145C 45000012 */  bc1f      .L802414A8
/* D98CF0 80241460 E620001C */   swc1     $f0, 0x1c($s1)
/* D98CF4 80241464 27A50040 */  addiu     $a1, $sp, 0x40
/* D98CF8 80241468 27A60044 */  addiu     $a2, $sp, 0x44
/* D98CFC 8024146C 27A2004C */  addiu     $v0, $sp, 0x4c
/* D98D00 80241470 C6220038 */  lwc1      $f2, 0x38($s1)
/* D98D04 80241474 C624003C */  lwc1      $f4, 0x3c($s1)
/* D98D08 80241478 C6260040 */  lwc1      $f6, 0x40($s1)
/* D98D0C 8024147C 46000007 */  neg.s     $f0, $f0
/* D98D10 80241480 E7A0004C */  swc1      $f0, 0x4c($sp)
/* D98D14 80241484 E7A20040 */  swc1      $f2, 0x40($sp)
/* D98D18 80241488 E7A40044 */  swc1      $f4, 0x44($sp)
/* D98D1C 8024148C E7A60048 */  swc1      $f6, 0x48($sp)
/* D98D20 80241490 AFA20010 */  sw        $v0, 0x10($sp)
/* D98D24 80241494 8E240080 */  lw        $a0, 0x80($s1)
/* D98D28 80241498 0C0372DF */  jal       npc_raycast_down_sides
/* D98D2C 8024149C 27A70048 */   addiu    $a3, $sp, 0x48
/* D98D30 802414A0 54400001 */  bnel      $v0, $zero, .L802414A8
/* D98D34 802414A4 E634001C */   swc1     $f20, 0x1c($s1)
.L802414A8:
/* D98D38 802414A8 C624003C */  lwc1      $f4, 0x3c($s1)
/* D98D3C 802414AC C620001C */  lwc1      $f0, 0x1c($s1)
/* D98D40 802414B0 46002100 */  add.s     $f4, $f4, $f0
/* D98D44 802414B4 C6200018 */  lwc1      $f0, 0x18($s1)
/* D98D48 802414B8 44801000 */  mtc1      $zero, $f2
/* D98D4C 802414BC 44801800 */  mtc1      $zero, $f3
/* D98D50 802414C0 46000021 */  cvt.d.s   $f0, $f0
/* D98D54 802414C4 4620103C */  c.lt.d    $f2, $f0
/* D98D58 802414C8 00000000 */  nop
/* D98D5C 802414CC 45000057 */  bc1f      .L8024162C
/* D98D60 802414D0 E624003C */   swc1     $f4, 0x3c($s1)
/* D98D64 802414D4 46002086 */  mov.s     $f2, $f4
/* D98D68 802414D8 C6200038 */  lwc1      $f0, 0x38($s1)
/* D98D6C 802414DC C6240040 */  lwc1      $f4, 0x40($s1)
/* D98D70 802414E0 C6260018 */  lwc1      $f6, 0x18($s1)
/* D98D74 802414E4 E7A20044 */  swc1      $f2, 0x44($sp)
/* D98D78 802414E8 E7A00040 */  swc1      $f0, 0x40($sp)
/* D98D7C 802414EC E7A40048 */  swc1      $f4, 0x48($sp)
/* D98D80 802414F0 E7A60010 */  swc1      $f6, 0x10($sp)
/* D98D84 802414F4 C620000C */  lwc1      $f0, 0xc($s1)
/* D98D88 802414F8 E7A00014 */  swc1      $f0, 0x14($sp)
/* D98D8C 802414FC 862200A8 */  lh        $v0, 0xa8($s1)
/* D98D90 80241500 27A50040 */  addiu     $a1, $sp, 0x40
/* D98D94 80241504 44820000 */  mtc1      $v0, $f0
/* D98D98 80241508 00000000 */  nop
/* D98D9C 8024150C 46800020 */  cvt.s.w   $f0, $f0
/* D98DA0 80241510 E7A00018 */  swc1      $f0, 0x18($sp)
/* D98DA4 80241514 862200A6 */  lh        $v0, 0xa6($s1)
/* D98DA8 80241518 27A60044 */  addiu     $a2, $sp, 0x44
/* D98DAC 8024151C 44820000 */  mtc1      $v0, $f0
/* D98DB0 80241520 00000000 */  nop
/* D98DB4 80241524 46800020 */  cvt.s.w   $f0, $f0
/* D98DB8 80241528 E7A0001C */  swc1      $f0, 0x1c($sp)
/* D98DBC 8024152C 8E240080 */  lw        $a0, 0x80($s1)
/* D98DC0 80241530 0C037711 */  jal       npc_test_move_simple_with_slipping
/* D98DC4 80241534 27A70048 */   addiu    $a3, $sp, 0x48
/* D98DC8 80241538 10400003 */  beqz      $v0, .L80241548
/* D98DCC 8024153C 00000000 */   nop
/* D98DD0 80241540 08090587 */  j         .L8024161C
/* D98DD4 80241544 AE200018 */   sw       $zero, 0x18($s1)
.L80241548:
/* D98DD8 80241548 C620001C */  lwc1      $f0, 0x1c($s1)
/* D98DDC 8024154C 3C01C004 */  lui       $at, 0xc004
/* D98DE0 80241550 44811800 */  mtc1      $at, $f3
/* D98DE4 80241554 44801000 */  mtc1      $zero, $f2
/* D98DE8 80241558 46000021 */  cvt.d.s   $f0, $f0
/* D98DEC 8024155C 4622003C */  c.lt.d    $f0, $f2
/* D98DF0 80241560 00000000 */  nop
/* D98DF4 80241564 4500002D */  bc1f      .L8024161C
/* D98DF8 80241568 00000000 */   nop
/* D98DFC 8024156C 9622008E */  lhu       $v0, 0x8e($s1)
/* D98E00 80241570 24420001 */  addiu     $v0, $v0, 1
/* D98E04 80241574 A622008E */  sh        $v0, 0x8e($s1)
/* D98E08 80241578 00021400 */  sll       $v0, $v0, 0x10
/* D98E0C 8024157C 8E830020 */  lw        $v1, 0x20($s4)
/* D98E10 80241580 00021403 */  sra       $v0, $v0, 0x10
/* D98E14 80241584 0043102A */  slt       $v0, $v0, $v1
/* D98E18 80241588 14400024 */  bnez      $v0, .L8024161C
/* D98E1C 8024158C 00000000 */   nop
/* D98E20 80241590 C62C0038 */  lwc1      $f12, 0x38($s1)
/* D98E24 80241594 C62E0040 */  lwc1      $f14, 0x40($s1)
/* D98E28 80241598 8EA60028 */  lw        $a2, 0x28($s5)
/* D98E2C 8024159C 0C00A720 */  jal       atan2
/* D98E30 802415A0 8EA70030 */   lw       $a3, 0x30($s5)
/* D98E34 802415A4 46000506 */  mov.s     $f20, $f0
/* D98E38 802415A8 C62C000C */  lwc1      $f12, 0xc($s1)
/* D98E3C 802415AC 0C00A70A */  jal       get_clamped_angle_diff
/* D98E40 802415B0 4600A386 */   mov.s    $f14, $f20
/* D98E44 802415B4 46000086 */  mov.s     $f2, $f0
/* D98E48 802415B8 8E82001C */  lw        $v0, 0x1c($s4)
/* D98E4C 802415BC 46001005 */  abs.s     $f0, $f2
/* D98E50 802415C0 44822000 */  mtc1      $v0, $f4
/* D98E54 802415C4 00000000 */  nop
/* D98E58 802415C8 46802120 */  cvt.s.w   $f4, $f4
/* D98E5C 802415CC 4600203C */  c.lt.s    $f4, $f0
/* D98E60 802415D0 00000000 */  nop
/* D98E64 802415D4 4500000D */  bc1f      .L8024160C
/* D98E68 802415D8 00000000 */   nop
/* D98E6C 802415DC 44800000 */  mtc1      $zero, $f0
/* D98E70 802415E0 C634000C */  lwc1      $f20, 0xc($s1)
/* D98E74 802415E4 4600103C */  c.lt.s    $f2, $f0
/* D98E78 802415E8 00000000 */  nop
/* D98E7C 802415EC 45000006 */  bc1f      .L80241608
/* D98E80 802415F0 00021023 */   negu     $v0, $v0
/* D98E84 802415F4 44820000 */  mtc1      $v0, $f0
/* D98E88 802415F8 00000000 */  nop
/* D98E8C 802415FC 46800020 */  cvt.s.w   $f0, $f0
/* D98E90 80241600 08090583 */  j         .L8024160C
/* D98E94 80241604 4600A500 */   add.s    $f20, $f20, $f0
.L80241608:
/* D98E98 80241608 4604A500 */  add.s     $f20, $f20, $f4
.L8024160C:
/* D98E9C 8024160C 0C00A6C9 */  jal       clamp_angle
/* D98EA0 80241610 4600A306 */   mov.s    $f12, $f20
/* D98EA4 80241614 E620000C */  swc1      $f0, 0xc($s1)
/* D98EA8 80241618 A620008E */  sh        $zero, 0x8e($s1)
.L8024161C:
/* D98EAC 8024161C 8E250018 */  lw        $a1, 0x18($s1)
/* D98EB0 80241620 8E26000C */  lw        $a2, 0xc($s1)
/* D98EB4 80241624 0C00EA95 */  jal       npc_move_heading
/* D98EB8 80241628 0220202D */   daddu    $a0, $s1, $zero
.L8024162C:
/* D98EBC 8024162C 8E42006C */  lw        $v0, 0x6c($s2)
/* D98EC0 80241630 2442FFFF */  addiu     $v0, $v0, -1
/* D98EC4 80241634 1C400003 */  bgtz      $v0, .L80241644
/* D98EC8 80241638 AE42006C */   sw       $v0, 0x6c($s2)
/* D98ECC 8024163C 24020005 */  addiu     $v0, $zero, 5
/* D98ED0 80241640 AE42006C */  sw        $v0, 0x6c($s2)
.L80241644:
/* D98ED4 80241644 C620003C */  lwc1      $f0, 0x3c($s1)
/* D98ED8 80241648 C6220068 */  lwc1      $f2, 0x68($s1)
/* D98EDC 8024164C 4600103C */  c.lt.s    $f2, $f0
/* D98EE0 80241650 00000000 */  nop
/* D98EE4 80241654 45000015 */  bc1f      L802416AC_D98F3C
/* D98EE8 80241658 2402000E */   addiu    $v0, $zero, 0xe
/* D98EEC 8024165C E622003C */  swc1      $f2, 0x3c($s1)
/* D98EF0 80241660 AE620070 */  sw        $v0, 0x70($s3)
dlabel L80241664_D98EF4
/* D98EF4 80241664 8E4200CC */  lw        $v0, 0xcc($s2)
/* D98EF8 80241668 922300A9 */  lbu       $v1, 0xa9($s1)
/* D98EFC 8024166C 8C440020 */  lw        $a0, 0x20($v0)
/* D98F00 80241670 8E220000 */  lw        $v0, ($s1)
/* D98F04 80241674 A22300AB */  sb        $v1, 0xab($s1)
/* D98F08 80241678 34420080 */  ori       $v0, $v0, 0x80
/* D98F0C 8024167C AE220000 */  sw        $v0, ($s1)
/* D98F10 80241680 2402000F */  addiu     $v0, $zero, 0xf
/* D98F14 80241684 A622008E */  sh        $v0, 0x8e($s1)
/* D98F18 80241688 2402000F */  addiu     $v0, $zero, 0xf
/* D98F1C 8024168C AE240028 */  sw        $a0, 0x28($s1)
/* D98F20 80241690 AE620070 */  sw        $v0, 0x70($s3)
dlabel L80241694_D98F24
/* D98F24 80241694 9622008E */  lhu       $v0, 0x8e($s1)
/* D98F28 80241698 2442FFFF */  addiu     $v0, $v0, -1
/* D98F2C 8024169C A622008E */  sh        $v0, 0x8e($s1)
/* D98F30 802416A0 00021400 */  sll       $v0, $v0, 0x10
/* D98F34 802416A4 58400001 */  blezl     $v0, L802416AC_D98F3C
/* D98F38 802416A8 AE600070 */   sw       $zero, 0x70($s3)
dlabel L802416AC_D98F3C
/* D98F3C 802416AC 0000102D */  daddu     $v0, $zero, $zero
.L802416B0:
/* D98F40 802416B0 8FBF006C */  lw        $ra, 0x6c($sp)
/* D98F44 802416B4 8FB60068 */  lw        $s6, 0x68($sp)
/* D98F48 802416B8 8FB50064 */  lw        $s5, 0x64($sp)
/* D98F4C 802416BC 8FB40060 */  lw        $s4, 0x60($sp)
/* D98F50 802416C0 8FB3005C */  lw        $s3, 0x5c($sp)
/* D98F54 802416C4 8FB20058 */  lw        $s2, 0x58($sp)
/* D98F58 802416C8 8FB10054 */  lw        $s1, 0x54($sp)
/* D98F5C 802416CC 8FB00050 */  lw        $s0, 0x50($sp)
/* D98F60 802416D0 D7B40070 */  ldc1      $f20, 0x70($sp)
/* D98F64 802416D4 03E00008 */  jr        $ra
/* D98F68 802416D8 27BD0078 */   addiu    $sp, $sp, 0x78
/* D98F6C 802416DC 00000000 */  nop
