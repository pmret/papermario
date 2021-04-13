.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8006D7C0
/* 48BC0 8006D7C0 3C02A480 */  lui       $v0, 0xa480
/* 48BC4 8006D7C4 34420018 */  ori       $v0, $v0, 0x18
/* 48BC8 8006D7C8 8C420000 */  lw        $v0, ($v0)
/* 48BCC 8006D7CC 30420003 */  andi      $v0, $v0, 3
/* 48BD0 8006D7D0 03E00008 */  jr        $ra
/* 48BD4 8006D7D4 0002102B */   sltu     $v0, $zero, $v0
/* 48BD8 8006D7D8 00000000 */  nop
/* 48BDC 8006D7DC 00000000 */  nop
