.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel push_entity_matrix
/* 10A6CC 802E8E4C 27BDFF58 */  addiu $sp, $sp, -0xa8
/* 10A6D0 802E8E50 AFB3009C */  sw    $s3, 0x9c($sp)
/* 10A6D4 802E8E54 3C13800A */  lui   $s3, 0x800a
/* 10A6D8 802E8E58 2673A66C */  addiu $s3, $s3, -0x5994
/* 10A6DC 802E8E5C AFBF00A4 */  sw    $ra, 0xa4($sp)
/* 10A6E0 802E8E60 AFB400A0 */  sw    $s4, 0xa0($sp)
/* 10A6E4 802E8E64 AFB20098 */  sw    $s2, 0x98($sp)
/* 10A6E8 802E8E68 AFB10094 */  sw    $s1, 0x94($sp)
/* 10A6EC 802E8E6C AFB00090 */  sw    $s0, 0x90($sp)
/* 10A6F0 802E8E70 8E710000 */  lw    $s1, ($s3)
/* 10A6F4 802E8E74 0C04417A */  jal   get_entity_by_index
/* 10A6F8 802E8E78 3C140001 */   lui   $s4, 1
/* 10A6FC 802E8E7C 27A40010 */  addiu $a0, $sp, 0x10
/* 10A700 802E8E80 0040802D */  daddu $s0, $v0, $zero
/* 10A704 802E8E84 8E050054 */  lw    $a1, 0x54($s0)
/* 10A708 802E8E88 8E060058 */  lw    $a2, 0x58($s0)
/* 10A70C 802E8E8C 8E07005C */  lw    $a3, 0x5c($s0)
/* 10A710 802E8E90 8E120040 */  lw    $s2, 0x40($s0)
/* 10A714 802E8E94 0C019DF0 */  jal   guScaleF
/* 10A718 802E8E98 36941630 */   ori   $s4, $s4, 0x1630
/* 10A71C 802E8E9C C6420018 */  lwc1  $f2, 0x18($s2)
/* 10A720 802E8EA0 3C013F80 */  lui   $at, 0x3f80
/* 10A724 802E8EA4 44810000 */  mtc1  $at, $f0
/* 10A728 802E8EA8 8E050048 */  lw    $a1, 0x48($s0)
/* 10A72C 802E8EAC 46001080 */  add.s $f2, $f2, $f0
/* 10A730 802E8EB0 8E070050 */  lw    $a3, 0x50($s0)
/* 10A734 802E8EB4 27B00050 */  addiu $s0, $sp, 0x50
/* 10A738 802E8EB8 44061000 */  mfc1  $a2, $f2
/* 10A73C 802E8EBC 0C019E40 */  jal   guTranslateF
/* 10A740 802E8EC0 0200202D */   daddu $a0, $s0, $zero
/* 10A744 802E8EC4 27A40010 */  addiu $a0, $sp, 0x10
/* 10A748 802E8EC8 0200282D */  daddu $a1, $s0, $zero
/* 10A74C 802E8ECC 0C019D80 */  jal   guMtxCatF
/* 10A750 802E8ED0 0200302D */   daddu $a2, $s0, $zero
/* 10A754 802E8ED4 0200202D */  daddu $a0, $s0, $zero
/* 10A758 802E8ED8 3C108007 */  lui   $s0, 0x8007
/* 10A75C 802E8EDC 261041F0 */  addiu $s0, $s0, 0x41f0
/* 10A760 802E8EE0 3C12800A */  lui   $s2, 0x800a
/* 10A764 802E8EE4 2652A674 */  addiu $s2, $s2, -0x598c
/* 10A768 802E8EE8 96050000 */  lhu   $a1, ($s0)
/* 10A76C 802E8EEC 8E420000 */  lw    $v0, ($s2)
/* 10A770 802E8EF0 00052980 */  sll   $a1, $a1, 6
/* 10A774 802E8EF4 00B42821 */  addu  $a1, $a1, $s4
/* 10A778 802E8EF8 0C019D40 */  jal   guMtxF2L
/* 10A77C 802E8EFC 00452821 */   addu  $a1, $v0, $a1
/* 10A780 802E8F00 0220202D */  daddu $a0, $s1, $zero
/* 10A784 802E8F04 26310008 */  addiu $s1, $s1, 8
/* 10A788 802E8F08 3C03DA38 */  lui   $v1, 0xda38
/* 10A78C 802E8F0C 34630002 */  ori   $v1, $v1, 2
/* 10A790 802E8F10 0220282D */  daddu $a1, $s1, $zero
/* 10A794 802E8F14 26310008 */  addiu $s1, $s1, 8
/* 10A798 802E8F18 0220302D */  daddu $a2, $s1, $zero
/* 10A79C 802E8F1C 26310008 */  addiu $s1, $s1, 8
/* 10A7A0 802E8F20 3C07D838 */  lui   $a3, 0xd838
/* 10A7A4 802E8F24 96020000 */  lhu   $v0, ($s0)
/* 10A7A8 802E8F28 34E70002 */  ori   $a3, $a3, 2
/* 10A7AC 802E8F2C AC830000 */  sw    $v1, ($a0)
/* 10A7B0 802E8F30 AE710000 */  sw    $s1, ($s3)
/* 10A7B4 802E8F34 24430001 */  addiu $v1, $v0, 1
/* 10A7B8 802E8F38 3042FFFF */  andi  $v0, $v0, 0xffff
/* 10A7BC 802E8F3C 00021180 */  sll   $v0, $v0, 6
/* 10A7C0 802E8F40 A6030000 */  sh    $v1, ($s0)
/* 10A7C4 802E8F44 8E430000 */  lw    $v1, ($s2)
/* 10A7C8 802E8F48 00541021 */  addu  $v0, $v0, $s4
/* 10A7CC 802E8F4C 00621821 */  addu  $v1, $v1, $v0
/* 10A7D0 802E8F50 3C02DE00 */  lui   $v0, 0xde00
/* 10A7D4 802E8F54 AC830004 */  sw    $v1, 4($a0)
/* 10A7D8 802E8F58 ACA20000 */  sw    $v0, ($a1)
/* 10A7DC 802E8F5C 3C020A00 */  lui   $v0, 0xa00
/* 10A7E0 802E8F60 24420680 */  addiu $v0, $v0, 0x680
/* 10A7E4 802E8F64 ACA20004 */  sw    $v0, 4($a1)
/* 10A7E8 802E8F68 24020040 */  addiu $v0, $zero, 0x40
/* 10A7EC 802E8F6C ACC70000 */  sw    $a3, ($a2)
/* 10A7F0 802E8F70 ACC20004 */  sw    $v0, 4($a2)
/* 10A7F4 802E8F74 8FBF00A4 */  lw    $ra, 0xa4($sp)
/* 10A7F8 802E8F78 8FB400A0 */  lw    $s4, 0xa0($sp)
/* 10A7FC 802E8F7C 8FB3009C */  lw    $s3, 0x9c($sp)
/* 10A800 802E8F80 8FB20098 */  lw    $s2, 0x98($sp)
/* 10A804 802E8F84 8FB10094 */  lw    $s1, 0x94($sp)
/* 10A808 802E8F88 8FB00090 */  lw    $s0, 0x90($sp)
/* 10A80C 802E8F8C 03E00008 */  jr    $ra
/* 10A810 802E8F90 27BD00A8 */   addiu $sp, $sp, 0xa8

/* 10A814 802E8F94 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 10A818 802E8F98 AFB10014 */  sw    $s1, 0x14($sp)
/* 10A81C 802E8F9C 0080882D */  daddu $s1, $a0, $zero
/* 10A820 802E8FA0 3C028016 */  lui   $v0, 0x8016
/* 10A824 802E8FA4 2442C7D0 */  addiu $v0, $v0, -0x3830
/* 10A828 802E8FA8 AFBF001C */  sw    $ra, 0x1c($sp)
/* 10A82C 802E8FAC AFB20018 */  sw    $s2, 0x18($sp)
/* 10A830 802E8FB0 AFB00010 */  sw    $s0, 0x10($sp)
/* 10A834 802E8FB4 8C430000 */  lw    $v1, ($v0)
/* 10A838 802E8FB8 8C440004 */  lw    $a0, 4($v0)
/* 10A83C 802E8FBC 8C450008 */  lw    $a1, 8($v0)
/* 10A840 802E8FC0 3C02802F */  lui   $v0, 0x802f
/* 10A844 802E8FC4 24428E4C */  addiu $v0, $v0, -0x71b4
/* 10A848 802E8FC8 8E300040 */  lw    $s0, 0x40($s1)
/* 10A84C 802E8FCC 2632004C */  addiu $s2, $s1, 0x4c
/* 10A850 802E8FD0 AE22003C */  sw    $v0, 0x3c($s1)
/* 10A854 802E8FD4 AE03000C */  sw    $v1, 0xc($s0)
/* 10A858 802E8FD8 AE040010 */  sw    $a0, 0x10($s0)
/* 10A85C 802E8FDC AE050014 */  sw    $a1, 0x14($s0)
/* 10A860 802E8FE0 C620004C */  lwc1  $f0, 0x4c($s1)
/* 10A864 802E8FE4 00A0202D */  daddu $a0, $a1, $zero
/* 10A868 802E8FE8 0C05152F */  jal   get_global_flag
/* 10A86C 802E8FEC E6000018 */   swc1  $f0, 0x18($s0)
/* 10A870 802E8FF0 AE020008 */  sw    $v0, 8($s0)
/* 10A874 802E8FF4 C620004C */  lwc1  $f0, 0x4c($s1)
/* 10A878 802E8FF8 460000A1 */  cvt.d.s $f2, $f0
/* 10A87C 802E8FFC 3C01404A */  lui   $at, 0x404a
/* 10A880 802E9000 44810800 */  mtc1  $at, $f1
/* 10A884 802E9004 44800000 */  mtc1  $zero, $f0
/* 10A888 802E9008 50400006 */  beql  $v0, $zero, .L802E9024
/* 10A88C 802E900C 46201001 */   sub.d $f0, $f2, $f0
/* 10A890 802E9010 3C01402E */  lui   $at, 0x402e
/* 10A894 802E9014 44810800 */  mtc1  $at, $f1
/* 10A898 802E9018 44800000 */  mtc1  $zero, $f0
/* 10A89C 802E901C 00000000 */  nop   
/* 10A8A0 802E9020 46201001 */  sub.d $f0, $f2, $f0
.L802E9024:
/* 10A8A4 802E9024 46200020 */  cvt.s.d $f0, $f0
/* 10A8A8 802E9028 E6400000 */  swc1  $f0, ($s2)
/* 10A8AC 802E902C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 10A8B0 802E9030 8FB20018 */  lw    $s2, 0x18($sp)
/* 10A8B4 802E9034 8FB10014 */  lw    $s1, 0x14($sp)
/* 10A8B8 802E9038 8FB00010 */  lw    $s0, 0x10($sp)
/* 10A8BC 802E903C 03E00008 */  jr    $ra
/* 10A8C0 802E9040 27BD0020 */   addiu $sp, $sp, 0x20

/* 10A8C4 802E9044 00000000 */  nop   
/* 10A8C8 802E9048 00000000 */  nop   
/* 10A8CC 802E904C 00000000 */  nop   
/* 10A8D0 802E9050 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 10A8D4 802E9054 AFB00010 */  sw    $s0, 0x10($sp)
/* 10A8D8 802E9058 0080802D */  daddu $s0, $a0, $zero
/* 10A8DC 802E905C AFBF0018 */  sw    $ra, 0x18($sp)
/* 10A8E0 802E9060 AFB10014 */  sw    $s1, 0x14($sp)
/* 10A8E4 802E9064 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 10A8E8 802E9068 C6000064 */  lwc1  $f0, 0x64($s0)
/* 10A8EC 802E906C 3C014334 */  lui   $at, 0x4334
/* 10A8F0 802E9070 44816000 */  mtc1  $at, $f12
/* 10A8F4 802E9074 0C00A6C9 */  jal   clamp_angle
/* 10A8F8 802E9078 46006301 */   sub.s $f12, $f12, $f0
/* 10A8FC 802E907C 3C118011 */  lui   $s1, 0x8011
/* 10A900 802E9080 2631EFC8 */  addiu $s1, $s1, -0x1038
/* 10A904 802E9084 C60C0048 */  lwc1  $f12, 0x48($s0)
/* 10A908 802E9088 C60E0050 */  lwc1  $f14, 0x50($s0)
/* 10A90C 802E908C 8E260028 */  lw    $a2, 0x28($s1)
/* 10A910 802E9090 8E270030 */  lw    $a3, 0x30($s1)
/* 10A914 802E9094 0C00A720 */  jal   atan2
/* 10A918 802E9098 46000506 */   mov.s $f20, $f0
/* 10A91C 802E909C 0C00A6C9 */  jal   clamp_angle
/* 10A920 802E90A0 46000306 */   mov.s $f12, $f0
/* 10A924 802E90A4 4600A501 */  sub.s $f20, $f20, $f0
/* 10A928 802E90A8 8E220004 */  lw    $v0, 4($s1)
/* 10A92C 802E90AC 30420001 */  andi  $v0, $v0, 1
/* 10A930 802E90B0 14400022 */  bnez  $v0, .L802E913C
/* 10A934 802E90B4 4600A505 */   abs.s $f20, $f20
/* 10A938 802E90B8 92020006 */  lbu   $v0, 6($s0)
/* 10A93C 802E90BC 30420001 */  andi  $v0, $v0, 1
/* 10A940 802E90C0 1440001E */  bnez  $v0, .L802E913C
/* 10A944 802E90C4 00000000 */   nop   
/* 10A948 802E90C8 3C014220 */  lui   $at, 0x4220
/* 10A94C 802E90CC 44810000 */  mtc1  $at, $f0
/* 10A950 802E90D0 00000000 */  nop   
/* 10A954 802E90D4 4600A03E */  c.le.s $f20, $f0
/* 10A958 802E90D8 00000000 */  nop   
/* 10A95C 802E90DC 45010008 */  bc1t  .L802E9100
/* 10A960 802E90E0 00000000 */   nop   
/* 10A964 802E90E4 3C0143A0 */  lui   $at, 0x43a0
/* 10A968 802E90E8 44810000 */  mtc1  $at, $f0
/* 10A96C 802E90EC 00000000 */  nop   
/* 10A970 802E90F0 4614003E */  c.le.s $f0, $f20
/* 10A974 802E90F4 00000000 */  nop   
/* 10A978 802E90F8 45000010 */  bc1f  .L802E913C
/* 10A97C 802E90FC 00000000 */   nop   
.L802E9100:
/* 10A980 802E9100 8E020000 */  lw    $v0, ($s0)
/* 10A984 802E9104 34421000 */  ori   $v0, $v0, 0x1000
/* 10A988 802E9108 AE020000 */  sw    $v0, ($s0)
/* 10A98C 802E910C 8E220004 */  lw    $v0, 4($s1)
/* 10A990 802E9110 30420010 */  andi  $v0, $v0, 0x10
/* 10A994 802E9114 1040000F */  beqz  $v0, .L802E9154
/* 10A998 802E9118 00000000 */   nop   
/* 10A99C 802E911C 92020006 */  lbu   $v0, 6($s0)
/* 10A9A0 802E9120 30420008 */  andi  $v0, $v0, 8
/* 10A9A4 802E9124 1040000B */  beqz  $v0, .L802E9154
/* 10A9A8 802E9128 00000000 */   nop   
/* 10A9AC 802E912C 0C04419E */  jal   func_80110678
/* 10A9B0 802E9130 0200202D */   daddu $a0, $s0, $zero
/* 10A9B4 802E9134 080BA455 */  j     .L802E9154
/* 10A9B8 802E9138 00000000 */   nop   

.L802E913C:
/* 10A9BC 802E913C 8E020000 */  lw    $v0, ($s0)
/* 10A9C0 802E9140 2403EFFF */  addiu $v1, $zero, -0x1001
/* 10A9C4 802E9144 00431024 */  and   $v0, $v0, $v1
/* 10A9C8 802E9148 AE020000 */  sw    $v0, ($s0)
/* 10A9CC 802E914C 2402FFFF */  addiu $v0, $zero, -1
/* 10A9D0 802E9150 A62200C6 */  sh    $v0, 0xc6($s1)
.L802E9154:
/* 10A9D4 802E9154 8FBF0018 */  lw    $ra, 0x18($sp)
/* 10A9D8 802E9158 8FB10014 */  lw    $s1, 0x14($sp)
/* 10A9DC 802E915C 8FB00010 */  lw    $s0, 0x10($sp)
/* 10A9E0 802E9160 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 10A9E4 802E9164 03E00008 */  jr    $ra
/* 10A9E8 802E9168 27BD0028 */   addiu $sp, $sp, 0x28

/* 10A9EC 802E916C 00000000 */  nop   

.set reorder
