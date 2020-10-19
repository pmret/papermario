.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EF4_AEE304
/* AEE304 80240EF4 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* AEE308 80240EF8 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* AEE30C 80240EFC 9062007E */  lbu       $v0, 0x7e($v1)
/* AEE310 80240F00 34420008 */  ori       $v0, $v0, 8
/* AEE314 80240F04 A062007E */  sb        $v0, 0x7e($v1)
/* AEE318 80240F08 03E00008 */  jr        $ra
/* AEE31C 80240F0C 24020002 */   addiu    $v0, $zero, 2
