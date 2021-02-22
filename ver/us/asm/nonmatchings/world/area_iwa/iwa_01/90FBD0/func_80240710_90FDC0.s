.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240710_90FDC0
/* 90FDC0 80240710 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 90FDC4 80240714 AFB20038 */  sw        $s2, 0x38($sp)
/* 90FDC8 80240718 0080902D */  daddu     $s2, $a0, $zero
/* 90FDCC 8024071C AFB00030 */  sw        $s0, 0x30($sp)
/* 90FDD0 80240720 AFBF003C */  sw        $ra, 0x3c($sp)
/* 90FDD4 80240724 AFB10034 */  sw        $s1, 0x34($sp)
/* 90FDD8 80240728 F7B60048 */  sdc1      $f22, 0x48($sp)
/* 90FDDC 8024072C F7B40040 */  sdc1      $f20, 0x40($sp)
/* 90FDE0 80240730 8E510148 */  lw        $s1, 0x148($s2)
/* 90FDE4 80240734 4485A000 */  mtc1      $a1, $f20
/* 90FDE8 80240738 86240008 */  lh        $a0, 8($s1)
/* 90FDEC 8024073C 4486B000 */  mtc1      $a2, $f22
/* 90FDF0 80240740 0C00EABB */  jal       get_npc_unsafe
/* 90FDF4 80240744 00E0802D */   daddu    $s0, $a3, $zero
/* 90FDF8 80240748 0200202D */  daddu     $a0, $s0, $zero
/* 90FDFC 8024074C 0220282D */  daddu     $a1, $s1, $zero
/* 90FE00 80240750 24030001 */  addiu     $v1, $zero, 1
/* 90FE04 80240754 4406A000 */  mfc1      $a2, $f20
/* 90FE08 80240758 4407B000 */  mfc1      $a3, $f22
/* 90FE0C 8024075C 0040802D */  daddu     $s0, $v0, $zero
/* 90FE10 80240760 0C01242D */  jal       func_800490B4
/* 90FE14 80240764 AFA30010 */   sw       $v1, 0x10($sp)
/* 90FE18 80240768 1440001D */  bnez      $v0, .L802407E0
/* 90FE1C 8024076C 24040002 */   addiu    $a0, $zero, 2
/* 90FE20 80240770 0200282D */  daddu     $a1, $s0, $zero
/* 90FE24 80240774 0000302D */  daddu     $a2, $zero, $zero
/* 90FE28 80240778 860300A8 */  lh        $v1, 0xa8($s0)
/* 90FE2C 8024077C 3C013F80 */  lui       $at, 0x3f80
/* 90FE30 80240780 44810000 */  mtc1      $at, $f0
/* 90FE34 80240784 3C014000 */  lui       $at, 0x4000
/* 90FE38 80240788 44811000 */  mtc1      $at, $f2
/* 90FE3C 8024078C 3C01C1A0 */  lui       $at, 0xc1a0
/* 90FE40 80240790 44812000 */  mtc1      $at, $f4
/* 90FE44 80240794 2402000F */  addiu     $v0, $zero, 0xf
/* 90FE48 80240798 AFA2001C */  sw        $v0, 0x1c($sp)
/* 90FE4C 8024079C 44833000 */  mtc1      $v1, $f6
/* 90FE50 802407A0 00000000 */  nop
/* 90FE54 802407A4 468031A0 */  cvt.s.w   $f6, $f6
/* 90FE58 802407A8 44073000 */  mfc1      $a3, $f6
/* 90FE5C 802407AC 27A20028 */  addiu     $v0, $sp, 0x28
/* 90FE60 802407B0 AFA20020 */  sw        $v0, 0x20($sp)
/* 90FE64 802407B4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 90FE68 802407B8 E7A20014 */  swc1      $f2, 0x14($sp)
/* 90FE6C 802407BC 0C01BFA4 */  jal       fx_emote
/* 90FE70 802407C0 E7A40018 */   swc1     $f4, 0x18($sp)
/* 90FE74 802407C4 8E2200CC */  lw        $v0, 0xcc($s1)
/* 90FE78 802407C8 8C430000 */  lw        $v1, ($v0)
/* 90FE7C 802407CC 24020014 */  addiu     $v0, $zero, 0x14
/* 90FE80 802407D0 A602008E */  sh        $v0, 0x8e($s0)
/* 90FE84 802407D4 24020021 */  addiu     $v0, $zero, 0x21
/* 90FE88 802407D8 0809020C */  j         .L80240830
/* 90FE8C 802407DC AE030028 */   sw       $v1, 0x28($s0)
.L802407E0:
/* 90FE90 802407E0 0C090148 */  jal       func_80240520_90FBD0
/* 90FE94 802407E4 0240202D */   daddu    $a0, $s2, $zero
/* 90FE98 802407E8 0040202D */  daddu     $a0, $v0, $zero
/* 90FE9C 802407EC 2402FFFF */  addiu     $v0, $zero, -1
/* 90FEA0 802407F0 10820010 */  beq       $a0, $v0, .L80240834
/* 90FEA4 802407F4 00000000 */   nop
/* 90FEA8 802407F8 0C00FB3A */  jal       get_enemy
/* 90FEAC 802407FC 00000000 */   nop
/* 90FEB0 80240800 8C42006C */  lw        $v0, 0x6c($v0)
/* 90FEB4 80240804 1440000B */  bnez      $v0, .L80240834
/* 90FEB8 80240808 00000000 */   nop
/* 90FEBC 8024080C 8602008C */  lh        $v0, 0x8c($s0)
/* 90FEC0 80240810 14400008 */  bnez      $v0, .L80240834
/* 90FEC4 80240814 00000000 */   nop
/* 90FEC8 80240818 8E2200CC */  lw        $v0, 0xcc($s1)
/* 90FECC 8024081C 8C420020 */  lw        $v0, 0x20($v0)
/* 90FED0 80240820 AE020028 */  sw        $v0, 0x28($s0)
/* 90FED4 80240824 96220072 */  lhu       $v0, 0x72($s1)
/* 90FED8 80240828 A602008E */  sh        $v0, 0x8e($s0)
/* 90FEDC 8024082C 2402001E */  addiu     $v0, $zero, 0x1e
.L80240830:
/* 90FEE0 80240830 AE420070 */  sw        $v0, 0x70($s2)
.L80240834:
/* 90FEE4 80240834 8FBF003C */  lw        $ra, 0x3c($sp)
/* 90FEE8 80240838 8FB20038 */  lw        $s2, 0x38($sp)
/* 90FEEC 8024083C 8FB10034 */  lw        $s1, 0x34($sp)
/* 90FEF0 80240840 8FB00030 */  lw        $s0, 0x30($sp)
/* 90FEF4 80240844 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 90FEF8 80240848 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 90FEFC 8024084C 03E00008 */  jr        $ra
/* 90FF00 80240850 27BD0050 */   addiu    $sp, $sp, 0x50
