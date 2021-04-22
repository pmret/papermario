.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC0B8_E2E9E8
/* E2E9E8 802BC0B8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2E9EC 802BC0BC AFBF0010 */  sw        $ra, 0x10($sp)
/* E2E9F0 802BC0C0 84840014 */  lh        $a0, 0x14($a0)
/* E2E9F4 802BC0C4 3C050000 */  lui       $a1, 0
/* E2E9F8 802BC0C8 24A50060 */  addiu     $a1, $a1, 0x60
/* E2E9FC 802BC0CC 0C048052 */  jal       play_model_animation
/* E2EA00 802BC0D0 00000000 */   nop
/* E2EA04 802BC0D4 0C03805E */  jal       disable_player_input
/* E2EA08 802BC0D8 00000000 */   nop
/* E2EA0C 802BC0DC 0C038039 */  jal       disable_player_shadow
/* E2EA10 802BC0E0 00000000 */   nop
/* E2EA14 802BC0E4 8FBF0010 */  lw        $ra, 0x10($sp)
/* E2EA18 802BC0E8 03E00008 */  jr        $ra
/* E2EA1C 802BC0EC 27BD0018 */   addiu    $sp, $sp, 0x18
