.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F44
/* ACBA64 80240F44 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* ACBA68 80240F48 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* ACBA6C 80240F4C 9062007E */  lbu       $v0, 0x7e($v1)
/* ACBA70 80240F50 34420008 */  ori       $v0, $v0, 8
/* ACBA74 80240F54 A062007E */  sb        $v0, 0x7e($v1)
/* ACBA78 80240F58 03E00008 */  jr        $ra
/* ACBA7C 80240F5C 24020002 */   addiu    $v0, $zero, 2
