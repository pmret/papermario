.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240784_B03004
/* B03004 80240784 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* B03008 80240788 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* B0300C 8024078C 9062007E */  lbu       $v0, 0x7e($v1)
/* B03010 80240790 34420008 */  ori       $v0, $v0, 8
/* B03014 80240794 A062007E */  sb        $v0, 0x7e($v1)
/* B03018 80240798 03E00008 */  jr        $ra
/* B0301C 8024079C 24020002 */   addiu    $v0, $zero, 2
