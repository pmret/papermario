.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel signF
/* 004E7C 80029A7C 44801000 */  mtc1  $zero, $f2
/* 004E80 80029A80 00000000 */  nop   
/* 004E84 80029A84 460C103C */  c.lt.s $f2, $f12
/* 004E88 80029A88 00000000 */  nop   
/* 004E8C 80029A8C 45010009 */  bc1t  .L80029AB4
/* 004E90 80029A90 00000000 */   nop   
/* 004E94 80029A94 3C01BF80 */  lui   $at, 0xbf80
/* 004E98 80029A98 44810000 */  mtc1  $at, $f0
/* 004E9C 80029A9C 4602603C */  c.lt.s $f12, $f2
/* 004EA0 80029AA0 00000000 */  nop   
/* 004EA4 80029AA4 45010005 */  bc1t  .L80029ABC
/* 004EA8 80029AA8 00000000 */   nop   
/* 004EAC 80029AAC 03E00008 */  jr    $ra
/* 004EB0 80029AB0 46001006 */   mov.s $f0, $f2

.L80029AB4:
/* 004EB4 80029AB4 3C013F80 */  lui   $at, 0x3f80
/* 004EB8 80029AB8 44810000 */  mtc1  $at, $f0
.L80029ABC:
/* 004EBC 80029ABC 03E00008 */  jr    $ra
/* 004EC0 80029AC0 00000000 */   nop   

