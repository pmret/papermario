.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FCB4
/* 2B0B4 8004FCB4 908200D4 */  lbu       $v0, 0xd4($a0)
/* 2B0B8 8004FCB8 3042007F */  andi      $v0, $v0, 0x7f
/* 2B0BC 8004FCBC A0A2004A */  sb        $v0, 0x4a($a1)
/* 2B0C0 8004FCC0 908200D5 */  lbu       $v0, 0xd5($a0)
/* 2B0C4 8004FCC4 3042007F */  andi      $v0, $v0, 0x7f
/* 2B0C8 8004FCC8 03E00008 */  jr        $ra
/* 2B0CC 8004FCCC A0A20057 */   sb       $v0, 0x57($a1)
