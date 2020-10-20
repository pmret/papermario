.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D84_E134E4
/* E134E4 80240D84 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E134E8 80240D88 AFBF0010 */  sw        $ra, 0x10($sp)
/* E134EC 80240D8C 0C00FB3A */  jal       get_enemy
/* E134F0 80240D90 0000202D */   daddu    $a0, $zero, $zero
/* E134F4 80240D94 8C440080 */  lw        $a0, 0x80($v0)
/* E134F8 80240D98 8C83000C */  lw        $v1, 0xc($a0)
/* E134FC 80240D9C 00031840 */  sll       $v1, $v1, 1
/* E13500 80240DA0 AC83000C */  sw        $v1, 0xc($a0)
/* E13504 80240DA4 AC830010 */  sw        $v1, 0x10($a0)
/* E13508 80240DA8 8FBF0010 */  lw        $ra, 0x10($sp)
/* E1350C 80240DAC 24020002 */  addiu     $v0, $zero, 2
/* E13510 80240DB0 03E00008 */  jr        $ra
/* E13514 80240DB4 27BD0018 */   addiu    $sp, $sp, 0x18
