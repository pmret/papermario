.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024011C_D62E2C
/* D62E2C 8024011C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D62E30 80240120 AFB00010 */  sw        $s0, 0x10($sp)
/* D62E34 80240124 0080802D */  daddu     $s0, $a0, $zero
/* D62E38 80240128 3C058024 */  lui       $a1, 0x8024
/* D62E3C 8024012C 24A50158 */  addiu     $a1, $a1, 0x158
/* D62E40 80240130 AFBF0014 */  sw        $ra, 0x14($sp)
/* D62E44 80240134 0C048C56 */  jal       bind_dynamic_entity_3
/* D62E48 80240138 0000202D */   daddu    $a0, $zero, $zero
/* D62E4C 8024013C 8E03013C */  lw        $v1, 0x13c($s0)
/* D62E50 80240140 AC620000 */  sw        $v0, ($v1)
/* D62E54 80240144 8FBF0014 */  lw        $ra, 0x14($sp)
/* D62E58 80240148 8FB00010 */  lw        $s0, 0x10($sp)
/* D62E5C 8024014C 24020002 */  addiu     $v0, $zero, 2
/* D62E60 80240150 03E00008 */  jr        $ra
/* D62E64 80240154 27BD0018 */   addiu    $sp, $sp, 0x18
