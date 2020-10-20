.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240070_ACAB90
/* ACAB90 80240070 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ACAB94 80240074 AFBF0010 */  sw        $ra, 0x10($sp)
/* ACAB98 80240078 0C04417A */  jal       get_entity_by_index
/* ACAB9C 8024007C 8C840084 */   lw       $a0, 0x84($a0)
/* ACABA0 80240080 0040182D */  daddu     $v1, $v0, $zero
/* ACABA4 80240084 8C640000 */  lw        $a0, ($v1)
/* ACABA8 80240088 3C050010 */  lui       $a1, 0x10
/* ACABAC 8024008C 00852025 */  or        $a0, $a0, $a1
/* ACABB0 80240090 AC640000 */  sw        $a0, ($v1)
/* ACABB4 80240094 8FBF0010 */  lw        $ra, 0x10($sp)
/* ACABB8 80240098 24020002 */  addiu     $v0, $zero, 2
/* ACABBC 8024009C 03E00008 */  jr        $ra
/* ACABC0 802400A0 27BD0018 */   addiu    $sp, $sp, 0x18
/* ACABC4 802400A4 00000000 */  nop       
/* ACABC8 802400A8 00000000 */  nop       
/* ACABCC 802400AC 00000000 */  nop       
