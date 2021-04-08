.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80053020
/* 2E420 80053020 24022010 */  addiu     $v0, $zero, 0x2010
/* 2E424 80053024 A4820000 */  sh        $v0, ($a0)
/* 2E428 80053028 240212C0 */  addiu     $v0, $zero, 0x12c0
/* 2E42C 8005302C A4820002 */  sh        $v0, 2($a0)
/* 2E430 80053030 2402007F */  addiu     $v0, $zero, 0x7f
/* 2E434 80053034 A0820004 */  sb        $v0, 4($a0)
/* 2E438 80053038 24020040 */  addiu     $v0, $zero, 0x40
/* 2E43C 8005303C A0820005 */  sb        $v0, 5($a0)
/* 2E440 80053040 A0800006 */  sb        $zero, 6($a0)
/* 2E444 80053044 A0800007 */  sb        $zero, 7($a0)
/* 2E448 80053048 A0800008 */  sb        $zero, 8($a0)
/* 2E44C 8005304C A0800009 */  sb        $zero, 9($a0)
/* 2E450 80053050 03E00008 */  jr        $ra
/* 2E454 80053054 A080000A */   sb       $zero, 0xa($a0)
