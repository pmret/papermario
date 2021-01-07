.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218758_5ECBE8
/* 5ECBE8 80218758 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 5ECBEC 8021875C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 5ECBF0 80218760 46006586 */  mov.s     $f22, $f12
/* 5ECBF4 80218764 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 5ECBF8 80218768 AFBF0010 */  sw        $ra, 0x10($sp)
/* 5ECBFC 8021876C 0C00A3FC */  jal       length2D
/* 5ECC00 80218770 46007506 */   mov.s    $f20, $f14
/* 5ECC04 80218774 4600A18D */  trunc.w.s $f6, $f20
/* 5ECC08 80218778 44023000 */  mfc1      $v0, $f6
/* 5ECC0C 8021877C 00000000 */  nop       
/* 5ECC10 80218780 04420001 */  bltzl     $v0, .L80218788
/* 5ECC14 80218784 00021023 */   negu     $v0, $v0
.L80218788:
/* 5ECC18 80218788 44821000 */  mtc1      $v0, $f2
/* 5ECC1C 8021878C 00000000 */  nop       
/* 5ECC20 80218790 468010A0 */  cvt.s.w   $f2, $f2
/* 5ECC24 80218794 46001103 */  div.s     $f4, $f2, $f0
/* 5ECC28 80218798 0000202D */  daddu     $a0, $zero, $zero
/* 5ECC2C 8021879C 2406005A */  addiu     $a2, $zero, 0x5a
/* 5ECC30 802187A0 0080282D */  daddu     $a1, $a0, $zero
/* 5ECC34 802187A4 3C078022 */  lui       $a3, %hi(D_80227B7C)
/* 5ECC38 802187A8 24E77B7C */  addiu     $a3, $a3, %lo(D_80227B7C)
/* 5ECC3C 802187AC 30C2FFFF */  andi      $v0, $a2, 0xffff
.L802187B0:
/* 5ECC40 802187B0 3083FFFF */  andi      $v1, $a0, 0xffff
/* 5ECC44 802187B4 00431023 */  subu      $v0, $v0, $v1
/* 5ECC48 802187B8 00021FC2 */  srl       $v1, $v0, 0x1f
/* 5ECC4C 802187BC 00431021 */  addu      $v0, $v0, $v1
/* 5ECC50 802187C0 00021043 */  sra       $v0, $v0, 1
/* 5ECC54 802187C4 00821821 */  addu      $v1, $a0, $v0
/* 5ECC58 802187C8 3062FFFF */  andi      $v0, $v1, 0xffff
/* 5ECC5C 802187CC 00021080 */  sll       $v0, $v0, 2
/* 5ECC60 802187D0 00471021 */  addu      $v0, $v0, $a3
/* 5ECC64 802187D4 C4400000 */  lwc1      $f0, ($v0)
/* 5ECC68 802187D8 4604003C */  c.lt.s    $f0, $f4
/* 5ECC6C 802187DC 00000000 */  nop       
/* 5ECC70 802187E0 45020002 */  bc1fl     .L802187EC
/* 5ECC74 802187E4 0060302D */   daddu    $a2, $v1, $zero
/* 5ECC78 802187E8 0060202D */  daddu     $a0, $v1, $zero
.L802187EC:
/* 5ECC7C 802187EC 24A50001 */  addiu     $a1, $a1, 1
/* 5ECC80 802187F0 30A2FFFF */  andi      $v0, $a1, 0xffff
/* 5ECC84 802187F4 2C420007 */  sltiu     $v0, $v0, 7
/* 5ECC88 802187F8 1440FFED */  bnez      $v0, .L802187B0
/* 5ECC8C 802187FC 30C2FFFF */   andi     $v0, $a2, 0xffff
/* 5ECC90 80218800 3082FFFF */  andi      $v0, $a0, 0xffff
/* 5ECC94 80218804 00021080 */  sll       $v0, $v0, 2
/* 5ECC98 80218808 30C3FFFF */  andi      $v1, $a2, 0xffff
/* 5ECC9C 8021880C 3C018022 */  lui       $at, %hi(D_80227B7C)
/* 5ECCA0 80218810 00220821 */  addu      $at, $at, $v0
/* 5ECCA4 80218814 C4227B7C */  lwc1      $f2, %lo(D_80227B7C)($at)
/* 5ECCA8 80218818 00031880 */  sll       $v1, $v1, 2
/* 5ECCAC 8021881C 46041081 */  sub.s     $f2, $f2, $f4
/* 5ECCB0 80218820 3C018022 */  lui       $at, %hi(D_80227B7C)
/* 5ECCB4 80218824 00230821 */  addu      $at, $at, $v1
/* 5ECCB8 80218828 C4207B7C */  lwc1      $f0, %lo(D_80227B7C)($at)
/* 5ECCBC 8021882C 46040001 */  sub.s     $f0, $f0, $f4
/* 5ECCC0 80218830 46001085 */  abs.s     $f2, $f2
/* 5ECCC4 80218834 46000005 */  abs.s     $f0, $f0
/* 5ECCC8 80218838 4600103C */  c.lt.s    $f2, $f0
/* 5ECCCC 8021883C 00000000 */  nop       
/* 5ECCD0 80218840 45000002 */  bc1f      .L8021884C
/* 5ECCD4 80218844 00C0182D */   daddu    $v1, $a2, $zero
/* 5ECCD8 80218848 0080182D */  daddu     $v1, $a0, $zero
.L8021884C:
/* 5ECCDC 8021884C 44800000 */  mtc1      $zero, $f0
/* 5ECCE0 80218850 00000000 */  nop       
/* 5ECCE4 80218854 4600B03C */  c.lt.s    $f22, $f0
/* 5ECCE8 80218858 00000000 */  nop       
/* 5ECCEC 8021885C 4500000A */  bc1f      .L80218888
/* 5ECCF0 80218860 00000000 */   nop      
/* 5ECCF4 80218864 4614003E */  c.le.s    $f0, $f20
/* 5ECCF8 80218868 00000000 */  nop       
/* 5ECCFC 8021886C 45000004 */  bc1f      .L80218880
/* 5ECD00 80218870 240200B4 */   addiu    $v0, $zero, 0xb4
/* 5ECD04 80218874 00431823 */  subu      $v1, $v0, $v1
/* 5ECD08 80218878 44800000 */  mtc1      $zero, $f0
/* 5ECD0C 8021887C 00000000 */  nop       
.L80218880:
/* 5ECD10 80218880 4600B03C */  c.lt.s    $f22, $f0
/* 5ECD14 80218884 00000000 */  nop       
.L80218888:
/* 5ECD18 80218888 45000005 */  bc1f      .L802188A0
/* 5ECD1C 8021888C 00000000 */   nop      
/* 5ECD20 80218890 4600A03C */  c.lt.s    $f20, $f0
/* 5ECD24 80218894 00000000 */  nop       
/* 5ECD28 80218898 45030001 */  bc1tl     .L802188A0
/* 5ECD2C 8021889C 246300B4 */   addiu    $v1, $v1, 0xb4
.L802188A0:
/* 5ECD30 802188A0 44800000 */  mtc1      $zero, $f0
/* 5ECD34 802188A4 00000000 */  nop       
/* 5ECD38 802188A8 4616003E */  c.le.s    $f0, $f22
/* 5ECD3C 802188AC 00000000 */  nop       
/* 5ECD40 802188B0 45000006 */  bc1f      .L802188CC
/* 5ECD44 802188B4 00000000 */   nop      
/* 5ECD48 802188B8 4600A03C */  c.lt.s    $f20, $f0
/* 5ECD4C 802188BC 00000000 */  nop       
/* 5ECD50 802188C0 45000002 */  bc1f      .L802188CC
/* 5ECD54 802188C4 24020168 */   addiu    $v0, $zero, 0x168
/* 5ECD58 802188C8 00431823 */  subu      $v1, $v0, $v1
.L802188CC:
/* 5ECD5C 802188CC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 5ECD60 802188D0 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 5ECD64 802188D4 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 5ECD68 802188D8 3062FFFF */  andi      $v0, $v1, 0xffff
/* 5ECD6C 802188DC 03E00008 */  jr        $ra
/* 5ECD70 802188E0 27BD0028 */   addiu    $sp, $sp, 0x28
