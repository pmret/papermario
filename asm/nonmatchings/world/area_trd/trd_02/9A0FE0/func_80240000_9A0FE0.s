.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_9A0FE0
/* 9A0FE0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9A0FE4 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9A0FE8 80240008 0C04417A */  jal       get_entity_by_index
/* 9A0FEC 8024000C 8C840084 */   lw       $a0, 0x84($a0)
/* 9A0FF0 80240010 0040182D */  daddu     $v1, $v0, $zero
/* 9A0FF4 80240014 8C640000 */  lw        $a0, ($v1)
/* 9A0FF8 80240018 3C050010 */  lui       $a1, 0x10
/* 9A0FFC 8024001C 00852025 */  or        $a0, $a0, $a1
/* 9A1000 80240020 AC640000 */  sw        $a0, ($v1)
/* 9A1004 80240024 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9A1008 80240028 24020002 */  addiu     $v0, $zero, 2
/* 9A100C 8024002C 03E00008 */  jr        $ra
/* 9A1010 80240030 27BD0018 */   addiu    $sp, $sp, 0x18
