.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80056D34
/* 32134 80056D34 24020001 */  addiu     $v0, $zero, 1
/* 32138 80056D38 3C018008 */  lui       $at, 0x8008
/* 3213C 80056D3C 03E00008 */  jr        $ra
/* 32140 80056D40 A0228E58 */   sb       $v0, -0x71a8($at)
