.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC274_E2EBA4
/* E2EBA4 802BC274 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2EBA8 802BC278 AFB00010 */  sw        $s0, 0x10($sp)
/* E2EBAC 802BC27C 0080802D */  daddu     $s0, $a0, $zero
/* E2EBB0 802BC280 AFBF0014 */  sw        $ra, 0x14($sp)
/* E2EBB4 802BC284 0C03A8CD */  jal       subtract_hp
/* E2EBB8 802BC288 24040001 */   addiu    $a0, $zero, 1
/* E2EBBC 802BC28C 3C05802C */  lui       $a1, %hi(D_802BCC8C)
/* E2EBC0 802BC290 24A5CC8C */  addiu     $a1, $a1, %lo(D_802BCC8C)
/* E2EBC4 802BC294 0C0AF074 */  jal       func_802BC1D0_E2EB00
/* E2EBC8 802BC298 0200202D */   daddu    $a0, $s0, $zero
/* E2EBCC 802BC29C 0C039769 */  jal       set_action_state
/* E2EBD0 802BC2A0 24040026 */   addiu    $a0, $zero, 0x26
/* E2EBD4 802BC2A4 8FBF0014 */  lw        $ra, 0x14($sp)
/* E2EBD8 802BC2A8 8FB00010 */  lw        $s0, 0x10($sp)
/* E2EBDC 802BC2AC 03E00008 */  jr        $ra
/* E2EBE0 802BC2B0 27BD0018 */   addiu    $sp, $sp, 0x18
