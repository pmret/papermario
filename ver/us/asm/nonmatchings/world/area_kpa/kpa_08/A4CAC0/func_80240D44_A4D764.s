.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D44_A4D764
/* A4D764 80240D44 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* A4D768 80240D48 AFB40048 */  sw        $s4, 0x48($sp)
/* A4D76C 80240D4C 0080A02D */  daddu     $s4, $a0, $zero
/* A4D770 80240D50 AFBF004C */  sw        $ra, 0x4c($sp)
/* A4D774 80240D54 AFB30044 */  sw        $s3, 0x44($sp)
/* A4D778 80240D58 AFB20040 */  sw        $s2, 0x40($sp)
/* A4D77C 80240D5C AFB1003C */  sw        $s1, 0x3c($sp)
/* A4D780 80240D60 AFB00038 */  sw        $s0, 0x38($sp)
/* A4D784 80240D64 F7B40050 */  sdc1      $f20, 0x50($sp)
/* A4D788 80240D68 8E910148 */  lw        $s1, 0x148($s4)
/* A4D78C 80240D6C 00A0902D */  daddu     $s2, $a1, $zero
/* A4D790 80240D70 86240008 */  lh        $a0, 8($s1)
/* A4D794 80240D74 0C00EABB */  jal       get_npc_unsafe
/* A4D798 80240D78 00C0982D */   daddu    $s3, $a2, $zero
/* A4D79C 80240D7C 0040802D */  daddu     $s0, $v0, $zero
/* A4D7A0 80240D80 9602008E */  lhu       $v0, 0x8e($s0)
/* A4D7A4 80240D84 2442FFFF */  addiu     $v0, $v0, -1
/* A4D7A8 80240D88 A602008E */  sh        $v0, 0x8e($s0)
/* A4D7AC 80240D8C 00021400 */  sll       $v0, $v0, 0x10
/* A4D7B0 80240D90 14400021 */  bnez      $v0, .L80240E18
/* A4D7B4 80240D94 0280202D */   daddu    $a0, $s4, $zero
/* A4D7B8 80240D98 24040002 */  addiu     $a0, $zero, 2
/* A4D7BC 80240D9C 0200282D */  daddu     $a1, $s0, $zero
/* A4D7C0 80240DA0 0000302D */  daddu     $a2, $zero, $zero
/* A4D7C4 80240DA4 8E2200CC */  lw        $v0, 0xcc($s1)
/* A4D7C8 80240DA8 3C013F80 */  lui       $at, 0x3f80
/* A4D7CC 80240DAC 44810000 */  mtc1      $at, $f0
/* A4D7D0 80240DB0 3C014000 */  lui       $at, 0x4000
/* A4D7D4 80240DB4 44811000 */  mtc1      $at, $f2
/* A4D7D8 80240DB8 8C430000 */  lw        $v1, ($v0)
/* A4D7DC 80240DBC 860200A8 */  lh        $v0, 0xa8($s0)
/* A4D7E0 80240DC0 3C01C1A0 */  lui       $at, 0xc1a0
/* A4D7E4 80240DC4 44812000 */  mtc1      $at, $f4
/* A4D7E8 80240DC8 44824000 */  mtc1      $v0, $f8
/* A4D7EC 80240DCC 00000000 */  nop
/* A4D7F0 80240DD0 46804220 */  cvt.s.w   $f8, $f8
/* A4D7F4 80240DD4 44074000 */  mfc1      $a3, $f8
/* A4D7F8 80240DD8 2402000C */  addiu     $v0, $zero, 0xc
/* A4D7FC 80240DDC AE030028 */  sw        $v1, 0x28($s0)
/* A4D800 80240DE0 AFA2001C */  sw        $v0, 0x1c($sp)
/* A4D804 80240DE4 27A20028 */  addiu     $v0, $sp, 0x28
/* A4D808 80240DE8 E7A00010 */  swc1      $f0, 0x10($sp)
/* A4D80C 80240DEC E7A20014 */  swc1      $f2, 0x14($sp)
/* A4D810 80240DF0 E7A40018 */  swc1      $f4, 0x18($sp)
/* A4D814 80240DF4 0C01BFA4 */  jal       fx_emote
/* A4D818 80240DF8 AFA20020 */   sw       $v0, 0x20($sp)
/* A4D81C 80240DFC 8E2200CC */  lw        $v0, 0xcc($s1)
/* A4D820 80240E00 8C430000 */  lw        $v1, ($v0)
/* A4D824 80240E04 2402000F */  addiu     $v0, $zero, 0xf
/* A4D828 80240E08 A602008E */  sh        $v0, 0x8e($s0)
/* A4D82C 80240E0C AE030028 */  sw        $v1, 0x28($s0)
/* A4D830 80240E10 080903B8 */  j         .L80240EE0
/* A4D834 80240E14 AE800070 */   sw       $zero, 0x70($s4)
.L80240E18:
/* A4D838 80240E18 8E450024 */  lw        $a1, 0x24($s2)
/* A4D83C 80240E1C 8E460028 */  lw        $a2, 0x28($s2)
/* A4D840 80240E20 0C090028 */  jal       func_802400A0_A4CAC0
/* A4D844 80240E24 0260382D */   daddu    $a3, $s3, $zero
/* A4D848 80240E28 24030001 */  addiu     $v1, $zero, 1
/* A4D84C 80240E2C 1443002C */  bne       $v0, $v1, .L80240EE0
/* A4D850 80240E30 0200202D */   daddu    $a0, $s0, $zero
/* A4D854 80240E34 240520D4 */  addiu     $a1, $zero, 0x20d4
/* A4D858 80240E38 0C012530 */  jal       ai_enemy_play_sound
/* A4D85C 80240E3C 0000302D */   daddu    $a2, $zero, $zero
/* A4D860 80240E40 27A4002C */  addiu     $a0, $sp, 0x2c
/* A4D864 80240E44 27A50030 */  addiu     $a1, $sp, 0x30
/* A4D868 80240E48 3C064188 */  lui       $a2, 0x4188
/* A4D86C 80240E4C C6020034 */  lwc1      $f2, 0x34($s0)
/* A4D870 80240E50 3C014387 */  lui       $at, 0x4387
/* A4D874 80240E54 44810000 */  mtc1      $at, $f0
/* A4D878 80240E58 8E2200CC */  lw        $v0, 0xcc($s1)
/* A4D87C 80240E5C C614003C */  lwc1      $f20, 0x3c($s0)
/* A4D880 80240E60 46020001 */  sub.s     $f0, $f0, $f2
/* A4D884 80240E64 3C014200 */  lui       $at, 0x4200
/* A4D888 80240E68 44812000 */  mtc1      $at, $f4
/* A4D88C 80240E6C C6060038 */  lwc1      $f6, 0x38($s0)
/* A4D890 80240E70 4604A500 */  add.s     $f20, $f20, $f4
/* A4D894 80240E74 3C013F80 */  lui       $at, 0x3f80
/* A4D898 80240E78 44811000 */  mtc1      $at, $f2
/* A4D89C 80240E7C 44070000 */  mfc1      $a3, $f0
/* A4D8A0 80240E80 C6000040 */  lwc1      $f0, 0x40($s0)
/* A4D8A4 80240E84 8C420020 */  lw        $v0, 0x20($v0)
/* A4D8A8 80240E88 46020000 */  add.s     $f0, $f0, $f2
/* A4D8AC 80240E8C E7A6002C */  swc1      $f6, 0x2c($sp)
/* A4D8B0 80240E90 AE020028 */  sw        $v0, 0x28($s0)
/* A4D8B4 80240E94 0C00A7E7 */  jal       add_vec2D_polar
/* A4D8B8 80240E98 E7A00030 */   swc1     $f0, 0x30($sp)
/* A4D8BC 80240E9C 0000202D */  daddu     $a0, $zero, $zero
/* A4D8C0 80240EA0 4406A000 */  mfc1      $a2, $f20
/* A4D8C4 80240EA4 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* A4D8C8 80240EA8 C7A20030 */  lwc1      $f2, 0x30($sp)
/* A4D8CC 80240EAC 44050000 */  mfc1      $a1, $f0
/* A4D8D0 80240EB0 44071000 */  mfc1      $a3, $f2
/* A4D8D4 80240EB4 3C013DCC */  lui       $at, 0x3dcc
/* A4D8D8 80240EB8 3421CCCD */  ori       $at, $at, 0xcccd
/* A4D8DC 80240EBC 44810000 */  mtc1      $at, $f0
/* A4D8E0 80240EC0 2402000D */  addiu     $v0, $zero, 0xd
/* A4D8E4 80240EC4 AFA20014 */  sw        $v0, 0x14($sp)
/* A4D8E8 80240EC8 0C01BFEC */  jal       playFX_13
/* A4D8EC 80240ECC E7A00010 */   swc1     $f0, 0x10($sp)
/* A4D8F0 80240ED0 2402000F */  addiu     $v0, $zero, 0xf
/* A4D8F4 80240ED4 A602008E */  sh        $v0, 0x8e($s0)
/* A4D8F8 80240ED8 24020016 */  addiu     $v0, $zero, 0x16
/* A4D8FC 80240EDC AE820070 */  sw        $v0, 0x70($s4)
.L80240EE0:
/* A4D900 80240EE0 8FBF004C */  lw        $ra, 0x4c($sp)
/* A4D904 80240EE4 8FB40048 */  lw        $s4, 0x48($sp)
/* A4D908 80240EE8 8FB30044 */  lw        $s3, 0x44($sp)
/* A4D90C 80240EEC 8FB20040 */  lw        $s2, 0x40($sp)
/* A4D910 80240EF0 8FB1003C */  lw        $s1, 0x3c($sp)
/* A4D914 80240EF4 8FB00038 */  lw        $s0, 0x38($sp)
/* A4D918 80240EF8 D7B40050 */  ldc1      $f20, 0x50($sp)
/* A4D91C 80240EFC 03E00008 */  jr        $ra
/* A4D920 80240F00 27BD0058 */   addiu    $sp, $sp, 0x58
