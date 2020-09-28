.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel PartnerIsFlying
/* F4698 802CFCE8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F469C 802CFCEC AFB00010 */  sw        $s0, 0x10($sp)
/* F46A0 802CFCF0 0080802D */  daddu     $s0, $a0, $zero
/* F46A4 802CFCF4 AFBF0018 */  sw        $ra, 0x18($sp)
/* F46A8 802CFCF8 AFB10014 */  sw        $s1, 0x14($sp)
/* F46AC 802CFCFC 8E02000C */  lw        $v0, 0xc($s0)
/* F46B0 802CFD00 0C03A969 */  jal       is_current_partner_flying
/* F46B4 802CFD04 8C510000 */   lw       $s1, ($v0)
/* F46B8 802CFD08 0200202D */  daddu     $a0, $s0, $zero
/* F46BC 802CFD0C 0040302D */  daddu     $a2, $v0, $zero
/* F46C0 802CFD10 0C0B2026 */  jal       set_variable
/* F46C4 802CFD14 0220282D */   daddu    $a1, $s1, $zero
/* F46C8 802CFD18 8FBF0018 */  lw        $ra, 0x18($sp)
/* F46CC 802CFD1C 8FB10014 */  lw        $s1, 0x14($sp)
/* F46D0 802CFD20 8FB00010 */  lw        $s0, 0x10($sp)
/* F46D4 802CFD24 24020002 */  addiu     $v0, $zero, 2
/* F46D8 802CFD28 03E00008 */  jr        $ra
/* F46DC 802CFD2C 27BD0020 */   addiu    $sp, $sp, 0x20
