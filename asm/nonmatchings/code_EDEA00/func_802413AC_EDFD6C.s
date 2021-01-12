.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413AC_EDFD6C
/* EDFD6C 802413AC 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* EDFD70 802413B0 AFB00028 */  sw        $s0, 0x28($sp)
/* EDFD74 802413B4 00A0802D */  daddu     $s0, $a1, $zero
/* EDFD78 802413B8 AFB1002C */  sw        $s1, 0x2c($sp)
/* EDFD7C 802413BC 00C0882D */  daddu     $s1, $a2, $zero
/* EDFD80 802413C0 AFBF0034 */  sw        $ra, 0x34($sp)
/* EDFD84 802413C4 AFB20030 */  sw        $s2, 0x30($sp)
/* EDFD88 802413C8 AE200070 */  sw        $zero, 0x70($s1)
/* EDFD8C 802413CC 8C830000 */  lw        $v1, ($a0)
/* EDFD90 802413D0 2402FDFF */  addiu     $v0, $zero, -0x201
/* EDFD94 802413D4 A480008E */  sh        $zero, 0x8e($a0)
/* EDFD98 802413D8 00621824 */  and       $v1, $v1, $v0
/* EDFD9C 802413DC 34650800 */  ori       $a1, $v1, 0x800
/* EDFDA0 802413E0 AC850000 */  sw        $a1, ($a0)
/* EDFDA4 802413E4 8E0200D0 */  lw        $v0, 0xd0($s0)
/* EDFDA8 802413E8 8C420034 */  lw        $v0, 0x34($v0)
/* EDFDAC 802413EC 10400003 */  beqz      $v0, .L802413FC
/* EDFDB0 802413F0 00E0902D */   daddu    $s2, $a3, $zero
/* EDFDB4 802413F4 08090501 */  j         .L80241404
/* EDFDB8 802413F8 34620808 */   ori      $v0, $v1, 0x808
.L802413FC:
/* EDFDBC 802413FC 2402FFF7 */  addiu     $v0, $zero, -9
/* EDFDC0 80241400 00A21024 */  and       $v0, $a1, $v0
.L80241404:
/* EDFDC4 80241404 AC820000 */  sw        $v0, ($a0)
/* EDFDC8 80241408 27A20024 */  addiu     $v0, $sp, 0x24
/* EDFDCC 8024140C 27A50018 */  addiu     $a1, $sp, 0x18
/* EDFDD0 80241410 C4800038 */  lwc1      $f0, 0x38($a0)
/* EDFDD4 80241414 C482003C */  lwc1      $f2, 0x3c($a0)
/* EDFDD8 80241418 C4840040 */  lwc1      $f4, 0x40($a0)
/* EDFDDC 8024141C 3C01447A */  lui       $at, 0x447a
/* EDFDE0 80241420 44813000 */  mtc1      $at, $f6
/* EDFDE4 80241424 27A6001C */  addiu     $a2, $sp, 0x1c
/* EDFDE8 80241428 E7A00018 */  swc1      $f0, 0x18($sp)
/* EDFDEC 8024142C E7A2001C */  swc1      $f2, 0x1c($sp)
/* EDFDF0 80241430 E7A40020 */  swc1      $f4, 0x20($sp)
/* EDFDF4 80241434 E7A60024 */  swc1      $f6, 0x24($sp)
/* EDFDF8 80241438 AFA20010 */  sw        $v0, 0x10($sp)
/* EDFDFC 8024143C 8C840080 */  lw        $a0, 0x80($a0)
/* EDFE00 80241440 0C03908F */  jal       func_800E423C
/* EDFE04 80241444 27A70020 */   addiu    $a3, $sp, 0x20
/* EDFE08 80241448 C7A20024 */  lwc1      $f2, 0x24($sp)
/* EDFE0C 8024144C 3C014059 */  lui       $at, 0x4059
/* EDFE10 80241450 44812800 */  mtc1      $at, $f5
/* EDFE14 80241454 44802000 */  mtc1      $zero, $f4
/* EDFE18 80241458 460010A1 */  cvt.d.s   $f2, $f2
/* EDFE1C 8024145C 46241082 */  mul.d     $f2, $f2, $f4
/* EDFE20 80241460 00000000 */  nop
/* EDFE24 80241464 C7A0001C */  lwc1      $f0, 0x1c($sp)
/* EDFE28 80241468 46000021 */  cvt.d.s   $f0, $f0
/* EDFE2C 8024146C 46240002 */  mul.d     $f0, $f0, $f4
/* EDFE30 80241470 00000000 */  nop
/* EDFE34 80241474 3C013FE0 */  lui       $at, 0x3fe0
/* EDFE38 80241478 44812800 */  mtc1      $at, $f5
/* EDFE3C 8024147C 44802000 */  mtc1      $zero, $f4
/* EDFE40 80241480 00000000 */  nop
/* EDFE44 80241484 46241080 */  add.d     $f2, $f2, $f4
/* EDFE48 80241488 AE000074 */  sw        $zero, 0x74($s0)
/* EDFE4C 8024148C 46240000 */  add.d     $f0, $f0, $f4
/* EDFE50 80241490 AE000090 */  sw        $zero, 0x90($s0)
/* EDFE54 80241494 4620120D */  trunc.w.d $f8, $f2
/* EDFE58 80241498 E6080078 */  swc1      $f8, 0x78($s0)
/* EDFE5C 8024149C 4620020D */  trunc.w.d $f8, $f0
/* EDFE60 802414A0 E6080088 */  swc1      $f8, 0x88($s0)
/* EDFE64 802414A4 8E420014 */  lw        $v0, 0x14($s2)
/* EDFE68 802414A8 AE220074 */  sw        $v0, 0x74($s1)
/* EDFE6C 802414AC 8E0200B0 */  lw        $v0, 0xb0($s0)
/* EDFE70 802414B0 34420010 */  ori       $v0, $v0, 0x10
/* EDFE74 802414B4 AE0200B0 */  sw        $v0, 0xb0($s0)
/* EDFE78 802414B8 8FBF0034 */  lw        $ra, 0x34($sp)
/* EDFE7C 802414BC 8FB20030 */  lw        $s2, 0x30($sp)
/* EDFE80 802414C0 8FB1002C */  lw        $s1, 0x2c($sp)
/* EDFE84 802414C4 8FB00028 */  lw        $s0, 0x28($sp)
/* EDFE88 802414C8 03E00008 */  jr        $ra
/* EDFE8C 802414CC 27BD0038 */   addiu    $sp, $sp, 0x38
