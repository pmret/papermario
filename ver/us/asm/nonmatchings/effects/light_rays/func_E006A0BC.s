.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E006A0BC
/* 36D0DC E006A0BC 24A2FFFF */  addiu     $v0, $a1, -1
/* 36D0E0 E006A0C0 00021880 */  sll       $v1, $v0, 2
/* 36D0E4 E006A0C4 00621821 */  addu      $v1, $v1, $v0
/* 36D0E8 E006A0C8 00031080 */  sll       $v0, $v1, 2
/* 36D0EC E006A0CC 24630001 */  addiu     $v1, $v1, 1
/* 36D0F0 E006A0D0 00033080 */  sll       $a2, $v1, 2
/* 36D0F4 E006A0D4 24630001 */  addiu     $v1, $v1, 1
/* 36D0F8 E006A0D8 00033880 */  sll       $a3, $v1, 2
/* 36D0FC E006A0DC 24630001 */  addiu     $v1, $v1, 1
/* 36D100 E006A0E0 00052840 */  sll       $a1, $a1, 1
/* 36D104 E006A0E4 24A5001E */  addiu     $a1, $a1, 0x1e
/* 36D108 E006A0E8 AC800058 */  sw        $zero, 0x58($a0)
/* 36D10C E006A0EC AC850028 */  sw        $a1, 0x28($a0)
/* 36D110 E006A0F0 3C01E007 */  lui       $at, %hi(D_E006AE10)
/* 36D114 E006A0F4 00220821 */  addu      $at, $at, $v0
/* 36D118 E006A0F8 C420AE10 */  lwc1      $f0, %lo(D_E006AE10)($at)
/* 36D11C E006A0FC 46800020 */  cvt.s.w   $f0, $f0
/* 36D120 E006A100 E480005C */  swc1      $f0, 0x5c($a0)
/* 36D124 E006A104 3C01E007 */  lui       $at, %hi(D_E006AE10)
/* 36D128 E006A108 00260821 */  addu      $at, $at, $a2
/* 36D12C E006A10C C420AE10 */  lwc1      $f0, %lo(D_E006AE10)($at)
/* 36D130 E006A110 46800020 */  cvt.s.w   $f0, $f0
/* 36D134 E006A114 E4800060 */  swc1      $f0, 0x60($a0)
/* 36D138 E006A118 3C01E007 */  lui       $at, %hi(D_E006AE10)
/* 36D13C E006A11C 00270821 */  addu      $at, $at, $a3
/* 36D140 E006A120 C420AE10 */  lwc1      $f0, %lo(D_E006AE10)($at)
/* 36D144 E006A124 46800020 */  cvt.s.w   $f0, $f0
/* 36D148 E006A128 44801000 */  mtc1      $zero, $f2
/* 36D14C E006A12C 3C01BF19 */  lui       $at, 0xbf19
/* 36D150 E006A130 3421999A */  ori       $at, $at, 0x999a
/* 36D154 E006A134 44812000 */  mtc1      $at, $f4
/* 36D158 E006A138 3C014120 */  lui       $at, 0x4120
/* 36D15C E006A13C 44813000 */  mtc1      $at, $f6
/* 36D160 E006A140 3C013F19 */  lui       $at, 0x3f19
/* 36D164 E006A144 3421999A */  ori       $at, $at, 0x999a
/* 36D168 E006A148 44814000 */  mtc1      $at, $f8
/* 36D16C E006A14C 00031080 */  sll       $v0, $v1, 2
/* 36D170 E006A150 E4800064 */  swc1      $f0, 0x64($a0)
/* 36D174 E006A154 AC800024 */  sw        $zero, 0x24($a0)
/* 36D178 E006A158 AC80002C */  sw        $zero, 0x2c($a0)
/* 36D17C E006A15C E4820038 */  swc1      $f2, 0x38($a0)
/* 36D180 E006A160 E4820034 */  swc1      $f2, 0x34($a0)
/* 36D184 E006A164 E4820048 */  swc1      $f2, 0x48($a0)
/* 36D188 E006A168 E484004C */  swc1      $f4, 0x4c($a0)
/* 36D18C E006A16C E486003C */  swc1      $f6, 0x3c($a0)
/* 36D190 E006A170 E4820040 */  swc1      $f2, 0x40($a0)
/* 36D194 E006A174 E4820050 */  swc1      $f2, 0x50($a0)
/* 36D198 E006A178 E4880054 */  swc1      $f8, 0x54($a0)
/* 36D19C E006A17C E4820080 */  swc1      $f2, 0x80($a0)
/* 36D1A0 E006A180 3C01E007 */  lui       $at, %hi(D_E006AE10)
/* 36D1A4 E006A184 00220821 */  addu      $at, $at, $v0
/* 36D1A8 E006A188 C420AE10 */  lwc1      $f0, %lo(D_E006AE10)($at)
/* 36D1AC E006A18C 46800020 */  cvt.s.w   $f0, $f0
/* 36D1B0 E006A190 44801000 */  mtc1      $zero, $f2
/* 36D1B4 E006A194 44801800 */  mtc1      $zero, $f3
/* 36D1B8 E006A198 46000021 */  cvt.d.s   $f0, $f0
/* 36D1BC E006A19C 46220002 */  mul.d     $f0, $f0, $f2
/* 36D1C0 E006A1A0 00000000 */  nop
/* 36D1C4 E006A1A4 24630001 */  addiu     $v1, $v1, 1
/* 36D1C8 E006A1A8 00031880 */  sll       $v1, $v1, 2
/* 36D1CC E006A1AC 3C01E007 */  lui       $at, %hi(D_E006AF50)
/* 36D1D0 E006A1B0 D422AF50 */  ldc1      $f2, %lo(D_E006AF50)($at)
/* 36D1D4 E006A1B4 46200020 */  cvt.s.d   $f0, $f0
/* 36D1D8 E006A1B8 E4800084 */  swc1      $f0, 0x84($a0)
/* 36D1DC E006A1BC 3C01E007 */  lui       $at, %hi(D_E006AE10)
/* 36D1E0 E006A1C0 00230821 */  addu      $at, $at, $v1
/* 36D1E4 E006A1C4 C420AE10 */  lwc1      $f0, %lo(D_E006AE10)($at)
/* 36D1E8 E006A1C8 46800020 */  cvt.s.w   $f0, $f0
/* 36D1EC E006A1CC 46000021 */  cvt.d.s   $f0, $f0
/* 36D1F0 E006A1D0 46220002 */  mul.d     $f0, $f0, $f2
/* 36D1F4 E006A1D4 00000000 */  nop
/* 36D1F8 E006A1D8 AC800090 */  sw        $zero, 0x90($a0)
/* 36D1FC E006A1DC 46200020 */  cvt.s.d   $f0, $f0
/* 36D200 E006A1E0 03E00008 */  jr        $ra
/* 36D204 E006A1E4 E4800088 */   swc1     $f0, 0x88($a0)
