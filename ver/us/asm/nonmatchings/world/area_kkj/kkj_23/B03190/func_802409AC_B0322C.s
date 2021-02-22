.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409AC_B0322C
/* B0322C 802409AC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B03230 802409B0 AFBF0010 */  sw        $ra, 0x10($sp)
/* B03234 802409B4 0C0398E9 */  jal       func_800E63A4
/* B03238 802409B8 0000202D */   daddu    $a0, $zero, $zero
/* B0323C 802409BC 8FBF0010 */  lw        $ra, 0x10($sp)
/* B03240 802409C0 24020002 */  addiu     $v0, $zero, 2
/* B03244 802409C4 03E00008 */  jr        $ra
/* B03248 802409C8 27BD0018 */   addiu    $sp, $sp, 0x18
/* B0324C 802409CC 00000000 */  nop
