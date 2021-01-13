.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CA8_BFF528
/* BFF528 80241CA8 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* BFF52C 80241CAC AFB20048 */  sw        $s2, 0x48($sp)
/* BFF530 80241CB0 0080902D */  daddu     $s2, $a0, $zero
/* BFF534 80241CB4 AFBF004C */  sw        $ra, 0x4c($sp)
/* BFF538 80241CB8 AFB10044 */  sw        $s1, 0x44($sp)
/* BFF53C 80241CBC AFB00040 */  sw        $s0, 0x40($sp)
/* BFF540 80241CC0 F7B40050 */  sdc1      $f20, 0x50($sp)
/* BFF544 80241CC4 8E500148 */  lw        $s0, 0x148($s2)
/* BFF548 80241CC8 0C00EABB */  jal       get_npc_unsafe
/* BFF54C 80241CCC 86040008 */   lh       $a0, 8($s0)
/* BFF550 80241CD0 27A50028 */  addiu     $a1, $sp, 0x28
/* BFF554 80241CD4 0040882D */  daddu     $s1, $v0, $zero
/* BFF558 80241CD8 27A6002C */  addiu     $a2, $sp, 0x2c
/* BFF55C 80241CDC 27A70030 */  addiu     $a3, $sp, 0x30
/* BFF560 80241CE0 C620003C */  lwc1      $f0, 0x3c($s1)
/* BFF564 80241CE4 3C014004 */  lui       $at, 0x4004
/* BFF568 80241CE8 44811800 */  mtc1      $at, $f3
/* BFF56C 80241CEC 44801000 */  mtc1      $zero, $f2
/* BFF570 80241CF0 C6260038 */  lwc1      $f6, 0x38($s1)
/* BFF574 80241CF4 46000021 */  cvt.d.s   $f0, $f0
/* BFF578 80241CF8 46220000 */  add.d     $f0, $f0, $f2
/* BFF57C 80241CFC 3C01447A */  lui       $at, 0x447a
/* BFF580 80241D00 44812000 */  mtc1      $at, $f4
/* BFF584 80241D04 C6020078 */  lwc1      $f2, 0x78($s0)
/* BFF588 80241D08 468010A0 */  cvt.s.w   $f2, $f2
/* BFF58C 80241D0C 46200020 */  cvt.s.d   $f0, $f0
/* BFF590 80241D10 E620003C */  swc1      $f0, 0x3c($s1)
/* BFF594 80241D14 46000206 */  mov.s     $f8, $f0
/* BFF598 80241D18 C6200040 */  lwc1      $f0, 0x40($s1)
/* BFF59C 80241D1C 27A20034 */  addiu     $v0, $sp, 0x34
/* BFF5A0 80241D20 E7A00030 */  swc1      $f0, 0x30($sp)
/* BFF5A4 80241D24 3C014059 */  lui       $at, 0x4059
/* BFF5A8 80241D28 44810800 */  mtc1      $at, $f1
/* BFF5AC 80241D2C 44800000 */  mtc1      $zero, $f0
/* BFF5B0 80241D30 460010A1 */  cvt.d.s   $f2, $f2
/* BFF5B4 80241D34 E7A60028 */  swc1      $f6, 0x28($sp)
/* BFF5B8 80241D38 E7A40034 */  swc1      $f4, 0x34($sp)
/* BFF5BC 80241D3C E7A8002C */  swc1      $f8, 0x2c($sp)
/* BFF5C0 80241D40 AFA20010 */  sw        $v0, 0x10($sp)
/* BFF5C4 80241D44 8E240080 */  lw        $a0, 0x80($s1)
/* BFF5C8 80241D48 46201083 */  div.d     $f2, $f2, $f0
/* BFF5CC 80241D4C 0C0372DF */  jal       func_800DCB7C
/* BFF5D0 80241D50 46201520 */   cvt.s.d  $f20, $f2
/* BFF5D4 80241D54 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* BFF5D8 80241D58 46140000 */  add.s     $f0, $f0, $f20
/* BFF5DC 80241D5C C622003C */  lwc1      $f2, 0x3c($s1)
/* BFF5E0 80241D60 4600103C */  c.lt.s    $f2, $f0
/* BFF5E4 80241D64 00000000 */  nop
/* BFF5E8 80241D68 45010028 */  bc1t      .L80241E0C
/* BFF5EC 80241D6C 00000000 */   nop
/* BFF5F0 80241D70 8E0200D0 */  lw        $v0, 0xd0($s0)
/* BFF5F4 80241D74 C62C0038 */  lwc1      $f12, 0x38($s1)
/* BFF5F8 80241D78 C62E0040 */  lwc1      $f14, 0x40($s1)
/* BFF5FC 80241D7C C44A0000 */  lwc1      $f10, ($v0)
/* BFF600 80241D80 468052A0 */  cvt.s.w   $f10, $f10
/* BFF604 80241D84 44065000 */  mfc1      $a2, $f10
/* BFF608 80241D88 C44A0008 */  lwc1      $f10, 8($v0)
/* BFF60C 80241D8C 468052A0 */  cvt.s.w   $f10, $f10
/* BFF610 80241D90 44075000 */  mfc1      $a3, $f10
/* BFF614 80241D94 0C00A720 */  jal       atan2
/* BFF618 80241D98 2410000A */   addiu    $s0, $zero, 0xa
/* BFF61C 80241D9C 24040002 */  addiu     $a0, $zero, 2
/* BFF620 80241DA0 0220282D */  daddu     $a1, $s1, $zero
/* BFF624 80241DA4 0000302D */  daddu     $a2, $zero, $zero
/* BFF628 80241DA8 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* BFF62C 80241DAC 862200A8 */  lh        $v0, 0xa8($s1)
/* BFF630 80241DB0 E620000C */  swc1      $f0, 0xc($s1)
/* BFF634 80241DB4 3C013F80 */  lui       $at, 0x3f80
/* BFF638 80241DB8 44810000 */  mtc1      $at, $f0
/* BFF63C 80241DBC 3C014000 */  lui       $at, 0x4000
/* BFF640 80241DC0 44812000 */  mtc1      $at, $f4
/* BFF644 80241DC4 3C01C1A0 */  lui       $at, 0xc1a0
/* BFF648 80241DC8 44813000 */  mtc1      $at, $f6
/* BFF64C 80241DCC 44825000 */  mtc1      $v0, $f10
/* BFF650 80241DD0 00000000 */  nop
/* BFF654 80241DD4 468052A0 */  cvt.s.w   $f10, $f10
/* BFF658 80241DD8 46141080 */  add.s     $f2, $f2, $f20
/* BFF65C 80241DDC 44075000 */  mfc1      $a3, $f10
/* BFF660 80241DE0 27A20038 */  addiu     $v0, $sp, 0x38
/* BFF664 80241DE4 E622003C */  swc1      $f2, 0x3c($s1)
/* BFF668 80241DE8 E7A00010 */  swc1      $f0, 0x10($sp)
/* BFF66C 80241DEC E7A40014 */  swc1      $f4, 0x14($sp)
/* BFF670 80241DF0 E7A60018 */  swc1      $f6, 0x18($sp)
/* BFF674 80241DF4 AFB0001C */  sw        $s0, 0x1c($sp)
/* BFF678 80241DF8 0C01BFA4 */  jal       fx_emote
/* BFF67C 80241DFC AFA20020 */   sw       $v0, 0x20($sp)
/* BFF680 80241E00 24020012 */  addiu     $v0, $zero, 0x12
/* BFF684 80241E04 A630008E */  sh        $s0, 0x8e($s1)
/* BFF688 80241E08 AE420070 */  sw        $v0, 0x70($s2)
.L80241E0C:
/* BFF68C 80241E0C 8FBF004C */  lw        $ra, 0x4c($sp)
/* BFF690 80241E10 8FB20048 */  lw        $s2, 0x48($sp)
/* BFF694 80241E14 8FB10044 */  lw        $s1, 0x44($sp)
/* BFF698 80241E18 8FB00040 */  lw        $s0, 0x40($sp)
/* BFF69C 80241E1C D7B40050 */  ldc1      $f20, 0x50($sp)
/* BFF6A0 80241E20 03E00008 */  jr        $ra
/* BFF6A4 80241E24 27BD0058 */   addiu    $sp, $sp, 0x58
