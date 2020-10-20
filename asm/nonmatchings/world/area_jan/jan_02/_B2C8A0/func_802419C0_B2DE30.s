.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419C0_B2DE30
/* B2DE30 802419C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B2DE34 802419C4 AFBF0010 */  sw        $ra, 0x10($sp)
/* B2DE38 802419C8 0C00EABB */  jal       get_npc_unsafe
/* B2DE3C 802419CC 8C84014C */   lw       $a0, 0x14c($a0)
/* B2DE40 802419D0 8FBF0010 */  lw        $ra, 0x10($sp)
/* B2DE44 802419D4 0000102D */  daddu     $v0, $zero, $zero
/* B2DE48 802419D8 03E00008 */  jr        $ra
/* B2DE4C 802419DC 27BD0018 */   addiu    $sp, $sp, 0x18
