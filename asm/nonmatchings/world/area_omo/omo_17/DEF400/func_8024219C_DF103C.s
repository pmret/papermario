.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024219C_DF103C
/* DF103C 8024219C 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* DF1040 802421A0 AFB00028 */  sw        $s0, 0x28($sp)
/* DF1044 802421A4 00A0802D */  daddu     $s0, $a1, $zero
/* DF1048 802421A8 AFB1002C */  sw        $s1, 0x2c($sp)
/* DF104C 802421AC 00C0882D */  daddu     $s1, $a2, $zero
/* DF1050 802421B0 AFBF0034 */  sw        $ra, 0x34($sp)
/* DF1054 802421B4 AFB20030 */  sw        $s2, 0x30($sp)
/* DF1058 802421B8 AE200070 */  sw        $zero, 0x70($s1)
/* DF105C 802421BC 8C830000 */  lw        $v1, ($a0)
/* DF1060 802421C0 2402FDFF */  addiu     $v0, $zero, -0x201
/* DF1064 802421C4 A480008E */  sh        $zero, 0x8e($a0)
/* DF1068 802421C8 00621824 */  and       $v1, $v1, $v0
/* DF106C 802421CC 34650800 */  ori       $a1, $v1, 0x800
/* DF1070 802421D0 AC850000 */  sw        $a1, ($a0)
/* DF1074 802421D4 8E0200D0 */  lw        $v0, 0xd0($s0)
/* DF1078 802421D8 8C420034 */  lw        $v0, 0x34($v0)
/* DF107C 802421DC 10400003 */  beqz      $v0, .L802421EC
/* DF1080 802421E0 00E0902D */   daddu    $s2, $a3, $zero
/* DF1084 802421E4 0809087D */  j         .L802421F4
/* DF1088 802421E8 34620808 */   ori      $v0, $v1, 0x808
.L802421EC:
/* DF108C 802421EC 2402FFF7 */  addiu     $v0, $zero, -9
/* DF1090 802421F0 00A21024 */  and       $v0, $a1, $v0
.L802421F4:
/* DF1094 802421F4 AC820000 */  sw        $v0, ($a0)
/* DF1098 802421F8 27A20024 */  addiu     $v0, $sp, 0x24
/* DF109C 802421FC 27A50018 */  addiu     $a1, $sp, 0x18
/* DF10A0 80242200 C4800038 */  lwc1      $f0, 0x38($a0)
/* DF10A4 80242204 C482003C */  lwc1      $f2, 0x3c($a0)
/* DF10A8 80242208 C4840040 */  lwc1      $f4, 0x40($a0)
/* DF10AC 8024220C 3C01447A */  lui       $at, 0x447a
/* DF10B0 80242210 44813000 */  mtc1      $at, $f6
/* DF10B4 80242214 27A6001C */  addiu     $a2, $sp, 0x1c
/* DF10B8 80242218 E7A00018 */  swc1      $f0, 0x18($sp)
/* DF10BC 8024221C E7A2001C */  swc1      $f2, 0x1c($sp)
/* DF10C0 80242220 E7A40020 */  swc1      $f4, 0x20($sp)
/* DF10C4 80242224 E7A60024 */  swc1      $f6, 0x24($sp)
/* DF10C8 80242228 AFA20010 */  sw        $v0, 0x10($sp)
/* DF10CC 8024222C 8C840080 */  lw        $a0, 0x80($a0)
/* DF10D0 80242230 0C0372DF */  jal       func_800DCB7C
/* DF10D4 80242234 27A70020 */   addiu    $a3, $sp, 0x20
/* DF10D8 80242238 C7A20024 */  lwc1      $f2, 0x24($sp)
/* DF10DC 8024223C 3C014059 */  lui       $at, 0x4059
/* DF10E0 80242240 44812800 */  mtc1      $at, $f5
/* DF10E4 80242244 44802000 */  mtc1      $zero, $f4
/* DF10E8 80242248 460010A1 */  cvt.d.s   $f2, $f2
/* DF10EC 8024224C 46241082 */  mul.d     $f2, $f2, $f4
/* DF10F0 80242250 00000000 */  nop
/* DF10F4 80242254 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* DF10F8 80242258 46000021 */  cvt.d.s   $f0, $f0
/* DF10FC 8024225C 46240002 */  mul.d     $f0, $f0, $f4
/* DF1100 80242260 00000000 */  nop
/* DF1104 80242264 3C013FE0 */  lui       $at, 0x3fe0
/* DF1108 80242268 44812800 */  mtc1      $at, $f5
/* DF110C 8024226C 44802000 */  mtc1      $zero, $f4
/* DF1110 80242270 00000000 */  nop
/* DF1114 80242274 46241080 */  add.d     $f2, $f2, $f4
/* DF1118 80242278 AE000074 */  sw        $zero, 0x74($s0)
/* DF111C 8024227C 46240000 */  add.d     $f0, $f0, $f4
/* DF1120 80242280 AE000090 */  sw        $zero, 0x90($s0)
/* DF1124 80242284 4620120D */  trunc.w.d $f8, $f2
/* DF1128 80242288 E6080078 */  swc1      $f8, 0x78($s0)
/* DF112C 8024228C 4620020D */  trunc.w.d $f8, $f0
/* DF1130 80242290 E6080088 */  swc1      $f8, 0x88($s0)
/* DF1134 80242294 8E420014 */  lw        $v0, 0x14($s2)
/* DF1138 80242298 AE220074 */  sw        $v0, 0x74($s1)
/* DF113C 8024229C 8E0200B0 */  lw        $v0, 0xb0($s0)
/* DF1140 802422A0 34420010 */  ori       $v0, $v0, 0x10
/* DF1144 802422A4 AE0200B0 */  sw        $v0, 0xb0($s0)
/* DF1148 802422A8 8FBF0034 */  lw        $ra, 0x34($sp)
/* DF114C 802422AC 8FB20030 */  lw        $s2, 0x30($sp)
/* DF1150 802422B0 8FB1002C */  lw        $s1, 0x2c($sp)
/* DF1154 802422B4 8FB00028 */  lw        $s0, 0x28($sp)
/* DF1158 802422B8 03E00008 */  jr        $ra
/* DF115C 802422BC 27BD0038 */   addiu    $sp, $sp, 0x38
