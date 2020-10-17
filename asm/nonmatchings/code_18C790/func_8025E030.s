.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025E030
/* 18C910 8025E030 3C02802A */  lui       $v0, 0x802a
/* 18C914 8025E034 8C42FB78 */  lw        $v0, -0x488($v0)
/* 18C918 8025E038 0002102B */  sltu      $v0, $zero, $v0
/* 18C91C 8025E03C 03E00008 */  jr        $ra
/* 18C920 8025E040 00021040 */   sll      $v0, $v0, 1
