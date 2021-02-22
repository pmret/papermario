.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B48_8EC968
/* 8EC968 80240B48 AC80007C */  sw        $zero, 0x7c($a0)
/* 8EC96C 80240B4C 03E00008 */  jr        $ra
/* 8EC970 80240B50 24020002 */   addiu    $v0, $zero, 2
