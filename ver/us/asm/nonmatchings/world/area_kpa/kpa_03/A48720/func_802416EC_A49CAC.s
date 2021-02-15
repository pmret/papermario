.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416EC_A49CAC
/* A49CAC 802416EC 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* A49CB0 802416F0 AFB40048 */  sw        $s4, 0x48($sp)
/* A49CB4 802416F4 0080A02D */  daddu     $s4, $a0, $zero
/* A49CB8 802416F8 AFBF004C */  sw        $ra, 0x4c($sp)
/* A49CBC 802416FC AFB30044 */  sw        $s3, 0x44($sp)
/* A49CC0 80241700 AFB20040 */  sw        $s2, 0x40($sp)
/* A49CC4 80241704 AFB1003C */  sw        $s1, 0x3c($sp)
/* A49CC8 80241708 AFB00038 */  sw        $s0, 0x38($sp)
/* A49CCC 8024170C F7B40050 */  sdc1      $f20, 0x50($sp)
/* A49CD0 80241710 8E910148 */  lw        $s1, 0x148($s4)
/* A49CD4 80241714 00A0902D */  daddu     $s2, $a1, $zero
/* A49CD8 80241718 86240008 */  lh        $a0, 8($s1)
/* A49CDC 8024171C 0C00EABB */  jal       get_npc_unsafe
/* A49CE0 80241720 00C0982D */   daddu    $s3, $a2, $zero
/* A49CE4 80241724 0040802D */  daddu     $s0, $v0, $zero
/* A49CE8 80241728 9602008E */  lhu       $v0, 0x8e($s0)
/* A49CEC 8024172C 2442FFFF */  addiu     $v0, $v0, -1
/* A49CF0 80241730 A602008E */  sh        $v0, 0x8e($s0)
/* A49CF4 80241734 00021400 */  sll       $v0, $v0, 0x10
/* A49CF8 80241738 14400021 */  bnez      $v0, .L802417C0
/* A49CFC 8024173C 0280202D */   daddu    $a0, $s4, $zero
/* A49D00 80241740 24040002 */  addiu     $a0, $zero, 2
/* A49D04 80241744 0200282D */  daddu     $a1, $s0, $zero
/* A49D08 80241748 0000302D */  daddu     $a2, $zero, $zero
/* A49D0C 8024174C 8E2200CC */  lw        $v0, 0xcc($s1)
/* A49D10 80241750 3C013F80 */  lui       $at, 0x3f80
/* A49D14 80241754 44810000 */  mtc1      $at, $f0
/* A49D18 80241758 3C014000 */  lui       $at, 0x4000
/* A49D1C 8024175C 44811000 */  mtc1      $at, $f2
/* A49D20 80241760 8C430000 */  lw        $v1, ($v0)
/* A49D24 80241764 860200A8 */  lh        $v0, 0xa8($s0)
/* A49D28 80241768 3C01C1A0 */  lui       $at, 0xc1a0
/* A49D2C 8024176C 44812000 */  mtc1      $at, $f4
/* A49D30 80241770 44824000 */  mtc1      $v0, $f8
/* A49D34 80241774 00000000 */  nop
/* A49D38 80241778 46804220 */  cvt.s.w   $f8, $f8
/* A49D3C 8024177C 44074000 */  mfc1      $a3, $f8
/* A49D40 80241780 2402000C */  addiu     $v0, $zero, 0xc
/* A49D44 80241784 AE030028 */  sw        $v1, 0x28($s0)
/* A49D48 80241788 AFA2001C */  sw        $v0, 0x1c($sp)
/* A49D4C 8024178C 27A20028 */  addiu     $v0, $sp, 0x28
/* A49D50 80241790 E7A00010 */  swc1      $f0, 0x10($sp)
/* A49D54 80241794 E7A20014 */  swc1      $f2, 0x14($sp)
/* A49D58 80241798 E7A40018 */  swc1      $f4, 0x18($sp)
/* A49D5C 8024179C 0C01BFA4 */  jal       fx_emote
/* A49D60 802417A0 AFA20020 */   sw       $v0, 0x20($sp)
/* A49D64 802417A4 8E2200CC */  lw        $v0, 0xcc($s1)
/* A49D68 802417A8 8C430000 */  lw        $v1, ($v0)
/* A49D6C 802417AC 2402000F */  addiu     $v0, $zero, 0xf
/* A49D70 802417B0 A602008E */  sh        $v0, 0x8e($s0)
/* A49D74 802417B4 AE030028 */  sw        $v1, 0x28($s0)
/* A49D78 802417B8 08090622 */  j         .L80241888
/* A49D7C 802417BC AE800070 */   sw       $zero, 0x70($s4)
.L802417C0:
/* A49D80 802417C0 8E450024 */  lw        $a1, 0x24($s2)
/* A49D84 802417C4 8E460028 */  lw        $a2, 0x28($s2)
/* A49D88 802417C8 0C090292 */  jal       func_80240A48_A49008
/* A49D8C 802417CC 0260382D */   daddu    $a3, $s3, $zero
/* A49D90 802417D0 24030001 */  addiu     $v1, $zero, 1
/* A49D94 802417D4 1443002C */  bne       $v0, $v1, .L80241888
/* A49D98 802417D8 0200202D */   daddu    $a0, $s0, $zero
/* A49D9C 802417DC 240520D4 */  addiu     $a1, $zero, 0x20d4
/* A49DA0 802417E0 0C012530 */  jal       func_800494C0
/* A49DA4 802417E4 0000302D */   daddu    $a2, $zero, $zero
/* A49DA8 802417E8 27A4002C */  addiu     $a0, $sp, 0x2c
/* A49DAC 802417EC 27A50030 */  addiu     $a1, $sp, 0x30
/* A49DB0 802417F0 3C064188 */  lui       $a2, 0x4188
/* A49DB4 802417F4 C6020034 */  lwc1      $f2, 0x34($s0)
/* A49DB8 802417F8 3C014387 */  lui       $at, 0x4387
/* A49DBC 802417FC 44810000 */  mtc1      $at, $f0
/* A49DC0 80241800 8E2200CC */  lw        $v0, 0xcc($s1)
/* A49DC4 80241804 C614003C */  lwc1      $f20, 0x3c($s0)
/* A49DC8 80241808 46020001 */  sub.s     $f0, $f0, $f2
/* A49DCC 8024180C 3C014200 */  lui       $at, 0x4200
/* A49DD0 80241810 44812000 */  mtc1      $at, $f4
/* A49DD4 80241814 C6060038 */  lwc1      $f6, 0x38($s0)
/* A49DD8 80241818 4604A500 */  add.s     $f20, $f20, $f4
/* A49DDC 8024181C 3C013F80 */  lui       $at, 0x3f80
/* A49DE0 80241820 44811000 */  mtc1      $at, $f2
/* A49DE4 80241824 44070000 */  mfc1      $a3, $f0
/* A49DE8 80241828 C6000040 */  lwc1      $f0, 0x40($s0)
/* A49DEC 8024182C 8C420020 */  lw        $v0, 0x20($v0)
/* A49DF0 80241830 46020000 */  add.s     $f0, $f0, $f2
/* A49DF4 80241834 E7A6002C */  swc1      $f6, 0x2c($sp)
/* A49DF8 80241838 AE020028 */  sw        $v0, 0x28($s0)
/* A49DFC 8024183C 0C00A7E7 */  jal       add_vec2D_polar
/* A49E00 80241840 E7A00030 */   swc1     $f0, 0x30($sp)
/* A49E04 80241844 0000202D */  daddu     $a0, $zero, $zero
/* A49E08 80241848 4406A000 */  mfc1      $a2, $f20
/* A49E0C 8024184C C7A0002C */  lwc1      $f0, 0x2c($sp)
/* A49E10 80241850 C7A20030 */  lwc1      $f2, 0x30($sp)
/* A49E14 80241854 44050000 */  mfc1      $a1, $f0
/* A49E18 80241858 44071000 */  mfc1      $a3, $f2
/* A49E1C 8024185C 3C013DCC */  lui       $at, 0x3dcc
/* A49E20 80241860 3421CCCD */  ori       $at, $at, 0xcccd
/* A49E24 80241864 44810000 */  mtc1      $at, $f0
/* A49E28 80241868 2402000D */  addiu     $v0, $zero, 0xd
/* A49E2C 8024186C AFA20014 */  sw        $v0, 0x14($sp)
/* A49E30 80241870 0C01BFEC */  jal       func_8006FFB0
/* A49E34 80241874 E7A00010 */   swc1     $f0, 0x10($sp)
/* A49E38 80241878 2402000F */  addiu     $v0, $zero, 0xf
/* A49E3C 8024187C A602008E */  sh        $v0, 0x8e($s0)
/* A49E40 80241880 24020016 */  addiu     $v0, $zero, 0x16
/* A49E44 80241884 AE820070 */  sw        $v0, 0x70($s4)
.L80241888:
/* A49E48 80241888 8FBF004C */  lw        $ra, 0x4c($sp)
/* A49E4C 8024188C 8FB40048 */  lw        $s4, 0x48($sp)
/* A49E50 80241890 8FB30044 */  lw        $s3, 0x44($sp)
/* A49E54 80241894 8FB20040 */  lw        $s2, 0x40($sp)
/* A49E58 80241898 8FB1003C */  lw        $s1, 0x3c($sp)
/* A49E5C 8024189C 8FB00038 */  lw        $s0, 0x38($sp)
/* A49E60 802418A0 D7B40050 */  ldc1      $f20, 0x50($sp)
/* A49E64 802418A4 03E00008 */  jr        $ra
/* A49E68 802418A8 27BD0058 */   addiu    $sp, $sp, 0x58
