.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003C428
/* 17828 8003C428 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1782C 8003C42C AFBF0010 */  sw        $ra, 0x10($sp)
/* 17830 8003C430 0C00F14F */  jal       func_8003C53C
/* 17834 8003C434 00000000 */   nop
/* 17838 8003C438 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1783C 8003C43C 03E00008 */  jr        $ra
/* 17840 8003C440 27BD0018 */   addiu    $sp, $sp, 0x18
