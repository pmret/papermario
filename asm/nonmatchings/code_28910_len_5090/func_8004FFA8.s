.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FFA8
/* 2B3A8 8004FFA8 908200D4 */  lbu       $v0, 0xd4($a0)
/* 2B3AC 8004FFAC 03E00008 */  jr        $ra
/* 2B3B0 8004FFB0 A0A20048 */   sb       $v0, 0x48($a1)
