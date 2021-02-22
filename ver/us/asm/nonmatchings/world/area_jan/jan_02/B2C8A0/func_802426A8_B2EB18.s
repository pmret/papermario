.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802426A8_B2EB18
/* B2EB18 802426A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B2EB1C 802426AC AFBF0010 */  sw        $ra, 0x10($sp)
/* B2EB20 802426B0 8C82000C */  lw        $v0, 0xc($a0)
/* B2EB24 802426B4 0C0B1EAF */  jal       get_variable
/* B2EB28 802426B8 8C450000 */   lw       $a1, ($v0)
/* B2EB2C 802426BC 0C03AC5A */  jal       func_800EB168
/* B2EB30 802426C0 0040202D */   daddu    $a0, $v0, $zero
/* B2EB34 802426C4 8FBF0010 */  lw        $ra, 0x10($sp)
/* B2EB38 802426C8 24020002 */  addiu     $v0, $zero, 2
/* B2EB3C 802426CC 03E00008 */  jr        $ra
/* B2EB40 802426D0 27BD0018 */   addiu    $sp, $sp, 0x18
/* B2EB44 802426D4 00000000 */  nop
/* B2EB48 802426D8 00000000 */  nop
/* B2EB4C 802426DC 00000000 */  nop
