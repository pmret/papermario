.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241290_865DD0
/* 865DD0 80241290 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 865DD4 80241294 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 865DD8 80241298 8C420010 */  lw        $v0, 0x10($v0)
/* 865DDC 8024129C 30424000 */  andi      $v0, $v0, 0x4000
/* 865DE0 802412A0 0002102B */  sltu      $v0, $zero, $v0
/* 865DE4 802412A4 03E00008 */  jr        $ra
/* 865DE8 802412A8 00021040 */   sll      $v0, $v0, 1
