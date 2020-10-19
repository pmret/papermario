.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240940_B663F0
/* B663F0 80240940 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B663F4 80240944 AFB10014 */  sw        $s1, 0x14($sp)
/* B663F8 80240948 0080882D */  daddu     $s1, $a0, $zero
/* B663FC 8024094C AFBF0018 */  sw        $ra, 0x18($sp)
/* B66400 80240950 AFB00010 */  sw        $s0, 0x10($sp)
/* B66404 80240954 8E300148 */  lw        $s0, 0x148($s1)
/* B66408 80240958 0C00EABB */  jal       get_npc_unsafe
/* B6640C 8024095C 86040008 */   lh       $a0, 8($s0)
/* B66410 80240960 3C054387 */  lui       $a1, 0x4387
/* B66414 80240964 0040202D */  daddu     $a0, $v0, $zero
/* B66418 80240968 0C00ECD0 */  jal       set_npc_yaw
/* B6641C 8024096C A480008E */   sh       $zero, 0x8e($a0)
/* B66420 80240970 24020003 */  addiu     $v0, $zero, 3
/* B66424 80240974 AE00006C */  sw        $zero, 0x6c($s0)
/* B66428 80240978 AE220070 */  sw        $v0, 0x70($s1)
/* B6642C 8024097C 8FBF0018 */  lw        $ra, 0x18($sp)
/* B66430 80240980 8FB10014 */  lw        $s1, 0x14($sp)
/* B66434 80240984 8FB00010 */  lw        $s0, 0x10($sp)
/* B66438 80240988 03E00008 */  jr        $ra
/* B6643C 8024098C 27BD0020 */   addiu    $sp, $sp, 0x20
