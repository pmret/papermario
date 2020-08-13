.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80254610
/* 182EF0 80254610 8C8301F4 */  lw    $v1, 0x1f4($a0)
/* 182EF4 80254614 8C620094 */  lw    $v0, 0x94($v1)
/* 182EF8 80254618 10400008 */  beqz  $v0, .L8025463C
/* 182EFC 8025461C 00000000 */   nop   
/* 182F00 80254620 8C620000 */  lw    $v0, ($v1)
/* 182F04 80254624 30420002 */  andi  $v0, $v0, 2
/* 182F08 80254628 14400004 */  bnez  $v0, .L8025463C
/* 182F0C 8025462C 24020014 */   addiu $v0, $zero, 0x14
/* 182F10 80254630 8C6300C0 */  lw    $v1, 0xc0($v1)
/* 182F14 80254634 A06007DB */  sb    $zero, 0x7db($v1)
/* 182F18 80254638 A06208AC */  sb    $v0, 0x8ac($v1)
.L8025463C:
/* 182F1C 8025463C 03E00008 */  jr    $ra
/* 182F20 80254640 00000000 */   nop   

