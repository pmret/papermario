.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024030C_AE589C
/* AE589C 8024030C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* AE58A0 80240310 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* AE58A4 80240314 9043007E */  lbu       $v1, 0x7e($v0)
/* AE58A8 80240318 306300FE */  andi      $v1, $v1, 0xfe
/* AE58AC 8024031C A043007E */  sb        $v1, 0x7e($v0)
/* AE58B0 80240320 90820087 */  lbu       $v0, 0x87($a0)
/* AE58B4 80240324 3C018011 */  lui       $at, %hi(gPlayerData+0x12)
/* AE58B8 80240328 A022F2A2 */  sb        $v0, %lo(gPlayerData+0x12)($at)
/* AE58BC 8024032C 03E00008 */  jr        $ra
/* AE58C0 80240330 24020002 */   addiu    $v0, $zero, 2
/* AE58C4 80240334 00000000 */  nop
/* AE58C8 80240338 00000000 */  nop
/* AE58CC 8024033C 00000000 */  nop
