.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel round
/* 4EC4 80029AC4 44800000 */  mtc1      $zero, $f0
/* 4EC8 80029AC8 00000000 */  nop
/* 4ECC 80029ACC 460C003E */  c.le.s    $f0, $f12
/* 4ED0 80029AD0 00000000 */  nop
/* 4ED4 80029AD4 4502000A */  bc1fl     .L80029B00
/* 4ED8 80029AD8 460060A1 */   cvt.d.s  $f2, $f12
/* 4EDC 80029ADC 3C013FE0 */  lui       $at, 0x3fe0
/* 4EE0 80029AE0 44811800 */  mtc1      $at, $f3
/* 4EE4 80029AE4 44801000 */  mtc1      $zero, $f2
/* 4EE8 80029AE8 46006021 */  cvt.d.s   $f0, $f12
/* 4EEC 80029AEC 46220000 */  add.d     $f0, $f0, $f2
/* 4EF0 80029AF0 4620010D */  trunc.w.d $f4, $f0
/* 4EF4 80029AF4 44022000 */  mfc1      $v0, $f4
/* 4EF8 80029AF8 03E00008 */  jr        $ra
/* 4EFC 80029AFC 00000000 */   nop
.L80029B00:
/* 4F00 80029B00 3C013FE0 */  lui       $at, 0x3fe0
/* 4F04 80029B04 44810800 */  mtc1      $at, $f1
/* 4F08 80029B08 44800000 */  mtc1      $zero, $f0
/* 4F0C 80029B0C 00000000 */  nop
/* 4F10 80029B10 46220001 */  sub.d     $f0, $f0, $f2
/* 4F14 80029B14 4620010D */  trunc.w.d $f4, $f0
/* 4F18 80029B18 44022000 */  mfc1      $v0, $f4
/* 4F1C 80029B1C 03E00008 */  jr        $ra
/* 4F20 80029B20 00021023 */   negu     $v0, $v0
