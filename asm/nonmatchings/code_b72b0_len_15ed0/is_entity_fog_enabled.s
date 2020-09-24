.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel is_entity_fog_enabled
/* B9750 80123050 3C028015 */  lui       $v0, 0x8015
/* B9754 80123054 8C424378 */  lw        $v0, 0x4378($v0)
/* B9758 80123058 03E00008 */  jr        $ra
/* B975C 8012305C 00000000 */   nop      
