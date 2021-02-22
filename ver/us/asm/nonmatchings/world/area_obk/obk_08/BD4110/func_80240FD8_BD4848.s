.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FD8_BD4848
/* BD4848 80240FD8 AC800074 */  sw        $zero, 0x74($a0)
/* BD484C 80240FDC 03E00008 */  jr        $ra
/* BD4850 80240FE0 24020002 */   addiu    $v0, $zero, 2
