.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240570_BA4CF0
/* BA4CF0 80240570 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BA4CF4 80240574 AFB10014 */  sw        $s1, 0x14($sp)
/* BA4CF8 80240578 0080882D */  daddu     $s1, $a0, $zero
/* BA4CFC 8024057C AFBF0018 */  sw        $ra, 0x18($sp)
/* BA4D00 80240580 AFB00010 */  sw        $s0, 0x10($sp)
/* BA4D04 80240584 8E300148 */  lw        $s0, 0x148($s1)
/* BA4D08 80240588 0C00EABB */  jal       get_npc_unsafe
/* BA4D0C 8024058C 86040008 */   lh       $a0, 8($s0)
/* BA4D10 80240590 24030001 */  addiu     $v1, $zero, 1
/* BA4D14 80240594 0040202D */  daddu     $a0, $v0, $zero
/* BA4D18 80240598 AE03006C */  sw        $v1, 0x6c($s0)
/* BA4D1C 8024059C 8482008C */  lh        $v0, 0x8c($a0)
/* BA4D20 802405A0 14400009 */  bnez      $v0, .L802405C8
/* BA4D24 802405A4 24020002 */   addiu    $v0, $zero, 2
/* BA4D28 802405A8 96030072 */  lhu       $v1, 0x72($s0)
/* BA4D2C 802405AC AE02006C */  sw        $v0, 0x6c($s0)
/* BA4D30 802405B0 A483008E */  sh        $v1, 0x8e($a0)
/* BA4D34 802405B4 8E0200CC */  lw        $v0, 0xcc($s0)
/* BA4D38 802405B8 8C420020 */  lw        $v0, 0x20($v0)
/* BA4D3C 802405BC AC820028 */  sw        $v0, 0x28($a0)
/* BA4D40 802405C0 2402001F */  addiu     $v0, $zero, 0x1f
/* BA4D44 802405C4 AE220070 */  sw        $v0, 0x70($s1)
.L802405C8:
/* BA4D48 802405C8 8FBF0018 */  lw        $ra, 0x18($sp)
/* BA4D4C 802405CC 8FB10014 */  lw        $s1, 0x14($sp)
/* BA4D50 802405D0 8FB00010 */  lw        $s0, 0x10($sp)
/* BA4D54 802405D4 03E00008 */  jr        $ra
/* BA4D58 802405D8 27BD0020 */   addiu    $sp, $sp, 0x20
