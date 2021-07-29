.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80242000_C80180
.double 35.0

glabel D_80242008_C80188
.double 2.3

.section .text

glabel func_802404EC_C7E66C
/* C7E66C 802404EC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C7E670 802404F0 AFB00010 */  sw        $s0, 0x10($sp)
/* C7E674 802404F4 0080802D */  daddu     $s0, $a0, $zero
/* C7E678 802404F8 AFBF0014 */  sw        $ra, 0x14($sp)
/* C7E67C 802404FC F7B40018 */  sdc1      $f20, 0x18($sp)
/* C7E680 80240500 C60C0090 */  lwc1      $f12, 0x90($s0)
/* C7E684 80240504 46806320 */  cvt.s.w   $f12, $f12
/* C7E688 80240508 3C018024 */  lui       $at, %hi(D_80242000_C80180)
/* C7E68C 8024050C D4342000 */  ldc1      $f20, %lo(D_80242000_C80180)($at)
/* C7E690 80240510 46006307 */  neg.s     $f12, $f12
/* C7E694 80240514 46006321 */  cvt.d.s   $f12, $f12
/* C7E698 80240518 46346301 */  sub.d     $f12, $f12, $f20
/* C7E69C 8024051C 0C00A8D4 */  jal       cos_deg
/* C7E6A0 80240520 46206320 */   cvt.s.d  $f12, $f12
/* C7E6A4 80240524 3C014008 */  lui       $at, 0x4008
/* C7E6A8 80240528 44811800 */  mtc1      $at, $f3
/* C7E6AC 8024052C 44801000 */  mtc1      $zero, $f2
/* C7E6B0 80240530 46000021 */  cvt.d.s   $f0, $f0
/* C7E6B4 80240534 46220002 */  mul.d     $f0, $f0, $f2
/* C7E6B8 80240538 00000000 */  nop
/* C7E6BC 8024053C C60C0090 */  lwc1      $f12, 0x90($s0)
/* C7E6C0 80240540 46806320 */  cvt.s.w   $f12, $f12
/* C7E6C4 80240544 46006307 */  neg.s     $f12, $f12
/* C7E6C8 80240548 46006321 */  cvt.d.s   $f12, $f12
/* C7E6CC 8024054C 46346301 */  sub.d     $f12, $f12, $f20
/* C7E6D0 80240550 3C018024 */  lui       $at, %hi(D_80242008_C80188)
/* C7E6D4 80240554 D4222008 */  ldc1      $f2, %lo(D_80242008_C80188)($at)
/* C7E6D8 80240558 46220001 */  sub.d     $f0, $f0, $f2
/* C7E6DC 8024055C 4620010D */  trunc.w.d $f4, $f0
/* C7E6E0 80240560 E6040098 */  swc1      $f4, 0x98($s0)
/* C7E6E4 80240564 0C00A8BB */  jal       sin_deg
/* C7E6E8 80240568 46206320 */   cvt.s.d  $f12, $f12
/* C7E6EC 8024056C 3C014014 */  lui       $at, 0x4014
/* C7E6F0 80240570 44811800 */  mtc1      $at, $f3
/* C7E6F4 80240574 44801000 */  mtc1      $zero, $f2
/* C7E6F8 80240578 46000021 */  cvt.d.s   $f0, $f0
/* C7E6FC 8024057C 46220002 */  mul.d     $f0, $f0, $f2
/* C7E700 80240580 00000000 */  nop
/* C7E704 80240584 4620010D */  trunc.w.d $f4, $f0
/* C7E708 80240588 E604009C */  swc1      $f4, 0x9c($s0)
/* C7E70C 8024058C 8FBF0014 */  lw        $ra, 0x14($sp)
/* C7E710 80240590 8FB00010 */  lw        $s0, 0x10($sp)
/* C7E714 80240594 D7B40018 */  ldc1      $f20, 0x18($sp)
/* C7E718 80240598 24020002 */  addiu     $v0, $zero, 2
/* C7E71C 8024059C 03E00008 */  jr        $ra
/* C7E720 802405A0 27BD0020 */   addiu    $sp, $sp, 0x20
