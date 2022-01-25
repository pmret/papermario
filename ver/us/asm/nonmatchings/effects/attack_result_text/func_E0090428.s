.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0090428
/* 38FD28 E0090428 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 38FD2C E009042C AFBF0010 */  sw        $ra, 0x10($sp)
/* 38FD30 E0090430 0C024111 */  jal       func_E0090444
/* 38FD34 E0090434 00000000 */   nop
/* 38FD38 E0090438 8FBF0010 */  lw        $ra, 0x10($sp)
/* 38FD3C E009043C 03E00008 */  jr        $ra
/* 38FD40 E0090440 27BD0018 */   addiu    $sp, $sp, 0x18
