.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E006A85C
/* 36D87C E006A85C 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 36D880 E006A860 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 36D884 E006A864 C4820034 */  lwc1      $f2, 0x34($a0)
/* 36D888 E006A868 3C014080 */  lui       $at, 0x4080
/* 36D88C E006A86C 44812000 */  mtc1      $at, $f4
/* 36D890 E006A870 3C08F200 */  lui       $t0, 0xf200
/* 36D894 E006A874 46041082 */  mul.s     $f2, $f2, $f4
/* 36D898 E006A878 00000000 */  nop
/* 36D89C E006A87C 8C670000 */  lw        $a3, ($v1)
/* 36D8A0 E006A880 C4800038 */  lwc1      $f0, 0x38($a0)
/* 36D8A4 E006A884 00E0482D */  daddu     $t1, $a3, $zero
/* 36D8A8 E006A888 24E70008 */  addiu     $a3, $a3, 8
/* 36D8AC E006A88C 46040002 */  mul.s     $f0, $f0, $f4
/* 36D8B0 E006A890 00000000 */  nop
/* 36D8B4 E006A894 24E20008 */  addiu     $v0, $a3, 8
/* 36D8B8 E006A898 AC670000 */  sw        $a3, ($v1)
/* 36D8BC E006A89C AC620000 */  sw        $v0, ($v1)
/* 36D8C0 E006A8A0 4600118D */  trunc.w.s $f6, $f2
/* 36D8C4 E006A8A4 44023000 */  mfc1      $v0, $f6
/* 36D8C8 E006A8A8 4600018D */  trunc.w.s $f6, $f0
/* 36D8CC E006A8AC 44063000 */  mfc1      $a2, $f6
/* 36D8D0 E006A8B0 30450FFF */  andi      $a1, $v0, 0xfff
/* 36D8D4 E006A8B4 00052B00 */  sll       $a1, $a1, 0xc
/* 36D8D8 E006A8B8 30C30FFF */  andi      $v1, $a2, 0xfff
/* 36D8DC E006A8BC 00681825 */  or        $v1, $v1, $t0
/* 36D8E0 E006A8C0 00A32825 */  or        $a1, $a1, $v1
/* 36D8E4 E006A8C4 24420200 */  addiu     $v0, $v0, 0x200
/* 36D8E8 E006A8C8 C480003C */  lwc1      $f0, 0x3c($a0)
/* 36D8EC E006A8CC 30420FFF */  andi      $v0, $v0, 0xfff
/* 36D8F0 E006A8D0 46040002 */  mul.s     $f0, $f0, $f4
/* 36D8F4 E006A8D4 00000000 */  nop
/* 36D8F8 E006A8D8 00021300 */  sll       $v0, $v0, 0xc
/* 36D8FC E006A8DC 24C60100 */  addiu     $a2, $a2, 0x100
/* 36D900 E006A8E0 C4820040 */  lwc1      $f2, 0x40($a0)
/* 36D904 E006A8E4 30C60FFF */  andi      $a2, $a2, 0xfff
/* 36D908 E006A8E8 46041082 */  mul.s     $f2, $f2, $f4
/* 36D90C E006A8EC 00000000 */  nop
/* 36D910 E006A8F0 00461025 */  or        $v0, $v0, $a2
/* 36D914 E006A8F4 AD250000 */  sw        $a1, ($t1)
/* 36D918 E006A8F8 AD220004 */  sw        $v0, 4($t1)
/* 36D91C E006A8FC 4600018D */  trunc.w.s $f6, $f0
/* 36D920 E006A900 44043000 */  mfc1      $a0, $f6
/* 36D924 E006A904 4600118D */  trunc.w.s $f6, $f2
/* 36D928 E006A908 44053000 */  mfc1      $a1, $f6
/* 36D92C E006A90C 30830FFF */  andi      $v1, $a0, 0xfff
/* 36D930 E006A910 00031B00 */  sll       $v1, $v1, 0xc
/* 36D934 E006A914 30A20FFF */  andi      $v0, $a1, 0xfff
/* 36D938 E006A918 00481025 */  or        $v0, $v0, $t0
/* 36D93C E006A91C 00621825 */  or        $v1, $v1, $v0
/* 36D940 E006A920 24840200 */  addiu     $a0, $a0, 0x200
/* 36D944 E006A924 30840FFF */  andi      $a0, $a0, 0xfff
/* 36D948 E006A928 00042300 */  sll       $a0, $a0, 0xc
/* 36D94C E006A92C 24A50100 */  addiu     $a1, $a1, 0x100
/* 36D950 E006A930 30A50FFF */  andi      $a1, $a1, 0xfff
/* 36D954 E006A934 3C020100 */  lui       $v0, 0x100
/* 36D958 E006A938 00A22825 */  or        $a1, $a1, $v0
/* 36D95C E006A93C 00852025 */  or        $a0, $a0, $a1
/* 36D960 E006A940 ACE30000 */  sw        $v1, ($a3)
/* 36D964 E006A944 03E00008 */  jr        $ra
/* 36D968 E006A948 ACE40004 */   sw       $a0, 4($a3)
