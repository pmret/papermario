.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406CC_A99C5C
/* A99C5C 802406CC 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* A99C60 802406D0 AFB7004C */  sw        $s7, 0x4c($sp)
/* A99C64 802406D4 0080B82D */  daddu     $s7, $a0, $zero
/* A99C68 802406D8 AFB10034 */  sw        $s1, 0x34($sp)
/* A99C6C 802406DC 00A0882D */  daddu     $s1, $a1, $zero
/* A99C70 802406E0 AFBF0050 */  sw        $ra, 0x50($sp)
/* A99C74 802406E4 AFB60048 */  sw        $s6, 0x48($sp)
/* A99C78 802406E8 AFB50044 */  sw        $s5, 0x44($sp)
/* A99C7C 802406EC AFB40040 */  sw        $s4, 0x40($sp)
/* A99C80 802406F0 AFB3003C */  sw        $s3, 0x3c($sp)
/* A99C84 802406F4 AFB20038 */  sw        $s2, 0x38($sp)
/* A99C88 802406F8 AFB00030 */  sw        $s0, 0x30($sp)
/* A99C8C 802406FC 8EF30148 */  lw        $s3, 0x148($s7)
/* A99C90 80240700 86640008 */  lh        $a0, 8($s3)
/* A99C94 80240704 8EF0000C */  lw        $s0, 0xc($s7)
/* A99C98 80240708 0C00FB5A */  jal       get_enemy_safe
/* A99C9C 8024070C 0000B02D */   daddu    $s6, $zero, $zero
/* A99CA0 80240710 10400131 */  beqz      $v0, .L80240BD8
/* A99CA4 80240714 24020005 */   addiu    $v0, $zero, 5
/* A99CA8 80240718 8E63006C */  lw        $v1, 0x6c($s3)
/* A99CAC 8024071C 1062012F */  beq       $v1, $v0, .L80240BDC
/* A99CB0 80240720 0000102D */   daddu    $v0, $zero, $zero
/* A99CB4 80240724 8E050000 */  lw        $a1, ($s0)
/* A99CB8 80240728 0C0B1EAF */  jal       evt_get_variable
/* A99CBC 8024072C 02E0202D */   daddu    $a0, $s7, $zero
/* A99CC0 80240730 86640008 */  lh        $a0, 8($s3)
/* A99CC4 80240734 0C00EABB */  jal       get_npc_unsafe
/* A99CC8 80240738 0040A82D */   daddu    $s5, $v0, $zero
/* A99CCC 8024073C 8E630070 */  lw        $v1, 0x70($s3)
/* A99CD0 80240740 30630002 */  andi      $v1, $v1, 2
/* A99CD4 80240744 10600008 */  beqz      $v1, .L80240768
/* A99CD8 80240748 0040902D */   daddu    $s2, $v0, $zero
/* A99CDC 8024074C 964200A8 */  lhu       $v0, 0xa8($s2)
/* A99CE0 80240750 00021400 */  sll       $v0, $v0, 0x10
/* A99CE4 80240754 00021C03 */  sra       $v1, $v0, 0x10
/* A99CE8 80240758 000217C2 */  srl       $v0, $v0, 0x1f
/* A99CEC 8024075C 00621821 */  addu      $v1, $v1, $v0
/* A99CF0 80240760 00031843 */  sra       $v1, $v1, 1
/* A99CF4 80240764 A24300AB */  sb        $v1, 0xab($s2)
.L80240768:
/* A99CF8 80240768 16200005 */  bnez      $s1, .L80240780
/* A99CFC 8024076C 3C030004 */   lui      $v1, 4
/* A99D00 80240770 8E6200B0 */  lw        $v0, 0xb0($s3)
/* A99D04 80240774 30420004 */  andi      $v0, $v0, 4
/* A99D08 80240778 10400019 */  beqz      $v0, .L802407E0
/* A99D0C 8024077C 00000000 */   nop
.L80240780:
/* A99D10 80240780 34630102 */  ori       $v1, $v1, 0x102
/* A99D14 80240784 AEE00070 */  sw        $zero, 0x70($s7)
/* A99D18 80240788 8E420000 */  lw        $v0, ($s2)
/* A99D1C 8024078C 0240202D */  daddu     $a0, $s2, $zero
/* A99D20 80240790 A640008E */  sh        $zero, 0x8e($s2)
/* A99D24 80240794 00431025 */  or        $v0, $v0, $v1
/* A99D28 80240798 0C00EAFF */  jal       disable_npc_shadow
/* A99D2C 8024079C AE420000 */   sw       $v0, ($s2)
/* A99D30 802407A0 3C041F30 */  lui       $a0, 0x1f30
/* A99D34 802407A4 8E420000 */  lw        $v0, ($s2)
/* A99D38 802407A8 2403F7FF */  addiu     $v1, $zero, -0x801
/* A99D3C 802407AC 00431024 */  and       $v0, $v0, $v1
/* A99D40 802407B0 AE420000 */  sw        $v0, ($s2)
/* A99D44 802407B4 8E620000 */  lw        $v0, ($s3)
/* A99D48 802407B8 8E6300B0 */  lw        $v1, 0xb0($s3)
/* A99D4C 802407BC 34840040 */  ori       $a0, $a0, 0x40
/* A99D50 802407C0 AE60006C */  sw        $zero, 0x6c($s3)
/* A99D54 802407C4 00441025 */  or        $v0, $v0, $a0
/* A99D58 802407C8 AE620000 */  sw        $v0, ($s3)
/* A99D5C 802407CC 30620004 */  andi      $v0, $v1, 4
/* A99D60 802407D0 10400003 */  beqz      $v0, .L802407E0
/* A99D64 802407D4 2402FFFB */   addiu    $v0, $zero, -5
/* A99D68 802407D8 00621024 */  and       $v0, $v1, $v0
/* A99D6C 802407DC AE6200B0 */  sw        $v0, 0xb0($s3)
.L802407E0:
/* A99D70 802407E0 8EE30070 */  lw        $v1, 0x70($s7)
/* A99D74 802407E4 24100001 */  addiu     $s0, $zero, 1
/* A99D78 802407E8 10700012 */  beq       $v1, $s0, .L80240834
/* A99D7C 802407EC 28620002 */   slti     $v0, $v1, 2
/* A99D80 802407F0 10400005 */  beqz      $v0, .L80240808
/* A99D84 802407F4 24020002 */   addiu    $v0, $zero, 2
/* A99D88 802407F8 10600007 */  beqz      $v1, .L80240818
/* A99D8C 802407FC 0000102D */   daddu    $v0, $zero, $zero
/* A99D90 80240800 080902F7 */  j         .L80240BDC
/* A99D94 80240804 00000000 */   nop
.L80240808:
/* A99D98 80240808 1062005B */  beq       $v1, $v0, .L80240978
/* A99D9C 8024080C 0000102D */   daddu    $v0, $zero, $zero
/* A99DA0 80240810 080902F7 */  j         .L80240BDC
/* A99DA4 80240814 00000000 */   nop
.L80240818:
/* A99DA8 80240818 8E420000 */  lw        $v0, ($s2)
/* A99DAC 8024081C 0240202D */  daddu     $a0, $s2, $zero
/* A99DB0 80240820 34420002 */  ori       $v0, $v0, 2
/* A99DB4 80240824 0C00EAFF */  jal       disable_npc_shadow
/* A99DB8 80240828 AE420000 */   sw       $v0, ($s2)
/* A99DBC 8024082C AE60006C */  sw        $zero, 0x6c($s3)
/* A99DC0 80240830 AEF00070 */  sw        $s0, 0x70($s7)
.L80240834:
/* A99DC4 80240834 8E74006C */  lw        $s4, 0x6c($s3)
/* A99DC8 80240838 24020001 */  addiu     $v0, $zero, 1
/* A99DCC 8024083C 168200E7 */  bne       $s4, $v0, .L80240BDC
/* A99DD0 80240840 0000102D */   daddu    $v0, $zero, $zero
/* A99DD4 80240844 8E64007C */  lw        $a0, 0x7c($s3)
/* A99DD8 80240848 24110002 */  addiu     $s1, $zero, 2
/* A99DDC 8024084C 0C00EABB */  jal       get_npc_unsafe
/* A99DE0 80240850 AE71006C */   sw       $s1, 0x6c($s3)
/* A99DE4 80240854 0040802D */  daddu     $s0, $v0, $zero
/* A99DE8 80240858 C6000038 */  lwc1      $f0, 0x38($s0)
/* A99DEC 8024085C E6400038 */  swc1      $f0, 0x38($s2)
/* A99DF0 80240860 C6000040 */  lwc1      $f0, 0x40($s0)
/* A99DF4 80240864 E6400040 */  swc1      $f0, 0x40($s2)
/* A99DF8 80240868 C6020034 */  lwc1      $f2, 0x34($s0)
/* A99DFC 8024086C 3C014387 */  lui       $at, 0x4387
/* A99E00 80240870 44810000 */  mtc1      $at, $f0
/* A99E04 80240874 26440038 */  addiu     $a0, $s2, 0x38
/* A99E08 80240878 46020001 */  sub.s     $f0, $f0, $f2
/* A99E0C 8024087C C6680078 */  lwc1      $f8, 0x78($s3)
/* A99E10 80240880 46804220 */  cvt.s.w   $f8, $f8
/* A99E14 80240884 44064000 */  mfc1      $a2, $f8
/* A99E18 80240888 44070000 */  mfc1      $a3, $f0
/* A99E1C 8024088C 0C00A7E7 */  jal       add_vec2D_polar
/* A99E20 80240890 26450040 */   addiu    $a1, $s2, 0x40
/* A99E24 80240894 C600003C */  lwc1      $f0, 0x3c($s0)
/* A99E28 80240898 C6620074 */  lwc1      $f2, 0x74($s3)
/* A99E2C 8024089C 468010A0 */  cvt.s.w   $f2, $f2
/* A99E30 802408A0 46020000 */  add.s     $f0, $f0, $f2
/* A99E34 802408A4 E640003C */  swc1      $f0, 0x3c($s2)
/* A99E38 802408A8 A2740007 */  sb        $s4, 7($s3)
/* A99E3C 802408AC C6400038 */  lwc1      $f0, 0x38($s2)
/* A99E40 802408B0 4600020D */  trunc.w.s $f8, $f0
/* A99E44 802408B4 44024000 */  mfc1      $v0, $f8
/* A99E48 802408B8 00000000 */  nop
/* A99E4C 802408BC A6620010 */  sh        $v0, 0x10($s3)
/* A99E50 802408C0 C640003C */  lwc1      $f0, 0x3c($s2)
/* A99E54 802408C4 4600020D */  trunc.w.s $f8, $f0
/* A99E58 802408C8 44024000 */  mfc1      $v0, $f8
/* A99E5C 802408CC 00000000 */  nop
/* A99E60 802408D0 A6620012 */  sh        $v0, 0x12($s3)
/* A99E64 802408D4 C6400040 */  lwc1      $f0, 0x40($s2)
/* A99E68 802408D8 4600020D */  trunc.w.s $f8, $f0
/* A99E6C 802408DC 44024000 */  mfc1      $v0, $f8
/* A99E70 802408E0 00000000 */  nop
/* A99E74 802408E4 A6620014 */  sh        $v0, 0x14($s3)
/* A99E78 802408E8 AE400044 */  sw        $zero, 0x44($s2)
/* A99E7C 802408EC AE400048 */  sw        $zero, 0x48($s2)
/* A99E80 802408F0 AE40004C */  sw        $zero, 0x4c($s2)
/* A99E84 802408F4 C6A00000 */  lwc1      $f0, ($s5)
/* A99E88 802408F8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A99E8C 802408FC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A99E90 80240900 C64C0038 */  lwc1      $f12, 0x38($s2)
/* A99E94 80240904 C64E0040 */  lwc1      $f14, 0x40($s2)
/* A99E98 80240908 E6400018 */  swc1      $f0, 0x18($s2)
/* A99E9C 8024090C 8C460028 */  lw        $a2, 0x28($v0)
/* A99EA0 80240910 0C00A720 */  jal       atan2
/* A99EA4 80240914 8C470030 */   lw       $a3, 0x30($v0)
/* A99EA8 80240918 E640000C */  swc1      $f0, 0xc($s2)
/* A99EAC 8024091C C6A0000C */  lwc1      $f0, 0xc($s5)
/* A99EB0 80240920 8E420000 */  lw        $v0, ($s2)
/* A99EB4 80240924 0240202D */  daddu     $a0, $s2, $zero
/* A99EB8 80240928 E640001C */  swc1      $f0, 0x1c($s2)
/* A99EBC 8024092C C6A00010 */  lwc1      $f0, 0x10($s5)
/* A99EC0 80240930 2403FFFD */  addiu     $v1, $zero, -3
/* A99EC4 80240934 E6400014 */  swc1      $f0, 0x14($s2)
/* A99EC8 80240938 C600003C */  lwc1      $f0, 0x3c($s0)
/* A99ECC 8024093C 00431024 */  and       $v0, $v0, $v1
/* A99ED0 80240940 AE420000 */  sw        $v0, ($s2)
/* A99ED4 80240944 0C00EAE8 */  jal       enable_npc_shadow
/* A99ED8 80240948 E6400064 */   swc1     $f0, 0x64($s2)
/* A99EDC 8024094C 8E420000 */  lw        $v0, ($s2)
/* A99EE0 80240950 3C03E0FF */  lui       $v1, 0xe0ff
/* A99EE4 80240954 34420800 */  ori       $v0, $v0, 0x800
/* A99EE8 80240958 AE420000 */  sw        $v0, ($s2)
/* A99EEC 8024095C 8E620000 */  lw        $v0, ($s3)
/* A99EF0 80240960 3463FFFF */  ori       $v1, $v1, 0xffff
/* A99EF4 80240964 00431024 */  and       $v0, $v0, $v1
/* A99EF8 80240968 AE620000 */  sw        $v0, ($s3)
/* A99EFC 8024096C 2402005A */  addiu     $v0, $zero, 0x5a
/* A99F00 80240970 A642008E */  sh        $v0, 0x8e($s2)
/* A99F04 80240974 AEF10070 */  sw        $s1, 0x70($s7)
.L80240978:
/* A99F08 80240978 0000202D */  daddu     $a0, $zero, $zero
/* A99F0C 8024097C 27B00020 */  addiu     $s0, $sp, 0x20
/* A99F10 80240980 864200A8 */  lh        $v0, 0xa8($s2)
/* A99F14 80240984 3C013FE0 */  lui       $at, 0x3fe0
/* A99F18 80240988 44810800 */  mtc1      $at, $f1
/* A99F1C 8024098C 44800000 */  mtc1      $zero, $f0
/* A99F20 80240990 44821000 */  mtc1      $v0, $f2
/* A99F24 80240994 00000000 */  nop
/* A99F28 80240998 468010A1 */  cvt.d.w   $f2, $f2
/* A99F2C 8024099C 46201082 */  mul.d     $f2, $f2, $f0
/* A99F30 802409A0 00000000 */  nop
/* A99F34 802409A4 0200282D */  daddu     $a1, $s0, $zero
/* A99F38 802409A8 C6440038 */  lwc1      $f4, 0x38($s2)
/* A99F3C 802409AC C640003C */  lwc1      $f0, 0x3c($s2)
/* A99F40 802409B0 27B10024 */  addiu     $s1, $sp, 0x24
/* A99F44 802409B4 E7A40020 */  swc1      $f4, 0x20($sp)
/* A99F48 802409B8 C6440040 */  lwc1      $f4, 0x40($s2)
/* A99F4C 802409BC 46000021 */  cvt.d.s   $f0, $f0
/* A99F50 802409C0 46220000 */  add.d     $f0, $f0, $f2
/* A99F54 802409C4 E7A40028 */  swc1      $f4, 0x28($sp)
/* A99F58 802409C8 C6420018 */  lwc1      $f2, 0x18($s2)
/* A99F5C 802409CC 46200020 */  cvt.s.d   $f0, $f0
/* A99F60 802409D0 E7A00024 */  swc1      $f0, 0x24($sp)
/* A99F64 802409D4 E7A20010 */  swc1      $f2, 0x10($sp)
/* A99F68 802409D8 C640000C */  lwc1      $f0, 0xc($s2)
/* A99F6C 802409DC 0220302D */  daddu     $a2, $s1, $zero
/* A99F70 802409E0 E7A00014 */  swc1      $f0, 0x14($sp)
/* A99F74 802409E4 864200A6 */  lh        $v0, 0xa6($s2)
/* A99F78 802409E8 27B40028 */  addiu     $s4, $sp, 0x28
/* A99F7C 802409EC 44820000 */  mtc1      $v0, $f0
/* A99F80 802409F0 00000000 */  nop
/* A99F84 802409F4 46800020 */  cvt.s.w   $f0, $f0
/* A99F88 802409F8 E7A00018 */  swc1      $f0, 0x18($sp)
/* A99F8C 802409FC 864200A8 */  lh        $v0, 0xa8($s2)
/* A99F90 80240A00 0280382D */  daddu     $a3, $s4, $zero
/* A99F94 80240A04 44820000 */  mtc1      $v0, $f0
/* A99F98 80240A08 00000000 */  nop
/* A99F9C 80240A0C 46800020 */  cvt.s.w   $f0, $f0
/* A99FA0 80240A10 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* A99FA4 80240A14 E7A0001C */   swc1     $f0, 0x1c($sp)
/* A99FA8 80240A18 54400001 */  bnel      $v0, $zero, .L80240A20
/* A99FAC 80240A1C 24160001 */   addiu    $s6, $zero, 1
.L80240A20:
/* A99FB0 80240A20 0200282D */  daddu     $a1, $s0, $zero
/* A99FB4 80240A24 0220302D */  daddu     $a2, $s1, $zero
/* A99FB8 80240A28 C6400038 */  lwc1      $f0, 0x38($s2)
/* A99FBC 80240A2C C642003C */  lwc1      $f2, 0x3c($s2)
/* A99FC0 80240A30 C6440040 */  lwc1      $f4, 0x40($s2)
/* A99FC4 80240A34 3C01447A */  lui       $at, 0x447a
/* A99FC8 80240A38 44813000 */  mtc1      $at, $f6
/* A99FCC 80240A3C 27A2002C */  addiu     $v0, $sp, 0x2c
/* A99FD0 80240A40 E7A00020 */  swc1      $f0, 0x20($sp)
/* A99FD4 80240A44 E7A20024 */  swc1      $f2, 0x24($sp)
/* A99FD8 80240A48 E7A40028 */  swc1      $f4, 0x28($sp)
/* A99FDC 80240A4C E7A6002C */  swc1      $f6, 0x2c($sp)
/* A99FE0 80240A50 AFA20010 */  sw        $v0, 0x10($sp)
/* A99FE4 80240A54 8E440080 */  lw        $a0, 0x80($s2)
/* A99FE8 80240A58 0C0372DF */  jal       npc_raycast_down_sides
/* A99FEC 80240A5C 0280382D */   daddu    $a3, $s4, $zero
/* A99FF0 80240A60 10400019 */  beqz      $v0, .L80240AC8
/* A99FF4 80240A64 00000000 */   nop
/* A99FF8 80240A68 C640001C */  lwc1      $f0, 0x1c($s2)
/* A99FFC 80240A6C C7A2002C */  lwc1      $f2, 0x2c($sp)
/* A9A000 80240A70 46000005 */  abs.s     $f0, $f0
/* A9A004 80240A74 4600103C */  c.lt.s    $f2, $f0
/* A9A008 80240A78 00000000 */  nop
/* A9A00C 80240A7C 45000012 */  bc1f      .L80240AC8
/* A9A010 80240A80 00000000 */   nop
/* A9A014 80240A84 C7A40024 */  lwc1      $f4, 0x24($sp)
/* A9A018 80240A88 C6400064 */  lwc1      $f0, 0x64($s2)
/* A9A01C 80240A8C 46002001 */  sub.s     $f0, $f4, $f0
/* A9A020 80240A90 3C014034 */  lui       $at, 0x4034
/* A9A024 80240A94 44811800 */  mtc1      $at, $f3
/* A9A028 80240A98 44801000 */  mtc1      $zero, $f2
/* A9A02C 80240A9C 46000005 */  abs.s     $f0, $f0
/* A9A030 80240AA0 46000021 */  cvt.d.s   $f0, $f0
/* A9A034 80240AA4 4622003C */  c.lt.d    $f0, $f2
/* A9A038 80240AA8 00000000 */  nop
/* A9A03C 80240AAC 45000006 */  bc1f      .L80240AC8
/* A9A040 80240AB0 0240202D */   daddu    $a0, $s2, $zero
/* A9A044 80240AB4 8E450018 */  lw        $a1, 0x18($s2)
/* A9A048 80240AB8 8E46000C */  lw        $a2, 0xc($s2)
/* A9A04C 80240ABC 2416000A */  addiu     $s6, $zero, 0xa
/* A9A050 80240AC0 0C00EA95 */  jal       npc_move_heading
/* A9A054 80240AC4 E644003C */   swc1     $f4, 0x3c($s2)
.L80240AC8:
/* A9A058 80240AC8 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* A9A05C 80240ACC 3C013FF0 */  lui       $at, 0x3ff0
/* A9A060 80240AD0 44811800 */  mtc1      $at, $f3
/* A9A064 80240AD4 44801000 */  mtc1      $zero, $f2
/* A9A068 80240AD8 46000021 */  cvt.d.s   $f0, $f0
/* A9A06C 80240ADC 4622003C */  c.lt.d    $f0, $f2
/* A9A070 80240AE0 00000000 */  nop
/* A9A074 80240AE4 45030001 */  bc1tl     .L80240AEC
/* A9A078 80240AE8 2416000B */   addiu    $s6, $zero, 0xb
.L80240AEC:
/* A9A07C 80240AEC 9642008E */  lhu       $v0, 0x8e($s2)
/* A9A080 80240AF0 2442FFFF */  addiu     $v0, $v0, -1
/* A9A084 80240AF4 A642008E */  sh        $v0, 0x8e($s2)
/* A9A088 80240AF8 00021400 */  sll       $v0, $v0, 0x10
/* A9A08C 80240AFC 58400001 */  blezl     $v0, .L80240B04
/* A9A090 80240B00 24160014 */   addiu    $s6, $zero, 0x14
.L80240B04:
/* A9A094 80240B04 56C00019 */  bnel      $s6, $zero, .L80240B6C
/* A9A098 80240B08 AFA00010 */   sw       $zero, 0x10($sp)
/* A9A09C 80240B0C 8E620070 */  lw        $v0, 0x70($s3)
/* A9A0A0 80240B10 30420001 */  andi      $v0, $v0, 1
/* A9A0A4 80240B14 10400009 */  beqz      $v0, .L80240B3C
/* A9A0A8 80240B18 00000000 */   nop
/* A9A0AC 80240B1C C640004C */  lwc1      $f0, 0x4c($s2)
/* A9A0B0 80240B20 3C014044 */  lui       $at, 0x4044
/* A9A0B4 80240B24 44811800 */  mtc1      $at, $f3
/* A9A0B8 80240B28 44801000 */  mtc1      $zero, $f2
/* A9A0BC 80240B2C 46000021 */  cvt.d.s   $f0, $f0
/* A9A0C0 80240B30 46220000 */  add.d     $f0, $f0, $f2
/* A9A0C4 80240B34 46200020 */  cvt.s.d   $f0, $f0
/* A9A0C8 80240B38 E640004C */  swc1      $f0, 0x4c($s2)
.L80240B3C:
/* A9A0CC 80240B3C 8E450018 */  lw        $a1, 0x18($s2)
/* A9A0D0 80240B40 8E46000C */  lw        $a2, 0xc($s2)
/* A9A0D4 80240B44 0C00EA95 */  jal       npc_move_heading
/* A9A0D8 80240B48 0240202D */   daddu    $a0, $s2, $zero
/* A9A0DC 80240B4C C644003C */  lwc1      $f4, 0x3c($s2)
/* A9A0E0 80240B50 C640001C */  lwc1      $f0, 0x1c($s2)
/* A9A0E4 80240B54 46002100 */  add.s     $f4, $f4, $f0
/* A9A0E8 80240B58 C6420014 */  lwc1      $f2, 0x14($s2)
/* A9A0EC 80240B5C 46020001 */  sub.s     $f0, $f0, $f2
/* A9A0F0 80240B60 E644003C */  swc1      $f4, 0x3c($s2)
/* A9A0F4 80240B64 080902F6 */  j         .L80240BD8
/* A9A0F8 80240B68 E640001C */   swc1     $f0, 0x1c($s2)
.L80240B6C:
/* A9A0FC 80240B6C AFA00014 */  sw        $zero, 0x14($sp)
/* A9A100 80240B70 8E450038 */  lw        $a1, 0x38($s2)
/* A9A104 80240B74 8E46003C */  lw        $a2, 0x3c($s2)
/* A9A108 80240B78 8E470040 */  lw        $a3, 0x40($s2)
/* A9A10C 80240B7C 0C01BECC */  jal       fx_walk
/* A9A110 80240B80 24040002 */   addiu    $a0, $zero, 2
/* A9A114 80240B84 3C01C47A */  lui       $at, 0xc47a
/* A9A118 80240B88 44810000 */  mtc1      $at, $f0
/* A9A11C 80240B8C AE60006C */  sw        $zero, 0x6c($s3)
/* A9A120 80240B90 8E420000 */  lw        $v0, ($s2)
/* A9A124 80240B94 0240202D */  daddu     $a0, $s2, $zero
/* A9A128 80240B98 AE400038 */  sw        $zero, 0x38($s2)
/* A9A12C 80240B9C AE400040 */  sw        $zero, 0x40($s2)
/* A9A130 80240BA0 AE40001C */  sw        $zero, 0x1c($s2)
/* A9A134 80240BA4 34420002 */  ori       $v0, $v0, 2
/* A9A138 80240BA8 E640003C */  swc1      $f0, 0x3c($s2)
/* A9A13C 80240BAC 0C00EAFF */  jal       disable_npc_shadow
/* A9A140 80240BB0 AE420000 */   sw       $v0, ($s2)
/* A9A144 80240BB4 8E420000 */  lw        $v0, ($s2)
/* A9A148 80240BB8 2403F7FF */  addiu     $v1, $zero, -0x801
/* A9A14C 80240BBC 00431024 */  and       $v0, $v0, $v1
/* A9A150 80240BC0 AE420000 */  sw        $v0, ($s2)
/* A9A154 80240BC4 8E620000 */  lw        $v0, ($s3)
/* A9A158 80240BC8 3C031F00 */  lui       $v1, 0x1f00
/* A9A15C 80240BCC 00431025 */  or        $v0, $v0, $v1
/* A9A160 80240BD0 AE620000 */  sw        $v0, ($s3)
/* A9A164 80240BD4 AEE00070 */  sw        $zero, 0x70($s7)
.L80240BD8:
/* A9A168 80240BD8 0000102D */  daddu     $v0, $zero, $zero
.L80240BDC:
/* A9A16C 80240BDC 8FBF0050 */  lw        $ra, 0x50($sp)
/* A9A170 80240BE0 8FB7004C */  lw        $s7, 0x4c($sp)
/* A9A174 80240BE4 8FB60048 */  lw        $s6, 0x48($sp)
/* A9A178 80240BE8 8FB50044 */  lw        $s5, 0x44($sp)
/* A9A17C 80240BEC 8FB40040 */  lw        $s4, 0x40($sp)
/* A9A180 80240BF0 8FB3003C */  lw        $s3, 0x3c($sp)
/* A9A184 80240BF4 8FB20038 */  lw        $s2, 0x38($sp)
/* A9A188 80240BF8 8FB10034 */  lw        $s1, 0x34($sp)
/* A9A18C 80240BFC 8FB00030 */  lw        $s0, 0x30($sp)
/* A9A190 80240C00 03E00008 */  jr        $ra
/* A9A194 80240C04 27BD0058 */   addiu    $sp, $sp, 0x58
