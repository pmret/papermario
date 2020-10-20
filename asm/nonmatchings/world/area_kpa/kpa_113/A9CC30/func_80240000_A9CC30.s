.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_A9CC30
/* A9CC30 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A9CC34 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* A9CC38 80240008 0C04417A */  jal       get_entity_by_index
/* A9CC3C 8024000C 8C840084 */   lw       $a0, 0x84($a0)
/* A9CC40 80240010 0040182D */  daddu     $v1, $v0, $zero
/* A9CC44 80240014 8C640000 */  lw        $a0, ($v1)
/* A9CC48 80240018 3C050010 */  lui       $a1, 0x10
/* A9CC4C 8024001C 00852025 */  or        $a0, $a0, $a1
/* A9CC50 80240020 AC640000 */  sw        $a0, ($v1)
/* A9CC54 80240024 8FBF0010 */  lw        $ra, 0x10($sp)
/* A9CC58 80240028 24020002 */  addiu     $v0, $zero, 2
/* A9CC5C 8024002C 03E00008 */  jr        $ra
/* A9CC60 80240030 27BD0018 */   addiu    $sp, $sp, 0x18
/* A9CC64 80240034 00000000 */  nop       
/* A9CC68 80240038 00000000 */  nop       
/* A9CC6C 8024003C 00000000 */  nop       
