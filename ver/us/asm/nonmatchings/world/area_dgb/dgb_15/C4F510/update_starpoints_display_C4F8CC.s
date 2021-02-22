.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel update_starpoints_display_C4F8CC
/* C4F8CC 802403BC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C4F8D0 802403C0 AFB40028 */  sw        $s4, 0x28($sp)
/* C4F8D4 802403C4 0080A02D */  daddu     $s4, $a0, $zero
/* C4F8D8 802403C8 AFBF002C */  sw        $ra, 0x2c($sp)
/* C4F8DC 802403CC AFB30024 */  sw        $s3, 0x24($sp)
/* C4F8E0 802403D0 AFB20020 */  sw        $s2, 0x20($sp)
/* C4F8E4 802403D4 AFB1001C */  sw        $s1, 0x1c($sp)
/* C4F8E8 802403D8 AFB00018 */  sw        $s0, 0x18($sp)
/* C4F8EC 802403DC 8E910148 */  lw        $s1, 0x148($s4)
/* C4F8F0 802403E0 86240008 */  lh        $a0, 8($s1)
/* C4F8F4 802403E4 0C00EABB */  jal       get_npc_unsafe
/* C4F8F8 802403E8 00A0802D */   daddu    $s0, $a1, $zero
/* C4F8FC 802403EC 16000005 */  bnez      $s0, .L80240404
/* C4F900 802403F0 0040902D */   daddu    $s2, $v0, $zero
/* C4F904 802403F4 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C4F908 802403F8 30420004 */  andi      $v0, $v0, 4
/* C4F90C 802403FC 10400015 */  beqz      $v0, .L80240454
/* C4F910 80240400 00000000 */   nop
.L80240404:
/* C4F914 80240404 AE800070 */  sw        $zero, 0x70($s4)
/* C4F918 80240408 8E420000 */  lw        $v0, ($s2)
/* C4F91C 8024040C 3C031F30 */  lui       $v1, 0x1f30
/* C4F920 80240410 A640008E */  sh        $zero, 0x8e($s2)
/* C4F924 80240414 34420102 */  ori       $v0, $v0, 0x102
/* C4F928 80240418 AE420000 */  sw        $v0, ($s2)
/* C4F92C 8024041C 8E220000 */  lw        $v0, ($s1)
/* C4F930 80240420 3C01C47A */  lui       $at, 0xc47a
/* C4F934 80240424 44810000 */  mtc1      $at, $f0
/* C4F938 80240428 00431025 */  or        $v0, $v0, $v1
/* C4F93C 8024042C AE220000 */  sw        $v0, ($s1)
/* C4F940 80240430 AE400038 */  sw        $zero, 0x38($s2)
/* C4F944 80240434 E640003C */  swc1      $f0, 0x3c($s2)
/* C4F948 80240438 AE400040 */  sw        $zero, 0x40($s2)
/* C4F94C 8024043C 8E2300B0 */  lw        $v1, 0xb0($s1)
/* C4F950 80240440 30620004 */  andi      $v0, $v1, 4
/* C4F954 80240444 10400003 */  beqz      $v0, .L80240454
/* C4F958 80240448 2402FFFB */   addiu    $v0, $zero, -5
/* C4F95C 8024044C 00621024 */  and       $v0, $v1, $v0
/* C4F960 80240450 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80240454:
/* C4F964 80240454 8E930070 */  lw        $s3, 0x70($s4)
/* C4F968 80240458 12600005 */  beqz      $s3, .L80240470
/* C4F96C 8024045C 24020001 */   addiu    $v0, $zero, 1
/* C4F970 80240460 12620048 */  beq       $s3, $v0, .L80240584
/* C4F974 80240464 00000000 */   nop
/* C4F978 80240468 0809017E */  j         .L802405F8
/* C4F97C 8024046C 00000000 */   nop
.L80240470:
/* C4F980 80240470 86240008 */  lh        $a0, 8($s1)
/* C4F984 80240474 0C00FB3A */  jal       get_enemy
/* C4F988 80240478 2484FFFF */   addiu    $a0, $a0, -1
/* C4F98C 8024047C 0040802D */  daddu     $s0, $v0, $zero
/* C4F990 80240480 0C00EABB */  jal       get_npc_unsafe
/* C4F994 80240484 86040008 */   lh       $a0, 8($s0)
/* C4F998 80240488 24030001 */  addiu     $v1, $zero, 1
/* C4F99C 8024048C 0040982D */  daddu     $s3, $v0, $zero
/* C4F9A0 80240490 A2230007 */  sb        $v1, 7($s1)
/* C4F9A4 80240494 8E03006C */  lw        $v1, 0x6c($s0)
/* C4F9A8 80240498 24020003 */  addiu     $v0, $zero, 3
/* C4F9AC 8024049C 14620056 */  bne       $v1, $v0, .L802405F8
/* C4F9B0 802404A0 00000000 */   nop
/* C4F9B4 802404A4 8E2500A8 */  lw        $a1, 0xa8($s1)
/* C4F9B8 802404A8 10A00003 */  beqz      $a1, .L802404B8
/* C4F9BC 802404AC 0260202D */   daddu    $a0, $s3, $zero
/* C4F9C0 802404B0 0C012530 */  jal       func_800494C0
/* C4F9C4 802404B4 0000302D */   daddu    $a2, $zero, $zero
.L802404B8:
/* C4F9C8 802404B8 27A40010 */  addiu     $a0, $sp, 0x10
/* C4F9CC 802404BC C6280070 */  lwc1      $f8, 0x70($s1)
/* C4F9D0 802404C0 46804220 */  cvt.s.w   $f8, $f8
/* C4F9D4 802404C4 C6620034 */  lwc1      $f2, 0x34($s3)
/* C4F9D8 802404C8 3C014387 */  lui       $at, 0x4387
/* C4F9DC 802404CC 44810000 */  mtc1      $at, $f0
/* C4F9E0 802404D0 44064000 */  mfc1      $a2, $f8
/* C4F9E4 802404D4 46020001 */  sub.s     $f0, $f0, $f2
/* C4F9E8 802404D8 C6660038 */  lwc1      $f6, 0x38($s3)
/* C4F9EC 802404DC C6640040 */  lwc1      $f4, 0x40($s3)
/* C4F9F0 802404E0 44070000 */  mfc1      $a3, $f0
/* C4F9F4 802404E4 27A50014 */  addiu     $a1, $sp, 0x14
/* C4F9F8 802404E8 E7A60010 */  swc1      $f6, 0x10($sp)
/* C4F9FC 802404EC 0C00A7E7 */  jal       add_vec2D_polar
/* C4FA00 802404F0 E7A40014 */   swc1     $f4, 0x14($sp)
/* C4FA04 802404F4 C7A00010 */  lwc1      $f0, 0x10($sp)
/* C4FA08 802404F8 4600020D */  trunc.w.s $f8, $f0
/* C4FA0C 802404FC 44024000 */  mfc1      $v0, $f8
/* C4FA10 80240500 E6400038 */  swc1      $f0, 0x38($s2)
/* C4FA14 80240504 A6220010 */  sh        $v0, 0x10($s1)
/* C4FA18 80240508 C660003C */  lwc1      $f0, 0x3c($s3)
/* C4FA1C 8024050C C622006C */  lwc1      $f2, 0x6c($s1)
/* C4FA20 80240510 468010A0 */  cvt.s.w   $f2, $f2
/* C4FA24 80240514 46020000 */  add.s     $f0, $f0, $f2
/* C4FA28 80240518 3C03800F */  lui       $v1, %hi(gPlayerStatusPtr)
/* C4FA2C 8024051C 8C637B30 */  lw        $v1, %lo(gPlayerStatusPtr)($v1)
/* C4FA30 80240520 E640003C */  swc1      $f0, 0x3c($s2)
/* C4FA34 80240524 C7A20014 */  lwc1      $f2, 0x14($sp)
/* C4FA38 80240528 4600020D */  trunc.w.s $f8, $f0
/* C4FA3C 8024052C 44024000 */  mfc1      $v0, $f8
/* C4FA40 80240530 00000000 */  nop
/* C4FA44 80240534 A6220012 */  sh        $v0, 0x12($s1)
/* C4FA48 80240538 4600120D */  trunc.w.s $f8, $f2
/* C4FA4C 8024053C 44024000 */  mfc1      $v0, $f8
/* C4FA50 80240540 E6420040 */  swc1      $f2, 0x40($s2)
/* C4FA54 80240544 A6220014 */  sh        $v0, 0x14($s1)
/* C4FA58 80240548 8C660028 */  lw        $a2, 0x28($v1)
/* C4FA5C 8024054C 8C670030 */  lw        $a3, 0x30($v1)
/* C4FA60 80240550 C64C0038 */  lwc1      $f12, 0x38($s2)
/* C4FA64 80240554 0C00A720 */  jal       atan2
/* C4FA68 80240558 C64E0040 */   lwc1     $f14, 0x40($s2)
/* C4FA6C 8024055C 3C03E0EF */  lui       $v1, 0xe0ef
/* C4FA70 80240560 E640000C */  swc1      $f0, 0xc($s2)
/* C4FA74 80240564 8E220000 */  lw        $v0, ($s1)
/* C4FA78 80240568 3463FFFF */  ori       $v1, $v1, 0xffff
/* C4FA7C 8024056C 00431024 */  and       $v0, $v0, $v1
/* C4FA80 80240570 AE220000 */  sw        $v0, ($s1)
/* C4FA84 80240574 24020001 */  addiu     $v0, $zero, 1
/* C4FA88 80240578 A640008E */  sh        $zero, 0x8e($s2)
/* C4FA8C 8024057C 0809017E */  j         .L802405F8
/* C4FA90 80240580 AE820070 */   sw       $v0, 0x70($s4)
.L80240584:
/* C4FA94 80240584 86240008 */  lh        $a0, 8($s1)
/* C4FA98 80240588 0C00FB3A */  jal       get_enemy
/* C4FA9C 8024058C 2484FFFF */   addiu    $a0, $a0, -1
/* C4FAA0 80240590 0040802D */  daddu     $s0, $v0, $zero
/* C4FAA4 80240594 0C00EABB */  jal       get_npc_unsafe
/* C4FAA8 80240598 86040008 */   lh       $a0, 8($s0)
/* C4FAAC 8024059C 9642008E */  lhu       $v0, 0x8e($s2)
/* C4FAB0 802405A0 24420001 */  addiu     $v0, $v0, 1
/* C4FAB4 802405A4 A642008E */  sh        $v0, 0x8e($s2)
/* C4FAB8 802405A8 00021400 */  sll       $v0, $v0, 0x10
/* C4FABC 802405AC 8E23007C */  lw        $v1, 0x7c($s1)
/* C4FAC0 802405B0 00021403 */  sra       $v0, $v0, 0x10
/* C4FAC4 802405B4 0043102A */  slt       $v0, $v0, $v1
/* C4FAC8 802405B8 50400001 */  beql      $v0, $zero, .L802405C0
/* C4FACC 802405BC A2200007 */   sb       $zero, 7($s1)
.L802405C0:
/* C4FAD0 802405C0 8E03006C */  lw        $v1, 0x6c($s0)
/* C4FAD4 802405C4 24020004 */  addiu     $v0, $zero, 4
/* C4FAD8 802405C8 1462000B */  bne       $v1, $v0, .L802405F8
/* C4FADC 802405CC 3C021F10 */   lui      $v0, 0x1f10
/* C4FAE0 802405D0 8E230000 */  lw        $v1, ($s1)
/* C4FAE4 802405D4 3C01C47A */  lui       $at, 0xc47a
/* C4FAE8 802405D8 44810000 */  mtc1      $at, $f0
/* C4FAEC 802405DC 00621825 */  or        $v1, $v1, $v0
/* C4FAF0 802405E0 AE230000 */  sw        $v1, ($s1)
/* C4FAF4 802405E4 AE400038 */  sw        $zero, 0x38($s2)
/* C4FAF8 802405E8 E640003C */  swc1      $f0, 0x3c($s2)
/* C4FAFC 802405EC AE400040 */  sw        $zero, 0x40($s2)
/* C4FB00 802405F0 A2330007 */  sb        $s3, 7($s1)
/* C4FB04 802405F4 AE800070 */  sw        $zero, 0x70($s4)
.L802405F8:
/* C4FB08 802405F8 8FBF002C */  lw        $ra, 0x2c($sp)
/* C4FB0C 802405FC 8FB40028 */  lw        $s4, 0x28($sp)
/* C4FB10 80240600 8FB30024 */  lw        $s3, 0x24($sp)
/* C4FB14 80240604 8FB20020 */  lw        $s2, 0x20($sp)
/* C4FB18 80240608 8FB1001C */  lw        $s1, 0x1c($sp)
/* C4FB1C 8024060C 8FB00018 */  lw        $s0, 0x18($sp)
/* C4FB20 80240610 0000102D */  daddu     $v0, $zero, $zero
/* C4FB24 80240614 03E00008 */  jr        $ra
/* C4FB28 80240618 27BD0030 */   addiu    $sp, $sp, 0x30
