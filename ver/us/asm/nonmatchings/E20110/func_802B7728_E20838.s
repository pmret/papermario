.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_802B7D88_E20E98
.double 0.05

dlabel D_802B7D90_E20EA0
.double 0.55, 0.0

.section .text

glabel func_802B7728_E20838
/* E20838 802B7728 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E2083C 802B772C AFB00010 */  sw        $s0, 0x10($sp)
/* E20840 802B7730 241000FF */  addiu     $s0, $zero, 0xff
/* E20844 802B7734 AFBF0018 */  sw        $ra, 0x18($sp)
/* E20848 802B7738 0C0ADD7A */  jal       func_802B75E8_E206F8
/* E2084C 802B773C AFB10014 */   sw       $s1, 0x14($sp)
/* E20850 802B7740 3C03802B */  lui       $v1, %hi(D_802B7CB8_E20DC8)
/* E20854 802B7744 24637CB8 */  addiu     $v1, $v1, %lo(D_802B7CB8_E20DC8)
/* E20858 802B7748 8C640000 */  lw        $a0, ($v1)
/* E2085C 802B774C 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* E20860 802B7750 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* E20864 802B7754 90850023 */  lbu       $a1, 0x23($a0)
/* E20868 802B7758 24020001 */  addiu     $v0, $zero, 1
/* E2086C 802B775C 10A20026 */  beq       $a1, $v0, .L802B77F8
/* E20870 802B7760 28A20002 */   slti     $v0, $a1, 2
/* E20874 802B7764 10400005 */  beqz      $v0, .L802B777C
/* E20878 802B7768 24020002 */   addiu    $v0, $zero, 2
/* E2087C 802B776C 10A00009 */  beqz      $a1, .L802B7794
/* E20880 802B7770 00000000 */   nop
/* E20884 802B7774 080ADE4A */  j         .L802B7928
/* E20888 802B7778 00000000 */   nop
.L802B777C:
/* E2088C 802B777C 10A20027 */  beq       $a1, $v0, .L802B781C
/* E20890 802B7780 24020003 */   addiu    $v0, $zero, 3
/* E20894 802B7784 10A20033 */  beq       $a1, $v0, .L802B7854
/* E20898 802B7788 00000000 */   nop
/* E2089C 802B778C 080ADE4A */  j         .L802B7928
/* E208A0 802B7790 00000000 */   nop
.L802B7794:
/* E208A4 802B7794 C4800010 */  lwc1      $f0, 0x10($a0)
/* E208A8 802B7798 3C01802B */  lui       $at, %hi(D_802B7D88_E20E98)
/* E208AC 802B779C D4227D88 */  ldc1      $f2, %lo(D_802B7D88_E20E98)($at)
/* E208B0 802B77A0 3C01802B */  lui       $at, %hi(D_802B7D90_E20EA0)
/* E208B4 802B77A4 D4247D90 */  ldc1      $f4, %lo(D_802B7D90_E20EA0)($at)
/* E208B8 802B77A8 46000021 */  cvt.d.s   $f0, $f0
/* E208BC 802B77AC 46220000 */  add.d     $f0, $f0, $f2
/* E208C0 802B77B0 AC80000C */  sw        $zero, 0xc($a0)
/* E208C4 802B77B4 46200020 */  cvt.s.d   $f0, $f0
/* E208C8 802B77B8 460000A1 */  cvt.d.s   $f2, $f0
/* E208CC 802B77BC 4622203E */  c.le.d    $f4, $f2
/* E208D0 802B77C0 00000000 */  nop
/* E208D4 802B77C4 45000058 */  bc1f      .L802B7928
/* E208D8 802B77C8 E4800010 */   swc1     $f0, 0x10($a0)
/* E208DC 802B77CC 90820023 */  lbu       $v0, 0x23($a0)
/* E208E0 802B77D0 3C013F0C */  lui       $at, 0x3f0c
/* E208E4 802B77D4 3421CCCD */  ori       $at, $at, 0xcccd
/* E208E8 802B77D8 44810000 */  mtc1      $at, $f0
/* E208EC 802B77DC 24420001 */  addiu     $v0, $v0, 1
/* E208F0 802B77E0 E4800010 */  swc1      $f0, 0x10($a0)
/* E208F4 802B77E4 A0820023 */  sb        $v0, 0x23($a0)
/* E208F8 802B77E8 8C630000 */  lw        $v1, ($v1)
/* E208FC 802B77EC 2402000C */  addiu     $v0, $zero, 0xc
/* E20900 802B77F0 080ADE4A */  j         .L802B7928
/* E20904 802B77F4 AC620014 */   sw       $v0, 0x14($v1)
.L802B77F8:
/* E20908 802B77F8 8C820014 */  lw        $v0, 0x14($a0)
/* E2090C 802B77FC AC80000C */  sw        $zero, 0xc($a0)
/* E20910 802B7800 2442FFFF */  addiu     $v0, $v0, -1
/* E20914 802B7804 1C400048 */  bgtz      $v0, .L802B7928
/* E20918 802B7808 AC820014 */   sw       $v0, 0x14($a0)
/* E2091C 802B780C 90820023 */  lbu       $v0, 0x23($a0)
/* E20920 802B7810 24420001 */  addiu     $v0, $v0, 1
/* E20924 802B7814 080ADE4A */  j         .L802B7928
/* E20928 802B7818 A0820023 */   sb       $v0, 0x23($a0)
.L802B781C:
/* E2092C 802B781C C48C000C */  lwc1      $f12, 0xc($a0)
/* E20930 802B7820 3C014120 */  lui       $at, 0x4120
/* E20934 802B7824 44810000 */  mtc1      $at, $f0
/* E20938 802B7828 00000000 */  nop
/* E2093C 802B782C 46006300 */  add.s     $f12, $f12, $f0
/* E20940 802B7830 3C0143B4 */  lui       $at, 0x43b4
/* E20944 802B7834 44810000 */  mtc1      $at, $f0
/* E20948 802B7838 00000000 */  nop
/* E2094C 802B783C 460C003E */  c.le.s    $f0, $f12
/* E20950 802B7840 00000000 */  nop
/* E20954 802B7844 45030001 */  bc1tl     .L802B784C
/* E20958 802B7848 46006301 */   sub.s    $f12, $f12, $f0
.L802B784C:
/* E2095C 802B784C 080ADE47 */  j         .L802B791C
/* E20960 802B7850 E48C000C */   swc1     $f12, 0xc($a0)
.L802B7854:
/* E20964 802B7854 C48C000C */  lwc1      $f12, 0xc($a0)
/* E20968 802B7858 3C0141C8 */  lui       $at, 0x41c8
/* E2096C 802B785C 44810000 */  mtc1      $at, $f0
/* E20970 802B7860 00000000 */  nop
/* E20974 802B7864 46006300 */  add.s     $f12, $f12, $f0
/* E20978 802B7868 3C0143B4 */  lui       $at, 0x43b4
/* E2097C 802B786C 44810000 */  mtc1      $at, $f0
/* E20980 802B7870 00000000 */  nop
/* E20984 802B7874 460C003E */  c.le.s    $f0, $f12
/* E20988 802B7878 00000000 */  nop
/* E2098C 802B787C 45030001 */  bc1tl     .L802B7884
/* E20990 802B7880 46006301 */   sub.s    $f12, $f12, $f0
.L802B7884:
/* E20994 802B7884 8C82001C */  lw        $v0, 0x1c($a0)
/* E20998 802B7888 E48C000C */  swc1      $f12, 0xc($a0)
/* E2099C 802B788C 2442FFE7 */  addiu     $v0, $v0, -0x19
/* E209A0 802B7890 04410002 */  bgez      $v0, .L802B789C
/* E209A4 802B7894 AC82001C */   sw       $v0, 0x1c($a0)
/* E209A8 802B7898 AC80001C */  sw        $zero, 0x1c($a0)
.L802B789C:
/* E209AC 802B789C 3C01428C */  lui       $at, 0x428c
/* E209B0 802B78A0 44810000 */  mtc1      $at, $f0
/* E209B4 802B78A4 00000000 */  nop
/* E209B8 802B78A8 460C003E */  c.le.s    $f0, $f12
/* E209BC 802B78AC 00000000 */  nop
/* E209C0 802B78B0 45000008 */  bc1f      .L802B78D4
/* E209C4 802B78B4 00000000 */   nop
/* E209C8 802B78B8 3C0142DC */  lui       $at, 0x42dc
/* E209CC 802B78BC 44810000 */  mtc1      $at, $f0
/* E209D0 802B78C0 00000000 */  nop
/* E209D4 802B78C4 4600603E */  c.le.s    $f12, $f0
/* E209D8 802B78C8 00000000 */  nop
/* E209DC 802B78CC 4501000F */  bc1t      .L802B790C
/* E209E0 802B78D0 00000000 */   nop
.L802B78D4:
/* E209E4 802B78D4 3C01437A */  lui       $at, 0x437a
/* E209E8 802B78D8 44810000 */  mtc1      $at, $f0
/* E209EC 802B78DC 00000000 */  nop
/* E209F0 802B78E0 460C003E */  c.le.s    $f0, $f12
/* E209F4 802B78E4 00000000 */  nop
/* E209F8 802B78E8 4500000C */  bc1f      .L802B791C
/* E209FC 802B78EC 00000000 */   nop
/* E20A00 802B78F0 3C014391 */  lui       $at, 0x4391
/* E20A04 802B78F4 44810000 */  mtc1      $at, $f0
/* E20A08 802B78F8 00000000 */  nop
/* E20A0C 802B78FC 4600603E */  c.le.s    $f12, $f0
/* E20A10 802B7900 00000000 */  nop
/* E20A14 802B7904 45000005 */  bc1f      .L802B791C
/* E20A18 802B7908 00000000 */   nop
.L802B790C:
/* E20A1C 802B790C 3C02802B */  lui       $v0, %hi(func_802B79C8_E20AD8)
/* E20A20 802B7910 244279C8 */  addiu     $v0, $v0, %lo(func_802B79C8_E20AD8)
/* E20A24 802B7914 3C018011 */  lui       $at, %hi(D_8010C958)
/* E20A28 802B7918 AC22C958 */  sw        $v0, %lo(D_8010C958)($at)
.L802B791C:
/* E20A2C 802B791C 0C0ADC00 */  jal       E20110_UnkAngleFunc1
/* E20A30 802B7920 00000000 */   nop
/* E20A34 802B7924 0040802D */  daddu     $s0, $v0, $zero
.L802B7928:
/* E20A38 802B7928 3C02802B */  lui       $v0, %hi(D_802B7CB8_E20DC8)
/* E20A3C 802B792C 8C427CB8 */  lw        $v0, %lo(D_802B7CB8_E20DC8)($v0)
/* E20A40 802B7930 A0500024 */  sb        $s0, 0x24($v0)
/* E20A44 802B7934 0C0ADD14 */  jal       func_802B7450_E20560
/* E20A48 802B7938 823000B4 */   lb       $s0, 0xb4($s1)
/* E20A4C 802B793C 1040000A */  beqz      $v0, .L802B7968
/* E20A50 802B7940 00000000 */   nop
/* E20A54 802B7944 82220015 */  lb        $v0, 0x15($s1)
/* E20A58 802B7948 14400007 */  bnez      $v0, .L802B7968
/* E20A5C 802B794C 00000000 */   nop
/* E20A60 802B7950 8E220000 */  lw        $v0, ($s1)
/* E20A64 802B7954 30420020 */  andi      $v0, $v0, 0x20
/* E20A68 802B7958 14400003 */  bnez      $v0, .L802B7968
/* E20A6C 802B795C 2E020003 */   sltiu    $v0, $s0, 3
/* E20A70 802B7960 14400005 */  bnez      $v0, .L802B7978
/* E20A74 802B7964 00000000 */   nop
.L802B7968:
/* E20A78 802B7968 3C03802B */  lui       $v1, %hi(D_802B7CB8_E20DC8)
/* E20A7C 802B796C 8C637CB8 */  lw        $v1, %lo(D_802B7CB8_E20DC8)($v1)
/* E20A80 802B7970 24020003 */  addiu     $v0, $zero, 3
/* E20A84 802B7974 A0620023 */  sb        $v0, 0x23($v1)
.L802B7978:
/* E20A88 802B7978 862400C6 */  lh        $a0, 0xc6($s1)
/* E20A8C 802B797C 962200C6 */  lhu       $v0, 0xc6($s1)
/* E20A90 802B7980 0480000C */  bltz      $a0, .L802B79B4
/* E20A94 802B7984 30424000 */   andi     $v0, $v0, 0x4000
/* E20A98 802B7988 1040000A */  beqz      $v0, .L802B79B4
/* E20A9C 802B798C 00000000 */   nop
/* E20AA0 802B7990 0C04417A */  jal       get_entity_by_index
/* E20AA4 802B7994 00000000 */   nop
/* E20AA8 802B7998 8C420000 */  lw        $v0, ($v0)
/* E20AAC 802B799C 30421000 */  andi      $v0, $v0, 0x1000
/* E20AB0 802B79A0 14400004 */  bnez      $v0, .L802B79B4
/* E20AB4 802B79A4 24020003 */   addiu    $v0, $zero, 3
/* E20AB8 802B79A8 3C03802B */  lui       $v1, %hi(D_802B7CB8_E20DC8)
/* E20ABC 802B79AC 8C637CB8 */  lw        $v1, %lo(D_802B7CB8_E20DC8)($v1)
/* E20AC0 802B79B0 A0620023 */  sb        $v0, 0x23($v1)
.L802B79B4:
/* E20AC4 802B79B4 8FBF0018 */  lw        $ra, 0x18($sp)
/* E20AC8 802B79B8 8FB10014 */  lw        $s1, 0x14($sp)
/* E20ACC 802B79BC 8FB00010 */  lw        $s0, 0x10($sp)
/* E20AD0 802B79C0 03E00008 */  jr        $ra
/* E20AD4 802B79C4 27BD0020 */   addiu    $sp, $sp, 0x20
