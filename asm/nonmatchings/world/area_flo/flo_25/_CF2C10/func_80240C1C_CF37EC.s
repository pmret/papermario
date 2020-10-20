.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C1C_CF37EC
/* CF37EC 80240C1C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CF37F0 80240C20 AFB20018 */  sw        $s2, 0x18($sp)
/* CF37F4 80240C24 0080902D */  daddu     $s2, $a0, $zero
/* CF37F8 80240C28 AFBF001C */  sw        $ra, 0x1c($sp)
/* CF37FC 80240C2C AFB10014 */  sw        $s1, 0x14($sp)
/* CF3800 80240C30 AFB00010 */  sw        $s0, 0x10($sp)
/* CF3804 80240C34 8E510148 */  lw        $s1, 0x148($s2)
/* CF3808 80240C38 0C00EABB */  jal       get_npc_unsafe
/* CF380C 80240C3C 86240008 */   lh       $a0, 8($s1)
/* CF3810 80240C40 0040802D */  daddu     $s0, $v0, $zero
/* CF3814 80240C44 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CF3818 80240C48 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CF381C 80240C4C C60C0038 */  lwc1      $f12, 0x38($s0)
/* CF3820 80240C50 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CF3824 80240C54 A600008E */  sh        $zero, 0x8e($s0)
/* CF3828 80240C58 8C460028 */  lw        $a2, 0x28($v0)
/* CF382C 80240C5C 0C00A720 */  jal       atan2
/* CF3830 80240C60 8C470030 */   lw       $a3, 0x30($v0)
/* CF3834 80240C64 E600000C */  swc1      $f0, 0xc($s0)
/* CF3838 80240C68 8E2200CC */  lw        $v0, 0xcc($s1)
/* CF383C 80240C6C 8C420020 */  lw        $v0, 0x20($v0)
/* CF3840 80240C70 AE020028 */  sw        $v0, 0x28($s0)
/* CF3844 80240C74 2402000B */  addiu     $v0, $zero, 0xb
/* CF3848 80240C78 AE420070 */  sw        $v0, 0x70($s2)
/* CF384C 80240C7C 8FBF001C */  lw        $ra, 0x1c($sp)
/* CF3850 80240C80 8FB20018 */  lw        $s2, 0x18($sp)
/* CF3854 80240C84 8FB10014 */  lw        $s1, 0x14($sp)
/* CF3858 80240C88 8FB00010 */  lw        $s0, 0x10($sp)
/* CF385C 80240C8C 03E00008 */  jr        $ra
/* CF3860 80240C90 27BD0020 */   addiu    $sp, $sp, 0x20
