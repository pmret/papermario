.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024041C_C3AE2C
/* C3AE2C 8024041C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C3AE30 80240420 AFB40028 */  sw        $s4, 0x28($sp)
/* C3AE34 80240424 0080A02D */  daddu     $s4, $a0, $zero
/* C3AE38 80240428 AFBF002C */  sw        $ra, 0x2c($sp)
/* C3AE3C 8024042C AFB30024 */  sw        $s3, 0x24($sp)
/* C3AE40 80240430 AFB20020 */  sw        $s2, 0x20($sp)
/* C3AE44 80240434 AFB1001C */  sw        $s1, 0x1c($sp)
/* C3AE48 80240438 AFB00018 */  sw        $s0, 0x18($sp)
/* C3AE4C 8024043C 8E910148 */  lw        $s1, 0x148($s4)
/* C3AE50 80240440 86240008 */  lh        $a0, 8($s1)
/* C3AE54 80240444 0C00EABB */  jal       get_npc_unsafe
/* C3AE58 80240448 00A0802D */   daddu    $s0, $a1, $zero
/* C3AE5C 8024044C 16000005 */  bnez      $s0, .L80240464
/* C3AE60 80240450 0040902D */   daddu    $s2, $v0, $zero
/* C3AE64 80240454 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C3AE68 80240458 30420004 */  andi      $v0, $v0, 4
/* C3AE6C 8024045C 10400015 */  beqz      $v0, .L802404B4
/* C3AE70 80240460 00000000 */   nop      
.L80240464:
/* C3AE74 80240464 AE800070 */  sw        $zero, 0x70($s4)
/* C3AE78 80240468 8E420000 */  lw        $v0, ($s2)
/* C3AE7C 8024046C 3C031F30 */  lui       $v1, 0x1f30
/* C3AE80 80240470 A640008E */  sh        $zero, 0x8e($s2)
/* C3AE84 80240474 34420102 */  ori       $v0, $v0, 0x102
/* C3AE88 80240478 AE420000 */  sw        $v0, ($s2)
/* C3AE8C 8024047C 8E220000 */  lw        $v0, ($s1)
/* C3AE90 80240480 3C01C47A */  lui       $at, 0xc47a
/* C3AE94 80240484 44810000 */  mtc1      $at, $f0
/* C3AE98 80240488 00431025 */  or        $v0, $v0, $v1
/* C3AE9C 8024048C AE220000 */  sw        $v0, ($s1)
/* C3AEA0 80240490 AE400038 */  sw        $zero, 0x38($s2)
/* C3AEA4 80240494 E640003C */  swc1      $f0, 0x3c($s2)
/* C3AEA8 80240498 AE400040 */  sw        $zero, 0x40($s2)
/* C3AEAC 8024049C 8E2300B0 */  lw        $v1, 0xb0($s1)
/* C3AEB0 802404A0 30620004 */  andi      $v0, $v1, 4
/* C3AEB4 802404A4 10400003 */  beqz      $v0, .L802404B4
/* C3AEB8 802404A8 2402FFFB */   addiu    $v0, $zero, -5
/* C3AEBC 802404AC 00621024 */  and       $v0, $v1, $v0
/* C3AEC0 802404B0 AE2200B0 */  sw        $v0, 0xb0($s1)
.L802404B4:
/* C3AEC4 802404B4 8E930070 */  lw        $s3, 0x70($s4)
/* C3AEC8 802404B8 12600005 */  beqz      $s3, .L802404D0
/* C3AECC 802404BC 24020001 */   addiu    $v0, $zero, 1
/* C3AED0 802404C0 12620048 */  beq       $s3, $v0, .L802405E4
/* C3AED4 802404C4 00000000 */   nop      
/* C3AED8 802404C8 08090196 */  j         .L80240658
/* C3AEDC 802404CC 00000000 */   nop      
.L802404D0:
/* C3AEE0 802404D0 86240008 */  lh        $a0, 8($s1)
/* C3AEE4 802404D4 0C00FB3A */  jal       get_enemy
/* C3AEE8 802404D8 2484FFFF */   addiu    $a0, $a0, -1
/* C3AEEC 802404DC 0040802D */  daddu     $s0, $v0, $zero
/* C3AEF0 802404E0 0C00EABB */  jal       get_npc_unsafe
/* C3AEF4 802404E4 86040008 */   lh       $a0, 8($s0)
/* C3AEF8 802404E8 24030001 */  addiu     $v1, $zero, 1
/* C3AEFC 802404EC 0040982D */  daddu     $s3, $v0, $zero
/* C3AF00 802404F0 A2230007 */  sb        $v1, 7($s1)
/* C3AF04 802404F4 8E03006C */  lw        $v1, 0x6c($s0)
/* C3AF08 802404F8 24020003 */  addiu     $v0, $zero, 3
/* C3AF0C 802404FC 14620056 */  bne       $v1, $v0, .L80240658
/* C3AF10 80240500 00000000 */   nop      
/* C3AF14 80240504 8E2500A8 */  lw        $a1, 0xa8($s1)
/* C3AF18 80240508 10A00003 */  beqz      $a1, .L80240518
/* C3AF1C 8024050C 0260202D */   daddu    $a0, $s3, $zero
/* C3AF20 80240510 0C012530 */  jal       func_800494C0
/* C3AF24 80240514 0000302D */   daddu    $a2, $zero, $zero
.L80240518:
/* C3AF28 80240518 27A40010 */  addiu     $a0, $sp, 0x10
/* C3AF2C 8024051C C6280070 */  lwc1      $f8, 0x70($s1)
/* C3AF30 80240520 46804220 */  cvt.s.w   $f8, $f8
/* C3AF34 80240524 C6620034 */  lwc1      $f2, 0x34($s3)
/* C3AF38 80240528 3C014387 */  lui       $at, 0x4387
/* C3AF3C 8024052C 44810000 */  mtc1      $at, $f0
/* C3AF40 80240530 44064000 */  mfc1      $a2, $f8
/* C3AF44 80240534 46020001 */  sub.s     $f0, $f0, $f2
/* C3AF48 80240538 C6660038 */  lwc1      $f6, 0x38($s3)
/* C3AF4C 8024053C C6640040 */  lwc1      $f4, 0x40($s3)
/* C3AF50 80240540 44070000 */  mfc1      $a3, $f0
/* C3AF54 80240544 27A50014 */  addiu     $a1, $sp, 0x14
/* C3AF58 80240548 E7A60010 */  swc1      $f6, 0x10($sp)
/* C3AF5C 8024054C 0C00A7E7 */  jal       add_vec2D_polar
/* C3AF60 80240550 E7A40014 */   swc1     $f4, 0x14($sp)
/* C3AF64 80240554 C7A00010 */  lwc1      $f0, 0x10($sp)
/* C3AF68 80240558 4600020D */  trunc.w.s $f8, $f0
/* C3AF6C 8024055C 44024000 */  mfc1      $v0, $f8
/* C3AF70 80240560 E6400038 */  swc1      $f0, 0x38($s2)
/* C3AF74 80240564 A6220010 */  sh        $v0, 0x10($s1)
/* C3AF78 80240568 C660003C */  lwc1      $f0, 0x3c($s3)
/* C3AF7C 8024056C C622006C */  lwc1      $f2, 0x6c($s1)
/* C3AF80 80240570 468010A0 */  cvt.s.w   $f2, $f2
/* C3AF84 80240574 46020000 */  add.s     $f0, $f0, $f2
/* C3AF88 80240578 3C03800F */  lui       $v1, %hi(gPlayerStatusPtr)
/* C3AF8C 8024057C 8C637B30 */  lw        $v1, %lo(gPlayerStatusPtr)($v1)
/* C3AF90 80240580 E640003C */  swc1      $f0, 0x3c($s2)
/* C3AF94 80240584 C7A20014 */  lwc1      $f2, 0x14($sp)
/* C3AF98 80240588 4600020D */  trunc.w.s $f8, $f0
/* C3AF9C 8024058C 44024000 */  mfc1      $v0, $f8
/* C3AFA0 80240590 00000000 */  nop       
/* C3AFA4 80240594 A6220012 */  sh        $v0, 0x12($s1)
/* C3AFA8 80240598 4600120D */  trunc.w.s $f8, $f2
/* C3AFAC 8024059C 44024000 */  mfc1      $v0, $f8
/* C3AFB0 802405A0 E6420040 */  swc1      $f2, 0x40($s2)
/* C3AFB4 802405A4 A6220014 */  sh        $v0, 0x14($s1)
/* C3AFB8 802405A8 8C660028 */  lw        $a2, 0x28($v1)
/* C3AFBC 802405AC 8C670030 */  lw        $a3, 0x30($v1)
/* C3AFC0 802405B0 C64C0038 */  lwc1      $f12, 0x38($s2)
/* C3AFC4 802405B4 0C00A720 */  jal       atan2
/* C3AFC8 802405B8 C64E0040 */   lwc1     $f14, 0x40($s2)
/* C3AFCC 802405BC 3C03E0EF */  lui       $v1, 0xe0ef
/* C3AFD0 802405C0 E640000C */  swc1      $f0, 0xc($s2)
/* C3AFD4 802405C4 8E220000 */  lw        $v0, ($s1)
/* C3AFD8 802405C8 3463FFFF */  ori       $v1, $v1, 0xffff
/* C3AFDC 802405CC 00431024 */  and       $v0, $v0, $v1
/* C3AFE0 802405D0 AE220000 */  sw        $v0, ($s1)
/* C3AFE4 802405D4 24020001 */  addiu     $v0, $zero, 1
/* C3AFE8 802405D8 A640008E */  sh        $zero, 0x8e($s2)
/* C3AFEC 802405DC 08090196 */  j         .L80240658
/* C3AFF0 802405E0 AE820070 */   sw       $v0, 0x70($s4)
.L802405E4:
/* C3AFF4 802405E4 86240008 */  lh        $a0, 8($s1)
/* C3AFF8 802405E8 0C00FB3A */  jal       get_enemy
/* C3AFFC 802405EC 2484FFFF */   addiu    $a0, $a0, -1
/* C3B000 802405F0 0040802D */  daddu     $s0, $v0, $zero
/* C3B004 802405F4 0C00EABB */  jal       get_npc_unsafe
/* C3B008 802405F8 86040008 */   lh       $a0, 8($s0)
/* C3B00C 802405FC 9642008E */  lhu       $v0, 0x8e($s2)
/* C3B010 80240600 24420001 */  addiu     $v0, $v0, 1
/* C3B014 80240604 A642008E */  sh        $v0, 0x8e($s2)
/* C3B018 80240608 00021400 */  sll       $v0, $v0, 0x10
/* C3B01C 8024060C 8E23007C */  lw        $v1, 0x7c($s1)
/* C3B020 80240610 00021403 */  sra       $v0, $v0, 0x10
/* C3B024 80240614 0043102A */  slt       $v0, $v0, $v1
/* C3B028 80240618 50400001 */  beql      $v0, $zero, .L80240620
/* C3B02C 8024061C A2200007 */   sb       $zero, 7($s1)
.L80240620:
/* C3B030 80240620 8E03006C */  lw        $v1, 0x6c($s0)
/* C3B034 80240624 24020004 */  addiu     $v0, $zero, 4
/* C3B038 80240628 1462000B */  bne       $v1, $v0, .L80240658
/* C3B03C 8024062C 3C021F10 */   lui      $v0, 0x1f10
/* C3B040 80240630 8E230000 */  lw        $v1, ($s1)
/* C3B044 80240634 3C01C47A */  lui       $at, 0xc47a
/* C3B048 80240638 44810000 */  mtc1      $at, $f0
/* C3B04C 8024063C 00621825 */  or        $v1, $v1, $v0
/* C3B050 80240640 AE230000 */  sw        $v1, ($s1)
/* C3B054 80240644 AE400038 */  sw        $zero, 0x38($s2)
/* C3B058 80240648 E640003C */  swc1      $f0, 0x3c($s2)
/* C3B05C 8024064C AE400040 */  sw        $zero, 0x40($s2)
/* C3B060 80240650 A2330007 */  sb        $s3, 7($s1)
/* C3B064 80240654 AE800070 */  sw        $zero, 0x70($s4)
.L80240658:
/* C3B068 80240658 8FBF002C */  lw        $ra, 0x2c($sp)
/* C3B06C 8024065C 8FB40028 */  lw        $s4, 0x28($sp)
/* C3B070 80240660 8FB30024 */  lw        $s3, 0x24($sp)
/* C3B074 80240664 8FB20020 */  lw        $s2, 0x20($sp)
/* C3B078 80240668 8FB1001C */  lw        $s1, 0x1c($sp)
/* C3B07C 8024066C 8FB00018 */  lw        $s0, 0x18($sp)
/* C3B080 80240670 0000102D */  daddu     $v0, $zero, $zero
/* C3B084 80240674 03E00008 */  jr        $ra
/* C3B088 80240678 27BD0030 */   addiu    $sp, $sp, 0x30
