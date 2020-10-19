.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240584_D37D84
/* D37D84 80240584 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D37D88 80240588 AFB10014 */  sw        $s1, 0x14($sp)
/* D37D8C 8024058C 0080882D */  daddu     $s1, $a0, $zero
/* D37D90 80240590 AFBF0018 */  sw        $ra, 0x18($sp)
/* D37D94 80240594 AFB00010 */  sw        $s0, 0x10($sp)
/* D37D98 80240598 8E300148 */  lw        $s0, 0x148($s1)
/* D37D9C 8024059C 0C00EABB */  jal       get_npc_unsafe
/* D37DA0 802405A0 86040008 */   lh       $a0, 8($s0)
/* D37DA4 802405A4 9443008E */  lhu       $v1, 0x8e($v0)
/* D37DA8 802405A8 2463FFFF */  addiu     $v1, $v1, -1
/* D37DAC 802405AC A443008E */  sh        $v1, 0x8e($v0)
/* D37DB0 802405B0 00031C00 */  sll       $v1, $v1, 0x10
/* D37DB4 802405B4 1C600003 */  bgtz      $v1, .L802405C4
/* D37DB8 802405B8 2402000C */   addiu    $v0, $zero, 0xc
/* D37DBC 802405BC AE00006C */  sw        $zero, 0x6c($s0)
/* D37DC0 802405C0 AE220070 */  sw        $v0, 0x70($s1)
.L802405C4:
/* D37DC4 802405C4 8FBF0018 */  lw        $ra, 0x18($sp)
/* D37DC8 802405C8 8FB10014 */  lw        $s1, 0x14($sp)
/* D37DCC 802405CC 8FB00010 */  lw        $s0, 0x10($sp)
/* D37DD0 802405D0 03E00008 */  jr        $ra
/* D37DD4 802405D4 27BD0020 */   addiu    $sp, $sp, 0x20
