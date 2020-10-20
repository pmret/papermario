.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_C46BE0
/* C46BE0 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C46BE4 80240004 AFB10014 */  sw        $s1, 0x14($sp)
/* C46BE8 80240008 0080882D */  daddu     $s1, $a0, $zero
/* C46BEC 8024000C AFBF0018 */  sw        $ra, 0x18($sp)
/* C46BF0 80240010 AFB00010 */  sw        $s0, 0x10($sp)
/* C46BF4 80240014 8E300148 */  lw        $s0, 0x148($s1)
/* C46BF8 80240018 0C00EABB */  jal       get_npc_unsafe
/* C46BFC 8024001C 86040008 */   lh       $a0, 8($s0)
/* C46C00 80240020 24030001 */  addiu     $v1, $zero, 1
/* C46C04 80240024 0040202D */  daddu     $a0, $v0, $zero
/* C46C08 80240028 AE03006C */  sw        $v1, 0x6c($s0)
/* C46C0C 8024002C 8482008C */  lh        $v0, 0x8c($a0)
/* C46C10 80240030 14400009 */  bnez      $v0, .L80240058
/* C46C14 80240034 24020002 */   addiu    $v0, $zero, 2
/* C46C18 80240038 96030072 */  lhu       $v1, 0x72($s0)
/* C46C1C 8024003C AE02006C */  sw        $v0, 0x6c($s0)
/* C46C20 80240040 A483008E */  sh        $v1, 0x8e($a0)
/* C46C24 80240044 8E0200CC */  lw        $v0, 0xcc($s0)
/* C46C28 80240048 8C420020 */  lw        $v0, 0x20($v0)
/* C46C2C 8024004C AC820028 */  sw        $v0, 0x28($a0)
/* C46C30 80240050 2402001F */  addiu     $v0, $zero, 0x1f
/* C46C34 80240054 AE220070 */  sw        $v0, 0x70($s1)
.L80240058:
/* C46C38 80240058 8FBF0018 */  lw        $ra, 0x18($sp)
/* C46C3C 8024005C 8FB10014 */  lw        $s1, 0x14($sp)
/* C46C40 80240060 8FB00010 */  lw        $s0, 0x10($sp)
/* C46C44 80240064 03E00008 */  jr        $ra
/* C46C48 80240068 27BD0020 */   addiu    $sp, $sp, 0x20
