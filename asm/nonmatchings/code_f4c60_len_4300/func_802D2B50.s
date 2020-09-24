.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D2B50
/* F7500 802D2B50 3C038011 */  lui       $v1, 0x8011
/* F7504 802D2B54 2463EFC8 */  addiu     $v1, $v1, -0x1038
/* F7508 802D2B58 8C620004 */  lw        $v0, 4($v1)
/* F750C 802D2B5C 34420008 */  ori       $v0, $v0, 8
/* F7510 802D2B60 AC620004 */  sw        $v0, 4($v1)
/* F7514 802D2B64 03E00008 */  jr        $ra
/* F7518 802D2B68 24020002 */   addiu    $v0, $zero, 2
