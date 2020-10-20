.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413A4_D65984
/* D65984 802413A4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D65988 802413A8 AFBF0010 */  sw        $ra, 0x10($sp)
/* D6598C 802413AC 8C82000C */  lw        $v0, 0xc($a0)
/* D65990 802413B0 0C0B1EAF */  jal       get_variable
/* D65994 802413B4 8C450000 */   lw       $a1, ($v0)
/* D65998 802413B8 0C00EAD2 */  jal       get_npc_safe
/* D6599C 802413BC 0040202D */   daddu    $a0, $v0, $zero
/* D659A0 802413C0 8FBF0010 */  lw        $ra, 0x10($sp)
/* D659A4 802413C4 24020002 */  addiu     $v0, $zero, 2
/* D659A8 802413C8 03E00008 */  jr        $ra
/* D659AC 802413CC 27BD0018 */   addiu    $sp, $sp, 0x18
