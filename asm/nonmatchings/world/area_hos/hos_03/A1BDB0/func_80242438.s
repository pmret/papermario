.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242438
/* A1D538 80242438 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A1D53C 8024243C AFBF0010 */  sw        $ra, 0x10($sp)
/* A1D540 80242440 8C82000C */  lw        $v0, 0xc($a0)
/* A1D544 80242444 3C068011 */  lui       $a2, 0x8011
/* A1D548 80242448 80C6F2A2 */  lb        $a2, -0xd5e($a2)
/* A1D54C 8024244C 0C0B2026 */  jal       set_variable
/* A1D550 80242450 8C450000 */   lw       $a1, ($v0)
/* A1D554 80242454 0C03AC5A */  jal       func_800EB168
/* A1D558 80242458 0000202D */   daddu    $a0, $zero, $zero
/* A1D55C 8024245C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A1D560 80242460 24020002 */  addiu     $v0, $zero, 2
/* A1D564 80242464 03E00008 */  jr        $ra
/* A1D568 80242468 27BD0018 */   addiu    $sp, $sp, 0x18
