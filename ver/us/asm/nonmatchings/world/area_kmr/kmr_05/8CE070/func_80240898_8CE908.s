.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kmr_05_UnkFunc4
/* 8CE908 80240898 27BDFF88 */  addiu     $sp, $sp, -0x78
/* 8CE90C 8024089C AFB3004C */  sw        $s3, 0x4c($sp)
/* 8CE910 802408A0 0080982D */  daddu     $s3, $a0, $zero
/* 8CE914 802408A4 AFBF0054 */  sw        $ra, 0x54($sp)
/* 8CE918 802408A8 AFB40050 */  sw        $s4, 0x50($sp)
/* 8CE91C 802408AC AFB20048 */  sw        $s2, 0x48($sp)
/* 8CE920 802408B0 AFB10044 */  sw        $s1, 0x44($sp)
/* 8CE924 802408B4 AFB00040 */  sw        $s0, 0x40($sp)
/* 8CE928 802408B8 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* 8CE92C 802408BC F7B80068 */  sdc1      $f24, 0x68($sp)
/* 8CE930 802408C0 F7B60060 */  sdc1      $f22, 0x60($sp)
/* 8CE934 802408C4 F7B40058 */  sdc1      $f20, 0x58($sp)
/* 8CE938 802408C8 8E710148 */  lw        $s1, 0x148($s3)
/* 8CE93C 802408CC 00A0902D */  daddu     $s2, $a1, $zero
/* 8CE940 802408D0 86240008 */  lh        $a0, 8($s1)
/* 8CE944 802408D4 0C00EABB */  jal       get_npc_unsafe
/* 8CE948 802408D8 00C0A02D */   daddu    $s4, $a2, $zero
/* 8CE94C 802408DC 0040802D */  daddu     $s0, $v0, $zero
/* 8CE950 802408E0 C6200078 */  lwc1      $f0, 0x78($s1)
/* 8CE954 802408E4 46800020 */  cvt.s.w   $f0, $f0
/* 8CE958 802408E8 46000021 */  cvt.d.s   $f0, $f0
/* 8CE95C 802408EC 3C014059 */  lui       $at, 0x4059
/* 8CE960 802408F0 44811800 */  mtc1      $at, $f3
/* 8CE964 802408F4 44801000 */  mtc1      $zero, $f2
/* 8CE968 802408F8 8602008E */  lh        $v0, 0x8e($s0)
/* 8CE96C 802408FC 9603008E */  lhu       $v1, 0x8e($s0)
/* 8CE970 80240900 46220003 */  div.d     $f0, $f0, $f2
/* 8CE974 80240904 46200620 */  cvt.s.d   $f24, $f0
/* 8CE978 80240908 C6200088 */  lwc1      $f0, 0x88($s1)
/* 8CE97C 8024090C 46800020 */  cvt.s.w   $f0, $f0
/* 8CE980 80240910 46000021 */  cvt.d.s   $f0, $f0
/* 8CE984 80240914 46220003 */  div.d     $f0, $f0, $f2
/* 8CE988 80240918 46200020 */  cvt.s.d   $f0, $f0
/* 8CE98C 8024091C 18400003 */  blez      $v0, .L8024092C
/* 8CE990 80240920 4600C680 */   add.s    $f26, $f24, $f0
/* 8CE994 80240924 2462FFFF */  addiu     $v0, $v1, -1
/* 8CE998 80240928 A602008E */  sh        $v0, 0x8e($s0)
.L8024092C:
/* 8CE99C 8024092C 8E220070 */  lw        $v0, 0x70($s1)
/* 8CE9A0 80240930 18400034 */  blez      $v0, .L80240A04
/* 8CE9A4 80240934 00000000 */   nop
/* 8CE9A8 80240938 C62C0074 */  lwc1      $f12, 0x74($s1)
/* 8CE9AC 8024093C 46806320 */  cvt.s.w   $f12, $f12
/* 8CE9B0 80240940 44820000 */  mtc1      $v0, $f0
/* 8CE9B4 80240944 00000000 */  nop
/* 8CE9B8 80240948 46800020 */  cvt.s.w   $f0, $f0
/* 8CE9BC 8024094C 46000021 */  cvt.d.s   $f0, $f0
/* 8CE9C0 80240950 46220003 */  div.d     $f0, $f0, $f2
/* 8CE9C4 80240954 0C00A8BB */  jal       sin_deg
/* 8CE9C8 80240958 462005A0 */   cvt.s.d  $f22, $f0
/* 8CE9CC 8024095C 8E020000 */  lw        $v0, ($s0)
/* 8CE9D0 80240960 30420008 */  andi      $v0, $v0, 8
/* 8CE9D4 80240964 10400003 */  beqz      $v0, .L80240974
/* 8CE9D8 80240968 46000506 */   mov.s    $f20, $f0
/* 8CE9DC 8024096C 0809026D */  j         .L802409B4
/* 8CE9E0 80240970 0000102D */   daddu    $v0, $zero, $zero
.L80240974:
/* 8CE9E4 80240974 27A50028 */  addiu     $a1, $sp, 0x28
/* 8CE9E8 80240978 27A6002C */  addiu     $a2, $sp, 0x2c
/* 8CE9EC 8024097C C6000038 */  lwc1      $f0, 0x38($s0)
/* 8CE9F0 80240980 C602003C */  lwc1      $f2, 0x3c($s0)
/* 8CE9F4 80240984 C6040040 */  lwc1      $f4, 0x40($s0)
/* 8CE9F8 80240988 3C01447A */  lui       $at, 0x447a
/* 8CE9FC 8024098C 44813000 */  mtc1      $at, $f6
/* 8CEA00 80240990 27A20034 */  addiu     $v0, $sp, 0x34
/* 8CEA04 80240994 E7A00028 */  swc1      $f0, 0x28($sp)
/* 8CEA08 80240998 E7A2002C */  swc1      $f2, 0x2c($sp)
/* 8CEA0C 8024099C E7A40030 */  swc1      $f4, 0x30($sp)
/* 8CEA10 802409A0 E7A60034 */  swc1      $f6, 0x34($sp)
/* 8CEA14 802409A4 AFA20010 */  sw        $v0, 0x10($sp)
/* 8CEA18 802409A8 8E040080 */  lw        $a0, 0x80($s0)
/* 8CEA1C 802409AC 0C0372DF */  jal       func_800DCB7C
/* 8CEA20 802409B0 27A70030 */   addiu    $a3, $sp, 0x30
.L802409B4:
/* 8CEA24 802409B4 10400007 */  beqz      $v0, .L802409D4
/* 8CEA28 802409B8 00000000 */   nop
/* 8CEA2C 802409BC 4616A082 */  mul.s     $f2, $f20, $f22
/* 8CEA30 802409C0 00000000 */  nop
/* 8CEA34 802409C4 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 8CEA38 802409C8 46180000 */  add.s     $f0, $f0, $f24
/* 8CEA3C 802409CC 08090278 */  j         .L802409E0
/* 8CEA40 802409D0 46020000 */   add.s    $f0, $f0, $f2
.L802409D4:
/* 8CEA44 802409D4 4616A002 */  mul.s     $f0, $f20, $f22
/* 8CEA48 802409D8 00000000 */  nop
/* 8CEA4C 802409DC 4600D000 */  add.s     $f0, $f26, $f0
.L802409E0:
/* 8CEA50 802409E0 E600003C */  swc1      $f0, 0x3c($s0)
/* 8CEA54 802409E4 8E220074 */  lw        $v0, 0x74($s1)
/* 8CEA58 802409E8 2442000A */  addiu     $v0, $v0, 0xa
/* 8CEA5C 802409EC 44826000 */  mtc1      $v0, $f12
/* 8CEA60 802409F0 00000000 */  nop
/* 8CEA64 802409F4 0C00A6C9 */  jal       clamp_angle
/* 8CEA68 802409F8 46806320 */   cvt.s.w  $f12, $f12
/* 8CEA6C 802409FC 4600020D */  trunc.w.s $f8, $f0
/* 8CEA70 80240A00 E6280074 */  swc1      $f8, 0x74($s1)
.L80240A04:
/* 8CEA74 80240A04 8E220090 */  lw        $v0, 0x90($s1)
/* 8CEA78 80240A08 1C400040 */  bgtz      $v0, .L80240B0C
/* 8CEA7C 80240A0C 2442FFFF */   addiu    $v0, $v0, -1
/* 8CEA80 80240A10 860200A8 */  lh        $v0, 0xa8($s0)
/* 8CEA84 80240A14 C600003C */  lwc1      $f0, 0x3c($s0)
/* 8CEA88 80240A18 44821000 */  mtc1      $v0, $f2
/* 8CEA8C 80240A1C 00000000 */  nop
/* 8CEA90 80240A20 468010A0 */  cvt.s.w   $f2, $f2
/* 8CEA94 80240A24 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 8CEA98 80240A28 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 8CEA9C 80240A2C 46020000 */  add.s     $f0, $f0, $f2
/* 8CEAA0 80240A30 3C014024 */  lui       $at, 0x4024
/* 8CEAA4 80240A34 44812800 */  mtc1      $at, $f5
/* 8CEAA8 80240A38 44802000 */  mtc1      $zero, $f4
/* 8CEAAC 80240A3C C442002C */  lwc1      $f2, 0x2c($v0)
/* 8CEAB0 80240A40 46000021 */  cvt.d.s   $f0, $f0
/* 8CEAB4 80240A44 46240000 */  add.d     $f0, $f0, $f4
/* 8CEAB8 80240A48 460010A1 */  cvt.d.s   $f2, $f2
/* 8CEABC 80240A4C 4620103C */  c.lt.d    $f2, $f0
/* 8CEAC0 80240A50 00000000 */  nop
/* 8CEAC4 80240A54 4500002E */  bc1f      .L80240B10
/* 8CEAC8 80240A58 0280202D */   daddu    $a0, $s4, $zero
/* 8CEACC 80240A5C 24020001 */  addiu     $v0, $zero, 1
/* 8CEAD0 80240A60 AFA20010 */  sw        $v0, 0x10($sp)
/* 8CEAD4 80240A64 8E460024 */  lw        $a2, 0x24($s2)
/* 8CEAD8 80240A68 8E470028 */  lw        $a3, 0x28($s2)
/* 8CEADC 80240A6C 0C01242D */  jal       func_800490B4
/* 8CEAE0 80240A70 0220282D */   daddu    $a1, $s1, $zero
/* 8CEAE4 80240A74 10400026 */  beqz      $v0, .L80240B10
/* 8CEAE8 80240A78 0000202D */   daddu    $a0, $zero, $zero
/* 8CEAEC 80240A7C 0200282D */  daddu     $a1, $s0, $zero
/* 8CEAF0 80240A80 0000302D */  daddu     $a2, $zero, $zero
/* 8CEAF4 80240A84 2412000C */  addiu     $s2, $zero, 0xc
/* 8CEAF8 80240A88 860300A8 */  lh        $v1, 0xa8($s0)
/* 8CEAFC 80240A8C 3C013F80 */  lui       $at, 0x3f80
/* 8CEB00 80240A90 44810000 */  mtc1      $at, $f0
/* 8CEB04 80240A94 3C014000 */  lui       $at, 0x4000
/* 8CEB08 80240A98 44811000 */  mtc1      $at, $f2
/* 8CEB0C 80240A9C 3C01C1A0 */  lui       $at, 0xc1a0
/* 8CEB10 80240AA0 44812000 */  mtc1      $at, $f4
/* 8CEB14 80240AA4 44834000 */  mtc1      $v1, $f8
/* 8CEB18 80240AA8 00000000 */  nop
/* 8CEB1C 80240AAC 46804220 */  cvt.s.w   $f8, $f8
/* 8CEB20 80240AB0 44074000 */  mfc1      $a3, $f8
/* 8CEB24 80240AB4 27A20038 */  addiu     $v0, $sp, 0x38
/* 8CEB28 80240AB8 AFB2001C */  sw        $s2, 0x1c($sp)
/* 8CEB2C 80240ABC AFA20020 */  sw        $v0, 0x20($sp)
/* 8CEB30 80240AC0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8CEB34 80240AC4 E7A20014 */  swc1      $f2, 0x14($sp)
/* 8CEB38 80240AC8 0C01BFA4 */  jal       fx_emote
/* 8CEB3C 80240ACC E7A40018 */   swc1     $f4, 0x18($sp)
/* 8CEB40 80240AD0 0200202D */  daddu     $a0, $s0, $zero
/* 8CEB44 80240AD4 240502F4 */  addiu     $a1, $zero, 0x2f4
/* 8CEB48 80240AD8 C480003C */  lwc1      $f0, 0x3c($a0)
/* 8CEB4C 80240ADC 3C060020 */  lui       $a2, 0x20
/* 8CEB50 80240AE0 0C012530 */  jal       func_800494C0
/* 8CEB54 80240AE4 E4800064 */   swc1     $f0, 0x64($a0)
/* 8CEB58 80240AE8 8E220018 */  lw        $v0, 0x18($s1)
/* 8CEB5C 80240AEC 9442002A */  lhu       $v0, 0x2a($v0)
/* 8CEB60 80240AF0 30420001 */  andi      $v0, $v0, 1
/* 8CEB64 80240AF4 10400003 */  beqz      $v0, .L80240B04
/* 8CEB68 80240AF8 2402000A */   addiu    $v0, $zero, 0xa
/* 8CEB6C 80240AFC 080902EB */  j         .L80240BAC
/* 8CEB70 80240B00 AE620070 */   sw       $v0, 0x70($s3)
.L80240B04:
/* 8CEB74 80240B04 080902EB */  j         .L80240BAC
/* 8CEB78 80240B08 AE720070 */   sw       $s2, 0x70($s3)
.L80240B0C:
/* 8CEB7C 80240B0C AE220090 */  sw        $v0, 0x90($s1)
.L80240B10:
/* 8CEB80 80240B10 8602008C */  lh        $v0, 0x8c($s0)
/* 8CEB84 80240B14 14400025 */  bnez      $v0, .L80240BAC
/* 8CEB88 80240B18 00000000 */   nop
/* 8CEB8C 80240B1C 8602008E */  lh        $v0, 0x8e($s0)
/* 8CEB90 80240B20 1C400022 */  bgtz      $v0, .L80240BAC
/* 8CEB94 80240B24 00000000 */   nop
/* 8CEB98 80240B28 8E620074 */  lw        $v0, 0x74($s3)
/* 8CEB9C 80240B2C 2442FFFF */  addiu     $v0, $v0, -1
/* 8CEBA0 80240B30 1840001D */  blez      $v0, .L80240BA8
/* 8CEBA4 80240B34 AE620074 */   sw       $v0, 0x74($s3)
/* 8CEBA8 80240B38 8E220018 */  lw        $v0, 0x18($s1)
/* 8CEBAC 80240B3C 9442002A */  lhu       $v0, 0x2a($v0)
/* 8CEBB0 80240B40 30420010 */  andi      $v0, $v0, 0x10
/* 8CEBB4 80240B44 14400007 */  bnez      $v0, .L80240B64
/* 8CEBB8 80240B48 00000000 */   nop
/* 8CEBBC 80240B4C C600000C */  lwc1      $f0, 0xc($s0)
/* 8CEBC0 80240B50 3C014334 */  lui       $at, 0x4334
/* 8CEBC4 80240B54 44816000 */  mtc1      $at, $f12
/* 8CEBC8 80240B58 0C00A6C9 */  jal       clamp_angle
/* 8CEBCC 80240B5C 460C0300 */   add.s    $f12, $f0, $f12
/* 8CEBD0 80240B60 E600000C */  swc1      $f0, 0xc($s0)
.L80240B64:
/* 8CEBD4 80240B64 0C00A67F */  jal       rand_int
/* 8CEBD8 80240B68 240403E8 */   addiu    $a0, $zero, 0x3e8
/* 8CEBDC 80240B6C 3C032E8B */  lui       $v1, 0x2e8b
/* 8CEBE0 80240B70 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* 8CEBE4 80240B74 00430018 */  mult      $v0, $v1
/* 8CEBE8 80240B78 00021FC3 */  sra       $v1, $v0, 0x1f
/* 8CEBEC 80240B7C 00004010 */  mfhi      $t0
/* 8CEBF0 80240B80 00082043 */  sra       $a0, $t0, 1
/* 8CEBF4 80240B84 00832023 */  subu      $a0, $a0, $v1
/* 8CEBF8 80240B88 00041840 */  sll       $v1, $a0, 1
/* 8CEBFC 80240B8C 00641821 */  addu      $v1, $v1, $a0
/* 8CEC00 80240B90 00031880 */  sll       $v1, $v1, 2
/* 8CEC04 80240B94 00641823 */  subu      $v1, $v1, $a0
/* 8CEC08 80240B98 00431023 */  subu      $v0, $v0, $v1
/* 8CEC0C 80240B9C 24420005 */  addiu     $v0, $v0, 5
/* 8CEC10 80240BA0 080902EB */  j         .L80240BAC
/* 8CEC14 80240BA4 A602008E */   sh       $v0, 0x8e($s0)
.L80240BA8:
/* 8CEC18 80240BA8 AE600070 */  sw        $zero, 0x70($s3)
.L80240BAC:
/* 8CEC1C 80240BAC 8FBF0054 */  lw        $ra, 0x54($sp)
/* 8CEC20 80240BB0 8FB40050 */  lw        $s4, 0x50($sp)
/* 8CEC24 80240BB4 8FB3004C */  lw        $s3, 0x4c($sp)
/* 8CEC28 80240BB8 8FB20048 */  lw        $s2, 0x48($sp)
/* 8CEC2C 80240BBC 8FB10044 */  lw        $s1, 0x44($sp)
/* 8CEC30 80240BC0 8FB00040 */  lw        $s0, 0x40($sp)
/* 8CEC34 80240BC4 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* 8CEC38 80240BC8 D7B80068 */  ldc1      $f24, 0x68($sp)
/* 8CEC3C 80240BCC D7B60060 */  ldc1      $f22, 0x60($sp)
/* 8CEC40 80240BD0 D7B40058 */  ldc1      $f20, 0x58($sp)
/* 8CEC44 80240BD4 03E00008 */  jr        $ra
/* 8CEC48 80240BD8 27BD0078 */   addiu    $sp, $sp, 0x78
