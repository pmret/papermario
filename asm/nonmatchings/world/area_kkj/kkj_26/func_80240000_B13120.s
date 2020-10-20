.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_B13120
/* B13120 80240000 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* B13124 80240004 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* B13128 80240008 9043007E */  lbu       $v1, 0x7e($v0)
/* B1312C 8024000C 306300FE */  andi      $v1, $v1, 0xfe
/* B13130 80240010 A043007E */  sb        $v1, 0x7e($v0)
/* B13134 80240014 90820087 */  lbu       $v0, 0x87($a0)
/* B13138 80240018 3C018011 */  lui       $at, 0x8011
/* B1313C 8024001C A022F2A2 */  sb        $v0, -0xd5e($at)
/* B13140 80240020 03E00008 */  jr        $ra
/* B13144 80240024 24020002 */   addiu    $v0, $zero, 2
/* B13148 80240028 00000000 */  nop       
/* B1314C 8024002C 00000000 */  nop       
