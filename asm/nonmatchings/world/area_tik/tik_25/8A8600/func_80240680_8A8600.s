.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240680_8A8600
/* 8A8600 80240680 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8A8604 80240684 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8A8608 80240688 0C04417A */  jal       get_entity_by_index
/* 8A860C 8024068C 8C840084 */   lw       $a0, 0x84($a0)
/* 8A8610 80240690 8C440040 */  lw        $a0, 0x40($v0)
/* 8A8614 80240694 24030001 */  addiu     $v1, $zero, 1
/* 8A8618 80240698 A0830030 */  sb        $v1, 0x30($a0)
/* 8A861C 8024069C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8A8620 802406A0 24020002 */  addiu     $v0, $zero, 2
/* 8A8624 802406A4 03E00008 */  jr        $ra
/* 8A8628 802406A8 27BD0018 */   addiu    $sp, $sp, 0x18
