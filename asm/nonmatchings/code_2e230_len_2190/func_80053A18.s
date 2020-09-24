.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80053A18
/* 2EE18 80053A18 A480000A */  sh        $zero, 0xa($a0)
/* 2EE1C 80053A1C AC800004 */  sw        $zero, 4($a0)
/* 2EE20 80053A20 03E00008 */  jr        $ra
/* 2EE24 80053A24 AC80000C */   sw       $zero, 0xc($a0)
