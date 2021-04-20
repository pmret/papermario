.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024011C_D9181C
/* D9181C 8024011C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D91820 80240120 AFB00010 */  sw        $s0, 0x10($sp)
/* D91824 80240124 0080802D */  daddu     $s0, $a0, $zero
/* D91828 80240128 3C058024 */  lui       $a1, %hi(func_80240158_D91858)
/* D9182C 8024012C 24A50158 */  addiu     $a1, $a1, %lo(func_80240158_D91858)
/* D91830 80240130 AFBF0014 */  sw        $ra, 0x14($sp)
/* D91834 80240134 0C048C56 */  jal       create_dynamic_entity_world
/* D91838 80240138 0000202D */   daddu    $a0, $zero, $zero
/* D9183C 8024013C 8E03013C */  lw        $v1, 0x13c($s0)
/* D91840 80240140 AC620000 */  sw        $v0, ($v1)
/* D91844 80240144 8FBF0014 */  lw        $ra, 0x14($sp)
/* D91848 80240148 8FB00010 */  lw        $s0, 0x10($sp)
/* D9184C 8024014C 24020002 */  addiu     $v0, $zero, 2
/* D91850 80240150 03E00008 */  jr        $ra
/* D91854 80240154 27BD0018 */   addiu    $sp, $sp, 0x18
