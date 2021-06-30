.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242D3C_A9647C
/* A9647C 80242D3C 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* A96480 80242D40 AFB40048 */  sw        $s4, 0x48($sp)
/* A96484 80242D44 0080A02D */  daddu     $s4, $a0, $zero
/* A96488 80242D48 AFBF004C */  sw        $ra, 0x4c($sp)
/* A9648C 80242D4C AFB30044 */  sw        $s3, 0x44($sp)
/* A96490 80242D50 AFB20040 */  sw        $s2, 0x40($sp)
/* A96494 80242D54 AFB1003C */  sw        $s1, 0x3c($sp)
/* A96498 80242D58 AFB00038 */  sw        $s0, 0x38($sp)
/* A9649C 80242D5C F7B40050 */  sdc1      $f20, 0x50($sp)
/* A964A0 80242D60 8E910148 */  lw        $s1, 0x148($s4)
/* A964A4 80242D64 00A0902D */  daddu     $s2, $a1, $zero
/* A964A8 80242D68 86240008 */  lh        $a0, 8($s1)
/* A964AC 80242D6C 0C00EABB */  jal       get_npc_unsafe
/* A964B0 80242D70 00C0982D */   daddu    $s3, $a2, $zero
/* A964B4 80242D74 0040802D */  daddu     $s0, $v0, $zero
/* A964B8 80242D78 9602008E */  lhu       $v0, 0x8e($s0)
/* A964BC 80242D7C 2442FFFF */  addiu     $v0, $v0, -1
/* A964C0 80242D80 A602008E */  sh        $v0, 0x8e($s0)
/* A964C4 80242D84 00021400 */  sll       $v0, $v0, 0x10
/* A964C8 80242D88 14400021 */  bnez      $v0, .L80242E10
/* A964CC 80242D8C 0280202D */   daddu    $a0, $s4, $zero
/* A964D0 80242D90 24040002 */  addiu     $a0, $zero, 2
/* A964D4 80242D94 0200282D */  daddu     $a1, $s0, $zero
/* A964D8 80242D98 0000302D */  daddu     $a2, $zero, $zero
/* A964DC 80242D9C 8E2200CC */  lw        $v0, 0xcc($s1)
/* A964E0 80242DA0 3C013F80 */  lui       $at, 0x3f80
/* A964E4 80242DA4 44810000 */  mtc1      $at, $f0
/* A964E8 80242DA8 3C014000 */  lui       $at, 0x4000
/* A964EC 80242DAC 44811000 */  mtc1      $at, $f2
/* A964F0 80242DB0 8C430000 */  lw        $v1, ($v0)
/* A964F4 80242DB4 860200A8 */  lh        $v0, 0xa8($s0)
/* A964F8 80242DB8 3C01C1A0 */  lui       $at, 0xc1a0
/* A964FC 80242DBC 44812000 */  mtc1      $at, $f4
/* A96500 80242DC0 44824000 */  mtc1      $v0, $f8
/* A96504 80242DC4 00000000 */  nop
/* A96508 80242DC8 46804220 */  cvt.s.w   $f8, $f8
/* A9650C 80242DCC 44074000 */  mfc1      $a3, $f8
/* A96510 80242DD0 2402000C */  addiu     $v0, $zero, 0xc
/* A96514 80242DD4 AE030028 */  sw        $v1, 0x28($s0)
/* A96518 80242DD8 AFA2001C */  sw        $v0, 0x1c($sp)
/* A9651C 80242DDC 27A20028 */  addiu     $v0, $sp, 0x28
/* A96520 80242DE0 E7A00010 */  swc1      $f0, 0x10($sp)
/* A96524 80242DE4 E7A20014 */  swc1      $f2, 0x14($sp)
/* A96528 80242DE8 E7A40018 */  swc1      $f4, 0x18($sp)
/* A9652C 80242DEC 0C01BFA4 */  jal       fx_emote
/* A96530 80242DF0 AFA20020 */   sw       $v0, 0x20($sp)
/* A96534 80242DF4 8E2200CC */  lw        $v0, 0xcc($s1)
/* A96538 80242DF8 8C430000 */  lw        $v1, ($v0)
/* A9653C 80242DFC 2402000F */  addiu     $v0, $zero, 0xf
/* A96540 80242E00 A602008E */  sh        $v0, 0x8e($s0)
/* A96544 80242E04 24020032 */  addiu     $v0, $zero, 0x32
/* A96548 80242E08 08090BB8 */  j         .L80242EE0
/* A9654C 80242E0C AE030028 */   sw       $v1, 0x28($s0)
.L80242E10:
/* A96550 80242E10 8E450024 */  lw        $a1, 0x24($s2)
/* A96554 80242E14 8E460028 */  lw        $a2, 0x28($s2)
/* A96558 80242E18 0C09074C */  jal       func_80241D30_A95470
/* A9655C 80242E1C 0260382D */   daddu    $a3, $s3, $zero
/* A96560 80242E20 24030001 */  addiu     $v1, $zero, 1
/* A96564 80242E24 1443002F */  bne       $v0, $v1, .L80242EE4
/* A96568 80242E28 00000000 */   nop
/* A9656C 80242E2C 8602008C */  lh        $v0, 0x8c($s0)
/* A96570 80242E30 1440002C */  bnez      $v0, .L80242EE4
/* A96574 80242E34 0200202D */   daddu    $a0, $s0, $zero
/* A96578 80242E38 240520D4 */  addiu     $a1, $zero, 0x20d4
/* A9657C 80242E3C 0C012530 */  jal       ai_enemy_play_sound
/* A96580 80242E40 0000302D */   daddu    $a2, $zero, $zero
/* A96584 80242E44 27A4002C */  addiu     $a0, $sp, 0x2c
/* A96588 80242E48 27A50030 */  addiu     $a1, $sp, 0x30
/* A9658C 80242E4C 3C0641F0 */  lui       $a2, 0x41f0
/* A96590 80242E50 C6020034 */  lwc1      $f2, 0x34($s0)
/* A96594 80242E54 3C014387 */  lui       $at, 0x4387
/* A96598 80242E58 44810000 */  mtc1      $at, $f0
/* A9659C 80242E5C 8E2200CC */  lw        $v0, 0xcc($s1)
/* A965A0 80242E60 C614003C */  lwc1      $f20, 0x3c($s0)
/* A965A4 80242E64 46020001 */  sub.s     $f0, $f0, $f2
/* A965A8 80242E68 3C0141E8 */  lui       $at, 0x41e8
/* A965AC 80242E6C 44812000 */  mtc1      $at, $f4
/* A965B0 80242E70 C6060038 */  lwc1      $f6, 0x38($s0)
/* A965B4 80242E74 4604A500 */  add.s     $f20, $f20, $f4
/* A965B8 80242E78 3C013F80 */  lui       $at, 0x3f80
/* A965BC 80242E7C 44811000 */  mtc1      $at, $f2
/* A965C0 80242E80 44070000 */  mfc1      $a3, $f0
/* A965C4 80242E84 C6000040 */  lwc1      $f0, 0x40($s0)
/* A965C8 80242E88 8C420020 */  lw        $v0, 0x20($v0)
/* A965CC 80242E8C 46020000 */  add.s     $f0, $f0, $f2
/* A965D0 80242E90 E7A6002C */  swc1      $f6, 0x2c($sp)
/* A965D4 80242E94 AE020028 */  sw        $v0, 0x28($s0)
/* A965D8 80242E98 0C00A7E7 */  jal       add_vec2D_polar
/* A965DC 80242E9C E7A00030 */   swc1     $f0, 0x30($sp)
/* A965E0 80242EA0 0000202D */  daddu     $a0, $zero, $zero
/* A965E4 80242EA4 4406A000 */  mfc1      $a2, $f20
/* A965E8 80242EA8 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* A965EC 80242EAC C7A20030 */  lwc1      $f2, 0x30($sp)
/* A965F0 80242EB0 44050000 */  mfc1      $a1, $f0
/* A965F4 80242EB4 44071000 */  mfc1      $a3, $f2
/* A965F8 80242EB8 3C013DCC */  lui       $at, 0x3dcc
/* A965FC 80242EBC 3421CCCD */  ori       $at, $at, 0xcccd
/* A96600 80242EC0 44810000 */  mtc1      $at, $f0
/* A96604 80242EC4 2402000D */  addiu     $v0, $zero, 0xd
/* A96608 80242EC8 AFA20014 */  sw        $v0, 0x14($sp)
/* A9660C 80242ECC 0C01BFEC */  jal       playFX_13
/* A96610 80242ED0 E7A00010 */   swc1     $f0, 0x10($sp)
/* A96614 80242ED4 2402000F */  addiu     $v0, $zero, 0xf
/* A96618 80242ED8 A602008E */  sh        $v0, 0x8e($s0)
/* A9661C 80242EDC 24020016 */  addiu     $v0, $zero, 0x16
.L80242EE0:
/* A96620 80242EE0 AE820070 */  sw        $v0, 0x70($s4)
.L80242EE4:
/* A96624 80242EE4 8FBF004C */  lw        $ra, 0x4c($sp)
/* A96628 80242EE8 8FB40048 */  lw        $s4, 0x48($sp)
/* A9662C 80242EEC 8FB30044 */  lw        $s3, 0x44($sp)
/* A96630 80242EF0 8FB20040 */  lw        $s2, 0x40($sp)
/* A96634 80242EF4 8FB1003C */  lw        $s1, 0x3c($sp)
/* A96638 80242EF8 8FB00038 */  lw        $s0, 0x38($sp)
/* A9663C 80242EFC D7B40050 */  ldc1      $f20, 0x50($sp)
/* A96640 80242F00 03E00008 */  jr        $ra
/* A96644 80242F04 27BD0058 */   addiu    $sp, $sp, 0x58
