.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242038_CD3E68
/* CD3E68 80242038 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* CD3E6C 8024203C AFB00028 */  sw        $s0, 0x28($sp)
/* CD3E70 80242040 00A0802D */  daddu     $s0, $a1, $zero
/* CD3E74 80242044 AFB1002C */  sw        $s1, 0x2c($sp)
/* CD3E78 80242048 00C0882D */  daddu     $s1, $a2, $zero
/* CD3E7C 8024204C AFBF0034 */  sw        $ra, 0x34($sp)
/* CD3E80 80242050 AFB20030 */  sw        $s2, 0x30($sp)
/* CD3E84 80242054 AE200070 */  sw        $zero, 0x70($s1)
/* CD3E88 80242058 8C830000 */  lw        $v1, ($a0)
/* CD3E8C 8024205C 2402FDFF */  addiu     $v0, $zero, -0x201
/* CD3E90 80242060 A480008E */  sh        $zero, 0x8e($a0)
/* CD3E94 80242064 00621824 */  and       $v1, $v1, $v0
/* CD3E98 80242068 34650800 */  ori       $a1, $v1, 0x800
/* CD3E9C 8024206C AC850000 */  sw        $a1, ($a0)
/* CD3EA0 80242070 8E0200D0 */  lw        $v0, 0xd0($s0)
/* CD3EA4 80242074 8C420034 */  lw        $v0, 0x34($v0)
/* CD3EA8 80242078 10400003 */  beqz      $v0, .L80242088
/* CD3EAC 8024207C 00E0902D */   daddu    $s2, $a3, $zero
/* CD3EB0 80242080 08090824 */  j         .L80242090
/* CD3EB4 80242084 34620808 */   ori      $v0, $v1, 0x808
.L80242088:
/* CD3EB8 80242088 2402FFF7 */  addiu     $v0, $zero, -9
/* CD3EBC 8024208C 00A21024 */  and       $v0, $a1, $v0
.L80242090:
/* CD3EC0 80242090 AC820000 */  sw        $v0, ($a0)
/* CD3EC4 80242094 27A20024 */  addiu     $v0, $sp, 0x24
/* CD3EC8 80242098 27A50018 */  addiu     $a1, $sp, 0x18
/* CD3ECC 8024209C C4800038 */  lwc1      $f0, 0x38($a0)
/* CD3ED0 802420A0 C482003C */  lwc1      $f2, 0x3c($a0)
/* CD3ED4 802420A4 C4840040 */  lwc1      $f4, 0x40($a0)
/* CD3ED8 802420A8 3C01447A */  lui       $at, 0x447a
/* CD3EDC 802420AC 44813000 */  mtc1      $at, $f6
/* CD3EE0 802420B0 27A6001C */  addiu     $a2, $sp, 0x1c
/* CD3EE4 802420B4 E7A00018 */  swc1      $f0, 0x18($sp)
/* CD3EE8 802420B8 E7A2001C */  swc1      $f2, 0x1c($sp)
/* CD3EEC 802420BC E7A40020 */  swc1      $f4, 0x20($sp)
/* CD3EF0 802420C0 E7A60024 */  swc1      $f6, 0x24($sp)
/* CD3EF4 802420C4 AFA20010 */  sw        $v0, 0x10($sp)
/* CD3EF8 802420C8 8C840080 */  lw        $a0, 0x80($a0)
/* CD3EFC 802420CC 0C0372DF */  jal       func_800DCB7C
/* CD3F00 802420D0 27A70020 */   addiu    $a3, $sp, 0x20
/* CD3F04 802420D4 C7A20024 */  lwc1      $f2, 0x24($sp)
/* CD3F08 802420D8 3C014059 */  lui       $at, 0x4059
/* CD3F0C 802420DC 44812800 */  mtc1      $at, $f5
/* CD3F10 802420E0 44802000 */  mtc1      $zero, $f4
/* CD3F14 802420E4 460010A1 */  cvt.d.s   $f2, $f2
/* CD3F18 802420E8 46241082 */  mul.d     $f2, $f2, $f4
/* CD3F1C 802420EC 00000000 */  nop
/* CD3F20 802420F0 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* CD3F24 802420F4 46000021 */  cvt.d.s   $f0, $f0
/* CD3F28 802420F8 46240002 */  mul.d     $f0, $f0, $f4
/* CD3F2C 802420FC 00000000 */  nop
/* CD3F30 80242100 3C013FE0 */  lui       $at, 0x3fe0
/* CD3F34 80242104 44812800 */  mtc1      $at, $f5
/* CD3F38 80242108 44802000 */  mtc1      $zero, $f4
/* CD3F3C 8024210C 00000000 */  nop
/* CD3F40 80242110 46241080 */  add.d     $f2, $f2, $f4
/* CD3F44 80242114 AE000074 */  sw        $zero, 0x74($s0)
/* CD3F48 80242118 46240000 */  add.d     $f0, $f0, $f4
/* CD3F4C 8024211C AE000090 */  sw        $zero, 0x90($s0)
/* CD3F50 80242120 4620120D */  trunc.w.d $f8, $f2
/* CD3F54 80242124 E6080078 */  swc1      $f8, 0x78($s0)
/* CD3F58 80242128 4620020D */  trunc.w.d $f8, $f0
/* CD3F5C 8024212C E6080088 */  swc1      $f8, 0x88($s0)
/* CD3F60 80242130 8E420014 */  lw        $v0, 0x14($s2)
/* CD3F64 80242134 AE220074 */  sw        $v0, 0x74($s1)
/* CD3F68 80242138 8E0200B0 */  lw        $v0, 0xb0($s0)
/* CD3F6C 8024213C 34420010 */  ori       $v0, $v0, 0x10
/* CD3F70 80242140 AE0200B0 */  sw        $v0, 0xb0($s0)
/* CD3F74 80242144 8FBF0034 */  lw        $ra, 0x34($sp)
/* CD3F78 80242148 8FB20030 */  lw        $s2, 0x30($sp)
/* CD3F7C 8024214C 8FB1002C */  lw        $s1, 0x2c($sp)
/* CD3F80 80242150 8FB00028 */  lw        $s0, 0x28($sp)
/* CD3F84 80242154 03E00008 */  jr        $ra
/* CD3F88 80242158 27BD0038 */   addiu    $sp, $sp, 0x38
