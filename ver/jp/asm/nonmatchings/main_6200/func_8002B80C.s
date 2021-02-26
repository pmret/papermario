.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002B80C
/* 6C0C 8002B80C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6C10 8002B810 AFBF0010 */  sw        $ra, 0x10($sp)
/* 6C14 8002B814 0C01BBD2 */  jal       func_8006EF48
/* 6C18 8002B818 00000000 */   nop
/* 6C1C 8002B81C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6C20 8002B820 03E00008 */  jr        $ra
/* 6C24 8002B824 27BD0018 */   addiu    $sp, $sp, 0x18
