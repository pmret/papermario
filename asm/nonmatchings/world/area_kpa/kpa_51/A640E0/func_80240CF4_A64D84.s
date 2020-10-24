.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CF4_A64D84
/* A64D84 80240CF4 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* A64D88 80240CF8 AFB40048 */  sw        $s4, 0x48($sp)
/* A64D8C 80240CFC 0080A02D */  daddu     $s4, $a0, $zero
/* A64D90 80240D00 AFBF004C */  sw        $ra, 0x4c($sp)
/* A64D94 80240D04 AFB30044 */  sw        $s3, 0x44($sp)
/* A64D98 80240D08 AFB20040 */  sw        $s2, 0x40($sp)
/* A64D9C 80240D0C AFB1003C */  sw        $s1, 0x3c($sp)
/* A64DA0 80240D10 AFB00038 */  sw        $s0, 0x38($sp)
/* A64DA4 80240D14 F7B40050 */  sdc1      $f20, 0x50($sp)
/* A64DA8 80240D18 8E910148 */  lw        $s1, 0x148($s4)
/* A64DAC 80240D1C 00A0902D */  daddu     $s2, $a1, $zero
/* A64DB0 80240D20 86240008 */  lh        $a0, 8($s1)
/* A64DB4 80240D24 0C00EABB */  jal       get_npc_unsafe
/* A64DB8 80240D28 00C0982D */   daddu    $s3, $a2, $zero
/* A64DBC 80240D2C 0040802D */  daddu     $s0, $v0, $zero
/* A64DC0 80240D30 9602008E */  lhu       $v0, 0x8e($s0)
/* A64DC4 80240D34 2442FFFF */  addiu     $v0, $v0, -1
/* A64DC8 80240D38 A602008E */  sh        $v0, 0x8e($s0)
/* A64DCC 80240D3C 00021400 */  sll       $v0, $v0, 0x10
/* A64DD0 80240D40 14400021 */  bnez      $v0, .L80240DC8
/* A64DD4 80240D44 0280202D */   daddu    $a0, $s4, $zero
/* A64DD8 80240D48 24040002 */  addiu     $a0, $zero, 2
/* A64DDC 80240D4C 0200282D */  daddu     $a1, $s0, $zero
/* A64DE0 80240D50 0000302D */  daddu     $a2, $zero, $zero
/* A64DE4 80240D54 8E2200CC */  lw        $v0, 0xcc($s1)
/* A64DE8 80240D58 3C013F80 */  lui       $at, 0x3f80
/* A64DEC 80240D5C 44810000 */  mtc1      $at, $f0
/* A64DF0 80240D60 3C014000 */  lui       $at, 0x4000
/* A64DF4 80240D64 44811000 */  mtc1      $at, $f2
/* A64DF8 80240D68 8C430000 */  lw        $v1, ($v0)
/* A64DFC 80240D6C 860200A8 */  lh        $v0, 0xa8($s0)
/* A64E00 80240D70 3C01C1A0 */  lui       $at, 0xc1a0
/* A64E04 80240D74 44812000 */  mtc1      $at, $f4
/* A64E08 80240D78 44824000 */  mtc1      $v0, $f8
/* A64E0C 80240D7C 00000000 */  nop       
/* A64E10 80240D80 46804220 */  cvt.s.w   $f8, $f8
/* A64E14 80240D84 44074000 */  mfc1      $a3, $f8
/* A64E18 80240D88 2402000C */  addiu     $v0, $zero, 0xc
/* A64E1C 80240D8C AE030028 */  sw        $v1, 0x28($s0)
/* A64E20 80240D90 AFA2001C */  sw        $v0, 0x1c($sp)
/* A64E24 80240D94 27A20028 */  addiu     $v0, $sp, 0x28
/* A64E28 80240D98 E7A00010 */  swc1      $f0, 0x10($sp)
/* A64E2C 80240D9C E7A20014 */  swc1      $f2, 0x14($sp)
/* A64E30 80240DA0 E7A40018 */  swc1      $f4, 0x18($sp)
/* A64E34 80240DA4 0C01BFA4 */  jal       fx_emote
/* A64E38 80240DA8 AFA20020 */   sw       $v0, 0x20($sp)
/* A64E3C 80240DAC 8E2200CC */  lw        $v0, 0xcc($s1)
/* A64E40 80240DB0 8C430000 */  lw        $v1, ($v0)
/* A64E44 80240DB4 2402000F */  addiu     $v0, $zero, 0xf
/* A64E48 80240DB8 A602008E */  sh        $v0, 0x8e($s0)
/* A64E4C 80240DBC AE030028 */  sw        $v1, 0x28($s0)
/* A64E50 80240DC0 080903A4 */  j         .L80240E90
/* A64E54 80240DC4 AE800070 */   sw       $zero, 0x70($s4)
.L80240DC8:
/* A64E58 80240DC8 8E450024 */  lw        $a1, 0x24($s2)
/* A64E5C 80240DCC 8E460028 */  lw        $a2, 0x28($s2)
/* A64E60 80240DD0 0C090014 */  jal       func_80240050_A640E0
/* A64E64 80240DD4 0260382D */   daddu    $a3, $s3, $zero
/* A64E68 80240DD8 24030001 */  addiu     $v1, $zero, 1
/* A64E6C 80240DDC 1443002C */  bne       $v0, $v1, .L80240E90
/* A64E70 80240DE0 0200202D */   daddu    $a0, $s0, $zero
/* A64E74 80240DE4 240520D4 */  addiu     $a1, $zero, 0x20d4
/* A64E78 80240DE8 0C012530 */  jal       func_800494C0
/* A64E7C 80240DEC 0000302D */   daddu    $a2, $zero, $zero
/* A64E80 80240DF0 27A4002C */  addiu     $a0, $sp, 0x2c
/* A64E84 80240DF4 27A50030 */  addiu     $a1, $sp, 0x30
/* A64E88 80240DF8 3C064188 */  lui       $a2, 0x4188
/* A64E8C 80240DFC C6020034 */  lwc1      $f2, 0x34($s0)
/* A64E90 80240E00 3C014387 */  lui       $at, 0x4387
/* A64E94 80240E04 44810000 */  mtc1      $at, $f0
/* A64E98 80240E08 8E2200CC */  lw        $v0, 0xcc($s1)
/* A64E9C 80240E0C C614003C */  lwc1      $f20, 0x3c($s0)
/* A64EA0 80240E10 46020001 */  sub.s     $f0, $f0, $f2
/* A64EA4 80240E14 3C014200 */  lui       $at, 0x4200
/* A64EA8 80240E18 44812000 */  mtc1      $at, $f4
/* A64EAC 80240E1C C6060038 */  lwc1      $f6, 0x38($s0)
/* A64EB0 80240E20 4604A500 */  add.s     $f20, $f20, $f4
/* A64EB4 80240E24 3C013F80 */  lui       $at, 0x3f80
/* A64EB8 80240E28 44811000 */  mtc1      $at, $f2
/* A64EBC 80240E2C 44070000 */  mfc1      $a3, $f0
/* A64EC0 80240E30 C6000040 */  lwc1      $f0, 0x40($s0)
/* A64EC4 80240E34 8C420020 */  lw        $v0, 0x20($v0)
/* A64EC8 80240E38 46020000 */  add.s     $f0, $f0, $f2
/* A64ECC 80240E3C E7A6002C */  swc1      $f6, 0x2c($sp)
/* A64ED0 80240E40 AE020028 */  sw        $v0, 0x28($s0)
/* A64ED4 80240E44 0C00A7E7 */  jal       add_vec2D_polar
/* A64ED8 80240E48 E7A00030 */   swc1     $f0, 0x30($sp)
/* A64EDC 80240E4C 0000202D */  daddu     $a0, $zero, $zero
/* A64EE0 80240E50 4406A000 */  mfc1      $a2, $f20
/* A64EE4 80240E54 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* A64EE8 80240E58 C7A20030 */  lwc1      $f2, 0x30($sp)
/* A64EEC 80240E5C 44050000 */  mfc1      $a1, $f0
/* A64EF0 80240E60 44071000 */  mfc1      $a3, $f2
/* A64EF4 80240E64 3C013DCC */  lui       $at, 0x3dcc
/* A64EF8 80240E68 3421CCCD */  ori       $at, $at, 0xcccd
/* A64EFC 80240E6C 44810000 */  mtc1      $at, $f0
/* A64F00 80240E70 2402000D */  addiu     $v0, $zero, 0xd
/* A64F04 80240E74 AFA20014 */  sw        $v0, 0x14($sp)
/* A64F08 80240E78 0C01BFEC */  jal       func_8006FFB0
/* A64F0C 80240E7C E7A00010 */   swc1     $f0, 0x10($sp)
/* A64F10 80240E80 2402000F */  addiu     $v0, $zero, 0xf
/* A64F14 80240E84 A602008E */  sh        $v0, 0x8e($s0)
/* A64F18 80240E88 24020016 */  addiu     $v0, $zero, 0x16
/* A64F1C 80240E8C AE820070 */  sw        $v0, 0x70($s4)
.L80240E90:
/* A64F20 80240E90 8FBF004C */  lw        $ra, 0x4c($sp)
/* A64F24 80240E94 8FB40048 */  lw        $s4, 0x48($sp)
/* A64F28 80240E98 8FB30044 */  lw        $s3, 0x44($sp)
/* A64F2C 80240E9C 8FB20040 */  lw        $s2, 0x40($sp)
/* A64F30 80240EA0 8FB1003C */  lw        $s1, 0x3c($sp)
/* A64F34 80240EA4 8FB00038 */  lw        $s0, 0x38($sp)
/* A64F38 80240EA8 D7B40050 */  ldc1      $f20, 0x50($sp)
/* A64F3C 80240EAC 03E00008 */  jr        $ra
/* A64F40 80240EB0 27BD0058 */   addiu    $sp, $sp, 0x58
