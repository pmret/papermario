.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218200_5EC690
/* 5EC690 80218200 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 5EC694 80218204 F7B60020 */  sdc1      $f22, 0x20($sp)
/* 5EC698 80218208 46006586 */  mov.s     $f22, $f12
/* 5EC69C 8021820C F7B40018 */  sdc1      $f20, 0x18($sp)
/* 5EC6A0 80218210 AFBF0010 */  sw        $ra, 0x10($sp)
/* 5EC6A4 80218214 0C00A3FC */  jal       length2D
/* 5EC6A8 80218218 46007506 */   mov.s    $f20, $f14
/* 5EC6AC 8021821C 4600A18D */  trunc.w.s $f6, $f20
/* 5EC6B0 80218220 44023000 */  mfc1      $v0, $f6
/* 5EC6B4 80218224 00000000 */  nop
/* 5EC6B8 80218228 04420001 */  bltzl     $v0, .L80218230
/* 5EC6BC 8021822C 00021023 */   negu     $v0, $v0
.L80218230:
/* 5EC6C0 80218230 44821000 */  mtc1      $v0, $f2
/* 5EC6C4 80218234 00000000 */  nop
/* 5EC6C8 80218238 468010A0 */  cvt.s.w   $f2, $f2
/* 5EC6CC 8021823C 46001103 */  div.s     $f4, $f2, $f0
/* 5EC6D0 80218240 0000202D */  daddu     $a0, $zero, $zero
/* 5EC6D4 80218244 2406005A */  addiu     $a2, $zero, 0x5a
/* 5EC6D8 80218248 0080282D */  daddu     $a1, $a0, $zero
/* 5EC6DC 8021824C 3C078022 */  lui       $a3, %hi(b_area_tik_floatTable)
/* 5EC6E0 80218250 24E72DA4 */  addiu     $a3, $a3, %lo(b_area_tik_floatTable)
/* 5EC6E4 80218254 30C2FFFF */  andi      $v0, $a2, 0xffff
.L80218258:
/* 5EC6E8 80218258 3083FFFF */  andi      $v1, $a0, 0xffff
/* 5EC6EC 8021825C 00431023 */  subu      $v0, $v0, $v1
/* 5EC6F0 80218260 00021FC2 */  srl       $v1, $v0, 0x1f
/* 5EC6F4 80218264 00431021 */  addu      $v0, $v0, $v1
/* 5EC6F8 80218268 00021043 */  sra       $v0, $v0, 1
/* 5EC6FC 8021826C 00821821 */  addu      $v1, $a0, $v0
/* 5EC700 80218270 3062FFFF */  andi      $v0, $v1, 0xffff
/* 5EC704 80218274 00021080 */  sll       $v0, $v0, 2
/* 5EC708 80218278 00471021 */  addu      $v0, $v0, $a3
/* 5EC70C 8021827C C4400000 */  lwc1      $f0, ($v0)
/* 5EC710 80218280 4604003C */  c.lt.s    $f0, $f4
/* 5EC714 80218284 00000000 */  nop
/* 5EC718 80218288 45020002 */  bc1fl     .L80218294
/* 5EC71C 8021828C 0060302D */   daddu    $a2, $v1, $zero
/* 5EC720 80218290 0060202D */  daddu     $a0, $v1, $zero
.L80218294:
/* 5EC724 80218294 24A50001 */  addiu     $a1, $a1, 1
/* 5EC728 80218298 30A2FFFF */  andi      $v0, $a1, 0xffff
/* 5EC72C 8021829C 2C420007 */  sltiu     $v0, $v0, 7
/* 5EC730 802182A0 1440FFED */  bnez      $v0, .L80218258
/* 5EC734 802182A4 30C2FFFF */   andi     $v0, $a2, 0xffff
/* 5EC738 802182A8 3082FFFF */  andi      $v0, $a0, 0xffff
/* 5EC73C 802182AC 00021080 */  sll       $v0, $v0, 2
/* 5EC740 802182B0 30C3FFFF */  andi      $v1, $a2, 0xffff
/* 5EC744 802182B4 3C018022 */  lui       $at, %hi(b_area_tik_floatTable)
/* 5EC748 802182B8 00220821 */  addu      $at, $at, $v0
/* 5EC74C 802182BC C4222DA4 */  lwc1      $f2, %lo(b_area_tik_floatTable)($at)
/* 5EC750 802182C0 00031880 */  sll       $v1, $v1, 2
/* 5EC754 802182C4 46041081 */  sub.s     $f2, $f2, $f4
/* 5EC758 802182C8 3C018022 */  lui       $at, %hi(b_area_tik_floatTable)
/* 5EC75C 802182CC 00230821 */  addu      $at, $at, $v1
/* 5EC760 802182D0 C4202DA4 */  lwc1      $f0, %lo(b_area_tik_floatTable)($at)
/* 5EC764 802182D4 46040001 */  sub.s     $f0, $f0, $f4
/* 5EC768 802182D8 46001085 */  abs.s     $f2, $f2
/* 5EC76C 802182DC 46000005 */  abs.s     $f0, $f0
/* 5EC770 802182E0 4600103C */  c.lt.s    $f2, $f0
/* 5EC774 802182E4 00000000 */  nop
/* 5EC778 802182E8 45000002 */  bc1f      .L802182F4
/* 5EC77C 802182EC 00C0182D */   daddu    $v1, $a2, $zero
/* 5EC780 802182F0 0080182D */  daddu     $v1, $a0, $zero
.L802182F4:
/* 5EC784 802182F4 44800000 */  mtc1      $zero, $f0
/* 5EC788 802182F8 00000000 */  nop
/* 5EC78C 802182FC 4600B03C */  c.lt.s    $f22, $f0
/* 5EC790 80218300 00000000 */  nop
/* 5EC794 80218304 4500000A */  bc1f      .L80218330
/* 5EC798 80218308 00000000 */   nop
/* 5EC79C 8021830C 4614003E */  c.le.s    $f0, $f20
/* 5EC7A0 80218310 00000000 */  nop
/* 5EC7A4 80218314 45000004 */  bc1f      .L80218328
/* 5EC7A8 80218318 240200B4 */   addiu    $v0, $zero, 0xb4
/* 5EC7AC 8021831C 00431823 */  subu      $v1, $v0, $v1
/* 5EC7B0 80218320 44800000 */  mtc1      $zero, $f0
/* 5EC7B4 80218324 00000000 */  nop
.L80218328:
/* 5EC7B8 80218328 4600B03C */  c.lt.s    $f22, $f0
/* 5EC7BC 8021832C 00000000 */  nop
.L80218330:
/* 5EC7C0 80218330 45000005 */  bc1f      .L80218348
/* 5EC7C4 80218334 00000000 */   nop
/* 5EC7C8 80218338 4600A03C */  c.lt.s    $f20, $f0
/* 5EC7CC 8021833C 00000000 */  nop
/* 5EC7D0 80218340 45030001 */  bc1tl     .L80218348
/* 5EC7D4 80218344 246300B4 */   addiu    $v1, $v1, 0xb4
.L80218348:
/* 5EC7D8 80218348 44800000 */  mtc1      $zero, $f0
/* 5EC7DC 8021834C 00000000 */  nop
/* 5EC7E0 80218350 4616003E */  c.le.s    $f0, $f22
/* 5EC7E4 80218354 00000000 */  nop
/* 5EC7E8 80218358 45000006 */  bc1f      .L80218374
/* 5EC7EC 8021835C 00000000 */   nop
/* 5EC7F0 80218360 4600A03C */  c.lt.s    $f20, $f0
/* 5EC7F4 80218364 00000000 */  nop
/* 5EC7F8 80218368 45000002 */  bc1f      .L80218374
/* 5EC7FC 8021836C 24020168 */   addiu    $v0, $zero, 0x168
/* 5EC800 80218370 00431823 */  subu      $v1, $v0, $v1
.L80218374:
/* 5EC804 80218374 8FBF0010 */  lw        $ra, 0x10($sp)
/* 5EC808 80218378 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 5EC80C 8021837C D7B40018 */  ldc1      $f20, 0x18($sp)
/* 5EC810 80218380 3062FFFF */  andi      $v0, $v1, 0xffff
/* 5EC814 80218384 03E00008 */  jr        $ra
/* 5EC818 80218388 27BD0028 */   addiu    $sp, $sp, 0x28
