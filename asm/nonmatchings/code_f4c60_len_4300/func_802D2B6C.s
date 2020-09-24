.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D2B6C
/* F751C 802D2B6C 3C038011 */  lui       $v1, 0x8011
/* F7520 802D2B70 2463EFC8 */  addiu     $v1, $v1, -0x1038
/* F7524 802D2B74 8C620004 */  lw        $v0, 4($v1)
/* F7528 802D2B78 34420004 */  ori       $v0, $v0, 4
/* F752C 802D2B7C AC620004 */  sw        $v0, 4($v1)
/* F7530 802D2B80 03E00008 */  jr        $ra
/* F7534 802D2B84 24020002 */   addiu    $v0, $zero, 2
