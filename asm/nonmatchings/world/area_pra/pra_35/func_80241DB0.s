.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241DB0
/* D8F000 80241DB0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D8F004 80241DB4 AFB10014 */  sw        $s1, 0x14($sp)
/* D8F008 80241DB8 0080882D */  daddu     $s1, $a0, $zero
/* D8F00C 80241DBC AFBF0018 */  sw        $ra, 0x18($sp)
/* D8F010 80241DC0 AFB00010 */  sw        $s0, 0x10($sp)
/* D8F014 80241DC4 8E300148 */  lw        $s0, 0x148($s1)
/* D8F018 80241DC8 0C00EABB */  jal       get_npc_unsafe
/* D8F01C 80241DCC 86040008 */   lh       $a0, 8($s0)
/* D8F020 80241DD0 24030001 */  addiu     $v1, $zero, 1
/* D8F024 80241DD4 0040202D */  daddu     $a0, $v0, $zero
/* D8F028 80241DD8 AE03006C */  sw        $v1, 0x6c($s0)
/* D8F02C 80241DDC 8482008C */  lh        $v0, 0x8c($a0)
/* D8F030 80241DE0 14400009 */  bnez      $v0, .L80241E08
/* D8F034 80241DE4 24020002 */   addiu    $v0, $zero, 2
/* D8F038 80241DE8 96030072 */  lhu       $v1, 0x72($s0)
/* D8F03C 80241DEC AE02006C */  sw        $v0, 0x6c($s0)
/* D8F040 80241DF0 A483008E */  sh        $v1, 0x8e($a0)
/* D8F044 80241DF4 8E0200CC */  lw        $v0, 0xcc($s0)
/* D8F048 80241DF8 8C420020 */  lw        $v0, 0x20($v0)
/* D8F04C 80241DFC AC820028 */  sw        $v0, 0x28($a0)
/* D8F050 80241E00 2402001F */  addiu     $v0, $zero, 0x1f
/* D8F054 80241E04 AE220070 */  sw        $v0, 0x70($s1)
.L80241E08:
/* D8F058 80241E08 8FBF0018 */  lw        $ra, 0x18($sp)
/* D8F05C 80241E0C 8FB10014 */  lw        $s1, 0x14($sp)
/* D8F060 80241E10 8FB00010 */  lw        $s0, 0x10($sp)
/* D8F064 80241E14 03E00008 */  jr        $ra
/* D8F068 80241E18 27BD0020 */   addiu    $sp, $sp, 0x20
