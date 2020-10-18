.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD1AC
/* 31CD1C 802BD1AC 3C02802C */  lui       $v0, 0x802c
/* 31CD20 802BD1B0 8C42E310 */  lw        $v0, -0x1cf0($v0)
/* 31CD24 802BD1B4 3C013F00 */  lui       $at, 0x3f00
/* 31CD28 802BD1B8 44810000 */  mtc1      $at, $f0
/* 31CD2C 802BD1BC 8C45000C */  lw        $a1, 0xc($v0)
/* 31CD30 802BD1C0 24030001 */  addiu     $v1, $zero, 1
/* 31CD34 802BD1C4 ACA40000 */  sw        $a0, ($a1)
/* 31CD38 802BD1C8 00042080 */  sll       $a0, $a0, 2
/* 31CD3C 802BD1CC 3C01802C */  lui       $at, 0x802c
/* 31CD40 802BD1D0 00240821 */  addu      $at, $at, $a0
/* 31CD44 802BD1D4 C422E250 */  lwc1      $f2, -0x1db0($at)
/* 31CD48 802BD1D8 468010A0 */  cvt.s.w   $f2, $f2
/* 31CD4C 802BD1DC 8C420008 */  lw        $v0, 8($v0)
/* 31CD50 802BD1E0 46001082 */  mul.s     $f2, $f2, $f0
/* 31CD54 802BD1E4 00000000 */  nop       
/* 31CD58 802BD1E8 2444FFFF */  addiu     $a0, $v0, -1
/* 31CD5C 802BD1EC 0064102A */  slt       $v0, $v1, $a0
/* 31CD60 802BD1F0 10400010 */  beqz      $v0, .L802BD234
/* 31CD64 802BD1F4 24A50038 */   addiu    $a1, $a1, 0x38
/* 31CD68 802BD1F8 3C01BF80 */  lui       $at, 0xbf80
/* 31CD6C 802BD1FC 44812000 */  mtc1      $at, $f4
.L802BD200:
/* 31CD70 802BD200 30620001 */  andi      $v0, $v1, 1
/* 31CD74 802BD204 44820000 */  mtc1      $v0, $f0
/* 31CD78 802BD208 00000000 */  nop       
/* 31CD7C 802BD20C 46800020 */  cvt.s.w   $f0, $f0
/* 31CD80 802BD210 46001002 */  mul.s     $f0, $f2, $f0
/* 31CD84 802BD214 00000000 */  nop       
/* 31CD88 802BD218 46002001 */  sub.s     $f0, $f4, $f0
/* 31CD8C 802BD21C 24630001 */  addiu     $v1, $v1, 1
/* 31CD90 802BD220 0064102A */  slt       $v0, $v1, $a0
/* 31CD94 802BD224 4600018D */  trunc.w.s $f6, $f0
/* 31CD98 802BD228 E4A60020 */  swc1      $f6, 0x20($a1)
/* 31CD9C 802BD22C 1440FFF4 */  bnez      $v0, .L802BD200
/* 31CDA0 802BD230 24A50038 */   addiu    $a1, $a1, 0x38
.L802BD234:
/* 31CDA4 802BD234 03E00008 */  jr        $ra
/* 31CDA8 802BD238 00000000 */   nop      
