.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024011C_D9305C
/* D9305C 8024011C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D93060 80240120 AFB00010 */  sw        $s0, 0x10($sp)
/* D93064 80240124 0080802D */  daddu     $s0, $a0, $zero
/* D93068 80240128 3C058024 */  lui       $a1, %hi(func_80240158_D92F7C)
/* D9306C 8024012C 24A50158 */  addiu     $a1, $a1, %lo(func_80240158_D92F7C)
/* D93070 80240130 AFBF0014 */  sw        $ra, 0x14($sp)
/* D93074 80240134 0C048C56 */  jal       bind_dynamic_entity_3
/* D93078 80240138 0000202D */   daddu    $a0, $zero, $zero
/* D9307C 8024013C 8E03013C */  lw        $v1, 0x13c($s0)
/* D93080 80240140 AC620000 */  sw        $v0, ($v1)
/* D93084 80240144 8FBF0014 */  lw        $ra, 0x14($sp)
/* D93088 80240148 8FB00010 */  lw        $s0, 0x10($sp)
/* D9308C 8024014C 24020002 */  addiu     $v0, $zero, 2
/* D93090 80240150 03E00008 */  jr        $ra
/* D93094 80240154 27BD0018 */   addiu    $sp, $sp, 0x18
