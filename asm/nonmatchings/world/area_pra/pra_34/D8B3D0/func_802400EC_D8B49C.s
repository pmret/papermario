.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400EC_D8B49C
/* D8B49C 802400EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D8B4A0 802400F0 AFB00010 */  sw        $s0, 0x10($sp)
/* D8B4A4 802400F4 0080802D */  daddu     $s0, $a0, $zero
/* D8B4A8 802400F8 3C058024 */  lui       $a1, 0x8024
/* D8B4AC 802400FC 24A50128 */  addiu     $a1, $a1, 0x128
/* D8B4B0 80240100 AFBF0014 */  sw        $ra, 0x14($sp)
/* D8B4B4 80240104 0C048C56 */  jal       bind_dynamic_entity_3
/* D8B4B8 80240108 0000202D */   daddu    $a0, $zero, $zero
/* D8B4BC 8024010C 8E03013C */  lw        $v1, 0x13c($s0)
/* D8B4C0 80240110 AC620000 */  sw        $v0, ($v1)
/* D8B4C4 80240114 8FBF0014 */  lw        $ra, 0x14($sp)
/* D8B4C8 80240118 8FB00010 */  lw        $s0, 0x10($sp)
/* D8B4CC 8024011C 24020002 */  addiu     $v0, $zero, 2
/* D8B4D0 80240120 03E00008 */  jr        $ra
/* D8B4D4 80240124 27BD0018 */   addiu    $sp, $sp, 0x18
