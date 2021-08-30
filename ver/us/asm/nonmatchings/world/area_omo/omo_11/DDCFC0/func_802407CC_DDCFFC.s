.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407CC_DDCFFC
/* DDCFFC 802407CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DDD000 802407D0 AFBF0010 */  sw        $ra, 0x10($sp)
/* DDD004 802407D4 8C82000C */  lw        $v0, 0xc($a0)
/* DDD008 802407D8 0C0B1EAF */  jal       evt_get_variable
/* DDD00C 802407DC 8C450000 */   lw       $a1, ($v0)
/* DDD010 802407E0 0C0B95A4 */  jal       entity_upgrade_block_hide_content
/* DDD014 802407E4 0040202D */   daddu    $a0, $v0, $zero
/* DDD018 802407E8 8FBF0010 */  lw        $ra, 0x10($sp)
/* DDD01C 802407EC 24020002 */  addiu     $v0, $zero, 2
/* DDD020 802407F0 03E00008 */  jr        $ra
/* DDD024 802407F4 27BD0018 */   addiu    $sp, $sp, 0x18
