.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408F0_823BB0
/* 823BB0 802408F0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 823BB4 802408F4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 823BB8 802408F8 0C04417A */  jal       get_entity_by_index
/* 823BBC 802408FC 8C840084 */   lw       $a0, 0x84($a0)
/* 823BC0 80240900 0040182D */  daddu     $v1, $v0, $zero
/* 823BC4 80240904 8C640000 */  lw        $a0, ($v1)
/* 823BC8 80240908 3C050010 */  lui       $a1, 0x10
/* 823BCC 8024090C 00852025 */  or        $a0, $a0, $a1
/* 823BD0 80240910 AC640000 */  sw        $a0, ($v1)
/* 823BD4 80240914 8FBF0010 */  lw        $ra, 0x10($sp)
/* 823BD8 80240918 24020002 */  addiu     $v0, $zero, 2
/* 823BDC 8024091C 03E00008 */  jr        $ra
/* 823BE0 80240920 27BD0018 */   addiu    $sp, $sp, 0x18
/* 823BE4 80240924 00000000 */  nop       
/* 823BE8 80240928 00000000 */  nop       
/* 823BEC 8024092C 00000000 */  nop       
