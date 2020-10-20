.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241454_A4DE74
/* A4DE74 80241454 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A4DE78 80241458 AFBF0014 */  sw        $ra, 0x14($sp)
/* A4DE7C 8024145C AFB00010 */  sw        $s0, 0x10($sp)
/* A4DE80 80241460 8C900148 */  lw        $s0, 0x148($a0)
/* A4DE84 80241464 0C00EABB */  jal       get_npc_unsafe
/* A4DE88 80241468 86040008 */   lh       $a0, 8($s0)
/* A4DE8C 8024146C 0040202D */  daddu     $a0, $v0, $zero
/* A4DE90 80241470 8E03006C */  lw        $v1, 0x6c($s0)
/* A4DE94 80241474 24020002 */  addiu     $v0, $zero, 2
/* A4DE98 80241478 14620003 */  bne       $v1, $v0, .L80241488
/* A4DE9C 8024147C 00000000 */   nop      
/* A4DEA0 80241480 AC80001C */  sw        $zero, 0x1c($a0)
/* A4DEA4 80241484 AC800018 */  sw        $zero, 0x18($a0)
.L80241488:
/* A4DEA8 80241488 8FBF0014 */  lw        $ra, 0x14($sp)
/* A4DEAC 8024148C 8FB00010 */  lw        $s0, 0x10($sp)
/* A4DEB0 80241490 24020002 */  addiu     $v0, $zero, 2
/* A4DEB4 80241494 03E00008 */  jr        $ra
/* A4DEB8 80241498 27BD0018 */   addiu    $sp, $sp, 0x18
/* A4DEBC 8024149C 00000000 */  nop       
