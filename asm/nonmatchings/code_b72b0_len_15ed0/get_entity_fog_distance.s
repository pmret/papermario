.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_entity_fog_distance
/* B9760 80123060 3C028015 */  lui       $v0, 0x8015
/* B9764 80123064 8C42438C */  lw        $v0, 0x438c($v0)
/* B9768 80123068 AC820000 */  sw        $v0, ($a0)
/* B976C 8012306C 3C028015 */  lui       $v0, 0x8015
/* B9770 80123070 8C424390 */  lw        $v0, 0x4390($v0)
/* B9774 80123074 03E00008 */  jr        $ra
/* B9778 80123078 ACA20000 */   sw       $v0, ($a1)
