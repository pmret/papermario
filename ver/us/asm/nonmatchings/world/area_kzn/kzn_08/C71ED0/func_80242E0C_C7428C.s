.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242E0C_C7428C
/* C7428C 80242E0C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C74290 80242E10 AFB10014 */  sw        $s1, 0x14($sp)
/* C74294 80242E14 0080882D */  daddu     $s1, $a0, $zero
/* C74298 80242E18 AFBF0018 */  sw        $ra, 0x18($sp)
/* C7429C 80242E1C AFB00010 */  sw        $s0, 0x10($sp)
/* C742A0 80242E20 8E300148 */  lw        $s0, 0x148($s1)
/* C742A4 80242E24 0C00EABB */  jal       get_npc_unsafe
/* C742A8 80242E28 86040008 */   lh       $a0, 8($s0)
/* C742AC 80242E2C 0040202D */  daddu     $a0, $v0, $zero
/* C742B0 80242E30 8482008E */  lh        $v0, 0x8e($a0)
/* C742B4 80242E34 9483008E */  lhu       $v1, 0x8e($a0)
/* C742B8 80242E38 18400003 */  blez      $v0, .L80242E48
/* C742BC 80242E3C 2462FFFF */   addiu    $v0, $v1, -1
/* C742C0 80242E40 08090B99 */  j         .L80242E64
/* C742C4 80242E44 A482008E */   sh       $v0, 0x8e($a0)
.L80242E48:
/* C742C8 80242E48 8E0200CC */  lw        $v0, 0xcc($s0)
/* C742CC 80242E4C AE00006C */  sw        $zero, 0x6c($s0)
/* C742D0 80242E50 8C420000 */  lw        $v0, ($v0)
/* C742D4 80242E54 AC820028 */  sw        $v0, 0x28($a0)
/* C742D8 80242E58 24020001 */  addiu     $v0, $zero, 1
/* C742DC 80242E5C AE200074 */  sw        $zero, 0x74($s1)
/* C742E0 80242E60 AE220070 */  sw        $v0, 0x70($s1)
.L80242E64:
/* C742E4 80242E64 8FBF0018 */  lw        $ra, 0x18($sp)
/* C742E8 80242E68 8FB10014 */  lw        $s1, 0x14($sp)
/* C742EC 80242E6C 8FB00010 */  lw        $s0, 0x10($sp)
/* C742F0 80242E70 03E00008 */  jr        $ra
/* C742F4 80242E74 27BD0020 */   addiu    $sp, $sp, 0x20
