.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AF4_D06224
/* D06224 80240AF4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D06228 80240AF8 AFBF0010 */  sw        $ra, 0x10($sp)
/* D0622C 80240AFC 8C82000C */  lw        $v0, 0xc($a0)
/* D06230 80240B00 0C0B1EAF */  jal       get_variable
/* D06234 80240B04 8C450000 */   lw       $a1, ($v0)
/* D06238 80240B08 00021600 */  sll       $v0, $v0, 0x18
/* D0623C 80240B0C 0C03AC5A */  jal       func_800EB168
/* D06240 80240B10 00022603 */   sra      $a0, $v0, 0x18
/* D06244 80240B14 8FBF0010 */  lw        $ra, 0x10($sp)
/* D06248 80240B18 24020002 */  addiu     $v0, $zero, 2
/* D0624C 80240B1C 03E00008 */  jr        $ra
/* D06250 80240B20 27BD0018 */   addiu    $sp, $sp, 0x18
