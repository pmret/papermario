.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218500_439F90
/* 439F90 80218500 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 439F94 80218504 F7B60020 */  sdc1      $f22, 0x20($sp)
/* 439F98 80218508 46006586 */  mov.s     $f22, $f12
/* 439F9C 8021850C F7B40018 */  sdc1      $f20, 0x18($sp)
/* 439FA0 80218510 AFBF0010 */  sw        $ra, 0x10($sp)
/* 439FA4 80218514 0C00A3FC */  jal       length2D
/* 439FA8 80218518 46007506 */   mov.s    $f20, $f14
/* 439FAC 8021851C 4600A18D */  trunc.w.s $f6, $f20
/* 439FB0 80218520 44023000 */  mfc1      $v0, $f6
/* 439FB4 80218524 00000000 */  nop
/* 439FB8 80218528 04420001 */  bltzl     $v0, .L80218530
/* 439FBC 8021852C 00021023 */   negu     $v0, $v0
.L80218530:
/* 439FC0 80218530 44821000 */  mtc1      $v0, $f2
/* 439FC4 80218534 00000000 */  nop
/* 439FC8 80218538 468010A0 */  cvt.s.w   $f2, $f2
/* 439FCC 8021853C 46001103 */  div.s     $f4, $f2, $f0
/* 439FD0 80218540 0000202D */  daddu     $a0, $zero, $zero
/* 439FD4 80218544 2406005A */  addiu     $a2, $zero, 0x5a
/* 439FD8 80218548 0080282D */  daddu     $a1, $a0, $zero
/* 439FDC 8021854C 3C078022 */  lui       $a3, %hi(D_8021DF84)
/* 439FE0 80218550 24E7DF84 */  addiu     $a3, $a3, %lo(D_8021DF84)
/* 439FE4 80218554 30C2FFFF */  andi      $v0, $a2, 0xffff
.L80218558:
/* 439FE8 80218558 3083FFFF */  andi      $v1, $a0, 0xffff
/* 439FEC 8021855C 00431023 */  subu      $v0, $v0, $v1
/* 439FF0 80218560 00021FC2 */  srl       $v1, $v0, 0x1f
/* 439FF4 80218564 00431021 */  addu      $v0, $v0, $v1
/* 439FF8 80218568 00021043 */  sra       $v0, $v0, 1
/* 439FFC 8021856C 00821821 */  addu      $v1, $a0, $v0
/* 43A000 80218570 3062FFFF */  andi      $v0, $v1, 0xffff
/* 43A004 80218574 00021080 */  sll       $v0, $v0, 2
/* 43A008 80218578 00471021 */  addu      $v0, $v0, $a3
/* 43A00C 8021857C C4400000 */  lwc1      $f0, ($v0)
/* 43A010 80218580 4604003C */  c.lt.s    $f0, $f4
/* 43A014 80218584 00000000 */  nop
/* 43A018 80218588 45020002 */  bc1fl     .L80218594
/* 43A01C 8021858C 0060302D */   daddu    $a2, $v1, $zero
/* 43A020 80218590 0060202D */  daddu     $a0, $v1, $zero
.L80218594:
/* 43A024 80218594 24A50001 */  addiu     $a1, $a1, 1
/* 43A028 80218598 30A2FFFF */  andi      $v0, $a1, 0xffff
/* 43A02C 8021859C 2C420007 */  sltiu     $v0, $v0, 7
/* 43A030 802185A0 1440FFED */  bnez      $v0, .L80218558
/* 43A034 802185A4 30C2FFFF */   andi     $v0, $a2, 0xffff
/* 43A038 802185A8 3082FFFF */  andi      $v0, $a0, 0xffff
/* 43A03C 802185AC 00021080 */  sll       $v0, $v0, 2
/* 43A040 802185B0 30C3FFFF */  andi      $v1, $a2, 0xffff
/* 43A044 802185B4 3C018022 */  lui       $at, %hi(D_8021DF84)
/* 43A048 802185B8 00220821 */  addu      $at, $at, $v0
/* 43A04C 802185BC C422DF84 */  lwc1      $f2, %lo(D_8021DF84)($at)
/* 43A050 802185C0 00031880 */  sll       $v1, $v1, 2
/* 43A054 802185C4 46041081 */  sub.s     $f2, $f2, $f4
/* 43A058 802185C8 3C018022 */  lui       $at, %hi(D_8021DF84)
/* 43A05C 802185CC 00230821 */  addu      $at, $at, $v1
/* 43A060 802185D0 C420DF84 */  lwc1      $f0, %lo(D_8021DF84)($at)
/* 43A064 802185D4 46040001 */  sub.s     $f0, $f0, $f4
/* 43A068 802185D8 46001085 */  abs.s     $f2, $f2
/* 43A06C 802185DC 46000005 */  abs.s     $f0, $f0
/* 43A070 802185E0 4600103C */  c.lt.s    $f2, $f0
/* 43A074 802185E4 00000000 */  nop
/* 43A078 802185E8 45000002 */  bc1f      .L802185F4
/* 43A07C 802185EC 00C0182D */   daddu    $v1, $a2, $zero
/* 43A080 802185F0 0080182D */  daddu     $v1, $a0, $zero
.L802185F4:
/* 43A084 802185F4 44800000 */  mtc1      $zero, $f0
/* 43A088 802185F8 00000000 */  nop
/* 43A08C 802185FC 4600B03C */  c.lt.s    $f22, $f0
/* 43A090 80218600 00000000 */  nop
/* 43A094 80218604 4500000A */  bc1f      .L80218630
/* 43A098 80218608 00000000 */   nop
/* 43A09C 8021860C 4614003E */  c.le.s    $f0, $f20
/* 43A0A0 80218610 00000000 */  nop
/* 43A0A4 80218614 45000004 */  bc1f      .L80218628
/* 43A0A8 80218618 240200B4 */   addiu    $v0, $zero, 0xb4
/* 43A0AC 8021861C 00431823 */  subu      $v1, $v0, $v1
/* 43A0B0 80218620 44800000 */  mtc1      $zero, $f0
/* 43A0B4 80218624 00000000 */  nop
.L80218628:
/* 43A0B8 80218628 4600B03C */  c.lt.s    $f22, $f0
/* 43A0BC 8021862C 00000000 */  nop
.L80218630:
/* 43A0C0 80218630 45000005 */  bc1f      .L80218648
/* 43A0C4 80218634 00000000 */   nop
/* 43A0C8 80218638 4600A03C */  c.lt.s    $f20, $f0
/* 43A0CC 8021863C 00000000 */  nop
/* 43A0D0 80218640 45030001 */  bc1tl     .L80218648
/* 43A0D4 80218644 246300B4 */   addiu    $v1, $v1, 0xb4
.L80218648:
/* 43A0D8 80218648 44800000 */  mtc1      $zero, $f0
/* 43A0DC 8021864C 00000000 */  nop
/* 43A0E0 80218650 4616003E */  c.le.s    $f0, $f22
/* 43A0E4 80218654 00000000 */  nop
/* 43A0E8 80218658 45000006 */  bc1f      .L80218674
/* 43A0EC 8021865C 00000000 */   nop
/* 43A0F0 80218660 4600A03C */  c.lt.s    $f20, $f0
/* 43A0F4 80218664 00000000 */  nop
/* 43A0F8 80218668 45000002 */  bc1f      .L80218674
/* 43A0FC 8021866C 24020168 */   addiu    $v0, $zero, 0x168
/* 43A100 80218670 00431823 */  subu      $v1, $v0, $v1
.L80218674:
/* 43A104 80218674 8FBF0010 */  lw        $ra, 0x10($sp)
/* 43A108 80218678 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 43A10C 8021867C D7B40018 */  ldc1      $f20, 0x18($sp)
/* 43A110 80218680 3062FFFF */  andi      $v0, $v1, 0xffff
/* 43A114 80218684 03E00008 */  jr        $ra
/* 43A118 80218688 27BD0028 */   addiu    $sp, $sp, 0x28
