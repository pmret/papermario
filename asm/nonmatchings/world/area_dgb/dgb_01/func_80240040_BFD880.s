.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_BFD8C0
/* BFD8C0 80240040 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BFD8C4 80240044 AFBF0010 */  sw        $ra, 0x10($sp)
/* BFD8C8 80240048 0C04417A */  jal       get_entity_by_index
/* BFD8CC 8024004C 8C840084 */   lw       $a0, 0x84($a0)
/* BFD8D0 80240050 0040182D */  daddu     $v1, $v0, $zero
/* BFD8D4 80240054 8C640000 */  lw        $a0, ($v1)
/* BFD8D8 80240058 3C050010 */  lui       $a1, 0x10
/* BFD8DC 8024005C 00852025 */  or        $a0, $a0, $a1
/* BFD8E0 80240060 AC640000 */  sw        $a0, ($v1)
/* BFD8E4 80240064 8FBF0010 */  lw        $ra, 0x10($sp)
/* BFD8E8 80240068 24020002 */  addiu     $v0, $zero, 2
/* BFD8EC 8024006C 03E00008 */  jr        $ra
/* BFD8F0 80240070 27BD0018 */   addiu    $sp, $sp, 0x18
