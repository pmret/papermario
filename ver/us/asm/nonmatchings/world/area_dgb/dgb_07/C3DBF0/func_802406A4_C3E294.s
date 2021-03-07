.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406A4_C3E294
/* C3E294 802406A4 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C3E298 802406A8 AFB40048 */  sw        $s4, 0x48($sp)
/* C3E29C 802406AC 0080A02D */  daddu     $s4, $a0, $zero
/* C3E2A0 802406B0 AFBF004C */  sw        $ra, 0x4c($sp)
/* C3E2A4 802406B4 AFB30044 */  sw        $s3, 0x44($sp)
/* C3E2A8 802406B8 AFB20040 */  sw        $s2, 0x40($sp)
/* C3E2AC 802406BC AFB1003C */  sw        $s1, 0x3c($sp)
/* C3E2B0 802406C0 AFB00038 */  sw        $s0, 0x38($sp)
/* C3E2B4 802406C4 8E930148 */  lw        $s3, 0x148($s4)
/* C3E2B8 802406C8 00C0802D */  daddu     $s0, $a2, $zero
/* C3E2BC 802406CC 86640008 */  lh        $a0, 8($s3)
/* C3E2C0 802406D0 0C00EABB */  jal       get_npc_unsafe
/* C3E2C4 802406D4 0000902D */   daddu    $s2, $zero, $zero
/* C3E2C8 802406D8 0C039D59 */  jal       get_player_data
/* C3E2CC 802406DC 0040882D */   daddu    $s1, $v0, $zero
/* C3E2D0 802406E0 0200202D */  daddu     $a0, $s0, $zero
/* C3E2D4 802406E4 0260282D */  daddu     $a1, $s3, $zero
/* C3E2D8 802406E8 0000382D */  daddu     $a3, $zero, $zero
/* C3E2DC 802406EC 3C0642A0 */  lui       $a2, 0x42a0
/* C3E2E0 802406F0 0040802D */  daddu     $s0, $v0, $zero
/* C3E2E4 802406F4 0C01242D */  jal       func_800490B4
/* C3E2E8 802406F8 AFA00010 */   sw       $zero, 0x10($sp)
/* C3E2EC 802406FC 10400022 */  beqz      $v0, .L80240788
/* C3E2F0 80240700 00000000 */   nop
/* C3E2F4 80240704 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C3E2F8 80240708 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C3E2FC 8024070C 804300B4 */  lb        $v1, 0xb4($v0)
/* C3E300 80240710 24020002 */  addiu     $v0, $zero, 2
/* C3E304 80240714 10620013 */  beq       $v1, $v0, .L80240764
/* C3E308 80240718 2402001A */   addiu    $v0, $zero, 0x1a
/* C3E30C 8024071C 10620011 */  beq       $v1, $v0, .L80240764
/* C3E310 80240720 24020003 */   addiu    $v0, $zero, 3
/* C3E314 80240724 1062000F */  beq       $v1, $v0, .L80240764
/* C3E318 80240728 2402000E */   addiu    $v0, $zero, 0xe
/* C3E31C 8024072C 1062000D */  beq       $v1, $v0, .L80240764
/* C3E320 80240730 24020010 */   addiu    $v0, $zero, 0x10
/* C3E324 80240734 1062000B */  beq       $v1, $v0, .L80240764
/* C3E328 80240738 2402000B */   addiu    $v0, $zero, 0xb
/* C3E32C 8024073C 10620009 */  beq       $v1, $v0, .L80240764
/* C3E330 80240740 2402000A */   addiu    $v0, $zero, 0xa
/* C3E334 80240744 10620007 */  beq       $v1, $v0, .L80240764
/* C3E338 80240748 24020012 */   addiu    $v0, $zero, 0x12
/* C3E33C 8024074C 10620005 */  beq       $v1, $v0, .L80240764
/* C3E340 80240750 24020013 */   addiu    $v0, $zero, 0x13
/* C3E344 80240754 10620003 */  beq       $v1, $v0, .L80240764
/* C3E348 80240758 24020025 */   addiu    $v0, $zero, 0x25
/* C3E34C 8024075C 14620002 */  bne       $v1, $v0, .L80240768
/* C3E350 80240760 00000000 */   nop
.L80240764:
/* C3E354 80240764 24120001 */  addiu     $s2, $zero, 1
.L80240768:
/* C3E358 80240768 82030012 */  lb        $v1, 0x12($s0)
/* C3E35C 8024076C 24020002 */  addiu     $v0, $zero, 2
/* C3E360 80240770 14620007 */  bne       $v1, $v0, .L80240790
/* C3E364 80240774 24020001 */   addiu    $v0, $zero, 1
/* C3E368 80240778 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* C3E36C 8024077C 8042EBB0 */  lb        $v0, %lo(D_8010EBB0)($v0)
/* C3E370 80240780 50430002 */  beql      $v0, $v1, .L8024078C
/* C3E374 80240784 24120001 */   addiu    $s2, $zero, 1
.L80240788:
/* C3E378 80240788 82030012 */  lb        $v1, 0x12($s0)
.L8024078C:
/* C3E37C 8024078C 24020001 */  addiu     $v0, $zero, 1
.L80240790:
/* C3E380 80240790 14620006 */  bne       $v1, $v0, .L802407AC
/* C3E384 80240794 24020003 */   addiu    $v0, $zero, 3
/* C3E388 80240798 3C028011 */  lui       $v0, %hi(D_8010EBB0)
/* C3E38C 8024079C 8042EBB0 */  lb        $v0, %lo(D_8010EBB0)($v0)
/* C3E390 802407A0 14400008 */  bnez      $v0, .L802407C4
/* C3E394 802407A4 27A40028 */   addiu    $a0, $sp, 0x28
/* C3E398 802407A8 24020003 */  addiu     $v0, $zero, 3
.L802407AC:
/* C3E39C 802407AC 1462001B */  bne       $v1, $v0, .L8024081C
/* C3E3A0 802407B0 24020002 */   addiu    $v0, $zero, 2
/* C3E3A4 802407B4 3C038011 */  lui       $v1, %hi(D_8010EBB0)
/* C3E3A8 802407B8 8063EBB0 */  lb        $v1, %lo(D_8010EBB0)($v1)
/* C3E3AC 802407BC 14620017 */  bne       $v1, $v0, .L8024081C
/* C3E3B0 802407C0 27A40028 */   addiu    $a0, $sp, 0x28
.L802407C4:
/* C3E3B4 802407C4 27A5002C */  addiu     $a1, $sp, 0x2c
/* C3E3B8 802407C8 8E27000C */  lw        $a3, 0xc($s1)
/* C3E3BC 802407CC C6200038 */  lwc1      $f0, 0x38($s1)
/* C3E3C0 802407D0 C6220040 */  lwc1      $f2, 0x40($s1)
/* C3E3C4 802407D4 0000302D */  daddu     $a2, $zero, $zero
/* C3E3C8 802407D8 E7A00028 */  swc1      $f0, 0x28($sp)
/* C3E3CC 802407DC 0C00A7E7 */  jal       add_vec2D_polar
/* C3E3D0 802407E0 E7A2002C */   swc1     $f2, 0x2c($sp)
/* C3E3D4 802407E4 3C028011 */  lui       $v0, %hi(wPartnerNpc)
/* C3E3D8 802407E8 8C42C930 */  lw        $v0, %lo(wPartnerNpc)($v0)
/* C3E3DC 802407EC C7AC0028 */  lwc1      $f12, 0x28($sp)
/* C3E3E0 802407F0 C7AE002C */  lwc1      $f14, 0x2c($sp)
/* C3E3E4 802407F4 8C460038 */  lw        $a2, 0x38($v0)
/* C3E3E8 802407F8 0C00A7B5 */  jal       dist2D
/* C3E3EC 802407FC 8C470040 */   lw       $a3, 0x40($v0)
/* C3E3F0 80240800 3C0142A0 */  lui       $at, 0x42a0
/* C3E3F4 80240804 44811000 */  mtc1      $at, $f2
/* C3E3F8 80240808 00000000 */  nop
/* C3E3FC 8024080C 4602003E */  c.le.s    $f0, $f2
/* C3E400 80240810 00000000 */  nop
/* C3E404 80240814 45030001 */  bc1tl     .L8024081C
/* C3E408 80240818 24120001 */   addiu    $s2, $zero, 1
.L8024081C:
/* C3E40C 8024081C 12400026 */  beqz      $s2, .L802408B8
/* C3E410 80240820 0220202D */   daddu    $a0, $s1, $zero
/* C3E414 80240824 3C05B000 */  lui       $a1, 0xb000
/* C3E418 80240828 34A5000E */  ori       $a1, $a1, 0xe
/* C3E41C 8024082C 0C012530 */  jal       func_800494C0
/* C3E420 80240830 0000302D */   daddu    $a2, $zero, $zero
/* C3E424 80240834 0000202D */  daddu     $a0, $zero, $zero
/* C3E428 80240838 0220282D */  daddu     $a1, $s1, $zero
/* C3E42C 8024083C 0000302D */  daddu     $a2, $zero, $zero
/* C3E430 80240840 862200A8 */  lh        $v0, 0xa8($s1)
/* C3E434 80240844 8E6300CC */  lw        $v1, 0xcc($s3)
/* C3E438 80240848 3C013F80 */  lui       $at, 0x3f80
/* C3E43C 8024084C 44810000 */  mtc1      $at, $f0
/* C3E440 80240850 3C014000 */  lui       $at, 0x4000
/* C3E444 80240854 44811000 */  mtc1      $at, $f2
/* C3E448 80240858 3C01C1A0 */  lui       $at, 0xc1a0
/* C3E44C 8024085C 44812000 */  mtc1      $at, $f4
/* C3E450 80240860 44823000 */  mtc1      $v0, $f6
/* C3E454 80240864 00000000 */  nop
/* C3E458 80240868 468031A0 */  cvt.s.w   $f6, $f6
/* C3E45C 8024086C 44073000 */  mfc1      $a3, $f6
/* C3E460 80240870 8C63002C */  lw        $v1, 0x2c($v1)
/* C3E464 80240874 2402000A */  addiu     $v0, $zero, 0xa
/* C3E468 80240878 A622008E */  sh        $v0, 0x8e($s1)
/* C3E46C 8024087C 2402000F */  addiu     $v0, $zero, 0xf
/* C3E470 80240880 AE230028 */  sw        $v1, 0x28($s1)
/* C3E474 80240884 AFA2001C */  sw        $v0, 0x1c($sp)
/* C3E478 80240888 27A20030 */  addiu     $v0, $sp, 0x30
/* C3E47C 8024088C E7A00010 */  swc1      $f0, 0x10($sp)
/* C3E480 80240890 E7A20014 */  swc1      $f2, 0x14($sp)
/* C3E484 80240894 E7A40018 */  swc1      $f4, 0x18($sp)
/* C3E488 80240898 0C01BFA4 */  jal       fx_emote
/* C3E48C 8024089C AFA20020 */   sw       $v0, 0x20($sp)
/* C3E490 802408A0 0220202D */  daddu     $a0, $s1, $zero
/* C3E494 802408A4 240502F4 */  addiu     $a1, $zero, 0x2f4
/* C3E498 802408A8 0C012530 */  jal       func_800494C0
/* C3E49C 802408AC 3C060020 */   lui      $a2, 0x20
/* C3E4A0 802408B0 24020002 */  addiu     $v0, $zero, 2
/* C3E4A4 802408B4 AE820070 */  sw        $v0, 0x70($s4)
.L802408B8:
/* C3E4A8 802408B8 9622008E */  lhu       $v0, 0x8e($s1)
/* C3E4AC 802408BC 24420001 */  addiu     $v0, $v0, 1
/* C3E4B0 802408C0 A622008E */  sh        $v0, 0x8e($s1)
/* C3E4B4 802408C4 00021400 */  sll       $v0, $v0, 0x10
/* C3E4B8 802408C8 00021C03 */  sra       $v1, $v0, 0x10
/* C3E4BC 802408CC 2402001B */  addiu     $v0, $zero, 0x1b
/* C3E4C0 802408D0 14620005 */  bne       $v1, $v0, .L802408E8
/* C3E4C4 802408D4 24020039 */   addiu    $v0, $zero, 0x39
/* C3E4C8 802408D8 0220202D */  daddu     $a0, $s1, $zero
/* C3E4CC 802408DC 3C05B000 */  lui       $a1, 0xb000
/* C3E4D0 802408E0 0809023F */  j         .L802408FC
/* C3E4D4 802408E4 34A5000C */   ori      $a1, $a1, 0xc
.L802408E8:
/* C3E4D8 802408E8 14620008 */  bne       $v1, $v0, .L8024090C
/* C3E4DC 802408EC 2402003B */   addiu    $v0, $zero, 0x3b
/* C3E4E0 802408F0 0220202D */  daddu     $a0, $s1, $zero
/* C3E4E4 802408F4 3C05B000 */  lui       $a1, 0xb000
/* C3E4E8 802408F8 34A5000D */  ori       $a1, $a1, 0xd
.L802408FC:
/* C3E4EC 802408FC 0C012530 */  jal       func_800494C0
/* C3E4F0 80240900 0000302D */   daddu    $a2, $zero, $zero
/* C3E4F4 80240904 0809024F */  j         .L8024093C
/* C3E4F8 80240908 00000000 */   nop
.L8024090C:
/* C3E4FC 8024090C 14620005 */  bne       $v1, $v0, .L80240924
/* C3E500 80240910 2402003C */   addiu    $v0, $zero, 0x3c
/* C3E504 80240914 8E6200CC */  lw        $v0, 0xcc($s3)
/* C3E508 80240918 8C420030 */  lw        $v0, 0x30($v0)
/* C3E50C 8024091C 0809024F */  j         .L8024093C
/* C3E510 80240920 AE220028 */   sw       $v0, 0x28($s1)
.L80240924:
/* C3E514 80240924 14620005 */  bne       $v1, $v0, .L8024093C
/* C3E518 80240928 00000000 */   nop
/* C3E51C 8024092C 8E6200CC */  lw        $v0, 0xcc($s3)
/* C3E520 80240930 8C420028 */  lw        $v0, 0x28($v0)
/* C3E524 80240934 A620008E */  sh        $zero, 0x8e($s1)
/* C3E528 80240938 AE220028 */  sw        $v0, 0x28($s1)
.L8024093C:
/* C3E52C 8024093C 8FBF004C */  lw        $ra, 0x4c($sp)
/* C3E530 80240940 8FB40048 */  lw        $s4, 0x48($sp)
/* C3E534 80240944 8FB30044 */  lw        $s3, 0x44($sp)
/* C3E538 80240948 8FB20040 */  lw        $s2, 0x40($sp)
/* C3E53C 8024094C 8FB1003C */  lw        $s1, 0x3c($sp)
/* C3E540 80240950 8FB00038 */  lw        $s0, 0x38($sp)
/* C3E544 80240954 03E00008 */  jr        $ra
/* C3E548 80240958 27BD0050 */   addiu    $sp, $sp, 0x50
