.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024069C_B5E94C
/* B5E94C 8024069C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B5E950 802406A0 AFBF0010 */  sw        $ra, 0x10($sp)
/* B5E954 802406A4 8C82000C */  lw        $v0, 0xc($a0)
/* B5E958 802406A8 0C0B1EAF */  jal       evt_get_variable
/* B5E95C 802406AC 8C450000 */   lw       $a1, ($v0)
/* B5E960 802406B0 0C0B95A4 */  jal       entity_upgrade_block_hide_content
/* B5E964 802406B4 0040202D */   daddu    $a0, $v0, $zero
/* B5E968 802406B8 8FBF0010 */  lw        $ra, 0x10($sp)
/* B5E96C 802406BC 24020002 */  addiu     $v0, $zero, 2
/* B5E970 802406C0 03E00008 */  jr        $ra
/* B5E974 802406C4 27BD0018 */   addiu    $sp, $sp, 0x18
