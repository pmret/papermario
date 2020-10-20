.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241564
/* 8ED384 80241564 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8ED388 80241568 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8ED38C 8024156C 8C82000C */  lw        $v0, 0xc($a0)
/* 8ED390 80241570 0C0B1EAF */  jal       get_variable
/* 8ED394 80241574 8C450000 */   lw       $a1, ($v0)
/* 8ED398 80241578 00021600 */  sll       $v0, $v0, 0x18
/* 8ED39C 8024157C 0C03AC5A */  jal       func_800EB168
/* 8ED3A0 80241580 00022603 */   sra      $a0, $v0, 0x18
/* 8ED3A4 80241584 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8ED3A8 80241588 24020002 */  addiu     $v0, $zero, 2
/* 8ED3AC 8024158C 03E00008 */  jr        $ra
/* 8ED3B0 80241590 27BD0018 */   addiu    $sp, $sp, 0x18
