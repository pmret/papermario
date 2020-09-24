.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel disable_entity_fog
/* B9700 80123000 3C018015 */  lui       $at, 0x8015
/* B9704 80123004 AC204378 */  sw        $zero, 0x4378($at)
/* B9708 80123008 03E00008 */  jr        $ra
/* B970C 8012300C 00000000 */   nop      
