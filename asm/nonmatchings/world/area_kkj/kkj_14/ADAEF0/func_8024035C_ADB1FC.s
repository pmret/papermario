.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024035C_ADB1FC
/* ADB1FC 8024035C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* ADB200 80240360 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* ADB204 80240364 9043007E */  lbu       $v1, 0x7e($v0)
/* ADB208 80240368 306300FE */  andi      $v1, $v1, 0xfe
/* ADB20C 8024036C A043007E */  sb        $v1, 0x7e($v0)
/* ADB210 80240370 90820087 */  lbu       $v0, 0x87($a0)
/* ADB214 80240374 3C018011 */  lui       $at, 0x8011
/* ADB218 80240378 A022F2A2 */  sb        $v0, -0xd5e($at)
/* ADB21C 8024037C 03E00008 */  jr        $ra
/* ADB220 80240380 24020002 */   addiu    $v0, $zero, 2
