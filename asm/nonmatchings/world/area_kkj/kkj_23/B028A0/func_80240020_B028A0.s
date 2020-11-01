.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240020_B028A0
/* B028A0 80240020 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* B028A4 80240024 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* B028A8 80240028 9043007E */  lbu       $v1, 0x7e($v0)
/* B028AC 8024002C 306300FE */  andi      $v1, $v1, 0xfe
/* B028B0 80240030 A043007E */  sb        $v1, 0x7e($v0)
/* B028B4 80240034 90820087 */  lbu       $v0, 0x87($a0)
/* B028B8 80240038 3C018011 */  lui       $at, %hi(gPlayerData+0x12)
/* B028BC 8024003C A022F2A2 */  sb        $v0, %lo(gPlayerData+0x12)($at)
/* B028C0 80240040 03E00008 */  jr        $ra
/* B028C4 80240044 24020002 */   addiu    $v0, $zero, 2
