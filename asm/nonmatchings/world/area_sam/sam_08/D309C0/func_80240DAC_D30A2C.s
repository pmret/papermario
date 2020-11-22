.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel UnkNpcAIFunc7
/* D30A2C 80240DAC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D30A30 80240DB0 AFB10014 */  sw        $s1, 0x14($sp)
/* D30A34 80240DB4 0080882D */  daddu     $s1, $a0, $zero
/* D30A38 80240DB8 AFBF0018 */  sw        $ra, 0x18($sp)
/* D30A3C 80240DBC AFB00010 */  sw        $s0, 0x10($sp)
/* D30A40 80240DC0 8E300148 */  lw        $s0, 0x148($s1)
/* D30A44 80240DC4 0C00EABB */  jal       get_npc_unsafe
/* D30A48 80240DC8 86040008 */   lh       $a0, 8($s0)
/* D30A4C 80240DCC 0040202D */  daddu     $a0, $v0, $zero
/* D30A50 80240DD0 9482008E */  lhu       $v0, 0x8e($a0)
/* D30A54 80240DD4 2442FFFF */  addiu     $v0, $v0, -1
/* D30A58 80240DD8 A482008E */  sh        $v0, 0x8e($a0)
/* D30A5C 80240DDC 00021400 */  sll       $v0, $v0, 0x10
/* D30A60 80240DE0 1C400009 */  bgtz      $v0, .L80240E08
/* D30A64 80240DE4 24020003 */   addiu    $v0, $zero, 3
/* D30A68 80240DE8 96030076 */  lhu       $v1, 0x76($s0)
/* D30A6C 80240DEC AE02006C */  sw        $v0, 0x6c($s0)
/* D30A70 80240DF0 A483008E */  sh        $v1, 0x8e($a0)
/* D30A74 80240DF4 8E0200CC */  lw        $v0, 0xcc($s0)
/* D30A78 80240DF8 8C420024 */  lw        $v0, 0x24($v0)
/* D30A7C 80240DFC AC820028 */  sw        $v0, 0x28($a0)
/* D30A80 80240E00 24020020 */  addiu     $v0, $zero, 0x20
/* D30A84 80240E04 AE220070 */  sw        $v0, 0x70($s1)
.L80240E08:
/* D30A88 80240E08 8FBF0018 */  lw        $ra, 0x18($sp)
/* D30A8C 80240E0C 8FB10014 */  lw        $s1, 0x14($sp)
/* D30A90 80240E10 8FB00010 */  lw        $s0, 0x10($sp)
/* D30A94 80240E14 03E00008 */  jr        $ra
/* D30A98 80240E18 27BD0020 */   addiu    $sp, $sp, 0x20
