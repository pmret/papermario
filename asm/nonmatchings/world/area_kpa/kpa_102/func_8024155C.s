.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024155C
/* A94C9C 8024155C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A94CA0 80241560 AFB20018 */  sw        $s2, 0x18($sp)
/* A94CA4 80241564 0080902D */  daddu     $s2, $a0, $zero
/* A94CA8 80241568 AFBF001C */  sw        $ra, 0x1c($sp)
/* A94CAC 8024156C AFB10014 */  sw        $s1, 0x14($sp)
/* A94CB0 80241570 AFB00010 */  sw        $s0, 0x10($sp)
/* A94CB4 80241574 8E510148 */  lw        $s1, 0x148($s2)
/* A94CB8 80241578 0C00EABB */  jal       get_npc_unsafe
/* A94CBC 8024157C 86240008 */   lh       $a0, 8($s1)
/* A94CC0 80241580 0040802D */  daddu     $s0, $v0, $zero
/* A94CC4 80241584 8E2300CC */  lw        $v1, 0xcc($s1)
/* A94CC8 80241588 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A94CCC 8024158C 8C630020 */  lw        $v1, 0x20($v1)
/* A94CD0 80241590 AE030028 */  sw        $v1, 0x28($s0)
/* A94CD4 80241594 96220076 */  lhu       $v0, 0x76($s1)
/* A94CD8 80241598 A602008E */  sh        $v0, 0x8e($s0)
/* A94CDC 8024159C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A94CE0 802415A0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A94CE4 802415A4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A94CE8 802415A8 8C460028 */  lw        $a2, 0x28($v0)
/* A94CEC 802415AC 0C00A720 */  jal       atan2
/* A94CF0 802415B0 8C470030 */   lw       $a3, 0x30($v0)
/* A94CF4 802415B4 2402000D */  addiu     $v0, $zero, 0xd
/* A94CF8 802415B8 E600000C */  swc1      $f0, 0xc($s0)
/* A94CFC 802415BC AE420070 */  sw        $v0, 0x70($s2)
/* A94D00 802415C0 8FBF001C */  lw        $ra, 0x1c($sp)
/* A94D04 802415C4 8FB20018 */  lw        $s2, 0x18($sp)
/* A94D08 802415C8 8FB10014 */  lw        $s1, 0x14($sp)
/* A94D0C 802415CC 8FB00010 */  lw        $s0, 0x10($sp)
/* A94D10 802415D0 03E00008 */  jr        $ra
/* A94D14 802415D4 27BD0020 */   addiu    $sp, $sp, 0x20
