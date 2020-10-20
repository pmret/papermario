.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D70_8EDB90
/* 8EDB90 80241D70 3C028016 */  lui       $v0, 0x8016
/* 8EDB94 80241D74 8442A552 */  lh        $v0, -0x5aae($v0)
/* 8EDB98 80241D78 AC820084 */  sw        $v0, 0x84($a0)
/* 8EDB9C 80241D7C 03E00008 */  jr        $ra
/* 8EDBA0 80241D80 24020002 */   addiu    $v0, $zero, 2
