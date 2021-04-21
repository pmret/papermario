.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pra_09_ReflectWall
/* D5897C 802400EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D58980 802400F0 AFB00010 */  sw        $s0, 0x10($sp)
/* D58984 802400F4 0080802D */  daddu     $s0, $a0, $zero
/* D58988 802400F8 3C058024 */  lui       $a1, %hi(func_80240128_D589B8)
/* D5898C 802400FC 24A50128 */  addiu     $a1, $a1, %lo(func_80240128_D589B8)
/* D58990 80240100 AFBF0014 */  sw        $ra, 0x14($sp)
/* D58994 80240104 0C048C56 */  jal       create_dynamic_entity_world
/* D58998 80240108 0000202D */   daddu    $a0, $zero, $zero
/* D5899C 8024010C 8E03013C */  lw        $v1, 0x13c($s0)
/* D589A0 80240110 AC620000 */  sw        $v0, ($v1)
/* D589A4 80240114 8FBF0014 */  lw        $ra, 0x14($sp)
/* D589A8 80240118 8FB00010 */  lw        $s0, 0x10($sp)
/* D589AC 8024011C 24020002 */  addiu     $v0, $zero, 2
/* D589B0 80240120 03E00008 */  jr        $ra
/* D589B4 80240124 27BD0018 */   addiu    $sp, $sp, 0x18
