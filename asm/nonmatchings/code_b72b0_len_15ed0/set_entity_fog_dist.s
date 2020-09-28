.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_entity_fog_dist
/* B9710 80123010 3C018015 */  lui       $at, 0x8015
/* B9714 80123014 AC24438C */  sw        $a0, 0x438c($at)
/* B9718 80123018 3C018015 */  lui       $at, 0x8015
/* B971C 8012301C AC254390 */  sw        $a1, 0x4390($at)
/* B9720 80123020 03E00008 */  jr        $ra
/* B9724 80123024 00000000 */   nop      
