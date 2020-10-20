.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024250C
/* D2239C 8024250C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D223A0 80242510 AFBF0010 */  sw        $ra, 0x10($sp)
/* D223A4 80242514 0C00EABB */  jal       get_npc_unsafe
/* D223A8 80242518 8C84008C */   lw       $a0, 0x8c($a0)
/* D223AC 8024251C 3C038025 */  lui       $v1, 0x8025
/* D223B0 80242520 8C63C1D8 */  lw        $v1, -0x3e28($v1)
/* D223B4 80242524 AC430028 */  sw        $v1, 0x28($v0)
/* D223B8 80242528 8FBF0010 */  lw        $ra, 0x10($sp)
/* D223BC 8024252C 24020002 */  addiu     $v0, $zero, 2
/* D223C0 80242530 03E00008 */  jr        $ra
/* D223C4 80242534 27BD0018 */   addiu    $sp, $sp, 0x18
