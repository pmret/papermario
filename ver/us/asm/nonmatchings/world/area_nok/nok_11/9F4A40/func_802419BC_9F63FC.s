.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nok_11_UnkFunc5
/* 9F63FC 802419BC 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 9F6400 802419C0 AFB00028 */  sw        $s0, 0x28($sp)
/* 9F6404 802419C4 00A0802D */  daddu     $s0, $a1, $zero
/* 9F6408 802419C8 AFB1002C */  sw        $s1, 0x2c($sp)
/* 9F640C 802419CC 00C0882D */  daddu     $s1, $a2, $zero
/* 9F6410 802419D0 AFBF0034 */  sw        $ra, 0x34($sp)
/* 9F6414 802419D4 AFB20030 */  sw        $s2, 0x30($sp)
/* 9F6418 802419D8 AE200070 */  sw        $zero, 0x70($s1)
/* 9F641C 802419DC 8C830000 */  lw        $v1, ($a0)
/* 9F6420 802419E0 2402FDFF */  addiu     $v0, $zero, -0x201
/* 9F6424 802419E4 A480008E */  sh        $zero, 0x8e($a0)
/* 9F6428 802419E8 00621824 */  and       $v1, $v1, $v0
/* 9F642C 802419EC 34650800 */  ori       $a1, $v1, 0x800
/* 9F6430 802419F0 AC850000 */  sw        $a1, ($a0)
/* 9F6434 802419F4 8E0200D0 */  lw        $v0, 0xd0($s0)
/* 9F6438 802419F8 8C420034 */  lw        $v0, 0x34($v0)
/* 9F643C 802419FC 10400003 */  beqz      $v0, .L80241A0C
/* 9F6440 80241A00 00E0902D */   daddu    $s2, $a3, $zero
/* 9F6444 80241A04 08090685 */  j         .L80241A14
/* 9F6448 80241A08 34620808 */   ori      $v0, $v1, 0x808
.L80241A0C:
/* 9F644C 80241A0C 2402FFF7 */  addiu     $v0, $zero, -9
/* 9F6450 80241A10 00A21024 */  and       $v0, $a1, $v0
.L80241A14:
/* 9F6454 80241A14 AC820000 */  sw        $v0, ($a0)
/* 9F6458 80241A18 27A20024 */  addiu     $v0, $sp, 0x24
/* 9F645C 80241A1C 27A50018 */  addiu     $a1, $sp, 0x18
/* 9F6460 80241A20 C4800038 */  lwc1      $f0, 0x38($a0)
/* 9F6464 80241A24 C482003C */  lwc1      $f2, 0x3c($a0)
/* 9F6468 80241A28 C4840040 */  lwc1      $f4, 0x40($a0)
/* 9F646C 80241A2C 3C01447A */  lui       $at, 0x447a
/* 9F6470 80241A30 44813000 */  mtc1      $at, $f6
/* 9F6474 80241A34 27A6001C */  addiu     $a2, $sp, 0x1c
/* 9F6478 80241A38 E7A00018 */  swc1      $f0, 0x18($sp)
/* 9F647C 80241A3C E7A2001C */  swc1      $f2, 0x1c($sp)
/* 9F6480 80241A40 E7A40020 */  swc1      $f4, 0x20($sp)
/* 9F6484 80241A44 E7A60024 */  swc1      $f6, 0x24($sp)
/* 9F6488 80241A48 AFA20010 */  sw        $v0, 0x10($sp)
/* 9F648C 80241A4C 8C840080 */  lw        $a0, 0x80($a0)
/* 9F6490 80241A50 0C0372DF */  jal       func_800DCB7C
/* 9F6494 80241A54 27A70020 */   addiu    $a3, $sp, 0x20
/* 9F6498 80241A58 C7A20024 */  lwc1      $f2, 0x24($sp)
/* 9F649C 80241A5C 3C014059 */  lui       $at, 0x4059
/* 9F64A0 80241A60 44812800 */  mtc1      $at, $f5
/* 9F64A4 80241A64 44802000 */  mtc1      $zero, $f4
/* 9F64A8 80241A68 460010A1 */  cvt.d.s   $f2, $f2
/* 9F64AC 80241A6C 46241082 */  mul.d     $f2, $f2, $f4
/* 9F64B0 80241A70 00000000 */  nop
/* 9F64B4 80241A74 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* 9F64B8 80241A78 46000021 */  cvt.d.s   $f0, $f0
/* 9F64BC 80241A7C 46240002 */  mul.d     $f0, $f0, $f4
/* 9F64C0 80241A80 00000000 */  nop
/* 9F64C4 80241A84 3C013FE0 */  lui       $at, 0x3fe0
/* 9F64C8 80241A88 44812800 */  mtc1      $at, $f5
/* 9F64CC 80241A8C 44802000 */  mtc1      $zero, $f4
/* 9F64D0 80241A90 00000000 */  nop
/* 9F64D4 80241A94 46241080 */  add.d     $f2, $f2, $f4
/* 9F64D8 80241A98 AE000074 */  sw        $zero, 0x74($s0)
/* 9F64DC 80241A9C 46240000 */  add.d     $f0, $f0, $f4
/* 9F64E0 80241AA0 AE000090 */  sw        $zero, 0x90($s0)
/* 9F64E4 80241AA4 4620120D */  trunc.w.d $f8, $f2
/* 9F64E8 80241AA8 E6080078 */  swc1      $f8, 0x78($s0)
/* 9F64EC 80241AAC 4620020D */  trunc.w.d $f8, $f0
/* 9F64F0 80241AB0 E6080088 */  swc1      $f8, 0x88($s0)
/* 9F64F4 80241AB4 8E420014 */  lw        $v0, 0x14($s2)
/* 9F64F8 80241AB8 AE220074 */  sw        $v0, 0x74($s1)
/* 9F64FC 80241ABC 8E0200B0 */  lw        $v0, 0xb0($s0)
/* 9F6500 80241AC0 34420010 */  ori       $v0, $v0, 0x10
/* 9F6504 80241AC4 AE0200B0 */  sw        $v0, 0xb0($s0)
/* 9F6508 80241AC8 8FBF0034 */  lw        $ra, 0x34($sp)
/* 9F650C 80241ACC 8FB20030 */  lw        $s2, 0x30($sp)
/* 9F6510 80241AD0 8FB1002C */  lw        $s1, 0x2c($sp)
/* 9F6514 80241AD4 8FB00028 */  lw        $s0, 0x28($sp)
/* 9F6518 80241AD8 03E00008 */  jr        $ra
/* 9F651C 80241ADC 27BD0038 */   addiu    $sp, $sp, 0x38
