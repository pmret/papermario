.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80029A84
/* 4E84 80029A84 44800000 */  mtc1      $zero, $f0
/* 4E88 80029A88 00000000 */  nop
/* 4E8C 80029A8C 460C003E */  c.le.s    $f0, $f12
/* 4E90 80029A90 00000000 */  nop
/* 4E94 80029A94 4502000A */  bc1fl     .L80029AC0
/* 4E98 80029A98 460060A1 */   cvt.d.s  $f2, $f12
/* 4E9C 80029A9C 3C013FE0 */  lui       $at, 0x3fe0
/* 4EA0 80029AA0 44811800 */  mtc1      $at, $f3
/* 4EA4 80029AA4 44801000 */  mtc1      $zero, $f2
/* 4EA8 80029AA8 46006021 */  cvt.d.s   $f0, $f12
/* 4EAC 80029AAC 46220000 */  add.d     $f0, $f0, $f2
/* 4EB0 80029AB0 4620010D */  trunc.w.d $f4, $f0
/* 4EB4 80029AB4 44022000 */  mfc1      $v0, $f4
/* 4EB8 80029AB8 03E00008 */  jr        $ra
/* 4EBC 80029ABC 00000000 */   nop
.L80029AC0:
/* 4EC0 80029AC0 3C013FE0 */  lui       $at, 0x3fe0
/* 4EC4 80029AC4 44810800 */  mtc1      $at, $f1
/* 4EC8 80029AC8 44800000 */  mtc1      $zero, $f0
/* 4ECC 80029ACC 00000000 */  nop
/* 4ED0 80029AD0 46220001 */  sub.d     $f0, $f0, $f2
/* 4ED4 80029AD4 4620010D */  trunc.w.d $f4, $f0
/* 4ED8 80029AD8 44022000 */  mfc1      $v0, $f4
/* 4EDC 80029ADC 03E00008 */  jr        $ra
/* 4EE0 80029AE0 00021023 */   negu     $v0, $v0
