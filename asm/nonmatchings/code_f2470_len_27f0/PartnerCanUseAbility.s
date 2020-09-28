.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel PartnerCanUseAbility
/* F4650 802CFCA0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F4654 802CFCA4 AFB00010 */  sw        $s0, 0x10($sp)
/* F4658 802CFCA8 0080802D */  daddu     $s0, $a0, $zero
/* F465C 802CFCAC AFBF0018 */  sw        $ra, 0x18($sp)
/* F4660 802CFCB0 AFB10014 */  sw        $s1, 0x14($sp)
/* F4664 802CFCB4 8E02000C */  lw        $v0, 0xc($s0)
/* F4668 802CFCB8 0C03AD0B */  jal       partner_can_use_ability
/* F466C 802CFCBC 8C510000 */   lw       $s1, ($v0)
/* F4670 802CFCC0 0200202D */  daddu     $a0, $s0, $zero
/* F4674 802CFCC4 0040302D */  daddu     $a2, $v0, $zero
/* F4678 802CFCC8 0C0B2026 */  jal       set_variable
/* F467C 802CFCCC 0220282D */   daddu    $a1, $s1, $zero
/* F4680 802CFCD0 8FBF0018 */  lw        $ra, 0x18($sp)
/* F4684 802CFCD4 8FB10014 */  lw        $s1, 0x14($sp)
/* F4688 802CFCD8 8FB00010 */  lw        $s0, 0x10($sp)
/* F468C 802CFCDC 24020002 */  addiu     $v0, $zero, 2
/* F4690 802CFCE0 03E00008 */  jr        $ra
/* F4694 802CFCE4 27BD0020 */   addiu    $sp, $sp, 0x20
