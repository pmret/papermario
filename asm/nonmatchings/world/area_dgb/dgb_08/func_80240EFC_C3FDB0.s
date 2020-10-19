.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EFC_C40CAC
/* C40CAC 80240EFC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C40CB0 80240F00 AFB10014 */  sw        $s1, 0x14($sp)
/* C40CB4 80240F04 0080882D */  daddu     $s1, $a0, $zero
/* C40CB8 80240F08 AFBF0018 */  sw        $ra, 0x18($sp)
/* C40CBC 80240F0C AFB00010 */  sw        $s0, 0x10($sp)
/* C40CC0 80240F10 8E300148 */  lw        $s0, 0x148($s1)
/* C40CC4 80240F14 0C00EABB */  jal       get_npc_unsafe
/* C40CC8 80240F18 86040008 */   lh       $a0, 8($s0)
/* C40CCC 80240F1C 0040202D */  daddu     $a0, $v0, $zero
/* C40CD0 80240F20 9482008E */  lhu       $v0, 0x8e($a0)
/* C40CD4 80240F24 2442FFFF */  addiu     $v0, $v0, -1
/* C40CD8 80240F28 A482008E */  sh        $v0, 0x8e($a0)
/* C40CDC 80240F2C 00021400 */  sll       $v0, $v0, 0x10
/* C40CE0 80240F30 1C400009 */  bgtz      $v0, .L80240F58
/* C40CE4 80240F34 24020003 */   addiu    $v0, $zero, 3
/* C40CE8 80240F38 96030076 */  lhu       $v1, 0x76($s0)
/* C40CEC 80240F3C AE02006C */  sw        $v0, 0x6c($s0)
/* C40CF0 80240F40 A483008E */  sh        $v1, 0x8e($a0)
/* C40CF4 80240F44 8E0200CC */  lw        $v0, 0xcc($s0)
/* C40CF8 80240F48 8C420024 */  lw        $v0, 0x24($v0)
/* C40CFC 80240F4C AC820028 */  sw        $v0, 0x28($a0)
/* C40D00 80240F50 24020020 */  addiu     $v0, $zero, 0x20
/* C40D04 80240F54 AE220070 */  sw        $v0, 0x70($s1)
.L80240F58:
/* C40D08 80240F58 8FBF0018 */  lw        $ra, 0x18($sp)
/* C40D0C 80240F5C 8FB10014 */  lw        $s1, 0x14($sp)
/* C40D10 80240F60 8FB00010 */  lw        $s0, 0x10($sp)
/* C40D14 80240F64 03E00008 */  jr        $ra
/* C40D18 80240F68 27BD0020 */   addiu    $sp, $sp, 0x20
