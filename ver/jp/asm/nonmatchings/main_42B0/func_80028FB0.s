.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80028FB0
/* 43B0 80028FB0 460C6302 */  mul.s     $f12, $f12, $f12
/* 43B4 80028FB4 00000000 */  nop
/* 43B8 80028FB8 460E7382 */  mul.s     $f14, $f14, $f14
/* 43BC 80028FBC 00000000 */  nop
/* 43C0 80028FC0 460E6300 */  add.s     $f12, $f12, $f14
/* 43C4 80028FC4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 43C8 80028FC8 46006004 */  sqrt.s    $f0, $f12
/* 43CC 80028FCC 46000032 */  c.eq.s    $f0, $f0
/* 43D0 80028FD0 00000000 */  nop
/* 43D4 80028FD4 45010003 */  bc1t      .L80028FE4
/* 43D8 80028FD8 AFBF0010 */   sw       $ra, 0x10($sp)
/* 43DC 80028FDC 0C0187B0 */  jal       func_80061EC0
/* 43E0 80028FE0 00000000 */   nop
.L80028FE4:
/* 43E4 80028FE4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 43E8 80028FE8 03E00008 */  jr        $ra
/* 43EC 80028FEC 27BD0018 */   addiu    $sp, $sp, 0x18
