.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80029E94
/* 5294 80029E94 44861000 */  mtc1      $a2, $f2
/* 5298 80029E98 00000000 */  nop
/* 529C 80029E9C 460C1301 */  sub.s     $f12, $f2, $f12
/* 52A0 80029EA0 460C6302 */  mul.s     $f12, $f12, $f12
/* 52A4 80029EA4 00000000 */  nop
/* 52A8 80029EA8 44871000 */  mtc1      $a3, $f2
/* 52AC 80029EAC 00000000 */  nop
/* 52B0 80029EB0 460E1381 */  sub.s     $f14, $f2, $f14
/* 52B4 80029EB4 460E7382 */  mul.s     $f14, $f14, $f14
/* 52B8 80029EB8 00000000 */  nop
/* 52BC 80029EBC 460E6300 */  add.s     $f12, $f12, $f14
/* 52C0 80029EC0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 52C4 80029EC4 46006004 */  sqrt.s    $f0, $f12
/* 52C8 80029EC8 46000032 */  c.eq.s    $f0, $f0
/* 52CC 80029ECC 00000000 */  nop
/* 52D0 80029ED0 45010003 */  bc1t      .L80029EE0
/* 52D4 80029ED4 AFBF0010 */   sw       $ra, 0x10($sp)
/* 52D8 80029ED8 0C0187B0 */  jal       func_80061EC0
/* 52DC 80029EDC 00000000 */   nop
.L80029EE0:
/* 52E0 80029EE0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 52E4 80029EE4 03E00008 */  jr        $ra
/* 52E8 80029EE8 27BD0018 */   addiu    $sp, $sp, 0x18
