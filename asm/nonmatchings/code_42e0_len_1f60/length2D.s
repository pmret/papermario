.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel length2D
/* 0043F0 80028FF0 460C6302 */  mul.s $f12, $f12, $f12
/* 0043F4 80028FF4 00000000 */  nop   
/* 0043F8 80028FF8 460E7382 */  mul.s $f14, $f14, $f14
/* 0043FC 80028FFC 00000000 */  nop   
/* 004400 80029000 460E6300 */  add.s $f12, $f12, $f14
/* 004404 80029004 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 004408 80029008 46006004 */  sqrt.s $f0, $f12
/* 00440C 8002900C 46000032 */  c.eq.s $f0, $f0
/* 004410 80029010 00000000 */  nop   
/* 004414 80029014 45010003 */  bc1t  .L80029024
/* 004418 80029018 AFBF0010 */   sw    $ra, 0x10($sp)
/* 00441C 8002901C 0C0187BC */  jal   sqrtf
/* 004420 80029020 00000000 */   nop   
.L80029024:
/* 004424 80029024 8FBF0010 */  lw    $ra, 0x10($sp)
/* 004428 80029028 03E00008 */  jr    $ra
/* 00442C 8002902C 27BD0018 */   addiu $sp, $sp, 0x18

