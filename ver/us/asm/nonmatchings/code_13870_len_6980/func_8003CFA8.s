.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003CFA8
/* 183A8 8003CFA8 00852021 */  addu      $a0, $a0, $a1
/* 183AC 8003CFAC 03E00008 */  jr        $ra
/* 183B0 8003CFB0 A0800330 */   sb       $zero, 0x330($a0)
