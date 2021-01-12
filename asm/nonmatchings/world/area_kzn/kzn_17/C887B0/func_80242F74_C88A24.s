.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242F74_C88A24
/* C88A24 80242F74 3C018024 */  lui       $at, %hi(D_802465E0)
/* C88A28 80242F78 D42265E0 */  ldc1      $f2, %lo(D_802465E0)($at)
/* C88A2C 80242F7C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C88A30 80242F80 AFB00010 */  sw        $s0, 0x10($sp)
/* C88A34 80242F84 0080802D */  daddu     $s0, $a0, $zero
/* C88A38 80242F88 AFBF0014 */  sw        $ra, 0x14($sp)
/* C88A3C 80242F8C C6000084 */  lwc1      $f0, 0x84($s0)
/* C88A40 80242F90 46800021 */  cvt.d.w   $f0, $f0
/* C88A44 80242F94 46201081 */  sub.d     $f2, $f2, $f0
/* C88A48 80242F98 462010A0 */  cvt.s.d   $f2, $f2
/* C88A4C 80242F9C 46021082 */  mul.s     $f2, $f2, $f2
/* C88A50 80242FA0 00000000 */  nop
/* C88A54 80242FA4 3C018024 */  lui       $at, %hi(D_802465E8)
/* C88A58 80242FA8 D42065E8 */  ldc1      $f0, %lo(D_802465E8)($at)
/* C88A5C 80242FAC C604008C */  lwc1      $f4, 0x8c($s0)
/* C88A60 80242FB0 46802121 */  cvt.d.w   $f4, $f4
/* C88A64 80242FB4 46240001 */  sub.d     $f0, $f0, $f4
/* C88A68 80242FB8 46200020 */  cvt.s.d   $f0, $f0
/* C88A6C 80242FBC 46000002 */  mul.s     $f0, $f0, $f0
/* C88A70 80242FC0 00000000 */  nop
/* C88A74 80242FC4 46001300 */  add.s     $f12, $f2, $f0
/* C88A78 80242FC8 46006004 */  sqrt.s    $f0, $f12
/* C88A7C 80242FCC 46000032 */  c.eq.s    $f0, $f0
/* C88A80 80242FD0 00000000 */  nop
/* C88A84 80242FD4 45030004 */  bc1tl     .L80242FE8
/* C88A88 80242FD8 46000007 */   neg.s    $f0, $f0
/* C88A8C 80242FDC 0C0187BC */  jal       sqrtf
/* C88A90 80242FE0 00000000 */   nop
/* C88A94 80242FE4 46000007 */  neg.s     $f0, $f0
.L80242FE8:
/* C88A98 80242FE8 4600018D */  trunc.w.s $f6, $f0
/* C88A9C 80242FEC E6060090 */  swc1      $f6, 0x90($s0)
/* C88AA0 80242FF0 8FBF0014 */  lw        $ra, 0x14($sp)
/* C88AA4 80242FF4 8FB00010 */  lw        $s0, 0x10($sp)
/* C88AA8 80242FF8 24020002 */  addiu     $v0, $zero, 2
/* C88AAC 80242FFC 03E00008 */  jr        $ra
/* C88AB0 80243000 27BD0018 */   addiu    $sp, $sp, 0x18
