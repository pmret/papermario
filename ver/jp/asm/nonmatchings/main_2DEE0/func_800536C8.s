.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800536C8
/* 2EAC8 800536C8 A480000A */  sh        $zero, 0xa($a0)
/* 2EACC 800536CC AC800004 */  sw        $zero, 4($a0)
/* 2EAD0 800536D0 03E00008 */  jr        $ra
/* 2EAD4 800536D4 AC80000C */   sw       $zero, 0xc($a0)
