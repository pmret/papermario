.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240424
/* 8DA524 80240424 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 8DA528 80240428 AFB40040 */  sw        $s4, 0x40($sp)
/* 8DA52C 8024042C 0080A02D */  daddu     $s4, $a0, $zero
/* 8DA530 80240430 AFBF0044 */  sw        $ra, 0x44($sp)
/* 8DA534 80240434 AFB3003C */  sw        $s3, 0x3c($sp)
/* 8DA538 80240438 AFB20038 */  sw        $s2, 0x38($sp)
/* 8DA53C 8024043C AFB10034 */  sw        $s1, 0x34($sp)
/* 8DA540 80240440 AFB00030 */  sw        $s0, 0x30($sp)
/* 8DA544 80240444 8E920148 */  lw        $s2, 0x148($s4)
/* 8DA548 80240448 00A0802D */  daddu     $s0, $a1, $zero
/* 8DA54C 8024044C 86440008 */  lh        $a0, 8($s2)
/* 8DA550 80240450 0C00EABB */  jal       get_npc_unsafe
/* 8DA554 80240454 00C0982D */   daddu    $s3, $a2, $zero
/* 8DA558 80240458 8E030008 */  lw        $v1, 8($s0)
/* 8DA55C 8024045C 04600031 */  bltz      $v1, .L80240524
/* 8DA560 80240460 0040882D */   daddu    $s1, $v0, $zero
/* 8DA564 80240464 0260202D */  daddu     $a0, $s3, $zero
/* 8DA568 80240468 AFA00010 */  sw        $zero, 0x10($sp)
/* 8DA56C 8024046C 8E060018 */  lw        $a2, 0x18($s0)
/* 8DA570 80240470 8E07001C */  lw        $a3, 0x1c($s0)
/* 8DA574 80240474 0C01242D */  jal       func_800490B4
/* 8DA578 80240478 0240282D */   daddu    $a1, $s2, $zero
/* 8DA57C 8024047C 10400029 */  beqz      $v0, .L80240524
/* 8DA580 80240480 0000202D */   daddu    $a0, $zero, $zero
/* 8DA584 80240484 0220282D */  daddu     $a1, $s1, $zero
/* 8DA588 80240488 0000302D */  daddu     $a2, $zero, $zero
/* 8DA58C 8024048C 862300A8 */  lh        $v1, 0xa8($s1)
/* 8DA590 80240490 3C013F80 */  lui       $at, 0x3f80
/* 8DA594 80240494 44810000 */  mtc1      $at, $f0
/* 8DA598 80240498 3C014000 */  lui       $at, 0x4000
/* 8DA59C 8024049C 44811000 */  mtc1      $at, $f2
/* 8DA5A0 802404A0 3C01C1A0 */  lui       $at, 0xc1a0
/* 8DA5A4 802404A4 44812000 */  mtc1      $at, $f4
/* 8DA5A8 802404A8 2402000F */  addiu     $v0, $zero, 0xf
/* 8DA5AC 802404AC AFA2001C */  sw        $v0, 0x1c($sp)
/* 8DA5B0 802404B0 44833000 */  mtc1      $v1, $f6
/* 8DA5B4 802404B4 00000000 */  nop       
/* 8DA5B8 802404B8 468031A0 */  cvt.s.w   $f6, $f6
/* 8DA5BC 802404BC 44073000 */  mfc1      $a3, $f6
/* 8DA5C0 802404C0 27A20028 */  addiu     $v0, $sp, 0x28
/* 8DA5C4 802404C4 AFA20020 */  sw        $v0, 0x20($sp)
/* 8DA5C8 802404C8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8DA5CC 802404CC E7A20014 */  swc1      $f2, 0x14($sp)
/* 8DA5D0 802404D0 0C01BFA4 */  jal       fx_emote
/* 8DA5D4 802404D4 E7A40018 */   swc1     $f4, 0x18($sp)
/* 8DA5D8 802404D8 0220202D */  daddu     $a0, $s1, $zero
/* 8DA5DC 802404DC 240502F4 */  addiu     $a1, $zero, 0x2f4
/* 8DA5E0 802404E0 0C012530 */  jal       func_800494C0
/* 8DA5E4 802404E4 3C060020 */   lui      $a2, 0x20
/* 8DA5E8 802404E8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 8DA5EC 802404EC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 8DA5F0 802404F0 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 8DA5F4 802404F4 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 8DA5F8 802404F8 8C460028 */  lw        $a2, 0x28($v0)
/* 8DA5FC 802404FC 0C00A720 */  jal       atan2
/* 8DA600 80240500 8C470030 */   lw       $a3, 0x30($v0)
/* 8DA604 80240504 E620000C */  swc1      $f0, 0xc($s1)
/* 8DA608 80240508 8E420018 */  lw        $v0, 0x18($s2)
/* 8DA60C 8024050C 9442002A */  lhu       $v0, 0x2a($v0)
/* 8DA610 80240510 30420001 */  andi      $v0, $v0, 1
/* 8DA614 80240514 14400002 */  bnez      $v0, .L80240520
/* 8DA618 80240518 2402000A */   addiu    $v0, $zero, 0xa
/* 8DA61C 8024051C 2402000C */  addiu     $v0, $zero, 0xc
.L80240520:
/* 8DA620 80240520 AE820070 */  sw        $v0, 0x70($s4)
.L80240524:
/* 8DA624 80240524 8FBF0044 */  lw        $ra, 0x44($sp)
/* 8DA628 80240528 8FB40040 */  lw        $s4, 0x40($sp)
/* 8DA62C 8024052C 8FB3003C */  lw        $s3, 0x3c($sp)
/* 8DA630 80240530 8FB20038 */  lw        $s2, 0x38($sp)
/* 8DA634 80240534 8FB10034 */  lw        $s1, 0x34($sp)
/* 8DA638 80240538 8FB00030 */  lw        $s0, 0x30($sp)
/* 8DA63C 8024053C 03E00008 */  jr        $ra
/* 8DA640 80240540 27BD0048 */   addiu    $sp, $sp, 0x48
