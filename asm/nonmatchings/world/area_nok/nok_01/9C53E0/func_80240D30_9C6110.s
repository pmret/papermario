.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D30_9C6110
/* 9C6110 80240D30 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C6114 80240D34 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9C6118 80240D38 8C82000C */  lw        $v0, 0xc($a0)
/* 9C611C 80240D3C 0C0B1EAF */  jal       get_variable
/* 9C6120 80240D40 8C450000 */   lw       $a1, ($v0)
/* 9C6124 80240D44 00021600 */  sll       $v0, $v0, 0x18
/* 9C6128 80240D48 0C03AC5A */  jal       func_800EB168
/* 9C612C 80240D4C 00022603 */   sra      $a0, $v0, 0x18
/* 9C6130 80240D50 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C6134 80240D54 24020002 */  addiu     $v0, $zero, 2
/* 9C6138 80240D58 03E00008 */  jr        $ra
/* 9C613C 80240D5C 27BD0018 */   addiu    $sp, $sp, 0x18
