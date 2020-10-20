.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D40_D309C0
/* D309C0 80240D40 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D309C4 80240D44 AFB10014 */  sw        $s1, 0x14($sp)
/* D309C8 80240D48 0080882D */  daddu     $s1, $a0, $zero
/* D309CC 80240D4C AFBF0018 */  sw        $ra, 0x18($sp)
/* D309D0 80240D50 AFB00010 */  sw        $s0, 0x10($sp)
/* D309D4 80240D54 8E300148 */  lw        $s0, 0x148($s1)
/* D309D8 80240D58 0C00EABB */  jal       get_npc_unsafe
/* D309DC 80240D5C 86040008 */   lh       $a0, 8($s0)
/* D309E0 80240D60 24030001 */  addiu     $v1, $zero, 1
/* D309E4 80240D64 0040202D */  daddu     $a0, $v0, $zero
/* D309E8 80240D68 AE03006C */  sw        $v1, 0x6c($s0)
/* D309EC 80240D6C 8482008C */  lh        $v0, 0x8c($a0)
/* D309F0 80240D70 14400009 */  bnez      $v0, .L80240D98
/* D309F4 80240D74 24020002 */   addiu    $v0, $zero, 2
/* D309F8 80240D78 96030072 */  lhu       $v1, 0x72($s0)
/* D309FC 80240D7C AE02006C */  sw        $v0, 0x6c($s0)
/* D30A00 80240D80 A483008E */  sh        $v1, 0x8e($a0)
/* D30A04 80240D84 8E0200CC */  lw        $v0, 0xcc($s0)
/* D30A08 80240D88 8C420020 */  lw        $v0, 0x20($v0)
/* D30A0C 80240D8C AC820028 */  sw        $v0, 0x28($a0)
/* D30A10 80240D90 2402001F */  addiu     $v0, $zero, 0x1f
/* D30A14 80240D94 AE220070 */  sw        $v0, 0x70($s1)
.L80240D98:
/* D30A18 80240D98 8FBF0018 */  lw        $ra, 0x18($sp)
/* D30A1C 80240D9C 8FB10014 */  lw        $s1, 0x14($sp)
/* D30A20 80240DA0 8FB00010 */  lw        $s0, 0x10($sp)
/* D30A24 80240DA4 03E00008 */  jr        $ra
/* D30A28 80240DA8 27BD0020 */   addiu    $sp, $sp, 0x20
