.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F40
/* 833740 80241F40 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 833744 80241F44 AFBF0010 */  sw        $ra, 0x10($sp)
/* 833748 80241F48 8C82000C */  lw        $v0, 0xc($a0)
/* 83374C 80241F4C 3C068016 */  lui       $a2, 0x8016
/* 833750 80241F50 84C6A552 */  lh        $a2, -0x5aae($a2)
/* 833754 80241F54 0C0B2026 */  jal       set_variable
/* 833758 80241F58 8C450000 */   lw       $a1, ($v0)
/* 83375C 80241F5C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 833760 80241F60 24020002 */  addiu     $v0, $zero, 2
/* 833764 80241F64 03E00008 */  jr        $ra
/* 833768 80241F68 27BD0018 */   addiu    $sp, $sp, 0x18
