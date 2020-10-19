.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024042C_BA0B5C
/* BA0B5C 8024042C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* BA0B60 80240430 AFB40028 */  sw        $s4, 0x28($sp)
/* BA0B64 80240434 0080A02D */  daddu     $s4, $a0, $zero
/* BA0B68 80240438 AFBF002C */  sw        $ra, 0x2c($sp)
/* BA0B6C 8024043C AFB30024 */  sw        $s3, 0x24($sp)
/* BA0B70 80240440 AFB20020 */  sw        $s2, 0x20($sp)
/* BA0B74 80240444 AFB1001C */  sw        $s1, 0x1c($sp)
/* BA0B78 80240448 AFB00018 */  sw        $s0, 0x18($sp)
/* BA0B7C 8024044C 8E910148 */  lw        $s1, 0x148($s4)
/* BA0B80 80240450 86240008 */  lh        $a0, 8($s1)
/* BA0B84 80240454 0C00EABB */  jal       get_npc_unsafe
/* BA0B88 80240458 00A0802D */   daddu    $s0, $a1, $zero
/* BA0B8C 8024045C 16000005 */  bnez      $s0, .L80240474
/* BA0B90 80240460 0040902D */   daddu    $s2, $v0, $zero
/* BA0B94 80240464 8E2200B0 */  lw        $v0, 0xb0($s1)
/* BA0B98 80240468 30420004 */  andi      $v0, $v0, 4
/* BA0B9C 8024046C 10400015 */  beqz      $v0, .L802404C4
/* BA0BA0 80240470 00000000 */   nop      
.L80240474:
/* BA0BA4 80240474 AE800070 */  sw        $zero, 0x70($s4)
/* BA0BA8 80240478 8E420000 */  lw        $v0, ($s2)
/* BA0BAC 8024047C 3C031F30 */  lui       $v1, 0x1f30
/* BA0BB0 80240480 A640008E */  sh        $zero, 0x8e($s2)
/* BA0BB4 80240484 34420102 */  ori       $v0, $v0, 0x102
/* BA0BB8 80240488 AE420000 */  sw        $v0, ($s2)
/* BA0BBC 8024048C 8E220000 */  lw        $v0, ($s1)
/* BA0BC0 80240490 3C01C47A */  lui       $at, 0xc47a
/* BA0BC4 80240494 44810000 */  mtc1      $at, $f0
/* BA0BC8 80240498 00431025 */  or        $v0, $v0, $v1
/* BA0BCC 8024049C AE220000 */  sw        $v0, ($s1)
/* BA0BD0 802404A0 AE400038 */  sw        $zero, 0x38($s2)
/* BA0BD4 802404A4 E640003C */  swc1      $f0, 0x3c($s2)
/* BA0BD8 802404A8 AE400040 */  sw        $zero, 0x40($s2)
/* BA0BDC 802404AC 8E2300B0 */  lw        $v1, 0xb0($s1)
/* BA0BE0 802404B0 30620004 */  andi      $v0, $v1, 4
/* BA0BE4 802404B4 10400003 */  beqz      $v0, .L802404C4
/* BA0BE8 802404B8 2402FFFB */   addiu    $v0, $zero, -5
/* BA0BEC 802404BC 00621024 */  and       $v0, $v1, $v0
/* BA0BF0 802404C0 AE2200B0 */  sw        $v0, 0xb0($s1)
.L802404C4:
/* BA0BF4 802404C4 8E930070 */  lw        $s3, 0x70($s4)
/* BA0BF8 802404C8 12600005 */  beqz      $s3, .L802404E0
/* BA0BFC 802404CC 24020001 */   addiu    $v0, $zero, 1
/* BA0C00 802404D0 12620048 */  beq       $s3, $v0, .L802405F4
/* BA0C04 802404D4 00000000 */   nop      
/* BA0C08 802404D8 0809019A */  j         .L80240668
/* BA0C0C 802404DC 00000000 */   nop      
.L802404E0:
/* BA0C10 802404E0 86240008 */  lh        $a0, 8($s1)
/* BA0C14 802404E4 0C00FB3A */  jal       get_enemy
/* BA0C18 802404E8 2484FFFF */   addiu    $a0, $a0, -1
/* BA0C1C 802404EC 0040802D */  daddu     $s0, $v0, $zero
/* BA0C20 802404F0 0C00EABB */  jal       get_npc_unsafe
/* BA0C24 802404F4 86040008 */   lh       $a0, 8($s0)
/* BA0C28 802404F8 24030001 */  addiu     $v1, $zero, 1
/* BA0C2C 802404FC 0040982D */  daddu     $s3, $v0, $zero
/* BA0C30 80240500 A2230007 */  sb        $v1, 7($s1)
/* BA0C34 80240504 8E03006C */  lw        $v1, 0x6c($s0)
/* BA0C38 80240508 24020003 */  addiu     $v0, $zero, 3
/* BA0C3C 8024050C 14620056 */  bne       $v1, $v0, .L80240668
/* BA0C40 80240510 00000000 */   nop      
/* BA0C44 80240514 8E2500A8 */  lw        $a1, 0xa8($s1)
/* BA0C48 80240518 10A00003 */  beqz      $a1, .L80240528
/* BA0C4C 8024051C 0260202D */   daddu    $a0, $s3, $zero
/* BA0C50 80240520 0C012530 */  jal       func_800494C0
/* BA0C54 80240524 0000302D */   daddu    $a2, $zero, $zero
.L80240528:
/* BA0C58 80240528 27A40010 */  addiu     $a0, $sp, 0x10
/* BA0C5C 8024052C C6280070 */  lwc1      $f8, 0x70($s1)
/* BA0C60 80240530 46804220 */  cvt.s.w   $f8, $f8
/* BA0C64 80240534 C6620034 */  lwc1      $f2, 0x34($s3)
/* BA0C68 80240538 3C014387 */  lui       $at, 0x4387
/* BA0C6C 8024053C 44810000 */  mtc1      $at, $f0
/* BA0C70 80240540 44064000 */  mfc1      $a2, $f8
/* BA0C74 80240544 46020001 */  sub.s     $f0, $f0, $f2
/* BA0C78 80240548 C6660038 */  lwc1      $f6, 0x38($s3)
/* BA0C7C 8024054C C6640040 */  lwc1      $f4, 0x40($s3)
/* BA0C80 80240550 44070000 */  mfc1      $a3, $f0
/* BA0C84 80240554 27A50014 */  addiu     $a1, $sp, 0x14
/* BA0C88 80240558 E7A60010 */  swc1      $f6, 0x10($sp)
/* BA0C8C 8024055C 0C00A7E7 */  jal       add_vec2D_polar
/* BA0C90 80240560 E7A40014 */   swc1     $f4, 0x14($sp)
/* BA0C94 80240564 C7A00010 */  lwc1      $f0, 0x10($sp)
/* BA0C98 80240568 4600020D */  trunc.w.s $f8, $f0
/* BA0C9C 8024056C 44024000 */  mfc1      $v0, $f8
/* BA0CA0 80240570 E6400038 */  swc1      $f0, 0x38($s2)
/* BA0CA4 80240574 A6220010 */  sh        $v0, 0x10($s1)
/* BA0CA8 80240578 C660003C */  lwc1      $f0, 0x3c($s3)
/* BA0CAC 8024057C C622006C */  lwc1      $f2, 0x6c($s1)
/* BA0CB0 80240580 468010A0 */  cvt.s.w   $f2, $f2
/* BA0CB4 80240584 46020000 */  add.s     $f0, $f0, $f2
/* BA0CB8 80240588 3C03800F */  lui       $v1, %hi(gPlayerStatusPtr)
/* BA0CBC 8024058C 8C637B30 */  lw        $v1, %lo(gPlayerStatusPtr)($v1)
/* BA0CC0 80240590 E640003C */  swc1      $f0, 0x3c($s2)
/* BA0CC4 80240594 C7A20014 */  lwc1      $f2, 0x14($sp)
/* BA0CC8 80240598 4600020D */  trunc.w.s $f8, $f0
/* BA0CCC 8024059C 44024000 */  mfc1      $v0, $f8
/* BA0CD0 802405A0 00000000 */  nop       
/* BA0CD4 802405A4 A6220012 */  sh        $v0, 0x12($s1)
/* BA0CD8 802405A8 4600120D */  trunc.w.s $f8, $f2
/* BA0CDC 802405AC 44024000 */  mfc1      $v0, $f8
/* BA0CE0 802405B0 E6420040 */  swc1      $f2, 0x40($s2)
/* BA0CE4 802405B4 A6220014 */  sh        $v0, 0x14($s1)
/* BA0CE8 802405B8 8C660028 */  lw        $a2, 0x28($v1)
/* BA0CEC 802405BC 8C670030 */  lw        $a3, 0x30($v1)
/* BA0CF0 802405C0 C64C0038 */  lwc1      $f12, 0x38($s2)
/* BA0CF4 802405C4 0C00A720 */  jal       atan2
/* BA0CF8 802405C8 C64E0040 */   lwc1     $f14, 0x40($s2)
/* BA0CFC 802405CC 3C03E0EF */  lui       $v1, 0xe0ef
/* BA0D00 802405D0 E640000C */  swc1      $f0, 0xc($s2)
/* BA0D04 802405D4 8E220000 */  lw        $v0, ($s1)
/* BA0D08 802405D8 3463FFFF */  ori       $v1, $v1, 0xffff
/* BA0D0C 802405DC 00431024 */  and       $v0, $v0, $v1
/* BA0D10 802405E0 AE220000 */  sw        $v0, ($s1)
/* BA0D14 802405E4 24020001 */  addiu     $v0, $zero, 1
/* BA0D18 802405E8 A640008E */  sh        $zero, 0x8e($s2)
/* BA0D1C 802405EC 0809019A */  j         .L80240668
/* BA0D20 802405F0 AE820070 */   sw       $v0, 0x70($s4)
.L802405F4:
/* BA0D24 802405F4 86240008 */  lh        $a0, 8($s1)
/* BA0D28 802405F8 0C00FB3A */  jal       get_enemy
/* BA0D2C 802405FC 2484FFFF */   addiu    $a0, $a0, -1
/* BA0D30 80240600 0040802D */  daddu     $s0, $v0, $zero
/* BA0D34 80240604 0C00EABB */  jal       get_npc_unsafe
/* BA0D38 80240608 86040008 */   lh       $a0, 8($s0)
/* BA0D3C 8024060C 9642008E */  lhu       $v0, 0x8e($s2)
/* BA0D40 80240610 24420001 */  addiu     $v0, $v0, 1
/* BA0D44 80240614 A642008E */  sh        $v0, 0x8e($s2)
/* BA0D48 80240618 00021400 */  sll       $v0, $v0, 0x10
/* BA0D4C 8024061C 8E23007C */  lw        $v1, 0x7c($s1)
/* BA0D50 80240620 00021403 */  sra       $v0, $v0, 0x10
/* BA0D54 80240624 0043102A */  slt       $v0, $v0, $v1
/* BA0D58 80240628 50400001 */  beql      $v0, $zero, .L80240630
/* BA0D5C 8024062C A2200007 */   sb       $zero, 7($s1)
.L80240630:
/* BA0D60 80240630 8E03006C */  lw        $v1, 0x6c($s0)
/* BA0D64 80240634 24020004 */  addiu     $v0, $zero, 4
/* BA0D68 80240638 1462000B */  bne       $v1, $v0, .L80240668
/* BA0D6C 8024063C 3C021F10 */   lui      $v0, 0x1f10
/* BA0D70 80240640 8E230000 */  lw        $v1, ($s1)
/* BA0D74 80240644 3C01C47A */  lui       $at, 0xc47a
/* BA0D78 80240648 44810000 */  mtc1      $at, $f0
/* BA0D7C 8024064C 00621825 */  or        $v1, $v1, $v0
/* BA0D80 80240650 AE230000 */  sw        $v1, ($s1)
/* BA0D84 80240654 AE400038 */  sw        $zero, 0x38($s2)
/* BA0D88 80240658 E640003C */  swc1      $f0, 0x3c($s2)
/* BA0D8C 8024065C AE400040 */  sw        $zero, 0x40($s2)
/* BA0D90 80240660 A2330007 */  sb        $s3, 7($s1)
/* BA0D94 80240664 AE800070 */  sw        $zero, 0x70($s4)
.L80240668:
/* BA0D98 80240668 8FBF002C */  lw        $ra, 0x2c($sp)
/* BA0D9C 8024066C 8FB40028 */  lw        $s4, 0x28($sp)
/* BA0DA0 80240670 8FB30024 */  lw        $s3, 0x24($sp)
/* BA0DA4 80240674 8FB20020 */  lw        $s2, 0x20($sp)
/* BA0DA8 80240678 8FB1001C */  lw        $s1, 0x1c($sp)
/* BA0DAC 8024067C 8FB00018 */  lw        $s0, 0x18($sp)
/* BA0DB0 80240680 0000102D */  daddu     $v0, $zero, $zero
/* BA0DB4 80240684 03E00008 */  jr        $ra
/* BA0DB8 80240688 27BD0030 */   addiu    $sp, $sp, 0x30
