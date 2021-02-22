.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400B4_9C5494
/* 9C5494 802400B4 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 9C5498 802400B8 AFB40040 */  sw        $s4, 0x40($sp)
/* 9C549C 802400BC 0080A02D */  daddu     $s4, $a0, $zero
/* 9C54A0 802400C0 AFBF0044 */  sw        $ra, 0x44($sp)
/* 9C54A4 802400C4 AFB3003C */  sw        $s3, 0x3c($sp)
/* 9C54A8 802400C8 AFB20038 */  sw        $s2, 0x38($sp)
/* 9C54AC 802400CC AFB10034 */  sw        $s1, 0x34($sp)
/* 9C54B0 802400D0 AFB00030 */  sw        $s0, 0x30($sp)
/* 9C54B4 802400D4 8E920148 */  lw        $s2, 0x148($s4)
/* 9C54B8 802400D8 00A0802D */  daddu     $s0, $a1, $zero
/* 9C54BC 802400DC 86440008 */  lh        $a0, 8($s2)
/* 9C54C0 802400E0 0C00EABB */  jal       get_npc_unsafe
/* 9C54C4 802400E4 00C0982D */   daddu    $s3, $a2, $zero
/* 9C54C8 802400E8 8E030008 */  lw        $v1, 8($s0)
/* 9C54CC 802400EC 04600031 */  bltz      $v1, .L802401B4
/* 9C54D0 802400F0 0040882D */   daddu    $s1, $v0, $zero
/* 9C54D4 802400F4 0260202D */  daddu     $a0, $s3, $zero
/* 9C54D8 802400F8 AFA00010 */  sw        $zero, 0x10($sp)
/* 9C54DC 802400FC 8E060018 */  lw        $a2, 0x18($s0)
/* 9C54E0 80240100 8E07001C */  lw        $a3, 0x1c($s0)
/* 9C54E4 80240104 0C01242D */  jal       func_800490B4
/* 9C54E8 80240108 0240282D */   daddu    $a1, $s2, $zero
/* 9C54EC 8024010C 10400029 */  beqz      $v0, .L802401B4
/* 9C54F0 80240110 0000202D */   daddu    $a0, $zero, $zero
/* 9C54F4 80240114 0220282D */  daddu     $a1, $s1, $zero
/* 9C54F8 80240118 0000302D */  daddu     $a2, $zero, $zero
/* 9C54FC 8024011C 862300A8 */  lh        $v1, 0xa8($s1)
/* 9C5500 80240120 3C013F80 */  lui       $at, 0x3f80
/* 9C5504 80240124 44810000 */  mtc1      $at, $f0
/* 9C5508 80240128 3C014000 */  lui       $at, 0x4000
/* 9C550C 8024012C 44811000 */  mtc1      $at, $f2
/* 9C5510 80240130 3C01C1A0 */  lui       $at, 0xc1a0
/* 9C5514 80240134 44812000 */  mtc1      $at, $f4
/* 9C5518 80240138 2402000F */  addiu     $v0, $zero, 0xf
/* 9C551C 8024013C AFA2001C */  sw        $v0, 0x1c($sp)
/* 9C5520 80240140 44833000 */  mtc1      $v1, $f6
/* 9C5524 80240144 00000000 */  nop
/* 9C5528 80240148 468031A0 */  cvt.s.w   $f6, $f6
/* 9C552C 8024014C 44073000 */  mfc1      $a3, $f6
/* 9C5530 80240150 27A20028 */  addiu     $v0, $sp, 0x28
/* 9C5534 80240154 AFA20020 */  sw        $v0, 0x20($sp)
/* 9C5538 80240158 E7A00010 */  swc1      $f0, 0x10($sp)
/* 9C553C 8024015C E7A20014 */  swc1      $f2, 0x14($sp)
/* 9C5540 80240160 0C01BFA4 */  jal       fx_emote
/* 9C5544 80240164 E7A40018 */   swc1     $f4, 0x18($sp)
/* 9C5548 80240168 0220202D */  daddu     $a0, $s1, $zero
/* 9C554C 8024016C 240502F4 */  addiu     $a1, $zero, 0x2f4
/* 9C5550 80240170 0C012530 */  jal       func_800494C0
/* 9C5554 80240174 3C060020 */   lui      $a2, 0x20
/* 9C5558 80240178 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 9C555C 8024017C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 9C5560 80240180 C62C0038 */  lwc1      $f12, 0x38($s1)
/* 9C5564 80240184 C62E0040 */  lwc1      $f14, 0x40($s1)
/* 9C5568 80240188 8C460028 */  lw        $a2, 0x28($v0)
/* 9C556C 8024018C 0C00A720 */  jal       atan2
/* 9C5570 80240190 8C470030 */   lw       $a3, 0x30($v0)
/* 9C5574 80240194 E620000C */  swc1      $f0, 0xc($s1)
/* 9C5578 80240198 8E420018 */  lw        $v0, 0x18($s2)
/* 9C557C 8024019C 9442002A */  lhu       $v0, 0x2a($v0)
/* 9C5580 802401A0 30420001 */  andi      $v0, $v0, 1
/* 9C5584 802401A4 14400002 */  bnez      $v0, .L802401B0
/* 9C5588 802401A8 2402000A */   addiu    $v0, $zero, 0xa
/* 9C558C 802401AC 2402000C */  addiu     $v0, $zero, 0xc
.L802401B0:
/* 9C5590 802401B0 AE820070 */  sw        $v0, 0x70($s4)
.L802401B4:
/* 9C5594 802401B4 8FBF0044 */  lw        $ra, 0x44($sp)
/* 9C5598 802401B8 8FB40040 */  lw        $s4, 0x40($sp)
/* 9C559C 802401BC 8FB3003C */  lw        $s3, 0x3c($sp)
/* 9C55A0 802401C0 8FB20038 */  lw        $s2, 0x38($sp)
/* 9C55A4 802401C4 8FB10034 */  lw        $s1, 0x34($sp)
/* 9C55A8 802401C8 8FB00030 */  lw        $s0, 0x30($sp)
/* 9C55AC 802401CC 03E00008 */  jr        $ra
/* 9C55B0 802401D0 27BD0048 */   addiu    $sp, $sp, 0x48
