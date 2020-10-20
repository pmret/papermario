.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240090
/* AB6320 80240090 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* AB6324 80240094 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* AB6328 80240098 9062007E */  lbu       $v0, 0x7e($v1)
/* AB632C 8024009C 34420001 */  ori       $v0, $v0, 1
/* AB6330 802400A0 A062007E */  sb        $v0, 0x7e($v1)
/* AB6334 802400A4 3C038011 */  lui       $v1, %hi(gPlayerData)
/* AB6338 802400A8 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* AB633C 802400AC 80620012 */  lb        $v0, 0x12($v1)
/* AB6340 802400B0 AC820084 */  sw        $v0, 0x84($a0)
/* AB6344 802400B4 2402000B */  addiu     $v0, $zero, 0xb
/* AB6348 802400B8 A0620012 */  sb        $v0, 0x12($v1)
/* AB634C 802400BC 03E00008 */  jr        $ra
/* AB6350 802400C0 24020002 */   addiu    $v0, $zero, 2
