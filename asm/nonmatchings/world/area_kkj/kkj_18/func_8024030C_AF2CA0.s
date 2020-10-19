.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024030C_AF2FAC
/* AF2FAC 8024030C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* AF2FB0 80240310 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* AF2FB4 80240314 9043007E */  lbu       $v1, 0x7e($v0)
/* AF2FB8 80240318 306300FE */  andi      $v1, $v1, 0xfe
/* AF2FBC 8024031C A043007E */  sb        $v1, 0x7e($v0)
/* AF2FC0 80240320 90820087 */  lbu       $v0, 0x87($a0)
/* AF2FC4 80240324 3C018011 */  lui       $at, 0x8011
/* AF2FC8 80240328 A022F2A2 */  sb        $v0, -0xd5e($at)
/* AF2FCC 8024032C 03E00008 */  jr        $ra
/* AF2FD0 80240330 24020002 */   addiu    $v0, $zero, 2
/* AF2FD4 80240334 00000000 */  nop       
/* AF2FD8 80240338 00000000 */  nop       
/* AF2FDC 8024033C 00000000 */  nop       
