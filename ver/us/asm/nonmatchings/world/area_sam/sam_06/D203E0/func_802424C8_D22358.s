.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802424C8_D22358
/* D22358 802424C8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D2235C 802424CC AFB00010 */  sw        $s0, 0x10($sp)
/* D22360 802424D0 0080802D */  daddu     $s0, $a0, $zero
/* D22364 802424D4 AFBF0014 */  sw        $ra, 0x14($sp)
/* D22368 802424D8 0C00EABB */  jal       get_npc_unsafe
/* D2236C 802424DC 8E04008C */   lw       $a0, 0x8c($s0)
/* D22370 802424E0 0040282D */  daddu     $a1, $v0, $zero
/* D22374 802424E4 8E040094 */  lw        $a0, 0x94($s0)
/* D22378 802424E8 8CA30028 */  lw        $v1, 0x28($a1)
/* D2237C 802424EC ACA40028 */  sw        $a0, 0x28($a1)
/* D22380 802424F0 8FBF0014 */  lw        $ra, 0x14($sp)
/* D22384 802424F4 8FB00010 */  lw        $s0, 0x10($sp)
/* D22388 802424F8 24020002 */  addiu     $v0, $zero, 2
/* D2238C 802424FC 3C018025 */  lui       $at, %hi(D_8024C1D8)
/* D22390 80242500 AC23C1D8 */  sw        $v1, %lo(D_8024C1D8)($at)
/* D22394 80242504 03E00008 */  jr        $ra
/* D22398 80242508 27BD0018 */   addiu    $sp, $sp, 0x18
