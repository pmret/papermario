.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C4C_CD7F2C
/* CD7F2C 80240C4C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CD7F30 80240C50 AFB20018 */  sw        $s2, 0x18($sp)
/* CD7F34 80240C54 0080902D */  daddu     $s2, $a0, $zero
/* CD7F38 80240C58 AFBF001C */  sw        $ra, 0x1c($sp)
/* CD7F3C 80240C5C AFB10014 */  sw        $s1, 0x14($sp)
/* CD7F40 80240C60 AFB00010 */  sw        $s0, 0x10($sp)
/* CD7F44 80240C64 8E510148 */  lw        $s1, 0x148($s2)
/* CD7F48 80240C68 0C00EABB */  jal       get_npc_unsafe
/* CD7F4C 80240C6C 86240008 */   lh       $a0, 8($s1)
/* CD7F50 80240C70 0040802D */  daddu     $s0, $v0, $zero
/* CD7F54 80240C74 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* CD7F58 80240C78 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* CD7F5C 80240C7C C60C0038 */  lwc1      $f12, 0x38($s0)
/* CD7F60 80240C80 C60E0040 */  lwc1      $f14, 0x40($s0)
/* CD7F64 80240C84 A600008E */  sh        $zero, 0x8e($s0)
/* CD7F68 80240C88 8C460028 */  lw        $a2, 0x28($v0)
/* CD7F6C 80240C8C 0C00A720 */  jal       atan2
/* CD7F70 80240C90 8C470030 */   lw       $a3, 0x30($v0)
/* CD7F74 80240C94 E600000C */  swc1      $f0, 0xc($s0)
/* CD7F78 80240C98 8E2200CC */  lw        $v0, 0xcc($s1)
/* CD7F7C 80240C9C 8C420020 */  lw        $v0, 0x20($v0)
/* CD7F80 80240CA0 AE020028 */  sw        $v0, 0x28($s0)
/* CD7F84 80240CA4 2402000B */  addiu     $v0, $zero, 0xb
/* CD7F88 80240CA8 AE420070 */  sw        $v0, 0x70($s2)
/* CD7F8C 80240CAC 8FBF001C */  lw        $ra, 0x1c($sp)
/* CD7F90 80240CB0 8FB20018 */  lw        $s2, 0x18($sp)
/* CD7F94 80240CB4 8FB10014 */  lw        $s1, 0x14($sp)
/* CD7F98 80240CB8 8FB00010 */  lw        $s0, 0x10($sp)
/* CD7F9C 80240CBC 03E00008 */  jr        $ra
/* CD7FA0 80240CC0 27BD0020 */   addiu    $sp, $sp, 0x20
