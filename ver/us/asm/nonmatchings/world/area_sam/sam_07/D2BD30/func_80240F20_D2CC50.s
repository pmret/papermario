.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F20_D2CC50
/* D2CC50 80240F20 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D2CC54 80240F24 AFB10014 */  sw        $s1, 0x14($sp)
/* D2CC58 80240F28 0080882D */  daddu     $s1, $a0, $zero
/* D2CC5C 80240F2C AFBF0018 */  sw        $ra, 0x18($sp)
/* D2CC60 80240F30 AFB00010 */  sw        $s0, 0x10($sp)
/* D2CC64 80240F34 8E300148 */  lw        $s0, 0x148($s1)
/* D2CC68 80240F38 0C00EABB */  jal       get_npc_unsafe
/* D2CC6C 80240F3C 86040008 */   lh       $a0, 8($s0)
/* D2CC70 80240F40 0040202D */  daddu     $a0, $v0, $zero
/* D2CC74 80240F44 8482008E */  lh        $v0, 0x8e($a0)
/* D2CC78 80240F48 9483008E */  lhu       $v1, 0x8e($a0)
/* D2CC7C 80240F4C 18400003 */  blez      $v0, .L80240F5C
/* D2CC80 80240F50 2462FFFF */   addiu    $v0, $v1, -1
/* D2CC84 80240F54 080903DE */  j         .L80240F78
/* D2CC88 80240F58 A482008E */   sh       $v0, 0x8e($a0)
.L80240F5C:
/* D2CC8C 80240F5C 8E0200CC */  lw        $v0, 0xcc($s0)
/* D2CC90 80240F60 AE00006C */  sw        $zero, 0x6c($s0)
/* D2CC94 80240F64 8C420000 */  lw        $v0, ($v0)
/* D2CC98 80240F68 AC820028 */  sw        $v0, 0x28($a0)
/* D2CC9C 80240F6C 24020001 */  addiu     $v0, $zero, 1
/* D2CCA0 80240F70 AE200074 */  sw        $zero, 0x74($s1)
/* D2CCA4 80240F74 AE220070 */  sw        $v0, 0x70($s1)
.L80240F78:
/* D2CCA8 80240F78 8FBF0018 */  lw        $ra, 0x18($sp)
/* D2CCAC 80240F7C 8FB10014 */  lw        $s1, 0x14($sp)
/* D2CCB0 80240F80 8FB00010 */  lw        $s0, 0x10($sp)
/* D2CCB4 80240F84 03E00008 */  jr        $ra
/* D2CCB8 80240F88 27BD0020 */   addiu    $sp, $sp, 0x20
