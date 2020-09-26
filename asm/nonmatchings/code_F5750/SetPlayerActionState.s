.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetPlayerActionState
/* F5A88 802D10D8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F5A8C 802D10DC AFBF0010 */  sw        $ra, 0x10($sp)
/* F5A90 802D10E0 8C82000C */  lw        $v0, 0xc($a0)
/* F5A94 802D10E4 0C0B1EAF */  jal       get_variable
/* F5A98 802D10E8 8C450000 */   lw       $a1, ($v0)
/* F5A9C 802D10EC 0C039769 */  jal       set_action_state
/* F5AA0 802D10F0 0040202D */   daddu    $a0, $v0, $zero
/* F5AA4 802D10F4 8FBF0010 */  lw        $ra, 0x10($sp)
/* F5AA8 802D10F8 24020002 */  addiu     $v0, $zero, 2
/* F5AAC 802D10FC 03E00008 */  jr        $ra
/* F5AB0 802D1100 27BD0018 */   addiu    $sp, $sp, 0x18
