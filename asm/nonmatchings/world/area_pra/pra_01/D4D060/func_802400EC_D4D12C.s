.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400EC_D4D12C
/* D4D12C 802400EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D4D130 802400F0 AFB00010 */  sw        $s0, 0x10($sp)
/* D4D134 802400F4 0080802D */  daddu     $s0, $a0, $zero
/* D4D138 802400F8 3C058024 */  lui       $a1, 0x8024
/* D4D13C 802400FC 24A50128 */  addiu     $a1, $a1, 0x128
/* D4D140 80240100 AFBF0014 */  sw        $ra, 0x14($sp)
/* D4D144 80240104 0C048C56 */  jal       bind_dynamic_entity_3
/* D4D148 80240108 0000202D */   daddu    $a0, $zero, $zero
/* D4D14C 8024010C 8E03013C */  lw        $v1, 0x13c($s0)
/* D4D150 80240110 AC620000 */  sw        $v0, ($v1)
/* D4D154 80240114 8FBF0014 */  lw        $ra, 0x14($sp)
/* D4D158 80240118 8FB00010 */  lw        $s0, 0x10($sp)
/* D4D15C 8024011C 24020002 */  addiu     $v0, $zero, 2
/* D4D160 80240120 03E00008 */  jr        $ra
/* D4D164 80240124 27BD0018 */   addiu    $sp, $sp, 0x18
