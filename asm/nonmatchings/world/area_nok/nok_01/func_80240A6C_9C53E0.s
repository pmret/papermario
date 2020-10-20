.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A6C_9C5E4C
/* 9C5E4C 80240A6C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C5E50 80240A70 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9C5E54 80240A74 0C03A625 */  jal       func_800E9894
/* 9C5E58 80240A78 00000000 */   nop      
/* 9C5E5C 80240A7C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C5E60 80240A80 24020002 */  addiu     $v0, $zero, 2
/* 9C5E64 80240A84 03E00008 */  jr        $ra
/* 9C5E68 80240A88 27BD0018 */   addiu    $sp, $sp, 0x18
