.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel UseCamPreset
/* 17CEFC 8024E61C 3C028028 */  lui   $v0, 0x8028
/* 17CF00 8024E620 80420CE0 */  lb    $v0, 0xce0($v0)
/* 17CF04 8024E624 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 17CF08 8024E628 AFBF0010 */  sw    $ra, 0x10($sp)
/* 17CF0C 8024E62C 8C85000C */  lw    $a1, 0xc($a0)
/* 17CF10 8024E630 14400009 */  bnez  $v0, .L8024E658
/* 17CF14 8024E634 24020002 */   addiu $v0, $zero, 2
/* 17CF18 8024E638 8CA50000 */  lw    $a1, ($a1)
/* 17CF1C 8024E63C 0C0B1EAF */  jal   get_variable
/* 17CF20 8024E640 00000000 */   nop   
/* 17CF24 8024E644 3C01802A */  lui   $at, 0x802a
/* 17CF28 8024E648 A020F2A4 */  sb    $zero, -0xd5c($at)
/* 17CF2C 8024E64C 0C0933CD */  jal   use_cam_preset
/* 17CF30 8024E650 0040202D */   daddu $a0, $v0, $zero
/* 17CF34 8024E654 24020002 */  addiu $v0, $zero, 2
.L8024E658:
/* 17CF38 8024E658 8FBF0010 */  lw    $ra, 0x10($sp)
/* 17CF3C 8024E65C 03E00008 */  jr    $ra
/* 17CF40 8024E660 27BD0018 */   addiu $sp, $sp, 0x18

/* 17CF44 8024E664 3C028028 */  lui   $v0, 0x8028
/* 17CF48 8024E668 80420CE0 */  lb    $v0, 0xce0($v0)
/* 17CF4C 8024E66C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 17CF50 8024E670 AFBF0010 */  sw    $ra, 0x10($sp)
/* 17CF54 8024E674 8C85000C */  lw    $a1, 0xc($a0)
/* 17CF58 8024E678 1440000B */  bnez  $v0, .L8024E6A8
/* 17CF5C 8024E67C 24020002 */   addiu $v0, $zero, 2
/* 17CF60 8024E680 8CA50000 */  lw    $a1, ($a1)
/* 17CF64 8024E684 0C0B1EAF */  jal   get_variable
/* 17CF68 8024E688 00000000 */   nop   
/* 17CF6C 8024E68C 0040202D */  daddu $a0, $v0, $zero
/* 17CF70 8024E690 24020001 */  addiu $v0, $zero, 1
/* 17CF74 8024E694 3C01802A */  lui   $at, 0x802a
/* 17CF78 8024E698 A022F2A4 */  sb    $v0, -0xd5c($at)
/* 17CF7C 8024E69C 0C0933CD */  jal   use_cam_preset
/* 17CF80 8024E6A0 00000000 */   nop   
/* 17CF84 8024E6A4 24020002 */  addiu $v0, $zero, 2
.L8024E6A8:
/* 17CF88 8024E6A8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 17CF8C 8024E6AC 03E00008 */  jr    $ra
/* 17CF90 8024E6B0 27BD0018 */   addiu $sp, $sp, 0x18

/* 17CF94 8024E6B4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 17CF98 8024E6B8 AFB00010 */  sw    $s0, 0x10($sp)
/* 17CF9C 8024E6BC 0080802D */  daddu $s0, $a0, $zero
/* 17CFA0 8024E6C0 3C028028 */  lui   $v0, 0x8028
/* 17CFA4 8024E6C4 80420CE0 */  lb    $v0, 0xce0($v0)
/* 17CFA8 8024E6C8 00A0182D */  daddu $v1, $a1, $zero
/* 17CFAC 8024E6CC AFBF0014 */  sw    $ra, 0x14($sp)
/* 17CFB0 8024E6D0 8E05000C */  lw    $a1, 0xc($s0)
/* 17CFB4 8024E6D4 14400018 */  bnez  $v0, .L8024E738
/* 17CFB8 8024E6D8 24020002 */   addiu $v0, $zero, 2
/* 17CFBC 8024E6DC 54600001 */  bnezl $v1, .L8024E6E4
/* 17CFC0 8024E6E0 AE000070 */   sw    $zero, 0x70($s0)
.L8024E6E4:
/* 17CFC4 8024E6E4 8E030070 */  lw    $v1, 0x70($s0)
/* 17CFC8 8024E6E8 10600005 */  beqz  $v1, .L8024E700
/* 17CFCC 8024E6EC 24020001 */   addiu $v0, $zero, 1
/* 17CFD0 8024E6F0 1062000B */  beq   $v1, $v0, .L8024E720
/* 17CFD4 8024E6F4 00000000 */   nop   
/* 17CFD8 8024E6F8 080939CE */  j     .L8024E738
/* 17CFDC 8024E6FC 0000102D */   daddu $v0, $zero, $zero

.L8024E700:
/* 17CFE0 8024E700 8CA50000 */  lw    $a1, ($a1)
/* 17CFE4 8024E704 0C0B1EAF */  jal   get_variable
/* 17CFE8 8024E708 0200202D */   daddu $a0, $s0, $zero
/* 17CFEC 8024E70C 0C093903 */  jal   func_8024E40C
/* 17CFF0 8024E710 0040202D */   daddu $a0, $v0, $zero
/* 17CFF4 8024E714 24020001 */  addiu $v0, $zero, 1
/* 17CFF8 8024E718 080939CD */  j     .L8024E734
/* 17CFFC 8024E71C AE020070 */   sw    $v0, 0x70($s0)

.L8024E720:
/* 17D000 8024E720 0C093961 */  jal   func_8024E584
/* 17D004 8024E724 00000000 */   nop   
/* 17D008 8024E728 0040182D */  daddu $v1, $v0, $zero
/* 17D00C 8024E72C 14600002 */  bnez  $v1, .L8024E738
/* 17D010 8024E730 24020002 */   addiu $v0, $zero, 2
.L8024E734:
/* 17D014 8024E734 0000102D */  daddu $v0, $zero, $zero
.L8024E738:
.L8024E738:
/* 17D018 8024E738 8FBF0014 */  lw    $ra, 0x14($sp)
/* 17D01C 8024E73C 8FB00010 */  lw    $s0, 0x10($sp)
/* 17D020 8024E740 03E00008 */  jr    $ra
/* 17D024 8024E744 27BD0018 */   addiu $sp, $sp, 0x18

/* 17D028 8024E748 3C028028 */  lui   $v0, 0x8028
/* 17D02C 8024E74C 80420CE0 */  lb    $v0, 0xce0($v0)
/* 17D030 8024E750 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 17D034 8024E754 AFB20018 */  sw    $s2, 0x18($sp)
/* 17D038 8024E758 0080902D */  daddu $s2, $a0, $zero
/* 17D03C 8024E75C AFB10014 */  sw    $s1, 0x14($sp)
/* 17D040 8024E760 3C11800B */  lui   $s1, 0x800b
/* 17D044 8024E764 263122D8 */  addiu $s1, $s1, 0x22d8
/* 17D048 8024E768 AFBF001C */  sw    $ra, 0x1c($sp)
/* 17D04C 8024E76C AFB00010 */  sw    $s0, 0x10($sp)
/* 17D050 8024E770 8E50000C */  lw    $s0, 0xc($s2)
/* 17D054 8024E774 14400024 */  bnez  $v0, .L8024E808
/* 17D058 8024E778 24020002 */   addiu $v0, $zero, 2
/* 17D05C 8024E77C 8E050000 */  lw    $a1, ($s0)
/* 17D060 8024E780 26100004 */  addiu $s0, $s0, 4
/* 17D064 8024E784 0C0B1EAF */  jal   get_variable
/* 17D068 8024E788 0240202D */   daddu $a0, $s2, $zero
/* 17D06C 8024E78C 0240202D */  daddu $a0, $s2, $zero
/* 17D070 8024E790 8E050000 */  lw    $a1, ($s0)
/* 17D074 8024E794 0C0B1EAF */  jal   get_variable
/* 17D078 8024E798 0040802D */   daddu $s0, $v0, $zero
/* 17D07C 8024E79C 0040182D */  daddu $v1, $v0, $zero
/* 17D080 8024E7A0 2610FFFF */  addiu $s0, $s0, -1
/* 17D084 8024E7A4 2E020008 */  sltiu $v0, $s0, 8
/* 17D088 8024E7A8 10400016 */  beqz  $v0, .L8024E804
/* 17D08C 8024E7AC 00101080 */   sll   $v0, $s0, 2
/* 17D090 8024E7B0 3C01802A */  lui   $at, 0x802a
/* 17D094 8024E7B4 00220821 */  addu  $at, $at, $v0
/* 17D098 8024E7B8 8C22CD70 */  lw    $v0, -0x3290($at)
/* 17D09C 8024E7BC 00400008 */  jr    $v0
/* 17D0A0 8024E7C0 00000000 */   nop   
/* 17D0A4 8024E7C4 08093A01 */  j     .L8024E804
/* 17D0A8 8024E7C8 A623001C */   sh    $v1, 0x1c($s1)

/* 17D0AC 8024E7CC 08093A01 */  j     .L8024E804
/* 17D0B0 8024E7D0 A623001E */   sh    $v1, 0x1e($s1)

/* 17D0B4 8024E7D4 08093A01 */  j     .L8024E804
/* 17D0B8 8024E7D8 A6230020 */   sh    $v1, 0x20($s1)

/* 17D0BC 8024E7DC 08093A01 */  j     .L8024E804
/* 17D0C0 8024E7E0 A6230022 */   sh    $v1, 0x22($s1)

/* 17D0C4 8024E7E4 08093A01 */  j     .L8024E804
/* 17D0C8 8024E7E8 A6230024 */   sh    $v1, 0x24($s1)

/* 17D0CC 8024E7EC 00031200 */  sll   $v0, $v1, 8
/* 17D0D0 8024E7F0 08093A01 */  j     .L8024E804
/* 17D0D4 8024E7F4 A6220026 */   sh    $v0, 0x26($s1)

/* 17D0D8 8024E7F8 08093A01 */  j     .L8024E804
/* 17D0DC 8024E7FC A6230028 */   sh    $v1, 0x28($s1)

/* 17D0E0 8024E800 A623002A */  sh    $v1, 0x2a($s1)
.L8024E804:
.L8024E804:
/* 17D0E4 8024E804 24020002 */  addiu $v0, $zero, 2
.L8024E808:
/* 17D0E8 8024E808 8FBF001C */  lw    $ra, 0x1c($sp)
/* 17D0EC 8024E80C 8FB20018 */  lw    $s2, 0x18($sp)
/* 17D0F0 8024E810 8FB10014 */  lw    $s1, 0x14($sp)
/* 17D0F4 8024E814 8FB00010 */  lw    $s0, 0x10($sp)
/* 17D0F8 8024E818 03E00008 */  jr    $ra
/* 17D0FC 8024E81C 27BD0020 */   addiu $sp, $sp, 0x20

/* 17D100 8024E820 3C028028 */  lui   $v0, 0x8028
/* 17D104 8024E824 80420CE0 */  lb    $v0, 0xce0($v0)
/* 17D108 8024E828 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 17D10C 8024E82C AFB10014 */  sw    $s1, 0x14($sp)
/* 17D110 8024E830 0080882D */  daddu $s1, $a0, $zero
/* 17D114 8024E834 AFB20018 */  sw    $s2, 0x18($sp)
/* 17D118 8024E838 3C12800B */  lui   $s2, 0x800b
/* 17D11C 8024E83C 265222D8 */  addiu $s2, $s2, 0x22d8
/* 17D120 8024E840 AFBF001C */  sw    $ra, 0x1c($sp)
/* 17D124 8024E844 AFB00010 */  sw    $s0, 0x10($sp)
/* 17D128 8024E848 8E30000C */  lw    $s0, 0xc($s1)
/* 17D12C 8024E84C 14400029 */  bnez  $v0, .L8024E8F4
/* 17D130 8024E850 24020002 */   addiu $v0, $zero, 2
/* 17D134 8024E854 8E050000 */  lw    $a1, ($s0)
/* 17D138 8024E858 0C0B1EAF */  jal   get_variable
/* 17D13C 8024E85C 26100004 */   addiu $s0, $s0, 4
/* 17D140 8024E860 A642001C */  sh    $v0, 0x1c($s2)
/* 17D144 8024E864 8E050000 */  lw    $a1, ($s0)
/* 17D148 8024E868 26100004 */  addiu $s0, $s0, 4
/* 17D14C 8024E86C 0C0B1EAF */  jal   get_variable
/* 17D150 8024E870 0220202D */   daddu $a0, $s1, $zero
/* 17D154 8024E874 A642001E */  sh    $v0, 0x1e($s2)
/* 17D158 8024E878 8E050000 */  lw    $a1, ($s0)
/* 17D15C 8024E87C 26100004 */  addiu $s0, $s0, 4
/* 17D160 8024E880 0C0B1EAF */  jal   get_variable
/* 17D164 8024E884 0220202D */   daddu $a0, $s1, $zero
/* 17D168 8024E888 A6420020 */  sh    $v0, 0x20($s2)
/* 17D16C 8024E88C 8E050000 */  lw    $a1, ($s0)
/* 17D170 8024E890 26100004 */  addiu $s0, $s0, 4
/* 17D174 8024E894 0C0B1EAF */  jal   get_variable
/* 17D178 8024E898 0220202D */   daddu $a0, $s1, $zero
/* 17D17C 8024E89C A6420022 */  sh    $v0, 0x22($s2)
/* 17D180 8024E8A0 8E050000 */  lw    $a1, ($s0)
/* 17D184 8024E8A4 26100004 */  addiu $s0, $s0, 4
/* 17D188 8024E8A8 0C0B1EAF */  jal   get_variable
/* 17D18C 8024E8AC 0220202D */   daddu $a0, $s1, $zero
/* 17D190 8024E8B0 A6420024 */  sh    $v0, 0x24($s2)
/* 17D194 8024E8B4 8E050000 */  lw    $a1, ($s0)
/* 17D198 8024E8B8 26100004 */  addiu $s0, $s0, 4
/* 17D19C 8024E8BC 0C0B1EAF */  jal   get_variable
/* 17D1A0 8024E8C0 0220202D */   daddu $a0, $s1, $zero
/* 17D1A4 8024E8C4 00021200 */  sll   $v0, $v0, 8
/* 17D1A8 8024E8C8 A6420026 */  sh    $v0, 0x26($s2)
/* 17D1AC 8024E8CC 8E050000 */  lw    $a1, ($s0)
/* 17D1B0 8024E8D0 26100004 */  addiu $s0, $s0, 4
/* 17D1B4 8024E8D4 0C0B1EAF */  jal   get_variable
/* 17D1B8 8024E8D8 0220202D */   daddu $a0, $s1, $zero
/* 17D1BC 8024E8DC A6420028 */  sh    $v0, 0x28($s2)
/* 17D1C0 8024E8E0 8E050000 */  lw    $a1, ($s0)
/* 17D1C4 8024E8E4 0C0B1EAF */  jal   get_variable
/* 17D1C8 8024E8E8 0220202D */   daddu $a0, $s1, $zero
/* 17D1CC 8024E8EC A642002A */  sh    $v0, 0x2a($s2)
/* 17D1D0 8024E8F0 24020002 */  addiu $v0, $zero, 2
.L8024E8F4:
/* 17D1D4 8024E8F4 8FBF001C */  lw    $ra, 0x1c($sp)
/* 17D1D8 8024E8F8 8FB20018 */  lw    $s2, 0x18($sp)
/* 17D1DC 8024E8FC 8FB10014 */  lw    $s1, 0x14($sp)
/* 17D1E0 8024E900 8FB00010 */  lw    $s0, 0x10($sp)
/* 17D1E4 8024E904 03E00008 */  jr    $ra
/* 17D1E8 8024E908 27BD0020 */   addiu $sp, $sp, 0x20

