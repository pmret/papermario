.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_A6CB00
/* A6CB00 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A6CB04 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* A6CB08 80240008 0C04417A */  jal       get_entity_by_index
/* A6CB0C 8024000C 8C840084 */   lw       $a0, 0x84($a0)
/* A6CB10 80240010 0040182D */  daddu     $v1, $v0, $zero
/* A6CB14 80240014 8C640000 */  lw        $a0, ($v1)
/* A6CB18 80240018 3C050010 */  lui       $a1, 0x10
/* A6CB1C 8024001C 00852025 */  or        $a0, $a0, $a1
/* A6CB20 80240020 AC640000 */  sw        $a0, ($v1)
/* A6CB24 80240024 8FBF0010 */  lw        $ra, 0x10($sp)
/* A6CB28 80240028 24020002 */  addiu     $v0, $zero, 2
/* A6CB2C 8024002C 03E00008 */  jr        $ra
/* A6CB30 80240030 27BD0018 */   addiu    $sp, $sp, 0x18
