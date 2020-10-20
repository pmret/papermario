.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EB4_A64F44
/* A64F44 80240EB4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A64F48 80240EB8 AFB10014 */  sw        $s1, 0x14($sp)
/* A64F4C 80240EBC 0080882D */  daddu     $s1, $a0, $zero
/* A64F50 80240EC0 AFBF0018 */  sw        $ra, 0x18($sp)
/* A64F54 80240EC4 AFB00010 */  sw        $s0, 0x10($sp)
/* A64F58 80240EC8 8E300148 */  lw        $s0, 0x148($s1)
/* A64F5C 80240ECC 0C00EABB */  jal       get_npc_unsafe
/* A64F60 80240ED0 86040008 */   lh       $a0, 8($s0)
/* A64F64 80240ED4 0040202D */  daddu     $a0, $v0, $zero
/* A64F68 80240ED8 9482008E */  lhu       $v0, 0x8e($a0)
/* A64F6C 80240EDC 2442FFFF */  addiu     $v0, $v0, -1
/* A64F70 80240EE0 A482008E */  sh        $v0, 0x8e($a0)
/* A64F74 80240EE4 00021400 */  sll       $v0, $v0, 0x10
/* A64F78 80240EE8 1C400008 */  bgtz      $v0, .L80240F0C
/* A64F7C 80240EEC 00000000 */   nop      
/* A64F80 80240EF0 8E0200CC */  lw        $v0, 0xcc($s0)
/* A64F84 80240EF4 8C430024 */  lw        $v1, 0x24($v0)
/* A64F88 80240EF8 24020009 */  addiu     $v0, $zero, 9
/* A64F8C 80240EFC A482008E */  sh        $v0, 0x8e($a0)
/* A64F90 80240F00 24020017 */  addiu     $v0, $zero, 0x17
/* A64F94 80240F04 AC830028 */  sw        $v1, 0x28($a0)
/* A64F98 80240F08 AE220070 */  sw        $v0, 0x70($s1)
.L80240F0C:
/* A64F9C 80240F0C 8FBF0018 */  lw        $ra, 0x18($sp)
/* A64FA0 80240F10 8FB10014 */  lw        $s1, 0x14($sp)
/* A64FA4 80240F14 8FB00010 */  lw        $s0, 0x10($sp)
/* A64FA8 80240F18 03E00008 */  jr        $ra
/* A64FAC 80240F1C 27BD0020 */   addiu    $sp, $sp, 0x20
