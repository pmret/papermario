.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel jan_09_UnkFunc7
/* B669C0 80240F10 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B669C4 80240F14 AFB40028 */  sw        $s4, 0x28($sp)
/* B669C8 80240F18 0080A02D */  daddu     $s4, $a0, $zero
/* B669CC 80240F1C AFBF002C */  sw        $ra, 0x2c($sp)
/* B669D0 80240F20 AFB30024 */  sw        $s3, 0x24($sp)
/* B669D4 80240F24 AFB20020 */  sw        $s2, 0x20($sp)
/* B669D8 80240F28 AFB1001C */  sw        $s1, 0x1c($sp)
/* B669DC 80240F2C AFB00018 */  sw        $s0, 0x18($sp)
/* B669E0 80240F30 8E910148 */  lw        $s1, 0x148($s4)
/* B669E4 80240F34 86240008 */  lh        $a0, 8($s1)
/* B669E8 80240F38 0C00EABB */  jal       get_npc_unsafe
/* B669EC 80240F3C 00A0802D */   daddu    $s0, $a1, $zero
/* B669F0 80240F40 16000005 */  bnez      $s0, .L80240F58
/* B669F4 80240F44 0040902D */   daddu    $s2, $v0, $zero
/* B669F8 80240F48 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B669FC 80240F4C 30420004 */  andi      $v0, $v0, 4
/* B66A00 80240F50 10400015 */  beqz      $v0, .L80240FA8
/* B66A04 80240F54 00000000 */   nop
.L80240F58:
/* B66A08 80240F58 AE800070 */  sw        $zero, 0x70($s4)
/* B66A0C 80240F5C 8E420000 */  lw        $v0, ($s2)
/* B66A10 80240F60 3C031F30 */  lui       $v1, 0x1f30
/* B66A14 80240F64 A640008E */  sh        $zero, 0x8e($s2)
/* B66A18 80240F68 34420102 */  ori       $v0, $v0, 0x102
/* B66A1C 80240F6C AE420000 */  sw        $v0, ($s2)
/* B66A20 80240F70 8E220000 */  lw        $v0, ($s1)
/* B66A24 80240F74 3C01C47A */  lui       $at, 0xc47a
/* B66A28 80240F78 44810000 */  mtc1      $at, $f0
/* B66A2C 80240F7C 00431025 */  or        $v0, $v0, $v1
/* B66A30 80240F80 AE220000 */  sw        $v0, ($s1)
/* B66A34 80240F84 AE400038 */  sw        $zero, 0x38($s2)
/* B66A38 80240F88 E640003C */  swc1      $f0, 0x3c($s2)
/* B66A3C 80240F8C AE400040 */  sw        $zero, 0x40($s2)
/* B66A40 80240F90 8E2300B0 */  lw        $v1, 0xb0($s1)
/* B66A44 80240F94 30620004 */  andi      $v0, $v1, 4
/* B66A48 80240F98 10400003 */  beqz      $v0, .L80240FA8
/* B66A4C 80240F9C 2402FFFB */   addiu    $v0, $zero, -5
/* B66A50 80240FA0 00621024 */  and       $v0, $v1, $v0
/* B66A54 80240FA4 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80240FA8:
/* B66A58 80240FA8 8E930070 */  lw        $s3, 0x70($s4)
/* B66A5C 80240FAC 12600005 */  beqz      $s3, .L80240FC4
/* B66A60 80240FB0 24020001 */   addiu    $v0, $zero, 1
/* B66A64 80240FB4 12620048 */  beq       $s3, $v0, .L802410D8
/* B66A68 80240FB8 00000000 */   nop
/* B66A6C 80240FBC 08090453 */  j         .L8024114C
/* B66A70 80240FC0 00000000 */   nop
.L80240FC4:
/* B66A74 80240FC4 86240008 */  lh        $a0, 8($s1)
/* B66A78 80240FC8 0C00FB3A */  jal       get_enemy
/* B66A7C 80240FCC 2484FFFF */   addiu    $a0, $a0, -1
/* B66A80 80240FD0 0040802D */  daddu     $s0, $v0, $zero
/* B66A84 80240FD4 0C00EABB */  jal       get_npc_unsafe
/* B66A88 80240FD8 86040008 */   lh       $a0, 8($s0)
/* B66A8C 80240FDC 24030001 */  addiu     $v1, $zero, 1
/* B66A90 80240FE0 0040982D */  daddu     $s3, $v0, $zero
/* B66A94 80240FE4 A2230007 */  sb        $v1, 7($s1)
/* B66A98 80240FE8 8E03006C */  lw        $v1, 0x6c($s0)
/* B66A9C 80240FEC 24020003 */  addiu     $v0, $zero, 3
/* B66AA0 80240FF0 14620056 */  bne       $v1, $v0, .L8024114C
/* B66AA4 80240FF4 00000000 */   nop
/* B66AA8 80240FF8 8E2500A8 */  lw        $a1, 0xa8($s1)
/* B66AAC 80240FFC 10A00003 */  beqz      $a1, .L8024100C
/* B66AB0 80241000 0260202D */   daddu    $a0, $s3, $zero
/* B66AB4 80241004 0C012530 */  jal       func_800494C0
/* B66AB8 80241008 0000302D */   daddu    $a2, $zero, $zero
.L8024100C:
/* B66ABC 8024100C 27A40010 */  addiu     $a0, $sp, 0x10
/* B66AC0 80241010 C6280070 */  lwc1      $f8, 0x70($s1)
/* B66AC4 80241014 46804220 */  cvt.s.w   $f8, $f8
/* B66AC8 80241018 C6620034 */  lwc1      $f2, 0x34($s3)
/* B66ACC 8024101C 3C014387 */  lui       $at, 0x4387
/* B66AD0 80241020 44810000 */  mtc1      $at, $f0
/* B66AD4 80241024 44064000 */  mfc1      $a2, $f8
/* B66AD8 80241028 46020001 */  sub.s     $f0, $f0, $f2
/* B66ADC 8024102C C6660038 */  lwc1      $f6, 0x38($s3)
/* B66AE0 80241030 C6640040 */  lwc1      $f4, 0x40($s3)
/* B66AE4 80241034 44070000 */  mfc1      $a3, $f0
/* B66AE8 80241038 27A50014 */  addiu     $a1, $sp, 0x14
/* B66AEC 8024103C E7A60010 */  swc1      $f6, 0x10($sp)
/* B66AF0 80241040 0C00A7E7 */  jal       add_vec2D_polar
/* B66AF4 80241044 E7A40014 */   swc1     $f4, 0x14($sp)
/* B66AF8 80241048 C7A00010 */  lwc1      $f0, 0x10($sp)
/* B66AFC 8024104C 4600020D */  trunc.w.s $f8, $f0
/* B66B00 80241050 44024000 */  mfc1      $v0, $f8
/* B66B04 80241054 E6400038 */  swc1      $f0, 0x38($s2)
/* B66B08 80241058 A6220010 */  sh        $v0, 0x10($s1)
/* B66B0C 8024105C C660003C */  lwc1      $f0, 0x3c($s3)
/* B66B10 80241060 C622006C */  lwc1      $f2, 0x6c($s1)
/* B66B14 80241064 468010A0 */  cvt.s.w   $f2, $f2
/* B66B18 80241068 46020000 */  add.s     $f0, $f0, $f2
/* B66B1C 8024106C 3C03800F */  lui       $v1, %hi(gPlayerStatusPtr)
/* B66B20 80241070 8C637B30 */  lw        $v1, %lo(gPlayerStatusPtr)($v1)
/* B66B24 80241074 E640003C */  swc1      $f0, 0x3c($s2)
/* B66B28 80241078 C7A20014 */  lwc1      $f2, 0x14($sp)
/* B66B2C 8024107C 4600020D */  trunc.w.s $f8, $f0
/* B66B30 80241080 44024000 */  mfc1      $v0, $f8
/* B66B34 80241084 00000000 */  nop
/* B66B38 80241088 A6220012 */  sh        $v0, 0x12($s1)
/* B66B3C 8024108C 4600120D */  trunc.w.s $f8, $f2
/* B66B40 80241090 44024000 */  mfc1      $v0, $f8
/* B66B44 80241094 E6420040 */  swc1      $f2, 0x40($s2)
/* B66B48 80241098 A6220014 */  sh        $v0, 0x14($s1)
/* B66B4C 8024109C 8C660028 */  lw        $a2, 0x28($v1)
/* B66B50 802410A0 8C670030 */  lw        $a3, 0x30($v1)
/* B66B54 802410A4 C64C0038 */  lwc1      $f12, 0x38($s2)
/* B66B58 802410A8 0C00A720 */  jal       atan2
/* B66B5C 802410AC C64E0040 */   lwc1     $f14, 0x40($s2)
/* B66B60 802410B0 3C03E0EF */  lui       $v1, 0xe0ef
/* B66B64 802410B4 E640000C */  swc1      $f0, 0xc($s2)
/* B66B68 802410B8 8E220000 */  lw        $v0, ($s1)
/* B66B6C 802410BC 3463FFFF */  ori       $v1, $v1, 0xffff
/* B66B70 802410C0 00431024 */  and       $v0, $v0, $v1
/* B66B74 802410C4 AE220000 */  sw        $v0, ($s1)
/* B66B78 802410C8 24020001 */  addiu     $v0, $zero, 1
/* B66B7C 802410CC A640008E */  sh        $zero, 0x8e($s2)
/* B66B80 802410D0 08090453 */  j         .L8024114C
/* B66B84 802410D4 AE820070 */   sw       $v0, 0x70($s4)
.L802410D8:
/* B66B88 802410D8 86240008 */  lh        $a0, 8($s1)
/* B66B8C 802410DC 0C00FB3A */  jal       get_enemy
/* B66B90 802410E0 2484FFFF */   addiu    $a0, $a0, -1
/* B66B94 802410E4 0040802D */  daddu     $s0, $v0, $zero
/* B66B98 802410E8 0C00EABB */  jal       get_npc_unsafe
/* B66B9C 802410EC 86040008 */   lh       $a0, 8($s0)
/* B66BA0 802410F0 9642008E */  lhu       $v0, 0x8e($s2)
/* B66BA4 802410F4 24420001 */  addiu     $v0, $v0, 1
/* B66BA8 802410F8 A642008E */  sh        $v0, 0x8e($s2)
/* B66BAC 802410FC 00021400 */  sll       $v0, $v0, 0x10
/* B66BB0 80241100 8E23007C */  lw        $v1, 0x7c($s1)
/* B66BB4 80241104 00021403 */  sra       $v0, $v0, 0x10
/* B66BB8 80241108 0043102A */  slt       $v0, $v0, $v1
/* B66BBC 8024110C 50400001 */  beql      $v0, $zero, .L80241114
/* B66BC0 80241110 A2200007 */   sb       $zero, 7($s1)
.L80241114:
/* B66BC4 80241114 8E03006C */  lw        $v1, 0x6c($s0)
/* B66BC8 80241118 24020004 */  addiu     $v0, $zero, 4
/* B66BCC 8024111C 1462000B */  bne       $v1, $v0, .L8024114C
/* B66BD0 80241120 3C021F10 */   lui      $v0, 0x1f10
/* B66BD4 80241124 8E230000 */  lw        $v1, ($s1)
/* B66BD8 80241128 3C01C47A */  lui       $at, 0xc47a
/* B66BDC 8024112C 44810000 */  mtc1      $at, $f0
/* B66BE0 80241130 00621825 */  or        $v1, $v1, $v0
/* B66BE4 80241134 AE230000 */  sw        $v1, ($s1)
/* B66BE8 80241138 AE400038 */  sw        $zero, 0x38($s2)
/* B66BEC 8024113C E640003C */  swc1      $f0, 0x3c($s2)
/* B66BF0 80241140 AE400040 */  sw        $zero, 0x40($s2)
/* B66BF4 80241144 A2330007 */  sb        $s3, 7($s1)
/* B66BF8 80241148 AE800070 */  sw        $zero, 0x70($s4)
.L8024114C:
/* B66BFC 8024114C 8FBF002C */  lw        $ra, 0x2c($sp)
/* B66C00 80241150 8FB40028 */  lw        $s4, 0x28($sp)
/* B66C04 80241154 8FB30024 */  lw        $s3, 0x24($sp)
/* B66C08 80241158 8FB20020 */  lw        $s2, 0x20($sp)
/* B66C0C 8024115C 8FB1001C */  lw        $s1, 0x1c($sp)
/* B66C10 80241160 8FB00018 */  lw        $s0, 0x18($sp)
/* B66C14 80241164 0000102D */  daddu     $v0, $zero, $zero
/* B66C18 80241168 03E00008 */  jr        $ra
/* B66C1C 8024116C 27BD0030 */   addiu    $sp, $sp, 0x30
