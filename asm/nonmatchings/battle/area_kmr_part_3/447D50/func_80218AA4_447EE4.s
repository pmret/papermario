.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218AA4_447EE4
/* 447EE4 80218AA4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 447EE8 80218AA8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 447EEC 80218AAC 8C82000C */  lw        $v0, 0xc($a0)
/* 447EF0 80218AB0 0C0B1EAF */  jal       get_variable
/* 447EF4 80218AB4 8C450000 */   lw       $a1, ($v0)
/* 447EF8 80218AB8 0C05123D */  jal       free_icon
/* 447EFC 80218ABC 0040202D */   daddu    $a0, $v0, $zero
/* 447F00 80218AC0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 447F04 80218AC4 24020002 */  addiu     $v0, $zero, 2
/* 447F08 80218AC8 03E00008 */  jr        $ra
/* 447F0C 80218ACC 27BD0018 */   addiu    $sp, $sp, 0x18
