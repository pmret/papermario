.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0002738
/* 328028 E0002738 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 32802C E000273C AFBF0010 */  sw        $ra, 0x10($sp)
/* 328030 E0002740 0C080128 */  jal       func_E02004A0
/* 328034 E0002744 00000000 */   nop      
/* 328038 E0002748 8FBF0010 */  lw        $ra, 0x10($sp)
/* 32803C E000274C 03E00008 */  jr        $ra
/* 328040 E0002750 27BD0018 */   addiu    $sp, $sp, 0x18
/* 328044 E0002754 00000000 */  nop       
/* 328048 E0002758 00000000 */  nop       
/* 32804C E000275C 00000000 */  nop       
