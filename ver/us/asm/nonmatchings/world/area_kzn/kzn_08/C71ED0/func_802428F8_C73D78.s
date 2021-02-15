.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802428F8_C73D78
/* C73D78 802428F8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C73D7C 802428FC AFB40028 */  sw        $s4, 0x28($sp)
/* C73D80 80242900 0080A02D */  daddu     $s4, $a0, $zero
/* C73D84 80242904 AFBF002C */  sw        $ra, 0x2c($sp)
/* C73D88 80242908 AFB30024 */  sw        $s3, 0x24($sp)
/* C73D8C 8024290C AFB20020 */  sw        $s2, 0x20($sp)
/* C73D90 80242910 AFB1001C */  sw        $s1, 0x1c($sp)
/* C73D94 80242914 AFB00018 */  sw        $s0, 0x18($sp)
/* C73D98 80242918 8E910148 */  lw        $s1, 0x148($s4)
/* C73D9C 8024291C 86240008 */  lh        $a0, 8($s1)
/* C73DA0 80242920 0C00EABB */  jal       get_npc_unsafe
/* C73DA4 80242924 00A0802D */   daddu    $s0, $a1, $zero
/* C73DA8 80242928 16000005 */  bnez      $s0, .L80242940
/* C73DAC 8024292C 0040902D */   daddu    $s2, $v0, $zero
/* C73DB0 80242930 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C73DB4 80242934 30420004 */  andi      $v0, $v0, 4
/* C73DB8 80242938 10400015 */  beqz      $v0, .L80242990
/* C73DBC 8024293C 00000000 */   nop
.L80242940:
/* C73DC0 80242940 AE800070 */  sw        $zero, 0x70($s4)
/* C73DC4 80242944 8E420000 */  lw        $v0, ($s2)
/* C73DC8 80242948 3C031F30 */  lui       $v1, 0x1f30
/* C73DCC 8024294C A640008E */  sh        $zero, 0x8e($s2)
/* C73DD0 80242950 34420102 */  ori       $v0, $v0, 0x102
/* C73DD4 80242954 AE420000 */  sw        $v0, ($s2)
/* C73DD8 80242958 8E220000 */  lw        $v0, ($s1)
/* C73DDC 8024295C 3C01C47A */  lui       $at, 0xc47a
/* C73DE0 80242960 44810000 */  mtc1      $at, $f0
/* C73DE4 80242964 00431025 */  or        $v0, $v0, $v1
/* C73DE8 80242968 AE220000 */  sw        $v0, ($s1)
/* C73DEC 8024296C AE400038 */  sw        $zero, 0x38($s2)
/* C73DF0 80242970 E640003C */  swc1      $f0, 0x3c($s2)
/* C73DF4 80242974 AE400040 */  sw        $zero, 0x40($s2)
/* C73DF8 80242978 8E2300B0 */  lw        $v1, 0xb0($s1)
/* C73DFC 8024297C 30620004 */  andi      $v0, $v1, 4
/* C73E00 80242980 10400003 */  beqz      $v0, .L80242990
/* C73E04 80242984 2402FFFB */   addiu    $v0, $zero, -5
/* C73E08 80242988 00621024 */  and       $v0, $v1, $v0
/* C73E0C 8024298C AE2200B0 */  sw        $v0, 0xb0($s1)
.L80242990:
/* C73E10 80242990 8E930070 */  lw        $s3, 0x70($s4)
/* C73E14 80242994 12600005 */  beqz      $s3, .L802429AC
/* C73E18 80242998 24020001 */   addiu    $v0, $zero, 1
/* C73E1C 8024299C 12620048 */  beq       $s3, $v0, .L80242AC0
/* C73E20 802429A0 00000000 */   nop
/* C73E24 802429A4 08090ACD */  j         .L80242B34
/* C73E28 802429A8 00000000 */   nop
.L802429AC:
/* C73E2C 802429AC 86240008 */  lh        $a0, 8($s1)
/* C73E30 802429B0 0C00FB3A */  jal       get_enemy
/* C73E34 802429B4 2484FFFF */   addiu    $a0, $a0, -1
/* C73E38 802429B8 0040802D */  daddu     $s0, $v0, $zero
/* C73E3C 802429BC 0C00EABB */  jal       get_npc_unsafe
/* C73E40 802429C0 86040008 */   lh       $a0, 8($s0)
/* C73E44 802429C4 24030001 */  addiu     $v1, $zero, 1
/* C73E48 802429C8 0040982D */  daddu     $s3, $v0, $zero
/* C73E4C 802429CC A2230007 */  sb        $v1, 7($s1)
/* C73E50 802429D0 8E03006C */  lw        $v1, 0x6c($s0)
/* C73E54 802429D4 24020003 */  addiu     $v0, $zero, 3
/* C73E58 802429D8 14620056 */  bne       $v1, $v0, .L80242B34
/* C73E5C 802429DC 00000000 */   nop
/* C73E60 802429E0 8E2500A8 */  lw        $a1, 0xa8($s1)
/* C73E64 802429E4 10A00003 */  beqz      $a1, .L802429F4
/* C73E68 802429E8 0260202D */   daddu    $a0, $s3, $zero
/* C73E6C 802429EC 0C012530 */  jal       func_800494C0
/* C73E70 802429F0 0000302D */   daddu    $a2, $zero, $zero
.L802429F4:
/* C73E74 802429F4 27A40010 */  addiu     $a0, $sp, 0x10
/* C73E78 802429F8 C6280070 */  lwc1      $f8, 0x70($s1)
/* C73E7C 802429FC 46804220 */  cvt.s.w   $f8, $f8
/* C73E80 80242A00 C6620034 */  lwc1      $f2, 0x34($s3)
/* C73E84 80242A04 3C014387 */  lui       $at, 0x4387
/* C73E88 80242A08 44810000 */  mtc1      $at, $f0
/* C73E8C 80242A0C 44064000 */  mfc1      $a2, $f8
/* C73E90 80242A10 46020001 */  sub.s     $f0, $f0, $f2
/* C73E94 80242A14 C6660038 */  lwc1      $f6, 0x38($s3)
/* C73E98 80242A18 C6640040 */  lwc1      $f4, 0x40($s3)
/* C73E9C 80242A1C 44070000 */  mfc1      $a3, $f0
/* C73EA0 80242A20 27A50014 */  addiu     $a1, $sp, 0x14
/* C73EA4 80242A24 E7A60010 */  swc1      $f6, 0x10($sp)
/* C73EA8 80242A28 0C00A7E7 */  jal       add_vec2D_polar
/* C73EAC 80242A2C E7A40014 */   swc1     $f4, 0x14($sp)
/* C73EB0 80242A30 C7A00010 */  lwc1      $f0, 0x10($sp)
/* C73EB4 80242A34 4600020D */  trunc.w.s $f8, $f0
/* C73EB8 80242A38 44024000 */  mfc1      $v0, $f8
/* C73EBC 80242A3C E6400038 */  swc1      $f0, 0x38($s2)
/* C73EC0 80242A40 A6220010 */  sh        $v0, 0x10($s1)
/* C73EC4 80242A44 C660003C */  lwc1      $f0, 0x3c($s3)
/* C73EC8 80242A48 C622006C */  lwc1      $f2, 0x6c($s1)
/* C73ECC 80242A4C 468010A0 */  cvt.s.w   $f2, $f2
/* C73ED0 80242A50 46020000 */  add.s     $f0, $f0, $f2
/* C73ED4 80242A54 3C03800F */  lui       $v1, %hi(gPlayerStatusPtr)
/* C73ED8 80242A58 8C637B30 */  lw        $v1, %lo(gPlayerStatusPtr)($v1)
/* C73EDC 80242A5C E640003C */  swc1      $f0, 0x3c($s2)
/* C73EE0 80242A60 C7A20014 */  lwc1      $f2, 0x14($sp)
/* C73EE4 80242A64 4600020D */  trunc.w.s $f8, $f0
/* C73EE8 80242A68 44024000 */  mfc1      $v0, $f8
/* C73EEC 80242A6C 00000000 */  nop
/* C73EF0 80242A70 A6220012 */  sh        $v0, 0x12($s1)
/* C73EF4 80242A74 4600120D */  trunc.w.s $f8, $f2
/* C73EF8 80242A78 44024000 */  mfc1      $v0, $f8
/* C73EFC 80242A7C E6420040 */  swc1      $f2, 0x40($s2)
/* C73F00 80242A80 A6220014 */  sh        $v0, 0x14($s1)
/* C73F04 80242A84 8C660028 */  lw        $a2, 0x28($v1)
/* C73F08 80242A88 8C670030 */  lw        $a3, 0x30($v1)
/* C73F0C 80242A8C C64C0038 */  lwc1      $f12, 0x38($s2)
/* C73F10 80242A90 0C00A720 */  jal       atan2
/* C73F14 80242A94 C64E0040 */   lwc1     $f14, 0x40($s2)
/* C73F18 80242A98 3C03E0EF */  lui       $v1, 0xe0ef
/* C73F1C 80242A9C E640000C */  swc1      $f0, 0xc($s2)
/* C73F20 80242AA0 8E220000 */  lw        $v0, ($s1)
/* C73F24 80242AA4 3463FFFF */  ori       $v1, $v1, 0xffff
/* C73F28 80242AA8 00431024 */  and       $v0, $v0, $v1
/* C73F2C 80242AAC AE220000 */  sw        $v0, ($s1)
/* C73F30 80242AB0 24020001 */  addiu     $v0, $zero, 1
/* C73F34 80242AB4 A640008E */  sh        $zero, 0x8e($s2)
/* C73F38 80242AB8 08090ACD */  j         .L80242B34
/* C73F3C 80242ABC AE820070 */   sw       $v0, 0x70($s4)
.L80242AC0:
/* C73F40 80242AC0 86240008 */  lh        $a0, 8($s1)
/* C73F44 80242AC4 0C00FB3A */  jal       get_enemy
/* C73F48 80242AC8 2484FFFF */   addiu    $a0, $a0, -1
/* C73F4C 80242ACC 0040802D */  daddu     $s0, $v0, $zero
/* C73F50 80242AD0 0C00EABB */  jal       get_npc_unsafe
/* C73F54 80242AD4 86040008 */   lh       $a0, 8($s0)
/* C73F58 80242AD8 9642008E */  lhu       $v0, 0x8e($s2)
/* C73F5C 80242ADC 24420001 */  addiu     $v0, $v0, 1
/* C73F60 80242AE0 A642008E */  sh        $v0, 0x8e($s2)
/* C73F64 80242AE4 00021400 */  sll       $v0, $v0, 0x10
/* C73F68 80242AE8 8E23007C */  lw        $v1, 0x7c($s1)
/* C73F6C 80242AEC 00021403 */  sra       $v0, $v0, 0x10
/* C73F70 80242AF0 0043102A */  slt       $v0, $v0, $v1
/* C73F74 80242AF4 50400001 */  beql      $v0, $zero, .L80242AFC
/* C73F78 80242AF8 A2200007 */   sb       $zero, 7($s1)
.L80242AFC:
/* C73F7C 80242AFC 8E03006C */  lw        $v1, 0x6c($s0)
/* C73F80 80242B00 24020004 */  addiu     $v0, $zero, 4
/* C73F84 80242B04 1462000B */  bne       $v1, $v0, .L80242B34
/* C73F88 80242B08 3C021F10 */   lui      $v0, 0x1f10
/* C73F8C 80242B0C 8E230000 */  lw        $v1, ($s1)
/* C73F90 80242B10 3C01C47A */  lui       $at, 0xc47a
/* C73F94 80242B14 44810000 */  mtc1      $at, $f0
/* C73F98 80242B18 00621825 */  or        $v1, $v1, $v0
/* C73F9C 80242B1C AE230000 */  sw        $v1, ($s1)
/* C73FA0 80242B20 AE400038 */  sw        $zero, 0x38($s2)
/* C73FA4 80242B24 E640003C */  swc1      $f0, 0x3c($s2)
/* C73FA8 80242B28 AE400040 */  sw        $zero, 0x40($s2)
/* C73FAC 80242B2C A2330007 */  sb        $s3, 7($s1)
/* C73FB0 80242B30 AE800070 */  sw        $zero, 0x70($s4)
.L80242B34:
/* C73FB4 80242B34 8FBF002C */  lw        $ra, 0x2c($sp)
/* C73FB8 80242B38 8FB40028 */  lw        $s4, 0x28($sp)
/* C73FBC 80242B3C 8FB30024 */  lw        $s3, 0x24($sp)
/* C73FC0 80242B40 8FB20020 */  lw        $s2, 0x20($sp)
/* C73FC4 80242B44 8FB1001C */  lw        $s1, 0x1c($sp)
/* C73FC8 80242B48 8FB00018 */  lw        $s0, 0x18($sp)
/* C73FCC 80242B4C 0000102D */  daddu     $v0, $zero, $zero
/* C73FD0 80242B50 03E00008 */  jr        $ra
/* C73FD4 80242B54 27BD0030 */   addiu    $sp, $sp, 0x30
