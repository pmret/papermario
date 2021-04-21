.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pra_27_ReflectWall
/* D79B0C 8024011C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D79B10 80240120 AFB00010 */  sw        $s0, 0x10($sp)
/* D79B14 80240124 0080802D */  daddu     $s0, $a0, $zero
/* D79B18 80240128 3C058024 */  lui       $a1, %hi(func_80240158_D79B48)
/* D79B1C 8024012C 24A50158 */  addiu     $a1, $a1, %lo(func_80240158_D79B48)
/* D79B20 80240130 AFBF0014 */  sw        $ra, 0x14($sp)
/* D79B24 80240134 0C048C56 */  jal       create_dynamic_entity_world
/* D79B28 80240138 0000202D */   daddu    $a0, $zero, $zero
/* D79B2C 8024013C 8E03013C */  lw        $v1, 0x13c($s0)
/* D79B30 80240140 AC620000 */  sw        $v0, ($v1)
/* D79B34 80240144 8FBF0014 */  lw        $ra, 0x14($sp)
/* D79B38 80240148 8FB00010 */  lw        $s0, 0x10($sp)
/* D79B3C 8024014C 24020002 */  addiu     $v0, $zero, 2
/* D79B40 80240150 03E00008 */  jr        $ra
/* D79B44 80240154 27BD0018 */   addiu    $sp, $sp, 0x18
