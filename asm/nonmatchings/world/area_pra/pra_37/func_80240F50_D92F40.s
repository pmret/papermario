.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F50_D93E90
/* D93E90 80240F50 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D93E94 80240F54 AFB10014 */  sw        $s1, 0x14($sp)
/* D93E98 80240F58 0080882D */  daddu     $s1, $a0, $zero
/* D93E9C 80240F5C AFBF0018 */  sw        $ra, 0x18($sp)
/* D93EA0 80240F60 AFB00010 */  sw        $s0, 0x10($sp)
/* D93EA4 80240F64 8E300148 */  lw        $s0, 0x148($s1)
/* D93EA8 80240F68 0C00EABB */  jal       get_npc_unsafe
/* D93EAC 80240F6C 86040008 */   lh       $a0, 8($s0)
/* D93EB0 80240F70 24030001 */  addiu     $v1, $zero, 1
/* D93EB4 80240F74 0040202D */  daddu     $a0, $v0, $zero
/* D93EB8 80240F78 AE03006C */  sw        $v1, 0x6c($s0)
/* D93EBC 80240F7C 8482008C */  lh        $v0, 0x8c($a0)
/* D93EC0 80240F80 14400009 */  bnez      $v0, .L80240FA8
/* D93EC4 80240F84 24020002 */   addiu    $v0, $zero, 2
/* D93EC8 80240F88 96030072 */  lhu       $v1, 0x72($s0)
/* D93ECC 80240F8C AE02006C */  sw        $v0, 0x6c($s0)
/* D93ED0 80240F90 A483008E */  sh        $v1, 0x8e($a0)
/* D93ED4 80240F94 8E0200CC */  lw        $v0, 0xcc($s0)
/* D93ED8 80240F98 8C420020 */  lw        $v0, 0x20($v0)
/* D93EDC 80240F9C AC820028 */  sw        $v0, 0x28($a0)
/* D93EE0 80240FA0 2402001F */  addiu     $v0, $zero, 0x1f
/* D93EE4 80240FA4 AE220070 */  sw        $v0, 0x70($s1)
.L80240FA8:
/* D93EE8 80240FA8 8FBF0018 */  lw        $ra, 0x18($sp)
/* D93EEC 80240FAC 8FB10014 */  lw        $s1, 0x14($sp)
/* D93EF0 80240FB0 8FB00010 */  lw        $s0, 0x10($sp)
/* D93EF4 80240FB4 03E00008 */  jr        $ra
/* D93EF8 80240FB8 27BD0020 */   addiu    $sp, $sp, 0x20
