.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FC78
/* 2B078 8004FC78 908200D4 */  lbu       $v0, 0xd4($a0)
/* 2B07C 8004FC7C A4A2003A */  sh        $v0, 0x3a($a1)
/* 2B080 8004FC80 908200D5 */  lbu       $v0, 0xd5($a0)
/* 2B084 8004FC84 A0A20055 */  sb        $v0, 0x55($a1)
/* 2B088 8004FC88 908200D6 */  lbu       $v0, 0xd6($a0)
/* 2B08C 8004FC8C 03E00008 */  jr        $ra
/* 2B090 8004FC90 A0A20056 */   sb       $v0, 0x56($a1)
