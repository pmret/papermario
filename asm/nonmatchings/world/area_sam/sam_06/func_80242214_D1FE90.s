.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242214_D220A4
/* D220A4 80242214 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D220A8 80242218 AFBF0010 */  sw        $ra, 0x10($sp)
/* D220AC 8024221C 8C82000C */  lw        $v0, 0xc($a0)
/* D220B0 80242220 0C0B1EAF */  jal       get_variable
/* D220B4 80242224 8C450000 */   lw       $a1, ($v0)
/* D220B8 80242228 00021600 */  sll       $v0, $v0, 0x18
/* D220BC 8024222C 0C03AC5A */  jal       func_800EB168
/* D220C0 80242230 00022603 */   sra      $a0, $v0, 0x18
/* D220C4 80242234 8FBF0010 */  lw        $ra, 0x10($sp)
/* D220C8 80242238 24020002 */  addiu     $v0, $zero, 2
/* D220CC 8024223C 03E00008 */  jr        $ra
/* D220D0 80242240 27BD0018 */   addiu    $sp, $sp, 0x18
