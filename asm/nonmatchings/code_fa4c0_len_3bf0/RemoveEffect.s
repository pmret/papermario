.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel RemoveEffect
/* FC494 802D7AE4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* FC498 802D7AE8 AFBF0010 */  sw        $ra, 0x10($sp)
/* FC49C 802D7AEC 8C82000C */  lw        $v0, 0xc($a0)
/* FC4A0 802D7AF0 0C0B1EAF */  jal       get_variable
/* FC4A4 802D7AF4 8C450000 */   lw       $a1, ($v0)
/* FC4A8 802D7AF8 0C016914 */  jal       remove_effect
/* FC4AC 802D7AFC 0040202D */   daddu    $a0, $v0, $zero
/* FC4B0 802D7B00 8FBF0010 */  lw        $ra, 0x10($sp)
/* FC4B4 802D7B04 24020002 */  addiu     $v0, $zero, 2
/* FC4B8 802D7B08 03E00008 */  jr        $ra
/* FC4BC 802D7B0C 27BD0018 */   addiu    $sp, $sp, 0x18
