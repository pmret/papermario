.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243748_96C908
/* 96C908 80243748 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 96C90C 8024374C AFBF0010 */  sw        $ra, 0x10($sp)
/* 96C910 80243750 8C82000C */  lw        $v0, 0xc($a0)
/* 96C914 80243754 0C0B1EAF */  jal       get_variable
/* 96C918 80243758 8C450000 */   lw       $a1, ($v0)
/* 96C91C 8024375C 00021600 */  sll       $v0, $v0, 0x18
/* 96C920 80243760 0C03AC5A */  jal       func_800EB168
/* 96C924 80243764 00022603 */   sra      $a0, $v0, 0x18
/* 96C928 80243768 8FBF0010 */  lw        $ra, 0x10($sp)
/* 96C92C 8024376C 24020002 */  addiu     $v0, $zero, 2
/* 96C930 80243770 03E00008 */  jr        $ra
/* 96C934 80243774 27BD0018 */   addiu    $sp, $sp, 0x18
