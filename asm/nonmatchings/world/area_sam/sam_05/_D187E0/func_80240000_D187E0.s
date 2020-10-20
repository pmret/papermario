.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_D187E0
/* D187E0 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D187E4 80240004 AFB10014 */  sw        $s1, 0x14($sp)
/* D187E8 80240008 0080882D */  daddu     $s1, $a0, $zero
/* D187EC 8024000C AFBF0018 */  sw        $ra, 0x18($sp)
/* D187F0 80240010 AFB00010 */  sw        $s0, 0x10($sp)
/* D187F4 80240014 8E300148 */  lw        $s0, 0x148($s1)
/* D187F8 80240018 0C00EABB */  jal       get_npc_unsafe
/* D187FC 8024001C 86040008 */   lh       $a0, 8($s0)
/* D18800 80240020 24030001 */  addiu     $v1, $zero, 1
/* D18804 80240024 0040202D */  daddu     $a0, $v0, $zero
/* D18808 80240028 AE03006C */  sw        $v1, 0x6c($s0)
/* D1880C 8024002C 8482008C */  lh        $v0, 0x8c($a0)
/* D18810 80240030 14400009 */  bnez      $v0, .L80240058
/* D18814 80240034 24020002 */   addiu    $v0, $zero, 2
/* D18818 80240038 96030072 */  lhu       $v1, 0x72($s0)
/* D1881C 8024003C AE02006C */  sw        $v0, 0x6c($s0)
/* D18820 80240040 A483008E */  sh        $v1, 0x8e($a0)
/* D18824 80240044 8E0200CC */  lw        $v0, 0xcc($s0)
/* D18828 80240048 8C420020 */  lw        $v0, 0x20($v0)
/* D1882C 8024004C AC820028 */  sw        $v0, 0x28($a0)
/* D18830 80240050 2402001F */  addiu     $v0, $zero, 0x1f
/* D18834 80240054 AE220070 */  sw        $v0, 0x70($s1)
.L80240058:
/* D18838 80240058 8FBF0018 */  lw        $ra, 0x18($sp)
/* D1883C 8024005C 8FB10014 */  lw        $s1, 0x14($sp)
/* D18840 80240060 8FB00010 */  lw        $s0, 0x10($sp)
/* D18844 80240064 03E00008 */  jr        $ra
/* D18848 80240068 27BD0020 */   addiu    $sp, $sp, 0x20
