.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1518_79C4B8
/* 79C4B8 802A1518 8C830084 */  lw        $v1, 0x84($a0)
/* 79C4BC 802A151C 8C620004 */  lw        $v0, 4($v1)
/* 79C4C0 802A1520 24420001 */  addiu     $v0, $v0, 1
/* 79C4C4 802A1524 AC620004 */  sw        $v0, 4($v1)
/* 79C4C8 802A1528 03E00008 */  jr        $ra
/* 79C4CC 802A152C 24020002 */   addiu    $v0, $zero, 2
