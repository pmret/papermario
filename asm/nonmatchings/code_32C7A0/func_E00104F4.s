.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00104F4
/* 32CC94 E00104F4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 32CC98 E00104F8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 32CC9C E00104FC 0C080128 */  jal       func_E02004A0
/* 32CCA0 E0010500 00000000 */   nop      
/* 32CCA4 E0010504 8FBF0010 */  lw        $ra, 0x10($sp)
/* 32CCA8 E0010508 03E00008 */  jr        $ra
/* 32CCAC E001050C 27BD0018 */   addiu    $sp, $sp, 0x18
