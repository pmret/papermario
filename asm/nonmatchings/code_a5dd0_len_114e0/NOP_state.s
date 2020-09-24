.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel NOP_state
/* A9290 80112B90 03E00008 */  jr        $ra
/* A9294 80112B94 00000000 */   nop      
