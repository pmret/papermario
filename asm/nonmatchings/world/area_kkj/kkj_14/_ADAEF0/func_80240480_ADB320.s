.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240480_ADB320
/* ADB320 80240480 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* ADB324 80240484 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* ADB328 80240488 9062007E */  lbu       $v0, 0x7e($v1)
/* ADB32C 8024048C 34420010 */  ori       $v0, $v0, 0x10
/* ADB330 80240490 A062007E */  sb        $v0, 0x7e($v1)
/* ADB334 80240494 03E00008 */  jr        $ra
/* ADB338 80240498 24020002 */   addiu    $v0, $zero, 2
