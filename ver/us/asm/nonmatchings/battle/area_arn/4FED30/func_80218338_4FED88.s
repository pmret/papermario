.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218338_4FED88
/* 4FED88 80218338 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4FED8C 8021833C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 4FED90 80218340 46006586 */  mov.s     $f22, $f12
/* 4FED94 80218344 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 4FED98 80218348 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4FED9C 8021834C 0C00A3FC */  jal       length2D
/* 4FEDA0 80218350 46007506 */   mov.s    $f20, $f14
/* 4FEDA4 80218354 4600A18D */  trunc.w.s $f6, $f20
/* 4FEDA8 80218358 44023000 */  mfc1      $v0, $f6
/* 4FEDAC 8021835C 00000000 */  nop
/* 4FEDB0 80218360 04420001 */  bltzl     $v0, .L80218368
/* 4FEDB4 80218364 00021023 */   negu     $v0, $v0
.L80218368:
/* 4FEDB8 80218368 44821000 */  mtc1      $v0, $f2
/* 4FEDBC 8021836C 00000000 */  nop
/* 4FEDC0 80218370 468010A0 */  cvt.s.w   $f2, $f2
/* 4FEDC4 80218374 46001103 */  div.s     $f4, $f2, $f0
/* 4FEDC8 80218378 0000202D */  daddu     $a0, $zero, $zero
/* 4FEDCC 8021837C 2406005A */  addiu     $a2, $zero, 0x5a
/* 4FEDD0 80218380 0080282D */  daddu     $a1, $a0, $zero
/* 4FEDD4 80218384 3C078022 */  lui       $a3, %hi(D_8021FD00_506750)
/* 4FEDD8 80218388 24E7FD00 */  addiu     $a3, $a3, %lo(D_8021FD00_506750)
/* 4FEDDC 8021838C 30C2FFFF */  andi      $v0, $a2, 0xffff
.L80218390:
/* 4FEDE0 80218390 3083FFFF */  andi      $v1, $a0, 0xffff
/* 4FEDE4 80218394 00431023 */  subu      $v0, $v0, $v1
/* 4FEDE8 80218398 00021FC2 */  srl       $v1, $v0, 0x1f
/* 4FEDEC 8021839C 00431021 */  addu      $v0, $v0, $v1
/* 4FEDF0 802183A0 00021043 */  sra       $v0, $v0, 1
/* 4FEDF4 802183A4 00821821 */  addu      $v1, $a0, $v0
/* 4FEDF8 802183A8 3062FFFF */  andi      $v0, $v1, 0xffff
/* 4FEDFC 802183AC 00021080 */  sll       $v0, $v0, 2
/* 4FEE00 802183B0 00471021 */  addu      $v0, $v0, $a3
/* 4FEE04 802183B4 C4400000 */  lwc1      $f0, ($v0)
/* 4FEE08 802183B8 4604003C */  c.lt.s    $f0, $f4
/* 4FEE0C 802183BC 00000000 */  nop
/* 4FEE10 802183C0 45020002 */  bc1fl     .L802183CC
/* 4FEE14 802183C4 0060302D */   daddu    $a2, $v1, $zero
/* 4FEE18 802183C8 0060202D */  daddu     $a0, $v1, $zero
.L802183CC:
/* 4FEE1C 802183CC 24A50001 */  addiu     $a1, $a1, 1
/* 4FEE20 802183D0 30A2FFFF */  andi      $v0, $a1, 0xffff
/* 4FEE24 802183D4 2C420007 */  sltiu     $v0, $v0, 7
/* 4FEE28 802183D8 1440FFED */  bnez      $v0, .L80218390
/* 4FEE2C 802183DC 30C2FFFF */   andi     $v0, $a2, 0xffff
/* 4FEE30 802183E0 3082FFFF */  andi      $v0, $a0, 0xffff
/* 4FEE34 802183E4 00021080 */  sll       $v0, $v0, 2
/* 4FEE38 802183E8 30C3FFFF */  andi      $v1, $a2, 0xffff
/* 4FEE3C 802183EC 3C018022 */  lui       $at, %hi(D_8021FD00_506750)
/* 4FEE40 802183F0 00220821 */  addu      $at, $at, $v0
/* 4FEE44 802183F4 C422FD00 */  lwc1      $f2, %lo(D_8021FD00_506750)($at)
/* 4FEE48 802183F8 00031880 */  sll       $v1, $v1, 2
/* 4FEE4C 802183FC 46041081 */  sub.s     $f2, $f2, $f4
/* 4FEE50 80218400 3C018022 */  lui       $at, %hi(D_8021FD00_506750)
/* 4FEE54 80218404 00230821 */  addu      $at, $at, $v1
/* 4FEE58 80218408 C420FD00 */  lwc1      $f0, %lo(D_8021FD00_506750)($at)
/* 4FEE5C 8021840C 46040001 */  sub.s     $f0, $f0, $f4
/* 4FEE60 80218410 46001085 */  abs.s     $f2, $f2
/* 4FEE64 80218414 46000005 */  abs.s     $f0, $f0
/* 4FEE68 80218418 4600103C */  c.lt.s    $f2, $f0
/* 4FEE6C 8021841C 00000000 */  nop
/* 4FEE70 80218420 45000002 */  bc1f      .L8021842C
/* 4FEE74 80218424 00C0182D */   daddu    $v1, $a2, $zero
/* 4FEE78 80218428 0080182D */  daddu     $v1, $a0, $zero
.L8021842C:
/* 4FEE7C 8021842C 44800000 */  mtc1      $zero, $f0
/* 4FEE80 80218430 00000000 */  nop
/* 4FEE84 80218434 4600B03C */  c.lt.s    $f22, $f0
/* 4FEE88 80218438 00000000 */  nop
/* 4FEE8C 8021843C 4500000A */  bc1f      .L80218468
/* 4FEE90 80218440 00000000 */   nop
/* 4FEE94 80218444 4614003E */  c.le.s    $f0, $f20
/* 4FEE98 80218448 00000000 */  nop
/* 4FEE9C 8021844C 45000004 */  bc1f      .L80218460
/* 4FEEA0 80218450 240200B4 */   addiu    $v0, $zero, 0xb4
/* 4FEEA4 80218454 00431823 */  subu      $v1, $v0, $v1
/* 4FEEA8 80218458 44800000 */  mtc1      $zero, $f0
/* 4FEEAC 8021845C 00000000 */  nop
.L80218460:
/* 4FEEB0 80218460 4600B03C */  c.lt.s    $f22, $f0
/* 4FEEB4 80218464 00000000 */  nop
.L80218468:
/* 4FEEB8 80218468 45000005 */  bc1f      .L80218480
/* 4FEEBC 8021846C 00000000 */   nop
/* 4FEEC0 80218470 4600A03C */  c.lt.s    $f20, $f0
/* 4FEEC4 80218474 00000000 */  nop
/* 4FEEC8 80218478 45030001 */  bc1tl     .L80218480
/* 4FEECC 8021847C 246300B4 */   addiu    $v1, $v1, 0xb4
.L80218480:
/* 4FEED0 80218480 44800000 */  mtc1      $zero, $f0
/* 4FEED4 80218484 00000000 */  nop
/* 4FEED8 80218488 4616003E */  c.le.s    $f0, $f22
/* 4FEEDC 8021848C 00000000 */  nop
/* 4FEEE0 80218490 45000006 */  bc1f      .L802184AC
/* 4FEEE4 80218494 00000000 */   nop
/* 4FEEE8 80218498 4600A03C */  c.lt.s    $f20, $f0
/* 4FEEEC 8021849C 00000000 */  nop
/* 4FEEF0 802184A0 45000002 */  bc1f      .L802184AC
/* 4FEEF4 802184A4 24020168 */   addiu    $v0, $zero, 0x168
/* 4FEEF8 802184A8 00431823 */  subu      $v1, $v0, $v1
.L802184AC:
/* 4FEEFC 802184AC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4FEF00 802184B0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 4FEF04 802184B4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 4FEF08 802184B8 3062FFFF */  andi      $v0, $v1, 0xffff
/* 4FEF0C 802184BC 03E00008 */  jr        $ra
/* 4FEF10 802184C0 27BD0028 */   addiu    $sp, $sp, 0x28
