.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240120_98AB30
/* 98AB30 80240120 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 98AB34 80240124 AFBF0010 */  sw        $ra, 0x10($sp)
/* 98AB38 80240128 0C04417A */  jal       get_entity_by_index
/* 98AB3C 8024012C 8C840084 */   lw       $a0, 0x84($a0)
/* 98AB40 80240130 0040182D */  daddu     $v1, $v0, $zero
/* 98AB44 80240134 8C640000 */  lw        $a0, ($v1)
/* 98AB48 80240138 3C050010 */  lui       $a1, 0x10
/* 98AB4C 8024013C 00852025 */  or        $a0, $a0, $a1
/* 98AB50 80240140 AC640000 */  sw        $a0, ($v1)
/* 98AB54 80240144 8FBF0010 */  lw        $ra, 0x10($sp)
/* 98AB58 80240148 24020002 */  addiu     $v0, $zero, 2
/* 98AB5C 8024014C 03E00008 */  jr        $ra
/* 98AB60 80240150 27BD0018 */   addiu    $sp, $sp, 0x18
/* 98AB64 80240154 00000000 */  nop       
/* 98AB68 80240158 00000000 */  nop       
/* 98AB6C 8024015C 00000000 */  nop       
