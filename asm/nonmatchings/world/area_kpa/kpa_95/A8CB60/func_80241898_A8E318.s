.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241898_A8E318
/* A8E318 80241898 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A8E31C 8024189C AFBF0010 */  sw        $ra, 0x10($sp)
/* A8E320 802418A0 8C82000C */  lw        $v0, 0xc($a0)
/* A8E324 802418A4 3C068011 */  lui       $a2, 0x8011
/* A8E328 802418A8 80C6F2A2 */  lb        $a2, -0xd5e($a2)
/* A8E32C 802418AC 0C0B2026 */  jal       set_variable
/* A8E330 802418B0 8C450000 */   lw       $a1, ($v0)
/* A8E334 802418B4 0C03AC5A */  jal       func_800EB168
/* A8E338 802418B8 0000202D */   daddu    $a0, $zero, $zero
/* A8E33C 802418BC 8FBF0010 */  lw        $ra, 0x10($sp)
/* A8E340 802418C0 24020002 */  addiu     $v0, $zero, 2
/* A8E344 802418C4 03E00008 */  jr        $ra
/* A8E348 802418C8 27BD0018 */   addiu    $sp, $sp, 0x18
