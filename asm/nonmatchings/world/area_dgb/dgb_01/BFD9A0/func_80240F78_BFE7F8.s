.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F78_BFE7F8
/* BFE7F8 80240F78 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* BFE7FC 80240F7C AFB20030 */  sw        $s2, 0x30($sp)
/* BFE800 80240F80 0080902D */  daddu     $s2, $a0, $zero
/* BFE804 80240F84 AFBF0038 */  sw        $ra, 0x38($sp)
/* BFE808 80240F88 AFB30034 */  sw        $s3, 0x34($sp)
/* BFE80C 80240F8C AFB1002C */  sw        $s1, 0x2c($sp)
/* BFE810 80240F90 AFB00028 */  sw        $s0, 0x28($sp)
/* BFE814 80240F94 F7B60048 */  sdc1      $f22, 0x48($sp)
/* BFE818 80240F98 F7B40040 */  sdc1      $f20, 0x40($sp)
/* BFE81C 80240F9C 8E510148 */  lw        $s1, 0x148($s2)
/* BFE820 80240FA0 86240008 */  lh        $a0, 8($s1)
/* BFE824 80240FA4 0C00EABB */  jal       get_npc_unsafe
/* BFE828 80240FA8 00A0982D */   daddu    $s3, $a1, $zero
/* BFE82C 80240FAC 0040802D */  daddu     $s0, $v0, $zero
/* BFE830 80240FB0 0200202D */  daddu     $a0, $s0, $zero
/* BFE834 80240FB4 C6220088 */  lwc1      $f2, 0x88($s1)
/* BFE838 80240FB8 468010A0 */  cvt.s.w   $f2, $f2
/* BFE83C 80240FBC 460010A1 */  cvt.d.s   $f2, $f2
/* BFE840 80240FC0 C604001C */  lwc1      $f4, 0x1c($s0)
/* BFE844 80240FC4 C6000014 */  lwc1      $f0, 0x14($s0)
/* BFE848 80240FC8 8E050018 */  lw        $a1, 0x18($s0)
/* BFE84C 80240FCC 46002100 */  add.s     $f4, $f4, $f0
/* BFE850 80240FD0 8E06000C */  lw        $a2, 0xc($s0)
/* BFE854 80240FD4 C6200078 */  lwc1      $f0, 0x78($s1)
/* BFE858 80240FD8 46800020 */  cvt.s.w   $f0, $f0
/* BFE85C 80240FDC E604001C */  swc1      $f4, 0x1c($s0)
/* BFE860 80240FE0 3C014059 */  lui       $at, 0x4059
/* BFE864 80240FE4 44812800 */  mtc1      $at, $f5
/* BFE868 80240FE8 44802000 */  mtc1      $zero, $f4
/* BFE86C 80240FEC 46000021 */  cvt.d.s   $f0, $f0
/* BFE870 80240FF0 46240003 */  div.d     $f0, $f0, $f4
/* BFE874 80240FF4 46200520 */  cvt.s.d   $f20, $f0
/* BFE878 80240FF8 46241083 */  div.d     $f2, $f2, $f4
/* BFE87C 80240FFC 0C00EA95 */  jal       npc_move_heading
/* BFE880 80241000 462015A0 */   cvt.s.d  $f22, $f2
/* BFE884 80241004 C604001C */  lwc1      $f4, 0x1c($s0)
/* BFE888 80241008 44801000 */  mtc1      $zero, $f2
/* BFE88C 8024100C 44801800 */  mtc1      $zero, $f3
/* BFE890 80241010 46002021 */  cvt.d.s   $f0, $f4
/* BFE894 80241014 4620103E */  c.le.d    $f2, $f0
/* BFE898 80241018 00000000 */  nop       
/* BFE89C 8024101C 45000030 */  bc1f      .L802410E0
/* BFE8A0 80241020 00000000 */   nop      
/* BFE8A4 80241024 C600003C */  lwc1      $f0, 0x3c($s0)
/* BFE8A8 80241028 46040000 */  add.s     $f0, $f0, $f4
/* BFE8AC 8024102C E600003C */  swc1      $f0, 0x3c($s0)
/* BFE8B0 80241030 8E2200CC */  lw        $v0, 0xcc($s1)
/* BFE8B4 80241034 8C420024 */  lw        $v0, 0x24($v0)
/* BFE8B8 80241038 AE020028 */  sw        $v0, 0x28($s0)
/* BFE8BC 8024103C A2200007 */  sb        $zero, 7($s1)
/* BFE8C0 80241040 8E020000 */  lw        $v0, ($s0)
/* BFE8C4 80241044 30420008 */  andi      $v0, $v0, 8
/* BFE8C8 80241048 14400011 */  bnez      $v0, .L80241090
/* BFE8CC 8024104C 0000102D */   daddu    $v0, $zero, $zero
/* BFE8D0 80241050 27A50018 */  addiu     $a1, $sp, 0x18
/* BFE8D4 80241054 27A6001C */  addiu     $a2, $sp, 0x1c
/* BFE8D8 80241058 C6000038 */  lwc1      $f0, 0x38($s0)
/* BFE8DC 8024105C C602003C */  lwc1      $f2, 0x3c($s0)
/* BFE8E0 80241060 C6040040 */  lwc1      $f4, 0x40($s0)
/* BFE8E4 80241064 3C01447A */  lui       $at, 0x447a
/* BFE8E8 80241068 44813000 */  mtc1      $at, $f6
/* BFE8EC 8024106C 27A20024 */  addiu     $v0, $sp, 0x24
/* BFE8F0 80241070 E7A00018 */  swc1      $f0, 0x18($sp)
/* BFE8F4 80241074 E7A2001C */  swc1      $f2, 0x1c($sp)
/* BFE8F8 80241078 E7A40020 */  swc1      $f4, 0x20($sp)
/* BFE8FC 8024107C E7A60024 */  swc1      $f6, 0x24($sp)
/* BFE900 80241080 AFA20010 */  sw        $v0, 0x10($sp)
/* BFE904 80241084 8E040080 */  lw        $a0, 0x80($s0)
/* BFE908 80241088 0C0372DF */  jal       func_800DCB7C
/* BFE90C 8024108C 27A70020 */   addiu    $a3, $sp, 0x20
.L80241090:
/* BFE910 80241090 1040000B */  beqz      $v0, .L802410C0
/* BFE914 80241094 00000000 */   nop      
/* BFE918 80241098 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* BFE91C 8024109C 46140080 */  add.s     $f2, $f0, $f20
/* BFE920 802410A0 C600003C */  lwc1      $f0, 0x3c($s0)
/* BFE924 802410A4 4600103E */  c.le.s    $f2, $f0
/* BFE928 802410A8 00000000 */  nop       
/* BFE92C 802410AC 4500008D */  bc1f      .L802412E4
/* BFE930 802410B0 00000000 */   nop      
/* BFE934 802410B4 E602003C */  swc1      $f2, 0x3c($s0)
/* BFE938 802410B8 080904B9 */  j         .L802412E4
/* BFE93C 802410BC AE400070 */   sw       $zero, 0x70($s2)
.L802410C0:
/* BFE940 802410C0 C602003C */  lwc1      $f2, 0x3c($s0)
/* BFE944 802410C4 C6000064 */  lwc1      $f0, 0x64($s0)
/* BFE948 802410C8 4602003E */  c.le.s    $f0, $f2
/* BFE94C 802410CC 00000000 */  nop       
/* BFE950 802410D0 45030084 */  bc1tl     .L802412E4
/* BFE954 802410D4 AE400070 */   sw       $zero, 0x70($s2)
/* BFE958 802410D8 080904B9 */  j         .L802412E4
/* BFE95C 802410DC 00000000 */   nop      
.L802410E0:
/* BFE960 802410E0 4622003C */  c.lt.d    $f0, $f2
/* BFE964 802410E4 00000000 */  nop       
/* BFE968 802410E8 4500007E */  bc1f      .L802412E4
/* BFE96C 802410EC 00000000 */   nop      
/* BFE970 802410F0 9602008E */  lhu       $v0, 0x8e($s0)
/* BFE974 802410F4 24420001 */  addiu     $v0, $v0, 1
/* BFE978 802410F8 A602008E */  sh        $v0, 0x8e($s0)
/* BFE97C 802410FC 00021400 */  sll       $v0, $v0, 0x10
/* BFE980 80241100 8E630020 */  lw        $v1, 0x20($s3)
/* BFE984 80241104 00021403 */  sra       $v0, $v0, 0x10
/* BFE988 80241108 0043102A */  slt       $v0, $v0, $v1
/* BFE98C 8024110C 14400026 */  bnez      $v0, .L802411A8
/* BFE990 80241110 00000000 */   nop      
/* BFE994 80241114 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BFE998 80241118 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BFE99C 8024111C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BFE9A0 80241120 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BFE9A4 80241124 A600008E */  sh        $zero, 0x8e($s0)
/* BFE9A8 80241128 8C460028 */  lw        $a2, 0x28($v0)
/* BFE9AC 8024112C 0C00A720 */  jal       atan2
/* BFE9B0 80241130 8C470030 */   lw       $a3, 0x30($v0)
/* BFE9B4 80241134 46000506 */  mov.s     $f20, $f0
/* BFE9B8 80241138 C60C000C */  lwc1      $f12, 0xc($s0)
/* BFE9BC 8024113C 0C00A70A */  jal       get_clamped_angle_diff
/* BFE9C0 80241140 4600A386 */   mov.s    $f14, $f20
/* BFE9C4 80241144 46000086 */  mov.s     $f2, $f0
/* BFE9C8 80241148 8E62001C */  lw        $v0, 0x1c($s3)
/* BFE9CC 8024114C 46001005 */  abs.s     $f0, $f2
/* BFE9D0 80241150 44822000 */  mtc1      $v0, $f4
/* BFE9D4 80241154 00000000 */  nop       
/* BFE9D8 80241158 46802120 */  cvt.s.w   $f4, $f4
/* BFE9DC 8024115C 4600203C */  c.lt.s    $f4, $f0
/* BFE9E0 80241160 00000000 */  nop       
/* BFE9E4 80241164 4500000D */  bc1f      .L8024119C
/* BFE9E8 80241168 00000000 */   nop      
/* BFE9EC 8024116C 44800000 */  mtc1      $zero, $f0
/* BFE9F0 80241170 C614000C */  lwc1      $f20, 0xc($s0)
/* BFE9F4 80241174 4600103C */  c.lt.s    $f2, $f0
/* BFE9F8 80241178 00000000 */  nop       
/* BFE9FC 8024117C 45000006 */  bc1f      .L80241198
/* BFEA00 80241180 00021023 */   negu     $v0, $v0
/* BFEA04 80241184 44820000 */  mtc1      $v0, $f0
/* BFEA08 80241188 00000000 */  nop       
/* BFEA0C 8024118C 46800020 */  cvt.s.w   $f0, $f0
/* BFEA10 80241190 08090467 */  j         .L8024119C
/* BFEA14 80241194 4600A500 */   add.s    $f20, $f20, $f0
.L80241198:
/* BFEA18 80241198 4604A500 */  add.s     $f20, $f20, $f4
.L8024119C:
/* BFEA1C 8024119C 0C00A6C9 */  jal       clamp_angle
/* BFEA20 802411A0 4600A306 */   mov.s    $f12, $f20
/* BFEA24 802411A4 E600000C */  swc1      $f0, 0xc($s0)
.L802411A8:
/* BFEA28 802411A8 8E020000 */  lw        $v0, ($s0)
/* BFEA2C 802411AC 30420008 */  andi      $v0, $v0, 8
/* BFEA30 802411B0 1040000A */  beqz      $v0, .L802411DC
/* BFEA34 802411B4 27A50018 */   addiu    $a1, $sp, 0x18
/* BFEA38 802411B8 C602003C */  lwc1      $f2, 0x3c($s0)
/* BFEA3C 802411BC C600001C */  lwc1      $f0, 0x1c($s0)
/* BFEA40 802411C0 46001080 */  add.s     $f2, $f2, $f0
/* BFEA44 802411C4 4616103C */  c.lt.s    $f2, $f22
/* BFEA48 802411C8 00000000 */  nop       
/* BFEA4C 802411CC 45020045 */  bc1fl     .L802412E4
/* BFEA50 802411D0 E602003C */   swc1     $f2, 0x3c($s0)
/* BFEA54 802411D4 080904B8 */  j         .L802412E0
/* BFEA58 802411D8 E616003C */   swc1     $f22, 0x3c($s0)
.L802411DC:
/* BFEA5C 802411DC C6000038 */  lwc1      $f0, 0x38($s0)
/* BFEA60 802411E0 27A6001C */  addiu     $a2, $sp, 0x1c
/* BFEA64 802411E4 E7A00018 */  swc1      $f0, 0x18($sp)
/* BFEA68 802411E8 860200A8 */  lh        $v0, 0xa8($s0)
/* BFEA6C 802411EC C600001C */  lwc1      $f0, 0x1c($s0)
/* BFEA70 802411F0 C604003C */  lwc1      $f4, 0x3c($s0)
/* BFEA74 802411F4 44821000 */  mtc1      $v0, $f2
/* BFEA78 802411F8 00000000 */  nop       
/* BFEA7C 802411FC 468010A0 */  cvt.s.w   $f2, $f2
/* BFEA80 80241200 46000005 */  abs.s     $f0, $f0
/* BFEA84 80241204 46020000 */  add.s     $f0, $f0, $f2
/* BFEA88 80241208 C6060040 */  lwc1      $f6, 0x40($s0)
/* BFEA8C 8024120C 27A20024 */  addiu     $v0, $sp, 0x24
/* BFEA90 80241210 46022100 */  add.s     $f4, $f4, $f2
/* BFEA94 80241214 3C014024 */  lui       $at, 0x4024
/* BFEA98 80241218 44811800 */  mtc1      $at, $f3
/* BFEA9C 8024121C 44801000 */  mtc1      $zero, $f2
/* BFEAA0 80241220 46000021 */  cvt.d.s   $f0, $f0
/* BFEAA4 80241224 46220000 */  add.d     $f0, $f0, $f2
/* BFEAA8 80241228 E7A60020 */  swc1      $f6, 0x20($sp)
/* BFEAAC 8024122C E7A4001C */  swc1      $f4, 0x1c($sp)
/* BFEAB0 80241230 46200020 */  cvt.s.d   $f0, $f0
/* BFEAB4 80241234 E7A00024 */  swc1      $f0, 0x24($sp)
/* BFEAB8 80241238 AFA20010 */  sw        $v0, 0x10($sp)
/* BFEABC 8024123C 8E040080 */  lw        $a0, 0x80($s0)
/* BFEAC0 80241240 0C0372DF */  jal       func_800DCB7C
/* BFEAC4 80241244 27A70020 */   addiu    $a3, $sp, 0x20
/* BFEAC8 80241248 10400015 */  beqz      $v0, .L802412A0
/* BFEACC 8024124C 00000000 */   nop      
/* BFEAD0 80241250 860200A8 */  lh        $v0, 0xa8($s0)
/* BFEAD4 80241254 C604001C */  lwc1      $f4, 0x1c($s0)
/* BFEAD8 80241258 44820000 */  mtc1      $v0, $f0
/* BFEADC 8024125C 00000000 */  nop       
/* BFEAE0 80241260 46800020 */  cvt.s.w   $f0, $f0
/* BFEAE4 80241264 46002085 */  abs.s     $f2, $f4
/* BFEAE8 80241268 46020000 */  add.s     $f0, $f0, $f2
/* BFEAEC 8024126C C7A20024 */  lwc1      $f2, 0x24($sp)
/* BFEAF0 80241270 4600103E */  c.le.s    $f2, $f0
/* BFEAF4 80241274 00000000 */  nop       
/* BFEAF8 80241278 45000005 */  bc1f      .L80241290
/* BFEAFC 8024127C 00000000 */   nop      
/* BFEB00 80241280 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* BFEB04 80241284 AE00001C */  sw        $zero, 0x1c($s0)
/* BFEB08 80241288 080904B9 */  j         .L802412E4
/* BFEB0C 8024128C E600003C */   swc1     $f0, 0x3c($s0)
.L80241290:
/* BFEB10 80241290 C600003C */  lwc1      $f0, 0x3c($s0)
/* BFEB14 80241294 46040000 */  add.s     $f0, $f0, $f4
/* BFEB18 80241298 080904B9 */  j         .L802412E4
/* BFEB1C 8024129C E600003C */   swc1     $f0, 0x3c($s0)
.L802412A0:
/* BFEB20 802412A0 C606003C */  lwc1      $f6, 0x3c($s0)
/* BFEB24 802412A4 860200A8 */  lh        $v0, 0xa8($s0)
/* BFEB28 802412A8 46163081 */  sub.s     $f2, $f6, $f22
/* BFEB2C 802412AC 44820000 */  mtc1      $v0, $f0
/* BFEB30 802412B0 00000000 */  nop       
/* BFEB34 802412B4 46800020 */  cvt.s.w   $f0, $f0
/* BFEB38 802412B8 46001080 */  add.s     $f2, $f2, $f0
/* BFEB3C 802412BC C604001C */  lwc1      $f4, 0x1c($s0)
/* BFEB40 802412C0 46002005 */  abs.s     $f0, $f4
/* BFEB44 802412C4 4602003C */  c.lt.s    $f0, $f2
/* BFEB48 802412C8 00000000 */  nop       
/* BFEB4C 802412CC 45020005 */  bc1fl     .L802412E4
/* BFEB50 802412D0 AE00001C */   sw       $zero, 0x1c($s0)
/* BFEB54 802412D4 46043000 */  add.s     $f0, $f6, $f4
/* BFEB58 802412D8 080904B9 */  j         .L802412E4
/* BFEB5C 802412DC E600003C */   swc1     $f0, 0x3c($s0)
.L802412E0:
/* BFEB60 802412E0 AE00001C */  sw        $zero, 0x1c($s0)
.L802412E4:
/* BFEB64 802412E4 8FBF0038 */  lw        $ra, 0x38($sp)
/* BFEB68 802412E8 8FB30034 */  lw        $s3, 0x34($sp)
/* BFEB6C 802412EC 8FB20030 */  lw        $s2, 0x30($sp)
/* BFEB70 802412F0 8FB1002C */  lw        $s1, 0x2c($sp)
/* BFEB74 802412F4 8FB00028 */  lw        $s0, 0x28($sp)
/* BFEB78 802412F8 D7B60048 */  ldc1      $f22, 0x48($sp)
/* BFEB7C 802412FC D7B40040 */  ldc1      $f20, 0x40($sp)
/* BFEB80 80241300 03E00008 */  jr        $ra
/* BFEB84 80241304 27BD0050 */   addiu    $sp, $sp, 0x50
