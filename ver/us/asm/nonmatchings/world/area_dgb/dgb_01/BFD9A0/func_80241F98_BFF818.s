.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F98_BFF818
/* BFF818 80241F98 27BDFF88 */  addiu     $sp, $sp, -0x78
/* BFF81C 80241F9C AFB20048 */  sw        $s2, 0x48($sp)
/* BFF820 80241FA0 0080902D */  daddu     $s2, $a0, $zero
/* BFF824 80241FA4 AFBF0054 */  sw        $ra, 0x54($sp)
/* BFF828 80241FA8 AFB40050 */  sw        $s4, 0x50($sp)
/* BFF82C 80241FAC AFB3004C */  sw        $s3, 0x4c($sp)
/* BFF830 80241FB0 AFB10044 */  sw        $s1, 0x44($sp)
/* BFF834 80241FB4 AFB00040 */  sw        $s0, 0x40($sp)
/* BFF838 80241FB8 F7BA0070 */  sdc1      $f26, 0x70($sp)
/* BFF83C 80241FBC F7B80068 */  sdc1      $f24, 0x68($sp)
/* BFF840 80241FC0 F7B60060 */  sdc1      $f22, 0x60($sp)
/* BFF844 80241FC4 F7B40058 */  sdc1      $f20, 0x58($sp)
/* BFF848 80241FC8 8E500148 */  lw        $s0, 0x148($s2)
/* BFF84C 80241FCC 00A0982D */  daddu     $s3, $a1, $zero
/* BFF850 80241FD0 86040008 */  lh        $a0, 8($s0)
/* BFF854 80241FD4 0C00EABB */  jal       get_npc_unsafe
/* BFF858 80241FD8 00C0A02D */   daddu    $s4, $a2, $zero
/* BFF85C 80241FDC 0040882D */  daddu     $s1, $v0, $zero
/* BFF860 80241FE0 C6200038 */  lwc1      $f0, 0x38($s1)
/* BFF864 80241FE4 C622003C */  lwc1      $f2, 0x3c($s1)
/* BFF868 80241FE8 C6240040 */  lwc1      $f4, 0x40($s1)
/* BFF86C 80241FEC 3C01447A */  lui       $at, 0x447a
/* BFF870 80241FF0 44813000 */  mtc1      $at, $f6
/* BFF874 80241FF4 C60C0074 */  lwc1      $f12, 0x74($s0)
/* BFF878 80241FF8 46806320 */  cvt.s.w   $f12, $f12
/* BFF87C 80241FFC E7A00028 */  swc1      $f0, 0x28($sp)
/* BFF880 80242000 E7A2002C */  swc1      $f2, 0x2c($sp)
/* BFF884 80242004 E7A40030 */  swc1      $f4, 0x30($sp)
/* BFF888 80242008 E7A60034 */  swc1      $f6, 0x34($sp)
/* BFF88C 8024200C C6000078 */  lwc1      $f0, 0x78($s0)
/* BFF890 80242010 46800020 */  cvt.s.w   $f0, $f0
/* BFF894 80242014 46000021 */  cvt.d.s   $f0, $f0
/* BFF898 80242018 C6020088 */  lwc1      $f2, 0x88($s0)
/* BFF89C 8024201C 468010A0 */  cvt.s.w   $f2, $f2
/* BFF8A0 80242020 3C014059 */  lui       $at, 0x4059
/* BFF8A4 80242024 44812800 */  mtc1      $at, $f5
/* BFF8A8 80242028 44802000 */  mtc1      $zero, $f4
/* BFF8AC 8024202C 460010A1 */  cvt.d.s   $f2, $f2
/* BFF8B0 80242030 46240003 */  div.d     $f0, $f0, $f4
/* BFF8B4 80242034 462006A0 */  cvt.s.d   $f26, $f0
/* BFF8B8 80242038 46241083 */  div.d     $f2, $f2, $f4
/* BFF8BC 8024203C 462010A0 */  cvt.s.d   $f2, $f2
/* BFF8C0 80242040 C6000070 */  lwc1      $f0, 0x70($s0)
/* BFF8C4 80242044 46800020 */  cvt.s.w   $f0, $f0
/* BFF8C8 80242048 46000021 */  cvt.d.s   $f0, $f0
/* BFF8CC 8024204C 46240003 */  div.d     $f0, $f0, $f4
/* BFF8D0 80242050 462005A0 */  cvt.s.d   $f22, $f0
/* BFF8D4 80242054 0C00A8BB */  jal       sin_deg
/* BFF8D8 80242058 4602D600 */   add.s    $f24, $f26, $f2
/* BFF8DC 8024205C 27A50028 */  addiu     $a1, $sp, 0x28
/* BFF8E0 80242060 27A6002C */  addiu     $a2, $sp, 0x2c
/* BFF8E4 80242064 27A70030 */  addiu     $a3, $sp, 0x30
/* BFF8E8 80242068 27A20034 */  addiu     $v0, $sp, 0x34
/* BFF8EC 8024206C AFA20010 */  sw        $v0, 0x10($sp)
/* BFF8F0 80242070 8E240080 */  lw        $a0, 0x80($s1)
/* BFF8F4 80242074 0C0372DF */  jal       func_800DCB7C
/* BFF8F8 80242078 46000506 */   mov.s    $f20, $f0
/* BFF8FC 8024207C 10400007 */  beqz      $v0, .L8024209C
/* BFF900 80242080 00000000 */   nop
/* BFF904 80242084 4616A082 */  mul.s     $f2, $f20, $f22
/* BFF908 80242088 00000000 */  nop
/* BFF90C 8024208C C7A0002C */  lwc1      $f0, 0x2c($sp)
/* BFF910 80242090 461A0000 */  add.s     $f0, $f0, $f26
/* BFF914 80242094 0809082A */  j         .L802420A8
/* BFF918 80242098 46020000 */   add.s    $f0, $f0, $f2
.L8024209C:
/* BFF91C 8024209C 4616A002 */  mul.s     $f0, $f20, $f22
/* BFF920 802420A0 00000000 */  nop
/* BFF924 802420A4 4600C000 */  add.s     $f0, $f24, $f0
.L802420A8:
/* BFF928 802420A8 E620003C */  swc1      $f0, 0x3c($s1)
/* BFF92C 802420AC 8E020074 */  lw        $v0, 0x74($s0)
/* BFF930 802420B0 2442000C */  addiu     $v0, $v0, 0xc
/* BFF934 802420B4 44826000 */  mtc1      $v0, $f12
/* BFF938 802420B8 00000000 */  nop
/* BFF93C 802420BC 0C00A6C9 */  jal       clamp_angle
/* BFF940 802420C0 46806320 */   cvt.s.w  $f12, $f12
/* BFF944 802420C4 4600020D */  trunc.w.s $f8, $f0
/* BFF948 802420C8 E6080074 */  swc1      $f8, 0x74($s0)
/* BFF94C 802420CC 8E420074 */  lw        $v0, 0x74($s2)
/* BFF950 802420D0 1C400037 */  bgtz      $v0, .L802421B0
/* BFF954 802420D4 2442FFFF */   addiu    $v0, $v0, -1
/* BFF958 802420D8 8E620014 */  lw        $v0, 0x14($s3)
/* BFF95C 802420DC AE420074 */  sw        $v0, 0x74($s2)
/* BFF960 802420E0 C662000C */  lwc1      $f2, 0xc($s3)
/* BFF964 802420E4 3C013FE0 */  lui       $at, 0x3fe0
/* BFF968 802420E8 44812800 */  mtc1      $at, $f5
/* BFF96C 802420EC 44802000 */  mtc1      $zero, $f4
/* BFF970 802420F0 460010A1 */  cvt.d.s   $f2, $f2
/* BFF974 802420F4 46241082 */  mul.d     $f2, $f2, $f4
/* BFF978 802420F8 00000000 */  nop
/* BFF97C 802420FC C6600010 */  lwc1      $f0, 0x10($s3)
/* BFF980 80242100 46000021 */  cvt.d.s   $f0, $f0
/* BFF984 80242104 46240002 */  mul.d     $f0, $f0, $f4
/* BFF988 80242108 00000000 */  nop
/* BFF98C 8024210C 0280202D */  daddu     $a0, $s4, $zero
/* BFF990 80242110 462010A0 */  cvt.s.d   $f2, $f2
/* BFF994 80242114 46200020 */  cvt.s.d   $f0, $f0
/* BFF998 80242118 44061000 */  mfc1      $a2, $f2
/* BFF99C 8024211C 44070000 */  mfc1      $a3, $f0
/* BFF9A0 80242120 0200282D */  daddu     $a1, $s0, $zero
/* BFF9A4 80242124 0C01242D */  jal       func_800490B4
/* BFF9A8 80242128 AFA00010 */   sw       $zero, 0x10($sp)
/* BFF9AC 8024212C 1040001E */  beqz      $v0, .L802421A8
/* BFF9B0 80242130 0000202D */   daddu    $a0, $zero, $zero
/* BFF9B4 80242134 0220282D */  daddu     $a1, $s1, $zero
/* BFF9B8 80242138 0000302D */  daddu     $a2, $zero, $zero
/* BFF9BC 8024213C 2410000C */  addiu     $s0, $zero, 0xc
/* BFF9C0 80242140 862300A8 */  lh        $v1, 0xa8($s1)
/* BFF9C4 80242144 3C013F80 */  lui       $at, 0x3f80
/* BFF9C8 80242148 44810000 */  mtc1      $at, $f0
/* BFF9CC 8024214C 3C014000 */  lui       $at, 0x4000
/* BFF9D0 80242150 44811000 */  mtc1      $at, $f2
/* BFF9D4 80242154 3C01C1A0 */  lui       $at, 0xc1a0
/* BFF9D8 80242158 44812000 */  mtc1      $at, $f4
/* BFF9DC 8024215C 44834000 */  mtc1      $v1, $f8
/* BFF9E0 80242160 00000000 */  nop
/* BFF9E4 80242164 46804220 */  cvt.s.w   $f8, $f8
/* BFF9E8 80242168 44074000 */  mfc1      $a3, $f8
/* BFF9EC 8024216C 27A20038 */  addiu     $v0, $sp, 0x38
/* BFF9F0 80242170 AFB0001C */  sw        $s0, 0x1c($sp)
/* BFF9F4 80242174 AFA20020 */  sw        $v0, 0x20($sp)
/* BFF9F8 80242178 E7A00010 */  swc1      $f0, 0x10($sp)
/* BFF9FC 8024217C E7A20014 */  swc1      $f2, 0x14($sp)
/* BFFA00 80242180 0C01BFA4 */  jal       fx_emote
/* BFFA04 80242184 E7A40018 */   swc1     $f4, 0x18($sp)
/* BFFA08 80242188 0220202D */  daddu     $a0, $s1, $zero
/* BFFA0C 8024218C 240502F4 */  addiu     $a1, $zero, 0x2f4
/* BFFA10 80242190 0C012530 */  jal       func_800494C0
/* BFFA14 80242194 3C060020 */   lui      $a2, 0x20
/* BFFA18 80242198 C620003C */  lwc1      $f0, 0x3c($s1)
/* BFFA1C 8024219C E6200064 */  swc1      $f0, 0x64($s1)
/* BFFA20 802421A0 080908A0 */  j         .L80242280
/* BFFA24 802421A4 AE500070 */   sw       $s0, 0x70($s2)
.L802421A8:
/* BFFA28 802421A8 8E420074 */  lw        $v0, 0x74($s2)
/* BFFA2C 802421AC 2442FFFF */  addiu     $v0, $v0, -1
.L802421B0:
/* BFFA30 802421B0 AE420074 */  sw        $v0, 0x74($s2)
/* BFFA34 802421B4 8622008C */  lh        $v0, 0x8c($s1)
/* BFFA38 802421B8 14400031 */  bnez      $v0, .L80242280
/* BFFA3C 802421BC 00000000 */   nop
/* BFFA40 802421C0 C62C0038 */  lwc1      $f12, 0x38($s1)
/* BFFA44 802421C4 8E0200D0 */  lw        $v0, 0xd0($s0)
/* BFFA48 802421C8 C62E0040 */  lwc1      $f14, 0x40($s1)
/* BFFA4C 802421CC C4480000 */  lwc1      $f8, ($v0)
/* BFFA50 802421D0 46804220 */  cvt.s.w   $f8, $f8
/* BFFA54 802421D4 44064000 */  mfc1      $a2, $f8
/* BFFA58 802421D8 C4480008 */  lwc1      $f8, 8($v0)
/* BFFA5C 802421DC 46804220 */  cvt.s.w   $f8, $f8
/* BFFA60 802421E0 44074000 */  mfc1      $a3, $f8
/* BFFA64 802421E4 0C00A720 */  jal       atan2
/* BFFA68 802421E8 00000000 */   nop
/* BFFA6C 802421EC 8E250018 */  lw        $a1, 0x18($s1)
/* BFFA70 802421F0 44060000 */  mfc1      $a2, $f0
/* BFFA74 802421F4 0220202D */  daddu     $a0, $s1, $zero
/* BFFA78 802421F8 0C00EA95 */  jal       npc_move_heading
/* BFFA7C 802421FC AE26000C */   sw       $a2, 0xc($s1)
/* BFFA80 80242200 C62C0038 */  lwc1      $f12, 0x38($s1)
/* BFFA84 80242204 8E0200D0 */  lw        $v0, 0xd0($s0)
/* BFFA88 80242208 C62E0040 */  lwc1      $f14, 0x40($s1)
/* BFFA8C 8024220C C4480000 */  lwc1      $f8, ($v0)
/* BFFA90 80242210 46804220 */  cvt.s.w   $f8, $f8
/* BFFA94 80242214 44064000 */  mfc1      $a2, $f8
/* BFFA98 80242218 C4480008 */  lwc1      $f8, 8($v0)
/* BFFA9C 8024221C 46804220 */  cvt.s.w   $f8, $f8
/* BFFAA0 80242220 44074000 */  mfc1      $a3, $f8
/* BFFAA4 80242224 0C00A7B5 */  jal       dist2D
/* BFFAA8 80242228 00000000 */   nop
/* BFFAAC 8024222C C6220018 */  lwc1      $f2, 0x18($s1)
/* BFFAB0 80242230 46021080 */  add.s     $f2, $f2, $f2
/* BFFAB4 80242234 4602003E */  c.le.s    $f0, $f2
/* BFFAB8 80242238 00000000 */  nop
/* BFFABC 8024223C 45000010 */  bc1f      .L80242280
/* BFFAC0 80242240 E7A00034 */   swc1     $f0, 0x34($sp)
/* BFFAC4 80242244 0C00A67F */  jal       rand_int
/* BFFAC8 80242248 240403E8 */   addiu    $a0, $zero, 0x3e8
/* BFFACC 8024224C 3C035555 */  lui       $v1, 0x5555
/* BFFAD0 80242250 34635556 */  ori       $v1, $v1, 0x5556
/* BFFAD4 80242254 00430018 */  mult      $v0, $v1
/* BFFAD8 80242258 24030002 */  addiu     $v1, $zero, 2
/* BFFADC 8024225C 000227C3 */  sra       $a0, $v0, 0x1f
/* BFFAE0 80242260 AE430070 */  sw        $v1, 0x70($s2)
/* BFFAE4 80242264 00004010 */  mfhi      $t0
/* BFFAE8 80242268 01042023 */  subu      $a0, $t0, $a0
/* BFFAEC 8024226C 00041840 */  sll       $v1, $a0, 1
/* BFFAF0 80242270 00641821 */  addu      $v1, $v1, $a0
/* BFFAF4 80242274 00431023 */  subu      $v0, $v0, $v1
/* BFFAF8 80242278 24420002 */  addiu     $v0, $v0, 2
/* BFFAFC 8024227C AE420074 */  sw        $v0, 0x74($s2)
.L80242280:
/* BFFB00 80242280 8FBF0054 */  lw        $ra, 0x54($sp)
/* BFFB04 80242284 8FB40050 */  lw        $s4, 0x50($sp)
/* BFFB08 80242288 8FB3004C */  lw        $s3, 0x4c($sp)
/* BFFB0C 8024228C 8FB20048 */  lw        $s2, 0x48($sp)
/* BFFB10 80242290 8FB10044 */  lw        $s1, 0x44($sp)
/* BFFB14 80242294 8FB00040 */  lw        $s0, 0x40($sp)
/* BFFB18 80242298 D7BA0070 */  ldc1      $f26, 0x70($sp)
/* BFFB1C 8024229C D7B80068 */  ldc1      $f24, 0x68($sp)
/* BFFB20 802422A0 D7B60060 */  ldc1      $f22, 0x60($sp)
/* BFFB24 802422A4 D7B40058 */  ldc1      $f20, 0x58($sp)
/* BFFB28 802422A8 03E00008 */  jr        $ra
/* BFFB2C 802422AC 27BD0078 */   addiu    $sp, $sp, 0x78
