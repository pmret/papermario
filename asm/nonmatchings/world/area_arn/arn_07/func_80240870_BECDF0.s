.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240870_BED660
/* BED660 80240870 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BED664 80240874 AFBF0010 */  sw        $ra, 0x10($sp)
/* BED668 80240878 0C04417A */  jal       get_entity_by_index
/* BED66C 8024087C 8C840084 */   lw       $a0, 0x84($a0)
/* BED670 80240880 0040182D */  daddu     $v1, $v0, $zero
/* BED674 80240884 8C640000 */  lw        $a0, ($v1)
/* BED678 80240888 3C050010 */  lui       $a1, 0x10
/* BED67C 8024088C 00852025 */  or        $a0, $a0, $a1
/* BED680 80240890 AC640000 */  sw        $a0, ($v1)
/* BED684 80240894 8FBF0010 */  lw        $ra, 0x10($sp)
/* BED688 80240898 24020002 */  addiu     $v0, $zero, 2
/* BED68C 8024089C 03E00008 */  jr        $ra
/* BED690 802408A0 27BD0018 */   addiu    $sp, $sp, 0x18
