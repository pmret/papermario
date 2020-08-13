.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel ForceExitHeading
/* 0F6920 802D1F70 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0F6924 802D1F74 AFB20020 */  sw    $s2, 0x20($sp)
/* 0F6928 802D1F78 0080902D */  daddu $s2, $a0, $zero
/* 0F692C 802D1F7C AFBF0028 */  sw    $ra, 0x28($sp)
/* 0F6930 802D1F80 AFB30024 */  sw    $s3, 0x24($sp)
/* 0F6934 802D1F84 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0F6938 802D1F88 AFB00018 */  sw    $s0, 0x18($sp)
/* 0F693C 802D1F8C F7B60038 */  sdc1  $f22, 0x38($sp)
/* 0F6940 802D1F90 F7B40030 */  sdc1  $f20, 0x30($sp)
/* 0F6944 802D1F94 0C016AFA */  jal   get_current_map_header
/* 0F6948 802D1F98 8E50000C */   lw    $s0, 0xc($s2)
/* 0F694C 802D1F9C 0240202D */  daddu $a0, $s2, $zero
/* 0F6950 802D1FA0 0040882D */  daddu $s1, $v0, $zero
/* 0F6954 802D1FA4 8E050000 */  lw    $a1, ($s0)
/* 0F6958 802D1FA8 0C0B1EAF */  jal   get_variable
/* 0F695C 802D1FAC 26100004 */   addiu $s0, $s0, 4
/* 0F6960 802D1FB0 0240202D */  daddu $a0, $s2, $zero
/* 0F6964 802D1FB4 8E050000 */  lw    $a1, ($s0)
/* 0F6968 802D1FB8 0C0B1EAF */  jal   get_variable
/* 0F696C 802D1FBC 0040982D */   daddu $s3, $v0, $zero
/* 0F6970 802D1FC0 3C108007 */  lui   $s0, 0x8007
/* 0F6974 802D1FC4 2610419C */  addiu $s0, $s0, 0x419c
/* 0F6978 802D1FC8 8E050000 */  lw    $a1, ($s0)
/* 0F697C 802D1FCC 84A3008E */  lh    $v1, 0x8e($a1)
/* 0F6980 802D1FD0 8E240014 */  lw    $a0, 0x14($s1)
/* 0F6984 802D1FD4 00031900 */  sll   $v1, $v1, 4
/* 0F6988 802D1FD8 00641821 */  addu  $v1, $v1, $a0
/* 0F698C 802D1FDC C4600000 */  lwc1  $f0, ($v1)
/* 0F6990 802D1FE0 4600020D */  trunc.w.s $f8, $f0
/* 0F6994 802D1FE4 44074000 */  mfc1  $a3, $f8
/* 0F6998 802D1FE8 00000000 */  nop   
/* 0F699C 802D1FEC AE470088 */  sw    $a3, 0x88($s2)
/* 0F69A0 802D1FF0 84A3008E */  lh    $v1, 0x8e($a1)
/* 0F69A4 802D1FF4 8E240014 */  lw    $a0, 0x14($s1)
/* 0F69A8 802D1FF8 00031900 */  sll   $v1, $v1, 4
/* 0F69AC 802D1FFC 00641821 */  addu  $v1, $v1, $a0
/* 0F69B0 802D2000 C4600004 */  lwc1  $f0, 4($v1)
/* 0F69B4 802D2004 4600020D */  trunc.w.s $f8, $f0
/* 0F69B8 802D2008 E648008C */  swc1  $f8, 0x8c($s2)
/* 0F69BC 802D200C 84A3008E */  lh    $v1, 0x8e($a1)
/* 0F69C0 802D2010 8E240014 */  lw    $a0, 0x14($s1)
/* 0F69C4 802D2014 00031900 */  sll   $v1, $v1, 4
/* 0F69C8 802D2018 00641821 */  addu  $v1, $v1, $a0
/* 0F69CC 802D201C C4600008 */  lwc1  $f0, 8($v1)
/* 0F69D0 802D2020 3C014334 */  lui   $at, 0x4334
/* 0F69D4 802D2024 44816000 */  mtc1  $at, $f12
/* 0F69D8 802D2028 4600020D */  trunc.w.s $f8, $f0
/* 0F69DC 802D202C 44064000 */  mfc1  $a2, $f8
/* 0F69E0 802D2030 00000000 */  nop   
/* 0F69E4 802D2034 AE460090 */  sw    $a2, 0x90($s2)
/* 0F69E8 802D2038 84A3008E */  lh    $v1, 0x8e($a1)
/* 0F69EC 802D203C 8E240014 */  lw    $a0, 0x14($s1)
/* 0F69F0 802D2040 00031900 */  sll   $v1, $v1, 4
/* 0F69F4 802D2044 00641821 */  addu  $v1, $v1, $a0
/* 0F69F8 802D2048 C460000C */  lwc1  $f0, 0xc($v1)
/* 0F69FC 802D204C 4487A000 */  mtc1  $a3, $f20
/* 0F6A00 802D2050 00000000 */  nop   
/* 0F6A04 802D2054 4680A520 */  cvt.s.w $f20, $f20
/* 0F6A08 802D2058 460C0300 */  add.s $f12, $f0, $f12
/* 0F6A0C 802D205C 4486B000 */  mtc1  $a2, $f22
/* 0F6A10 802D2060 00000000 */  nop   
/* 0F6A14 802D2064 4680B5A0 */  cvt.s.w $f22, $f22
/* 0F6A18 802D2068 0C00A6C9 */  jal   clamp_angle
/* 0F6A1C 802D206C 0040882D */   daddu $s1, $v0, $zero
/* 0F6A20 802D2070 46000306 */  mov.s $f12, $f0
/* 0F6A24 802D2074 27A50010 */  addiu $a1, $sp, 0x10
/* 0F6A28 802D2078 0C00A88D */  jal   sin_cos_deg
/* 0F6A2C 802D207C 27A60014 */   addiu $a2, $sp, 0x14
/* 0F6A30 802D2080 C7A40010 */  lwc1  $f4, 0x10($sp)
/* 0F6A34 802D2084 44937000 */  mtc1  $s3, $f14
/* 0F6A38 802D2088 00000000 */  nop   
/* 0F6A3C 802D208C 468073A0 */  cvt.s.w $f14, $f14
/* 0F6A40 802D2090 46047302 */  mul.s $f12, $f14, $f4
/* 0F6A44 802D2094 00000000 */  nop   
/* 0F6A48 802D2098 8E020000 */  lw    $v0, ($s0)
/* 0F6A4C 802D209C 3C013E99 */  lui   $at, 0x3e99
/* 0F6A50 802D20A0 3421999A */  ori   $at, $at, 0x999a
/* 0F6A54 802D20A4 44810000 */  mtc1  $at, $f0
/* 0F6A58 802D20A8 C4420094 */  lwc1  $f2, 0x94($v0)
/* 0F6A5C 802D20AC 46001082 */  mul.s $f2, $f2, $f0
/* 0F6A60 802D20B0 00000000 */  nop   
/* 0F6A64 802D20B4 C7A00014 */  lwc1  $f0, 0x14($sp)
/* 0F6A68 802D20B8 46007382 */  mul.s $f14, $f14, $f0
/* 0F6A6C 802D20BC 00000000 */  nop   
/* 0F6A70 802D20C0 46001182 */  mul.s $f6, $f2, $f0
/* 0F6A74 802D20C4 00000000 */  nop   
/* 0F6A78 802D20C8 46041082 */  mul.s $f2, $f2, $f4
/* 0F6A7C 802D20CC 00000000 */  nop   
/* 0F6A80 802D20D0 460CA300 */  add.s $f12, $f20, $f12
/* 0F6A84 802D20D4 460EB381 */  sub.s $f14, $f22, $f14
/* 0F6A88 802D20D8 46066301 */  sub.s $f12, $f12, $f6
/* 0F6A8C 802D20DC 4406A000 */  mfc1  $a2, $f20
/* 0F6A90 802D20E0 4407B000 */  mfc1  $a3, $f22
/* 0F6A94 802D20E4 46027381 */  sub.s $f14, $f14, $f2
/* 0F6A98 802D20E8 3C108011 */  lui   $s0, 0x8011
/* 0F6A9C 802D20EC 2610EFC8 */  addiu $s0, $s0, -0x1038
/* 0F6AA0 802D20F0 E60C0028 */  swc1  $f12, 0x28($s0)
/* 0F6AA4 802D20F4 0C00A7B5 */  jal   dist2D
/* 0F6AA8 802D20F8 E60E0030 */   swc1  $f14, 0x30($s0)
/* 0F6AAC 802D20FC 44911000 */  mtc1  $s1, $f2
/* 0F6AB0 802D2100 00000000 */  nop   
/* 0F6AB4 802D2104 468010A0 */  cvt.s.w $f2, $f2
/* 0F6AB8 802D2108 46020003 */  div.s $f0, $f0, $f2
/* 0F6ABC 802D210C E6400098 */  swc1  $f0, 0x98($s2)
/* 0F6AC0 802D2110 8E030000 */  lw    $v1, ($s0)
/* 0F6AC4 802D2114 3C040400 */  lui   $a0, 0x400
/* 0F6AC8 802D2118 00641825 */  or    $v1, $v1, $a0
/* 0F6ACC 802D211C AE030000 */  sw    $v1, ($s0)
/* 0F6AD0 802D2120 8FBF0028 */  lw    $ra, 0x28($sp)
/* 0F6AD4 802D2124 8FB30024 */  lw    $s3, 0x24($sp)
/* 0F6AD8 802D2128 8FB20020 */  lw    $s2, 0x20($sp)
/* 0F6ADC 802D212C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0F6AE0 802D2130 8FB00018 */  lw    $s0, 0x18($sp)
/* 0F6AE4 802D2134 D7B60038 */  ldc1  $f22, 0x38($sp)
/* 0F6AE8 802D2138 D7B40030 */  ldc1  $f20, 0x30($sp)
/* 0F6AEC 802D213C 24020002 */  addiu $v0, $zero, 2
/* 0F6AF0 802D2140 03E00008 */  jr    $ra
/* 0F6AF4 802D2144 27BD0040 */   addiu $sp, $sp, 0x40

/* 0F6AF8 802D2148 3C04FBFF */  lui   $a0, 0xfbff
/* 0F6AFC 802D214C 3C038011 */  lui   $v1, 0x8011
/* 0F6B00 802D2150 2463EFC8 */  addiu $v1, $v1, -0x1038
/* 0F6B04 802D2154 8C620000 */  lw    $v0, ($v1)
/* 0F6B08 802D2158 3484FFFF */  ori   $a0, $a0, 0xffff
/* 0F6B0C 802D215C 00441024 */  and   $v0, $v0, $a0
/* 0F6B10 802D2160 AC620000 */  sw    $v0, ($v1)
/* 0F6B14 802D2164 03E00008 */  jr    $ra
/* 0F6B18 802D2168 24020002 */   addiu $v0, $zero, 2

