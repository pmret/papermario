.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_997F70
/* 997F70 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 997F74 80240004 AFB20018 */  sw        $s2, 0x18($sp)
/* 997F78 80240008 0080902D */  daddu     $s2, $a0, $zero
/* 997F7C 8024000C AFBF001C */  sw        $ra, 0x1c($sp)
/* 997F80 80240010 AFB10014 */  sw        $s1, 0x14($sp)
/* 997F84 80240014 AFB00010 */  sw        $s0, 0x10($sp)
/* 997F88 80240018 8E510148 */  lw        $s1, 0x148($s2)
/* 997F8C 8024001C 0C00EABB */  jal       get_npc_unsafe
/* 997F90 80240020 86240008 */   lh       $a0, 8($s1)
/* 997F94 80240024 0040802D */  daddu     $s0, $v0, $zero
/* 997F98 80240028 8E2300CC */  lw        $v1, 0xcc($s1)
/* 997F9C 8024002C C60C0038 */  lwc1      $f12, 0x38($s0)
/* 997FA0 80240030 8C630020 */  lw        $v1, 0x20($v1)
/* 997FA4 80240034 AE030028 */  sw        $v1, 0x28($s0)
/* 997FA8 80240038 96220076 */  lhu       $v0, 0x76($s1)
/* 997FAC 8024003C A602008E */  sh        $v0, 0x8e($s0)
/* 997FB0 80240040 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 997FB4 80240044 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 997FB8 80240048 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 997FBC 8024004C 8C460028 */  lw        $a2, 0x28($v0)
/* 997FC0 80240050 0C00A720 */  jal       atan2
/* 997FC4 80240054 8C470030 */   lw       $a3, 0x30($v0)
/* 997FC8 80240058 2402000D */  addiu     $v0, $zero, 0xd
/* 997FCC 8024005C E600000C */  swc1      $f0, 0xc($s0)
/* 997FD0 80240060 AE420070 */  sw        $v0, 0x70($s2)
/* 997FD4 80240064 8FBF001C */  lw        $ra, 0x1c($sp)
/* 997FD8 80240068 8FB20018 */  lw        $s2, 0x18($sp)
/* 997FDC 8024006C 8FB10014 */  lw        $s1, 0x14($sp)
/* 997FE0 80240070 8FB00010 */  lw        $s0, 0x10($sp)
/* 997FE4 80240074 03E00008 */  jr        $ra
/* 997FE8 80240078 27BD0020 */   addiu    $sp, $sp, 0x20
