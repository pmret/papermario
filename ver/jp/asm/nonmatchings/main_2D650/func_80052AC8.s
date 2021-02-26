.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80052AC8
/* 2DEC8 80052AC8 9082003D */  lbu       $v0, 0x3d($a0)
/* 2DECC 80052ACC 34420020 */  ori       $v0, $v0, 0x20
/* 2DED0 80052AD0 03E00008 */  jr        $ra
/* 2DED4 80052AD4 A082003D */   sb       $v0, 0x3d($a0)
/* 2DED8 80052AD8 00000000 */  nop
/* 2DEDC 80052ADC 00000000 */  nop
