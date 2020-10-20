.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241454_B5F704
/* B5F704 80241454 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B5F708 80241458 AFB10014 */  sw        $s1, 0x14($sp)
/* B5F70C 8024145C 0080882D */  daddu     $s1, $a0, $zero
/* B5F710 80241460 AFBF0018 */  sw        $ra, 0x18($sp)
/* B5F714 80241464 AFB00010 */  sw        $s0, 0x10($sp)
/* B5F718 80241468 8E300148 */  lw        $s0, 0x148($s1)
/* B5F71C 8024146C 0C00EABB */  jal       get_npc_unsafe
/* B5F720 80241470 86040008 */   lh       $a0, 8($s0)
/* B5F724 80241474 3C054387 */  lui       $a1, 0x4387
/* B5F728 80241478 0040202D */  daddu     $a0, $v0, $zero
/* B5F72C 8024147C 0C00ECD0 */  jal       set_npc_yaw
/* B5F730 80241480 A480008E */   sh       $zero, 0x8e($a0)
/* B5F734 80241484 24020003 */  addiu     $v0, $zero, 3
/* B5F738 80241488 AE00006C */  sw        $zero, 0x6c($s0)
/* B5F73C 8024148C AE220070 */  sw        $v0, 0x70($s1)
/* B5F740 80241490 8FBF0018 */  lw        $ra, 0x18($sp)
/* B5F744 80241494 8FB10014 */  lw        $s1, 0x14($sp)
/* B5F748 80241498 8FB00010 */  lw        $s0, 0x10($sp)
/* B5F74C 8024149C 03E00008 */  jr        $ra
/* B5F750 802414A0 27BD0020 */   addiu    $sp, $sp, 0x20
