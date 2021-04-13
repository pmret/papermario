.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005DA04
/* 38E04 8005DA04 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 38E08 8005DA08 AFB00010 */  sw        $s0, 0x10($sp)
/* 38E0C 8005DA0C 0080802D */  daddu     $s0, $a0, $zero
/* 38E10 8005DA10 AFBF0014 */  sw        $ra, 0x14($sp)
/* 38E14 8005DA14 C60C0084 */  lwc1      $f12, 0x84($s0)
/* 38E18 8005DA18 0C00A6B9 */  jal       func_80029AE4
/* 38E1C 8005DA1C 46806320 */   cvt.s.w  $f12, $f12
/* 38E20 8005DA20 3C014334 */  lui       $at, 0x4334
/* 38E24 8005DA24 44811000 */  mtc1      $at, $f2
/* 38E28 8005DA28 4600018D */  trunc.w.s $f6, $f0
/* 38E2C 8005DA2C E6060084 */  swc1      $f6, 0x84($s0)
/* 38E30 8005DA30 4600103E */  c.le.s    $f2, $f0
/* 38E34 8005DA34 00000000 */  nop
/* 38E38 8005DA38 45030001 */  bc1tl     .L8005DA40
/* 38E3C 8005DA3C 46020001 */   sub.s    $f0, $f0, $f2
.L8005DA40:
/* 38E40 8005DA40 3C0142B4 */  lui       $at, 0x42b4
/* 38E44 8005DA44 44812000 */  mtc1      $at, $f4
/* 38E48 8005DA48 00000000 */  nop
/* 38E4C 8005DA4C 4600203E */  c.le.s    $f4, $f0
/* 38E50 8005DA50 00000000 */  nop
/* 38E54 8005DA54 45030001 */  bc1tl     .L8005DA5C
/* 38E58 8005DA58 46001001 */   sub.s    $f0, $f2, $f0
.L8005DA5C:
/* 38E5C 8005DA5C 46002001 */  sub.s     $f0, $f4, $f0
/* 38E60 8005DA60 3C0142BE */  lui       $at, 0x42be
/* 38E64 8005DA64 44811000 */  mtc1      $at, $f2
/* 38E68 8005DA68 00000000 */  nop
/* 38E6C 8005DA6C 46020002 */  mul.s     $f0, $f0, $f2
/* 38E70 8005DA70 00000000 */  nop
/* 38E74 8005DA74 46040003 */  div.s     $f0, $f0, $f4
/* 38E78 8005DA78 4600018D */  trunc.w.s $f6, $f0
/* 38E7C 8005DA7C 44023000 */  mfc1      $v0, $f6
/* 38E80 8005DA80 00000000 */  nop
/* 38E84 8005DA84 244200A0 */  addiu     $v0, $v0, 0xa0
/* 38E88 8005DA88 AE02008C */  sw        $v0, 0x8c($s0)
/* 38E8C 8005DA8C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 38E90 8005DA90 8FB00010 */  lw        $s0, 0x10($sp)
/* 38E94 8005DA94 24020002 */  addiu     $v0, $zero, 2
/* 38E98 8005DA98 03E00008 */  jr        $ra
/* 38E9C 8005DA9C 27BD0018 */   addiu    $sp, $sp, 0x18
