.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel dist2D
/* 0052D4 80029ED4 44861000 */  mtc1  $a2, $f2
/* 0052D8 80029ED8 00000000 */  nop   
/* 0052DC 80029EDC 460C1301 */  sub.s $f12, $f2, $f12
/* 0052E0 80029EE0 460C6302 */  mul.s $f12, $f12, $f12
/* 0052E4 80029EE4 00000000 */  nop   
/* 0052E8 80029EE8 44871000 */  mtc1  $a3, $f2
/* 0052EC 80029EEC 00000000 */  nop   
/* 0052F0 80029EF0 460E1381 */  sub.s $f14, $f2, $f14
/* 0052F4 80029EF4 460E7382 */  mul.s $f14, $f14, $f14
/* 0052F8 80029EF8 00000000 */  nop   
/* 0052FC 80029EFC 460E6300 */  add.s $f12, $f12, $f14
/* 005300 80029F00 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 005304 80029F04 46006004 */  sqrt.s $f0, $f12
/* 005308 80029F08 46000032 */  c.eq.s $f0, $f0
/* 00530C 80029F0C 00000000 */  nop   
/* 005310 80029F10 45010003 */  bc1t  .L80029F20
/* 005314 80029F14 AFBF0010 */   sw    $ra, 0x10($sp)
/* 005318 80029F18 0C0187BC */  jal   sqrtf
/* 00531C 80029F1C 00000000 */   nop   
.L80029F20:
/* 005320 80029F20 8FBF0010 */  lw    $ra, 0x10($sp)
/* 005324 80029F24 03E00008 */  jr    $ra
/* 005328 80029F28 27BD0018 */   addiu $sp, $sp, 0x18

