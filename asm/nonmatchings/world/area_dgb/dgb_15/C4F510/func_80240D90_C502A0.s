.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D90_C502A0
/* C502A0 80240D90 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C502A4 80240D94 AFB40040 */  sw        $s4, 0x40($sp)
/* C502A8 80240D98 0080A02D */  daddu     $s4, $a0, $zero
/* C502AC 80240D9C AFBF0044 */  sw        $ra, 0x44($sp)
/* C502B0 80240DA0 AFB3003C */  sw        $s3, 0x3c($sp)
/* C502B4 80240DA4 AFB20038 */  sw        $s2, 0x38($sp)
/* C502B8 80240DA8 AFB10034 */  sw        $s1, 0x34($sp)
/* C502BC 80240DAC AFB00030 */  sw        $s0, 0x30($sp)
/* C502C0 80240DB0 8E910148 */  lw        $s1, 0x148($s4)
/* C502C4 80240DB4 00A0902D */  daddu     $s2, $a1, $zero
/* C502C8 80240DB8 86240008 */  lh        $a0, 8($s1)
/* C502CC 80240DBC 0C00EABB */  jal       get_npc_unsafe
/* C502D0 80240DC0 00C0982D */   daddu    $s3, $a2, $zero
/* C502D4 80240DC4 8E430014 */  lw        $v1, 0x14($s2)
/* C502D8 80240DC8 04600031 */  bltz      $v1, .L80240E90
/* C502DC 80240DCC 0040802D */   daddu    $s0, $v0, $zero
/* C502E0 80240DD0 0260202D */  daddu     $a0, $s3, $zero
/* C502E4 80240DD4 AFA00010 */  sw        $zero, 0x10($sp)
/* C502E8 80240DD8 8E460024 */  lw        $a2, 0x24($s2)
/* C502EC 80240DDC 8E470028 */  lw        $a3, 0x28($s2)
/* C502F0 80240DE0 0C01242D */  jal       func_800490B4
/* C502F4 80240DE4 0220282D */   daddu    $a1, $s1, $zero
/* C502F8 80240DE8 10400029 */  beqz      $v0, .L80240E90
/* C502FC 80240DEC 0000202D */   daddu    $a0, $zero, $zero
/* C50300 80240DF0 0200282D */  daddu     $a1, $s0, $zero
/* C50304 80240DF4 0000302D */  daddu     $a2, $zero, $zero
/* C50308 80240DF8 860300A8 */  lh        $v1, 0xa8($s0)
/* C5030C 80240DFC 3C013F80 */  lui       $at, 0x3f80
/* C50310 80240E00 44810000 */  mtc1      $at, $f0
/* C50314 80240E04 3C014000 */  lui       $at, 0x4000
/* C50318 80240E08 44811000 */  mtc1      $at, $f2
/* C5031C 80240E0C 3C01C1A0 */  lui       $at, 0xc1a0
/* C50320 80240E10 44812000 */  mtc1      $at, $f4
/* C50324 80240E14 2402000F */  addiu     $v0, $zero, 0xf
/* C50328 80240E18 AFA2001C */  sw        $v0, 0x1c($sp)
/* C5032C 80240E1C 44833000 */  mtc1      $v1, $f6
/* C50330 80240E20 00000000 */  nop
/* C50334 80240E24 468031A0 */  cvt.s.w   $f6, $f6
/* C50338 80240E28 44073000 */  mfc1      $a3, $f6
/* C5033C 80240E2C 27A20028 */  addiu     $v0, $sp, 0x28
/* C50340 80240E30 AFA20020 */  sw        $v0, 0x20($sp)
/* C50344 80240E34 E7A00010 */  swc1      $f0, 0x10($sp)
/* C50348 80240E38 E7A20014 */  swc1      $f2, 0x14($sp)
/* C5034C 80240E3C 0C01BFA4 */  jal       fx_emote
/* C50350 80240E40 E7A40018 */   swc1     $f4, 0x18($sp)
/* C50354 80240E44 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C50358 80240E48 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C5035C 80240E4C C60C0038 */  lwc1      $f12, 0x38($s0)
/* C50360 80240E50 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C50364 80240E54 8C460028 */  lw        $a2, 0x28($v0)
/* C50368 80240E58 0C00A720 */  jal       atan2
/* C5036C 80240E5C 8C470030 */   lw       $a3, 0x30($v0)
/* C50370 80240E60 0200202D */  daddu     $a0, $s0, $zero
/* C50374 80240E64 240502F4 */  addiu     $a1, $zero, 0x2f4
/* C50378 80240E68 3C060020 */  lui       $a2, 0x20
/* C5037C 80240E6C 0C012530 */  jal       func_800494C0
/* C50380 80240E70 E480000C */   swc1     $f0, 0xc($a0)
/* C50384 80240E74 8E220018 */  lw        $v0, 0x18($s1)
/* C50388 80240E78 9442002A */  lhu       $v0, 0x2a($v0)
/* C5038C 80240E7C 30420001 */  andi      $v0, $v0, 1
/* C50390 80240E80 14400029 */  bnez      $v0, .L80240F28
/* C50394 80240E84 2402000A */   addiu    $v0, $zero, 0xa
/* C50398 80240E88 080903CA */  j         .L80240F28
/* C5039C 80240E8C 2402000C */   addiu    $v0, $zero, 0xc
.L80240E90:
/* C503A0 80240E90 8602008C */  lh        $v0, 0x8c($s0)
/* C503A4 80240E94 14400025 */  bnez      $v0, .L80240F2C
/* C503A8 80240E98 00000000 */   nop
/* C503AC 80240E9C 9602008E */  lhu       $v0, 0x8e($s0)
/* C503B0 80240EA0 2442FFFF */  addiu     $v0, $v0, -1
/* C503B4 80240EA4 A602008E */  sh        $v0, 0x8e($s0)
/* C503B8 80240EA8 00021400 */  sll       $v0, $v0, 0x10
/* C503BC 80240EAC 1440001F */  bnez      $v0, .L80240F2C
/* C503C0 80240EB0 00000000 */   nop
/* C503C4 80240EB4 8E820074 */  lw        $v0, 0x74($s4)
/* C503C8 80240EB8 2442FFFF */  addiu     $v0, $v0, -1
/* C503CC 80240EBC 10400019 */  beqz      $v0, .L80240F24
/* C503D0 80240EC0 AE820074 */   sw       $v0, 0x74($s4)
/* C503D4 80240EC4 8E220018 */  lw        $v0, 0x18($s1)
/* C503D8 80240EC8 9442002A */  lhu       $v0, 0x2a($v0)
/* C503DC 80240ECC 30420010 */  andi      $v0, $v0, 0x10
/* C503E0 80240ED0 14400007 */  bnez      $v0, .L80240EF0
/* C503E4 80240ED4 00000000 */   nop
/* C503E8 80240ED8 C600000C */  lwc1      $f0, 0xc($s0)
/* C503EC 80240EDC 3C014334 */  lui       $at, 0x4334
/* C503F0 80240EE0 44816000 */  mtc1      $at, $f12
/* C503F4 80240EE4 0C00A6C9 */  jal       clamp_angle
/* C503F8 80240EE8 460C0300 */   add.s    $f12, $f0, $f12
/* C503FC 80240EEC E600000C */  swc1      $f0, 0xc($s0)
.L80240EF0:
/* C50400 80240EF0 8E440008 */  lw        $a0, 8($s2)
/* C50404 80240EF4 000417C2 */  srl       $v0, $a0, 0x1f
/* C50408 80240EF8 00822021 */  addu      $a0, $a0, $v0
/* C5040C 80240EFC 00042043 */  sra       $a0, $a0, 1
/* C50410 80240F00 0C00A67F */  jal       rand_int
/* C50414 80240F04 24840001 */   addiu    $a0, $a0, 1
/* C50418 80240F08 8E430008 */  lw        $v1, 8($s2)
/* C5041C 80240F0C 000327C2 */  srl       $a0, $v1, 0x1f
/* C50420 80240F10 00641821 */  addu      $v1, $v1, $a0
/* C50424 80240F14 00031843 */  sra       $v1, $v1, 1
/* C50428 80240F18 00621821 */  addu      $v1, $v1, $v0
/* C5042C 80240F1C 080903CB */  j         .L80240F2C
/* C50430 80240F20 A603008E */   sh       $v1, 0x8e($s0)
.L80240F24:
/* C50434 80240F24 24020004 */  addiu     $v0, $zero, 4
.L80240F28:
/* C50438 80240F28 AE820070 */  sw        $v0, 0x70($s4)
.L80240F2C:
/* C5043C 80240F2C 8FBF0044 */  lw        $ra, 0x44($sp)
/* C50440 80240F30 8FB40040 */  lw        $s4, 0x40($sp)
/* C50444 80240F34 8FB3003C */  lw        $s3, 0x3c($sp)
/* C50448 80240F38 8FB20038 */  lw        $s2, 0x38($sp)
/* C5044C 80240F3C 8FB10034 */  lw        $s1, 0x34($sp)
/* C50450 80240F40 8FB00030 */  lw        $s0, 0x30($sp)
/* C50454 80240F44 03E00008 */  jr        $ra
/* C50458 80240F48 27BD0048 */   addiu    $sp, $sp, 0x48
