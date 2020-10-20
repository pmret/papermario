.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A2C_CD385C
/* CD385C 80241A2C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CD3860 80241A30 AFB20018 */  sw        $s2, 0x18($sp)
/* CD3864 80241A34 0080902D */  daddu     $s2, $a0, $zero
/* CD3868 80241A38 AFBF001C */  sw        $ra, 0x1c($sp)
/* CD386C 80241A3C AFB10014 */  sw        $s1, 0x14($sp)
/* CD3870 80241A40 AFB00010 */  sw        $s0, 0x10($sp)
/* CD3874 80241A44 8E510148 */  lw        $s1, 0x148($s2)
/* CD3878 80241A48 0C00EABB */  jal       get_npc_unsafe
/* CD387C 80241A4C 86240008 */   lh       $a0, 8($s1)
/* CD3880 80241A50 0040802D */  daddu     $s0, $v0, $zero
/* CD3884 80241A54 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CD3888 80241A58 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CD388C 80241A5C C60C0038 */  lwc1      $f12, 0x38($s0)
/* CD3890 80241A60 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CD3894 80241A64 A600008E */  sh        $zero, 0x8e($s0)
/* CD3898 80241A68 8C460028 */  lw        $a2, 0x28($v0)
/* CD389C 80241A6C 0C00A720 */  jal       atan2
/* CD38A0 80241A70 8C470030 */   lw       $a3, 0x30($v0)
/* CD38A4 80241A74 E600000C */  swc1      $f0, 0xc($s0)
/* CD38A8 80241A78 8E2200CC */  lw        $v0, 0xcc($s1)
/* CD38AC 80241A7C 8C420020 */  lw        $v0, 0x20($v0)
/* CD38B0 80241A80 AE020028 */  sw        $v0, 0x28($s0)
/* CD38B4 80241A84 2402000B */  addiu     $v0, $zero, 0xb
/* CD38B8 80241A88 AE420070 */  sw        $v0, 0x70($s2)
/* CD38BC 80241A8C 8FBF001C */  lw        $ra, 0x1c($sp)
/* CD38C0 80241A90 8FB20018 */  lw        $s2, 0x18($sp)
/* CD38C4 80241A94 8FB10014 */  lw        $s1, 0x14($sp)
/* CD38C8 80241A98 8FB00010 */  lw        $s0, 0x10($sp)
/* CD38CC 80241A9C 03E00008 */  jr        $ra
/* CD38D0 80241AA0 27BD0020 */   addiu    $sp, $sp, 0x20
