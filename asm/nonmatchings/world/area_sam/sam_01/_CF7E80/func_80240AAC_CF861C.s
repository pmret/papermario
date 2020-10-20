.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AAC_CF861C
/* CF861C 80240AAC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CF8620 80240AB0 AFBF0010 */  sw        $ra, 0x10($sp)
/* CF8624 80240AB4 0C00EABB */  jal       get_npc_unsafe
/* CF8628 80240AB8 8C84014C */   lw       $a0, 0x14c($a0)
/* CF862C 80240ABC 8FBF0010 */  lw        $ra, 0x10($sp)
/* CF8630 80240AC0 0000102D */  daddu     $v0, $zero, $zero
/* CF8634 80240AC4 03E00008 */  jr        $ra
/* CF8638 80240AC8 27BD0018 */   addiu    $sp, $sp, 0x18
