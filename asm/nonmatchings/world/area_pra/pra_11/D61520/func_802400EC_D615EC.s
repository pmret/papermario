.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400EC_D615EC
/* D615EC 802400EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D615F0 802400F0 AFB00010 */  sw        $s0, 0x10($sp)
/* D615F4 802400F4 0080802D */  daddu     $s0, $a0, $zero
/* D615F8 802400F8 3C058024 */  lui       $a1, %hi(func_80240128_D61628)
/* D615FC 802400FC 24A50128 */  addiu     $a1, $a1, %lo(func_80240128_D61628)
/* D61600 80240100 AFBF0014 */  sw        $ra, 0x14($sp)
/* D61604 80240104 0C048C56 */  jal       bind_dynamic_entity_3
/* D61608 80240108 0000202D */   daddu    $a0, $zero, $zero
/* D6160C 8024010C 8E03013C */  lw        $v1, 0x13c($s0)
/* D61610 80240110 AC620000 */  sw        $v0, ($v1)
/* D61614 80240114 8FBF0014 */  lw        $ra, 0x14($sp)
/* D61618 80240118 8FB00010 */  lw        $s0, 0x10($sp)
/* D6161C 8024011C 24020002 */  addiu     $v0, $zero, 2
/* D61620 80240120 03E00008 */  jr        $ra
/* D61624 80240124 27BD0018 */   addiu    $sp, $sp, 0x18
