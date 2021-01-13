.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A24_B5FCD4
/* B5FCD4 80241A24 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B5FCD8 80241A28 AFB40028 */  sw        $s4, 0x28($sp)
/* B5FCDC 80241A2C 0080A02D */  daddu     $s4, $a0, $zero
/* B5FCE0 80241A30 AFBF002C */  sw        $ra, 0x2c($sp)
/* B5FCE4 80241A34 AFB30024 */  sw        $s3, 0x24($sp)
/* B5FCE8 80241A38 AFB20020 */  sw        $s2, 0x20($sp)
/* B5FCEC 80241A3C AFB1001C */  sw        $s1, 0x1c($sp)
/* B5FCF0 80241A40 AFB00018 */  sw        $s0, 0x18($sp)
/* B5FCF4 80241A44 8E910148 */  lw        $s1, 0x148($s4)
/* B5FCF8 80241A48 86240008 */  lh        $a0, 8($s1)
/* B5FCFC 80241A4C 0C00EABB */  jal       get_npc_unsafe
/* B5FD00 80241A50 00A0802D */   daddu    $s0, $a1, $zero
/* B5FD04 80241A54 16000005 */  bnez      $s0, .L80241A6C
/* B5FD08 80241A58 0040902D */   daddu    $s2, $v0, $zero
/* B5FD0C 80241A5C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* B5FD10 80241A60 30420004 */  andi      $v0, $v0, 4
/* B5FD14 80241A64 10400015 */  beqz      $v0, .L80241ABC
/* B5FD18 80241A68 00000000 */   nop
.L80241A6C:
/* B5FD1C 80241A6C AE800070 */  sw        $zero, 0x70($s4)
/* B5FD20 80241A70 8E420000 */  lw        $v0, ($s2)
/* B5FD24 80241A74 3C031F30 */  lui       $v1, 0x1f30
/* B5FD28 80241A78 A640008E */  sh        $zero, 0x8e($s2)
/* B5FD2C 80241A7C 34420102 */  ori       $v0, $v0, 0x102
/* B5FD30 80241A80 AE420000 */  sw        $v0, ($s2)
/* B5FD34 80241A84 8E220000 */  lw        $v0, ($s1)
/* B5FD38 80241A88 3C01C47A */  lui       $at, 0xc47a
/* B5FD3C 80241A8C 44810000 */  mtc1      $at, $f0
/* B5FD40 80241A90 00431025 */  or        $v0, $v0, $v1
/* B5FD44 80241A94 AE220000 */  sw        $v0, ($s1)
/* B5FD48 80241A98 AE400038 */  sw        $zero, 0x38($s2)
/* B5FD4C 80241A9C E640003C */  swc1      $f0, 0x3c($s2)
/* B5FD50 80241AA0 AE400040 */  sw        $zero, 0x40($s2)
/* B5FD54 80241AA4 8E2300B0 */  lw        $v1, 0xb0($s1)
/* B5FD58 80241AA8 30620004 */  andi      $v0, $v1, 4
/* B5FD5C 80241AAC 10400003 */  beqz      $v0, .L80241ABC
/* B5FD60 80241AB0 2402FFFB */   addiu    $v0, $zero, -5
/* B5FD64 80241AB4 00621024 */  and       $v0, $v1, $v0
/* B5FD68 80241AB8 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80241ABC:
/* B5FD6C 80241ABC 8E930070 */  lw        $s3, 0x70($s4)
/* B5FD70 80241AC0 12600005 */  beqz      $s3, .L80241AD8
/* B5FD74 80241AC4 24020001 */   addiu    $v0, $zero, 1
/* B5FD78 80241AC8 12620048 */  beq       $s3, $v0, .L80241BEC
/* B5FD7C 80241ACC 00000000 */   nop
/* B5FD80 80241AD0 08090718 */  j         .L80241C60
/* B5FD84 80241AD4 00000000 */   nop
.L80241AD8:
/* B5FD88 80241AD8 86240008 */  lh        $a0, 8($s1)
/* B5FD8C 80241ADC 0C00FB3A */  jal       get_enemy
/* B5FD90 80241AE0 2484FFFF */   addiu    $a0, $a0, -1
/* B5FD94 80241AE4 0040802D */  daddu     $s0, $v0, $zero
/* B5FD98 80241AE8 0C00EABB */  jal       get_npc_unsafe
/* B5FD9C 80241AEC 86040008 */   lh       $a0, 8($s0)
/* B5FDA0 80241AF0 24030001 */  addiu     $v1, $zero, 1
/* B5FDA4 80241AF4 0040982D */  daddu     $s3, $v0, $zero
/* B5FDA8 80241AF8 A2230007 */  sb        $v1, 7($s1)
/* B5FDAC 80241AFC 8E03006C */  lw        $v1, 0x6c($s0)
/* B5FDB0 80241B00 24020003 */  addiu     $v0, $zero, 3
/* B5FDB4 80241B04 14620056 */  bne       $v1, $v0, .L80241C60
/* B5FDB8 80241B08 00000000 */   nop
/* B5FDBC 80241B0C 8E2500A8 */  lw        $a1, 0xa8($s1)
/* B5FDC0 80241B10 10A00003 */  beqz      $a1, .L80241B20
/* B5FDC4 80241B14 0260202D */   daddu    $a0, $s3, $zero
/* B5FDC8 80241B18 0C012530 */  jal       func_800494C0
/* B5FDCC 80241B1C 0000302D */   daddu    $a2, $zero, $zero
.L80241B20:
/* B5FDD0 80241B20 27A40010 */  addiu     $a0, $sp, 0x10
/* B5FDD4 80241B24 C6280070 */  lwc1      $f8, 0x70($s1)
/* B5FDD8 80241B28 46804220 */  cvt.s.w   $f8, $f8
/* B5FDDC 80241B2C C6620034 */  lwc1      $f2, 0x34($s3)
/* B5FDE0 80241B30 3C014387 */  lui       $at, 0x4387
/* B5FDE4 80241B34 44810000 */  mtc1      $at, $f0
/* B5FDE8 80241B38 44064000 */  mfc1      $a2, $f8
/* B5FDEC 80241B3C 46020001 */  sub.s     $f0, $f0, $f2
/* B5FDF0 80241B40 C6660038 */  lwc1      $f6, 0x38($s3)
/* B5FDF4 80241B44 C6640040 */  lwc1      $f4, 0x40($s3)
/* B5FDF8 80241B48 44070000 */  mfc1      $a3, $f0
/* B5FDFC 80241B4C 27A50014 */  addiu     $a1, $sp, 0x14
/* B5FE00 80241B50 E7A60010 */  swc1      $f6, 0x10($sp)
/* B5FE04 80241B54 0C00A7E7 */  jal       add_vec2D_polar
/* B5FE08 80241B58 E7A40014 */   swc1     $f4, 0x14($sp)
/* B5FE0C 80241B5C C7A00010 */  lwc1      $f0, 0x10($sp)
/* B5FE10 80241B60 4600020D */  trunc.w.s $f8, $f0
/* B5FE14 80241B64 44024000 */  mfc1      $v0, $f8
/* B5FE18 80241B68 E6400038 */  swc1      $f0, 0x38($s2)
/* B5FE1C 80241B6C A6220010 */  sh        $v0, 0x10($s1)
/* B5FE20 80241B70 C660003C */  lwc1      $f0, 0x3c($s3)
/* B5FE24 80241B74 C622006C */  lwc1      $f2, 0x6c($s1)
/* B5FE28 80241B78 468010A0 */  cvt.s.w   $f2, $f2
/* B5FE2C 80241B7C 46020000 */  add.s     $f0, $f0, $f2
/* B5FE30 80241B80 3C03800F */  lui       $v1, %hi(gPlayerStatusPtr)
/* B5FE34 80241B84 8C637B30 */  lw        $v1, %lo(gPlayerStatusPtr)($v1)
/* B5FE38 80241B88 E640003C */  swc1      $f0, 0x3c($s2)
/* B5FE3C 80241B8C C7A20014 */  lwc1      $f2, 0x14($sp)
/* B5FE40 80241B90 4600020D */  trunc.w.s $f8, $f0
/* B5FE44 80241B94 44024000 */  mfc1      $v0, $f8
/* B5FE48 80241B98 00000000 */  nop
/* B5FE4C 80241B9C A6220012 */  sh        $v0, 0x12($s1)
/* B5FE50 80241BA0 4600120D */  trunc.w.s $f8, $f2
/* B5FE54 80241BA4 44024000 */  mfc1      $v0, $f8
/* B5FE58 80241BA8 E6420040 */  swc1      $f2, 0x40($s2)
/* B5FE5C 80241BAC A6220014 */  sh        $v0, 0x14($s1)
/* B5FE60 80241BB0 8C660028 */  lw        $a2, 0x28($v1)
/* B5FE64 80241BB4 8C670030 */  lw        $a3, 0x30($v1)
/* B5FE68 80241BB8 C64C0038 */  lwc1      $f12, 0x38($s2)
/* B5FE6C 80241BBC 0C00A720 */  jal       atan2
/* B5FE70 80241BC0 C64E0040 */   lwc1     $f14, 0x40($s2)
/* B5FE74 80241BC4 3C03E0EF */  lui       $v1, 0xe0ef
/* B5FE78 80241BC8 E640000C */  swc1      $f0, 0xc($s2)
/* B5FE7C 80241BCC 8E220000 */  lw        $v0, ($s1)
/* B5FE80 80241BD0 3463FFFF */  ori       $v1, $v1, 0xffff
/* B5FE84 80241BD4 00431024 */  and       $v0, $v0, $v1
/* B5FE88 80241BD8 AE220000 */  sw        $v0, ($s1)
/* B5FE8C 80241BDC 24020001 */  addiu     $v0, $zero, 1
/* B5FE90 80241BE0 A640008E */  sh        $zero, 0x8e($s2)
/* B5FE94 80241BE4 08090718 */  j         .L80241C60
/* B5FE98 80241BE8 AE820070 */   sw       $v0, 0x70($s4)
.L80241BEC:
/* B5FE9C 80241BEC 86240008 */  lh        $a0, 8($s1)
/* B5FEA0 80241BF0 0C00FB3A */  jal       get_enemy
/* B5FEA4 80241BF4 2484FFFF */   addiu    $a0, $a0, -1
/* B5FEA8 80241BF8 0040802D */  daddu     $s0, $v0, $zero
/* B5FEAC 80241BFC 0C00EABB */  jal       get_npc_unsafe
/* B5FEB0 80241C00 86040008 */   lh       $a0, 8($s0)
/* B5FEB4 80241C04 9642008E */  lhu       $v0, 0x8e($s2)
/* B5FEB8 80241C08 24420001 */  addiu     $v0, $v0, 1
/* B5FEBC 80241C0C A642008E */  sh        $v0, 0x8e($s2)
/* B5FEC0 80241C10 00021400 */  sll       $v0, $v0, 0x10
/* B5FEC4 80241C14 8E23007C */  lw        $v1, 0x7c($s1)
/* B5FEC8 80241C18 00021403 */  sra       $v0, $v0, 0x10
/* B5FECC 80241C1C 0043102A */  slt       $v0, $v0, $v1
/* B5FED0 80241C20 50400001 */  beql      $v0, $zero, .L80241C28
/* B5FED4 80241C24 A2200007 */   sb       $zero, 7($s1)
.L80241C28:
/* B5FED8 80241C28 8E03006C */  lw        $v1, 0x6c($s0)
/* B5FEDC 80241C2C 24020004 */  addiu     $v0, $zero, 4
/* B5FEE0 80241C30 1462000B */  bne       $v1, $v0, .L80241C60
/* B5FEE4 80241C34 3C021F10 */   lui      $v0, 0x1f10
/* B5FEE8 80241C38 8E230000 */  lw        $v1, ($s1)
/* B5FEEC 80241C3C 3C01C47A */  lui       $at, 0xc47a
/* B5FEF0 80241C40 44810000 */  mtc1      $at, $f0
/* B5FEF4 80241C44 00621825 */  or        $v1, $v1, $v0
/* B5FEF8 80241C48 AE230000 */  sw        $v1, ($s1)
/* B5FEFC 80241C4C AE400038 */  sw        $zero, 0x38($s2)
/* B5FF00 80241C50 E640003C */  swc1      $f0, 0x3c($s2)
/* B5FF04 80241C54 AE400040 */  sw        $zero, 0x40($s2)
/* B5FF08 80241C58 A2330007 */  sb        $s3, 7($s1)
/* B5FF0C 80241C5C AE800070 */  sw        $zero, 0x70($s4)
.L80241C60:
/* B5FF10 80241C60 8FBF002C */  lw        $ra, 0x2c($sp)
/* B5FF14 80241C64 8FB40028 */  lw        $s4, 0x28($sp)
/* B5FF18 80241C68 8FB30024 */  lw        $s3, 0x24($sp)
/* B5FF1C 80241C6C 8FB20020 */  lw        $s2, 0x20($sp)
/* B5FF20 80241C70 8FB1001C */  lw        $s1, 0x1c($sp)
/* B5FF24 80241C74 8FB00018 */  lw        $s0, 0x18($sp)
/* B5FF28 80241C78 0000102D */  daddu     $v0, $zero, $zero
/* B5FF2C 80241C7C 03E00008 */  jr        $ra
/* B5FF30 80241C80 27BD0030 */   addiu    $sp, $sp, 0x30
