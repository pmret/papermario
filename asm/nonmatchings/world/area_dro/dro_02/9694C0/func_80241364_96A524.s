.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241364_96A524
/* 96A524 80241364 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 96A528 80241368 3C058024 */  lui       $a1, %hi(D_802412F8)
/* 96A52C 8024136C 24A512F8 */  addiu     $a1, $a1, %lo(D_802412F8)
/* 96A530 80241370 AFBF0010 */  sw        $ra, 0x10($sp)
/* 96A534 80241374 0C048C8F */  jal       bind_dynamic_entity_7
/* 96A538 80241378 0000202D */   daddu    $a0, $zero, $zero
/* 96A53C 8024137C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 96A540 80241380 3C018025 */  lui       $at, %hi(gPauseMenuCursorPosY)
/* 96A544 80241384 AC22EFA0 */  sw        $v0, %lo(gPauseMenuCursorPosY)($at)
/* 96A548 80241388 24020002 */  addiu     $v0, $zero, 2
/* 96A54C 8024138C 03E00008 */  jr        $ra
/* 96A550 80241390 27BD0018 */   addiu    $sp, $sp, 0x18
