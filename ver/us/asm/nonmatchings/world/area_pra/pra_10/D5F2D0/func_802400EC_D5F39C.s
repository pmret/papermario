.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pra_10_ReflectWall
/* D5F39C 802400EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D5F3A0 802400F0 AFB00010 */  sw        $s0, 0x10($sp)
/* D5F3A4 802400F4 0080802D */  daddu     $s0, $a0, $zero
/* D5F3A8 802400F8 3C058024 */  lui       $a1, %hi(func_80240128_D5F3D8)
/* D5F3AC 802400FC 24A50128 */  addiu     $a1, $a1, %lo(func_80240128_D5F3D8)
/* D5F3B0 80240100 AFBF0014 */  sw        $ra, 0x14($sp)
/* D5F3B4 80240104 0C048C56 */  jal       create_dynamic_entity_world
/* D5F3B8 80240108 0000202D */   daddu    $a0, $zero, $zero
/* D5F3BC 8024010C 8E03013C */  lw        $v1, 0x13c($s0)
/* D5F3C0 80240110 AC620000 */  sw        $v0, ($v1)
/* D5F3C4 80240114 8FBF0014 */  lw        $ra, 0x14($sp)
/* D5F3C8 80240118 8FB00010 */  lw        $s0, 0x10($sp)
/* D5F3CC 8024011C 24020002 */  addiu     $v0, $zero, 2
/* D5F3D0 80240120 03E00008 */  jr        $ra
/* D5F3D4 80240124 27BD0018 */   addiu    $sp, $sp, 0x18
