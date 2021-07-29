.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB044_E2B774
/* E2B774 802BB044 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* E2B778 802BB048 AFB10014 */  sw        $s1, 0x14($sp)
/* E2B77C 802BB04C 0080882D */  daddu     $s1, $a0, $zero
/* E2B780 802BB050 AFB20018 */  sw        $s2, 0x18($sp)
/* E2B784 802BB054 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* E2B788 802BB058 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* E2B78C 802BB05C AFBF001C */  sw        $ra, 0x1c($sp)
/* E2B790 802BB060 AFB00010 */  sw        $s0, 0x10($sp)
/* E2B794 802BB064 F7B80030 */  sdc1      $f24, 0x30($sp)
/* E2B798 802BB068 F7B60028 */  sdc1      $f22, 0x28($sp)
/* E2B79C 802BB06C F7B40020 */  sdc1      $f20, 0x20($sp)
/* E2B7A0 802BB070 C640002C */  lwc1      $f0, 0x2c($s2)
/* E2B7A4 802BB074 C622004C */  lwc1      $f2, 0x4c($s1)
/* E2B7A8 802BB078 864200B0 */  lh        $v0, 0xb0($s2)
/* E2B7AC 802BB07C 46020001 */  sub.s     $f0, $f0, $f2
/* E2B7B0 802BB080 8E300040 */  lw        $s0, 0x40($s1)
/* E2B7B4 802BB084 44821000 */  mtc1      $v0, $f2
/* E2B7B8 802BB088 00000000 */  nop
/* E2B7BC 802BB08C 468010A1 */  cvt.d.w   $f2, $f2
/* E2B7C0 802BB090 46000021 */  cvt.d.s   $f0, $f0
/* E2B7C4 802BB094 46200005 */  abs.d     $f0, $f0
/* E2B7C8 802BB098 4620103C */  c.lt.d    $f2, $f0
/* E2B7CC 802BB09C 00000000 */  nop
/* E2B7D0 802BB0A0 45000004 */  bc1f      .L802BB0B4
/* E2B7D4 802BB0A4 2403FFDF */   addiu    $v1, $zero, -0x21
/* E2B7D8 802BB0A8 8E220000 */  lw        $v0, ($s1)
/* E2B7DC 802BB0AC 080AEC2F */  j         .L802BB0BC
/* E2B7E0 802BB0B0 34420020 */   ori      $v0, $v0, 0x20
.L802BB0B4:
/* E2B7E4 802BB0B4 8E220000 */  lw        $v0, ($s1)
/* E2B7E8 802BB0B8 00431024 */  and       $v0, $v0, $v1
.L802BB0BC:
/* E2B7EC 802BB0BC AE220000 */  sw        $v0, ($s1)
/* E2B7F0 802BB0C0 92220006 */  lbu       $v0, 6($s1)
/* E2B7F4 802BB0C4 30420001 */  andi      $v0, $v0, 1
/* E2B7F8 802BB0C8 5040003E */  beql      $v0, $zero, .L802BB1C4
/* E2B7FC 802BB0CC AE000000 */   sw       $zero, ($s0)
/* E2B800 802BB0D0 C6020000 */  lwc1      $f2, ($s0)
/* E2B804 802BB0D4 44800000 */  mtc1      $zero, $f0
/* E2B808 802BB0D8 00000000 */  nop
/* E2B80C 802BB0DC 46001032 */  c.eq.s    $f2, $f0
/* E2B810 802BB0E0 00000000 */  nop
/* E2B814 802BB0E4 45000003 */  bc1f      .L802BB0F4
/* E2B818 802BB0E8 3C040001 */   lui      $a0, 1
/* E2B81C 802BB0EC 0C037FBF */  jal       suggest_player_anim_clearUnkFlag
/* E2B820 802BB0F0 34840005 */   ori      $a0, $a0, 5
.L802BB0F4:
/* E2B824 802BB0F4 C6000000 */  lwc1      $f0, ($s0)
/* E2B828 802BB0F8 3C013FE0 */  lui       $at, 0x3fe0
/* E2B82C 802BB0FC 44811800 */  mtc1      $at, $f3
/* E2B830 802BB100 44801000 */  mtc1      $zero, $f2
/* E2B834 802BB104 46000021 */  cvt.d.s   $f0, $f0
/* E2B838 802BB108 46220000 */  add.d     $f0, $f0, $f2
/* E2B83C 802BB10C 3C014004 */  lui       $at, 0x4004
/* E2B840 802BB110 44812800 */  mtc1      $at, $f5
/* E2B844 802BB114 44802000 */  mtc1      $zero, $f4
/* E2B848 802BB118 46200020 */  cvt.s.d   $f0, $f0
/* E2B84C 802BB11C 460000A1 */  cvt.d.s   $f2, $f0
/* E2B850 802BB120 4622203E */  c.le.d    $f4, $f2
/* E2B854 802BB124 00000000 */  nop
/* E2B858 802BB128 45000005 */  bc1f      .L802BB140
/* E2B85C 802BB12C E6000000 */   swc1     $f0, ($s0)
/* E2B860 802BB130 3C014020 */  lui       $at, 0x4020
/* E2B864 802BB134 44810000 */  mtc1      $at, $f0
/* E2B868 802BB138 00000000 */  nop
/* E2B86C 802BB13C E6000000 */  swc1      $f0, ($s0)
.L802BB140:
/* E2B870 802BB140 C62C0064 */  lwc1      $f12, 0x64($s1)
/* E2B874 802BB144 3C014334 */  lui       $at, 0x4334
/* E2B878 802BB148 4481A000 */  mtc1      $at, $f20
/* E2B87C 802BB14C 00000000 */  nop
/* E2B880 802BB150 460CA301 */  sub.s     $f12, $f20, $f12
/* E2B884 802BB154 3C0140C9 */  lui       $at, 0x40c9
/* E2B888 802BB158 34210FD0 */  ori       $at, $at, 0xfd0
/* E2B88C 802BB15C 4481B000 */  mtc1      $at, $f22
/* E2B890 802BB160 00000000 */  nop
/* E2B894 802BB164 46166302 */  mul.s     $f12, $f12, $f22
/* E2B898 802BB168 00000000 */  nop
/* E2B89C 802BB16C 3C0143B4 */  lui       $at, 0x43b4
/* E2B8A0 802BB170 4481C000 */  mtc1      $at, $f24
/* E2B8A4 802BB174 0C00A85B */  jal       sin_rad
/* E2B8A8 802BB178 46186303 */   div.s    $f12, $f12, $f24
/* E2B8AC 802BB17C C6220064 */  lwc1      $f2, 0x64($s1)
/* E2B8B0 802BB180 4602A501 */  sub.s     $f20, $f20, $f2
/* E2B8B4 802BB184 4616A502 */  mul.s     $f20, $f20, $f22
/* E2B8B8 802BB188 00000000 */  nop
/* E2B8BC 802BB18C C6160000 */  lwc1      $f22, ($s0)
/* E2B8C0 802BB190 4600B582 */  mul.s     $f22, $f22, $f0
/* E2B8C4 802BB194 00000000 */  nop
/* E2B8C8 802BB198 0C00A874 */  jal       cos_rad
/* E2B8CC 802BB19C 4618A303 */   div.s    $f12, $f20, $f24
/* E2B8D0 802BB1A0 C6040000 */  lwc1      $f4, ($s0)
/* E2B8D4 802BB1A4 46002102 */  mul.s     $f4, $f4, $f0
/* E2B8D8 802BB1A8 00000000 */  nop
/* E2B8DC 802BB1AC C6420028 */  lwc1      $f2, 0x28($s2)
/* E2B8E0 802BB1B0 46161080 */  add.s     $f2, $f2, $f22
/* E2B8E4 802BB1B4 C6400030 */  lwc1      $f0, 0x30($s2)
/* E2B8E8 802BB1B8 46040001 */  sub.s     $f0, $f0, $f4
/* E2B8EC 802BB1BC E6420028 */  swc1      $f2, 0x28($s2)
/* E2B8F0 802BB1C0 E6400030 */  swc1      $f0, 0x30($s2)
.L802BB1C4:
/* E2B8F4 802BB1C4 8FBF001C */  lw        $ra, 0x1c($sp)
/* E2B8F8 802BB1C8 8FB20018 */  lw        $s2, 0x18($sp)
/* E2B8FC 802BB1CC 8FB10014 */  lw        $s1, 0x14($sp)
/* E2B900 802BB1D0 8FB00010 */  lw        $s0, 0x10($sp)
/* E2B904 802BB1D4 D7B80030 */  ldc1      $f24, 0x30($sp)
/* E2B908 802BB1D8 D7B60028 */  ldc1      $f22, 0x28($sp)
/* E2B90C 802BB1DC D7B40020 */  ldc1      $f20, 0x20($sp)
/* E2B910 802BB1E0 03E00008 */  jr        $ra
/* E2B914 802BB1E4 27BD0038 */   addiu    $sp, $sp, 0x38
