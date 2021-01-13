.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218480_5EC910
/* 5EC910 80218480 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 5EC914 80218484 F7B60020 */  sdc1      $f22, 0x20($sp)
/* 5EC918 80218488 46006586 */  mov.s     $f22, $f12
/* 5EC91C 8021848C F7B40018 */  sdc1      $f20, 0x18($sp)
/* 5EC920 80218490 AFBF0010 */  sw        $ra, 0x10($sp)
/* 5EC924 80218494 0C00A3FC */  jal       length2D
/* 5EC928 80218498 46007506 */   mov.s    $f20, $f14
/* 5EC92C 8021849C 4600A18D */  trunc.w.s $f6, $f20
/* 5EC930 802184A0 44023000 */  mfc1      $v0, $f6
/* 5EC934 802184A4 00000000 */  nop
/* 5EC938 802184A8 04420001 */  bltzl     $v0, .L802184B0
/* 5EC93C 802184AC 00021023 */   negu     $v0, $v0
.L802184B0:
/* 5EC940 802184B0 44821000 */  mtc1      $v0, $f2
/* 5EC944 802184B4 00000000 */  nop
/* 5EC948 802184B8 468010A0 */  cvt.s.w   $f2, $f2
/* 5EC94C 802184BC 46001103 */  div.s     $f4, $f2, $f0
/* 5EC950 802184C0 0000202D */  daddu     $a0, $zero, $zero
/* 5EC954 802184C4 2406005A */  addiu     $a2, $zero, 0x5a
/* 5EC958 802184C8 0080282D */  daddu     $a1, $a0, $zero
/* 5EC95C 802184CC 3C078022 */  lui       $a3, %hi(D_80224880)
/* 5EC960 802184D0 24E74880 */  addiu     $a3, $a3, %lo(D_80224880)
/* 5EC964 802184D4 30C2FFFF */  andi      $v0, $a2, 0xffff
.L802184D8:
/* 5EC968 802184D8 3083FFFF */  andi      $v1, $a0, 0xffff
/* 5EC96C 802184DC 00431023 */  subu      $v0, $v0, $v1
/* 5EC970 802184E0 00021FC2 */  srl       $v1, $v0, 0x1f
/* 5EC974 802184E4 00431021 */  addu      $v0, $v0, $v1
/* 5EC978 802184E8 00021043 */  sra       $v0, $v0, 1
/* 5EC97C 802184EC 00821821 */  addu      $v1, $a0, $v0
/* 5EC980 802184F0 3062FFFF */  andi      $v0, $v1, 0xffff
/* 5EC984 802184F4 00021080 */  sll       $v0, $v0, 2
/* 5EC988 802184F8 00471021 */  addu      $v0, $v0, $a3
/* 5EC98C 802184FC C4400000 */  lwc1      $f0, ($v0)
/* 5EC990 80218500 4604003C */  c.lt.s    $f0, $f4
/* 5EC994 80218504 00000000 */  nop
/* 5EC998 80218508 45020002 */  bc1fl     .L80218514
/* 5EC99C 8021850C 0060302D */   daddu    $a2, $v1, $zero
/* 5EC9A0 80218510 0060202D */  daddu     $a0, $v1, $zero
.L80218514:
/* 5EC9A4 80218514 24A50001 */  addiu     $a1, $a1, 1
/* 5EC9A8 80218518 30A2FFFF */  andi      $v0, $a1, 0xffff
/* 5EC9AC 8021851C 2C420007 */  sltiu     $v0, $v0, 7
/* 5EC9B0 80218520 1440FFED */  bnez      $v0, .L802184D8
/* 5EC9B4 80218524 30C2FFFF */   andi     $v0, $a2, 0xffff
/* 5EC9B8 80218528 3082FFFF */  andi      $v0, $a0, 0xffff
/* 5EC9BC 8021852C 00021080 */  sll       $v0, $v0, 2
/* 5EC9C0 80218530 30C3FFFF */  andi      $v1, $a2, 0xffff
/* 5EC9C4 80218534 3C018022 */  lui       $at, %hi(D_80224880)
/* 5EC9C8 80218538 00220821 */  addu      $at, $at, $v0
/* 5EC9CC 8021853C C4224880 */  lwc1      $f2, %lo(D_80224880)($at)
/* 5EC9D0 80218540 00031880 */  sll       $v1, $v1, 2
/* 5EC9D4 80218544 46041081 */  sub.s     $f2, $f2, $f4
/* 5EC9D8 80218548 3C018022 */  lui       $at, %hi(D_80224880)
/* 5EC9DC 8021854C 00230821 */  addu      $at, $at, $v1
/* 5EC9E0 80218550 C4204880 */  lwc1      $f0, %lo(D_80224880)($at)
/* 5EC9E4 80218554 46040001 */  sub.s     $f0, $f0, $f4
/* 5EC9E8 80218558 46001085 */  abs.s     $f2, $f2
/* 5EC9EC 8021855C 46000005 */  abs.s     $f0, $f0
/* 5EC9F0 80218560 4600103C */  c.lt.s    $f2, $f0
/* 5EC9F4 80218564 00000000 */  nop
/* 5EC9F8 80218568 45000002 */  bc1f      .L80218574
/* 5EC9FC 8021856C 00C0182D */   daddu    $v1, $a2, $zero
/* 5ECA00 80218570 0080182D */  daddu     $v1, $a0, $zero
.L80218574:
/* 5ECA04 80218574 44800000 */  mtc1      $zero, $f0
/* 5ECA08 80218578 00000000 */  nop
/* 5ECA0C 8021857C 4600B03C */  c.lt.s    $f22, $f0
/* 5ECA10 80218580 00000000 */  nop
/* 5ECA14 80218584 4500000A */  bc1f      .L802185B0
/* 5ECA18 80218588 00000000 */   nop
/* 5ECA1C 8021858C 4614003E */  c.le.s    $f0, $f20
/* 5ECA20 80218590 00000000 */  nop
/* 5ECA24 80218594 45000004 */  bc1f      .L802185A8
/* 5ECA28 80218598 240200B4 */   addiu    $v0, $zero, 0xb4
/* 5ECA2C 8021859C 00431823 */  subu      $v1, $v0, $v1
/* 5ECA30 802185A0 44800000 */  mtc1      $zero, $f0
/* 5ECA34 802185A4 00000000 */  nop
.L802185A8:
/* 5ECA38 802185A8 4600B03C */  c.lt.s    $f22, $f0
/* 5ECA3C 802185AC 00000000 */  nop
.L802185B0:
/* 5ECA40 802185B0 45000005 */  bc1f      .L802185C8
/* 5ECA44 802185B4 00000000 */   nop
/* 5ECA48 802185B8 4600A03C */  c.lt.s    $f20, $f0
/* 5ECA4C 802185BC 00000000 */  nop
/* 5ECA50 802185C0 45030001 */  bc1tl     .L802185C8
/* 5ECA54 802185C4 246300B4 */   addiu    $v1, $v1, 0xb4
.L802185C8:
/* 5ECA58 802185C8 44800000 */  mtc1      $zero, $f0
/* 5ECA5C 802185CC 00000000 */  nop
/* 5ECA60 802185D0 4616003E */  c.le.s    $f0, $f22
/* 5ECA64 802185D4 00000000 */  nop
/* 5ECA68 802185D8 45000006 */  bc1f      .L802185F4
/* 5ECA6C 802185DC 00000000 */   nop
/* 5ECA70 802185E0 4600A03C */  c.lt.s    $f20, $f0
/* 5ECA74 802185E4 00000000 */  nop
/* 5ECA78 802185E8 45000002 */  bc1f      .L802185F4
/* 5ECA7C 802185EC 24020168 */   addiu    $v0, $zero, 0x168
/* 5ECA80 802185F0 00431823 */  subu      $v1, $v0, $v1
.L802185F4:
/* 5ECA84 802185F4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 5ECA88 802185F8 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 5ECA8C 802185FC D7B40018 */  ldc1      $f20, 0x18($sp)
/* 5ECA90 80218600 3062FFFF */  andi      $v0, $v1, 0xffff
/* 5ECA94 80218604 03E00008 */  jr        $ra
/* 5ECA98 80218608 27BD0028 */   addiu    $sp, $sp, 0x28
