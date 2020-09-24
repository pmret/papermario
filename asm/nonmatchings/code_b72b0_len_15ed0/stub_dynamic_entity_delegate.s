.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel stub_dynamic_entity_delegate
/* B97B0 801230B0 03E00008 */  jr        $ra
/* B97B4 801230B4 00000000 */   nop      
