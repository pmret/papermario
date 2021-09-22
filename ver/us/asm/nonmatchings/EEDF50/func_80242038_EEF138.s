.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242038_EEF138
/* EEF138 80242038 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* EEF13C 8024203C AFB00028 */  sw        $s0, 0x28($sp)
/* EEF140 80242040 00A0802D */  daddu     $s0, $a1, $zero
/* EEF144 80242044 AFB1002C */  sw        $s1, 0x2c($sp)
/* EEF148 80242048 00C0882D */  daddu     $s1, $a2, $zero
/* EEF14C 8024204C AFBF0034 */  sw        $ra, 0x34($sp)
/* EEF150 80242050 AFB20030 */  sw        $s2, 0x30($sp)
/* EEF154 80242054 AE200070 */  sw        $zero, 0x70($s1)
/* EEF158 80242058 8C830000 */  lw        $v1, ($a0)
/* EEF15C 8024205C 2402FDFF */  addiu     $v0, $zero, -0x201
/* EEF160 80242060 A480008E */  sh        $zero, 0x8e($a0)
/* EEF164 80242064 00621824 */  and       $v1, $v1, $v0
/* EEF168 80242068 34650800 */  ori       $a1, $v1, 0x800
/* EEF16C 8024206C AC850000 */  sw        $a1, ($a0)
/* EEF170 80242070 8E0200D0 */  lw        $v0, 0xd0($s0)
/* EEF174 80242074 8C420034 */  lw        $v0, 0x34($v0)
/* EEF178 80242078 10400003 */  beqz      $v0, .L80242088
/* EEF17C 8024207C 00E0902D */   daddu    $s2, $a3, $zero
/* EEF180 80242080 08090824 */  j         .L80242090
/* EEF184 80242084 34620808 */   ori      $v0, $v1, 0x808
.L80242088:
/* EEF188 80242088 2402FFF7 */  addiu     $v0, $zero, -9
/* EEF18C 8024208C 00A21024 */  and       $v0, $a1, $v0
.L80242090:
/* EEF190 80242090 AC820000 */  sw        $v0, ($a0)
/* EEF194 80242094 27A20024 */  addiu     $v0, $sp, 0x24
/* EEF198 80242098 27A50018 */  addiu     $a1, $sp, 0x18
/* EEF19C 8024209C C4800038 */  lwc1      $f0, 0x38($a0)
/* EEF1A0 802420A0 C482003C */  lwc1      $f2, 0x3c($a0)
/* EEF1A4 802420A4 C4840040 */  lwc1      $f4, 0x40($a0)
/* EEF1A8 802420A8 3C01447A */  lui       $at, 0x447a
/* EEF1AC 802420AC 44813000 */  mtc1      $at, $f6
/* EEF1B0 802420B0 27A6001C */  addiu     $a2, $sp, 0x1c
/* EEF1B4 802420B4 E7A00018 */  swc1      $f0, 0x18($sp)
/* EEF1B8 802420B8 E7A2001C */  swc1      $f2, 0x1c($sp)
/* EEF1BC 802420BC E7A40020 */  swc1      $f4, 0x20($sp)
/* EEF1C0 802420C0 E7A60024 */  swc1      $f6, 0x24($sp)
/* EEF1C4 802420C4 AFA20010 */  sw        $v0, 0x10($sp)
/* EEF1C8 802420C8 8C840080 */  lw        $a0, 0x80($a0)
/* EEF1CC 802420CC 0C03908F */  jal       dead_npc_raycast_down_sides
/* EEF1D0 802420D0 27A70020 */   addiu    $a3, $sp, 0x20
/* EEF1D4 802420D4 C7A20024 */  lwc1      $f2, 0x24($sp)
/* EEF1D8 802420D8 3C014059 */  lui       $at, 0x4059
/* EEF1DC 802420DC 44812800 */  mtc1      $at, $f5
/* EEF1E0 802420E0 44802000 */  mtc1      $zero, $f4
/* EEF1E4 802420E4 460010A1 */  cvt.d.s   $f2, $f2
/* EEF1E8 802420E8 46241082 */  mul.d     $f2, $f2, $f4
/* EEF1EC 802420EC 00000000 */  nop
/* EEF1F0 802420F0 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* EEF1F4 802420F4 46000021 */  cvt.d.s   $f0, $f0
/* EEF1F8 802420F8 46240002 */  mul.d     $f0, $f0, $f4
/* EEF1FC 802420FC 00000000 */  nop
/* EEF200 80242100 3C013FE0 */  lui       $at, 0x3fe0
/* EEF204 80242104 44812800 */  mtc1      $at, $f5
/* EEF208 80242108 44802000 */  mtc1      $zero, $f4
/* EEF20C 8024210C 00000000 */  nop
/* EEF210 80242110 46241080 */  add.d     $f2, $f2, $f4
/* EEF214 80242114 AE000074 */  sw        $zero, 0x74($s0)
/* EEF218 80242118 46240000 */  add.d     $f0, $f0, $f4
/* EEF21C 8024211C AE000090 */  sw        $zero, 0x90($s0)
/* EEF220 80242120 4620120D */  trunc.w.d $f8, $f2
/* EEF224 80242124 E6080078 */  swc1      $f8, 0x78($s0)
/* EEF228 80242128 4620020D */  trunc.w.d $f8, $f0
/* EEF22C 8024212C E6080088 */  swc1      $f8, 0x88($s0)
/* EEF230 80242130 8E420014 */  lw        $v0, 0x14($s2)
/* EEF234 80242134 AE220074 */  sw        $v0, 0x74($s1)
/* EEF238 80242138 8E0200B0 */  lw        $v0, 0xb0($s0)
/* EEF23C 8024213C 34420010 */  ori       $v0, $v0, 0x10
/* EEF240 80242140 AE0200B0 */  sw        $v0, 0xb0($s0)
/* EEF244 80242144 8FBF0034 */  lw        $ra, 0x34($sp)
/* EEF248 80242148 8FB20030 */  lw        $s2, 0x30($sp)
/* EEF24C 8024214C 8FB1002C */  lw        $s1, 0x2c($sp)
/* EEF250 80242150 8FB00028 */  lw        $s0, 0x28($sp)
/* EEF254 80242154 03E00008 */  jr        $ra
/* EEF258 80242158 27BD0038 */   addiu    $sp, $sp, 0x38
