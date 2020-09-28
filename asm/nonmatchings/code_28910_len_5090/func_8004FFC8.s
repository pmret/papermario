.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FFC8
/* 2B3C8 8004FFC8 908200D4 */  lbu       $v0, 0xd4($a0)
/* 2B3CC 8004FFCC A4A2003A */  sh        $v0, 0x3a($a1)
/* 2B3D0 8004FFD0 908200D5 */  lbu       $v0, 0xd5($a0)
/* 2B3D4 8004FFD4 A0A20055 */  sb        $v0, 0x55($a1)
/* 2B3D8 8004FFD8 908200D6 */  lbu       $v0, 0xd6($a0)
/* 2B3DC 8004FFDC 03E00008 */  jr        $ra
/* 2B3E0 8004FFE0 A0A20056 */   sb       $v0, 0x56($a1)
