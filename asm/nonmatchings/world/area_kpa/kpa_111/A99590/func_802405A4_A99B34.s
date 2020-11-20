.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel UnkSetDurationFunc
/* A99B34 802405A4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A99B38 802405A8 AFB10014 */  sw        $s1, 0x14($sp)
/* A99B3C 802405AC 0080882D */  daddu     $s1, $a0, $zero
/* A99B40 802405B0 AFBF0018 */  sw        $ra, 0x18($sp)
/* A99B44 802405B4 AFB00010 */  sw        $s0, 0x10($sp)
/* A99B48 802405B8 8E300148 */  lw        $s0, 0x148($s1)
/* A99B4C 802405BC 0C00EABB */  jal       get_npc_unsafe
/* A99B50 802405C0 86040008 */   lh       $a0, 8($s0)
/* A99B54 802405C4 96030076 */  lhu       $v1, 0x76($s0)
/* A99B58 802405C8 A443008E */  sh        $v1, 0x8e($v0)
/* A99B5C 802405CC 24020021 */  addiu     $v0, $zero, 0x21
/* A99B60 802405D0 AE220070 */  sw        $v0, 0x70($s1)
/* A99B64 802405D4 8FBF0018 */  lw        $ra, 0x18($sp)
/* A99B68 802405D8 8FB10014 */  lw        $s1, 0x14($sp)
/* A99B6C 802405DC 8FB00010 */  lw        $s0, 0x10($sp)
/* A99B70 802405E0 03E00008 */  jr        $ra
/* A99B74 802405E4 27BD0020 */   addiu    $sp, $sp, 0x20
