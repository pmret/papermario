.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240298_8FF118
/* 8FF118 80240298 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 8FF11C 8024029C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 8FF120 802402A0 8C420010 */  lw        $v0, 0x10($v0)
/* 8FF124 802402A4 30429000 */  andi      $v0, $v0, 0x9000
/* 8FF128 802402A8 0002102B */  sltu      $v0, $zero, $v0
/* 8FF12C 802402AC 03E00008 */  jr        $ra
/* 8FF130 802402B0 00021040 */   sll      $v0, $v0, 1
