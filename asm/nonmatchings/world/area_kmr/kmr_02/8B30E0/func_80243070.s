.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243070
/* 8B30E0 80243070 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B30E4 80243074 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B30E8 80243078 0C03A625 */  jal       func_800E9894
/* 8B30EC 8024307C 00000000 */   nop      
/* 8B30F0 80243080 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B30F4 80243084 24020002 */  addiu     $v0, $zero, 2
/* 8B30F8 80243088 03E00008 */  jr        $ra
/* 8B30FC 8024308C 27BD0018 */   addiu    $sp, $sp, 0x18
