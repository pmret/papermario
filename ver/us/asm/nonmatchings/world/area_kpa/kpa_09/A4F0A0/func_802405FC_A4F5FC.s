.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405FC_A4F5FC
/* A4F5FC 802405FC 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* A4F600 80240600 AFB7004C */  sw        $s7, 0x4c($sp)
/* A4F604 80240604 0080B82D */  daddu     $s7, $a0, $zero
/* A4F608 80240608 AFB10034 */  sw        $s1, 0x34($sp)
/* A4F60C 8024060C 00A0882D */  daddu     $s1, $a1, $zero
/* A4F610 80240610 AFBF0050 */  sw        $ra, 0x50($sp)
/* A4F614 80240614 AFB60048 */  sw        $s6, 0x48($sp)
/* A4F618 80240618 AFB50044 */  sw        $s5, 0x44($sp)
/* A4F61C 8024061C AFB40040 */  sw        $s4, 0x40($sp)
/* A4F620 80240620 AFB3003C */  sw        $s3, 0x3c($sp)
/* A4F624 80240624 AFB20038 */  sw        $s2, 0x38($sp)
/* A4F628 80240628 AFB00030 */  sw        $s0, 0x30($sp)
/* A4F62C 8024062C 8EF30148 */  lw        $s3, 0x148($s7)
/* A4F630 80240630 86640008 */  lh        $a0, 8($s3)
/* A4F634 80240634 8EF0000C */  lw        $s0, 0xc($s7)
/* A4F638 80240638 0C00FB5A */  jal       get_enemy_safe
/* A4F63C 8024063C 0000B02D */   daddu    $s6, $zero, $zero
/* A4F640 80240640 10400131 */  beqz      $v0, .L80240B08
/* A4F644 80240644 24020005 */   addiu    $v0, $zero, 5
/* A4F648 80240648 8E63006C */  lw        $v1, 0x6c($s3)
/* A4F64C 8024064C 1062012F */  beq       $v1, $v0, .L80240B0C
/* A4F650 80240650 0000102D */   daddu    $v0, $zero, $zero
/* A4F654 80240654 8E050000 */  lw        $a1, ($s0)
/* A4F658 80240658 0C0B1EAF */  jal       evt_get_variable
/* A4F65C 8024065C 02E0202D */   daddu    $a0, $s7, $zero
/* A4F660 80240660 86640008 */  lh        $a0, 8($s3)
/* A4F664 80240664 0C00EABB */  jal       get_npc_unsafe
/* A4F668 80240668 0040A82D */   daddu    $s5, $v0, $zero
/* A4F66C 8024066C 8E630070 */  lw        $v1, 0x70($s3)
/* A4F670 80240670 30630002 */  andi      $v1, $v1, 2
/* A4F674 80240674 10600008 */  beqz      $v1, .L80240698
/* A4F678 80240678 0040902D */   daddu    $s2, $v0, $zero
/* A4F67C 8024067C 964200A8 */  lhu       $v0, 0xa8($s2)
/* A4F680 80240680 00021400 */  sll       $v0, $v0, 0x10
/* A4F684 80240684 00021C03 */  sra       $v1, $v0, 0x10
/* A4F688 80240688 000217C2 */  srl       $v0, $v0, 0x1f
/* A4F68C 8024068C 00621821 */  addu      $v1, $v1, $v0
/* A4F690 80240690 00031843 */  sra       $v1, $v1, 1
/* A4F694 80240694 A24300AB */  sb        $v1, 0xab($s2)
.L80240698:
/* A4F698 80240698 16200005 */  bnez      $s1, .L802406B0
/* A4F69C 8024069C 3C030004 */   lui      $v1, 4
/* A4F6A0 802406A0 8E6200B0 */  lw        $v0, 0xb0($s3)
/* A4F6A4 802406A4 30420004 */  andi      $v0, $v0, 4
/* A4F6A8 802406A8 10400019 */  beqz      $v0, .L80240710
/* A4F6AC 802406AC 00000000 */   nop
.L802406B0:
/* A4F6B0 802406B0 34630102 */  ori       $v1, $v1, 0x102
/* A4F6B4 802406B4 AEE00070 */  sw        $zero, 0x70($s7)
/* A4F6B8 802406B8 8E420000 */  lw        $v0, ($s2)
/* A4F6BC 802406BC 0240202D */  daddu     $a0, $s2, $zero
/* A4F6C0 802406C0 A640008E */  sh        $zero, 0x8e($s2)
/* A4F6C4 802406C4 00431025 */  or        $v0, $v0, $v1
/* A4F6C8 802406C8 0C00EAFF */  jal       disable_npc_shadow
/* A4F6CC 802406CC AE420000 */   sw       $v0, ($s2)
/* A4F6D0 802406D0 3C041F30 */  lui       $a0, 0x1f30
/* A4F6D4 802406D4 8E420000 */  lw        $v0, ($s2)
/* A4F6D8 802406D8 2403F7FF */  addiu     $v1, $zero, -0x801
/* A4F6DC 802406DC 00431024 */  and       $v0, $v0, $v1
/* A4F6E0 802406E0 AE420000 */  sw        $v0, ($s2)
/* A4F6E4 802406E4 8E620000 */  lw        $v0, ($s3)
/* A4F6E8 802406E8 8E6300B0 */  lw        $v1, 0xb0($s3)
/* A4F6EC 802406EC 34840040 */  ori       $a0, $a0, 0x40
/* A4F6F0 802406F0 AE60006C */  sw        $zero, 0x6c($s3)
/* A4F6F4 802406F4 00441025 */  or        $v0, $v0, $a0
/* A4F6F8 802406F8 AE620000 */  sw        $v0, ($s3)
/* A4F6FC 802406FC 30620004 */  andi      $v0, $v1, 4
/* A4F700 80240700 10400003 */  beqz      $v0, .L80240710
/* A4F704 80240704 2402FFFB */   addiu    $v0, $zero, -5
/* A4F708 80240708 00621024 */  and       $v0, $v1, $v0
/* A4F70C 8024070C AE6200B0 */  sw        $v0, 0xb0($s3)
.L80240710:
/* A4F710 80240710 8EE30070 */  lw        $v1, 0x70($s7)
/* A4F714 80240714 24100001 */  addiu     $s0, $zero, 1
/* A4F718 80240718 10700012 */  beq       $v1, $s0, .L80240764
/* A4F71C 8024071C 28620002 */   slti     $v0, $v1, 2
/* A4F720 80240720 10400005 */  beqz      $v0, .L80240738
/* A4F724 80240724 24020002 */   addiu    $v0, $zero, 2
/* A4F728 80240728 10600007 */  beqz      $v1, .L80240748
/* A4F72C 8024072C 0000102D */   daddu    $v0, $zero, $zero
/* A4F730 80240730 080902C3 */  j         .L80240B0C
/* A4F734 80240734 00000000 */   nop
.L80240738:
/* A4F738 80240738 1062005B */  beq       $v1, $v0, .L802408A8
/* A4F73C 8024073C 0000102D */   daddu    $v0, $zero, $zero
/* A4F740 80240740 080902C3 */  j         .L80240B0C
/* A4F744 80240744 00000000 */   nop
.L80240748:
/* A4F748 80240748 8E420000 */  lw        $v0, ($s2)
/* A4F74C 8024074C 0240202D */  daddu     $a0, $s2, $zero
/* A4F750 80240750 34420002 */  ori       $v0, $v0, 2
/* A4F754 80240754 0C00EAFF */  jal       disable_npc_shadow
/* A4F758 80240758 AE420000 */   sw       $v0, ($s2)
/* A4F75C 8024075C AE60006C */  sw        $zero, 0x6c($s3)
/* A4F760 80240760 AEF00070 */  sw        $s0, 0x70($s7)
.L80240764:
/* A4F764 80240764 8E74006C */  lw        $s4, 0x6c($s3)
/* A4F768 80240768 24020001 */  addiu     $v0, $zero, 1
/* A4F76C 8024076C 168200E7 */  bne       $s4, $v0, .L80240B0C
/* A4F770 80240770 0000102D */   daddu    $v0, $zero, $zero
/* A4F774 80240774 8E64007C */  lw        $a0, 0x7c($s3)
/* A4F778 80240778 24110002 */  addiu     $s1, $zero, 2
/* A4F77C 8024077C 0C00EABB */  jal       get_npc_unsafe
/* A4F780 80240780 AE71006C */   sw       $s1, 0x6c($s3)
/* A4F784 80240784 0040802D */  daddu     $s0, $v0, $zero
/* A4F788 80240788 C6000038 */  lwc1      $f0, 0x38($s0)
/* A4F78C 8024078C E6400038 */  swc1      $f0, 0x38($s2)
/* A4F790 80240790 C6000040 */  lwc1      $f0, 0x40($s0)
/* A4F794 80240794 E6400040 */  swc1      $f0, 0x40($s2)
/* A4F798 80240798 C6020034 */  lwc1      $f2, 0x34($s0)
/* A4F79C 8024079C 3C014387 */  lui       $at, 0x4387
/* A4F7A0 802407A0 44810000 */  mtc1      $at, $f0
/* A4F7A4 802407A4 26440038 */  addiu     $a0, $s2, 0x38
/* A4F7A8 802407A8 46020001 */  sub.s     $f0, $f0, $f2
/* A4F7AC 802407AC C6680078 */  lwc1      $f8, 0x78($s3)
/* A4F7B0 802407B0 46804220 */  cvt.s.w   $f8, $f8
/* A4F7B4 802407B4 44064000 */  mfc1      $a2, $f8
/* A4F7B8 802407B8 44070000 */  mfc1      $a3, $f0
/* A4F7BC 802407BC 0C00A7E7 */  jal       add_vec2D_polar
/* A4F7C0 802407C0 26450040 */   addiu    $a1, $s2, 0x40
/* A4F7C4 802407C4 C600003C */  lwc1      $f0, 0x3c($s0)
/* A4F7C8 802407C8 C6620074 */  lwc1      $f2, 0x74($s3)
/* A4F7CC 802407CC 468010A0 */  cvt.s.w   $f2, $f2
/* A4F7D0 802407D0 46020000 */  add.s     $f0, $f0, $f2
/* A4F7D4 802407D4 E640003C */  swc1      $f0, 0x3c($s2)
/* A4F7D8 802407D8 A2740007 */  sb        $s4, 7($s3)
/* A4F7DC 802407DC C6400038 */  lwc1      $f0, 0x38($s2)
/* A4F7E0 802407E0 4600020D */  trunc.w.s $f8, $f0
/* A4F7E4 802407E4 44024000 */  mfc1      $v0, $f8
/* A4F7E8 802407E8 00000000 */  nop
/* A4F7EC 802407EC A6620010 */  sh        $v0, 0x10($s3)
/* A4F7F0 802407F0 C640003C */  lwc1      $f0, 0x3c($s2)
/* A4F7F4 802407F4 4600020D */  trunc.w.s $f8, $f0
/* A4F7F8 802407F8 44024000 */  mfc1      $v0, $f8
/* A4F7FC 802407FC 00000000 */  nop
/* A4F800 80240800 A6620012 */  sh        $v0, 0x12($s3)
/* A4F804 80240804 C6400040 */  lwc1      $f0, 0x40($s2)
/* A4F808 80240808 4600020D */  trunc.w.s $f8, $f0
/* A4F80C 8024080C 44024000 */  mfc1      $v0, $f8
/* A4F810 80240810 00000000 */  nop
/* A4F814 80240814 A6620014 */  sh        $v0, 0x14($s3)
/* A4F818 80240818 AE400044 */  sw        $zero, 0x44($s2)
/* A4F81C 8024081C AE400048 */  sw        $zero, 0x48($s2)
/* A4F820 80240820 AE40004C */  sw        $zero, 0x4c($s2)
/* A4F824 80240824 C6A00000 */  lwc1      $f0, ($s5)
/* A4F828 80240828 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A4F82C 8024082C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A4F830 80240830 C64C0038 */  lwc1      $f12, 0x38($s2)
/* A4F834 80240834 C64E0040 */  lwc1      $f14, 0x40($s2)
/* A4F838 80240838 E6400018 */  swc1      $f0, 0x18($s2)
/* A4F83C 8024083C 8C460028 */  lw        $a2, 0x28($v0)
/* A4F840 80240840 0C00A720 */  jal       atan2
/* A4F844 80240844 8C470030 */   lw       $a3, 0x30($v0)
/* A4F848 80240848 E640000C */  swc1      $f0, 0xc($s2)
/* A4F84C 8024084C C6A0000C */  lwc1      $f0, 0xc($s5)
/* A4F850 80240850 8E420000 */  lw        $v0, ($s2)
/* A4F854 80240854 0240202D */  daddu     $a0, $s2, $zero
/* A4F858 80240858 E640001C */  swc1      $f0, 0x1c($s2)
/* A4F85C 8024085C C6A00010 */  lwc1      $f0, 0x10($s5)
/* A4F860 80240860 2403FFFD */  addiu     $v1, $zero, -3
/* A4F864 80240864 E6400014 */  swc1      $f0, 0x14($s2)
/* A4F868 80240868 C600003C */  lwc1      $f0, 0x3c($s0)
/* A4F86C 8024086C 00431024 */  and       $v0, $v0, $v1
/* A4F870 80240870 AE420000 */  sw        $v0, ($s2)
/* A4F874 80240874 0C00EAE8 */  jal       enable_npc_shadow
/* A4F878 80240878 E6400064 */   swc1     $f0, 0x64($s2)
/* A4F87C 8024087C 8E420000 */  lw        $v0, ($s2)
/* A4F880 80240880 3C03E0FF */  lui       $v1, 0xe0ff
/* A4F884 80240884 34420800 */  ori       $v0, $v0, 0x800
/* A4F888 80240888 AE420000 */  sw        $v0, ($s2)
/* A4F88C 8024088C 8E620000 */  lw        $v0, ($s3)
/* A4F890 80240890 3463FFFF */  ori       $v1, $v1, 0xffff
/* A4F894 80240894 00431024 */  and       $v0, $v0, $v1
/* A4F898 80240898 AE620000 */  sw        $v0, ($s3)
/* A4F89C 8024089C 2402005A */  addiu     $v0, $zero, 0x5a
/* A4F8A0 802408A0 A642008E */  sh        $v0, 0x8e($s2)
/* A4F8A4 802408A4 AEF10070 */  sw        $s1, 0x70($s7)
.L802408A8:
/* A4F8A8 802408A8 0000202D */  daddu     $a0, $zero, $zero
/* A4F8AC 802408AC 27B00020 */  addiu     $s0, $sp, 0x20
/* A4F8B0 802408B0 864200A8 */  lh        $v0, 0xa8($s2)
/* A4F8B4 802408B4 3C013FE0 */  lui       $at, 0x3fe0
/* A4F8B8 802408B8 44810800 */  mtc1      $at, $f1
/* A4F8BC 802408BC 44800000 */  mtc1      $zero, $f0
/* A4F8C0 802408C0 44821000 */  mtc1      $v0, $f2
/* A4F8C4 802408C4 00000000 */  nop
/* A4F8C8 802408C8 468010A1 */  cvt.d.w   $f2, $f2
/* A4F8CC 802408CC 46201082 */  mul.d     $f2, $f2, $f0
/* A4F8D0 802408D0 00000000 */  nop
/* A4F8D4 802408D4 0200282D */  daddu     $a1, $s0, $zero
/* A4F8D8 802408D8 C6440038 */  lwc1      $f4, 0x38($s2)
/* A4F8DC 802408DC C640003C */  lwc1      $f0, 0x3c($s2)
/* A4F8E0 802408E0 27B10024 */  addiu     $s1, $sp, 0x24
/* A4F8E4 802408E4 E7A40020 */  swc1      $f4, 0x20($sp)
/* A4F8E8 802408E8 C6440040 */  lwc1      $f4, 0x40($s2)
/* A4F8EC 802408EC 46000021 */  cvt.d.s   $f0, $f0
/* A4F8F0 802408F0 46220000 */  add.d     $f0, $f0, $f2
/* A4F8F4 802408F4 E7A40028 */  swc1      $f4, 0x28($sp)
/* A4F8F8 802408F8 C6420018 */  lwc1      $f2, 0x18($s2)
/* A4F8FC 802408FC 46200020 */  cvt.s.d   $f0, $f0
/* A4F900 80240900 E7A00024 */  swc1      $f0, 0x24($sp)
/* A4F904 80240904 E7A20010 */  swc1      $f2, 0x10($sp)
/* A4F908 80240908 C640000C */  lwc1      $f0, 0xc($s2)
/* A4F90C 8024090C 0220302D */  daddu     $a2, $s1, $zero
/* A4F910 80240910 E7A00014 */  swc1      $f0, 0x14($sp)
/* A4F914 80240914 864200A6 */  lh        $v0, 0xa6($s2)
/* A4F918 80240918 27B40028 */  addiu     $s4, $sp, 0x28
/* A4F91C 8024091C 44820000 */  mtc1      $v0, $f0
/* A4F920 80240920 00000000 */  nop
/* A4F924 80240924 46800020 */  cvt.s.w   $f0, $f0
/* A4F928 80240928 E7A00018 */  swc1      $f0, 0x18($sp)
/* A4F92C 8024092C 864200A8 */  lh        $v0, 0xa8($s2)
/* A4F930 80240930 0280382D */  daddu     $a3, $s4, $zero
/* A4F934 80240934 44820000 */  mtc1      $v0, $f0
/* A4F938 80240938 00000000 */  nop
/* A4F93C 8024093C 46800020 */  cvt.s.w   $f0, $f0
/* A4F940 80240940 0C0376B9 */  jal       npc_test_move_taller_with_slipping
/* A4F944 80240944 E7A0001C */   swc1     $f0, 0x1c($sp)
/* A4F948 80240948 54400001 */  bnel      $v0, $zero, .L80240950
/* A4F94C 8024094C 24160001 */   addiu    $s6, $zero, 1
.L80240950:
/* A4F950 80240950 0200282D */  daddu     $a1, $s0, $zero
/* A4F954 80240954 0220302D */  daddu     $a2, $s1, $zero
/* A4F958 80240958 C6400038 */  lwc1      $f0, 0x38($s2)
/* A4F95C 8024095C C642003C */  lwc1      $f2, 0x3c($s2)
/* A4F960 80240960 C6440040 */  lwc1      $f4, 0x40($s2)
/* A4F964 80240964 3C01447A */  lui       $at, 0x447a
/* A4F968 80240968 44813000 */  mtc1      $at, $f6
/* A4F96C 8024096C 27A2002C */  addiu     $v0, $sp, 0x2c
/* A4F970 80240970 E7A00020 */  swc1      $f0, 0x20($sp)
/* A4F974 80240974 E7A20024 */  swc1      $f2, 0x24($sp)
/* A4F978 80240978 E7A40028 */  swc1      $f4, 0x28($sp)
/* A4F97C 8024097C E7A6002C */  swc1      $f6, 0x2c($sp)
/* A4F980 80240980 AFA20010 */  sw        $v0, 0x10($sp)
/* A4F984 80240984 8E440080 */  lw        $a0, 0x80($s2)
/* A4F988 80240988 0C0372DF */  jal       npc_raycast_down_sides
/* A4F98C 8024098C 0280382D */   daddu    $a3, $s4, $zero
/* A4F990 80240990 10400019 */  beqz      $v0, .L802409F8
/* A4F994 80240994 00000000 */   nop
/* A4F998 80240998 C640001C */  lwc1      $f0, 0x1c($s2)
/* A4F99C 8024099C C7A2002C */  lwc1      $f2, 0x2c($sp)
/* A4F9A0 802409A0 46000005 */  abs.s     $f0, $f0
/* A4F9A4 802409A4 4600103C */  c.lt.s    $f2, $f0
/* A4F9A8 802409A8 00000000 */  nop
/* A4F9AC 802409AC 45000012 */  bc1f      .L802409F8
/* A4F9B0 802409B0 00000000 */   nop
/* A4F9B4 802409B4 C7A40024 */  lwc1      $f4, 0x24($sp)
/* A4F9B8 802409B8 C6400064 */  lwc1      $f0, 0x64($s2)
/* A4F9BC 802409BC 46002001 */  sub.s     $f0, $f4, $f0
/* A4F9C0 802409C0 3C014034 */  lui       $at, 0x4034
/* A4F9C4 802409C4 44811800 */  mtc1      $at, $f3
/* A4F9C8 802409C8 44801000 */  mtc1      $zero, $f2
/* A4F9CC 802409CC 46000005 */  abs.s     $f0, $f0
/* A4F9D0 802409D0 46000021 */  cvt.d.s   $f0, $f0
/* A4F9D4 802409D4 4622003C */  c.lt.d    $f0, $f2
/* A4F9D8 802409D8 00000000 */  nop
/* A4F9DC 802409DC 45000006 */  bc1f      .L802409F8
/* A4F9E0 802409E0 0240202D */   daddu    $a0, $s2, $zero
/* A4F9E4 802409E4 8E450018 */  lw        $a1, 0x18($s2)
/* A4F9E8 802409E8 8E46000C */  lw        $a2, 0xc($s2)
/* A4F9EC 802409EC 2416000A */  addiu     $s6, $zero, 0xa
/* A4F9F0 802409F0 0C00EA95 */  jal       npc_move_heading
/* A4F9F4 802409F4 E644003C */   swc1     $f4, 0x3c($s2)
.L802409F8:
/* A4F9F8 802409F8 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* A4F9FC 802409FC 3C013FF0 */  lui       $at, 0x3ff0
/* A4FA00 80240A00 44811800 */  mtc1      $at, $f3
/* A4FA04 80240A04 44801000 */  mtc1      $zero, $f2
/* A4FA08 80240A08 46000021 */  cvt.d.s   $f0, $f0
/* A4FA0C 80240A0C 4622003C */  c.lt.d    $f0, $f2
/* A4FA10 80240A10 00000000 */  nop
/* A4FA14 80240A14 45030001 */  bc1tl     .L80240A1C
/* A4FA18 80240A18 2416000B */   addiu    $s6, $zero, 0xb
.L80240A1C:
/* A4FA1C 80240A1C 9642008E */  lhu       $v0, 0x8e($s2)
/* A4FA20 80240A20 2442FFFF */  addiu     $v0, $v0, -1
/* A4FA24 80240A24 A642008E */  sh        $v0, 0x8e($s2)
/* A4FA28 80240A28 00021400 */  sll       $v0, $v0, 0x10
/* A4FA2C 80240A2C 58400001 */  blezl     $v0, .L80240A34
/* A4FA30 80240A30 24160014 */   addiu    $s6, $zero, 0x14
.L80240A34:
/* A4FA34 80240A34 56C00019 */  bnel      $s6, $zero, .L80240A9C
/* A4FA38 80240A38 AFA00010 */   sw       $zero, 0x10($sp)
/* A4FA3C 80240A3C 8E620070 */  lw        $v0, 0x70($s3)
/* A4FA40 80240A40 30420001 */  andi      $v0, $v0, 1
/* A4FA44 80240A44 10400009 */  beqz      $v0, .L80240A6C
/* A4FA48 80240A48 00000000 */   nop
/* A4FA4C 80240A4C C640004C */  lwc1      $f0, 0x4c($s2)
/* A4FA50 80240A50 3C014044 */  lui       $at, 0x4044
/* A4FA54 80240A54 44811800 */  mtc1      $at, $f3
/* A4FA58 80240A58 44801000 */  mtc1      $zero, $f2
/* A4FA5C 80240A5C 46000021 */  cvt.d.s   $f0, $f0
/* A4FA60 80240A60 46220000 */  add.d     $f0, $f0, $f2
/* A4FA64 80240A64 46200020 */  cvt.s.d   $f0, $f0
/* A4FA68 80240A68 E640004C */  swc1      $f0, 0x4c($s2)
.L80240A6C:
/* A4FA6C 80240A6C 8E450018 */  lw        $a1, 0x18($s2)
/* A4FA70 80240A70 8E46000C */  lw        $a2, 0xc($s2)
/* A4FA74 80240A74 0C00EA95 */  jal       npc_move_heading
/* A4FA78 80240A78 0240202D */   daddu    $a0, $s2, $zero
/* A4FA7C 80240A7C C644003C */  lwc1      $f4, 0x3c($s2)
/* A4FA80 80240A80 C640001C */  lwc1      $f0, 0x1c($s2)
/* A4FA84 80240A84 46002100 */  add.s     $f4, $f4, $f0
/* A4FA88 80240A88 C6420014 */  lwc1      $f2, 0x14($s2)
/* A4FA8C 80240A8C 46020001 */  sub.s     $f0, $f0, $f2
/* A4FA90 80240A90 E644003C */  swc1      $f4, 0x3c($s2)
/* A4FA94 80240A94 080902C2 */  j         .L80240B08
/* A4FA98 80240A98 E640001C */   swc1     $f0, 0x1c($s2)
.L80240A9C:
/* A4FA9C 80240A9C AFA00014 */  sw        $zero, 0x14($sp)
/* A4FAA0 80240AA0 8E450038 */  lw        $a1, 0x38($s2)
/* A4FAA4 80240AA4 8E46003C */  lw        $a2, 0x3c($s2)
/* A4FAA8 80240AA8 8E470040 */  lw        $a3, 0x40($s2)
/* A4FAAC 80240AAC 0C01BECC */  jal       fx_walk
/* A4FAB0 80240AB0 24040002 */   addiu    $a0, $zero, 2
/* A4FAB4 80240AB4 3C01C47A */  lui       $at, 0xc47a
/* A4FAB8 80240AB8 44810000 */  mtc1      $at, $f0
/* A4FABC 80240ABC AE60006C */  sw        $zero, 0x6c($s3)
/* A4FAC0 80240AC0 8E420000 */  lw        $v0, ($s2)
/* A4FAC4 80240AC4 0240202D */  daddu     $a0, $s2, $zero
/* A4FAC8 80240AC8 AE400038 */  sw        $zero, 0x38($s2)
/* A4FACC 80240ACC AE400040 */  sw        $zero, 0x40($s2)
/* A4FAD0 80240AD0 AE40001C */  sw        $zero, 0x1c($s2)
/* A4FAD4 80240AD4 34420002 */  ori       $v0, $v0, 2
/* A4FAD8 80240AD8 E640003C */  swc1      $f0, 0x3c($s2)
/* A4FADC 80240ADC 0C00EAFF */  jal       disable_npc_shadow
/* A4FAE0 80240AE0 AE420000 */   sw       $v0, ($s2)
/* A4FAE4 80240AE4 8E420000 */  lw        $v0, ($s2)
/* A4FAE8 80240AE8 2403F7FF */  addiu     $v1, $zero, -0x801
/* A4FAEC 80240AEC 00431024 */  and       $v0, $v0, $v1
/* A4FAF0 80240AF0 AE420000 */  sw        $v0, ($s2)
/* A4FAF4 80240AF4 8E620000 */  lw        $v0, ($s3)
/* A4FAF8 80240AF8 3C031F00 */  lui       $v1, 0x1f00
/* A4FAFC 80240AFC 00431025 */  or        $v0, $v0, $v1
/* A4FB00 80240B00 AE620000 */  sw        $v0, ($s3)
/* A4FB04 80240B04 AEE00070 */  sw        $zero, 0x70($s7)
.L80240B08:
/* A4FB08 80240B08 0000102D */  daddu     $v0, $zero, $zero
.L80240B0C:
/* A4FB0C 80240B0C 8FBF0050 */  lw        $ra, 0x50($sp)
/* A4FB10 80240B10 8FB7004C */  lw        $s7, 0x4c($sp)
/* A4FB14 80240B14 8FB60048 */  lw        $s6, 0x48($sp)
/* A4FB18 80240B18 8FB50044 */  lw        $s5, 0x44($sp)
/* A4FB1C 80240B1C 8FB40040 */  lw        $s4, 0x40($sp)
/* A4FB20 80240B20 8FB3003C */  lw        $s3, 0x3c($sp)
/* A4FB24 80240B24 8FB20038 */  lw        $s2, 0x38($sp)
/* A4FB28 80240B28 8FB10034 */  lw        $s1, 0x34($sp)
/* A4FB2C 80240B2C 8FB00030 */  lw        $s0, 0x30($sp)
/* A4FB30 80240B30 03E00008 */  jr        $ra
/* A4FB34 80240B34 27BD0058 */   addiu    $sp, $sp, 0x58
