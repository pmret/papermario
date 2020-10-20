.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240070_ACE1B0
/* ACE1B0 80240070 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ACE1B4 80240074 AFBF0010 */  sw        $ra, 0x10($sp)
/* ACE1B8 80240078 0C04417A */  jal       get_entity_by_index
/* ACE1BC 8024007C 8C840084 */   lw       $a0, 0x84($a0)
/* ACE1C0 80240080 0040182D */  daddu     $v1, $v0, $zero
/* ACE1C4 80240084 8C640000 */  lw        $a0, ($v1)
/* ACE1C8 80240088 3C050010 */  lui       $a1, 0x10
/* ACE1CC 8024008C 00852025 */  or        $a0, $a0, $a1
/* ACE1D0 80240090 AC640000 */  sw        $a0, ($v1)
/* ACE1D4 80240094 8FBF0010 */  lw        $ra, 0x10($sp)
/* ACE1D8 80240098 24020002 */  addiu     $v0, $zero, 2
/* ACE1DC 8024009C 03E00008 */  jr        $ra
/* ACE1E0 802400A0 27BD0018 */   addiu    $sp, $sp, 0x18
/* ACE1E4 802400A4 00000000 */  nop       
/* ACE1E8 802400A8 00000000 */  nop       
/* ACE1EC 802400AC 00000000 */  nop       
