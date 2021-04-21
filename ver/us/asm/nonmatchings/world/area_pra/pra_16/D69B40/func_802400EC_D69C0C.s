.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pra_16_ReflectWall
/* D69C0C 802400EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D69C10 802400F0 AFB00010 */  sw        $s0, 0x10($sp)
/* D69C14 802400F4 0080802D */  daddu     $s0, $a0, $zero
/* D69C18 802400F8 3C058024 */  lui       $a1, %hi(func_80240128_D69C48)
/* D69C1C 802400FC 24A50128 */  addiu     $a1, $a1, %lo(func_80240128_D69C48)
/* D69C20 80240100 AFBF0014 */  sw        $ra, 0x14($sp)
/* D69C24 80240104 0C048C56 */  jal       create_dynamic_entity_world
/* D69C28 80240108 0000202D */   daddu    $a0, $zero, $zero
/* D69C2C 8024010C 8E03013C */  lw        $v1, 0x13c($s0)
/* D69C30 80240110 AC620000 */  sw        $v0, ($v1)
/* D69C34 80240114 8FBF0014 */  lw        $ra, 0x14($sp)
/* D69C38 80240118 8FB00010 */  lw        $s0, 0x10($sp)
/* D69C3C 8024011C 24020002 */  addiu     $v0, $zero, 2
/* D69C40 80240120 03E00008 */  jr        $ra
/* D69C44 80240124 27BD0018 */   addiu    $sp, $sp, 0x18
