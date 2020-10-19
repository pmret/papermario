.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406CC_A9F40C
/* A9F40C 802406CC 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* A9F410 802406D0 AFB7004C */  sw        $s7, 0x4c($sp)
/* A9F414 802406D4 0080B82D */  daddu     $s7, $a0, $zero
/* A9F418 802406D8 AFB10034 */  sw        $s1, 0x34($sp)
/* A9F41C 802406DC 00A0882D */  daddu     $s1, $a1, $zero
/* A9F420 802406E0 AFBF0050 */  sw        $ra, 0x50($sp)
/* A9F424 802406E4 AFB60048 */  sw        $s6, 0x48($sp)
/* A9F428 802406E8 AFB50044 */  sw        $s5, 0x44($sp)
/* A9F42C 802406EC AFB40040 */  sw        $s4, 0x40($sp)
/* A9F430 802406F0 AFB3003C */  sw        $s3, 0x3c($sp)
/* A9F434 802406F4 AFB20038 */  sw        $s2, 0x38($sp)
/* A9F438 802406F8 AFB00030 */  sw        $s0, 0x30($sp)
/* A9F43C 802406FC 8EF30148 */  lw        $s3, 0x148($s7)
/* A9F440 80240700 86640008 */  lh        $a0, 8($s3)
/* A9F444 80240704 8EF0000C */  lw        $s0, 0xc($s7)
/* A9F448 80240708 0C00FB5A */  jal       get_enemy_safe
/* A9F44C 8024070C 0000B02D */   daddu    $s6, $zero, $zero
/* A9F450 80240710 10400131 */  beqz      $v0, .L80240BD8
/* A9F454 80240714 24020005 */   addiu    $v0, $zero, 5
/* A9F458 80240718 8E63006C */  lw        $v1, 0x6c($s3)
/* A9F45C 8024071C 1062012F */  beq       $v1, $v0, .L80240BDC
/* A9F460 80240720 0000102D */   daddu    $v0, $zero, $zero
/* A9F464 80240724 8E050000 */  lw        $a1, ($s0)
/* A9F468 80240728 0C0B1EAF */  jal       get_variable
/* A9F46C 8024072C 02E0202D */   daddu    $a0, $s7, $zero
/* A9F470 80240730 86640008 */  lh        $a0, 8($s3)
/* A9F474 80240734 0C00EABB */  jal       get_npc_unsafe
/* A9F478 80240738 0040A82D */   daddu    $s5, $v0, $zero
/* A9F47C 8024073C 8E630070 */  lw        $v1, 0x70($s3)
/* A9F480 80240740 30630002 */  andi      $v1, $v1, 2
/* A9F484 80240744 10600008 */  beqz      $v1, .L80240768
/* A9F488 80240748 0040902D */   daddu    $s2, $v0, $zero
/* A9F48C 8024074C 964200A8 */  lhu       $v0, 0xa8($s2)
/* A9F490 80240750 00021400 */  sll       $v0, $v0, 0x10
/* A9F494 80240754 00021C03 */  sra       $v1, $v0, 0x10
/* A9F498 80240758 000217C2 */  srl       $v0, $v0, 0x1f
/* A9F49C 8024075C 00621821 */  addu      $v1, $v1, $v0
/* A9F4A0 80240760 00031843 */  sra       $v1, $v1, 1
/* A9F4A4 80240764 A24300AB */  sb        $v1, 0xab($s2)
.L80240768:
/* A9F4A8 80240768 16200005 */  bnez      $s1, .L80240780
/* A9F4AC 8024076C 3C030004 */   lui      $v1, 4
/* A9F4B0 80240770 8E6200B0 */  lw        $v0, 0xb0($s3)
/* A9F4B4 80240774 30420004 */  andi      $v0, $v0, 4
/* A9F4B8 80240778 10400019 */  beqz      $v0, .L802407E0
/* A9F4BC 8024077C 00000000 */   nop      
.L80240780:
/* A9F4C0 80240780 34630102 */  ori       $v1, $v1, 0x102
/* A9F4C4 80240784 AEE00070 */  sw        $zero, 0x70($s7)
/* A9F4C8 80240788 8E420000 */  lw        $v0, ($s2)
/* A9F4CC 8024078C 0240202D */  daddu     $a0, $s2, $zero
/* A9F4D0 80240790 A640008E */  sh        $zero, 0x8e($s2)
/* A9F4D4 80240794 00431025 */  or        $v0, $v0, $v1
/* A9F4D8 80240798 0C00EAFF */  jal       disable_npc_shadow
/* A9F4DC 8024079C AE420000 */   sw       $v0, ($s2)
/* A9F4E0 802407A0 3C041F30 */  lui       $a0, 0x1f30
/* A9F4E4 802407A4 8E420000 */  lw        $v0, ($s2)
/* A9F4E8 802407A8 2403F7FF */  addiu     $v1, $zero, -0x801
/* A9F4EC 802407AC 00431024 */  and       $v0, $v0, $v1
/* A9F4F0 802407B0 AE420000 */  sw        $v0, ($s2)
/* A9F4F4 802407B4 8E620000 */  lw        $v0, ($s3)
/* A9F4F8 802407B8 8E6300B0 */  lw        $v1, 0xb0($s3)
/* A9F4FC 802407BC 34840040 */  ori       $a0, $a0, 0x40
/* A9F500 802407C0 AE60006C */  sw        $zero, 0x6c($s3)
/* A9F504 802407C4 00441025 */  or        $v0, $v0, $a0
/* A9F508 802407C8 AE620000 */  sw        $v0, ($s3)
/* A9F50C 802407CC 30620004 */  andi      $v0, $v1, 4
/* A9F510 802407D0 10400003 */  beqz      $v0, .L802407E0
/* A9F514 802407D4 2402FFFB */   addiu    $v0, $zero, -5
/* A9F518 802407D8 00621024 */  and       $v0, $v1, $v0
/* A9F51C 802407DC AE6200B0 */  sw        $v0, 0xb0($s3)
.L802407E0:
/* A9F520 802407E0 8EE30070 */  lw        $v1, 0x70($s7)
/* A9F524 802407E4 24100001 */  addiu     $s0, $zero, 1
/* A9F528 802407E8 10700012 */  beq       $v1, $s0, .L80240834
/* A9F52C 802407EC 28620002 */   slti     $v0, $v1, 2
/* A9F530 802407F0 10400005 */  beqz      $v0, .L80240808
/* A9F534 802407F4 24020002 */   addiu    $v0, $zero, 2
/* A9F538 802407F8 10600007 */  beqz      $v1, .L80240818
/* A9F53C 802407FC 0000102D */   daddu    $v0, $zero, $zero
/* A9F540 80240800 080902F7 */  j         .L80240BDC
/* A9F544 80240804 00000000 */   nop      
.L80240808:
/* A9F548 80240808 1062005B */  beq       $v1, $v0, .L80240978
/* A9F54C 8024080C 0000102D */   daddu    $v0, $zero, $zero
/* A9F550 80240810 080902F7 */  j         .L80240BDC
/* A9F554 80240814 00000000 */   nop      
.L80240818:
/* A9F558 80240818 8E420000 */  lw        $v0, ($s2)
/* A9F55C 8024081C 0240202D */  daddu     $a0, $s2, $zero
/* A9F560 80240820 34420002 */  ori       $v0, $v0, 2
/* A9F564 80240824 0C00EAFF */  jal       disable_npc_shadow
/* A9F568 80240828 AE420000 */   sw       $v0, ($s2)
/* A9F56C 8024082C AE60006C */  sw        $zero, 0x6c($s3)
/* A9F570 80240830 AEF00070 */  sw        $s0, 0x70($s7)
.L80240834:
/* A9F574 80240834 8E74006C */  lw        $s4, 0x6c($s3)
/* A9F578 80240838 24020001 */  addiu     $v0, $zero, 1
/* A9F57C 8024083C 168200E7 */  bne       $s4, $v0, .L80240BDC
/* A9F580 80240840 0000102D */   daddu    $v0, $zero, $zero
/* A9F584 80240844 8E64007C */  lw        $a0, 0x7c($s3)
/* A9F588 80240848 24110002 */  addiu     $s1, $zero, 2
/* A9F58C 8024084C 0C00EABB */  jal       get_npc_unsafe
/* A9F590 80240850 AE71006C */   sw       $s1, 0x6c($s3)
/* A9F594 80240854 0040802D */  daddu     $s0, $v0, $zero
/* A9F598 80240858 C6000038 */  lwc1      $f0, 0x38($s0)
/* A9F59C 8024085C E6400038 */  swc1      $f0, 0x38($s2)
/* A9F5A0 80240860 C6000040 */  lwc1      $f0, 0x40($s0)
/* A9F5A4 80240864 E6400040 */  swc1      $f0, 0x40($s2)
/* A9F5A8 80240868 C6020034 */  lwc1      $f2, 0x34($s0)
/* A9F5AC 8024086C 3C014387 */  lui       $at, 0x4387
/* A9F5B0 80240870 44810000 */  mtc1      $at, $f0
/* A9F5B4 80240874 26440038 */  addiu     $a0, $s2, 0x38
/* A9F5B8 80240878 46020001 */  sub.s     $f0, $f0, $f2
/* A9F5BC 8024087C C6680078 */  lwc1      $f8, 0x78($s3)
/* A9F5C0 80240880 46804220 */  cvt.s.w   $f8, $f8
/* A9F5C4 80240884 44064000 */  mfc1      $a2, $f8
/* A9F5C8 80240888 44070000 */  mfc1      $a3, $f0
/* A9F5CC 8024088C 0C00A7E7 */  jal       add_vec2D_polar
/* A9F5D0 80240890 26450040 */   addiu    $a1, $s2, 0x40
/* A9F5D4 80240894 C600003C */  lwc1      $f0, 0x3c($s0)
/* A9F5D8 80240898 C6620074 */  lwc1      $f2, 0x74($s3)
/* A9F5DC 8024089C 468010A0 */  cvt.s.w   $f2, $f2
/* A9F5E0 802408A0 46020000 */  add.s     $f0, $f0, $f2
/* A9F5E4 802408A4 E640003C */  swc1      $f0, 0x3c($s2)
/* A9F5E8 802408A8 A2740007 */  sb        $s4, 7($s3)
/* A9F5EC 802408AC C6400038 */  lwc1      $f0, 0x38($s2)
/* A9F5F0 802408B0 4600020D */  trunc.w.s $f8, $f0
/* A9F5F4 802408B4 44024000 */  mfc1      $v0, $f8
/* A9F5F8 802408B8 00000000 */  nop       
/* A9F5FC 802408BC A6620010 */  sh        $v0, 0x10($s3)
/* A9F600 802408C0 C640003C */  lwc1      $f0, 0x3c($s2)
/* A9F604 802408C4 4600020D */  trunc.w.s $f8, $f0
/* A9F608 802408C8 44024000 */  mfc1      $v0, $f8
/* A9F60C 802408CC 00000000 */  nop       
/* A9F610 802408D0 A6620012 */  sh        $v0, 0x12($s3)
/* A9F614 802408D4 C6400040 */  lwc1      $f0, 0x40($s2)
/* A9F618 802408D8 4600020D */  trunc.w.s $f8, $f0
/* A9F61C 802408DC 44024000 */  mfc1      $v0, $f8
/* A9F620 802408E0 00000000 */  nop       
/* A9F624 802408E4 A6620014 */  sh        $v0, 0x14($s3)
/* A9F628 802408E8 AE400044 */  sw        $zero, 0x44($s2)
/* A9F62C 802408EC AE400048 */  sw        $zero, 0x48($s2)
/* A9F630 802408F0 AE40004C */  sw        $zero, 0x4c($s2)
/* A9F634 802408F4 C6A00000 */  lwc1      $f0, ($s5)
/* A9F638 802408F8 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A9F63C 802408FC 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A9F640 80240900 C64C0038 */  lwc1      $f12, 0x38($s2)
/* A9F644 80240904 C64E0040 */  lwc1      $f14, 0x40($s2)
/* A9F648 80240908 E6400018 */  swc1      $f0, 0x18($s2)
/* A9F64C 8024090C 8C460028 */  lw        $a2, 0x28($v0)
/* A9F650 80240910 0C00A720 */  jal       atan2
/* A9F654 80240914 8C470030 */   lw       $a3, 0x30($v0)
/* A9F658 80240918 E640000C */  swc1      $f0, 0xc($s2)
/* A9F65C 8024091C C6A0000C */  lwc1      $f0, 0xc($s5)
/* A9F660 80240920 8E420000 */  lw        $v0, ($s2)
/* A9F664 80240924 0240202D */  daddu     $a0, $s2, $zero
/* A9F668 80240928 E640001C */  swc1      $f0, 0x1c($s2)
/* A9F66C 8024092C C6A00010 */  lwc1      $f0, 0x10($s5)
/* A9F670 80240930 2403FFFD */  addiu     $v1, $zero, -3
/* A9F674 80240934 E6400014 */  swc1      $f0, 0x14($s2)
/* A9F678 80240938 C600003C */  lwc1      $f0, 0x3c($s0)
/* A9F67C 8024093C 00431024 */  and       $v0, $v0, $v1
/* A9F680 80240940 AE420000 */  sw        $v0, ($s2)
/* A9F684 80240944 0C00EAE8 */  jal       enable_npc_shadow
/* A9F688 80240948 E6400064 */   swc1     $f0, 0x64($s2)
/* A9F68C 8024094C 8E420000 */  lw        $v0, ($s2)
/* A9F690 80240950 3C03E0FF */  lui       $v1, 0xe0ff
/* A9F694 80240954 34420800 */  ori       $v0, $v0, 0x800
/* A9F698 80240958 AE420000 */  sw        $v0, ($s2)
/* A9F69C 8024095C 8E620000 */  lw        $v0, ($s3)
/* A9F6A0 80240960 3463FFFF */  ori       $v1, $v1, 0xffff
/* A9F6A4 80240964 00431024 */  and       $v0, $v0, $v1
/* A9F6A8 80240968 AE620000 */  sw        $v0, ($s3)
/* A9F6AC 8024096C 2402005A */  addiu     $v0, $zero, 0x5a
/* A9F6B0 80240970 A642008E */  sh        $v0, 0x8e($s2)
/* A9F6B4 80240974 AEF10070 */  sw        $s1, 0x70($s7)
.L80240978:
/* A9F6B8 80240978 0000202D */  daddu     $a0, $zero, $zero
/* A9F6BC 8024097C 27B00020 */  addiu     $s0, $sp, 0x20
/* A9F6C0 80240980 864200A8 */  lh        $v0, 0xa8($s2)
/* A9F6C4 80240984 3C013FE0 */  lui       $at, 0x3fe0
/* A9F6C8 80240988 44810800 */  mtc1      $at, $f1
/* A9F6CC 8024098C 44800000 */  mtc1      $zero, $f0
/* A9F6D0 80240990 44821000 */  mtc1      $v0, $f2
/* A9F6D4 80240994 00000000 */  nop       
/* A9F6D8 80240998 468010A1 */  cvt.d.w   $f2, $f2
/* A9F6DC 8024099C 46201082 */  mul.d     $f2, $f2, $f0
/* A9F6E0 802409A0 00000000 */  nop       
/* A9F6E4 802409A4 0200282D */  daddu     $a1, $s0, $zero
/* A9F6E8 802409A8 C6440038 */  lwc1      $f4, 0x38($s2)
/* A9F6EC 802409AC C640003C */  lwc1      $f0, 0x3c($s2)
/* A9F6F0 802409B0 27B10024 */  addiu     $s1, $sp, 0x24
/* A9F6F4 802409B4 E7A40020 */  swc1      $f4, 0x20($sp)
/* A9F6F8 802409B8 C6440040 */  lwc1      $f4, 0x40($s2)
/* A9F6FC 802409BC 46000021 */  cvt.d.s   $f0, $f0
/* A9F700 802409C0 46220000 */  add.d     $f0, $f0, $f2
/* A9F704 802409C4 E7A40028 */  swc1      $f4, 0x28($sp)
/* A9F708 802409C8 C6420018 */  lwc1      $f2, 0x18($s2)
/* A9F70C 802409CC 46200020 */  cvt.s.d   $f0, $f0
/* A9F710 802409D0 E7A00024 */  swc1      $f0, 0x24($sp)
/* A9F714 802409D4 E7A20010 */  swc1      $f2, 0x10($sp)
/* A9F718 802409D8 C640000C */  lwc1      $f0, 0xc($s2)
/* A9F71C 802409DC 0220302D */  daddu     $a2, $s1, $zero
/* A9F720 802409E0 E7A00014 */  swc1      $f0, 0x14($sp)
/* A9F724 802409E4 864200A6 */  lh        $v0, 0xa6($s2)
/* A9F728 802409E8 27B40028 */  addiu     $s4, $sp, 0x28
/* A9F72C 802409EC 44820000 */  mtc1      $v0, $f0
/* A9F730 802409F0 00000000 */  nop       
/* A9F734 802409F4 46800020 */  cvt.s.w   $f0, $f0
/* A9F738 802409F8 E7A00018 */  swc1      $f0, 0x18($sp)
/* A9F73C 802409FC 864200A8 */  lh        $v0, 0xa8($s2)
/* A9F740 80240A00 0280382D */  daddu     $a3, $s4, $zero
/* A9F744 80240A04 44820000 */  mtc1      $v0, $f0
/* A9F748 80240A08 00000000 */  nop       
/* A9F74C 80240A0C 46800020 */  cvt.s.w   $f0, $f0
/* A9F750 80240A10 0C0376B9 */  jal       func_800DDAE4
/* A9F754 80240A14 E7A0001C */   swc1     $f0, 0x1c($sp)
/* A9F758 80240A18 54400001 */  bnel      $v0, $zero, .L80240A20
/* A9F75C 80240A1C 24160001 */   addiu    $s6, $zero, 1
.L80240A20:
/* A9F760 80240A20 0200282D */  daddu     $a1, $s0, $zero
/* A9F764 80240A24 0220302D */  daddu     $a2, $s1, $zero
/* A9F768 80240A28 C6400038 */  lwc1      $f0, 0x38($s2)
/* A9F76C 80240A2C C642003C */  lwc1      $f2, 0x3c($s2)
/* A9F770 80240A30 C6440040 */  lwc1      $f4, 0x40($s2)
/* A9F774 80240A34 3C01447A */  lui       $at, 0x447a
/* A9F778 80240A38 44813000 */  mtc1      $at, $f6
/* A9F77C 80240A3C 27A2002C */  addiu     $v0, $sp, 0x2c
/* A9F780 80240A40 E7A00020 */  swc1      $f0, 0x20($sp)
/* A9F784 80240A44 E7A20024 */  swc1      $f2, 0x24($sp)
/* A9F788 80240A48 E7A40028 */  swc1      $f4, 0x28($sp)
/* A9F78C 80240A4C E7A6002C */  swc1      $f6, 0x2c($sp)
/* A9F790 80240A50 AFA20010 */  sw        $v0, 0x10($sp)
/* A9F794 80240A54 8E440080 */  lw        $a0, 0x80($s2)
/* A9F798 80240A58 0C0372DF */  jal       func_800DCB7C
/* A9F79C 80240A5C 0280382D */   daddu    $a3, $s4, $zero
/* A9F7A0 80240A60 10400019 */  beqz      $v0, .L80240AC8
/* A9F7A4 80240A64 00000000 */   nop      
/* A9F7A8 80240A68 C640001C */  lwc1      $f0, 0x1c($s2)
/* A9F7AC 80240A6C C7A2002C */  lwc1      $f2, 0x2c($sp)
/* A9F7B0 80240A70 46000005 */  abs.s     $f0, $f0
/* A9F7B4 80240A74 4600103C */  c.lt.s    $f2, $f0
/* A9F7B8 80240A78 00000000 */  nop       
/* A9F7BC 80240A7C 45000012 */  bc1f      .L80240AC8
/* A9F7C0 80240A80 00000000 */   nop      
/* A9F7C4 80240A84 C7A40024 */  lwc1      $f4, 0x24($sp)
/* A9F7C8 80240A88 C6400064 */  lwc1      $f0, 0x64($s2)
/* A9F7CC 80240A8C 46002001 */  sub.s     $f0, $f4, $f0
/* A9F7D0 80240A90 3C014034 */  lui       $at, 0x4034
/* A9F7D4 80240A94 44811800 */  mtc1      $at, $f3
/* A9F7D8 80240A98 44801000 */  mtc1      $zero, $f2
/* A9F7DC 80240A9C 46000005 */  abs.s     $f0, $f0
/* A9F7E0 80240AA0 46000021 */  cvt.d.s   $f0, $f0
/* A9F7E4 80240AA4 4622003C */  c.lt.d    $f0, $f2
/* A9F7E8 80240AA8 00000000 */  nop       
/* A9F7EC 80240AAC 45000006 */  bc1f      .L80240AC8
/* A9F7F0 80240AB0 0240202D */   daddu    $a0, $s2, $zero
/* A9F7F4 80240AB4 8E450018 */  lw        $a1, 0x18($s2)
/* A9F7F8 80240AB8 8E46000C */  lw        $a2, 0xc($s2)
/* A9F7FC 80240ABC 2416000A */  addiu     $s6, $zero, 0xa
/* A9F800 80240AC0 0C00EA95 */  jal       npc_move_heading
/* A9F804 80240AC4 E644003C */   swc1     $f4, 0x3c($s2)
.L80240AC8:
/* A9F808 80240AC8 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* A9F80C 80240ACC 3C013FF0 */  lui       $at, 0x3ff0
/* A9F810 80240AD0 44811800 */  mtc1      $at, $f3
/* A9F814 80240AD4 44801000 */  mtc1      $zero, $f2
/* A9F818 80240AD8 46000021 */  cvt.d.s   $f0, $f0
/* A9F81C 80240ADC 4622003C */  c.lt.d    $f0, $f2
/* A9F820 80240AE0 00000000 */  nop       
/* A9F824 80240AE4 45030001 */  bc1tl     .L80240AEC
/* A9F828 80240AE8 2416000B */   addiu    $s6, $zero, 0xb
.L80240AEC:
/* A9F82C 80240AEC 9642008E */  lhu       $v0, 0x8e($s2)
/* A9F830 80240AF0 2442FFFF */  addiu     $v0, $v0, -1
/* A9F834 80240AF4 A642008E */  sh        $v0, 0x8e($s2)
/* A9F838 80240AF8 00021400 */  sll       $v0, $v0, 0x10
/* A9F83C 80240AFC 58400001 */  blezl     $v0, .L80240B04
/* A9F840 80240B00 24160014 */   addiu    $s6, $zero, 0x14
.L80240B04:
/* A9F844 80240B04 56C00019 */  bnel      $s6, $zero, .L80240B6C
/* A9F848 80240B08 AFA00010 */   sw       $zero, 0x10($sp)
/* A9F84C 80240B0C 8E620070 */  lw        $v0, 0x70($s3)
/* A9F850 80240B10 30420001 */  andi      $v0, $v0, 1
/* A9F854 80240B14 10400009 */  beqz      $v0, .L80240B3C
/* A9F858 80240B18 00000000 */   nop      
/* A9F85C 80240B1C C640004C */  lwc1      $f0, 0x4c($s2)
/* A9F860 80240B20 3C014044 */  lui       $at, 0x4044
/* A9F864 80240B24 44811800 */  mtc1      $at, $f3
/* A9F868 80240B28 44801000 */  mtc1      $zero, $f2
/* A9F86C 80240B2C 46000021 */  cvt.d.s   $f0, $f0
/* A9F870 80240B30 46220000 */  add.d     $f0, $f0, $f2
/* A9F874 80240B34 46200020 */  cvt.s.d   $f0, $f0
/* A9F878 80240B38 E640004C */  swc1      $f0, 0x4c($s2)
.L80240B3C:
/* A9F87C 80240B3C 8E450018 */  lw        $a1, 0x18($s2)
/* A9F880 80240B40 8E46000C */  lw        $a2, 0xc($s2)
/* A9F884 80240B44 0C00EA95 */  jal       npc_move_heading
/* A9F888 80240B48 0240202D */   daddu    $a0, $s2, $zero
/* A9F88C 80240B4C C644003C */  lwc1      $f4, 0x3c($s2)
/* A9F890 80240B50 C640001C */  lwc1      $f0, 0x1c($s2)
/* A9F894 80240B54 46002100 */  add.s     $f4, $f4, $f0
/* A9F898 80240B58 C6420014 */  lwc1      $f2, 0x14($s2)
/* A9F89C 80240B5C 46020001 */  sub.s     $f0, $f0, $f2
/* A9F8A0 80240B60 E644003C */  swc1      $f4, 0x3c($s2)
/* A9F8A4 80240B64 080902F6 */  j         .L80240BD8
/* A9F8A8 80240B68 E640001C */   swc1     $f0, 0x1c($s2)
.L80240B6C:
/* A9F8AC 80240B6C AFA00014 */  sw        $zero, 0x14($sp)
/* A9F8B0 80240B70 8E450038 */  lw        $a1, 0x38($s2)
/* A9F8B4 80240B74 8E46003C */  lw        $a2, 0x3c($s2)
/* A9F8B8 80240B78 8E470040 */  lw        $a3, 0x40($s2)
/* A9F8BC 80240B7C 0C01BECC */  jal       fx_walk_normal
/* A9F8C0 80240B80 24040002 */   addiu    $a0, $zero, 2
/* A9F8C4 80240B84 3C01C47A */  lui       $at, 0xc47a
/* A9F8C8 80240B88 44810000 */  mtc1      $at, $f0
/* A9F8CC 80240B8C AE60006C */  sw        $zero, 0x6c($s3)
/* A9F8D0 80240B90 8E420000 */  lw        $v0, ($s2)
/* A9F8D4 80240B94 0240202D */  daddu     $a0, $s2, $zero
/* A9F8D8 80240B98 AE400038 */  sw        $zero, 0x38($s2)
/* A9F8DC 80240B9C AE400040 */  sw        $zero, 0x40($s2)
/* A9F8E0 80240BA0 AE40001C */  sw        $zero, 0x1c($s2)
/* A9F8E4 80240BA4 34420002 */  ori       $v0, $v0, 2
/* A9F8E8 80240BA8 E640003C */  swc1      $f0, 0x3c($s2)
/* A9F8EC 80240BAC 0C00EAFF */  jal       disable_npc_shadow
/* A9F8F0 80240BB0 AE420000 */   sw       $v0, ($s2)
/* A9F8F4 80240BB4 8E420000 */  lw        $v0, ($s2)
/* A9F8F8 80240BB8 2403F7FF */  addiu     $v1, $zero, -0x801
/* A9F8FC 80240BBC 00431024 */  and       $v0, $v0, $v1
/* A9F900 80240BC0 AE420000 */  sw        $v0, ($s2)
/* A9F904 80240BC4 8E620000 */  lw        $v0, ($s3)
/* A9F908 80240BC8 3C031F00 */  lui       $v1, 0x1f00
/* A9F90C 80240BCC 00431025 */  or        $v0, $v0, $v1
/* A9F910 80240BD0 AE620000 */  sw        $v0, ($s3)
/* A9F914 80240BD4 AEE00070 */  sw        $zero, 0x70($s7)
.L80240BD8:
/* A9F918 80240BD8 0000102D */  daddu     $v0, $zero, $zero
.L80240BDC:
/* A9F91C 80240BDC 8FBF0050 */  lw        $ra, 0x50($sp)
/* A9F920 80240BE0 8FB7004C */  lw        $s7, 0x4c($sp)
/* A9F924 80240BE4 8FB60048 */  lw        $s6, 0x48($sp)
/* A9F928 80240BE8 8FB50044 */  lw        $s5, 0x44($sp)
/* A9F92C 80240BEC 8FB40040 */  lw        $s4, 0x40($sp)
/* A9F930 80240BF0 8FB3003C */  lw        $s3, 0x3c($sp)
/* A9F934 80240BF4 8FB20038 */  lw        $s2, 0x38($sp)
/* A9F938 80240BF8 8FB10034 */  lw        $s1, 0x34($sp)
/* A9F93C 80240BFC 8FB00030 */  lw        $s0, 0x30($sp)
/* A9F940 80240C00 03E00008 */  jr        $ra
/* A9F944 80240C04 27BD0058 */   addiu    $sp, $sp, 0x58
