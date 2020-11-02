.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_B150B0
/* B150B0 80240000 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* B150B4 80240004 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* B150B8 80240008 9043007E */  lbu       $v1, 0x7e($v0)
/* B150BC 8024000C 306300FE */  andi      $v1, $v1, 0xfe
/* B150C0 80240010 A043007E */  sb        $v1, 0x7e($v0)
/* B150C4 80240014 90820087 */  lbu       $v0, 0x87($a0)
/* B150C8 80240018 3C018011 */  lui       $at, %hi(gPlayerData+0x12)
/* B150CC 8024001C A022F2A2 */  sb        $v0, %lo(gPlayerData+0x12)($at)
/* B150D0 80240020 03E00008 */  jr        $ra
/* B150D4 80240024 24020002 */   addiu    $v0, $zero, 2
/* B150D8 80240028 00000000 */  nop       
/* B150DC 8024002C 00000000 */  nop       
