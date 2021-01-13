.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EF8_BAE838
/* BAE838 80240EF8 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* BAE83C 80240EFC AFB20030 */  sw        $s2, 0x30($sp)
/* BAE840 80240F00 0080902D */  daddu     $s2, $a0, $zero
/* BAE844 80240F04 AFBF0038 */  sw        $ra, 0x38($sp)
/* BAE848 80240F08 AFB30034 */  sw        $s3, 0x34($sp)
/* BAE84C 80240F0C AFB1002C */  sw        $s1, 0x2c($sp)
/* BAE850 80240F10 AFB00028 */  sw        $s0, 0x28($sp)
/* BAE854 80240F14 F7B60048 */  sdc1      $f22, 0x48($sp)
/* BAE858 80240F18 F7B40040 */  sdc1      $f20, 0x40($sp)
/* BAE85C 80240F1C 8E510148 */  lw        $s1, 0x148($s2)
/* BAE860 80240F20 86240008 */  lh        $a0, 8($s1)
/* BAE864 80240F24 0C00EABB */  jal       get_npc_unsafe
/* BAE868 80240F28 00A0982D */   daddu    $s3, $a1, $zero
/* BAE86C 80240F2C 0040802D */  daddu     $s0, $v0, $zero
/* BAE870 80240F30 0200202D */  daddu     $a0, $s0, $zero
/* BAE874 80240F34 C6220088 */  lwc1      $f2, 0x88($s1)
/* BAE878 80240F38 468010A0 */  cvt.s.w   $f2, $f2
/* BAE87C 80240F3C 460010A1 */  cvt.d.s   $f2, $f2
/* BAE880 80240F40 C604001C */  lwc1      $f4, 0x1c($s0)
/* BAE884 80240F44 C6000014 */  lwc1      $f0, 0x14($s0)
/* BAE888 80240F48 8E050018 */  lw        $a1, 0x18($s0)
/* BAE88C 80240F4C 46002100 */  add.s     $f4, $f4, $f0
/* BAE890 80240F50 8E06000C */  lw        $a2, 0xc($s0)
/* BAE894 80240F54 C6200078 */  lwc1      $f0, 0x78($s1)
/* BAE898 80240F58 46800020 */  cvt.s.w   $f0, $f0
/* BAE89C 80240F5C E604001C */  swc1      $f4, 0x1c($s0)
/* BAE8A0 80240F60 3C014059 */  lui       $at, 0x4059
/* BAE8A4 80240F64 44812800 */  mtc1      $at, $f5
/* BAE8A8 80240F68 44802000 */  mtc1      $zero, $f4
/* BAE8AC 80240F6C 46000021 */  cvt.d.s   $f0, $f0
/* BAE8B0 80240F70 46240003 */  div.d     $f0, $f0, $f4
/* BAE8B4 80240F74 46200520 */  cvt.s.d   $f20, $f0
/* BAE8B8 80240F78 46241083 */  div.d     $f2, $f2, $f4
/* BAE8BC 80240F7C 0C00EA95 */  jal       npc_move_heading
/* BAE8C0 80240F80 462015A0 */   cvt.s.d  $f22, $f2
/* BAE8C4 80240F84 C604001C */  lwc1      $f4, 0x1c($s0)
/* BAE8C8 80240F88 44801000 */  mtc1      $zero, $f2
/* BAE8CC 80240F8C 44801800 */  mtc1      $zero, $f3
/* BAE8D0 80240F90 46002021 */  cvt.d.s   $f0, $f4
/* BAE8D4 80240F94 4620103E */  c.le.d    $f2, $f0
/* BAE8D8 80240F98 00000000 */  nop
/* BAE8DC 80240F9C 45000030 */  bc1f      .L80241060
/* BAE8E0 80240FA0 00000000 */   nop
/* BAE8E4 80240FA4 C600003C */  lwc1      $f0, 0x3c($s0)
/* BAE8E8 80240FA8 46040000 */  add.s     $f0, $f0, $f4
/* BAE8EC 80240FAC E600003C */  swc1      $f0, 0x3c($s0)
/* BAE8F0 80240FB0 8E2200CC */  lw        $v0, 0xcc($s1)
/* BAE8F4 80240FB4 8C420024 */  lw        $v0, 0x24($v0)
/* BAE8F8 80240FB8 AE020028 */  sw        $v0, 0x28($s0)
/* BAE8FC 80240FBC A2200007 */  sb        $zero, 7($s1)
/* BAE900 80240FC0 8E020000 */  lw        $v0, ($s0)
/* BAE904 80240FC4 30420008 */  andi      $v0, $v0, 8
/* BAE908 80240FC8 14400011 */  bnez      $v0, .L80241010
/* BAE90C 80240FCC 0000102D */   daddu    $v0, $zero, $zero
/* BAE910 80240FD0 27A50018 */  addiu     $a1, $sp, 0x18
/* BAE914 80240FD4 27A6001C */  addiu     $a2, $sp, 0x1c
/* BAE918 80240FD8 C6000038 */  lwc1      $f0, 0x38($s0)
/* BAE91C 80240FDC C602003C */  lwc1      $f2, 0x3c($s0)
/* BAE920 80240FE0 C6040040 */  lwc1      $f4, 0x40($s0)
/* BAE924 80240FE4 3C01447A */  lui       $at, 0x447a
/* BAE928 80240FE8 44813000 */  mtc1      $at, $f6
/* BAE92C 80240FEC 27A20024 */  addiu     $v0, $sp, 0x24
/* BAE930 80240FF0 E7A00018 */  swc1      $f0, 0x18($sp)
/* BAE934 80240FF4 E7A2001C */  swc1      $f2, 0x1c($sp)
/* BAE938 80240FF8 E7A40020 */  swc1      $f4, 0x20($sp)
/* BAE93C 80240FFC E7A60024 */  swc1      $f6, 0x24($sp)
/* BAE940 80241000 AFA20010 */  sw        $v0, 0x10($sp)
/* BAE944 80241004 8E040080 */  lw        $a0, 0x80($s0)
/* BAE948 80241008 0C0372DF */  jal       func_800DCB7C
/* BAE94C 8024100C 27A70020 */   addiu    $a3, $sp, 0x20
.L80241010:
/* BAE950 80241010 1040000B */  beqz      $v0, .L80241040
/* BAE954 80241014 00000000 */   nop
/* BAE958 80241018 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* BAE95C 8024101C 46140080 */  add.s     $f2, $f0, $f20
/* BAE960 80241020 C600003C */  lwc1      $f0, 0x3c($s0)
/* BAE964 80241024 4600103E */  c.le.s    $f2, $f0
/* BAE968 80241028 00000000 */  nop
/* BAE96C 8024102C 4500008D */  bc1f      .L80241264
/* BAE970 80241030 00000000 */   nop
/* BAE974 80241034 E602003C */  swc1      $f2, 0x3c($s0)
/* BAE978 80241038 08090499 */  j         .L80241264
/* BAE97C 8024103C AE400070 */   sw       $zero, 0x70($s2)
.L80241040:
/* BAE980 80241040 C602003C */  lwc1      $f2, 0x3c($s0)
/* BAE984 80241044 C6000064 */  lwc1      $f0, 0x64($s0)
/* BAE988 80241048 4602003E */  c.le.s    $f0, $f2
/* BAE98C 8024104C 00000000 */  nop
/* BAE990 80241050 45030084 */  bc1tl     .L80241264
/* BAE994 80241054 AE400070 */   sw       $zero, 0x70($s2)
/* BAE998 80241058 08090499 */  j         .L80241264
/* BAE99C 8024105C 00000000 */   nop
.L80241060:
/* BAE9A0 80241060 4622003C */  c.lt.d    $f0, $f2
/* BAE9A4 80241064 00000000 */  nop
/* BAE9A8 80241068 4500007E */  bc1f      .L80241264
/* BAE9AC 8024106C 00000000 */   nop
/* BAE9B0 80241070 9602008E */  lhu       $v0, 0x8e($s0)
/* BAE9B4 80241074 24420001 */  addiu     $v0, $v0, 1
/* BAE9B8 80241078 A602008E */  sh        $v0, 0x8e($s0)
/* BAE9BC 8024107C 00021400 */  sll       $v0, $v0, 0x10
/* BAE9C0 80241080 8E630020 */  lw        $v1, 0x20($s3)
/* BAE9C4 80241084 00021403 */  sra       $v0, $v0, 0x10
/* BAE9C8 80241088 0043102A */  slt       $v0, $v0, $v1
/* BAE9CC 8024108C 14400026 */  bnez      $v0, .L80241128
/* BAE9D0 80241090 00000000 */   nop
/* BAE9D4 80241094 C60C0038 */  lwc1      $f12, 0x38($s0)
/* BAE9D8 80241098 C60E0040 */  lwc1      $f14, 0x40($s0)
/* BAE9DC 8024109C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* BAE9E0 802410A0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* BAE9E4 802410A4 A600008E */  sh        $zero, 0x8e($s0)
/* BAE9E8 802410A8 8C460028 */  lw        $a2, 0x28($v0)
/* BAE9EC 802410AC 0C00A720 */  jal       atan2
/* BAE9F0 802410B0 8C470030 */   lw       $a3, 0x30($v0)
/* BAE9F4 802410B4 46000506 */  mov.s     $f20, $f0
/* BAE9F8 802410B8 C60C000C */  lwc1      $f12, 0xc($s0)
/* BAE9FC 802410BC 0C00A70A */  jal       get_clamped_angle_diff
/* BAEA00 802410C0 4600A386 */   mov.s    $f14, $f20
/* BAEA04 802410C4 46000086 */  mov.s     $f2, $f0
/* BAEA08 802410C8 8E62001C */  lw        $v0, 0x1c($s3)
/* BAEA0C 802410CC 46001005 */  abs.s     $f0, $f2
/* BAEA10 802410D0 44822000 */  mtc1      $v0, $f4
/* BAEA14 802410D4 00000000 */  nop
/* BAEA18 802410D8 46802120 */  cvt.s.w   $f4, $f4
/* BAEA1C 802410DC 4600203C */  c.lt.s    $f4, $f0
/* BAEA20 802410E0 00000000 */  nop
/* BAEA24 802410E4 4500000D */  bc1f      .L8024111C
/* BAEA28 802410E8 00000000 */   nop
/* BAEA2C 802410EC 44800000 */  mtc1      $zero, $f0
/* BAEA30 802410F0 C614000C */  lwc1      $f20, 0xc($s0)
/* BAEA34 802410F4 4600103C */  c.lt.s    $f2, $f0
/* BAEA38 802410F8 00000000 */  nop
/* BAEA3C 802410FC 45000006 */  bc1f      .L80241118
/* BAEA40 80241100 00021023 */   negu     $v0, $v0
/* BAEA44 80241104 44820000 */  mtc1      $v0, $f0
/* BAEA48 80241108 00000000 */  nop
/* BAEA4C 8024110C 46800020 */  cvt.s.w   $f0, $f0
/* BAEA50 80241110 08090447 */  j         .L8024111C
/* BAEA54 80241114 4600A500 */   add.s    $f20, $f20, $f0
.L80241118:
/* BAEA58 80241118 4604A500 */  add.s     $f20, $f20, $f4
.L8024111C:
/* BAEA5C 8024111C 0C00A6C9 */  jal       clamp_angle
/* BAEA60 80241120 4600A306 */   mov.s    $f12, $f20
/* BAEA64 80241124 E600000C */  swc1      $f0, 0xc($s0)
.L80241128:
/* BAEA68 80241128 8E020000 */  lw        $v0, ($s0)
/* BAEA6C 8024112C 30420008 */  andi      $v0, $v0, 8
/* BAEA70 80241130 1040000A */  beqz      $v0, .L8024115C
/* BAEA74 80241134 27A50018 */   addiu    $a1, $sp, 0x18
/* BAEA78 80241138 C602003C */  lwc1      $f2, 0x3c($s0)
/* BAEA7C 8024113C C600001C */  lwc1      $f0, 0x1c($s0)
/* BAEA80 80241140 46001080 */  add.s     $f2, $f2, $f0
/* BAEA84 80241144 4616103C */  c.lt.s    $f2, $f22
/* BAEA88 80241148 00000000 */  nop
/* BAEA8C 8024114C 45020045 */  bc1fl     .L80241264
/* BAEA90 80241150 E602003C */   swc1     $f2, 0x3c($s0)
/* BAEA94 80241154 08090498 */  j         .L80241260
/* BAEA98 80241158 E616003C */   swc1     $f22, 0x3c($s0)
.L8024115C:
/* BAEA9C 8024115C C6000038 */  lwc1      $f0, 0x38($s0)
/* BAEAA0 80241160 27A6001C */  addiu     $a2, $sp, 0x1c
/* BAEAA4 80241164 E7A00018 */  swc1      $f0, 0x18($sp)
/* BAEAA8 80241168 860200A8 */  lh        $v0, 0xa8($s0)
/* BAEAAC 8024116C C600001C */  lwc1      $f0, 0x1c($s0)
/* BAEAB0 80241170 C604003C */  lwc1      $f4, 0x3c($s0)
/* BAEAB4 80241174 44821000 */  mtc1      $v0, $f2
/* BAEAB8 80241178 00000000 */  nop
/* BAEABC 8024117C 468010A0 */  cvt.s.w   $f2, $f2
/* BAEAC0 80241180 46000005 */  abs.s     $f0, $f0
/* BAEAC4 80241184 46020000 */  add.s     $f0, $f0, $f2
/* BAEAC8 80241188 C6060040 */  lwc1      $f6, 0x40($s0)
/* BAEACC 8024118C 27A20024 */  addiu     $v0, $sp, 0x24
/* BAEAD0 80241190 46022100 */  add.s     $f4, $f4, $f2
/* BAEAD4 80241194 3C014024 */  lui       $at, 0x4024
/* BAEAD8 80241198 44811800 */  mtc1      $at, $f3
/* BAEADC 8024119C 44801000 */  mtc1      $zero, $f2
/* BAEAE0 802411A0 46000021 */  cvt.d.s   $f0, $f0
/* BAEAE4 802411A4 46220000 */  add.d     $f0, $f0, $f2
/* BAEAE8 802411A8 E7A60020 */  swc1      $f6, 0x20($sp)
/* BAEAEC 802411AC E7A4001C */  swc1      $f4, 0x1c($sp)
/* BAEAF0 802411B0 46200020 */  cvt.s.d   $f0, $f0
/* BAEAF4 802411B4 E7A00024 */  swc1      $f0, 0x24($sp)
/* BAEAF8 802411B8 AFA20010 */  sw        $v0, 0x10($sp)
/* BAEAFC 802411BC 8E040080 */  lw        $a0, 0x80($s0)
/* BAEB00 802411C0 0C0372DF */  jal       func_800DCB7C
/* BAEB04 802411C4 27A70020 */   addiu    $a3, $sp, 0x20
/* BAEB08 802411C8 10400015 */  beqz      $v0, .L80241220
/* BAEB0C 802411CC 00000000 */   nop
/* BAEB10 802411D0 860200A8 */  lh        $v0, 0xa8($s0)
/* BAEB14 802411D4 C604001C */  lwc1      $f4, 0x1c($s0)
/* BAEB18 802411D8 44820000 */  mtc1      $v0, $f0
/* BAEB1C 802411DC 00000000 */  nop
/* BAEB20 802411E0 46800020 */  cvt.s.w   $f0, $f0
/* BAEB24 802411E4 46002085 */  abs.s     $f2, $f4
/* BAEB28 802411E8 46020000 */  add.s     $f0, $f0, $f2
/* BAEB2C 802411EC C7A20024 */  lwc1      $f2, 0x24($sp)
/* BAEB30 802411F0 4600103E */  c.le.s    $f2, $f0
/* BAEB34 802411F4 00000000 */  nop
/* BAEB38 802411F8 45000005 */  bc1f      .L80241210
/* BAEB3C 802411FC 00000000 */   nop
/* BAEB40 80241200 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* BAEB44 80241204 AE00001C */  sw        $zero, 0x1c($s0)
/* BAEB48 80241208 08090499 */  j         .L80241264
/* BAEB4C 8024120C E600003C */   swc1     $f0, 0x3c($s0)
.L80241210:
/* BAEB50 80241210 C600003C */  lwc1      $f0, 0x3c($s0)
/* BAEB54 80241214 46040000 */  add.s     $f0, $f0, $f4
/* BAEB58 80241218 08090499 */  j         .L80241264
/* BAEB5C 8024121C E600003C */   swc1     $f0, 0x3c($s0)
.L80241220:
/* BAEB60 80241220 C606003C */  lwc1      $f6, 0x3c($s0)
/* BAEB64 80241224 860200A8 */  lh        $v0, 0xa8($s0)
/* BAEB68 80241228 46163081 */  sub.s     $f2, $f6, $f22
/* BAEB6C 8024122C 44820000 */  mtc1      $v0, $f0
/* BAEB70 80241230 00000000 */  nop
/* BAEB74 80241234 46800020 */  cvt.s.w   $f0, $f0
/* BAEB78 80241238 46001080 */  add.s     $f2, $f2, $f0
/* BAEB7C 8024123C C604001C */  lwc1      $f4, 0x1c($s0)
/* BAEB80 80241240 46002005 */  abs.s     $f0, $f4
/* BAEB84 80241244 4602003C */  c.lt.s    $f0, $f2
/* BAEB88 80241248 00000000 */  nop
/* BAEB8C 8024124C 45020005 */  bc1fl     .L80241264
/* BAEB90 80241250 AE00001C */   sw       $zero, 0x1c($s0)
/* BAEB94 80241254 46043000 */  add.s     $f0, $f6, $f4
/* BAEB98 80241258 08090499 */  j         .L80241264
/* BAEB9C 8024125C E600003C */   swc1     $f0, 0x3c($s0)
.L80241260:
/* BAEBA0 80241260 AE00001C */  sw        $zero, 0x1c($s0)
.L80241264:
/* BAEBA4 80241264 8FBF0038 */  lw        $ra, 0x38($sp)
/* BAEBA8 80241268 8FB30034 */  lw        $s3, 0x34($sp)
/* BAEBAC 8024126C 8FB20030 */  lw        $s2, 0x30($sp)
/* BAEBB0 80241270 8FB1002C */  lw        $s1, 0x2c($sp)
/* BAEBB4 80241274 8FB00028 */  lw        $s0, 0x28($sp)
/* BAEBB8 80241278 D7B60048 */  ldc1      $f22, 0x48($sp)
/* BAEBBC 8024127C D7B40040 */  ldc1      $f20, 0x40($sp)
/* BAEBC0 80241280 03E00008 */  jr        $ra
/* BAEBC4 80241284 27BD0050 */   addiu    $sp, $sp, 0x50
