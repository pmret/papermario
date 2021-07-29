.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel calc_partner_damage_enemy
/* 1ACC08 8027E328 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 1ACC0C 8027E32C AFB40040 */  sw        $s4, 0x40($sp)
/* 1ACC10 8027E330 3C14800E */  lui       $s4, %hi(gBattleStatus)
/* 1ACC14 8027E334 2694C070 */  addiu     $s4, $s4, %lo(gBattleStatus)
/* 1ACC18 8027E338 AFBF0054 */  sw        $ra, 0x54($sp)
/* 1ACC1C 8027E33C AFBE0050 */  sw        $fp, 0x50($sp)
/* 1ACC20 8027E340 AFB7004C */  sw        $s7, 0x4c($sp)
/* 1ACC24 8027E344 AFB60048 */  sw        $s6, 0x48($sp)
/* 1ACC28 8027E348 AFB50044 */  sw        $s5, 0x44($sp)
/* 1ACC2C 8027E34C AFB3003C */  sw        $s3, 0x3c($sp)
/* 1ACC30 8027E350 AFB20038 */  sw        $s2, 0x38($sp)
/* 1ACC34 8027E354 AFB10034 */  sw        $s1, 0x34($sp)
/* 1ACC38 8027E358 AFB00030 */  sw        $s0, 0x30($sp)
/* 1ACC3C 8027E35C AFA00020 */  sw        $zero, 0x20($sp)
/* 1ACC40 8027E360 AFA00024 */  sw        $zero, 0x24($sp)
/* 1ACC44 8027E364 AFA00028 */  sw        $zero, 0x28($sp)
/* 1ACC48 8027E368 AFA0002C */  sw        $zero, 0x2c($sp)
/* 1ACC4C 8027E36C 8E8800DC */  lw        $t0, 0xdc($s4)
/* 1ACC50 8027E370 0000F02D */  daddu     $fp, $zero, $zero
/* 1ACC54 8027E374 A2800199 */  sb        $zero, 0x199($s4)
/* 1ACC58 8027E378 A6800180 */  sh        $zero, 0x180($s4)
/* 1ACC5C 8027E37C AFA80018 */  sw        $t0, 0x18($sp)
/* 1ACC60 8027E380 968301A0 */  lhu       $v1, 0x1a0($s4)
/* 1ACC64 8027E384 868401A0 */  lh        $a0, 0x1a0($s4)
/* 1ACC68 8027E388 928201A2 */  lbu       $v0, 0x1a2($s4)
/* 1ACC6C 8027E38C 95050192 */  lhu       $a1, 0x192($t0)
/* 1ACC70 8027E390 829001A2 */  lb        $s0, 0x1a2($s4)
/* 1ACC74 8027E394 03C0A82D */  daddu     $s5, $fp, $zero
/* 1ACC78 8027E398 A68301A4 */  sh        $v1, 0x1a4($s4)
/* 1ACC7C 8027E39C A28201A6 */  sb        $v0, 0x1a6($s4)
/* 1ACC80 8027E3A0 0C09A75B */  jal       get_actor
/* 1ACC84 8027E3A4 A68501A8 */   sh       $a1, 0x1a8($s4)
/* 1ACC88 8027E3A8 8FA80018 */  lw        $t0, 0x18($sp)
/* 1ACC8C 8027E3AC 0040982D */  daddu     $s3, $v0, $zero
/* 1ACC90 8027E3B0 16600003 */  bnez      $s3, .L8027E3C0
/* 1ACC94 8027E3B4 2512000C */   addiu    $s2, $t0, 0xc
.L8027E3B8:
/* 1ACC98 8027E3B8 0809FE67 */  j         .L8027F99C
/* 1ACC9C 8027E3BC 0000102D */   daddu    $v0, $zero, $zero
.L8027E3C0:
/* 1ACCA0 8027E3C0 0260202D */  daddu     $a0, $s3, $zero
/* 1ACCA4 8027E3C4 0C099117 */  jal       get_actor_part
/* 1ACCA8 8027E3C8 0200282D */   daddu    $a1, $s0, $zero
/* 1ACCAC 8027E3CC 0040B02D */  daddu     $s6, $v0, $zero
/* 1ACCB0 8027E3D0 56C00003 */  bnel      $s6, $zero, .L8027E3E0
/* 1ACCB4 8027E3D4 A66001F8 */   sh       $zero, 0x1f8($s3)
.L8027E3D8:
/* 1ACCB8 8027E3D8 0809F8F6 */  j         .L8027E3D8
/* 1ACCBC 8027E3DC 00000000 */   nop
.L8027E3E0:
/* 1ACCC0 8027E3E0 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1ACCC4 8027E3E4 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 1ACCC8 8027E3E8 30420800 */  andi      $v0, $v0, 0x800
/* 1ACCCC 8027E3EC 1040000C */  beqz      $v0, .L8027E420
/* 1ACCD0 8027E3F0 24080002 */   addiu    $t0, $zero, 2
/* 1ACCD4 8027E3F4 24110017 */  addiu     $s1, $zero, 0x17
/* 1ACCD8 8027E3F8 AFA8001C */  sw        $t0, 0x1c($sp)
/* 1ACCDC 8027E3FC C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ACCE0 8027E400 2404010C */  addiu     $a0, $zero, 0x10c
/* 1ACCE4 8027E404 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1ACCE8 8027E408 8E46000C */  lw        $a2, 0xc($s2)
/* 1ACCEC 8027E40C 8E470010 */  lw        $a3, 0x10($s2)
/* 1ACCF0 8027E410 0C052757 */  jal       sfx_play_sound_at_position
/* 1ACCF4 8027E414 0000282D */   daddu    $a1, $zero, $zero
/* 1ACCF8 8027E418 0809FB1B */  j         .L8027EC6C
/* 1ACCFC 8027E41C 00000000 */   nop
.L8027E420:
/* 1ACD00 8027E420 8EC4007C */  lw        $a0, 0x7c($s6)
/* 1ACD04 8027E424 30820020 */  andi      $v0, $a0, 0x20
/* 1ACD08 8027E428 1440055C */  bnez      $v0, .L8027F99C
/* 1ACD0C 8027E42C 24020006 */   addiu    $v0, $zero, 6
/* 1ACD10 8027E430 82630218 */  lb        $v1, 0x218($s3)
/* 1ACD14 8027E434 2402000E */  addiu     $v0, $zero, 0xe
/* 1ACD18 8027E438 10620007 */  beq       $v1, $v0, .L8027E458
/* 1ACD1C 8027E43C 30820800 */   andi     $v0, $a0, 0x800
/* 1ACD20 8027E440 10400007 */  beqz      $v0, .L8027E460
/* 1ACD24 8027E444 00000000 */   nop
/* 1ACD28 8027E448 8E820188 */  lw        $v0, 0x188($s4)
/* 1ACD2C 8027E44C 30420800 */  andi      $v0, $v0, 0x800
/* 1ACD30 8027E450 14400003 */  bnez      $v0, .L8027E460
/* 1ACD34 8027E454 00000000 */   nop
.L8027E458:
/* 1ACD38 8027E458 0809FE67 */  j         .L8027F99C
/* 1ACD3C 8027E45C 24020006 */   addiu    $v0, $zero, 6
.L8027E460:
/* 1ACD40 8027E460 82630214 */  lb        $v1, 0x214($s3)
/* 1ACD44 8027E464 2402000C */  addiu     $v0, $zero, 0xc
/* 1ACD48 8027E468 14620019 */  bne       $v1, $v0, .L8027E4D0
/* 1ACD4C 8027E46C 2404010C */   addiu    $a0, $zero, 0x10c
/* 1ACD50 8027E470 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ACD54 8027E474 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1ACD58 8027E478 8E46000C */  lw        $a2, 0xc($s2)
/* 1ACD5C 8027E47C 8E470010 */  lw        $a3, 0x10($s2)
/* 1ACD60 8027E480 0C052757 */  jal       sfx_play_sound_at_position
/* 1ACD64 8027E484 0000282D */   daddu    $a1, $zero, $zero
/* 1ACD68 8027E488 24020001 */  addiu     $v0, $zero, 1
/* 1ACD6C 8027E48C AFA20010 */  sw        $v0, 0x10($sp)
/* 1ACD70 8027E490 AFA20014 */  sw        $v0, 0x14($sp)
/* 1ACD74 8027E494 C64C000C */  lwc1      $f12, 0xc($s2)
/* 1ACD78 8027E498 C64E0010 */  lwc1      $f14, 0x10($s2)
/* 1ACD7C 8027E49C 8E460014 */  lw        $a2, 0x14($s2)
/* 1ACD80 8027E4A0 0C093BF8 */  jal       func_8024EFE0
/* 1ACD84 8027E4A4 0000382D */   daddu    $a3, $zero, $zero
/* 1ACD88 8027E4A8 AFA00010 */  sw        $zero, 0x10($sp)
/* 1ACD8C 8027E4AC C64C000C */  lwc1      $f12, 0xc($s2)
/* 1ACD90 8027E4B0 C64E0010 */  lwc1      $f14, 0x10($s2)
/* 1ACD94 8027E4B4 8E460014 */  lw        $a2, 0x14($s2)
/* 1ACD98 8027E4B8 0C09996B */  jal       show_damage_popup
/* 1ACD9C 8027E4BC 0000382D */   daddu    $a3, $zero, $zero
/* 1ACDA0 8027E4C0 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1ACDA4 8027E4C4 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 1ACDA8 8027E4C8 0809FB19 */  j         .L8027EC64
/* 1ACDAC 8027E4CC 30420240 */   andi     $v0, $v0, 0x240
.L8027E4D0:
/* 1ACDB0 8027E4D0 8EC20080 */  lw        $v0, 0x80($s6)
/* 1ACDB4 8027E4D4 8E830188 */  lw        $v1, 0x188($s4)
/* 1ACDB8 8027E4D8 00431024 */  and       $v0, $v0, $v1
/* 1ACDBC 8027E4DC 10400003 */  beqz      $v0, .L8027E4EC
/* 1ACDC0 8027E4E0 30620080 */   andi     $v0, $v1, 0x80
/* 1ACDC4 8027E4E4 24080001 */  addiu     $t0, $zero, 1
/* 1ACDC8 8027E4E8 AFA80020 */  sw        $t0, 0x20($sp)
.L8027E4EC:
/* 1ACDCC 8027E4EC 10400005 */  beqz      $v0, .L8027E504
/* 1ACDD0 8027E4F0 00000000 */   nop
/* 1ACDD4 8027E4F4 8EC2007C */  lw        $v0, 0x7c($s6)
/* 1ACDD8 8027E4F8 30420010 */  andi      $v0, $v0, 0x10
/* 1ACDDC 8027E4FC 14400084 */  bnez      $v0, .L8027E710
/* 1ACDE0 8027E500 00000000 */   nop
.L8027E504:
/* 1ACDE4 8027E504 8E820188 */  lw        $v0, 0x188($s4)
/* 1ACDE8 8027E508 3C031000 */  lui       $v1, 0x1000
/* 1ACDEC 8027E50C 00431024 */  and       $v0, $v0, $v1
/* 1ACDF0 8027E510 1440001E */  bnez      $v0, .L8027E58C
/* 1ACDF4 8027E514 00000000 */   nop
/* 1ACDF8 8027E518 8EC2007C */  lw        $v0, 0x7c($s6)
/* 1ACDFC 8027E51C 30428000 */  andi      $v0, $v0, 0x8000
/* 1ACE00 8027E520 1040001A */  beqz      $v0, .L8027E58C
/* 1ACE04 8027E524 0260202D */   daddu    $a0, $s3, $zero
/* 1ACE08 8027E528 0C09DC58 */  jal       dispatch_event_actor
/* 1ACE0C 8027E52C 24050022 */   addiu    $a1, $zero, 0x22
/* 1ACE10 8027E530 8E82018C */  lw        $v0, 0x18c($s4)
/* 1ACE14 8027E534 30420002 */  andi      $v0, $v0, 2
/* 1ACE18 8027E538 1440000A */  bnez      $v0, .L8027E564
/* 1ACE1C 8027E53C 240400EA */   addiu    $a0, $zero, 0xea
/* 1ACE20 8027E540 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ACE24 8027E544 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1ACE28 8027E548 8E46000C */  lw        $a2, 0xc($s2)
/* 1ACE2C 8027E54C 8E470010 */  lw        $a3, 0x10($s2)
/* 1ACE30 8027E550 0C052757 */  jal       sfx_play_sound_at_position
/* 1ACE34 8027E554 0000282D */   daddu    $a1, $zero, $zero
/* 1ACE38 8027E558 24040001 */  addiu     $a0, $zero, 1
/* 1ACE3C 8027E55C 0809FE62 */  j         .L8027F988
/* 1ACE40 8027E560 2405002C */   addiu    $a1, $zero, 0x2c
.L8027E564:
/* 1ACE44 8027E564 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ACE48 8027E568 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1ACE4C 8027E56C 8E46000C */  lw        $a2, 0xc($s2)
/* 1ACE50 8027E570 8E470010 */  lw        $a3, 0x10($s2)
/* 1ACE54 8027E574 0C052757 */  jal       sfx_play_sound_at_position
/* 1ACE58 8027E578 0000282D */   daddu    $a1, $zero, $zero
/* 1ACE5C 8027E57C 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1ACE60 8027E580 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 1ACE64 8027E584 0809FB19 */  j         .L8027EC64
/* 1ACE68 8027E588 30420240 */   andi     $v0, $v0, 0x240
.L8027E58C:
/* 1ACE6C 8027E58C 8E820188 */  lw        $v0, 0x188($s4)
/* 1ACE70 8027E590 34630040 */  ori       $v1, $v1, 0x40
/* 1ACE74 8027E594 00431024 */  and       $v0, $v0, $v1
/* 1ACE78 8027E598 14400015 */  bnez      $v0, .L8027E5F0
/* 1ACE7C 8027E59C 3C031000 */   lui      $v1, 0x1000
/* 1ACE80 8027E5A0 8EC2007C */  lw        $v0, 0x7c($s6)
/* 1ACE84 8027E5A4 30420002 */  andi      $v0, $v0, 2
/* 1ACE88 8027E5A8 10400011 */  beqz      $v0, .L8027E5F0
/* 1ACE8C 8027E5AC 00000000 */   nop
/* 1ACE90 8027E5B0 8E82018C */  lw        $v0, 0x18c($s4)
/* 1ACE94 8027E5B4 30420010 */  andi      $v0, $v0, 0x10
/* 1ACE98 8027E5B8 1440000D */  bnez      $v0, .L8027E5F0
/* 1ACE9C 8027E5BC 240400EA */   addiu    $a0, $zero, 0xea
/* 1ACEA0 8027E5C0 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ACEA4 8027E5C4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1ACEA8 8027E5C8 8E46000C */  lw        $a2, 0xc($s2)
/* 1ACEAC 8027E5CC 8E470010 */  lw        $a3, 0x10($s2)
/* 1ACEB0 8027E5D0 0C052757 */  jal       sfx_play_sound_at_position
/* 1ACEB4 8027E5D4 0000282D */   daddu    $a1, $zero, $zero
/* 1ACEB8 8027E5D8 24040001 */  addiu     $a0, $zero, 1
/* 1ACEBC 8027E5DC 0C09FEE7 */  jal       dispatch_damage_event_partner_1
/* 1ACEC0 8027E5E0 2405002C */   addiu    $a1, $zero, 0x2c
/* 1ACEC4 8027E5E4 0260202D */  daddu     $a0, $s3, $zero
/* 1ACEC8 8027E5E8 0809F9D0 */  j         .L8027E740
/* 1ACECC 8027E5EC 2405001C */   addiu    $a1, $zero, 0x1c
.L8027E5F0:
/* 1ACED0 8027E5F0 8E820188 */  lw        $v0, 0x188($s4)
/* 1ACED4 8027E5F4 34630080 */  ori       $v1, $v1, 0x80
/* 1ACED8 8027E5F8 00431024 */  and       $v0, $v0, $v1
/* 1ACEDC 8027E5FC 14400009 */  bnez      $v0, .L8027E624
/* 1ACEE0 8027E600 3C030001 */   lui      $v1, 1
/* 1ACEE4 8027E604 8EC2007C */  lw        $v0, 0x7c($s6)
/* 1ACEE8 8027E608 00431024 */  and       $v0, $v0, $v1
/* 1ACEEC 8027E60C 10400005 */  beqz      $v0, .L8027E624
/* 1ACEF0 8027E610 00000000 */   nop
/* 1ACEF4 8027E614 8E82018C */  lw        $v0, 0x18c($s4)
/* 1ACEF8 8027E618 30420004 */  andi      $v0, $v0, 4
/* 1ACEFC 8027E61C 1040003C */  beqz      $v0, .L8027E710
/* 1ACF00 8027E620 00000000 */   nop
.L8027E624:
/* 1ACF04 8027E624 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 1ACF08 8027E628 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 1ACF0C 8027E62C 8E020000 */  lw        $v0, ($s0)
/* 1ACF10 8027E630 30420020 */  andi      $v0, $v0, 0x20
/* 1ACF14 8027E634 10400014 */  beqz      $v0, .L8027E688
/* 1ACF18 8027E638 00000000 */   nop
/* 1ACF1C 8027E63C 8E820188 */  lw        $v0, 0x188($s4)
/* 1ACF20 8027E640 30420002 */  andi      $v0, $v0, 2
/* 1ACF24 8027E644 10400010 */  beqz      $v0, .L8027E688
/* 1ACF28 8027E648 00000000 */   nop
/* 1ACF2C 8027E64C 8EC2007C */  lw        $v0, 0x7c($s6)
/* 1ACF30 8027E650 30420600 */  andi      $v0, $v0, 0x600
/* 1ACF34 8027E654 1040000C */  beqz      $v0, .L8027E688
/* 1ACF38 8027E658 240400EA */   addiu    $a0, $zero, 0xea
/* 1ACF3C 8027E65C C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ACF40 8027E660 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1ACF44 8027E664 8E46000C */  lw        $a2, 0xc($s2)
/* 1ACF48 8027E668 8E470010 */  lw        $a3, 0x10($s2)
/* 1ACF4C 8027E66C 0C052757 */  jal       sfx_play_sound_at_position
/* 1ACF50 8027E670 0000282D */   daddu    $a1, $zero, $zero
/* 1ACF54 8027E674 0260202D */  daddu     $a0, $s3, $zero
/* 1ACF58 8027E678 0C09DC58 */  jal       dispatch_event_actor
/* 1ACF5C 8027E67C 24050022 */   addiu    $a1, $zero, 0x22
/* 1ACF60 8027E680 0809FB17 */  j         .L8027EC5C
/* 1ACF64 8027E684 00000000 */   nop
.L8027E688:
/* 1ACF68 8027E688 8E820188 */  lw        $v0, 0x188($s4)
/* 1ACF6C 8027E68C 3C031000 */  lui       $v1, 0x1000
/* 1ACF70 8027E690 00431024 */  and       $v0, $v0, $v1
/* 1ACF74 8027E694 1440002E */  bnez      $v0, .L8027E750
/* 1ACF78 8027E698 3C030020 */   lui      $v1, 0x20
/* 1ACF7C 8027E69C 8EC2007C */  lw        $v0, 0x7c($s6)
/* 1ACF80 8027E6A0 00431024 */  and       $v0, $v0, $v1
/* 1ACF84 8027E6A4 10400009 */  beqz      $v0, .L8027E6CC
/* 1ACF88 8027E6A8 00000000 */   nop
/* 1ACF8C 8027E6AC 8E620000 */  lw        $v0, ($s3)
/* 1ACF90 8027E6B0 30420800 */  andi      $v0, $v0, 0x800
/* 1ACF94 8027E6B4 14400005 */  bnez      $v0, .L8027E6CC
/* 1ACF98 8027E6B8 00000000 */   nop
/* 1ACF9C 8027E6BC 8E82018C */  lw        $v0, 0x18c($s4)
/* 1ACFA0 8027E6C0 30420080 */  andi      $v0, $v0, 0x80
/* 1ACFA4 8027E6C4 10400012 */  beqz      $v0, .L8027E710
/* 1ACFA8 8027E6C8 00000000 */   nop
.L8027E6CC:
/* 1ACFAC 8027E6CC 8E820188 */  lw        $v0, 0x188($s4)
/* 1ACFB0 8027E6D0 3C031000 */  lui       $v1, 0x1000
/* 1ACFB4 8027E6D4 00431024 */  and       $v0, $v0, $v1
/* 1ACFB8 8027E6D8 1440001D */  bnez      $v0, .L8027E750
/* 1ACFBC 8027E6DC 00000000 */   nop
/* 1ACFC0 8027E6E0 8EC2007C */  lw        $v0, 0x7c($s6)
/* 1ACFC4 8027E6E4 30420010 */  andi      $v0, $v0, 0x10
/* 1ACFC8 8027E6E8 10400019 */  beqz      $v0, .L8027E750
/* 1ACFCC 8027E6EC 00000000 */   nop
/* 1ACFD0 8027E6F0 8E620000 */  lw        $v0, ($s3)
/* 1ACFD4 8027E6F4 30420800 */  andi      $v0, $v0, 0x800
/* 1ACFD8 8027E6F8 14400015 */  bnez      $v0, .L8027E750
/* 1ACFDC 8027E6FC 00000000 */   nop
/* 1ACFE0 8027E700 8E82018C */  lw        $v0, 0x18c($s4)
/* 1ACFE4 8027E704 30420001 */  andi      $v0, $v0, 1
/* 1ACFE8 8027E708 14400011 */  bnez      $v0, .L8027E750
/* 1ACFEC 8027E70C 00000000 */   nop
.L8027E710:
/* 1ACFF0 8027E710 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ACFF4 8027E714 24040108 */  addiu     $a0, $zero, 0x108
/* 1ACFF8 8027E718 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1ACFFC 8027E71C 8E46000C */  lw        $a2, 0xc($s2)
/* 1AD000 8027E720 8E470010 */  lw        $a3, 0x10($s2)
/* 1AD004 8027E724 0C052757 */  jal       sfx_play_sound_at_position
/* 1AD008 8027E728 0000282D */   daddu    $a1, $zero, $zero
/* 1AD00C 8027E72C 24040001 */  addiu     $a0, $zero, 1
/* 1AD010 8027E730 0C09FEE7 */  jal       dispatch_damage_event_partner_1
/* 1AD014 8027E734 2405002A */   addiu    $a1, $zero, 0x2a
/* 1AD018 8027E738 0260202D */  daddu     $a0, $s3, $zero
/* 1AD01C 8027E73C 2405001B */  addiu     $a1, $zero, 0x1b
.L8027E740:
/* 1AD020 8027E740 0C09DC58 */  jal       dispatch_event_actor
/* 1AD024 8027E744 00000000 */   nop
/* 1AD028 8027E748 0809FE67 */  j         .L8027F99C
/* 1AD02C 8027E74C 2402FFFF */   addiu    $v0, $zero, -1
.L8027E750:
/* 1AD030 8027E750 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 1AD034 8027E754 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 1AD038 8027E758 8E020000 */  lw        $v0, ($s0)
/* 1AD03C 8027E75C 30420020 */  andi      $v0, $v0, 0x20
/* 1AD040 8027E760 10400014 */  beqz      $v0, .L8027E7B4
/* 1AD044 8027E764 00000000 */   nop
/* 1AD048 8027E768 8E820188 */  lw        $v0, 0x188($s4)
/* 1AD04C 8027E76C 30420002 */  andi      $v0, $v0, 2
/* 1AD050 8027E770 10400010 */  beqz      $v0, .L8027E7B4
/* 1AD054 8027E774 00000000 */   nop
/* 1AD058 8027E778 8EC2007C */  lw        $v0, 0x7c($s6)
/* 1AD05C 8027E77C 30420600 */  andi      $v0, $v0, 0x600
/* 1AD060 8027E780 1040000C */  beqz      $v0, .L8027E7B4
/* 1AD064 8027E784 240400EA */   addiu    $a0, $zero, 0xea
/* 1AD068 8027E788 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1AD06C 8027E78C E7A00010 */  swc1      $f0, 0x10($sp)
/* 1AD070 8027E790 8E46000C */  lw        $a2, 0xc($s2)
/* 1AD074 8027E794 8E470010 */  lw        $a3, 0x10($s2)
/* 1AD078 8027E798 0C052757 */  jal       sfx_play_sound_at_position
/* 1AD07C 8027E79C 0000282D */   daddu    $a1, $zero, $zero
/* 1AD080 8027E7A0 0260202D */  daddu     $a0, $s3, $zero
/* 1AD084 8027E7A4 0C09DC58 */  jal       dispatch_event_actor
/* 1AD088 8027E7A8 24050022 */   addiu    $a1, $zero, 0x22
/* 1AD08C 8027E7AC 0809FB17 */  j         .L8027EC5C
/* 1AD090 8027E7B0 00000000 */   nop
.L8027E7B4:
/* 1AD094 8027E7B4 8E830188 */  lw        $v1, 0x188($s4)
/* 1AD098 8027E7B8 30628000 */  andi      $v0, $v1, 0x8000
/* 1AD09C 8027E7BC 10400015 */  beqz      $v0, .L8027E814
/* 1AD0A0 8027E7C0 2404000B */   addiu    $a0, $zero, 0xb
/* 1AD0A4 8027E7C4 8FA80018 */  lw        $t0, 0x18($sp)
/* 1AD0A8 8027E7C8 81020212 */  lb        $v0, 0x212($t0)
/* 1AD0AC 8027E7CC 10440473 */  beq       $v0, $a0, .L8027F99C
/* 1AD0B0 8027E7D0 0000102D */   daddu    $v0, $zero, $zero
/* 1AD0B4 8027E7D4 82620212 */  lb        $v0, 0x212($s3)
/* 1AD0B8 8027E7D8 10440005 */  beq       $v0, $a0, .L8027E7F0
/* 1AD0BC 8027E7DC 3C021000 */   lui      $v0, 0x1000
/* 1AD0C0 8027E7E0 8EC2007C */  lw        $v0, 0x7c($s6)
/* 1AD0C4 8027E7E4 30420080 */  andi      $v0, $v0, 0x80
/* 1AD0C8 8027E7E8 1040FEF3 */  beqz      $v0, .L8027E3B8
/* 1AD0CC 8027E7EC 3C021000 */   lui      $v0, 0x1000
.L8027E7F0:
/* 1AD0D0 8027E7F0 00621024 */  and       $v0, $v1, $v0
/* 1AD0D4 8027E7F4 14400469 */  bnez      $v0, .L8027F99C
/* 1AD0D8 8027E7F8 0000102D */   daddu    $v0, $zero, $zero
/* 1AD0DC 8027E7FC 8E82018C */  lw        $v0, 0x18c($s4)
/* 1AD0E0 8027E800 30420008 */  andi      $v0, $v0, 8
/* 1AD0E4 8027E804 10400454 */  beqz      $v0, .L8027F958
/* 1AD0E8 8027E808 0000102D */   daddu    $v0, $zero, $zero
/* 1AD0EC 8027E80C 0809FE67 */  j         .L8027F99C
/* 1AD0F0 8027E810 00000000 */   nop
.L8027E814:
/* 1AD0F4 8027E814 30620002 */  andi      $v0, $v1, 2
/* 1AD0F8 8027E818 10400010 */  beqz      $v0, .L8027E85C
/* 1AD0FC 8027E81C 0000202D */   daddu    $a0, $zero, $zero
/* 1AD100 8027E820 C6440014 */  lwc1      $f4, 0x14($s2)
/* 1AD104 8027E824 3C0140A0 */  lui       $at, 0x40a0
/* 1AD108 8027E828 44810000 */  mtc1      $at, $f0
/* 1AD10C 8027E82C 3C013F80 */  lui       $at, 0x3f80
/* 1AD110 8027E830 44811000 */  mtc1      $at, $f2
/* 1AD114 8027E834 24020018 */  addiu     $v0, $zero, 0x18
/* 1AD118 8027E838 AFA20014 */  sw        $v0, 0x14($sp)
/* 1AD11C 8027E83C 46002100 */  add.s     $f4, $f4, $f0
/* 1AD120 8027E840 E7A20010 */  swc1      $f2, 0x10($sp)
/* 1AD124 8027E844 8E45000C */  lw        $a1, 0xc($s2)
/* 1AD128 8027E848 8E460010 */  lw        $a2, 0x10($s2)
/* 1AD12C 8027E84C 44072000 */  mfc1      $a3, $f4
/* 1AD130 8027E850 24080001 */  addiu     $t0, $zero, 1
/* 1AD134 8027E854 0C01C184 */  jal       playFX_24
/* 1AD138 8027E858 AFA80024 */   sw       $t0, 0x24($sp)
.L8027E85C:
/* 1AD13C 8027E85C 8E820188 */  lw        $v0, 0x188($s4)
/* 1AD140 8027E860 30420020 */  andi      $v0, $v0, 0x20
/* 1AD144 8027E864 10400005 */  beqz      $v0, .L8027E87C
/* 1AD148 8027E868 00000000 */   nop
/* 1AD14C 8027E86C 0C09451D */  jal       func_80251474
/* 1AD150 8027E870 0260202D */   daddu    $a0, $s3, $zero
/* 1AD154 8027E874 24080001 */  addiu     $t0, $zero, 1
/* 1AD158 8027E878 AFA80028 */  sw        $t0, 0x28($sp)
.L8027E87C:
/* 1AD15C 8027E87C 8E820188 */  lw        $v0, 0x188($s4)
/* 1AD160 8027E880 30420004 */  andi      $v0, $v0, 4
/* 1AD164 8027E884 1040000E */  beqz      $v0, .L8027E8C0
/* 1AD168 8027E888 24020018 */   addiu    $v0, $zero, 0x18
/* 1AD16C 8027E88C C6440014 */  lwc1      $f4, 0x14($s2)
/* 1AD170 8027E890 3C0140A0 */  lui       $at, 0x40a0
/* 1AD174 8027E894 44810000 */  mtc1      $at, $f0
/* 1AD178 8027E898 3C013F80 */  lui       $at, 0x3f80
/* 1AD17C 8027E89C 44811000 */  mtc1      $at, $f2
/* 1AD180 8027E8A0 AFA20014 */  sw        $v0, 0x14($sp)
/* 1AD184 8027E8A4 46002100 */  add.s     $f4, $f4, $f0
/* 1AD188 8027E8A8 E7A20010 */  swc1      $f2, 0x10($sp)
/* 1AD18C 8027E8AC 8E45000C */  lw        $a1, 0xc($s2)
/* 1AD190 8027E8B0 8E460010 */  lw        $a2, 0x10($s2)
/* 1AD194 8027E8B4 44072000 */  mfc1      $a3, $f4
/* 1AD198 8027E8B8 0C01C70C */  jal       playFX_5F
/* 1AD19C 8027E8BC 0000202D */   daddu    $a0, $zero, $zero
.L8027E8C0:
/* 1AD1A0 8027E8C0 8E820188 */  lw        $v0, 0x188($s4)
/* 1AD1A4 8027E8C4 30420008 */  andi      $v0, $v0, 8
/* 1AD1A8 8027E8C8 1040000C */  beqz      $v0, .L8027E8FC
/* 1AD1AC 8027E8CC 0000202D */   daddu    $a0, $zero, $zero
/* 1AD1B0 8027E8D0 C6420014 */  lwc1      $f2, 0x14($s2)
/* 1AD1B4 8027E8D4 3C0140A0 */  lui       $at, 0x40a0
/* 1AD1B8 8027E8D8 44810000 */  mtc1      $at, $f0
/* 1AD1BC 8027E8DC 00000000 */  nop
/* 1AD1C0 8027E8E0 46001080 */  add.s     $f2, $f2, $f0
/* 1AD1C4 8027E8E4 8E45000C */  lw        $a1, 0xc($s2)
/* 1AD1C8 8027E8E8 8E460010 */  lw        $a2, 0x10($s2)
/* 1AD1CC 8027E8EC 44071000 */  mfc1      $a3, $f2
/* 1AD1D0 8027E8F0 24080001 */  addiu     $t0, $zero, 1
/* 1AD1D4 8027E8F4 0C01C2A4 */  jal       playFX_30
/* 1AD1D8 8027E8F8 AFA8002C */   sw       $t0, 0x2c($sp)
.L8027E8FC:
/* 1AD1DC 8027E8FC 8FA80018 */  lw        $t0, 0x18($sp)
/* 1AD1E0 8027E900 81020212 */  lb        $v0, 0x212($t0)
/* 1AD1E4 8027E904 2403000B */  addiu     $v1, $zero, 0xb
/* 1AD1E8 8027E908 10430016 */  beq       $v0, $v1, .L8027E964
/* 1AD1EC 8027E90C 00000000 */   nop
/* 1AD1F0 8027E910 82620212 */  lb        $v0, 0x212($s3)
/* 1AD1F4 8027E914 10430005 */  beq       $v0, $v1, .L8027E92C
/* 1AD1F8 8027E918 3C031000 */   lui      $v1, 0x1000
/* 1AD1FC 8027E91C 8EC2007C */  lw        $v0, 0x7c($s6)
/* 1AD200 8027E920 30420080 */  andi      $v0, $v0, 0x80
/* 1AD204 8027E924 1040000F */  beqz      $v0, .L8027E964
/* 1AD208 8027E928 00000000 */   nop
.L8027E92C:
/* 1AD20C 8027E92C 8E820188 */  lw        $v0, 0x188($s4)
/* 1AD210 8027E930 34630020 */  ori       $v1, $v1, 0x20
/* 1AD214 8027E934 00431024 */  and       $v0, $v0, $v1
/* 1AD218 8027E938 1440000A */  bnez      $v0, .L8027E964
/* 1AD21C 8027E93C 00000000 */   nop
/* 1AD220 8027E940 8E82018C */  lw        $v0, 0x18c($s4)
/* 1AD224 8027E944 30420008 */  andi      $v0, $v0, 8
/* 1AD228 8027E948 14400006 */  bnez      $v0, .L8027E964
/* 1AD22C 8027E94C 00000000 */   nop
/* 1AD230 8027E950 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1AD234 8027E954 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 1AD238 8027E958 8C620000 */  lw        $v0, ($v1)
/* 1AD23C 8027E95C 34420020 */  ori       $v0, $v0, 0x20
/* 1AD240 8027E960 AC620000 */  sw        $v0, ($v1)
.L8027E964:
/* 1AD244 8027E964 8EC2007C */  lw        $v0, 0x7c($s6)
/* 1AD248 8027E968 3C03000C */  lui       $v1, 0xc
/* 1AD24C 8027E96C 00431024 */  and       $v0, $v0, $v1
/* 1AD250 8027E970 10400005 */  beqz      $v0, .L8027E988
/* 1AD254 8027E974 3C03F7FF */   lui      $v1, 0xf7ff
/* 1AD258 8027E978 8E820188 */  lw        $v0, 0x188($s4)
/* 1AD25C 8027E97C 3463FFFF */  ori       $v1, $v1, 0xffff
/* 1AD260 8027E980 00431024 */  and       $v0, $v0, $v1
/* 1AD264 8027E984 AE820188 */  sw        $v0, 0x188($s4)
.L8027E988:
/* 1AD268 8027E988 8EC50078 */  lw        $a1, 0x78($s6)
/* 1AD26C 8027E98C 8E860188 */  lw        $a2, 0x188($s4)
/* 1AD270 8027E990 0C0998AF */  jal       get_defense
/* 1AD274 8027E994 0260202D */   daddu    $a0, $s3, $zero
/* 1AD278 8027E998 0040802D */  daddu     $s0, $v0, $zero
/* 1AD27C 8027E99C 8E850188 */  lw        $a1, 0x188($s4)
/* 1AD280 8027E9A0 3C020800 */  lui       $v0, 0x800
/* 1AD284 8027E9A4 00A21024 */  and       $v0, $a1, $v0
/* 1AD288 8027E9A8 14400003 */  bnez      $v0, .L8027E9B8
/* 1AD28C 8027E9AC 00000000 */   nop
/* 1AD290 8027E9B0 82620222 */  lb        $v0, 0x222($s3)
/* 1AD294 8027E9B4 02028021 */  addu      $s0, $s0, $v0
.L8027E9B8:
/* 1AD298 8027E9B8 8684017E */  lh        $a0, 0x17e($s4)
/* 1AD29C 8027E9BC 8FA80018 */  lw        $t0, 0x18($sp)
/* 1AD2A0 8027E9C0 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AD2A4 8027E9C4 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 1AD2A8 8027E9C8 81030221 */  lb        $v1, 0x221($t0)
/* 1AD2AC 8027E9CC 30420020 */  andi      $v0, $v0, 0x20
/* 1AD2B0 8027E9D0 1040000A */  beqz      $v0, .L8027E9FC
/* 1AD2B4 8027E9D4 00832021 */   addu     $a0, $a0, $v1
/* 1AD2B8 8027E9D8 30A20200 */  andi      $v0, $a1, 0x200
/* 1AD2BC 8027E9DC 10400007 */  beqz      $v0, .L8027E9FC
/* 1AD2C0 8027E9E0 00000000 */   nop
/* 1AD2C4 8027E9E4 8EC2007C */  lw        $v0, 0x7c($s6)
/* 1AD2C8 8027E9E8 30420200 */  andi      $v0, $v0, 0x200
/* 1AD2CC 8027E9EC 10400003 */  beqz      $v0, .L8027E9FC
/* 1AD2D0 8027E9F0 00000000 */   nop
/* 1AD2D4 8027E9F4 0000802D */  daddu     $s0, $zero, $zero
/* 1AD2D8 8027E9F8 826401B8 */  lb        $a0, 0x1b8($s3)
.L8027E9FC:
/* 1AD2DC 8027E9FC 8E820188 */  lw        $v0, 0x188($s4)
/* 1AD2E0 8027EA00 3C034000 */  lui       $v1, 0x4000
/* 1AD2E4 8027EA04 00431024 */  and       $v0, $v0, $v1
/* 1AD2E8 8027EA08 10400003 */  beqz      $v0, .L8027EA18
/* 1AD2EC 8027EA0C 00000000 */   nop
/* 1AD2F0 8027EA10 0000802D */  daddu     $s0, $zero, $zero
/* 1AD2F4 8027EA14 0200202D */  daddu     $a0, $s0, $zero
.L8027EA18:
/* 1AD2F8 8027EA18 8FA80018 */  lw        $t0, 0x18($sp)
/* 1AD2FC 8027EA1C 81030210 */  lb        $v1, 0x210($t0)
/* 1AD300 8027EA20 2402000A */  addiu     $v0, $zero, 0xa
/* 1AD304 8027EA24 14620008 */  bne       $v1, $v0, .L8027EA48
/* 1AD308 8027EA28 28820064 */   slti     $v0, $a0, 0x64
/* 1AD30C 8027EA2C 10800005 */  beqz      $a0, .L8027EA44
/* 1AD310 8027EA30 000417C2 */   srl      $v0, $a0, 0x1f
/* 1AD314 8027EA34 00821021 */  addu      $v0, $a0, $v0
/* 1AD318 8027EA38 00022043 */  sra       $a0, $v0, 1
/* 1AD31C 8027EA3C 50800001 */  beql      $a0, $zero, .L8027EA44
/* 1AD320 8027EA40 24040001 */   addiu    $a0, $zero, 1
.L8027EA44:
/* 1AD324 8027EA44 28820064 */  slti      $v0, $a0, 0x64
.L8027EA48:
/* 1AD328 8027EA48 50400001 */  beql      $v0, $zero, .L8027EA50
/* 1AD32C 8027EA4C 24040063 */   addiu    $a0, $zero, 0x63
.L8027EA50:
/* 1AD330 8027EA50 04820001 */  bltzl     $a0, .L8027EA58
/* 1AD334 8027EA54 0000802D */   daddu    $s0, $zero, $zero
.L8027EA58:
/* 1AD338 8027EA58 00902023 */  subu      $a0, $a0, $s0
/* 1AD33C 8027EA5C 04810002 */  bgez      $a0, .L8027EA68
/* 1AD340 8027EA60 A66001FA */   sh       $zero, 0x1fa($s3)
/* 1AD344 8027EA64 0000202D */  daddu     $a0, $zero, $zero
.L8027EA68:
/* 1AD348 8027EA68 8E820188 */  lw        $v0, 0x188($s4)
/* 1AD34C 8027EA6C 3C030010 */  lui       $v1, 0x10
/* 1AD350 8027EA70 00431024 */  and       $v0, $v0, $v1
/* 1AD354 8027EA74 10400007 */  beqz      $v0, .L8027EA94
/* 1AD358 8027EA78 00000000 */   nop
/* 1AD35C 8027EA7C 18800005 */  blez      $a0, .L8027EA94
/* 1AD360 8027EA80 00000000 */   nop
/* 1AD364 8027EA84 82820198 */  lb        $v0, 0x198($s4)
/* 1AD368 8027EA88 00822021 */  addu      $a0, $a0, $v0
/* 1AD36C 8027EA8C 58800001 */  blezl     $a0, .L8027EA94
/* 1AD370 8027EA90 24040001 */   addiu    $a0, $zero, 1
.L8027EA94:
/* 1AD374 8027EA94 1C800019 */  bgtz      $a0, .L8027EAFC
/* 1AD378 8027EA98 A6800180 */   sh       $zero, 0x180($s4)
/* 1AD37C 8027EA9C A66001FA */  sh        $zero, 0x1fa($s3)
/* 1AD380 8027EAA0 8E820188 */  lw        $v0, 0x188($s4)
/* 1AD384 8027EAA4 3C034000 */  lui       $v1, 0x4000
/* 1AD388 8027EAA8 00431024 */  and       $v0, $v0, $v1
/* 1AD38C 8027EAAC 1440000C */  bnez      $v0, .L8027EAE0
/* 1AD390 8027EAB0 24080002 */   addiu    $t0, $zero, 2
/* 1AD394 8027EAB4 24110017 */  addiu     $s1, $zero, 0x17
/* 1AD398 8027EAB8 AFA8001C */  sw        $t0, 0x1c($sp)
/* 1AD39C 8027EABC C6400014 */  lwc1      $f0, 0x14($s2)
/* 1AD3A0 8027EAC0 2404010C */  addiu     $a0, $zero, 0x10c
/* 1AD3A4 8027EAC4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1AD3A8 8027EAC8 8E46000C */  lw        $a2, 0xc($s2)
/* 1AD3AC 8027EACC 8E470010 */  lw        $a3, 0x10($s2)
/* 1AD3B0 8027EAD0 0C052757 */  jal       sfx_play_sound_at_position
/* 1AD3B4 8027EAD4 0000282D */   daddu    $a1, $zero, $zero
/* 1AD3B8 8027EAD8 0809FAE5 */  j         .L8027EB94
/* 1AD3BC 8027EADC A6800180 */   sh       $zero, 0x180($s4)
.L8027EAE0:
/* 1AD3C0 8027EAE0 AFA8001C */  sw        $t0, 0x1c($sp)
/* 1AD3C4 8027EAE4 826201B8 */  lb        $v0, 0x1b8($s3)
/* 1AD3C8 8027EAE8 1C400002 */  bgtz      $v0, .L8027EAF4
/* 1AD3CC 8027EAEC 24110017 */   addiu    $s1, $zero, 0x17
/* 1AD3D0 8027EAF0 24110020 */  addiu     $s1, $zero, 0x20
.L8027EAF4:
/* 1AD3D4 8027EAF4 0809FAE5 */  j         .L8027EB94
/* 1AD3D8 8027EAF8 A6800180 */   sh       $zero, 0x180($s4)
.L8027EAFC:
/* 1AD3DC 8027EAFC 966201FC */  lhu       $v0, 0x1fc($s3)
/* 1AD3E0 8027EB00 966301FA */  lhu       $v1, 0x1fa($s3)
/* 1AD3E4 8027EB04 00441021 */  addu      $v0, $v0, $a0
/* 1AD3E8 8027EB08 00641823 */  subu      $v1, $v1, $a0
/* 1AD3EC 8027EB0C A66201FC */  sh        $v0, 0x1fc($s3)
/* 1AD3F0 8027EB10 A66301FA */  sh        $v1, 0x1fa($s3)
/* 1AD3F4 8027EB14 A6800180 */  sh        $zero, 0x180($s4)
/* 1AD3F8 8027EB18 8EC20000 */  lw        $v0, ($s6)
/* 1AD3FC 8027EB1C 24110009 */  addiu     $s1, $zero, 9
/* 1AD400 8027EB20 30422000 */  andi      $v0, $v0, 0x2000
/* 1AD404 8027EB24 14400016 */  bnez      $v0, .L8027EB80
/* 1AD408 8027EB28 AFA0001C */   sw       $zero, 0x1c($sp)
/* 1AD40C 8027EB2C 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AD410 8027EB30 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 1AD414 8027EB34 3C030200 */  lui       $v1, 0x200
/* 1AD418 8027EB38 00431024 */  and       $v0, $v0, $v1
/* 1AD41C 8027EB3C 14400010 */  bnez      $v0, .L8027EB80
/* 1AD420 8027EB40 00000000 */   nop
/* 1AD424 8027EB44 8FA80020 */  lw        $t0, 0x20($sp)
/* 1AD428 8027EB48 1500000D */  bnez      $t0, .L8027EB80
/* 1AD42C 8027EB4C 00000000 */   nop
/* 1AD430 8027EB50 8EC20004 */  lw        $v0, 4($s6)
/* 1AD434 8027EB54 30420004 */  andi      $v0, $v0, 4
/* 1AD438 8027EB58 14400009 */  bnez      $v0, .L8027EB80
/* 1AD43C 8027EB5C 00000000 */   nop
/* 1AD440 8027EB60 926201B8 */  lbu       $v0, 0x1b8($s3)
/* 1AD444 8027EB64 00441023 */  subu      $v0, $v0, $a0
/* 1AD448 8027EB68 A26201B8 */  sb        $v0, 0x1b8($s3)
/* 1AD44C 8027EB6C 00021600 */  sll       $v0, $v0, 0x18
/* 1AD450 8027EB70 1C400003 */  bgtz      $v0, .L8027EB80
/* 1AD454 8027EB74 00000000 */   nop
/* 1AD458 8027EB78 A26001B8 */  sb        $zero, 0x1b8($s3)
/* 1AD45C 8027EB7C 24110020 */  addiu     $s1, $zero, 0x20
.L8027EB80:
/* 1AD460 8027EB80 96820180 */  lhu       $v0, 0x180($s4)
/* 1AD464 8027EB84 00441021 */  addu      $v0, $v0, $a0
/* 1AD468 8027EB88 A6820180 */  sh        $v0, 0x180($s4)
/* 1AD46C 8027EB8C A66201F8 */  sh        $v0, 0x1f8($s3)
/* 1AD470 8027EB90 A66001FA */  sh        $zero, 0x1fa($s3)
.L8027EB94:
/* 1AD474 8027EB94 8EC20000 */  lw        $v0, ($s6)
/* 1AD478 8027EB98 30422000 */  andi      $v0, $v0, 0x2000
/* 1AD47C 8027EB9C 10400033 */  beqz      $v0, .L8027EC6C
/* 1AD480 8027EBA0 2403000B */   addiu    $v1, $zero, 0xb
/* 1AD484 8027EBA4 8FA80018 */  lw        $t0, 0x18($sp)
/* 1AD488 8027EBA8 81020212 */  lb        $v0, 0x212($t0)
/* 1AD48C 8027EBAC 10430011 */  beq       $v0, $v1, .L8027EBF4
/* 1AD490 8027EBB0 00000000 */   nop
/* 1AD494 8027EBB4 82620212 */  lb        $v0, 0x212($s3)
/* 1AD498 8027EBB8 10430005 */  beq       $v0, $v1, .L8027EBD0
/* 1AD49C 8027EBBC 00000000 */   nop
/* 1AD4A0 8027EBC0 8EC2007C */  lw        $v0, 0x7c($s6)
/* 1AD4A4 8027EBC4 30420080 */  andi      $v0, $v0, 0x80
/* 1AD4A8 8027EBC8 1040000A */  beqz      $v0, .L8027EBF4
/* 1AD4AC 8027EBCC 00000000 */   nop
.L8027EBD0:
/* 1AD4B0 8027EBD0 8E820188 */  lw        $v0, 0x188($s4)
/* 1AD4B4 8027EBD4 3C031000 */  lui       $v1, 0x1000
/* 1AD4B8 8027EBD8 00431024 */  and       $v0, $v0, $v1
/* 1AD4BC 8027EBDC 14400005 */  bnez      $v0, .L8027EBF4
/* 1AD4C0 8027EBE0 00000000 */   nop
/* 1AD4C4 8027EBE4 8E82018C */  lw        $v0, 0x18c($s4)
/* 1AD4C8 8027EBE8 30420008 */  andi      $v0, $v0, 8
/* 1AD4CC 8027EBEC 1040035A */  beqz      $v0, .L8027F958
/* 1AD4D0 8027EBF0 00000000 */   nop
.L8027EBF4:
/* 1AD4D4 8027EBF4 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 1AD4D8 8027EBF8 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 1AD4DC 8027EBFC 8E020000 */  lw        $v0, ($s0)
/* 1AD4E0 8027EC00 30420020 */  andi      $v0, $v0, 0x20
/* 1AD4E4 8027EC04 14400002 */  bnez      $v0, .L8027EC10
/* 1AD4E8 8027EC08 24110019 */   addiu    $s1, $zero, 0x19
/* 1AD4EC 8027EC0C 24110017 */  addiu     $s1, $zero, 0x17
.L8027EC10:
/* 1AD4F0 8027EC10 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1AD4F4 8027EC14 2404010C */  addiu     $a0, $zero, 0x10c
/* 1AD4F8 8027EC18 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1AD4FC 8027EC1C 8E46000C */  lw        $a2, 0xc($s2)
/* 1AD500 8027EC20 8E470010 */  lw        $a3, 0x10($s2)
/* 1AD504 8027EC24 0C052757 */  jal       sfx_play_sound_at_position
/* 1AD508 8027EC28 0000282D */   daddu    $a1, $zero, $zero
/* 1AD50C 8027EC2C 0260202D */  daddu     $a0, $s3, $zero
/* 1AD510 8027EC30 0C09DC58 */  jal       dispatch_event_actor
/* 1AD514 8027EC34 0220282D */   daddu    $a1, $s1, $zero
/* 1AD518 8027EC38 24020001 */  addiu     $v0, $zero, 1
/* 1AD51C 8027EC3C AFA20010 */  sw        $v0, 0x10($sp)
/* 1AD520 8027EC40 24020003 */  addiu     $v0, $zero, 3
/* 1AD524 8027EC44 AFA20014 */  sw        $v0, 0x14($sp)
/* 1AD528 8027EC48 C64C000C */  lwc1      $f12, 0xc($s2)
/* 1AD52C 8027EC4C C64E0010 */  lwc1      $f14, 0x10($s2)
/* 1AD530 8027EC50 8E460014 */  lw        $a2, 0x14($s2)
/* 1AD534 8027EC54 0C093BF8 */  jal       func_8024EFE0
/* 1AD538 8027EC58 0000382D */   daddu    $a3, $zero, $zero
.L8027EC5C:
/* 1AD53C 8027EC5C 8E020000 */  lw        $v0, ($s0)
/* 1AD540 8027EC60 30420240 */  andi      $v0, $v0, 0x240
.L8027EC64:
/* 1AD544 8027EC64 0809FE67 */  j         .L8027F99C
/* 1AD548 8027EC68 0002102B */   sltu     $v0, $zero, $v0
.L8027EC6C:
/* 1AD54C 8027EC6C 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AD550 8027EC70 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 1AD554 8027EC74 30420020 */  andi      $v0, $v0, 0x20
/* 1AD558 8027EC78 1040000D */  beqz      $v0, .L8027ECB0
/* 1AD55C 8027EC7C 24020009 */   addiu    $v0, $zero, 9
/* 1AD560 8027EC80 52220001 */  beql      $s1, $v0, .L8027EC88
/* 1AD564 8027EC84 2411000A */   addiu    $s1, $zero, 0xa
.L8027EC88:
/* 1AD568 8027EC88 24020017 */  addiu     $v0, $zero, 0x17
/* 1AD56C 8027EC8C 52220001 */  beql      $s1, $v0, .L8027EC94
/* 1AD570 8027EC90 24110019 */   addiu    $s1, $zero, 0x19
.L8027EC94:
/* 1AD574 8027EC94 826201B8 */  lb        $v0, 0x1b8($s3)
/* 1AD578 8027EC98 1C400008 */  bgtz      $v0, .L8027ECBC
/* 1AD57C 8027EC9C 24020019 */   addiu    $v0, $zero, 0x19
/* 1AD580 8027ECA0 52220006 */  beql      $s1, $v0, .L8027ECBC
/* 1AD584 8027ECA4 24110020 */   addiu    $s1, $zero, 0x20
/* 1AD588 8027ECA8 0809FB2F */  j         .L8027ECBC
/* 1AD58C 8027ECAC 00000000 */   nop
.L8027ECB0:
/* 1AD590 8027ECB0 24020020 */  addiu     $v0, $zero, 0x20
/* 1AD594 8027ECB4 52220001 */  beql      $s1, $v0, .L8027ECBC
/* 1AD598 8027ECB8 24110009 */   addiu    $s1, $zero, 9
.L8027ECBC:
/* 1AD59C 8027ECBC 3C10800E */  lui       $s0, %hi(gBattleStatus)
/* 1AD5A0 8027ECC0 2610C070 */  addiu     $s0, $s0, %lo(gBattleStatus)
/* 1AD5A4 8027ECC4 8E020000 */  lw        $v0, ($s0)
/* 1AD5A8 8027ECC8 30420020 */  andi      $v0, $v0, 0x20
/* 1AD5AC 8027ECCC 14400007 */  bnez      $v0, .L8027ECEC
/* 1AD5B0 8027ECD0 00000000 */   nop
/* 1AD5B4 8027ECD4 0C099B85 */  jal       func_80266E14
/* 1AD5B8 8027ECD8 02C0202D */   daddu    $a0, $s6, $zero
/* 1AD5BC 8027ECDC 8E020000 */  lw        $v0, ($s0)
/* 1AD5C0 8027ECE0 30420020 */  andi      $v0, $v0, 0x20
/* 1AD5C4 8027ECE4 10400055 */  beqz      $v0, .L8027EE3C
/* 1AD5C8 8027ECE8 00000000 */   nop
.L8027ECEC:
/* 1AD5CC 8027ECEC 8E820188 */  lw        $v0, 0x188($s4)
/* 1AD5D0 8027ECF0 3C030400 */  lui       $v1, 0x400
/* 1AD5D4 8027ECF4 00431024 */  and       $v0, $v0, $v1
/* 1AD5D8 8027ECF8 10400007 */  beqz      $v0, .L8027ED18
/* 1AD5DC 8027ECFC 2402000A */   addiu    $v0, $zero, 0xa
/* 1AD5E0 8027ED00 52220001 */  beql      $s1, $v0, .L8027ED08
/* 1AD5E4 8027ED04 2411000B */   addiu    $s1, $zero, 0xb
.L8027ED08:
/* 1AD5E8 8027ED08 24020020 */  addiu     $v0, $zero, 0x20
/* 1AD5EC 8027ED0C 52220001 */  beql      $s1, $v0, .L8027ED14
/* 1AD5F0 8027ED10 24110021 */   addiu    $s1, $zero, 0x21
.L8027ED14:
/* 1AD5F4 8027ED14 241E0001 */  addiu     $fp, $zero, 1
.L8027ED18:
/* 1AD5F8 8027ED18 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AD5FC 8027ED1C 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 1AD600 8027ED20 30420020 */  andi      $v0, $v0, 0x20
/* 1AD604 8027ED24 10400045 */  beqz      $v0, .L8027EE3C
/* 1AD608 8027ED28 3C031000 */   lui      $v1, 0x1000
/* 1AD60C 8027ED2C 8E820188 */  lw        $v0, 0x188($s4)
/* 1AD610 8027ED30 00431024 */  and       $v0, $v0, $v1
/* 1AD614 8027ED34 14400013 */  bnez      $v0, .L8027ED84
/* 1AD618 8027ED38 3C030010 */   lui      $v1, 0x10
/* 1AD61C 8027ED3C 8EC2007C */  lw        $v0, 0x7c($s6)
/* 1AD620 8027ED40 00431024 */  and       $v0, $v0, $v1
/* 1AD624 8027ED44 1040000F */  beqz      $v0, .L8027ED84
/* 1AD628 8027ED48 24020009 */   addiu    $v0, $zero, 9
/* 1AD62C 8027ED4C 52220001 */  beql      $s1, $v0, .L8027ED54
/* 1AD630 8027ED50 24110015 */   addiu    $s1, $zero, 0x15
.L8027ED54:
/* 1AD634 8027ED54 2402000A */  addiu     $v0, $zero, 0xa
/* 1AD638 8027ED58 52220001 */  beql      $s1, $v0, .L8027ED60
/* 1AD63C 8027ED5C 24110015 */   addiu    $s1, $zero, 0x15
.L8027ED60:
/* 1AD640 8027ED60 24020017 */  addiu     $v0, $zero, 0x17
/* 1AD644 8027ED64 52220001 */  beql      $s1, $v0, .L8027ED6C
/* 1AD648 8027ED68 24110015 */   addiu    $s1, $zero, 0x15
.L8027ED6C:
/* 1AD64C 8027ED6C 24020019 */  addiu     $v0, $zero, 0x19
/* 1AD650 8027ED70 52220001 */  beql      $s1, $v0, .L8027ED78
/* 1AD654 8027ED74 24110015 */   addiu    $s1, $zero, 0x15
.L8027ED78:
/* 1AD658 8027ED78 24020020 */  addiu     $v0, $zero, 0x20
/* 1AD65C 8027ED7C 52220001 */  beql      $s1, $v0, .L8027ED84
/* 1AD660 8027ED80 24110028 */   addiu    $s1, $zero, 0x28
.L8027ED84:
/* 1AD664 8027ED84 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AD668 8027ED88 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 1AD66C 8027ED8C 30420020 */  andi      $v0, $v0, 0x20
/* 1AD670 8027ED90 1040002A */  beqz      $v0, .L8027EE3C
/* 1AD674 8027ED94 00000000 */   nop
/* 1AD678 8027ED98 8E820188 */  lw        $v0, 0x188($s4)
/* 1AD67C 8027ED9C 30420080 */  andi      $v0, $v0, 0x80
/* 1AD680 8027EDA0 1040000B */  beqz      $v0, .L8027EDD0
/* 1AD684 8027EDA4 00000000 */   nop
/* 1AD688 8027EDA8 8EC2007C */  lw        $v0, 0x7c($s6)
/* 1AD68C 8027EDAC 30424000 */  andi      $v0, $v0, 0x4000
/* 1AD690 8027EDB0 10400007 */  beqz      $v0, .L8027EDD0
/* 1AD694 8027EDB4 2402000A */   addiu    $v0, $zero, 0xa
/* 1AD698 8027EDB8 52220001 */  beql      $s1, $v0, .L8027EDC0
/* 1AD69C 8027EDBC 2411000C */   addiu    $s1, $zero, 0xc
.L8027EDC0:
/* 1AD6A0 8027EDC0 24020019 */  addiu     $v0, $zero, 0x19
/* 1AD6A4 8027EDC4 52220001 */  beql      $s1, $v0, .L8027EDCC
/* 1AD6A8 8027EDC8 2411000C */   addiu    $s1, $zero, 0xc
.L8027EDCC:
/* 1AD6AC 8027EDCC 241E0001 */  addiu     $fp, $zero, 1
.L8027EDD0:
/* 1AD6B0 8027EDD0 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AD6B4 8027EDD4 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 1AD6B8 8027EDD8 30420020 */  andi      $v0, $v0, 0x20
/* 1AD6BC 8027EDDC 10400017 */  beqz      $v0, .L8027EE3C
/* 1AD6C0 8027EDE0 00000000 */   nop
/* 1AD6C4 8027EDE4 8E820188 */  lw        $v0, 0x188($s4)
/* 1AD6C8 8027EDE8 30420080 */  andi      $v0, $v0, 0x80
/* 1AD6CC 8027EDEC 1040000E */  beqz      $v0, .L8027EE28
/* 1AD6D0 8027EDF0 00000000 */   nop
/* 1AD6D4 8027EDF4 8EC2007C */  lw        $v0, 0x7c($s6)
/* 1AD6D8 8027EDF8 30421000 */  andi      $v0, $v0, 0x1000
/* 1AD6DC 8027EDFC 1040000A */  beqz      $v0, .L8027EE28
/* 1AD6E0 8027EE00 2402000A */   addiu    $v0, $zero, 0xa
/* 1AD6E4 8027EE04 52220001 */  beql      $s1, $v0, .L8027EE0C
/* 1AD6E8 8027EE08 2411000D */   addiu    $s1, $zero, 0xd
.L8027EE0C:
/* 1AD6EC 8027EE0C 24020019 */  addiu     $v0, $zero, 0x19
/* 1AD6F0 8027EE10 52220001 */  beql      $s1, $v0, .L8027EE18
/* 1AD6F4 8027EE14 2411000D */   addiu    $s1, $zero, 0xd
.L8027EE18:
/* 1AD6F8 8027EE18 8E620000 */  lw        $v0, ($s3)
/* 1AD6FC 8027EE1C 30420400 */  andi      $v0, $v0, 0x400
/* 1AD700 8027EE20 50400001 */  beql      $v0, $zero, .L8027EE28
/* 1AD704 8027EE24 241E0001 */   addiu    $fp, $zero, 1
.L8027EE28:
/* 1AD708 8027EE28 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AD70C 8027EE2C 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 1AD710 8027EE30 30420020 */  andi      $v0, $v0, 0x20
/* 1AD714 8027EE34 14400017 */  bnez      $v0, .L8027EE94
/* 1AD718 8027EE38 00000000 */   nop
.L8027EE3C:
/* 1AD71C 8027EE3C 8E820188 */  lw        $v0, 0x188($s4)
/* 1AD720 8027EE40 30420080 */  andi      $v0, $v0, 0x80
/* 1AD724 8027EE44 1040000E */  beqz      $v0, .L8027EE80
/* 1AD728 8027EE48 00000000 */   nop
/* 1AD72C 8027EE4C 8EC2007C */  lw        $v0, 0x7c($s6)
/* 1AD730 8027EE50 30421000 */  andi      $v0, $v0, 0x1000
/* 1AD734 8027EE54 1040000A */  beqz      $v0, .L8027EE80
/* 1AD738 8027EE58 24020009 */   addiu    $v0, $zero, 9
/* 1AD73C 8027EE5C 52220001 */  beql      $s1, $v0, .L8027EE64
/* 1AD740 8027EE60 2411000D */   addiu    $s1, $zero, 0xd
.L8027EE64:
/* 1AD744 8027EE64 24020017 */  addiu     $v0, $zero, 0x17
/* 1AD748 8027EE68 52220001 */  beql      $s1, $v0, .L8027EE70
/* 1AD74C 8027EE6C 2411000D */   addiu    $s1, $zero, 0xd
.L8027EE70:
/* 1AD750 8027EE70 8E620000 */  lw        $v0, ($s3)
/* 1AD754 8027EE74 30420400 */  andi      $v0, $v0, 0x400
/* 1AD758 8027EE78 50400001 */  beql      $v0, $zero, .L8027EE80
/* 1AD75C 8027EE7C 241E0001 */   addiu    $fp, $zero, 1
.L8027EE80:
/* 1AD760 8027EE80 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AD764 8027EE84 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 1AD768 8027EE88 30420020 */  andi      $v0, $v0, 0x20
/* 1AD76C 8027EE8C 104000DA */  beqz      $v0, .L8027F1F8
/* 1AD770 8027EE90 00000000 */   nop
.L8027EE94:
/* 1AD774 8027EE94 8E820188 */  lw        $v0, 0x188($s4)
/* 1AD778 8027EE98 30420200 */  andi      $v0, $v0, 0x200
/* 1AD77C 8027EE9C 10400010 */  beqz      $v0, .L8027EEE0
/* 1AD780 8027EEA0 00000000 */   nop
/* 1AD784 8027EEA4 8EC2007C */  lw        $v0, 0x7c($s6)
/* 1AD788 8027EEA8 30420200 */  andi      $v0, $v0, 0x200
/* 1AD78C 8027EEAC 1040000C */  beqz      $v0, .L8027EEE0
/* 1AD790 8027EEB0 24020020 */   addiu    $v0, $zero, 0x20
/* 1AD794 8027EEB4 52220001 */  beql      $s1, $v0, .L8027EEBC
/* 1AD798 8027EEB8 24110022 */   addiu    $s1, $zero, 0x22
.L8027EEBC:
/* 1AD79C 8027EEBC 24020019 */  addiu     $v0, $zero, 0x19
/* 1AD7A0 8027EEC0 52220001 */  beql      $s1, $v0, .L8027EEC8
/* 1AD7A4 8027EEC4 24110022 */   addiu    $s1, $zero, 0x22
.L8027EEC8:
/* 1AD7A8 8027EEC8 2402000A */  addiu     $v0, $zero, 0xa
/* 1AD7AC 8027EECC 52220001 */  beql      $s1, $v0, .L8027EED4
/* 1AD7B0 8027EED0 24110022 */   addiu    $s1, $zero, 0x22
.L8027EED4:
/* 1AD7B4 8027EED4 241E0001 */  addiu     $fp, $zero, 1
/* 1AD7B8 8027EED8 03C0402D */  daddu     $t0, $fp, $zero
/* 1AD7BC 8027EEDC AFA80024 */  sw        $t0, 0x24($sp)
.L8027EEE0:
/* 1AD7C0 8027EEE0 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AD7C4 8027EEE4 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 1AD7C8 8027EEE8 30420020 */  andi      $v0, $v0, 0x20
/* 1AD7CC 8027EEEC 104000C2 */  beqz      $v0, .L8027F1F8
/* 1AD7D0 8027EEF0 00000000 */   nop
/* 1AD7D4 8027EEF4 8E820188 */  lw        $v0, 0x188($s4)
/* 1AD7D8 8027EEF8 30420202 */  andi      $v0, $v0, 0x202
/* 1AD7DC 8027EEFC 10400008 */  beqz      $v0, .L8027EF20
/* 1AD7E0 8027EF00 2402000A */   addiu    $v0, $zero, 0xa
/* 1AD7E4 8027EF04 52220001 */  beql      $s1, $v0, .L8027EF0C
/* 1AD7E8 8027EF08 2411000E */   addiu    $s1, $zero, 0xe
.L8027EF0C:
/* 1AD7EC 8027EF0C 24020020 */  addiu     $v0, $zero, 0x20
/* 1AD7F0 8027EF10 52220001 */  beql      $s1, $v0, .L8027EF18
/* 1AD7F4 8027EF14 24110024 */   addiu    $s1, $zero, 0x24
.L8027EF18:
/* 1AD7F8 8027EF18 24080001 */  addiu     $t0, $zero, 1
/* 1AD7FC 8027EF1C AFA80024 */  sw        $t0, 0x24($sp)
.L8027EF20:
/* 1AD800 8027EF20 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AD804 8027EF24 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 1AD808 8027EF28 30420020 */  andi      $v0, $v0, 0x20
/* 1AD80C 8027EF2C 104000B2 */  beqz      $v0, .L8027F1F8
/* 1AD810 8027EF30 00000000 */   nop
/* 1AD814 8027EF34 86820180 */  lh        $v0, 0x180($s4)
/* 1AD818 8027EF38 044000AF */  bltz      $v0, .L8027F1F8
/* 1AD81C 8027EF3C 24020020 */   addiu    $v0, $zero, 0x20
/* 1AD820 8027EF40 122200AD */  beq       $s1, $v0, .L8027F1F8
/* 1AD824 8027EF44 24020021 */   addiu    $v0, $zero, 0x21
/* 1AD828 8027EF48 122200AB */  beq       $s1, $v0, .L8027F1F8
/* 1AD82C 8027EF4C 24020022 */   addiu    $v0, $zero, 0x22
/* 1AD830 8027EF50 122200A9 */  beq       $s1, $v0, .L8027F1F8
/* 1AD834 8027EF54 00000000 */   nop
/* 1AD838 8027EF58 8EC20004 */  lw        $v0, 4($s6)
/* 1AD83C 8027EF5C 30420004 */  andi      $v0, $v0, 4
/* 1AD840 8027EF60 144000A5 */  bnez      $v0, .L8027F1F8
/* 1AD844 8027EF64 3C030008 */   lui      $v1, 8
/* 1AD848 8027EF68 8E820190 */  lw        $v0, 0x190($s4)
/* 1AD84C 8027EF6C 00431024 */  and       $v0, $v0, $v1
/* 1AD850 8027EF70 10400008 */  beqz      $v0, .L8027EF94
/* 1AD854 8027EF74 0260202D */   daddu    $a0, $s3, $zero
/* 1AD858 8027EF78 2405000A */  addiu     $a1, $zero, 0xa
/* 1AD85C 8027EF7C 0C099ADE */  jal       try_inflict_status
/* 1AD860 8027EF80 24060027 */   addiu    $a2, $zero, 0x27
/* 1AD864 8027EF84 10400003 */  beqz      $v0, .L8027EF94
/* 1AD868 8027EF88 00000000 */   nop
/* 1AD86C 8027EF8C 241E0001 */  addiu     $fp, $zero, 1
/* 1AD870 8027EF90 03C0A82D */  daddu     $s5, $fp, $zero
.L8027EF94:
/* 1AD874 8027EF94 8E820190 */  lw        $v0, 0x190($s4)
/* 1AD878 8027EF98 3C030002 */  lui       $v1, 2
/* 1AD87C 8027EF9C 00431024 */  and       $v0, $v0, $v1
/* 1AD880 8027EFA0 10400008 */  beqz      $v0, .L8027EFC4
/* 1AD884 8027EFA4 0260202D */   daddu    $a0, $s3, $zero
/* 1AD888 8027EFA8 24050009 */  addiu     $a1, $zero, 9
/* 1AD88C 8027EFAC 0C099ADE */  jal       try_inflict_status
/* 1AD890 8027EFB0 24060025 */   addiu    $a2, $zero, 0x25
/* 1AD894 8027EFB4 10400003 */  beqz      $v0, .L8027EFC4
/* 1AD898 8027EFB8 00000000 */   nop
/* 1AD89C 8027EFBC 241E0001 */  addiu     $fp, $zero, 1
/* 1AD8A0 8027EFC0 03C0A82D */  daddu     $s5, $fp, $zero
.L8027EFC4:
/* 1AD8A4 8027EFC4 8E820190 */  lw        $v0, 0x190($s4)
/* 1AD8A8 8027EFC8 3C030010 */  lui       $v1, 0x10
/* 1AD8AC 8027EFCC 00431024 */  and       $v0, $v0, $v1
/* 1AD8B0 8027EFD0 10400008 */  beqz      $v0, .L8027EFF4
/* 1AD8B4 8027EFD4 0260202D */   daddu    $a0, $s3, $zero
/* 1AD8B8 8027EFD8 2405000C */  addiu     $a1, $zero, 0xc
/* 1AD8BC 8027EFDC 0C099ADE */  jal       try_inflict_status
/* 1AD8C0 8027EFE0 24060028 */   addiu    $a2, $zero, 0x28
/* 1AD8C4 8027EFE4 10400003 */  beqz      $v0, .L8027EFF4
/* 1AD8C8 8027EFE8 00000000 */   nop
/* 1AD8CC 8027EFEC 241E0001 */  addiu     $fp, $zero, 1
/* 1AD8D0 8027EFF0 03C0A82D */  daddu     $s5, $fp, $zero
.L8027EFF4:
/* 1AD8D4 8027EFF4 8E820190 */  lw        $v0, 0x190($s4)
/* 1AD8D8 8027EFF8 30421000 */  andi      $v0, $v0, 0x1000
/* 1AD8DC 8027EFFC 10400008 */  beqz      $v0, .L8027F020
/* 1AD8E0 8027F000 0260202D */   daddu    $a0, $s3, $zero
/* 1AD8E4 8027F004 24050006 */  addiu     $a1, $zero, 6
/* 1AD8E8 8027F008 0C099ADE */  jal       try_inflict_status
/* 1AD8EC 8027F00C 24060020 */   addiu    $a2, $zero, 0x20
/* 1AD8F0 8027F010 10400003 */  beqz      $v0, .L8027F020
/* 1AD8F4 8027F014 00000000 */   nop
/* 1AD8F8 8027F018 241E0001 */  addiu     $fp, $zero, 1
/* 1AD8FC 8027F01C 03C0A82D */  daddu     $s5, $fp, $zero
.L8027F020:
/* 1AD900 8027F020 8E820190 */  lw        $v0, 0x190($s4)
/* 1AD904 8027F024 3C030020 */  lui       $v1, 0x20
/* 1AD908 8027F028 00431024 */  and       $v0, $v0, $v1
/* 1AD90C 8027F02C 10400008 */  beqz      $v0, .L8027F050
/* 1AD910 8027F030 0260202D */   daddu    $a0, $s3, $zero
/* 1AD914 8027F034 24050008 */  addiu     $a1, $zero, 8
/* 1AD918 8027F038 0C099ADE */  jal       try_inflict_status
/* 1AD91C 8027F03C 24060029 */   addiu    $a2, $zero, 0x29
/* 1AD920 8027F040 10400003 */  beqz      $v0, .L8027F050
/* 1AD924 8027F044 00000000 */   nop
/* 1AD928 8027F048 241E0001 */  addiu     $fp, $zero, 1
/* 1AD92C 8027F04C 03C0A82D */  daddu     $s5, $fp, $zero
.L8027F050:
/* 1AD930 8027F050 8E820190 */  lw        $v0, 0x190($s4)
/* 1AD934 8027F054 30422000 */  andi      $v0, $v0, 0x2000
/* 1AD938 8027F058 10400008 */  beqz      $v0, .L8027F07C
/* 1AD93C 8027F05C 0260202D */   daddu    $a0, $s3, $zero
/* 1AD940 8027F060 2405000B */  addiu     $a1, $zero, 0xb
/* 1AD944 8027F064 0C099ADE */  jal       try_inflict_status
/* 1AD948 8027F068 24060021 */   addiu    $a2, $zero, 0x21
/* 1AD94C 8027F06C 10400003 */  beqz      $v0, .L8027F07C
/* 1AD950 8027F070 00000000 */   nop
/* 1AD954 8027F074 241E0001 */  addiu     $fp, $zero, 1
/* 1AD958 8027F078 03C0A82D */  daddu     $s5, $fp, $zero
.L8027F07C:
/* 1AD95C 8027F07C 8E820190 */  lw        $v0, 0x190($s4)
/* 1AD960 8027F080 30428000 */  andi      $v0, $v0, 0x8000
/* 1AD964 8027F084 10400008 */  beqz      $v0, .L8027F0A8
/* 1AD968 8027F088 0260202D */   daddu    $a0, $s3, $zero
/* 1AD96C 8027F08C 24050003 */  addiu     $a1, $zero, 3
/* 1AD970 8027F090 0C099ADE */  jal       try_inflict_status
/* 1AD974 8027F094 24060023 */   addiu    $a2, $zero, 0x23
/* 1AD978 8027F098 10400003 */  beqz      $v0, .L8027F0A8
/* 1AD97C 8027F09C 00000000 */   nop
/* 1AD980 8027F0A0 241E0001 */  addiu     $fp, $zero, 1
/* 1AD984 8027F0A4 03C0A82D */  daddu     $s5, $fp, $zero
.L8027F0A8:
/* 1AD988 8027F0A8 8E820190 */  lw        $v0, 0x190($s4)
/* 1AD98C 8027F0AC 3C030001 */  lui       $v1, 1
/* 1AD990 8027F0B0 00431024 */  and       $v0, $v0, $v1
/* 1AD994 8027F0B4 10400008 */  beqz      $v0, .L8027F0D8
/* 1AD998 8027F0B8 0260202D */   daddu    $a0, $s3, $zero
/* 1AD99C 8027F0BC 24050005 */  addiu     $a1, $zero, 5
/* 1AD9A0 8027F0C0 0C099ADE */  jal       try_inflict_status
/* 1AD9A4 8027F0C4 24060026 */   addiu    $a2, $zero, 0x26
/* 1AD9A8 8027F0C8 10400003 */  beqz      $v0, .L8027F0D8
/* 1AD9AC 8027F0CC 00000000 */   nop
/* 1AD9B0 8027F0D0 241E0001 */  addiu     $fp, $zero, 1
/* 1AD9B4 8027F0D4 03C0A82D */  daddu     $s5, $fp, $zero
.L8027F0D8:
/* 1AD9B8 8027F0D8 8E820190 */  lw        $v0, 0x190($s4)
/* 1AD9BC 8027F0DC 3C030004 */  lui       $v1, 4
/* 1AD9C0 8027F0E0 00431024 */  and       $v0, $v0, $v1
/* 1AD9C4 8027F0E4 10400008 */  beqz      $v0, .L8027F108
/* 1AD9C8 8027F0E8 0260202D */   daddu    $a0, $s3, $zero
/* 1AD9CC 8027F0EC 24050004 */  addiu     $a1, $zero, 4
/* 1AD9D0 8027F0F0 0C099ADE */  jal       try_inflict_status
/* 1AD9D4 8027F0F4 24060024 */   addiu    $a2, $zero, 0x24
/* 1AD9D8 8027F0F8 10400003 */  beqz      $v0, .L8027F108
/* 1AD9DC 8027F0FC 00000000 */   nop
/* 1AD9E0 8027F100 241E0001 */  addiu     $fp, $zero, 1
/* 1AD9E4 8027F104 03C0A82D */  daddu     $s5, $fp, $zero
.L8027F108:
/* 1AD9E8 8027F108 8E620008 */  lw        $v0, 8($s3)
/* 1AD9EC 8027F10C 9050001B */  lbu       $s0, 0x1b($v0)
/* 1AD9F0 8027F110 5E000001 */  bgtzl     $s0, .L8027F118
/* 1AD9F4 8027F114 24100064 */   addiu    $s0, $zero, 0x64
.L8027F118:
/* 1AD9F8 8027F118 92820194 */  lbu       $v0, 0x194($s4)
/* 1AD9FC 8027F11C 00500018 */  mult      $v0, $s0
/* 1ADA00 8027F120 00001012 */  mflo      $v0
/* 1ADA04 8027F124 3C0351EB */  lui       $v1, 0x51eb
/* 1ADA08 8027F128 3463851F */  ori       $v1, $v1, 0x851f
/* 1ADA0C 8027F12C 00430018 */  mult      $v0, $v1
/* 1ADA10 8027F130 000217C3 */  sra       $v0, $v0, 0x1f
/* 1ADA14 8027F134 00001810 */  mfhi      $v1
/* 1ADA18 8027F138 00031943 */  sra       $v1, $v1, 5
/* 1ADA1C 8027F13C 00628023 */  subu      $s0, $v1, $v0
/* 1ADA20 8027F140 8E820190 */  lw        $v0, 0x190($s4)
/* 1ADA24 8027F144 3C030040 */  lui       $v1, 0x40
/* 1ADA28 8027F148 00431024 */  and       $v0, $v0, $v1
/* 1ADA2C 8027F14C 10400023 */  beqz      $v0, .L8027F1DC
/* 1ADA30 8027F150 00000000 */   nop
/* 1ADA34 8027F154 0C00A67F */  jal       rand_int
/* 1ADA38 8027F158 24040063 */   addiu    $a0, $zero, 0x63
/* 1ADA3C 8027F15C 0050102A */  slt       $v0, $v0, $s0
/* 1ADA40 8027F160 1040001C */  beqz      $v0, .L8027F1D4
/* 1ADA44 8027F164 24110019 */   addiu    $s1, $zero, 0x19
/* 1ADA48 8027F168 92620210 */  lbu       $v0, 0x210($s3)
/* 1ADA4C 8027F16C 2442FFFD */  addiu     $v0, $v0, -3
/* 1ADA50 8027F170 2C420006 */  sltiu     $v0, $v0, 6
/* 1ADA54 8027F174 14400018 */  bnez      $v0, .L8027F1D8
/* 1ADA58 8027F178 24080002 */   addiu    $t0, $zero, 2
/* 1ADA5C 8027F17C 8E620000 */  lw        $v0, ($s3)
/* 1ADA60 8027F180 30420400 */  andi      $v0, $v0, 0x400
/* 1ADA64 8027F184 14400014 */  bnez      $v0, .L8027F1D8
/* 1ADA68 8027F188 00000000 */   nop
/* 1ADA6C 8027F18C 24110039 */  addiu     $s1, $zero, 0x39
/* 1ADA70 8027F190 24150001 */  addiu     $s5, $zero, 1
/* 1ADA74 8027F194 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1ADA78 8027F198 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 1ADA7C 8027F19C AFA0001C */  sw        $zero, 0x1c($sp)
/* 1ADA80 8027F1A0 8C430000 */  lw        $v1, ($v0)
/* 1ADA84 8027F1A4 02A0F02D */  daddu     $fp, $s5, $zero
/* 1ADA88 8027F1A8 34630079 */  ori       $v1, $v1, 0x79
/* 1ADA8C 8027F1AC AC430000 */  sw        $v1, ($v0)
/* 1ADA90 8027F1B0 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ADA94 8027F1B4 24040231 */  addiu     $a0, $zero, 0x231
/* 1ADA98 8027F1B8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1ADA9C 8027F1BC 8E46000C */  lw        $a2, 0xc($s2)
/* 1ADAA0 8027F1C0 8E470010 */  lw        $a3, 0x10($s2)
/* 1ADAA4 8027F1C4 0C052757 */  jal       sfx_play_sound_at_position
/* 1ADAA8 8027F1C8 0000282D */   daddu    $a1, $zero, $zero
/* 1ADAAC 8027F1CC 0809FC77 */  j         .L8027F1DC
/* 1ADAB0 8027F1D0 00000000 */   nop
.L8027F1D4:
/* 1ADAB4 8027F1D4 24080002 */  addiu     $t0, $zero, 2
.L8027F1D8:
/* 1ADAB8 8027F1D8 AFA8001C */  sw        $t0, 0x1c($sp)
.L8027F1DC:
/* 1ADABC 8027F1DC 12A00006 */  beqz      $s5, .L8027F1F8
/* 1ADAC0 8027F1E0 24020017 */   addiu    $v0, $zero, 0x17
/* 1ADAC4 8027F1E4 52220001 */  beql      $s1, $v0, .L8027F1EC
/* 1ADAC8 8027F1E8 24110009 */   addiu    $s1, $zero, 9
.L8027F1EC:
/* 1ADACC 8027F1EC 24020019 */  addiu     $v0, $zero, 0x19
/* 1ADAD0 8027F1F0 52220001 */  beql      $s1, $v0, .L8027F1F8
/* 1ADAD4 8027F1F4 2411000A */   addiu    $s1, $zero, 0xa
.L8027F1F8:
/* 1ADAD8 8027F1F8 8E620008 */  lw        $v0, 8($s3)
/* 1ADADC 8027F1FC 92830194 */  lbu       $v1, 0x194($s4)
/* 1ADAE0 8027F200 9050001B */  lbu       $s0, 0x1b($v0)
/* 1ADAE4 8027F204 00700018 */  mult      $v1, $s0
/* 1ADAE8 8027F208 00001812 */  mflo      $v1
/* 1ADAEC 8027F20C 3C0251EB */  lui       $v0, 0x51eb
/* 1ADAF0 8027F210 3442851F */  ori       $v0, $v0, 0x851f
/* 1ADAF4 8027F214 00620018 */  mult      $v1, $v0
/* 1ADAF8 8027F218 3C17800E */  lui       $s7, %hi(gBattleStatus)
/* 1ADAFC 8027F21C 26F7C070 */  addiu     $s7, $s7, %lo(gBattleStatus)
/* 1ADB00 8027F220 8EE20000 */  lw        $v0, ($s7)
/* 1ADB04 8027F224 00031FC3 */  sra       $v1, $v1, 0x1f
/* 1ADB08 8027F228 30420020 */  andi      $v0, $v0, 0x20
/* 1ADB0C 8027F22C 00004810 */  mfhi      $t1
/* 1ADB10 8027F230 00092143 */  sra       $a0, $t1, 5
/* 1ADB14 8027F234 10400025 */  beqz      $v0, .L8027F2CC
/* 1ADB18 8027F238 00838023 */   subu     $s0, $a0, $v1
/* 1ADB1C 8027F23C 8E820188 */  lw        $v0, 0x188($s4)
/* 1ADB20 8027F240 30421000 */  andi      $v0, $v0, 0x1000
/* 1ADB24 8027F244 10400022 */  beqz      $v0, .L8027F2D0
/* 1ADB28 8027F248 0260202D */   daddu    $a0, $s3, $zero
/* 1ADB2C 8027F24C 0C00A67F */  jal       rand_int
/* 1ADB30 8027F250 24040063 */   addiu    $a0, $zero, 0x63
/* 1ADB34 8027F254 0050102A */  slt       $v0, $v0, $s0
/* 1ADB38 8027F258 1040001A */  beqz      $v0, .L8027F2C4
/* 1ADB3C 8027F25C 24110019 */   addiu    $s1, $zero, 0x19
/* 1ADB40 8027F260 92620210 */  lbu       $v0, 0x210($s3)
/* 1ADB44 8027F264 2442FFFD */  addiu     $v0, $v0, -3
/* 1ADB48 8027F268 2C420006 */  sltiu     $v0, $v0, 6
/* 1ADB4C 8027F26C 14400016 */  bnez      $v0, .L8027F2C8
/* 1ADB50 8027F270 24080002 */   addiu    $t0, $zero, 2
/* 1ADB54 8027F274 8E620000 */  lw        $v0, ($s3)
/* 1ADB58 8027F278 30420400 */  andi      $v0, $v0, 0x400
/* 1ADB5C 8027F27C 14400012 */  bnez      $v0, .L8027F2C8
/* 1ADB60 8027F280 00000000 */   nop
/* 1ADB64 8027F284 24110039 */  addiu     $s1, $zero, 0x39
/* 1ADB68 8027F288 24150001 */  addiu     $s5, $zero, 1
/* 1ADB6C 8027F28C AFA0001C */  sw        $zero, 0x1c($sp)
/* 1ADB70 8027F290 8EE20000 */  lw        $v0, ($s7)
/* 1ADB74 8027F294 02A0F02D */  daddu     $fp, $s5, $zero
/* 1ADB78 8027F298 34420079 */  ori       $v0, $v0, 0x79
/* 1ADB7C 8027F29C AEE20000 */  sw        $v0, ($s7)
/* 1ADB80 8027F2A0 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ADB84 8027F2A4 24040231 */  addiu     $a0, $zero, 0x231
/* 1ADB88 8027F2A8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1ADB8C 8027F2AC 8E46000C */  lw        $a2, 0xc($s2)
/* 1ADB90 8027F2B0 8E470010 */  lw        $a3, 0x10($s2)
/* 1ADB94 8027F2B4 0C052757 */  jal       sfx_play_sound_at_position
/* 1ADB98 8027F2B8 0000282D */   daddu    $a1, $zero, $zero
/* 1ADB9C 8027F2BC 0809FCB4 */  j         .L8027F2D0
/* 1ADBA0 8027F2C0 0260202D */   daddu    $a0, $s3, $zero
.L8027F2C4:
/* 1ADBA4 8027F2C4 24080002 */  addiu     $t0, $zero, 2
.L8027F2C8:
/* 1ADBA8 8027F2C8 AFA8001C */  sw        $t0, 0x1c($sp)
.L8027F2CC:
/* 1ADBAC 8027F2CC 0260202D */  daddu     $a0, $s3, $zero
.L8027F2D0:
/* 1ADBB0 8027F2D0 0220282D */  daddu     $a1, $s1, $zero
/* 1ADBB4 8027F2D4 0C09DC58 */  jal       dispatch_event_actor
/* 1ADBB8 8027F2D8 A2950199 */   sb       $s5, 0x199($s4)
/* 1ADBBC 8027F2DC 8E620000 */  lw        $v0, ($s3)
/* 1ADBC0 8027F2E0 3C030200 */  lui       $v1, 0x200
/* 1ADBC4 8027F2E4 00431024 */  and       $v0, $v0, $v1
/* 1ADBC8 8027F2E8 1440002F */  bnez      $v0, .L8027F3A8
/* 1ADBCC 8027F2EC 00000000 */   nop
/* 1ADBD0 8027F2F0 86870180 */  lh        $a3, 0x180($s4)
/* 1ADBD4 8027F2F4 14E0000F */  bnez      $a3, .L8027F334
/* 1ADBD8 8027F2F8 00000000 */   nop
/* 1ADBDC 8027F2FC 17C0002C */  bnez      $fp, .L8027F3B0
/* 1ADBE0 8027F300 00000000 */   nop
/* 1ADBE4 8027F304 16A00028 */  bnez      $s5, .L8027F3A8
/* 1ADBE8 8027F308 24020001 */   addiu    $v0, $zero, 1
/* 1ADBEC 8027F30C AFA20010 */  sw        $v0, 0x10($sp)
/* 1ADBF0 8027F310 24020003 */  addiu     $v0, $zero, 3
/* 1ADBF4 8027F314 AFA20014 */  sw        $v0, 0x14($sp)
/* 1ADBF8 8027F318 C64C000C */  lwc1      $f12, 0xc($s2)
/* 1ADBFC 8027F31C C64E0010 */  lwc1      $f14, 0x10($s2)
/* 1ADC00 8027F320 8E460014 */  lw        $a2, 0x14($s2)
/* 1ADC04 8027F324 0C093BF8 */  jal       func_8024EFE0
/* 1ADC08 8027F328 0000382D */   daddu    $a3, $zero, $zero
/* 1ADC0C 8027F32C 0809FCEA */  j         .L8027F3A8
/* 1ADC10 8027F330 00000000 */   nop
.L8027F334:
/* 1ADC14 8027F334 8FA80020 */  lw        $t0, 0x20($sp)
/* 1ADC18 8027F338 1500001B */  bnez      $t0, .L8027F3A8
/* 1ADC1C 8027F33C 3C032000 */   lui      $v1, 0x2000
/* 1ADC20 8027F340 8E820188 */  lw        $v0, 0x188($s4)
/* 1ADC24 8027F344 34630040 */  ori       $v1, $v1, 0x40
/* 1ADC28 8027F348 00431024 */  and       $v0, $v0, $v1
/* 1ADC2C 8027F34C 10400007 */  beqz      $v0, .L8027F36C
/* 1ADC30 8027F350 AFA00010 */   sw       $zero, 0x10($sp)
/* 1ADC34 8027F354 C64C000C */  lwc1      $f12, 0xc($s2)
/* 1ADC38 8027F358 C64E0010 */  lwc1      $f14, 0x10($s2)
/* 1ADC3C 8027F35C 0C09996B */  jal       show_damage_popup
/* 1ADC40 8027F360 8E460014 */   lw       $a2, 0x14($s2)
/* 1ADC44 8027F364 0809FCDF */  j         .L8027F37C
/* 1ADC48 8027F368 00000000 */   nop
.L8027F36C:
/* 1ADC4C 8027F36C C64C000C */  lwc1      $f12, 0xc($s2)
/* 1ADC50 8027F370 C64E0010 */  lwc1      $f14, 0x10($s2)
/* 1ADC54 8027F374 0C099937 */  jal       func_802664DC
/* 1ADC58 8027F378 8E460014 */   lw       $a2, 0x14($s2)
.L8027F37C:
/* 1ADC5C 8027F37C 8EC20004 */  lw        $v0, 4($s6)
/* 1ADC60 8027F380 30420004 */  andi      $v0, $v0, 4
/* 1ADC64 8027F384 14400008 */  bnez      $v0, .L8027F3A8
/* 1ADC68 8027F388 00000000 */   nop
/* 1ADC6C 8027F38C 86820180 */  lh        $v0, 0x180($s4)
/* 1ADC70 8027F390 AFA20010 */  sw        $v0, 0x10($sp)
/* 1ADC74 8027F394 8E45000C */  lw        $a1, 0xc($s2)
/* 1ADC78 8027F398 8E460010 */  lw        $a2, 0x10($s2)
/* 1ADC7C 8027F39C 8E470014 */  lw        $a3, 0x14($s2)
/* 1ADC80 8027F3A0 0C0999B9 */  jal       func_802666E4
/* 1ADC84 8027F3A4 0260202D */   daddu    $a0, $s3, $zero
.L8027F3A8:
/* 1ADC88 8027F3A8 13C00006 */  beqz      $fp, .L8027F3C4
/* 1ADC8C 8027F3AC 00000000 */   nop
.L8027F3B0:
/* 1ADC90 8027F3B0 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1ADC94 8027F3B4 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 1ADC98 8027F3B8 30420240 */  andi      $v0, $v0, 0x240
/* 1ADC9C 8027F3BC 14400008 */  bnez      $v0, .L8027F3E0
/* 1ADCA0 8027F3C0 00000000 */   nop
.L8027F3C4:
/* 1ADCA4 8027F3C4 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 1ADCA8 8027F3C8 8C63C070 */  lw        $v1, %lo(gBattleStatus)($v1)
/* 1ADCAC 8027F3CC 30620240 */  andi      $v0, $v1, 0x240
/* 1ADCB0 8027F3D0 10400025 */  beqz      $v0, .L8027F468
/* 1ADCB4 8027F3D4 30620080 */   andi     $v0, $v1, 0x80
/* 1ADCB8 8027F3D8 14400023 */  bnez      $v0, .L8027F468
/* 1ADCBC 8027F3DC 00000000 */   nop
.L8027F3E0:
/* 1ADCC0 8027F3E0 86820180 */  lh        $v0, 0x180($s4)
/* 1ADCC4 8027F3E4 1840000A */  blez      $v0, .L8027F410
/* 1ADCC8 8027F3E8 24040231 */   addiu    $a0, $zero, 0x231
/* 1ADCCC 8027F3EC C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ADCD0 8027F3F0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1ADCD4 8027F3F4 8E46000C */  lw        $a2, 0xc($s2)
/* 1ADCD8 8027F3F8 8E470010 */  lw        $a3, 0x10($s2)
/* 1ADCDC 8027F3FC 0C052757 */  jal       sfx_play_sound_at_position
/* 1ADCE0 8027F400 0000282D */   daddu    $a1, $zero, $zero
/* 1ADCE4 8027F404 86820180 */  lh        $v0, 0x180($s4)
/* 1ADCE8 8027F408 1C400008 */  bgtz      $v0, .L8027F42C
/* 1ADCEC 8027F40C 00000000 */   nop
.L8027F410:
/* 1ADCF0 8027F410 8E820188 */  lw        $v0, 0x188($s4)
/* 1ADCF4 8027F414 3C034000 */  lui       $v1, 0x4000
/* 1ADCF8 8027F418 00431024 */  and       $v0, $v0, $v1
/* 1ADCFC 8027F41C 10400012 */  beqz      $v0, .L8027F468
/* 1ADD00 8027F420 00000000 */   nop
/* 1ADD04 8027F424 13C00010 */  beqz      $fp, .L8027F468
/* 1ADD08 8027F428 00000000 */   nop
.L8027F42C:
/* 1ADD0C 8027F42C 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1ADD10 8027F430 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 1ADD14 8027F434 30420040 */  andi      $v0, $v0, 0x40
/* 1ADD18 8027F438 10400004 */  beqz      $v0, .L8027F44C
/* 1ADD1C 8027F43C 0000202D */   daddu    $a0, $zero, $zero
/* 1ADD20 8027F440 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ADD24 8027F444 0809FD16 */  j         .L8027F458
/* 1ADD28 8027F448 E7A00010 */   swc1     $f0, 0x10($sp)
.L8027F44C:
/* 1ADD2C 8027F44C C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ADD30 8027F450 24040003 */  addiu     $a0, $zero, 3
/* 1ADD34 8027F454 E7A00010 */  swc1      $f0, 0x10($sp)
.L8027F458:
/* 1ADD38 8027F458 8E46000C */  lw        $a2, 0xc($s2)
/* 1ADD3C 8027F45C 8E470010 */  lw        $a3, 0x10($s2)
/* 1ADD40 8027F460 0C0999FC */  jal       func_802667F0
/* 1ADD44 8027F464 0260282D */   daddu    $a1, $s3, $zero
.L8027F468:
/* 1ADD48 8027F468 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1ADD4C 8027F46C 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 1ADD50 8027F470 30420020 */  andi      $v0, $v0, 0x20
/* 1ADD54 8027F474 10400003 */  beqz      $v0, .L8027F484
/* 1ADD58 8027F478 00000000 */   nop
/* 1ADD5C 8027F47C 0C099A5C */  jal       func_80266970
/* 1ADD60 8027F480 0260202D */   daddu    $a0, $s3, $zero
.L8027F484:
/* 1ADD64 8027F484 86820180 */  lh        $v0, 0x180($s4)
/* 1ADD68 8027F488 1840002E */  blez      $v0, .L8027F544
/* 1ADD6C 8027F48C 00000000 */   nop
/* 1ADD70 8027F490 8FA80020 */  lw        $t0, 0x20($sp)
/* 1ADD74 8027F494 15000029 */  bnez      $t0, .L8027F53C
/* 1ADD78 8027F498 00000000 */   nop
/* 1ADD7C 8027F49C 8FA80018 */  lw        $t0, 0x18($sp)
/* 1ADD80 8027F4A0 8D0201B0 */  lw        $v0, 0x1b0($t0)
/* 1ADD84 8027F4A4 10400009 */  beqz      $v0, .L8027F4CC
/* 1ADD88 8027F4A8 0260202D */   daddu    $a0, $s3, $zero
/* 1ADD8C 8027F4AC C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ADD90 8027F4B0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1ADD94 8027F4B4 8D0401B0 */  lw        $a0, 0x1b0($t0)
/* 1ADD98 8027F4B8 8E46000C */  lw        $a2, 0xc($s2)
/* 1ADD9C 8027F4BC 8E470010 */  lw        $a3, 0x10($s2)
/* 1ADDA0 8027F4C0 0C052757 */  jal       sfx_play_sound_at_position
/* 1ADDA4 8027F4C4 0000282D */   daddu    $a1, $zero, $zero
/* 1ADDA8 8027F4C8 0260202D */  daddu     $a0, $s3, $zero
.L8027F4CC:
/* 1ADDAC 8027F4CC 0C099C06 */  jal       func_80267018
/* 1ADDB0 8027F4D0 24050001 */   addiu    $a1, $zero, 1
/* 1ADDB4 8027F4D4 8FA80024 */  lw        $t0, 0x24($sp)
/* 1ADDB8 8027F4D8 11000004 */  beqz      $t0, .L8027F4EC
/* 1ADDBC 8027F4DC 240400EA */   addiu    $a0, $zero, 0xea
/* 1ADDC0 8027F4E0 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ADDC4 8027F4E4 0809FD4A */  j         .L8027F528
/* 1ADDC8 8027F4E8 E7A00010 */   swc1     $f0, 0x10($sp)
.L8027F4EC:
/* 1ADDCC 8027F4EC 8FA80028 */  lw        $t0, 0x28($sp)
/* 1ADDD0 8027F4F0 11000004 */  beqz      $t0, .L8027F504
/* 1ADDD4 8027F4F4 2404037B */   addiu    $a0, $zero, 0x37b
/* 1ADDD8 8027F4F8 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ADDDC 8027F4FC 0809FD4A */  j         .L8027F528
/* 1ADDE0 8027F500 E7A00010 */   swc1     $f0, 0x10($sp)
.L8027F504:
/* 1ADDE4 8027F504 8FA8002C */  lw        $t0, 0x2c($sp)
/* 1ADDE8 8027F508 11000004 */  beqz      $t0, .L8027F51C
/* 1ADDEC 8027F50C 240400EB */   addiu    $a0, $zero, 0xeb
/* 1ADDF0 8027F510 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ADDF4 8027F514 0809FD4A */  j         .L8027F528
/* 1ADDF8 8027F518 E7A00010 */   swc1     $f0, 0x10($sp)
.L8027F51C:
/* 1ADDFC 8027F51C C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ADE00 8027F520 240400E9 */  addiu     $a0, $zero, 0xe9
/* 1ADE04 8027F524 E7A00010 */  swc1      $f0, 0x10($sp)
.L8027F528:
/* 1ADE08 8027F528 8E46000C */  lw        $a2, 0xc($s2)
/* 1ADE0C 8027F52C 8E470010 */  lw        $a3, 0x10($s2)
/* 1ADE10 8027F530 0C052757 */  jal       sfx_play_sound_at_position
/* 1ADE14 8027F534 0000282D */   daddu    $a1, $zero, $zero
/* 1ADE18 8027F538 86820180 */  lh        $v0, 0x180($s4)
.L8027F53C:
/* 1ADE1C 8027F53C 1C400005 */  bgtz      $v0, .L8027F554
/* 1ADE20 8027F540 00000000 */   nop
.L8027F544:
/* 1ADE24 8027F544 17C00003 */  bnez      $fp, .L8027F554
/* 1ADE28 8027F548 00000000 */   nop
/* 1ADE2C 8027F54C 12A00005 */  beqz      $s5, .L8027F564
/* 1ADE30 8027F550 00000000 */   nop
.L8027F554:
/* 1ADE34 8027F554 8EC20000 */  lw        $v0, ($s6)
/* 1ADE38 8027F558 30422000 */  andi      $v0, $v0, 0x2000
/* 1ADE3C 8027F55C 10400008 */  beqz      $v0, .L8027F580
/* 1ADE40 8027F560 00000000 */   nop
.L8027F564:
/* 1ADE44 8027F564 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ADE48 8027F568 2404010C */  addiu     $a0, $zero, 0x10c
/* 1ADE4C 8027F56C E7A00010 */  swc1      $f0, 0x10($sp)
/* 1ADE50 8027F570 8E46000C */  lw        $a2, 0xc($s2)
/* 1ADE54 8027F574 8E470010 */  lw        $a3, 0x10($s2)
/* 1ADE58 8027F578 0C052757 */  jal       sfx_play_sound_at_position
/* 1ADE5C 8027F57C 0000282D */   daddu    $a1, $zero, $zero
.L8027F580:
/* 1ADE60 8027F580 8E820190 */  lw        $v0, 0x190($s4)
/* 1ADE64 8027F584 30421000 */  andi      $v0, $v0, 0x1000
/* 1ADE68 8027F588 10400018 */  beqz      $v0, .L8027F5EC
/* 1ADE6C 8027F58C 00000000 */   nop
/* 1ADE70 8027F590 12A00016 */  beqz      $s5, .L8027F5EC
/* 1ADE74 8027F594 00000000 */   nop
/* 1ADE78 8027F598 3C048029 */  lui       $a0, %hi(DoSleepHit)
/* 1ADE7C 8027F59C 248445E0 */  addiu     $a0, $a0, %lo(DoSleepHit)
/* 1ADE80 8027F5A0 2405000A */  addiu     $a1, $zero, 0xa
/* 1ADE84 8027F5A4 0C0B0CF8 */  jal       start_script
/* 1ADE88 8027F5A8 0000302D */   daddu    $a2, $zero, $zero
/* 1ADE8C 8027F5AC C640000C */  lwc1      $f0, 0xc($s2)
/* 1ADE90 8027F5B0 4600018D */  trunc.w.s $f6, $f0
/* 1ADE94 8027F5B4 E4460084 */  swc1      $f6, 0x84($v0)
/* 1ADE98 8027F5B8 C6400010 */  lwc1      $f0, 0x10($s2)
/* 1ADE9C 8027F5BC 4600018D */  trunc.w.s $f6, $f0
/* 1ADEA0 8027F5C0 E4460088 */  swc1      $f6, 0x88($v0)
/* 1ADEA4 8027F5C4 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ADEA8 8027F5C8 4600018D */  trunc.w.s $f6, $f0
/* 1ADEAC 8027F5CC E446008C */  swc1      $f6, 0x8c($v0)
/* 1ADEB0 8027F5D0 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ADEB4 8027F5D4 24042031 */  addiu     $a0, $zero, 0x2031
/* 1ADEB8 8027F5D8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1ADEBC 8027F5DC 8E46000C */  lw        $a2, 0xc($s2)
/* 1ADEC0 8027F5E0 8E470010 */  lw        $a3, 0x10($s2)
/* 1ADEC4 8027F5E4 0C052757 */  jal       sfx_play_sound_at_position
/* 1ADEC8 8027F5E8 0000282D */   daddu    $a1, $zero, $zero
.L8027F5EC:
/* 1ADECC 8027F5EC 8E820190 */  lw        $v0, 0x190($s4)
/* 1ADED0 8027F5F0 3C030004 */  lui       $v1, 4
/* 1ADED4 8027F5F4 00431024 */  and       $v0, $v0, $v1
/* 1ADED8 8027F5F8 10400018 */  beqz      $v0, .L8027F65C
/* 1ADEDC 8027F5FC 00000000 */   nop
/* 1ADEE0 8027F600 12A00016 */  beqz      $s5, .L8027F65C
/* 1ADEE4 8027F604 00000000 */   nop
/* 1ADEE8 8027F608 3C048029 */  lui       $a0, %hi(DoDizzyHit)
/* 1ADEEC 8027F60C 248445FC */  addiu     $a0, $a0, %lo(DoDizzyHit)
/* 1ADEF0 8027F610 2405000A */  addiu     $a1, $zero, 0xa
/* 1ADEF4 8027F614 0C0B0CF8 */  jal       start_script
/* 1ADEF8 8027F618 0000302D */   daddu    $a2, $zero, $zero
/* 1ADEFC 8027F61C C640000C */  lwc1      $f0, 0xc($s2)
/* 1ADF00 8027F620 4600018D */  trunc.w.s $f6, $f0
/* 1ADF04 8027F624 E4460084 */  swc1      $f6, 0x84($v0)
/* 1ADF08 8027F628 C6400010 */  lwc1      $f0, 0x10($s2)
/* 1ADF0C 8027F62C 4600018D */  trunc.w.s $f6, $f0
/* 1ADF10 8027F630 E4460088 */  swc1      $f6, 0x88($v0)
/* 1ADF14 8027F634 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ADF18 8027F638 4600018D */  trunc.w.s $f6, $f0
/* 1ADF1C 8027F63C E446008C */  swc1      $f6, 0x8c($v0)
/* 1ADF20 8027F640 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ADF24 8027F644 24042032 */  addiu     $a0, $zero, 0x2032
/* 1ADF28 8027F648 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1ADF2C 8027F64C 8E46000C */  lw        $a2, 0xc($s2)
/* 1ADF30 8027F650 8E470010 */  lw        $a3, 0x10($s2)
/* 1ADF34 8027F654 0C052757 */  jal       sfx_play_sound_at_position
/* 1ADF38 8027F658 0000282D */   daddu    $a1, $zero, $zero
.L8027F65C:
/* 1ADF3C 8027F65C 8E820190 */  lw        $v0, 0x190($s4)
/* 1ADF40 8027F660 3C030001 */  lui       $v1, 1
/* 1ADF44 8027F664 00431024 */  and       $v0, $v0, $v1
/* 1ADF48 8027F668 10400018 */  beqz      $v0, .L8027F6CC
/* 1ADF4C 8027F66C 00000000 */   nop
/* 1ADF50 8027F670 12A00016 */  beqz      $s5, .L8027F6CC
/* 1ADF54 8027F674 00000000 */   nop
/* 1ADF58 8027F678 3C048029 */  lui       $a0, %hi(DoParalyzeHit)
/* 1ADF5C 8027F67C 24844618 */  addiu     $a0, $a0, %lo(DoParalyzeHit)
/* 1ADF60 8027F680 2405000A */  addiu     $a1, $zero, 0xa
/* 1ADF64 8027F684 0C0B0CF8 */  jal       start_script
/* 1ADF68 8027F688 0000302D */   daddu    $a2, $zero, $zero
/* 1ADF6C 8027F68C C640000C */  lwc1      $f0, 0xc($s2)
/* 1ADF70 8027F690 4600018D */  trunc.w.s $f6, $f0
/* 1ADF74 8027F694 E4460084 */  swc1      $f6, 0x84($v0)
/* 1ADF78 8027F698 C6400010 */  lwc1      $f0, 0x10($s2)
/* 1ADF7C 8027F69C 4600018D */  trunc.w.s $f6, $f0
/* 1ADF80 8027F6A0 E4460088 */  swc1      $f6, 0x88($v0)
/* 1ADF84 8027F6A4 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ADF88 8027F6A8 4600018D */  trunc.w.s $f6, $f0
/* 1ADF8C 8027F6AC E446008C */  swc1      $f6, 0x8c($v0)
/* 1ADF90 8027F6B0 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ADF94 8027F6B4 24042032 */  addiu     $a0, $zero, 0x2032
/* 1ADF98 8027F6B8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1ADF9C 8027F6BC 8E46000C */  lw        $a2, 0xc($s2)
/* 1ADFA0 8027F6C0 8E470010 */  lw        $a3, 0x10($s2)
/* 1ADFA4 8027F6C4 0C052757 */  jal       sfx_play_sound_at_position
/* 1ADFA8 8027F6C8 0000282D */   daddu    $a1, $zero, $zero
.L8027F6CC:
/* 1ADFAC 8027F6CC 8E820190 */  lw        $v0, 0x190($s4)
/* 1ADFB0 8027F6D0 3C030002 */  lui       $v1, 2
/* 1ADFB4 8027F6D4 00431024 */  and       $v0, $v0, $v1
/* 1ADFB8 8027F6D8 10400018 */  beqz      $v0, .L8027F73C
/* 1ADFBC 8027F6DC 00000000 */   nop
/* 1ADFC0 8027F6E0 12A00016 */  beqz      $s5, .L8027F73C
/* 1ADFC4 8027F6E4 00000000 */   nop
/* 1ADFC8 8027F6E8 3C048029 */  lui       $a0, %hi(DoPoisonHit)
/* 1ADFCC 8027F6EC 24844634 */  addiu     $a0, $a0, %lo(DoPoisonHit)
/* 1ADFD0 8027F6F0 2405000A */  addiu     $a1, $zero, 0xa
/* 1ADFD4 8027F6F4 0C0B0CF8 */  jal       start_script
/* 1ADFD8 8027F6F8 0000302D */   daddu    $a2, $zero, $zero
/* 1ADFDC 8027F6FC C640000C */  lwc1      $f0, 0xc($s2)
/* 1ADFE0 8027F700 4600018D */  trunc.w.s $f6, $f0
/* 1ADFE4 8027F704 E4460084 */  swc1      $f6, 0x84($v0)
/* 1ADFE8 8027F708 C6400010 */  lwc1      $f0, 0x10($s2)
/* 1ADFEC 8027F70C 4600018D */  trunc.w.s $f6, $f0
/* 1ADFF0 8027F710 E4460088 */  swc1      $f6, 0x88($v0)
/* 1ADFF4 8027F714 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1ADFF8 8027F718 4600018D */  trunc.w.s $f6, $f0
/* 1ADFFC 8027F71C E446008C */  swc1      $f6, 0x8c($v0)
/* 1AE000 8027F720 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1AE004 8027F724 24042032 */  addiu     $a0, $zero, 0x2032
/* 1AE008 8027F728 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1AE00C 8027F72C 8E46000C */  lw        $a2, 0xc($s2)
/* 1AE010 8027F730 8E470010 */  lw        $a3, 0x10($s2)
/* 1AE014 8027F734 0C052757 */  jal       sfx_play_sound_at_position
/* 1AE018 8027F738 0000282D */   daddu    $a1, $zero, $zero
.L8027F73C:
/* 1AE01C 8027F73C 8E820190 */  lw        $v0, 0x190($s4)
/* 1AE020 8027F740 3C030020 */  lui       $v1, 0x20
/* 1AE024 8027F744 00431024 */  and       $v0, $v0, $v1
/* 1AE028 8027F748 10400018 */  beqz      $v0, .L8027F7AC
/* 1AE02C 8027F74C 00000000 */   nop
/* 1AE030 8027F750 12A00016 */  beqz      $s5, .L8027F7AC
/* 1AE034 8027F754 00000000 */   nop
/* 1AE038 8027F758 3C048029 */  lui       $a0, %hi(DoStopHit)
/* 1AE03C 8027F75C 24844650 */  addiu     $a0, $a0, %lo(DoStopHit)
/* 1AE040 8027F760 2405000A */  addiu     $a1, $zero, 0xa
/* 1AE044 8027F764 0C0B0CF8 */  jal       start_script
/* 1AE048 8027F768 0000302D */   daddu    $a2, $zero, $zero
/* 1AE04C 8027F76C C640000C */  lwc1      $f0, 0xc($s2)
/* 1AE050 8027F770 4600018D */  trunc.w.s $f6, $f0
/* 1AE054 8027F774 E4460084 */  swc1      $f6, 0x84($v0)
/* 1AE058 8027F778 C6400010 */  lwc1      $f0, 0x10($s2)
/* 1AE05C 8027F77C 4600018D */  trunc.w.s $f6, $f0
/* 1AE060 8027F780 E4460088 */  swc1      $f6, 0x88($v0)
/* 1AE064 8027F784 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1AE068 8027F788 4600018D */  trunc.w.s $f6, $f0
/* 1AE06C 8027F78C E446008C */  swc1      $f6, 0x8c($v0)
/* 1AE070 8027F790 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1AE074 8027F794 24042032 */  addiu     $a0, $zero, 0x2032
/* 1AE078 8027F798 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1AE07C 8027F79C 8E46000C */  lw        $a2, 0xc($s2)
/* 1AE080 8027F7A0 8E470010 */  lw        $a3, 0x10($s2)
/* 1AE084 8027F7A4 0C052757 */  jal       sfx_play_sound_at_position
/* 1AE088 8027F7A8 0000282D */   daddu    $a1, $zero, $zero
.L8027F7AC:
/* 1AE08C 8027F7AC 8E820190 */  lw        $v0, 0x190($s4)
/* 1AE090 8027F7B0 30424000 */  andi      $v0, $v0, 0x4000
/* 1AE094 8027F7B4 10400019 */  beqz      $v0, .L8027F81C
/* 1AE098 8027F7B8 00000000 */   nop
/* 1AE09C 8027F7BC 12A00017 */  beqz      $s5, .L8027F81C
/* 1AE0A0 8027F7C0 00000000 */   nop
/* 1AE0A4 8027F7C4 3C048029 */  lui       $a0, %hi(DoFreezeHit)
/* 1AE0A8 8027F7C8 2484466C */  addiu     $a0, $a0, %lo(DoFreezeHit)
/* 1AE0AC 8027F7CC 2405000A */  addiu     $a1, $zero, 0xa
/* 1AE0B0 8027F7D0 0C0B0CF8 */  jal       start_script
/* 1AE0B4 8027F7D4 0000302D */   daddu    $a2, $zero, $zero
/* 1AE0B8 8027F7D8 C640000C */  lwc1      $f0, 0xc($s2)
/* 1AE0BC 8027F7DC 4600018D */  trunc.w.s $f6, $f0
/* 1AE0C0 8027F7E0 E4460084 */  swc1      $f6, 0x84($v0)
/* 1AE0C4 8027F7E4 C6400010 */  lwc1      $f0, 0x10($s2)
/* 1AE0C8 8027F7E8 4600018D */  trunc.w.s $f6, $f0
/* 1AE0CC 8027F7EC E4460088 */  swc1      $f6, 0x88($v0)
/* 1AE0D0 8027F7F0 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1AE0D4 8027F7F4 AC530090 */  sw        $s3, 0x90($v0)
/* 1AE0D8 8027F7F8 4600018D */  trunc.w.s $f6, $f0
/* 1AE0DC 8027F7FC E446008C */  swc1      $f6, 0x8c($v0)
/* 1AE0E0 8027F800 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1AE0E4 8027F804 240400EB */  addiu     $a0, $zero, 0xeb
/* 1AE0E8 8027F808 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1AE0EC 8027F80C 8E46000C */  lw        $a2, 0xc($s2)
/* 1AE0F0 8027F810 8E470010 */  lw        $a3, 0x10($s2)
/* 1AE0F4 8027F814 0C052757 */  jal       sfx_play_sound_at_position
/* 1AE0F8 8027F818 0000282D */   daddu    $a1, $zero, $zero
.L8027F81C:
/* 1AE0FC 8027F81C 8E820190 */  lw        $v0, 0x190($s4)
/* 1AE100 8027F820 3C030008 */  lui       $v1, 8
/* 1AE104 8027F824 00431024 */  and       $v0, $v0, $v1
/* 1AE108 8027F828 10400019 */  beqz      $v0, .L8027F890
/* 1AE10C 8027F82C 00000000 */   nop
/* 1AE110 8027F830 12A00017 */  beqz      $s5, .L8027F890
/* 1AE114 8027F834 00000000 */   nop
/* 1AE118 8027F838 3C048029 */  lui       $a0, %hi(DoShinkHit)
/* 1AE11C 8027F83C 248446B8 */  addiu     $a0, $a0, %lo(DoShinkHit)
/* 1AE120 8027F840 2405000A */  addiu     $a1, $zero, 0xa
/* 1AE124 8027F844 0C0B0CF8 */  jal       start_script
/* 1AE128 8027F848 0000302D */   daddu    $a2, $zero, $zero
/* 1AE12C 8027F84C C640000C */  lwc1      $f0, 0xc($s2)
/* 1AE130 8027F850 4600018D */  trunc.w.s $f6, $f0
/* 1AE134 8027F854 E4460084 */  swc1      $f6, 0x84($v0)
/* 1AE138 8027F858 C6400010 */  lwc1      $f0, 0x10($s2)
/* 1AE13C 8027F85C 4600018D */  trunc.w.s $f6, $f0
/* 1AE140 8027F860 E4460088 */  swc1      $f6, 0x88($v0)
/* 1AE144 8027F864 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1AE148 8027F868 AC530090 */  sw        $s3, 0x90($v0)
/* 1AE14C 8027F86C 4600018D */  trunc.w.s $f6, $f0
/* 1AE150 8027F870 E446008C */  swc1      $f6, 0x8c($v0)
/* 1AE154 8027F874 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1AE158 8027F878 24042032 */  addiu     $a0, $zero, 0x2032
/* 1AE15C 8027F87C E7A00010 */  swc1      $f0, 0x10($sp)
/* 1AE160 8027F880 8E46000C */  lw        $a2, 0xc($s2)
/* 1AE164 8027F884 8E470010 */  lw        $a3, 0x10($s2)
/* 1AE168 8027F888 0C052757 */  jal       sfx_play_sound_at_position
/* 1AE16C 8027F88C 0000282D */   daddu    $a1, $zero, $zero
.L8027F890:
/* 1AE170 8027F890 8E820188 */  lw        $v0, 0x188($s4)
/* 1AE174 8027F894 30420040 */  andi      $v0, $v0, 0x40
/* 1AE178 8027F898 1040000A */  beqz      $v0, .L8027F8C4
/* 1AE17C 8027F89C 24020093 */   addiu    $v0, $zero, 0x93
/* 1AE180 8027F8A0 92630136 */  lbu       $v1, 0x136($s3)
/* 1AE184 8027F8A4 14620007 */  bne       $v1, $v0, .L8027F8C4
/* 1AE188 8027F8A8 24040165 */   addiu    $a0, $zero, 0x165
/* 1AE18C 8027F8AC C6400014 */  lwc1      $f0, 0x14($s2)
/* 1AE190 8027F8B0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1AE194 8027F8B4 8E46000C */  lw        $a2, 0xc($s2)
/* 1AE198 8027F8B8 8E470010 */  lw        $a3, 0x10($s2)
/* 1AE19C 8027F8BC 0C052757 */  jal       sfx_play_sound_at_position
/* 1AE1A0 8027F8C0 0000282D */   daddu    $a1, $zero, $zero
.L8027F8C4:
/* 1AE1A4 8027F8C4 0C099AB7 */  jal       func_80266ADC
/* 1AE1A8 8027F8C8 0260202D */   daddu    $a0, $s3, $zero
/* 1AE1AC 8027F8CC 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 1AE1B0 8027F8D0 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 1AE1B4 8027F8D4 30420240 */  andi      $v0, $v0, 0x240
/* 1AE1B8 8027F8D8 1040000A */  beqz      $v0, .L8027F904
/* 1AE1BC 8027F8DC 00000000 */   nop
/* 1AE1C0 8027F8E0 8FA8001C */  lw        $t0, 0x1c($sp)
/* 1AE1C4 8027F8E4 15000004 */  bnez      $t0, .L8027F8F8
/* 1AE1C8 8027F8E8 24020002 */   addiu    $v0, $zero, 2
/* 1AE1CC 8027F8EC 24080001 */  addiu     $t0, $zero, 1
/* 1AE1D0 8027F8F0 AFA8001C */  sw        $t0, 0x1c($sp)
/* 1AE1D4 8027F8F4 8FA8001C */  lw        $t0, 0x1c($sp)
.L8027F8F8:
/* 1AE1D8 8027F8F8 15020002 */  bne       $t0, $v0, .L8027F904
/* 1AE1DC 8027F8FC 24080003 */   addiu    $t0, $zero, 3
/* 1AE1E0 8027F900 AFA8001C */  sw        $t0, 0x1c($sp)
.L8027F904:
/* 1AE1E4 8027F904 8FA80018 */  lw        $t0, 0x18($sp)
/* 1AE1E8 8027F908 81020212 */  lb        $v0, 0x212($t0)
/* 1AE1EC 8027F90C 2403000B */  addiu     $v1, $zero, 0xb
/* 1AE1F0 8027F910 10430021 */  beq       $v0, $v1, .L8027F998
/* 1AE1F4 8027F914 00000000 */   nop
/* 1AE1F8 8027F918 82620212 */  lb        $v0, 0x212($s3)
/* 1AE1FC 8027F91C 10430005 */  beq       $v0, $v1, .L8027F934
/* 1AE200 8027F920 00000000 */   nop
/* 1AE204 8027F924 8EC2007C */  lw        $v0, 0x7c($s6)
/* 1AE208 8027F928 30420080 */  andi      $v0, $v0, 0x80
/* 1AE20C 8027F92C 1040001A */  beqz      $v0, .L8027F998
/* 1AE210 8027F930 00000000 */   nop
.L8027F934:
/* 1AE214 8027F934 8E820188 */  lw        $v0, 0x188($s4)
/* 1AE218 8027F938 3C031000 */  lui       $v1, 0x1000
/* 1AE21C 8027F93C 00431024 */  and       $v0, $v0, $v1
/* 1AE220 8027F940 14400015 */  bnez      $v0, .L8027F998
/* 1AE224 8027F944 00000000 */   nop
/* 1AE228 8027F948 8E82018C */  lw        $v0, 0x18c($s4)
/* 1AE22C 8027F94C 30420008 */  andi      $v0, $v0, 8
/* 1AE230 8027F950 14400011 */  bnez      $v0, .L8027F998
/* 1AE234 8027F954 00000000 */   nop
.L8027F958:
/* 1AE238 8027F958 C6400014 */  lwc1      $f0, 0x14($s2)
/* 1AE23C 8027F95C 2404037B */  addiu     $a0, $zero, 0x37b
/* 1AE240 8027F960 E7A00010 */  swc1      $f0, 0x10($sp)
/* 1AE244 8027F964 8E46000C */  lw        $a2, 0xc($s2)
/* 1AE248 8027F968 8E470010 */  lw        $a3, 0x10($s2)
/* 1AE24C 8027F96C 0C052757 */  jal       sfx_play_sound_at_position
/* 1AE250 8027F970 0000282D */   daddu    $a1, $zero, $zero
/* 1AE254 8027F974 8FA40018 */  lw        $a0, 0x18($sp)
/* 1AE258 8027F978 0C09451D */  jal       func_80251474
/* 1AE25C 8027F97C 00000000 */   nop
/* 1AE260 8027F980 24040001 */  addiu     $a0, $zero, 1
/* 1AE264 8027F984 2405002F */  addiu     $a1, $zero, 0x2f
.L8027F988:
/* 1AE268 8027F988 0C09FEE7 */  jal       dispatch_damage_event_partner_1
/* 1AE26C 8027F98C 00000000 */   nop
/* 1AE270 8027F990 0809FE67 */  j         .L8027F99C
/* 1AE274 8027F994 2402FFFF */   addiu    $v0, $zero, -1
.L8027F998:
/* 1AE278 8027F998 8FA2001C */  lw        $v0, 0x1c($sp)
.L8027F99C:
/* 1AE27C 8027F99C 8FBF0054 */  lw        $ra, 0x54($sp)
/* 1AE280 8027F9A0 8FBE0050 */  lw        $fp, 0x50($sp)
/* 1AE284 8027F9A4 8FB7004C */  lw        $s7, 0x4c($sp)
/* 1AE288 8027F9A8 8FB60048 */  lw        $s6, 0x48($sp)
/* 1AE28C 8027F9AC 8FB50044 */  lw        $s5, 0x44($sp)
/* 1AE290 8027F9B0 8FB40040 */  lw        $s4, 0x40($sp)
/* 1AE294 8027F9B4 8FB3003C */  lw        $s3, 0x3c($sp)
/* 1AE298 8027F9B8 8FB20038 */  lw        $s2, 0x38($sp)
/* 1AE29C 8027F9BC 8FB10034 */  lw        $s1, 0x34($sp)
/* 1AE2A0 8027F9C0 8FB00030 */  lw        $s0, 0x30($sp)
/* 1AE2A4 8027F9C4 03E00008 */  jr        $ra
/* 1AE2A8 8027F9C8 27BD0058 */   addiu    $sp, $sp, 0x58
