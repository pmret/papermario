.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80029A3C
/* 4E3C 80029A3C 44801000 */  mtc1      $zero, $f2
/* 4E40 80029A40 00000000 */  nop
/* 4E44 80029A44 460C103C */  c.lt.s    $f2, $f12
/* 4E48 80029A48 00000000 */  nop
/* 4E4C 80029A4C 45010009 */  bc1t      .L80029A74
/* 4E50 80029A50 00000000 */   nop
/* 4E54 80029A54 3C01BF80 */  lui       $at, 0xbf80
/* 4E58 80029A58 44810000 */  mtc1      $at, $f0
/* 4E5C 80029A5C 4602603C */  c.lt.s    $f12, $f2
/* 4E60 80029A60 00000000 */  nop
/* 4E64 80029A64 45010005 */  bc1t      .L80029A7C
/* 4E68 80029A68 00000000 */   nop
/* 4E6C 80029A6C 03E00008 */  jr        $ra
/* 4E70 80029A70 46001006 */   mov.s    $f0, $f2
.L80029A74:
/* 4E74 80029A74 3C013F80 */  lui       $at, 0x3f80
/* 4E78 80029A78 44810000 */  mtc1      $at, $f0
.L80029A7C:
/* 4E7C 80029A7C 03E00008 */  jr        $ra
/* 4E80 80029A80 00000000 */   nop
