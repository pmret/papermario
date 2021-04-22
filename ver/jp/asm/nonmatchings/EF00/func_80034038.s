.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80034038
/* F438 80034038 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F43C 8003403C AFBF0010 */  sw        $ra, 0x10($sp)
/* F440 80034040 0C00D015 */  jal       func_80034054
/* F444 80034044 00000000 */   nop
/* F448 80034048 8FBF0010 */  lw        $ra, 0x10($sp)
/* F44C 8003404C 03E00008 */  jr        $ra
/* F450 80034050 27BD0018 */   addiu    $sp, $sp, 0x18
