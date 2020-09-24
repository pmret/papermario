.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel enable_entity_fog
/* B96EC 80122FEC 24020001 */  addiu     $v0, $zero, 1
/* B96F0 80122FF0 3C018015 */  lui       $at, 0x8015
/* B96F4 80122FF4 AC224378 */  sw        $v0, 0x4378($at)
/* B96F8 80122FF8 03E00008 */  jr        $ra
/* B96FC 80122FFC 00000000 */   nop      
