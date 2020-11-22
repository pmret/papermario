.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel UnkNpcAIFunc7
/* D93EFC 80240FBC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D93F00 80240FC0 AFB10014 */  sw        $s1, 0x14($sp)
/* D93F04 80240FC4 0080882D */  daddu     $s1, $a0, $zero
/* D93F08 80240FC8 AFBF0018 */  sw        $ra, 0x18($sp)
/* D93F0C 80240FCC AFB00010 */  sw        $s0, 0x10($sp)
/* D93F10 80240FD0 8E300148 */  lw        $s0, 0x148($s1)
/* D93F14 80240FD4 0C00EABB */  jal       get_npc_unsafe
/* D93F18 80240FD8 86040008 */   lh       $a0, 8($s0)
/* D93F1C 80240FDC 0040202D */  daddu     $a0, $v0, $zero
/* D93F20 80240FE0 9482008E */  lhu       $v0, 0x8e($a0)
/* D93F24 80240FE4 2442FFFF */  addiu     $v0, $v0, -1
/* D93F28 80240FE8 A482008E */  sh        $v0, 0x8e($a0)
/* D93F2C 80240FEC 00021400 */  sll       $v0, $v0, 0x10
/* D93F30 80240FF0 1C400009 */  bgtz      $v0, .L80241018
/* D93F34 80240FF4 24020003 */   addiu    $v0, $zero, 3
/* D93F38 80240FF8 96030076 */  lhu       $v1, 0x76($s0)
/* D93F3C 80240FFC AE02006C */  sw        $v0, 0x6c($s0)
/* D93F40 80241000 A483008E */  sh        $v1, 0x8e($a0)
/* D93F44 80241004 8E0200CC */  lw        $v0, 0xcc($s0)
/* D93F48 80241008 8C420024 */  lw        $v0, 0x24($v0)
/* D93F4C 8024100C AC820028 */  sw        $v0, 0x28($a0)
/* D93F50 80241010 24020020 */  addiu     $v0, $zero, 0x20
/* D93F54 80241014 AE220070 */  sw        $v0, 0x70($s1)
.L80241018:
/* D93F58 80241018 8FBF0018 */  lw        $ra, 0x18($sp)
/* D93F5C 8024101C 8FB10014 */  lw        $s1, 0x14($sp)
/* D93F60 80241020 8FB00010 */  lw        $s0, 0x10($sp)
/* D93F64 80241024 03E00008 */  jr        $ra
/* D93F68 80241028 27BD0020 */   addiu    $sp, $sp, 0x20
