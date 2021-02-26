.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FC94
/* 2B094 8004FC94 908200D4 */  lbu       $v0, 0xd4($a0)
/* 2B098 8004FC98 03E00008 */  jr        $ra
/* 2B09C 8004FC9C A0A20055 */   sb       $v0, 0x55($a1)
