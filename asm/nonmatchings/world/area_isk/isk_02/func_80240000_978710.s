.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_978710
/* 978710 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 978714 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* 978718 80240008 0C04417A */  jal       get_entity_by_index
/* 97871C 8024000C 8C840084 */   lw       $a0, 0x84($a0)
/* 978720 80240010 0040182D */  daddu     $v1, $v0, $zero
/* 978724 80240014 8C640000 */  lw        $a0, ($v1)
/* 978728 80240018 3C050010 */  lui       $a1, 0x10
/* 97872C 8024001C 00852025 */  or        $a0, $a0, $a1
/* 978730 80240020 AC640000 */  sw        $a0, ($v1)
/* 978734 80240024 8FBF0010 */  lw        $ra, 0x10($sp)
/* 978738 80240028 24020002 */  addiu     $v0, $zero, 2
/* 97873C 8024002C 03E00008 */  jr        $ra
/* 978740 80240030 27BD0018 */   addiu    $sp, $sp, 0x18
/* 978744 80240034 00000000 */  nop       
/* 978748 80240038 00000000 */  nop       
/* 97874C 8024003C 00000000 */  nop       
