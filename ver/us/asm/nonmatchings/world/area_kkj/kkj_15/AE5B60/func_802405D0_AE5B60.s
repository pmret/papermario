.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405D0_AE5B60
/* AE5B60 802405D0 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* AE5B64 802405D4 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* AE5B68 802405D8 9062007E */  lbu       $v0, 0x7e($v1)
/* AE5B6C 802405DC 34420010 */  ori       $v0, $v0, 0x10
/* AE5B70 802405E0 A062007E */  sb        $v0, 0x7e($v1)
/* AE5B74 802405E4 03E00008 */  jr        $ra
/* AE5B78 802405E8 24020002 */   addiu    $v0, $zero, 2
