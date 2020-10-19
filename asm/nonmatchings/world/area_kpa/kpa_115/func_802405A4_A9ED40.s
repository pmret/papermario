.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405A4_A9F2E4
/* A9F2E4 802405A4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A9F2E8 802405A8 AFB10014 */  sw        $s1, 0x14($sp)
/* A9F2EC 802405AC 0080882D */  daddu     $s1, $a0, $zero
/* A9F2F0 802405B0 AFBF0018 */  sw        $ra, 0x18($sp)
/* A9F2F4 802405B4 AFB00010 */  sw        $s0, 0x10($sp)
/* A9F2F8 802405B8 8E300148 */  lw        $s0, 0x148($s1)
/* A9F2FC 802405BC 0C00EABB */  jal       get_npc_unsafe
/* A9F300 802405C0 86040008 */   lh       $a0, 8($s0)
/* A9F304 802405C4 96030076 */  lhu       $v1, 0x76($s0)
/* A9F308 802405C8 A443008E */  sh        $v1, 0x8e($v0)
/* A9F30C 802405CC 24020021 */  addiu     $v0, $zero, 0x21
/* A9F310 802405D0 AE220070 */  sw        $v0, 0x70($s1)
/* A9F314 802405D4 8FBF0018 */  lw        $ra, 0x18($sp)
/* A9F318 802405D8 8FB10014 */  lw        $s1, 0x14($sp)
/* A9F31C 802405DC 8FB00010 */  lw        $s0, 0x10($sp)
/* A9F320 802405E0 03E00008 */  jr        $ra
/* A9F324 802405E4 27BD0020 */   addiu    $sp, $sp, 0x20
