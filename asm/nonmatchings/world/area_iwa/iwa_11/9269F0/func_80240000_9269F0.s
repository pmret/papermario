.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_9269F0
/* 9269F0 80240000 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 9269F4 80240004 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 9269F8 80240008 8C420010 */  lw        $v0, 0x10($v0)
/* 9269FC 8024000C 3042C000 */  andi      $v0, $v0, 0xc000
/* 926A00 80240010 0002102B */  sltu      $v0, $zero, $v0
/* 926A04 80240014 03E00008 */  jr        $ra
/* 926A08 80240018 00021040 */   sll      $v0, $v0, 1
/* 926A0C 8024001C 00000000 */  nop
