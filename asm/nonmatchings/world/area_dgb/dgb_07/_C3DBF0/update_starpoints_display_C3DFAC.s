.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel update_starpoints_display_C3DFAC
/* C3DFAC 802403BC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C3DFB0 802403C0 AFB40028 */  sw        $s4, 0x28($sp)
/* C3DFB4 802403C4 0080A02D */  daddu     $s4, $a0, $zero
/* C3DFB8 802403C8 AFBF002C */  sw        $ra, 0x2c($sp)
/* C3DFBC 802403CC AFB30024 */  sw        $s3, 0x24($sp)
/* C3DFC0 802403D0 AFB20020 */  sw        $s2, 0x20($sp)
/* C3DFC4 802403D4 AFB1001C */  sw        $s1, 0x1c($sp)
/* C3DFC8 802403D8 AFB00018 */  sw        $s0, 0x18($sp)
/* C3DFCC 802403DC 8E910148 */  lw        $s1, 0x148($s4)
/* C3DFD0 802403E0 86240008 */  lh        $a0, 8($s1)
/* C3DFD4 802403E4 0C00EABB */  jal       get_npc_unsafe
/* C3DFD8 802403E8 00A0802D */   daddu    $s0, $a1, $zero
/* C3DFDC 802403EC 16000005 */  bnez      $s0, .L80240404
/* C3DFE0 802403F0 0040902D */   daddu    $s2, $v0, $zero
/* C3DFE4 802403F4 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C3DFE8 802403F8 30420004 */  andi      $v0, $v0, 4
/* C3DFEC 802403FC 10400015 */  beqz      $v0, .L80240454
/* C3DFF0 80240400 00000000 */   nop      
.L80240404:
/* C3DFF4 80240404 AE800070 */  sw        $zero, 0x70($s4)
/* C3DFF8 80240408 8E420000 */  lw        $v0, ($s2)
/* C3DFFC 8024040C 3C031F30 */  lui       $v1, 0x1f30
/* C3E000 80240410 A640008E */  sh        $zero, 0x8e($s2)
/* C3E004 80240414 34420102 */  ori       $v0, $v0, 0x102
/* C3E008 80240418 AE420000 */  sw        $v0, ($s2)
/* C3E00C 8024041C 8E220000 */  lw        $v0, ($s1)
/* C3E010 80240420 3C01C47A */  lui       $at, 0xc47a
/* C3E014 80240424 44810000 */  mtc1      $at, $f0
/* C3E018 80240428 00431025 */  or        $v0, $v0, $v1
/* C3E01C 8024042C AE220000 */  sw        $v0, ($s1)
/* C3E020 80240430 AE400038 */  sw        $zero, 0x38($s2)
/* C3E024 80240434 E640003C */  swc1      $f0, 0x3c($s2)
/* C3E028 80240438 AE400040 */  sw        $zero, 0x40($s2)
/* C3E02C 8024043C 8E2300B0 */  lw        $v1, 0xb0($s1)
/* C3E030 80240440 30620004 */  andi      $v0, $v1, 4
/* C3E034 80240444 10400003 */  beqz      $v0, .L80240454
/* C3E038 80240448 2402FFFB */   addiu    $v0, $zero, -5
/* C3E03C 8024044C 00621024 */  and       $v0, $v1, $v0
/* C3E040 80240450 AE2200B0 */  sw        $v0, 0xb0($s1)
.L80240454:
/* C3E044 80240454 8E930070 */  lw        $s3, 0x70($s4)
/* C3E048 80240458 12600005 */  beqz      $s3, .L80240470
/* C3E04C 8024045C 24020001 */   addiu    $v0, $zero, 1
/* C3E050 80240460 12620048 */  beq       $s3, $v0, .L80240584
/* C3E054 80240464 00000000 */   nop      
/* C3E058 80240468 0809017E */  j         .L802405F8
/* C3E05C 8024046C 00000000 */   nop      
.L80240470:
/* C3E060 80240470 86240008 */  lh        $a0, 8($s1)
/* C3E064 80240474 0C00FB3A */  jal       get_enemy
/* C3E068 80240478 2484FFFF */   addiu    $a0, $a0, -1
/* C3E06C 8024047C 0040802D */  daddu     $s0, $v0, $zero
/* C3E070 80240480 0C00EABB */  jal       get_npc_unsafe
/* C3E074 80240484 86040008 */   lh       $a0, 8($s0)
/* C3E078 80240488 24030001 */  addiu     $v1, $zero, 1
/* C3E07C 8024048C 0040982D */  daddu     $s3, $v0, $zero
/* C3E080 80240490 A2230007 */  sb        $v1, 7($s1)
/* C3E084 80240494 8E03006C */  lw        $v1, 0x6c($s0)
/* C3E088 80240498 24020003 */  addiu     $v0, $zero, 3
/* C3E08C 8024049C 14620056 */  bne       $v1, $v0, .L802405F8
/* C3E090 802404A0 00000000 */   nop      
/* C3E094 802404A4 8E2500A8 */  lw        $a1, 0xa8($s1)
/* C3E098 802404A8 10A00003 */  beqz      $a1, .L802404B8
/* C3E09C 802404AC 0260202D */   daddu    $a0, $s3, $zero
/* C3E0A0 802404B0 0C012530 */  jal       func_800494C0
/* C3E0A4 802404B4 0000302D */   daddu    $a2, $zero, $zero
.L802404B8:
/* C3E0A8 802404B8 27A40010 */  addiu     $a0, $sp, 0x10
/* C3E0AC 802404BC C6280070 */  lwc1      $f8, 0x70($s1)
/* C3E0B0 802404C0 46804220 */  cvt.s.w   $f8, $f8
/* C3E0B4 802404C4 C6620034 */  lwc1      $f2, 0x34($s3)
/* C3E0B8 802404C8 3C014387 */  lui       $at, 0x4387
/* C3E0BC 802404CC 44810000 */  mtc1      $at, $f0
/* C3E0C0 802404D0 44064000 */  mfc1      $a2, $f8
/* C3E0C4 802404D4 46020001 */  sub.s     $f0, $f0, $f2
/* C3E0C8 802404D8 C6660038 */  lwc1      $f6, 0x38($s3)
/* C3E0CC 802404DC C6640040 */  lwc1      $f4, 0x40($s3)
/* C3E0D0 802404E0 44070000 */  mfc1      $a3, $f0
/* C3E0D4 802404E4 27A50014 */  addiu     $a1, $sp, 0x14
/* C3E0D8 802404E8 E7A60010 */  swc1      $f6, 0x10($sp)
/* C3E0DC 802404EC 0C00A7E7 */  jal       add_vec2D_polar
/* C3E0E0 802404F0 E7A40014 */   swc1     $f4, 0x14($sp)
/* C3E0E4 802404F4 C7A00010 */  lwc1      $f0, 0x10($sp)
/* C3E0E8 802404F8 4600020D */  trunc.w.s $f8, $f0
/* C3E0EC 802404FC 44024000 */  mfc1      $v0, $f8
/* C3E0F0 80240500 E6400038 */  swc1      $f0, 0x38($s2)
/* C3E0F4 80240504 A6220010 */  sh        $v0, 0x10($s1)
/* C3E0F8 80240508 C660003C */  lwc1      $f0, 0x3c($s3)
/* C3E0FC 8024050C C622006C */  lwc1      $f2, 0x6c($s1)
/* C3E100 80240510 468010A0 */  cvt.s.w   $f2, $f2
/* C3E104 80240514 46020000 */  add.s     $f0, $f0, $f2
/* C3E108 80240518 3C03800F */  lui       $v1, %hi(gPlayerStatusPtr)
/* C3E10C 8024051C 8C637B30 */  lw        $v1, %lo(gPlayerStatusPtr)($v1)
/* C3E110 80240520 E640003C */  swc1      $f0, 0x3c($s2)
/* C3E114 80240524 C7A20014 */  lwc1      $f2, 0x14($sp)
/* C3E118 80240528 4600020D */  trunc.w.s $f8, $f0
/* C3E11C 8024052C 44024000 */  mfc1      $v0, $f8
/* C3E120 80240530 00000000 */  nop       
/* C3E124 80240534 A6220012 */  sh        $v0, 0x12($s1)
/* C3E128 80240538 4600120D */  trunc.w.s $f8, $f2
/* C3E12C 8024053C 44024000 */  mfc1      $v0, $f8
/* C3E130 80240540 E6420040 */  swc1      $f2, 0x40($s2)
/* C3E134 80240544 A6220014 */  sh        $v0, 0x14($s1)
/* C3E138 80240548 8C660028 */  lw        $a2, 0x28($v1)
/* C3E13C 8024054C 8C670030 */  lw        $a3, 0x30($v1)
/* C3E140 80240550 C64C0038 */  lwc1      $f12, 0x38($s2)
/* C3E144 80240554 0C00A720 */  jal       atan2
/* C3E148 80240558 C64E0040 */   lwc1     $f14, 0x40($s2)
/* C3E14C 8024055C 3C03E0EF */  lui       $v1, 0xe0ef
/* C3E150 80240560 E640000C */  swc1      $f0, 0xc($s2)
/* C3E154 80240564 8E220000 */  lw        $v0, ($s1)
/* C3E158 80240568 3463FFFF */  ori       $v1, $v1, 0xffff
/* C3E15C 8024056C 00431024 */  and       $v0, $v0, $v1
/* C3E160 80240570 AE220000 */  sw        $v0, ($s1)
/* C3E164 80240574 24020001 */  addiu     $v0, $zero, 1
/* C3E168 80240578 A640008E */  sh        $zero, 0x8e($s2)
/* C3E16C 8024057C 0809017E */  j         .L802405F8
/* C3E170 80240580 AE820070 */   sw       $v0, 0x70($s4)
.L80240584:
/* C3E174 80240584 86240008 */  lh        $a0, 8($s1)
/* C3E178 80240588 0C00FB3A */  jal       get_enemy
/* C3E17C 8024058C 2484FFFF */   addiu    $a0, $a0, -1
/* C3E180 80240590 0040802D */  daddu     $s0, $v0, $zero
/* C3E184 80240594 0C00EABB */  jal       get_npc_unsafe
/* C3E188 80240598 86040008 */   lh       $a0, 8($s0)
/* C3E18C 8024059C 9642008E */  lhu       $v0, 0x8e($s2)
/* C3E190 802405A0 24420001 */  addiu     $v0, $v0, 1
/* C3E194 802405A4 A642008E */  sh        $v0, 0x8e($s2)
/* C3E198 802405A8 00021400 */  sll       $v0, $v0, 0x10
/* C3E19C 802405AC 8E23007C */  lw        $v1, 0x7c($s1)
/* C3E1A0 802405B0 00021403 */  sra       $v0, $v0, 0x10
/* C3E1A4 802405B4 0043102A */  slt       $v0, $v0, $v1
/* C3E1A8 802405B8 50400001 */  beql      $v0, $zero, .L802405C0
/* C3E1AC 802405BC A2200007 */   sb       $zero, 7($s1)
.L802405C0:
/* C3E1B0 802405C0 8E03006C */  lw        $v1, 0x6c($s0)
/* C3E1B4 802405C4 24020004 */  addiu     $v0, $zero, 4
/* C3E1B8 802405C8 1462000B */  bne       $v1, $v0, .L802405F8
/* C3E1BC 802405CC 3C021F10 */   lui      $v0, 0x1f10
/* C3E1C0 802405D0 8E230000 */  lw        $v1, ($s1)
/* C3E1C4 802405D4 3C01C47A */  lui       $at, 0xc47a
/* C3E1C8 802405D8 44810000 */  mtc1      $at, $f0
/* C3E1CC 802405DC 00621825 */  or        $v1, $v1, $v0
/* C3E1D0 802405E0 AE230000 */  sw        $v1, ($s1)
/* C3E1D4 802405E4 AE400038 */  sw        $zero, 0x38($s2)
/* C3E1D8 802405E8 E640003C */  swc1      $f0, 0x3c($s2)
/* C3E1DC 802405EC AE400040 */  sw        $zero, 0x40($s2)
/* C3E1E0 802405F0 A2330007 */  sb        $s3, 7($s1)
/* C3E1E4 802405F4 AE800070 */  sw        $zero, 0x70($s4)
.L802405F8:
/* C3E1E8 802405F8 8FBF002C */  lw        $ra, 0x2c($sp)
/* C3E1EC 802405FC 8FB40028 */  lw        $s4, 0x28($sp)
/* C3E1F0 80240600 8FB30024 */  lw        $s3, 0x24($sp)
/* C3E1F4 80240604 8FB20020 */  lw        $s2, 0x20($sp)
/* C3E1F8 80240608 8FB1001C */  lw        $s1, 0x1c($sp)
/* C3E1FC 8024060C 8FB00018 */  lw        $s0, 0x18($sp)
/* C3E200 80240610 0000102D */  daddu     $v0, $zero, $zero
/* C3E204 80240614 03E00008 */  jr        $ra
/* C3E208 80240618 27BD0030 */   addiu    $sp, $sp, 0x30
