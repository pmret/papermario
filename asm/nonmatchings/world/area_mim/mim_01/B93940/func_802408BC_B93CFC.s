.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408BC_B93CFC
/* B93CFC 802408BC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B93D00 802408C0 AFB40028 */  sw        $s4, 0x28($sp)
/* B93D04 802408C4 0080A02D */  daddu     $s4, $a0, $zero
/* B93D08 802408C8 AFBF002C */  sw        $ra, 0x2c($sp)
/* B93D0C 802408CC AFB30024 */  sw        $s3, 0x24($sp)
/* B93D10 802408D0 AFB20020 */  sw        $s2, 0x20($sp)
/* B93D14 802408D4 AFB1001C */  sw        $s1, 0x1c($sp)
/* B93D18 802408D8 AFB00018 */  sw        $s0, 0x18($sp)
/* B93D1C 802408DC 8E910148 */  lw        $s1, 0x148($s4)
/* B93D20 802408E0 86240008 */  lh        $a0, 8($s1)
/* B93D24 802408E4 0C00EABB */  jal       get_npc_unsafe
/* B93D28 802408E8 00A0802D */   daddu    $s0, $a1, $zero
/* B93D2C 802408EC 16000005 */  bnez      $s0, .L80240904
/* B93D30 802408F0 0040902D */   daddu    $s2, $v0, $zero
/* B93D34 802408F4 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B93D38 802408F8 30420004 */  andi      $v0, $v0, 4
/* B93D3C 802408FC 10400015 */  beqz      $v0, .L80240954
/* B93D40 80240900 00000000 */   nop
.L80240904:
/* B93D44 80240904 AE800070 */  sw        $zero, 0x70($s4)
/* B93D48 80240908 8E420000 */  lw        $v0, ($s2)
/* B93D4C 8024090C 3C031F30 */  lui       $v1, 0x1f30
/* B93D50 80240910 A640008E */  sh        $zero, 0x8e($s2)
/* B93D54 80240914 34420102 */  ori       $v0, $v0, 0x102
/* B93D58 80240918 AE420000 */  sw        $v0, ($s2)
/* B93D5C 8024091C 8E220000 */  lw        $v0, ($s1)
/* B93D60 80240920 3C01C47A */  lui       $at, 0xc47a
/* B93D64 80240924 44810000 */  mtc1      $at, $f0
/* B93D68 80240928 00431025 */  or        $v0, $v0, $v1
/* B93D6C 8024092C AE220000 */  sw        $v0, ($s1)
/* B93D70 80240930 AE400038 */  sw        $zero, 0x38($s2)
/* B93D74 80240934 E640003C */  swc1      $f0, 0x3c($s2)
/* B93D78 80240938 AE400040 */  sw        $zero, 0x40($s2)
/* B93D7C 8024093C 8E2300B0 */  lw        $v1, 0xb0($s1)
/* B93D80 80240940 30620004 */  andi      $v0, $v1, 4
/* B93D84 80240944 10400003 */  beqz      $v0, .L80240954
/* B93D88 80240948 2402FFFB */   addiu    $v0, $zero, -5
/* B93D8C 8024094C 00621024 */  and       $v0, $v1, $v0
/* B93D90 80240950 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80240954:
/* B93D94 80240954 8E930070 */  lw        $s3, 0x70($s4)
/* B93D98 80240958 12600005 */  beqz      $s3, .L80240970
/* B93D9C 8024095C 24020001 */   addiu    $v0, $zero, 1
/* B93DA0 80240960 12620048 */  beq       $s3, $v0, .L80240A84
/* B93DA4 80240964 00000000 */   nop
/* B93DA8 80240968 080902BE */  j         .L80240AF8
/* B93DAC 8024096C 00000000 */   nop
.L80240970:
/* B93DB0 80240970 86240008 */  lh        $a0, 8($s1)
/* B93DB4 80240974 0C00FB3A */  jal       get_enemy
/* B93DB8 80240978 2484FFFF */   addiu    $a0, $a0, -1
/* B93DBC 8024097C 0040802D */  daddu     $s0, $v0, $zero
/* B93DC0 80240980 0C00EABB */  jal       get_npc_unsafe
/* B93DC4 80240984 86040008 */   lh       $a0, 8($s0)
/* B93DC8 80240988 24030001 */  addiu     $v1, $zero, 1
/* B93DCC 8024098C 0040982D */  daddu     $s3, $v0, $zero
/* B93DD0 80240990 A2230007 */  sb        $v1, 7($s1)
/* B93DD4 80240994 8E03006C */  lw        $v1, 0x6c($s0)
/* B93DD8 80240998 24020003 */  addiu     $v0, $zero, 3
/* B93DDC 8024099C 14620056 */  bne       $v1, $v0, .L80240AF8
/* B93DE0 802409A0 00000000 */   nop
/* B93DE4 802409A4 8E2500A8 */  lw        $a1, 0xa8($s1)
/* B93DE8 802409A8 10A00003 */  beqz      $a1, .L802409B8
/* B93DEC 802409AC 0260202D */   daddu    $a0, $s3, $zero
/* B93DF0 802409B0 0C012530 */  jal       func_800494C0
/* B93DF4 802409B4 0000302D */   daddu    $a2, $zero, $zero
.L802409B8:
/* B93DF8 802409B8 27A40010 */  addiu     $a0, $sp, 0x10
/* B93DFC 802409BC C6280070 */  lwc1      $f8, 0x70($s1)
/* B93E00 802409C0 46804220 */  cvt.s.w   $f8, $f8
/* B93E04 802409C4 C6620034 */  lwc1      $f2, 0x34($s3)
/* B93E08 802409C8 3C014387 */  lui       $at, 0x4387
/* B93E0C 802409CC 44810000 */  mtc1      $at, $f0
/* B93E10 802409D0 44064000 */  mfc1      $a2, $f8
/* B93E14 802409D4 46020001 */  sub.s     $f0, $f0, $f2
/* B93E18 802409D8 C6660038 */  lwc1      $f6, 0x38($s3)
/* B93E1C 802409DC C6640040 */  lwc1      $f4, 0x40($s3)
/* B93E20 802409E0 44070000 */  mfc1      $a3, $f0
/* B93E24 802409E4 27A50014 */  addiu     $a1, $sp, 0x14
/* B93E28 802409E8 E7A60010 */  swc1      $f6, 0x10($sp)
/* B93E2C 802409EC 0C00A7E7 */  jal       add_vec2D_polar
/* B93E30 802409F0 E7A40014 */   swc1     $f4, 0x14($sp)
/* B93E34 802409F4 C7A00010 */  lwc1      $f0, 0x10($sp)
/* B93E38 802409F8 4600020D */  trunc.w.s $f8, $f0
/* B93E3C 802409FC 44024000 */  mfc1      $v0, $f8
/* B93E40 80240A00 E6400038 */  swc1      $f0, 0x38($s2)
/* B93E44 80240A04 A6220010 */  sh        $v0, 0x10($s1)
/* B93E48 80240A08 C660003C */  lwc1      $f0, 0x3c($s3)
/* B93E4C 80240A0C C622006C */  lwc1      $f2, 0x6c($s1)
/* B93E50 80240A10 468010A0 */  cvt.s.w   $f2, $f2
/* B93E54 80240A14 46020000 */  add.s     $f0, $f0, $f2
/* B93E58 80240A18 3C03800F */  lui       $v1, %hi(gPlayerStatusPtr)
/* B93E5C 80240A1C 8C637B30 */  lw        $v1, %lo(gPlayerStatusPtr)($v1)
/* B93E60 80240A20 E640003C */  swc1      $f0, 0x3c($s2)
/* B93E64 80240A24 C7A20014 */  lwc1      $f2, 0x14($sp)
/* B93E68 80240A28 4600020D */  trunc.w.s $f8, $f0
/* B93E6C 80240A2C 44024000 */  mfc1      $v0, $f8
/* B93E70 80240A30 00000000 */  nop
/* B93E74 80240A34 A6220012 */  sh        $v0, 0x12($s1)
/* B93E78 80240A38 4600120D */  trunc.w.s $f8, $f2
/* B93E7C 80240A3C 44024000 */  mfc1      $v0, $f8
/* B93E80 80240A40 E6420040 */  swc1      $f2, 0x40($s2)
/* B93E84 80240A44 A6220014 */  sh        $v0, 0x14($s1)
/* B93E88 80240A48 8C660028 */  lw        $a2, 0x28($v1)
/* B93E8C 80240A4C 8C670030 */  lw        $a3, 0x30($v1)
/* B93E90 80240A50 C64C0038 */  lwc1      $f12, 0x38($s2)
/* B93E94 80240A54 0C00A720 */  jal       atan2
/* B93E98 80240A58 C64E0040 */   lwc1     $f14, 0x40($s2)
/* B93E9C 80240A5C 3C03E0EF */  lui       $v1, 0xe0ef
/* B93EA0 80240A60 E640000C */  swc1      $f0, 0xc($s2)
/* B93EA4 80240A64 8E220000 */  lw        $v0, ($s1)
/* B93EA8 80240A68 3463FFFF */  ori       $v1, $v1, 0xffff
/* B93EAC 80240A6C 00431024 */  and       $v0, $v0, $v1
/* B93EB0 80240A70 AE220000 */  sw        $v0, ($s1)
/* B93EB4 80240A74 24020001 */  addiu     $v0, $zero, 1
/* B93EB8 80240A78 A640008E */  sh        $zero, 0x8e($s2)
/* B93EBC 80240A7C 080902BE */  j         .L80240AF8
/* B93EC0 80240A80 AE820070 */   sw       $v0, 0x70($s4)
.L80240A84:
/* B93EC4 80240A84 86240008 */  lh        $a0, 8($s1)
/* B93EC8 80240A88 0C00FB3A */  jal       get_enemy
/* B93ECC 80240A8C 2484FFFF */   addiu    $a0, $a0, -1
/* B93ED0 80240A90 0040802D */  daddu     $s0, $v0, $zero
/* B93ED4 80240A94 0C00EABB */  jal       get_npc_unsafe
/* B93ED8 80240A98 86040008 */   lh       $a0, 8($s0)
/* B93EDC 80240A9C 9642008E */  lhu       $v0, 0x8e($s2)
/* B93EE0 80240AA0 24420001 */  addiu     $v0, $v0, 1
/* B93EE4 80240AA4 A642008E */  sh        $v0, 0x8e($s2)
/* B93EE8 80240AA8 00021400 */  sll       $v0, $v0, 0x10
/* B93EEC 80240AAC 8E23007C */  lw        $v1, 0x7c($s1)
/* B93EF0 80240AB0 00021403 */  sra       $v0, $v0, 0x10
/* B93EF4 80240AB4 0043102A */  slt       $v0, $v0, $v1
/* B93EF8 80240AB8 50400001 */  beql      $v0, $zero, .L80240AC0
/* B93EFC 80240ABC A2200007 */   sb       $zero, 7($s1)
.L80240AC0:
/* B93F00 80240AC0 8E03006C */  lw        $v1, 0x6c($s0)
/* B93F04 80240AC4 24020004 */  addiu     $v0, $zero, 4
/* B93F08 80240AC8 1462000B */  bne       $v1, $v0, .L80240AF8
/* B93F0C 80240ACC 3C021F10 */   lui      $v0, 0x1f10
/* B93F10 80240AD0 8E230000 */  lw        $v1, ($s1)
/* B93F14 80240AD4 3C01C47A */  lui       $at, 0xc47a
/* B93F18 80240AD8 44810000 */  mtc1      $at, $f0
/* B93F1C 80240ADC 00621825 */  or        $v1, $v1, $v0
/* B93F20 80240AE0 AE230000 */  sw        $v1, ($s1)
/* B93F24 80240AE4 AE400038 */  sw        $zero, 0x38($s2)
/* B93F28 80240AE8 E640003C */  swc1      $f0, 0x3c($s2)
/* B93F2C 80240AEC AE400040 */  sw        $zero, 0x40($s2)
/* B93F30 80240AF0 A2330007 */  sb        $s3, 7($s1)
/* B93F34 80240AF4 AE800070 */  sw        $zero, 0x70($s4)
.L80240AF8:
/* B93F38 80240AF8 8FBF002C */  lw        $ra, 0x2c($sp)
/* B93F3C 80240AFC 8FB40028 */  lw        $s4, 0x28($sp)
/* B93F40 80240B00 8FB30024 */  lw        $s3, 0x24($sp)
/* B93F44 80240B04 8FB20020 */  lw        $s2, 0x20($sp)
/* B93F48 80240B08 8FB1001C */  lw        $s1, 0x1c($sp)
/* B93F4C 80240B0C 8FB00018 */  lw        $s0, 0x18($sp)
/* B93F50 80240B10 0000102D */  daddu     $v0, $zero, $zero
/* B93F54 80240B14 03E00008 */  jr        $ra
/* B93F58 80240B18 27BD0030 */   addiu    $sp, $sp, 0x30
