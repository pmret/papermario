.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055050
/* 30450 80055050 24020001 */  addiu     $v0, $zero, 1
/* 30454 80055054 3C018008 */  lui       $at, 0x8008
/* 30458 80055058 A4228DB4 */  sh        $v0, -0x724c($at)
/* 3045C 8005505C 3C018008 */  lui       $at, 0x8008
/* 30460 80055060 03E00008 */  jr        $ra
/* 30464 80055064 AC208DB0 */   sw       $zero, -0x7250($at)
