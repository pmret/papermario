.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel NOP_npc_callback
/* 13870 80038470 03E00008 */  jr        $ra
/* 13874 80038474 00000000 */   nop      
