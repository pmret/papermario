.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241740_B36310
/* B36310 80241740 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B36314 80241744 AFBF0010 */  sw        $ra, 0x10($sp)
/* B36318 80241748 8C82000C */  lw        $v0, 0xc($a0)
/* B3631C 8024174C 3C068011 */  lui       $a2, 0x8011
/* B36320 80241750 80C6F2A2 */  lb        $a2, -0xd5e($a2)
/* B36324 80241754 0C0B2026 */  jal       set_variable
/* B36328 80241758 8C450000 */   lw       $a1, ($v0)
/* B3632C 8024175C 0C03AC5A */  jal       func_800EB168
/* B36330 80241760 0000202D */   daddu    $a0, $zero, $zero
/* B36334 80241764 8FBF0010 */  lw        $ra, 0x10($sp)
/* B36338 80241768 24020002 */  addiu     $v0, $zero, 2
/* B3633C 8024176C 03E00008 */  jr        $ra
/* B36340 80241770 27BD0018 */   addiu    $sp, $sp, 0x18
