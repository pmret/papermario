.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241588_D51578
/* D51578 80241588 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D5157C 8024158C AFBF0010 */  sw        $ra, 0x10($sp)
/* D51580 80241590 0C04417A */  jal       get_entity_by_index
/* D51584 80241594 8C840084 */   lw       $a0, 0x84($a0)
/* D51588 80241598 0040182D */  daddu     $v1, $v0, $zero
/* D5158C 8024159C 8C640000 */  lw        $a0, ($v1)
/* D51590 802415A0 3C050010 */  lui       $a1, 0x10
/* D51594 802415A4 00852025 */  or        $a0, $a0, $a1
/* D51598 802415A8 AC640000 */  sw        $a0, ($v1)
/* D5159C 802415AC 8FBF0010 */  lw        $ra, 0x10($sp)
/* D515A0 802415B0 24020002 */  addiu     $v0, $zero, 2
/* D515A4 802415B4 03E00008 */  jr        $ra
/* D515A8 802415B8 27BD0018 */   addiu    $sp, $sp, 0x18
