.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel btl_state_update_end_turn_C7A6B8
/* C7A6B8 802439D8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C7A6BC 802439DC AFBF0010 */  sw        $ra, 0x10($sp)
/* C7A6C0 802439E0 0C00EABB */  jal       get_npc_unsafe
/* C7A6C4 802439E4 8C84008C */   lw       $a0, 0x8c($a0)
/* C7A6C8 802439E8 3C038024 */  lui       $v1, %hi(D_80247664)
/* C7A6CC 802439EC 8C637664 */  lw        $v1, %lo(D_80247664)($v1)
/* C7A6D0 802439F0 AC430028 */  sw        $v1, 0x28($v0)
/* C7A6D4 802439F4 8FBF0010 */  lw        $ra, 0x10($sp)
/* C7A6D8 802439F8 24020002 */  addiu     $v0, $zero, 2
/* C7A6DC 802439FC 03E00008 */  jr        $ra
/* C7A6E0 80243A00 27BD0018 */   addiu    $sp, $sp, 0x18
/* C7A6E4 80243A04 00000000 */  nop
/* C7A6E8 80243A08 00000000 */  nop
/* C7A6EC 80243A0C 00000000 */  nop
