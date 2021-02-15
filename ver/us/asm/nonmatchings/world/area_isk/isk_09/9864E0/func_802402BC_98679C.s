.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402BC_98679C
/* 98679C 802402BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9867A0 802402C0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9867A4 802402C4 0C04417A */  jal       get_entity_by_index
/* 9867A8 802402C8 8C840084 */   lw       $a0, 0x84($a0)
/* 9867AC 802402CC 8C440040 */  lw        $a0, 0x40($v0)
/* 9867B0 802402D0 24030001 */  addiu     $v1, $zero, 1
/* 9867B4 802402D4 A0830030 */  sb        $v1, 0x30($a0)
/* 9867B8 802402D8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9867BC 802402DC 24020002 */  addiu     $v0, $zero, 2
/* 9867C0 802402E0 03E00008 */  jr        $ra
/* 9867C4 802402E4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 9867C8 802402E8 00000000 */  nop
/* 9867CC 802402EC 00000000 */  nop
