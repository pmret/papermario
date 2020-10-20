.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405EC_AE5B7C
/* AE5B7C 802405EC 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* AE5B80 802405F0 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* AE5B84 802405F4 9062007E */  lbu       $v0, 0x7e($v1)
/* AE5B88 802405F8 304200EF */  andi      $v0, $v0, 0xef
/* AE5B8C 802405FC A062007E */  sb        $v0, 0x7e($v1)
/* AE5B90 80240600 03E00008 */  jr        $ra
/* AE5B94 80240604 24020002 */   addiu    $v0, $zero, 2
/* AE5B98 80240608 00000000 */  nop       
/* AE5B9C 8024060C 00000000 */  nop       
