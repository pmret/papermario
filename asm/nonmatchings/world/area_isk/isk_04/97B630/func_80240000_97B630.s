.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_97B630
/* 97B630 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 97B634 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* 97B638 80240008 0C04417A */  jal       get_entity_by_index
/* 97B63C 8024000C 8C840084 */   lw       $a0, 0x84($a0)
/* 97B640 80240010 0040182D */  daddu     $v1, $v0, $zero
/* 97B644 80240014 8C640000 */  lw        $a0, ($v1)
/* 97B648 80240018 3C050010 */  lui       $a1, 0x10
/* 97B64C 8024001C 00852025 */  or        $a0, $a0, $a1
/* 97B650 80240020 AC640000 */  sw        $a0, ($v1)
/* 97B654 80240024 8FBF0010 */  lw        $ra, 0x10($sp)
/* 97B658 80240028 24020002 */  addiu     $v0, $zero, 2
/* 97B65C 8024002C 03E00008 */  jr        $ra
/* 97B660 80240030 27BD0018 */   addiu    $sp, $sp, 0x18
/* 97B664 80240034 00000000 */  nop       
/* 97B668 80240038 00000000 */  nop       
/* 97B66C 8024003C 00000000 */  nop       
