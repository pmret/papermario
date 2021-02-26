.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003CC68
/* 18068 8003CC68 00852021 */  addu      $a0, $a0, $a1
/* 1806C 8003CC6C 03E00008 */  jr        $ra
/* 18070 8003CC70 A0800330 */   sb       $zero, 0x330($a0)
