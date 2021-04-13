.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80053058
/* 2E458 80053058 24022010 */  addiu     $v0, $zero, 0x2010
/* 2E45C 8005305C A4820000 */  sh        $v0, ($a0)
/* 2E460 80053060 2402007F */  addiu     $v0, $zero, 0x7f
/* 2E464 80053064 A0820002 */  sb        $v0, 2($a0)
/* 2E468 80053068 24020040 */  addiu     $v0, $zero, 0x40
/* 2E46C 8005306C A0820003 */  sb        $v0, 3($a0)
/* 2E470 80053070 A0800004 */  sb        $zero, 4($a0)
/* 2E474 80053074 A0800005 */  sb        $zero, 5($a0)
/* 2E478 80053078 03E00008 */  jr        $ra
/* 2E47C 8005307C A0800006 */   sb       $zero, 6($a0)
