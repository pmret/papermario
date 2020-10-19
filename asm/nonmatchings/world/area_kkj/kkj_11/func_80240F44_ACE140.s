.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F44_ACF084
/* ACF084 80240F44 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* ACF088 80240F48 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* ACF08C 80240F4C 9062007E */  lbu       $v0, 0x7e($v1)
/* ACF090 80240F50 34420008 */  ori       $v0, $v0, 8
/* ACF094 80240F54 A062007E */  sb        $v0, 0x7e($v1)
/* ACF098 80240F58 03E00008 */  jr        $ra
/* ACF09C 80240F5C 24020002 */   addiu    $v0, $zero, 2
