.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FFE4
/* 2B3E4 8004FFE4 908200D4 */  lbu       $v0, 0xd4($a0)
/* 2B3E8 8004FFE8 03E00008 */  jr        $ra
/* 2B3EC 8004FFEC A0A20055 */   sb       $v0, 0x55($a1)
