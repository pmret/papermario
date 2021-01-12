.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0012104
/* 32DE14 E0012104 94820004 */  lhu       $v0, 4($a0)
/* 32DE18 E0012108 14400010 */  bnez      $v0, .LE001214C
/* 32DE1C E001210C 00000000 */   nop
/* 32DE20 E0012110 C4820078 */  lwc1      $f2, 0x78($a0)
/* 32DE24 E0012114 44800000 */  mtc1      $zero, $f0
/* 32DE28 E0012118 00000000 */  nop
/* 32DE2C E001211C 46001032 */  c.eq.s    $f2, $f0
/* 32DE30 E0012120 00000000 */  nop
/* 32DE34 E0012124 45010009 */  bc1t      .LE001214C
/* 32DE38 E0012128 00000000 */   nop
/* 32DE3C E001212C 3C028011 */  lui       $v0, %hi(gPlayerActionState)
/* 32DE40 E0012130 8042F07C */  lb        $v0, %lo(gPlayerActionState)($v0)
/* 32DE44 E0012134 14400005 */  bnez      $v0, .LE001214C
/* 32DE48 E0012138 00000000 */   nop
/* 32DE4C E001213C 94820006 */  lhu       $v0, 6($a0)
/* 32DE50 E0012140 24420001 */  addiu     $v0, $v0, 1
/* 32DE54 E0012144 03E00008 */  jr        $ra
/* 32DE58 E0012148 A4820006 */   sh       $v0, 6($a0)
.LE001214C:
/* 32DE5C E001214C C48E0088 */  lwc1      $f14, 0x88($a0)
/* 32DE60 E0012150 C480008C */  lwc1      $f0, 0x8c($a0)
/* 32DE64 E0012154 46007380 */  add.s     $f14, $f14, $f0
/* 32DE68 E0012158 C48C0084 */  lwc1      $f12, 0x84($a0)
/* 32DE6C E001215C 460E6300 */  add.s     $f12, $f12, $f14
/* 32DE70 E0012160 C4800080 */  lwc1      $f0, 0x80($a0)
/* 32DE74 E0012164 460C0000 */  add.s     $f0, $f0, $f12
/* 32DE78 E0012168 C48A0070 */  lwc1      $f10, 0x70($a0)
/* 32DE7C E001216C 460A0282 */  mul.s     $f10, $f0, $f10
/* 32DE80 E0012170 00000000 */  nop
/* 32DE84 E0012174 E4800080 */  swc1      $f0, 0x80($a0)
/* 32DE88 E0012178 46000186 */  mov.s     $f6, $f0
/* 32DE8C E001217C C4800074 */  lwc1      $f0, 0x74($a0)
/* 32DE90 E0012180 46003182 */  mul.s     $f6, $f6, $f0
/* 32DE94 E0012184 00000000 */  nop
/* 32DE98 E0012188 C4800090 */  lwc1      $f0, 0x90($a0)
/* 32DE9C E001218C 46003182 */  mul.s     $f6, $f6, $f0
/* 32DEA0 E0012190 00000000 */  nop
/* 32DEA4 E0012194 C4880080 */  lwc1      $f8, 0x80($a0)
/* 32DEA8 E0012198 C4800074 */  lwc1      $f0, 0x74($a0)
/* 32DEAC E001219C 46004202 */  mul.s     $f8, $f8, $f0
/* 32DEB0 E00121A0 00000000 */  nop
/* 32DEB4 E00121A4 C4800094 */  lwc1      $f0, 0x94($a0)
/* 32DEB8 E00121A8 90820008 */  lbu       $v0, 8($a0)
/* 32DEBC E00121AC 46004202 */  mul.s     $f8, $f8, $f0
/* 32DEC0 E00121B0 00000000 */  nop
/* 32DEC4 E00121B4 C482002C */  lwc1      $f2, 0x2c($a0)
/* 32DEC8 E00121B8 C484000C */  lwc1      $f4, 0xc($a0)
/* 32DECC E00121BC 2442FFF4 */  addiu     $v0, $v0, -0xc
/* 32DED0 E00121C0 A0820008 */  sb        $v0, 8($a0)
/* 32DED4 E00121C4 460A1080 */  add.s     $f2, $f2, $f10
/* 32DED8 E00121C8 E48E0088 */  swc1      $f14, 0x88($a0)
/* 32DEDC E00121CC 44805000 */  mtc1      $zero, $f10
/* 32DEE0 E00121D0 46062101 */  sub.s     $f4, $f4, $f6
/* 32DEE4 E00121D4 C4800014 */  lwc1      $f0, 0x14($a0)
/* 32DEE8 E00121D8 C4860080 */  lwc1      $f6, 0x80($a0)
/* 32DEEC E00121DC 46080001 */  sub.s     $f0, $f0, $f8
/* 32DEF0 E00121E0 E48C0084 */  swc1      $f12, 0x84($a0)
/* 32DEF4 E00121E4 E482002C */  swc1      $f2, 0x2c($a0)
/* 32DEF8 E00121E8 460A303C */  c.lt.s    $f6, $f10
/* 32DEFC E00121EC E484000C */  swc1      $f4, 0xc($a0)
/* 32DF00 E00121F0 45000002 */  bc1f      .LE00121FC
/* 32DF04 E00121F4 E4800014 */   swc1     $f0, 0x14($a0)
/* 32DF08 E00121F8 E48A0078 */  swc1      $f10, 0x78($a0)
.LE00121FC:
/* 32DF0C E00121FC 03E00008 */  jr        $ra
/* 32DF10 E0012200 00000000 */   nop
