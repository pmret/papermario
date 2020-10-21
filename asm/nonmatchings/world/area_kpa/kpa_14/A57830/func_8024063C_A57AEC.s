.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024063C_A57AEC
/* A57AEC 8024063C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A57AF0 80240640 AFBF0010 */  sw        $ra, 0x10($sp)
/* A57AF4 80240644 0C04417A */  jal       get_entity_by_index
/* A57AF8 80240648 8C840084 */   lw       $a0, 0x84($a0)
/* A57AFC 8024064C 0040182D */  daddu     $v1, $v0, $zero
/* A57B00 80240650 8C640000 */  lw        $a0, ($v1)
/* A57B04 80240654 3C050010 */  lui       $a1, 0x10
/* A57B08 80240658 00852025 */  or        $a0, $a0, $a1
/* A57B0C 8024065C AC640000 */  sw        $a0, ($v1)
/* A57B10 80240660 8FBF0010 */  lw        $ra, 0x10($sp)
/* A57B14 80240664 24020002 */  addiu     $v0, $zero, 2
/* A57B18 80240668 03E00008 */  jr        $ra
/* A57B1C 8024066C 27BD0018 */   addiu    $sp, $sp, 0x18
