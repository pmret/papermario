.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240384_ADB224
/* ADB224 80240384 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* ADB228 80240388 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* ADB22C 8024038C 9062007E */  lbu       $v0, 0x7e($v1)
/* ADB230 80240390 34420004 */  ori       $v0, $v0, 4
/* ADB234 80240394 A062007E */  sb        $v0, 0x7e($v1)
/* ADB238 80240398 03E00008 */  jr        $ra
/* ADB23C 8024039C 24020002 */   addiu    $v0, $zero, 2
