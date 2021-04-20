.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241690_E13DF0
/* E13DF0 80241690 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E13DF4 80241694 0000202D */  daddu     $a0, $zero, $zero
/* E13DF8 80241698 AFBF0014 */  sw        $ra, 0x14($sp)
/* E13DFC 8024169C 0C00FB3A */  jal       get_enemy
/* E13E00 802416A0 AFB00010 */   sw       $s0, 0x10($sp)
/* E13E04 802416A4 8C500080 */  lw        $s0, 0x80($v0)
/* E13E08 802416A8 0C048D70 */  jal       free_dynamic_entity
/* E13E0C 802416AC 8E040000 */   lw       $a0, ($s0)
/* E13E10 802416B0 0C05123D */  jal       free_icon
/* E13E14 802416B4 8E040004 */   lw       $a0, 4($s0)
/* E13E18 802416B8 8FBF0014 */  lw        $ra, 0x14($sp)
/* E13E1C 802416BC 8FB00010 */  lw        $s0, 0x10($sp)
/* E13E20 802416C0 24020002 */  addiu     $v0, $zero, 2
/* E13E24 802416C4 03E00008 */  jr        $ra
/* E13E28 802416C8 27BD0018 */   addiu    $sp, $sp, 0x18
