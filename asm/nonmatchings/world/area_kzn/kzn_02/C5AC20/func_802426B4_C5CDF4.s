.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802426B4_C5CDF4
/* C5CDF4 802426B4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C5CDF8 802426B8 AFB00010 */  sw        $s0, 0x10($sp)
/* C5CDFC 802426BC 0080802D */  daddu     $s0, $a0, $zero
/* C5CE00 802426C0 AFBF0014 */  sw        $ra, 0x14($sp)
/* C5CE04 802426C4 0C00EABB */  jal       get_npc_unsafe
/* C5CE08 802426C8 8E04008C */   lw       $a0, 0x8c($s0)
/* C5CE0C 802426CC 0040282D */  daddu     $a1, $v0, $zero
/* C5CE10 802426D0 8E040094 */  lw        $a0, 0x94($s0)
/* C5CE14 802426D4 8CA30028 */  lw        $v1, 0x28($a1)
/* C5CE18 802426D8 ACA40028 */  sw        $a0, 0x28($a1)
/* C5CE1C 802426DC 8FBF0014 */  lw        $ra, 0x14($sp)
/* C5CE20 802426E0 8FB00010 */  lw        $s0, 0x10($sp)
/* C5CE24 802426E4 24020002 */  addiu     $v0, $zero, 2
/* C5CE28 802426E8 3C018024 */  lui       $at, 0x8024
/* C5CE2C 802426EC AC236794 */  sw        $v1, 0x6794($at)
/* C5CE30 802426F0 03E00008 */  jr        $ra
/* C5CE34 802426F4 27BD0018 */   addiu    $sp, $sp, 0x18
