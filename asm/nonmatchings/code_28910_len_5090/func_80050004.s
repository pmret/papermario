.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050004
/* 2B404 80050004 908200D4 */  lbu       $v0, 0xd4($a0)
/* 2B408 80050008 3042007F */  andi      $v0, $v0, 0x7f
/* 2B40C 8005000C A0A2004A */  sb        $v0, 0x4a($a1)
/* 2B410 80050010 908200D5 */  lbu       $v0, 0xd5($a0)
/* 2B414 80050014 3042007F */  andi      $v0, $v0, 0x7f
/* 2B418 80050018 03E00008 */  jr        $ra
/* 2B41C 8005001C A0A20057 */   sb       $v0, 0x57($a1)
