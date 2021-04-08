.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel trd_02_UnkFunc14
/* 9A1D54 80240D74 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 9A1D58 80240D78 AFB40040 */  sw        $s4, 0x40($sp)
/* 9A1D5C 80240D7C 0080A02D */  daddu     $s4, $a0, $zero
/* 9A1D60 80240D80 AFBF0044 */  sw        $ra, 0x44($sp)
/* 9A1D64 80240D84 AFB3003C */  sw        $s3, 0x3c($sp)
/* 9A1D68 80240D88 AFB20038 */  sw        $s2, 0x38($sp)
/* 9A1D6C 80240D8C AFB10034 */  sw        $s1, 0x34($sp)
/* 9A1D70 80240D90 AFB00030 */  sw        $s0, 0x30($sp)
/* 9A1D74 80240D94 8E910148 */  lw        $s1, 0x148($s4)
/* 9A1D78 80240D98 00A0902D */  daddu     $s2, $a1, $zero
/* 9A1D7C 80240D9C 86240008 */  lh        $a0, 8($s1)
/* 9A1D80 80240DA0 0C00EABB */  jal       get_npc_unsafe
/* 9A1D84 80240DA4 00C0982D */   daddu    $s3, $a2, $zero
/* 9A1D88 80240DA8 8E430014 */  lw        $v1, 0x14($s2)
/* 9A1D8C 80240DAC 04600031 */  bltz      $v1, .L80240E74
/* 9A1D90 80240DB0 0040802D */   daddu    $s0, $v0, $zero
/* 9A1D94 80240DB4 0260202D */  daddu     $a0, $s3, $zero
/* 9A1D98 80240DB8 AFA00010 */  sw        $zero, 0x10($sp)
/* 9A1D9C 80240DBC 8E460024 */  lw        $a2, 0x24($s2)
/* 9A1DA0 80240DC0 8E470028 */  lw        $a3, 0x28($s2)
/* 9A1DA4 80240DC4 0C01242D */  jal       func_800490B4
/* 9A1DA8 80240DC8 0220282D */   daddu    $a1, $s1, $zero
/* 9A1DAC 80240DCC 10400029 */  beqz      $v0, .L80240E74
/* 9A1DB0 80240DD0 0000202D */   daddu    $a0, $zero, $zero
/* 9A1DB4 80240DD4 0200282D */  daddu     $a1, $s0, $zero
/* 9A1DB8 80240DD8 0000302D */  daddu     $a2, $zero, $zero
/* 9A1DBC 80240DDC 860300A8 */  lh        $v1, 0xa8($s0)
/* 9A1DC0 80240DE0 3C013F80 */  lui       $at, 0x3f80
/* 9A1DC4 80240DE4 44810000 */  mtc1      $at, $f0
/* 9A1DC8 80240DE8 3C014000 */  lui       $at, 0x4000
/* 9A1DCC 80240DEC 44811000 */  mtc1      $at, $f2
/* 9A1DD0 80240DF0 3C01C1A0 */  lui       $at, 0xc1a0
/* 9A1DD4 80240DF4 44812000 */  mtc1      $at, $f4
/* 9A1DD8 80240DF8 2402000F */  addiu     $v0, $zero, 0xf
/* 9A1DDC 80240DFC AFA2001C */  sw        $v0, 0x1c($sp)
/* 9A1DE0 80240E00 44833000 */  mtc1      $v1, $f6
/* 9A1DE4 80240E04 00000000 */  nop
/* 9A1DE8 80240E08 468031A0 */  cvt.s.w   $f6, $f6
/* 9A1DEC 80240E0C 44073000 */  mfc1      $a3, $f6
/* 9A1DF0 80240E10 27A20028 */  addiu     $v0, $sp, 0x28
/* 9A1DF4 80240E14 AFA20020 */  sw        $v0, 0x20($sp)
/* 9A1DF8 80240E18 E7A00010 */  swc1      $f0, 0x10($sp)
/* 9A1DFC 80240E1C E7A20014 */  swc1      $f2, 0x14($sp)
/* 9A1E00 80240E20 0C01BFA4 */  jal       fx_emote
/* 9A1E04 80240E24 E7A40018 */   swc1     $f4, 0x18($sp)
/* 9A1E08 80240E28 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 9A1E0C 80240E2C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 9A1E10 80240E30 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9A1E14 80240E34 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9A1E18 80240E38 8C460028 */  lw        $a2, 0x28($v0)
/* 9A1E1C 80240E3C 0C00A720 */  jal       atan2
/* 9A1E20 80240E40 8C470030 */   lw       $a3, 0x30($v0)
/* 9A1E24 80240E44 0200202D */  daddu     $a0, $s0, $zero
/* 9A1E28 80240E48 240502F4 */  addiu     $a1, $zero, 0x2f4
/* 9A1E2C 80240E4C 3C060020 */  lui       $a2, 0x20
/* 9A1E30 80240E50 0C012530 */  jal       func_800494C0
/* 9A1E34 80240E54 E480000C */   swc1     $f0, 0xc($a0)
/* 9A1E38 80240E58 8E220018 */  lw        $v0, 0x18($s1)
/* 9A1E3C 80240E5C 9442002A */  lhu       $v0, 0x2a($v0)
/* 9A1E40 80240E60 30420001 */  andi      $v0, $v0, 1
/* 9A1E44 80240E64 14400029 */  bnez      $v0, .L80240F0C
/* 9A1E48 80240E68 2402000A */   addiu    $v0, $zero, 0xa
/* 9A1E4C 80240E6C 080903C3 */  j         .L80240F0C
/* 9A1E50 80240E70 2402000C */   addiu    $v0, $zero, 0xc
.L80240E74:
/* 9A1E54 80240E74 8602008C */  lh        $v0, 0x8c($s0)
/* 9A1E58 80240E78 14400025 */  bnez      $v0, .L80240F10
/* 9A1E5C 80240E7C 00000000 */   nop
/* 9A1E60 80240E80 9602008E */  lhu       $v0, 0x8e($s0)
/* 9A1E64 80240E84 2442FFFF */  addiu     $v0, $v0, -1
/* 9A1E68 80240E88 A602008E */  sh        $v0, 0x8e($s0)
/* 9A1E6C 80240E8C 00021400 */  sll       $v0, $v0, 0x10
/* 9A1E70 80240E90 1440001F */  bnez      $v0, .L80240F10
/* 9A1E74 80240E94 00000000 */   nop
/* 9A1E78 80240E98 8E820074 */  lw        $v0, 0x74($s4)
/* 9A1E7C 80240E9C 2442FFFF */  addiu     $v0, $v0, -1
/* 9A1E80 80240EA0 10400019 */  beqz      $v0, .L80240F08
/* 9A1E84 80240EA4 AE820074 */   sw       $v0, 0x74($s4)
/* 9A1E88 80240EA8 8E220018 */  lw        $v0, 0x18($s1)
/* 9A1E8C 80240EAC 9442002A */  lhu       $v0, 0x2a($v0)
/* 9A1E90 80240EB0 30420010 */  andi      $v0, $v0, 0x10
/* 9A1E94 80240EB4 14400007 */  bnez      $v0, .L80240ED4
/* 9A1E98 80240EB8 00000000 */   nop
/* 9A1E9C 80240EBC C600000C */  lwc1      $f0, 0xc($s0)
/* 9A1EA0 80240EC0 3C014334 */  lui       $at, 0x4334
/* 9A1EA4 80240EC4 44816000 */  mtc1      $at, $f12
/* 9A1EA8 80240EC8 0C00A6C9 */  jal       clamp_angle
/* 9A1EAC 80240ECC 460C0300 */   add.s    $f12, $f0, $f12
/* 9A1EB0 80240ED0 E600000C */  swc1      $f0, 0xc($s0)
.L80240ED4:
/* 9A1EB4 80240ED4 8E440008 */  lw        $a0, 8($s2)
/* 9A1EB8 80240ED8 000417C2 */  srl       $v0, $a0, 0x1f
/* 9A1EBC 80240EDC 00822021 */  addu      $a0, $a0, $v0
/* 9A1EC0 80240EE0 00042043 */  sra       $a0, $a0, 1
/* 9A1EC4 80240EE4 0C00A67F */  jal       rand_int
/* 9A1EC8 80240EE8 24840001 */   addiu    $a0, $a0, 1
/* 9A1ECC 80240EEC 8E430008 */  lw        $v1, 8($s2)
/* 9A1ED0 80240EF0 000327C2 */  srl       $a0, $v1, 0x1f
/* 9A1ED4 80240EF4 00641821 */  addu      $v1, $v1, $a0
/* 9A1ED8 80240EF8 00031843 */  sra       $v1, $v1, 1
/* 9A1EDC 80240EFC 00621821 */  addu      $v1, $v1, $v0
/* 9A1EE0 80240F00 080903C4 */  j         .L80240F10
/* 9A1EE4 80240F04 A603008E */   sh       $v1, 0x8e($s0)
.L80240F08:
/* 9A1EE8 80240F08 24020004 */  addiu     $v0, $zero, 4
.L80240F0C:
/* 9A1EEC 80240F0C AE820070 */  sw        $v0, 0x70($s4)
.L80240F10:
/* 9A1EF0 80240F10 8FBF0044 */  lw        $ra, 0x44($sp)
/* 9A1EF4 80240F14 8FB40040 */  lw        $s4, 0x40($sp)
/* 9A1EF8 80240F18 8FB3003C */  lw        $s3, 0x3c($sp)
/* 9A1EFC 80240F1C 8FB20038 */  lw        $s2, 0x38($sp)
/* 9A1F00 80240F20 8FB10034 */  lw        $s1, 0x34($sp)
/* 9A1F04 80240F24 8FB00030 */  lw        $s0, 0x30($sp)
/* 9A1F08 80240F28 03E00008 */  jr        $ra
/* 9A1F0C 80240F2C 27BD0048 */   addiu    $sp, $sp, 0x48
