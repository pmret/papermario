.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241570_A03DB0
/* A03DB0 80241570 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A03DB4 80241574 AFB20018 */  sw        $s2, 0x18($sp)
/* A03DB8 80241578 0080902D */  daddu     $s2, $a0, $zero
/* A03DBC 8024157C AFBF001C */  sw        $ra, 0x1c($sp)
/* A03DC0 80241580 AFB10014 */  sw        $s1, 0x14($sp)
/* A03DC4 80241584 AFB00010 */  sw        $s0, 0x10($sp)
/* A03DC8 80241588 8E510148 */  lw        $s1, 0x148($s2)
/* A03DCC 8024158C 0C00EABB */  jal       get_npc_unsafe
/* A03DD0 80241590 86240008 */   lh       $a0, 8($s1)
/* A03DD4 80241594 0040802D */  daddu     $s0, $v0, $zero
/* A03DD8 80241598 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A03DDC 8024159C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A03DE0 802415A0 C60C0038 */  lwc1      $f12, 0x38($s0)
/* A03DE4 802415A4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* A03DE8 802415A8 A600008E */  sh        $zero, 0x8e($s0)
/* A03DEC 802415AC 8C460028 */  lw        $a2, 0x28($v0)
/* A03DF0 802415B0 0C00A720 */  jal       atan2
/* A03DF4 802415B4 8C470030 */   lw       $a3, 0x30($v0)
/* A03DF8 802415B8 E600000C */  swc1      $f0, 0xc($s0)
/* A03DFC 802415BC 8E2200CC */  lw        $v0, 0xcc($s1)
/* A03E00 802415C0 8C420020 */  lw        $v0, 0x20($v0)
/* A03E04 802415C4 AE020028 */  sw        $v0, 0x28($s0)
/* A03E08 802415C8 2402000B */  addiu     $v0, $zero, 0xb
/* A03E0C 802415CC AE420070 */  sw        $v0, 0x70($s2)
/* A03E10 802415D0 8FBF001C */  lw        $ra, 0x1c($sp)
/* A03E14 802415D4 8FB20018 */  lw        $s2, 0x18($sp)
/* A03E18 802415D8 8FB10014 */  lw        $s1, 0x14($sp)
/* A03E1C 802415DC 8FB00010 */  lw        $s0, 0x10($sp)
/* A03E20 802415E0 03E00008 */  jr        $ra
/* A03E24 802415E4 27BD0020 */   addiu    $sp, $sp, 0x20
