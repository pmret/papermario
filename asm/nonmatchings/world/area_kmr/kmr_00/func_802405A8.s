.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405A8
/* 8AC538 802405A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8AC53C 802405AC 0000202D */  daddu     $a0, $zero, $zero
/* 8AC540 802405B0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8AC544 802405B4 0C015564 */  jal       func_80055590
/* 8AC548 802405B8 240507D0 */   addiu    $a1, $zero, 0x7d0
/* 8AC54C 802405BC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8AC550 802405C0 24020002 */  addiu     $v0, $zero, 2
/* 8AC554 802405C4 03E00008 */  jr        $ra
/* 8AC558 802405C8 27BD0018 */   addiu    $sp, $sp, 0x18
