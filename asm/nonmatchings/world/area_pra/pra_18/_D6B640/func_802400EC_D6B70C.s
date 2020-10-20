.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400EC_D6B70C
/* D6B70C 802400EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D6B710 802400F0 AFB00010 */  sw        $s0, 0x10($sp)
/* D6B714 802400F4 0080802D */  daddu     $s0, $a0, $zero
/* D6B718 802400F8 3C058024 */  lui       $a1, 0x8024
/* D6B71C 802400FC 24A50128 */  addiu     $a1, $a1, 0x128
/* D6B720 80240100 AFBF0014 */  sw        $ra, 0x14($sp)
/* D6B724 80240104 0C048C56 */  jal       bind_dynamic_entity_3
/* D6B728 80240108 0000202D */   daddu    $a0, $zero, $zero
/* D6B72C 8024010C 8E03013C */  lw        $v1, 0x13c($s0)
/* D6B730 80240110 AC620000 */  sw        $v0, ($v1)
/* D6B734 80240114 8FBF0014 */  lw        $ra, 0x14($sp)
/* D6B738 80240118 8FB00010 */  lw        $s0, 0x10($sp)
/* D6B73C 8024011C 24020002 */  addiu     $v0, $zero, 2
/* D6B740 80240120 03E00008 */  jr        $ra
/* D6B744 80240124 27BD0018 */   addiu    $sp, $sp, 0x18
