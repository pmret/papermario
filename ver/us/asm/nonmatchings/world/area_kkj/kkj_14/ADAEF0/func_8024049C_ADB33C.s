.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024049C_ADB33C
/* ADB33C 8024049C 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* ADB340 802404A0 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* ADB344 802404A4 9062007E */  lbu       $v0, 0x7e($v1)
/* ADB348 802404A8 304200EF */  andi      $v0, $v0, 0xef
/* ADB34C 802404AC A062007E */  sb        $v0, 0x7e($v1)
/* ADB350 802404B0 03E00008 */  jr        $ra
/* ADB354 802404B4 24020002 */   addiu    $v0, $zero, 2
/* ADB358 802404B8 00000000 */  nop
/* ADB35C 802404BC 00000000 */  nop
