.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC3A0_E2ECD0
/* E2ECD0 802BC3A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2ECD4 802BC3A4 AFBF0010 */  sw        $ra, 0x10($sp)
/* E2ECD8 802BC3A8 0C038069 */  jal       enable_player_input
/* E2ECDC 802BC3AC 00000000 */   nop      
/* E2ECE0 802BC3B0 0C03802C */  jal       enable_player_shadow
/* E2ECE4 802BC3B4 00000000 */   nop      
/* E2ECE8 802BC3B8 0C039769 */  jal       set_action_state
/* E2ECEC 802BC3BC 2404001E */   addiu    $a0, $zero, 0x1e
/* E2ECF0 802BC3C0 8FBF0010 */  lw        $ra, 0x10($sp)
/* E2ECF4 802BC3C4 03E00008 */  jr        $ra
/* E2ECF8 802BC3C8 27BD0018 */   addiu    $sp, $sp, 0x18
